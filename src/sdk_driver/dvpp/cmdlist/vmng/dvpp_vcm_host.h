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
#ifndef DVPP_VMNG_VCM_HOST_H
#define DVPP_VMNG_VCM_HOST_H
#include "dvpp_vcm_define.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t (*DVPP_VCM_RECV_F)(uint32_t dev_id, uint32_t fid, void *msg_data, uint32_t msg_data_len);

int32_t dvpp_vcm_vpc_register_client(uint32_t dev_id, uint32_t fid);
int32_t dvpp_vcm_vpc_unregister_client(uint32_t dev_id, uint32_t fid);
int32_t dvpp_vcm_register_msg_recv_cb(enum dvpp_vcm_cmd cmd, DVPP_VCM_RECV_F func);

#ifdef __cplusplus
}
#endif
#endif