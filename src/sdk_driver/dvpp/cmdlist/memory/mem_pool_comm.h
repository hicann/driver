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

#ifndef MEM_POOL_COMM_H
#define MEM_POOL_COMM_H

#include "ka_type.h"
#include "ka_list_pub.h"
#include "ka_task_pub.h"

enum mem_node_type {
    ARGS_MEM_NODE = 0,
    DMA_MEM_NODE = 1
};

struct mem_node {
    void* vaddr;
    uint64_t paddr;
    ka_list_head_t list;
};

struct mem_pool_info {
    uint32_t mem_size; // 内存池总大小
    uint32_t node_size; // 单个node大小
    uint32_t mem_node_num; // 内存池节点总个数

    struct mem_node node_list; // 内存池节点链表
    void* base_vaddr; // 内存池虚拟基地址
    uint64_t base_paddr; // 内存池物理基地址
    void* base_nodes_addr; // 内存池节点基地址

    ka_mutex_t mtx;
    ka_semaphore_t sem;

    volatile uint32_t is_inited;
    uint32_t pool_id; // 本内存池序号
};

typedef int32_t (*init)(struct mem_pool_info* args_pool);
typedef void (*deinit)(struct mem_pool_info* args_pool);

#endif // #ifndef MEM_POOL_COMM_H
