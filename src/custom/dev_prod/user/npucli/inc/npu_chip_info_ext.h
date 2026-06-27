/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _NPU_CHIP_INFO_EXT_H_
#define _NPU_CHIP_INFO_EXT_H_

#include "npu_smi.h"

int show_ascend_chip_spod_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_sio_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_cpu_freq_up_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_hccs_avail_credit_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_cpu_num_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_custom_op_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_current_fault_event_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_usages_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_custom_op_secverify_enable_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_custom_op_secverify_mode_info(struct npu_smi_operate_info *operate_info);
int show_ascend_op_timeout_info(struct npu_smi_operate_info *operate_info);
int show_custom_op_secverify_cert_info(struct npu_smi_operate_info *operate_info);
#endif