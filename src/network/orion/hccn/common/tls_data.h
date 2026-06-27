/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TLS_DATA_H
#define TLS_DATA_H

#include "tls.h"
#include "tool_param.h"

#define TLS_ALARM_MIN_DAYS 7
#define TLS_ALARM_MAX_DAYS 180

#define MAX_CA_FIELD_LEN 5

#define TLS_SET_ENABLE  (1 << 0)
#define TLS_SET_ALARM   (1 << 1)
#define TLS_SET_CLEAR   (1 << 2)
#define TLS_SET_CFG     (1 << 3)
#define TLS_SET_ALL     (~0)

enum tls_clear_mode {
    TLS_CLEAR_ALL = 0,
    TLS_CLEAR_CRL
};

struct tls_clear_info {
    enum tls_clear_mode clear_mode;
    unsigned int save_mode;
};

struct tls_cmd_args {
    unsigned int set_mode_mask;
    unsigned int option_count;
    struct sub_option_entry options[0];  // 零长度数组指示所有选项的起始地址
    struct sub_option_entry alarm;
    struct sub_option_entry clear;
    struct sub_option_entry enable;
    struct sub_option_entry path;
    struct sub_option_entry pri;
    struct sub_option_entry certs[0];    // 零长度数组指示所有证书选项的起始地址，包括 pub and CAs
    struct sub_option_entry pub;
    struct sub_option_entry ca[MAX_CA_CERT_INDEX];  // ca1, ..., caN
    struct sub_option_entry crl;
    struct sub_option_entry host;
    struct sub_option_entry options_end[0];  // 零长度数组指示选项结束地址
};

#endif // TLS_DATA_H
