/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef SRC_DRIVER_NETWORK_HCCN_HCCN_TOOL_SRC_TOOL_IP_H
#define SRC_DRIVER_NETWORK_HCCN_HCCN_TOOL_SRC_TOOL_IP_H

#include <unistd.h>
#include <string.h>
#include "ossl_user_linux.h"
#include "ds_net.h"

#define CLEAR_ROUTE_TYPE_IPV4 1
#define CLEAR_ROUTE_TYPE_IPV6 2

int tool_check_ip_route_net_segment(struct tool_param *param, const char *address, const char *netmask);
int tool_trans_config_to_ip_route(FILE *fp, struct tool_param *param, struct ds_route_table_value ip_param);
int tool_route_clear_zero_conf(struct tool_param *param, enum read_route_operation route_op, int route_type);

#endif