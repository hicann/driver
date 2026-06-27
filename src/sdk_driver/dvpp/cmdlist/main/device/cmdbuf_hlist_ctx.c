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

#include "ka_list_pub.h"
#include "ka_share_pool.h"
#include "cmdbuf_hlist_ctx.h"
#include "dvpp_cmdlist_define.h"
#include "dvpp_cmdlist_log.h"

typedef struct {
    cmdbuf_context ctx;
    ka_hlist_node_t node;
} cmdbuf_hlist_ctx;

int32_t add_cmdbuf_hlist(cmdbuf_context *ctx, dvpp_cmdlist_private_data *data)
{
    cmdbuf_hlist_ctx *hlist_ctx = NULL;
    uint32_t ctx_size = sizeof(cmdbuf_hlist_ctx);
    ka_hlist_head_t *head = &(data->head);

    hlist_ctx = (cmdbuf_hlist_ctx *)kzalloc(ctx_size, GFP_KERNEL);
    if (hlist_ctx == NULL) {
        DVPP_CMDLIST_LOG_ERROR("kzalloc size %d failed\n", ctx_size);
        return -1;
    }
    hlist_ctx->ctx = *ctx;

    down_write(&(data->rw_sem));
    KA_INIT_HLIST_NODE(&(hlist_ctx->node));
    ka_hlist_add_head(&(hlist_ctx->node), head);
    up_write(&(data->rw_sem));
    DVPP_CMDLIST_LOG_DEBUG("add hlist pid %d, chn %u, uva %#x, kva %#x, size %u\n",
        ctx->pid, ctx->chn, (uint32_t)GET_LOW_ADDR(ctx->uva), (uint32_t)GET_LOW_ADDR(ctx->kva), ctx->size);
    return 0;
}

uint64_t search_cmdbuf_hlist(pid_t pid, uint32_t chn, uint64_t uva, dvpp_cmdlist_private_data *data)
{
    cmdbuf_hlist_ctx *hlist_ctx = NULL;
    uint64_t kva = 0;
    ka_hlist_head_t *head = &(data->head);

    down_read(&(data->rw_sem));

    ka_hlist_for_each_entry(hlist_ctx, head, node) {
        if ((hlist_ctx->ctx.pid == pid) && (hlist_ctx->ctx.chn == chn) && (hlist_ctx->ctx.uva == uva)) {
            break;
        }
    }
    if (hlist_ctx == NULL) {
        up_read(&(data->rw_sem));
        return 0;
    }
    kva = hlist_ctx->ctx.kva;

    up_read(&(data->rw_sem));

    return kva;
}

void del_cmdbuf_hlist(pid_t pid, dvpp_cmdlist_private_data *data)
{
    cmdbuf_hlist_ctx *hlist_ctx = NULL;
    int32_t ret;
    const int32_t spg_id = 0; // unshare kva, spg_id is not used
    ka_hlist_head_t *head = &(data->head);
    ka_hlist_node_t *n = NULL;

    down_write(&(data->rw_sem));
    ka_hlist_for_each_entry_safe(hlist_ctx, n, head, node) {
        if (hlist_ctx->ctx.pid == pid) {
            DVPP_CMDLIST_LOG_DEBUG("del hlist pid %d, chn %u, uva %#x, kva %#x, size %u\n",
                hlist_ctx->ctx.pid, hlist_ctx->ctx.chn, (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.uva),
                (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.kva), hlist_ctx->ctx.size);
            ret = ka_mg_sp_unshare(hlist_ctx->ctx.kva, hlist_ctx->ctx.size, spg_id);
            if (ret != 0) {
                DVPP_CMDLIST_LOG_ERROR("unshare kva failed, ret %d, hlist pid %d, chn %u, uva %#x, kva %#x, size %u\n",
                    ret, hlist_ctx->ctx.pid, hlist_ctx->ctx.chn, (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.uva),
                    (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.kva), hlist_ctx->ctx.size);
            }
            ka_hlist_del(&(hlist_ctx->node));
            kfree(hlist_ctx);
            hlist_ctx = NULL;
        }
    }
    up_write(&(data->rw_sem));
}

void del_chn_cmdbuf_hlist(pid_t pid, uint32_t chn, dvpp_cmdlist_private_data *data)
{
    cmdbuf_hlist_ctx *hlist_ctx = NULL;
    int32_t ret;
    const int32_t spg_id = 0; // unshare kva, spg_id is not used
    ka_hlist_head_t *head = &(data->head);
    ka_hlist_node_t *n = NULL;

    down_write(&(data->rw_sem));
    ka_hlist_for_each_entry_safe(hlist_ctx, n, head, node) {
        if ((hlist_ctx->ctx.pid == pid) && (hlist_ctx->ctx.chn == chn)) {
            DVPP_CMDLIST_LOG_DEBUG("del hlist pid %d, chn %u, uva %#x, kva %#x, size %u\n",
                hlist_ctx->ctx.pid, hlist_ctx->ctx.chn, (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.uva),
                (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.kva), hlist_ctx->ctx.size);

            ret = ka_mg_sp_unshare(hlist_ctx->ctx.kva, hlist_ctx->ctx.size, spg_id);
            if (ret != 0) {
                DVPP_CMDLIST_LOG_ERROR("unshare kva failed, ret %d, hlist pid %d, chn %u, uva %#x, kva %#x, size %u\n",
                    ret, hlist_ctx->ctx.pid, hlist_ctx->ctx.chn, (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.uva),
                    (uint32_t)GET_LOW_ADDR(hlist_ctx->ctx.kva), hlist_ctx->ctx.size);
            }
            ka_hlist_del(&(hlist_ctx->node));
            kfree(hlist_ctx);
            hlist_ctx = NULL;
        }
    }
    up_write(&(data->rw_sem));
}