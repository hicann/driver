/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef COMM_CHANNEL_EXT_H
#define COMM_CHANNEL_EXT_H

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define TX_SIGNAL_PERIOD         10
#define LINK_STATUS_MAX_LEN   16
#define PARSE_TIME_FIELD_NUM  8            // 时间戳解析字段个数
#define DEV_MON_LANE_NUM      8
#define UDIE_ID_MIN_IDX       0
#define UDIE_ID_MAX_IDX       1
#define PORT_ID_MIN_IDX       0
#define PORT_ID_MAX_IDX       8
#define LINK_STAT_MAX_IDX     10           // 记录的link status最多条数
#define CMD_STR_MAX_LEN       1024         // 拼接 cmd 字符串最大长度
#define LINK_UP_STR           "LINK_UP"    // link cmd result 字符串中up状态
#define LINK_DOWN_STR         "LINK_DOWN"  // link cmd result 字符串中down状态
#define LINK_UP_CNT_STR       "link up count"       // link up count 解析固定字符串
#define LINK_DOWN_CNT_STR     "link down count"     // link down count 解析固定字符串
#define LINK_RECORD_STR       "link change records" // link change records 解析固定字符串
#define MAX_PORT_LINK_STATUS  10U
// link cmd result 字符串最大长度
#define LINK_INFO_BUF_MAX_LEN ((sizeof(struct link_stat_data)) * MAX_PORT_LINK_STATUS)

#define XSFP_REG_NUM_ONE_ROW    16
#define XSFP_REG_BUF_LEN 128
#define NUMBER_HEX 16
#define S_TO_MS 1000
#define NS_TO_MS 1000000
#define TASK_COMP_TIMEOUT 20000 // 20s
#define TASK_STEP_US 500000
 
#pragma pack(1)
struct snr_info_data {
    unsigned int udie_id;
    unsigned int port_id;
    unsigned int lane;
    unsigned int snr;
};
 
typedef struct {
    unsigned int time_stamp;
    char link_status[LINK_STATUS_MAX_LEN];
} time_stamp_entry;
 
typedef struct {
    unsigned int port_type;
    float npu_rx_snr[DEV_MON_LANE_NUM];
} port_static_info_data;
#pragma pack()

enum optical_sub_cmd_e {
    OPTICAL_TX_SIGNAL_ENABLE = 0,
    OPTICAL_TX_SIGNAL_DISABLE = 1,
    OPTICAL_DUMP_REG_ALL = 0,
    OPTICAL_DUMP_REG_SPECIFIED = 1,
    OPTICAL_RESET_SOFT,
    OPTICAL_RESET_HARD,
    OPTICAL_SUB_CMD_UNKNOW,
    OPTICAL_HIGH_POWER_ENABLE,
    OPTICAL_HIGH_POWER_DISABLE,
};

enum imp_xsfp_opts_e {
    IMP_XSFP_OPT_SET = 0,
    IMP_XSFP_OPT_GET,
};

enum optical_test_result_e {
    OPTICAL_TEST_INIT = 0,
    OPTICAL_TEST_RUN,
    OPTICAL_TEST_CHECK,
    OPTICAL_TEST_SUCC,
    OPTICAL_TEST_FAIL,
    OPTICAL_TEST_TIMEOUT,
};

enum optical_power_status_e {
    OPTICAL_HIGH_POWER = 0,
    OPTICAL_LOW_POWER
};

typedef struct {
    enum optical_power_status_e power_status;
    enum optical_test_result_e task_status;
} optical_power_result_t;

struct optical_test_t {
    int optical_index;
    int test_mode;
    enum optical_sub_cmd_e cmd;
    enum imp_xsfp_opts_e opt;
    union {
        int loopback_mode;
        unsigned int dump_page_id;
    };
};

typedef enum {
    OPTICAL_RESET_INIT = 0,
    OPTICAL_RESET_OK,
    OPTICAL_RESET_ERR,
    OPTICAL_RDFX_TIMEOUT,
    OPTICAL_RDFX_ERR_IDX,
    OPTICAL_RDFX_ERR_START,
    OPTICAL_RDFX_ERR_STATUS,
    OPTICAL_NOT_PRESENT
} optical_reset_result_e;

struct uboe_port_ctrl {
    unsigned char port_id;
    unsigned char port_en_flag;
};

#pragma pack(1)
#define MAX_IP_VAL_LEN              48

typedef struct {
    unsigned int cmd;
    unsigned int max_time;
} xsfp_cdb_cmd_max_time_t;

// cdb command max duration time
#define XSFP_UPGRADE_CMD_NUM        6
typedef struct {
    xsfp_cdb_cmd_max_time_t cmd_max_time[XSFP_UPGRADE_CMD_NUM]; // 命令最大执行时间
} xsfp_cdb_cmd_feature_t;

typedef struct {
    unsigned int addr_high;         // 固件包在HBM中存储的起始物理地址
    unsigned int addr_low;
    unsigned int size;              // 固件包大小
    unsigned int offset;            // 当前固件写入偏移
} xsfp_firmware_info_t;

typedef struct {
    unsigned char state;            // 升级处理状态
    unsigned char sm_status;        // 升级状态机状态
    unsigned char err_status;       // 升级状态错误码
} xsfp_upgrade_state_t;

typedef struct {
    xsfp_cdb_cmd_feature_t feature_info;    // 升级命令相关能力
    xsfp_firmware_info_t fw_info;           // 固件包信息
    xsfp_upgrade_state_t state_info;
    unsigned char reset_flag;               // 收到reset标识
    unsigned char cmd_send;                 // 命令写入成功标识
    unsigned long long cmd_send_time;       // 命令写入成功时间
    unsigned long long run_start_time;      // 镜像运行开始时间
} xsfp_upgrade_info;

#define ADD_MODE_FLAG       1
#define DEL_MODE_FLAG       2
#define IP_DIR_SIZE         8
#define IP_RET_DATA_SIZE    32
#define IP_MAX_RULE_NUM     50
#define IP_RULE_SIZE        128
#define IP_MAX_SIZE         2048
#define IP_ROUTE_DATA_SIZE  4096
#define IP_CMD_SIZE         512

struct ip_rule_t {
    char dir[IP_DIR_SIZE];
    char ip[MAX_IP_VAL_LEN];
    unsigned int table;
    unsigned char addel;
};

struct ip_rule_ret_t {
    unsigned int priority;
    char selector[IP_RET_DATA_SIZE];
    char action[IP_RET_DATA_SIZE];
    char table[IP_RET_DATA_SIZE];
};

struct ip_rules_ret_t {
    struct ip_rule_ret_t *ip_rules;
    unsigned int ip_rules_num;
};

struct ip_route_t {
    unsigned int ip_mask;      /* 0~32 */
    unsigned int table_id;     /* 0~255 */
    unsigned int addel;
    char ip_address[MAX_IP_VAL_LEN];
    char via_address[MAX_IP_VAL_LEN];
};

typedef struct {
    unsigned int index;
    unsigned int addr_high;      // 固件包在HBM中存储的起始物理地址
    unsigned int addr_low;
    unsigned int size;           // 固件包大小
} xsfp_upgrade_fw_info_t;

struct link_stat_data {
    unsigned int  logic_id;
    unsigned int  udie_id;
    unsigned int  port_id;
    char link_status[LINK_STATUS_MAX_LEN];
    char time[TIME_MAX_LEN];
};

typedef struct {
    unsigned long long link_up_cnt;
    unsigned long long link_down_cnt;
    unsigned int up_timestamp[LINK_STAT_MAX_IDX];
    unsigned int down_timestamp[LINK_STAT_MAX_IDX];
} link_info_data;

union fec_mode_cfg_t {
    struct {
        unsigned int rs_mode;            // 0：bypass; 1: 128 T2算法, 2:128 T4算法
        unsigned int auto_change_mode;   // 0:静态配置; 1:动态配置（auto自适应）
        unsigned int itlv_mode;          // 0:非交织模式; 1:交织模式
    } ub_fec_mode_cfg;
    struct {
        unsigned int rs_mode;            // 0：no-fec; 2: RSFEC (528,514); 3: RSFEC (544,514); 5:RSFEC (544,514)
    } eth_fec_mode_cfg;
};

struct fec_query_cmdq_req_t {
    unsigned int port_id;
    unsigned int mode;
    union fec_mode_cfg_t fec_cfg;
};

struct fmea_info_out_band {
    unsigned char qdd_fail;
    unsigned char cdr_fail;
    unsigned char cpld_fail;
};

typedef struct dft_i2c_param_t {
    enum {
        DFT_I2C_CMD_START_TEST,  // 启动压测
        DFT_I2C_CMD_GET_RESULT,  // 获取压测结果
        DFT_I2C_CMD_CLEAR_RESULT // 清除压测结果
    } cmd;
    enum {
        DFT_I2C_TYPE_CPLD        = 1 << 0,
        DFT_I2C_TYPE_OSFP        = 1 << 1,
    } i2c_test_object; /* 按bit位表示是否需要执行cpld和光模块的压测 */
} dft_I2c_test_param;

typedef enum {
    DFT_I2C_TEST_RUNNING = 0,
    DFT_I2C_TEST_SUCCESS,
    DFT_I2C_TEST_START_FAILURE,
    DFT_I2C_TEST_RESULT_FAILURE,
    DFT_I2C_TEST_NA,
    DFT_I2C_TEST_STATUS_MAX
} dft_I2c_test_status;

#define PARAM_INVALID   (-1)
#define IP_VAL_LEN      20

typedef struct {
    unsigned int enable;
    unsigned int period;
    char ip_addr[MAX_IP_VAL_LEN];
} arp_param_t;

#pragma pack()

#define UBOE_PORT_INDEX     8

#define DOWN_DATA_LOG_MAX   5
#define MAX_PORT_NUM 10
#define INBUFCOUNT 2
#define MAX_LANE_NUMS 4
#define DUMP_RX_CTLE_STR_LEN 90

struct down_data_log_t {
    struct {
        int snr_metric;
        int metric_his_min;
        int err_avg;
        int cycles_avg;
        int heh_avg;
    } snr;
    struct {
        unsigned int c3_ud_2csr;
        unsigned int c5_ud_2csr;
    } rx_ffe_cfg;
};

typedef struct {
    unsigned int times; // rdfx 查询时会赋值
    unsigned int end_index;
    struct down_data_log_t data[MAX_LANE_NUMS];
} down_data_log_port_item_t;

typedef struct {
    unsigned int times; // rdfx 查询时会赋值
    unsigned int end_index;
    struct down_data_log_t data[DOWN_DATA_LOG_MAX][MAX_LANE_NUMS];
} down_data_log_port_info_t;

#define LANE_NUMBER_UBOE 2
#define LANE_NUMBER_ELSE 4

typedef struct {
    int lane;
    int snr_metric;
    int metric_his_min;
    int err_avg;
    int cycles_avg;
    int heh_avg;
    unsigned int c3_ud_2csr;
    unsigned int c5_ud_2csr;
} down_data_table_row_t;
typedef struct {
    unsigned int port;   // 对应上层传入的第一个u32
    unsigned int index;   // 对应上层传入的第二个u32
} port_lane_inbuf_t;

#define MAX_UB_DIE_NUM  2
#define MAX_UB_PORT_NUM 9
#define MAX_UB_PF_NUM   2

typedef struct {
    unsigned char udie_id;
    unsigned char port_id;
    unsigned char pf_id;
} ub_port_param_t;

#pragma pack(1)
typedef struct { // 闪断时端口统计信息
    unsigned int time;                          // 时间戳
    unsigned int npu_rx_snr[MAX_LANE_NUMS];     // NPU端口SNR
    unsigned long long pcs_err_cnt;             // pcs_err_cnt
    unsigned long long cw_before_correct_cnt;   // fec纠前误码
    unsigned long long cw_correct_cnt;          // fec纠后误码
    unsigned long long cw_uncorrect_cnt;        // fec未纠误码
} port_linkdown_info_inner_t;

typedef struct linkdown_info_head {
    unsigned char all;     // 队列中有多少数据包
    unsigned char num;     // 本帧中有多少数据包
} linkdown_info_head_t;

typedef struct {
    unsigned int slot_id;
    unsigned int port_type;
    linkdown_info_head_t info_head;
    port_linkdown_info_inner_t inner_info;
} port_linkdown_info_t;
#pragma pack()

#define XSFP_DD_FORCE_PWR_OFFSET  4  // 光模块第4位
#define XSFP_DD_PWR_OFFSET        6  // 光模块第6位

// ------------------ 光模块固件升级参数结构 ------------------
#define OPTICAL_FW_VERSION_LEN 32
// 光模块固件升级状态机状态（用于HCCN工具侧）
typedef enum {
    OPTICAL_UPGRADE_SM_IDLE = 0,
    OPTICAL_UPGRADE_SM_FEATURES_GET,
    OPTICAL_UPGRADE_SM_START_DOWNLOAD,
    OPTICAL_UPGRADE_SM_WRITE_FW,
    OPTICAL_UPGRADE_SM_COMPLETE_DOWNLOAD,
    OPTICAL_UPGRADE_SM_RUN_FW_IMAGE,
    OPTICAL_UPGRADE_SM_COMMIT_FW_IMAGE,
    OPTICAL_UPGRADE_SM_SUCCESS,
    OPTICAL_UPGRADE_SM_FAULT_PROC,
    OPTICAL_UPGRADE_SM_MAX,  // Array size sentinel
} OPTICAL_FW_UPGRADE_SM_E;
 
// 光模块固件升级处理状态（简化状态，用于HCCN工具侧）
typedef enum {
    OPTICAL_UPGRADE_STATE_IDLE = 0,
    OPTICAL_UPGRADE_STATE_PROCESSING,
    OPTICAL_UPGRADE_STATE_SUCCESS,
    OPTICAL_UPGRADE_STATE_FAILED,
    OPTICAL_UPGRADE_STATE_MAX,  // Array size sentinel
} OPTICAL_FW_UPGRADE_STATE_E;

// DSMI -> RDFX 升级请求（固件路径，光模块ID和udie_id由公共部分处理）
struct optical_upgrade_req {
    char firmware_path[PATH_MAX];  // 固件文件路径，使用Linux最大路径长度
};
 
// RDFX -> IMP 固件地址信息（HBM物理地址拆分为高低32位）
typedef struct {
    unsigned int optical_index;    // 光模块索引（通过 optical_id 获取）
    unsigned int addr_high;        // 固件包在HBM中存储的起始物理地址高32位
    unsigned int addr_low;         // 固件包在HBM中存储的起始物理地址低32位
    unsigned int size;             // 固件包大小
} xsfp_firmware_info;
 
// 升级状态重置请求（包含 HBM 内存释放信息）
struct xsfp_upgrade_reset {
    unsigned int optical_index;       // 光模块索引（IMP 期望 u32 类型）
    // HBM 内存信息（用于释放已分配的 HBM 内存）
    unsigned int hbm_addr_high;       // HBM 物理地址高 32 位
    unsigned int hbm_addr_low;        // HBM 物理地址低 32 位
    unsigned int hbm_size;            // HBM 内存大小
    unsigned int hbm_dma_addr_high;   // DMA 地址高 32 位
    unsigned int hbm_dma_addr_low;    // DMA 地址低 32 位
    int hbm_dma_mapped;               // 是否已进行 DMA mapping
};
 
// 光模块固件升级结果（用于 tool 层）
struct optical_upgrade_result {
    xsfp_upgrade_state_t upgrade_state;  // 升级状态（包含state, sm_status, err_status）
    unsigned char progress;              // 升级进度 0-100（由状态机状态计算得出）
    unsigned char reserved1;             // 保留对齐
    unsigned short reserved2;            // 保留对齐
    char firmware_ver[OPTICAL_FW_VERSION_LEN];
    // HBM 内存信息（用于升级失败或超时时释放内存）
    unsigned int hbm_addr_high;          // HBM 物理地址高 32 位
    unsigned int hbm_addr_low;           // HBM 物理地址低 32 位
    unsigned int hbm_size;               // HBM 内存大小
    unsigned int hbm_dma_addr_high;      // DMA 地址高 32 位
    unsigned int hbm_dma_addr_low;       // DMA 地址低 32 位
    int hbm_dma_mapped;                  // 是否已进行 DMA mapping
};

#define MAX_PRI_NUM 8

#define PFC_RX          0    // 0: pfc rx
#define PFC_TX          1    // 1: pfc tx
#define SLAVE_NAME_IDX0 0
#define SLAVE_NAME_IDX1 1
#define BOND_SLAVE_NUM  2
#define SLAVE_NAME_LEN  16

struct pfc_time_t {
    unsigned long long pause_tx;
    unsigned long long pause_rx;
    unsigned long long pfc_tx[MAX_PRI_NUM];
    unsigned long long pfc_rx[MAX_PRI_NUM];
};

struct pfc_count_t {
    unsigned int pause_rx_cnt;
    unsigned int pause_tx_cnt;
    unsigned int pause_rx_warning_cnt;
    unsigned int pause_tx_warning_cnt;
    unsigned int pfc_rx_err_cnt[MAX_PRI_NUM];
    unsigned int pfc_tx_err_cnt[MAX_PRI_NUM];
    unsigned int pfc_rx_warn_cnt[MAX_PRI_NUM];
    unsigned int pfc_tx_warn_cnt[MAX_PRI_NUM];
};

struct pfc_stat_info_t {
    char slave_name[SLAVE_NAME_LEN];
    struct pfc_time_t pfc_time;
    struct pfc_count_t pfc_count;
};

struct pfc_storm_t {
    unsigned char mode;
    unsigned char rsv[3];
    unsigned int dir;
    unsigned int detect_period;
    unsigned int warn_thrd;
    unsigned int err_thrd;
    unsigned int close_time;
};

struct pfc_storm_info_t {
    struct pfc_storm_t pfc_storm_rx;
    struct pfc_storm_t pfc_storm_tx;
};

#define MAX_EID_NUM                 48
#define UBPING_MESH_MAX_NUM         48
#define UB_PING_RESERVE_NUM         4

struct ubping_pair_info {
    char src_addr[MAX_IP_VAL_LEN];
    char dst_addr[MAX_IP_VAL_LEN];
};

struct ub_ping_operate {
    struct ubping_pair_info ub_pair_info;  // 源/目的eid对
    int ub_pair_num;
    int pkt_size;             // ping报文大小，取值范围：0~4046，默认值为4046，注这里需要看ip over urma的mtu值是多少
    int pkt_send_num;            // ping报文发送轮数, 默认为3轮；
    int pkt_interval;            // ping报文间隔，多久发送一次，默认值为1S；
    int timeout;             // ping超时时间，发送失败了后直接停止；
    int reserve;                // 预留字段
};

struct ub_ping_result {
    unsigned int suc_pkt_num;    // ping成功次数
    unsigned int fail_pkt_num;    // ping失败次数
    long max_time;                // ping最大时延
    long min_time;                // ping最小时延
    long avg_time;                // ping平均时延
    long tp95_time;               // ping时延TP95分位数
    long reserve;                 // 预留字段
};

struct dcmi_ub_ping_operate {
    struct ubping_pair_info ub_pair_info;  // 源/目的eid对
    int pkt_size;             // ping报文大小，取值范围：0~4046，默认值为4046，注这里需要看ip over urma的mtu值是多少
    int pkt_send_num;            // ping报文发送轮数, 默认为3轮；
    int pkt_interval;            // ping报文间隔，多久发送一次，默认值为1S；
    int timeout;             // ping超时时间，发送失败了后直接停止；
    int task_interval;            // 常驻任务轮询间隔
};

struct ubping_mesh_operate {
    struct ubping_pair_info ub_pair_info[UBPING_MESH_MAX_NUM];
    int pair_num;
    int pkt_size;
    int pkt_send_num;
    int pkt_interval;
    int task_interval;
    unsigned int reserved[UB_PING_RESERVE_NUM];
};

struct ubping_mesh_result {
    struct ubping_pair_info ub_pair_info;
    long max_time_us;     // ping最大时延
    long min_time_us;     // ping最小时延
    long avg_time_us;     // ping平均时延
    long tp95_time_us;     // ping时延TP95分位数
    unsigned int suc_pkt_num;  // ping成功次数
    unsigned int fail_pkt_num;  // ping失败次数
    int reply_stat_num;    // 统计结果所用样本轮数
};

struct ubping_mesh_info {
    int result_num;
    struct ubping_mesh_result ub_ping_result[UBPING_MESH_MAX_NUM];
};

#endif