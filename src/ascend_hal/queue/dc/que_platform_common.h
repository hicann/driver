/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef QUE_PLATFORM_COMMON_H
#define QUE_PLATFORM_COMMON_H

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>
#include "ascend_hal_error.h"

#if (defined DRV_HOST) || (defined QUEUE_UT)
#define SHAREPOOL_MEM_ADD_START 0x0000000000000000
#define SHAREPOOL_MEM_ADD_END 0xFFFFFFFFFFFFFFFF
#else
#define SHAREPOOL_MEM_ADD_START 0x0000E80000000000
#define SHAREPOOL_MEM_ADD_END 0x0000F80000000000
#endif

#ifdef DRV_HOST
/*
 * In 910B sriov/mdev:
 * devid = pf_id * MAX_VF_NUM(16) + (vfid - 1) + 100
 * pf:     devid 0   ~ devid 63
 * vf:     devid 100 ~ devid 1123
 * rsv:    devid 64  ~ devid 99
 */
#define MAX_DEVICE 1124
#else
/*
 * In 910B sriov/mdev:
 * pf:     devid 0   ~ devid 31
 * vf:     devid 32  ~ devid 63
 */
#define MAX_DEVICE 64
#endif

/* Forward declarations */
struct buff_iovec;
struct que_ctx;
struct que_tgt_proc;
struct que_node;
struct que_pkt;
struct queue_manages;

#define MAX_RES_TYPE 5
typedef int (*que_ub_res_alloc)(struct que_ctx *ctx, unsigned int d2d_flag);
typedef void (*que_ub_res_free)(struct que_ctx *ctx, unsigned int d2d_flag);

#endif /* QUE_PLATFORM_COMMON_H */
