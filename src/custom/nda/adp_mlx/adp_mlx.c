/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 *
 * File Name     : adp_mlx.c
 * Description   : mlx5 adapter driver for ibv_extend, implements modify_qp callback
 */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <infiniband/verbs.h>
#include <infiniband/mlx5dv.h>
#include "ibv_extend.h"

static int driver_modify_qp(struct ibv_context *context, struct ibv_qp_attr_extend *attr, int attr_mask)
{
    (void)context;

    if (attr == NULL || attr->qp == NULL) {
        syslog(LOG_ERR, "modify_qp: invalid parameter, attr or qp is NULL");
        errno = EINVAL;
        return -1;
    }

    if (!(attr_mask & IBV_QP_ATTR_EXTEND_UDP_SRC_PORT)) {
        syslog(LOG_ERR, "modify_qp: attr_mask 0x%x does not include UDP_SRC_PORT", attr_mask);
        errno = EOPNOTSUPP;
        return -1;
    }

    if (attr->udp_src_port == 0 || attr->udp_src_port > 0xFFFF) {
        syslog(LOG_ERR, "modify_qp: udp_src_port %u out of range (1-65535)", attr->udp_src_port);
        errno = EINVAL;
        return -1;
    }

    return mlx5dv_modify_qp_udp_sport(attr->qp, (uint16_t)attr->udp_src_port);
}

static struct ibv_context_extend_ops adp_mlx_ops = {
    .version = IBV_EXTEND_DRIVER_VERSION_V2,
    .modify_qp = driver_modify_qp,
};

static struct ibv_context_extend *adp_mlx_alloc_context(struct ibv_context *context)
{
    struct ibv_context_extend *ctx_extend;

    ctx_extend = (struct ibv_context_extend *)calloc(1, sizeof(struct ibv_context_extend));
    if (!ctx_extend) {
        syslog(LOG_ERR, "alloc_context: out of memory");
        return NULL;
    }
    ctx_extend->context = context;
    ctx_extend->ops = &adp_mlx_ops;

    return ctx_extend;
}

static void adp_mlx_free_context(struct ibv_context_extend *context)
{
    if (context) {
        free(context);
    }
}

static const struct verbs_device_extend_ops adp_mlx_driver_ops = {
    .name = "mlx5",
    .alloc_context = adp_mlx_alloc_context,
    .free_context = adp_mlx_free_context,
};

PROVIDER_EXTEND_DRIVER(adp_mlx_driver_ops)
