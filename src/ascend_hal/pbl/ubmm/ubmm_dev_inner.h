/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef UBMEM_DEV_INNER_H
#define UBMEM_DEV_INNER_H

#ifndef EMU_ST
#include "dmc_user_interface.h"
#else
#include "ascend_inpackage_hal.h"
#include "ut_log.h"
#endif

#define ubmem_err(fmt, ...) DRV_ERR(HAL_MODULE_TYPE_DEVMM, fmt, ##__VA_ARGS__)
#define ubmem_warn(fmt, ...) DRV_WARN(HAL_MODULE_TYPE_DEVMM, fmt, ##__VA_ARGS__)
#define ubmem_info(fmt, ...) DRV_INFO(HAL_MODULE_TYPE_DEVMM, fmt, ##__VA_ARGS__)

#define ubmem_err_if(cont, fmt, ...) do { \
    if (cont) { \
        ubmem_err(fmt, ##__VA_ARGS__); \
    } \
} while (0)

#endif