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

#include "ka_task_pub.h"
#include "pbl/pbl_ubmm.h"
#include "comm_msg_chan.h"

#include "svm_kern_log.h"
#include "ubmm_usage_counter.h"

void ubmm_usage_counter_inc(u32 udevid, int tgid)
{
    struct ubmm_ctx *ctx = NULL;
    int ret = 0;

    ctx = ubmm_ctx_get(udevid, tgid);
    if (ctx == NULL) {
        return;
    }

    if (ctx->ubdev_task_added == false) {
        ret = ubmem_dev_add_task(udevid, tgid);
        if (ret == 0) {
            ctx->ubdev_task_added = true;
        }
    }

    ubmm_ctx_put(ctx);
}

void ubmm_usage_counter_recycle(struct ubmm_ctx *ctx)
{
    bool is_idle = false;
    int ret;

    if (ctx->ubdev_task_added == false) {
        return;
    }
    ctx->ubdev_task_added = false;

    ret = ubmem_dev_delete_task(ctx->udevid, ctx->tgid, &is_idle);
    if (ret != 0) {
        svm_warn("ubmem_dev_delete_task failed, ignore. (ret=%d; udevid=%u; tgid=%d)\n", ret, ctx->udevid, ctx->tgid);
        return;
    }

    if ((is_idle == false) || (ubmem_dev_is_fault(ctx->udevid) == false)) {
        return;
    }
    /* A repapir message can be sent only when no one is using ubmem and there is a ubmem fault */
    ret = devdrv_send_vdm_msg(ctx->udevid);
    if (ret != 0) {
        svm_warn("msg_chan_repair_ubmem failed, ignore. (ret=%d; udevid=%u)\n", ret, ctx->udevid);
    }
}