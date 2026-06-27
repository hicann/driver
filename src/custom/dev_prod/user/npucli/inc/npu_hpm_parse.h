/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef __NPU_HPM_PARSE_H__
#define __NPU_HPM_PARSE_H__
// 宏定义
#define CMS_FILE_LIST_ID 1
#define CMS_SIGN_FILE_ID 2
#define CMS_CRL_FILE_ID 3
#define CMS_LEN_CHAR_NUM 8
#define CMS_SIGNATYPE_CHAR_NUM 8
#define CMS_MANUFACTURE_ID_CHAR_NUM 3
#define CMS_TWO_CHAR_NUM 2
#define CMS_FOUR_CHAR_NUM 4
#define CMS_FILE_INFO_BASE_ADDR 0
#define CMS_FILE_LIST_ID_OFFSET (CMS_FILE_INFO_BASE_ADDR + CMS_LEN_CHAR_NUM)
#define CMS_FILE_LIST_LEN_OFFSET (CMS_FILE_LIST_ID_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_SIGN_FILE_ID_OFFSET (CMS_FILE_LIST_LEN_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_SIGN_FILE_LEN_OFFSET (CMS_SIGN_FILE_ID_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_CRL_FILE_ID_OFFSET (CMS_SIGN_FILE_LEN_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_CRL_FILE_LEN_OFFSET (CMS_CRL_FILE_ID_OFFSET + CMS_LEN_CHAR_NUM)

#define FILE_MAX_LENGTH (3 * 1024 * 1024)
#define MAX_FILE_PATH_LEN 24
#define PACKAGE_FILE_NUM  20
#define MAX_FIRMWARE_DES 21
#define MAX_BANK_NUMBER 8
#define RESERVE_SPACE 256

#define DWORD_HIGHEST_BYTE 3
#define DWORD_SEC_HIGHEST_BYTE 2
#define DWORD_SEC_LOWEST_BYTE 1
#define DWORD_LOWEST_BYTE 0

#define BUFF_MAX_LEN 256
#define ID_STR_LEN 10
#define UPGRADE_NAME_LEN 20

#define SHIFT_THREE_BITS 3
#define SHIFT_FOUR_BITS 4
#define SHIFT_EIGHT_BITS 8
#define SHIFT_SIXTEEN_BITS 16
#define SHIFT_TWENTY_FOUR_BITS 24

typedef enum {
    CMS_FILE_LIST = 0,
    CMS_SIGN_FILE,
    CMS_CRL_FILE,
    CMS_FILE_NUM
} CMS_FILE_E;

typedef struct mcu_upgrade_info {
    int is_support_mcu_type;
    int is_new_mcu_package;
    unsigned int board_id;
    unsigned int mcu_type;
    char tar_name[UPGRADE_NAME_LEN];
} MCU_UPGRADE_INFO;

typedef struct TagCmsFileStr {
    unsigned int fileId;
    unsigned int fileLen;
} CMS_FILE;

typedef struct TagCmsFileHeaderStr {
    unsigned int fileNum;
    CMS_FILE cmsFile[CMS_FILE_NUM];
} CMS_FILE_HEADER;

typedef struct TagImageHeaderStr {
    unsigned char signature[CMS_SIGNATYPE_CHAR_NUM]; /* PICMGFWU */
    unsigned char formatVersion;
    unsigned char deviceId;
    unsigned char manufactureId[CMS_MANUFACTURE_ID_CHAR_NUM]; /* 小字序 */
    unsigned char productId[CMS_TWO_CHAR_NUM];                /* 小字序 */
    unsigned char imageTime[CMS_FOUR_CHAR_NUM];               /* 镜像文件创建事件 */
    unsigned char imageCapabilities;
    unsigned char components[CMS_FOUR_CHAR_NUM];
    unsigned char selftestTimeout;        /* 以5秒为单位 */
    unsigned char rollbackTimeout;        /* 以5秒为单位 */
    unsigned char inaccessibilityTimeout; /* 以5秒为单位 */
    unsigned char earliestRevision[CMS_TWO_CHAR_NUM];
    unsigned char firmwareRevision[CMS_TWO_CHAR_NUM];
    unsigned char auxiliaryRevision[CMS_FOUR_CHAR_NUM];
    unsigned char oemDataLength[CMS_TWO_CHAR_NUM]; /* 固定为0 */
    unsigned char headerChecksum;
} IMAGE_HEADER;

#pragma pack(1)
typedef struct TagUpgradeActionTypeStr {
    unsigned char actionType;
    unsigned char components[CMS_FOUR_CHAR_NUM];
    unsigned char headChecksum;
} UPGRADE_ACTION_TYPE;

typedef struct TagBankInfoStr {
    unsigned char offset[CMS_FOUR_CHAR_NUM];
    unsigned char length[CMS_FOUR_CHAR_NUM];
    char filePath[MAX_FILE_PATH_LEN];
} BANK_INFO;

typedef struct TagUpgradeRecordHeadStr {
    UPGRADE_ACTION_TYPE upgradeType;
    unsigned char firmwareVision[CMS_TWO_CHAR_NUM];
    unsigned char auxiliaryVision[CMS_FOUR_CHAR_NUM];
    unsigned char firmwareDes[MAX_FIRMWARE_DES];
    unsigned char firmwareLength[CMS_FOUR_CHAR_NUM];
    unsigned char reserved[RESERVE_SPACE];
    BANK_INFO bankInformation[MAX_BANK_NUMBER];
} UPGRADE_RECORD_HEAD;
#pragma pack()

typedef struct TagUpgradeRecordStr {
    UPGRADE_RECORD_HEAD upgradeRecordHead;
    char *recordData;
} UPGRADE_RECORD;

typedef struct TagUpgradeImageInfoStr {
    CMS_FILE_HEADER fileHead;
    char *fileList;
    char *cmsFile;
    char *crlFile;
    IMAGE_HEADER imageHead;
    UPGRADE_ACTION_TYPE upgradeType;
    UPGRADE_RECORD upgradeRecord[PACKAGE_FILE_NUM];
} HPM_IMAGE_INFO;

int hpm_file_parse_bin_file(int card_id, const char *file, char *bin_file, char *dir_path, int path_len);
int determine_file_type(const char *file, const char *fileType, int typeLen);
int get_mcu_upgrade_info(int card_id, MCU_UPGRADE_INFO *upgrade_info);

#endif /* __NPU_HPM_PARSE_H__ */
