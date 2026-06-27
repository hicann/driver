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

#ifndef DVPP_MEM_ALLOCATER_COMM_H
#define DVPP_MEM_ALLOCATER_COMM_H

#include "dvpp_mem_allocater.h"
#include "mem_pool_comm.h"
#include "dvpp_cmdlist.h"

#ifdef __cplusplus
extern "C" {
#endif

init get_init_func(enum mem_node_type node_type);
struct mem_pool_info* get_mem_pool(enum dvpp_sqe_type mod_type, enum mem_node_type node_type, uint32_t pool_id);
uint32_t get_node_num(enum dvpp_sqe_type mod_type);
ka_mutex_t* get_mutex(enum dvpp_sqe_type mod_type);
void* alloc_node(enum dvpp_sqe_type mod_type, enum mem_node_type node_type, uint32_t pool_id, uint32_t size);
void free_node(enum dvpp_sqe_type mod_type, enum mem_node_type node_type, uint32_t pool_id, struct mem_node* node);
int32_t check_pool_id(uint32_t pool_id);
void dvpp_create_mem_pools_by_id(uint32_t pool_id);
void dvpp_destroy_mem_pools_by_id(uint32_t pool_id);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_MEM_ALLOCATER_COMM_H