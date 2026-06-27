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

#ifndef DVPP_MEM_ALLOCATER_ARGS_H
#define DVPP_MEM_ALLOCATER_ARGS_H

#include "dvpp_cmdlist.h"

#ifdef __cplusplus
extern "C" {
#endif

uint64_t alloc_args_memory(uint32_t pool_id, uint32_t args_size, dvpp_sqe_args* sqe_args);
void free_args_memory(uint32_t pool_id, dvpp_sqe_args* sqe_args, uint64_t args_addr);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_MEM_ALLOCATER_ARGS_H