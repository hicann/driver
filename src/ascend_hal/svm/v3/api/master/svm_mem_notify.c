/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include <pthread.h>

#include "ascend_hal.h"
#include "svm_dbi.h"
#include "svm_log.h"
#include "malloc_mng.h"
#include "svm_flag.h"

int halMemAllocVaWithNoPopulate(u32 devid, u64 size, u64 *opened_va)
{
    struct svm_malloc_location location;
    u64 start = 0;
    u64 svm_flag = 0;
    u64 align;
    int ret;

    svm_flag |= (SVM_FLAG_ATTR_VA_ONLY_WITHOUT_POPULATE | SVM_FLAG_BY_PASS_CACHE | SVM_FLAG_CAP_REGISTER_ACCESS);
    svm_flag |= SVM_FLAG_CAP_GET_ATTR;

    ret = svm_dbi_query_npage_size(devid, &align);
    if (ret != 0) {
        svm_err("svm_dbi_query_npage_size failed.(ret=%d; dev_id=%u)\n", ret, devid);
        return ret;
    }

    svm_flag_set_module_id(&svm_flag, DEVMM_MODULE_ID);

    svm_malloc_location_pack(devid, SVM_MALLOC_NUMA_NO_NODE, &location);

    ret = svm_malloc(&start, size, align, svm_flag, &location);
    if (ret != DRV_ERROR_NONE) {
        svm_err("svm_malloc failed.(ret=%d; dev_id=%u)\n", ret, devid);
        return ret;
    }

    *opened_va = start;
    svm_debug("svm alloc addr.(addr=0x%llx, size=0x%llx)\n", start, size);
    return 0;
}

void halMemFreeVaWithNoPopulate(u64 opened_va)
{
    (void)svm_free(opened_va);
}