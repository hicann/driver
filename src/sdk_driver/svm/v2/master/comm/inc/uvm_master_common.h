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

#ifndef UVM_MASTER_COMMON_H
#define UVM_MASTER_COMMON_H

#include "uvm_heap_mng.h"
#include "devmm_proc_info.h"

int uvm_host_sync_device_data(
    struct devmm_svm_process *svm_proc, struct uvm_page_info *page_info, uint64_t start, ka_page_t **pages);
int uvm_host_alloc_and_map_page(
    struct devmm_svm_process *svm_proc, struct uvm_page_info *page_info, uint64_t start, int numa_id,
    bool is_read_only);
int uvm_reset_ptes_of_hugepage_host(
    struct devmm_svm_process *svm_proc, ka_vm_area_struct_t *vma, uint64_t addr, bool is_read_only, bool need_lock);
int set_page_pte_readwrite(
    struct devmm_svm_process *svm_proc, ka_vm_area_struct_t *vma, struct uvm_page_info *page_info, bool need_lock);
int uvm_reset_ptes_of_hugepage(
    struct devmm_svm_process *svm_proc, ka_vm_area_struct_t *vma, uint64_t addr, bool is_read_only);
#endif