/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef UT_TEST
#include "prof_adapt.h"
#include "prof_adapt_user.h"
#include "prof_adapt_kernel.h"
#include "prof_common.h"

static struct prof_adapt_core_notifier g_adapt_core_notifier = {NULL};

void prof_adapt_register_notifier(struct prof_adapt_core_notifier *notifier)
{
    g_adapt_core_notifier.poll_report = notifier->poll_report;
    g_adapt_core_notifier.chan_report = notifier->chan_report;
}

struct prof_adapt_core_notifier *prof_adapt_get_notifier(void)
{
    return &g_adapt_core_notifier;
}

drvError_t prof_adapt_register_channel(uint32_t dev_id, uint32_t chan_id, struct prof_sample_register_para *para)
{
    return prof_user_register_channel(dev_id, chan_id, para);
}

drvError_t prof_adapt_get_channels(uint32_t dev_id, struct prof_channel_list *channels)
{
    return prof_kernel_get_channels(dev_id, channels);
}

drvError_t prof_adapt_get_chan_ops(uint32_t dev_id, uint32_t chan_mode, struct prof_chan_ops **ops)
{
#ifdef CFG_SOC_PLATFORM_CLOUD_V4
    HAL_CC_INFO cc_info = {0};
    int size = sizeof(HAL_CC_INFO);
    drvError_t ret = halGetDeviceInfoByBuff(dev_id, MODULE_TYPE_CC, INFO_TYPE_CC, &cc_info, &size);
    if (ret != DRV_ERROR_NOT_SUPPORT) {
        if (ret != 0) {
            PROF_ERR("Failed to halGetDeviceInfoByBuff. (ret = %u)\n", ret);
            return PROF_ERROR;
        }
        if (cc_info.cc_cfg_info.cc_mode == HAL_CC_MODE_NORMAL) {
            PROF_INFO("CPU is currently in confidential computing mode, and prof drv is disable.\n");
            return PROF_NOT_SUPPORT;
        }
    }
#endif
    if (chan_mode == PROF_CHAN_MODE_USER) {
        return prof_user_get_chan_ops(ops);
    } else {
        return prof_kernel_get_chan_ops(dev_id, ops);
    }
}

#else
int prof_adapt_ut_test(void)
{
    return 0;
}
#endif
