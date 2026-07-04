/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_SHELL_OPS_H
#define TOOL_SHELL_OPS_H

#include "tool_param.h"
#include "dev_info_data.h"

#define ARP_MATCH_CNT 2

#define INVALID_GW 0xFFFFFFFF

void tool_get_shell_cmds(struct cmd_entry **cmds, unsigned int *count);
int tool_set_pfc_exec(struct command_context *ctx, struct netdev_info *ndev_info);
int tool_set_prio_tc_exec(struct command_context *ctx, struct netdev_info *ndev_info);
bool is_ipaddr_conflict(struct command_context *ctx);
int tool_set_gateway_exec(struct command_context *ctx);
int tool_arp_set(struct command_context *ctx);
int tool_exec_with_link_status(struct command_context *ctx, int (*exec_func)(struct command_context *ctx),
    bool double_check_flag);
int tool_set_mtu_exec(struct command_context *ctx);
int tool_bond_attr_set(struct command_context *ctx);
int tool_get_udhcpc_exec(struct command_context *ctx);

#endif // TOOL_SHELL_OPS_H
