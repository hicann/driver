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

#ifndef KA_MEMORY_MNG_H
#define KA_MEMORY_MNG_H

#include "ka_fs_pub.h"

void ka_mem_mng_init(void);
void ka_mem_mng_uninit(void);
int ka_mem_stats_show(ka_seq_file_t *seq, void *offset);
bool ka_is_enable_mem_record(void);
void ka_mem_record_status_reset(bool is_enable);
void ka_mem_alloc_stat_add(unsigned int module_id, size_t size, unsigned long va);
void ka_mem_alloc_stat_del(unsigned long va, unsigned int module_id);

#endif
