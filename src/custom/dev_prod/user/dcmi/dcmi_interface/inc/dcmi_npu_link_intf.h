/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __DCMI_NPU_LINK_INTF_H__
#define __DCMI_NPU_LINK_INTF_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define HAL_TOPOLOGY_HCCS       0
#define HAL_TOPOLOGY_PIX        1
#define HAL_TOPOLOGY_PIB        2
#define HAL_TOPOLOGY_PHB        3
#define HAL_TOPOLOGY_SYS        4
#define HAL_TOPOLOGY_SIO        5
#define HAL_TOPOLOGY_HCCS_SW    6
#define HAL_TOPOLOGY_UB         7

#define SYS_BUS_PCI_DEVICE_PATH     "/sys/bus/pci/devices"
#define SYS_CLASS_UBURMA_PATH       "/sys/class/uburma"

#define DCMI_PCI_PROC_BUS_PCI_PATH "/proc/bus/pci"
#define DCMI_PCI_PCI_DOMAIN        0x0000
#define DCMI_PCI_INVALID_VALUE    (-1)

#define MAX_MACRO_ID 12
#define MIN_MACRO_ID 0
#define MAX_H60_ID   7
#define MAX_A_X_MACRO_ID   10
#define RES_MACRO_ID 8
#define MAX_310P_MACRO_ID 4
#define MAX_950_POD_MACRO_ID 17
#define MAX_950_1P_MACRO_ID 3
#define MAX_950_2P_MACRO_ID 8
#define MAX_950_4P_MACRO_ID 6
#define RES_950_2P_MACRO_ID 7
#define MAX_A_X_950_UBX_MACRO_ID 17

#define MAX_INVALID_950_0_0_SERVER_MACRO_ID 8
#define MIN_INVALID_950_0_0_SERVER_MACRO_ID 1

#define FULL_EYE_MAX_LANE_NUM 4

#define HCCS_SINGLE_PACKETS_BYTES       20
#define PROFILING_BYTE_TRANS_TO_GMBYTE  (1024 * 1024 * 1024)
#define PROFILING_MS_TRANS_TO_S         1000

#define UDIE_ID_0     0
#define UDIE_ID_1     1

#define PORT_ID_0     0
#define PORT_ID_1     1
#define PORT_ID_2     2
#define PORT_ID_3     3
#define PORT_ID_4     4
#define PORT_ID_5     5
#define PORT_ID_6     6
#define PORT_ID_7     7
#define PORT_ID_8     8

#define PROFILING_TIME_MIN    100
#define PROFILING_TIME_MAX    10000

struct dcmi_hccs_link_bandwidth_info {
    int profiling_time;
    unsigned int tx_bandwidth[DCMI_HCCS_MAX_PCS_NUM];
    unsigned int rx_bandwidth[DCMI_HCCS_MAX_PCS_NUM];
};

// UB带宽查询接口需要用到的数据结构
struct ub_bandwidth_t {
    unsigned int tx_bandwidth;
    unsigned int rx_bandwidth;
};

int dcmi_pci_write_conf_byte(const char *param, unsigned int pos, unsigned char byte);

int dcmi_get_phyid_by_cardid_and_devid(int card_id, int device_id, unsigned int *phyid);

int dsmi_get_ub_bandwidth(int device_id, int udie_id, int port_id, unsigned int time_interval,
    struct ub_bandwidth_t *bw);

int dcmi_get_cpu_affinity_by_device_id(int card_id, int device_id, char *affinity_cpu, int *length);
 
int dcmi_query_topo_type(int card_id1, int card_id2, int device_id1, int device_id2, int *topo_type);

int dcmi_get_npu_ub_bandwidth_info(int card_id, int device_id, unsigned int profiling_time,
    struct dcmi_ub_port_info *ub_port_info, struct dcmi_ub_bandwidth_info *ub_bandwidth_info);

int dcmi_ub_bandwidth_info_check(int card_id, int device_id, unsigned int profiling_time,
    struct dcmi_ub_port_info *ub_port_info);

int dcmi_topo_read_line_info_from_file(const char *cfg_file_path, char *content);
 
int dcmi_hal_to_npu_topo_type(int hal_topo_type);
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __DCMI_NPU_LINK_INTF_H__ */
