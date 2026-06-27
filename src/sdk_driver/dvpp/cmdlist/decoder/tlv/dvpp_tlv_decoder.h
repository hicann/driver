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

#ifndef TLV_DVPP_TLV_BUF_H
#define TLV_DVPP_TLV_BUF_H

#include "ka_type.h"
#include "dvpp_cmdlist_define.h"
#include "dvpp_tlv_types.h"
#include "dvpp_decoder.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif // #ifdef __cplusplus

// 第一版 1.0.0
#define TLV_MAJOR_VERSION 1
#define TLV_MINOR_VERSION 0
#define TLV_REVISSION_VERSION 0

#define DVPP_TLV_STRUCT_PTR_DEFAULT_VAL ((void*)(-1))
#define DVPP_MAX_TLV_TYPE 50

typedef uint16_t tlv_data_type;
typedef uint16_t tlv_data_len;
typedef void*    tlv_data_val;

typedef struct DvppTlvVersionParam {
    uint16_t major_num;
    uint16_t minor_num;
    uint16_t revision_num;
} dvpp_tlv_version_param;

typedef struct DvppTlvHeadParam {
    uint16_t mod;
    uint16_t batch_cnt;
    uint16_t node_cnt;
    uint16_t node_cnt_of_batch[DVPP_MAX_BATCH_NUM];
} dvpp_tlv_head_param;

typedef struct {
    tlv_data_type type;
    tlv_data_len  len;
    tlv_data_val  val;
} dvpp_tlv_data;

typedef struct {
    void *val[DVPP_MAX_NODE_NUM][DVPP_MAX_TLV_TYPE];
} dvpp_tlv_type_struct;

typedef struct {
    uint16_t mod;
    uint8_t *pbuf;
    uint8_t *ppos;
    uint32_t size;
    dvpp_tlv_head_param *head;
    dvpp_tlv_version_param *version;
    dvpp_tlv_type_struct *tlv_type_struct;
    uint32_t tlv_type_struct_size;
    uint32_t tlv_node_num;
} dvpp_tlv_decoder;

void dvpp_tlv_decoder_register(void);
void dvpp_tlv_decoder_unregister(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif // #ifdef __cplusplus

#endif // #ifndef TLV_DVPP_TLV_BUF_H
