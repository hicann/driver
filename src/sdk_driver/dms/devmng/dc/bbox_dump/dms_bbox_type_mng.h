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
#ifndef __DMS_BBOX_TYPE_MNG_H
#define __DMS_BBOX_TYPE_MNG_H
#include "ka_common_pub.h"
#include "ubcore_types.h"
#include "ubcore_uapi.h"

struct bbox_ub_dump_ctx {
    ka_rw_semaphore_t sem;
    void *va;
    u32 size;
    u32 token_value;
    struct ubcore_target_seg *target_seg;
    struct ubcore_target_seg *remote_seg;
};

struct ubcore_device *bbox_get_ubcore_dev(u32 dev_id);

int bbox_init_ub_segment(struct ubcore_device *ubc_dev, u32 dev_id, u32 type, u64 va, u32 len, u32 token_val);
void bbox_uninit_ub_segment(struct bbox_ub_dump_ctx *ctx);
int bbox_import_ub_segment(struct ubcore_device *ubc_dev, struct bbox_ub_dump_ctx *ctx, struct ubcore_seg *seg,
                           u32 rmt_token_value);
void bbox_unimport_ub_segment(struct bbox_ub_dump_ctx *ctx);
int bbox_ub_get_data(u32 dev_id, u32 type, u32 offset, u32 len, void *buf);

struct bbox_ub_dump_ctx *bbox_get_ub_dump_ctx(u32 dev_id, u32 type);
void bbox_ub_dump_ctx_init(void);

#endif
