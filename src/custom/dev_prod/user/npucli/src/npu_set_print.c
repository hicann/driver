/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "securec.h"
#include "dcmi_log.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "npu_common.h"
#include "npu_set_print.h"

void print_reset_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info)
{
    char* type_list[] = {"card", "chip", "server", "vnpu"};
    char* chan_list[] = {"outband", "inband"};

    if (ret == NPU_ERR_CODE_NOT_SUPPORT || ret == NPU_ERR_CODE_NOT_SUPPORT_FOR_WIN) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }

    if (ret == NPU_ERR_CODE_ABORT_OPERATE) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        if (type_index == SERVER_SET) {
            printf("\t%-30s : User aborts reset %s by inband.\n", "Message", type_list[type_index]);
        } else {
            printf("\t%-30s : User aborts reset %s by %s.\n", "Message", type_list[type_index],
                   chan_list[operate_info->chan_src]);
        }
        return;
    }

    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to reset %s\n", "Message", type_list[type_index]);
        gplog(LOG_OP, "Failed to reset %s.", type_list[type_index]);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Reset %s successfully.\n", "Message", type_list[type_index]);
    gplog(LOG_OP, "Reset %s successfully.", type_list[type_index]);
}

void print_ssh_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info)
{
    char* type_list[] = {"card", "chip"};
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s :Failed to set %s ssh-enable\n", "Message", type_list[type_index]);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");

    if (npu_board_type_is_station()) {
        if (type_index == 0) {
            printf("\t%-30s : The ssh-enable is set successfully.", "Message");
        } else if (type_index == 1) {
            printf("\t%-30s : The ssh-enable of the %s is set successfully.", "Message", type_list[type_index]);
        }
        printf(" Reset system for the configuration to take effect.\n");
    } else {
        printf(
            "\t%-30s : The ssh-enable of the %s is set successfully. Reset %s for the configuration to take effect.\n",
            "Message", type_list[type_index], type_list[type_index]);
    }
}

void print_p2p_mem_cfg_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info)
{
    char* type_list[] = {"card", "chip"};
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s p2p-mem-cfg\n", "Message", type_list[type_index]);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The p2p-mem-cfg of the %s is set successfully. %s\n",
        "Message", type_list[type_index], "Restart the OS for the configuration to take effect.");
}
void print_result(int ret, struct npu_smi_operate_info *operate_info, SET_TYPE_E type_index, int need_reset)
{
    char* type_list[] = {"card", "chip", "server"};
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT || ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret == NPU_ERR_CODE_ABORT_OPERATE) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : User aborts %s %s.\n", "Message", type_list[type_index], operate_info->stype);
        return;
    }
    if (ret == NPU_ERR_CODE_NOT_SUPPORT_IN_CONTAINER) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : The %s %d is occupied by Docker. Please release the device first.\n", "Message",
            type_list[type_index], operate_info->id);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s %s\n", "Message", type_list[type_index], operate_info->stype);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");

    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        if (need_reset) {
            if (npu_board_type_is_station() == TRUE || npu_board_type_is_soc() == TRUE) {
                printf("\t%-30s : The %s of the %s is set successfully. Please reboot system.\n", "Message",
                    operate_info->stype, type_list[type_index]);
            } else {
                printf("\t%-30s : The %s of the %s is set successfully. Reset card for the configuration to take "
                    "effect.\n",
                    "Message", operate_info->stype, type_list[type_index]);
            }
        } else {
            printf("\t%-30s : The %s of the %s is set successfully.\n", "Message", operate_info->stype,
                type_list[type_index]);
        }
    } else {
        printf("\t%-30s : Set %s %s successfully\n", "Message", type_list[type_index], operate_info->stype);
    }
}

void print_work_tops_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info)
{
    char* type_list[] = {"card", "chip"};
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s nve-level\n", "Message", type_list[type_index]);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s of the %s is set successfully.\n",
        "Message", operate_info->stype, type_list[type_index]);
}

void print_mac_addr_result(int ret, struct npu_smi_operate_info *operate_info)
{
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT || ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret == NPU_ERR_CODE_ABORT_OPERATE) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : User aborts %s.\n", "Message", operate_info->stype);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s\n", "Message", operate_info->stype);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Set chip %s successfully. Reset system for the configuration to take effect.\n", "Message",
        operate_info->stype);
}

void print_cpu_num_cfg_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info)
{
    char* type_list[] = {"card", "chip"};
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s cpu-num-cfg\n", "Message", type_list[type_index]);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");

    if (dcmi_get_product_type_inner() == DCMI_A200I_SOC_A1 || dcmi_get_product_type_inner() == DCMI_A800D_G1) {
        printf("\t%-30s : The %s of the %s is set successfully. Reset system for the configuration to take effect.\n",
            "Message", "cpu-num-cfg", type_list[type_index]);
        return;
    }

    if (npu_board_type_is_card() == TRUE) {
        printf("\t%-30s : The %s of the %s is set successfully. Reset %s for the configuration to take effect.\n",
            "Message", "cpu-num-cfg", type_list[type_index], type_list[type_index]);
    } else {
        printf("\t%-30s : The %s of the %s is set successfully. Reset system for the configuration to take effect.\n",
            "Message", "cpu-num-cfg", type_list[type_index]);
    }
}

void print_vnpu_mode_check_result(int ret, struct npu_smi_operate_info *operate_info)
{
    if (ret != NPU_OK) {
        if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
            printf("The vnpu is not in docker mode, does not support setting %s.\n", operate_info->stype);
        } else {
            printf("Failed to get vnpu mode.\n");
        }
        return;
    }
}

int show_reset_risk(void)
{
    int ret;
    char inputCmdStr[MAX_LENTH] = { '\0' };

    printf("Resetting the standard PCIe card or NPU chip may cause a system hang or"
        " abnormal reset during service running.\n");
    printf("Are you sure you want to continue resetting?(Y/N)\n");

    ret = scanf_s("%s", inputCmdStr, (unsigned int)sizeof(inputCmdStr));
    if ((ret != 1) || ((strcmp(inputCmdStr, "Y") != 0) && (strcmp(inputCmdStr, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }

    if (dcmi_board_type_is_310p_duo_chips() || dcmi_board_chip_type_is_ascend_910_93()) {
        if (dcmi_board_chip_type_is_ascend_910_93()) {
            printf("It will reboot all devices, do you want to continue reboot? [y/n]\n");
        } else {
            printf("It's SMP mode, it will reboot all devices in this SMP system, "
                "do you want to continue reboot? [y/n]\n");
        }
        ret = check_confirm_info();
        if (ret != NPU_OK) {
            if (ret == NPU_ERR_CODE_ABORT_OPERATE) {
                gplog(LOG_OP, "User aborts reset.");
                return ret;
            }
            gplog(LOG_ERR, "check_confirm_info failed. errcode: %d", ret);
            return ret;
        }
    }

    return NPU_OK;
}

int show_reset_vnpu_risk(void)
{
    int ret;
    char inputCmdStr[MAX_LENTH] = { '\0' };

    printf("Resetting the vnpu may cause a system hang or"
        " abnormal reset during service running.\n");
    printf("Are you sure you want to continue resetting?(Y/N)\n");

    ret = scanf_s("%s", inputCmdStr, (unsigned int)sizeof(inputCmdStr));
    if ((ret != 1) || ((strcmp(inputCmdStr, "Y") != 0) && (strcmp(inputCmdStr, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }

    return NPU_OK;
}

int show_device_share_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};

    printf("%s, %s.\n", "There are security risks when opening device sharing",
        "Please ensure that only a single user uses the chip");
    printf("Are you sure you want to continue setting?(Y/N)\n");

    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

int show_device_share_risk_for_chip(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};
 
    printf("%s, %s!\n", "Setting device sharing for single chip is not allowed for this product",
        "all chips belong to the npu card will keep same device-share status");
    printf("%s, %s.\n", "There are security risks when enabling or disabling the device sharing",
        "Please ensure that only a single user operating the card at the same time");
    printf("Are you sure you want to continue setting?(Y/N)\n");
 
    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

void show_power_state_status(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return;
    }
    struct dcmi_power_state_info_stru power_info = {0};
    power_info.type = DCMI_POWER_STATE_SUSPEND;
    power_info.mode = DCMI_POWER_RESUME_MODE_TIME;
    power_info.value = (unsigned int)(operate_info->enable_value);
    ret = dcmi_set_power_state(operate_info->id, operate_info->chip_id, power_info);
    if (ret != DCMI_OK) {
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            gplog(LOG_OP, "This device does not support setting %s. value=%d", operate_info->stype,
                operate_info->enable_value);
            printf("This device does not support setting %s.\n", operate_info->stype);
        } else {
            gplog(LOG_OP, "dcmi_set_power_state failed. ret=%d", ret);
            printf("\t%-30s : %s\n", "Status", "Fail");
            printf("\t%-30s : %s\n", "Message", "The power-state is set failed");
        }
        return;
    }
    return;
}

void print_bootsel_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info)
{
    char* type_list[] = {"card", "chip"};
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s boot-select\n", "Message", type_list[type_index]);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s of the %s is set successfully. Power off system for the configuration to take effect.\n",
           "Message", "boot-select", type_list[type_index]);
}

void print_cpu_freq_up_result(int ret, SET_TYPE_E type_index, struct npu_smi_operate_info *operate_info)
{
    char* type_list[] = {"card", "chip"};
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    }
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s :Failed to set %s cpu-freq-up\n", "Message", type_list[type_index]);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");

    if (type_index == 0) {
        printf("\t%-30s : The cpu-freq-up is set successfully.", "Message");
    } else if (type_index == 1) {
        printf("\t%-30s : The cpu-freq-up of the %s is set successfully.", "Message", type_list[type_index]);
    }
    printf(" Reset system for the configuration to take effect.\n");
}

int show_msn_permanent_risk(void)
{
    int ret;
    char inputCmdStr[MAX_LENTH] = { '\0' };

    printf("This command will introduce a permanent process in host to collect system logs continuously, ");
    printf("Make sure that this path space capacity can save the system logs collected by the current gear setting.\n");
    printf("Warning: if the gear you set this time is different from last time, ");
    printf("some historical logs will be lost! Make sure that historical logs are backed up!\n");
    printf("Are you sure you want to continue this command?(Y/N)\n");

    ret = scanf_s("%s", inputCmdStr, (unsigned int)sizeof(inputCmdStr));
    if ((ret != 1) || ((strcmp(inputCmdStr, "Y") != 0) && (strcmp(inputCmdStr, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }

    return NPU_OK;
}

int show_custom_op_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};

    printf("%s, %s.\n", "Customizable operator will be allowed when opening custom-op",
        "Please ensure that the custom code is secure and trustworthy");
    printf("Are you sure you want to continue setting?(Y/N)\n");

    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

int show_custom_op_secverify_enable_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};

    printf("%s, %s.\n", "Customizable operator secverifying will be allowed when opening custom-op-secverify-enable",
        "Please ensure that the custom code is secure and trustworthy");
    printf("Are you sure you want to continue setting?(Y/N)\n");

    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

int show_op_timeout_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};

    printf("%s, %s.\n", "Configuring the timeout value will enable customizable operations",
        "Please ensure that any custom code is secure and trustworthy");
    printf("Are you sure you want to continue setting?(Y/N)\n");

    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

// 确定设置命令是否继续执行
int show_device_share_config_recover_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};

    printf("%s, %s.\n", "Device share config recover will be allowed when opening device share enable",
        "Please ensure that the custom code is secure and trustworthy");
    printf("Are you sure you want to continue setting?(Y/N)\n");

    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

int show_multi_die_policy_config_recover_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};

    printf("%s, %s.\n", "Multi die policy config recover will be configured",
        "Please ensure that the custom code is secure and trustworthy");
    printf("Are you sure you want to continue setting?(Y/N)\n");

    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

int show_qos_master_config_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};

    printf("%s, %s.\n", "QoS master info will be configured",
        "Please ensure that the custom code is secure and trustworthy");
    printf("Are you sure you want to continue setting?(Y/N)\n");

    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}

int show_multi_die_policy_risk(void)
{
    int ret;
    char input_cmd_str[MAX_LENTH] = {0};
 
    printf("%s, %s.\n", "Support for single-die pass-through containers may lead to potential security risks",
        "Please ensure that the custom code is secure and trustworthy");
    printf("Are you sure you want to continue setting?(Y/N)\n");
 
    ret = scanf_s("%s", input_cmd_str, (unsigned int)sizeof(input_cmd_str));
    if ((ret != 1) || ((strcmp(input_cmd_str, "Y") != 0) && (strcmp(input_cmd_str, "y") != 0))) {
        return NPU_ERR_CODE_ABORT_OPERATE;
    }
    return NPU_OK;
}