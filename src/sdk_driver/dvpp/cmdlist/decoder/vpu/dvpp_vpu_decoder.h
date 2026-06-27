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

#ifndef DVPP_CMDLIST_DVPP_VPU_BUF
#define DVPP_CMDLIST_DVPP_VPU_BUF

#include "ka_type.h"

#include "dvpp_cmdlist_define.h"
#include "dvpp_decoder.h"
#include "dvpp_vpu_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void **vpu_config;
    uint16_t node_cnt;
    uint16_t *node_cnt_of_batch;
    uint16_t batch_cnt;
    dvpp_mod_type mod;
} dvpp_vpu_decoder;

void dvpp_vpu_decoder_register(void);
void dvpp_vpu_decoder_unregister(void);

extern uint32_t g_vpu_mod_vpc_stru_len[VPU_VPC_TYPE_BUTT];
extern uint32_t g_vpu_mod_jpegd_stru_len[VPU_JPEGD_TYPE_BUTT];
extern uint32_t g_vpu_mod_jpege_stru_len[VPU_JPEGE_TYPE_BUTT];

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_CMDLIST_DVPP_VPU_BUF