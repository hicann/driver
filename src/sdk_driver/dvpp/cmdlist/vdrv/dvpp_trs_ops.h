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

#ifndef DVPP_TRS_OPS_H
#define DVPP_TRS_OPS_H

#include "ka_type.h"
typedef struct {
    uint64_t addr;
    uint64_t size;
    uint8_t  init_flag;
} dvpp_share_mem_info;

void dvpp_trs_sqe_update_init(void);
void dvpp_trs_sqe_update_uninit(void);

#endif // #ifndef DVPP_TRS_OPS_H