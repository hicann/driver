/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "svm_log.h"
#include "svm_dbi.h"
#include "svm_init_pri.h"
#include "svm_criu.h"
#include "svm_ioctl_api.h"
#include "svm_mmap.h"

static int svm_sys_cmd_criu_reset(u32 devid, void *data)
{
    int ret;

    SVM_UNUSED(data);

    ret = svm_ioctl_criu_reset(devid);
    if (ret != DRV_ERROR_NONE) {
        svm_err("Reset ioctl failed. (devid=%u; ret=%d)\n", devid, ret);
        return ret;
    }

    if (devid == svm_get_host_devid()) {
        svm_mmap_criu_reset();
    }

    return DRV_ERROR_NONE;
}

static const struct svm_criu_ops g_sys_cmd_criu_ops = {
    .name = "sys_cmd",
    .reset = svm_sys_cmd_criu_reset,
};

static void __attribute__((constructor(SVM_INIT_PRI_FISRT))) svm_sys_cmd_init(void)
{
    int ret;

    ret = svm_criu_register_ops(&g_sys_cmd_criu_ops);
    if (ret != DRV_ERROR_NONE) {
        svm_err("Register CRIU ops failed.\n");
    }
}
