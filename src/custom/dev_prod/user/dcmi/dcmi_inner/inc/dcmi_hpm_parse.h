/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef DCMI_HPM_PARSE_H
#define DCMI_HPM_PARSE_H

#define DCMI_VRD_NUM_LEN                  1
#define DCMI_MCU_RETRY_TOTAL_TIMES        2
#define DCMI_SUPPLIER_NAME_LEN            4
#define DCMI_MAX_VRD_FILE_NUM             20
#define DCMI_VRD_NAME_PARSE_PARAM_VALID   3
#define DCMI_WAIT_MINID_TO_MCU_SWITCH     6
#define DCMI_TRY_TRANS_FILE_TIMES         10
#define DCMI_UPGRADE_STATE_WAIT_TIME      120
#define DCMI_CHECK_UPGRADE_STATUS_NUM     10
#define DCMI_VRD_NAME_LEN                 10
#define DCMI_VRD_VALUE_LEN                2
#define DCMI_VRD_VALUE_NUM                3
#define DCMI_VRD_INFO_LEN                 (DCMI_VRD_NAME_LEN + DCMI_VRD_VALUE_LEN * DCMI_VRD_VALUE_NUM)

#define DCMI_VRD_VALUE_INVALID            0x7fff
#define DCMI_VRD_VALUE_ERROR              0x7ffd
#define DCMI_VRD_APP_INDEX_LEN            1
#define DCMI_VRD_APP_SUPPLIER_LEN         1
#define DCMI_VRD_APP_INFO_LEN             4
#define DCMI_BIT_SHIFT                    4

#define DCMI_SHIFT_THREE_BITS             3
#define DCMI_SHIFT_FOUR_BITS              4
#define DCMI_SHIFT_EIGHT_BITS             8
#define DCMI_SHIFT_SIXTEEN_BITS           16
#define DCMI_SHIFT_TWENTY_FOUR_BITS       24

#define DCMI_DWORD_HIGHEST_BYTE           3
#define DCMI_DWORD_SEC_HIGHEST_BYTE       2
#define DCMI_DWORD_SEC_LOWEST_BYTE        1
#define DCMI_DWORD_LOWEST_BYTE            0

// CMS文件读取相关宏定义
#define DCMI_MAX_FILE_PATH_LEN            24
#define DCMI_PACKAGE_FILE_NUM             20
#define DCMI_MAX_FIRMWARE_DES             21
#define DCMI_MAX_BANK_NUMBER              8
#define DCMI_RESERVE_SPACE                256
#define DCMI_CMS_LEN_CHAR_NUM             8
#define DCMI_CMS_SIGNATYPE_CHAR_NUM       8
#define DCMI_CMS_MANUFACTURE_ID_CHAR_NUM  3
#define DCMI_CMS_TWO_CHAR_NUM             2
#define DCMI_CMS_FOUR_CHAR_NUM            4
#define DCMI_CMS_FILE_INFO_BASE_ADDR      0
#define DCMI_VRD_NAME_PARSE_PARAM_VALID   3
#define DCMI_FILE_MAX_LENGTH              (3 * 1024 * 1024)

#define DCMI_CMS_FILE_LIST_ID_OFFSET      (DCMI_CMS_FILE_INFO_BASE_ADDR  + DCMI_CMS_LEN_CHAR_NUM)
#define DCMI_CMS_FILE_LIST_LEN_OFFSET     (DCMI_CMS_FILE_LIST_ID_OFFSET  + DCMI_CMS_LEN_CHAR_NUM)
#define DCMI_CMS_SIGN_FILE_ID_OFFSET      (DCMI_CMS_FILE_LIST_LEN_OFFSET + DCMI_CMS_LEN_CHAR_NUM)
#define DCMI_CMS_SIGN_FILE_LEN_OFFSET     (DCMI_CMS_SIGN_FILE_ID_OFFSET  + DCMI_CMS_LEN_CHAR_NUM)
#define DCMI_CMS_CRL_FILE_ID_OFFSET       (DCMI_CMS_SIGN_FILE_LEN_OFFSET + DCMI_CMS_LEN_CHAR_NUM)
#define DCMI_CMS_CRL_FILE_LEN_OFFSET      (DCMI_CMS_CRL_FILE_ID_OFFSET   + DCMI_CMS_LEN_CHAR_NUM)

typedef enum {
    DCMI_CMS_FILE_LIST = 0,
    DCMI_CMS_SIGN_FILE,
    DCMI_CMS_CRL_FILE,
    DCMI_CMS_FILE_NUM
} DCMI_CMS_FILE_E;

typedef struct DCMITagImageHeaderStr {
    unsigned char signature[DCMI_CMS_SIGNATYPE_CHAR_NUM];          /* PICMGFWU */
    unsigned char formatVersion;
    unsigned char deviceId;
    unsigned char manufactureId[DCMI_CMS_MANUFACTURE_ID_CHAR_NUM]; /* 小字序 */
    unsigned char productId[DCMI_CMS_TWO_CHAR_NUM];                /* 小字序 */
    unsigned char imageTime[DCMI_CMS_FOUR_CHAR_NUM];               /* 镜像文件创建事件 */
    unsigned char imageCapabilities;
    unsigned char components[DCMI_CMS_FOUR_CHAR_NUM];
    unsigned char selftestTimeout;                                 /* 以5秒为单位 */
    unsigned char rollbackTimeout;                                 /* 以5秒为单位 */
    unsigned char inaccessibilityTimeout;                          /* 以5秒为单位 */
    unsigned char earliestRevision[DCMI_CMS_TWO_CHAR_NUM];
    unsigned char firmwareRevision[DCMI_CMS_TWO_CHAR_NUM];
    unsigned char auxiliaryRevision[DCMI_CMS_FOUR_CHAR_NUM];
    unsigned char oemDataLength[DCMI_CMS_TWO_CHAR_NUM];            /* 固定为0 */
    unsigned char headerChecksum;
} DCMI_IMAGE_HEADER;

#pragma pack(1)
typedef struct DCMITagUpgradeActionTypeStr {
    unsigned char actionType;
    unsigned char components[DCMI_CMS_FOUR_CHAR_NUM];
    unsigned char headChecksum;
} DCMI_UPGRADE_ACTION_TYPE;

typedef struct DCMITagBankInfoStr {
    unsigned char offset[DCMI_CMS_FOUR_CHAR_NUM];
    unsigned char length[DCMI_CMS_FOUR_CHAR_NUM];
    char filePath[DCMI_MAX_FILE_PATH_LEN];
} DCMI_BANK_INFO;

typedef struct DCMITagUpgradeRecordHeadStr {
    DCMI_UPGRADE_ACTION_TYPE upgradeType;
    unsigned char firmwareVision[DCMI_CMS_TWO_CHAR_NUM];
    unsigned char auxiliaryVision[DCMI_CMS_FOUR_CHAR_NUM];
    unsigned char firmwareDes[DCMI_MAX_FIRMWARE_DES];
    unsigned char firmwareLength[DCMI_CMS_FOUR_CHAR_NUM];
    unsigned char reserved[DCMI_RESERVE_SPACE];
    DCMI_BANK_INFO bankInformation[DCMI_MAX_BANK_NUMBER];
} DCMI_UPGRADE_RECORD_HEAD;
#pragma pack()

typedef struct DCMITagCmsFileStr {
    unsigned int fileId;
    unsigned int fileLen;
} DCMI_CMS_FILE;

typedef struct DCMITagCmsFileHeaderStr {
    unsigned int fileNum;
    DCMI_CMS_FILE cmsFile[DCMI_CMS_FILE_NUM];
} DCMI_CMS_FILE_HEADER;

typedef struct DCMITagVrdUpgradeInfo {
    char supplier[DCMI_SUPPLIER_NAME_LEN];
    unsigned long version;
    int index;
} DCMI_VRD_APP_UPGRADE_INFO;

int dcmi_get_vrd_image_info(const char *cms_file, unsigned int *recOffset, unsigned int *recLen);

int dcmi_parse_bin_file_from_vrd_hpm(int card_id, const char *file, char bin_file_names[][MAX_LENTH],
    int *bin_file_num, char *dir_path);

int dcmi_determine_file_type(const char *file, const char *fileType, int typeLen);

int dcmi_list_vrd_files(char *path, char fileNames[][MAX_LENTH], int *fileNum);

int dcmi_generate_vrd_package_dir(const char *hpm_dir, char *file_dir, char *tar_file_path, int card_id);

int dcmi_generate_vrd_image_file(int card_id, const char *cms_file, const char *tar_file);

int dcmi_vrd_params_check(int card_id, const char *file);

int dcmi_parse_single_vrd_hpm(int card_id, const char *file);

unsigned int dcmi_get_cms_file_item(const char *cmsFile, int offset, unsigned int *val);

unsigned int dcmi_get_image_record_length(DCMI_BANK_INFO *bankInfo);

unsigned int dcmi_get_image_file_offset(DCMI_CMS_FILE_HEADER *cmsFileHead);

int dcmi_get_file_len_by_path(const char *file, unsigned int *file_len);

int dcmi_compare_bin_name_index(const void *bin_name1, const void *bin_name2);

int dcmi_start_vrd_upgrade(int card_id, int index);

int dcmi_send_clear_file_msg(int card_id, int index);

int dcmi_get_vrd_current_version(int card_id, DCMI_VRD_APP_UPGRADE_INFO *current_vrd_info, int *current_vrd_num);

int dcmi_filter_bin_fileNames(int current_vrd_num, DCMI_VRD_APP_UPGRADE_INFO *current_vrd_info,
    char bin_file_names[][MAX_LENTH], int *bin_file_num, char filter_file_names[][MAX_LENTH]);

#endif /* DCMI_HPM_PARSE_H */