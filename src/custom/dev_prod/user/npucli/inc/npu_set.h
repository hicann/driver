/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_SET_H__
#define __NPU_SET_H__
#include <fcntl.h>
#include <sys/ioctl.h>
#include "npu_smi.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define MCU_COLLECT_LOG_RETRY_TIMES 3
#define MCU_COLLECT_LOG_WAIT_TIME 2
#define MCU_COLLECT_DIFF_LOG_WAIT_TIME 5

#define REVOCATION_FILE_LEN 544 // 秘钥吊销文件长度

#define AI_CPU_CNT_2 192
#define AI_CPU_CNT_4 240
#define AI_CPU_CNT_6 252

#define MAX_DEVICE_NUM_IN_CAR 16

#define BMC_RESET_CHIP_SUCCESS 0x0
#define BMC_RESET_CHIP_FARLED 0x01
#define BMC_RESET_CHIP_UNKNOWN 0x02

#define PWM_IOC_MAGIC 'p'
#define PWM_CMD_SET_DUTY_RATIO _IOW(PWM_IOC_MAGIC, 1, int)             // 设置占空比
#define PWM_CMD_SET_DUTY_RATIO_ADJUST_MODE _IOW(PWM_IOC_MAGIC, 3, int) // 设置调速模式
#define PWM_CMD_CLOSE_PWM_ENABLE _IOW(PWM_IOC_MAGIC, 4, int)           // 关闭风扇使能

#define DEV_PWM_NAME "/dev/pwm"
#define PWM_CHANNEL 2
#define FAN_CONFIG_FILE "/home/data/fan_config.ini"
#define AUTO_SPEED 101
#define MANUAL_SPEED 102

#define FILE_PATH_FOR_RESETTING_MUTEX "/run"
#define FILE_NAME_FOR_RESETTING_MUTEX "reset"
#define MAX_WAIT_TIME_FOR_RESETTING_A_MUTEX 40000       // 最长等待40s 40000 = 40 * 1000

#define CARD_NUM_IN_ONE_OS_910_SMP  4

#define CHANNEL_STATUS_SUCCESS 1        // 带外状态 1 为正常

typedef enum set_type_e {
    CARD_SET = 0,
    CHIP_SET,
    SERVER_SET,
    VNPU_SET
} SET_TYPE_E;


/* NPU命令定义 */
struct set_help_cmd {
    void (*func)(struct npu_smi_operate_info *operate_info);
    int type;
};

int npu_set_main(struct npu_smi_operate_info *operate_info, int argc, char **argv);
int parse_fdata_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv);
int set_device_share_config_recover_status(struct npu_smi_operate_info *operate_info);
int set_card_multi_die_policy(struct npu_smi_operate_info *operate_info);
int set_multi_die_policy_config_recover_status(struct npu_smi_operate_info *operate_info);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __NPU_SET_H__ */