/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include <string.h>
#include "securec.h"
#include "buff_feature.h"
#include "buff_manage_kernel_api.h"
#include "drv_buff_log.h"

static unsigned long long g_buff_dev_feature[BUFF_FEATURE_DEV_NUM] = {0};

drvError_t buff_dev_feature_init_all(void)
{
    static struct xsm_feature_get_arg all_features;
    drvError_t ret;

    ret = buff_pool_feature_get_all(&all_features);
    if (ret != DRV_ERROR_NONE) {
        buff_err("buff_dev_feature_init_all: query all features failed. (ret=%d)\n", ret);
        return ret;
    }
    (void)memcpy_s(g_buff_dev_feature, sizeof(g_buff_dev_feature), all_features.feature_bitmaps,
                   sizeof(all_features.feature_bitmaps));
    return DRV_ERROR_NONE;
}

bool buff_has_dev_feature(unsigned int dev_id, unsigned int feature_id)
{
    if (dev_id >= BUFF_FEATURE_DEV_NUM) {
        buff_err("Invalid dev_id. (dev_id=%u; max=%u)\n", dev_id, BUFF_FEATURE_DEV_NUM);
        return false;
    }
    if (feature_id >= BUFF_FEATURE_NUM) {
        buff_err("Invalid feature_id. (feature_id=%u; max=%u)\n", feature_id, BUFF_FEATURE_NUM);
        return false;
    }
    return (g_buff_dev_feature[dev_id] & (1ULL << feature_id)) != 0;
}
