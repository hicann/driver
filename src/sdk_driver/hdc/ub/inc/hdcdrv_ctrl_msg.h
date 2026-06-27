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
#ifndef _HDCDRV_CTRL_MSG_H_
#define _HDCDRV_CTRL_MSG_H_

#include "ka_type.h"
#include "ka_common_pub.h"
#include "ka_base_pub.h"
#include "ka_task_pub.h"
#include "ka_memory_pub.h"
#include "ka_hashtable_pub.h"
#include "hdcdrv_adapt_ub.h"

#define HDC_UB_NODE_HASH_BIT 10
// When the value below changes, the value of the user_space macro with the same name also needs to be modified.
#define HDCDRV_UB_SINGLE_DEV_MAX_SESSION 264 /* 64 * 4(log + tsd + dvpp + reserved) + 8 */
#define HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH 1024

#define HDCDRV_NODE_IDLE 0
#define HDCDRV_NODE_BUSY 1
#define HDCDRV_NODE_NEED_FREE 2

#define HDCDRV_MAX_COPY_RETRY_TIME 3

struct hdcdrv_event_msg_block {
    u32 fail_count;
    struct hdcdrv_event_msg data;
    ka_list_head_t list;
};

// dev level, one dev has one pool
struct hdcdrv_event_msg_pool {
    int tail;
    int head;
    struct hdcdrv_event_msg_block *ctrl_msg_block_queue[HDCDRV_UB_CTRL_MSG_QUEUE_DEPTH]; // store remote events
    KA_DECLARE_HASHTABLE(htable, HDC_UB_NODE_HASH_BIT); // store pid node for these use hdc process
};

struct hdcdrv_ctrl_msg_node {
    ka_hlist_node_t hnode; /* hash pid node */
    u64 hash_pid;          /* use pid as hash val */
    ka_wait_queue_head_t wq_ctrl_msg;
    void *ctx;
    u32 ref;
    u32 status;
    ka_list_head_t wait_list;
};

int hdcdrv_ctrl_msg_queue_init(struct hdcdrv_dev *dev);
void hdcdrv_ctrl_msg_queue_uninit(struct hdcdrv_dev *dev);
struct hdcdrv_ctrl_msg_node *hdcdrv_add_ctrl_msg_node(struct hdcdrv_dev *dev, u64 hash_pid);
void hdcdrv_del_ctrl_msg_node(struct hdcdrv_dev *dev, struct hdcdrv_ctrl_msg_node *ctrl_node);
void hdcdrv_ctrl_msg_node_list_res_clear(struct hdcdrv_ctrl_msg_node *ctrl_node, struct hdcdrv_event_msg_pool *pool);
int hdcdrv_wake_up_ctrl_node(struct hdcdrv_dev *dev, u64 pid, struct hdcdrv_event_msg *event_msg);
int hdcdrv_get_ctrl_msg_event(struct hdcdrv_dev *dev, struct hdcdrv_ctrl_msg_node *ctrl_node,
                              struct hdcdrv_cmd_wait_ctrl_msg *cmd);
bool hdcdrv_is_msg_queue_empty(struct hdcdrv_dev *dev);
struct hdcdrv_ctrl_msg_node *hdcdrv_find_ctrl_msg_node(struct hdcdrv_dev *dev, u64 hash_pid);
void hdcdrv_clear_event_msg_pool(struct hdcdrv_dev *dev);
bool hdcdrv_is_wait_list_empty(struct hdcdrv_ctrl_msg_node *ctrl_node);
#endif // _HDCDRV_CTRL_MSG_H_