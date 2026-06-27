/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef CMDBUF_HLIST_CTX_H
#define CMDBUF_HLIST_CTX_H

#include "ka_type.h"
#include "ka_task_pub.h"
#include "dvpp_cmdlist_ioctl.h"

typedef struct {
    ka_pid_t pid;
    uint32_t chn;
    uint32_t size;
    uint64_t uva;
    uint64_t kva;
} cmdbuf_context;

uint64_t search_cmdbuf_hlist(ka_pid_t pid, uint32_t chn, uint64_t uva, dvpp_cmdlist_private_data *data);
int32_t add_cmdbuf_hlist(cmdbuf_context *ctx, dvpp_cmdlist_private_data *data);
void del_cmdbuf_hlist(ka_pid_t pid, dvpp_cmdlist_private_data *data);
void del_chn_cmdbuf_hlist(ka_pid_t pid, uint32_t chn, dvpp_cmdlist_private_data *data);

#endif // #ifndef CMDBUF_HLIST_CTX_H