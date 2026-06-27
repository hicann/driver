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
#include "ka_system_pub.h"
#include "ka_memory_pub.h"

#include "pbl_feature_loader.h"

#include "svm_pub.h"
#include "normal_pgtable.h"
#include "pte_ops.h"

static int svm_pmd_entry_of_free_ptes(ka_pmd_t *pmd, u64 addr, u64 next, struct ka_pgwalk *walk)
{
#ifndef CFG_FEATURE_ENABLE_ASAN
    ka_vm_area_struct_t *vma = walk->vma;
#endif

#ifndef CFG_FEATURE_ENABLE_ASAN
    ka_pgtable_t pte = ka_mm_pmd_pgtable(*pmd);
#endif
    ka_mm_pmd_clear(pmd);
#ifndef CFG_FEATURE_ENABLE_ASAN
    ka_mm_pte_free(vma->vm_mm, pte); /* asan do not find ptlock_free api */
    ka_mm_dec_nr_ptes(vma->vm_mm);
#endif
    return 0;
}

static void svm_try_free_ptes(ka_vm_area_struct_t *vma, u64 start, u64 end)
{
    u64 align_start = svm_align_up(start, KA_HPAGE_SIZE);
    u64 align_end = svm_align_down(end, KA_HPAGE_SIZE);
    struct ka_pgwalk_ops ops = {NULL};

    if (align_end > align_start) {
        ops.pmd_entry = svm_pmd_entry_of_free_ptes;
        (void)ka_walk_page_range(vma, align_start, align_end, &ops, NULL);
        ka_mm_flush_tlb_range(vma, align_start, align_end);
    }
}

int svm_free_ptes_init(void)
{
    svm_normal_register_free_ptes_ops(svm_try_free_ptes);
    return 0;
}
DECLAER_FEATURE_AUTO_INIT(svm_free_ptes_init, FEATURE_LOADER_STAGE_0);
