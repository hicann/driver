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
#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <limits.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <dirent.h>
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_interface_api.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_os_adapter.h"
#include "dcmi_product_judge.h"
#include "securec.h"
#include "dcmi_hpm_parse.h"

int dcmi_get_upgrade_status(int card_id, int index)
{
    int ret;
    int upgrade_times = 0;
    int upgrade_status = -1;
    while (upgrade_times < DCMI_UPGRADE_STATE_WAIT_TIME) {
        ret = dcmi_get_single_vrd_upgrade_status(card_id, &upgrade_status, index);
        if (ret != DCMI_OK) {
            sleep(DCMI_WAIT_MINID_TO_MCU_SWITCH);
            ret = dcmi_get_single_vrd_upgrade_status(card_id, &upgrade_status, index);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "Failed to query upgrade progress(bin index=%d, ret=%d).", index, ret);
                return ret;
            }
        }
        if (upgrade_status == DCMI_UPGRADE_IDLE || upgrade_status == DCMI_UPGRADE_NOT_SUPPORT) {
            return DCMI_OK;
        } else if (upgrade_status == DCMI_UPGRADE_UPGRADE_FAIL) {
            gplog(LOG_ERR, "Start device upgrade fail(bin index=%d, upgrade_status=%d).", index, upgrade_status);
            return DCMI_ERROR_CODE_BASE;
        }
        sleep(1); // 延迟1s
        upgrade_times++;
    }
    gplog(LOG_ERR, "Start device upgrade timeout(bin index=%d).", index);
    return DCMI_ERROR_CODE_BASE;
}

int dcmi_start_vrd_upgrade(int card_id, int index)
{
    int ret = DCMI_OK;
    for (int i = 0; i < DCMI_MCU_RETRY_TOTAL_TIMES; i++) {
        ret = dcmi_set_single_vrd_upgrade_stage(card_id, index);
        if (ret != DCMI_OK) {
            sleep(DCMI_WAIT_MINID_TO_MCU_SWITCH);
            ret = dcmi_set_single_vrd_upgrade_stage(card_id, index);
            if (ret != DCMI_OK) {
                break;
            }
        }
 
        sleep(3); // 延时3s
        ret = dcmi_get_upgrade_status(card_id, index);
        if (ret == DCMI_OK) {
            break;
        }
        
        gplog(LOG_ERR, "Vrd upgrade failed, retry again.(times=%d).", i + 1);
        sleep(5);    // 延时5S
    }
    return ret;
}

int dcmi_send_clear_file_msg(int card_id, int index)
{
    MCU_SMBUS_REQ_MSG mcu_req = {0};
    mcu_req.lun = DCMI_MCU_MSG_LUN;
    mcu_req.opcode = DCMI_MCU_VRD_CLEAR_FILE_OPCODE;
    mcu_req.arg = (unsigned char)index;
    mcu_req.offset = 0;
    mcu_req.lenth = 0;
    int ret = dcmi_vrd_set_info(card_id, &mcu_req, index);
    return ret;
}

/*******************************************************************************
  函 数 名		:  dcmi_vrd_params_check
  功能描述		:  检查vrd升级接口/npu-smi工具vrd升级命令 参数是否正确
  输入参数		:  card_id : 待升级的卡id
                  file : 指定升级的hpm文件路径
  输出参数		:  None
  返 回 值		:  检查通过，返回DCMI_OK，否则返回对应错误码
*******************************************************************************/
int dcmi_vrd_params_check(int card_id, const char *file)
{
    // 1.hpm文件检查
    if (file == NULL) {
        gplog(LOG_ERR, "The upgrade file is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    // 2.hpm文件格式检查
    int ret = dcmi_determine_file_type(file, "hpm", (int)strlen("hpm"));
    if (ret != DCMI_OK) {
        return ret;
    }

    // 3.card id范围检查，非范围内id则返回错误，不支持-1代表全部id
    ret = dcmi_check_card_id(card_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Check card id failed(card_id=%d, ret=%d).", card_id, ret);
        return ret;
    }

    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_compare_bin_name_index
  功能描述		:  处理vrd.tar.gz中的bin序列包， 分割得到索引值，进行升序排序
  输入参数		:  bin_name1 : 待转换的bin包名称，如vrd_09_0006_21.bin ==> 21.bin ==> 21
                  bin_name2 : 待转换的bin包名称，如vrd_09_0006_22.bin ==> 22.bin ==> 22
  输出参数		:  None
  返 回 值		:  升序排序
*******************************************************************************/
int dcmi_compare_bin_name_index(const void *bin_name1, const void *bin_name2)
{
    const char *str1 = (const char *)bin_name1;
    const char *str2 = (const char *)bin_name2;
    int index1, index2;
    int ret = dcmi_convert_str_to_int(strrchr(str1, '_') + 1, &index1);
    if (ret != DCMI_OK) {
        return ret;
    }
    ret = dcmi_convert_str_to_int(strrchr(str2, '_') + 1, &index2);
    if (ret != DCMI_OK) {
        return ret;
    }
    return index1 - index2;
}

/*******************************************************************************
  函 数 名		:  dcmi_parse_bin_name_info
  功能描述		:  解析VRD中所有bin文件名，提取供应商编号、版本号和索引号，
                  并将结果存储到结构体中
  输入参数		:  binFileNames : VRD中所有bin文件名列表
                  binFileNum : bin文件个数
  输出参数		:  vrdUpgradeInfo : 解析输出，存储解析出的供应商编号、版本号和索引号
  返 回 值		:  解析成功， 返回DCMI_OK；失败则返回相应错误码
*******************************************************************************/
int dcmi_parse_bin_name_info(char bin_file_names[][MAX_LENTH], int bin_file_num,
                             DCMI_VRD_APP_UPGRADE_INFO *vrd_upgrade_info)
{
    if (bin_file_names == NULL) {
        gplog(LOG_ERR, "Input parameter error: bin file names is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (vrd_upgrade_info == NULL) {
        gplog(LOG_ERR, "Output parameter error: vrd upgrade info is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    int ret, i;
    unsigned int supplier;
    char *file_name;
    for (i = 0; i < bin_file_num; i++) {
        file_name = strrchr(bin_file_names[i], '/');
        if (file_name == NULL) {
            gplog(LOG_ERR, "file path cant be strrchr by /.");
            return DCMI_ERR_CODE_INNER_ERR;
        }

        file_name++;
        ret = sscanf_s(file_name, "vrd_%02x_%04x_%d.bin", &supplier, &vrd_upgrade_info[i].version,
                       &vrd_upgrade_info[i].index);
        if (ret < DCMI_VRD_NAME_PARSE_PARAM_VALID) {
            gplog(LOG_ERR, "Call sscanf_s failed.(ret=%d).", ret);
            return DCMI_ERR_CODE_SECURE_FUN_FAIL;
        }
        ret = sprintf_s(vrd_upgrade_info[i].supplier, DCMI_SUPPLIER_NAME_LEN, "%02x", supplier);
        if (ret < EOK) {
            gplog(LOG_ERR, "Call sprintf_s failed.(ret=%d).", ret);
            return DCMI_ERR_CODE_SECURE_FUN_FAIL;
        }
    }
    return DCMI_OK;
}

static int check_parameters(DCMI_VRD_APP_UPGRADE_INFO *current_vrd_info,
    char bin_file_names[][MAX_LENTH], int *bin_file_num, char filter_file_names[][MAX_LENTH])
{
    if (current_vrd_info == NULL) {
        gplog(LOG_ERR, "Input parameter error: current vrd info is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if (bin_file_names == NULL) {
        gplog(LOG_ERR, "Input parameter error: bin file names is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if (bin_file_num == NULL) {
        gplog(LOG_ERR, "Input parameter error: bin file num is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (filter_file_names == NULL) {
        gplog(LOG_ERR, "filter_file_names is not null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_filter_bin_fileNames
  功能描述		:  将字符current_vrd_version转换结构体current_vrd_info表示
  输入参数		:  current_vrd_num : 当前 VRD 的个数
                  current_vrd_info : 当前 VRD 的详细信息
                  bin_file_names : 升级路径中所有bin文件名
  输出参数		:  bin_file_num : 过滤后的bin文件名个数
                  filter_file_names : 过滤后的bin文件名
  返 回 值		:  过滤成功， 返回DCMI_OK；失败则返回相应错误码
*******************************************************************************/
int dcmi_filter_bin_fileNames(int current_vrd_num, DCMI_VRD_APP_UPGRADE_INFO *current_vrd_info,
    char bin_file_names[][MAX_LENTH], int *bin_file_num, char filter_file_names[][MAX_LENTH])
{
    int ret = check_parameters(current_vrd_info, bin_file_names, bin_file_num, filter_file_names);
    if (ret != DCMI_OK) {
        return ret;
    }

    int file_num = *bin_file_num;
    int filtered_file_num = 0;
    // 解析升级路径中版本号和厂商信息
    DCMI_VRD_APP_UPGRADE_INFO vrd_upgrade_info[DCMI_MAX_VRD_FILE_NUM] = {0};
    ret = dcmi_parse_bin_name_info(bin_file_names, file_num, vrd_upgrade_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_parse_bin_name_info fail(ret=%d).", ret);
        return ret;
    }
    
    // 先找校验文件的，再找其他符合条件的
    for (int i = 0; i < file_num; i++) {
        if (strstr(bin_file_names[i], "vrd_00_") != NULL) {
            ret = sprintf_s(filter_file_names[filtered_file_num], MAX_LENTH, "%s", bin_file_names[i]);
            if (ret < EOK) {
                gplog(LOG_ERR, "Call sprintf_s fail.(ret=%d).", ret);
                return DCMI_ERR_CODE_SECURE_FUN_FAIL;
            }
            filtered_file_num++;
            break;
        }
    }

    for (int i = 0; i < file_num; i++) {
        if (strstr(bin_file_names[i], "vrd_00_") != NULL) {
            continue;
        }
        // 当前的binFileNames顺序和vrdUpgradeInfo的顺序一一对应，找到了vrdUpgradeInfo的下标即是binFileName的下标
        for (int j = 0; j < current_vrd_num; j++) {
            if (strcmp(vrd_upgrade_info[i].supplier, current_vrd_info[j].supplier) != 0 ||
                (vrd_upgrade_info[i].index != current_vrd_info[j].index)) {
                continue;
            }
            // 比较版本防止回退
            if (current_vrd_info[j].version >= vrd_upgrade_info[i].version) {
                continue;
            }
            ret = sprintf_s(filter_file_names[filtered_file_num], MAX_LENTH, "%s", bin_file_names[i]);
            if (ret < EOK) {
                gplog(LOG_ERR, "Call sprintf_s fail.(ret=%d).", ret);
                return DCMI_ERR_CODE_SECURE_FUN_FAIL;
            }
            filtered_file_num++;
            break;
        }
    }
    *bin_file_num = filtered_file_num;
    return DCMI_OK;
}

int dcmi_transport_vrd_file(int card_id, char *fileName, int index, int cur_bin_idx, int bin_num)
{
    int ret;
    int upgrade_status = DCMI_UPGRADE_STATE_NONE;
    // 传输文件，最多重试10次
    for (int times = 0; times < DCMI_TRY_TRANS_FILE_TIMES; times++) {
        DCMI_VRD_PER_UPGRADE_INFO per_vrd_info = dcmi_set_vrd_per_upgrade_info(card_id, index, cur_bin_idx,
                                                                               bin_num, false);
        ret = dcmi_trans_vrd_file(fileName, &per_vrd_info);
        if (ret == DCMI_OK || ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            break;
        }
        sleep(DCMI_WAIT_MINID_TO_MCU_SWITCH);
    }
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_trans_vrd_file fail(card_id=%d, ret=%d).", card_id, ret);
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
        gplog(LOG_ERR, "Call dcmi_get_single_vrd_upgrade_status fail(card_id=%d, ret=%d).", card_id, ret);
        return ret;
    }

    sleep(5); // 延时5s
    // 启动升级
    ret = dcmi_start_vrd_upgrade(card_id, index);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "Upgrade the VRD firmware of NPU Board(card_id=%d, result=%s, ret=%d).", card_id, "failed", ret);
        return ret;
    }
    // 发送清除命令
    ret = dcmi_send_clear_file_msg(card_id, index);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_send_clear_file_msg fail(card_id=%d, ret=%d).", card_id, ret);
    }
    gplog(LOG_OP, "Upgrade the VRD firmware of NPU Board(card_id=%d, result=%s, ret=%d).",
        card_id, (ret == DCMI_OK) ?  "success" : "failed", ret);
    return ret;
}

/*******************************************************************************
  函 数 名		:  dcmi_transport_vrd_upgrade_firmware
  功能描述		:  分批bin_file_num上传bin文件进行固件升级
  输入参数		:  card_id : 卡id
                  bin_file_names : 过滤后的bin文件名列表
                  bin_file_num : bin文件数量
  输出参数		:  None
  返 回 值		:  成功返回DCMI_OK，失败返回对应错误码
*******************************************************************************/
int dcmi_transport_vrd_upgrade_firmware(int card_id, char bin_file_names[][MAX_LENTH], int bin_file_num)
{
    int ret;
    int index = -1;
    
    for (int i = 0; i < bin_file_num; i++) {
        ret = dcmi_convert_str_to_int(strrchr(bin_file_names[i], '_') + 1, &index);
        if (ret != DCMI_OK) {
            return ret;
        }
        ret = dcmi_transport_vrd_file(card_id, bin_file_names[i], index, i + 1, bin_file_num);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Vrd upgrade bin failed.(bin_file_name=%s).", bin_file_names[i]);
            return ret;
        }
        sleep(5); // 延时5S，等待AO清理flash
    }

    return ret;
}

/*******************************************************************************
  函 数 名		:  dcmi_set_vrd_info_from_version
  功能描述		:  将字符current_vrd_version转换结构体current_vrd_info表示
  输入参数		:  current_vrd_version : VRD版本信息字符
  输出参数		:  current_vrd_num : 当前 VRD 的数量
                  current_vrd_info : 接收存储当前 VRD 的详细信息
  返 回 值		:  转换成功， 返回DCMI_OK；转换失败，返回错误码
*******************************************************************************/
int dcmi_set_vrd_info_from_version(char *current_vrd_version, int len, DCMI_VRD_APP_UPGRADE_INFO *current_vrd_info,
                                   int *current_vrd_num)
{
    if (current_vrd_version == NULL) {
        gplog(LOG_ERR, "Input parameter error: current vrd version is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (current_vrd_info == NULL) {
        gplog(LOG_ERR, "Input parameter error: current vrd info is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (current_vrd_num == NULL) {
        gplog(LOG_ERR, "Input parameter error: current vrd num is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    int vrd_num = (int)current_vrd_version[0];
    vrd_num = vrd_num > DCMI_MAX_VRD_FILE_NUM ? DCMI_MAX_VRD_FILE_NUM : vrd_num;
    int ret;
    for (int i = 0; i < vrd_num; i++) {
        int index_offset = i * DCMI_VRD_APP_INFO_LEN + DCMI_VRD_NUM_LEN;
        char *index = current_vrd_version + index_offset;
        char *supplier = index + DCMI_VRD_APP_INDEX_LEN;
        char *version = supplier + DCMI_VRD_APP_SUPPLIER_LEN;
        
        current_vrd_info[i].index = *index;
        ret = sprintf_s(current_vrd_info[i].supplier, DCMI_SUPPLIER_NAME_LEN, "%02x", *supplier);
        if (ret < EOK) {
            gplog(LOG_ERR, "Call sprintf_s fail(ret=%d).", ret);
            return DCMI_ERR_CODE_SECURE_FUN_FAIL;
        }
        current_vrd_info[i].version = (((unsigned char)*(version + 1)) << DCMI_BIT_SHIFT) | ((unsigned char)*version);
    }
    *current_vrd_num = vrd_num;
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_get_vrd_current_version
  功能描述		:  获取指定id的卡片当前的VRD版本信息
  输入参数		:  card_id : 卡id
  输出参数		:  current_vrd_num : 当前 VRD 的数量
                  current_vrd_info : 接收存储当前 VRD 的详细信息
  返 回 值		:  获取成功， 返回DCMI_OK；获取失败，返回错误码
*******************************************************************************/
int dcmi_get_vrd_current_version(int card_id, DCMI_VRD_APP_UPGRADE_INFO *current_vrd_info, int *current_vrd_num)
{
    char current_vrd_version[MAX_LENTH] = {0};
    int ret = dcmi_get_upgradable_vrd_version(card_id, current_vrd_version, MAX_LENTH);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get current vrd version(card_id=%d, ret=%d).", card_id, ret);
        return ret;
    }
    return dcmi_set_vrd_info_from_version(current_vrd_version, MAX_LENTH, current_vrd_info, current_vrd_num);
}

/*******************************************************************************
  函 数 名		:  dcmi_parse_single_vrd_hpm
  功能描述		:  处理单个vrd hpm升级核心流程
  输入参数		:  card_id : 待升级的卡id
                  file : 指定升级的hpm文件路径
  输出参数		:  None
  返 回 值		:  升级结果ret，通过，返回DCMI_OK，否则返回对应错误码
*******************************************************************************/
int dcmi_parse_single_vrd_hpm(int card_id, const char *file)
{
    // 1.从hpm文件中解析出bin文件
    int bin_file_num = 0;
    char dir_path[MAX_LENTH] = {0};
    char bin_file_names[DCMI_MAX_VRD_FILE_NUM][MAX_LENTH] = { { 0 } };
    int ret = dcmi_parse_bin_file_from_vrd_hpm(card_id, file, bin_file_names, &bin_file_num, dir_path);
    if (ret != DCMI_OK) {
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
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }

    // 4.过滤排序后的bin文件，得到需要上传的filter_file_names、bin_file_num
    char filter_file_names[DCMI_MAX_VRD_FILE_NUM][MAX_LENTH] = { { 0 } };
    ret = dcmi_filter_bin_fileNames(current_vrd_num, current_vrd_info, bin_file_names,
                                    &bin_file_num, filter_file_names);
    if (ret != DCMI_OK) {
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }
    // 如果当前文件夹里只存在vrd_00的校验文件，则不进行vrd升级
    if (bin_file_num == 1 && strstr(filter_file_names[0], "vrd_00_") != NULL) {
        gplog(LOG_OP, "Card %d no need to upgrade vrd.", card_id);
        (void)dcmi_remove_dir(dir_path);
        return DCMI_OK;
    }

    // 5.传递vrd固件
    ret = dcmi_transport_vrd_upgrade_firmware(card_id, filter_file_names, bin_file_num);
    // 传包后删除目录
    (void)dcmi_remove_dir(dir_path);
    return ret;
}

/*******************************************************************************
  函 数 名		:  dcmi_parse_bin_file_from_vrd_hpm
  功能描述		:  将hpm文件中vrd.tar.gz文件解析到，另存dir_path下，再解压成bin文件
  输入参数		:  card_id : 待升级的卡id
                  file : 指定升级的hpm文件路径
  输出参数		:  bin_file_names  : 存放解析出的bin文件路径列表
                  bin_file_num : 解析出的bin文件个数
                  dir_path : 存放解析出的bin文件路径
  返 回 值		:  匹配成功，返回DCMI_OK，否则返回对应错误码
*******************************************************************************/
int dcmi_parse_bin_file_from_vrd_hpm(int card_id, const char *file, char bin_file_names[][MAX_LENTH],
    int *bin_file_num, char *dir_path)
{
    if ((file == NULL) || (dir_path == NULL) || (bin_file_names == NULL) || (bin_file_num == NULL)) {
        gplog(LOG_ERR, "Input parameter error: file, bin_file or dir_path is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    char hpm_dir[DCMI_BUFF_MAX_LEN] = {0};
    char tar_file_path[DCMI_BUFF_MAX_LEN] = {0};

    // 1.获取hpm文件所在的目录
    int ret = dcmi_get_file_directory(file, hpm_dir, DCMI_BUFF_MAX_LEN);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Get file directory failed.(ret=%d).", ret);
        return ret;
    }

    // 2.在hpm文件目录下创建package目录用于存放解压后的包，将解析出vrd.tar.gz文件放在新生成的package目录下
    // dir_path: /run/vrd_upgrade_$(card_id)
    // tar_file_path: /run/vrd_upgrade_$(card_id)/vrd.tar.gz
    ret = dcmi_generate_vrd_package_dir(hpm_dir, dir_path, tar_file_path, card_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Generate directory failed.(ret=%d).", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    // 3.从hpm签名文件中解析出vrd.tar.gz文件
    ret = dcmi_generate_vrd_image_file(card_id, file, tar_file_path);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Generate vrd.tar.gz failed.(ret=%d).", ret);
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }
    // 将vrd.tar.gz解压成bin文件，和hpm文件放在同一目录下
    ret = dcmi_extract_targz_package(tar_file_path, dir_path);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Extract vrd.tar.gz failed.(ret=%d).", ret);
        (void)dcmi_remove_file(tar_file_path);
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }
    (void)dcmi_remove_file(tar_file_path);
    ret = dcmi_list_vrd_files(dir_path, bin_file_names, bin_file_num);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Get vrd upgrade file path failed.(ret=%d).", ret);
        (void)dcmi_remove_file(tar_file_path);
        (void)dcmi_remove_dir(dir_path);
        return ret;
    }
    return DCMI_OK;
}

// 列出所有解压后的文件名
int dcmi_list_vrd_files(char *path, char fileNames[][MAX_LENTH], int *fileNum)
{
    int ret;
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(path)) == NULL) {
        gplog(LOG_ERR, "Open dir error.");
        return DCMI_ERR_CODE_FILE_OPERATE_FAIL;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if (strstr(entry->d_name, "vrd_") != NULL && (*fileNum) < DCMI_MAX_VRD_FILE_NUM) {
            ret = sprintf_s(fileNames[*fileNum], MAX_LENTH, "%s/%s", path, entry->d_name);
            if (ret < EOK) {
                gplog(LOG_ERR, "Call sprintf_s fail.(ret=%d).", ret);
                closedir(dir);
                return DCMI_ERR_CODE_SECURE_FUN_FAIL;
            }
            (*fileNum)++;
        }
    }
    closedir(dir);
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_generate_vrd_package_dir
  功能描述		:  生成一个用于存储 VRD包的目录，并将 VRD 文件放置在该目录下
  输入参数		:  hpm_dir : 表示 HPM 文件的目录路径
                  card_id : 卡片ID
  输出参数		:  file_dir : 生成的临时目录路径
                  tar_file_path : 生成的 tar.gz 文件路径
  返 回 值		:  成功返回 DCMI_OK，失败返回对应错误码
*******************************************************************************/
int dcmi_generate_vrd_package_dir(const char *hpm_dir, char *file_dir, char *tar_file_path, int card_id)
{
    char path[PATH_MAX + 1] = {0x00};
    int ret;

    // 1.检查hpm_dir是否合法
    if (dcmi_check_filename(hpm_dir, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "File path is illegal.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    // 2. 拼接得到临时路径 file_dir: /run/vrd_upgrade_1
    ret = snprintf_s(file_dir, MAX_LENTH, MAX_LENTH - 1, "%s_%d", VRD_UPGRADE_TEMP_PATH, card_id);
    if (ret <= 0) {
        gplog(LOG_ERR, "Call snprintf_s failed.(ret=%d).", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }
    // 3.检查file_dir目录是否存在，不存在则创建
    if (access(file_dir, F_OK) != DCMI_OK) {
        if (mkdir(file_dir, S_IRUSR | S_IWUSR) < 0) {
            gplog(LOG_ERR, "Make dir failed.(file_dir=%s, ret=%d).", file_dir, ret);
            return DCMI_ERR_CODE_INNER_ERR;
        }
    }

    // 4.将vrd.tar.gz文件和hpm文件放在同一目录下 tar_file_path:/run/vrd_upgrade_1/vrd.tar.gz
    ret = snprintf_s(tar_file_path, MAX_LENTH, MAX_LENTH - 1, "%s/%s", file_dir, "vrd.tar.gz");
    if (ret <= 0) {
        gplog(LOG_ERR, "Call snprintf_s failed.(ret=%d).", ret);
        (void)dcmi_remove_dir(file_dir);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_generate_vrd_image_file
  功能描述		:  从源文件hpm中读取特定数据，并且写入到目标文件tar_file中
  输入参数		:  card_id : 卡片ID
                  cms_file : 源文件路径
                  tar_file : 目标文件路径
  输出参数		:  None
  返 回 值		:  成功返回 DCMI_OK，失败返回对应错误码
*******************************************************************************/
int dcmi_generate_vrd_image_file(int card_id, const char *cms_file, const char *tar_file)
{
    unsigned int rec_offset = 0;
    unsigned int rec_len = 0;
    unsigned char *rec_data = NULL;
    int ret = dcmi_get_vrd_image_info(cms_file, &rec_offset, &rec_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Get upgrade record info failed.(ret=%d).", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    rec_data = calloc(1, DCMI_FILE_MAX_LENGTH);
    if (rec_data == NULL) {
        gplog(LOG_ERR, "Call calloc fail.");
        return DCMI_ERR_CODE_MEM_OPERATE_FAIL;
    }

    // 读出镜像文件内容
    ret = dcmi_get_file_data(cms_file, rec_data, DCMI_FILE_MAX_LENGTH, rec_offset, rec_len);
    if (ret != 0) {
        gplog(LOG_ERR, "Get upgrade record failed.(ret=%d).", ret);
        free(rec_data);
        rec_data = NULL;
        return DCMI_ERR_CODE_INNER_ERR;
    }

    // 生成镜像文件
    ret = dcmi_write_data_to_file(tar_file, (const char *)rec_data, rec_len, rec_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Write upgrade record to failed.(ret=%d).", ret);
        free(rec_data);
        rec_data = NULL;
        return DCMI_ERR_CODE_INNER_ERR;
    }

    free(rec_data);
    rec_data = NULL;
    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_get_cms_file_item
  功能描述		:  从CMS格式文件中读取指定偏移处的十六进制数值
  输入参数		:  cmsFile  : CMS格式配置文件的路径
                  offset  : 要读取的数值项在文件中的字节偏移量
  输出参数		:  val : 读取到的十六进制数值，保存到cmsFileHead结构体中
  返 回 值		:  成功返回 DCMI_OK，失败返回对应错误码
*******************************************************************************/
unsigned int dcmi_get_cms_file_item(const char *cmsFile, int offset, unsigned int *val)
{
    int ret;
    char buf[DCMI_CMS_LEN_CHAR_NUM + 1] = {0};

    if (cmsFile == NULL) {
        gplog(LOG_ERR, "Input parameter error: cmsFile is null.");
        return DCMI_ERR_CODE_INNER_ERR;
    }

    ret = dcmi_get_file_data(cmsFile, (unsigned char *)&buf, DCMI_CMS_LEN_CHAR_NUM, offset, DCMI_CMS_LEN_CHAR_NUM);
    if (ret != 0) {
        gplog(LOG_ERR, "read cms file item failed.%d.", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    ret = sscanf_s(buf, "%x", val);
    if (ret <= 0) {
        gplog(LOG_ERR, "call sscanf_s failed.%d.", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_get_cms_file_head
  功能描述		:  获取cms文件头信息，保存到cmsFileHead结构体中
  输入参数		:  cms_file : 源文件路径
  输出参数		:  cmsFileHead : 存储cms文件头信息的结构体
  返 回 值		:  成功返回 DCMI_OK，失败返回对应错误码
*******************************************************************************/
int dcmi_get_cms_file_head(const char *cmsFile, DCMI_CMS_FILE_HEADER *cmsFileHead)
{
    unsigned int ret;

    if ((cmsFile == NULL) || (cmsFileHead == NULL)) {
        gplog(LOG_ERR, "Input parameter error: cmsFile or cmsFileHead is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    /* 0:读取fileNum */
    ret = dcmi_get_cms_file_item(cmsFile, DCMI_CMS_FILE_INFO_BASE_ADDR, &cmsFileHead->fileNum);

    /* 1:读取fileListId */
    ret |= dcmi_get_cms_file_item(cmsFile, DCMI_CMS_FILE_LIST_ID_OFFSET,
                                  &cmsFileHead->cmsFile[DCMI_CMS_FILE_LIST].fileId);

    /* 2:读取fileListLen */
    ret |= dcmi_get_cms_file_item(cmsFile, DCMI_CMS_FILE_LIST_LEN_OFFSET,
                                  &cmsFileHead->cmsFile[DCMI_CMS_FILE_LIST].fileLen);

    /* 3:读取signFileId */
    ret |= dcmi_get_cms_file_item(cmsFile, DCMI_CMS_SIGN_FILE_ID_OFFSET,
                                  &cmsFileHead->cmsFile[DCMI_CMS_SIGN_FILE].fileId);

    /* 4:读取signFileLen */
    ret |= dcmi_get_cms_file_item(cmsFile, DCMI_CMS_SIGN_FILE_LEN_OFFSET,
                                  &cmsFileHead->cmsFile[DCMI_CMS_SIGN_FILE].fileLen);

    /* 5:读取crlFileId */
    ret |= dcmi_get_cms_file_item(cmsFile, DCMI_CMS_CRL_FILE_ID_OFFSET,
                                  &cmsFileHead->cmsFile[DCMI_CMS_CRL_FILE].fileId);

    /* 6:读取crlFileLen */
    ret |= dcmi_get_cms_file_item(cmsFile, DCMI_CMS_CRL_FILE_LEN_OFFSET,
                                  &cmsFileHead->cmsFile[DCMI_CMS_CRL_FILE].fileLen);
    if (ret != 0) {
        gplog(LOG_ERR, "Get cms file head item failed.%u.", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    return DCMI_OK;
}

/*******************************************************************************
  函 数 名		:  dcmi_get_vrd_image_info
  功能描述		:  从指定cms_file中获取vrd.tar.gz文件的偏移量recOffset和长度recLen
  输入参数		:  cms_file : 指定的hpm文件路径
  输出参数		:  recOffset : vrd.tar.gz在hpm中的偏移量
                  recLen : vrd.tar.gz在hpm中的长度
  返 回 值		:  成功返回 DCMI_OK，失败返回对应错误码
*******************************************************************************/
int dcmi_get_vrd_image_info(const char *cms_file, unsigned int *recOffset, unsigned int *recLen)
{
    DCMI_CMS_FILE_HEADER cmsFileHead = {0};
    unsigned int recHeadOffset, recHeadLen;
    unsigned int hpmLen;
    DCMI_UPGRADE_RECORD_HEAD upRecHead = {{0}};
    unsigned int temRecLen = 0;
    unsigned int i = 0;
    int ret = dcmi_get_cms_file_head(cms_file, &cmsFileHead);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Get file header failed.(ret=%d).", ret);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    ret = dcmi_get_file_len_by_path(cms_file, &hpmLen);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call get_file_length failed.(ret=%d).", ret);
        return ret;
    }

    recHeadOffset = dcmi_get_image_file_offset(&cmsFileHead) + sizeof(DCMI_IMAGE_HEADER) +
        sizeof(DCMI_UPGRADE_ACTION_TYPE);
    recHeadLen = sizeof(DCMI_UPGRADE_RECORD_HEAD);

    // 获取镜像文件在hpm文件中的偏移和长度
    while (recHeadOffset < hpmLen) {
        ret = dcmi_get_file_data(cms_file, (unsigned char *)&upRecHead, recHeadLen, recHeadOffset, recHeadLen);
        if (ret != 0) {
            gplog(LOG_ERR, "Get upgrade record header failed.(record_index=%u, ret=%d).", i, ret);
            return DCMI_ERR_CODE_INNER_ERR;
        }

        temRecLen = dcmi_get_image_record_length(&upRecHead.bankInformation[0]);
        if (strstr((const char *)upRecHead.bankInformation[0].filePath, "vrd.tar.gz") != NULL) {
            break;
        }
        recHeadOffset = recHeadOffset + recHeadLen + temRecLen;
        i++;
    }

    if (recHeadOffset >= hpmLen) {
        gplog(LOG_ERR, "Find file image failed.");
        return DCMI_ERR_CODE_INNER_ERR;
    }

    *recOffset = recHeadOffset + recHeadLen;
    *recLen = temRecLen;
    gplog(LOG_OP, "Upgrade record file path success.(record_index=%u).", i);
    return DCMI_OK;
}

int dcmi_get_file_len_by_path(const char *file, unsigned int *file_len)
{
    FILE *fp = NULL;

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
    if (dcmi_check_filename(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
#else
    char path[MAX_PATH + 1] = {0x00};
    if (dcmi_check_filename(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
#endif
    if ((fp = fopen((const char *)path, "r")) == NULL) {
        gplog(LOG_ERR, "open file failed errno is %d.", errno);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    (void)fseek(fp, 0, SEEK_END);
    *file_len = ftell(fp);

    (void)fclose(fp);
    return DCMI_OK;
}

unsigned int dcmi_get_file_list_offset(DCMI_CMS_FILE_HEADER *cmsFileHead)
{
    // 1个数据为文件个数，每个文件包含文件id和文件长度2个数据，每个数据长度是8个字节
    return DCMI_CMS_FILE_INFO_BASE_ADDR + (cmsFileHead->fileNum * 2 + 1) * DCMI_CMS_LEN_CHAR_NUM;
}

unsigned int dcmi_get_sign_file_offset(DCMI_CMS_FILE_HEADER *cmsFileHead)
{
    return dcmi_get_file_list_offset(cmsFileHead) + cmsFileHead->cmsFile[DCMI_CMS_FILE_LIST].fileLen;
}

unsigned int dcmi_get_crl_file_offset(DCMI_CMS_FILE_HEADER *cmsFileHead)
{
    return dcmi_get_sign_file_offset(cmsFileHead) + cmsFileHead->cmsFile[DCMI_CMS_SIGN_FILE].fileLen;
}

// mcuimage.hpm文件偏移
unsigned int dcmi_get_image_file_offset(DCMI_CMS_FILE_HEADER *cmsFileHead)
{
    return dcmi_get_crl_file_offset(cmsFileHead) + cmsFileHead->cmsFile[DCMI_CMS_CRL_FILE].fileLen;
}

unsigned int dcmi_make_dword(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    return (((((unsigned int)a) & 0xff) << DCMI_SHIFT_TWENTY_FOUR_BITS) |
        ((((unsigned int)b) & 0xff) << DCMI_SHIFT_SIXTEEN_BITS) |
        ((((unsigned int)c) & 0xff) << DCMI_SHIFT_EIGHT_BITS) | (((unsigned int)d) & 0xff));
}

// 镜像文件长度
unsigned int dcmi_get_image_record_length(DCMI_BANK_INFO *bankInfo)
{
    return dcmi_make_dword(bankInfo->length[DCMI_DWORD_HIGHEST_BYTE], bankInfo->length[DCMI_DWORD_SEC_HIGHEST_BYTE],
        bankInfo->length[DCMI_DWORD_SEC_LOWEST_BYTE], bankInfo->length[DCMI_DWORD_LOWEST_BYTE]);
}
