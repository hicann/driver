/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "ascend_kernel_hal.h"
#include "xsmem_framework_platform.h"
#include "pbl/pbl_uda.h"
#include "xsmem_framework_log.h"
#include "xsmem_feature_check.h"
#include "xsmem_algo_cache_vma.h"
#include "xsmem_framework.h"

#define BUFF_HOST_NOTIFIER "buff_host"

/*
 * Register pool algorithms for the host platform.
 * Only VMA-based algorithms are registered here; SP algorithms are
 * not included because their availability is determined at runtime
 * via the feature check system (buff_has_feature / xsmem_feature_check).
 * The CFG_FEATURE_SUPPORT_SP compile-time switch has been replaced
 * by the runtime feature check mechanism.
 */
static void xsmem_algo_register(void)
{
    xsmem_register_algo(xsm_get_vma_algo());
    xsmem_register_algo(xsm_get_cache_vma_algo());
}

static void buff_host_notifier_unregister(void)
{
    struct uda_dev_type type;
    uda_davinci_near_real_entity_type_pack(&type);
    (void)uda_notifier_unregister(BUFF_HOST_NOTIFIER, &type);
    xsmem_info("Buff host notifier unregistered.\n");
}

void xsmem_dev_unreg(void)
{
    buff_host_notifier_unregister();
    xsmem_dev_unreg_external();
    buff_feature_uninit();
}

static int buff_host_notifier_func(u32 udevid, enum uda_notified_action action)
{
    int ret = 0;
    xsmem_info("Buff host notifier: device init. (udevid=%u, action=%d)\n", udevid, action);
    switch (action) {
        case UDA_INIT:
            ret = buff_feature_init_by_devid(udevid);
            if (ret != 0) {
                xsmem_err("Failed to init buff feature by devid %u, ret=%d\n", udevid, ret);
                return ret;
            }
            break;
        default:
            break;
    }
    return ret;
}

int xsmem_dev_reg(void)
{
    struct uda_dev_type type;
    int ret;

    buff_feature_system_init();

    uda_davinci_near_real_entity_type_pack(&type);
    ret = uda_notifier_register(BUFF_HOST_NOTIFIER, &type, UDA_PRI3, buff_host_notifier_func);
    if (ret != 0) {
        xsmem_err("Failed to register buff host notifier. (ret=%d)\n", ret);
        return ret;
    }
    ret = xsmem_dev_reg_external();
    if (ret != 0) {
        return ret;
    }
    xsmem_algo_register();
    xsmem_info("Buff host notifier registered successfully.\n");
    return 0;
}
