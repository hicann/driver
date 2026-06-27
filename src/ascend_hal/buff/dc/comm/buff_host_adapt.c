/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "buff_platform.h"
#include "drv_buff_adp.h"
#include "buff_feature.h"
#include "ascend_hal.h"
#include "drv_buff_log.h"

/*
 * Get destination engine type for event routing.
 * Host platform always returns CCPU_HOST.
 */
unsigned int buff_event_get_dst_engine(void)
{
    return CCPU_HOST;
}

/*
 * Set CPU affinity for buff recycle thread.
 * Host platform does not need to set CPU affinity, empty implementation.
 */
void buff_recycle_set_thread_affinity(void)
{ /* Host platform does not need to set CPU affinity */
}

/*
 * Get current device ID.
 * Host platform always returns 0.
 */
int buff_get_current_devid(void)
{
    return 0;
}

/*
 * Get the hugepage allocation policy for mbuf.
 * Host platform: query runtime feature to determine if hugepage is supported.
 */
unsigned long buff_get_mbuf_hugepage_policy(void)
{
    return BUFF_SP_HUGEPAGE_PRIOR;
}

/*
 * Check if hugepage feature is supported for memzone configuration.
 * Host platform: query runtime feature bitmap.
 */
bool buff_mz_has_hugepage(void)
{
    return true;
}

/*
 * Check if dvpp memzone is NOT supported.
 * Host platform: query runtime feature bitmap.
 */
bool buff_mz_has_no_dvpp(void)
{
    return true;
}

/*
 * Initialize platform-specific features.
 * Host platform: query runtime feature bitmap.
 */
int buff_platform_feature_init(void)
{
    drvError_t ret = buff_dev_feature_init_all();
    if (ret != DRV_ERROR_NONE) {
        buff_err("Dev feature init err. (ret=%d)\n", ret);
    }
    return (int)ret;
}
