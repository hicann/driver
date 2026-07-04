/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef COMM_DFX_CHANNEL_H
#define COMM_DFX_CHANNEL_H

/* UBoE设备名称前缀长度 */

#define UBOE_DEV_NAME_PREFIX_LEN    3

/* UDP源端口配置相关宏 */

#define UDP_SPORT_TP_ATTR_CNT_SET   5
#define UDP_SPORT_TP_ATTR_CNT_RESET 1
#define UDP_SPORT_TP_ATTR_MASK_SET  (0x1F << 12)
#define UDP_SPORT_TP_ATTR_MASK_RESET (1 << 16)

typedef enum {
    DEV_NOT_FOUND = 1,
    NOT_UBOE_DEV,
} udp_sport_err_code_e;

// UDP源端口模式枚举
typedef enum {
    UDP_SPORT_MODE_INVALID = 0,        // 未指定（用于判断是否指定了操作）
    UDP_SPORT_MODE_DEFAULT,           // default模式（未配置）
    UDP_SPORT_MODE_GLOBAL,          // global模式
} udp_sport_mode_e;

// UDP源端口配置数据结构
#define UDP_SPORT_DEV_NAME_LEN 64
struct udp_sport_data {
    int ret;                        // 返回值（内核态设置，用户态读取）
    char dev_name[UDP_SPORT_DEV_NAME_LEN];  // urma设备名称
    unsigned int mode;              // 模式: global/reset（查询时作为输出）
    unsigned int sport;             // 源端口号: 4097~65535（查询时作为输出）
};

#endif // COMM_DFX_CHANNEL_H
