/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_INFO_PRINT_H__
#define __NPU_INFO_PRINT_H__

#include "npu_common.h"
#include "npu_info.h"

#define TEMPERATURE_NUM_LEN     1
#define TEMPERATURE_NAME_LEN    8
#define TEMPERATURE_VALUE_LEN   2
#define TEMPERATURE_INFO_LEN    (TEMPERATURE_NAME_LEN + TEMPERATURE_VALUE_LEN)
#define TEMP_VALUE_INVALID 0x7fff
#define TEMP_VALUE_ERROR   0x7ffd
#define MULTI_BIT_ECC_ERRORS_THRESHOLD   64

#define     Atlas_900_A3_SuperPoD_MAIN_BOARD_ID1      0x18    // 天成产品名：Atlas 900 A3 SuperPoD 集群算力系统
#define     Atlas_900_A3_SuperPoD_MAIN_BOARD_ID2      0x19
#define     Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID1     0x1C
#define     Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID2     0x1D
#define     HCCS_9000_ARR_COL_MAX    8   // 天工npu-1520的hccs链路链接信息存储数组列数最大值
#define     HCCS_9000_ARR_ROW_MAX    8   // 天工npu-1520的hccs链路链接信息存储数组行数最大值
#define     HCCS_9000_ARR_COL_MIN    2   // 天工npu-1520的hccs链路链接信息存储数组列数最小值
#define     HCCS_9000_ARR_ROW_MIN    0   // 天工npu-1520的hccs链路链接信息存储数组行数最小值
#define     HCCS_900_ARR_COL_MAX     8   // 天成npu-1520的hccs链路链接信息存储数组列数最大值
#define     HCCS_900_ARR_ROW_MAX     16  // 天成npu-1520的hccs链路链接信息存储数组行数最大值
#define     HCCS_900_ARR_COL_MIN     1   // 天成npu-1520的hccs链路链接信息存储数组列数最小值
#define     HCCS_900_ARR_ROW_MIN     0   // 天成npu-1520的hccs链路链接信息存储数组行数最小值

void print_query_chip_not_support_info(struct npu_smi_operate_info *operate_info);

void print_npu_watch_header(const int *stype, const int stype_len);

void print_chip_watch_info(int card_id, int device_id, struct npu_chip_watch_info *chip_info, const int *stype);

void print_card_total_info(struct npu_card_total_info *card_info);

void print_proc_total_info(struct npu_card_total_info *card_info);

void print_proc_total_info_with_HBM(struct npu_card_total_info *card_info);

void print_card_total_info_first(struct npu_card_total_info *card_info, int chip_index);

void print_card_total_info_second(struct npu_card_total_info *card_info, int chip_index);

void print_total_info(struct npu_total_info *npu_total_info);

void print_card_total_info_with_HBM(struct npu_card_total_info *card_info);

void print_card_total_info_with_HBM_first(struct npu_card_total_info *card_info, int chip_index);

void print_card_total_info_with_HBM_second(struct npu_card_total_info *card_info, int chip_index, unsigned int phyid);

void print_total_info_with_HBM(struct npu_total_info *npu_total_info);

void print_all_info(struct npu_all_info *npu_all_info);

void print_mapping_info(struct npu_mapping_info *npu_mapping_info);

void print_mapping_info_910_93(struct npu_mapping_info *npu_mapping_info);

void print_mapping_info_950(struct npu_mapping_info *npu_mapping_info);

void print_flash_info(struct npu_flash_info *flash_info);

void print_chip_usages_info(struct npu_chip_usages_info *usages_info);

void print_chip_usages_dvpp_info(struct npu_chip_usages_info *usages_info);

void print_chip_info_by_type(enum dcmi_unit_type device_type,
    struct npu_chip_info *chip_info, unsigned int module_id);

void print_memory_info(int card_id, int device_id, struct npu_memory_info *memory_info);

void print_ascend_board_info(struct npu_device_info *device_info);

void print_npu_card_info(struct npu_device_info *device_info);
#ifndef ORIENT_CH
void print_npu_info(struct npu_device_info *device_info, struct npu_chip_info *chip_info);
#endif
void print_common_info(struct npu_card_common_info *card_common_info);

void print_chip_temperature_for_outband(int card_id, const char *data_info, int len);

void printf_ddr_ecc_info(struct dcmi_ecc_info *ddr_ecc_info, unsigned int next_isolated_pages_cnt);

void printf_hbm_ecc_info(struct dcmi_ecc_info *hbm_ecc_info);

void print_diagnosis_info(struct npu_smi_operate_info *operate_info, struct npu_device_health_info *health_info);

void print_pcie_err_code(struct dcmi_chip_pcie_err_rate *pcie_err_code_info);

void print_pcie_err_count(struct dcmi_pcie_link_error_info *pcie_err_count);

void print_chip_temp_info(int ret, enum dcmi_unit_type device_type, int temp);

void printf_template_info(struct dcmi_computing_template *template_in, unsigned int template_num);

void print_npu_work_mode_info(const int card_id, const unsigned char work_mode);

void print_npu_topo_info(struct topo_info *topo_operate_info);

void print_npu_hccs_lane(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int env_offset);

void print_npu_single_hccs_lane(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info, int id, int env_offset);

void print_npu_hccs_topo(struct npu_smi_operate_info *operate_info);

void print_npu_sio_info(struct dcmi_sio_crc_err_statistics_info *sio_info);

void printf_hccs_bandwidth_info(struct dcmi_hccs_bandwidth_info *hccs_bandwidth_info, int env_offset);

void print_npu_310P_hccs_lane_packet_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info);

void print_npu_310P_hccs_lane_retry_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info);

void print_npu_310P_hccs_lane_error_info(struct dcmi_hccs_statues *hccs_status, struct dcmi_hccs_lane_info *lane_info,
    struct dcmi_hccs_statistic_info_u64 *statistic_info);

int print_ascend_chip_hccs_lane_info(struct npu_smi_operate_info *operate_info, struct dcmi_hccs_statues *hccs_status,
    struct dcmi_hccs_lane_info *lane_info, struct dcmi_hccs_statistic_info_u64 *statistic_info);

void printf_hccs_avail_credit_info(int card_id, struct dcmi_hccs_credit_info *hccs_credit_info);

void printf_syslog_dump_info(int type, int persistence_enable, int gear, char *syslog_path,
                             int *card_msn_existed, int path_len, int card_num);

void print_op_timeout_info(struct ts_dcmi_ctrl_msg_body_t *op_timeout_info);

int card_950_type_judge(unsigned int mainboard_id);

void print_diagnosis_info_ao(struct npu_smi_operate_info *operate_info, struct npu_device_health_info *health_info,
                             unsigned int *ao_err_code_list, unsigned int ao_err_code_count);

#endif /* __NPU_INFO_PRINT_H__ */
