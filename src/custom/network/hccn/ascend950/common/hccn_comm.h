/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef HCCN_COMM_H
#define HCCN_COMM_H

#include <stdbool.h>
#include <errno.h>
#include "hccn_log.h"

#define MAX_IP_VAL_LEN 48
#define MAX_IPV4_LEN 20
#define MAX_IPV6_NUM 16

#define MAX_TRACEROUTE_WAITING_TIMES 600

struct ip_val {
    unsigned int ip_addr;
    unsigned char ip6_addr[MAX_IPV6_NUM];
    char str_ip[MAX_IP_VAL_LEN];
};

enum traceroute_status {
    TRACEROUTE_STATUS_HALT    = 0,
    TRACEROUTE_STATUS_RUNNING = 1,
    TRACEROUTE_STATUS_ERROR   = 2
};

struct traceroute_info {
    int max_ttl;
    int tos;
    int waittime;
    int sport;
    int dport;
    struct ip_val src_ip;
    struct ip_val dst_ip;
    bool reset_flag;
};

enum {
    ARGC_ID_0 = 0,
    ARGC_ID_1,
    ARGC_ID_2,
    ARGC_ID_3,
    ARGC_ID_4,
    ARGC_ID_5,
    ARGC_ID_6,
    ARGC_ID_7,
    ARGC_ID_MAX
};

#define ARG_NUM_TWO 2
#define ARG_NUM_THREE 3

#define CLOSE_RETRY_FOR_EINTR(fd) do {                                    \
    int ret_;                                                             \
    do {                                                                  \
        ret_ = close((fd));                                               \
        if (ret_ < 0) {                                                   \
            hccn_warn("close fd:%d unsuccessful, errno:%d", (fd), errno); \
        }                                                                 \
    } while ((ret_ < 0) && (errno == EINTR));                             \
    (fd) = -1;                                                            \
} while (0)

#define FREE_BUF(buf) do { \
    if ((buf) != NULL) {   \
        free((buf));       \
        (buf) = NULL;      \
    }                      \
} while (0)
#endif // HCCN_COMM_H
