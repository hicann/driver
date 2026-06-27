/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef DSMI_OPTICAL_H
#define DSMI_OPTICAL_H

#include "ds_data.h"
#include "comm_channel.h"

// 函数声明
// struct optical_upgrade_result 定义在 comm_channel.h 中
int dsmi_optical_upgrade_firmware(struct command_context *ctx,
    char *firmware_path, int path_size, struct optical_upgrade_result *result);

#endif /* DSMI_OPTICAL_H */