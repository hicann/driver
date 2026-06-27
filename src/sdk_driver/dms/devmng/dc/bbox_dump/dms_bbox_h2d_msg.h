/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
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
#ifndef __DMS_BBOX_H2D_MSG_H
#define __DMS_BBOX_H2D_MSG_H
#ifdef CFG_FEATURE_UB
#include "ubcore_types.h"
#endif

#define BBOX_MSG_MAGIC 0x5A5A5A5A
typedef enum bbox_msg_type {
    BBOX_QUERY_SEG_MSG,
    BBOX_QUERY_REG_MSG,
    BBOX_QUERY_DMA_MSG,
    BBOX_MSG_TYPE_MAX_NUM
} BBOX_MSG_TYPE;

struct bbox_msg_head {
    BBOX_MSG_TYPE cmd_type;
    u32 valid;
    int error_code;
    int rsv;
};

#ifdef CFG_FEATURE_UB
struct bbox_msg_data_for_ub {
    struct bbox_msg_head head;
    u32 mem_type;
    u32 token_value;
    struct ubcore_seg seg;
};
#endif

struct bbox_msg_data_for_pcie {
    struct bbox_msg_head head;
    u32 mem_type;
    struct bbox_dump_type_info bbox_dma_infos[MEM_CTRL_TYPE_MAX];
};
#endif