/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_LIB_H
#define TOOL_LIB_H

#include "ds_data.h"
#include "comm_channel.h"
#include "comm_product.h"

#define TOOL_USED_BY_OPTICAL_SUM     2
#define MAX_CHIP_NUM   4 // 上下层抽屉相同槽位的模组物理id相差4
#define INVALID_CHIP_ID (-1)
#define MAX_XSFP_LANE 8
#define TABLE_INFO_INVALID "-"

/** 获取当前board_type */
unsigned int tool_get_board_type(struct command_context *ctx);
/** 获取当前port_type */
unsigned int tool_get_port_type(struct command_context *ctx);
bool tool_is_pcie_board(struct command_context *ctx);
/** 获取标卡的有效port_list，以int数组返回结果，-1是数组结束符 */
int *tool_get_pcie_card_port_list(struct command_context *ctx);
int product_host_device_channel(struct command_context *ctx, unsigned int cmd, struct product_channel_msg *msg);
char* trim(char *str);
bool tool_is_ascend950_A_K_0_8(struct command_context *ctx);
bool tool_is_ascend950_A_K_2_4(struct command_context *ctx);
/** 验证固件文件路径有效性 */
int validate_firmware_path(const char *path);
bool tool_is_uboe_mainboard(unsigned int mainboard_id);

#endif