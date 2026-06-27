/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef XSMEM_FRAMEWORK_PLATFORM_H
#define XSMEM_FRAMEWORK_PLATFORM_H
#include "xsmem_algo_vma.h"

int xsmem_dev_reg(void);
struct xsm_pool_algo *xsm_get_cache_vma_algo(void);
struct xsm_pool_algo *xsm_get_sp_algo(void);
void xsmem_dev_unreg(void);
#endif /* XSMEM_FRAMEWORK_PLATFORM_H */
