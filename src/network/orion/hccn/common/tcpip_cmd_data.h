/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef TCPIP_CMD_DATA_H
#define TCPIP_CMD_DATA_H
#include <netinet/in.h>
#include <stdbool.h>
#include "hccn_comm.h"

#define MSG_TOO_LONG "Message too long"
#define MSG_RECV_TIMEOUT "recv time out seq"
#define MSG_DEST_UNREACHABLE "Destination Host Unreachable"

#define NET_HEALTH_STATUS_LEN   20
#define IP_BROADCAST    0xFFFFFFFF

struct ping_cmd_args {
    int pkt;
    bool is_ipv6_cmd;
    struct ip_val src_addr;
    struct ip_val dst_addr;
};

union addr_t {
    struct in_addr addr;
    struct in6_addr addr6;
};

union sockaddr_t {
    struct sockaddr sa;
    struct sockaddr_in sa_in;
    struct sockaddr_in6 sa_in6;
};

enum rdfx_deal_detect_ip {
    RDFX_GET_DETECT_IP = 0,
    RDFX_SET_DETECT_IP = 1,
};

struct netdetect_cmd_args {
    struct ip_val address;
};

#endif // TCPIP_CMD_DATA_H
