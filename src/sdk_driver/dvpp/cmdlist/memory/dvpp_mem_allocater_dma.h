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

#ifndef DVPP_MEM_ALLOCATER_DMA_H
#define DVPP_MEM_ALLOCATER_DMA_H

#include "dvpp_cmdlist.h"
#include "dvpp_dma_mem_ctrl.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t alloc_dma_memory(uint32_t pool_id, dvpp_sqe_args* sqe_args, uint32_t size, dvpp_dma_mem* dma_mem);
void free_dma_memory(uint32_t pool_id, dvpp_sqe_args* sqe_args, dvpp_dma_mem* dma_mem);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_MEM_ALLOCATER_DMA_H