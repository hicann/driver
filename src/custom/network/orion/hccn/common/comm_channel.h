/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef COMM_CHANNEL_H
#define COMM_CHANNEL_H

#include "utils/compiler.h"
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define LINK_STAT_MAX_ROW_NUM 10
#define LINK_PRINT_COL        5
#define TIME_MAX_LEN          25
#define MSG_MAX_SIZE          1024
#define LINK_TIME_INFO_LEN    50

#include "comm_channel_ext.h"

#pragma pack(4)

struct product_channel_msg {
    void *inbuf;
    unsigned int inlen;
    void *outbuf;
    unsigned int outlen;
};

typedef enum {
    OPTICAL_ID_0 = 0,
    OPTICAL_ID_1,
    OPTICAL_ID_2,
    OPTICAL_ID_3,
    OPTICAL_ID_4,
    OPTICAL_ID_MAX,
} optical_id_t;

typedef enum {
    XSFP_PRODUCT_UNKNOWN,
    XSFP_PRODUCT_SFP,
    XSFP_PRODUCT_QSFP,
    XSFP_PRODUCT_QSFP_DD,
    XSFP_PRODUCT_OSFP,
    XSFP_PRODUCT_LPO,
    XSFP_PRODUCT_OSFP_ACC
} XSFP_PRODUCT_TYPE;

#define MODULE_TYPE_ACC 0x04

// ↓ 以下是数据结构区间
#ifdef DEBUG_MODE
struct i2c_test_t {
    unsigned char dev;
    unsigned char reg;
    unsigned char rw;
    unsigned int  val;
};
#endif
struct hccn_speed_t {
    unsigned int speed;  // 速率
    unsigned int cap;    // 理论能力
    unsigned int width;  // 实际能力
    unsigned int status; // 降lane状态
};

#pragma pack()
#define VENDOR_NAME_LEN             16
#define VENDOR_PN_LEN               16
#define VENDOR_SN_LEN               16
#define VENDOR_REV_LENGTH           2
#define FOUR_VALUE                  4
#define TWO_VALUE                   2
#define DATA_CODE_LEN               8
#define WAVE_LEN                    2
#define XSFP_VENDOR_REV_LEN         4
#define THREE_VALUE                 3
#define XSFP_NAME_LEN               20
#define XSFP_OUI_LEN                3
#define XSFP_PN_LEN                 20
#define XSFP_WAVE_LEN               2
#define XSFP_SN_LEN                 20
#define XSFP_DATACODE_LEN           12
#define XSFP_POWER_LEN              16
#define XSFP_SNR_LEN                8
#define XSFP_MEDIA_LEN              4
#define XSFP_SHOW_SNR_LEN           4
#define XSFP_PHYSICAL_CODE_LEN      16
#define XSFP_MAX_OPTICAL_MODULE_NUM 1
#define XSFP_SPEC_COMPLIANCE_LEN    12
#define XSFP_MEDIAINTERFACE_LENGTH  1
#define XSFP_PRESENT_PRODUCT        1
#define XSFP_ABSENT_PRODUCT         0
#define MAX_DP_NUM                  8
#define SUPPORT_INFO_LAST_BIT       6
#define BIT_NUM_FOUR                4
#define BIT_NUM_THREE               3
#define MANAGE_CHARACTER_NUM        3
#define MAX_APP_DESC_NUM            32
#define OSFP_PAGE_INFO_LEFT_NUM     63
#define QDD_PAGE_INFO_LEFT_NUM      64
#define XSFP_PAGE_REG_LENGTH        128
#define XSFP_PAGE_REG_MAX_LENGTH    256
#define LANE_NUMBER                 4
#define MAX_IPV6_NUM                16
#define PERCENT_NINETY_FIVE         95
#define MAX_PING_RESULT_LEN         1024
#define MAX_PING_PKT_NUM            1000
#define MAX_PING_PKT_SIZE           4046
#define MAX_PING_PKT_INTERVAL       10000
#define MAX_PING_TIMEOUT            10000
#define NS_CHANGE_TO_US             1000
#define US_CHANGE_TO_MS             1000
#define DEFAULT_TIMEOUT_TIME        1000
#define DEFAULT_PKT_SEND_NUM        3
#define DEFAULT_PKT_INTERVAL        1000
#define DEFAULT_PKT_SIZE            4046
#define CHANGE_TO_PERCENT           100
#define PKT_SEND_FAIL               (-1)
#define PING_RESULT_BUF_SIZE        200
#define DFT_I2C_TEST_TYPE_COUNT     2
#define MAX_DIE_NUM                 2
#define SERVER_NPU_NUM              8

#define XSFP_VPP_SCALE              (1.0f / 10.0f)
#define XSFP_SNR_SCALE              (1.0f / 256.0f)
#define XSFP_LTP_SCALE              (1.0f / 256.0f)

#define CMD_OPS_IDX 2
#define DEFAULT_FILL_CONTENT "********"
struct check_element {
    char *cmd;
    char *config_para;
};

#pragma pack(1)

/* 需与 build_ubcfg.py 中的 MediumType 对应 */
enum optical_medium_type_t {
    MEDIUM_ACC  = 0,
    MEDIUM_LPO  = 1,
    MEDIUM_ODSP = 2,
    MEDIUM_MAX  = 3
};

/* 需与 build_ubcfg.py 中的 ModuleType 对应 */
enum laser_module_type_t {
    LASER_VCSEL = 0,
    LASER_SIPH  = 1,
    LASER_SIPH2 = 2,
    LASER_OTHER = 3,
};

/* 需与 build_ubcfg.py 中的 ChipType 对应 */
enum npu_chip_type_t {
    NPU_CHIP_V100 = 0,
    NPU_CHIP_V120 = 1,
    NPU_CHIP_V121 = 2
};

// 静态信息，module级别，结构体成员变量需要保证4字节对齐
typedef struct {
    unsigned char vendor_oui[XSFP_OUI_LEN + 1];      // 带外不使用
    unsigned char vendor_name[XSFP_NAME_LEN];
    unsigned char vendor_sn[XSFP_SN_LEN];
    unsigned char vendor_pn[XSFP_PN_LEN];
    unsigned char physical_code[XSFP_PHYSICAL_CODE_LEN + FOUR_VALUE];     // 物理编码
    unsigned char date_code[XSFP_DATACODE_LEN];
    unsigned char laser_interface;     // 激光器类型
    unsigned char vendor_rev[XSFP_VENDOR_REV_LEN];
    unsigned char specification_compliance[XSFP_SPEC_COMPLIANCE_LEN];   // xsfp_get_specification_compliance
} xsfp_manufacture_info;

// 静态信息，module级别
typedef struct {
    int temp_high_threshold;
    int temp_low_threshold;
    int temp_high_alarm_threshold;
    int temp_low_alarm_threshold;

    int vcc_high_threshold;
    int vcc_low_threshold;
    int vcc_high_alarm_threshold;
    int vcc_low_alarm_threshold;

    int tx_power_high_threshold;
    int tx_power_low_threshold;
    int tx_power_high_alarm_threshold;
    int tx_power_low_alarm_threshold;

    int tx_bias_high_threshold;
    int tx_bias_low_threshold;
    int tx_bias_high_alarm_threshold;
    int tx_bias_low_alarm_threshold;

    int rx_power_high_threshold;
    int rx_power_low_threshold;
    int rx_power_high_alarm_threshold;
    int rx_power_low_alarm_threshold;
} xsfp_threshold_info;

// 静态信息，module级别
typedef struct {
    unsigned char wavelength[WAVE_LEN];
    unsigned char xsfp_identifier;
    unsigned char media_type;    // Code:MediaType 01h:MMF 02h:SMF 03h: Passive Cu 04h: Active Cables
    unsigned int optical_speed;
    unsigned char optical_type;
    unsigned char dr4_flag;
    unsigned char optical_lane_cnt;        // 光模块光侧lane数量
    unsigned char electrical_lane_cnt;     // 光模块电侧lane数量
    unsigned char media_info[XSFP_MEDIA_LEN];      // media type 介质类型，qdd为module_host_options，qsfp为transceiver_codes
} xsfp_base_info;

// module级别
typedef struct {
    unsigned char txlos;
    unsigned char txlol;
    unsigned char rxlos;
    unsigned char rxlol;
} xsfp_adapt_info;

// dp级别维护
typedef struct {
    unsigned short tx_bias;
    unsigned short rx_power;
    unsigned short tx_power;
    unsigned short host_snr;
    unsigned short media_snr;
} xsfp_dp_monitor_info;

#define GET_VDM_INFO_FIELD_COUNT() \
    (sizeof(xsfp_dp_vdm_info_t) / sizeof(unsigned short))

#define GET_VDM_INFO_FIELD_INDEX(field) \
    (&((xsfp_dp_vdm_info_t *)0)->field - ((xsfp_dp_vdm_info_t *)0)->begin)

/* VDM (Versatile Diagnostics Monitoring) 信息具名数组，每个字段2字节。 */
typedef struct {
    unsigned short begin[0];
    unsigned short host_ltp;
    unsigned short media_ltp;
    unsigned short tx_vpp;
    unsigned short rx_vpp;
    unsigned short end[0];
} xsfp_dp_vdm_info_t;

/* 光模块的 VDM (Versatile Diagnostics Monitoring) 信息。
 * 假定不会存在只有部分lane有某个vdm字段的情况。 */
typedef struct {
    unsigned char valid_bitmap[4];  /* bit位表征 xsfp_dp_vdm_info_t 中字段的有效性 */
    xsfp_dp_vdm_info_t lanes[MAX_DP_NUM];
} xsfp_vdm_info_t;

STATIC_ASSERT(
    (sizeof(((xsfp_vdm_info_t *)0)->valid_bitmap) * 0x8) >= GET_VDM_INFO_FIELD_COUNT(),
    size_of_valid_bitmap_too_small);

typedef struct {
    int temperature;
    int voltage;
    int tx_fault;
    xsfp_adapt_info adapt_info;
    xsfp_dp_monitor_info dp_info[MAX_DP_NUM];
    xsfp_vdm_info_t vdm_info;
    unsigned char loopback_mode;
    unsigned char tx_signal;
    unsigned char recv[2];
} xsfp_dynamic_info;

typedef struct {
    int temperature;
    int tx_fault;
    xsfp_dp_monitor_info dp_info[MAX_DP_NUM];
    xsfp_vdm_info_t vdm_info;
    unsigned char hostsnr_support;
    unsigned char mediasnr_support;
    unsigned char access_failed;
    unsigned char optical_type;
} xsfp_extra_info;

// 每条lane一个dpsm，单独维护状态
typedef struct {
    unsigned char dpsm_stat; // dpsm状态
    unsigned char last_master_output_disable;
    unsigned char last_slave_output_disable;
    unsigned char master_output_disable;
    unsigned char slave_output_disable; // 从光模块关光状态
    unsigned char last_master_dp_ready;
    unsigned char last_slave_dp_ready;
    unsigned char master_dp_ready;
    unsigned char slave_dp_ready; // 从光模块dp ready状态
    unsigned char master_dp_reinit_flag; // dp重启事件标记
    unsigned char slave_dp_reinit_flag;
    unsigned char dpsm_init_machine;
    unsigned long long last_time;
} xsfp_dpsm_stat;

struct osfp_page_info {
    unsigned char manage_character;
    unsigned char app_desc_page0[MAX_APP_DESC_NUM];
    unsigned char app_desc_page1[MAX_APP_DESC_NUM];
    char page_info[OSFP_PAGE_INFO_LEFT_NUM];
};

struct qdd_page_info {
    unsigned char app_desc_page0[MAX_APP_DESC_NUM];
    unsigned char app_desc_page1[MAX_APP_DESC_NUM];
    char page_info[QDD_PAGE_INFO_LEFT_NUM];
};

typedef struct {
    union {
        struct osfp_page_info osfp_info; // OSFP光模块page页信息，端口拆分的信息
        struct qdd_page_info qsfpdd_info; // QDD光模块page页信息
        unsigned char info[XSFP_PAGE_REG_LENGTH]; // 获取对应寄存器信息
    } xsfp_info; // 初始化时一把拿走
    unsigned char type; // 光模块类型，osfp/lpo/qdd/ACC
    unsigned char data_valid; // 当前信息是否可访问
    unsigned char hot_reset; // 当前是否为热复位场景
    unsigned char last_master_xsfp_present; // 上次主控模块的在位状态
    unsigned char last_slave_xsfp_present; // 上次互助光模块的在位状态
    unsigned char master_xsfp_present; // 主控模块的在位状态
    unsigned char slave_xsfp_present; // 互助光模块的在位状态
    unsigned char last_master_xsfp_inited; // 上一次主控模块初始化状态
    unsigned char last_slave_xsfp_inited; // 上一次从控光模块初始化状态
    unsigned char master_xsfp_inited; // 主控模块是否做过模块级初始化标识
    unsigned char slave_xsfp_inited; // 从控光模块是否做过模块级初始化表示
    unsigned char dp_ready; // dp初始化完成标志，每条lane一个bit
    unsigned char msm_stat; // msm状态
    unsigned char fail_cnt; // 总失败次数
    unsigned char appsel_code;
    unsigned char lane_num; // qdd 4, osfp 8
    unsigned char lane_mask; // qdd 0xf, osfp 0xff
    unsigned char xsfp_init_machine_stat;
    unsigned char udie_msg_fail_cnt;
    unsigned char recv_flag;
    unsigned long long last_time; // 当前状态重试次数
    unsigned long long change_timestamp;
    xsfp_dpsm_stat dp_info[MAX_DP_NUM / 2]; // DPSM状态信息, osfp维护8条lane， qdd维护4条lane
} xsfp_config_info;

typedef struct {
    unsigned char hostsnr_support;
    unsigned char mediasnr_support;
    unsigned char loopback_support;
    unsigned char recv_flag;
    unsigned char prbs_support;
    unsigned char smart_support; // 智慧光模块能力合集
    unsigned char reserved[2];
} xsfp_support;

enum XSFP_SMART_SUPPORT_CAP {
    XSFP_SMART_SUPPORT_DD = 0,
    XSFP_SMART_SUPPORT_BUTT = 8,
};

typedef struct {
    unsigned int optical_run_time;                  // 模块运行时间
    unsigned int optical_power_on_time;             // 不支持  模块上电运行时间, 光模块累计上电时间, 掉电保存; 单位: 天
    unsigned int odsp_high_heat_time;               // 不支持
    unsigned int laser_run_time;                    // 激光器运行时间, 激光器开光累计工作时间, 掉点保存; 单位: 天
    unsigned int hard_bad;                          // 模块本体诊断Error, 说明模块硬件有一般隐患，可能造成业务性能劣化
    unsigned int hard_err;                          // 模块本体诊断Bad, 说明硬件硬件有严重故障，业务会受到影响或者已经产生影响
    unsigned short optical_power_on_count;          // 模块上电次数, 记录包括光模块正常工作下复位,插拔导致的光模块重新上下电的事件统计次数, 掉电保存; 单位: 次
    unsigned short optical_power_on_status;         // 不支持
    unsigned short odsp_temp;                       // ODSP结温上报, 单位:1/256 degree
    unsigned short laser_temp;                      // 激光器温度, 单位:1/256 degree
    unsigned short laser_core_temp;                 // 不支持
    unsigned short electrical_link_detection;       // 电链路诊断告警, 表征当前模块电链路HRX有信号幅度/告警
    unsigned short optical_link_detection;          // 光链路诊断告警, 表征光口性能相比出厂有劣化(SNR或者光功率跌落)
    unsigned char severe_optical_link_detection;    // 光链路严重告警, 表征光口性能已经严重劣化，处于逼近或已有纠后误码状态
    unsigned char is_first_printed;                 // 避免重复打印的标识
} xsfp_smart_info;

typedef struct {
    unsigned char access_failed;
    // 这里不要新增字段，会影响带外获取，详见 rdfx_out_band_get_xsfp_field
    xsfp_base_info base_data;
    xsfp_support xsfp_capabilities;
    xsfp_config_info config_data;
    xsfp_manufacture_info manufacture_data;
    xsfp_threshold_info threshold_data;
    xsfp_dynamic_info dynamic_data;
    xsfp_smart_info smart_data;
    xsfp_upgrade_info upgrade_info;     // 固件升级信息
    unsigned char available;            // 模块可用标识
    unsigned char rev_len[TWO_VALUE];
} xsfp_module_info;

typedef struct {
    unsigned char optical_type;
    xsfp_config_info config_data;
    xsfp_dynamic_info dynamic_data;
} xsfp_cfg_status_info;

struct ub_port_cfg_param {
    int present;
    int medium_type;    // 光模块介质类型（ODSP / LPO / ACC）
    int laser_interface;        // 激光器类型
    unsigned char dr4_flag;     // DR8/DR4标志
    unsigned char param_config_done;           // serdes参数是否已完成配置
    unsigned char vendor_name[XSFP_NAME_LEN];
    unsigned char vendor_pn[XSFP_PN_LEN];
    unsigned char physical_code[XSFP_PHYSICAL_CODE_LEN + FOUR_VALUE];
};

typedef struct xsfp_linkdown_info_inner {
    unsigned int time;
    unsigned int reserve;
    unsigned int volt;
    unsigned int tx_power[MAX_DP_NUM];
    unsigned int rx_power[MAX_DP_NUM];
    unsigned int bias[MAX_DP_NUM];
    unsigned int tx_los;
    unsigned int rx_los;
    unsigned int tx_lol;
    unsigned int rx_lol;
    unsigned int temperature;
    unsigned int tx_fault;
    unsigned short host_snr_or_tx_vpp[MAX_DP_NUM];
    unsigned short media_snr_or_rx_vpp[MAX_DP_NUM];
    unsigned char optical_type; // 光模块类型,用于解析tx/rx功率
    unsigned char resv[3]; // 3:对齐
} xsfp_linkdown_info_inner_t;

typedef struct xsfp_linkdown_info {
    unsigned char type;    // 标志数据包类型(如何解析)
    unsigned char all;     // 队列中有多少数据包
    unsigned char num;     // 本帧中有多少数据包
    unsigned char len;     // 一个数据包有多长
    xsfp_linkdown_info_inner_t inner_info;
} xsfp_linkdown_info_t;
#pragma pack()

// 建议较晚引用当前头文件，以防其他定义unlikely的地方不做校验
#ifndef unlikely
#define unlikely(x)     __builtin_expect((x), 0)
#endif

enum xsfp_task_status {
    XSFP_TASK_INIT = 0,
    XSFP_TASK_RUNNING,
    XSFP_TASK_SUCCESS,
    XSFP_TASK_ERROR
};

// 用于填充product_channel_msg的宏，不做成函数是为了能被 TOOL DSMI RDFX HCLGE IMP 都能调用到
#define SET_PRODUCT_MSG(msg, _inbuf, _inlen, _outbuf, _outlen) \
    do { \
        (msg).inbuf = (_inbuf); \
        (msg).inlen = (_inlen); \
        (msg).outbuf = (_outbuf); \
        (msg).outlen = (_outlen); \
    } while (0)

// ↓ 以下是命令字区间 0~0xFFFF
// 产品命令字
#ifdef DEBUG_MODE
#define CMD_I2C_OPERATE                         0x0001
#endif
#define CMD_GET_SPEED                           0x0002
#define CMD_OPTICAL_OPERATE_BASE_DATA           0x0003
#define CMD_OPTICAL_OPERATE_XSFP_CAPABILITIES   0x0004
#define CMD_OPTICAL_OPERATE_CONFIG_DATA         0x0005
#define CMD_OPTICAL_OPERATE_MANUFACTURE_DATA    0x0006
#define CMD_OPTICAL_OPERATE_THRESHOLD_DATA      0x0007
#define CMD_OPTICAL_OPERATE_DYNAMIC_DATA        0x0008
#define CMD_GET_SERDES                          0x0009
#define CMD_DUMP_REGS                           0x000A
#define CMD_OPTICAL_OPERATE_ACCESS_FAILED_DATA  0x000B
#define CMD_LINK_STAT_OPERATE                   0x000C
#define CMD_GET_UB_PING_INFO                    0x000D
#define CMD_SU_BER_TEST_MODE                    0x000E
#define CMD_SU_BER_GET_MODE_STATUS              0x000F
#define CMD_SU_BER_SET_CLEAR                    0x0010
#define CMD_SU_BER_GET_RESULT                   0x0011
#define CMD_GET_FMEA_INFO                       0x0012

#define CMD_GET_SLOT_ID                         0x0013
#define CMD_GET_PORT_CFG_PARAM                  0x0014
#define CMD_SET_PORT_CFG_DONE                   0x0015
#define CMD_GET_DOWN_DATA                       0x0016
#define CMD_OPTICAL_OPERATE_EXTRA_DATA          0x0017
#define CMD_GET_PORT_LINK_DOWN_INFO             0x0018
#define CMD_GET_OPTICAL_SMART_INFO              0x0019
#define CMD_SET_XSFP_PRBS_CONFIG                0x001A
#define CMD_HANDLE_XSFP_PRBS                    0x001B
#define CMD_GET_XSFP_PRBS_RESULT                0x001C
#define CMD_GET_SEND_ARP                        0x001D
#define CMD_SET_SEND_ARP                        0x001E
#define CMD_GET_XSFP_LINKDOWN_INFO              0x001F
#define CMD_OPTICAL_TX_SIGNAL                   0x0020
#define CMD_OPTICAL_OPERATE_CFG_STATUS          0x0021
#define CMD_OPTICAL_UPGRADE_FIRMWARE            0x0022  // 光模块固件升级
#define CMD_OPTICAL_GET_UPGRADE_STATUS          0x0023  // 查询升级状态
#define CMD_OPTICAL_UPGRADE_RESET               0x0024  // 重置升级状态
#define CMD_START_PINGMESH_TASK                 0x0025
#define CMD_STOP_PINGMESH_TASK                  0x0026
#define CMD_GET_PINGMESH_STAT                   0x0027
#define CMD_GET_PINGMESH_RESULT                 0x0028
#define CMD_SET_UDP_SPORT_MODE                  0x0029
#define CMD_GET_UDP_SPORT_MODE                  0x002A
#define CMD_OPTICAL_RESET                       0x002B
#define CMD_SET_UBOE_PORT_EN_CONTROL            0x002C
#define CMD_OPTICAL_SET_POWER_MODE              0x002D
// 预留 0x002E
// 预留 0x002F
#define CMD_OPTICAL_OPERATE_DUMP_REG            0x0030
#define CMD_OPTICAL_DUMP_REG_TASK_REGISTER      0x0031
#define CMD_OPTICAL_DUMP_REG_TASK_COMPLETE      0x0032
#define CMD_OPTICAL_DUMP_REG_GET_INFO           0x0033
#define CMD_OPTICAL_OPERATE_LOOPBACK            0x0034
#define CMD_OPTICAL_LOOPBACK_TASK_REGISTER      0x0035
#define CMD_OPTICAL_LOOPBACK_TASK_COMPLETE      0x0036
#define CMD_IP_RULE_GET                         0X0037
#define CMD_IP_RULE_SET                         0X0038
#define CMD_IP_ROUTE_SET                        0X0039
#define CMD_IP_ROUTE_GET                        0X003A
#define CMD_GET_PFC_STORM                       0x003B
#define CMD_SET_PFC_STORM                       0x003C
#define CMD_GET_PFC_STAT                        0x003D
#define CMD_SET_PFC_STAT                        0x003E
#define CMD_OPTICAL_DIRTY_DETECTION             0x003F

// 装备命令字
#define CMD_DFT_I2C_TEST_HANDLE                 0xE016

// 海思命令字
#define CMD_GET_ADAPT_STATUS                    0xFB04
#define CMDQ_FEC_QUERY_CMD                      0xFB80
#define CMD_PFC_OPERATE                         0xFB81      // 查询反压时间和清除
#define CMD_OP_PFC_STORM                        0xFB82      // 反压风暴参数
#define CMD_PFC_COUNT                           0xFB83      // 反压风暴统计

#endif
