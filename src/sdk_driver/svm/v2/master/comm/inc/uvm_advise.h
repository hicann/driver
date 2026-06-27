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
#ifndef UVM_ADVISE_H
#define UVM_ADVISE_H

#include "devmm_proc_info.h"
#include "uvm_heap_mng.h"

#define INVALID_NUMA (-1)

int devmm_uvm_ioctl_advise(struct devmm_svm_process *svm_pro, struct devmm_ioctl_arg *arg);
int devmm_uvm_ioctl_get_mem_range_attributes(struct devmm_svm_process *svm_pro, struct devmm_ioctl_arg *arg);
int uvm_check_and_get_advise_id(int type, int id, bool numaEnable);
#endif /* UVM_ADVISE_H */
