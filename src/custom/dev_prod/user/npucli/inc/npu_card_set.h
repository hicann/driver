/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _NPU_CARD_SET_H_
#define _NPU_CARD_SET_H_
#include "npu_smi.h"

int set_tls_cert(struct npu_smi_operate_info *operate_info);
int set_tls_cert_period(struct npu_smi_operate_info *operate_info);
int set_card_ecc_enable(struct npu_smi_operate_info *operate_info);
int set_card_reset(struct npu_smi_operate_info *operate_info);
int set_card_ssh_enable(struct npu_smi_operate_info *operate_info);
int set_card_collect_log(struct npu_smi_operate_info *operate_info);
int set_card_customized_info(struct npu_smi_operate_info *operate_info);
int set_card_err_count_clear(struct npu_smi_operate_info *operate_info);
int set_card_share(struct npu_smi_operate_info *operate_info);
int set_card_sec_revocation(struct npu_smi_operate_info *operate_info);
int set_card_ecc_info_clear(struct npu_smi_operate_info *operate_info);
int set_card_cpu_num_config(struct npu_smi_operate_info *operate_info);
int set_card_vnpu_config(struct npu_smi_operate_info *operate_info);
int set_card_nve_level(struct npu_smi_operate_info *operate_info);
int set_card_boot_sel(struct npu_smi_operate_info *operate_info);
int set_card_reset_vnpu(struct npu_smi_operate_info *operate_info);
int reset_vnpu_para_check(struct npu_smi_operate_info *operate_info);
int set_card_cpu_freq_up_cfg(struct npu_smi_operate_info *operate_info);
int set_card_custom_op(struct npu_smi_operate_info *operate_info);
int set_card_custom_op_secverify_enable(struct npu_smi_operate_info *operate_info);
int set_card_custom_op_secverify_mode(struct npu_smi_operate_info *operate_info);
int set_card_custom_op_secverify_cert(struct npu_smi_operate_info *operate_info);
#endif /* _NPU_CARD_SET_H_ */