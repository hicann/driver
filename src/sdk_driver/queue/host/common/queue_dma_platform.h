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

#ifndef QUEUE_DMA_PLATFORM_H
#define QUEUE_DMA_PLATFORM_H

#include "queue_dma.h"
#include "ka_system_pub.h"

#define QUEUE_DMA_MAX_NODE_CNT_MINI (0x8000 - 0x200)
#define QUEUE_DMA_MAX_NODE_CNT_STD 32768

void queue_clear_dma_blks_platform(struct queue_dma_list *dma_list, u32 dev_id);
void queue_unmap_dma_blks_platform(ka_device_t *dev, struct queue_dma_list *dma_list, u64 idx, u32 dev_id);
bool queue_get_dma_sva_enable_platform(u32 dev_id);
u64 get_queue_dma_max_node_cnt(u32 dev_id);

#endif /* QUEUE_DMA_PLATFORM_H */
