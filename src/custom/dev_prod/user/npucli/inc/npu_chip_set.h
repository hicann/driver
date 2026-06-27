/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _NPU_CHIP_SET_H_
#define _NPU_CHIP_SET_H_
#include "npu_smi.h"

int set_chip_reset(struct npu_smi_operate_info *operate_info);
int set_chip_ssh_enable(struct npu_smi_operate_info *operate_info);
int set_chip_boot_area(struct npu_smi_operate_info *operate_info);
int set_chip_mcu_monitor(struct npu_smi_operate_info *operate_info);
int set_chip_err_count_clear(struct npu_smi_operate_info *operate_info);
int set_chip_share(struct npu_smi_operate_info *operate_info);
int set_chip_nve_level(struct npu_smi_operate_info *operate_info);
int set_chip_sec_revocation(struct npu_smi_operate_info *operate_info);
int set_disk_power(struct npu_smi_operate_info *operate_info);
int set_device_ip(struct npu_smi_operate_info *operate_info);
int set_chip_mac_addr(struct npu_smi_operate_info *operate_info);
int set_aicpu_config(struct npu_smi_operate_info *operate_info);
int set_chip_ecc_info_clear(struct npu_smi_operate_info *operate_info);
int set_chip_create_vdevice(struct npu_smi_operate_info *operate_info);
int set_chip_destroy_vdevice(struct npu_smi_operate_info *operate_info);
int set_chip_vdevice_svm(struct npu_smi_operate_info *operate_info);
int set_chip_cpu_num_config(struct npu_smi_operate_info *operate_info);
int set_chip_p2p_mem_cfg(struct npu_smi_operate_info *operate_info);
int set_p2p_mem_cfg_bar_cfg_off(struct npu_smi_operate_info *operate_info);
int set_p2p_mem_cfg_bar_cfg_on(struct npu_smi_operate_info *operate_info);
int set_power_state(struct npu_smi_operate_info *operate_info);
int set_chip_boot_sel(struct npu_smi_operate_info *operate_info);
int set_user_config(unsigned int card_id, unsigned int device_id);
int set_chip_custom_op(struct npu_smi_operate_info *operate_info);
int set_op_timeout(struct npu_smi_operate_info *operate_info);
int set_custom_op_secverify_cert(struct npu_smi_operate_info *operate_info);
int set_qos_master(struct npu_smi_operate_info *operate_info);
#endif /* _NPU_CHIP_SET_H_ */