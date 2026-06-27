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
#include <stdio.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "npu_error_code.h"
#include "npu_common.h"
#include "dcmi_log.h"
#include "dcmi_inner_cfg_manage.h"
#include "npu_set_print.h"
#include "npu_file_operate.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_product_judge.h"
#include "dcmi_hot_reset_intf.h"
#include "dcmi_inner_cfg_persist.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_environment_judge.h"
#include "dcmi_permission_judge.h"
#include "npu_chip_set_ext.h"

STATIC int reset_chip_inband(struct npu_smi_operate_info *operate_info)
{
    int ret;

    // 通过一个芯片获取对应类型
    dcmi_init_product_type_inner(operate_info->id, 0);
    ret = show_reset_risk();
    if (ret != NPU_OK) {
        gplog(LOG_OP, "User aborts reset.");
        return ret;
    }

    printf("\t%-30s : %s\n", "Message", "resetting ...");

    // NPU_A300I_A2_BIN2_BOARD_ID没有网口
    if (((npu_get_chip_type() == NPU_CHIP_910B) || (npu_get_chip_type() == NPU_CHIP_910_93)) &&
        !(dcmi_board_chip_type_is_ascend_910b_300i_a2())) {
        // 设置网口down标志位为1
        ret = npu_set_nic_down_flag(operate_info->id, NIC_DOWN_ENABLE);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "Failed to set device %d nic down flag to 1. errcode: %d.", operate_info->id, ret);
            return ret;
        }
    }
    // 热复位NPU芯片
#ifndef NPU_SMI_V2
    ret = dcmi_set_device_reset(operate_info->id, operate_info->chip_id, INBAND_CHANNEL);
#else
    ret = dcmiv2_reset_device(operate_info->id, INBAND_CHANNEL);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_set_device_reset failed. errcode: %d", ret);
        ret = dcmi_to_npu_error_code(ret);
        goto END;
    }

    // 获取NPU芯片热复位状态
    ret = get_chip_boot_status(operate_info->id, operate_info->chip_id);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get_chip_boot_status failed. errcode: %d", ret);
    }

END:
    if (((npu_get_chip_type() == NPU_CHIP_910B) || (npu_get_chip_type() == NPU_CHIP_910_93)) &&
        !(dcmi_board_chip_type_is_ascend_910b_300i_a2())) {
        // 设置网口down标志位为0
        ret = npu_set_nic_down_flag(operate_info->id, NIC_DOWN_DISABLE);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "Failed to set device %d nic down flag to 0. errcode: %d.", operate_info->id, ret);
            return ret;
        }
    }
    return ret;
}

STATIC int check_outband_channel_state(int card_id, int chip_id)
{
    int ret;
    int channel_state = 0;

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_outband_channel_state(card_id, chip_id, &channel_state);
#else
    ret = dcmiv2_get_device_outband_channel_state(chip_id, &channel_state);
#endif
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    if (ret != DCMI_OK || channel_state != CHANNEL_STATUS_SUCCESS) {
        printf("\nChip reset is not supported. Please check BMC version and IPMI driver.\n");
        printf("Please reboot OS to reset chip if there is no BMC.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }
    return NPU_OK;
}

STATIC int reset_chip_outband(struct npu_smi_operate_info *operate_info)
{
#ifdef _WIN32
    return NPU_ERR_CODE_NOT_SUPPORT_FOR_WIN;
#else
    int ret, fd;

    dcmi_init_product_type_inner(operate_info->id, 0);
    ret = show_reset_risk();
    if (ret != NPU_OK) {
        gplog(LOG_OP, "User aborts reset.");
        return ret;
    }

    ret = check_outband_channel_state(operate_info->id, operate_info->chip_id);
    if (ret != NPU_OK) {
        return ret;
    }

    printf("\t%-30s : %s\n", "Message", "resetting ...");

    if (npu_create_lock_file(FILE_PATH_FOR_RESETTING_MUTEX, FILE_NAME_FOR_RESETTING_MUTEX, &fd) != NPU_OK) {
        gplog(LOG_ERR, "reset_chip_outband creat lock file fail.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (npu_set_file_lock(fd, MAX_WAIT_TIME_FOR_RESETTING_A_MUTEX) != NPU_OK) {
        printf("Another user is resetting the NPU(s). Please try again later.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = reset_operation_with_v2(operate_info);
    if (ret != DCMI_OK) {
        goto OUT;
    }

    /* 重新扫描的操作只是触发驱动启动扫描，这里等待2秒 */
    sleep(2);
OUT:
    npu_set_file_unlock(fd);
    return dcmi_to_npu_error_code(ret);
#endif
}

STATIC int get_smp_device_boot_status()
{
    int ret;
    int retry_time = BOOT_STATUS_RETRY_TIME;
    enum dcmi_boot_status boot_status = DCMI_BOOT_STATUS_UNINIT;
    unsigned int boot_status_flag = 0;
    unsigned int boot_status_finish_flag = 0;
    unsigned int i;
    int card_id_list[MAX_CARD_NUM] = {0};
    int card_num = 0;

    ret = dcmi_get_card_list(&card_num, card_id_list, MAX_CARD_NUM);
    if (ret != DCMI_OK) {
        printf("Failed to get card number.\n");
        return dcmi_to_npu_error_code(ret);
    }
    /* 复位状态结束标志，兼容4P和8P形态 */
    for (i = 0; i < (unsigned int)card_num; i++) {
        boot_status_finish_flag |= (1 << i);
    }

    while (retry_time--) {
        if (boot_status_flag == boot_status_finish_flag) {
            break;
        }

        for (i = 0; i < (unsigned int)card_num; i++) {
            ret = dcmi_get_device_boot_status(card_id_list[i], 0, &boot_status);
            if (ret != DCMI_OK) {
                continue;
            }

            if (boot_status == DCMI_SYSTEM_START_FINISH) {
                boot_status_flag |= (1 << i);
            }
        }
        sleep(3); // 延时3s
    }

    if (retry_time == -1) {
        gplog(LOG_ERR, "device reboot timeout, boot status flag is %d", boot_status_flag);
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

static void print_reset_message()
{
    size_t index, table_size;

    struct npu_reset_time_table chip_reset_time_table[] = {
        {DCMI_A900_A3_SUPERPOD_MAIN_BOARD_ID1, 360},
        {DCMI_A900_A3_SUPERPOD_MAIN_BOARD_ID2, 360},
        {DCMI_A_K_910_93_MAIN_BOARD_ID, 360},
        {Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID1, 200},
        {Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID2, 200},
        {DCMI_A_X_910_93_MAIN_BOARD_ID, 200},
    };
    
    table_size = sizeof(chip_reset_time_table) / sizeof(chip_reset_time_table[0]);
    if (dcmi_get_product_type_inner() == DCMI_A900_A3_SUPERPOD) {
        for (index = 0; index < table_size; index++) {
            if (dcmi_get_maindboard_id_inner() == chip_reset_time_table[index].mainboard_id) {
                printf("\t%-30s : %s %u %s\n", "Message", "resetting (about",
                    chip_reset_time_table[index].reset_time, "seconds) ...");
            }
        }
    } else if (dcmi_get_product_type_inner() == DCMI_A200T_BOX_A1) {
        printf("\t%-30s : %s\n", "Message", "resetting (about 260 seconds) ...");
    } else {
        printf("\t%-30s : %s\n", "Message", "resetting (about 150 seconds) ...");
    }
}

STATIC int npu_board_hot_reset()
{
    int ret, i;
    int card_id_list[MAX_CARD_NUM] = {0};
    int card_num = 0;

    ret = dcmi_get_card_list(&card_num, card_id_list, MAX_CARD_NUM);
    if (ret != DCMI_OK) {
        printf("Failed to get card number.\n");
        return dcmi_to_npu_error_code(ret);
    }

    print_reset_message();

    dcmi_npu_msn_env_clean(-1);

    // 关闭网络
    if (dcmi_is_in_phy_machine()) {
        for (i = 0; i < card_num; i++) {
            ret = npu_set_nic_down_flag(card_id_list[i], NIC_DOWN_ENABLE);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "Failed to set device %d nic down flag to 1. errcode: %d.", card_id_list[i], ret);
                goto END;
            }
        }
    }

    // 热复位NPU板
    ret = dcmi_set_all_npu_hot_reset();
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to reset device%d-%d. errcode: %d.", card_id_list[0], card_id_list[card_num - 1], ret);
        ret = dcmi_to_npu_error_code(ret);
        goto END;
    }

    // 获取NPU板热复位状态
    ret = get_smp_device_boot_status();
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to get device%d-%d boot status. errcode: %d.", card_id_list[0],
            card_id_list[card_num - 1], ret);
    }

END:
    if (dcmi_is_in_phy_machine()) {
        for (i = 0; i < card_num; i++) {
            ret = npu_set_nic_down_flag(card_id_list[i], NIC_DOWN_DISABLE);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "Failed to set device %d nic down flag to 0. errcode: %d.", card_id_list[i], ret);
            }
        }
    }
    return ret;
}

STATIC int reset_server_smp_nophy(struct npu_smi_operate_info *operate_info)
{
    int ret;

    printf("\t%-30s : %s\n", "Message", "resetting ...");

    // 热复位NPU芯片
    ret = dcmi_set_device_reset(operate_info->id, operate_info->chip_id, INBAND_CHANNEL);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Resetting npu board fail.%d.", ret);
        ret = dcmi_to_npu_error_code(ret);
        return ret;
    }

    // 获取NPU芯片热复位状态
    ret = get_chip_boot_status(operate_info->id, operate_info->chip_id);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get_chip_boot_status failed. errcode: %d", ret);
    }

    return ret;
}

STATIC int reset_server_smp_phy()
{
    int ret;

    ret = npu_board_hot_reset();
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Resetting npu board fail.%d.", ret);
        return ret;
    }

    return NPU_OK;
}

STATIC int check_smp_mode_confirm_info()
{
    int ret;
    printf("It's SMP mode, it will reboot all devices%s, do you want to continue reboot? [y/n]\n",
        (dcmi_is_in_phy_machine() == FALSE) ? " in this SMP system" : "");
    ret = check_confirm_info();
    if (ret != NPU_OK) {
        if (ret == NPU_ERR_CODE_ABORT_OPERATE) {
            gplog(LOG_OP, "User aborts reset.");
        } else {
            gplog(LOG_ERR, "check_confirm_info failed. errcode: %d", ret);
        }
        return ret;
    }
    return ret;
}

STATIC int check_amp_hccs_on_mode_confirm_info()
{
    int ret;

    printf("It's AMP mode, but hccs is on, it will reboot all devices, do you want to continue reboot? [y/n]\n");
    ret = check_confirm_info();
    if (ret != NPU_OK) {
        if (ret == NPU_ERR_CODE_ABORT_OPERATE) {
            gplog(LOG_OP, "User aborts reset.");
        } else {
            gplog(LOG_ERR, "check_confirm_info failed. errcode: %d", ret);
        }
        return ret;
    }

    return ret;
}

STATIC int reset_server_amp_all_device()
{
    int ret;

    ret = npu_board_hot_reset();
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Resetting npu board fail.%d.", ret);
        return ret;
    }

    return NPU_OK;
}

STATIC int reset_server_amp_nophy(struct npu_smi_operate_info *operate_info)
{
    int ret;

    ret = show_reset_risk();
    if (ret != NPU_OK) {
        gplog(LOG_OP, "User aborts reset.");
        return ret;
    }

    // 虚拟机下，不关网络
    ret = reset_server_smp_nophy(operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Resetting npu chip inband fail.%d.", ret);
        return ret;
    }

    return NPU_OK;
}

STATIC int reset_server_amp_hccs(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int hccs_status;

    ret = dcmi_get_hccs_status(operate_info->id, operate_info->chip_id, &hccs_status);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Get hccs status fail.%d.", ret);
        return ret;
    }
    if (hccs_status == HCCS_OFF) {
        // hccs全断，可以进行单P复位
        if (dcmi_is_in_phy_machine()) {
            ret = reset_chip_inband(operate_info);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "Resetting npu chip inband fail.%d.", ret);
                return ret;
            }
        } else {
            ret = reset_server_amp_nophy(operate_info);
            if (ret != NPU_OK) {
                return ret;
            }
        }
    } else {
        ret = show_reset_risk();
        if (ret != NPU_OK) {
            gplog(LOG_OP, "User aborts reset.");
            return ret;
        }
        // 增加打印-由于hccs并没有全部断开，需要对所有芯片一起复位。
        ret = check_amp_hccs_on_mode_confirm_info();
        if (ret != NPU_OK) {
            return ret;
        }
        // 全部一起复位（包括没有hccs互联的device）
        ret = reset_server_amp_all_device();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    return NPU_OK;
}

STATIC int reset_server_handle_smp(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (!dcmi_is_in_phy_machine()) {
        ret = reset_server_smp_nophy(operate_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "Resetting npu chip inband fail.%d.", ret);
            return ret;
        }
    } else {
        ret = reset_server_smp_phy();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    return NPU_OK;
}

STATIC int reset_server_handle_amp(struct npu_smi_operate_info *operate_info)
{
    int ret;

    // 910B虽然为AMP但存在HCCS互联关系，需要单独处理（HCCS全断才能单片复位）
    if (npu_get_chip_type() == NPU_CHIP_910B) {
        ret = reset_server_amp_hccs(operate_info);
        if (ret != NPU_OK) {
            return ret;
        }
    } else if (npu_get_chip_type() == NPU_CHIP_910_93) {
        ret = show_reset_risk();
        if (ret != NPU_OK) {
            gplog(LOG_OP, "User aborts reset.");
            return ret;
        }
        // 910_93临时走全片复位
        ret = reset_server_amp_all_device();
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "Resetting all npu chip inband fail.%d.", ret);
            return ret;
        }
    } else if (dcmi_board_chip_type_is_ascend_950() &&
        operate_info->chan_src == OUTBAND_CHANNEL) {
        if (dcmi_board_chip_type_is_ascend_950_pod() || dcmi_board_chip_type_is_ascend_950_server()) {
            ret = reset_chip_outband(operate_info);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "Resetting npu chip outband fail.%d.", ret);
                return ret;
            }
        } else {
            gplog(LOG_OP, "The device does not support out-band reset.");
            return DCMI_ERR_CODE_NOT_SUPPORT;
        }
    } else {
        ret = reset_chip_inband(operate_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "Resetting npu chip inband fail.%d.", ret);
            return ret;
        }
    }
    return NPU_OK;
}

STATIC int reset_server(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned char workMode = NPU_AMP_WORK_MODE;

    if ((npu_get_chip_type() == NPU_CHIP_910B) || (npu_get_chip_type() == NPU_CHIP_910_93)
        || (npu_get_chip_type() == NPU_CHIP_950)) {
        // 910B本来就是AMP模式的，只是因为有HCCS互联，所以需要判断是否需要全部一起复位
        // 910_93是SMP模式，但是并非是0xFF复位所有device，而是复位单chip下的2个device
        workMode = NPU_AMP_WORK_MODE;
    } else {
        ret = dcmi_get_npu_work_mode(operate_info->id, &workMode);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to get npu work mode. errcode: %d", ret);
            return dcmi_to_npu_error_code(ret);
        }
    }

    // NPU为SMP模式时需以SMP系统为单位一起复位
    if (workMode == NPU_SMP_WORK_MODE) {
        ret = show_reset_risk();
        if (ret != NPU_OK) {
            gplog(LOG_OP, "User aborts reset.");
            return ret;
        }

        ret = check_smp_mode_confirm_info();
        if (ret != NPU_OK) {
            return ret;
        }

        ret = reset_server_handle_smp(operate_info);
        if (ret != NPU_OK) {
            return ret;
        }
    } else {
        ret = reset_server_handle_amp(operate_info);
        if (ret != NPU_OK) {
            return ret;
        }
    }

    return NPU_OK;
}

STATIC int check_reset_hccs_support()
{
    int log_type;
    const char *reset_hccs_support_str[] = {"This command cannot be executed on a common container",
        "This command cannot be executed on a common container or a VM privileged container"};

    if ((npu_get_chip_type() != NPU_CHIP_910B) && (npu_get_chip_type() != NPU_CHIP_910_93)
        && (npu_get_chip_type() != NPU_CHIP_950)) {
        return NPU_OK;
    }

    if (dcmi_is_in_phy_machine() || npu_is_in_virtual_machine()) {
        return NPU_OK;
    }

    log_type = npu_get_chip_type() == NPU_CHIP_910B ? 0 : 1;
    // 如果为容器环境，必须为特权容器
    if (npu_is_in_docker() && dcmi_check_a2_a3_a5_device_reset_docker_permission() != DCMI_OK) {
        printf("%s.\n", reset_hccs_support_str[log_type]);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    return NPU_OK;
}

STATIC int reset_card(struct npu_smi_operate_info *operate_info)
{
    int ret = 0;
    int chip_type = npu_get_chip_type();
    if (operate_info->chan_src == INBAND_CHANNEL) {
        if ((npu_board_type_is_card() == TRUE) && (chip_type == NPU_CHIP_910B) &&
            (npu_is_run_in_vm_or_docker() == TRUE)) {
            // 910B标卡在容器和虚拟机场景不支持热复位
            printf("This command cannot be executed on a VM or container.\n");
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
        if ((npu_board_type_is_card() == TRUE && chip_type == NPU_CHIP_950) &&
            (npu_is_run_in_vm_or_docker() == TRUE && dcmi_is_in_phy_privileged_docker_root() == FALSE)) {
            // 950标卡仅在物理机和特权容器支持热复位
            printf("This command cannot be executed on a VM or container.\n");
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
        ret = reset_chip_inband(operate_info);
    } else {
        if (npu_is_in_docker()) {
            printf("This command cannot be executed on a container.\n");
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
        if (npu_is_in_virtual_machine()) {
            printf("This command cannot be executed on a VM.\n");
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
        ret = reset_chip_outband(operate_info);
    }
    return ret;
}

STATIC int set_chip_reset_check_permission(struct npu_smi_operate_info *operate_info)
{
    int ret = 0;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    // 通过一个芯片获取对应类型
    dcmi_init_product_type_inner(operate_info->id, 0);

    if (dcmi_check_device_reset_vnpu_mode(operate_info->id) == DCMI_OK) {
        // 算力切分场景下，不支持该命令
        printf("In the vNPU scenario, this device does not support setting %s.\n", operate_info->stype);
        gplog(LOG_OP, "In the vNPU scenario, this device does not support setting %s, card=%d.",
            operate_info->stype, operate_info->id);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
#else
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type != NPU_TYPE || ((npu_board_type_is_model() == TRUE) &&
        (operate_info->chan_src == OUTBAND_CHANNEL))) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

#ifdef _WIN32
    if (npu_board_type_is_card() != TRUE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#endif

    if ((dcmi_board_type_is_310p_duo_chips() == TRUE) && (operate_info->chip_id > 0)) {
        printf("SMP mode only support reset chip 0.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    // 910_93不支持虚拟机内热复位
    if ((npu_get_chip_type() == NPU_CHIP_910_93) && (npu_is_in_virtual_machine() == TRUE)) {
        printf("This command cannot be executed on a VM.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return NPU_OK;
}

int set_chip_reset(struct npu_smi_operate_info *operate_info)
{
    int ret, msn_recover_ret;

    ret = set_chip_reset_check_permission(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    if (npu_board_type_is_server() == TRUE) {
        ret = check_reset_hccs_support();
        if (ret != NPU_OK) {
            return ret;
        }
        ret = reset_server(operate_info);
        print_reset_result(ret, SERVER_SET, operate_info);
    } else {
        ret = reset_card(operate_info);
        if (ret == NPU_ERR_CODE_NOT_SUPPORT || ret == NPU_ERR_CODE_OPER_NOT_PERMITTED) {
            return ret;
        }
        print_reset_result(ret, CHIP_SET, operate_info);
    }

    if (!npu_is_in_docker()) {
        msn_recover_ret = npu_msn_log_cfg_recover(operate_info->id);
        if (msn_recover_ret != NPU_OK) {
            gplog(LOG_ERR, "Failed to recover msn(ret=%d).", msn_recover_ret);
        }
    }
    return ret;
}

int set_chip_ssh_enable(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. ret is %d", ret);
        print_ssh_result(ret, CHIP_SET, operate_info);
        return dcmi_to_npu_error_code(ret);
    }

    // 310p双芯片卡为SMP模式，不支持设置单个芯片的ssh使能状态
    bool check_result = (dcmi_board_type_is_310p_duo_chips() || (device_type != NPU_TYPE));
    if (check_result) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    char enable_value = (char)operate_info->enable_value;
    if (enable_value == 1) {
        printf("[WARNING]: Enabling SSH will raise the safety risks.\n");
    }
    ret = dcmi_set_device_user_config(operate_info->id, operate_info->chip_id, "ssh_status", 1, &enable_value);
    print_ssh_result(ret, CHIP_SET, operate_info);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set the SSH function for chip%d of card%d failed. enable_flag=%d.", operate_info->chip_id,
            operate_info->id, operate_info->enable_value);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "Set the SSH function for chip%d of card%d success. enable_flag=%d.", operate_info->chip_id,
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_chip_boot_area(struct npu_smi_operate_info *operate_info)
{
    if (npu_board_type_is_station() == FALSE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    int ret = dcmi_switch_boot_area(operate_info->id, operate_info->chip_id);
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set the boot-area for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "Set the boot-area for chip%d of card%d success.", operate_info->chip_id, operate_info->id);
    return NPU_OK;
}

int set_chip_mcu_monitor(struct npu_smi_operate_info *operate_info)
{
    if (npu_board_type_is_station() == FALSE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int ret;
    ret = dcmi_mcu_set_monitor_enable(operate_info->id, operate_info->chip_id, operate_info->enable_value);
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set the mcu-monitor for chip%d of card%d failed. enable_flag=%d.", operate_info->chip_id,
            operate_info->id, operate_info->enable_value);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "Set the mcu-monitor for chip%d of card%d success. enable_flag=%d.", operate_info->chip_id,
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_chip_err_count_clear(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
    if (npu_check_is_has_pcie() == FALSE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = check_support_err_count_clear(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_set_device_clear_pcie_error(operate_info->id, operate_info->chip_id);
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "clear pcie error count for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "clear pcie err count for chip%d of card%d success.", operate_info->chip_id, operate_info->id);
    return NPU_OK;
#else
    printf("This device does not support setting %s.\n", operate_info->stype);
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int set_chip_share(struct npu_smi_operate_info *operate_info)
{
    int ret = 0;
    bool check_result = (npu_check_is_has_d_chip() == FALSE);
    if (check_result) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_board_chip_type_is_ascend_910_93()) {
        ret = show_device_share_risk_for_chip();
    } else if (operate_info->enable_value) {
        ret = show_device_share_risk();
    }
 
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_set_device_info(operate_info->id, operate_info->chip_id, DEVICE_SHARE_MAIN_CMD, DEVICE_SHARE_SUB_CMD,
        &operate_info->enable_value, sizeof(int));
    if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
        printf("Operation not permitted, only root user on physical machine or on physical privilege container "
               "can call this api.\n");
    }
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "config device share for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }

    if (npu_board_type_is_station() == TRUE || dcmi_get_product_type_inner() == DCMI_A500_A2) {
        update_minid_conf("device_share", operate_info->enable_value);
    }

    gplog(LOG_OP, "Set device share for chip%d of card%d success. enable_flag=%d.", operate_info->chip_id,
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

STATIC int set_nve_level_for_310(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char enable_value = (char)operate_info->enable_value;

    ret = dcmi_set_device_user_config(operate_info->id, operate_info->chip_id, "set_nve_level", 1, &enable_value);
    print_result(ret, operate_info, CHIP_SET, TRUE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "config nve level for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "config nve level %d for chip%d of card%d success.", operate_info->enable_value,
        operate_info->chip_id, operate_info->id);
    return NPU_OK;
}

STATIC int set_nve_level_for_310b(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    DCMI_LP_WORK_TOPS_STRU work_tops_stru = { 0 };
    unsigned int work_tops_len = sizeof(work_tops_stru);

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type != NPU_TYPE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    work_tops_stru.work_tops = (unsigned int)operate_info->enable_value;
    work_tops_stru.is_in_flash = 1; // 持久化写入闪存标志

    ret = dcmi_set_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_LP,
        DCMI_LP_SUB_CMD_SET_WORK_TOPS, &work_tops_stru, work_tops_len);
    print_work_tops_result(ret, CHIP_SET, operate_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_set_device_info failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "config nve level %d for chip%d of card%d success.", operate_info->enable_value,
        operate_info->chip_id, operate_info->id);

    return dcmi_to_npu_error_code(ret);
}

int set_chip_nve_level(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (npu_board_type_is_soc() == FALSE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (npu_get_chip_type() == NPU_CHIP_310B) {
        ret = set_nve_level_for_310b(operate_info);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "set_nve_level_for_310b failed. err is %d.", ret);
        }
    } else {
        ret = set_nve_level_for_310(operate_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "set_nve_level_for_310 failed. err is %d.", ret);
        }
    }

    return ret;
}

STATIC int board_sec_revocation(int revo_type, unsigned char *revo_file, unsigned int file_len)
{
    int ret_temp, ret, i;
    int card_id_list[MAX_CARD_NUM] = {0};
    int card_num = 0;

    ret = dcmi_get_card_list(&card_num, card_id_list, MAX_CARD_NUM);
    if (ret != DCMI_OK) {
        printf("Failed to get card number.\n");
        return dcmi_to_npu_error_code(ret);
    }

    for (i = 0; i < card_num; i++) {
        ret_temp = dcmi_set_device_sec_revocation(card_id_list[i], 0, revo_type, revo_file, file_len);
        if (ret_temp != DCMI_OK) {
            printf("Revoking device %d certificate failed.\n", card_id_list[i]);
            gplog(LOG_ERR, "Revoking device %d certificate failed.%d.", card_id_list[i], ret);
            ret = ret_temp;
        }
    }

    return dcmi_to_npu_error_code(ret);
}

STATIC int npu_board_sec_revocation(struct npu_smi_operate_info *operate_info, int revo_type, unsigned char *revo_file,
    unsigned int file_len)
{
    int ret;
    unsigned char work_mode = NPU_AMP_WORK_MODE;

    // 910B获取工作模式存在问题，需手动判断，将910B工作模式写为AMP
    if ((npu_get_chip_type() == NPU_CHIP_910B) || (npu_get_chip_type() == NPU_CHIP_910_93)) {
        work_mode = NPU_AMP_WORK_MODE;
    } else {
        // 获取D板的工作模式，0:1P*4 1:4P
        ret = dcmi_get_npu_work_mode(operate_info->id, &work_mode);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to get npu work mode");
            return dcmi_to_npu_error_code(ret);
        }
    }
    // NPU为SMP模式时，需以SMP系统为单位一起执行密钥吊销
    if (work_mode == NPU_SMP_WORK_MODE) {
        printf("It's SMP mode, it will revoke all device's certificates, ");
        printf("do you want to continue revoke? [y/n]\n");
        ret = check_confirm_info();
        if (ret != NPU_OK) {
            if (ret == NPU_ERR_CODE_ABORT_OPERATE) {
                gplog(LOG_OP, "User aborts revocation.");
                return ret;
            }
            gplog(LOG_ERR, "check_confirm_info failed. errcode: %d", ret);
            return ret;
        }

        ret = board_sec_revocation(revo_type, revo_file, file_len);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "board_sec_revocation fail.");
            return ret;
        }
    } else {
        ret = dcmi_set_device_sec_revocation(operate_info->id, operate_info->chip_id, revo_type, revo_file, file_len);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_set_device_sec_revocation fail");
            return dcmi_to_npu_error_code(ret);
        }
    }

    return NPU_OK;
}

STATIC int sec_revocation(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int file_len = 0;
    enum dcmi_revo_type revo_type = DCMI_REVOCATION_TYPE_SOC;
    unsigned char revo_file[REVOCATION_FILE_LEN] = {0};

    ret = get_file_length((const char *)operate_info->file_path, &file_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "call get_file_length failed.%d.", ret);
        return ret;
    }

    if (file_len != REVOCATION_FILE_LEN) {
        printf("\t%-30s : file length(%u) is not equal to %d.\n", "Message", file_len, REVOCATION_FILE_LEN);
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = get_file_data((const char *)operate_info->file_path, revo_file, sizeof(revo_file), 0, REVOCATION_FILE_LEN);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "call get_file_data failed.%d.", ret);
        return ret;
    }

    if (npu_board_type_is_card() == TRUE) {
        ret = dcmi_set_device_sec_revocation(operate_info->id, operate_info->chip_id, revo_type, revo_file, file_len);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "call dcmi_set_device_sec_revocation failed.%d.", ret);
            return dcmi_to_npu_error_code(ret);
        }
    } else if (npu_board_type_is_server() == TRUE) {
        ret = npu_board_sec_revocation(operate_info, revo_type, revo_file, file_len);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "call npu_board_sec_revocation failed.%d.", ret);
            return ret;
        }
    } else {
        printf("This device does not support setting %s.\n", operate_info->stype);
    }

    return NPU_OK;
}

int set_chip_sec_revocation(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->file_path == NULL) {
        printf("This command must input file path.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((dcmi_board_chip_type_is_ascend_910_93()) && (operate_info->chip_id != 0)) {
        gplog(LOG_OP, "This product is only supported on chip 0.");
        printf("This device does not support setting %s.\n", operate_info->stype);
        free(operate_info->file_path);
        operate_info->file_path = NULL;
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = sec_revocation(operate_info);
    if (npu_board_type_is_card() == TRUE) {
        print_result(ret, operate_info, CHIP_SET, FALSE);
    } else if (npu_board_type_is_server() == TRUE) {
        print_result(ret, operate_info, SERVER_SET, FALSE);
    }

    if (ret == NPU_OK) {
        gplog(LOG_OP, "Set the revocation for chip%d of card%d success.", operate_info->chip_id, operate_info->id);
    } else {
        gplog(LOG_OP, "Set the revocation for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
    }

    free(operate_info->file_path);
    operate_info->file_path = NULL;
    return ret;
}

int set_disk_power(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int ret;
    ret = dcmi_mcu_set_disk_power(operate_info->id, operate_info->chip_id, operate_info->enable_value);
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set the disk power for card%d failed. chip_id=%d, enable_flag=%d.", operate_info->id,
            operate_info->chip_id, operate_info->enable_value);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "Set the disk power for card%d success. chip_id=%d, enable_flag=%d.", operate_info->id,
        operate_info->chip_id, operate_info->enable_value);
    return NPU_OK;
}

int check_ip_addr(unsigned int *ip_addr, int ip_max_len)
{
    int i;
    int all_zero = TRUE;
    int borad_cast = TRUE;
    for (i = 0; i < ip_max_len; i++) {
        if (ip_addr[i] > 0) {
            all_zero = FALSE;
        }
        if (ip_addr[i] > MAX_IP_VALUE) {
            return FALSE;
        }

        if (ip_addr[i] < MAX_IP_VALUE) {
            borad_cast = FALSE;
        }
    }
    if ((all_zero == TRUE) || (borad_cast == TRUE)) {
        /* 全0或者为广播地址 */
        return FALSE;
    }
    return TRUE;
}

int set_device_ip(struct npu_smi_operate_info *operate_info)
{
    int ret, i;
    struct dcmi_ip_addr ip_addr = { { { 0 } } };
    struct dcmi_ip_addr ip_mask = { { { 0 } } };
    unsigned int input_ip_addr[MAX_IP_LEN] = { 0 };
    unsigned int input_mask_addr[MAX_IP_LEN] = { 0 };
    const int OFFSET_0 = 0;
    const int OFFSET_1 = 1;
    const int OFFSET_2 = 2;
    const int OFFSET_3 = 3;

    /* 获取用户输入的IP地址及子网掩码 */
    ret = sscanf_s(operate_info->sdata, "%u.%u.%u.%u/%u.%u.%u.%u", &(input_ip_addr[OFFSET_0]),
        &(input_ip_addr[OFFSET_1]), &(input_ip_addr[OFFSET_2]), &(input_ip_addr[OFFSET_3]),
        &(input_mask_addr[OFFSET_0]), &(input_mask_addr[OFFSET_1]), &(input_mask_addr[OFFSET_2]),
        &(input_mask_addr[OFFSET_3]));
    if (ret != IP_AND_MASK_CNT) {
        printf("string format: XX.XX.XX.XX/XX.XX.XX.XX\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = check_ip_addr(input_ip_addr, MAX_IP_LEN);
    if (ret == FALSE) {
        printf("Invalid IP address.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = check_netmask_addr(input_mask_addr, MAX_IP_LEN);
    if (ret == FALSE) {
        printf("Invalid netmask.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = 0; i < MAX_IP_LEN; i++) {
        ip_addr.u_addr.ip4[i] = (unsigned char)input_ip_addr[i];
        ip_mask.u_addr.ip4[i] = (unsigned char)input_mask_addr[i];
    }

    ret = dcmi_set_device_ip(operate_info->id, operate_info->chip_id, DCMI_VNIC_PORT, 0, &ip_addr, &ip_mask);
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set the device ip for card%d failed. chip_id=%d, ipstr=%s.", operate_info->id,
            operate_info->chip_id, operate_info->sdata);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "Set the device ip for card%d success. chip_id=%d, ipstr=%s.", operate_info->id,
        operate_info->chip_id, operate_info->sdata);

    return NPU_OK;
}

STATIC int mac_addr_para_check(struct npu_smi_operate_info *operate_info)
{
    enum dcmi_unit_type device_type = NPU_TYPE;
    int ret;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        printf("This device does not support setting mac-addr.\n");
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
    if (device_type != NPU_TYPE) {
        printf("This device does not support setting mac-addr.\n");
        gplog(LOG_OP, "device_type %d is not support.", device_type);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    if (operate_info->enable_value < 0 || operate_info->enable_value >= MAC_ADDR_MAX_COUNT) {
        printf("Error parameter of -d\n");
        gplog(LOG_ERR, "Error parameter of -d\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if (strlen(operate_info->sdata) != MAC_ADDR_STRING_LEN) {
        printf("Error parameter of -s\n");
        gplog(LOG_ERR, "Error parameter of -s, string format: XX:XX:XX:XX:XX:XX\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

STATIC int mac_addr_string_check(struct npu_smi_operate_info *operate_info, char *mac_addr_string, int mac_addr_len)
{
    int ret, i;
    int count = 0;
    int mac_addr[MAC_ADDR_LEN] = { 0 };

    ret = sscanf_s((char *)operate_info->sdata, "%x:%x:%x:%x:%x:%x",
        &(mac_addr[MAC_ADDR_OFFSET0]), &(mac_addr[MAC_ADDR_OFFSET1]),
        &(mac_addr[MAC_ADDR_OFFSET2]), &(mac_addr[MAC_ADDR_OFFSET3]),
        &(mac_addr[MAC_ADDR_OFFSET4]), &(mac_addr[MAC_ADDR_OFFSET5]));
    if (ret != MAC_ADDR_LEN) {
        printf("Error parameter of -s\n");
        gplog(LOG_ERR, "Error parameter of -s, sscanf_s failed.ret=%d\n", ret);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    for (i = 0; i < MAC_ADDR_LEN; i++) {
        if (mac_addr[i] > 0xff || mac_addr[i] < 0) {
            printf("Error parameter of -s\n");
            gplog(LOG_ERR, "Error parameter of -s\n");
            return NPU_ERR_CODE_INVALID_PARAMETER;
        } else {
            mac_addr_string[i] = (char)mac_addr[i];
        }
    }

    for (i = 0; i < MAC_ADDR_LEN; i++) {
        if (mac_addr[i] == 0) {
            count++;
        }
    }
    if (count == i) {
        printf("Error parameter of -s\n");
        gplog(LOG_ERR, "Error parameter of -s, string format: XX:XX:XX:XX:XX:XX\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    count = 0;
    for (i = 0; i < MAC_ADDR_LEN; i++) {
        if (mac_addr[i] == 0xff) {
            count++;
        }
    }
    if (count == i) {
        printf("Error parameter of -s\n");
        gplog(LOG_ERR, "Error parameter of -s, string format: XX:XX:XX:XX:XX:XX\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

int set_chip_mac_addr(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char mac_addr_string[MAC_ADDR_LEN] = { 0 };

    ret = mac_addr_para_check(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = mac_addr_string_check(operate_info, mac_addr_string, MAC_ADDR_LEN);
    if (ret != NPU_OK) {
        return ret;
    }

    if (dcmi_board_chip_type_is_ascend_310b()) {
        ret = dcmi_set_device_mac(operate_info->id, operate_info->chip_id, operate_info->enable_value,
            mac_addr_string, sizeof(mac_addr_string));
        print_mac_addr_result(ret, operate_info);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Call dcmi_set_device_mac failed.%d\n", ret);
            return dcmi_to_npu_error_code(ret);
        }
        gplog(LOG_OP, "Set mac-addr succeeded.\n");
        return NPU_OK;
    } else {
        gplog(LOG_ERR, "This device does not support set mac-addr.%d\n", ret);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
}

int set_aicpu_config(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int ret;
    int aicpu_config[] = {0, 0, AI_CPU_CNT_2, 0, AI_CPU_CNT_4, 0, AI_CPU_CNT_6, 0};
    char aicpu_config_value = (char)aicpu_config[operate_info->enable_value];

    ret = dcmi_set_device_user_config(operate_info->id, operate_info->chip_id, "aicpu_config", sizeof(unsigned char),
        &aicpu_config_value);
    print_result(ret, operate_info, CHIP_SET, TRUE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "config aicpu for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "config aicpu %d for chip%d of card%d success.", operate_info->enable_value, operate_info->chip_id,
        operate_info->id);
    return NPU_OK;
}

int set_chip_ecc_info_clear(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type != NPU_CHIP_910 && chip_type != NPU_CHIP_910B &&
        chip_type != NPU_CHIP_910_93 && chip_type != NPU_CHIP_950) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#ifndef NPU_SMI_V2
    ret = dcmi_set_device_clear_ecc_statistics_info(operate_info->id, operate_info->chip_id);
#else
    ret = dcmiv2_clear_device_ecc_stats_info(operate_info->id);
#endif
    if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
        printf("In the vNPU scenario, this device does not support setting %s.\n", operate_info->stype);
        gplog(LOG_OP, "In the vNPU scenario, this device does not support setting %s.", operate_info->stype);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "clear ecc_info for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "clear ecc_info for chip%d of card%d success.", operate_info->chip_id, operate_info->id);
    return NPU_OK;
}

STATIC int check_create_vnpu_param(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct dcmi_soc_free_resource soc_free_resource = { 0 };
    struct dcmi_computing_template need_resource = { { 0 } };
    unsigned int resource_len = sizeof(soc_free_resource);

    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_VDEV_MNG,
        DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE, &soc_free_resource, &resource_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get free resource failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmi_get_template_info_by_name(operate_info->id, operate_info->vnpu_conf, &need_resource);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_template_info_by_name failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (need_resource.aicore_num > (unsigned int)soc_free_resource.computing.aic) {
        printf("Insufficient number of cores available, unallocated cores number:%f.\n",
            soc_free_resource.computing.aic);
        gplog(LOG_ERR, "insufficient number of cores available at card %d chip %d, need %u, remain %f",
            operate_info->id, operate_info->chip_id, need_resource.aicore_num,
            soc_free_resource.computing.aic);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if ((soc_free_resource.computing.device_aicpu != 0xffff) && // 不支持查询情景接口返回-1，无符号为0xffff
        (need_resource.aicpu_num > (unsigned int)soc_free_resource.computing.device_aicpu)) {
        printf("Insufficient number of AICPU available, unallocated AICPU number:%u.\n",
            soc_free_resource.computing.device_aicpu);
        gplog(LOG_ERR, "insufficient number of aicpu available at card %d chip %d, need %f, remain %u",
            operate_info->id, operate_info->chip_id, need_resource.aicpu_num,
            soc_free_resource.computing.device_aicpu);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    bool not_enough_resource = (need_resource.vpc > soc_free_resource.media.vpc) ||
        (need_resource.venc > soc_free_resource.media.venc) ||
        (need_resource.vdec > soc_free_resource.media.vdec) ||
        (need_resource.jpegd > soc_free_resource.media.jpegd) ||
        (need_resource.jpege > soc_free_resource.media.jpege);
    if (not_enough_resource && (npu_get_chip_type() == NPU_CHIP_310P || npu_get_chip_type() == NPU_CHIP_910B)) {
        printf("Insufficient number of DVPP available, unallocated DVPP number:\n");
        printf("VPC:%f, VENC:%f, VDEC:%f, JPEGD:%f, JPEGE:%f.\n", soc_free_resource.media.vpc,
            soc_free_resource.media.venc, soc_free_resource.media.vdec, soc_free_resource.media.jpegd,
            soc_free_resource.media.jpege);
        gplog(LOG_ERR, "insufficient number of DVPP available at card %d chip %d.",
            operate_info->id, operate_info->chip_id);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return NPU_OK;
}

static int set_dcmi_create_vdev_res(struct npu_smi_operate_info *operate_info,
    struct dcmi_create_vdev_res_stru *vdev)
{
    int ret;

    if (operate_info == NULL || vdev == NULL) {
        gplog(LOG_ERR, "operate_info or vdev is NULL.");
        return -1;
    }

    /* Querying the Current VNPU Configuration Status */
    ret = check_create_vnpu_param(operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "check_create_vnpu_param failed. err is %d", ret);
        return ret;
    }

    vdev->vfg_id = operate_info->vfg_id;
    vdev->vdev_id = operate_info->vnpu_id;

    ret = sscanf_s(operate_info->vnpu_conf, "%s", vdev->template_name, sizeof(vdev->template_name));
    if (ret != 1) {
        gplog(LOG_ERR, "sscanf_s failed, err is %d.", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    gplog(LOG_INFO, "vfg_id is %u, vdev_id is %u.", vdev->vfg_id, vdev->vdev_id);
    return NPU_OK;
}

int set_chip_create_vdevice_for_910B(struct npu_smi_operate_info *operate_info)
{
    struct dcmi_create_vdev_out out = { 0 };
    struct dcmi_create_vdev_res_stru vdev = { 0 };
    int ret;

    ret = set_dcmi_create_vdev_res(operate_info, &vdev);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_create_vdevice(operate_info->id, operate_info->chip_id, &vdev, &out);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "create vnpu failed. card_id = %d, device_id = %d", operate_info->id, operate_info->chip_id);
        printf("create vnpu failed.\n");
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "create vnpu success. card_id = %d, device_id = %d", operate_info->id, operate_info->chip_id);
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Create vnpu success\n", "Message");
    return ret;
}

int set_chip_create_vdevice_for_310P_910(struct npu_smi_operate_info *operate_info)
{
    struct dcmi_create_vdev_out out = { 0 };
    struct dcmi_create_vdev_res_stru vdev = { 0 };
    int ret;

    ret = set_dcmi_create_vdev_res(operate_info, &vdev);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_create_vdevice(operate_info->id, operate_info->chip_id, &vdev, &out);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "create vnpu failed. card_id = %d, device_id = %d", operate_info->id, operate_info->chip_id);
        printf("create vnpu failed.\n");
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "create vnpu success. card_id = %d, device_id = %d", operate_info->id, operate_info->chip_id);
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Create vnpu success\n", "Message");
    return ret;
}

int set_chip_create_vdevice(struct npu_smi_operate_info *operate_info)
{
    enum dcmi_unit_type device_type = INVALID_TYPE;
    int ret;

    ret = check_valid_set_operation_env(operate_info);
    if (ret != NPU_OK) {
        return NPU_OK;
    }

    ret = check_vdev_template_param(operate_info->vnpu_conf);
    if (ret != NPU_OK) {
        printf("Must input parameter of -f.\n");
        return ret;
    }

    ret = check_vnpu_docker_mode();
    if (ret != NPU_OK) {
        print_vnpu_mode_check_result(ret, operate_info);
        return NPU_OK;
    }

    ret = check_vnpu_workmode(operate_info);
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("NPU is working in SMP mode, does not support vnpu creation.\n");
        return ret;
    } else if (ret != NPU_OK) {
        printf("Failed to get npu work mode.\n");
        return ret;
    }

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type != NPU_TYPE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    switch (npu_get_chip_type()) {
        case NPU_CHIP_310P:
        case NPU_CHIP_910:
            ret = set_chip_create_vdevice_for_310P_910(operate_info);
            break;
        case NPU_CHIP_910B:
            ret = set_chip_create_vdevice_for_910B(operate_info);
            break;
        default:
            return NPU_ERR_CODE_NOT_SUPPORT;
    }
    return ret;
}

STATIC int get_valid_vdev_id(int *vdev_id, struct npu_smi_operate_info *operate_info)
{
    int ret;
    ret = str2int(vdev_id, operate_info->vnpu_conf);
    if (ret != NPU_OK) {
        return ret;
    }
    ret = check_vdev_exist(operate_info, *vdev_id);
    if (ret != NPU_OK) {
        printf("Error parameter of -v.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return NPU_OK;
}

int set_chip_destroy_vdevice_for_310P_910(struct npu_smi_operate_info *operate_info)
{
    int vdev_id = 0;
    int ret;

    ret = get_valid_vdev_id(&vdev_id, operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_set_destroy_vdevice(operate_info->id, operate_info->chip_id, vdev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "destroy vnpu failed. card_id = %d, device_id = %d vnpu_id = %d", operate_info->id,
            operate_info->chip_id, vdev_id);
        printf("destroy vnpu %d failed.\n", vdev_id);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "destroy vnpu success. card_id = %d, device_id = %d vnpu_id = %d", operate_info->id,
        operate_info->chip_id, vdev_id);

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Destroy vnpu %d success\n", "Message", vdev_id);
    return NPU_OK;
}

int set_chip_destroy_vdevice_for_910B(struct npu_smi_operate_info *operate_info)
{
    int vdev_id = 0;
    int ret;

    ret = get_valid_vdev_id(&vdev_id, operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_set_destroy_vdevice(operate_info->id, operate_info->chip_id, vdev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "destroy vnpu failed. card_id = %d, device_id = %d vnpu_id = %d", operate_info->id,
            operate_info->chip_id, vdev_id);
        printf("destroy vnpu %d failed.\n", vdev_id);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "destroy vnpu success. card_id = %d, device_id = %d vnpu_id = %d", operate_info->id,
        operate_info->chip_id, vdev_id);

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Destroy vnpu %d success\n", "Message", vdev_id);
    return NPU_OK;
}

int set_chip_destroy_vdevice(struct npu_smi_operate_info *operate_info)
{
    enum dcmi_unit_type device_type = NPU_TYPE;

    int ret = check_valid_set_operation_env(operate_info);
    if (ret != NPU_OK) {
        return NPU_OK;
    }

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type != NPU_TYPE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = check_vnpu_docker_mode();
    if (ret != NPU_OK) {
        print_vnpu_mode_check_result(ret, operate_info);
        return NPU_OK;
    }

    ret = check_vnpu_workmode(operate_info);
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("NPU is working in SMP mode, does not support vnpu creation.\n");
        return ret;
    } else if (ret != NPU_OK) {
        printf("Failed to get npu work mode.\n");
        return ret;
    }

    switch (npu_get_chip_type()) {
        case NPU_CHIP_310P:
        case NPU_CHIP_910:
            ret = set_chip_destroy_vdevice_for_310P_910(operate_info);
            break;
        case NPU_CHIP_910B:
            ret = set_chip_destroy_vdevice_for_910B(operate_info);
            break;
        default:
            return NPU_ERR_CODE_NOT_SUPPORT;
    }
    return ret;
}

int set_chip_vdevice_svm(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->vnpu_conf[NPU_V_PARAM_FLAG_INDEX] == 0) {
        printf("Must input parameter of -v.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (npu_get_chip_type() != NPU_CHIP_310P && npu_get_chip_type() != NPU_CHIP_910) {
        printf("This device does not support setting %s npu type is %d.\n", operate_info->stype, npu_get_chip_type());
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_set_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_SVM, DCMI_VNPU_SVM_SUB_CMD,
        &operate_info->vnpu_svm, sizeof(unsigned long int));
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "config device share for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "set device svm for chip%d of card%d success. svm: %lu.", operate_info->chip_id, operate_info->id,
        operate_info->vnpu_svm);

    return NPU_OK;
}

int set_chip_cpu_num_config(struct npu_smi_operate_info *operate_info)
{
    int ret, i;
    unsigned char cpu_num_config[DCMI_CPU_NUM_CFG_LEN] = {0};
    enum dcmi_unit_type device_type = INVALID_TYPE;
    int vnpu_cfg = DCMI_NO_EXIST_VNPU_CFG;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. ret is %d", ret);
        print_ssh_result(ret, CHIP_SET, operate_info);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type != NPU_TYPE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

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

    ret = dcmi_cfg_chip_exist_vnpu_config(operate_info->id, operate_info->chip_id, &vnpu_cfg);
    if ((ret == DCMI_OK) && (vnpu_cfg == DCMI_EXIST_VNPU_CFG)) {
        print_cpu_num_cfg_result(NPU_ERR_CODE_SECURE_FUN_FAIL, CHIP_SET, operate_info);
        gplog(LOG_OP, "Config cpu num for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return NPU_OK;
    }

    ret = dcmi_set_device_cpu_num_config(operate_info->id, operate_info->chip_id, cpu_num_config, DCMI_CPU_NUM_CFG_LEN);

    print_cpu_num_cfg_result(ret, CHIP_SET, operate_info);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Config cpu num for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "Config cpu num for chip%d of card%d success.", operate_info->chip_id, operate_info->id);
    return NPU_OK;
}
int set_p2p_mem_cfg_bar_cfg_off(struct npu_smi_operate_info *operate_info)
{
    int ret = dcmi_set_device_user_config(operate_info->id, operate_info->chip_id, "p2p_mem_cfg", P2P_MEM_CFG_SIZE,
        (char *)&operate_info->enable_value);
    print_p2p_mem_cfg_result(ret, CARD_SET, operate_info);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set the p2p-mem-cfg function of card%d failed. enable_flag=%d.",
            operate_info->id, operate_info->enable_value);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "Set the p2p-mem-cfg function of card%d success. enable_flag=%d.",
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_p2p_mem_cfg_bar_cfg_on(struct npu_smi_operate_info *operate_info)
{
    int ret = dcmi_clear_device_user_config(operate_info->id, operate_info->chip_id, "p2p_mem_cfg");
    print_p2p_mem_cfg_result(ret, CARD_SET, operate_info);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Set the p2p-mem-cfg function of card%d failed. enable_flag=%d.",
            operate_info->id, operate_info->enable_value);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "Set the p2p-mem-cfg function of card%d success. enable_flag=%d.",
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_chip_p2p_mem_cfg(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. ret is %d", ret);
        print_p2p_mem_cfg_result(ret, CHIP_SET, operate_info);
        return dcmi_to_npu_error_code(ret);
    }

    // 2P卡为SMP模式，不支持设置单个芯片的ssh使能状态
    bool check_result = (dcmi_board_type_is_310p_duo_chips() || (device_type != NPU_TYPE));
    if (check_result) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    } else if (operate_info->enable_value == BAR_CFG_ON) {
        ret = set_p2p_mem_cfg_bar_cfg_on(operate_info);
    } else {
        ret = set_p2p_mem_cfg_bar_cfg_off(operate_info);
    }

    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "set_chip_p2p_mem_cfg failed.\n");
        return ret;
    }
    return NPU_OK;
}

int set_power_state(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int fd = -1;
    struct pwm_info pwm_operate_info = { 0 };
    struct dcmi_power_state_info_stru power_info = {0};
    if (npu_get_chip_type() != NPU_CHIP_310B) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if (operate_info->enable_value < MIN_SLEEP_TIMES ||
        operate_info->enable_value > MAX_SLEEP_TIMES) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    pwm_operate_info.channel_num = PWM_CHANNEL;
    pwm_operate_info.ratio = 0;

    fd = open(DEV_PWM_NAME, O_WRONLY);
    if (fd == -1) {
        gplog(LOG_ERR, "open pwm dev failed.");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }
    ret = ioctl(fd, PWM_CMD_CLOSE_PWM_ENABLE, &pwm_operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "ioctl close pwm enable failed. err is %d", ret);
        close(fd);
        return NPU_ERR_CODE_IOCTL_FAIL;
    }
    close(fd);

    power_info.type = DCMI_POWER_STATE_SUSPEND;
    power_info.mode = DCMI_POWER_RESUME_MODE_TIME;
    power_info.value = (unsigned int)operate_info->enable_value;
    ret = dcmi_set_power_state(operate_info->id, operate_info->chip_id, power_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "set_sleep_state failed.\n");
        show_power_state_status(operate_info);
        return dcmi_to_npu_error_code(ret);
    }
    show_power_state_status(operate_info);
    return NPU_OK;
}

static int cert_file_read(char *file_set, unsigned int *cert_count, struct dcmi_certs_chain_data *certs_chain_data)
{
#ifndef _WIN32
    int ret;
    char seps[] = " ";
    unsigned int count = 1;
    char *seg = NULL;
    char *next_token = NULL;

    seg = strtok_s(file_set, seps, &next_token);
    if (seg == NULL) {
        gplog(LOG_ERR, "Call strtok_s failed.");
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = read_file_to_buf(seg, &certs_chain_data->data[0], NPU_CERT_MAX_SIZE, &certs_chain_data->data_len[0]);
    if (ret != NPU_OK) {
        return ret;
    }

    while (((seg = strtok_s(NULL, seps, &next_token)) != NULL) && count < MAX_CERT_COUNT) {
        ret = read_file_to_buf(seg, &certs_chain_data->data[count * NPU_CERT_MAX_SIZE], NPU_CERT_MAX_SIZE,
                               &certs_chain_data->data_len[count]);
        if (ret != NPU_OK) {
            return ret;
        }

        count++;
    };
    *cert_count = count;
    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

static int set_cert_inner_work(struct npu_smi_operate_info *operate_info, enum dcmi_main_cmd main_cmd,
                               unsigned int sub_cmd)
{
    int ret;
    unsigned int certs_size;
    struct dcmi_certs_chain_data *certs_chain_data = NULL;
    unsigned int cert_count = 0;

    certs_chain_data =  (struct dcmi_certs_chain_data *)calloc(1, sizeof(struct dcmi_certs_chain_data) +
                                                                        MAX_CERT_COUNT * NPU_CERT_MAX_SIZE);
    if (certs_chain_data == NULL) {
        gplog(LOG_ERR, "The certs_chain_data calloc failed.");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = cert_file_read(operate_info->sdata, &cert_count, certs_chain_data);
    if (ret != NPU_OK) {
        free(certs_chain_data);
        return ret;
    }
    certs_chain_data->count = cert_count;
    certs_size = sizeof(struct dcmi_certs_chain_data) + cert_count * NPU_CERT_MAX_SIZE;
#ifndef NPU_SMI_V2
    ret = dcmi_set_device_info(operate_info->id, operate_info->chip_id,
                               main_cmd, sub_cmd, (char *)certs_chain_data, certs_size);
#else
    ret = dcmiv2_set_device_info(operate_info->id, main_cmd, sub_cmd, (char *)certs_chain_data, certs_size);
#endif
    if (ret != DCMI_OK) {
        free(certs_chain_data);
        gplog(LOG_ERR, "Failed to set cert info. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
    free(certs_chain_data);
    return NPU_OK;
}

static void print_cert_set_status(struct npu_smi_operate_info *operate_info, int ret)
{
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    } else if (ret == NPU_ERR_CODE_PARTITION_NOT_RIGHT) {
        printf("The certificate does not match the CSR file of %s.\n", operate_info->stype);
        return;
    } else if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s.\n", "Message", operate_info->stype);
        return;
    }

    gplog(LOG_OP, "Set %s for card %d chip %d successfully.", operate_info->stype,
          operate_info->id, operate_info->chip_id);
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s of the chip is set successfully.\n", "Message", operate_info->stype);
    return;
}

STATIC int set_cert(struct npu_smi_operate_info *operate_info, enum dcmi_main_cmd main_cmd, unsigned int sub_cmd)
{
#ifndef _WIN32
    int ret;
#ifndef NPU_SMI_V2
    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b() ||
        dcmi_board_chip_type_is_ascend_310p()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#else
    operate_info->chip_id=0;
    if (!(dcmi_board_chip_type_is_ascend_950()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#endif
    if ((dcmi_board_type_is_310p_duo_chips() || dcmi_board_chip_type_is_ascend_910_93()) &&
        (operate_info->chip_id != 0)) {
        gplog(LOG_OP, "The Atlas 300I Duo card and 910_93 is only supported on chip 0.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = set_cert_inner_work(operate_info, main_cmd, sub_cmd);
    return ret;
#else
    gplog(LOG_OP, "unsupport set %s.", operate_info->stype);
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int set_user_config(unsigned int card_id, unsigned int device_id)
{
    int ret;
    unsigned char buf = DEFAULT_EXPIERD_THRESHOLD;
    unsigned char buf_size = sizeof(unsigned char);

#ifndef NPU_SMI_V2
    ret = dcmi_set_user_config(card_id, device_id, CERT_CONFIG_EXPIRED, buf_size, &buf);
#else
    ret = dcmiv2_set_device_user_config(device_id, CERT_CONFIG_EXPIRED, buf_size, (char*)&buf);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Set user config failed. (card_id=%u; device_id=%u; ret=%d)", card_id, device_id, ret);
        return ret;
    }
    return 0;
}

int set_tls_cert(struct npu_smi_operate_info *operate_info)
{
    int ret = set_cert(operate_info, DCMI_MAIN_CMD_EX_CERT, DCMI_CERT_SUB_CMD_TLS_CERT_INFO);
    print_cert_set_status(operate_info, ret);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to set cert, err is %d.", ret);
        return ret;
    }
    // 预置tls证书时新增默认过期阈值90天
    ret = set_user_config(operate_info->id, operate_info->chip_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to set user config, err is %d.", ret);
        return ret;
    }

    return ret;
}

int set_chip_boot_sel(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int boot_sel = 0xff;
    int retry_times = 0;

    if (dcmi_board_chip_type_is_ascend_310b() == FALSE) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_mcu_set_boot_sel(operate_info->id, operate_info->chip_id, operate_info->enable_value);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_mcu_set_boot_sel failed. err is %d", ret);
        goto FALIEUR;
    }

    while (retry_times++ < 3) {  // 重试3次
        sleep(1);  // 延时1s，等待MCU生效启动介质配置
        ret = dcmi_mcu_get_boot_sel(operate_info->id, operate_info->chip_id, &boot_sel);
        ret = (boot_sel == operate_info->enable_value) ? DCMI_OK : DCMI_ERR_CODE_INNER_ERR;
        if (ret == DCMI_OK) {
            break;
        }
    }

    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "boot_select set failed. set value %d, cur boot_select %d",
              operate_info->enable_value, boot_sel);
        goto FALIEUR;
    }

    print_bootsel_result(ret, CHIP_SET, operate_info);
    gplog(LOG_OP, "Set the boot_select for chip%d of card%d success. boot_select=%d.", operate_info->chip_id,
        operate_info->id, operate_info->enable_value);
    return NPU_OK;

FALIEUR:
    print_bootsel_result(ret, CHIP_SET, operate_info);
    gplog(LOG_OP, "Set the boot_select for chip%d of card%d failed. boot_select=%d.", operate_info->chip_id,
        operate_info->id, operate_info->enable_value);
    return dcmi_to_npu_error_code(ret);
}

int set_chip_custom_op(struct npu_smi_operate_info *operate_info)
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

    int ret;
    if (operate_info->enable_value) {
        ret = show_custom_op_risk();
        if (ret != NPU_OK) {
            return ret;
        }
    }

    ret = dcmi_set_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_SOC_INFO,
        DCMI_SOC_INFO_SUB_CMD_CUSTOM_OP, &operate_info->enable_value, sizeof(int));
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "config custom op for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "Set custom-op for chip%d of card%d success. enable_flag=%d.", operate_info->chip_id,
        operate_info->id, operate_info->enable_value);
    return NPU_OK;
}

int set_op_timeout(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct ts_dcmi_ctrl_msg_body_t ts_msg = {0};

    if (dcmi_check_run_in_docker() && !dcmi_check_run_in_privileged_docker()) {
        printf("This command cannot be executed on a container.");
        gplog(LOG_ERR, "op-timeout-cfg command cannot be executed on a container.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    ret = show_op_timeout_risk();
    if (ret != NPU_OK) {
        return ret;
    }

    ts_msg.msg_type = DCMI_TYPE_STARS_TASK_TIMEOUT_SET;
    ts_msg.u.set_task_timeout_info.timeout_limit_exp = (unsigned int)operate_info->enable_value;

    ret = dcmi_set_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_TS,
                               DCMI_TS_SUB_CMD_COMMON_MSG, &ts_msg, sizeof(ts_msg));

    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Set op-timeout for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "Set op-timeout for chip%d of card%d success. timeout exponent=%d.", operate_info->chip_id,
        operate_info->id, operate_info->enable_value);

    return NPU_OK;
}

int master_id_is_invalid(int data)
{
    return data >= QOS_MASTER_ID_MAX || data <= 0 || data == QOS_MASTER_ID_INVALID || data == QOS_MASTER_ID_AIC_DATA
        || data == QOS_MASTER_ID_AIV_DATA;
}

int qos_master_param_check(int param, int data)
{
    switch (param) {
        case QOS_MASTER:
            if (master_id_is_invalid(data)) {
                printf("Error parameter of master_id.\n");
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            break;
        case QOS_MPAMID:
            if (data < 0 || data > QOS_MASTER_MPAMID_MAX) {
                printf("Error parameter of mpamid.\n");
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            break;
        case QOS_QOS:
            if (data < 0 || data > QOS_MASTER_QOS_MAX) {
                printf("Error parameter of qos.\n");
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            break;
        case QOS_MODE:
            if (data != 0 && data != QOS_MASTER_MODE_MAX) {
                printf("Error parameter of mode.\n");
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
            break;
        default:
            break;
    }
    return NPU_OK;
}

int qos_master_para_parse(struct npu_smi_operate_info *operate_info, struct dcmi_qos_master_config *qos_cfg)
{
    int ret = 0;
    int argc = 0;
    char *str = operate_info->sdata;
    int tmp_mode = 0;

    while ((argc < QOS_MAX) && (*str != '\0')) {
        ret = 0;
        switch (argc) {
            case QOS_MASTER:
                ret += str2int(&(qos_cfg->master), str);
                ret += qos_master_param_check(argc, qos_cfg->master);
                break;
            case QOS_MPAMID:
                ret += str2int(&(qos_cfg->mpamid), str);
                ret += qos_master_param_check(argc, qos_cfg->mpamid);
                if (qos_cfg->master == QOS_MASTER_ID_PCIE && qos_cfg->mpamid >= 0x20) { // pcie模式下 mpamid为0到31
                    printf("Error parameter of mpamid.\n");
                    ret = NPU_ERR_CODE_INVALID_PARAMETER;
                }
                break;
            case QOS_QOS:
                ret += str2int(&(qos_cfg->qos), str);
                ret += qos_master_param_check(argc, qos_cfg->qos);
                break;
            case QOS_BITMAP_0:
            case QOS_BITMAP_1:
            case QOS_BITMAP_2:
            case QOS_BITMAP_3: // [0, 0xFFFFFFFFFFFFFFFF], 自动判断大小，不需要额外校验参数有效性
                ret = str2ull(&(qos_cfg->bitmap[argc - QOS_BITMAP_0]), str);
                if (ret != NPU_OK) {
                    printf("Error parameter of bitmap.\n");
                }
                break;
            case QOS_MODE:
                ret += str2int(&tmp_mode, str);
                ret += qos_master_param_check(argc, tmp_mode);
                qos_cfg->mode = (unsigned int)tmp_mode;
                break;
        }
        if (ret != NPU_OK) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
        str += strlen(str) + 1;
        argc++;
    }
    return NPU_OK;
}

int set_qos_master(struct npu_smi_operate_info *operate_info)
{
    int ret = 0;
    struct dcmi_qos_master_config qos_cfg = {0};
    if (operate_info == NULL) {
        gplog(LOG_ERR, "operate_info is NULL.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((!dcmi_is_in_phy_privileged_docker_root()) && (!dcmi_is_in_phy_machine_root())) {
        printf("Operation not permitted, only root user on physical machine or on physical privilege container can "
                "call this api.\n");
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine or on physical privilege container "
                "can call this api.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    ret = qos_master_para_parse(operate_info, &qos_cfg);
    if (ret != NPU_OK) {
        return ret;
    }

    if (!dcmi_board_chip_type_is_ascend_910_93()) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = show_qos_master_config_risk();
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_set_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_QOS,
                               DCMI_QOS_SUB_MASTER_CONFIG, &qos_cfg, sizeof(qos_cfg));
    print_result(ret, operate_info, CHIP_SET, FALSE);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "qos-master-config for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }

    gplog(LOG_OP, "Set qos-master-config for chip%d of card%d success. (master_id=%d, mpamid=%d, qos=%d, mode=%u)",
        operate_info->chip_id, operate_info->id, qos_cfg.master, qos_cfg.mpamid, qos_cfg.qos, qos_cfg.mode);
    return NPU_OK;
}

STATIC int custom_op_secverify_cert_file_read(char *file_set, unsigned int *cert_count, char *certs_chain_data)
{
#ifndef _WIN32
    int ret;
    char seps[] = " ";
    unsigned int cert_count_size = 0;
    char *seg = NULL;
    char *next_token = NULL;
    unsigned int data_len = 0;

    seg = strtok_s(file_set, seps, &next_token);
    if (seg == NULL) {
        gplog(LOG_ERR, "Call strtok_s failed.");
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = read_file_to_buf(seg, (unsigned char*)certs_chain_data, CUSTOM_OP_SECVERIFY_CERT_CHAIN_SIZE_MAX, &data_len);
    if (ret != NPU_OK) {
        return ret;
    }
    cert_count_size += data_len;
    while (((seg = strtok_s(NULL, seps, &next_token)) != NULL)
           && cert_count_size < CUSTOM_OP_SECVERIFY_CERT_CHAIN_SIZE_MAX) {
        ret = read_file_to_buf(seg, (unsigned char*)(certs_chain_data + cert_count_size),
                               CUSTOM_OP_SECVERIFY_CERT_CHAIN_SIZE_MAX, &data_len);
        if (ret != NPU_OK) {
            return ret;
        }
 
        cert_count_size += data_len;
    };
    *cert_count = cert_count_size;
    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int set_custom_op_secverify_cert(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
    unsigned int certs_size = 0;
    char *certs_chain_data = NULL;
    // 仅支持物理机root + 虚机的root + 特权容器root
    if (!(dcmi_is_in_phy_machine_root() || dcmi_is_in_vm_root() || dcmi_is_in_privileged_docker_root())) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    certs_chain_data = (char *)calloc(CUSTOM_OP_SECVERIFY_CERT_CHAIN_SIZE_MAX + CUSTOM_OP_SECVERIFY_CERT_SIZE_MAX,
                                      sizeof(char));
    if (certs_chain_data == NULL) {
        gplog(LOG_ERR, "The certs_chain_data calloc failed.");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = custom_op_secverify_cert_file_read(operate_info->sdata, &certs_size, certs_chain_data);
    if (ret != NPU_OK) {
        free(certs_chain_data);
        return ret;
    }

    if (certs_size > CUSTOM_OP_SECVERIFY_CERT_CHAIN_SIZE_MAX) {
        gplog(LOG_ERR, "The size of the custom op secverify cert is over the limit. size: %d", certs_size);
        free(certs_chain_data);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = dcmi_set_custom_op_secverify_cert(operate_info->id, operate_info->chip_id, certs_chain_data, certs_size);
    if (ret != DCMI_OK) {
        free(certs_chain_data);
        gplog(LOG_ERR, "Failed to set cert info. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
 
    free(certs_chain_data);
    return NPU_OK;
#else
    gplog(LOG_OP, "unsupport set %s.", operate_info->stype);
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}