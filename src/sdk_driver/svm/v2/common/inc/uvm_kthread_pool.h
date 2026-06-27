/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
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

#ifndef UVM_KTHREAD_POOL_H
#define UVM_KTHREAD_POOL_H

#include "ascend_hal_define.h"
#include "devmm_adapt.h"

#define UVM_THREAD_NUM 4

extern struct kthread_pool *pool;

struct uvm_msg_process_task {
    struct devmm_svm_process *svm_proc;
    struct devmm_svm_heap *heap;
    void *msg;
    uint32_t msg_id;
    uint32_t ack_len;
};

struct kthread_task {
    struct list_head list;
    void (*func)(void *);
    void *arg;
};

struct kthread_pool {
    struct list_head task_list;
    spinlock_t lock;
    wait_queue_head_t waitq;
    struct task_struct **threads;
    int num_threads;
    bool stop;
};

struct kthread_pool *kthread_pool_create(int num_threads);

void kthread_pool_destroy(struct kthread_pool *pool);

int kthread_pool_submit(struct kthread_pool *pool, void (*func)(void *), void *arg);

#endif /* UVM_KTHREAD_POOL_H */