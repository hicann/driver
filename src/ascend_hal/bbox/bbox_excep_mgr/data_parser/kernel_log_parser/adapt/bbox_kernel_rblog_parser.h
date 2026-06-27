/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef BBOX_KERNEL_RB_LOG_PARSER_H
#define BBOX_KERNEL_RB_LOG_PARSER_H

#include "bbox_kernel_rblog_parser_types.h"

/* adapt version: with last_finalized_id for kernel log adapt feature */
struct rb_desc_ring {
    u32 count_bits;
    struct rb_desc *descs;
    struct rb_printk_info *infos;
    unsigned long head_id;
    unsigned long tail_id;
    unsigned long last_finalized_id;
};

struct rb_printk {
    struct rb_desc_ring desc_ring;
    struct rb_data_ring text_data_ring;
    unsigned long fail;
};

#endif /* BBOX_KERNEL_RB_LOG_PARSER_H */
