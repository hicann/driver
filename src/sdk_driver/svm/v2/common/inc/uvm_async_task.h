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

#ifndef UVM_ASYNC_TASK_H
#define UVM_ASYNC_TASK_H

#include "ascend_hal_define.h"
#include "devmm_adapt.h"

struct msg_process_cnt {
    uint64_t id;
    ka_atomic_t cnt;
    ka_hlist_node_t hnode;
};

void devmm_uvm_msg_process_async(void *data);

void uvm_hnode_add_to_prefetch_msg_id_hashtable(struct msg_process_cnt *cnt);
struct msg_process_cnt *uvm_hnode_find_from_prefetch_msg_id_hashtable(uint64_t prefetch_msg_id);
int uvm_hnode_find_and_add_to_prefetch_msg_id_hashtable(struct msg_process_cnt **cnt, uint64_t prefetch_msg_id);
void uvm_hnode_del_from_prefetch_msg_id_hashtable(struct msg_process_cnt *cnt);
int add_to_prefetch_msg_id_hashtable(struct msg_process_cnt **cnt, uint64_t prefetch_msg_id);

#endif /* UVM_ASYNC_TASK_H */