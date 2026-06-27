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

#include "svm_sub_event_type_uk_msg.h"
#include "mwl_uk_msg.h"
#include "svm_umc_server.h"

static int svm_mwl_proc_func(u32 devid, const void *msg_in, void *msg_out)
{
    SVM_UNUSED(devid);
    SVM_UNUSED(msg_in);
    SVM_UNUSED(msg_out);

    return 0;
}

SVM_EVENT_PROC_REGISTER(SVM_MWL_OP_EVENT, svm_mwl_proc_func, (u64)sizeof(struct svm_mwl_op_msg), 0);
