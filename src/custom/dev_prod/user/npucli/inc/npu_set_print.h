/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_SET_PRINT_H__
#define __NPU_SET_PRINT_H__

#include "npu_set.h"

void print_reset_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info);
void print_ssh_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info);
void print_result(int ret, struct npu_smi_operate_info *operate_info, SET_TYPE_E type_index, int need_reset);
void print_work_tops_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info);
void print_cpu_num_cfg_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info);
void print_vnpu_mode_check_result(int ret, struct npu_smi_operate_info *operate_info);
int show_reset_risk(void);
int show_reset_vnpu_risk(void);
int show_device_share_risk(void);
int show_multi_die_policy_risk(void);
int show_multi_die_policy_config_recover_risk(void);
int show_device_share_risk_for_chip(void);
int show_msn_permanent_risk(void);
int show_custom_op_risk(void);
int show_custom_op_secverify_enable_risk(void);
int show_op_timeout_risk(void);
int show_device_share_config_recover_risk(void);
int show_qos_master_config_risk(void);
void show_power_state_status(struct npu_smi_operate_info *operate_info);
void print_mac_addr_result(int ret, struct npu_smi_operate_info *operate_info);
void print_p2p_mem_cfg_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info);
void print_bootsel_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info);
void print_cpu_freq_up_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info);
#endif /* __NPU_SET_PRINT_H__ */