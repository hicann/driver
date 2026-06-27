/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _NPU_CHIP_INFO_H_
#define _NPU_CHIP_INFO_H_

#include "npu_smi.h"

int query_chip_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_board_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_volt_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_temp_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_power_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_health_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_memory_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_flash_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_ssh_enable_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_ecc_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_err_count_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_pcie_error_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_device_share_info(struct npu_smi_operate_info *operate_info);
int show_chip_product_type(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_ecc_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_proc_mem_info(struct npu_smi_operate_info *operate_info);
int show_key_manage_info(struct npu_smi_operate_info *operate_info);
int npu_get_chip_firmware_version(int card_id, int chip_id, unsigned char *version_str, int len);
int npu_get_chip_common_info(int card_id, int chip_id, struct npu_chip_common_info *chip_common_info);
bool check_result_for_dcmi_get_device_aicore_info(void);
bool check_result_for_npu_get_hbm_info(enum npu_chip_type chip_type);
bool check_result_for_npu_get_chip_common_info_for_910(void);
int show_ascend_chip_health_state(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_p2p_mem_cfg_status(struct npu_smi_operate_info *operate_info);
int get_ascend_chip_board_info(struct npu_smi_operate_info *operate_info, struct npu_chip_info *chip_info,
    enum dcmi_unit_type *dev_type);
int get_pid_name(int pid, char *name, int name_len);
int get_env_offset_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_mac_addr_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_sensor_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_sys_time_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_phyid_remap_info(struct npu_smi_operate_info *operate_info);
#endif /* _NPU_CHIP_INFO_H_ */