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
#include "pbl_uda.h"

#include "ascend_kernel_hal.h"

#include "svm_sub_event_type_uk_msg.h"
#include "mwl_uk_msg.h"
#include "svm_um_handle.h"
#include "svm_kern_log.h"
#include "mwl.h"

static int mwl_op_pre_handle(u32 udevid, int master_tgid, int slave_tgid, void *msg, u32 msg_len)
{
    struct svm_mwl_op_msg *op_msg = (struct svm_mwl_op_msg *)msg;

    if ((msg_len != sizeof(*op_msg)) || (udevid == uda_get_host_id())) {
        svm_err(
            "Invalid para. (udevid=%u; master_tgid=%d; slave_tgid=%d; msg_len=%u)\n", udevid, master_tgid, slave_tgid,
            msg_len);
        return -EINVAL;
    }

    if ((op_msg->size == 0) || (op_msg->va + op_msg->size < op_msg->va)) {
        svm_err(
            "Invalid va/size. (udevid=%u; master_tgid=%d; va=0x%llx; size=%llu)\n", udevid, master_tgid, op_msg->va,
            op_msg->size);
        return -EINVAL;
    }

    if (op_msg->flag == SVM_ADDR_WHITELIST_ADD) {
        return svm_mwl_add_mem(udevid, master_tgid, MWL_ID_NO_USE, op_msg->va, op_msg->size);
    } else if (op_msg->flag == SVM_ADDR_WHITELIST_DEL) {
        return svm_mwl_del_mem(udevid, master_tgid, MWL_ID_NO_USE, op_msg->va, op_msg->size);
    }

    svm_err(
        "Invalid flag. (udevid=%u; master_tgid=%d; slave_tgid=%d; msg_len=%u; flag=%llu)\n", udevid, master_tgid,
        slave_tgid, msg_len, op_msg->flag);
    return -EINVAL;
}

static int mwl_um_handle_init(void)
{
    svm_um_register_handle(SVM_MWL_OP_EVENT, mwl_op_pre_handle, NULL, NULL);
    return 0;
}
DECLAER_FEATURE_AUTO_INIT(mwl_um_handle_init, FEATURE_LOADER_STAGE_4);