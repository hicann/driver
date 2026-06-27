/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef _NPU_CMS_API_H_
#define _NPU_CMS_API_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define PERMISSION_CRL 0644
#define PERMISSION_HWSIPCRL 0755
#define CRL_MAX_SIZE 32768
#define ROOT_UID 0

#define LOCAL_CRL_IS_ERROR (-2)

#ifndef UPDATE_OK
#define UPDATE_OK 1
#endif

#if defined(VRD_CMS)

#define VRD_BASE_ADDR 0
#define FILE_HASH_OFFSET 0x40
#define SECURE_HDR_SIZE 0x2000
#define CMS_NAME_DOMAIN_LEN 12
#define CMS_TAG_AND_LEN_SIZE 16
#define CMS_FIEL_SIZE_D ((CMS_TAG_AND_LEN_SIZE) - (CMS_NAME_DOMAIN_LEN))
#define CMS_FILE_SIZE_16K 0x4000
#define CMS_INI_FILE_SIZE_2K 0x800
#define CMS_DATA_ALIGN 16
#define CMS_DATA_RESERVE_GAP 32
#define CHAR_SHA256_LEN 64
#define SHA256_LEN 32
#define HEXADECIMAL 16
#endif

typedef struct tag_CMS_FILE_INFO {
    uint32_t file_num;
    uint32_t file1_id;
    uint32_t file_list_len;
    uint32_t file2_id;
    uint32_t cms_sign_len;
    uint32_t file3_id;
    uint32_t crl_file_len;
} CMS_FILE_INFO;

#define VALIDATE_FILE_MAX_SIZE (8 * 1024 * 1024)
int cms_validate_sign(const char *file_name);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* _NPU_CMS_API_H_ */
