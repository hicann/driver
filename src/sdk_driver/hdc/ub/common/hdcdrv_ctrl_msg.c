/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "kernel_version_adapt.h"
#include "ka_compiler_pub.h"
#include "ka_base_pub.h"
#include "ka_list_pub.h"
#include "ka_task_pub.h"
#include "hdcdrv_cmd.h"
#include "hdcdrv_core_com_ub.h"
#include "hdcdrv_mem_com_ub.h"
#include "hdcdrv_ctrl_msg.h"
#include "hdcdrv_core_ub.h"

struct hdcdrv_ctrl_msg_node *hdcdrv_find_ctrl_msg_node(struct hdcdrv_dev *dev, u64 hash_pid)
{
    struct hdcdrv_ctrl_msg_node *ctrl_node = NULL;
    u64 key = hash_pid; /* Search the hash table using dev_id as the key value */

    ka_hash_for_each_possible(dev->event_msg_pool.htable, ctrl_node, hnode, key)
    {
        if (ctrl_node->hash_pid == hash_pid) {
            return ctrl_node;
        }
    }

    return NULL;
}

struct hdcdrv_ctrl_msg_node *hdcdrv_add_ctrl_msg_node(struct hdcdrv_dev *dev, u64 hash_pid)
{
    struct hdcdrv_ctrl_msg_node *ctrl_node = NULL;
    u64 key = hash_pid;

    if (hdcdrv_find_ctrl_msg_node(dev, hash_pid) != NULL) {
        hdcdrv_err("Repeat add node.(dev_id=%u; pid=%llu)\n", dev->dev_id, hash_pid);
        return NULL;
    }

    ctrl_node = hdcdrv_ub_kvmalloc(sizeof(struct hdcdrv_ctrl_msg_node));
    if (ctrl_node == NULL) {
        hdcdrv_err("Alloc Node for process failed.(dev_id=%u; pid=%llu)\n", dev->dev_id, hash_pid);
        return NULL;
    }

    ctrl_node->hash_pid = hash_pid;
    ctrl_node->ref = 0;
    ctrl_node->status = HDCDRV_NODE_IDLE;
    ctrl_node->ctx = NULL;
    KA_INIT_LIST_HEAD(&ctrl_node->wait_list);
    ka_hash_add(dev->event_msg_pool.htable, &ctrl_node->hnode, key);
    ka_task_init_waitqueue_head(&ctrl_node->wq_ctrl_msg);

    return ctrl_node;
}

// Clear all event in list and wakeup node, this operation should be in the dev mutex
void hdcdrv_ctrl_msg_node_list_res_clear(struct hdcdrv_ctrl_msg_node *ctrl_node, struct hdcdrv_event_msg_pool *pool)
{
    struct hdcdrv_event_msg_block *block = NULL;

    // Set node idle, then the wait_event thread will not deal with event and exit after wakeup
    ctrl_node->status = HDCDRV_NODE_IDLE;

    while (!ka_list_empty(&ctrl_node->wait_list)) {
        block = ka_list_first_entry(&ctrl_node->wait_list, struct hdcdrv_event_msg_block, list);
        ka_list_del(&block->list);
        pool->ctrl_msg_block_queue[pool->head] = block;
        pool->head = (pool->head + 1) % HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH;
    }

    ka_task_wake_up_interruptible(&ctrl_node->wq_ctrl_msg);
}

void hdcdrv_del_ctrl_msg_node(struct hdcdrv_dev *dev, struct hdcdrv_ctrl_msg_node *ctrl_node)
{
    struct hdcdrv_ctx *ctx = ctrl_node->ctx;

    ka_hash_del(&ctrl_node->hnode);
    if (ctx != NULL) {
        ka_task_mutex_lock(&ctx->ctx_lock);
        ctrl_node->ctx = NULL;
        ctx->ctrl_node = NULL;
        ka_task_mutex_unlock(&ctx->ctx_lock);
    }
    if (ctrl_node->ref != 0) {
        ctrl_node->status = HDCDRV_NODE_NEED_FREE;
        ka_task_wake_up_interruptible(&ctrl_node->wq_ctrl_msg);
        return;
    }
    // Free must be after wait_interruptible has been wake up and wait_event thread has exit
    hdcdrv_ub_kvfree(ctrl_node);
}

// Used in uninstance, clear all event_block and wakeup all ctrl_node
void hdcdrv_clear_event_msg_pool(struct hdcdrv_dev *dev)
{
    struct hdcdrv_ctrl_msg_node *ctrl_node = NULL;
    ka_hlist_node_t *local_hnode = NULL;
    u32 bkt = 0;

    ka_hash_for_each_safe(dev->event_msg_pool.htable, bkt, local_hnode, ctrl_node, hnode)
    {
        hdcdrv_ctrl_msg_node_list_res_clear(ctrl_node, &dev->event_msg_pool);
    }
}

STATIC void hdcdrv_clear_dev_all_ctrl_msg_node(struct hdcdrv_dev *dev)
{
    struct hdcdrv_ctrl_msg_node *ctrl_node = NULL;
    ka_hlist_node_t *local_hnode = NULL;
    u32 bkt = 0;

    ka_hash_for_each_safe(dev->event_msg_pool.htable, bkt, local_hnode, ctrl_node, hnode)
    {
        hdcdrv_ctrl_msg_node_list_res_clear(ctrl_node, &dev->event_msg_pool);
        hdcdrv_del_ctrl_msg_node(dev, ctrl_node);
    }
}

int hdcdrv_ctrl_msg_queue_init(struct hdcdrv_dev *dev)
{
    int i;
    dev->event_msg_pool.tail = 0;
    dev->event_msg_pool.head = 0;
    for (i = 0; i < HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH; i++) {
        dev->event_msg_pool.ctrl_msg_block_queue[i] = (struct hdcdrv_event_msg_block *)ka_mm_vzalloc(
            sizeof(struct hdcdrv_event_msg_block));
        if (dev->event_msg_pool.ctrl_msg_block_queue[i] == NULL) {
            hdcdrv_err("alloc node failed for event queue.(dev_id=%u)\n", dev->dev_id);
            goto exit_queue_init;
        }
        KA_INIT_LIST_HEAD(&dev->event_msg_pool.ctrl_msg_block_queue[i]->list);
    }

    return 0;

exit_queue_init:
    for (i = i - 1; i >= 0; i--) {
        ka_mm_vfree(dev->event_msg_pool.ctrl_msg_block_queue[i]);
        dev->event_msg_pool.ctrl_msg_block_queue[i] = NULL;
    }

    return -ENOMEM;
}

void hdcdrv_ctrl_msg_queue_uninit(struct hdcdrv_dev *dev)
{
    int i, cnt = 0;
    hdcdrv_clear_dev_all_ctrl_msg_node(dev);
    for (i = 0; i < HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH; i++) {
        if (dev->event_msg_pool.ctrl_msg_block_queue[i] == NULL) {
            cnt++;
            continue;
        }
        ka_mm_vfree(dev->event_msg_pool.ctrl_msg_block_queue[i]);
        dev->event_msg_pool.ctrl_msg_block_queue[i] = NULL;
    }

    if (cnt != 0) {
        hdcdrv_err("Exist node has not been recycled.(cnt=%d)\n", cnt);
    }
}

STATIC bool hdcdrv_is_msg_queue_full(struct hdcdrv_dev *dev)
{
    if (((dev->event_msg_pool.tail + 1) % HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH) == dev->event_msg_pool.head) {
        return true;
    }

    return false;
}

bool hdcdrv_is_msg_queue_empty(struct hdcdrv_dev *dev)
{
    if (dev->event_msg_pool.tail == dev->event_msg_pool.head) {
        return true;
    }

    return false;
}

bool hdcdrv_is_wait_list_empty(struct hdcdrv_ctrl_msg_node *ctrl_node)
{
    if (ka_list_empty(&ctrl_node->wait_list)) {
        return true;
    }

    return false;
}

int hdcdrv_wake_up_ctrl_node(struct hdcdrv_dev *dev, u64 pid, struct hdcdrv_event_msg *event_msg)
{
    struct hdcdrv_ctrl_msg_node *ctrl_node = NULL;
    struct hdcdrv_event_msg_pool *pool = &dev->event_msg_pool;
    struct hdcdrv_event_msg_block *block = NULL;

    if (hdcdrv_is_msg_queue_full(dev)) {
        hdcdrv_warn("process queue has been full.(dev_id=%u)\n", dev->dev_id);
        return HDCDRV_DMA_QUE_FULL;
    }

    ctrl_node = hdcdrv_find_ctrl_msg_node(dev, pid);
    if (ctrl_node == NULL) {
        hdcdrv_warn("process not exist.(dev_id=%u; pid=%llu)\n", dev->dev_id, pid);
        return DRV_ERROR_NO_PROCESS;
    }

    if (ctrl_node->status != HDCDRV_NODE_BUSY) {
        hdcdrv_warn("process ctrl_node is idle.(dev_id=%u; pid=%llu; status=%u)\n", dev->dev_id, pid,
                    ctrl_node->status);
        return DRV_ERROR_NO_PROCESS;
    }

    block = pool->ctrl_msg_block_queue[pool->tail];
    pool->ctrl_msg_block_queue[pool->tail] = NULL;
    block->fail_count = 0;
    (void)memcpy_s(&block->data, sizeof(struct hdcdrv_event_msg), event_msg, sizeof(struct hdcdrv_event_msg));
    dev->event_msg_pool.tail = (dev->event_msg_pool.tail + 1) % HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH;
    ka_list_add_tail(&block->list, &ctrl_node->wait_list);
    ka_task_wake_up_interruptible(&ctrl_node->wq_ctrl_msg);

    return 0;
}

/*
    1. From list, find the block
    2. delete block from list
    3. copy data from block to event_msg
    4. return block to pool
*/
int hdcdrv_get_ctrl_msg_event(struct hdcdrv_dev *dev, struct hdcdrv_ctrl_msg_node *ctrl_node,
                              struct hdcdrv_cmd_wait_ctrl_msg *cmd)
{
    struct hdcdrv_event_msg_pool *pool = &dev->event_msg_pool;
    struct hdcdrv_event_msg_block *block = NULL;
    int ret;

    block = ka_list_first_entry(&ctrl_node->wait_list, struct hdcdrv_event_msg_block, list);
    ret = ka_base_copy_to_user((void __ka_user *)cmd->msg_buf, &block->data, sizeof(struct hdcdrv_event_msg));
    if (ret != 0) {
        block->fail_count++;
        ret = HDCDRV_COPY_TO_USER_FAIL;
        hdcdrv_warn("Copy to User unsuccess.(dev_id=%u; retry_time=%u)\n", dev->dev_id, block->fail_count);
        if (block->fail_count < HDCDRV_MAX_COPY_RETRY_TIME) {
            return ret;
        }
    }

    ka_list_del(&block->list);
    block->fail_count = 0;
    pool->ctrl_msg_block_queue[pool->head] = block;
    pool->head = (pool->head + 1) % HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH;

    return ret;
}