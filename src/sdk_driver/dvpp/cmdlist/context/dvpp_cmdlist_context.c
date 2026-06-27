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

#include "dvpp_cmdlist_context.h"
#include "ka_list_pub.h"

static dvpp_cmdlist_context g_dvpp_cmdlist_ctx;

dvpp_cmdlist_context* get_dvpp_cmdlist_ctx(void)
{
    return &g_dvpp_cmdlist_ctx;
}

void dvpp_cmdlist_context_init(void)
{
    uint16_t i = 0;
    // init_node_num 的值不能超过 MAX_TIME_COST_NODE_LEN
    uint16_t const init_node_num = 64;
    ka_task_spin_lock_init(&g_dvpp_cmdlist_ctx.time_cost_stat.splock);
    g_dvpp_cmdlist_ctx.time_cost_stat.node_idx = 0;
    g_dvpp_cmdlist_ctx.time_cost_stat.enable = 0;
    g_dvpp_cmdlist_ctx.time_cost_stat.node_num = init_node_num;

    for (i = 0; i < MAX_TIME_COST_NODE_LEN; i++) {
        KA_INIT_HLIST_HEAD(&g_dvpp_cmdlist_ctx.time_cost_stat.head[i]);
        KA_INIT_HLIST_NODE(&g_dvpp_cmdlist_ctx.time_cost_stat.node[i].hlist);
    }
}

void dvpp_cmdlist_context_deinit(void)
{
    return;
}

static void init_time_cost_node(time_cost_node *node)
{
    node->streamid = 0;
    node->taskid = 0;
    node->time_cost_usr_copy_to_kern = 0;
    node->time_cost_vmalloc = 0;
    node->time_cost_dma_alloc = 0;
    node->time_cost_u2k_map = 0;
    node->time_cost_pcie_copy = 0;
}

time_cost_node* alloc_time_cost_node_from_ctx(void)
{
    dvpp_cmdlist_context *ctx = &g_dvpp_cmdlist_ctx;
    time_cost_node* node = NULL;
    uint16_t idx = 0;
    ka_task_spin_lock(&ctx->time_cost_stat.splock);
    idx = ctx->time_cost_stat.node_idx % ctx->time_cost_stat.node_num;
    ctx->time_cost_stat.node_idx++;
    node = &ctx->time_cost_stat.node[idx];
    init_time_cost_node(node);
    if ((node->hlist.pprev) && (node->hlist.pprev != KA_LIST_POISON2)) {
        ka_hlist_del_init(&node->hlist);
    }
    ka_task_spin_unlock(&ctx->time_cost_stat.splock);

    return node;
}

void add_time_cost_node_to_ctx(time_cost_node* node)
{
    dvpp_cmdlist_context *ctx = &g_dvpp_cmdlist_ctx;
    uint32_t key = (uint32_t)(node->taskid << 16) + (uint32_t)(node->streamid);
    ka_hlist_head_t *hlhead = &(ctx->time_cost_stat.head[key % ctx->time_cost_stat.node_num]);
    ka_task_spin_lock(&ctx->time_cost_stat.splock);

    ka_hlist_add_head(&(node->hlist), hlhead);

    ka_task_spin_unlock(&ctx->time_cost_stat.splock);
}

time_cost_node* get_time_cost_node_from_ctx(uint16_t streamid, uint16_t taskid)
{
    dvpp_cmdlist_context *ctx = &g_dvpp_cmdlist_ctx;
    time_cost_node* pos = NULL;
    time_cost_node* ret_node = NULL;
    ka_hlist_node_t* n = NULL;
    uint32_t key = (uint32_t)(taskid << 16) + (uint32_t)(streamid);
    ka_hlist_head_t *hlhead = &(ctx->time_cost_stat.head[key % ctx->time_cost_stat.node_num]);

    ka_task_spin_lock(&ctx->time_cost_stat.splock);

    ka_hlist_for_each_entry_safe(pos, n, hlhead, hlist) {
        if (pos->taskid == taskid && pos->streamid == streamid) {
            ret_node = pos;
            break;
        }
    }

    ka_task_spin_unlock(&ctx->time_cost_stat.splock);

    return ret_node;
}
