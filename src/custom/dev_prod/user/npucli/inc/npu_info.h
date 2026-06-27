/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_INFO_H__
#define __NPU_INFO_H__
#include <fcntl.h>
#include <sys/ioctl.h>
#include "npu_smi.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define NPU_ERROR_STRING_MAX_LENGTH    256
#define HCCS_MAX_PCS_NUM 16
#define NPU_SENSORS_TEMP_INVALID     0x7EFF
#define NPU_SENSORS_TEMP_FAULT       0x7FFF
#define NPU_PRODUCT_TYPE_STR_MAX     64
#define CPU_NUMBER_IN_CHIP 8
#define AI_CPU_SET_PATH "/sys/fs/cgroup/cpuset/AICPU/cpuset.cpus"
#define DIGITAL_NUM_TO_PER           100
#define MAX_TRY_COUNT 3
#define RETRY_SLEEP_TIME 2

#define PWM_IOC_MAGIC 'p'
#define PWM_CMD_GET_DUTY_RATIO _IOR(PWM_IOC_MAGIC, 0, int)             // 获取占空比
#define PWM_CMD_GET_DUTY_RATIO_ADJUST_MODE _IOR(PWM_IOC_MAGIC, 2, int) // 获取调速模式

#define DEV_PWM_NAME "/dev/pwm"
#define PWM_CHANNEL 2

#define SYS_BUS_PCI_DEVICE_PATH     "/sys/bus/pci/devices"
#define TOPO_PCIE_CONFIG_SPACE_LEN   256

/* PCIe Configuration Space Header offset */

#define TOPO_PCI_CLASS_CODE          0x09    /* Offset of device code */

#define TOPO_PCI_PRIMARY_BUS         0x18    /* Offset of primary bus number */

#define TOPO_PCI_SECONDARY_BUS       0x19    /* Offset of secondary bus number */

#define TOPO_PCI_CAPABILITY_LIST     0x34    /* Offset of first capability list entry */

/* PCIe Capability Structure offset */

#define TOPO_PCIE_LNKCAP             0xc     /* Link Capabilities */

#define TOPO_PCIE_LNKSTA             0x12    /* Link Status */
/* Bit mask of link cap */

#define TOPO_PCIE_MASK_LNKCAP_SPEED  0x0000f
#define TOPO_PCIE_MASK_LNKCAP_WIDTH  0x003f0

/* Bit mask of link status */

#define TOPO_PCIE_MASK_LNKSTA_SPEED  0x000f
#define TOPO_PCIE_MASK_LNKSTA_WIDTH  0x03f0
#define BIT_OPERATION_CAP_WIDTH      4
#define BIT_OPERATION_STA_WIDTH      8
#define BIT_OPERATION_ONE_BYTE       8

#define DEV_CLASS_LEN                3
#define LNK_CAP_LEN                  4
#define LNK_STA_LEN                  2

#define PCIE_NUM_MAX                 256
#define PCIE_NAME_LENTH              16
#define TOPO_INFO_MAX_LENTH          32

/* PCIe bridge class */

#define TOPO_PCI_CLASS_CODE_MASK     0xff0000
#define TOPO_PCI_BASE_CLASS_BRIDGE   0x060000

/* Distinguish 1980 server type */

#define TYPE_910_SERVER               4

/* Distinguish 1980b type */

#define TYPE_910B_POD                0
#define TYPE_910B_CARD               4

/* phy machine mach flag */

#define TOPO_HOST_PHY_MACH_FLAG      0x5a6b7c8d

#define ATLAS_9000_OFFSET       2
#define DEFAULT_OFFSET          1

#define NIC_PORT_NUM     4
#define NIC_NPU_RATIO    4
#define NIC_NAME_LEN     32

typedef enum {
    TOPO_TYPE_SELF = 0,     /* 芯片本身 */
    TOPO_TYPE_SYS,          /* 通过PCIe连接且穿过NUMA nodes， nodes之间通过SMP连接，如：QPI、 UPI */
    TOPO_TYPE_PHB,          /* 通过PCIe连接且穿过同一个CPU的 PCIe host bridge */
    TOPO_TYPE_HCCS,         /* 通过HCCS链接 */
    TOPO_TYPE_PXB,          /* 通过PCIe连接穿过多个PCIe switch */
    TOPO_TYPE_PIX,          /* 通过PCIe连接穿过一个PCIe switch */
    TOPO_TYPE_SIO,          /* 通过SIO总线连接 */
    TOPO_TYPE_HCCS_SW,      /* 通过1520交换的HCCS链接 */
    TOPO_TYPE_UB,           /* 通过UB总线连接 */
    TOPO_TYPE_BUTT,         /* 未知关系 */
    TOPO_TYPE_MAX,
} NPU_TOPO_TYPE;

struct topo_pcie_cfg_info {
    unsigned int device_id;
    unsigned int vender_id;
    unsigned int subVender_id;
    unsigned int subDevice_id;
    unsigned int dev_class;
    unsigned int primary_bus;
    unsigned int secondary_bus;
    unsigned int cap_speed;
    unsigned int cap_width;
    unsigned int sta_speed;
    unsigned int sta_width;
};
struct topo_pcie_id {
    unsigned int domain;
    unsigned int bdf_busid;
    unsigned int bdf_deviceid;
    unsigned int bdf_funcid;
};

struct topo_pcie_info {
    int numa_node;
    int pcie_size;
    char affinity_cpu[TOPO_INFO_MAX_LENTH];
    char local_cpu_list[TOPO_INFO_MAX_LENTH];
    struct topo_pcie_cfg_info config;
    struct topo_pcie_id pcie_id;
    struct topo_pcie_info *prev_pcie_info;
    struct topo_pcie_info *next_pcie_info;
};

struct topo_info {
    int device_count;
    int device_id_list[NPU_MAX_COUNT];
    char affinity_cpu_info[NPU_MAX_COUNT][TOPO_INFO_MAX_LENTH];           /* 设备的亲和CPU列表，与device_id_list的数组下标一一对应 */
    NPU_TOPO_TYPE topo_type_matrix[NPU_MAX_COUNT][NPU_MAX_COUNT];   /* 设备两两之间的拓扑关系，行和列的下标与device_id_list的数组下标一一对应 */
    NPU_TOPO_TYPE nic_topo_matrix[NIC_PORT_NUM][NPU_MAX_COUNT];   /* NIC与NPU的拓扑关系记录，4个NIC口对应所有NPU */
    char nic_name_list[NIC_PORT_NUM][NIC_NAME_LEN];   /* 网卡名称列表 */
};

/* NPU命令定义 */
struct info_help_cmd {
    void (*func)(struct npu_smi_operate_info *operate_info);
    int type;
};

int npu_info_main(struct npu_smi_operate_info *operate_info, int argc, char **argv);
int query_mapping_info(struct npu_smi_operate_info *operate_info);
int query_all_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_default_proc(struct npu_smi_operate_info *operate_info);
int show_ddr_ecc_info(struct npu_smi_operate_info *operate_info);
int show_ascend_chip_usages_info(struct npu_smi_operate_info *operate_info);
int query_pwm_mode(unsigned int *mode);
int get_card_and_logic_id_list(int *card_id_list, int *logic_id_list, int *card_num);
int get_card_msn_existed_list(int card_num, int *logic_id_list, int *card_id_list, int *card_msn_existed);
int check_msn_is_existed(int device_logic_id, int card_id, int *msn_existed_flag);
int show_ascend_device_share_config_recover_info(struct npu_smi_operate_info *operate_info);
int show_ascend_multi_die_policy_config_recover_info(struct npu_smi_operate_info *operate_info);
int show_card_multi_die_policy_info(struct npu_smi_operate_info *operate_info);

/* 模型保护证书管理功能信息获取 */
int show_tls_csr_info(struct npu_smi_operate_info *operate_info);
int show_tls_cert_info(struct npu_smi_operate_info *operate_info);
int show_tls_cert_period_info(struct npu_smi_operate_info *operate_info);
int show_tls_rootkey_info(struct npu_smi_operate_info *operate_info);

int show_work_tops(struct npu_smi_operate_info *operate_info);
int show_work_tops_v2(DCMI_LP_CUR_TOPS_STRU *cur_tops_stru, DCMI_LP_TOPS_DETAILS_STRU *tops_details_stru);

bool is_A5_card_mainboard_id(int mainboard_id);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPU_INFO_H__ */