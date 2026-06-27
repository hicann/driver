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
#include "devmm_proc_info.h"
#include "svm_proc_mng.h"
#include "devmm_common.h"
#include "svm_kernel_msg.h"
#include "devmm_page_cache.h"
#include "devmm_addr_mng.h"
#include "svm_heap_mng.h"
#include "svm_proc_gfp.h"
#include "svm_dynamic_addr.h"
#include "svm_define.h"

#ifndef EMU_ST
static int devmm_mremap(ka_vm_area_struct_t *area) { return -EACCES; }
#endif
STATIC int devmm_soma_vm_fault_host(ka_vm_area_struct_t *vma, ka_vm_fault_struct_t *vmf) { return -EACCES; }

KA_DEFINE_VM_OPS_FAULT_FUNC(devmm_soma_vm_fault_host)

static ka_vm_operations_struct_t soma_master_vma_ops = {
    .open = NULL,
    ka_vm_ops_init_fault(devmm_soma_vm_fault_host)
#ifndef EMU_ST
        ka_vm_ops_init_mremap(devmm_mremap)
#endif
};

void devmm_soma_setup_vma_ops(ka_vm_area_struct_t *vma) { ka_mm_set_vm_ops(vma, &soma_master_vma_ops); }