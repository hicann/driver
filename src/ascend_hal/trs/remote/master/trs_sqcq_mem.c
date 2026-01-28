/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "ascend_hal_error.h"

#include "trs_user_interface.h"
#include "trs_user_pub_def.h"
#include "trs_sqcq.h"
#include "trs_sq_mem_raw.h"
#include "trs_sq_mem_cache.h"

static bool trs_sq_mem_is_from_cache(uint32_t devid, uint64_t va, uint64_t size)
{
    int ret = trs_sq_mem_cache_check_exists(devid, va, size);
    return (ret == DRV_ERROR_NONE);
}

static int trs_sq_mem_alloc(uint32_t devid, uint64_t *va, uint64_t size)
{
    int ret = trs_sq_mem_cache_alloc(devid, va, size);
    if ((ret == DRV_ERROR_NOT_SUPPORT) || (ret == DRV_ERROR_NO_RESOURCES)) {
        ret = trs_sq_mem_raw_alloc(devid, va, size);
    }

    return ret;
}

static void trs_sq_mem_free(uint32_t devid, uint64_t va, uint64_t size)
{
    if (trs_sq_mem_is_from_cache(devid, va, size)) {
        (void)trs_sq_mem_cache_free(devid, va, size);
    } else {
        trs_sq_mem_raw_free(devid, va);
    }
}

#ifndef EMU_ST
static int __attribute__((constructor)) trs_sqcq_mem_construct(void)
{
    struct trs_sqcq_mem_ops sqcq_mem_ops = {NULL};

    sqcq_mem_ops.mem_alloc = trs_sq_mem_alloc;
    sqcq_mem_ops.mem_free = trs_sq_mem_free;
    trs_register_sqcq_mem_ops(&sqcq_mem_ops);

    trs_info("Register Sqcq mem ops succeeded.\n");
    return 0;
}
#else
int trs_sqcq_mem_construct(void)
{
    struct trs_sqcq_mem_ops sqcq_mem_ops = {NULL};

    sqcq_mem_ops.mem_alloc = trs_sq_mem_alloc;
    sqcq_mem_ops.mem_free = trs_sq_mem_free;
    trs_register_sqcq_mem_ops(&sqcq_mem_ops);

    trs_info("Register Sqcq mem ops succeeded.\n");
    return 0;
}

void trs_sqcq_mem_un_construct(void)
{
    struct trs_sqcq_mem_ops sqcq_mem_ops = {NULL};
    trs_register_sqcq_mem_ops(&sqcq_mem_ops);
    trs_info("Unregister Sqcq mem ops succeeded.\n");
}
#endif
