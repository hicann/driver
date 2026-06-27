/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _NPU_PARAMETER_PARSE_H_
#define _NPU_PARAMETER_PARSE_H_

#ifdef ORIENT_CH
#define STYPE_CMD_HCCS "xlink"
#else
#define STYPE_CMD_HCCS "hccs"
#endif

int parse_upgrade_help_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int check_para_i_is_support(unsigned int index);

int check_para_c_is_support(unsigned int index);

int check_para_d_is_support(unsigned int index);

int check_para_f_is_support(unsigned int index);

int check_para_m_is_support(unsigned int index);

int check_para_s_is_support(unsigned int index);

int check_para_v_is_support(unsigned int index);

int check_para_p_is_support(unsigned int index);

int check_para_g_is_support(unsigned int index);

void init_para_support_map(void);

int parse_type_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_card_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_chip_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_watch_type_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_watch_delay_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_chip_all_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_chip_lane_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_chip_mapping_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_help_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_phyid_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_profiling_time_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

/* 设置功能参数解析 */
int parse_str_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_enable_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_chan_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_multi_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_virgroup_id_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_sdata_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

/* 升级功能参数解析 */
int parse_upgrade_type_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_mcu_file_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_upgrade_query_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_upgrade_version_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_upgrade_active_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);

int parse_chip_hccs_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);
#endif /* _NPU_PARAMETER_PARSE_H_ */