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

#ifndef DVPP_CMDLIST_CONTEXT_H
#define DVPP_CMDLIST_CONTEXT_H

#include "ka_type.h"
#include "ka_task_pub.h"
#include "ka_list_pub.h"
#include "dvpp_cmdlist_util.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_TIME_COST_NODE_LEN (1024)

typedef struct {
    uint16_t taskid;
    uint16_t streamid;
    int64_t time_cost_usr_copy_to_kern;
    int64_t time_cost_vmalloc;
    int64_t time_cost_dma_alloc;
    int64_t time_cost_u2k_map;
    int64_t time_cost_pcie_copy;
    ka_hlist_node_t hlist;
} time_cost_node;

typedef struct {
    ka_hlist_head_t head[MAX_TIME_COST_NODE_LEN];
    time_cost_node node[MAX_TIME_COST_NODE_LEN];
    ka_spinlock_t splock;
    uint16_t node_idx;
    uint16_t node_num;
    uint8_t enable;
} time_cost_stat;

typedef struct {
    // 内存池信息

    // 耗时统计信息
    time_cost_stat time_cost_stat;
} dvpp_cmdlist_context;

#define BEGIN_TIME_STAMP(ctx, streamid, taskid, stage) \
do { \
    if ((ctx)->time_cost_stat.enable == 1) { \
        time_cost_node* tmp_time_cost_node = get_time_cost_node_from_ctx((streamid), (taskid)); \
        tmp_time_cost_node->stage = dvpp_cmdlist_get_usec(); \
    } \
} while (0)

#define CALC_TIME_COST(ctx, streamid, taskid, stage) \
do { \
    if ((ctx)->time_cost_stat.enable == 1) { \
        time_cost_node* tmp_time_cost_node = get_time_cost_node_from_ctx((streamid), (taskid)); \
        tmp_time_cost_node->stage = dvpp_cmdlist_get_usec() - tmp_time_cost_node->stage; \
    } \
} while (0)

void dvpp_cmdlist_context_init(void);
void dvpp_cmdlist_context_deinit(void);
time_cost_node* alloc_time_cost_node_from_ctx(void);
void add_time_cost_node_to_ctx(time_cost_node* node);
time_cost_node* get_time_cost_node_from_ctx(uint16_t streamid, uint16_t taskid);
dvpp_cmdlist_context* get_dvpp_cmdlist_ctx(void);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_CMDLIST_CONTEXT_H
