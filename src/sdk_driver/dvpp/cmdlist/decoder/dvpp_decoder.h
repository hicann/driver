
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

#ifndef DVPP_CMDLIST_DVPP_PROTOCOL
#define DVPP_CMDLIST_DVPP_PROTOCOL

#ifdef __KERNEL__
#include "ka_type.h"
#else
#include <stdint.h>
#include <stddef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif
typedef enum {
    DVPP_PROTOCOL_TLV,
    DVPP_PROTOCOL_VPU,
    DVPP_PROTOCOL_BUTT,
} dvpp_protocol_type;

typedef struct {
    void *decoder;
    dvpp_protocol_type protocol;
} dvpp_decoder;

typedef int32_t (*pfn_dvpp_init_decoder)(void *decoder);
typedef int32_t (*pfn_dvpp_decode_args)(void *decoder);
typedef uint16_t (*pfn_dvpp_get_node_cnt)(void *decoder);
typedef uint16_t (*pfn_dvpp_get_batch_cnt)(void *decoder);
typedef uint16_t (*pfn_dvpp_get_node_cnt_of_batch)(void *decoder, uint32_t index);
typedef uint32_t (*pfn_dvpp_get_module_type)(void *decoder);
typedef void* (*pfn_dvpp_get_vpu_mod_val)(void *decoder, uint32_t node_idx, uint32_t type);
typedef uint16_t (*pfn_dvpp_get_vpu_mod_len)(void *decoder, uint32_t node_idx, uint32_t type);

typedef struct dvpp_decoder_ops {
    pfn_dvpp_init_decoder dvpp_init_decoder;
    pfn_dvpp_decode_args   dvpp_decode_args;
    pfn_dvpp_get_node_cnt dvpp_get_node_cnt;
    pfn_dvpp_get_batch_cnt dvpp_get_batch_cnt;
    pfn_dvpp_get_node_cnt_of_batch dvpp_get_node_cnt_of_batch;
    pfn_dvpp_get_module_type dvpp_get_module_type;
    pfn_dvpp_get_vpu_mod_val dvpp_get_vpu_mod_val;
    pfn_dvpp_get_vpu_mod_len dvpp_get_vpu_mod_len;
} dvpp_decoder_ops;

dvpp_decoder_ops *dvpp_get_decoder_ops(void);

int32_t dvpp_init_decoder(dvpp_decoder *decoder);
int32_t dvpp_decode_args(dvpp_decoder *decoder);
uint16_t dvpp_get_node_cnt(dvpp_decoder *decoder);
uint16_t dvpp_get_batch_cnt(dvpp_decoder *decoder);
uint16_t dvpp_get_node_cnt_of_batch(dvpp_decoder *decoder, uint32_t index);
uint32_t dvpp_get_module_type(dvpp_decoder *decoder);
void* dvpp_get_vpu_mod_val(dvpp_decoder *decoder, uint32_t node_idx, uint32_t type);
uint16_t dvpp_get_vpu_mod_len(dvpp_decoder *decoder, uint32_t node_idx, uint32_t type);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_CMDLIST_DVPP_PROTOCOL