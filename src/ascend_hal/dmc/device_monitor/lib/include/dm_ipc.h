/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef DM_IPC_H
#define DM_IPC_H

#include <netinet/in.h>
#include "dm_msg_intf.h"

#ifdef CFG_FEATURE_UPGRADE_MULTI_FRAME_IPC
#define MAX_IPC_MAX_TRANSLEN 220
#else
#define MAX_IPC_MAX_TRANSLEN 32
#endif

typedef struct DM_IPC_ADDR_S {
    int addr_type;
    short channel;
    int dev_id;
} DM_IPC_ADDR_ST;

int dm_ipc_init(DM_INTF_S **my_intf, DM_CB_S *cb, DM_MSG_TIMEOUT_HNDL_T timeout_hndl, const DM_ADDR_ST *my_addr,
                const char *my_name, int name_len);
#endif
