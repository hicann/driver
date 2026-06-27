/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_UDP_H
#define TOOL_UDP_H

#include "tool_param.h"
#include "comm_dfx_channel.h"

// UDP配置项名称，tool_write_conf/tool_read_conf 会自动追加 _{phy_id}
#define UDP_SPORT_CFG_NAME "udp"
#define UDP_SPORT_CFG_MAX_LEN 512

// UDP配置条目解析结果结构体
#define UDP_CFG_MODE_STR_LEN    32
#define UDP_CFG_MODE_DATA_LEN   128
// 配置条目缓冲区最大长度：dev_name(64) + mode_str(32) + sport(最大5位) + 2个冒号 + 1个'\0'
#define UDP_CFG_ENTRY_BUF_LEN   (UDP_SPORT_DEV_NAME_LEN + UDP_CFG_MODE_STR_LEN + 5 + 2 + 1)
typedef struct {
    char dev_name[UDP_SPORT_DEV_NAME_LEN];
    char mode_str[UDP_CFG_MODE_STR_LEN];
    char mode_data[UDP_CFG_MODE_DATA_LEN];
} udp_cfg_entry_t;

/* 获取UDP源端口配置命令的子选项 */
void get_udp_sport_sub_opts(struct sub_option_entry **sub_opts, unsigned int *count);

/* 分配UDP源端口配置参数内存 */
void *alloc_udp_sport_args(void);

/* UDP源端口配置参数赋值 */
int udp_sport_assign(void *args, struct sub_option_entry *opt, value_union *type_val);

/* UDP源端口配置命令执行入口 */
int tool_udp_sport_exec(struct command_context *ctx);

/* UDP源端口配置帮助信息 */
void tool_udp_sport_help(struct command_context *ctx, unsigned int mode);

/* UDP源端口配置Recovery函数 */
int tool_cfg_udp_sport_recovery(struct command_context *ctx);

#endif /* TOOL_UDP_H */
