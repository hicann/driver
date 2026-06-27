/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/stat.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif
#include "securec.h"
#include "cmscbb.h"
#include "dcmi_log.h"
#include "npu_common.h"
#include "npu_cms_api.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

CMSCBB_ERROR_CODE CmscbbMdCreateCtx(CMSCBB_CRYPTO_MD_CTX *md_ctx);
CMSCBB_ERROR_CODE CmscbbMdInit(CMSCBB_CRYPTO_MD_CTX md_ctx, CVB_UINT32 hash_id);
CMSCBB_ERROR_CODE CmscbbMdUpdate(CMSCBB_CRYPTO_MD_CTX md_ctx, const CVB_BYTE *data, CVB_UINT32 len);
CMSCBB_ERROR_CODE CmscbbMdFinal(CMSCBB_CRYPTO_MD_CTX md_ctx, CVB_BYTE *digest, CVB_UINT32 *len,
    const CVB_UINT32 *digestMaxLen);
CVB_VOID CmscbbMdDestoryCtx(CMSCBB_CRYPTO_MD_CTX md_ctx);
STATIC int transmit_pss_cert_to_cmscbb(CMSCBB_VRF_CTX *pCtx);

#define CMS_FILE_NUM 3
#define CMS_FILE_LIST_ID 1
#define CMS_SIGN_FILE_ID 2
#define CMS_CRL_FILE_ID 3

#if defined(VRD_CMS)
#define CMS_LEN_CHAR_NUM 4
#define CMS_IMG_DESC 0x2058
#define CMS_CODE_LEN_SIZE 0x205c
#else
#define CMS_LEN_CHAR_NUM 8
#define CMS_FILE_INFO_BASE_ADDR 0
#define CMS_FILE_LIST_ID_OFFSET (CMS_FILE_INFO_BASE_ADDR + CMS_LEN_CHAR_NUM)
#define CMS_FILE_LIST_LEN_OFFSET (CMS_FILE_LIST_ID_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_SIGN_FILE_ID_OFFSET (CMS_FILE_LIST_LEN_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_SIGN_FILE_LEN_OFFSET (CMS_SIGN_FILE_ID_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_CRL_FILE_ID_OFFSET (CMS_SIGN_FILE_LEN_OFFSET + CMS_LEN_CHAR_NUM)
#define CMS_CRL_FILE_LEN_OFFSET (CMS_CRL_FILE_ID_OFFSET + CMS_LEN_CHAR_NUM)

#define CMS_FILE_INFO_OFFSET 0
#endif

#define HASH_MAX_SIZE 128
#define MAX_LINE_BUF 256
#define MAX_PROCTOR_SIZE 20
#define CMS_LIST_NAME "Name: "
#define UMS_FILE_DST_TAG "Destination: "
#define UMS_UPGRADE_TOTAL_SIZE_TAG "TotalSize:"
#define STR_HASH256_DIGEST "SHA256-Digest"
#define STR_HASH384_DIGEST "SHA384-Digest"
#define STR_HASH512_DIGEST "SHA512-Digest"

#define MAX_MD_BUF_LEN 256
#define MAX_MD_HASH_LEN 256

#define MAX_FLASH_BUF_LEN 256

static unsigned char g_root_cert[] = {
    0x30, 0x82, 0x05, 0x4F, 0x30, 0x82, 0x03, 0x37, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x08, 0x45,
    0xB6, 0x14, 0x73, 0x38, 0x30, 0xB4, 0x79, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
    0x0D, 0x01, 0x01, 0x0B, 0x05, 0x00, 0x30, 0x37, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
    0x06, 0x13, 0x02, 0x43, 0x4E, 0x31, 0x0F, 0x30, 0x0D, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x06,
    0x48, 0x75, 0x61, 0x77, 0x65, 0x69, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13,
    0x0E, 0x48, 0x75, 0x61, 0x77, 0x65, 0x69, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41, 0x30,
    0x20, 0x17, 0x0D, 0x31, 0x35, 0x31, 0x30, 0x31, 0x35, 0x30, 0x38, 0x30, 0x38, 0x35, 0x30, 0x5A,
    0x18, 0x0F, 0x32, 0x30, 0x35, 0x30, 0x31, 0x30, 0x31, 0x35, 0x30, 0x38, 0x30, 0x38, 0x35, 0x30,
    0x5A, 0x30, 0x37, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x43, 0x4E,
    0x31, 0x0F, 0x30, 0x0D, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x06, 0x48, 0x75, 0x61, 0x77, 0x65,
    0x69, 0x31, 0x17, 0x30, 0x15, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x0E, 0x48, 0x75, 0x61, 0x77,
    0x65, 0x69, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41, 0x30, 0x82, 0x02, 0x22, 0x30, 0x0D,
    0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x02,
    0x0F, 0x00, 0x30, 0x82, 0x02, 0x0A, 0x02, 0x82, 0x02, 0x01, 0x00, 0xEE, 0x4C, 0x63, 0x03, 0x98,
    0x3B, 0xDD, 0x01, 0xFB, 0x9E, 0xFA, 0xD3, 0x23, 0xF6, 0x44, 0x24, 0xFD, 0x83, 0x6B, 0x74, 0x34,
    0x32, 0x0D, 0x34, 0xAB, 0xCF, 0xE6, 0x33, 0x90, 0xC0, 0x98, 0x59, 0x12, 0xE7, 0xFF, 0x6B, 0xBB,
    0x56, 0x50, 0x9C, 0xA5, 0xCD, 0xE7, 0x3A, 0x2A, 0xE7, 0x77, 0xB8, 0x7F, 0x5A, 0xFD, 0x79, 0x48,
    0x70, 0x8E, 0x86, 0xA4, 0x58, 0x83, 0xE3, 0xA1, 0x37, 0x42, 0xDB, 0xB8, 0x61, 0x06, 0x82, 0x9B,
    0x65, 0xB6, 0x4E, 0x0D, 0xB4, 0xBF, 0xB8, 0xF1, 0x6E, 0xF1, 0xA5, 0xEB, 0x70, 0x39, 0xC0, 0x9C,
    0x27, 0xBE, 0xD3, 0x60, 0xEC, 0x87, 0x90, 0xA5, 0x1E, 0x6F, 0x83, 0xA7, 0x7E, 0xE6, 0x21, 0xEE,
    0x7A, 0x36, 0x1C, 0x3F, 0x7C, 0xC5, 0x4E, 0xA9, 0x97, 0xF4, 0xD1, 0xC6, 0x38, 0x1B, 0x27, 0xC9,
    0x2B, 0x20, 0x51, 0x0B, 0x57, 0x1D, 0x79, 0xC8, 0x35, 0x8B, 0x69, 0x82, 0x02, 0x92, 0xC1, 0x7B,
    0xD5, 0x99, 0x87, 0x8F, 0xF1, 0x96, 0x69, 0xA1, 0x0A, 0xEA, 0xE4, 0x97, 0xA4, 0x72, 0x5A, 0xB5,
    0xEA, 0xCF, 0xA5, 0xE6, 0x8B, 0xD8, 0x25, 0x66, 0x19, 0x51, 0xEB, 0xB8, 0x34, 0x63, 0x40, 0x94,
    0xAA, 0xD4, 0xEF, 0xCA, 0xFF, 0x86, 0xA0, 0x9C, 0x93, 0xB8, 0x7D, 0x33, 0xAB, 0x50, 0xD4, 0x87,
    0xA5, 0x51, 0x6A, 0x62, 0xA4, 0x9A, 0x81, 0xC0, 0x30, 0xAA, 0x43, 0x80, 0x37, 0xE6, 0x16, 0x41,
    0xF7, 0xDD, 0x41, 0x70, 0x81, 0x4D, 0x97, 0xFD, 0xE7, 0xFA, 0x98, 0x91, 0xA9, 0x62, 0xC1, 0xEE,
    0x8E, 0x57, 0x2F, 0xA2, 0x7E, 0x4D, 0x64, 0xA0, 0x18, 0x04, 0x79, 0x8E, 0xA1, 0xFD, 0x9E, 0xF6,
    0x6C, 0x43, 0xC8, 0x86, 0x47, 0xD2, 0x66, 0x67, 0x0E, 0xC9, 0xDE, 0x30, 0x5E, 0x44, 0x0C, 0xAE,
    0x23, 0x3B, 0xEA, 0x81, 0x74, 0x59, 0xF9, 0x29, 0xD5, 0xF2, 0xF2, 0x53, 0x86, 0x89, 0x55, 0x49,
    0x69, 0xE1, 0xAD, 0xBB, 0x1D, 0xF3, 0x1B, 0xF2, 0xE0, 0x19, 0xF8, 0xA5, 0xEB, 0xCF, 0x35, 0x9B,
    0x29, 0x63, 0xDE, 0x31, 0xEC, 0xCF, 0x24, 0xF4, 0x0B, 0x22, 0x11, 0xA1, 0x09, 0xFD, 0x1F, 0x00,
    0xF9, 0x3E, 0x7E, 0x8F, 0xBA, 0x79, 0x29, 0xE4, 0x17, 0x32, 0x59, 0xDC, 0xDD, 0x67, 0x54, 0xC5,
    0x70, 0x12, 0xAE, 0x21, 0x63, 0x86, 0x52, 0x16, 0xF3, 0x70, 0x5A, 0x17, 0x9E, 0x4C, 0xB3, 0xEA,
    0x20, 0xDE, 0xE2, 0x0C, 0x6D, 0x1F, 0x80, 0xF7, 0x65, 0x0D, 0xF1, 0xD2, 0x5A, 0x71, 0x20, 0x77,
    0x96, 0x53, 0x12, 0xA5, 0xD4, 0x7D, 0x05, 0x7A, 0x81, 0x09, 0xC7, 0xA3, 0xCB, 0xD0, 0xAA, 0x1C,
    0xFE, 0x22, 0x7E, 0x78, 0xC4, 0xB3, 0xA3, 0x11, 0xF1, 0xE0, 0x9E, 0x42, 0xC9, 0x36, 0x20, 0x17,
    0xDF, 0x73, 0xA5, 0xF4, 0xBB, 0x9D, 0x85, 0xEC, 0x46, 0x1A, 0xFC, 0xCB, 0x56, 0xAC, 0x5D, 0xCA,
    0x7B, 0xB9, 0xB2, 0xE8, 0x23, 0xCC, 0x8B, 0x90, 0xC6, 0xC1, 0x62, 0xB8, 0x3E, 0x5C, 0x52, 0xF4,
    0xDE, 0x03, 0x87, 0x9A, 0x4B, 0x6D, 0x75, 0x7E, 0xBB, 0xC4, 0xA9, 0xC2, 0xC5, 0xCA, 0x58, 0x15,
    0x55, 0xAC, 0xFA, 0x73, 0xF0, 0xCA, 0xF3, 0x82, 0x9B, 0xCD, 0x52, 0x1F, 0x56, 0x18, 0x9C, 0x99,
    0xC6, 0x3F, 0x97, 0x2C, 0x8C, 0x7F, 0x21, 0x1F, 0x6C, 0x5B, 0x66, 0x93, 0x29, 0xC2, 0xB0, 0x99,
    0x9F, 0xA9, 0x59, 0x7F, 0xBB, 0x73, 0x69, 0xF9, 0x9E, 0xCC, 0x58, 0x09, 0xE9, 0xFF, 0xC0, 0xF0,
    0xD6, 0x4F, 0x9B, 0x38, 0x57, 0x7B, 0xE2, 0xD7, 0x81, 0xF5, 0x9A, 0x88, 0x4D, 0xDD, 0x05, 0x33,
    0xC5, 0xCB, 0xAB, 0x9B, 0xCC, 0x12, 0xA5, 0x59, 0x3E, 0x77, 0x05, 0x0A, 0x4F, 0xE2, 0xED, 0x75,
    0x62, 0xF7, 0x55, 0xC4, 0xDC, 0x52, 0xC2, 0xB2, 0xA1, 0x13, 0x85, 0x02, 0x03, 0x01, 0x00, 0x01,
    0xA3, 0x5D, 0x30, 0x5B, 0x30, 0x1F, 0x06, 0x03, 0x55, 0x1D, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80,
    0x14, 0x72, 0x76, 0x96, 0xC3, 0x0F, 0x90, 0x9C, 0xD4, 0x55, 0xB8, 0xAE, 0x9B, 0x49, 0xEE, 0xF7,
    0xDF, 0x5C, 0xC9, 0x02, 0xB4, 0x30, 0x0C, 0x06, 0x03, 0x55, 0x1D, 0x13, 0x04, 0x05, 0x30, 0x03,
    0x01, 0x01, 0xFF, 0x30, 0x0B, 0x06, 0x03, 0x55, 0x1D, 0x0F, 0x04, 0x04, 0x03, 0x02, 0x01, 0x06,
    0x30, 0x1D, 0x06, 0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0x72, 0x76, 0x96, 0xC3, 0x0F,
    0x90, 0x9C, 0xD4, 0x55, 0xB8, 0xAE, 0x9B, 0x49, 0xEE, 0xF7, 0xDF, 0x5C, 0xC9, 0x02, 0xB4, 0x30,
    0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0B, 0x05, 0x00, 0x03, 0x82,
    0x02, 0x01, 0x00, 0x70, 0x57, 0x51, 0x04, 0xB0, 0xCA, 0xC4, 0x6A, 0xB0, 0xC4, 0xD2, 0x11, 0x2A,
    0x13, 0x20, 0x3F, 0x37, 0x46, 0x29, 0x05, 0xC5, 0x23, 0x35, 0x63, 0xBC, 0x52, 0x62, 0xD8, 0x59,
    0x2C, 0xC1, 0xA6, 0xFE, 0x1E, 0x3D, 0x73, 0x6D, 0x57, 0xA3, 0xD0, 0xF1, 0x1A, 0xC6, 0x36, 0xD8,
    0x5C, 0x8A, 0xC6, 0xB9, 0xEA, 0x76, 0xDB, 0xF8, 0xE7, 0xF0, 0x72, 0x53, 0xE9, 0x8A, 0x2D, 0x35,
    0x8F, 0xCF, 0x50, 0x54, 0x8E, 0x12, 0x95, 0x4F, 0x01, 0x14, 0x95, 0x32, 0x53, 0xF1, 0x48, 0x44,
    0x8B, 0x9D, 0x95, 0x25, 0xD6, 0x27, 0x30, 0x15, 0x25, 0xC8, 0xC7, 0x6A, 0xD5, 0x3A, 0x4A, 0xA8,
    0xBB, 0x39, 0xD1, 0x83, 0xA1, 0x93, 0x88, 0x93, 0x1D, 0x23, 0x9B, 0x22, 0x79, 0xAC, 0xAA, 0x18,
    0xA0, 0x28, 0xF8, 0x84, 0xE8, 0xD8, 0x1D, 0xE6, 0x09, 0x20, 0x5F, 0xC2, 0x10, 0x81, 0x7E, 0x3A,
    0x76, 0x66, 0x8F, 0x93, 0xFA, 0x7B, 0xF3, 0x31, 0xC4, 0x2D, 0x05, 0xBC, 0x4C, 0x60, 0x26, 0xB2,
    0x72, 0xAA, 0x02, 0x06, 0x99, 0x14, 0x51, 0x92, 0x85, 0x44, 0x3B, 0x18, 0xE9, 0x20, 0x72, 0x2D,
    0x9C, 0x81, 0x5A, 0x11, 0xAE, 0xF2, 0xF1, 0xC5, 0xFD, 0xC2, 0x7B, 0xE3, 0x85, 0x82, 0x02, 0x47,
    0xA0, 0x91, 0x9A, 0x6D, 0x23, 0xCC, 0xDB, 0x1F, 0x77, 0x49, 0x70, 0x76, 0xD3, 0x9E, 0x76, 0x58,
    0x77, 0x17, 0xB9, 0xC8, 0x93, 0xC3, 0xAD, 0xD6, 0x9D, 0xF0, 0x50, 0xC2, 0xA0, 0xD4, 0x77, 0x0C,
    0x73, 0x1C, 0xF2, 0x81, 0x6B, 0xF8, 0x0A, 0x35, 0x53, 0x67, 0x2E, 0x84, 0xD7, 0xFF, 0xAC, 0xE8,
    0xA4, 0xC4, 0x1B, 0x05, 0xF4, 0xA7, 0xFD, 0x88, 0x48, 0x98, 0x5F, 0x8E, 0xD9, 0x51, 0x13, 0x3B,
    0xD0, 0xEA, 0x67, 0xF0, 0x04, 0xF6, 0xC8, 0xE8, 0xD6, 0x66, 0x0F, 0x4C, 0xA6, 0x46, 0xCC, 0xBB,
    0x9A, 0x51, 0x04, 0x3E, 0x79, 0x30, 0x7A, 0x81, 0x05, 0x37, 0xDC, 0xBC, 0x3F, 0xC1, 0x88, 0x4E,
    0xEA, 0x65, 0xDB, 0x49, 0xF9, 0x0B, 0xF4, 0x43, 0xF0, 0x9F, 0x88, 0xDC, 0x00, 0x72, 0xB1, 0x6E,
    0x09, 0xE7, 0xB1, 0x58, 0xEA, 0x6A, 0x09, 0x6B, 0x08, 0xD8, 0xBE, 0x9A, 0x86, 0x42, 0x2F, 0x91,
    0xE2, 0xF8, 0x89, 0xDD, 0x05, 0xB2, 0x5B, 0xE0, 0x32, 0x30, 0xEF, 0x21, 0x42, 0x29, 0xBD, 0xDB,
    0x8B, 0x86, 0x36, 0xEC, 0x62, 0x8F, 0xC0, 0x2F, 0x9D, 0xAD, 0x8A, 0xE4, 0xC7, 0x38, 0x4D, 0xBF,
    0xC7, 0x8D, 0x20, 0x4C, 0x27, 0xD8, 0x25, 0xB1, 0xF4, 0xCB, 0x36, 0xA3, 0x74, 0xC4, 0x34, 0xFB,
    0x6F, 0xBF, 0xF8, 0xA3, 0x61, 0x64, 0x93, 0x94, 0xB3, 0xB7, 0xFA, 0xCA, 0x4E, 0x24, 0x95, 0x55,
    0xB1, 0xF6, 0xD9, 0x44, 0xB6, 0xAE, 0x2E, 0x52, 0x57, 0xC0, 0x3E, 0x81, 0xB1, 0xFF, 0xE3, 0x53,
    0x63, 0x14, 0xD6, 0x65, 0x03, 0x1B, 0x31, 0x2D, 0x23, 0x74, 0x80, 0x77, 0x92, 0xB4, 0x38, 0xA1,
    0x90, 0x5B, 0x3D, 0x96, 0x26, 0x90, 0x20, 0x22, 0x98, 0xA4, 0x94, 0xE8, 0x64, 0xA1, 0xD2, 0xEA,
    0x13, 0xF4, 0xA5, 0xA6, 0x14, 0xEB, 0x5C, 0x12, 0xAB, 0x2E, 0x25, 0x50, 0x4C, 0xA4, 0x6B, 0x92,
    0xB3, 0x41, 0x92, 0x2B, 0xEE, 0x1F, 0xC1, 0x67, 0xC7, 0xA5, 0x54, 0x8E, 0xB1, 0x18, 0xA1, 0xE0,
    0xBF, 0x65, 0x52, 0xA6, 0x06, 0x0A, 0xBB, 0x10, 0xB9, 0xF4, 0x8F, 0xAC, 0xC9, 0x74, 0x6C, 0x37,
    0xA0, 0x2C, 0x95, 0x54, 0x6A, 0xF3, 0xFD, 0x99, 0xA3, 0x52, 0x0F, 0x71, 0x4D, 0xE4, 0xD3, 0x55,
    0x6C, 0x64, 0x09, 0x6F, 0x01, 0x1A, 0xF1, 0x4B, 0xE9, 0x58, 0x7F, 0x3B, 0x5D, 0x8A, 0xCB, 0x34,
    0x81, 0xD3, 0x68, 0x8C, 0x09, 0x83, 0x67, 0x09, 0x3B, 0xDD, 0x5C, 0x2D, 0xCB, 0x82, 0xAB, 0x3D,
    0xA9, 0xC4, 0x87
};

static unsigned char pbPssRootCert0[] = {
    0x30, 0x82, 0x06, 0x42, 0x30, 0x82, 0x03, 0xF6, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x03, 0x3C,
    0x3A, 0xDB, 0x30, 0x41, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0A, 0x30,
    0x34, 0xA0, 0x0F, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01,
    0x05, 0x00, 0xA1, 0x1C, 0x30, 0x1A, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01,
    0x08, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00,
    0xA2, 0x03, 0x02, 0x01, 0x20, 0x30, 0x7C, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
    0x13, 0x02, 0x43, 0x4E, 0x31, 0x1C, 0x30, 0x1A, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x13, 0x48,
    0x75, 0x61, 0x77, 0x65, 0x69, 0x20, 0x54, 0x65, 0x63, 0x68, 0x6E, 0x6F, 0x6C, 0x6F, 0x67, 0x69,
    0x65, 0x73, 0x31, 0x27, 0x30, 0x25, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x1E, 0x48, 0x75, 0x61,
    0x77, 0x65, 0x69, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F,
    0x6E, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x31, 0x26, 0x30, 0x24, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x13, 0x1D, 0x48, 0x75, 0x61, 0x77, 0x65, 0x69, 0x20, 0x49, 0x6E, 0x74,
    0x65, 0x67, 0x72, 0x69, 0x74, 0x79, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41, 0x20, 0x2D,
    0x20, 0x47, 0x32, 0x30, 0x20, 0x17, 0x0D, 0x32, 0x31, 0x30, 0x32, 0x30, 0x37, 0x30, 0x39, 0x33,
    0x36, 0x34, 0x36, 0x5A, 0x18, 0x0F, 0x32, 0x30, 0x35, 0x31, 0x30, 0x35, 0x30, 0x37, 0x30, 0x39,
    0x33, 0x36, 0x34, 0x36, 0x5A, 0x30, 0x7C, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
    0x13, 0x02, 0x43, 0x4E, 0x31, 0x1C, 0x30, 0x1A, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x13, 0x48,
    0x75, 0x61, 0x77, 0x65, 0x69, 0x20, 0x54, 0x65, 0x63, 0x68, 0x6E, 0x6F, 0x6C, 0x6F, 0x67, 0x69,
    0x65, 0x73, 0x31, 0x27, 0x30, 0x25, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x1E, 0x48, 0x75, 0x61,
    0x77, 0x65, 0x69, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69, 0x66, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F,
    0x6E, 0x20, 0x41, 0x75, 0x74, 0x68, 0x6F, 0x72, 0x69, 0x74, 0x79, 0x31, 0x26, 0x30, 0x24, 0x06,
    0x03, 0x55, 0x04, 0x03, 0x13, 0x1D, 0x48, 0x75, 0x61, 0x77, 0x65, 0x69, 0x20, 0x49, 0x6E, 0x74,
    0x65, 0x67, 0x72, 0x69, 0x74, 0x79, 0x20, 0x52, 0x6F, 0x6F, 0x74, 0x20, 0x43, 0x41, 0x20, 0x2D,
    0x20, 0x47, 0x32, 0x30, 0x82, 0x02, 0x22, 0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
    0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x02, 0x0F, 0x00, 0x30, 0x82, 0x02, 0x0A, 0x02,
    0x82, 0x02, 0x01, 0x00, 0xDD, 0x89, 0x4F, 0x23, 0xFC, 0x75, 0x2D, 0xA6, 0x24, 0x8B, 0x8E, 0xC9,
    0xAB, 0xD6, 0xDD, 0x4F, 0xFE, 0x70, 0x43, 0x4D, 0xBC, 0x6E, 0xBA, 0x7D, 0x0E, 0x55, 0xC8, 0x9A,
    0x43, 0xA3, 0x9C, 0xF8, 0x4E, 0xB2, 0xD5, 0x85, 0xC2, 0x52, 0x61, 0x67, 0xFA, 0x9D, 0x56, 0xC0,
    0xA1, 0x09, 0x41, 0xEB, 0x64, 0x29, 0xB0, 0x96, 0x95, 0xC6, 0x5C, 0x87, 0xC2, 0x36, 0x1B, 0xF7,
    0xFC, 0xE8, 0x9F, 0xD9, 0xE2, 0x6E, 0x19, 0xC1, 0x92, 0x52, 0x57, 0x4E, 0x01, 0xFE, 0xE2, 0x90,
    0x18, 0x0C, 0xB7, 0xE4, 0x55, 0xB9, 0x6C, 0xD0, 0x6D, 0xBD, 0x81, 0xF7, 0xC4, 0xDE, 0x27, 0x7B,
    0x4A, 0x06, 0x5B, 0xAA, 0x96, 0x92, 0x02, 0x50, 0xB0, 0x31, 0xC6, 0xEA, 0x21, 0x59, 0xA9, 0x10,
    0x4A, 0x2F, 0x1D, 0x4E, 0xEF, 0x23, 0xA1, 0xC2, 0xF1, 0x1D, 0x1B, 0x98, 0xDF, 0x27, 0x08, 0x36,
    0xE8, 0xD2, 0xB9, 0x69, 0xDE, 0xF9, 0xBC, 0xCE, 0x8B, 0x1C, 0x0E, 0xAD, 0x10, 0xF1, 0xBD, 0xB6,
    0xD3, 0x21, 0x72, 0x68, 0xFD, 0x56, 0x0C, 0xD4, 0x74, 0x01, 0x4E, 0x1C, 0xEB, 0x75, 0x22, 0x50,
    0x24, 0x67, 0xEA, 0x1D, 0x16, 0x7E, 0x8F, 0xAE, 0xD7, 0xB8, 0x8B, 0xF3, 0x34, 0x6D, 0x86, 0x60,
    0x0F, 0xF2, 0xD2, 0x86, 0x58, 0x2D, 0x06, 0x9F, 0xA2, 0x0E, 0xB5, 0x83, 0xFB, 0x31, 0xDF, 0x71,
    0x60, 0x03, 0x10, 0x61, 0x2C, 0x13, 0x3C, 0x72, 0x5F, 0xB0, 0x89, 0xBE, 0x22, 0x41, 0x4E, 0x7A,
    0x14, 0xC0, 0xA3, 0x34, 0xFC, 0x24, 0x06, 0x2F, 0x36, 0x94, 0x4D, 0xC1, 0x8A, 0x7E, 0x65, 0x51,
    0xAA, 0xF9, 0x71, 0x0A, 0xE4, 0x86, 0x45, 0x8B, 0x19, 0x5A, 0x53, 0xB2, 0xA0, 0x6A, 0x26, 0x89,
    0x2C, 0xE6, 0x1F, 0x10, 0x8C, 0x2B, 0x3B, 0x21, 0xAC, 0x75, 0xBE, 0x45, 0x33, 0xBA, 0x62, 0x27,
    0x45, 0xBD, 0xBB, 0x7F, 0x78, 0xA3, 0x34, 0x4D, 0x19, 0x77, 0xB1, 0x79, 0xBA, 0x4B, 0x5F, 0x82,
    0xF8, 0x54, 0x58, 0xDB, 0x97, 0xAC, 0xE2, 0x5A, 0xD7, 0x06, 0x6D, 0x7F, 0xED, 0x52, 0x1C, 0x63,
    0x2F, 0x02, 0x02, 0x60, 0x40, 0xCD, 0x8B, 0x1C, 0x16, 0x46, 0x89, 0xA8, 0x38, 0x8E, 0xA9, 0x9D,
    0xB0, 0x1F, 0x79, 0xC3, 0x9A, 0x89, 0xD9, 0x78, 0xB8, 0x0B, 0xD2, 0x07, 0xE1, 0x48, 0xDE, 0x57,
    0xA1, 0xFB, 0x0E, 0x6B, 0x7F, 0x8A, 0xD0, 0x5C, 0x0B, 0x18, 0xC4, 0xAC, 0xF1, 0x2E, 0xB3, 0x9D,
    0x2C, 0x85, 0x76, 0x68, 0x2C, 0x74, 0x0B, 0xB9, 0xDC, 0x4C, 0xD0, 0x43, 0xF0, 0x83, 0xA2, 0x5C,
    0x83, 0x2B, 0x36, 0xB7, 0xF2, 0xCA, 0x91, 0x33, 0x16, 0xB6, 0x15, 0x2B, 0xC8, 0xAD, 0xB8, 0xE2,
    0x97, 0x2A, 0x6E, 0x52, 0x0E, 0x90, 0x1F, 0x8A, 0x7C, 0x5D, 0x97, 0x4B, 0x69, 0xCF, 0xC3, 0xEB,
    0x7B, 0x3A, 0xF6, 0xB5, 0x5B, 0x0E, 0x07, 0x2D, 0xF5, 0x8B, 0x77, 0xF5, 0xEE, 0xCF, 0x0B, 0x1E,
    0x75, 0x5C, 0xB9, 0x10, 0x65, 0xEB, 0xF3, 0x5B, 0x4C, 0x1A, 0x72, 0xEC, 0xA5, 0xBF, 0x3C, 0x96,
    0x4C, 0x21, 0xEA, 0xBC, 0xD1, 0xE8, 0xDF, 0x35, 0x4B, 0xBD, 0xF8, 0x6D, 0x7C, 0x1E, 0xF4, 0x2E,
    0x48, 0x53, 0x4E, 0x76, 0x48, 0x70, 0x91, 0x52, 0x8B, 0xF4, 0x33, 0xEB, 0x60, 0x5F, 0x43, 0x00,
    0x6B, 0x88, 0xC2, 0xC4, 0xB4, 0xD6, 0x85, 0x0F, 0x25, 0x40, 0xD7, 0xF6, 0x72, 0x24, 0xB3, 0xDA,
    0x3B, 0x43, 0x6F, 0x43, 0xB4, 0xF6, 0xB6, 0x49, 0x1F, 0xB2, 0x8A, 0x52, 0x8C, 0x6A, 0xBC, 0x53,
    0xD6, 0xDC, 0x8A, 0xB2, 0xCB, 0xC8, 0x82, 0x53, 0xDC, 0xF5, 0xB9, 0x8F, 0xEC, 0xEB, 0xF7, 0xA7,
    0x0E, 0xE2, 0x79, 0xCE, 0xE9, 0x32, 0xB6, 0x7A, 0xC5, 0xE7, 0x04, 0x2E, 0xA6, 0xFE, 0xDA, 0xAB,
    0x36, 0x12, 0xA7, 0x43, 0x02, 0x03, 0x01, 0x00, 0x01, 0xA3, 0x63, 0x30, 0x61, 0x30, 0x0E, 0x06,
    0x03, 0x55, 0x1D, 0x0F, 0x01, 0x01, 0xFF, 0x04, 0x04, 0x03, 0x02, 0x01, 0x06, 0x30, 0x0F, 0x06,
    0x03, 0x55, 0x1D, 0x13, 0x01, 0x01, 0xFF, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xFF, 0x30, 0x1D,
    0x06, 0x03, 0x55, 0x1D, 0x0E, 0x04, 0x16, 0x04, 0x14, 0x0E, 0x39, 0x01, 0x7D, 0x26, 0xCB, 0x02,
    0x6A, 0xE0, 0xCA, 0x34, 0x65, 0x50, 0x20, 0xA1, 0x44, 0x6C, 0xEC, 0x7F, 0x9E, 0x30, 0x1F, 0x06,
    0x03, 0x55, 0x1D, 0x23, 0x04, 0x18, 0x30, 0x16, 0x80, 0x14, 0x0E, 0x39, 0x01, 0x7D, 0x26, 0xCB,
    0x02, 0x6A, 0xE0, 0xCA, 0x34, 0x65, 0x50, 0x20, 0xA1, 0x44, 0x6C, 0xEC, 0x7F, 0x9E, 0x30, 0x41,
    0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x0A, 0x30, 0x34, 0xA0, 0x0F, 0x30,
    0x0D, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0xA1, 0x1C,
    0x30, 0x1A, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x08, 0x30, 0x0D, 0x06,
    0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0xA2, 0x03, 0x02, 0x01,
    0x20, 0x03, 0x82, 0x02, 0x01, 0x00, 0x61, 0x9D, 0xA9, 0xE9, 0x54, 0xEC, 0xF4, 0x7B, 0x17, 0x45,
    0x7D, 0x2C, 0xAF, 0xF1, 0x5C, 0x41, 0x64, 0xA2, 0xF4, 0x5C, 0x86, 0x03, 0xB9, 0xEE, 0x67, 0x99,
    0xEA, 0x34, 0x08, 0x9D, 0xBB, 0xEF, 0x44, 0xE3, 0xE8, 0xD6, 0x5A, 0xC0, 0xE2, 0x4F, 0x90, 0xE0,
    0x25, 0xBB, 0x34, 0x80, 0x26, 0x91, 0x8A, 0x65, 0xD6, 0x60, 0x4D, 0xF6, 0x5D, 0x8C, 0xA8, 0x11,
    0x52, 0x61, 0x80, 0xCC, 0xBD, 0x08, 0x05, 0xD3, 0x9F, 0xDA, 0x56, 0xE6, 0x47, 0x2C, 0xF8, 0x42,
    0x6D, 0x5E, 0xEA, 0x74, 0xEA, 0x07, 0xA4, 0xEF, 0xBD, 0xEC, 0x9E, 0x92, 0xC9, 0xF1, 0x7F, 0x10,
    0xC0, 0x42, 0xAD, 0x2D, 0xDB, 0x36, 0xC8, 0xBF, 0x8D, 0x4E, 0x4B, 0x74, 0x4E, 0x6D, 0xFE, 0x42,
    0x4F, 0x9E, 0x93, 0x29, 0x1E, 0xE6, 0xA7, 0xBB, 0x7A, 0x41, 0x1F, 0x37, 0x12, 0xBF, 0x33, 0x68,
    0xAF, 0x16, 0x6D, 0xE8, 0x45, 0x33, 0x1D, 0x29, 0xB9, 0x14, 0xED, 0xFA, 0x44, 0x93, 0xED, 0xBD,
    0xF6, 0x37, 0x3A, 0x76, 0x8C, 0x8E, 0xE3, 0xC6, 0x5B, 0xA0, 0x8B, 0xBF, 0xBF, 0xA0, 0x9A, 0x11,
    0x77, 0x06, 0x1D, 0xEC, 0xD2, 0x93, 0x76, 0x4A, 0x63, 0x2D, 0x20, 0x73, 0xDD, 0xD7, 0xE2, 0x82,
    0xDD, 0x86, 0xA7, 0xC5, 0x39, 0x05, 0x35, 0xF1, 0x02, 0xF3, 0xBA, 0x86, 0xC5, 0x64, 0x6F, 0x83,
    0x87, 0x6C, 0x9E, 0x67, 0xFA, 0x1E, 0x5A, 0xBD, 0x8F, 0x2A, 0xFC, 0x7C, 0xF3, 0x77, 0x6C, 0x5C,
    0xED, 0xB2, 0x45, 0x1D, 0x5C, 0xB9, 0xA4, 0xBE, 0x27, 0x87, 0xFB, 0xCC, 0xD7, 0x3F, 0x3F, 0x31,
    0x16, 0x54, 0xA7, 0x11, 0x8B, 0x28, 0xEA, 0x33, 0x35, 0xAA, 0xD8, 0x11, 0x25, 0x52, 0xCC, 0x86,
    0x5C, 0xF6, 0x8B, 0xC0, 0xD3, 0xC5, 0x8A, 0x99, 0xA4, 0xAA, 0x5E, 0x40, 0xA0, 0x37, 0x01, 0x2F,
    0xEC, 0xAF, 0xDC, 0x0C, 0x29, 0xCA, 0x02, 0x9E, 0xF7, 0x6A, 0x49, 0xD4, 0x00, 0x62, 0x60, 0xEB,
    0x30, 0x0D, 0xDC, 0x16, 0x62, 0x91, 0x22, 0xD8, 0x33, 0xE5, 0x7E, 0x4E, 0x67, 0x38, 0x15, 0x1F,
    0xD4, 0x40, 0x6F, 0xFE, 0x19, 0x29, 0x1D, 0xBE, 0x0D, 0x24, 0x9B, 0x12, 0xAD, 0xDE, 0x2C, 0xF0,
    0xA1, 0x57, 0x2D, 0x8F, 0xF2, 0x5E, 0xDF, 0x9D, 0x15, 0x40, 0xB3, 0xA0, 0x62, 0x49, 0x8E, 0x4D,
    0x05, 0xDD, 0x04, 0x2B, 0x4C, 0xA3, 0xC4, 0xF9, 0xAB, 0xF6, 0x56, 0xAB, 0xC9, 0x9C, 0xB7, 0x50,
    0xED, 0x4B, 0x82, 0x9A, 0x2F, 0x18, 0x0B, 0x41, 0x03, 0x76, 0xD7, 0x84, 0x12, 0xE4, 0xCA, 0x98
};

/* 根证书第二部分，用宏定义 */

#define PSS_ROOT_CERT_PART2                                                                               \
    {                                                                                                     \
        0xEB, 0xC9, 0x85, 0xCA, 0xE5, 0x37, 0x78, 0xA3, 0x7B, 0xB0, 0x3E, 0xC1, 0x53, 0x38, 0x46, 0xEA,   \
        0xDF, 0xA9, 0x85, 0x58, 0x45, 0x27, 0xA9, 0xAC, 0x94, 0xF3, 0xA9, 0x6B, 0x13, 0x92, 0x69, 0x41,   \
        0x70, 0x05, 0x75, 0xB5, 0x9D, 0x9E, 0x1A, 0x7E, 0x82, 0xAB, 0x93, 0xB1, 0x05, 0x5D, 0x54, 0x35,   \
        0xC6, 0xBD, 0xFB, 0x16, 0xC7, 0x3E, 0x6B, 0x63, 0xFB, 0x0C, 0x5F, 0x46, 0x0F, 0x89, 0x62, 0xCB,   \
        0x32, 0xDC, 0xFB, 0x4C, 0x4E, 0x25, 0x94, 0x55, 0xAC, 0xCE, 0xDF, 0x34, 0xF6, 0xDD, 0x20, 0x3D,   \
        0x1A, 0xDA, 0x0A, 0x7A, 0xE6, 0xAC, 0x93, 0x2B, 0x8C, 0x2B, 0x0F, 0xFC, 0x6C, 0x4B, 0xB7, 0x3A,   \
        0x36, 0xD0, 0x0F, 0xBE, 0x5F, 0x12, 0x5F, 0xF1, 0xFB, 0xEB, 0x25, 0x7B, 0xFD, 0x71, 0x6D, 0xAA,   \
        0x69, 0x9F, 0x46, 0x3D, 0xD8, 0xC8, 0x68, 0xF6, 0x0D, 0xCB, 0x56, 0x67, 0xCA, 0x94, 0x55, 0x3B,   \
        0x31, 0x1D, 0x0C, 0x55, 0x31, 0x69, 0x1E, 0x17, 0x37, 0xFB, 0x1B, 0x86, 0xAE, 0xEA, 0x3A, 0xA7,   \
        0x50, 0x2A, 0xD9, 0xC7, 0x0C, 0x24, 0xAD, 0xB3, 0xCC, 0xDC, 0x7E, 0x8B, 0x03, 0x75, 0x5D, 0xAC,   \
        0x5D, 0x68, 0x58, 0xDD, 0x21, 0x8E                                                                \
    }

#if defined(VRD_CMS)
int g_code_len_size = 0;
int g_base_size = 0;
int sign_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    int align;
    align = CMS_DATA_RESERVE_GAP - (g_code_len_size % CMS_DATA_ALIGN);       // 对齐地址
    return (g_base_size + SECURE_HDR_SIZE + g_code_len_size + align + CMS_TAG_AND_LEN_SIZE);
}

int list_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    return (sign_file_offset(cms_file_info) + CMS_FILE_SIZE_16K);
}

int crl_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    return (list_file_offset(cms_file_info) + CMS_INI_FILE_SIZE_2K);
}
int up_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    return (SECURE_HDR_SIZE);
}
#else
int list_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    return (CMS_FILE_INFO_OFFSET +
        ((cms_file_info)->file_num * 2 + 1) * CMS_LEN_CHAR_NUM); /* 文件偏移((cms_file_info)->file_num * 2 + 1) */
}

int sign_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    return (list_file_offset(cms_file_info) + (cms_file_info)->file_list_len);
}

int crl_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    return (sign_file_offset(cms_file_info) + (cms_file_info)->cms_sign_len);
}

int up_file_offset(const CMS_FILE_INFO *cms_file_info)
{
    return (crl_file_offset(cms_file_info) + (cms_file_info)->crl_file_len);
}
#endif

#define DCMI_CMS_FILE_NAME_LENTH 256

char g_cms_file_name[DCMI_CMS_FILE_NAME_LENTH] = {0};
int g_total_up_file_len = 0;

int cms_get_file_len(const char *file_name, int *file_len)
{
    FILE *fp = NULL;
#ifndef _WIN32
    char path[PATH_MAX + 1] = {0x00};
#else
    char path[MAX_PATH + 1] = {0x00};
#endif

    if (check_filename(file_name, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "Upgrade file path is illegal.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((fp = fopen((const char *)path, "r")) == NULL) {
        gplog(LOG_ERR, "open file %s failed errno(%d).", path, errno);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fseek(fp, 0, SEEK_END);
    *file_len = ftell(fp);
    (void)fseek(fp, 0, SEEK_SET);

    (void)fclose(fp);

    return NPU_OK;
}
#ifndef _WIN32
// 从文件中读取一定数据
int cms_read_buff_from_file(const char *file_name, char *buffer, int offset, int lenth)
{
    int ret;
    int count;
    FILE *fp = NULL;
    char path[PATH_MAX + 1] = {0x00};

    ret = check_filename(file_name, path, sizeof(path));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Upgrade file path is illegal.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((fp = fopen((const char *)path, "r")) == NULL) {
        gplog(LOG_ERR, "open file %s failed errno(%d).", path, errno);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = fseek(fp, offset, SEEK_SET);
    if (ret != 0) {
        gplog(LOG_ERR, "call fseek fail.file %s failed errno(%d).", path, errno);
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    count = (int)fread(buffer, 1, lenth, fp);
    if ((count == 0) || (count != lenth)) {
        gplog(LOG_ERR, "count(%d) err. len_curr(%d).", count, lenth);
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)fclose(fp);

    return NPU_OK;
}
#else
int cms_read_buff_from_file(const char *file_name, char *buffer, int offset, int lenth)
{
    int ret;
    char path[MAX_PATH + 1] = { 0x00 };
    HANDLE hFile;
    DWORD dwStatus;
    DWORD dwPoint;
    DWORD cbRead = 0;
    wchar_t pcStr[MAX_PATH + 1] = { 0x00 };

    if (check_filename(file_name, path, sizeof(path)) != NPU_OK) {
        gplog(LOG_ERR, "Upgrade file path is illegal.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = MultiByteToWideChar(CP_ACP, 0, path, -1, pcStr, 0);
    dwStatus = MultiByteToWideChar(CP_ACP, 0, path, -1, pcStr, ret);
    if (dwStatus == FALSE) {
        dwStatus = GetLastError();
        gplog(LOG_ERR, "call MultiByteToWideChar Error: %d", dwStatus);
        return NPU_ERR_CODE_INNER_ERR;
    }

    hFile = CreateFile(pcStr, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        dwStatus = GetLastError();
        gplog(LOG_ERR, "Error opening file %s\nError: %d", path, dwStatus);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }
    dwPoint = SetFilePointer(hFile, (LONG)offset, NULL, FILE_BEGIN);
    if (dwPoint == INVALID_SET_FILE_POINTER) {
        dwStatus = GetLastError();
        gplog(LOG_ERR, "call SetFilePointer Error: %d", dwStatus);
        CloseHandle(hFile);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }
    if (ReadFile(hFile, buffer, lenth, &cbRead, NULL) == FALSE) {
        dwStatus = GetLastError();
        gplog(LOG_ERR, "call ReadFile Error: %d", dwStatus);
        CloseHandle(hFile);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    CloseHandle(hFile);
    return NPU_OK;
}
#endif
int cms_read_cms_file_info_item(uint32_t offset, uint32_t *val)
{
    int32_t ret;
    char buf[CMS_LEN_CHAR_NUM + 1] = {0};

    ret = cms_read_buff_from_file((const char *)g_cms_file_name, (char *)buf, offset, CMS_LEN_CHAR_NUM);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read_app_flash_content failed, ret = %d", ret);
        return ret;
    }

#if defined(VRD_CMS)
    *val = *(uint32_t *)buf;
#else
    ret = sscanf_s(buf, "%x", val);
    if (ret <= 0) {
        gplog(LOG_ERR, "call sscanf_s failed.%d.\n", ret);
    }
#endif
    return NPU_OK;
}

#if defined(VRD_CMS)
int cms_read_cms_file_info(CMS_FILE_INFO *cms_file_info)
{
    int ret;
    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    /* 读取ImageDesc大小 */
    ret = cms_read_cms_file_info_item(CMS_IMG_DESC, (uint32_t*)&g_base_size);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms g_base_size failed, ret = %d", ret);
        return ret;
    }

    /* 读取正文大小 */
    ret = cms_read_cms_file_info_item(CMS_CODE_LEN_SIZE, (uint32_t*)&g_code_len_size);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms g_code_len_size failed, ret = %d", ret);
        return ret;
    }

    /* 读取cms文件大小 正文偏移与文件大小地址偏移为CMS_FIEL_SIZE_D */
    ret = cms_read_cms_file_info_item(sign_file_offset(cms_file_info) - CMS_FIEL_SIZE_D,
        &cms_file_info->cms_sign_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms cms_sign_len failed, ret = %d", ret);
        return ret;
    }

    /* 读取src文件大小 */
    ret = cms_read_cms_file_info_item(list_file_offset(cms_file_info) - CMS_FIEL_SIZE_D,
        &cms_file_info->file_list_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms file_list_len failed, ret = %d", ret);
        return ret;
    }

    /* 读取crl文件大小 正文偏移与文件大小地址偏移为CMS_FIEL_SIZE_D */
    ret = cms_read_cms_file_info_item(crl_file_offset(cms_file_info) - CMS_FIEL_SIZE_D,
        &cms_file_info->crl_file_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms crl_file_len failed, ret = %d", ret);
        return ret;
    }

    return NPU_OK;
}
#else
// 从bin中读取cms文件
int cms_read_cms_file_info(CMS_FILE_INFO *cms_file_info)
{
    int ret;

    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    /* 读取file_num */
    ret = cms_read_cms_file_info_item(CMS_FILE_INFO_OFFSET, &cms_file_info->file_num);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms file_num failed, ret = %d", ret);
        return ret;
    }
    /* 读取file1_id */
    ret = cms_read_cms_file_info_item(CMS_FILE_LIST_ID_OFFSET, &cms_file_info->file1_id);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms file1_id failed, ret = %d", ret);
        return ret;
    }
    /* 读取file_list_len */
    ret = cms_read_cms_file_info_item(CMS_FILE_LIST_LEN_OFFSET, &cms_file_info->file_list_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms file_list_len failed, ret = %d", ret);
        return ret;
    }
    /* 读取file2_id */
    ret = cms_read_cms_file_info_item(CMS_SIGN_FILE_ID_OFFSET, &cms_file_info->file2_id);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms file2_id failed, ret = %d", ret);
        return ret;
    }
    /* 读取cms_sign_len */
    ret = cms_read_cms_file_info_item(CMS_SIGN_FILE_LEN_OFFSET, &cms_file_info->cms_sign_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms sign_len failed, ret = %d", ret);
        return ret;
    }
    /* 读取file3_id */
    ret = cms_read_cms_file_info_item(CMS_CRL_FILE_ID_OFFSET, &cms_file_info->file3_id);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms file3_id failed, ret = %d", ret);
        return ret;
    }
    /* 读取crl_file_len */
    ret = cms_read_cms_file_info_item(CMS_CRL_FILE_LEN_OFFSET, &cms_file_info->crl_file_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "read cms crl_file_len failed, ret = %d", ret);
        return ret;
    }

    return NPU_OK;
}
#endif
// 校验签名文件基本信息
int check_cms_file_info(const CMS_FILE_INFO *cms_file_info)
{
    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((cms_file_info->file_num == CMS_FILE_NUM) && (cms_file_info->file1_id == CMS_FILE_LIST_ID) &&
        (cms_file_info->file2_id == CMS_SIGN_FILE_ID) && (cms_file_info->file3_id == CMS_CRL_FILE_ID)) {
        return NPU_OK;
    }

    gplog(LOG_ERR, "Check cms_file_info failed.");
    gplog(LOG_ERR,
        "file_num = %u file1_id = %u file_list_len = %u file2_id = %u cms_sign_len = %u file3_id = %u crl_file_len = "
        "%u",
        cms_file_info->file_num, cms_file_info->file1_id, cms_file_info->file_list_len, cms_file_info->file2_id,
        cms_file_info->cms_sign_len, cms_file_info->file3_id, cms_file_info->crl_file_len);

    return NPU_ERR_CODE_INNER_ERR;
}

int update_content(CMSCBB_VRF_CTX ctx, const CMS_FILE_INFO *cms_file_info)
{
    CMSCBB_ERROR_CODE ret;
    CVB_UINT32 total_len = 0;
    CVB_UINT32 buf_len = MAX_FLASH_BUF_LEN;
    CVB_BYTE *read_buf = CVB_NULL;
    int offset;
    int err;

    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    offset = list_file_offset(cms_file_info);

    read_buf = (CVB_BYTE *)malloc(MAX_FLASH_BUF_LEN);
    if (read_buf == NULL) {
        gplog(LOG_ERR, "pvPortMalloc failed.");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    /* 从Flash中读取数据到read_buf中 */
    while (total_len < cms_file_info->file_list_len) {
        if (total_len + buf_len > cms_file_info->file_list_len) {
            buf_len = cms_file_info->file_list_len - total_len;
        }

        err = memset_s(read_buf, MAX_FLASH_BUF_LEN, 0, MAX_FLASH_BUF_LEN);
        if (err != 0) {
            gplog(LOG_ERR, "call memset_s failed.%d.\n", err);
        }

        err = cms_read_buff_from_file((const char *)g_cms_file_name, (char *)read_buf, offset, buf_len);
        if (err != NPU_OK) {
            gplog(LOG_ERR, "read_up_file_content failed, rc = %d", err);
            free(read_buf);
            return err;
        }

        ret = CmscbbVerifyDetachSignatureUpdate(ctx, (const CVB_BYTE *)read_buf, buf_len);
        if (ret != CVB_SUCCESS) {
            gplog(LOG_ERR, "cmscbb_verify_detach_signature_update failed, ret = %d", (int)ret);
            free(read_buf);
            return NPU_ERR_CODE_INNER_ERR;
        }

        total_len += buf_len;
        offset += (int)buf_len;
    }

    free(read_buf);
    return NPU_OK;
}
CVB_UINT32 digest_algorithm_str_to_id(const char *digest_algo)
{
    if (strncmp(digest_algo, STR_HASH256_DIGEST, strlen(STR_HASH256_DIGEST)) == 0) {
        return CMSCBB_HASH_SHA256;
    } else if (strncmp(digest_algo, STR_HASH384_DIGEST, strlen(STR_HASH384_DIGEST)) == 0) {
        return CMSCBB_HASH_SHA384;
    } else if (strncmp(digest_algo, STR_HASH512_DIGEST, strlen(STR_HASH512_DIGEST)) == 0) {
        return CMSCBB_HASH_SHA512;
    } else {
        gplog(LOG_ERR, "Wrong digest algorithm : %s", digest_algo);
        return 0;
    }
}

int verify_detach_signature_quick(CMSCBB_VRF_CTX ctx, const CMS_FILE_INFO *cms_file_info, CVB_INT32 *result)
{
    int ret;
    CMSCBB_ERROR_CODE err;
    CVB_BYTE *pSig = CVB_NULL;

    /* 入参校验 */
    if (cms_file_info == NULL || result == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info OR result is null.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    *result = CVB_FALSE;

    /* 读取签名文件的内容 */
    if (cms_file_info->cms_sign_len > 0) {
        pSig = (CVB_BYTE *)malloc(cms_file_info->cms_sign_len);
        if (pSig == NULL) {
            gplog(LOG_ERR, "malloc failed, cms_sign_len=%u.", cms_file_info->cms_sign_len);
            return NPU_ERR_CODE_MEM_OPERATE_FAIL;
        }
        (void)memset_s(pSig, cms_file_info->cms_sign_len, 0, cms_file_info->cms_sign_len);
    } else {
        gplog(LOG_ERR, "malloc failed, cms_sign_len=%u.", cms_file_info->cms_sign_len);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = cms_read_buff_from_file((const char *)g_cms_file_name, (char *)pSig, sign_file_offset(cms_file_info),
        cms_file_info->cms_sign_len);
    if (ret != 0) {
        gplog(LOG_ERR, "read_cms_file_content failed, ret = %d", ret);
        free(pSig);
        return ret;
    }

    err = CmscbbVerifyDetachSignatureBegin(ctx, pSig, (CVB_UINT32)cms_file_info->cms_sign_len);
    if (err != 0) {
        gplog(LOG_ERR, "cmscbb_verify_detach_signature_begin, err = %u", err);
        free(pSig);
        return err;
    }
    free(pSig);
    pSig = NULL;

    ret = update_content(ctx, cms_file_info);
    if (ret != 0) {
        gplog(LOG_ERR, "update_content failed, ret = %d", ret);
        return ret;
    }

    err = CmscbbVerifyDetachSignatureFinal(ctx, result);
    if (err != CVB_SUCCESS) {
        gplog(LOG_ERR, "cmscbb_verify_detach_signature_final failed, err = %u", err);
        return err;
    }
    return err;
}

int IsValidPath(const char *fileName)
{
    return access(fileName, W_OK);
}

int IsOwnerRoot(const char *dirName)
{
    struct stat dirStat;

    if (stat(dirName, &dirStat) != 0) {
        gplog(LOG_ERR, "stat %s fail.", dirName);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if ((dirStat.st_uid) != ROOT_UID) {
        gplog(LOG_ERR, "need change the folder %s owner to root.", dirName);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    return NPU_OK;
}

int CheckSaveCrlPathPermission(const char *dirName)
{
    struct stat dirStat;

    if ((IsOwnerRoot(dirName) != 0) && (chown(dirName, ROOT_UID, ROOT_UID) != 0)) {
        gplog(LOG_ERR, "change dir %s owner to root fail.", dirName);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (stat(dirName, &dirStat) != 0) {
        gplog(LOG_ERR, "dir %s stat error.", dirName);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if ((dirStat.st_mode & 0x1ff) != FILE_PERMISSION_755 && (chmod(dirName, PERMISSION_HWSIPCRL) != 0)) {
        gplog(LOG_ERR, "change dir %s permission to 755 fail.", dirName);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    return NPU_OK;
}

static int ChangePermission(const char *fileName)
{
    struct stat crlPathStat;

    if (IsValidPath(fileName) == 0) {
        if (stat(fileName, &crlPathStat) != 0) {
            gplog(LOG_ERR, "stat %s fail.", fileName);
            return NPU_ERR_CODE_FILE_OPERATE_FAIL;
        }

        if ((crlPathStat.st_mode != PERMISSION_CRL) && (chmod(fileName, PERMISSION_CRL) != 0)) {
            gplog(LOG_ERR, "chmod %s permission fail.", fileName);
            return NPU_ERR_CODE_FILE_OPERATE_FAIL;
        }

        if ((IsOwnerRoot(fileName) != 0) && (chown(fileName, ROOT_UID, ROOT_UID) != 0)) {
            gplog(LOG_ERR, "chown %s owner fail.", fileName);
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
    }

    return NPU_OK;
}

int ChangeCrlPermissionAndOwner()
{
    int ret;

    ret = ChangePermission(CRL_PATH);
    ret += ChangePermission(CRL_PATH_PSS);

    return ret;
}

int CreateCrlSavePath(const char *dirName)
{
    struct stat crlSavePathStat;
#ifndef _WIN32
    if (mkdir(dirName, PERMISSION_HWSIPCRL) != 0) {
#else
    if (_mkdir(dirName) != 0) {
#endif
        gplog(LOG_ERR, "mkdir dir %s fail!", dirName);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (chmod(dirName, PERMISSION_HWSIPCRL) != 0) {
        gplog(LOG_ERR, "chmod dir %s fail!", dirName);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    gplog(LOG_INFO, "create dir %s!", dirName);

    if (stat(dirName, &crlSavePathStat) != 0) {
        gplog(LOG_ERR, "stat dir %s fail!", dirName);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }
    if ((crlSavePathStat.st_mode & 0x1ff) == FILE_PERMISSION_755) {
        return NPU_OK;
    }

    gplog(LOG_ERR, "dir %s permission is incorrect!", dirName);
    return NPU_ERR_CODE_INNER_ERR;
}

#ifdef _WIN32
int CopyCrlToSavePath(const char *updateCrl, int len, const char *desFile)
{
    int ret;
    CHAR path[MAX_PATH + 1] = { 0x00 };
    HANDLE hFile;
    DWORD dwStatus;
    DWORD cbWrite = 0;
    wchar_t pcStr[MAX_PATH + 1] = { 0x00 };

    if (check_filename(desFile, path, sizeof(path)) != DCMI_OK) {
        gplog(LOG_ERR, "Upgrade file path is illegal.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = MultiByteToWideChar(CP_ACP, 0, path, -1, pcStr, 0);
    dwStatus = MultiByteToWideChar(CP_ACP, 0, path, -1, pcStr, ret);
    if (dwStatus == FALSE) {
        dwStatus = GetLastError();
        gplog(LOG_ERR, "call MultiByteToWideChar Error: %d\n", dwStatus);
        return NPU_ERR_CODE_INNER_ERR;
    }

    hFile = CreateFile(pcStr, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        dwStatus = GetLastError();
        gplog(LOG_ERR, "Error opening file %s\nError: %d\n", desFile, dwStatus);
        return NPU_ERR_CODE_INNER_ERR;
    }
    /* 请空文件 */
    SetFilePointer(hFile, 0, 0, FILE_BEGIN);
    SetEndOfFile(hFile);

    if (WriteFile(hFile, updateCrl, len, &cbWrite, NULL) == FALSE) {
        dwStatus = GetLastError();
        gplog(LOG_ERR, "call ReadFile Error: %d", dwStatus);
        CloseHandle(hFile);
        return NPU_ERR_CODE_INNER_ERR;
    }
    if (cbWrite != len) {
        gplog(LOG_ERR, "call ReadFile Error: writted=%d, clrLen=%d", cbWrite, len);
    }
    CloseHandle(hFile);
    return NPU_OK;
}
#else
int CopyCrlToSavePath(const char *updateCrl, int len, const char *desFile)
{
    int fd = -1;
    int ret;

    fd = open(desFile, O_RDWR | O_CREAT, PERMISSION_CRL);
    if (fd < 0) {
        gplog(LOG_ERR, "open file fail!");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = write(fd, updateCrl, len);
    if (ret < 0) {
        gplog(LOG_ERR, "write crl file fail!");
        close(fd);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)close(fd);

    if (ChangeCrlPermissionAndOwner() != 0) {
        gplog(LOG_ERR, "change crl permission fail!");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    gplog(LOG_INFO, "Update crl file success!");
    return NPU_OK;
}
#endif

int ChkSysLocalCrl(const char *updateCrl, int len, int isPssCrl)
{
    /* 检查默认crl路径是否存在, 若不存在则进行创建 */
    if ((IsValidPath(CRL_SAVE_PATH) != 0) && (CreateCrlSavePath(CRL_SAVE_PATH) != 0)) {
        gplog(LOG_ERR, "ChkSysLocalCrl creatre crl path failed.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 文件夹存在,检查文件夹属主和权限 */
    if (CheckSaveCrlPathPermission(CRL_SAVE_PATH) != 0) {
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 检查默认crl文件是否存在, 若不存在, 使用用户输入CRL进行创建 */
    if (IsValidPath((isPssCrl == 0) ? CRL_PATH : CRL_PATH_PSS) != 0) {
        if (CopyCrlToSavePath(updateCrl, len, (isPssCrl == 0) ? CRL_PATH : CRL_PATH_PSS) != 0) {
            return NPU_ERR_CODE_INNER_ERR;
        }

        gplog(LOG_INFO, "System local CRL file not exist, use input CRL(%d) to create!.", isPssCrl);
        return UPDATE_OK;
    } else if (ChangeCrlPermissionAndOwner() != 0) {
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

static int verify_cms_file_use_pss_cert(const char *updateCrl, const CMS_FILE_INFO *cms_file_info)
{
    CMSCBB_ERROR_CODE ret = -1;
    int err;
    CMSCBB_VRF_CTX vrf_ctx = NULL;              /* 解析updatePathCrl的上下文 */
    CmscbbCtxCreateParams createParams = { 0 }; /* 回调函数注册 */
    CVB_INT32 result = 0;

    createParams.st_size = sizeof(createParams);
    if ((ret = CmscbbVerifyCreateCtx(&vrf_ctx, &createParams)) != CVB_SUCCESS) {
        gplog(LOG_ERR, "CmscbbVerifyCreateCtx failed(%u).", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    err = transmit_pss_cert_to_cmscbb(&vrf_ctx);
    if (err != NPU_OK) {
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "transmit_pss_cert_to_cmscbb failed(%d).", err);
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = CmscbbVerifyAddCrl(vrf_ctx, (const CVB_BYTE *)updateCrl, cms_file_info->crl_file_len);
    if (ret != CVB_SUCCESS) {
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "CmscbbVerifyAddCrl failed(%u).", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if ((err = verify_detach_signature_quick(vrf_ctx, cms_file_info, &result)) != 0 || (CVB_UINT32)result != CVB_TRUE) {
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "verify_detach_signature_quick failed(%d).", err);
        return NPU_ERR_CODE_INNER_ERR;
    }

    CmscbbVrfCtxFree(vrf_ctx);
    return NPU_OK;
}

int ChkUsrInputCrl(const char *updateCrl, const CMS_FILE_INFO *cms_file_info, int *IsPssCrl)
{
    CMSCBB_ERROR_CODE ret = -1;
    int err;
    CMSCBB_VRF_CTX vrf_ctx = NULL;              /* 解析updatePathCrl的上下文 */
    CmscbbCtxCreateParams createParams = { 0 }; /* 回调函数注册 */
    CVB_INT32 result = 0;

    if (cms_file_info->crl_file_len >= CRL_MAX_SIZE) {
        gplog(LOG_ERR, "The crl file size(%u) is too large.", cms_file_info->crl_file_len);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    createParams.st_size = sizeof(createParams);

    /* 先使用pcks证书解析，在用pss解析。为解析updateCrl创建上下文 */
    if ((ret = CmscbbVerifyCreateCtx(&vrf_ctx, &createParams)) != CVB_SUCCESS) {
        gplog(LOG_ERR, "CmscbbVerifyCreateCtx failed(%u).", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 加入根证书 */
    ret = CmscbbVerifyAddCert(vrf_ctx, (const CVB_BYTE *)g_root_cert, sizeof(g_root_cert));
    if (ret != CVB_SUCCESS) {
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "CmscbbVerifyAddCert failed(%u).", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 加入crl */
    ret = CmscbbVerifyAddCrl(vrf_ctx, (const CVB_BYTE *)updateCrl, cms_file_info->crl_file_len);
    if (ret != CVB_SUCCESS) {
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "CmscbbVerifyAddCrl failed(%u).", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 校验签名 */
    if ((err = verify_detach_signature_quick(vrf_ctx, cms_file_info, &result)) != 0 || (CVB_UINT32)result != CVB_TRUE) {
        CmscbbVrfCtxFree(vrf_ctx);

        err = verify_cms_file_use_pss_cert(updateCrl, cms_file_info);
        if (err != NPU_OK) {
            gplog(LOG_ERR, "verify_cms_file_use_pss_cert failed(%d).", err);
            return NPU_ERR_CODE_INNER_ERR;
        }

        *IsPssCrl = 1;
        return NPU_OK;
    }

    CmscbbVrfCtxFree(vrf_ctx);
    *IsPssCrl = 0;

    return NPU_OK;
}

STATIC int AddCert(CMSCBB_VRF_CTX *vrf_ctx, int isPssCrl)
{
    int ret;
    CMSCBB_ERROR_CODE err;
    if (isPssCrl == 0) {
        /* 添加PKCS根证书 */
        err = CmscbbVerifyAddCert(*vrf_ctx, (const CVB_BYTE *)g_root_cert, sizeof(g_root_cert));
        if (err != CVB_SUCCESS) {
            gplog(LOG_ERR, "Add root certificate failed");
            return NPU_ERR_CODE_INNER_ERR;
        }
    } else {
        /* 添加PSS根证书 */
        ret = transmit_pss_cert_to_cmscbb(vrf_ctx);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "%s: add pss failed", __FUNCTION__);
            return NPU_ERR_CODE_INNER_ERR;
        }
    }

    return NPU_OK;
}

static int DoCrlCompare(const char *updateCrl, int len, int isPssCrl, CmscbbCrlPeriodStat *stat)
{
    CMSCBB_VRF_CTX vrf_ctx = NULL;             /* 解析updateCrl的上下文 */
    CmscbbCtxCreateParams createParams = { 0 }; /* 回调函数注册 */
    CmscbbCrlBundleInfo *pCrlToUpdate = NULL;   /* CRL解析结果 */
    CmscbbCrlBundleInfo *pCrlOnDevice = NULL;   /* CRL解析结果 */
    CmscbbCrlPeriodStat crlStat = SCPS_MIX;     /* CRL比较结果 */
    uint32_t ret;

    createParams.st_size = sizeof(createParams);

    /* 为解析pszCrlToUpdate创建上下文 */
    if ((CmscbbVerifyCreateCtx(&vrf_ctx, &createParams)) != CVB_SUCCESS) {
        gplog(LOG_ERR, "CmscbbVerifyCreateCtx fail.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 加入根证书 */
    if (AddCert(&vrf_ctx, isPssCrl) != NPU_OK) {
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "CmscbbVerifyAddCert fail.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 解析pszCrlToUpdate */
    if ((CmscbbDecodeCrl(vrf_ctx, (const CVB_BYTE *)updateCrl, (CVB_UINT32)len, &pCrlToUpdate)) != CVB_SUCCESS) {
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "CmscbbDecodeCrl fail.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 解析pCrlOnDevice */
    if ((CmscbbDecodeCrlFile(vrf_ctx, (const CVB_CHAR *)(isPssCrl == 0 ? CRL_PATH : CRL_PATH_PSS), &pCrlOnDevice)) !=
        CVB_SUCCESS) {
        CmscbbCrlFree(vrf_ctx, pCrlToUpdate);
        gplog(LOG_ERR, "CmscbbVerifyAddCert or CmscbbDecodeCrlFile fail.");
        return LOCAL_CRL_IS_ERROR;
    }

    /* 比较两个crl */
    if ((ret = (CmscbbCrlCompare(vrf_ctx, pCrlToUpdate, pCrlOnDevice, &crlStat))) != CVB_SUCCESS) {
        CmscbbCrlFree(vrf_ctx, pCrlToUpdate);
        CmscbbCrlFree(vrf_ctx, pCrlOnDevice);
        CmscbbVrfCtxFree(vrf_ctx);
        gplog(LOG_ERR, "CmscbbCrlCompare fail(%u).", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 保存crl比较的结果 */
    *stat = crlStat;

    /* 销毁资源 */
    CmscbbCrlFree(vrf_ctx, pCrlToUpdate);
    CmscbbCrlFree(vrf_ctx, pCrlOnDevice);
    CmscbbVrfCtxFree(vrf_ctx);
    return NPU_OK;
}

int UpdateCrlFile(const char *updateCrl, const CMS_FILE_INFO *cms_file_info)
{
    CmscbbCrlPeriodStat stat;
    int ret;
    int isPssCrl;

    if (ChkUsrInputCrl(updateCrl, cms_file_info, &isPssCrl) != NPU_OK) {
        gplog(LOG_ERR, "ChkUsrInputCrl error!");
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = ChkSysLocalCrl(updateCrl, cms_file_info->crl_file_len, isPssCrl);
    if (ret == UPDATE_OK) {
        return NPU_OK;
    } else if (ret != NPU_OK) {
        gplog(LOG_ERR, "ChkSysLocalCrl error!");
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = DoCrlCompare(updateCrl, cms_file_info->crl_file_len, isPssCrl, &stat);
    if (ret == LOCAL_CRL_IS_ERROR) {
        if (CopyCrlToSavePath(updateCrl, cms_file_info->crl_file_len, (isPssCrl == 0 ? CRL_PATH : CRL_PATH_PSS)) != 0) {
            return NPU_ERR_CODE_INNER_ERR;
        }

        gplog(LOG_INFO, "local crl error, update crl to local!");
        return NPU_OK;
    } else if (ret != NPU_OK) {
        gplog(LOG_ERR, "DoCrlCompare: return error code %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    switch (stat) {
        case SCPS_SAME:
        case SCPS_OLD:
            gplog(LOG_INFO, "input CRL is same with or older than local, No need to update!");
            return NPU_OK;

        case SCPS_NEW:
            gplog(LOG_INFO, "input CRL is newer, update to local now(%d)!", isPssCrl);
            if (CopyCrlToSavePath(updateCrl, cms_file_info->crl_file_len, (isPssCrl == 0) ? CRL_PATH : CRL_PATH_PSS) !=
                0) {
                return NPU_ERR_CODE_INNER_ERR;
            }
            return NPU_OK;

        case SCPS_MIX:
            gplog(LOG_INFO, "can not compare input CRL, Not to update!");
            break;

        default:
            gplog(LOG_INFO, "unknown compare result, Not to update!");
            break;
    }

    return NPU_OK;
}

int update_add_crl_file(const CMS_FILE_INFO *cms_file_info, CMSCBB_VRF_CTX vrf_ctx)
{
    int ret = 0;
    CMSCBB_ERROR_CODE err;
    /* 添加CRL */
    if (cms_file_info->crl_file_len > 0) {
        CVB_BYTE *content = (CVB_BYTE *)malloc(cms_file_info->crl_file_len);
        if (content == NULL) {
            gplog(LOG_ERR, "pvPortMalloc failed.");
            return NPU_ERR_CODE_MEM_OPERATE_FAIL;
        }
        (void)memset_s(content, cms_file_info->crl_file_len, 0, cms_file_info->crl_file_len);

        int file_offset = crl_file_offset(cms_file_info);
        ret = cms_read_buff_from_file((const char *)g_cms_file_name, (char *)content, file_offset,
                                      cms_file_info->crl_file_len);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "read_cms_file_content failed, ret = %d", ret);
            free(content);
            return ret;
        }

        ret = UpdateCrlFile((char *)content, cms_file_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "UpdateCrlFile failed(%d)", ret);
            free(content);
            return ret;
        }

        if (IsValidPath(CRL_PATH) == 0) {
            err = CmscbbVerifyAddCrlFile(vrf_ctx, CRL_PATH);
            if (err != CVB_SUCCESS) {
                gplog(LOG_ERR, "CmscbbVerifyAddCrlFile failed, err = %u", err);
                free(content);
                return NPU_ERR_CODE_INNER_ERR;
            }
        }

        if (IsValidPath(CRL_PATH_PSS) == 0) {
            err = CmscbbVerifyAddCrlFile(vrf_ctx, CRL_PATH_PSS);
            if (err != CVB_SUCCESS) {
                gplog(LOG_ERR, "CmscbbVerifyAddCrlFile failed, err = %u", err);
                free(content);
                return NPU_ERR_CODE_INNER_ERR;
            }
        }

        free(content);
    }

    return ret;
}

STATIC int transmit_pss_cert_to_cmscbb(CMSCBB_VRF_CTX *pCtx)
{
    CMSCBB_ERROR_CODE ret;
    errno_t secure_ret;
    CVB_UINT32 pss_root_cert_byte;                   /* pss根证书总字节数 */
    CVB_BYTE *pss_root_cert = NULL;                  /* pss根证书汇总 */
    CVB_BYTE pss_root_cert2[] = PSS_ROOT_CERT_PART2; /* pss根证书局部数据 */

    if (pCtx == NULL) {
        gplog(LOG_ERR, "%s: input param error", __FUNCTION__);
        return NPU_ERR_CODE_INNER_ERR;
    }
    /* 组合根证书 */
    pss_root_cert_byte = sizeof(pbPssRootCert0) + sizeof(pss_root_cert2);
    pss_root_cert = (CVB_BYTE *)malloc(pss_root_cert_byte);
    if (pss_root_cert == NULL) {
        gplog(LOG_ERR, "%s: malloc failed", __FUNCTION__);
        return NPU_ERR_CODE_INNER_ERR;
    }

    secure_ret = memcpy_s(pss_root_cert, pss_root_cert_byte, pbPssRootCert0, sizeof(pbPssRootCert0));
    if (secure_ret != EOK) {
        gplog(LOG_ERR, "%s: memcpy_s failed", __FUNCTION__);
        free(pss_root_cert);
        return NPU_ERR_CODE_INNER_ERR;
    }

    secure_ret = memcpy_s(pss_root_cert + sizeof(pbPssRootCert0), pss_root_cert_byte - sizeof(pbPssRootCert0),
        pss_root_cert2, sizeof(pss_root_cert2));
    if (secure_ret != EOK) {
        gplog(LOG_ERR, "%s: memcpy_s failed", __FUNCTION__);
        free(pss_root_cert);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 添加根证书 */
    ret = CmscbbVerifyAddCert(*pCtx, (const CVB_BYTE *)pss_root_cert, pss_root_cert_byte);
    if (ret != CVB_SUCCESS) {
        gplog(LOG_ERR, "%s: add root certificate failed, code %u", __FUNCTION__, ret);
        free(pss_root_cert);
        return NPU_ERR_CODE_INNER_ERR;
    }

    free(pss_root_cert);

    return NPU_OK;
}

int verify_file_sign(const CMS_FILE_INFO *cms_file_info)
{
    CMSCBB_VRF_CTX vrf_ctx = NULL;
    CMSCBB_ERROR_CODE ret;
    int err;
    CmscbbCtxCreateParams create_params = { 0 };
    CVB_INT32 result = 0;

    /* 入参判断 */
    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.\r\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    /* 初始化创建参数，并注册回调函数 */
    create_params.st_size = sizeof(CmscbbCtxCreateParams);

    /* 创建验证上下文 */
    ret = CmscbbVerifyCreateCtx(&vrf_ctx, &create_params);
    if (ret != CVB_SUCCESS) {
        gplog(LOG_ERR, "Failed cmscbb_verify_create_ctx, ret = %d\r\n", (int)ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 添加根证书 */
    ret = CmscbbVerifyAddCert(vrf_ctx, (const CVB_BYTE *)g_root_cert, sizeof(g_root_cert));
    if (ret != CVB_SUCCESS) {
        gplog(LOG_ERR, "Add root certificate failed");
        CmscbbVrfCtxFree(vrf_ctx);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 添加PSS根证书 */
    err = transmit_pss_cert_to_cmscbb(&vrf_ctx);
    if (err != NPU_OK) {
        gplog(LOG_ERR, "%s: add pss failed", __FUNCTION__);
        CmscbbVrfCtxFree(vrf_ctx);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 添加CRL */
    err = update_add_crl_file(cms_file_info, vrf_ctx);
    if (err != CVB_SUCCESS) {
        gplog(LOG_ERR, "update_add_crl_file failed");
        CmscbbVrfCtxFree(vrf_ctx);
        return err;
    }

    /* 在保持证书和crl不变的前提下可以重复调用验证过程验证多个签名 */
    err = verify_detach_signature_quick(vrf_ctx, cms_file_info, &result);
    if (err != 0) {
        gplog(LOG_ERR, "verify signature error, code %08x.", err);
        CmscbbVrfCtxFree(vrf_ctx);
        return err;
    }

    if ((CVB_UINT32)result != CVB_TRUE) {
        gplog(LOG_ERR, "verify signature not match.\n");
        CmscbbVrfCtxFree(vrf_ctx);
        return NPU_ERR_CODE_INNER_ERR;
    }

    gplog(LOG_INFO, "verify signature success.");
    /* 销毁资源 */
    CmscbbVrfCtxFree(vrf_ctx);

    return NPU_OK;
}

int read_up_file_line(int offset, CVB_BYTE *line_buf, int buf_len)
{
    int ret;
    int byte_cnt = 0;

    if ((line_buf == NULL) || (buf_len == 0)) {
        gplog(LOG_ERR, "Input parameter error : line_buf is null OR buf_len is 0, buf_len = %d\r\n", buf_len);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    while (byte_cnt < buf_len) {
        /* 每次从Flash中读取1个字节 */
        ret = cms_read_buff_from_file((const char *)g_cms_file_name, (char *)(line_buf + byte_cnt),
                                      offset + byte_cnt, 1);
        if (ret != 0) {
            gplog(LOG_ERR, "SPI_FLASH_ReadAppCode failed, ret = %d\r\n", ret);
            return ret;
        }

        /* 遇到换行符结束一行的读取 */
        if (line_buf[byte_cnt] == '\n') {
            line_buf[byte_cnt] = '\0';
            return NPU_OK;
        }

        byte_cnt++;
    }

    gplog(LOG_ERR, "Line too long.\r\n");
    return NPU_ERR_CODE_INNER_ERR;
}

void byte_to_str(char *str, int max_str_len, uint8_t *src_byte, uint32_t byte_cnt)
{
    unsigned int i;
    int ret;
    int pos_curr = 0;
    const int POS_OFFSET = 2;

    if ((str == NULL) || (src_byte == NULL) || (max_str_len <= 1)) {
        gplog(LOG_ERR, "Input parameter error.\r\n");
        return;
    }

    for (i = 0; i < byte_cnt; i++) {
        ret = sprintf_s(str + pos_curr, max_str_len - 1 - pos_curr, "%02x", src_byte[i]);
        if (ret <= 0) {
            gplog(LOG_ERR, "sprintf failed.\n");
            return;
        }
        pos_curr += POS_OFFSET;
    }
}

int md_update(const CMS_FILE_INFO *cms_file_info, CMSCBB_CRYPTO_MD_CTX ctx)
{
    int buf_len;
    int err;
    CMSCBB_ERROR_CODE ret;
#if defined(VRD_CMS)
    int offset_end = up_file_offset(cms_file_info) + g_code_len_size + g_base_size;
#else
    int offset_end = g_total_up_file_len;
#endif
    int offset = up_file_offset(cms_file_info);

    char *buf = (char *)malloc(MAX_MD_BUF_LEN);
    if (buf == NULL) {
        gplog(LOG_ERR, "pvPortMalloc failed : buf is null.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    while (offset < offset_end) {
        err = memset_s(buf, MAX_MD_BUF_LEN, 0, MAX_MD_BUF_LEN);
        if (err != 0) {
            gplog(LOG_ERR, "call memset_s failed.%d.\n", err);
        }

        if (offset + MAX_MD_BUF_LEN > offset_end) {
            buf_len = offset_end - offset;
        } else {
            buf_len = MAX_MD_BUF_LEN;
        }

        err = cms_read_buff_from_file((const char *)g_cms_file_name, buf, offset, buf_len);
        if (err != NPU_OK) {
            gplog(LOG_ERR, "read_app_flash_content failed, ret = %d\r\n", err);
            free(buf);
            return err;
        }

        ret = CmscbbMdUpdate(ctx, (const unsigned char *)buf, buf_len);
        if (ret != CVB_SUCCESS) {
            gplog(LOG_ERR, "Failed to update md context, ret = %d\r\n", (int)ret);
            free(buf);
            return NPU_ERR_CODE_INNER_ERR;
        }

        offset += buf_len;
    }
    free(buf);

    return NPU_OK;
}

bool is_check_invalid(const CMS_FILE_INFO *cms_file_info,
    const char *digest_algo, char *md, int md_max_len, int *len)
{
#if defined(VRD_CMS)
    bool check_invalid = (cms_file_info == NULL) || (md_max_len == 0) ||
        (md == NULL) || (len == NULL);
#else
    bool check_invalid = (cms_file_info == NULL) || (digest_algo == NULL) ||
        (md == NULL) || (md_max_len == 0) || (len == NULL);
#endif
    return check_invalid;
}

CMSCBB_ERROR_CODE init_cmscbb_md(CMSCBB_CRYPTO_MD_CTX ctx, const char *digest_algo)
{
    CMSCBB_ERROR_CODE ret;
#if defined(VRD_CMS)
    ret = (CMSCBB_ERROR_CODE)(CmscbbMdInit(ctx, (CVB_UINT32)CMSCBB_HASH_SHA256));
#else
    ret = (CMSCBB_ERROR_CODE)(CmscbbMdInit(ctx, (CVB_UINT32)digest_algorithm_str_to_id(digest_algo)));
#endif
    if (ret != 0) {
        gplog(LOG_ERR, "init md context error, ret = %d\r\n.", (int)ret);
        CmscbbMdDestoryCtx(ctx);
        return NPU_ERR_CODE_INNER_ERR;
    }
    return ret;
}

int cal_up_file_md(const CMS_FILE_INFO *cms_file_info, const char *digest_algo, char *md, int md_max_len, int *len)
{
    CMSCBB_CRYPTO_MD_CTX ctx = NULL;
    CVB_UINT32 md_len = 0;

    /* 入参校验 */
    if (is_check_invalid(cms_file_info, digest_algo, md, md_max_len, len)) {
        gplog(LOG_ERR, "Input parameter error.\r\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    /* 创建摘要计算上下文 */
    CMSCBB_ERROR_CODE ret = (CMSCBB_ERROR_CODE)CmscbbMdCreateCtx(&ctx);
    if (ret != CVB_SUCCESS) {
        gplog(LOG_ERR, "create md context error, ret = %d\r\n.", (int)ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = init_cmscbb_md(ctx, digest_algo);
    if (ret != 0) {
        return NPU_ERR_CODE_INNER_ERR;
    }

    int err = md_update(cms_file_info, ctx);
    if (err != 0) {
        gplog(LOG_ERR, "md update error, ret = %d\r\n.", err);
        CmscbbMdDestoryCtx(ctx);
        return err;
    }

    char *md_byte = (char *)malloc(MAX_MD_HASH_LEN);
    if (md_byte == NULL) {
        gplog(LOG_ERR, "malloc failed : md_byte is null.\n");
        CmscbbMdDestoryCtx(ctx);
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }
    err = memset_s(md_byte, MAX_MD_HASH_LEN, 0, MAX_MD_HASH_LEN);
    if (err != 0) {
        gplog(LOG_ERR, "call memset_s failed.%d.\n", err);
    }

    /* 获取最终摘要值 */
    CVB_UINT32 md_byte_max_len = MAX_MD_HASH_LEN;
    ret = (CMSCBB_ERROR_CODE)(CmscbbMdFinal(ctx, (CVB_BYTE *)md_byte, &md_len, &md_byte_max_len));
    if (ret != CVB_SUCCESS) {
        gplog(LOG_ERR, "final md context error, ret = %d\r\n", (int)ret);
        CmscbbMdDestoryCtx(ctx);
        free(md_byte);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 字节转换为字符串 */
    byte_to_str(md, md_max_len, (uint8_t *)md_byte, md_len);
    *len = md_len * 2; /* len为md_len * 2 */

    /* 清理资源 */
    free(md_byte);
    CmscbbMdDestoryCtx(ctx);

    return NPU_OK;
}

int compare_file_md(const CMS_FILE_INFO *cms_file_info, char *buf, int offset)
{
    char *calc_hash = NULL;

    (void)memset_s(buf, MAX_LINE_BUF + 1, 0, MAX_LINE_BUF + 1);
    int ret = read_up_file_line(offset, (CVB_BYTE *)buf, MAX_LINE_BUF + 1);
    if (ret != NPU_OK) {
        goto err_quit;
    }

    char *digest_sep = strchr(buf, ':');
    if (digest_sep == NULL) {
        gplog(LOG_ERR, "strchr buf[%s] failed.\r\n", buf);
        ret = NPU_ERR_CODE_INNER_ERR;
        goto err_quit;
    }

    char *file_hash = digest_sep + strlen(": ");
    if (strlen(file_hash) == 0) {
        gplog(LOG_ERR, "Hash value is null\r\n");
        ret = NPU_ERR_CODE_INNER_ERR;
        goto err_quit;
    }

    *digest_sep = '\0';
    char *digest_algo = buf;

    calc_hash = malloc(HASH_MAX_SIZE + 1);
    if (calc_hash == NULL) {
        gplog(LOG_ERR, "malloc failed : calc_hash is null.");
        ret = NPU_ERR_CODE_MEM_OPERATE_FAIL;
        goto err_quit;
    }

    (void)memset_s(calc_hash, HASH_MAX_SIZE + 1, 0, HASH_MAX_SIZE + 1);

    int has_len = 0;
    ret = cal_up_file_md(cms_file_info, digest_algo, calc_hash, HASH_MAX_SIZE + 1, &has_len);
    if (ret != 0) {
        goto err_quit;
    }

    /* 比较摘要值 */
    if (strcmp(file_hash, calc_hash) != 0) {
        gplog(LOG_ERR, "checksum in file list : %s : %s\r\n", digest_algo, file_hash);
        gplog(LOG_ERR, "checksum of real file : %s : %s\r\n", digest_algo, calc_hash);
        ret = NPU_ERR_CODE_INNER_ERR;
        goto err_quit;
    }

err_quit:
    if (calc_hash != NULL) {
        free(calc_hash);
    }
    return ret;
}
#if defined(VRD_CMS)
int get_hash_data(const CMS_FILE_INFO *cms_file_info, char **hash_buf)
{
    int ret;
    int offset = FILE_HASH_OFFSET;

    /* 入参校验 */
    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.\r\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    *hash_buf = malloc(HASH_MAX_SIZE + 1);
    if (*hash_buf == NULL) {
        gplog(LOG_ERR, "pvPortMalloc failed : buf is null.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    char *hash_buf_tmp = malloc(SHA256_LEN + 1);
    if (hash_buf_tmp == NULL) {
        free(*hash_buf);
        *hash_buf = NULL;
        gplog(LOG_ERR, "pvPortMalloc failed : buf is null.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    (void)memset_s(*hash_buf, HASH_MAX_SIZE + 1, 0, HASH_MAX_SIZE + 1);
    (void)memset_s(hash_buf_tmp, SHA256_LEN + 1, 0, SHA256_LEN + 1);

    ret = cms_read_buff_from_file((const char *)g_cms_file_name, hash_buf_tmp, offset, SHA256_LEN);
    if (ret != NPU_OK) {
        free(*hash_buf);
        *hash_buf = NULL;
        free(hash_buf_tmp);
        hash_buf_tmp = NULL;
        gplog(LOG_ERR, "read_up_file_line failed, ret = %d\r\n", ret);
        return ret;
    }

    /* 字节转换为字符串 */
    byte_to_str(*hash_buf, HASH_MAX_SIZE + 1, (uint8_t *)hash_buf_tmp, SHA256_LEN);
    free(hash_buf_tmp);
    hash_buf_tmp = NULL;

    return 0;
}

int verify_file_checksum(const CMS_FILE_INFO *cms_file_info)
{
    int ret = 0;
    int has_len = 0;
    char *hash_buf = NULL;
    /* 入参校验 */
    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.\r\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = get_hash_data(cms_file_info, &hash_buf);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get_hash_data failed, ret = %d\r\n", ret);
        goto err_quit_hash;
    }

    char *calc_hash = malloc(HASH_MAX_SIZE + 1);
    if (calc_hash == NULL) {
        gplog(LOG_ERR, "malloc failed : calc_hash is null.");
        ret = NPU_ERR_CODE_MEM_OPERATE_FAIL;
        goto err_quit_hash;
    }

    (void)memset_s(calc_hash, HASH_MAX_SIZE + 1, 0, HASH_MAX_SIZE + 1);

    ret = cal_up_file_md(cms_file_info, NULL, calc_hash, HASH_MAX_SIZE + 1, &has_len);
    if (ret != 0) {
        goto err_quit_calc;
    }

    /* 比较摘要值 */
    if (strcmp(hash_buf, calc_hash) != 0) {
        gplog(LOG_ERR, "checksum in file list : %s\r\n", hash_buf);
        gplog(LOG_ERR, "checksum of real file : %s\r\n", calc_hash);
        ret = NPU_ERR_CODE_INNER_ERR;
        goto err_quit_calc;
    }
err_quit_calc:
    if (calc_hash != NULL) {
        free(calc_hash);
    }
err_quit_hash:
    if (hash_buf != NULL) {
        free(hash_buf);
    }

    return ret;
}
#else
int verify_file_checksum(const CMS_FILE_INFO *cms_file_info)
{
    int ret = 0;
    int name_flag = 0;

    /* 入参校验 */
    if (cms_file_info == NULL) {
        gplog(LOG_ERR, "Input parameter error : cms_file_info is null.\r\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int offset = list_file_offset(cms_file_info);
    int offset_end = sign_file_offset(cms_file_info);

    char *buf = malloc(MAX_LINE_BUF + 1);
    if (buf == NULL) {
        gplog(LOG_ERR, "pvPortMalloc failed : buf is null.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    while (offset < offset_end) {
        ret = memset_s(buf, MAX_LINE_BUF + 1, 0, MAX_LINE_BUF + 1);
        if (ret != 0) {
            gplog(LOG_ERR, "call memset_s failed.%d.\n", ret);
        }

        ret = read_up_file_line(offset, (CVB_BYTE *)buf, MAX_LINE_BUF + 1);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "read_up_file_line failed, ret = %d\r\n", ret);
            goto err_quit;
        }

        offset += (int)(strlen(buf) + 1);
        size_t len = strlen(CMS_LIST_NAME);
        if (strncmp(buf, CMS_LIST_NAME, len) == 0) {
            name_flag = 1;
            ret = compare_file_md(cms_file_info, buf, offset);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "get_file_md failed, ret = %d\r\n", ret);
                goto err_quit;
            }
            break;
        }
    }

    if (name_flag == 0) {
        gplog(LOG_ERR, "File list wrong : can't find digest.\r\n");
        ret = NPU_ERR_CODE_INNER_ERR;
        goto err_quit;
    }

err_quit:
    if (buf != NULL) {
        free(buf);
    }

    return ret;
}
#endif

STATIC int cms_get_file_check_size(const char *file_name)
{
    int ret;

    ret = cms_get_file_len(file_name, &g_total_up_file_len);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to get cms file info, ret = %d, file_len = %d\r\n", ret, g_total_up_file_len);
        return ret;
    }

    if (g_total_up_file_len > VALIDATE_FILE_MAX_SIZE) {
        gplog(LOG_ERR, "cms file is too large, file_len = %d\r\n", g_total_up_file_len);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return NPU_OK;
}
// 总入口
int cms_validate_sign(const char *file_name)
{
    int ret = -1;
    int cms_file_info_sz;
    int file_length;
    CMS_FILE_INFO cms_file_info = { 0 };

    if ((file_name == NULL) || (strlen(file_name) + 1 > DCMI_CMS_FILE_NAME_LENTH)) {
        gplog(LOG_ERR, "Failed to get cms file info, ret = %d\r\n", ret);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = memcpy_s(g_cms_file_name, DCMI_CMS_FILE_NAME_LENTH, file_name, strlen(file_name) + 1);
    if (ret != EOK) {
        gplog(LOG_ERR, "call memcpy_s failed.%d\n", ret);
    }

    ret = cms_get_file_check_size(file_name);
    if (ret != NPU_OK) {
        return ret;
    }

    /* 从Flash中读取文件信息 */
    ret = cms_read_cms_file_info(&cms_file_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to get cms file info, ret = %d\r\n", ret);
        return ret;
    }
#if defined(VRD_CMS)
    cms_file_info_sz = (int)(cms_file_info.file_list_len + cms_file_info.cms_sign_len + cms_file_info.crl_file_len);
#else
    /* 校验签名文件基本信息 */
    if (check_cms_file_info(&cms_file_info) != 0) {
        gplog(LOG_ERR, "check_cms_file_info failed.\r\n");
        return NPU_ERR_CODE_INNER_ERR;
    }

    cms_file_info_sz = (int)
        (sizeof(CMS_FILE_INFO) + cms_file_info.file_list_len + cms_file_info.cms_sign_len + cms_file_info.crl_file_len);
#endif
    /* 从Flash中读取升级文件总长度 */
    file_length = g_total_up_file_len;

    if (file_length < cms_file_info_sz) {
        gplog(LOG_ERR, "File length is too short : file_length = %d\r\n", file_length);
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 校验清单文件的签名 */
    ret = verify_file_sign(&cms_file_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Verify file sign failed, ret = %d\r\n", ret);
        return ret;
    }

    /* 校验文件校验和 */
    ret = verify_file_checksum(&cms_file_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Verify file checksum failed, ret = %d\r\n", ret);
        return ret;
    }
    return NPU_OK;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */
