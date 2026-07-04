/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef HCCN_UDIS_COMM_H
#define HCCN_UDIS_COMM_H

#include "udis_user.h"

enum query_mode {
    QUERY_PORT_TYPE = 0,
    QUERY_NPU_TYPE,
    QUERY_MAX_TYPE,
};

#define HCCN_MAX_NAME_LEN (UDIS_MAX_NAME_LEN - 1) // for '\0'
#define HCCN_NAME_PORT_TYPE_LEN 5                 // for "_(die_id)_(portid)"

// name should ≤ (UDIS_MAX_NAME_LEN - HCCN_NAME_x_LEN)
#define HCCN_UDIS_NAME_LINK       "link"
#define HCCN_UDIS_NAME_NET_HEALTH "net_health"

#endif // HCCN_UDIS_COMM_H
