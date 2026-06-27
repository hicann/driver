/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_SMI_H__
#define __NPU_SMI_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define TOOL_NAME "npu-smi"

#define NPU_MAX_LENTH 256
#define NPU_LONG_STR_MAX_LENGTH 512
#define NPU_MAX_COUNT 64    /* The system supports up to 64 cards */

#define NPU_DEFAULT_VALUE  (-1)
#define NPU_DEFAULT_TEMP_VALUE  (-200)

#ifdef DT_FLAG
#define STATIC
#else
#define STATIC static
#endif

#define NPU_OK                   0
#define NPU_ERR                  1
#define NPU_ERR_CODE_BASE        (-9000)
#define NPU_ERR_CODE_INVALID_PARAMETER             (NPU_ERR_CODE_BASE - 1)
#define NPU_ERR_CODE_OPER_NOT_PERMITTED            (NPU_ERR_CODE_BASE - 2)
#define NPU_ERR_CODE_MEM_OPERATE_FAIL              (NPU_ERR_CODE_BASE - 3)
#define NPU_ERR_CODE_SECURE_FUN_FAIL               (NPU_ERR_CODE_BASE - 4)
#define NPU_ERR_CODE_INNER_ERR                     (NPU_ERR_CODE_BASE - 5)
#define NPU_ERR_CODE_TIME_OUT                      (NPU_ERR_CODE_BASE - 6)
#define NPU_ERR_CODE_INVALID_DEVICE_ID             (NPU_ERR_CODE_BASE - 7)
#define NPU_ERR_CODE_DEVICE_NOT_EXIST              (NPU_ERR_CODE_BASE - 8)
#define NPU_ERR_CODE_IOCTL_FAIL                    (NPU_ERR_CODE_BASE - 9)
#define NPU_ERR_CODE_SEND_MSG_FAIL                 (NPU_ERR_CODE_BASE - 10)
#define NPU_ERR_CODE_RECV_MSG_FAIL                 (NPU_ERR_CODE_BASE - 11)
#define NPU_ERR_CODE_NOT_REDAY                     (NPU_ERR_CODE_BASE - 12)
#define NPU_ERR_CODE_NOT_SUPPORT_IN_CONTAINER      (NPU_ERR_CODE_BASE - 13)
#define NPU_ERR_CODE_FILE_OPERATE_FAIL             (NPU_ERR_CODE_BASE - 14)
#define NPU_ERR_CODE_RESET_FAIL                    (NPU_ERR_CODE_BASE - 15)
#define NPU_ERR_CODE_ABORT_OPERATE                 (NPU_ERR_CODE_BASE - 16)
#define NPU_ERR_CODE_PARAMETER_SHOW_HELP           (NPU_ERR_CODE_BASE - 17)
#define NPU_ERR_CODE_NO_MATRIX_PROC                (NPU_ERR_CODE_BASE - 18)
#define NPU_ERR_CODE_DCMI_FUN_FAIL                 (NPU_ERR_CODE_BASE - 19)
#define NPU_ERR_CODE_RESOURCE_OCCUPIED             (NPU_ERR_CODE_BASE - 20)
#define NPU_ERR_CODE_IS_UPGRADING                  (NPU_ERR_CODE_BASE - 21)
#define NPU_ERR_CODE_PARTITION_NOT_RIGHT           (NPU_ERR_CODE_BASE - 22)
#define NPU_ERR_CODE_NOT_SUPPORT                   (NPU_ERR_CODE_BASE - 255)
#define NPU_ERR_CODE_NOT_SUPPORT_FOR_WIN           (NPU_ERR_CODE_BASE - 256)


enum npu_watch_type {
    WATCH_INIT = 0,
    WATCH_CHIP_INFO,                   /* 芯片的监控数据 */
    WATCH_CHIP_PROC,                   /* 芯片的MATRIX进程状态 */
    WATCH_MAX                          /* 监控最大个数 */
};

enum npu_item_type {
    BOARD,               /* board 信息 */
    VOLT,                /* 电压 */
    TEMP,                /* 温度 */
    POWER,               /* 功耗 */
    HEALTH,              /* 健康状态 */
    MEMORY,              /* 内存 */
    FLASH,               /* 闪存 */
    ECC_ENABLE,          /* ECC 使能标志 */
    P2P_ENABLE_FLAG,     /* P2P 使能标志 */
    SSH_ENABLE,          /* 设置D芯片ssh使能 */
    USAGES,              /* 利用率 */
    COMMON,              /* 常用信息 */
    ECC,                 /* ECC 计数 */
    ECC_INFO,            /* ECC 统计信息 */
    IIC_CHECK,           /* iic 通道检测 */
    MCU_MONITOR,         /* MCU监控功能 */
    CUSTOMIZED_INFO,     /* 用户定制化信息 */
    CUSTOMIZED_CLEAR,    /* 清除用户定制化信息 */
    LICENSE,             /* 用户定制化信息 */
    BOOT_AREA,           /* uboot 切区 */
    IP,                  /* 设置npu芯片IP */
    ERR_COUNT,           /* 查询npu芯片误码率 */
    DEVICE_SHARE,        /* 设置共享模式 */
    SENSORS,             /* 芯片传感器 */
    SYS_TIME,            /* 系统时间 */
    PRODUCT_TYPE,        /* 查询产品类型 */
    MCU_ITEM,            /* MCU 标志 */
    COLLECT_LOG,         /* 收集日志 */
    RESET,               /* 复位 */
    DISK_POWER,          /* 设置硬盘上下电 */
    ERR_COUNT_CLEAR,     /* 清除npu芯片误码率 */
    BOOTLOADER,          /* MCU bootlader */
    NVE_LEVEL,           /* 设置算力等级或算力档位 */
    AICPU_CONF,          /* 配置AICPU和CONTRL CPU的配比 */
    REVOCATION,          /* 证书吊销 */
    ECC_INFO_CLEAR,      /* 清除ECC统计信息 */
    VNPU_MODE,           /* 算力切分模式 */
    VNPU_CREATE,         /* 算力切分创建 */
    VNPU_DESTORY,        /* 算力切分销毁 */
    VNPU_INFO,           /* 算力切分查询 */
    RESET_VNPU,          /* 复位vnpu    */
    SET_VNPU_SVM,        /* 虚拟设备共享内存阈值设置 */
    VNPU_SVM_INFO,       /* 虚拟设备共享内存阈值显示 */
    KEY_MANAGE,          /* 模型保护 */
    FIRST_POWER_ON_DATE, /* 单板首次上电时间 */
    TLS_CSR_GET,         /* TLS公钥/CSR文件读取 */
    DEV_CSR_GET,         /* DEV公钥/CSR文件读取 */
    TLS_CERT,            /* TLS证书信息读取/预置 */
    DEV_CERT,            /* DEV证书信息读取/预置 */
    TLS_CERT_PERIOD,     /* TLS证书有效期读取/预置/恢复 */
    ROOTKEY,               /* 数据加密硬件根密钥能力 */
    PROC_MEM,            /* 进程内存占用 */
    CHIP_TEST,           /* 芯片自检测试 */
    PERIPHERY_TEST,      /* 外围器件测试 */
    AGING,               /* 老化测试 */
    AGING_CLEAN,         /* 设置老化测试标志 */
    ELABLE,              /* 电子标签 */
    ELABLE_CLEAR,        /* 清除电子标签 */
    ClEAR_LOG,           /* 清除日志 */
    FIXTURE,             /* 夹具 */
    LED_TEST,            /* 点灯测试 */
    TEC_TEST,            /* 温控测试 */
    MAC_ADDR,            /* MAC 地址 */
    STRESS_START,        /* 启动压力测试 */
    STRESS_DOWNLOAD,     /* 下载压力测试包 */
    STRESS_STOP,         /* 停止压力测试 */
    STRESS_RESULT,       /* 压力测试结果 */
    HCCS_STRESS_START,   /* 启动HCCS压力测试 */
    HCCS_STRESS_STOP,    /* 停止HCCS压力测试 */
    HCCS_LOOPBACK_RESULT, /* HCCS 环回测试结果 */
    HCCS_LOOPBACK_START,  /* HCCS 环回测试开始 */
    HCCS_LOOPBACK_STOP,   /* HCCS 环回测试结束 */
    HCCS_LOOPBACK_PREPARE, /* HCCS 环回测试准备工作，HDLC断链操作 */
    START_SD_TEST,       /* 启动SD 卡文件读写测试 */
    STOP_SD_TEST,        /* 停止SD 卡文件读写测试 */
    MCU_INFO,            /* 获取MCU信息 */
    SWITCH_IIC,          /* IIC通道切换 */
    HBM_VOLT,            /* HBM电压 */
    VDDAVS_BIAS,         /* VDDAVS电源电压负拉偏 */
    PMU_VOLT,            /* PMU电压 */
    EQUIP_FLAG,          /* 装备测试标志 */
    NIC_TEST,            /* 100G接口卡装备测试 */
    NIC_LINK_SPEED,      /* 获取100G接口卡网口link和speed */
    HCCS_SPEED,          /* 获取芯片间HCCS 速率 */
    HCCS_STRESS_RESULT,  /* HCCS压力测试结果 */
    HBM_STATUS,          /* HBM失效测试 */
    PMU_DIE,             /* PMU DIE */
    HBM_FLAG,            /* HBM RESERVE FLAG */
    HBM_ERR_INFO,        /* HBM ERR INFO */
    HBM_REPAIR,          /* HBM 修复 */
    HBM_PG_FLAG,         /* HBM part good FLAG */
    HBM_REPAIR_INFO,     /* HBM 修复信息 */
    MARGIN_RESULT,       /* 眼图测试结果 */
    EDP_RESULT,          /* EDP信号检测结果 */
    TMP_PROTECT_START,   /* 启动过温保护测试 */
    TMP_PROTECT_STOP,    /* 停止过温保护测试 */
    TMP_PROTECT_RESULT,  /* 过温保护测试结果 */
    MCU_VERSION,         /* 查询MCU版本 */
    CPU_NUM_CFG,         /* 系统CPU配比 */
    VRD_ITEM,            /* vrd 标志 */
    HW_COMPATIBLE,       /* 防回滚硬件兼容性 */
    PHYID_REMAP,         /* PHYID查询CARD ID和 DEVICE ID */
    VNPU_CFG_RECOVER,    /* 配置恢复使能 */
    TEMPLATE_INFO,       /* 算力切分模板 */
    WATCH_INFO,
    PKCS_ENABLE,         /* pkcs签名校验 */
    PWM_MODE,            /* 风扇调速模式 */
    PWM_DUTY_RATIO,
    FAN_SPEED,           /* 风扇转速r/min */
    P2P_MEM_CFG,        /* bar空间拷贝开关 */
    CLEAR_ECC,           /* 清除ecc 内容 */
    BUTTON_TEST,         /* MCU控制下的按键测试 */
    POWER_STATE,         /* 设置休眠唤醒 */
    ITEMS_MAX,
    EMMC_DATA,          /* 1911 装备模组EMMC_DATA[4:7]测试 */
    TPM,                /* TPM在位检测 */
    HCCS_BER_TEST,       /* HCCS误码校验测试 */
    HCCS_BER_RESULT,     /* HCCS误码校验结果 */
    WORK_MODE,          /* NPU工作模式 */
    BOOT_SEL,           /* 启动介质 */
    BIOS_MBIST_FLAG,    /* bios-mbist自检标志 */
    BIOS_MBIST_TEST,    /* 获取bios-mbist自检结果 */
    OS_MBIST_TEST,      /* os-mbist自检 */
    CRACK_TEST,         /* crack自检 */
    TOPO,               /* npu拓扑关系以及cpu亲和性 */
    AGING_LOG,          /* AI老化测试失败日志 */
    AGING_BOARD,        /* 离线老化测试底板信息 */
    HBM_TEMP_AGING,      /* 高温老化测试 */
    HCCS,               /* 查询HCCS端口lane信息 */
    SIO_INFO,           /* 查询SIO信息,当前暂为error个数 */
    TPM_INIT_RESULT,     /* tpm初始化结果 */
    SIO_BER_RESUL,       /* 双die间sio通信误码率 */
    SPOD_INFO,          /* 查询超节点配置信息 */
    HCCS_BANDWIDTH_INFO, /* 查询hccs带宽信息 */
    CPU_FREQ_UP,          /* CPU 提频标志 */
    SYS_LOG_DUMP,       /* device侧日志落盘host侧 */
    CLEAR_SYSLOG_CFG,   /* 清除日志落盘配置 */
    SYS_LOG_ENABLE,   /* 系统日志持久化 */
    HCCS_AVAIL_CREDIT,   /* 查询HCCS可用信用证信息 */
    SYS_LOG_INFO,   /* 系统日志持久化信息 */
    SET_VOLTAGE,  /* 设置电压值 */
    GET_VOLTAGE,  /* 查询电压值 */
    RECOVER_VOLTAGE,  /* 恢复电压值 */
    CUSTOM_OP,   /* AICPU 算子免签开关 */
    CUSTOM_OP_CFG_RECOVER,   /* 配置 AICPU 算子免签开关 持久化 */
    CUSTOM_OP_SECVERIFY_ENABLE,   /* AI CPU算子用户自定义验签能力使能状态 */
    CUSTOM_OP_SECVERIFY_MODE,   /* AI CPU算子安全启动完整性校验模式 */
    OP_TIMEOUT,     /* 算子超时时刻信息 */
    DEVICE_SHARE_CFG_RECOVER,    /* 配置容器共享持久化 */
    CURRENT_FAULT_EVENT,   /* 故障报警 */
    LOW_POWER,           /* 降低功耗 */
    HBM_ECC_SRAM_TO_FLASH,    /* 搬运HBM ecc sram to flash */
    HBM_GET_ECC_INFO_FLASH,   /* 获取 ecc info in flash */
    HBM_GET_MOVE_FLASH_CNT,   /* 获取HBM搬运到flash的次数 */
    HBM_ERASE_FLASH_ECC,       /* 擦除flash ecc错误信息 */
    CUSTOM_OP_SECVERIFY_CERT, /* AI CPU算子安全启动验签证书 */
    RST_FAC_SET,     /* 清除装备阶段写入信息 */
    SET_GPIO,           /* 设置GPIO电平值 */
    GPIO_RESULT,         /* 获取GPIO电平结果 */
    TPM_IAK_CSR,         /* 获取csr文件 */
    TPM_IAK_NONCE,       /* 下发凭证并返回设备处理结果内容 */
    TPM_IAK_CERT,        /* 下发IAK证书 */
    TPM_IAK_RESULT,      /* 校验IAK证书 */
    IAK_CERT,      /* 保存IAK证书 */
    EK_CERT,         /* 保存EK证书 */
    DICE_CSR_GET,        /* DICE公钥/CSR文件读取 */
    DICE_CERT,           /* DICE证书信息读取/预置 */
    QOS_MASTER_CONFIG,         /* QOS配置持久化 */
    FREQREDUCE_CAUSE,           /* NPU降频原因查询 */
    MULTI_DIE_POLICY,    /* 设置A3单die通入容器 */
    MULTI_DIE_POLICY_CFG_RECOVER,    /* 设置A3单die通入容器策略持久化 */
    I2C_TEST,      /* i2c两路读写光模块 */
    VDM_ITEM,
    POWER_SUPPLY_INFO       /* 查询电源信息 */
};

struct npu_smi_operate_info {
    unsigned char is_total;                      /* 是否查询所有信息 */
    unsigned char is_watch;                      /* 是否格式输出监控数据 */
    unsigned char is_all;                        /* 是否对卡上所有芯片操作标志 */
    unsigned char is_erase;                      /* 是否擦除标志，log "-e" 后置1 */
    unsigned char is_reset;                      /* 保留参数，未使用 */
    unsigned char is_upgrade;                    /* 是否升级标志，upgrade "-t" 后置1 */
    unsigned char is_query;                      /* nputest 是否为"-q" 标志 */
    unsigned char is_active;                     /* 是否生效标志，"-a" 后置1 */
    unsigned char is_version;                    /* 是否显示版本信息标志 */
    unsigned char is_test;                       /* 保留参数，未使用 */
    unsigned char is_chip;                       /* 是否传入芯片编号标志，"-c" 后置1 */
    unsigned char is_sdata;                      /* 是否传入参数标志，在sdata赋值后置1 */
    unsigned char is_set;                        /* nputest 是否为"-s" 标志 */
    unsigned char is_mapping;                    /* 是否显示NPU 拓扑信息标志 */
    unsigned char is_common;                     /* 是否为通用信息 */
    unsigned char is_hccs_topo;                  /* 是否查询HCCS链路topo信息 */
    unsigned char has_id;                        /* 是否有输入卡id */
    unsigned char is_save_cert;                  /* 判断是否为保存证书 ek/iak */
    int save_cert_type;                          /* 保存证书类型 ek/iak */
    int chan_src;                                /* 命令通道 带内或带外 */
    const char *name;
    const char *desc;
    char *file_path;                             /* 升级包文件路径 */
    int id;                                      /* pcie卡编号 */
    int chip_id;                                 /* 芯片编号 */
    int lane_id;                                 /* HCCS链路编号 */
    int type;                                    /* 操作类型编号，详见test_item_e */
    int time;                                    /* 测试时间，单位: second */
    int item_type;                               /* 测试项类型，-p 后面的类型 */
    int enable_value;                            /* 是否使能标志，1:使能 */
    int watch_delay;                             /* info watch 间隔时长，单位秒 */
    char stype[NPU_MAX_LENTH];                   /* 操作类型名称，-t/-q/-s 等后面的类型 */
    int profiling_time;                          /* HCCS采样间隔，单位毫秒 */
    int watch_stype[NPU_MAX_LENTH];              /* info watch -s 显示类型 */
    char sdata[NPU_LONG_STR_MAX_LENGTH];         /* 操作项需要传入的参数，如:mac地址、电子标签、压力测试bitmap等 */
    char vnpu_conf[NPU_MAX_LENTH];               /* vNPU算力切分配置参数 */
    unsigned long int vnpu_svm;                  /* vNPU共享内存阈值 */
    char fdata[NPU_MAX_LENTH];                   /* 防回滚兼容性文件 */
    unsigned long int phy_id;                    /* 芯片物理ID */
    unsigned long int vnpu_id;
    unsigned int vfg_id;                         /* 虚拟分组ID */
    char output_file_path[NPU_MAX_LENTH];        /* 输出文件路径 */
};

struct npu_smi_type_map {
    const char *name;
    int type;
    unsigned int support_hw_form;        // 支持的硬件形态，卡，芯片和通用
    unsigned int support_env;            // 运行环境是否支持     1.非root 2.容器 3.虚拟机
    unsigned int win_support_list;       // 每个bit分别代表windows下具体器件是否支持
    unsigned int linux_support_list;           // 每个bit分别代表具体的形态是否支持
};

/* NPUSMI参数解析定义 */
struct npu_smi_parse_param {
    char *param;
    int (*parse_proc)(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);
};

/* NPU命令定义 */
struct npu_cmd {
    int (*func)(struct npu_smi_operate_info *operate_info, int argc, char **argv);
    const char *name;
    const char *desc;
};

struct npu_help {
    void (*func)(const char *name);
    const char *name;
    const char *desc;
};


/* NPU info命令定义 */
struct npu_info_cmd {
    int (*check_parm)(struct npu_smi_operate_info *operate_info);
    int (*cmd_proc)(struct npu_smi_operate_info *operate_info);
    int type;
};

struct pwm_info {
    unsigned int channel_num;
    unsigned int ratio;       // 占空比（取值范围为：0---100，例：ratio = 45 表示占空比为45%）
};

int npu_help_main(struct npu_smi_operate_info *operate_info, int argc, char **argv);

int npu_version_main(struct npu_smi_operate_info *operate_info, int argc, char **argv);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPU_SMI_H__ */

