/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdbool.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <stdio.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "npu_error_code.h"
#include "npu_common.h"
#include "npu_set.h"
#include "dcmi_log.h"
#include "dcmi_inner_cfg_manage.h"
#include "npu_set_print.h"
#include "npu_file_operate.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_hot_reset_intf.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_inner_cfg_persist.h"
#include "dcmi_common.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "npu_chip_set.h"
#include "npu_chip_set_ext.h"
#include "npu_card_set.h"

struct args_reset_inband {
    int card_id;
    int device_id;
    int result;
};

enum result_reset {
    RESET_INBAND_RESETING = 0,
    RESET_INBAND_FAIL,
    RESET_INBAND_SUCCESS
};

int set_card_collect_log(struct npu_smi_operate_info *operate_info)
{
    int ret, numid;

    if (npu_check_is_has_mcu() == FALSE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    for (numid = 0; numid < MCU_LOG_MAX; numid++) {
        ret = dcmi_mcu_collect_log(operate_info->id, numid);
        if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
            printf("In the vNPU scenario, this device does not support setting %s.\n", operate_info->stype);
            gplog(LOG_OP, "In the vNPU scenario, this device does not support setting %s.", operate_info->stype);
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
        if (ret != DCMI_OK) {
            if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
                printf("\nFailed to collect logs,(%d).\n", numid);
            } else {
                printf("\nCollect log fail,(%d).\n", numid);
            }
            gplog(LOG_OP, "Set the collect-log function for card%d failed.logtype=%d.", operate_info->id, numid);
        } else {
            if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
                printf("\nLogs collected successfully,(%d).\n", numid);
            } else {
                printf("\nCollect log success,(%d).\n", numid);
            }
            gplog(LOG_OP, "Set the collect-log function for card%d success. logtype=%d.", operate_info->id, numid);
        }

        if (numid != (MCU_LOG_MAX - 1)) {
            sleep(MCU_COLLECT_DIFF_LOG_WAIT_TIME);
        }
    }

    return dcmi_to_npu_error_code(ret);
}

int set_card_nve_level(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_card_sec_revocation(struct npu_smi_operate_info *operate_info)
{
    if (npu_get_chip_type() != NPU_CHIP_910 && npu_get_chip_type() != NPU_CHIP_910B &&
        npu_get_chip_type() != NPU_CHIP_910_93) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_card_ecc_enable(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_device_ecc_enable(operate_info->id, chip_id, DCMI_DEVICE_TYPE_DDR, operate_info->enable_value);
        if (ret != DCMI_OK) {
            print_result(ret, operate_info, CARD_SET, FALSE);
            gplog(LOG_OP, "Set the ECC function for card%d failed. enable_flag=%d.", operate_info->id,
                operate_info->enable_value);
            return dcmi_to_npu_error_code(ret);
        }
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    if (npu_board_type_is_card() == TRUE) {
        printf("\t%-30s : The %s is set successfully. Reset card for the configuration to take effect.\n", "Message",
            operate_info->stype);
    } else {
        printf("\t%-30s : The %s is set successfully. Reset system for the configuration to take effect.\n", "Message",
            operate_info->stype);
    }

    gplog(LOG_OP, "Set the ECC function for card%d success. enable_flag=%d.", operate_info->id,
        operate_info->enable_value);
    return NPU_OK;
}

STATIC int set_card_pre_reset(int card_id, int npu_count)
{
    int ret;
    int chip_index;

    for (chip_index = 0; chip_index < npu_count; chip_index++) {
        ret = dcmi_pre_reset_soc(card_id, chip_index);
        if (ret != DCMI_OK) {
            printf("Failed to start prereset card %d chip %d.\n", card_id, chip_index);
            printf("Please reboot OS to reset card.\n");
            return dcmi_to_npu_error_code(ret);
        }
    }
    return NPU_OK;
}

STATIC int set_card_outband_reset(int card_id, int npu_count)
{
    int ret;
    int chip_index;

    for (chip_index = 0; chip_index < npu_count; chip_index++) {
        ret = dcmi_reset_device(card_id, chip_index);
        if (ret != DCMI_OK) {
            printf("Failed to reset card %d chip %d.\n", card_id, chip_index);
            printf("Please reboot OS to reset card.\n");
            return dcmi_to_npu_error_code(ret);
        }
    }
    return NPU_OK;
}

STATIC int set_card_rescan(int card_id, int npu_count)
{
    int ret;
    int chip_index;

    for (chip_index = 0; chip_index < npu_count; chip_index++) {
        ret = dcmi_rescan_soc(card_id, chip_index);
        if (ret != DCMI_OK) {
            printf("Failed to rescan card %d chip %d.\n", card_id, chip_index);
            printf("Please reboot OS to reset card.\n");
            return dcmi_to_npu_error_code(ret);
        }
    }
    return NPU_OK;
}

#ifndef _WIN32
STATIC int reset_card_outband(struct npu_smi_operate_info *operate_info)
{
    int ret, mcu_id, cpu_id, fd;
    int npu_count = 0;
    int channel_state = 0;

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    // 通过一个芯片获取对应类型
    dcmi_init_product_type_inner(operate_info->id, 0);

    ret = show_reset_risk();
    if (ret != NPU_OK) {
        gplog(LOG_OP, "User aborts reset.");
        return ret;
    }

    // 只需通过获取一个芯片的状态来判断通路状态
    ret = dcmi_get_device_outband_channel_state(operate_info->id, 0, &channel_state);
    if (ret != DCMI_OK || channel_state != CHANNEL_STATUS_SUCCESS) {
        printf("\nChip reset is not supported. Please check BMC version and IPMI driver.\n");
        printf("Please reboot OS to reset chip if there is no BMC.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 310p双芯片卡为SMP模式，复位一个芯片即会触发整卡复位
    npu_count = (dcmi_board_type_is_310p_duo_chips() == TRUE) ? 1 : npu_count;

    printf("\t%-30s : %s\n", "Message", "resetting ...");

    if (npu_create_lock_file(FILE_PATH_FOR_RESETTING_MUTEX, FILE_NAME_FOR_RESETTING_MUTEX, &fd) != NPU_OK) {
        gplog(LOG_ERR, "reset_card_outband creat lock file fail.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (npu_set_file_lock(fd, MAX_WAIT_TIME_FOR_RESETTING_A_MUTEX) != NPU_OK) {
        printf("Another user is resetting the NPU(s). Please try again later.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 预复位
    ret = set_card_pre_reset(operate_info->id, npu_count);
    if (ret != NPU_OK) {
        goto OUT;
    }

    // 复位
    ret = set_card_outband_reset(operate_info->id, npu_count);
    if (ret != NPU_OK) {
        goto OUT;
    }
    sleep(3); // 延时3s

    // 重新扫描
    ret = set_card_rescan(operate_info->id, npu_count);
    if (ret != NPU_OK) {
        goto OUT;
    }
OUT:
    npu_set_file_unlock(fd);
    return ret;
}
#else
STATIC int reset_card_outband(struct npu_smi_operate_info *operate_info)
{
    return NPU_ERR_CODE_NOT_SUPPORT;
}
#endif

#ifndef _WIN32
STATIC int reset_card_inband(struct npu_smi_operate_info *operate_info)
{
    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    ret = show_reset_risk();
    if (ret != NPU_OK) {
        gplog(LOG_OP, "User aborts reset.");
        return ret;
    }

    // 310p双芯片卡为SMP模式，复位一个芯片即会触发整卡复位
    npu_count = (dcmi_board_type_is_310p_duo_chips() == TRUE) ? 1 : npu_count;
    printf("\t%-30s : %s\n", "Message", "resetting ...");

    // 复位
    for (chip_id = 0; chip_id < npu_count; chip_id++) {
#ifndef NPU_SMI_V2
        ret = dcmi_set_device_reset(operate_info->id, chip_id, operate_info->chan_src);
#else
        ret = dcmiv2_reset_device(operate_info->id, operate_info->chan_src);
#endif
        if (ret != DCMI_OK) {
            return dcmi_to_npu_error_code(ret);
        }
    }
    // 复位状态查询
    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = get_chip_boot_status(operate_info->id, chip_id);
        if (ret != NPU_OK) {
            return ret;
        }
    }

    return NPU_OK;
}
#else
DWORD WINAPI thread_reset_device_inband(_In_ LPVOID arg)
{
    struct args_reset_inband *param = (struct args_reset_inband *)arg;
    int ret;

    ret = dcmi_set_device_reset(param->card_id, param->device_id, INBAND_CHANNEL);
    if (ret != 0) {
        param->result = RESET_INBAND_FAIL;
    }
    else {
        param->result = RESET_INBAND_SUCCESS;
    }

    return NPU_OK;
}

STATIC int reset_card_inband(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int chip_count = 0;
    int chip_index;
    HANDLE  thread[MAX_DEVICE_NUM_IN_CAR] = { 0 };
    struct args_reset_inband args[MAX_DEVICE_NUM_IN_CAR] = { {0} };

    ret = show_reset_risk();
    if (ret != NPU_OK) {
        gplog(LOG_OP, "User aborts reset.");
        return ret;
    }

    ret = dcmi_get_device_num_in_card(operate_info->id, &chip_count);
    if (ret != DCMI_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    if (chip_count > MAX_DEVICE_NUM_IN_CAR) {
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 310p双芯片卡为SMP模式，复位一个芯片即会触发整卡复位
    chip_count = (dcmi_board_type_is_310p_duo_chips() == TRUE) ? 1 : chip_count;

    printf("\t%-30s : %s\n", "Message", "resetting ...");

    // 复位
    for (chip_index = 0; chip_index < chip_count; chip_index++) {
        args[chip_index].card_id = operate_info->id;
        args[chip_index].device_id = chip_index;
        thread[chip_index] = CreateThread(NULL, 0, thread_reset_device_inband, &args[chip_index], 0, NULL);
        if (thread[chip_index] == NULL) {
            printf("create thread(%d) error\n", chip_index);
            gplog(LOG_ERR, "call CreateThread Error: index=%d, err=%d", chip_index, GetLastError());
            return NPU_ERR_CODE_INNER_ERR;
        }
    }

    WaitForMultipleObjects(chip_count, thread, TRUE, INFINITE);
    for (chip_index = 0; chip_index < chip_count; chip_index++) {
        if (args[chip_index].result != RESET_INBAND_SUCCESS) {
            printf("Failed to reset card %d chip %d.\n", operate_info->id, chip_index);
            printf("Please reboot OS to reset card.\n");
            return NPU_ERR_CODE_INNER_ERR;
        }
    }
    return NPU_OK;
}
#endif

STATIC int set_card_reset_check_permission(struct npu_smi_operate_info *operate_info)
{
    int chip_type = npu_get_chip_type();
    if ((chip_type == NPU_CHIP_910B) && (npu_is_run_in_vm_or_docker() == TRUE)) {
        // 910B在容器和虚拟机场景不支持热复位
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    if (dcmi_board_chip_type_is_ascend_950_card() &&
        (npu_is_run_in_vm_or_docker() == TRUE && dcmi_is_in_phy_privileged_docker_root() == FALSE)) {
        // 950标卡仅在物理机和特权容器支持热复位
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (dcmi_check_device_reset_vnpu_mode(operate_info->id) == DCMI_OK) {
        // 910B算力切分场景下，不支持该命令
        printf("In the vNPU scenario, this device does not support setting %s.\n", operate_info->stype);
        gplog(LOG_OP, "In the vNPU scenario, this device does not support setting %s, card=%d, chip=%d.",
            operate_info->stype, operate_info->id, operate_info->chip_id);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (((npu_board_type_is_server() == TRUE) || (npu_is_run_in_vm_or_docker() == TRUE)) &&
          !dcmi_board_chip_type_is_ascend_950_card()) {
        printf("Must input parameter of chip id.\n");
        if (chip_type == NPU_CHIP_910B) {
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

#ifdef _WIN32
    if (npu_board_type_is_card() != TRUE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#endif

    return NPU_OK;
}

static bool is_chip_inband_reset_supported(void)
{
    int chip_type = npu_get_chip_type();
    // 明确支持npu-smi set -t reset -i的芯片型号
    if (chip_type == NPU_CHIP_310 ||
        chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_950) {
        return true;
    }
    return false;
}

int set_card_reset(struct npu_smi_operate_info *operate_info)
{
    int ret, msn_recover_ret;
    ret = set_card_reset_check_permission(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    if (operate_info->chan_src == INBAND_CHANNEL) {
        if (!is_chip_inband_reset_supported()) {
            printf("Must input parameter of chip id.\n");
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
        ret = reset_card_inband(operate_info);
    } else {
        if (npu_board_type_is_card() != TRUE) {
            printf("This device does not support setting %s.\n", operate_info->stype);
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
        ret = reset_card_outband(operate_info);
    }
    print_reset_result(ret, CARD_SET, operate_info);

    if (!npu_is_in_docker()) {
        msn_recover_ret = npu_msn_log_cfg_recover(operate_info->id);
        if (msn_recover_ret != NPU_OK) {
            gplog(LOG_ERR, "Failed to recover msn(ret=%d).", msn_recover_ret);
        }
    }

    return ret;
}

int set_card_ssh_enable(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    char enable_value = (char)operate_info->enable_value;
    if (enable_value == 1) {
        printf("[WARNING]: Enabling SSH will raise the safety risks.\n");
    }
    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_device_user_config(operate_info->id, chip_id, "ssh_status", 1, &enable_value);
        if (ret != NPU_OK) {
            print_ssh_result(ret, CARD_SET, operate_info);
            gplog(LOG_OP, "Set the SSH function for card%d failed. enable_flag=%d.", operate_info->id,
                operate_info->enable_value);
            return dcmi_to_npu_error_code(ret);
        }
    }

    print_ssh_result(NPU_OK, CARD_SET, operate_info);
    gplog(LOG_OP, "Set the SSH function for card%d success. enable_flag=%d.", operate_info->id,
        operate_info->enable_value);
    return NPU_OK;
}

STATIC int check_support_set_customized_info(struct npu_smi_operate_info *operate_info)
{
    bool check_support_result = false;

    switch (npu_get_chip_type()) {
        case NPU_CHIP_310:
            check_support_result = (strcmp(operate_info->stype, "license") != 0) ? false : true;
            break;
        case NPU_CHIP_310P:
            check_support_result = (strcmp(operate_info->stype, "customized-info") != 0) ? false : true;
            break;
        default:
            break;
    }

    if (!check_support_result) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return NPU_OK;
}

int set_card_customized_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    ret = check_support_set_customized_info(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    if (operate_info->is_sdata != TRUE) {
        printf("Must input parameter of customized info data.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_set_card_customized_info(operate_info->id, operate_info->sdata, (int)strlen(operate_info->sdata));
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set %s for card%d failed.", operate_info->stype, operate_info->id);
        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            char *type_info = (npu_get_chip_type() == NPU_CHIP_310) ? "License" : "Customized info";
            printf("\t%-30s : %s is already exists\n", "Reason", type_info);
        } else if (ret != DCMI_ERR_CODE_NOT_SUPPORT) {
            char *type_info = (npu_get_chip_type() == NPU_CHIP_310) ? "license" : "customized info";
            printf("\t%-30s : Failed to get %s\n", "Reason", type_info);
        }

        print_result(ret, operate_info, CARD_SET, FALSE);
        return dcmi_to_npu_error_code(ret);
    }

    print_result(ret, operate_info, CARD_SET, FALSE);
    gplog(LOG_OP, "Set %s for card%d success.", operate_info->stype, operate_info->id);
    return NPU_OK;
}

int set_card_err_count_clear(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;
    enum npu_chip_type chip_type = npu_get_chip_type();

    ret = check_support_err_count_clear(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_device_clear_pcie_error(operate_info->id, chip_id);
        if (ret != DCMI_OK) {
            print_result(ret, operate_info, CARD_SET, FALSE);
            gplog(LOG_OP, "clear pcie error count for card%d failed.", operate_info->id);
            return dcmi_to_npu_error_code(ret);
        }
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    if ((chip_type == NPU_CHIP_310) || (chip_type == NPU_CHIP_310B)) {
        printf("\t%-30s : The %s is set successfully.\n", "Message", operate_info->stype);
    } else {
        printf("\t%-30s : Set %s successfully\n", "Message", operate_info->stype);
    }

    gplog(LOG_OP, "clear pcie error count for card%d success.", operate_info->id);
    return NPU_OK;
#else
    printf("This device does not support setting %s.\n", operate_info->stype);
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

STATIC int set_card_share_for_products(struct npu_smi_operate_info *operate_info)
{
    int ret, chip_id;
    int npu_count = 0, mcu_id = 0, cpu_id = 0;
    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }
 
    if (dcmi_board_chip_type_is_ascend_910_93()) {
        // A3 场景下 下发配置容器共享命令会配置两个die，也就是配两遍；
        // 如果走正常通道每个die都会配两遍，持久化文件会写4遍，所以保留这个特殊通道，提升执行效率。
        ret = dcmi_set_device_info(operate_info->id, 0, DEVICE_SHARE_MAIN_CMD, DEVICE_SHARE_SUB_CMD,
            &operate_info->enable_value, sizeof(int));
    } else {
        for (chip_id = 0; chip_id < npu_count; chip_id++) {
            ret = dcmi_set_device_info(operate_info->id, chip_id, DEVICE_SHARE_MAIN_CMD, DEVICE_SHARE_SUB_CMD,
                &operate_info->enable_value, sizeof(int));
            if (ret != DCMI_OK) {
                return ret;
            }
        }
    }
 
    return ret;
}

int set_card_share(struct npu_smi_operate_info *operate_info)
{
    int ret;
    bool check_result = (npu_check_is_has_d_chip() == FALSE);
    if (check_result) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    } else if (operate_info->enable_value) {
        ret = show_device_share_risk();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    ret = set_card_share_for_products(operate_info);
    if (ret != DCMI_OK) {
        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine or on physical privilege container "
                   "can call this api.\n");
        }
        ret = dcmi_to_npu_error_code(ret);
        print_result(ret, operate_info, CARD_SET, FALSE);
        gplog(LOG_OP, "Set device share for card%d failed. enable_flag=%d.", operate_info->id,
            operate_info->enable_value);
        return ret;
    }

    if (npu_board_type_is_station() || dcmi_get_product_type_inner() == DCMI_A500_A2) {
        update_minid_conf("device_share", operate_info->enable_value);
    }
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s is set successfully.\n", "Message", operate_info->stype);
    gplog(LOG_OP, "Set device share for card%d success. enable_flag=%d.", operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_card_ecc_info_clear(struct npu_smi_operate_info *operate_info)
{
    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type != NPU_CHIP_910 && chip_type != NPU_CHIP_910B &&
        chip_type != NPU_CHIP_910_93  && chip_type != NPU_CHIP_950) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_device_clear_ecc_statistics_info(operate_info->id, chip_id);
        if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
            printf("In the vNPU scenario, this device does not support setting %s.\n", operate_info->stype);
            gplog(LOG_OP, "In the vNPU scenario, this device does not support setting %s.", operate_info->stype);
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
        if (ret != DCMI_OK) {
            print_result(ret, operate_info, CARD_SET, FALSE);
            gplog(LOG_OP, "clear ecc info for card%d failed.", operate_info->id);
            return dcmi_to_npu_error_code(ret);
        }
    }

    print_result(ret, operate_info, CARD_SET, FALSE);
    gplog(LOG_OP, "clear ecc info for card%d success.", operate_info->id);
    return NPU_OK;
}

int set_card_vnpu_config(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_card_cpu_num_config(struct npu_smi_operate_info *operate_info)
{
    int ret, i, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;
    unsigned char cpu_num_config[DCMI_CPU_NUM_CFG_LEN] = {0};
    int vnpu_cfg = DCMI_NO_EXIST_VNPU_CFG;

    if (operate_info->vnpu_conf[NPU_V_PARAM_FLAG_INDEX] == 0) {
        printf("Must input parameter of -v.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = 0; i < CPU_CFG_INDEX_MAX; i++) {
        if (operate_info->vnpu_conf[i] < 0) {
            gplog(LOG_ERR, "vnpu_conf[%d] value %d less than 0.", i, (int)operate_info->vnpu_conf[i]);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    // 添加校验-v参数及解析成cpu_num_config, 海思接口顺序排列与实际习惯不符，对外顺序表现为AI、Ctrl、Data
    cpu_num_config[2] = (unsigned char)operate_info->vnpu_conf[0];         // 昇腾入参0（AI）对应海思入参2
    cpu_num_config[0] = (unsigned char)operate_info->vnpu_conf[1];         // 昇腾入参1（Ctrl）对应海思入参0
    cpu_num_config[1] = (unsigned char)operate_info->vnpu_conf[2];         // 昇腾入参2（Data）对应海思入参1

    ret = dcmi_check_cpu_num_config(cpu_num_config, DCMI_CPU_NUM_CFG_LEN);
    if (ret != NPU_OK) {
        printf("Error parameter of -v\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    ret = dcmi_cfg_card_exist_vnpu_config(operate_info->id, &vnpu_cfg);
    if ((ret == DCMI_OK) && (vnpu_cfg == DCMI_EXIST_VNPU_CFG)) {
        print_cpu_num_cfg_result(NPU_ERR_CODE_INNER_ERR, CARD_SET, operate_info);
        gplog(LOG_OP, "Config cpu num for card%d failed.", operate_info->id);
        return NPU_OK;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_device_cpu_num_config(operate_info->id, chip_id, cpu_num_config, DCMI_CPU_NUM_CFG_LEN);
        if (ret != NPU_OK) {
            print_cpu_num_cfg_result(ret, CARD_SET, operate_info);
            gplog(LOG_OP, "Config cpu num for card%d failed.", operate_info->id);
            return dcmi_to_npu_error_code(ret);
        }
    }

    print_cpu_num_cfg_result(NPU_OK, CARD_SET, operate_info);
    gplog(LOG_OP, "Config cpu num for card%d success.", operate_info->id);
    return NPU_OK;
}

int set_card_boot_sel(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int npu_check_vdev_id(int vnpu_id)
{
    int num_id, vnum_id, ret;
    int card_id_list[MAX_CARD_NUM] = {0};
    int card_num = 0;
    int vdev_num = 0;
    struct dcmi_soc_total_resource soc_total_resource = { 0 };
    unsigned int resource_len;

    ret = dcmi_get_card_list(&card_num, card_id_list, MAX_CARD_NUM);
    if (ret != DCMI_OK) {
        printf("Failed to get card number.\n");
        return ret;
    }

    for (num_id = 0; num_id < card_num; num_id++) {
        resource_len = sizeof(soc_total_resource);
        ret = dcmi_get_device_info(card_id_list[num_id], 0, DCMI_MAIN_CMD_VDEV_MNG,
        DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE, &soc_total_resource, &resource_len);
        if (ret != DCMI_OK) {
            gplog(LOG_INFO, "get total resource failed. ret is %d", ret);
            continue;
        }
        vdev_num = (int)soc_total_resource.vdev_num;
        gplog(LOG_INFO, "vdev_num = %d. ret is %d", vdev_num, ret);
        for (vnum_id = 0; vnum_id < vdev_num; vnum_id++) {
            gplog(LOG_INFO, "vdev_id = %u.", soc_total_resource.vdev_id[vnum_id]);
            if (vnpu_id == (int)(soc_total_resource.vdev_id[vnum_id])) {
                return NPU_OK;
            }
        }
    }

    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_card_reset_vnpu(struct npu_smi_operate_info *operate_info)
{
    int ret;
    if ((dcmi_check_run_in_docker() && dcmi_check_run_not_root()) || dcmi_check_run_in_vm()) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical"\
        " or privileged docker can call this api.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    if (!dcmi_board_chip_type_is_ascend_910b()) {
        gplog(LOG_OP, "This device does not support hot reset vnpu.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    ret = show_reset_vnpu_risk();
    if (ret != NPU_OK) {
        gplog(LOG_OP, "User aborts reset-vnpu.");
        return ret;
    }
    printf("\t%-30s : %s\n", "Message", "resetting ...");
    // 不对外暴露dcmi接口，在此处直接调用dsmi接口复位vnpu
    dcmi_npu_msn_env_clean(operate_info->id);
    ret = dcmi_to_npu_error_code(dsmi_hot_reset_soc(operate_info->id));
    if (ret != NPU_OK) {
        gplog(LOG_OP, "set_vnpu_reset_vnpu failed, ret is %d", ret);
        gplog(LOG_ERR, "call dsmi_hot_reset_soc failed, ret is %d.", ret);
    } else {
        gplog(LOG_OP, "set_vnpu_reset_vnpu success, vdev_id is %d", operate_info->id);
    }
    print_reset_result(ret, VNPU_SET, operate_info);
    return ret;
}


int reset_vnpu_para_check(struct npu_smi_operate_info *operate_info)
{
    unsigned int env_flag;
    int ret;

    ret = dcmi_get_environment_flag(&env_flag);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    if ((env_flag != ENV_PHYSICAL) && (env_flag != ENV_PHYSICAL_PRIVILEGED_CONTAINER)) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (npu_check_vdev_id(operate_info->id) != NPU_OK) {
        printf("Invalid vnpu id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

int set_card_cpu_freq_up_cfg(struct npu_smi_operate_info *operate_info)
{
    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;
    char enable_value[CPU_FREQ_UP_CONFIG_LEN] = {0};

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    if (!dcmi_board_chip_type_is_ascend_310p_300v()) {
        gplog(LOG_ERR, "board_type is not 310p 300v and does not support set cpu freq.");
        printf("This device does not support set cpu freq.\n");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == 0) {
        printf("[WARNING]: CPU Frequency up will raise the safety risks.\n");
    }

    ret = memcpy_s(&enable_value, sizeof(enable_value), &operate_info->enable_value, sizeof(int));
    if (ret != EOK) {
        gplog(LOG_ERR, "call memcpy_s failed.%d", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_device_user_config(operate_info->id, chip_id, "set_cpu_freq",
            sizeof(enable_value), enable_value);
        if (ret != NPU_OK) {
            print_cpu_freq_up_result(ret, CARD_SET, operate_info);
            gplog(LOG_OP, "Set the CPU frequency for card%d failed. enable_flag=%d.", operate_info->id,
                operate_info->enable_value);
            return dcmi_to_npu_error_code(ret);
        }
    }

    print_cpu_freq_up_result(NPU_OK, CARD_SET, operate_info);
    gplog(LOG_OP, "Set the CPU frequency for card%d success. enable_flag=%d.", operate_info->id,
        operate_info->enable_value);
    return NPU_OK;
}

int set_card_custom_op(struct npu_smi_operate_info *operate_info)
{
    bool check_result = (npu_check_is_has_d_chip() == FALSE);
    if (check_result) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int ret, chip_id;
    if (operate_info->enable_value) {
        ret = show_custom_op_risk();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_device_info(operate_info->id, chip_id, DCMI_MAIN_CMD_SOC_INFO, DCMI_SOC_INFO_SUB_CMD_CUSTOM_OP,
            &operate_info->enable_value, sizeof(int));
        if (ret != DCMI_OK) {
            ret = dcmi_to_npu_error_code(ret);
            print_result(ret, operate_info, CARD_SET, FALSE);
            gplog(LOG_OP, "Set custom op for card%d failed. enable_flag=%d.", operate_info->id,
                operate_info->enable_value);
            return ret;
        }
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s is set successfully.\n", "Message", operate_info->stype);
    gplog(LOG_OP, "Set custom_op for card%d success. enable_flag=%d.", operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_card_custom_op_secverify_enable(struct npu_smi_operate_info *operate_info)
{
    int ret, chip_id;
    int npu_count = 0, mcu_id = 0, cpu_id = 0;
    unsigned char new_enable;

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value == 1) {
        ret = show_custom_op_secverify_enable_risk();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    new_enable = (operate_info->enable_value == 0) ? 0 : 1;
    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        ret = dcmi_set_custom_op_secverify_enable(operate_info->id, chip_id, "sign_auth_enable",
            &new_enable, sizeof(new_enable));
        if (ret != DCMI_OK) {
            ret = dcmi_to_npu_error_code(ret);
            print_result(ret, operate_info, CARD_SET, FALSE);
            gplog(LOG_ERR, "Set custom op secverify enable for card%d failed. (chip_id=%d, enable_flag=%d).",
                operate_info->id, chip_id, operate_info->enable_value);
            return ret;
        }
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s is set successfully.\n", "Message", operate_info->stype);
    gplog(LOG_OP, "Set custom_op_secverify_enable for card%d success. enable_flag=%d.",
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_card_custom_op_secverify_mode(struct npu_smi_operate_info *operate_info)
{
    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;
    unsigned char enable = 0;
    unsigned char enable_bitmap = 0;

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
        enable = 0;
        ret = dcmi_get_custom_op_secverify_enable(operate_info->id, chip_id, &enable);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "failed to query custom_op_secverify_enable. err is %d.\n", ret);
            return dcmi_to_npu_error_code(ret);
        }
        if (enable != 1) {
            continue;
        }
        enable_bitmap |= (1 << chip_id);
        ret = dcmi_set_custom_op_secverify_mode(operate_info->id, chip_id, &operate_info->enable_value, sizeof(int));
        if (ret != DCMI_OK) {
            ret = dcmi_to_npu_error_code(ret);
            print_result(ret, operate_info, CARD_SET, FALSE);
            gplog(LOG_ERR, "Set custom op secverify mode for card%d failed. (chip_id=%d, enable_flag=%d).",
                operate_info->id, chip_id, operate_info->enable_value);
            return ret;
        }
    }
    if (enable_bitmap == 0) {
        printf("Need set custom-op-secverify-enable as True first on a physical machine.\n");
        gplog(LOG_INFO, "failed to check custom-op-secverify-enable first.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s is set successfully.\n", "Message", operate_info->stype);
    gplog(LOG_OP, "Set custom-op-secverify-mode for card%d success. (mode_flag=%d.)",
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_card_custom_op_secverify_cert(struct npu_smi_operate_info *operate_info)
{
    int ret, device_count, i;
    int mcu_id = NPU_DEFAULT_VALUE;
    int cpu_id = NPU_DEFAULT_VALUE;
    struct npu_smi_operate_info tmp_npu_intf = { 0 };
 
    ret = npu_get_card_device_id(operate_info->id, &device_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to query chip count, ret=%d\n", ret);
        return ret;
    }

    tmp_npu_intf.id = operate_info->id;

    for (i = 0; i < device_count; i++) {
        tmp_npu_intf.chip_id = i;
        ret = strcpy_s(tmp_npu_intf.sdata, NPU_MAX_LENTH, operate_info->sdata);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "strcpy_s failed, ret=%d\n", ret);
            return ret;
        }
        ret = set_custom_op_secverify_cert(&tmp_npu_intf);
        if (ret != NPU_OK) {
            if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
                printf("This device does not support setting %s.\n", operate_info->stype);
            } else {
                printf("\t%-30s : %s\n", "Status", "Fail");
                printf("\t%-30s : Failed to set %s.\n", "Message", operate_info->stype);
            }
            return ret;
        }
        gplog(LOG_OP, "Set %s for card %d chip %d successfully.", operate_info->stype,
            operate_info->id, i);
        printf("\t%-30s : %s\n", "Status", "OK");
        printf("\t%-30s : The %s of the chip%d is set successfully.\n", "Message", operate_info->stype, i);
    }
    return ret;
}