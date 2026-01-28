/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef TRS_SQ_MEM_CACHE_H
#define TRS_SQ_MEM_CACHE_H

#include <stdint.h>

/* DRV_ERROR_NO_RESOURCES: no enough memory in cache. */
int trs_sq_mem_cache_alloc(uint32_t devid, uint64_t *va, uint64_t size);
int trs_sq_mem_cache_free(uint32_t devid, uint64_t va, uint64_t size);
int trs_sq_mem_cache_check_exists(uint32_t devid, uint64_t va, uint64_t size);

#endif