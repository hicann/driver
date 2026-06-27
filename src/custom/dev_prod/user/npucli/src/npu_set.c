/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _WIN32
#include <unistd.h>
#include <pthread.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <stddef.h>
#include <limits.h>
#include "securec.h"
#include "npu_card_set.h"
#include "npu_chip_set.h"
#include "npu_chip_set_ext.h"
#include "npu_cmd_parse.h"
#include "npu_common.h"
#include "dcmi_interface_api.h"
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_product_judge.h"
#include "dcmi_inner_cfg_persist.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_basic_info_intf.h"
#include "npu_set_print.h"
#include "npu_info.h"
#include "npu_set.h"

int set_vdevice_mode(struct npu_smi_operate_info *operate_info)
{
    int ret;
    const char *mode_string[] = { "docker", "vm" };

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_set_vdevice_mode(operate_info->enable_value);
    if (ret != DCMI_OK) {
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            gplog(LOG_OP, "This device does not support setting %s. mode=%d", operate_info->stype,
                operate_info->enable_value);
            printf("This device does not support setting %s.\n", operate_info->stype);
        } else if (ret == DCMI_ERR_CODE_RESOURCE_OCCUPIED) {
            gplog(LOG_OP, "can not setting %s. mode=%d, because has other vnpu", operate_info->stype,
                operate_info->enable_value);
            printf("\t%-30s : %s\n", "Status", "Fail");
            printf("\t%-30s : %s\n", "Message",
                "The vNPU(s) in another mode already exist. Destroy them before switching the mode");
        } else {
            gplog(LOG_OP, "dcmi_set_vdevice_mode failed. ret=%d", ret);
            printf("set vnpu mode failed.\n");
        }
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "set vnpu mode success. mode=%d", operate_info->enable_value);
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Set vnpu %s mode success\n", "Message", mode_string[operate_info->enable_value]);
    return ret;
}

STATIC int set_pkcs_enable(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    // pkcs使能整机生效，与device_id, card_id无关，参数不会使用，此处强制写0, buf_size为固定值，强制写1
    ret = dcmi_set_device_info(0, 0, DCMI_MAIN_CMD_SEC, DCMI_SEC_SUB_CMD_PSS, &operate_info->enable_value, 1);
    if (ret != DCMI_OK) {
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            gplog(LOG_OP, "This device does not support setting %s. value=%d", operate_info->stype,
                operate_info->enable_value);
            printf("This device does not support setting %s.\n", operate_info->stype);
        } else {
            gplog(LOG_OP, "dcmi_set_device_info failed. ret=%d", ret);
            printf("\t%-30s : %s\n", "Status", "Fail");
            printf("\t%-30s : %s\n", "Message", "The pkcs-enable is set failed");
        }
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "set pkcs-enable success. value=%d", operate_info->enable_value);
    if (operate_info->enable_value == 0) {
        printf("[WARNING]: Enabling pkcs will raise safety risks.\n");
    }
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The pkcs %s is set successfully\n", "Message", (operate_info->enable_value == 0) ?
        "Enable" : "Disable");
    return ret;
}

/* ****************************************************************************
 函 数 名  : chip_set
 功能描述  : 对芯片的配置
 输入参数  : struct npu_smi_operate_info *operate_info
 输出参数  : 无
 返 回 值  : int
 修改历史      :
  1.日    期   : 2018年7月20日
    修改内容   : 新生成函数
**************************************************************************** */
int chip_set(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->id == NPU_INVALID_VALUE || operate_info->chip_id == NPU_INVALID_VALUE) {
        printf("This command must input card id and chip id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    struct npu_operate_table_item set_chip_info_table[] = {
        {RESET, set_chip_reset},
        {SSH_ENABLE, set_chip_ssh_enable},
        {BOOT_AREA, set_chip_boot_area},
        {MCU_MONITOR, set_chip_mcu_monitor},
        {ERR_COUNT_CLEAR, set_chip_err_count_clear},
        {DEVICE_SHARE, set_chip_share},
        {NVE_LEVEL, set_chip_nve_level},
        {REVOCATION, set_chip_sec_revocation},
        {DISK_POWER, set_disk_power},
        {IP, set_device_ip},
        {MAC_ADDR, set_chip_mac_addr},
        {AICPU_CONF, set_aicpu_config},
        {ECC_INFO_CLEAR, set_chip_ecc_info_clear},
        {VNPU_CREATE, set_chip_create_vdevice},
        {VNPU_DESTORY, set_chip_destroy_vdevice},
        {TLS_CERT, set_tls_cert},
        {TLS_CERT_PERIOD, set_tls_cert_period},
        {SET_VNPU_SVM, set_chip_vdevice_svm},
        {CPU_NUM_CFG, set_chip_cpu_num_config},
        {P2P_MEM_CFG, set_chip_p2p_mem_cfg},
        {NPU_INVALID_VALUE, npu_invalid_item_proc},
        {POWER_STATE, set_power_state},
        {BOOT_SEL, set_chip_boot_sel},
        {CUSTOM_OP, set_chip_custom_op},
        {OP_TIMEOUT, set_op_timeout},
        {QOS_MASTER_CONFIG, set_qos_master}
    };

    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    size_t table_index;
    size_t table_size = sizeof(set_chip_info_table) / sizeof(set_chip_info_table[0]);
    /* 查表并执行对应的设置操作 */
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == set_chip_info_table[table_index].fun_index) {
            ret = set_chip_info_table[table_index].proc_func(operate_info);
            return ret;
        }
    }

    printf("Error parameter in set chip info, type: \"%s\".\n", operate_info->stype);
    return ret;
}

int set_card_p2p_mem_cfg(struct npu_smi_operate_info *operate_info)
{
    int ret;
    operate_info->chip_id = 0;
    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    } else if (operate_info->enable_value == BAR_CFG_ON) {
        ret = set_p2p_mem_cfg_bar_cfg_on(operate_info);
    } else {
        ret = set_p2p_mem_cfg_bar_cfg_off(operate_info);
    }
    if (ret != NPU_OK) {
        gplog(LOG_OP, "Set the p2p-mem-cfg function for card%d failed. enable_flag=%d.", operate_info->id,
            operate_info->enable_value);
        return ret;
    }
    return NPU_OK;
}

int set_key_manage_status(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
    size_t i;
    char real_path[PATH_MAX + 1] = {0};
    const char *config_table[] = {"start", "stop"};
    const char *dst_config_table[] = {"enable", "disable"};

    if (strlen(operate_info->sdata) == 0) {
        gplog(LOG_OP, "Set %s without -s. ", operate_info->stype);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = 0; i < sizeof(config_table) / sizeof(config_table[0]); i++) {
        if ((strncmp(operate_info->sdata, config_table[i], strlen(operate_info->sdata)) == 0) &&
            (strncmp(operate_info->sdata, config_table[i], strlen(config_table[i])) == 0)) {
            break;
        }
    }

    if (i >= sizeof(config_table) / sizeof(config_table[0])) {
        gplog(LOG_OP, "Set %s with wrong parameter:%s. ", operate_info->stype, operate_info->sdata);
        printf("Error parameter of -s\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = npu_get_key_manage_path(real_path, sizeof(real_path));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_key_manage_path failed. err is %d.", ret);
        gplog(LOG_OP, "Set %s %s fail.", operate_info->stype, operate_info->sdata);
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s %s\n", "Message", operate_info->stype, operate_info->sdata);
        return ret;
    }

    char *cmd_str[] = {real_path, "kmsagent", (char *)dst_config_table[i], NULL};
    ret = npu_safe_exec_syscmd_without_output(cmd_str);
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s %s\n", "Message", operate_info->stype, operate_info->sdata);
    } else {
        printf("\t%-30s : %s\n", "Status", "OK");
        printf("\t%-30s : Set %s %s successfully\n", "Message", operate_info->stype, operate_info->sdata);
    }

    gplog(LOG_OP, "Set %s %s %s.", operate_info->stype, operate_info->sdata, (ret == NPU_OK) ? "success" : "fail");
    return NPU_OK;
#else
    printf("This device does not support setting %s.\n", operate_info->stype);
    gplog(LOG_OP, "unsupport set %s.", operate_info->stype);
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

/* ****************************************************************************
 函 数 名  : card_set
 功能描述  : 对卡的配置
 输入参数  : struct npu_smi_operate_info *operate_info
 输出参数  : 无
 返 回 值  : int
 修改历史      :
  1.日    期   : 2021年4月28日
    修改内容   : 新生成函数
**************************************************************************** */
int card_set(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->id == NPU_INVALID_VALUE) {
        printf("This command must input card id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    struct npu_operate_table_item set_card_info_table[] = {
        {ECC_ENABLE, set_card_ecc_enable},
        {SSH_ENABLE, set_card_ssh_enable},
        {COLLECT_LOG, set_card_collect_log},
        {CUSTOMIZED_INFO, set_card_customized_info},
        {ERR_COUNT_CLEAR, set_card_err_count_clear},
        {DEVICE_SHARE, set_card_share},
        {NVE_LEVEL, set_card_nve_level},
        {REVOCATION, set_card_sec_revocation},
        {VNPU_CREATE, set_card_vnpu_config},
        {VNPU_DESTORY, set_card_vnpu_config},
        {CPU_NUM_CFG, set_card_cpu_num_config},
        {P2P_MEM_CFG, set_card_p2p_mem_cfg},
        {NPU_INVALID_VALUE, npu_invalid_item_proc},
        {BOOT_SEL, set_card_boot_sel},
        {RESET_VNPU, set_card_reset_vnpu},
        {CPU_FREQ_UP, set_card_cpu_freq_up_cfg},
        {CUSTOM_OP, set_card_custom_op},
        {CUSTOM_OP_SECVERIFY_ENABLE, set_card_custom_op_secverify_enable},
        {CUSTOM_OP_SECVERIFY_MODE, set_card_custom_op_secverify_mode},
        {CUSTOM_OP_SECVERIFY_CERT, set_card_custom_op_secverify_cert},
#ifdef NPU_SMI_V2
        {ECC_INFO_CLEAR, set_chip_ecc_info_clear},
        {TLS_CERT, set_tls_cert},
        {TLS_CERT_PERIOD, set_tls_cert_period},
        {RESET, set_chip_reset},
#else
        {ECC_INFO_CLEAR, set_card_ecc_info_clear},
        {RESET, set_card_reset},
#endif
    };

    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    size_t table_index;
    size_t table_size = sizeof(set_card_info_table) / sizeof(set_card_info_table[0]);
    /* 查表并执行对应的设置操作 */
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == set_card_info_table[table_index].fun_index) {
            ret = set_card_info_table[table_index].proc_func(operate_info);
            return ret;
        }
    }

    printf("Error parameter in set card info, type: \"%s\".\n", operate_info->stype);
    return ret;
}

int npu_set_vnpu_cfg_recover_state(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (npu_get_chip_type() != NPU_CHIP_310P && npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_OK;
    }

    ret = dcmi_set_vnpu_config_recover_mode(operate_info->enable_value);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "dcmi_set_vnpu_config_recover_mode failed. ret %d", ret);
        /* 该接口返回DCMI_ERR_CODE_NOT_SUPPORT，一种可能是芯片类型不匹配，另外是工作在SMP模式下，
           芯片类型在命令解析已判断，此处返回不支持只有工作模式为SMP
        */
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("NPU is working in SMP mode, does not support setting %s\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("This device does not support setting %s.\n", operate_info->stype);
            ret = DCMI_OK;
        }
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "set vnpu config recover %s success.", (operate_info->enable_value == 0) ? "disable" : "enable");
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The VNPU config recover mode %s is set successfully.\n", "Message",
        (operate_info->enable_value == 0) ? "Disable" : "Enable");
    return ret;
}

int ioctl_set_pwm_mode(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int fd = -1;

    fd = open(DEV_PWM_NAME, O_WRONLY);
    if (fd == -1) {
        gplog(LOG_ERR, "open pwm dev failed.");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = ioctl(fd, PWM_CMD_SET_DUTY_RATIO_ADJUST_MODE, &operate_info->enable_value);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "ioctl set pwm mode failed. err is %d", ret);
        close(fd);
        return NPU_ERR_CODE_IOCTL_FAIL;
    }

    close(fd);
    return NPU_OK;
}

int get_pwm_duty_ratio(struct pwm_info *pwm_operate_info)
{
    int ret;
    int fd = -1;

    fd = open(DEV_PWM_NAME, O_RDONLY);
    if (fd == -1) {
        gplog(LOG_ERR, "open pwm dev failed.");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    pwm_operate_info->channel_num = PWM_CHANNEL;
    ret = ioctl(fd, PWM_CMD_GET_DUTY_RATIO, pwm_operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "ioctl query pwm duty ratio failed. err is %d", ret);
        close(fd);
        return NPU_ERR_CODE_IOCTL_FAIL;
    }

    close(fd);
    return NPU_OK;
}

int save_usr_pwm_set(int pwm)
{
#define HUNDREDS_DIGIT 0
#define TENS_DIGIT 1
#define UNITS_DIGIT 2
#define PWM_NUM_SIZE 3
#define NUMBER_TEN 10
    char pwm_numb[PWM_NUM_SIZE] = {};
    FILE *fp = NULL;
    int fpno;
    int ret;
    struct pwm_info pwm_operate_info = { 0 };

    if (pwm == MANUAL_SPEED) {
        ret = get_pwm_duty_ratio(&pwm_operate_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "get pwm duty ratio error.\n");
            return ret;
        }
        pwm = (int)(pwm_operate_info.ratio);
    }

    pwm_numb[HUNDREDS_DIGIT] = (pwm / NUMBER_TEN) / NUMBER_TEN + '0';
    pwm_numb[TENS_DIGIT] = (pwm / NUMBER_TEN) % NUMBER_TEN + '0';
    pwm_numb[UNITS_DIGIT] = pwm % NUMBER_TEN + '0';

    fp = fopen(FAN_CONFIG_FILE, "w");
    if (fp == NULL) {
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    fpno = fileno(fp);
    if (fpno >= 0) {
        (void)fchmod(fpno, S_IRUSR | S_IWUSR | S_IRGRP);
    }

    ret = (int)fwrite(pwm_numb, sizeof(char), (size_t)PWM_NUM_SIZE, fp);
    if (ret != PWM_NUM_SIZE) {
        gplog(LOG_ERR, "fwrite error.errno is %d", errno);
        fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fclose(fp);
    return NPU_OK;
}

int set_pwm_mode(struct npu_smi_operate_info *operate_info)
{
#define MANUAL 0
    int ret;
    const char *mode_string[] = {"manual", "auto"};

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = ioctl_set_pwm_mode(operate_info);
    if (ret != NPU_OK) {
        printf("Set pwm mode failed.\n");
        return ret;
    }

    if (operate_info->enable_value == MANUAL) {
        ret = save_usr_pwm_set(MANUAL_SPEED);
        if (ret != NPU_OK) {
            return ret;
        }
    } else {
        ret = save_usr_pwm_set(AUTO_SPEED);
        if (ret != NPU_OK) {
            return ret;
        }
    }

    gplog(LOG_OP, "set pwm mode success. mode=%d", operate_info->enable_value);
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Set pwm %s mode success\n", "Message", mode_string[operate_info->enable_value]);
    return ret;
}

int ioctl_set_pwm_duty_ratio(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int fd = -1;
    struct pwm_info pwm_operate_info = { 0 };

    fd = open(DEV_PWM_NAME, O_WRONLY);
    if (fd == -1) {
        gplog(LOG_ERR, "open pwm dev failed.");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    pwm_operate_info.channel_num = PWM_CHANNEL;
    pwm_operate_info.ratio = (unsigned int)(operate_info->enable_value);

    ret = ioctl(fd, PWM_CMD_SET_DUTY_RATIO, &pwm_operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "ioctl set pwm duty ratio failed. err is %d", ret);
        close(fd);
        return NPU_ERR_CODE_IOCTL_FAIL;
    }

    close(fd);
    return NPU_OK;
}

int set_pwm_duty_ratio(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int mode;

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = query_pwm_mode(&mode);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Get pwm mode failed. err is %d", ret);
        return ret;
    }

    if (mode == PWM_AUTO) {
        printf("Setting duty ratio is not allowed in the current auto mode.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = ioctl_set_pwm_duty_ratio(operate_info);
    if (ret != NPU_OK) {
        printf("Set pwm duty ratio failed.\n");
        return ret;
    }

    ret = save_usr_pwm_set(operate_info->enable_value);
    if (ret != NPU_OK) {
        return ret;
    }

    gplog(LOG_OP, "set pwm duty ratio success. duty_ratio=%d", operate_info->enable_value);
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Set pwm duty ratio %d success\n", "Message", operate_info->enable_value);
    return ret;
}

int check_msn_is_existed(int device_logic_id, int card_id, int *msn_existed_flag)
{
    int ret;
    FILE *fp;
    char cmdline[SYS_LOG_MAX_CMD_LINE];
    char buff[SYS_LOG_MAX_CMD_LINE] = {0};
    *msn_existed_flag = FALSE;

    (void)memset_s(cmdline, sizeof(cmdline), 0, sizeof(cmdline));
    ret = sprintf_s(cmdline, sizeof(cmdline),
        "ps -ef | grep \"msnpureport report --permanent -d %d \" | grep -v grep", device_logic_id);
    if (ret < EOK) {
        gplog(LOG_ERR, "Call sprintf_s failed. ret %d", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    fp = popen(cmdline, "r");
    if (fp == NULL) {
        gplog(LOG_ERR, "Failed to run the command on the popen, errno is %d\n", errno);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (fgets(buff, sizeof(buff), fp) != NULL) {
        *msn_existed_flag = TRUE;
    }

    (void)pclose(fp);
    return NPU_OK;
}

int save_sys_log_cfg(const char *file_path, int syslog_level)
{
    int ret;
    char npu_smi_cmd[SYS_LOG_MAX_CMD_LINE] = {0};

    ret = sprintf_s(npu_smi_cmd, sizeof(npu_smi_cmd), "/usr/local/bin/npu-smi set -t sys-log-dump -s %d -f %s\ny\n",
        syslog_level, file_path);
    if (ret < EOK) {
        gplog(LOG_ERR, "Call sprintf_s failed. ret = %d", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = dcmi_set_syslog_persistence_cfg(npu_smi_cmd, SYS_LOG_MAX_CMD_LINE);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Save sys log cfg failed. ret = %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    return NPU_OK;
}

int get_card_and_logic_id_list(int *card_id_list, int *logic_id_list, int *card_num)
{
    int ret, num_id;
    int device_logic_id;

#ifndef NPU_SMI_V2
    ret = dcmi_get_card_list(card_num, card_id_list, MAX_CARD_NUM);
#else
    ret = dcmiv2_get_device_list(card_id_list, card_num, MAX_CARD_NUM);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get card number.");
        return dcmi_to_npu_error_code(ret);
    }

    for (num_id = 0; num_id < *card_num; num_id++) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_logic_id(&device_logic_id, card_id_list[num_id], 0);
#else
        device_logic_id = card_id_list[num_id];
#endif
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "call dcmi_get_device_logic_id failed.ret = %d.", ret);
            logic_id_list[num_id] = -1;
            continue;
        }
        logic_id_list[num_id] = device_logic_id;
    }

    return NPU_OK;
}

int get_card_msn_existed_list(int card_num, int *logic_id_list, int *card_id_list, int *card_msn_existed)
{
    int ret;
    int msn_existed_flag = 0;

    for (int num_id = 0; num_id < card_num; num_id++) {
        ret = check_msn_is_existed(logic_id_list[num_id], card_id_list[num_id], &msn_existed_flag);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "NPU[%d] check msn is existed failed, ret = %d.", card_id_list[num_id], ret);
            return dcmi_to_npu_error_code(ret);
        }
        card_msn_existed[num_id] = (msn_existed_flag == TRUE) ? card_id_list[num_id] : card_msn_existed[num_id];
    }

    return NPU_OK;
}

int check_cards_msn_process(int *card_id_list, int *logic_id_list,
                            int *card_msn_existed, int card_num, int *existed_msn_and_lost_cards)
{
    int ret = 0;
    int num_id;
    int msn_existed_flag = FALSE;

    for (num_id = 0; num_id < card_num; num_id++) {
        if (card_id_list[num_id] < 0) {
            *existed_msn_and_lost_cards += 1;
            card_msn_existed[num_id] = 1;
            continue;
        }
        ret = check_msn_is_existed(logic_id_list[num_id], card_id_list[num_id], &msn_existed_flag);
        if (ret != NPU_OK) {
            printf("Failed to check whether NPU-%d log process is existed or not, ret = %d\n",
                   card_id_list[num_id], ret);
            gplog(LOG_ERR, "Failed to check whether NPU-%d log process is existed or not, ret = %d",
                  card_id_list[num_id], ret);
            return ret;
        }
        if (msn_existed_flag == TRUE) {
            printf("Another process is collecting logs continuously for the os where NPU-%d is in.\n",
                   card_id_list[num_id]);
            gplog(LOG_OP, "Another process is collecting logs continuously for the os where NPU-%d is in.",
                  card_id_list[num_id]);
            *existed_msn_and_lost_cards += 1;
            card_msn_existed[num_id] = 1;
        }
    }

    return NPU_OK;
}

int check_cards_msn_process_v2(int *card_id_list, int *logic_id_list,
                               int *card_msn_existed, int card_num, int *existed_msn_num)
{
    int ret = NPU_OK;
    int num_id;
    int msn_existed_flag = FALSE;

    for (num_id = 0; num_id < card_num; num_id++) {
        if (card_msn_existed[num_id] == 1) {
            continue;
        }

        ret = check_msn_is_existed(logic_id_list[num_id], card_id_list[num_id], &msn_existed_flag);
        if (ret != NPU_OK) {
            printf("Failed to check whether NPU-%d log process is existed or not, ret = %d\n",
                   card_id_list[num_id], ret);
            return ret;
        }

        if (msn_existed_flag == TRUE) {
            card_msn_existed[num_id] = 1;
            *existed_msn_num += 1;
        }
    }

    return ret;
}

int check_syslog_cfg(char *file_path, int syslog_level, int *cfg_changed_flag, int existed_msn_num)
{
    int ret;
    char cfg[SYS_LOG_MAX_CMD_LINE] = {0};
    char input_cfg[SYS_LOG_MAX_CMD_LINE] = {0};

    ret = access("/etc/npu_dev_syslog.cfg", F_OK);
    if (ret != NPU_OK) {
        if (existed_msn_num == 0) {
            return NPU_OK;
        }
        printf("ERROR: The configuration file has been deleted, please clear configuration "
            "and stop syslog collecting process first.\n");
        gplog(LOG_ERR, "sys log cfg does not existed. ret = %d.", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = dcmi_check_syslog_cfg_legal(cfg, sizeof(cfg) / sizeof(char));
    if (ret != DCMI_OK) {
        printf("ERROR: The configuration file has been maliciously modified, please clear configuration and "
            "stop syslog collecting process first.\n");
        gplog(LOG_ERR, "sys log cfg format error. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = sprintf_s(input_cfg, sizeof(input_cfg), "/usr/local/bin/npu-smi set -t sys-log-dump -s %d -f %s\n",
        syslog_level, file_path);
    if (ret < EOK) {
        printf("Call sprintf_s failed. ret = %d.\n", ret);
        gplog(LOG_ERR, "Call sprintf_s failed. ret = %d.", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    if (strncmp(input_cfg, cfg, strlen(input_cfg)) != 0 || strlen(input_cfg) != strlen(cfg)) {
        *cfg_changed_flag = TRUE;
    }

    return NPU_OK;
}

int set_sys_log(char *file_path, int syslog_level)
{
    int ret, num_id, card_num, retry_count = 3, existed_msn_and_lost_cards = 0, lost_card_num = 0;
    int card_id_list[MAX_CARD_NUM] = {0}, logic_id_list[MAX_CARD_NUM] = {0}, card_msn_existed[MAX_CARD_NUM] = {0};
    int cfg_changed_flag = FALSE; // 对比输入配置与当前配置相比是否不一致

    ret = get_card_and_logic_id_list(card_id_list, logic_id_list, &card_num);
    if (ret != NPU_OK) {
        printf("Get card id list or logic id list failed. ret = %d.\n", ret);
        return ret;
    }

    ret = check_cards_msn_process(card_id_list, logic_id_list, card_msn_existed, card_num, &existed_msn_and_lost_cards);
    if (ret != NPU_OK || existed_msn_and_lost_cards == card_num) {
        return ret;
    }

    for (int index = 0; index < card_num; index++) {
        lost_card_num += (card_id_list[index] == -1)? 1 : 0;
    }

    ret = check_syslog_cfg(file_path, syslog_level, &cfg_changed_flag, existed_msn_and_lost_cards);
    if (ret != NPU_OK) {
        return ret;
    }

    // 部分卡直通虚拟机场景下，通到虚机的卡的card_id为-1，existed_msn_and_lost_cards计算了card_id为-1的卡，需要减去这部分；
    if (existed_msn_and_lost_cards > lost_card_num && cfg_changed_flag == TRUE) {
        printf("ERROR:Input configuration is different with existing, please clear configuration and "
            "stop syslog collecting process first.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    while (retry_count >= 0 && existed_msn_and_lost_cards < card_num) {
        for (num_id = 0; num_id < card_num; num_id++) {
            if (card_msn_existed[num_id]) {
                continue;
            }
            // 调用失败会在内部做error记录，并且会在check_cards_msn_process_v2做状态刷新后重试
            // 该处不对返回值做记录判断
            (void)dcmi_set_npu_syslog_dump(card_id_list[num_id], logic_id_list[num_id], syslog_level, file_path);
        }

        usleep(SYSLOG_RETRY_TIME); // 延时5s后再刷新msn进程的在位情况
        ret = check_cards_msn_process_v2(card_id_list, logic_id_list, card_msn_existed,
                                         card_num, &existed_msn_and_lost_cards);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "check_cards_msn_process_v2 for card %d failed, ret = %d.", card_id_list[num_id], ret);
            return ret;
        }
        retry_count--;
    }

    if (existed_msn_and_lost_cards < card_num) {
        printf("Failed to start collecting syslog for all NPU.\n");
    }
    ret = save_sys_log_cfg(file_path, syslog_level);
    if (ret != NPU_OK) {
        printf("Failed to save syslog cfg!");
    }
    return ret;
}

int set_sys_log_dump(struct npu_smi_operate_info *operate_info)
{
    int ret, syslog_level, lock_fd, i;
    char file_path[SYS_LOG_MAX_CMD_LINE] = { 0 };
    char *sdata = operate_info->sdata;

    ret = dcmi_cfg_set_lock(&lock_fd, DCMI_CFG_GET_LOCK_TIMEOUT, DCMI_CFG_SYSLOG_NPU_SMI_LOCK_FILE_NAME);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Get dcmi_cfg_set_lock failed, ret = %d.", ret);
        return DCMI_ERR_CODE_RESOURCE_OCCUPIED;
    }

    if (operate_info->has_id) {
        printf("This command does not support input card id.\n");
        gplog(LOG_ERR, "This command does not support input card id.");
        dcmi_cfg_set_unlock(lock_fd);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->file_path == NULL) {
        printf("This command must input file path and log level.\n");
        gplog(LOG_ERR, "This command must input file path and log level.");
        dcmi_cfg_set_unlock(lock_fd);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (access(operate_info->file_path, F_OK) != NPU_OK || operate_info->file_path[0] != '/') {
        printf("File path does not exist or is not absolute path.\n");
        gplog(LOG_ERR, "File path does not exist or is not absolute path.");
        dcmi_cfg_set_unlock(lock_fd);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = 0; i < strlen(operate_info->file_path); i++) {
        if (i == strlen(operate_info->file_path) - 1 && operate_info->file_path[i] == '/') {
            break;
        }
        file_path[i] = operate_info->file_path[i];
    }

    if ((str2int(&syslog_level, sdata) != 0) || syslog_level < SYSLOG_LEVEL_MIN || syslog_level > SYSLOG_LEVEL_MAX) {
        printf("Input para of -s is invalid, please input 1 to 10.\n");
        gplog(LOG_ERR, "Input para of -s is invalid, please input 1 to 10.");
        dcmi_cfg_set_unlock(lock_fd);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = show_msn_permanent_risk();
    if (ret != 0) {
        gplog(LOG_OP, "User aborts reset.");
        dcmi_cfg_set_unlock(lock_fd);
        return ret;
    }

    ret = set_sys_log(file_path, syslog_level); // ret不等于0时在内部已做错误处理
    dcmi_cfg_set_unlock(lock_fd);

    return ret;
}

int clear_syslog_cfg(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->has_id) {
        printf("This command does not support input card id.\n");
        gplog(LOG_ERR, "This command does not support input card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_clear_npu_syslog_cfg();
    if (ret != DCMI_OK) {
        printf("Failed to clear syslog config.\n");
        return ret;
    }
    gplog(LOG_OP, "Set clear_syslog_cfg success.");
    printf("Clear syslog config success.\n");
    return NPU_OK;
}

int npu_set_custom_op_cfg_recover_state(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_set_custom_op_config_recover_mode(operate_info->enable_value);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_set_custom_op_config_recover_mode failed. ret %d", ret);

        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support setting %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine can call this api.\n");
            ret = DCMI_OK;
        } else {
            printf("Failed to set custom op config recover state, mode=%d.\n", operate_info->enable_value);
        }
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "set custom-op config recover %s success.", (operate_info->enable_value == 0) ? "disable" : "enable");
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The custom-op config recover mode %s is set successfully.\n", "Message",
        (operate_info->enable_value == 0) ? "Disable" : "Enable");
    return ret;
}

int set_device_share_config_recover_status(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->has_id) {
        printf("This command does not support entering card id.\n");
        gplog(LOG_ERR, "This command does not support entering card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value != 0 && operate_info->enable_value != 1) {
        printf("Must input valid parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value) {
        ret = show_device_share_config_recover_risk();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    ret = dcmi_set_device_share_config_recover_mode(operate_info->enable_value);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_set_device_share_config_recover_mode failed. ret %d", ret);

        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support setting %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine or on physical privilege container "
                   "can call this api.\n");
            ret = DCMI_OK;
        } else {
            printf("Failed to set device share config recover state, mode=%d.\n", operate_info->enable_value);
        }
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "set device-share config recover %s success.",
        (operate_info->enable_value == 0) ? "disable" : "enable");
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The device-share config recover mode %s is set successfully.\n", "Message",
        (operate_info->enable_value == 0) ? "Disable" : "Enable");
    return ret;
}

int set_multi_die_policy_config_recover_status(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->has_id) {
        printf("This command does not support entering card id.\n");
        gplog(LOG_ERR, "This command does not support entering card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value != 0 && operate_info->enable_value != 1) {
        printf("Must input valid parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value) {
        ret = show_multi_die_policy_config_recover_risk();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    ret = dcmi_set_multi_die_policy_config_recover_mode(operate_info->enable_value);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_set_multi_die_policy_config_recover_mode failed. ret %d", ret);

        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support setting %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine or on physical privilege container "
                   "can call this api.\n");
            ret = DCMI_OK;
        } else {
            printf("Failed to set multi die policy config recover state, mode=%d.\n", operate_info->enable_value);
        }
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "set multi-die-policy config recover %s success.",
        (operate_info->enable_value == 0) ? "disable" : "enable");
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The multi-die-policy config recover mode %s is set successfully.\n", "Message",
        (operate_info->enable_value == 0) ? "Disable" : "Enable");
    return ret;
}

int set_card_multi_die_policy(struct npu_smi_operate_info *operate_info)
{
    int ret;
 
    if (operate_info->has_id) {
        printf("This command does not support entering card id.\n");
        gplog(LOG_ERR, "This command does not support entering card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
 
    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
 
    if (operate_info->enable_value != 0 && operate_info->enable_value != 1) {
        printf("Must input valid parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
 
    if (operate_info->enable_value == 1) {
        ret = show_multi_die_policy_risk();
        if (ret != NPU_OK) {
            return ret;
        }
    }
 
    ret = dcmi_set_multi_die_policy((enum dcmi_multi_die_policy)operate_info->enable_value);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_set_multi_die_policy failed. ret %d", ret);
 
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support setting %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine or on physical privilege container "
                   "can call this api.\n");
            ret = DCMI_OK;
        } else {
            printf("Failed to set multi_die policy, value=%d.\n", operate_info->enable_value);
        }
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "set multi_die policy %s success.",
        (operate_info->enable_value == 0) ? "UNION_POLICY" : "INDEP_POLICY");
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The multi_die policy %s is set successfully.\n", "Message",
        (operate_info->enable_value == 0) ? "UNION_POLICY" : "INDEP_POLICY");
    return ret;
}

int common_set(struct npu_smi_operate_info *operate_info)
{
    struct npu_operate_table_item set_common_info_table[] = {
        {KEY_MANAGE, set_key_manage_status},
        {VNPU_MODE, set_vdevice_mode},
        {PKCS_ENABLE, set_pkcs_enable},
        {VNPU_CFG_RECOVER, npu_set_vnpu_cfg_recover_state},
        {PWM_MODE, set_pwm_mode},
        {PWM_DUTY_RATIO, set_pwm_duty_ratio},
        {NPU_INVALID_VALUE, npu_invalid_item_proc},
        {SYS_LOG_DUMP, set_sys_log_dump},
        {CLEAR_SYSLOG_CFG, clear_syslog_cfg},
        {SYS_LOG_ENABLE, set_card_syslog_enable},
        {CUSTOM_OP_CFG_RECOVER, npu_set_custom_op_cfg_recover_state},
        {DEVICE_SHARE_CFG_RECOVER, set_device_share_config_recover_status},
        {MULTI_DIE_POLICY, set_card_multi_die_policy},
        {MULTI_DIE_POLICY_CFG_RECOVER, set_multi_die_policy_config_recover_status},
    };

    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    size_t table_index;
    size_t table_size = sizeof(set_common_info_table) / sizeof(set_common_info_table[0]);
    /* 查表并执行对应的设置操作 */
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == set_common_info_table[table_index].fun_index) {
            ret = set_common_info_table[table_index].proc_func(operate_info);
            return ret;
        }
    }

    printf("Error parameter in set common info, type: \"%s\".\n", operate_info->stype);
    return ret;
}

int parse_fdata_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;

    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (strcmp(operate_info->stype, "create-vnpu") == 0) {
        ret = set_create_vdev_param(operate_info, argv[cur + 1]);
        return ret;
    }

    if (strcmp(operate_info->stype, "sys-log-dump") == 0) {
        ret = set_path(operate_info, argv[cur + 1]);
        return ret;
    }

    if (strcmp(operate_info->stype, "revocate") == 0 &&
        (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93)) {
        ret = set_path(operate_info, argv[cur + 1]);
        return ret;
    }

    if (npu_get_chip_type() == NPU_CHIP_910) {
        ret = set_path(operate_info, argv[cur + 1]);
    } else {
        ret = set_sdata(operate_info, argv[cur + 1]);
        operate_info->is_sdata = TRUE;
    }

    return ret;
}

/* ****************************************************************************
 函 数 名  : npu_set_boot_area_help
 功能描述  : 引导区配置帮助菜单
 输入参数  : struct npu_smi_operate_info *operate_info
 输出参数  : 无
 返 回 值  : int
 修改历史      :
  1.日    期   : 2021年4月28日
    修改内容   : 新生成函数
**************************************************************************** */
void npu_set_boot_area_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t boot-area [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID, only support the chip of MCU\n");
}

void npu_set_mcu_monitor_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t mcu-monitor [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID. Only the MCU chip ID is supported\n");
    printf("       -d %%d          Enable or not. The value can only be 0 or 1\n");
    printf("                       (0: False, 1: True)\n");
}

void npu_set_disk_power_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t disk-power [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID, only support the chip of mcu\n");
    printf("       -d %%d          power state value, only can input 0 or 1\n");
    printf("                       (0: poweroff, 1: power on)\n");
}

void npu_set_device_ip_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t ip [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -s %%d          ip and netmask, XX.XX.XX.XX/XX.XX.XX.XX\n");
    printf("                          (eg:192.168.1.135/255.255.255.0)\n");
}

void npu_set_device_mac_addr_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t mac-addr [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -d %%d          Mac Addr ID\n");
    printf("                       (0, 1, 2, 3)\n");
    printf("       -s %%s          mac-addr, XX:XX:XX:XX:XX:XX\n");
    printf("                       (eg:00:05:b8:b9:54:16)\n");
}

void npu_set_enable_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -d %%d          Enable value, only can input 0 or 1\n");
    printf("                       (0: False, 1: TRUE)\n");
}

void npu_set_ecc_enable_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -d %%d          Enable value, only can input 0 or 1\n");
    printf("                       (0: False, 1: TRUE)\n");
}

void npu_set_nve_level_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t nve-level [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    if (npu_get_chip_type() == NPU_CHIP_310B) {
        if (dcmi_get_310b_tops_type() == IS_310B_20TOPS_TYPE) {
            printf("       -d %%d          level value, only can input 0 or 1 or 2 or 3\n");
            printf("                       (0: 20T_1.6GHz, 1: 8T_1.0GHz, 2: 16T_1.6GHz, 3: 8T_1.6GHz)\n");
        } else {
            printf("       -d %%d          level value, only can input 0 or 1\n");
            printf("                       (0: 8T_1.0GHz, 1: 4T_1.0GHz)\n");
        }
    } else {
        printf("       -d %%d          level value, only can input 0 or 1 or 2 or 3\n");
        printf("                       (0: Low, 1: Middle, 2: High, 3: Full)\n");
    }
}

void npu_set_aicpu_config_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t aicpu-config [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -d %%d          AI CPU count, can only enter 2 or 4 or 6\n");
}

void npu_set_create_vcpu_help_inner()
{
    if (npu_get_chip_type() == NPU_CHIP_910) {
        printf("                           (vir02, vir04, vir08, vir16)\n");
    } else if (npu_get_chip_type() == NPU_CHIP_310P) {
        printf("                           (vir01, vir02, vir02_1c, vir04, vir04_3c, vir04_3c_ndvpp, vir04_4c_dvpp)\n");
        printf("       -g %%d              VGroup ID.\n");
        printf("                           (0, 1, 2, 3)\n");
    } else if (npu_get_chip_type() == NPU_CHIP_910B) {
        switch (dcmi_get_board_id_inner()) {
            case DCMI_A900T_POD_A1_BIN0_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN0_P3_BOARD_ID:
            case DCMI_A200T_BOX_A1_BIN0_BOARD_ID:
            case DCMI_A300T_A1_BIN0_BOARD_ID:
            case DCMI_A800T_POD_A2_BIN0_BOARD_ID:
                printf("                           (vir12_3c_32g, vir06_1c_16g)\n");
                break;
            case DCMI_A900T_POD_A1_BIN2_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN2_P3_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN2X_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN2X_P3_BOARD_ID:
            case DCMI_A800I_POD_A2_BIN4_1_PCIE_BOARD_ID:
            case DCMI_A200T_BOX_A1_BIN2_BOARD_ID:
            case DCMI_A200I_BOX_A1_BIN2X_1_BOARD_ID:
            case DCMI_A300T_A1_BIN2_BOARD_ID:
            case DCMI_A300I_A2_BIN2_BOARD_ID:
            case DCMI_A300I_A2_BIN2_64G_BOARD_ID:
            case DCMI_A800I_POD_A2_BIN2_BOARD_ID:
            case DCMI_A800I_POD_A2_BIN2_1_BOARD_ID:
                printf("                           (vir10_3c_16g, vir10_4c_16g_m, vir10_3c_16g_nm, vir05_1c_8g)\n");
                break;
            case DCMI_A900T_POD_A1_BIN1_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN1_P3_BOARD_ID:
            case DCMI_A300T_A1_BIN1_300W_BOARD_ID:
            case DCMI_A300T_A1_BIN1_350W_BOARD_ID:
            case DCMI_A200T_BOX_A1_BIN1_BOARD_ID:
            case DCMI_A800T_POD_A2_BIN1_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN2X_1_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN2X_1_P3_BOARD_ID:
                printf("                           (vir10_3c_32g, vir05_1c_16g)\n");
                break;
            case DCMI_A900T_POD_A1_BIN3_BOARD_ID:
            case DCMI_A900T_POD_A1_BIN3_P3_BOARD_ID:
            case DCMI_A200T_BOX_A1_BIN3_BOARD_ID:
                printf("                           (vir12_3c_32g, vir06_1c_16g)\n");
                break;
            default:
                return;
        }
    }
}

void npu_set_create_vcpu_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t create-vnpu [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d              Card ID\n");
    printf("       -c %%d              Chip ID\n");
    printf("       -f %%s              Template Name\n");
    npu_set_create_vcpu_help_inner();
    printf("       -v %%d              Vnpu ID\n");
}

void npu_set_destroy_vcpu_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t destroy-vnpu [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d              Card ID\n");
    printf("       -c %%d              Chip ID\n");
    printf("       -v %%d              Vnpu ID\n");
}

void npu_set_key_manage_help(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    printf("Usage: %s %s -t key-manage [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -s             Manage service statuses. Enter start or stop.\n");
    printf("                      start: starts the service and enables auto startup.\n");
    printf("                      stop: stops the service and disables auto startup.\n");
#else
    printf("This device does not support setting %s.\n", operate_info->stype);
    gplog(LOG_OP, "unsupport get %s help.", operate_info->stype);
#endif
}

void npu_set_license_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t license [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -f             License (1-255)\n");
}

void npu_set_revocate_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t revocate [Options...]\n", TOOL_NAME, operate_info->name);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -f             Path of SoC certificate files\n");
}
void npu_set_p2p_mem_cfg(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -d %%d          bar-cfg switch, only can input 0 or 1\n");
    printf("                       (0: Disable, 1: Enable)\n");
}
void npu_set_help(const char *name)
{
    printf("Usage: %s %s <-h|-t type> [Options...]\n", TOOL_NAME, name);
    printf("\nCommands:\n");
    printf("       -h, --help     Show this help text and exit\n");
    printf("       -t type        The set type for device\n");
#ifndef NPU_SMI_V2
    printf("                      type: ecc-enable, collect-log, reset, device-share, nve-level, clear-ecc-info,\n");
    printf("                            license, ssh-enable, customized-info, clear-pcie-err, revocate, mac-addr,\n");
    printf("                            mcu-monitor, boot-area, aicpu-config, disk-power, ip, errcount-clear,\n");
    printf(
        "                            vnpu-mode, create-vnpu, destroy-vnpu, vnpu-svm, cpu-num-cfg, vnpu-cfg-recover,\n");
    printf(
        "                            key-manage, pkcs-enable, p2p-mem-cfg, pwm-mode, pwm-duty-ratio, power-state,\n");
    printf("                            boot-select, reset-vnpu, tls-cert, tls-cert-period, cpu-freq-up, custom-op,\n");
    printf("                            sys-log-dump, clear-syslog-cfg, sys-log-enable, custom-op-cfg-recover,\n");
    printf("                            custom-op-secverify-enable, custom-op-secverify-mode, op-timeout-cfg,\n");
    printf("                            device-share-cfg-recover, custom-op-secverify-cert, qos-master-config,\n");
    printf("                            multi-die-policy, multi-die-policy-cfg-recover.\n");
#else
    printf("                      type: reset, clear-ecc-info, key-manage, sys-log-enable, sys-log-dump,\n");
    printf("                            clear-syslog-cfg, tls-cert, tls-cert-period.\n");
#endif
    printf("\nOptions:\n");
#ifndef NPU_SMI_V2
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
#else
    printf("       -i %%d          NPU ID\n");
#endif
    printf("       -d %%d          Config value\n");
    printf("       -s             String format configuration\n");
    printf("       -f             License (1-255) or path of SoC certificate files\n");
    printf("                      or path of all device logs are continuously collected\n");
    printf("       -m             By in-band reset, only can input 1\n");
}

void npu_set_tls_cert_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -f             Path of TLS certificate files\n");
}

void npu_set_tls_cert_period_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -s %%d          Validity period range : 7-180 days.\n");
}

void npu_set_cpu_num_config_help(struct npu_smi_operate_info *operate_info)
{
    int cpu_total_count;

    if (dcmi_board_chip_type_is_ascend_310b()) {
        cpu_total_count = DCMI_CPU_NUM_TOTAL_310B;
    } else if (dcmi_310p_chip_is_ag() == TRUE) {
        cpu_total_count = DCMI_CPU_NUM_TOTAL_AG;
    } else {
        cpu_total_count = DCMI_CPU_NUM_TOTAL_PG;
    }

    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -v %%s          ai_cpu_num:ctrl_cpu_num:data_cpu_num\n");
    printf("                      data_cpu_num only can input 0\n");
    if (dcmi_board_chip_type_is_ascend_310b() || (dcmi_get_product_type_inner() == DCMI_A200I_SOC_A1)) {
        printf("                      sum of ai_cpu_num (0-%d) and ctrl_cpu_num (1-%d) must be %d\n",
            cpu_total_count - 1, cpu_total_count, cpu_total_count);
    } else {
        printf("                      sum of ai_cpu_num (1-%d) and ctrl_cpu_num (1-%d) must be %d\n",
            cpu_total_count - 1, cpu_total_count - 1, cpu_total_count);
    }
}

static void npu_set_vnpu_mode_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          Vnpu mode, only can input 0 or 1\n");
    printf("                       (0: docker, 1: VM)\n");
}

void npu_set_pkcs_enable_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          Pkcs enable, only can input 0 or 1\n");
    printf("                       (0: Enable, 1: Disable)\n");
}

void npu_set_config_recover_help(struct npu_smi_operate_info *operate_info)
{
    if (npu_get_chip_type() != NPU_CHIP_310P && npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM or container.\n");
        return;
    }
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          Persistence config recover mode, only can input 0 or 1\n");
    printf("                       (0: Disable, 1: Enable)\n");
}

void npu_set_device_share_recover_help(struct npu_smi_operate_info *operate_info)
{
    if ((npu_get_chip_type() != NPU_CHIP_310P) && (npu_get_chip_type() != NPU_CHIP_910B) &&
        (npu_get_chip_type() != NPU_CHIP_910_93)) {
        if (npu_is_in_virtual_machine()) {
            printf("This command cannot be executed on a VM.\n");
            return;
        }
    }
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          Persistence config recover mode, only can input 0 or 1\n");
    printf("                       (0: Disable, 1: Enable)\n");
}

void npu_set_multi_die_policy_recover_help(struct npu_smi_operate_info *operate_info)
{
    if ((npu_get_chip_type() != NPU_CHIP_910_93)) {
        printf("This command cannot be executed on the card");
        return;
    }
 
    if (npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM.\n");
            return;
    }
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          Persistence config recover mode, only can input 0 or 1\n");
    printf("                       (0: Disable, 1: Enable)\n");
}

void npu_set_custom_op_secverify_enable_help(struct npu_smi_operate_info *operate_info)
{
    if (npu_is_in_docker() || npu_is_in_virtual_machine() || user_egid_check()) {
        printf("This command can only be executed on a physical root machine.\n");
        return;
    }
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -d %%d          Custom op secverify enable, only can input 0 or 1\n");
    printf("                       (0: False, 1: True)\n");
}

void npu_set_custom_op_secverify_mode_help(struct npu_smi_operate_info *operate_info)
{
    if (user_egid_check()) {
        printf("This command cannot be executed on a VM or container.\n");
        return;
    }
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -d %%d          Custom op secverify mode, only can input 0~7\n");
#ifdef ORIENT_CH
    printf("                       (0: Close Secverifying,     1: Apply default cert)\n");
    printf("                       (2: Apply custom cert,      3: Apply default or custom cert)\n");
    printf("                       (4: Apply community cert,   5: Apply default or community cert)\n");
    printf("                       (6: Apply custom or community cert)\n");
    printf("                       (7: Apply default or custom or community cert)\n");
#else
    printf("                       (0: Close Secverifying,     1: Apply Huawei cert)\n");
    printf("                       (2: Apply custom cert,      3: Apply Huawei or custom cert)\n");
    printf("                       (4: Apply community cert,   5: Apply Huawei or community cert)\n");
    printf("                       (6: Apply custom or community cert)\n");
    printf("                       (7: Apply Huawei or custom or community cert)\n");
#endif
}

void npu_set_pwm_mode_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          Pwm mode, only can input 0 or 1\n");
    printf("                      (0: Manual, 1: Auto)\n");
}

void npu_set_pwm_duty_ratio_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          Pwm duty ratio, only can input 0 - 100\n");
}

void npu_set_power_state_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -d %%d          sleep time, only can input 200 - 604800000\n");
}

static void npu_set_boot_sel_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -d %%d          Boot Select, only can input 3 or 4\n");
    printf("                       (3: M.2 SSD, 4: eMMC)\n");
}

static void npu_set_reset_vnpu_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Vnpu ID\n");
}

void npu_set_cpu_freq_up_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -d %%d          Cpu freq up, only can input 0 or 1\n");
    printf("                       (0: 1.9GHz, 1: 1.0GHz)\n");
}

void npu_set_op_timeout_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -d %%d          Timeout duration, only can input 20 - 32\n");
}

void npu_set_custom_op_secverify_cert_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -f             Path of custom op secverify certificate files\n");
}

void npu_set_qos_master_config_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -s %%d          master_id, only can input 1, 2, 3, 4, 5, 6, 7, 10, 12, 13\n");
    printf("                      (1: vdec, 2: vpc, 3: jpge, 4: jpgd, 5: roce)\n");
    printf("                      (6: nic, 7: pcie, 10: aic_ins, 12: aiv_ins, 13: sdma)\n");
    printf("          %%d          mpamid, only can input from 0 to 127, pcie mode only can input from 0 to 31\n");
    printf("          %%d          qos, only can input from 0 to 7\n");
    printf("                      (0: dedicated for hardlimit, 7: Scheduling green channel)\n");
    printf("          0x%%x        bitmap[0], from 0x0 to 0xffffffffffffffff\n");
    printf("          0x%%x        bitmap[1], from 0x0 to 0xffffffffffffffff\n");
    printf("          0x%%x        bitmap[2], from 0x0 to 0xffffffffffffffff\n");
    printf("          0x%%x        bitmap[3], from 0x0 to 0xffffffffffffffff\n");
    printf("          %%u          mode, only can input 0, 2\n");
    printf("                      (0: regs valid, 2: sqe valid)\n");
}

void npu_set_multi_die_policy_help(struct npu_smi_operate_info *operate_info)
{
    if ((npu_get_chip_type() != NPU_CHIP_910_93)) {
        printf("This command cannot be executed on the card");
        return;
    }
 
    if (npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM.\n");
            return;
    }
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -d %%d          multi-die-policy, only can input 0 or 1\n");
    printf("                       (0: UNION_POLICY, 1: INDEP_POLICY)\n");
}

static struct set_help_cmd set_help_list[] = {
    { npu_set_boot_area_help,   BOOT_AREA},
    { npu_set_mcu_monitor_help, MCU_MONITOR},
    { npu_set_disk_power_help, DISK_POWER},
    { npu_set_device_ip_help, IP},
    { npu_set_device_mac_addr_help, MAC_ADDR},
    { npu_set_enable_help, SSH_ENABLE},
    { npu_set_ecc_enable_help, ECC_ENABLE},
    { npu_set_enable_help, DEVICE_SHARE},
    { npu_set_device_share_recover_help, DEVICE_SHARE_CFG_RECOVER},
    { npu_set_nve_level_help, NVE_LEVEL},
    { npu_set_aicpu_config_help, AICPU_CONF},
    { npu_set_create_vcpu_help, VNPU_CREATE},
    { npu_set_destroy_vcpu_help, VNPU_DESTORY},
    { npu_set_key_manage_help, KEY_MANAGE},
    { npu_set_license_help, CUSTOMIZED_INFO},
    { npu_set_revocate_help, REVOCATION},
    { npu_set_tls_cert_help, TLS_CERT},
    { npu_set_tls_cert_period_help, TLS_CERT_PERIOD},
    { npu_set_cpu_num_config_help, CPU_NUM_CFG},
    { npu_set_vnpu_mode_help, VNPU_MODE},
    { npu_set_pkcs_enable_help, PKCS_ENABLE},
    { npu_set_config_recover_help, VNPU_CFG_RECOVER},
    { npu_set_pwm_mode_help, PWM_MODE},
    { npu_set_pwm_duty_ratio_help, PWM_DUTY_RATIO},
    { npu_set_p2p_mem_cfg, P2P_MEM_CFG},
    { npu_set_power_state_help, POWER_STATE},
    { npu_set_boot_sel_help, BOOT_SEL},
    { npu_set_reset_vnpu_help, RESET_VNPU},
    { npu_set_cpu_freq_up_help, CPU_FREQ_UP},
    { npu_set_enable_help, CUSTOM_OP},
    { npu_set_config_recover_help, CUSTOM_OP_CFG_RECOVER},
    { npu_set_custom_op_secverify_enable_help, CUSTOM_OP_SECVERIFY_ENABLE},
    { npu_set_custom_op_secverify_mode_help, CUSTOM_OP_SECVERIFY_MODE},
    { npu_set_op_timeout_help, OP_TIMEOUT},
    { npu_set_custom_op_secverify_cert_help, CUSTOM_OP_SECVERIFY_CERT},
    { npu_set_qos_master_config_help, QOS_MASTER_CONFIG},
    { npu_set_multi_die_policy_help, MULTI_DIE_POLICY},
    { npu_set_multi_die_policy_recover_help, MULTI_DIE_POLICY_CFG_RECOVER},
    { NULL },
};

void npu_set_show_help(struct npu_smi_operate_info *operate_info)
{
    struct set_help_cmd *cmd = NULL;
    /* 优先走定制的帮助信息 */
    for (cmd = set_help_list; cmd->func != NULL; cmd++) {
        if (cmd->type == operate_info->type) {
            cmd->func(operate_info);
            return;
        }
    }
    
    /*不支持A5虚拟机-h和--help */
    if (npu_get_chip_type() == NPU_CHIP_950 && npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM or container.\n");
        return;
    }

    /* 未定制的帮助信息，打印npu-set的默认帮助 */
    npu_set_help(operate_info->name);
}

int check_env_set(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    if (type_unsupport_set_in_common_docker(argc, argv)) {
        printf("This command cannot be executed on a common container.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if ((npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93 ||
            dcmi_get_product_type_inner() == DCMI_A200_A2_EP) &&
        (!type_support_in_vm_or_docker(argc, argv)) && npu_is_run_in_vm_or_docker()) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    /* 除reset外，set类型命令均不支持容器场景,910B特权容器支持复位vnpu */
    if (npu_is_in_docker() && (!type_support_in_vm_or_docker(argc, argv))) {
        printf("This command cannot be executed on a container.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    return NPU_OK;
}

/* ****************************************************************************
 函 数 名  : npu_set_run
 功能描述  : 执行具体的操作
 输入参数  : struct npu_smi_operate_info *operate_info
 输出参数  : 无
 返 回 值  : unsigned int
 修改历史      :
  1.日    期   : 2018年5月15日
    修改内容   : 新生成函数
**************************************************************************** */
int npu_set_run(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->is_common) {
        ret = common_set(operate_info);
    } else if (operate_info->is_chip) {
        ret = chip_set(operate_info);
    } else {
        ret = card_set(operate_info);
    }
    if (ret == NPU_ERR_CODE_INVALID_PARAMETER) {
        npu_set_show_help(operate_info);
    }
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        gplog(LOG_OP, "This device does not support setting %s. card_id=%d, device_id=%d", \
              operate_info->stype, operate_info->id, operate_info->chip_id);
    }
    return ret;
}

/* ****************************************************************************
 函 数 名  : npu_set_main
 功能描述  : set功能主入口函数
 输入参数  : struct npu_smi_operate_info *operate_info
             int argc
             char ** argv
 输出参数  : 无
 返 回 值  : int
 修改历史      :
  1.日    期   : 2018年5月14日
    修改内容   : 新生成函数
**************************************************************************** */
int npu_set_main(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int ret;

    /* 只有root用户才有设置权限 */
    ret = user_egid_check();
    if (ret != NPU_OK) {
        return ret;
    }

    if (argc < LEAST_PARAMETER_NUM) {
        printf("\nThere has no options.\n\n");
        npu_set_show_help(operate_info);
        return NPU_ERR_CODE_PARAMETER_SHOW_HELP;
    }

    ret = check_env_set(operate_info, argc, argv);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = parse_npu_set_param(operate_info, argc, argv);

#ifdef NPU_SMI_V2
    if (operate_info->is_chip) {
        printf("This device does not support input parameter of -c.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
#endif
    if (ret == NPU_OK) {
        ret = npu_set_run(operate_info);
        if (operate_info->file_path != NULL) {
            free(operate_info->file_path);
            operate_info->file_path = NULL;
        }
        return ret;
    }

    if (operate_info->file_path != NULL) {
        free(operate_info->file_path);
        operate_info->file_path = NULL;
    }

    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        gplog(LOG_OP, "This device does not support setting %s.", operate_info->stype);
        ret = NPU_OK;
    }
    if ((ret == NPU_ERR_CODE_INVALID_PARAMETER) || (ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
        npu_set_show_help(operate_info);
    }
    if ((ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP) || (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED)) {
        ret = NPU_OK;
    }
    return ret;
}
