/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_COMMON_H__
#define __NPU_COMMON_H__

#include "dcmi_interface_api.h"
#include "npu_board_id.h"
#include "dcmi_os_adapter.h"
#include "dcmi_common.h"
#include "npu_error_code.h"
#include "npu_smi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

#define NPU_DEC_TO_STR_BASE         10
#define NPU_HEX_TO_STR_BASE         16
#define NPU_INVALID_VALUE           (-1)
#define NPU_FLASH_BLOCK_NUM         32
#define NPU_HEALTH_STATE_MAX_LEN    16
#define NPU_ERROR_CODE_MAX_NUM      128
#define NPU_MAX_CHIP_NUM_IN_CARD    16
#define MAX_PROC_NUM                32
#define MAX_CHIP_PROCESS_NUM        8
#define MAX_PROCESS_NAME_LEN        16
#define NPU_LANE_ID                 (-1)
#define MAX_HCCS_PROFILING_TIME     1000

#define LEAST_PARAMETER_NUM 2
#define PARAM_START_INDEX   1
#define PARAM_STEP          2

#define DEVICE_SHARE_MAIN_CMD (0x8001)
#define DEVICE_SHARE_SUB_CMD   (0)

#define NPU_AMP_WORK_MODE       0
#define NPU_SMP_WORK_MODE       1
#define NPU_INVALID_WORK_MODE   0xff
#define ASCEND_INSTALL_INFO "/etc/ascend_install.info"

#define DCMI_VNPU_SVM_SUB_CMD 0
#define DCMI_READ_VNPU_SVM_SUB_CMD 1

#define NPU_WATCH_DELAY_MIN_VALUE 1
#define NPU_WATCH_DELAY_MAX_VALUE 100

#define QUARTER_BUFF_LEN 64
#define BOOT_STATUS_RETRY_TIME 120
#define DCMI_ERR_CODE_SYSLOG_CONFIG_ILLEGAL 10

#define NPU_PRODUCT_NAME_MAX_LEN 64

#define CLOSE_NIC_NETWORK_RETRY_TIME 3

#define QOS_MASTER_MPAMID_MAX 127
#define QOS_MASTER_QOS_MAX 7
#define QOS_MASTER_MODE_MAX 2

enum info_watch_type {
    POWER_TYPE = 0,
    TEMP_TYPE,
    AI_CORE_TYPE,
    AI_CPU_TYPE,
    CTRL_CPU_TYPE,
    MEMORY_TYPE,
    MEMORY_BANDWIDTH_TYPE,
    NPU_UTILIZATION_TYPE,
    AI_CUBE_TYPE,
    WATCH_STYPE_BOTTOM
};

enum qos_cfg_para {
    QOS_MASTER = 0,
    QOS_MPAMID,
    QOS_QOS,
    QOS_BITMAP_0,
    QOS_BITMAP_1,
    QOS_BITMAP_2,
    QOS_BITMAP_3,
    QOS_MODE,
    QOS_MAX
};

enum qos_master_type {
    QOS_MASTER_ID_VDEC = 1,
    QOS_MASTER_ID_VPC,
    QOS_MASTER_ID_JPGE,
    QOS_MASTER_ID_JPGD,
    QOS_MASTER_ID_ROCE,
    QOS_MASTER_ID_NIC,
    QOS_MASTER_ID_PCIE,
    QOS_MASTER_ID_INVALID,
    QOS_MASTER_ID_AIC_DATA,
    QOS_MASTER_ID_AIC_INS,
    QOS_MASTER_ID_AIV_DATA,
    QOS_MASTER_ID_AIV_INS,
    QOS_MASTER_ID_SDMA,
    QOS_MASTER_ID_MAX,
};

enum device_health_state {
    NORMAL_STATE = 0,
    WARINING_STATE,
    ALARM_STATE,
    CRITICAL_STATE
};

enum ecc_device_type {
    DDR = 0,
    L2BUF,
    SRAM_ECC,
    CACHE,
    HBM
};

enum bytes_transforms_type {
    BYTES_KB = 0,
    BYTES_MB,
    BYTES_GB,
    BYTES_TB
};

enum kb_transforms_type_e {
    KB_BYTES = 0,
    KB_MB,
    KB_GB,
};

enum npu_chip_type {
    NPU_CHIP_310 = 0,
    NPU_CHIP_310P,
    NPU_CHIP_910,
    NPU_CHIP_310B,
    NPU_CHIP_910B,
    NPU_CHIP_910_93,
    NPU_CHIP_950,
    NPU_CHIP_INVALID = 0xFF
};

enum npu_board_type {
    NPU_BOARD_TYPE_MODEL = 0,
    NPU_BOARD_TYPE_SOC,
    NPU_BOARD_TYPE_STATION,
    NPU_BOARD_TYPE_HILENS,
    NPU_BOARD_TYPE_CARD,
    NPU_BOARD_TYPE_SERVER,
    NPU_BOARD_TYPE_UBX,
    NPU_BOARD_TYPE_INVALID = 0xFF
};

enum cmd_support_type {
    CMD_SPT_MODEL = 0x1,
    CMD_SPT_310_SOC = 0x2,
    CMD_SPT_STATION = 0x4,
    CMD_SPT_HILENS = 0x8,
    CMD_SPT_310_CARD = 0x10,
    CMD_SPT_SERVER = 0x20,
    CMD_SPT_310P_CARD = 0x40,
    CMD_SPT_910_CARD = 0x80,
    CMD_SPT_310P_SOC = 0x100,
    CMD_SPT_310B_SOC = 0x200,
    CMD_SPT_910B_SERVER = 0x400,
    CMD_SPT_910B_CARD = 0x800,
    CMD_SPT_310B_SOC_DK = 0x1000,
    CMD_SPT_310B_SOC_STATION = 0x2000,
    CMD_SPT_910_93_SERVER = 0x4000,
    CMD_SPT_910_93_CARD = 0x8000,
    CMD_SPT_950_SERVER = 0x10000,
    CMD_SPT_950_SOC = 0x20000,
    CMD_SPT_950_CARD = 0x40000,
    CMD_SPT_INVALID = 0xFFFF
};

enum cmd_support_hardware_form {
    CMD_HW_SPT_CARD = 0x1,
    CMD_HW_SPT_CHIP = 0x2,
    CMD_HW_SPT_COMMON = 0x4,
    CMD_HW_SPT_INVALID = 0xFFFF
};

enum cmd_support_env_form {
    CMD_ENV_SPT_NON_ROOT = 0x1,
    CMD_ENV_SPT_DOCKER = 0x2,
    CMD_ENV_SPT_VM = 0x4,
    CMD_ENV_SPT_INVALID = 0xFFFF
};

typedef enum {
    VNPU_DOCKER,
    VNPU_VM,
    VNPU_MODE_MAX,
} VDEV_MODE;

enum pwm_ratio {
    PWM_MIN_RATIO = 0,
    PWM_MAX_RATIO = 100,
};

enum pwm_mode {
    PWM_MANUAL,
    PWM_AUTO,
    PWM_MODE_MAX,
};

enum sleep_time {
    MIN_SLEEP_TIME = 200,
    MAX_SLEEP_TIME = 604800000,
};

enum boot_sel_mode {
    SSD = 3,
    EMMC,
    BOOT_SEL_MODE_MAX,
};

enum secverify_mode {
    SEC_VERIFY_OFF = 0,                  // 关闭验证，不验签
    HUAWEI_CERT,                         // 使用华为证书验签
    CUSTOM_CERT,                         // 使用客户证书验签
    HUAWEI_OR_CUSTOM_CERT,               // 使用华为或客户证书验签
    COMMUNITY_CERT,                      // 使用社区证书验签
    HUAWEI_OR_COMMUNITY_CERT,            // 使用华为或社区证书验签
    CUSTOM_OR_COMMUNITY_CERT,            // 使用客户或社区证书验签
    HUAWEI_OR_CUSTOM_OR_COMMUNITY_CERT,  // 使用华为或客户或社区证书验签
    SEC_VERIFY_MODE_MAX,
};

#define CMD_SPT_310 (CMD_SPT_MODEL | CMD_SPT_310_SOC | CMD_SPT_STATION | CMD_SPT_HILENS | CMD_SPT_310_CARD)
#define CMD_SPT_310B (CMD_SPT_310B_SOC_DK | CMD_SPT_310B_SOC_STATION)
#define CMD_SPT_310P (CMD_SPT_310P_CARD | CMD_SPT_310P_SOC)
#define CMD_SPT_910B (CMD_SPT_910B_SERVER | CMD_SPT_910B_CARD)
#define CMD_SPT_910_93 (CMD_SPT_910_93_SERVER | CMD_SPT_910_93_CARD)
#define CMD_SPT_950 (CMD_SPT_950_SERVER | CMD_SPT_950_SOC | CMD_SPT_950_CARD)

#define CMD_SPT_CARD (CMD_SPT_310_CARD | CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_910B_CARD | CMD_SPT_910_93_CARD)
#define CMD_SPT_EP (CMD_SPT_MODEL | CMD_SPT_STATION | CMD_SPT_HILENS | CMD_SPT_SERVER | CMD_SPT_CARD)
#define CMD_SPT_SOC (CMD_SPT_310_SOC | CMD_SPT_310P_SOC | CMD_SPT_310B)
#define CMD_SPT_ALL_SERVER (CMD_SPT_SERVER | CMD_SPT_910B_SERVER | CMD_SPT_910_93_SERVER)
#define CMD_SPT_ALL (CMD_SPT_MODEL | CMD_SPT_SOC | CMD_SPT_STATION | CMD_SPT_HILENS | CMD_SPT_SERVER | CMD_SPT_CARD | \
                     CMD_SPT_910B | CMD_SPT_310B | CMD_SPT_910_93 | CMD_SPT_950)
#define CMD_SPT_STATION_HILEN (CMD_SPT_STATION | CMD_SPT_HILENS)
#define CMD_WIN_SPT_ALL (CMD_SPT_MODEL | CMD_SPT_310_CARD)
#define CMD_SPT_MCU (CMD_SPT_CARD | CMD_SPT_STATION_HILEN | CMD_SPT_310P_SOC | CMD_SPT_310B_SOC_STATION | \
                     CMD_SPT_910B | CMD_SPT_910_93)

#define CMD_HW_SPT_CARD_CHIP (CMD_HW_SPT_CARD | CMD_HW_SPT_CHIP)
#define CMD_ENV_SPT_ALL (CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_DOCKER | CMD_ENV_SPT_VM)
#define CMD_ENV_SPT_ROOT (CMD_ENV_SPT_DOCKER | CMD_ENV_SPT_VM)

#define CMD_SPT_MODEL_INDEX               0
#define CMD_SPT_310_INDEX                 4
#define CMD_SPT_310P_INDEX                6
#define CMD_SPT_910_INDEX                 7
#define CMD_SPT_310P_SOC_INDEX            8
#define CMD_SPT_310B_SOC_INDEX            9
#define CMD_SPT_910B_SERVER_INDEX         10
#define CMD_SPT_910B_CARD_INDEX           11
#define CMD_SPT_310B_SOC_DK_INDEX         12
#define CMD_SPT_310B_SOC_STATION_INDEX    13
#define CMD_SPT_910_93_SERVER_INDEX       14
#define CMD_SPT_910_93_CARD_INDEX         15
#define CMD_SPT_950_SERVER_INDEX       16
#define CMD_SPT_950_SOC_INDEX          17
#define CMD_SPT_950_CARD_INDEX         18

#define NPU_CHIP_VENDER_ID     0x19e5
#define NPU_310_DEVICE_ID      0xd100
#define NPU_310P_DEVICE_ID     0xd500
#define NPU_310B_DEVICE_ID     0xd105
#define NPU_910_DEVICE_ID      0xd801
#define NPU_910B_DEVICE_ID     0xd802
#define NPU_910_93_DEVICE_ID     0xd803
#define NPU_950_DEVICE_ID     0xd806

#define NPU_PERMILLAGE_TRANS        0.001
#define NPU_PERCENTAGE_TRANS        0.01
#define NPU_DECIMAL_TRANS           0.1

#define BOARD_CONFIG_FILE   "/run/board_cfg.ini"
#define BOARD_TYPE_KEY      "board_type="
#define BOARD_TYPE_HILENS   "hilens"
#define BOARD_INFO_LINE_LEN 256
#define NPU_CFG_LINE_MAX_LEN 1024

#define IIC_TEST_CASE 6

#define NPU_INVALID_PCB_ID    0xFF

#define NPU_V_PARAM_FLAG_INDEX      (NPU_MAX_LENTH - 1)
#define NPU_V_PARAM_NUMBER_INDEX    (NPU_MAX_LENTH - 2)

#define MAX_IP_LEN 4
#define MAX_IP_VALUE 255
#define IP_AND_MASK_CNT 8

#define VNPU_AICORE_1_NUMBER   1
#define VNPU_AICORE_2_NUMBER   2
#define VNPU_AICORE_4_NUMBER   4
#define VNPU_AICORE_8_NUMBER   8
#define VNPU_AICORE_16_NUMBER  16
#define MAP_SIZE 4096UL
#define MAP_MASK (MAP_SIZE - 1)

#define BUF_LEN 256

#define P2P_MEM_CFG_SIZE 4
#define BAR_CFG_ON 1
#define BAR_CFG_OFF 0
#define BAR_CFG_SIZE 4096
#define MIN_SLEEP_TIMES 200  /* 单位：ms */

#define MAX_SLEEP_TIMES 604800000  /* 单位：ms */

#define NIC_DOWN_ENABLE     1
#define NIC_DOWN_DISABLE    0

struct npu_device_health_info {
    char health_state[NPU_HEALTH_STATE_MAX_LEN];
    int error_code_count;
    unsigned int error_code[NPU_ERROR_CODE_MAX_NUM];
    int error_code_width; // 每个错误码占用字节空间
};

struct dcmi_device_compat_info {
    int err;
    enum dcmi_device_compat compatibility;
};

struct npu_device_info {
    int npu_id;
    int chip_count;
    int mcu_id;
    int cpu_id;
    int chip_fault;
    int pcb_id;
    int class_id;
    int slot_id;
    int firmware_version_lenth;
    unsigned int main_board_id;
    char product_name[NPU_MAX_LENTH];
    char model[NPU_MAX_LENTH];
    char description[NPU_MAX_LENTH];
    char manufacturer[NPU_MAX_LENTH];
    char serial_number[NPU_MAX_LENTH];
    char software_version[NPU_MAX_LENTH];
    unsigned char firmware_version[NPU_MAX_LENTH];
    struct dcmi_device_compat_info compat_info;
    char health_state[NPU_MAX_LENTH];
    char pcie_info[NPU_MAX_LENTH];
    struct dcmi_pcie_info_all device_pcie_info;
    struct dcmi_ub_id_info device_ub_id_info;
    struct dcmi_board_info board_info;
};

struct npu_chip_info {
    int npu_id;
    int chip_id;
    int chip_logic_id;
    int chip_pos_id;
    int xloader_version_len;
    char xloader_version[NPU_MAX_LENTH];
    struct dcmi_die_id vdie_id;
    struct dcmi_die_id ndie_id;
    struct dcmi_die_id ddie_id;
    struct dcmi_chip_info_v2 chip_info;
    struct dcmi_board_info board_info;
    struct dcmi_pcie_info_all device_pcie_info;
};

struct npu_chip_info_die {
    struct dcmi_die_id die_id;
};

struct npu_chip_usages_info {
    struct dcmi_get_memory_info_stru memory_size_info_M;
    struct dcmi_hbm_info hbm_size_info_M;
    struct dcmi_dvpp_ratio dvpp_ratio;
    unsigned int memory_usage;
    unsigned int hbm_usage;
    unsigned int aicore_usage;
    unsigned int aivector_usage;
    unsigned int aicpu_usage;
    unsigned int ctrlcpu_usage;
    unsigned int vectorcore_usage;
    unsigned int memory_bandwidth_usage;
    unsigned int hbm_bandwidth_usage;
    unsigned int npu_utilization_usage;
    unsigned int aicube_usage;
};

struct npu_memory_info {
    unsigned int memory_frequency_mhz;
    unsigned int hbm_frequency_mhz;
    struct dcmi_get_memory_info_stru memory_size_info_M;
    struct dcmi_hbm_info hbm_size_info_M;
    struct dcmi_hbm_product_info hbm_product_info;
};

struct npu_flash_info {
    unsigned int flash_count;
    struct dcmi_flash_info flash_info[NPU_FLASH_BLOCK_NUM];
};

struct npu_card_info {
    int card_id;
    int chip_count;
    int mcu_id;
    int cpu_id;
    char product_name[NPU_MAX_LENTH];
    char serial_number[NPU_MAX_LENTH];
    int chip_logic_id[NPU_MAX_CHIP_NUM_IN_CARD];
    int chip_phy_id[NPU_MAX_CHIP_NUM_IN_CARD];
    struct dcmi_chip_info chip_info[NPU_MAX_CHIP_NUM_IN_CARD];
};

struct npu_all_info {
    int card_count;
    struct npu_card_info card_info[MAX_CARD_NUM];
};

struct npu_mapping_info {
    int card_count;
    struct npu_card_info card_info[MAX_CARD_NUM];
};

struct npu_chip_common_info {
    unsigned int memory_usage;
    unsigned int hbm_usage;
    unsigned int npu_usage;
    int temp;
    unsigned int aicore_count;
    int power;
    struct dcmi_aicore_info aicore_info;
};

struct npu_card_common_info {
    int card_id;
    int chip_count;
    int mcu_id;
    int cpu_id;
    struct npu_chip_common_info chip_common_info[NPU_MAX_CHIP_NUM_IN_CARD];
};

struct npu_common_info {
    int card_count;
    struct npu_card_common_info card_common_info[MAX_CARD_NUM];
};

struct npu_chip_watch_info {
    int temp;
    int power;
    struct npu_chip_usages_info usages_info;
};

struct npu_watch_card_info {
    int card_id;
    int chip_count;
    int mcu_id;
    int cpu_id;
};

struct npu_watch_info {
    int card_count;
    struct npu_watch_card_info card_info[MAX_CARD_NUM];
};

struct npu_card_total_info {
    int card_id;
    int chip_count;
    int d_chip_count;
    int mcu_id;
    int cpu_id;
    int is_has_pcie;
    int proc_nums[NPU_MAX_CHIP_NUM_IN_CARD];
    char chip_proc_name[NPU_MAX_CHIP_NUM_IN_CARD][MAX_PROC_NUM][MAX_PROCESS_NAME_LEN];
    unsigned int chip_health[NPU_MAX_CHIP_NUM_IN_CARD];
    struct dcmi_chip_info chip_info[NPU_MAX_CHIP_NUM_IN_CARD];
    struct dcmi_pcie_info_all device_pcie_info[NPU_MAX_CHIP_NUM_IN_CARD];
    struct dcmi_get_memory_info_stru chip_memory_info[NPU_MAX_CHIP_NUM_IN_CARD];
    struct dcmi_hbm_info chip_hbm_info[NPU_MAX_CHIP_NUM_IN_CARD];
    struct npu_chip_common_info chip_common_info[NPU_MAX_CHIP_NUM_IN_CARD];
    struct dcmi_proc_mem_info chip_proc_info[NPU_MAX_CHIP_NUM_IN_CARD][MAX_PROC_NUM];
};

struct npu_total_info {
    int card_count;
    char software_version[NPU_MAX_LENTH];
    struct npu_card_total_info card_info[MAX_CARD_NUM];
};

typedef int (*query_proc_fun)(struct npu_smi_operate_info *operate_info);

struct npu_operate_table_item {
    int fun_index;
    query_proc_fun proc_func;
};

struct npu_reset_time_table {
    unsigned int mainboard_id;
    unsigned int reset_time;
};

typedef enum npu_nve_level_e {
    NVE_LOW,
    NVE_MID,
    NVE_HIGH,
    NVE_FULL,
    NVE_DEFAULT = 0xff,
} NPU_NVE_LEVEL;

/* 算力档位可设置值 */
typedef enum npu_work_tops_e {
    WORK_TOPS_20T_1600MHz,
    WORK_TOPS_8T_1000MHz,
    WORK_TOPS_16T_1600MHz,
    WORK_TOPS_8T_1600MHz,
    WORK_TOPS_4T_1000MHz,
    WORK_TOPS_MAX,
} NPU_WORK_TOPS;

typedef enum npu_aicpu_cnt_e {
    CPU_CNT_2 = 2,
    CPU_CNT_4 = 4,
    CPU_CNT_6 = 6,
    CPU_CNT_default = 0xff,
} NPU_AICPU_CNT;

typedef enum npu_virgroup_id_range {
    VIRGROUP_0 = 0,
    VIRGROUP_1 = 1,
    VIRGROUP_2 = 2,
    VIRGROUP_3 = 3,
    VIRGROUP_MAX = 4,
} NPU_VIRGROUP_ID;

#define NPU_INFO_PARAMETER_MIN_NUM 2

// root权限检查
int user_egid_check();

// 文件操作
int check_file_path(const char *tmp_path);

int get_file_length(const char *file, unsigned int *file_len);

int get_file_data(const char *file, unsigned char *fileBuf, unsigned int bufLen, unsigned int offset,
    unsigned int readLen);

int write_data_to_file(const char *file, const char *writeBuf, unsigned int bufLen, unsigned int writeLen);

int get_file_directory(const char *file, char *fileDir, int dirLen);

int remove_file(const char *filename);

int check_filename(const char *file, char *path, int len);

int covert_file_path(const char *file, char *path, int len);

int read_file_to_buf(const char *path, unsigned char *data, long int data_size, unsigned int *data_len);

/* 字符串操作 */
int str2int(int *ptmp_num, const char *tmp_str);

int set_sdata(struct npu_smi_operate_info *operate_info, const char *tmp_str);

int set_path(struct npu_smi_operate_info *operate_info, const char *tmp_path);

int npu_init_chip_type(int card_id, int device_id);

int npu_get_chip_type();

int npu_get_board_type_by_config(void);

int npu_get_board_type_by_board_id(void);

int npu_board_type_is_station(void);

int npu_board_type_is_hilens(void);

int npu_board_type_is_card(void);

int npu_board_type_is_server(void);

int npu_board_type_is_soc(void);

int npu_board_type_is_model(void);

int npu_get_total_ascend_chip_count(void);

int npu_check_card_id(int card_id);

int npu_check_vdev_id(int vnpu_id);

int npu_check_chip_id(int card_id, int device_id);

int npu_check_npu_chip_id(int card_id, int device_id);

int npu_check_is_has_d_chip(void);

int npu_check_is_has_pcie(void);

int npu_check_is_has_mcu(void);

int bytes_transform(unsigned long long  bytes, enum bytes_transforms_type flag, unsigned long long *result);

int npu_is_run_in_vm_or_docker(void);

int npu_is_in_virtual_machine(void);

int npu_is_in_docker();

int npu_get_card_device_id(int card_id, int *d_chip_count, int *mcu_id, int *cpu_id);

int npu_common_get_health_state_str(int status_index, char *health_state, int state_length);

int check_watch_chip_parm(struct npu_smi_operate_info *operate_info);

int check_watch_proc_parm(struct npu_smi_operate_info *operate_info);

int npu_info_proc_watch_param(struct npu_smi_operate_info *operate_info, const char *argv, int *para_num);

int npu_get_device_power_info(int card_id, int chip_index, int *power);

int npu_get_device_temperature(int card_id, int chip_index, int *temp);

int npu_get_ai_core_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_ai_cube_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_util_info_simultaneously(int card_id, int chip_index, struct npu_chip_usages_info *usages_info);

int npu_get_ai_cpu_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_ctrl_cpu_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_vector_core_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_ddr_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_hbm_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_ddr_bandwidth_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_hbm_bandwidth_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_npu_utilization_usage(int card_id, int chip_index, unsigned int *usage);

int npu_get_npu_utilization_usage_v2(int card_id, unsigned int *usage);

int npu_close_nic_network(int cardId);

int npu_set_nic_down_flag(int card_id, int enable_flag);

int npu_msn_log_cfg_recover(int cardId);

int check_netmask_addr(unsigned int *ip_addr, int ip_max_len);

int check_vnpu_workmode(struct npu_smi_operate_info *operate_info);

int check_vnpu_docker_mode(void);

int npu_get_elabel_pn_sn_items_info(int card_index, struct npu_all_info *npu_all_info);

int npu_safe_exec_syscmd_without_output(char *cmdstring[]);

int npu_get_driver_install_path(char *path, int len);

int npu_get_key_manage_path(char *real_path, int len);

int npu_get_driver_install_path_rc(char *path, int len);

int npu_get_driver_install_path_ep(char *path, int len);

int determine_run_env_support(struct npu_smi_type_map *type_map);

int determine_hardware_support(struct npu_smi_type_map *type_map);

int check_vdev_template_param(const char *template_name);

int set_create_vdev_param(struct npu_smi_operate_info *operate_info, const char *tmp_value);

int check_vdev_exist(struct npu_smi_operate_info *operate_info, int vdev_id);

int check_confirm_info(void);

int check_support_get_err_count_info(struct npu_smi_operate_info *operate_info);

int npu_get_dvpp_info_usage(int card_id, int device_id, struct dcmi_dvpp_ratio *usage);

int npu_get_hbm_info(int card_id, int chip_id, struct npu_chip_usages_info *usages_info);

int check_support_customized_info(struct npu_smi_operate_info *operate_info);

int check_support_err_count_clear(struct npu_smi_operate_info *operate_info);

int update_minid_conf(char *config_name, int config_value);

int get_chip_boot_status(int card_id, int device_id);

int npu_invalid_item_proc(struct npu_smi_operate_info *operate_info);

int set_card_syslog_enable(struct npu_smi_operate_info *operate_info);

int check_vnpu_chip_name(int card_id, int device_id);

int check_valid_set_operation_env(struct npu_smi_operate_info *operate_info);

int check_valid_info_operation_env(struct npu_smi_operate_info *operate_info);

int check_is_mixed_env(struct npu_smi_operate_info *operate_info, int *mixed_flag);

int npu_get_first_ready_device(int *card_id, int *chip_id);

int set_chip_id(struct npu_smi_operate_info *operate_info, const char *tmp_id);

int set_id(struct npu_smi_operate_info *operate_info, const char *tmp_id);

int set_watch_delay(struct npu_smi_operate_info *operate_info, const char *tmp_sec);

int set_enable_value(struct npu_smi_operate_info *operate_info, const char *tmp_value);

int set_chan_src(struct npu_smi_operate_info *operate_info, const char *tmp_value);

int set_cpu_num_param(struct npu_smi_operate_info *operate_info, const char *tmp_value);

int set_vdev_svm_param(struct npu_smi_operate_info *operate_info, const char *tmp_value);

int set_vdev_id_param(struct npu_smi_operate_info *operate_info, const char *tmp_value);

int set_phy_id(struct npu_smi_operate_info *operate_info, const char *tmp_id);

int set_lane_id(struct npu_smi_operate_info *operate_info, const char *tmp_id);

int set_destroy_vdev_param(struct npu_smi_operate_info *operate_info, const char *tmp_value);

bool is_a_x_910_93(int card_id);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPU_COMMON_H__ */
