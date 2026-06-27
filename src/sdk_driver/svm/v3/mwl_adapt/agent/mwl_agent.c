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

#include "pbl_feature_loader.h"
#include "dpa_kernel_interface.h"

#include "ascend_kernel_hal.h"
#include "svm_kern_log.h"
#include "kmc_h2d.h"
#include "mwl.h"
#include "mwl_msg.h"

static int mwl_agent_op(u32 udevid, void *msg, u32 *reply_len)
{
    struct mwl_op_msg *msg_info = (struct mwl_op_msg *)msg;
    u32 master_tgid;
    int ret;

    *reply_len = sizeof(struct mwl_op_msg);

    ret = devdrv_query_master_pid_by_device_slave(udevid, msg_info->devpid, &master_tgid);
    if (ret != 0) {
        svm_err("Not apm bind proc. (udevid=%u; devpid=%d; ret=%d)\n", udevid, msg_info->devpid, ret);
        return -EPERM;
    }

    if ((msg_info->size == 0) || (msg_info->va + msg_info->size < msg_info->va)) {
        svm_err(
            "Invalid va or size. (udevid=%u; devpid=%d; va=0x%llx; size=%llu)\n", udevid, msg_info->devpid,
            msg_info->va, msg_info->size);
        return -EINVAL;
    }

    if (msg_info->flag == SVM_ADDR_WHITELIST_ADD) {
        return svm_mwl_add_mem(udevid, master_tgid, MWL_ID_NO_USE, msg_info->va, msg_info->size);
    } else if (msg_info->flag == SVM_ADDR_WHITELIST_DEL) {
        return svm_mwl_del_mem(udevid, master_tgid, MWL_ID_NO_USE, msg_info->va, msg_info->size);
    }

    svm_err(
        "Invalid flag. (udevid=%u; devpid=%d; va=0x%llx; size=%llu; flag=%llu)\n", udevid, msg_info->devpid,
        msg_info->va, msg_info->size, msg_info->flag);
    return -EINVAL;
}

static struct svm_kmc_d2h_recv_handle g_d2h_mwl_op_handle = {
    .func = mwl_agent_op, .raw_msg_size = sizeof(struct mwl_op_msg), .extend_gran_size = 0};

static int mwl_agent_init(void)
{
    svm_kmc_d2h_recv_handle_register(SVM_KMC_MSG_MWL_OP, &g_d2h_mwl_op_handle);
    return 0;
}
DECLAER_FEATURE_AUTO_INIT(mwl_agent_init, FEATURE_LOADER_STAGE_3);
