/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef HCCN_ERR_H
#define HCCN_ERR_H

#include <stdbool.h>
#include <stdio.h>
#include "ds_data.h"

enum {
    TOOL_EXE_SUCCESS = 0x0,

    TOOL_USER_INPUT_PARAM_ERR = 0x1000,
    TOOL_PUBLIC_MODE_EMPTY_ERR,
    TOOL_PUBLIC_MODE_TYPE_ERR,
    TOOL_PUBLIC_CMD_EMPTY_ERR,
    TOOL_PUBLIC_CMD_TYPE_ERR,
    TOOL_PUBLIC_CMD_MODE_ERR,
    TOOL_PUBLIC_ARGS_PARSE_ERR,
    TOOL_PUBLIC_ARGS_ID_ERR,
    TOOL_PUBLIC_ARGS_RANGE_ERR,
    TOOL_PUBLIC_ARGS_REPEAT_ERR,
    TOOL_PUBLIC_ARGS_MISMATCH_CMD_ERR,
    TOOL_PUBLIC_ARGS_CHIP_ERR,
    TOOL_PUBLIC_ARGS_UDIE_ERR,
    TOOL_PUBLIC_ARGS_PORT_ERR,
    TOOL_PUBLIC_ARGS_DEV_NAME_ERR,
    TOOL_PRIVATE_ARGS_NUM_ERR,
    TOOL_PRIVATE_ARGS_PARSE_ERR,
    TOOL_PRIVATE_ARGS_REPEAT_ERR,
    TOOL_PRIVATE_ARGS_CONFLICT_ERR,
    TOOL_PRIVATE_ARGS_MISMATCH_MODE_ERR,
    TOOL_PRIVATE_ARGS_VALUE_ERR,
    TOOL_EXE_USER_ABORT_CMD_ERR,
    TOOL_EXE_HELP = 0x1FFF,

    DSMI_EXE_ERR = 0x2000,

    /*
     * Error code range reserved for FILE_OPT_ERR: 0x3000 - 0x30FF.
     * This range is reserved and MUST NOT be used by other modules.
     * For details, please refer to common/file_opt.h.
     */
    FILE_OPT_ERR_BASE = 0x3000,
    FILE_OPT_ERR_MAX = 0x30FF,

    DEV_EXE_ERR = 0x3100,
    DEV_SYS_BUSY_ERR,
    TOOL_PUBLIC_ROOT_UNSUPPORT,
    TOOL_PUBLIC_ENV_UNSUPPORT,
    DEV_EXE_CONFLICT_IP_ADDR_ERR,
    DEV_EXE_GATEWAY_NOT_PRESET_ERR,
    DEV_EXE_IP_ADDRESS_NOT_PRESET_ERR,
    DEV_EXE_DIFF_SEGMT_GTWY_ERR,
    TOOL_DHCPC_PROCESS_EXIST_ERR,
    TOOL_DHCPC_CONFIG_ERR,
    TOOL_TROUTE_PROCESS_EXIST_ERR,
    DEV_EXE_TRACEROUTE_ERR,
    DEV_EXE_TRACEROUTE_TIMEOUT,
    DEV_QOS_MAP_CONFLICT_ERR,
    DEV_QOS_UNMAP_REPEAT_ERR,
    TOOL_EXE_DEV_INFO_ERR,
    DEV_EXE_ETH_TEST_ERR,
    TOOL_GATEWAY_OR_ARP_RECOVERY_ERR,
    TOOL_WRITE_CONF_ERR,

    TOOL_TLS_ERR = 0x4000,
    TLS_INPUT_NO_PATH_ERR,      // INPUT ERR
    TLS_INPUT_CERT_COUNT_ERR,
    TLS_PWD_COMPLEXITY_ERR,     // PWD ERR
    TLS_PWD_LEN_INVALID_ERR,
    TLS_NO_WEAK_PWD_DICT,
    TLS_WEAK_PWD_DICT_NULL,
    TLS_WEAK_PWD_DICT_TOO_MANY,
    TLS_WEAK_PWD_DICT_CHECK_FAIL,
    TLS_PWD_TOO_WEAK_ERR,
    TLS_NO_CERT_ERR,            // CERT ERR
    TLS_CERT_EXPIRED_ERR,
    TLS_CERT_ILLEGAL_ERR,
    TLS_CERT_LEN_INVALID_ERR,
    TLS_CERT_VERIFY_FAIL,
    TLS_CERT_DISCONTINOUS_ERR,
    TLS_CA_WITHOUT_PRI_ERR,

    HCCN_ERR_MASK = 0xFF00,
};

static inline bool disable_err_log(int ret)
{
    static const int log_disable_errors[] = {
        DEV_EXE_GATEWAY_NOT_PRESET_ERR,
        DEV_EXE_IP_ADDRESS_NOT_PRESET_ERR
    };
    size_t count = ARRAY_SIZE_COMPUTE(log_disable_errors);
    size_t i;

    for (i = 0; i < count; i++) {
        if (ret == log_disable_errors[i]) {
            return true;
        }
    }
    return false;
}

#endif // HCCN_ERR_H
