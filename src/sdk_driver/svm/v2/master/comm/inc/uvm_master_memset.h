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

#ifndef UVM_MASTER_MEMSET_H
#define UVM_MASTER_MEMSET_H

#include "uvm_heap_mng.h"
#include "devmm_proc_info.h"

int devmm_uvm_ioctl_memset_process(struct devmm_svm_process *svm_proc, struct devmm_ioctl_arg *arg);

#endif /* UVM_MASTER_MEMSET_H */