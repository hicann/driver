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
#else
#include <io.h>
#include <process.h>
#endif
#include <dirent.h>
#include <stddef.h>
#include <stdlib.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "npu_set.h"
#include "npu_cmd_parse.h"
#include "npu_common.h"
#include "dcmi_log.h"
#include "npu_hpm_parse.h"
#include "npu_cms_api.h"
#include "npu_file_operate.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_hpm_parse.h"
#include "npu_upgrade.h"

#define WAIT_MINID_TO_MCU_SWITCH 6
#define TRY_TRANS_FILE_TIMES 10
#define UPGRADE_STATE_WAIT_TIME 120
#define CHECK_UPGRADE_STATUS_NUM 10

#define MAX_PCIE_INFO_LENTH 512
#define SHA256_HASH_SIZE 32

enum  UPGRADE_ERR_MESSAGE {
    PARA_ERR = 0,
    TYPE_ERR = 1,
    ERR_MAX
};

#ifdef _WIN32
bool NT_SUCCESS(int Status)
{
    return (((NTSTATUS)(Status)) >= 0);
}

typedef struct _BCRYPT_ENV {
    BCRYPT_ALG_HANDLE hAlg;
    BCRYPT_HASH_HANDLE hHash;
    PBYTE pbHash;
    PBYTE pbHashObject;
    DWORD cbHash;
} BCRYPT_ENV;
#endif

int box_check_upgrade_mcu(struct npu_smi_operate_info *operate_info)
{
    int ret, numid;
    int upgrade_status = -1;
    int upgrade_progress = 0;
    MCU_UPGRADE_INFO upgrade_info = {0};

    ret = get_mcu_upgrade_info(operate_info->id, &upgrade_info);
    if (ret != 0) {
        gplog(LOG_ERR, "Box get mcu upgrade info failed.%d.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (upgrade_info.mcu_type != 3) { // 3表示华大mcu
        return NPU_OK;
    }

    for (numid = 0; numid < CHECK_UPGRADE_STATUS_NUM; numid++) { // 连续获取10次状态
        ret = dcmi_get_mcu_upgrade_status(operate_info->id, &upgrade_status, &upgrade_progress);
        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            break;
        }
        if (ret != NPU_OK) {
            sleep(1); /* 延迟1s */
            continue;
        }

        if ((upgrade_status == DCMI_UPGRADE_IDLE) || (upgrade_status == DCMI_UPGRADE_UPGRADE_FAIL) ||
            (upgrade_status == DCMI_UPGRADE_UPGRADING) || (upgrade_status == DCMI_UPGRADE_NOT_SUPPORT)) {
            break;
        }

        sleep(1); /* 延迟1s */
    }

    if ((upgrade_status == DCMI_UPGRADE_UPGRADING) || (upgrade_status == DCMI_UPGRADE_NOT_SUPPORT)) {
        printf("This device does not support upgrading %s.\n", operate_info->stype);
        gplog(LOG_ERR, "mcu state: %d\n", upgrade_status);
        return NPU_ERR_CODE_BASE;
    }
    return NPU_OK;
}

int box_upgrade_mcu_check(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int double_module = 2;  // box存在2个npu，对应1个mcu
 
    if (dcmi_board_chip_type_is_ascend_910b_200t_box_a2() != TRUE) {
        return NPU_OK;
    }

    if (operate_info->id % double_module == 0) {
        operate_info->id += 1;
        ret = box_check_upgrade_mcu(operate_info);
        operate_info->id -= 1;
    } else {
        operate_info->id -= 1;
        ret = box_check_upgrade_mcu(operate_info);
        operate_info->id += 1;
    }

    return ret;
}

int check_upgrade_status(struct npu_smi_operate_info *operate_info)
{
    int ret, numid;
    int upgrade_status = -1;
    int upgrade_progress = 0;

    for (numid = 0; numid < CHECK_UPGRADE_STATUS_NUM; numid++) { // 连续获取10次状态
        ret = dcmi_get_mcu_upgrade_status(operate_info->id, &upgrade_status, &upgrade_progress);
        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            return dcmi_to_npu_error_code(ret);
        }
        if (ret != NPU_OK) {
            sleep(1); /* 延迟1s */
            continue;
        }

        if ((upgrade_status == DCMI_UPGRADE_IDLE) || (upgrade_status == DCMI_UPGRADE_UPGRADE_FAIL)) {
            break;
        }

        sleep(1); /* 延迟1s */
    }

    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "upgrade", "Failed");
        gplog(LOG_ERR, "call dcmi_get_mcu_upgrade_status fail.%d.\n", ret);
        return NPU_ERR_CODE_BASE;
    }

    if ((upgrade_status != DCMI_UPGRADE_IDLE) && (upgrade_status != DCMI_UPGRADE_UPGRADE_FAIL)) {
        printf("This device does not support upgrading %s.\n", operate_info->stype);
        gplog(LOG_ERR, "mcu state: %d\n", upgrade_status);
        return NPU_ERR_CODE_BASE;
    }

    return NPU_OK;
}

int check_vrd_upgrade_status(struct npu_smi_operate_info *operate_info)
{
    int ret, numid;
    int upgrade_status = -1;
    int upgrade_progress = 0;

    for (numid = 0; numid < CHECK_UPGRADE_STATUS_NUM; numid++) { // 连续获取10次状态
        ret = dcmi_get_vrd_upgrade_status(operate_info->id, &upgrade_status, &upgrade_progress);
        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            return dcmi_to_npu_error_code(ret);
        }
        if (ret != NPU_OK) {
            sleep(1); /* 延迟1s */
            continue;
        }

        if (upgrade_status != DCMI_UPGRADE_UPGRADING) {
            break;
        }

        sleep(1); /* 延迟1s */
    }

    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "upgrade", "Failed");
        gplog(LOG_ERR, "call dcmi_get_vrd_upgrade_status fail.%d.\n", ret);
        return NPU_ERR_CODE_BASE;
    }

    if (upgrade_status == DCMI_UPGRADE_UPGRADING) {
        printf("This device does not support upgrading %s.\n", operate_info->stype);
        gplog(LOG_ERR, "VRD firmware is being upgraded.\n");
        return NPU_ERR_CODE_BASE;
    }

    if ((operate_info->type == VRD_ITEM) && (upgrade_status == DCMI_UPGRADE_NEED_VALIDATE)) {
        printf("This device does not support upgrading %s. ", operate_info->stype);
        printf("Please power off the server for at least 30 seconds to make the VRD firmware take effect.\n");
        gplog(LOG_ERR, "VRD firmware needs to take effect.\n");
        return NPU_ERR_CODE_BASE;
    }

    return NPU_OK;
}

int transport_upgrade_file(struct npu_smi_operate_info *operate_info)
{
    int ret, retry_times;
    int upgrade_status = DCMI_UPGRADE_STATE_NONE;
    int upgrade_progress = 0;

    /* 传输文件，最多重试10次 */
    for (retry_times = 0; retry_times < TRY_TRANS_FILE_TIMES; retry_times++) {
        ret = dcmi_set_mcu_upgrade_file(operate_info->id, operate_info->file_path);
        if (ret == DCMI_OK || ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            break;
        }
        sleep(WAIT_MINID_TO_MCU_SWITCH);
    }

    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    /* 获取升级状态，最多重试10次 */
    for (retry_times = 0; retry_times < TRY_TRANS_FILE_TIMES; retry_times++) {
        ret = dcmi_get_mcu_upgrade_status(operate_info->id, &upgrade_status, &upgrade_progress);
        if ((ret != DCMI_OK) || (upgrade_status == DCMI_UPGRADE_UPGRADE_FAIL)) {
            sleep(1);
            continue;
        }
        break;
    }

    return dcmi_to_npu_error_code(ret);
}

int get_upgrade_state(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int upgrade_status = -1;
    int upgrade_progress = 0;
    int upgrade_times = 0;

    while (upgrade_times < UPGRADE_STATE_WAIT_TIME) {
        ret = dcmi_get_mcu_upgrade_status(operate_info->id, &upgrade_status, &upgrade_progress);
        if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
            printf("In the vNPU scenario, this device does not support upgrading %s.\n", operate_info->stype);
            gplog(LOG_OP, "In the vNPU scenario, this device does not support upgrading %s.", operate_info->stype);
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }

        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            return ret;
        }

        if (ret != NPU_OK) {
            sleep(WAIT_MINID_TO_MCU_SWITCH);
            ret = dcmi_get_mcu_upgrade_status(operate_info->id, &upgrade_status, &upgrade_progress);
            if (ret != NPU_OK) {
                printf("Failed to query upgrade progress.\n");
                return ret;
            }
        }

        if ((upgrade_status == DCMI_UPGRADE_UPGRADING) || (upgrade_status == DCMI_UPGRADE_NOT_SUPPORT)) {
            printf("\rStart upgrade [%d].", upgrade_progress);
            fflush(stdout);
            sleep(1); /* 延迟1s */
            upgrade_times++;
        } else if (upgrade_status == DCMI_UPGRADE_IDLE) {
            printf("\rStart upgrade [100].");
            printf("\n\t%-30s : %s\n", "Status", "OK");
            if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
                printf("\t%-30s : %s\n", "Message", "The device upgrade is started successfully");
            } else {
                printf("\t%-30s : %s\n", "Message", "Start device upgrade successfully");
            }

            printf("\t%-30s : %s %s\n", "Message", "need active", operate_info->stype);
            return NPU_OK;
        } else {
            printf("\n\t%-30s : %s\n", "Status", "fail");
            printf("\t%-30s : %s[%d]\n", "Message", "Start device upgrade fail", upgrade_status);
            return NPU_ERR_CODE_BASE;
        }
    }

    printf("\n\t%-30s : %s\n", "Status", "fail");
    printf("\t%-30s : %s\n", "Message", "Start device upgrade timeout");

    return NPU_ERR_CODE_BASE;
}
int do_mcu_package_trans_and_upgrade(struct npu_smi_operate_info *operate_info)
{
    int ret;

    // 传输文件
    ret = transport_upgrade_file(operate_info);
    if (ret != NPU_OK) {
        if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
            printf("\t%-30s : %s\n", "Transfer", "Fail");
        } else {
            printf("\t%-30s : %s\n", "transfile", "Fail");
        }

        printf("\t%-30s : %s\n", "Message", "Failed to transfile file");
        return ret;
    }

    if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
        printf("\t%-30s : %s\n", "Transfer", "success");
    } else {
        printf("\t%-30s : %s\n", "transfile", "successfully");
    }

    // 延时5s
    sleep(5);

    // 启动升级
    // 增加超时退出机制
    ret = dcmi_set_mcu_upgrade_stage(operate_info->id, MCU_UPGRADE_START);
    if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
        return ret;
    }
    if (ret != NPU_OK) {
        sleep(WAIT_MINID_TO_MCU_SWITCH);
        ret = dcmi_set_mcu_upgrade_stage(operate_info->id, MCU_UPGRADE_START);
        if (ret != NPU_OK) {
            printf("\t%-30s : %s\n", "Status", "Fail");
            printf("\t%-30s : %s\n", "Message", "Failed to upgrade device");
            return ret;
        }
    }

    printf("\t%-30s : %s\n", "Status", "start to upgrade");

    // 延时2s
    sleep(2);

    return get_upgrade_state(operate_info);
}
int do_mcu_package_upgrade(struct npu_smi_operate_info *operate_info)
{
    int ret, i;

    // 查询升级状态
    ret = check_upgrade_status(operate_info);
    if (ret != NPU_OK) {
        printf("Failed to upgrade the MCU firmware.\n");
        gplog(LOG_ERR, "Upgrade the MCU firmware of NPU Board %d failed.", operate_info->id);
        return ret;
    }

    if (npu_get_chip_type() == NPU_CHIP_310P) {
        ret = check_vrd_upgrade_status(operate_info);
        if (ret != NPU_OK) {
            return ret;
        }
    }

    ret = cms_validate_sign(operate_info->file_path);
    if (ret != NPU_OK) {
        printf("cms_validate_sign operate file err. Error:%d\n", ret);
        return ret;
    }
    printf("\t%-30s : %s\n", "Validity", "success");

    for (i = 0; i < MCU_RETRY_TOTAL_TIMES; i++) {
        ret = do_mcu_package_trans_and_upgrade(operate_info);
        if (ret == NPU_OK) {
            break;
        }
        printf("mcu upgrade failed, retry %d times.\n", i + 1);
        gplog(LOG_ERR, "mcu upgrade failed, retry %d times.", i + 1);
        sleep(5);                                               // 延时5S，等待MCU清理flash
    }
    return ret;
}

int support_upgrade_file_type_is_hpm(void)
{
    return (npu_get_chip_type() == NPU_CHIP_310P || npu_get_chip_type() == NPU_CHIP_310B ||
            npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) ? TRUE : FALSE;
}

static void print_do_mcu_upgrade_failed_message(unsigned int err_type)
{
    switch (err_type) {
        case PARA_ERR:
            printf("\t%-30s : %s\n", "Status", "Fail");
            printf("\t%-30s : %s\n", "Message", "Failed to parse file");
            break;
        case TYPE_ERR:
            printf("\t%-30s : %s\n", "Status", "Fail");
            printf("\t%-30s : %s\n", "Message", "File type error");
            break;
        default:
            return;
    }
}

STATIC int check_mcu_upgrade_environment(struct npu_smi_operate_info *operate_info)
{
    int ret;
    if (dcmi_check_card_is_split_phy(operate_info->id) == TRUE) {
        // 算力切分场景下，不支持该命令
        printf("In the vNPU scenario, this device does not support upgrading %s.\n", operate_info->stype);
        gplog(LOG_OP, "In the vNPU scenario, this device does not support upgrading %s.", operate_info->stype);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if ((npu_get_chip_type() != NPU_CHIP_310) && (npu_get_chip_type() != NPU_CHIP_310B)) {
        printf("[WARNING]: Do not power off or restart the system during the upgrade.\n");
    }

    ret = box_upgrade_mcu_check(operate_info);
    if (ret == NPU_ERR_CODE_BASE) {
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    return NPU_OK;
}

int do_mcu_upgrade(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char bin_file[MAX_LENTH] = {0};
    char dir_path[MAX_LENTH] = {0};

    ret = check_mcu_upgrade_environment(operate_info);
    if (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED) {
        return ret;
    }

    gplog(LOG_OP, "Start to upgrade the MCU firmware of NPU Board(%d).", operate_info->id);

    if (support_upgrade_file_type_is_hpm()) {
        // 升级文件类型为hpm
        ret = determine_file_type(operate_info->file_path, "hpm", (int)strlen("hpm"));
        if (ret == NPU_OK) {
            ret = cms_validate_sign(operate_info->file_path);
            if (ret != NPU_OK) {
                printf("cms_validate_sign operate file err. Error:%d\n", ret);
                gplog(LOG_OP, "Upgrade the MCU firmware of NPU Board(%d) failed.", operate_info->id);
                return ret;
            }

            // 从hpm文件中解析出bin文件
            ret = hpm_file_parse_bin_file(operate_info->id, operate_info->file_path, bin_file, dir_path, MAX_LENTH);
            if (ret != 0) {
                print_do_mcu_upgrade_failed_message(PARA_ERR);
                return NPU_ERR_CODE_BASE;
            }

            ret = strcpy_s(operate_info->file_path, MAX_LENTH, bin_file);
            if (ret != EOK) {
                gplog(LOG_ERR, "call strcpy_s failed.%d.", ret);
                (void)remove_dir(dir_path);
                return NPU_ERR_CODE_SECURE_FUN_FAIL;
            }

            ret = do_mcu_package_upgrade(operate_info);
            // 升级结束后删除生成的目录package
            (void)remove_dir(dir_path);
        } else {
            print_do_mcu_upgrade_failed_message(TYPE_ERR);
        }
    } else {
        // 升级文件类型为bin
        ret = determine_file_type(operate_info->file_path, "bin", (int)strlen("bin"));
        if (ret == NPU_OK) {
            ret = do_mcu_package_upgrade(operate_info);
            // 仅在算力分组宿主机场景下，这里才会出现权限错误
            if (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED) {
                printf("Failed to upgrade the MCU firmware.\n");
            }
        } else {
            print_do_mcu_upgrade_failed_message(TYPE_ERR);
        }
    }

    gplog(LOG_OP, "Upgrade the MCU firmware of NPU Board(%d) %s, ret(%d).", operate_info->id,
        (ret == NPU_OK) ?  "success" : "failed", ret);
    return ret;
}

int get_vrd_upgrade_state(int card_id)
{
    int ret;
    int upgrade_status = -1;
    int upgrade_progress = 0;
    int upgrade_times = 0;

    while (upgrade_times < UPGRADE_STATE_WAIT_TIME) {
        ret = dcmi_get_vrd_upgrade_status(card_id, &upgrade_status, &upgrade_progress);
        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            return dcmi_to_npu_error_code(ret);
        }
        if (ret != NPU_OK) {
            sleep(WAIT_MINID_TO_MCU_SWITCH);
            ret = dcmi_get_vrd_upgrade_status(card_id, &upgrade_status, &upgrade_progress);
            if (ret != NPU_OK) {
                printf("Failed to query upgrade progress.\n");
                return dcmi_to_npu_error_code(ret);
            }
        }

        if ((upgrade_status == DCMI_UPGRADE_UPGRADING) || (upgrade_status == DCMI_UPGRADE_NOT_SUPPORT)) {
            printf("\rStart upgrade [%d].", upgrade_progress);
            fflush(stdout);
            sleep(1); /* 延迟1s */
            upgrade_times++;
        } else if (upgrade_status == DCMI_UPGRADE_NEED_VALIDATE) {
            printf("\rStart upgrade [100].");
            printf("\n\t%-30s : %s\n", "Status", "OK");
            printf("\t%-30s : %s\n", "Message", "Start device upgrade successfully");
            printf("\t%-30s : %s\n", "Message",
                   "Power off the server for at least 30 seconds to make the VRD firmware take effect");
            return NPU_OK;
        } else if (upgrade_status == DCMI_UPGRADE_NOT_NEED) {
            printf("\n\t%-30s : %s\n", "Status", "OK");
            printf("\t%-30s : %s\n", "Message", "The VRD firmware does not need to be upgraded");
            return NPU_OK;
        } else {
            printf("\n\t%-30s : %s\n", "Status", "fail");
            printf("\t%-30s : %s[%d]\n", "Message", "Start device upgrade fail", upgrade_status);
            return NPU_ERR_CODE_BASE;
        }
    }

    printf("\n\t%-30s : %s\n", "Status", "fail");
    printf("\t%-30s : %s\n", "Message", "Start device upgrade timeout");

    return NPU_ERR_CODE_BASE;
}

int check_before_vrd_upgrade(struct npu_smi_operate_info *operate_info)
{
    int ret = 0;
 
#ifdef NPU_SMI_V2
    int card_id, dev_id;
    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &dev_id, operate_info->id);
    if (ret != DCMI_OK) {
        return ret;
    }
    operate_info->id = card_id;
#endif
    // 查询升级状态
    ret = check_upgrade_status(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }
 
    ret = check_vrd_upgrade_status(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }
    return NPU_OK;
}

int transport_vrd_file(int card_id, char *fileName, int index, int cur_bin_idx, int bin_num)
{
    int ret;
    int upgrade_status = DCMI_UPGRADE_STATE_NONE;
    // 传输文件，最多重试10次
    for (int times = 0; times < DCMI_TRY_TRANS_FILE_TIMES; times++) {
        DCMI_VRD_PER_UPGRADE_INFO per_vrd_info = dcmi_set_vrd_per_upgrade_info(card_id, index, cur_bin_idx,
                                                                               bin_num, true);
        ret = dcmi_trans_vrd_file(fileName, &per_vrd_info);
        if (ret == DCMI_OK || ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            break;
        }
        sleep(DCMI_WAIT_MINID_TO_MCU_SWITCH);
    }
    if (ret != DCMI_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        gplog(LOG_ERR, "Call dcmi_trans_vrd_file fail, ret=%d.\n", ret);
        return ret;
    }
    
     /* 获取升级状态，最多重试10次 */
    for (int times = 0; times < DCMI_TRY_TRANS_FILE_TIMES; times++) {
        ret = dcmi_get_single_vrd_upgrade_status(card_id, &upgrade_status, index);
        if ((ret != DCMI_OK) || (upgrade_status == DCMI_UPGRADE_UPGRADE_FAIL)) {
            sleep(1);
            continue;
        }
        break;
    }
    if (ret != DCMI_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        gplog(LOG_ERR, "Call dcmi_get_single_vrd_upgrade_status fail, ret=%d.\n", ret);
        return ret;
    }

    sleep(5); // 延时5s
    // 启动升级
    ret = dcmi_start_vrd_upgrade(card_id, index);
    if (ret != DCMI_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : %s\n", "Message", "Failed to start upgrade vrd.");
        gplog(LOG_OP, "Upgrade the VRD firmware of NPU Board,(card_id=%d, result=%s, ret=%d).", card_id, "failed", ret);
        return ret;
    }
    // 发送清除命令
    ret = dcmi_send_clear_file_msg(card_id, index);
    if (ret != DCMI_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : %s\n", "Message", "Failed to clear flash upgrade file.");
        gplog(LOG_ERR, "Call dcmi_send_clear_file_msg fail, ret=%d.\n", ret);
    }
    gplog(LOG_OP, "Upgrade the VRD firmware of NPU Board,(card_id=%d, result=%s, ret=%d).",
        card_id, (ret == DCMI_OK) ?  "success" : "failed", ret);
    return ret;
}

int transport_vrd_upgrade_firmware(int card_id, char bin_file_names[][MAX_LENTH], int bin_file_num)
{
    int ret;
    int index = -1;
    
    for (int i = 0; i < bin_file_num; i++) {
        ret = dcmi_convert_str_to_int(strrchr(bin_file_names[i], '_') + 1, &index);
        if (ret != DCMI_OK) {
            return ret;
        }
        ret = transport_vrd_file(card_id, bin_file_names[i], index, i + 1, bin_file_num);
        if (ret != DCMI_OK) {
            printf("\t%-30s : Failed to transfer vrd file: %s\n", "Message", bin_file_names[i]);
            gplog(LOG_ERR, "Vrd upgrade bin failed.(bin_file_name=%s).", bin_file_names[i]);
            return ret;
        }
        sleep(5); // 延时5S，等待AO清理flash
    }

    return ret;
}

int parse_single_vrd_hpm(int card_id, const char *file)
{
    // 1.从hpm文件中解析出bin文件
    int bin_file_num = 0;
    char dir_path[MAX_LENTH] = {0};
    char bin_file_names[DCMI_MAX_VRD_FILE_NUM][MAX_LENTH] = { { 0 } };
    int ret = dcmi_parse_bin_file_from_vrd_hpm(card_id, file, bin_file_names, &bin_file_num, dir_path);
    if (ret != DCMI_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : %s\n", "Message", "Failed to parse file");
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }

    // 2.根据index进行排序
    qsort(bin_file_names, bin_file_num, sizeof(bin_file_names[0]), dcmi_compare_bin_name_index);

    // 3.校验版本信息，根据版本信息来过滤
    DCMI_VRD_APP_UPGRADE_INFO current_vrd_info[DCMI_MAX_VRD_FILE_NUM] = {0};
    int current_vrd_num = 0;
    ret = dcmi_get_vrd_current_version(card_id, current_vrd_info, &current_vrd_num);
    if (ret != DCMI_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to get %d current version\n", "Message", card_id);
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }

    // 4.过滤排序后的bin文件，得到需要上传的filter_file_names、bin_file_num
    char filter_file_names[DCMI_MAX_VRD_FILE_NUM][MAX_LENTH] = { { 0 } };
    ret = dcmi_filter_bin_fileNames(current_vrd_num, current_vrd_info, bin_file_names,
                                    &bin_file_num, filter_file_names);
    if (ret != DCMI_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to filter %d file names\n", "Message", card_id);
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }

    // 如果当前文件夹里只存在vrd_00的校验文件，则不进行vrd升级
    if (bin_file_num == 1 && strstr(filter_file_names[0], "vrd_00_") != NULL) {
        printf("\t%-30s : %s\n", "Status", "OK");
        printf("\t%-30s : Card %d no need to upgrade vrd\n", "Message", card_id);
        gplog(LOG_OP, "Card %d no need to upgrade vrd.", card_id);
        (void)dcmi_remove_dir(dir_path);
        return DCMI_OK;
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : %s\n", "Message", "Start to upgrade");
    printf("Start upgrade.\n");

    // 5.传递vrd固件
    ret = transport_vrd_upgrade_firmware(card_id, filter_file_names, bin_file_num);
    if (ret == DCMI_OK) {
        printf("\n\t%-30s : %s\n", "Status", "OK");
        printf("\t%-30s : %s\n", "Message", "Start device upgrade successfully");
        printf("\t%-30s : %s\n", "Message", "Need active vrd");
    }

    // 传包后删除目录
    (void)dcmi_remove_dir(dir_path);
    return ret;
}

int set_vrd_upgrade_file(int card_id, const char *file)
{
    // 1.场景判断
    int ret, fd = -1;
    bool is_in_root_env = dcmi_is_in_phy_machine_root() || dcmi_is_in_privileged_docker_root();
    if (!is_in_root_env) {
        printf("This command cannot be executed on a VM or container.\n");
        gplog(LOG_OP, "Operation not permitted, Only the root user on the physical machine or the root user on a "
                      "privileged container can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    // 2. 参数校验，hpm文件检查
    if (file == NULL) {
        gplog(LOG_ERR, "The file path is empty.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (access(file, F_OK) != NPU_OK) {
        printf("File path does not exist. Error:%d\n", access(file, F_OK));
        gplog(LOG_ERR, "The upgrade file is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    // 3.检查路径是否存在，格式是否为hpm文件
    ret = dcmi_determine_file_type(file, "hpm", (int)strlen("hpm"));
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_determine_file_type failed, input file is %s.", file);
        return ret;
    }

    // 4.校验card id
    ret = dcmi_check_card_id(card_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Check card id failed(card_id=%d, ret=%d).", card_id, ret);
        return ret;
    }

    printf("[WARNING]: Do not power off or restart the system during the upgrade.\n");
    printf("Start verification\n\t%-30s : %s\n", "Validity", "Success");
    printf("Start parse.\n");

    // 5.vrd升级核心步骤前加锁
    ret = dcmi_vrd_set_lock_up(&fd, DCMI_VRD_GET_LOCK_TIME_OUT_MS);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_vrd_set_lock failed. ret is %d.", ret);
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : %s\n", "Message", "Updating. Please try again later.");
        return DCMI_ERR_CODE_RESOURCE_OCCUPIED;
    }

    ret = parse_single_vrd_hpm(card_id, file);
    dcmi_vrd_set_unlock_up(fd);
 
    return ret;
}

int do_vrd_upgrade(struct npu_smi_operate_info *operate_info)
{
    int ret, i;
    // 910B\910_93只支持vrd查询版本信息
    if (npu_get_chip_type() == NPU_CHIP_910B || npu_get_chip_type() == NPU_CHIP_910_93) {
        printf("This device does not support upgrading %s.\n", operate_info->stype);
        gplog(LOG_OP, "This device does not support upgrading %s.", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    if (dcmi_get_product_type_inner() == DCMI_A350_A5_CARD) {
        ret = set_vrd_upgrade_file(operate_info->id, operate_info->file_path);
        return dcmi_to_npu_error_code(ret);
    }
    printf("[WARNING]: Do not power off or restart the system during the upgrade.\n");

    ret = check_before_vrd_upgrade(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    for (i = 0; i < MCU_RETRY_TOTAL_TIMES; i++) {
        // 启动升级
        ret = dcmi_set_vrd_upgrade_stage(operate_info->id, VRD_UPGRADE_START);
        if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            ret = dcmi_to_npu_error_code(ret);
            break;
        }
        if (ret != NPU_OK) {
            sleep(WAIT_MINID_TO_MCU_SWITCH);
            ret = dcmi_set_vrd_upgrade_stage(operate_info->id, VRD_UPGRADE_START);
            if (ret != NPU_OK) {
                printf("\t%-30s : %s\n", "Status", "Fail");
                printf("\t%-30s : %s\n", "Message", "Failed to upgrade device");
                ret = dcmi_to_npu_error_code(ret);
                break;
            }
        }

        printf("\t%-30s : %s\n", "Status", "start to upgrade");

        // 延时2s
        sleep(2);
        ret = get_vrd_upgrade_state(operate_info->id);
        if (ret == NPU_OK) {
            break;
        }
        printf("vrd upgrade failed, retry %d times.\n", i + 1);
        gplog(LOG_ERR, "vrd upgrade failed, retry %d times.", i + 1);
        sleep(5);    // 延时5S
    }

    gplog(LOG_OP, "Upgrade the VRD firmware of NPU Board(%d) %s, ret(%d).", operate_info->id,
        (ret == NPU_OK) ?  "success" : "failed", ret);
    return ret;
}

#ifndef _WIN32
int generate_bootloader_file_header(struct npu_smi_operate_info *operate_info, char *bootloader, int bootloader_len)
{
    unsigned int file_len = 0;
    char sha_cmd[MAX_LENTH] = {0};
    char msginfo[MAX_PCIE_INFO_LENTH] = {0};
    int sha256_index;

    /* 构造bootloader file header */
    bootloader[3] = 0x0; /* bootloader[3]为0 */
    bootloader[2] = 0x0; /* bootloader[2]为0 */
    bootloader[1] = 0x0; /* bootloader[1]为0 */
    bootloader[0] = 0x1; /* bootloader[0]为1 */

    /* 计算升级包长度 */
    int ret = get_file_length(operate_info->file_path, &file_len);
    if ((ret != 0) || (file_len <= 0)) {
        gplog(LOG_ERR, "call get_file_length failed. file_len: %u, ret: %d\n", file_len, ret);
        return -1;
    }

    /* 注意大小端 */
    bootloader[7] = file_len >> 24; /* bootloader[7]为file_len的24-31bit */
    bootloader[6] = file_len >> 16; /* bootloader[6]为file_len的16-23bit */
    bootloader[5] = file_len >> 8;  /* bootloader[5]为file_len的8-15bit */
    bootloader[4] = (char)file_len; /* bootloader[4]为file_len的0-7bit */

    /* 计算sha256，通过系统现有命令计算 */
    ret = snprintf_s(&sha_cmd[0], MAX_LENTH, MAX_LENTH - 1, "/usr/bin/sha256sum %s 2>&1", operate_info->file_path);
    if (ret <= 0) {
        gplog(LOG_ERR, "call snprintf_s failed.%d\n", ret);
        return -1;
    }

    FILE *fd = popen(sha_cmd, "r");
    if (fd == NULL) {
        gplog(LOG_ERR, "call system failed. %s \n", sha_cmd);
        return -1;
    }

    if (fgets(&msginfo[0], MAX_PCIE_INFO_LENTH, fd)) {
        char *pFind = strstr(&msginfo[0], operate_info->file_path);
        if (pFind == NULL) {
            gplog(LOG_ERR, "can not find same string\n");
            (void)pclose(fd);
            return -1;
        }

        for (sha256_index = 0; sha256_index < SHA256_HASH_SIZE; sha256_index++) {
            int msg_offset = sha256_index * 2;                                          /* 偏移为sha256_index * 2 */
            ret = sscanf_s(msginfo + msg_offset, "%02hhx", &bootloader[8 + sha256_index]); /* 第8 + sha256_index个字节 */
            if (ret <= 0) {
                gplog(LOG_ERR, "call sscanf_s failed.%d %s.\n", ret, msginfo + msg_offset);
                (void)pclose(fd);
                return -1;
            }
        }
    }

    (void)pclose(fd);
    return 0;
}
#else
static int create_hash_env(BCRYPT_ENV *hash_env)
{
    NTSTATUS status;
    DWORD cbHashObject = 0;
    DWORD cbData = 0;
    // open an algorithm handle
    status = BCryptOpenAlgorithmProvider(&hash_env->hAlg, BCRYPT_SHA256_ALGORITHM, NULL, 0);
    if (!NT_SUCCESS(status)) {
        gplog(LOG_ERR, "call BCryptOpenAlgorithmProvider error,status=0x%x.", status);
        return NPU_ERR_CODE_INNER_ERR;
    }

    status = BCryptGetProperty(hash_env->hAlg, BCRYPT_OBJECT_LENGTH, (PBYTE)&cbHashObject, sizeof(DWORD), &cbData, 0);
    if (!NT_SUCCESS(status)) {
        gplog(LOG_ERR, "call BCryptGetProperty error,status=0x%x.", status);
        BCryptCloseAlgorithmProvider(hash_env->hAlg, 0);
        return NPU_ERR_CODE_INNER_ERR;
    }

    // allocate the hash object on the heap
    hash_env->pbHashObject = (PBYTE)HeapAlloc(GetProcessHeap(), 0, cbHashObject);
    if (hash_env->pbHashObject == NULL) {
        gplog(LOG_ERR, "call HeapAlloc error.");
        BCryptCloseAlgorithmProvider(hash_env->hAlg, 0);
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }
    status = BCryptGetProperty(hash_env->hAlg, BCRYPT_HASH_LENGTH, (PBYTE)&hash_env->cbHash, sizeof(DWORD), &cbData, 0);
    if (!NT_SUCCESS(status)) {
        gplog(LOG_ERR, "call BCryptGetProperty get BCRYPT_HASH_LENGTH error,status=0x%x.", status);
        BCryptCloseAlgorithmProvider(hash_env->hAlg, 0);
        HeapFree(GetProcessHeap(), 0, hash_env->pbHashObject);
        return NPU_ERR_CODE_INNER_ERR;
    }

    status = BCryptCreateHash(hash_env->hAlg, &hash_env->hHash, hash_env->pbHashObject, cbHashObject, NULL, 0, 0);
    if (!NT_SUCCESS(status)) {
        gplog(LOG_ERR, "call BCryptCreateHash error,status=0x%x.", status);
        BCryptCloseAlgorithmProvider(hash_env->hAlg, 0);
        HeapFree(GetProcessHeap(), 0, hash_env->pbHashObject);
        return NPU_ERR_CODE_INNER_ERR;
    }

    // allocate the hash buffer on the heap
    hash_env->pbHash = (PBYTE)HeapAlloc(GetProcessHeap(), 0, hash_env->cbHash);
    if (hash_env->pbHash == NULL) {
        gplog(LOG_ERR, "call HeapAlloc error.");
        BCryptCloseAlgorithmProvider(hash_env->hAlg, 0);
        HeapFree(GetProcessHeap(), 0, hash_env->pbHashObject);
        BCryptDestroyHash(hash_env->hHash);
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }
    return DCMI_OK;
}

static void release_hash_env(BCRYPT_ENV *hash_env)
{
    if (hash_env->hAlg) {
        BCryptCloseAlgorithmProvider(hash_env->hAlg, 0);
    }

    if (hash_env->hHash) {
        BCryptDestroyHash(hash_env->hHash);
    }

    if (hash_env->pbHashObject) {
        HeapFree(GetProcessHeap(), 0, hash_env->pbHashObject);
    }

    if (hash_env->pbHash) {
        HeapFree(GetProcessHeap(), 0, hash_env->pbHash);
    }
}

int generate_bootloader_file_header(struct npu_smi_operate_info *operate_info, char *bootloader, int bootloader_len)
{
    const int BOOTLOADER_HASH_START_INDEX = 8;
    HANDLE hFile;
    char path[MAX_PATH + 1] = { 0x00 };
    NTSTATUS status;
    int ret;
    DWORD cbRead = 0;
    BYTE rgbFile[BUFSIZE];
    BOOL bResult = FALSE;
    CHAR rgbDigits[] = "0123456789abcdef";
    BCRYPT_ENV hash_env = { 0 };

    if ((operate_info->file_path == NULL) || (strlen(operate_info->file_path) > MAX_PATH) ||
        (PathCanonicalizeA(path, operate_info->file_path) == FALSE)) {
        printf("\t%-30s : Upgrade file path is illegal.\n", "Message");
        return -1;
    }

    hFile = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        gplog(LOG_ERR, "CreateFile false, Error:%d", GetLastError());
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }
    if (create_hash_env(&hash_env) != DCMI_OK) {
        gplog(LOG_ERR, "call create_hash_env Error.");
        CloseHandle(hFile);
        return NPU_ERR_CODE_INNER_ERR;
    }

    while (bResult = ReadFile(hFile, rgbFile, BUFSIZE, &cbRead, NULL)) {
        if (cbRead == 0) {
            break;
        }
        // hash some data
        if (!NT_SUCCESS(status = BCryptHashData(hash_env.hHash, (PBYTE)rgbFile, cbRead, 0))) {
            wprintf(L"**** Error 0x%x returned by BCryptHashData\n", status);
            goto Cleanup;
        }
    }

    // close the hash
    if (!NT_SUCCESS(status = BCryptFinishHash(hash_env.hHash, hash_env.pbHash, hash_env.cbHash, 0))) {
        wprintf(L"**** Error 0x%x returned by BCryptFinishHash\n", status);
        goto Cleanup;
    }

    for (DWORD i = 0; i < hash_env.cbHash; i++) {
        bootloader[BOOTLOADER_HASH_START_INDEX + i] = hash_env.pbHash[i];
    }
    ret = DCMI_OK;
Cleanup:

    if (hFile) {
        CloseHandle(hFile);
    }

    release_hash_env(&hash_env);
    return ret;
}
#endif

int do_mcu_bootloader_upgrade(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char bootloader[MAX_LENTH] = {0};

    // 只有在Atlas500上并且MCU在线时才支持升级BootLoader
    if (!(npu_board_type_is_station() == TRUE && npu_check_is_has_mcu() == TRUE)) {
        printf("This device does not support upgrading %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = check_upgrade_status(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = transport_upgrade_file(operate_info);
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "transfile", "Fail");
        printf("\t%-30s : %s\n", "Message", "Failed to transfile file");
        return ret;
    }
    printf("\t%-30s : %s\n", "transfile", "successfully");

    sleep(5); /* 延迟5s */

    // 计算bootloader_file_header
    ret = generate_bootloader_file_header(operate_info, bootloader, MAX_LENTH);
    if (ret != 0) {
        printf("generate bootloader file header fail. Error:%d\n", ret);
        gplog(LOG_ERR, "call generate_bootloader_file_header fail.ret(%d). bootloader: %s\n", ret, bootloader);
        return ret;
    }

    // 启动升级,bootloader只在小站上适用
    const int BOOTLOADER_LEN = 40;
    ret = dcmi_mcu_start_bootloader_upgrade(operate_info->id, bootloader, BOOTLOADER_LEN);
    if (ret != NPU_OK) {
        sleep(WAIT_MINID_TO_MCU_SWITCH);
        ret = dcmi_mcu_start_bootloader_upgrade(operate_info->id, bootloader, BOOTLOADER_LEN);
        if (ret != NPU_OK) {
            printf("\t%-30s : %s\n", "Status", "Fail");
            printf("\t%-30s : %s\n", "Message", "Failed to upgrade device");
            return ret;
        }
    }

    printf("\t%-30s : %s\n", "Status", "start to upgrade");

    // 等待MCU Bootloader搬运完成，此时mcu会再次打开中断
    sleep(10); // 延迟10s

    ret = get_upgrade_state(operate_info);
    if (ret == NPU_OK) {
        gplog(LOG_OP, "Upgrade the bootloader firmware of NPU Board(%d) success.", operate_info->id);
    } else {
        gplog(LOG_OP, "Upgrade the bootloader firmware of NPU Board(%d) failed.", operate_info->id);
    }
    return ret;
}

int check_upgrade_file(struct npu_smi_operate_info *operate_info)
{
    int ret = NPU_OK;
    switch (operate_info->type) {
        case VRD_ITEM:
            break;
        case MCU_ITEM:
        case BOOTLOADER:
        default:
            if (operate_info->file_path == NULL) {
                printf("This command must input file path.\n");
                ret = NPU_ERR_CODE_INVALID_PARAMETER;
                break;
            }

            ret = access(operate_info->file_path, F_OK);
            if (ret != NPU_OK) {
                printf("File path does not exist. Error:%d\n", ret);
            }
            break;
    }
    return ret;
}

int do_npu_upgrade(struct npu_smi_operate_info *operate_info)
{
    int ret;
    size_t table_index;
    ret = check_upgrade_file(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    struct npu_operate_table_item npu_upgrade_table[] = {
        {MCU_ITEM, do_mcu_upgrade},
        {BOOTLOADER, do_mcu_bootloader_upgrade},
        {VRD_ITEM, do_vrd_upgrade},
        {NPU_INVALID_VALUE, npu_invalid_item_proc}
    };

    size_t table_size = sizeof(npu_upgrade_table) / sizeof(npu_upgrade_table[0]);
    // 查表并执行对应的升级操作
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == npu_upgrade_table[table_index].fun_index) {
            return npu_upgrade_table[table_index].proc_func(operate_info);
        }
    }
    printf("Error parameter in upgrade info, type: \"%s\".\n", operate_info->stype);
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int show_upgrade_progress(struct npu_smi_operate_info *operate_info, int upgrade_status, int upgrade_progress)
{
    int ret = NPU_OK;

    switch (upgrade_status) {
        case DCMI_UPGRADE_IDLE: {
            printf("\t%-30s : %s\n", "Conclusion", "PASS");
            if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
                printf("\t%-30s : %s\n", "Message", "The device is upgraded successfully.");
            } else {
                printf("\t%-30s : %s\n", "Message", "Device upgrade successfully.");
            }

            break;
        }

        case DCMI_UPGRADE_UPGRADING: {
            printf("\t%-30s : %s\n", "Conclusion", "Running");
            printf("\t%-30s : %d\n", "Schedule", upgrade_progress);
            break;
        }

        case DCMI_UPGRADE_NOT_SUPPORT: {
            printf("\tThis device does not support upgrading %s.\n", operate_info->stype);
            ret = DCMI_UPGRADE_NOT_SUPPORT;
            break;
        }

        case DCMI_UPGRADE_UPGRADE_FAIL: {
            printf("\tFailed to upgrade Device %s.\n", operate_info->stype);
            ret = DCMI_UPGRADE_UPGRADE_FAIL;
            break;
        }

        default: {
            printf("Query upgrade status error, upgrade status: %d.\n", upgrade_status);
            ret = NPU_ERR_CODE_INNER_ERR;
            break;
        }
    }

    return ret;
}

int do_npu_query_progress(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int upgrade_progress = 0;
    int upgrade_status = DCMI_UPGRADE_STATE_NONE;

    switch (operate_info->type) {
        case MCU_ITEM:
            ret = dcmi_get_mcu_upgrade_status(operate_info->id, &upgrade_status, &upgrade_progress);
            if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
                printf("In the vNPU scenario, this device does not support querying upgrade progress.\n");
                gplog(LOG_OP, "In the vNPU scenario, this device does not support querying upgrade progress.");
                return NPU_ERR_CODE_OPER_NOT_PERMITTED;
            }
            if (ret != DCMI_OK) {
                printf("Failed to query upgrade progress.\n");
                return dcmi_to_npu_error_code(ret);
            }
            break;
        case NPU_DEFAULT_VALUE:
            printf("Must input parameter of type.\n");
            return NPU_ERR_CODE_INVALID_PARAMETER;
        case VRD_ITEM:
            printf("This device does not support querying upgrade progress.\n");
            gplog(LOG_OP, "This device does not support querying upgrade progress.");
            return NPU_ERR_CODE_NOT_SUPPORT;
        default:
            printf("Error parameter in querying upgrade info, type: \"%s\".\n", operate_info->stype);
            return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = show_upgrade_progress(operate_info, upgrade_status, upgrade_progress);
    return ret;
}

void print_vrd_version(const char *data_info, int len)
{
    int ret;
    char tmp_data[VOL_MOD_NAME_LEN + VOL_MOD_NUM_LEN] = {0}; /* 临时vrd温度名称 */
    int vrd_index, vrd_num, name_offset, value_offset;
    short curr_ver, obj_ver, left_times;

    vrd_num = (int)data_info[0];
    if (npu_get_chip_type() == NPU_CHIP_910B && vrd_num == 0) {
        printf("\t%-30s : %s\n\n", "VRD Count", "NA");
    } else {
        printf("\t%-30s : %d\n\n", "VRD Count", vrd_num);
    }

    for (vrd_index = 0; vrd_index < vrd_num; vrd_index++) {
        name_offset = vrd_index * VOL_MOD_INFO_LEN + VOL_MOD_NUM_LEN;
        value_offset = vrd_index * VOL_MOD_INFO_LEN + VOL_MOD_NAME_LEN + VOL_MOD_NUM_LEN;
        memcpy_s(&curr_ver, sizeof(short), data_info + value_offset, sizeof(short));
        memcpy_s(&obj_ver, sizeof(short), data_info + value_offset + VOL_MOD_VALUE_LEN, sizeof(short));
        memcpy_s(&left_times, sizeof(short),
            data_info + value_offset + VOL_MOD_VALUE_LEN + VOL_MOD_VALUE_LEN, sizeof(short));
        /* PCIE带外管理规范，vrd名称长度为10(不含结束字符) */
        ret = strncpy_s(tmp_data, sizeof(tmp_data), data_info + name_offset, VOL_MOD_NAME_LEN);
        if (ret != EOK) {
            gplog(LOG_ERR, "strncpy_s failed. err is %d", ret);
            return;
        }
        printf("\t%-30s : %s\n", "VRD Name", tmp_data);

        if (curr_ver == VOL_MOD_VALUE_INVALID || obj_ver == VOL_MOD_VALUE_INVALID
            || left_times == VOL_MOD_VALUE_INVALID) {
            printf(" %s\n", "Failed");
        } else if (curr_ver == VOL_MOD_VALUE_ERROR || obj_ver == VOL_MOD_VALUE_ERROR
            || left_times == VOL_MOD_VALUE_ERROR) {
            printf(" %s\n", "NA");
        } else {
            printf("\t%-30s : %hd\n", "Current Version", curr_ver);
            printf("\t%-30s : %hd\n", "Target Version", obj_ver);
            printf("\t%-30s : %hd\n\n", "Remaining Upgrade Count", left_times);
        }
    }
}

void print_vdm_version(const char *data_info)
{
    int ret;
    char tmp_data[VOL_MOD_NAME_LEN + VOL_MOD_NUM_LEN] = {0};
    int vdm_index, vdm_num, name_offset, value_offset;
    short curr_ver, obj_ver, left_times;

    vdm_num = (int)data_info[0];
    if (npu_get_chip_type() == NPU_CHIP_910B && vdm_num == 0) {
        printf("\t%-30s : %s\n\n", "VDM Count", "NA");
    } else {
        printf("\t%-30s : %d\n\n", "VDM Count", vdm_num);
    }

    for (vdm_index = 0; vdm_index < vdm_num; vdm_index++) {
        name_offset = vdm_index * VOL_MOD_INFO_LEN + VOL_MOD_NUM_LEN;
        value_offset = vdm_index * VOL_MOD_INFO_LEN + VOL_MOD_NAME_LEN + VOL_MOD_NUM_LEN;
        memcpy_s(&curr_ver, sizeof(short), data_info + value_offset, sizeof(short));
        memcpy_s(&obj_ver, sizeof(short), data_info + value_offset + VOL_MOD_VALUE_LEN, sizeof(short));
        memcpy_s(&left_times, sizeof(short),
            data_info + value_offset + VOL_MOD_VALUE_LEN + VOL_MOD_VALUE_LEN, sizeof(short));
        /* PCIE带外管理规范，vrd名称长度为10(不含结束字符) */
        ret = strncpy_s(tmp_data, sizeof(tmp_data), data_info + name_offset, VOL_MOD_NAME_LEN);
        if (ret != EOK) {
            gplog(LOG_ERR, "print_vdm_version strncpy_s failed. err is %d", ret);
            return;
        }
        printf("\t%-30s : %s\n", "VDM Name", tmp_data);

        if (curr_ver == VOL_MOD_VALUE_INVALID || obj_ver == VOL_MOD_VALUE_INVALID
            || left_times == VOL_MOD_VALUE_INVALID) {
            printf(" %s\n", "Failed");
        } else if (curr_ver == VOL_MOD_VALUE_ERROR || obj_ver == VOL_MOD_VALUE_ERROR
            || left_times == VOL_MOD_VALUE_ERROR) {
            printf(" %s\n", "NA");
        } else {
            printf("\t%-30s : %hd\n", "Current Version", curr_ver);
            printf("\t%-30s : %hd\n", "Target Version", obj_ver);
            printf("\t%-30s : %hd\n\n", "Remaining Upgrade Count", left_times);
        }
    }
}

int do_npu_query_version(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char str_version[MAX_LENTH] = {0};

    switch (operate_info->type) {
        case MCU_ITEM:
            ret = dcmi_get_mcu_version(operate_info->id, str_version, MAX_LENTH);
            if (ret != DCMI_OK) {
                printf("Failed to query %s version.\n", operate_info->stype);
                return dcmi_to_npu_error_code(ret);
            }
            if (npu_get_chip_type() == NPU_CHIP_910B) {
                printf("\t%-30s : %s\n", "Version", strcmp(str_version, "0") == 0 ? "NA" : str_version);
            } else {
                printf("\t%-30s : %s\n", "Version", str_version);
            }
            
            break;
        case VRD_ITEM:
            ret = dcmi_get_vrd_info(operate_info->id, str_version, MAX_LENTH);
            if (ret != DCMI_OK) {
                printf("Failed to query %s version.\n", operate_info->stype);
                return dcmi_to_npu_error_code(ret);
            }
            print_vrd_version(str_version, MAX_LENTH);
            break;
        case VDM_ITEM:
            ret = dcmi_get_vdm_info(operate_info->id, str_version, MAX_LENTH);
            if (ret != DCMI_OK) {
                printf("Failed to query %s version.\n", operate_info->stype);
                return dcmi_to_npu_error_code(ret);
            }
            print_vdm_version(str_version);
            break;
        case NPU_DEFAULT_VALUE:
            ret = NPU_ERR_CODE_INVALID_PARAMETER;
            printf("Must input parameter of type.\n");
            break;
        default:
            ret = NPU_ERR_CODE_INVALID_PARAMETER;
            printf("Error parameter in querying upgrade info, type: \"%s\".\n", operate_info->stype);
            break;
    }

    return ret;
}

int do_npu_active(struct npu_smi_operate_info *operate_info)
{
    int ret;

    // 只有在Atlas500上才支持升级BootLoader
    if (operate_info->type == BOOTLOADER && npu_board_type_is_station() == FALSE) {
        printf("This device does not support activating %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    switch (operate_info->type) {
        case MCU_ITEM: // 与bootloader处理相同
        case BOOTLOADER: {
            gplog(LOG_OP, "Start to active the %s firmware of NPU Board(%d).\n", operate_info->stype, operate_info->id);
            ret = dcmi_set_mcu_upgrade_stage(operate_info->id, MCU_UPGRADE_VALIDETE);
            break;
        }
        case VRD_ITEM: {
            printf("This device does not support activating %s.\n", operate_info->stype);
            gplog(LOG_OP, "This device does not support activating %s.", operate_info->stype);
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
        default: {
            ret = NPU_ERR_CODE_INVALID_PARAMETER;
            printf("Error parameter in active, type: \"%s\".\n", operate_info->stype);
            return ret;
        }
    }

    if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
        printf("In the vNPU scenario, this device does not support activating %s.\n", operate_info->stype);
        gplog(LOG_OP, "In the vNPU scenario, this device does not support activating %s.", operate_info->stype);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    if (ret != NPU_OK) {
        printf("Failed to activate the mcu upgrade.\n");
        gplog(LOG_OP, "Activate the %s firmware of NPU Board(%d) failed.", operate_info->stype, operate_info->id);
    } else {
        gplog(LOG_OP, "Activate the %s firmware of NPU Board(%d) successfully.", operate_info->stype, operate_info->id);

        printf("\t%-30s : %s\n", "Status", "OK");
        printf("\t%-30s : %s\n", "Message", "The upgrade has taken effect after performed reboot successfully.\n");
    }

    return ret;
}

void print_upgrade_result(int ret, struct npu_smi_operate_info *operate_info)
{
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        if (operate_info->is_upgrade) {
            printf("This device does not support upgrading %s.\n", operate_info->stype);
            gplog(LOG_OP, "This device does not support upgrading %s.", operate_info->stype);
        } else if (operate_info->is_query) {
            printf("This device does not support querying upgrade progress.\n");
            gplog(LOG_OP, "This device does not support querying upgrade progress.");
        } else if (operate_info->is_version) {
            printf("This device does not support querying version.\n");
            gplog(LOG_OP, "This device does not support querying version.");
        } else if (operate_info->is_active) {
            printf("This device does not support activating %s.\n", operate_info->stype);
            gplog(LOG_OP, "This device does not support activating %s.", operate_info->stype);
        }
    }
}

int npu_upgrade_run(struct npu_smi_operate_info *operate_info)
{
    int ret;
    if (operate_info->id == NPU_INVALID_VALUE) {
        printf("This command must input card id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (npu_check_is_has_mcu() == FALSE && !dcmi_board_chip_type_is_ascend_950()) {
        ret = NPU_ERR_CODE_NOT_SUPPORT;
        print_upgrade_result(ret, operate_info);
        return ret;
    }

    struct npu_operate_table_item npu_upgrade_op[] = {
        {operate_info->is_upgrade, do_npu_upgrade},
        {operate_info->is_query, do_npu_query_progress},
        {operate_info->is_version, do_npu_query_version},
        {operate_info->is_active, do_npu_active}
    };

    size_t table_index;
    size_t table_size = sizeof(npu_upgrade_op) / sizeof(npu_upgrade_op[0]);
    for (table_index = 0; table_index < table_size; table_index++) {
        if (npu_upgrade_op[table_index].fun_index) {
            ret = npu_upgrade_op[table_index].proc_func(operate_info);
            break;
        }
    }

    if (table_index == table_size) {
        printf("\nParameter error.\n\n");
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        gplog(LOG_OP, "This device does not support upgrading %s, card_id=%d, device_id=%d", \
              operate_info->stype, operate_info->id, operate_info->chip_id);
    }
    return ret;
}

#ifndef NPU_SMI_V2
void npu_upgrade_help(const char *name)
{
    printf("Usage: %s %s <-h|-t type|-q type|-b type|-a type> [Options...]\n", TOOL_NAME, name);
    printf("\nCommands:\n");
    printf("       -h, --help     Show this help text and exit\n");
    printf("       -t type        Upgrade device firmware\n");
    printf("       -q type        Query the upgrade status\n");
    printf("       -b type        Query the firmware version\n");
    printf("       -a type        Active the firmware version\n");
    printf("                      type: mcu bootloader vrd\n");
    printf("\nOptions:\n");
    printf("       -i ID          Upgrade for this card ID\n");
    printf("       -f file        The firmware file path\n");
}
#else
void npu_upgrade_help(const char *name)
{
    printf("Usage: %s %s <-h|-t type|-b type> [Options...]\n", TOOL_NAME, name);
    printf("\nCommands:\n");
    printf("       -h, --help     Show this help text and exit\n");
    printf("       -t type        Upgrade device firmware\n");
    printf("                      type: vrd\n");
    printf("       -b type        Query the firmware version\n");
    printf("                      type: vrd vdm\n");
    printf("\nOptions:\n");
    printf("       -i ID          Upgrade for this device ID\n");
    printf("       -f file        The firmware file path\n");
}
#endif


/*******************************************************************************
  函 数 名    : check_permission_and_environment
  功能描述    : 检查用户权限和运行环境，确保操作合法
  输入参数    :
                 argv : 命令行参数数组
                 argc : 命令行参数个数
  输出参数    : None
  返 回 值    : 成功返回 NPU_OK，失败返回对应错误码
*******************************************************************************/
int check_permission_and_environment(char **argv, int argc)
{
    int ret, i;
    for (i = PARAM_START_INDEX; i < argc; i = i + PARAM_STEP) {
        if ((strcmp(argv[i], "-t") == 0) || (strcmp(argv[i], "-a") == 0) || (strcmp(argv[i], "-q") == 0)) {
            // 非root用户除了能够查询版本信息之外，不允许做其他的操作
            ret = user_egid_check();
            if (ret != NPU_OK) {
                return ret;
            }
            // A5标卡支持该场景下的-t操作VRD升级
            if ((strcmp(argv[i], "-t") == 0) && (dcmi_get_product_type_inner() == DCMI_A350_A5_CARD)) {
                continue;
            }
            // A2/A3 卡只支持物理机
            if (npu_is_run_in_vm_or_docker()) {
                printf("This command cannot be executed on a VM or container.\n");
                return NPU_ERR_CODE_OPER_NOT_PERMITTED;
            }
        }
    }

    return NPU_OK;
}

int npu_upgrade_main(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int ret;
    ret = check_permission_and_environment(argv, argc);
    if (ret != NPU_OK) {
        return ret;
    }
    
    if (argc < LEAST_PARAMETER_NUM) {
        printf("\nThere has no options.\n\n");
        npu_upgrade_help(operate_info->name);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = parse_npu_upgrade_param(operate_info, argc, argv);
    if (ret == NPU_OK) {
        ret = npu_upgrade_run(operate_info);
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

    if ((ret == NPU_ERR_CODE_INVALID_PARAMETER) || (ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
        npu_upgrade_help(operate_info->name);
    }
    if (ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP) {
        ret = NPU_OK;
    }
    return ret;
}
