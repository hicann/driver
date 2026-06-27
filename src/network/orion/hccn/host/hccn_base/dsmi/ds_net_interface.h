/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef DS_NET_INTERFACE_H
#define DS_NET_INTERFACE_H

#include <unistd.h>
#include <sys/types.h>
#include "ds_data.h"

#define EXPORT_FUNCTION __attribute__ ((visibility ("default")))

struct dsmi_info {
    char *inbuf;
    unsigned int size_in;
    char *extra_inbuf;
    unsigned int size_extra_in;
    char *outbuf;
    unsigned int *size_out;
};

struct ds_trans_data {
    enum ds_cmd_opcode cmd;
    const char *inbuf;
    unsigned int size_in;
    char *outbuf;
    unsigned int *size_out;
    int result;
    /* when size_out>2000 set pid = getpid() */
    pid_t pid;
};

#define DSMI_FILL_INFO(_dsmi_info, _inbuf, _size_in, _extra_inbuf, _size_extra_in, _outbuf, _size_out) do { \
    (_dsmi_info).inbuf = (_inbuf); \
    (_dsmi_info).size_in = (_size_in); \
    (_dsmi_info).extra_inbuf = (_extra_inbuf); \
    (_dsmi_info).size_extra_in = (_size_extra_in); \
    (_dsmi_info).outbuf = (_outbuf); \
    (_dsmi_info).size_out = (_size_out); \
} while (0)

#define DSMI_SET_TRANS_DATA(_trans_data, _cmd, _inbuf, _size_in, _outbuf, _size_out) do { \
    (_trans_data).cmd = (_cmd); \
    (_trans_data).inbuf = (_inbuf); \
    (_trans_data).size_in = (_size_in); \
    (_trans_data).outbuf = (_outbuf); \
    (_trans_data).size_out = (_size_out); \
    (_trans_data).result = (-1); \
    (_trans_data).pid = (*((_trans_data).size_out) > MAX_CMD_PAYLOAD_LEN) ? getpid() : 0; \
} while (0)

EXPORT_FUNCTION int dsmi_exe_get_info(int logic_id, enum ds_cmd_opcode cmd, struct dsmi_info *info);
#ifdef ENABLE_BUILD_PRODUCT
EXPORT_FUNCTION int dsmi_network_transmission_channel(int logic_id, struct ds_trans_data *trans_data);
#endif

#endif // DS_NET_INTERFACE_H