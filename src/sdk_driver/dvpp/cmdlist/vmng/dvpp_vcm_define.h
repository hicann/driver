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
#ifndef DVPP_VMNG_VCM_DEFINE_H
#define DVPP_VMNG_VCM_DEFINE_H
#include "ka_type.h"

enum dvpp_vcm_cmd {
    DVPP_VCM_GEN_CMDLIST = 0,
    DVPP_VCM_MAXCMD
};

#define DVPP_VCM_MSG_DATA_MAXLEN 64

struct dvpp_vcm_msg {
    enum dvpp_vcm_cmd cmd;
    int32_t complete_code;
    uint32_t msg_data_len;
    uint8_t msg_data[DVPP_VCM_MSG_DATA_MAXLEN];
};

#endif