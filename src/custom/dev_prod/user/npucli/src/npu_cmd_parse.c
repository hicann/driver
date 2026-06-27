/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef _WIN32
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <sys/types.h>
#include "securec.h"
#include "dcmi_log.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_environment_judge.h"
#include "npu_set.h"
#include "npu_upgrade.h"
#include "npu_common.h"
#include "npu_parameter_parse.h"
#include "npu_cmd_parse.h"

#define CMD_NUM 8
#define CMD_LEN 20

struct npu_smi_type_map *g_type_map_list = NULL;

static struct npu_smi_type_map g_type_watch_map_list[] = {
    {"p", POWER_TYPE},
    {"t", TEMP_TYPE},
    {"a", AI_CORE_TYPE},
    {"i", AI_CPU_TYPE},
    {"c", CTRL_CPU_TYPE},
    {"m", MEMORY_TYPE},
    {"b", MEMORY_BANDWIDTH_TYPE},
    {"n", NPU_UTILIZATION_TYPE},
    {"u", AI_CUBE_TYPE},
    {NULL}
};
struct npu_smi_type_map g_type_info_map_list[] = {
    {"flash",               FLASH,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"usages",              USAGES,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"ecc-enable",          ECC_ENABLE,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"p2p-enable",          P2P_ENABLE_FLAG,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_310 | CMD_SPT_310B},
    {"ecc",                 ECC,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"common",              COMMON,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"license",             CUSTOMIZED_INFO,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_SPT_310_CARD, CMD_SPT_310_CARD},
    {"i2c_check",           IIC_CHECK,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_SPT_310_CARD, CMD_SPT_310_CARD},
    {"ssh-enable",          SSH_ENABLE,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_SPT_310_CARD,
        CMD_SPT_STATION_HILEN | CMD_SPT_310_CARD | CMD_SPT_310P_CARD},
    {"err-count",           ERR_COUNT,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_310_CARD},
    {"pcie-err",            ERR_COUNT,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_310P_CARD | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"mcu-monitor",         MCU_MONITOR,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_STATION_HILEN},
    {"boot-area",           BOOT_AREA,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_STATION_HILEN},
    {"board",               BOARD,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"health",              HEALTH,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"volt",                VOLT,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"temp",                TEMP,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"power",               POWER,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"memory",              MEMORY,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_ALL},
    {"product",             PRODUCT_TYPE,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, CMD_WIN_SPT_ALL, CMD_SPT_310 | CMD_SPT_310P | CMD_SPT_310B},
    {"mac-addr",            MAC_ADDR,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_DOCKER, 0, CMD_SPT_310B},
    {"ip",                  IP,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_STATION_HILEN | CMD_SPT_310_CARD},
    {"device-share",        DEVICE_SHARE,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0,
        CMD_SPT_310_SOC | CMD_SPT_STATION | CMD_SPT_310B | CMD_SPT_310P | CMD_SPT_910B | CMD_SPT_910_93},
    {"device-share-cfg-recover", DEVICE_SHARE_CFG_RECOVER,
        CMD_HW_SPT_COMMON,   CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_310P | CMD_SPT_910B | CMD_SPT_910_93},
    {"nve-level",           NVE_LEVEL,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_310_SOC | CMD_SPT_310B},
    {"aicpu-config",        AICPU_CONF,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_310_SOC},
    {"sensors",             SENSORS,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0,
        CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"sys-time",            SYS_TIME,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0,
        CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"customized-info",     CUSTOMIZED_INFO,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_310P},
    {"info-vnpu",           VNPU_INFO,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B},
    {"vnpu-mode",           VNPU_MODE,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B},
    {"pkcs-enable",         PKCS_ENABLE,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310P_CARD},
    {"vnpu-svm",            VNPU_SVM_INFO,
        CMD_HW_SPT_CARD_CHIP,   0, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER},
    {"key-manage",          KEY_MANAGE,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_VM, 0, CMD_SPT_MODEL | CMD_SPT_STATION | CMD_SPT_HILENS | CMD_SPT_SERVER | \
        CMD_SPT_310_CARD | CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"first-power-on-date", FIRST_POWER_ON_DATE,
        CMD_HW_SPT_CARD,        CMD_ENV_SPT_NON_ROOT, 0, CMD_SPT_310P | CMD_SPT_910B_CARD | CMD_SPT_910_93_CARD},
    {"tls-csr-get",         TLS_CSR_GET,
        CMD_HW_SPT_CHIP,        0, 0, CMD_SPT_910B | CMD_SPT_310P_CARD | CMD_SPT_910_93 | CMD_SPT_950},
    {"tls-cert",            TLS_CERT,
        CMD_HW_SPT_CHIP,        CMD_ENV_SPT_ALL, 0, CMD_SPT_910B | CMD_SPT_310P_CARD | CMD_SPT_910_93 | CMD_SPT_950},
    {"tls-cert-period",     TLS_CERT_PERIOD,
        CMD_HW_SPT_CHIP,        CMD_ENV_SPT_ALL, 0, CMD_SPT_910B | CMD_SPT_310P_CARD | CMD_SPT_910_93 | CMD_SPT_950},
    {"rootkey",     ROOTKEY,
        CMD_HW_SPT_CHIP,        CMD_ENV_SPT_ALL, 0, CMD_SPT_910B | CMD_SPT_310P_CARD},
    {"proc-mem",            PROC_MEM,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_EP | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950_CARD | \
        CMD_SPT_950_SERVER},
    {"cpu-num-cfg",         CPU_NUM_CFG,
        CMD_HW_SPT_CHIP,        CMD_ENV_SPT_ALL, 0, CMD_SPT_310P | CMD_SPT_310B},
    {"phyid-remap",         PHYID_REMAP,
        CMD_HW_SPT_CHIP,        CMD_ENV_SPT_ALL, 0, CMD_SPT_ALL},
    {"vnpu-cfg-recover",    VNPU_CFG_RECOVER,
        CMD_HW_SPT_COMMON,  CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B},
    {"template-info",         TEMPLATE_INFO,
        CMD_HW_SPT_COMMON,  CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B},
    {"pwm-mode",            PWM_MODE,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310B_SOC_DK},
    {"pwm-duty-ratio",      PWM_DUTY_RATIO,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310B_SOC_DK},
    {"p2p-mem-cfg",         P2P_MEM_CFG,
        CMD_HW_SPT_CARD_CHIP,    CMD_ENV_SPT_ALL, 0, CMD_SPT_310P_CARD},
    {"work-mode",           WORK_MODE,
        CMD_HW_SPT_CARD,    CMD_ENV_SPT_ALL, 0, CMD_SPT_SERVER},
    {"boot-select",         BOOT_SEL,
        CMD_HW_SPT_CARD_CHIP,    CMD_ENV_SPT_ALL, 0, CMD_SPT_310B_SOC_STATION},
    {"topo",                TOPO,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER | CMD_ENV_SPT_NON_ROOT, 0,
        CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
#ifdef ORIENT_CH
    {"xlink",         HCCS,
        CMD_HW_SPT_CHIP,    CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER,
        0, CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_310P},
#else
    {"hccs",         HCCS,
        CMD_HW_SPT_CHIP,    CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER,
        0, CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_310P},
#endif
    {"spod-info",         SPOD_INFO,
        CMD_HW_SPT_CHIP,    CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910_93 | \
        CMD_SPT_950_SERVER},
    {"sio-info",         SIO_INFO,
        CMD_HW_SPT_CHIP,    CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910_93 | \
        CMD_SPT_950},
#ifdef ORIENT_CH
    {"xlink-bw",    HCCS_BANDWIDTH_INFO,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER,
        0, CMD_SPT_910B | CMD_SPT_910_93},
#else
    {"hccs-bw",    HCCS_BANDWIDTH_INFO,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER,
        0, CMD_SPT_910B | CMD_SPT_910_93},
#endif
    {"cpu-freq-up",      CPU_FREQ_UP,
        CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ALL, 0, CMD_SPT_310P_CARD},
#ifdef ORIENT_CH
    {"xlink-credit",         HCCS_AVAIL_CREDIT,
        CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ALL, 0, CMD_SPT_910_93},
#else
    {"hccs-credit",         HCCS_AVAIL_CREDIT,
        CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ALL, 0, CMD_SPT_910_93},
#endif
    {"sys-log-info",  SYS_LOG_INFO,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"custom-op", CUSTOM_OP,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_910_93},
    {"custom-op-cfg-recover", CUSTOM_OP_CFG_RECOVER,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_910_93},
    {"custom-op-secverify-enable", CUSTOM_OP_SECVERIFY_ENABLE,
        CMD_HW_SPT_CARD, CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"custom-op-secverify-mode", CUSTOM_OP_SECVERIFY_MODE,
        CMD_HW_SPT_CARD, CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"op-timeout", OP_TIMEOUT,
        CMD_HW_SPT_CHIP, CMD_ENV_SPT_ALL, 0, CMD_SPT_910B | CMD_SPT_910_93},
    {"current-fault-event", CURRENT_FAULT_EVENT, CMD_HW_SPT_CHIP, CMD_ENV_SPT_ALL, 0, CMD_SPT_950},
    {"custom-op-secverify-cert", CUSTOM_OP_SECVERIFY_CERT, CMD_HW_SPT_CARD,
        CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910B | CMD_SPT_910_93},
    {"multi-die-policy", MULTI_DIE_POLICY, CMD_HW_SPT_COMMON, CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910_93},
    {"multi-die-policy-cfg-recover", MULTI_DIE_POLICY_CFG_RECOVER,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910_93},
    { NULL }
};

struct npu_smi_type_map g_type_set_map_list[] = {
    {"ecc-enable",      ECC_ENABLE,
        CMD_HW_SPT_CARD_CHIP, 0, CMD_WIN_SPT_ALL, CMD_SPT_310 | CMD_SPT_310P | CMD_SPT_310B},
    {"collect-log",     COLLECT_LOG,
        CMD_HW_SPT_CARD_CHIP, 0, CMD_SPT_310_CARD, CMD_SPT_MCU},
    {"license",         CUSTOMIZED_INFO,
        CMD_HW_SPT_CARD_CHIP, 0, CMD_SPT_310_CARD, CMD_SPT_310_CARD},
    {"reset",           RESET,
        CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ROOT,
        CMD_SPT_310_CARD, CMD_SPT_CARD | CMD_SPT_ALL_SERVER | CMD_SPT_MODEL | CMD_SPT_910B_CARD | \
        CMD_SPT_910_93_CARD | CMD_SPT_950_CARD | CMD_SPT_950_SERVER},
    {"ssh-enable",      SSH_ENABLE,
        CMD_HW_SPT_CARD_CHIP, 0, CMD_SPT_310_CARD, CMD_SPT_STATION_HILEN | CMD_SPT_310_CARD | CMD_SPT_310P_CARD},
    {"errcount-clear",  ERR_COUNT_CLEAR,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310_CARD},
    {"clear-pcie-err",  ERR_COUNT_CLEAR,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310P_CARD},
    {"mcu-monitor",     MCU_MONITOR,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_STATION_HILEN},
    {"boot-area",       BOOT_AREA,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_STATION_HILEN},
    {"disk-power",      DISK_POWER,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_STATION_HILEN | CMD_SPT_310B},
    {"ip",              IP,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_STATION_HILEN | CMD_SPT_310_CARD},
    {"device-share",    DEVICE_SHARE,
        CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_310_SOC | CMD_SPT_STATION_HILEN | CMD_SPT_310B | CMD_SPT_310P | CMD_SPT_910B | CMD_SPT_910_93},
    {"device-share-cfg-recover", DEVICE_SHARE_CFG_RECOVER,
        CMD_HW_SPT_COMMON,   CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_310P | CMD_SPT_910B | CMD_SPT_910_93},
    {"nve-level",       NVE_LEVEL,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310_SOC | CMD_SPT_310B},
    {"aicpu-config",    AICPU_CONF,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310_SOC},
    {"mac-addr",            MAC_ADDR,
        CMD_HW_SPT_CHIP, 0, 0, CMD_SPT_310B},
    {"revocate",        REVOCATION,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B | CMD_SPT_910_93},
    {"customized-info", CUSTOMIZED_INFO,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310P},
    {"clear-ecc-info",  ECC_INFO_CLEAR,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B | CMD_SPT_310P_CARD | \
        CMD_SPT_910_93 | CMD_SPT_950},
    {"vnpu-mode",       VNPU_MODE,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B | CMD_SPT_910_93},
    {"pkcs-enable",     PKCS_ENABLE,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310P_CARD},
    {"create-vnpu",     VNPU_CREATE,
        CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | \
        CMD_SPT_910B},
    {"destroy-vnpu",    VNPU_DESTORY,
        CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | \
        CMD_SPT_910B},
    {"vnpu-svm",        SET_VNPU_SVM,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER},
    {"tls-cert",        TLS_CERT,
        CMD_HW_SPT_CHIP, 0, 0, CMD_SPT_910B | CMD_SPT_310P_CARD | CMD_SPT_910_93 | CMD_SPT_950},
    {"tls-cert-period", TLS_CERT_PERIOD,
        CMD_HW_SPT_CHIP, 0, 0, CMD_SPT_910B | CMD_SPT_310P_CARD | CMD_SPT_910_93 | CMD_SPT_950},
    {"key-manage",      KEY_MANAGE,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_VM, 0, CMD_SPT_MODEL | CMD_SPT_STATION | CMD_SPT_HILENS | CMD_SPT_SERVER | \
        CMD_SPT_310_CARD | CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"cpu-num-cfg",     CPU_NUM_CFG,
        CMD_HW_SPT_CHIP, 0, 0, CMD_SPT_310P_CARD | CMD_SPT_310P_SOC | CMD_SPT_310B},
    {"vnpu-cfg-recover",    VNPU_CFG_RECOVER,
        CMD_HW_SPT_COMMON,  CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910_CARD | CMD_SPT_SERVER | \
        CMD_SPT_910B},
    {"pwm-mode",        PWM_MODE,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310B_SOC_DK},
    {"pwm-duty-ratio",  PWM_DUTY_RATIO,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_310B_SOC_DK},
    {"p2p-mem-cfg",    P2P_MEM_CFG,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310P_CARD},
    {"power-state",    POWER_STATE, CMD_HW_SPT_CHIP, 0, 0, CMD_SPT_310B_SOC_DK },
    {"boot-select",    BOOT_SEL, CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310B_SOC_STATION},
    {"reset-vnpu",    RESET_VNPU, CMD_HW_SPT_CARD, CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910B },
    {"cpu-freq-up",      CPU_FREQ_UP,
        CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_310P_CARD},
    {"sys-log-dump",   SYS_LOG_DUMP,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"clear-syslog-cfg",   CLEAR_SYSLOG_CFG,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"sys-log-enable",  SYS_LOG_ENABLE,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_VM, 0, CMD_SPT_310P_CARD | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"custom-op", CUSTOM_OP,
        CMD_HW_SPT_CARD_CHIP,   CMD_ENV_SPT_ALL, 0, CMD_SPT_910_93},
    {"custom-op-cfg-recover", CUSTOM_OP_CFG_RECOVER,
        CMD_HW_SPT_COMMON, 0, 0, CMD_SPT_910_93},
    {"custom-op-secverify-enable", CUSTOM_OP_SECVERIFY_ENABLE,
        CMD_HW_SPT_CARD, CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"custom-op-secverify-mode", CUSTOM_OP_SECVERIFY_MODE,
        CMD_HW_SPT_CARD, CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0,
        CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"op-timeout-cfg", OP_TIMEOUT,
        CMD_HW_SPT_CHIP, CMD_ENV_SPT_ROOT, 0, CMD_SPT_910B | CMD_SPT_910_93},
    {"custom-op-secverify-cert", CUSTOM_OP_SECVERIFY_CERT, CMD_HW_SPT_CARD,
        CMD_ENV_SPT_NON_ROOT | CMD_ENV_SPT_VM | CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910B | CMD_SPT_910_93},
    {"qos-master-config", QOS_MASTER_CONFIG, CMD_HW_SPT_CHIP,
        CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910_93},
    {"multi-die-policy", MULTI_DIE_POLICY, CMD_HW_SPT_COMMON, CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910_93},
    {"multi-die-policy-cfg-recover", MULTI_DIE_POLICY_CFG_RECOVER,
        CMD_HW_SPT_COMMON, CMD_ENV_SPT_DOCKER, 0, CMD_SPT_910_93},
    { NULL }
};

static struct npu_smi_type_map g_type_clear_map_list[] = {
    {"ecc-info", ECC_INFO, CMD_HW_SPT_CARD_CHIP, 0, 0,
     CMD_SPT_910_CARD | CMD_SPT_SERVER | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_310P_CARD | CMD_SPT_950},
    {"ecc-info", ECC_INFO, CMD_HW_SPT_CARD_CHIP, 0, 0, CMD_SPT_910_CARD | CMD_SPT_SERVER},
    {"tls-cert-period", TLS_CERT_PERIOD, CMD_HW_SPT_CHIP, 0, 0,
     CMD_SPT_910B | CMD_SPT_310P_CARD | CMD_SPT_910_93 | CMD_SPT_950},
    {NULL}};

// upgrade的命令比较特殊，非root，容器，虚拟机中都要设置成支持
static struct npu_smi_type_map g_type_upgrade_map_list[] = {
    {"mcu",         MCU_ITEM,
     CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ALL, CMD_SPT_310_CARD, CMD_SPT_MCU},
    {"bootloader",  BOOTLOADER,
     CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ALL, CMD_SPT_310_CARD, CMD_SPT_STATION_HILEN},
    {"vrd",         VRD_ITEM,
     CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ALL, 0, CMD_SPT_310P | CMD_SPT_910B | CMD_SPT_910_93 | CMD_SPT_950},
    {"vdm",         VDM_ITEM,
     CMD_HW_SPT_CARD_CHIP, CMD_ENV_SPT_ALL, 0, CMD_SPT_950_SERVER | CMD_SPT_950_SOC},
    { NULL }
};

void npu_smi_info_map_load()
{
    g_type_map_list = g_type_info_map_list;
}

void npu_smi_set_map_load()
{
    g_type_map_list = g_type_set_map_list;
}

void npu_smi_clear_map_load()
{
    g_type_map_list = g_type_clear_map_list;
}

void npu_smi_upgrade_map_load()
{
    g_type_map_list = g_type_upgrade_map_list;
}

int set_type(struct npu_smi_operate_info *operate_info, const char *tmp_type)
{
    size_t len_x, len_y, len_tmp;
    int ret;
    struct npu_smi_type_map *type_map;
    for (type_map = g_type_map_list; type_map->name != NULL; type_map++) {
        len_x = strlen(tmp_type);
        len_y = strlen(type_map->name);
        len_tmp = ((len_x > len_y) ? len_x : len_y);
        if (strncmp(tmp_type, type_map->name, len_tmp) == 0) {
            operate_info->type = type_map->type;
            ret = memcpy_s(operate_info->stype, sizeof(operate_info->stype), tmp_type, strlen(tmp_type) + 1);
            if (ret != EOK) {
                gplog(LOG_ERR, "memcpy_s failed. ret is %d.", ret);
            }

            if (determine_run_env_support(type_map) != NPU_OK) {
                return NPU_ERR_CODE_OPER_NOT_PERMITTED;
            }
            if (determine_hardware_support(type_map) != TRUE) {
                return NPU_ERR_CODE_NOT_SUPPORT;
            }

            if (type_map->support_hw_form == CMD_HW_SPT_COMMON) {
                operate_info->is_common = 1;
            }
            return ret;
        }
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_watch_type(struct npu_smi_operate_info *operate_info, const char *tmp_type)
{
    size_t len = strlen(tmp_type);
    struct npu_smi_type_map *type_map;
    size_t tmp_index;
    int had_type;

    for (type_map = g_type_watch_map_list; type_map->name != NULL; type_map++) {
        operate_info->watch_stype[type_map->type] = NPU_DEFAULT_VALUE;
    }

    // 查询是否有不匹配的字符
    for (tmp_index = 0; tmp_index < len; tmp_index++) {
        had_type = FALSE;
        for (type_map = g_type_watch_map_list; type_map->name != NULL; type_map++) {
            if (strncmp(tmp_type + tmp_index, type_map->name, strlen(type_map->name)) == 0) {
                had_type = TRUE;
                operate_info->watch_stype[type_map->type] = TRUE;
                break;
            }
        }
        if (had_type != TRUE) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }
    return NPU_OK;
}

int set_qos_cfg_para_parse(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret = 0, pos = 0, len = 0;

    if (cur + QOS_MAX > argc) { // -s后参数数量为8
        gplog(LOG_ERR, "Parameter missing, expected %d QoS parameters.", QOS_MAX);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (int i = 0; i < QOS_MAX; i++) {
        if (argv[cur + i] == NULL) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
        len = strlen(argv[cur + i]);
        if (pos + len + 1 > NPU_MAX_LENTH) {
            gplog(LOG_ERR, "Parameter missing at index %d, expected %d QoS parameters, but parameter %d is NULL.",
                i, QOS_MAX, i);
            return NPU_ERR_CODE_INNER_ERR;
        }
        ret = strcpy_s(operate_info->sdata + pos, NPU_MAX_LENTH - pos, argv[cur + i]);
        if (ret != EOK) {
            gplog(LOG_ERR, "call strcpy_s failed, ret = %d", ret);
            return NPU_ERR_CODE_SECURE_FUN_FAIL;
        }
        pos += len + 1;  // +1 for the \0
    }
    operate_info->sdata[pos] = '\0';
    return NPU_OK;
}

static struct npu_smi_parse_param g_parse_info_param_arr[] = {
    {"-i", parse_card_param},
    {"-t", parse_type_param},
    {"-c", parse_chip_param},
    {"-s", parse_watch_type_param},
    {"-d", parse_watch_delay_param},
    {"-l", parse_chip_all_param},
    {"-m", parse_chip_mapping_param},
    {"-h", parse_help_param},
    {"-p", parse_phyid_param},
    {"-R", parse_chip_hccs_param},
    {"-lane", parse_chip_lane_param},
    {"--help", parse_help_param},
    {"-time", parse_profiling_time_param},
    {NULL},
};

static int check_conflict_commands(char *command, int *single_flag, int *i_flag, int *c_flag, int *is_single)
{
    char *single_parameters[] = {"-t", "-l", "-m", "-h", "-help"};
    int num_single_params = sizeof(single_parameters) / sizeof(single_parameters[0]);
    int command_len = strlen(command);

    for (int j = 0; j < num_single_params; j++) {
        if (strncmp(command, single_parameters[j], command_len) == 0) {
            if ((*single_flag) > 0) {
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            (*single_flag)++;
            (*is_single) = 1;
            break;
        }
    }

    // 检查是否是附加参数
    if (!(*is_single)) {
        if (strncmp(command, "-i", command_len) == 0) {
            if ((*i_flag) > 0) {
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            (*i_flag)++;
        } else if (strncmp(command, "-c", command_len) == 0) {
            if ((*c_flag) > 0) {
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            (*c_flag)++;
        }
    }

    return NPU_OK;
}


static void check_npu_utilization_support(struct npu_smi_operate_info *operate_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    bool npu_utilization_support_type = (chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950);
    if (operate_info->watch_stype[NPU_UTILIZATION_TYPE] != NPU_DEFAULT_VALUE && !npu_utilization_support_type) {
        operate_info->watch_stype[NPU_UTILIZATION_TYPE] = NPU_DEFAULT_VALUE;
    }
}

static void check_ai_cube_support(struct npu_smi_operate_info *operate_info)
{
    int chip_type = npu_get_chip_type();
    bool ai_cube_support_type = (chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950);
    if (operate_info->watch_stype[AI_CUBE_TYPE] != NPU_DEFAULT_VALUE && !ai_cube_support_type) {
        operate_info->watch_stype[AI_CUBE_TYPE] = NPU_DEFAULT_VALUE;
    }
}

int parse_npu_info_not_watch_proc_param(struct npu_smi_operate_info *operate_info, int argc, char **argv, int para_num)
{
    struct npu_smi_parse_param *cmd = NULL;
    int i, tmp_para_num;
    int single_flag = 0;
    int i_flag = 0;
    int c_flag = 0;
    tmp_para_num = para_num;
    npu_smi_info_map_load();

    for (i = PARAM_START_INDEX + tmp_para_num; i < argc; i = i + PARAM_STEP) {
        char *command = argv[i];
        int is_single = 0;
        int ret = NPU_OK;
        ret = check_conflict_commands(command, &single_flag, &i_flag, &c_flag, &is_single);
        if (ret != NPU_OK) {
            printf("Error parameter of %s\n", command);
            return ret;
        }
        for (cmd = g_parse_info_param_arr; cmd->parse_proc != NULL; cmd++) {
            size_t len_tmp = ((strlen(command) > strlen(cmd->param)) ? strlen(command) : strlen(cmd->param));
            if (strncmp(command, cmd->param, len_tmp) == 0) {
                tmp_para_num++;
                ret = cmd->parse_proc(operate_info, i, argc, (const char **)argv);
                break;
            }
        }
        if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support querying %s.\n", argv[i + 1]);
            return ret;
        } else if (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED || ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP) {
            return ret;
        } else if (ret != NPU_OK) {
            printf("Error parameter of %s\n", command);
            return ret;
        }
        if (cmd->parse_proc == NULL) {
            printf("Error parameter of %s\n", command);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    check_npu_utilization_support(operate_info);
    check_ai_cube_support(operate_info);
    if (tmp_para_num == 0) {
        printf("\nInput parameter format error.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return NPU_OK;
}

int parse_npu_info_param(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int para_num = 0;
    if (argc >= NPU_INFO_PARAMETER_MIN_NUM) {
        if (npu_info_proc_watch_param(operate_info, (const char *)argv[1], &para_num) == NPU_ERR_CODE_NOT_SUPPORT) {
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
    }

    return parse_npu_info_not_watch_proc_param(operate_info, argc, argv, para_num);
}

static struct npu_smi_parse_param g_parse_set_param_arr[] = {
    { "-t", parse_type_param},
    { "-i", parse_card_param},
    { "-c", parse_chip_param},
    { "-s", parse_str_param},
    { "-d", parse_enable_param},
    { "-v", parse_multi_param},
    { "-g", parse_virgroup_id_param},
    { "-m", parse_chan_param},
    { "-f", parse_fdata_param},
    { "-h", parse_help_param},
    { "--help", parse_help_param},
    { NULL },
};

static void npu_print_not_support(struct npu_smi_operate_info *operate_info, int i, char **argv)
{
    if (operate_info->type == NPU_INVALID_VALUE || strcmp(argv[i], "-t") == 0) {
        printf("This device does not support setting %s.\n", argv[i + 1]);
    } else {
        printf("This device does not support setting %s with %s.\n", operate_info->stype, argv[i]);
    }
}

int parse_npu_setqos_master_cfg_param(struct npu_smi_operate_info *operate_info,
    struct npu_smi_parse_param *param_info, int cur, int argc, char **argv)
{
    int ret = 0, tmp = 0;
    ret = param_info->parse_proc(operate_info, cur, argc, (const char **)argv);
    tmp = cur + QOS_MAX - 1;
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        npu_print_not_support(operate_info, tmp, argv);
        return ret;
    } else if (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED) {
        return ret;
    } else if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
        printf("Error parameter of -s\n");
        return ret;
    }
    if (param_info->parse_proc == NULL) {
        printf("Error parameter of -s\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

/* ****************************************************************************
 函 数 名  : parse_npu_set_param
 功能描述  : 设置功能参数解析
 输入参数  : struct npu_smi_operate_info *operate_info
 输出参数  : 无
 返 回 值  : int
 修改历史      :
  1.日    期   : 2021年4月28日
    修改内容   : 新生成函数
**************************************************************************** */
int parse_npu_set_param(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int i;
    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    struct npu_smi_parse_param *param_info = NULL;

    npu_smi_set_map_load();

    for (i = PARAM_START_INDEX; i < argc; i = i + PARAM_STEP) {
        for (param_info = g_parse_set_param_arr; param_info->parse_proc != NULL; param_info++) {
            if (strcmp(argv[i], param_info->param) != 0) {
                continue;
            }
            if (strncmp(operate_info->stype, "qos-master-config", strlen("qos-master-config")) == 0 &&
                strncmp(argv[i], "-s", strlen("-s")) == 0) {
                return parse_npu_setqos_master_cfg_param(operate_info, param_info, i, argc, argv);
            } else {
                ret = param_info->parse_proc(operate_info, i, argc, (const char **)argv);
                break;
            }
        }
        if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
            npu_print_not_support(operate_info, i, argv);
            return ret;
        } else if (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED) {
            return ret;
        } else if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
            printf("Error parameter of %s\n", argv[i]);
            return ret;
        }
        if (param_info->parse_proc == NULL) {
            printf("Error parameter of %s\n", argv[i]);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    return ret;
}

static struct npu_smi_parse_param g_parse_upgrade_param_arr[] = {
    { "-i", parse_card_param},
    { "-t", parse_upgrade_type_param},
    { "-f", parse_mcu_file_param},
    { "-q", parse_upgrade_query_param},
    { "-b", parse_upgrade_version_param},
    { "-a", parse_upgrade_active_param},
    { "-h", parse_upgrade_help_param},
    { "--help", parse_upgrade_help_param},
    { NULL },
};

int parse_npu_upgrade_param(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int i;
    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    struct npu_smi_parse_param *param_info = NULL;

    npu_smi_upgrade_map_load();

    if (argc <= PARAM_START_INDEX) {
        return ret;
    }
    for (i = PARAM_START_INDEX; i < argc; i = i + PARAM_STEP) {
        for (param_info = g_parse_upgrade_param_arr; param_info->parse_proc != NULL; param_info++) {
            if (strcmp(argv[i], param_info->param) == 0) {
                ret = param_info->parse_proc(operate_info, i, argc, (const char **)argv);
                break;
            }
        }
        if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
            print_upgrade_result(ret, operate_info);
            return ret;
        } else if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
            printf("Error parameter of %s\n", argv[i]);
            return ret;
        }
        if (param_info->parse_proc == NULL) {
            printf("Error parameter of %s\n", argv[i]);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    if ((!operate_info->has_id) &&
        (strcmp("-h", param_info->param) != 0) && (strcmp("--help", param_info->param) != 0)) {
        printf("\nThis command must input card id.\n\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return ret;
}

static struct npu_smi_parse_param g_parse_clear_param_arr[] = {
    { "-t", parse_type_param},
    { "-i", parse_card_param},
    { "-c", parse_chip_param},
    { "-h", parse_help_param},
    { "--help", parse_help_param},
    { NULL },
};

int parse_npu_clear_param(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int i;
    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    struct npu_smi_parse_param *param_info = NULL;

    npu_smi_clear_map_load();

    for (i = PARAM_START_INDEX; i < argc; i = i + PARAM_STEP) {
        for (param_info = g_parse_clear_param_arr; param_info->parse_proc != NULL; param_info++) {
            if (strcmp(argv[i], param_info->param) == 0) {
                ret = param_info->parse_proc(operate_info, i, argc, (const char **)argv);
                break;
            }
        }
        if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support clearing %s.\n", argv[i + 1]);
            return ret;
        }
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
            printf("Error parameter of %s\n", argv[i]);
            return ret;
        }
        if (param_info->parse_proc == NULL) {
            printf("Error parameter of %s\n", argv[i]);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    return ret;
}

int is_npu_syslog_type_support(int argc_num, char **argv)
{
    if (((strcmp(argv[argc_num], "sys-log-dump") == 0) || (strcmp(argv[argc_num], "clear-syslog-cfg") == 0) ||
        (strcmp(argv[argc_num], "sys-log-enable") == 0)) && !npu_is_in_docker()) {
        return TRUE;
    }
    return FALSE;
}

static int is_reset_vnpu_supported(int chip_type, const char *arg)
{
    return (chip_type == NPU_CHIP_910B) &&
           ((strcmp(arg, "reset-vnpu") == 0) || (strcmp(arg, "reset") == 0));
}

static int is_custom_op_secverify_mode_or_cert_supported(int chip_type, const char *arg)
{
    return (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93) &&
           (strcmp(arg, "custom-op-secverify-mode") == 0 || strcmp(arg, "custom-op-secverify-cert") == 0);
}

static int is_basic_reset_supported(int chip_type, const char *arg)
{
    return (chip_type != NPU_CHIP_910B) && (strcmp(arg, "reset") == 0);
}

static int is_op_timeout_supported(int chip_type, const char *arg)
{
    return (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93) &&
        (strcmp(arg, "op-timeout-cfg") == 0);
}

static int is_device_share_and_recover_supported(int chip_type, const char *arg)
{
    return (chip_type == NPU_CHIP_910B|| chip_type == NPU_CHIP_910_93|| chip_type == NPU_CHIP_310P) &&
        ((strcmp(arg, "device-share") == 0) || (strcmp(arg, "device-share-cfg-recover") == 0));
}

static int is_qos_master_config_supported(int chip_type, const char *arg)
{
    return chip_type == NPU_CHIP_910_93 && strcmp(arg, "qos-master-config") == 0;
}

static int set_type_is_support(int chip_type, const char *input_str)
{
    return is_reset_vnpu_supported(chip_type, input_str) ||
        is_custom_op_secverify_mode_or_cert_supported(chip_type, input_str) ||
        is_basic_reset_supported(chip_type, input_str) ||
        is_device_share_and_recover_supported(chip_type, input_str) ||
        is_qos_master_config_supported(chip_type, input_str) ||
        is_op_timeout_supported(chip_type, input_str);
}

int type_support_in_vm_or_docker(int argc, char **argv)
{
    int i, argc_num;
    int chip_type = npu_get_chip_type();
    int ret = FALSE;

    if (argv == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    // 1980B&310BEP 容器和虚拟机场景支持set -h
    for (i = PARAM_START_INDEX; i < argc; i++) {
        if ((npu_get_chip_type() == NPU_CHIP_910B || dcmi_get_product_type_inner() == DCMI_A200_A2_EP) &&
            ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))) {
            return TRUE;
        }
    }
    for (i = PARAM_START_INDEX; i + 1 < argc; i = i + PARAM_STEP) {
        if (strcmp(argv[i], "-t") == 0) {
            if (set_type_is_support(chip_type, argv[i + 1])) {
                ret = TRUE;
                break;
            }
            argc_num = i + 1;
            if (is_npu_syslog_type_support(argc_num, argv) == TRUE) {
                ret = TRUE;
                break;
            }
        }
    }
    return ret;
}

int type_unsupport_set_in_common_docker(int argc, char **argv)
{
    int i;
    int ret = FALSE;

    if (argv == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = PARAM_START_INDEX; i + 1 < argc; i = i + PARAM_STEP) {
        if ((strcmp(argv[i], "-t") == 0) && ((strcmp(argv[i + 1], "custom-op-secverify-mode") == 0))) {
            ret = (dcmi_check_run_in_docker()) && (!dcmi_check_run_in_privileged_docker());
            break;
        }
        if ((strcmp(argv[i], "-t") == 0) && ((strcmp(argv[i + 1], "custom-op-secverify-cert") == 0))) {
            ret = (dcmi_check_run_in_docker()) && (!dcmi_check_run_in_privileged_docker());
            break;
        }
    }
    return ret;
}

int type_unsupport_info_in_common_docker(int argc, char **argv)
{
    int i;
    int ret = FALSE;

    if (argv == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = PARAM_START_INDEX; i + 1 < argc; i = i + PARAM_STEP) {
        if ((strcmp(argv[i], "-t") == 0) && ((strcmp(argv[i + 1], "custom-op-secverify-enable") == 0))) {
            ret = (dcmi_check_run_in_docker()) && (!dcmi_check_run_in_privileged_docker());
            break;
        }
    }
    return ret;
}

int check_cmd_is_vnpu(char **argv, int index)
{
    int i;
    int ret = FALSE;

    if (argv == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    char cmd[CMD_NUM][CMD_LEN] = {"info-vnpu", "vnpu-svm", "vnpu-mode",
        "vnpu-cfg-recover", "template-info", "create-vnpu", "destroy-vnpu",
        "reset-vnpu"};
    for (i = 0; i < CMD_NUM; i++) {
        if (strcmp(argv[index], cmd[i]) == 0) {
            return TRUE;
        }
    }
    return ret;
}

int type_is_vnpu(int argc, char **argv, int *index)
{
    int ret = FALSE;

    if (argv == NULL || index == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if (npu_get_chip_type() != NPU_CHIP_910B) {
        // 仅对910B产品做判断
        return FALSE;
    }
    return ret;
}

int type_is_info_vnpu(int argc, char **argv)
{
    int i = 0;

    if ((argv == NULL) || (argv[0] == NULL)) {
        gplog(LOG_ERR, "argv is NULL.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = PARAM_START_INDEX; i + 1 < argc; i = i + PARAM_STEP) {
        if ((strcmp(argv[i], "-t") == 0) && (strcmp(argv[i + 1], "info-vnpu") == 0)) {
            return TRUE;
        }
    }

    return FALSE;
}

int type_need_check_root(int argc, char **argv)
{
    int i;
    int ret = FALSE;

    if (argv == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = PARAM_START_INDEX; i + 1 < argc; i = i + PARAM_STEP) {
        if ((strcmp(argv[i], "-t") == 0) && ((strcmp(argv[i + 1], "custom-op-secverify-enable") == 0))) {
            ret = user_egid_check() ? TRUE : FALSE;
            break;
        }
    }
    return ret;
}