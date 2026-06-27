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

#ifndef NORMAL_PGTABLE_H
#define NORMAL_PGTABLE_H

#include "ka_memory_pub.h"

typedef void (*svm_normal_free_ptes_ops_t)(ka_vm_area_struct_t *vma, u64 start, u64 end);

void svm_normal_register_free_ptes_ops(svm_normal_free_ptes_ops_t ops);

int svm_normal_pgtbl_init(void);

#endif
