/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_PRODUCT_H
#define TOOL_PRODUCT_H

#include "comm_channel.h"
#include "comm_channel_ext.h"
#include "tool_cfg_ops.h"

int product_host_device_channel(struct command_context *ctx, unsigned int cmd, struct product_channel_msg *msg);

#define FEC_MODE_BYPASS        0   // bypass
#define FEC_MODE_128_T2        1   // 128 T2算法
#define FEC_MODE_128_T4        2   // 128 T4算法
 
#define FEC_MODE_STATIC        0   // 静态模式
#define FEC_MODE_TRENDS        1   // 动态模式
 
#define FEC_MODE_INTERWEAVE    0   // 交织模式
#define FEC_MODE_UNINTERWEAVE  1   // 非交织模式
 
#define FEC_MODE_NO_FEC    0   // no-fec
#define FEC_MODE_RSFEC_2   2   // RSFEC (528,514)
#define FEC_MODE_RSFEC_3   3   // RSFEC (544,514), one code word per frame
#define FEC_MODE_RSFEC_5   5   // RSFEC (544,514), two interleave code words per frame

#define MAX_CFG_LIST 128

#define TMP_CFG_STR_SIZE    0x20

#define PFC_TIME_UNITS      100 // pfc 周期时间单位 100ms
#define ONE_HUNDRED_PERCENT 100 // 百分比 100%
#define PFC_TIME_ERR        0x6031 // pfc 周期时间配置错误，待精细化回显需求删除，仅pfc内部函数使用
#define PFC_THRD_ERR        0x6032 // pfc 阈值配置错误，待精细化回显需求删除，仅pfc内部函数使用

#define MATCH_LIST_CNT      1

void tool_get_product_cmds(struct cmd_entry **cmds, unsigned int *count);
int tool_get_product_other_info(struct command_context *ctx);
recovery_cmd_t *tool_get_full_independent_cmd_list(recovery_cmd_t *list, unsigned int *size);
recovery_cmd_t *tool_get_full_dependent_cmd_list(recovery_cmd_t *list, unsigned int *size);
int tool_set_send_arp(struct command_context *ctx);
int tool_write_conf_comm_uint(struct command_context *ctx, char *cfg_name, unsigned int cfg_size,
                              unsigned int cfg_value);
int tool_set_pfc_storm(struct command_context *ctx, struct pfc_storm_info_t *info);
int tool_set_ip_rule(struct command_context *ctx);
int tool_set_ip_route(struct command_context *ctx);
#endif