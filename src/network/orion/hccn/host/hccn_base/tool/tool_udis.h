/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_UDIS_H
#define TOOL_UDIS_H

#include "tool_param.h"
#include "dsmi_common_interface.h"

#define LINK_STATUS_UP 1
#define LINK_STATUS_DOWN 0

int tool_udis_get_net_health_exec(struct command_context *ctx, DSMI_NET_HEALTH_STATUS *presult);

#endif // TOOL_UDIS_H
