/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
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

#ifndef MEM_ALLOCATER_H
#define MEM_ALLOCATER_H

#include "mem_pool_comm.h"

#ifdef __cplusplus
extern "C" {
#endif

void create_mem_pool(struct mem_pool_info** mem_pool, ka_mutex_t* mtx);
int32_t init_mem_allocater(init func, struct mem_pool_info* mem_pool, uint32_t node_num,
    uint32_t node_size, ka_mutex_t* mtx);
void destroy_mem_pool(deinit func, struct mem_pool_info** mem_pool, ka_mutex_t* mtx);
struct mem_node* alloc_node_from_pool(struct mem_pool_info* mem_pool);
void free_node_to_pool(struct mem_node* node, struct mem_pool_info* mem_pool);

#ifdef __cplusplus
}
#endif
#endif // #ifndef MEM_ALLOCATER_H
