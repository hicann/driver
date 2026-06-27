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
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif
#include "securec.h"
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_mcu_intf.h"
#include "npu_common.h"
#include "npu_file_operate.h"
#include "npu_hpm_parse.h"

// 判断文件类型
int determine_file_type(const char *file, const char *fileType, int typeLen)
{
    int ret, i;

    if ((file == NULL) || (fileType == NULL)) {
        gplog(LOG_ERR, "file or fileType pointer is NULL.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif

    if (check_filename(file, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    for (i = (int)strlen(path) - 1; i >= 0; i--) {
        if (path[i] == '.') {
            ret = strncmp((const char *)&path[i + 1], fileType, typeLen);
            if (ret != 0) {
                gplog(LOG_INFO, "file is not %s file.", fileType);
                return NPU_ERR_CODE_SECURE_FUN_FAIL;
            }
            return NPU_OK;
        }
    }

    gplog(LOG_ERR, "can not find the file.");
    return NPU_ERR_CODE_INNER_ERR;
}

unsigned int get_file_list_offset(CMS_FILE_HEADER *cmsFileHead)
{
    // 1个数据为文件个数，每个文件包含文件id和文件长度2个数据，每个数据长度是8个字节
    return CMS_FILE_INFO_BASE_ADDR + (cmsFileHead->fileNum * 2 + 1) * CMS_LEN_CHAR_NUM;
}

unsigned int get_sign_file_offset(CMS_FILE_HEADER *cmsFileHead)
{
    return get_file_list_offset(cmsFileHead) + cmsFileHead->cmsFile[CMS_FILE_LIST].fileLen;
}

unsigned int get_crl_file_offset(CMS_FILE_HEADER *cmsFileHead)
{
    return get_sign_file_offset(cmsFileHead) + cmsFileHead->cmsFile[CMS_SIGN_FILE].fileLen;
}

// mcuimage.hpm文件偏移
unsigned int get_image_file_offset(CMS_FILE_HEADER *cmsFileHead)
{
    return get_crl_file_offset(cmsFileHead) + cmsFileHead->cmsFile[CMS_CRL_FILE].fileLen;
}

unsigned int make_dword(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    return (((((unsigned int)a) & 0xff) << SHIFT_TWENTY_FOUR_BITS) |
        ((((unsigned int)b) & 0xff) << SHIFT_SIXTEEN_BITS) |
        ((((unsigned int)c) & 0xff) << SHIFT_EIGHT_BITS) | (((unsigned int)d) & 0xff));
}

// 镜像文件长度
unsigned int get_image_record_length(BANK_INFO *bankInfo)
{
    return make_dword(bankInfo->length[DWORD_HIGHEST_BYTE], bankInfo->length[DWORD_SEC_HIGHEST_BYTE],
        bankInfo->length[DWORD_SEC_LOWEST_BYTE], bankInfo->length[DWORD_LOWEST_BYTE]);
}

// 从文件中读取一定数据
unsigned int get_cms_file_item(const char *cmsFile, int offset, unsigned int *val)
{
    int ret;
    char buf[CMS_LEN_CHAR_NUM + 1] = {0};

    if (cmsFile == NULL) {
        gplog(LOG_ERR, "Input parameter error: cmsFile is null.\n");
        return NPU_ERR;
    }

    ret = get_file_data(cmsFile, (unsigned char *)&buf, CMS_LEN_CHAR_NUM, offset, CMS_LEN_CHAR_NUM);
    if (ret != 0) {
        gplog(LOG_ERR, "read cms file item failed.%d.\n", ret);
        return NPU_ERR;
    }

    ret = sscanf_s(buf, "%x", val);
    if (ret <= 0) {
        gplog(LOG_ERR, "call sscanf_s failed.%d.\n", ret);
        return NPU_ERR;
    }

    return NPU_OK;
}

int get_cms_file_head(const char *cmsFile, CMS_FILE_HEADER *cmsFileHead)
{
    unsigned int ret;

    if ((cmsFile == NULL) || (cmsFileHead == NULL)) {
        gplog(LOG_ERR, "Input parameter error: cmsFile or cmsFileHead is null.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    /* 0:读取fileNum */
    ret = get_cms_file_item(cmsFile, CMS_FILE_INFO_BASE_ADDR, &cmsFileHead->fileNum);

    /* 1:读取fileListId */
    ret |= get_cms_file_item(cmsFile, CMS_FILE_LIST_ID_OFFSET, &cmsFileHead->cmsFile[CMS_FILE_LIST].fileId);

    /* 2:读取fileListLen */
    ret |= get_cms_file_item(cmsFile, CMS_FILE_LIST_LEN_OFFSET, &cmsFileHead->cmsFile[CMS_FILE_LIST].fileLen);

    /* 3:读取signFileId */
    ret |= get_cms_file_item(cmsFile, CMS_SIGN_FILE_ID_OFFSET, &cmsFileHead->cmsFile[CMS_SIGN_FILE].fileId);

    /* 4:读取signFileLen */
    ret |= get_cms_file_item(cmsFile, CMS_SIGN_FILE_LEN_OFFSET, &cmsFileHead->cmsFile[CMS_SIGN_FILE].fileLen);

    /* 5:读取crlFileId */
    ret |= get_cms_file_item(cmsFile, CMS_CRL_FILE_ID_OFFSET, &cmsFileHead->cmsFile[CMS_CRL_FILE].fileId);

    /* 6:读取crlFileLen */
    ret |= get_cms_file_item(cmsFile, CMS_CRL_FILE_LEN_OFFSET, &cmsFileHead->cmsFile[CMS_CRL_FILE].fileLen);
    if (ret != 0) {
        gplog(LOG_ERR, "Get cms file head item failed.%u.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

int get_image_info(MCU_UPGRADE_INFO *upgrade_info, const char *cms_file, unsigned int *rec_offset,
                   unsigned int *rec_len)
{
    int ret;
    unsigned int recHeadOffset, recHeadLen, hpmLen;
    unsigned int temRecLen = 0;
    unsigned int i = 0;
    CMS_FILE_HEADER cmsFileHead = { 0 };
    UPGRADE_RECORD_HEAD upRecHead = { { 0 } };

    bool check_invalid = ((cms_file == NULL) || (rec_offset == NULL) || (rec_len == NULL) || (upgrade_info == NULL));
    if (check_invalid) {
        gplog(LOG_ERR, "Input parameter is null.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    // 获取cms文件头信息
    ret = get_cms_file_head(cms_file, &cmsFileHead);
    if (ret != 0) {
        gplog(LOG_ERR, "Get file header failed.%d.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    recHeadOffset = get_image_file_offset(&cmsFileHead) + sizeof(IMAGE_HEADER) + sizeof(UPGRADE_ACTION_TYPE);
    recHeadLen = sizeof(UPGRADE_RECORD_HEAD);

    ret = get_file_length(cms_file, &hpmLen);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "call get_file_length failed.%d.", ret);
        return ret;
    }

    // 获取镜像文件在hpm文件中的偏移和长度
    while (recHeadOffset < hpmLen) {
        ret = get_file_data(cms_file, (unsigned char *)&upRecHead, recHeadLen, recHeadOffset, recHeadLen);
        if (ret != 0) {
            gplog(LOG_ERR, "Get upgrade record%u header failed.%d.\n", i, ret);
            return NPU_ERR_CODE_INNER_ERR;
        }

        temRecLen = get_image_record_length(&upRecHead.bankInformation[0]);
        // 兼容新老MCU，旧版本MCU中只有一个mcu.tar.gz，通过判断是否存在mcu.tar.gz确认当前升级的MCU固件为新/旧固件
        if (strstr((const char *)upRecHead.bankInformation[0].filePath, "mcu.tar.gz") != NULL) {
            upgrade_info->is_new_mcu_package = 0;
            break;
        } else if (strstr((const char *)upRecHead.bankInformation[0].filePath, upgrade_info->tar_name) != NULL) {
            upgrade_info->is_new_mcu_package = 1;
            break;
        }
        recHeadOffset = recHeadOffset + recHeadLen + temRecLen;
        i++;
    }

    if (recHeadOffset >= hpmLen) {
        gplog(LOG_ERR, "find file image failed.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }

    *rec_offset = recHeadOffset + recHeadLen;
    *rec_len = temRecLen;
    gplog(LOG_OP, "upgrade record%u file path success.\n", i);
    return NPU_OK;
}

int generate_image_file(int card_id, MCU_UPGRADE_INFO *upgrade_info, const char *cms_file, const char *tar_file)
{
    int ret;
    unsigned int recOffset = 0;
    unsigned int recLen = 0;
    unsigned char *recData = NULL;

    if ((cms_file == NULL) || (tar_file == NULL) || (upgrade_info == NULL)) {
        gplog(LOG_ERR, "Input parameter is null.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    // 读出镜像文件在cms文件中的偏移和长度
    ret = get_image_info(upgrade_info, cms_file, &recOffset, &recLen);
    if (ret != 0) {
        gplog(LOG_ERR, "Get upgrade record info failed.%d.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    recData = calloc(1, FILE_MAX_LENGTH);
    if (recData == NULL) {
        gplog(LOG_ERR, "call calloc fail.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    // 读出镜像文件内容
    ret = get_file_data(cms_file, recData, FILE_MAX_LENGTH, recOffset, recLen);
    if (ret != 0) {
        gplog(LOG_ERR, "Get upgrade record failed.%d.\n", ret);
        free(recData);
        recData = NULL;
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 生成镜像文件
    ret = write_data_to_file(tar_file, (const char *)recData, recLen, recLen);
    if (ret != 0) {
        gplog(LOG_ERR, "Write upgrade record to failed.%d.\n", ret);
        free(recData);
        recData = NULL;
        return NPU_ERR_CODE_INNER_ERR;
    }

    free(recData);
    recData = NULL;

    return NPU_OK;
}

int generate_package_directory(const char *hpm_dir, char *file_dir, char *tar_file_path, int dir_len, int card_id)
{
    int ret;

    if ((hpm_dir == NULL) || (file_dir == NULL) || (tar_file_path == NULL)) {
        gplog(LOG_ERR, "hpm_dir, file_dir or tar_file_path pointer is NULL.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (check_filename(hpm_dir, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = snprintf_s(file_dir, dir_len, dir_len - 1, "%s_%d", MCU_UPDATE_TEMP_PATH, card_id);
    if (ret <= 0) {
        gplog(LOG_ERR, "call snprintf_s failed.%d.\n", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    if (access(file_dir, F_OK) != DCMI_OK) {
#ifndef _WIN32
        if (mkdir(file_dir, S_IRUSR | S_IWUSR) < 0) {
#else
        if (_mkdir(file_dir) < 0) {
#endif
            gplog(LOG_ERR, "mkdir %s failed.%d\n", file_dir, ret);
            return NPU_ERR_CODE_INNER_ERR;
        }
    }

    // 将mcu.tar.gz文件和hpm文件放在同一目录下
    ret = snprintf_s(tar_file_path, dir_len, dir_len - 1, "%s/%s", file_dir, "mcu.tar.gz");
    if (ret <= 0) {
        gplog(LOG_ERR, "call snprintf_s failed.%d.\n", ret);
        (void)remove_dir(file_dir);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    return NPU_OK;
}

int extract_targz_package(const char *sourceFile, const char *targetPath)
{
    int ret;
    char cmdBuf[BUFF_MAX_LEN] = {0x00};

#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif
    if (check_filename(sourceFile, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "file path is illegal.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = snprintf_s(cmdBuf, BUFF_MAX_LEN, BUFF_MAX_LEN - 1, "tar -mzxf %s -C %s", path, targetPath);
    if (ret <= 0) {
        gplog(LOG_ERR, "call snprintf_s failed.%d.\n", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    /* 存放的是指向每一个参数的指针 */
    char *exec_argv[7] = {"tar", "--warning=no-timestamp", "-mzxf", path, "-C", (char*)targetPath, NULL};
    ret = safe_exec("/bin/tar", exec_argv);
    if (ret != 0) {
        gplog(LOG_ERR, "%s failed.%d.\n", cmdBuf, ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

int get_mcu_upgrade_file_path(MCU_UPGRADE_INFO *upgrade_info, const char *source_file,
                              char *target_path, int path_len)
{
    int ret;

    if ((upgrade_info == NULL) || (source_file == NULL) || (target_path == NULL)) {
        gplog(LOG_ERR, "Input parameter is null.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    // 兼容新老MCU，旧版本MCU包解压后bin包文件名为mcu.bin
    if (!upgrade_info->is_new_mcu_package) {
        ret = snprintf_s(target_path, path_len, path_len - 1, "%s/mcu.bin", source_file);
    } else if (upgrade_info->is_support_mcu_type) {
        ret = snprintf_s(target_path, path_len, path_len - 1, "%s/%02x_%02x.bin",
                         source_file, upgrade_info->board_id, upgrade_info->mcu_type);
    } else {
        ret = snprintf_s(target_path, path_len, path_len - 1, "%s/%s.bin", source_file, "default");
    }

    if (ret <= 0) {
        gplog(LOG_ERR, "call snprintf_s failed.%d.\n", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = access(target_path, F_OK);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "mcu upgrade file does not exist.%d.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
    return NPU_OK;
}

int get_mcu_upgrade_info(int card_id, MCU_UPGRADE_INFO *upgrade_info)
{
    int ret;

    if (upgrade_info == NULL) {
        gplog(LOG_ERR, "upgrade_info is null.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_mcu_get_board_id(card_id, &upgrade_info->board_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get board_id failed.%d.\n", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmi_mcu_get_mcu_type_id(card_id, &upgrade_info->mcu_type);
    if (ret == DCMI_OK) {
        upgrade_info->is_support_mcu_type = 1;
        ret = sprintf_s(upgrade_info->tar_name, UPGRADE_NAME_LEN, "%02x_%02x.tar.gz",
                        upgrade_info->board_id, upgrade_info->mcu_type);
        if (ret <= 0) {
            gplog(LOG_ERR, "call sprintf_s failed.%d.\n", ret);
            return NPU_ERR_CODE_SECURE_FUN_FAIL;
        }
        return NPU_OK;
    } else if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        upgrade_info->is_support_mcu_type = 0;
        // 旧版本MCU不支持查询mcu type id，因此模糊匹配第一个包含boardid的tar包作为升级包
        ret = sprintf_s(upgrade_info->tar_name, UPGRADE_NAME_LEN, "%02x_", upgrade_info->board_id);
        if (ret <= 0) {
            gplog(LOG_ERR, "call sprintf_s failed.%d.\n", ret);
            return NPU_ERR_CODE_SECURE_FUN_FAIL;
        }
        return NPU_OK;
    }

    gplog(LOG_ERR, "get type_id failed.%d.\n", ret);
    return dcmi_to_npu_error_code(ret);
}

int hpm_file_parse_bin_file(int card_id, const char *file, char *bin_file, char *dir_path, int path_len)
{
    int ret;
    char hpm_dir[BUFF_MAX_LEN] = {0};
    char tar_file_path[BUFF_MAX_LEN] = {0};
    MCU_UPGRADE_INFO upgrade_info = {0};

    if ((file == NULL) || (bin_file == NULL) || (dir_path == NULL)) {
        gplog(LOG_ERR, "Input parameter error: file, bin_file or dir_path is null.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    // 获取hpm文件目录
    ret = get_file_directory(file, hpm_dir, BUFF_MAX_LEN);
    if (ret != 0) {
        gplog(LOG_ERR, "Get file directory failed.%d.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = get_mcu_upgrade_info(card_id, &upgrade_info);
    if (ret != 0) {
        gplog(LOG_ERR, "Get mcu upgrade info failed.%d.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 在hpm文件目录下创建package目录用于存放解压后的包，将解析出mcu.tar.gz文件放在新生成的package目录下
    ret = generate_package_directory(hpm_dir, dir_path, tar_file_path, path_len, card_id);
    if (ret != 0) {
        gplog(LOG_ERR, "Generate directory failed.%d.\n", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 从hpm签名文件中解析出mcu.tar.gz文件
    ret = generate_image_file(card_id, &upgrade_info, file, tar_file_path);
    if (ret != 0) {
        gplog(LOG_ERR, "Generate mcu.tar.gz failed.%d.\n", ret);
        (void)remove_dir(dir_path);
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 将mcu.tar.gz解压成mcu.bin文件，和hpm文件放在同一目录下
    ret = extract_targz_package(tar_file_path, dir_path);
    if (ret != 0) {
        gplog(LOG_ERR, "Extract mcu.tar.gz failed.%d.\n", ret);
        (void)remove_file((const char *)&tar_file_path);
        (void)remove_dir(dir_path);
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = get_mcu_upgrade_file_path(&upgrade_info, dir_path, bin_file, path_len);
    if (ret != 0) {
        gplog(LOG_ERR, "get mcu upgrade file path failed.%d.\n", ret);
        (void)remove_file((const char *)&tar_file_path);
        (void)remove_dir(dir_path);
        return NPU_ERR_CODE_INNER_ERR;
    }

    // 删除mcu.tar.gz
    (void)remove_file((const char *)&tar_file_path);
    return NPU_OK;
}
