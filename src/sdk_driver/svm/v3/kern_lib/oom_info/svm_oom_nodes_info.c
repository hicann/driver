/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/oom.h>

#include "ka_base_pub.h"

#include "pbl_feature_loader.h"

#include "svm_gfp.h"
#include "svm_kern_log.h"

#define SVM_OOM_NOTIFY_INTERVAL_SEC 120U
#define SVM_OOM_NOTIFY_BURST 3U

static KA_BASE_DEFINE_RATELIMIT_STATE(svm_oom_print_rs, SVM_OOM_NOTIFY_INTERVAL_SEC *KA_HZ, SVM_OOM_NOTIFY_BURST);

static void svm_oom_print_nodes_info(void)
{
    if (!__ka_base_ratelimit(&svm_oom_print_rs)) {
        return;
    }

    (void)oom_type_notifier_call(OOM_TYPE_CGROUP, NULL);
}

int svm_oom_nodes_info_init(void)
{
    svm_register_print_nodes_info_ops(svm_oom_print_nodes_info);
    return 0;
}
DECLAER_FEATURE_AUTO_INIT(svm_oom_nodes_info_init, FEATURE_LOADER_STAGE_0);
