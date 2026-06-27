/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include "ascend_hal.h"
#include "securec.h"

#include "svm_pub.h"
#include "svm_log.h"
#include "svm_addr_desc.h"
#include "svm_dbi.h"
#include "va_allocator.h"
#include "malloc_mng.h"
#ifdef CFG_FEATURE_SUPPORT_UB
#include "svm_urma_seg_mng.h"

/* to-do: tsdrv call, delete later, let tsdrv call get token info */
int halMemGetSeg(uint32_t devid, uint64_t va, uint64_t size, urma_seg_t *seg, urma_token_t *token)
{
    struct svm_dst_va dst_va;
    struct svm_prop prop, pre_prop;
    urma_seg_t tmp_seg, pre_seg;
    u32 token_id, token_val, pre_token_id, pre_token_val;
    u32 user_devid;
    u64 tmp_va;
    int ret;

    if ((devid >= SVM_MAX_AGENT_NUM) || (seg == NULL) || (token == NULL)) {
        svm_err("Invalid para. (devid=%u; seg_is_null=%d; token_is_null=%d)\n", devid, (seg == NULL), (token == NULL));
        return DRV_ERROR_INVALID_VALUE;
    }

    if (svm_va_is_in_range(va, size) == false) {
        svm_err("Invalid va. (va=0x%llx; size=%llu)\n", va, size);
        return DRV_ERROR_INVALID_VALUE;
    }

    for (tmp_va = va; tmp_va < (va + size); tmp_va = (prop.start + prop.size)) {
        ret = svm_get_prop(tmp_va, &prop);
        if (ret != 0) {
            svm_err("Get prop failed. (va=0x%llx)\n", tmp_va);
            return ret;
        }

        if (prop.devid == SVM_INVALID_DEVID) {
            svm_err("Invalid va. (va=0x%llx)\n", tmp_va);
            return DRV_ERROR_INVALID_VALUE;
        }

        user_devid = (prop.devid == svm_get_host_devid()) ? devid : svm_get_host_devid();
        svm_dst_va_pack(prop.devid, PROCESS_CP1, prop.start, prop.size, &dst_va);
        ret = svm_urma_get_seg_with_token_info(user_devid, &dst_va, &tmp_seg, &token_id, &token_val);
        if (ret != DRV_ERROR_NONE) {
            svm_err(
                "Get svm_urma_seg failed. (user_devid=%u; devid=%u; va=0x%llx; size=%llu)\n", user_devid, dst_va.devid,
                dst_va.va, dst_va.size);
            return ret;
        }

        if ((tmp_va != va) && ((memcmp(&pre_seg, &tmp_seg, sizeof(urma_seg_t)) != 0) || (pre_token_id != token_id) ||
                               (pre_token_val != token_val) || (pre_prop.devid != prop.devid))) {
            svm_err("The va prop is not match. (va=0x%llx; tmp_va=0x%llx; size=0x%llx)\n", va, tmp_va, size);
            return DRV_ERROR_INVALID_VALUE;
        }

        pre_seg = tmp_seg;
        pre_token_id = token_id;
        pre_token_val = token_val;
        pre_prop = prop;
    }

    *seg = tmp_seg;
    token->token = token_val;
    return DRV_ERROR_NONE;
}
#endif
