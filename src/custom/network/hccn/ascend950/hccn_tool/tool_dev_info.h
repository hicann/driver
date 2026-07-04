/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TOOL_DEVICE_INFO_H
#define TOOL_DEVICE_INFO_H

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "tool_param.h"
#include "dev_info_data.h"

#define IP_ADDRESS_RADIX 10

static inline int get_bond_id_from_name(const char *dev_name)
{
    const char *num_part_start;
    char *endptr;
    long id;

    if (strlen(dev_name) < BOND_IFACE_PREFIX_LEN) {
        return -1;
    }

    num_part_start = dev_name + BOND_IFACE_PREFIX_LEN;
    if (*num_part_start == '\0') {
        return -1;
    }

    if (*num_part_start == '0' && *(num_part_start + 1) != '\0') {
        return -1;
    }

    id = strtol(num_part_start, &endptr, IP_ADDRESS_RADIX);
    if (*endptr != '\0' || id < 0 || id > INT_MAX) {
        return -1;
    }

    return (int)id;
}

#define CHECK_BOND_DEV_RETURN(dev_name_var, slot_id_var) \
do { \
    if ((dev_name_var) == NULL || (dev_name_var)[0] == '\0') { \
        TOOL_PRINT_ERR("Device name is empty, expected 'bond%d'.", (slot_id_var)); \
        return TOOL_PUBLIC_ARGS_DEV_NAME_ERR; \
    } \
    if (strncmp((dev_name_var), BOND_IFACE_PREFIX, BOND_IFACE_PREFIX_LEN) != 0) { \
        TOOL_PRINT_ERR("Command is only applicable to bond devices, expected 'bond%d'.", (slot_id_var)); \
        return TOOL_PUBLIC_ARGS_DEV_NAME_ERR; \
    } \
    int bond_id = get_bond_id_from_name(dev_name_var); \
    if (bond_id < 0) { \
        TOOL_PRINT_ERR("Invalid bond device name format, expected 'bond%d'.", (slot_id_var)); \
        return TOOL_PUBLIC_ARGS_DEV_NAME_ERR; \
    } \
    if (bond_id != (slot_id_var)) { \
        TOOL_PRINT_ERR("Bond device ID mismatch: name='bond%d', expected 'bond%d'.", bond_id, (slot_id_var)); \
        return TOOL_PUBLIC_ARGS_DEV_NAME_ERR; \
    } \
} while(0)

void tool_info_print_help(struct command_context *ctx, unsigned int mode);
int tool_info_exec(struct command_context *ctx);
int tool_get_bond_slaves(struct command_context *ctx, struct netdev_info *ndev_info);
#endif // TOOL_DEVICE_INFO_H
