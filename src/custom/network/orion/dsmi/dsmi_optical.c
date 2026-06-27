/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <linux/limits.h>
#include "ds_data.h"
#include "tool_comm.h"
#include "tool_errcode.h"
#include "dsmi_optical.h"
#include "comm_channel.h"
#include "tool_lib.h"
#include "ascend_hal_error.h"
#include "dsmi_common_interface.h"
#include "dsmi_common.h"
#include "dsmi_upgrade_proc.h"
#include "cmscbb.h"

#define EXPORT_FUNCTION __attribute__ ((visibility ("default")))

#define POLL_INTERVAL 10    // 轮询间隔（秒）
#define MAX_RETRY 120       // 最大重试次数 (2小时 = 720 * 10秒)
#define UPGRADE_PROGRESS_MAX 100  // 升级进度最大值
#define CMS_READ_BUF_SIZE 4096    // CMS 验证读取缓冲区大小
#define CMS_MAX_FILE_SIZE (10 * 1024 * 1024)  // CMS 签名文件最大 10MB
#define CMS_SIGNATURE_EXT ".cms"   // CMS 签名文件扩展名
#define CMS_CRL_EXT ".crl"         // CRL 吊销列表扩展名

// 光模块固件组件类型（使用 DSMI_COMPONENT_TYPE_MAX 类似 bootrom 的方式）
#define DSMI_COMPONENT_TYPE_XSFP_FIRMWARE ((DSMI_COMPONENT_TYPE)DSMI_COMPONENT_TYPE_MAX)

// 华为根证书（DER 格式，对应公司内部RSA-PKCS#1V1.5算法的根证书）
static const unsigned char g_optical_root_cert[] = {
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

// 光模块升级状态机状态字符串定义
const char* optical_upgrade_sm_str[OPTICAL_UPGRADE_SM_MAX] = {
    "IDLE",                 /* 空闲状态 */
    "FEATURES_GET",         /* 获取特性 */
    "START_DOWNLOAD",       /* 开始固件下载 */
    "WRITE_FW",             /* 写入固件 */
    "COMPLETE_DOWNLOAD",    /* 完成固件下载 */
    "RUN_FW_IMAGE",         /* 运行固件镜像 */
    "COMMIT_FW_IMAGE",      /* 提交固件镜像 */
    "SUCCESS",              /* 升级成功 */
    "FAULT_PROC",           /* 故障处理 */
};

// 光模块升级处理状态字符串定义
const char* optical_upgrade_state_str[OPTICAL_UPGRADE_STATE_MAX] = {
    "IDLE",        /* 空闲状态 */
    "PROCESSING",  /* 处理中 */
    "SUCCESS",     /* 升级成功 */
    "FAILED",      /* 升级失败 */
};

// 根据状态机状态计算升级进度 (0-100)
static unsigned char calculate_upgrade_progress(unsigned char sm_status)
{
    unsigned char progress;
    
    // 状态机状态总数为 OPTICAL_UPGRADE_SM_SUCCESS (8个有效状态)
    // 进度 = (当前状态 / 总状态数) * 100
    if (sm_status >= OPTICAL_UPGRADE_SM_SUCCESS) {
        return UPGRADE_PROGRESS_MAX;
    }
    progress = (unsigned char)((sm_status * UPGRADE_PROGRESS_MAX) / OPTICAL_UPGRADE_SM_SUCCESS);
    return (progress > UPGRADE_PROGRESS_MAX) ? UPGRADE_PROGRESS_MAX : progress;
}

static int optical_check_upgrade_status(struct command_context *ctx,
    unsigned char optical_id, struct optical_upgrade_result *result)
{
    int ret;
    struct product_channel_msg msg = {0};

    // 通过 product_host_device_channel 与 RDFX/IMP 交互
    SET_PRODUCT_MSG(msg, &optical_id, sizeof(unsigned char), result, sizeof(*result));
    ret = product_host_device_channel(ctx, CMD_OPTICAL_GET_UPGRADE_STATUS, &msg);

    return ret;
}

/**
 * optical_upgrade_reset() - 重置 IMP 侧升级状态并释放 HBM 内存
 * @ctx: 命令上下文
 * @hbm_addr_high: HBM 物理地址高 32 位
 * @hbm_addr_low: HBM 物理地址低 32 位
 * @hbm_size: HBM 内存大小
 *
 * 在升级结束（成功、失败或超时）后调用，重置 IMP 侧的升级状态标志位。
 * HBM 内存在 RDFX 侧通过 ioctl 释放。
 *
 * Return: 0 成功，负值失败
 */
static int optical_upgrade_reset(struct command_context *ctx,
    unsigned int hbm_addr_high, unsigned int hbm_addr_low, unsigned int hbm_size)
{
    int ret;
    struct product_channel_msg msg = {0};
    struct xsfp_upgrade_reset reset_req = {0};

    // 填充重置请求，包含 HBM 地址信息
    reset_req.optical_index = (unsigned int)ctx->optical_id;  // IMP 期望 u32 类型
    reset_req.hbm_addr_high = hbm_addr_high;
    reset_req.hbm_addr_low = hbm_addr_low;
    reset_req.hbm_size = hbm_size;

    // 通过 product_host_device_channel 与 RDFX/IMP 交互
    // RDFX 侧会先释放 HBM 内存，再重置 IMP 升级状态
    SET_PRODUCT_MSG(msg, &reset_req, sizeof(reset_req), NULL, 0);
    ret = product_host_device_channel(ctx, CMD_OPTICAL_UPGRADE_RESET, &msg);
    if (ret) {
        hccn_err("Upgrade reset failed. (ret=%d)", ret);
    } else {
        hccn_info("Upgrade reset successfully");
    }

    return ret;
}

static int optical_transmit_firmware_to_device(struct command_context *ctx,
    const char *firmware_path, char *dst_path_out, int dst_path_size)
{
    int ret;
    int device_id = ctx->npu_info.logic_id;
    char *dst_path = NULL;

    if (!firmware_path) {
        return TOOL_INVALID_PARAM;
    }

    dst_path = (char *)calloc(PATH_MAX, sizeof(char));
    if (dst_path == NULL) {
        hccn_err("dst_path calloc failed");
        return TOOL_ENOMEM;
    }

    ret = find_file_name(device_id, firmware_path, dst_path);
    if (ret != 0) {
        hccn_err("find_file_name failed, file=%s, device_id=%d, ret=%d", firmware_path, device_id, ret);
        goto out;
    }

    ret = transmit_file_to_device(device_id, firmware_path,
                                  dst_path, DSMI_COMPONENT_TYPE_XSFP_FIRMWARE);
    if (ret) {
        hccn_err("Transmit firmware to device failed. (ret=%d)", ret);
        goto out;
    }

    if (dst_path_out && dst_path_size > 0) {
        ret = strncpy_s(dst_path_out, dst_path_size, dst_path, strlen(dst_path));
        if (ret != EOK) {
            hccn_err("strncpy_s failed. (ret=%d)", ret);
            ret = TOOL_INVALID_PARAM;
            goto out;
        }
    }

    hccn_info("Firmware transmitted to device: %s -> %s", firmware_path, dst_path);

out:
    free(dst_path);
    return ret;
}

// 处理升级结果状态
static int handle_upgrade_result(struct command_context *ctx,
    struct optical_upgrade_result *result)
{
    optical_upgrade_reset(ctx, result->hbm_addr_high, result->hbm_addr_low, result->hbm_size);

    if (result->upgrade_state.state == OPTICAL_UPGRADE_STATE_SUCCESS) {
        hccn_info("Optical firmware upgrade success. Version: %s", result->firmware_ver);
        TOOL_PRINT_INFO("Upgrade completed successfully!");
        return 0;
    }

    if (result->upgrade_state.state == OPTICAL_UPGRADE_STATE_PROCESSING) {
        hccn_err("Optical firmware upgrade timeout at stage: %s",
            optical_upgrade_sm_str[result->upgrade_state.sm_status]);
        return DRV_ERROR_WAIT_TIMEOUT;
    }

    if (result->upgrade_state.state == OPTICAL_UPGRADE_STATE_FAILED) {
        hccn_err("Optical firmware upgrade failed. error_code=%u", result->upgrade_state.err_status);
        return result->upgrade_state.err_status ? (int)result->upgrade_state.err_status : DRV_ERROR_STATUS_FAIL;
    }

    hccn_err("Optical firmware upgrade unexpected state:%d, sm_status: %d, err_status: %u",
        result->upgrade_state.state, result->upgrade_state.sm_status,
        result->upgrade_state.err_status);
    return result->upgrade_state.err_status ? (int)result->upgrade_state.err_status : DRV_ERROR_STATUS_FAIL;
}

// 轮询升级状态
static int poll_upgrade_status(struct command_context *ctx,
    struct optical_upgrade_result *result)
{
    int ret;
    unsigned char last_sm_status = 0xFF;
    int retry_count = 0;

    do {
        ret = optical_check_upgrade_status(ctx, (unsigned char)ctx->optical_id, result);
        if (ret) {
            hccn_err("Check upgrade status failed. (ret=%d)", ret);
            optical_upgrade_reset(ctx, result->hbm_addr_high, result->hbm_addr_low, result->hbm_size);
            return ret;
        }

        result->progress = calculate_upgrade_progress(result->upgrade_state.sm_status);

        if (result->upgrade_state.sm_status != last_sm_status) {
            if (result->upgrade_state.sm_status < OPTICAL_UPGRADE_SM_SUCCESS) {
                TOOL_PRINT_INFO("Upgrade state: %s, stage: %s (%d%%)",
                    optical_upgrade_state_str[result->upgrade_state.state],
                    optical_upgrade_sm_str[result->upgrade_state.sm_status],
                    result->progress);
            } else {
                TOOL_PRINT_INFO("Upgrading... %d%%", result->progress);
            }
            last_sm_status = result->upgrade_state.sm_status;
        }

        if (result->upgrade_state.state == OPTICAL_UPGRADE_STATE_PROCESSING) {
            sleep(POLL_INTERVAL);
        }
    } while (result->upgrade_state.state == OPTICAL_UPGRADE_STATE_PROCESSING && retry_count++ < MAX_RETRY);

    return 0;
}

/**
 * read_file_to_buffer() - 读取整个文件到内存
 * @path: 文件路径
 * @buf: 输出缓冲区（调用方需释放）
 * @buf_len: 输出缓冲区长度
 *
 * Return: 0 成功，负值失败
 */
static int read_file_to_buffer(const char *path, CVB_BYTE **buf, CVB_UINT32 *buf_len)
{
    FILE *fp = NULL;
    long file_size;
    int ret = 0;

    if (!path || !buf || !buf_len) {
        return TOOL_INVALID_PARAM;
    }

    *buf = NULL;
    *buf_len = 0;

    fp = fopen(path, "rb");
    if (!fp) {
        hccn_err("Failed to open file: %s, errno=%d", path, errno);
        return TOOL_INVALID_PARAM;
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        hccn_err("fseek SEEK_END failed, path=%s, errno=%d", path, errno);
        ret = TOOL_INVALID_PARAM;
        goto out;
    }
    file_size = ftell(fp);
    if (fseek(fp, 0, SEEK_SET) != 0) {
        hccn_err("fseek SEEK_SET failed, path=%s, errno=%d", path, errno);
        ret = TOOL_INVALID_PARAM;
        goto out;
    }

    if (file_size <= 0 || file_size > CMS_MAX_FILE_SIZE) {
        hccn_err("Invalid file size: %ld, path=%s", file_size, path);
        ret = TOOL_INVALID_PARAM;
        goto out;
    }

    *buf = (CVB_BYTE *)malloc((size_t)file_size);
    if (!*buf) {
        hccn_err("malloc failed, size=%ld", file_size);
        ret = TOOL_ENOMEM;
        goto out;
    }

    if (fread(*buf, 1, (size_t)file_size, fp) != (size_t)file_size) {
        hccn_err("fread failed, path=%s", path);
        free(*buf);
        *buf = NULL;
        ret = TOOL_INVALID_PARAM;
        goto out;
    }

    *buf_len = (CVB_UINT32)file_size;

out:
    if (fp != NULL) {
        (void)fclose(fp);
    }
    return ret;
}

/**
 * cms_update_firmware_content() - 将固件内容分块送入 CMS 验证
 * @ctx: CMS 验证上下文
 * @firmware_path: 固件文件路径
 *
 * Return: 0 成功，负值失败
 */
static int cms_update_firmware_content(CMSCBB_VRF_CTX ctx, const char *firmware_path)
{
    FILE *fp = NULL;
    CVB_BYTE read_buf[CMS_READ_BUF_SIZE];
    size_t nread;
    CMSCBB_ERROR_CODE ret;

    fp = fopen(firmware_path, "rb");
    if (!fp) {
        hccn_err("Failed to open firmware file: %s, errno=%d", firmware_path, errno);
        return TOOL_INVALID_PARAM;
    }

    while ((nread = fread(read_buf, 1, sizeof(read_buf), fp)) > 0) {
        ret = CmscbbVerifyDetachSignatureUpdate(ctx, read_buf, (CVB_UINT32)nread);
        if (ret != CVB_SUCCESS) {
            hccn_err("CmscbbVerifyDetachSignatureUpdate failed, ret=%d", (int)ret);
            (void)fclose(fp);
            return DRV_ERROR_STATUS_FAIL;
        }
    }

    (void)fclose(fp);
    return 0;
}

/**
 * derive_cms_file_paths() - 从固件路径推导 .cms 和 .crl 文件路径
 * @firmware_path: 固件文件路径
 * @cms_path: 输出 CMS 签名文件路径（调用方分配 PATH_MAX）
 * @crl_path: 输出 CRL 吊销列表路径（调用方分配 PATH_MAX）
 *
 * 命名约定：firmware.bin → firmware.cms + firmware.crl
 * 替换最后一个 '.' 之后的扩展名
 *
 * Return: 0 成功，负值失败
 */
static int derive_cms_file_paths(const char *firmware_path, char *cms_path, char *crl_path)
{
    int err;
    char *dot = NULL;

    err = strncpy_s(cms_path, PATH_MAX, firmware_path, strlen(firmware_path));
    if (err != EOK) {
        hccn_err("strncpy_s for cms_path failed");
        return TOOL_INVALID_PARAM;
    }
    dot = strrchr(cms_path, '.');
    if (!dot) {
        hccn_err("Firmware path has no extension: %s", firmware_path);
        return TOOL_INVALID_PARAM;
    }
    *dot = '\0';
    err = strncat_s(cms_path, PATH_MAX, CMS_SIGNATURE_EXT, strlen(CMS_SIGNATURE_EXT));
    if (err != EOK) {
        hccn_err("strncat_s " CMS_SIGNATURE_EXT " failed");
        return TOOL_INVALID_PARAM;
    }

    err = strncpy_s(crl_path, PATH_MAX, firmware_path, strlen(firmware_path));
    if (err != EOK) {
        hccn_err("strncpy_s for crl_path failed");
        return TOOL_INVALID_PARAM;
    }
    dot = strrchr(crl_path, '.');
    if (!dot) {
        hccn_err("Firmware path has no extension: %s", firmware_path);
        return TOOL_INVALID_PARAM;
    }
    *dot = '\0';
    err = strncat_s(crl_path, PATH_MAX, CMS_CRL_EXT, strlen(CMS_CRL_EXT));
    if (err != EOK) {
        hccn_err("strncat_s " CMS_CRL_EXT " failed");
        return TOOL_INVALID_PARAM;
    }

    return 0;
}

/**
 * cms_verify_execute() - 执行 CMS 分离签名验证
 * @ctx: CMS 验证上下文（已添加根证书和 CRL）
 * @cms_path: .cms 签名文件路径
 * @firmware_path: 固件文件路径
 *
 * 执行流程：Begin → Update → Final
 *
 * Return: 0 验证通过，负值验证失败
 */
static int cms_verify_execute(CMSCBB_VRF_CTX ctx, const char *cms_path, const char *firmware_path)
{
    CVB_BYTE *cms_data = NULL;
    CVB_UINT32 cms_data_len = 0;
    CVB_INT32 result = 0;
    CMSCBB_ERROR_CODE ret;
    int err;

    err = read_file_to_buffer(cms_path, &cms_data, &cms_data_len);
    if (err != 0) {
        hccn_err("Failed to read CMS signature file: %s", cms_path);
        return err;
    }

    ret = CmscbbVerifyDetachSignatureBegin(ctx, cms_data, cms_data_len);
    if (ret != CVB_SUCCESS) {
        hccn_err("CmscbbVerifyDetachSignatureBegin failed, ret=%d", (int)ret);
        free(cms_data);
        return DRV_ERROR_STATUS_FAIL;
    }
    free(cms_data);

    err = cms_update_firmware_content(ctx, firmware_path);
    if (err != 0) {
        hccn_err("cms_update_firmware_content failed, ret=%d", err);
        return err;
    }

    ret = CmscbbVerifyDetachSignatureFinal(ctx, &result);
    if (ret != CVB_SUCCESS) {
        hccn_err("CmscbbVerifyDetachSignatureFinal failed, ret=%d", (int)ret);
        return DRV_ERROR_STATUS_FAIL;
    }

    if ((CVB_UINT32)result != CVB_TRUE) {
        hccn_err("CMS signature verification FAILED! result=%d", result);
        return DRV_ERROR_STATUS_FAIL;
    }

    hccn_info("CMS signature verification PASSED");
    return 0;
}

/**
 * cms_validate_paths() - 验证 CMS 签名验证所需文件路径
 * @firmware_path: 固件文件路径
 * @cms_path: 输出 CMS 签名文件路径（调用方分配 PATH_MAX）
 * @crl_path: 输出 CRL 吊销列表路径（调用方分配 PATH_MAX）
 *
 * Step 1: 从固件路径推导 .cms/.crl 路径，并校验文件可访问性
 *
 * Return: 0 成功，负值失败
 */
static int cms_validate_paths(const char *firmware_path, char *cms_path, char *crl_path)
{
    int err;

    if (!firmware_path) {
        hccn_err("firmware_path is NULL");
        return TOOL_INVALID_PARAM;
    }

    err = derive_cms_file_paths(firmware_path, cms_path, crl_path);
    if (err != 0) {
        hccn_err("derive_cms_file_paths failed, ret=%d", err);
        return err;
    }

    if (access(firmware_path, R_OK) != 0) {
        hccn_err("Firmware file not accessible: %s, errno=%d", firmware_path, errno);
        return TOOL_INVALID_PARAM;
    }

    if (access(cms_path, R_OK) != 0) {
        hccn_err("CMS signature file not accessible: %s, errno=%d", cms_path, errno);
        return TOOL_INVALID_PARAM;
    }

    hccn_info("CMS verification: firmware=%s, cms=%s, crl=%s",
        firmware_path, cms_path, crl_path);
    return 0;
}

/**
 * cms_construct_ctx() - 构造 CMS 验证上下文
 * @ctx_out: 输出已构造的验证上下文
 * @crl_path: CRL 吊销列表路径
 *
 * Step 2: 创建验证上下文 → 添加根证书 → 添加 CRL（如存在）
 *
 * Return: 0 成功，负值失败
 */
static int cms_construct_ctx(CMSCBB_VRF_CTX *ctx_out, const char *crl_path)
{
    CmscbbCtxCreateParams params = {0};
    CMSCBB_ERROR_CODE ret;
    CMSCBB_VRF_CTX ctx = NULL;

    params.st_size = sizeof(params);
    ret = CmscbbVerifyCreateCtx(&ctx, &params);
    if (ret != CVB_SUCCESS) {
        hccn_err("CmscbbVerifyCreateCtx failed, ret=%d", (int)ret);
        return DRV_ERROR_STATUS_FAIL;
    }

    ret = CmscbbVerifyAddCert(ctx, g_optical_root_cert, sizeof(g_optical_root_cert));
    if (ret != CVB_SUCCESS) {
        hccn_err("CmscbbVerifyAddCert failed, ret=%d", (int)ret);
        CmscbbVrfCtxFree(ctx);
        return DRV_ERROR_STATUS_FAIL;
    }

    if (access(crl_path, F_OK) == 0) {
        ret = CmscbbVerifyAddCrlFile(ctx, crl_path);
        if (ret != CVB_SUCCESS) {
            hccn_err("CmscbbVerifyAddCrlFile failed, crl=%s, ret=%d", crl_path, (int)ret);
            CmscbbVrfCtxFree(ctx);
            return DRV_ERROR_STATUS_FAIL;
        }
    } else {
        hccn_err("CRL file not found, invalid crl path %s", crl_path);
        CmscbbVrfCtxFree(ctx);
        return DRV_ERROR_STATUS_FAIL;
    }

    *ctx_out = ctx;
    return 0;
}

/**
 * verify_optical_firmware_cms() - 验证光模块固件 CMS 数字签名
 * @firmware_path: 固件文件路径
 *
 * 验证流程（三步结构）：
 * 1. cms_validate_paths  — 校验路径与文件可访问性
 * 2. cms_construct_ctx   — 构造验证上下文（根证书 + CRL）
 * 3. cms_verify_execute  — 执行分离签名验证（Begin → Update → Final）
 *
 * Return: 0 验证通过，负值验证失败
 */
static int verify_optical_firmware_cms(const char *firmware_path)
{
    CMSCBB_VRF_CTX ctx = NULL;
    int err;
    char cms_path[PATH_MAX] = {0};
    char crl_path[PATH_MAX] = {0};

    /* Step 1: validate paths */
    err = cms_validate_paths(firmware_path, cms_path, crl_path);
    if (err != 0) {
        return err;
    }

    /* Step 2: construct verification context */
    err = cms_construct_ctx(&ctx, crl_path);
    if (err != 0) {
        return err;
    }

    /* Step 3: execute verification (Begin → Update → Final) */
    err = cms_verify_execute(ctx, cms_path, firmware_path);

    CmscbbVrfCtxFree(ctx);
    return err;
}

EXPORT_FUNCTION int dsmi_optical_upgrade_firmware(struct command_context *ctx,
    char *firmware_path, int path_size, struct optical_upgrade_result *result)
{
    int ret;
    struct product_channel_msg upgrade_msg = {0};
    struct optical_upgrade_req upgrade_req = {0};
    char device_firmware_path[PATH_MAX] = {0};
    unsigned int saved_hbm_addr_high, saved_hbm_addr_low, saved_hbm_size;

    if (!firmware_path || !result) {
        return TOOL_INVALID_PARAM;
    }

    (void)memset_s(result, sizeof(*result), 0, sizeof(*result));

    // CMS 数字签名校验：在传输固件到设备之前验证签名
    ret = verify_optical_firmware_cms(firmware_path);
    if (ret) {
        hccn_err("CMS signature verification failed, firmware=%s, ret=%d", firmware_path, ret);
        TOOL_PRINT_INFO("Firmware CMS signature verification failed! The firmware package may be tampered.");
        return ret;
    }
    TOOL_PRINT_INFO("Firmware CMS signature verification passed.");

    ret = optical_transmit_firmware_to_device(ctx, firmware_path,
        device_firmware_path, sizeof(device_firmware_path));
    if (ret) {
        return ret;
    }

    ret = strncpy_s(upgrade_req.firmware_path, PATH_MAX,
        device_firmware_path, strlen(device_firmware_path));
    if (ret != EOK) {
        hccn_err("strncpy_s failed. (ret=%d)", ret);
        return TOOL_INVALID_PARAM;
    }

    SET_PRODUCT_MSG(upgrade_msg, &upgrade_req, sizeof(upgrade_req),
        result, sizeof(*result));
    ret = product_host_device_channel(ctx, CMD_OPTICAL_UPGRADE_FIRMWARE, &upgrade_msg);
    if (ret) {
        hccn_err("Trigger upgrade failed. (ret=%d)", ret);
        return ret;
    }

    saved_hbm_addr_high = result->hbm_addr_high;
    saved_hbm_addr_low = result->hbm_addr_low;
    saved_hbm_size = result->hbm_size;

    ret = poll_upgrade_status(ctx, result);
    // 在poll_upgrade_status之后，将保存的HBM地址写回result
    result->hbm_addr_high = saved_hbm_addr_high;
    result->hbm_addr_low = saved_hbm_addr_low;
    result->hbm_size = saved_hbm_size;
    if (ret) {
        return ret;
    }

    return handle_upgrade_result(ctx, result);
}