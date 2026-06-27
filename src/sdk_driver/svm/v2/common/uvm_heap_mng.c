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

#include "uvm_heap_mng.h"

int devmm_get_virt_pfn_by_uvm_heap(const struct devmm_uvm_heap *heap, u64 va, unsigned long *pfn)
{
#ifndef EMU_ST
    if (heap == NULL) {
        devmm_drv_err("Heap is NULL.\n");
        return -EINVAL;
    }
#endif

    if ((va < heap->start) || (va >= (heap->start + heap->heap_size))) {
#ifndef EMU_ST
        devmm_drv_err("Vaddress overflow. (va=0x%llx; start=0x%llx; size=%llu)\n", va, heap->start, heap->heap_size);
        return -EINVAL;
#endif
    }

    if (heap->chunk_page_size == 0) {
#ifndef EMU_ST
        devmm_drv_err("Heap chunk page size could not be zero.\n");
        return -EINVAL;
#endif
    }
    *pfn = (va - heap->start) / heap->chunk_page_size;
    return 0;
}

int uvm_get_page_info_by_va(struct devmm_uvm_heap *heap, u64 va, struct uvm_page_info *page_info)
{
    unsigned long pfn;
    int ret;

    if (page_info == NULL) {
#ifndef EMU_ST
        devmm_drv_err("Page_info ptr is NULL.\n");
        return -EINVAL;
#endif
    }

    ret = devmm_get_virt_pfn_by_uvm_heap(heap, va, &pfn);
    if (ret != 0) {
        devmm_drv_err("Fail to get virt pfn of va. (va=0x%llx)\n", va);
        return -EINVAL;
    }

    page_info->chunk_page_size = heap->chunk_page_size;
    page_info->page_bitmap = &heap->page_bitmaps[pfn];
    page_info->page_map = &heap->page_maps[pfn];
    page_info->dev_bitmap = &heap->device_bitmaps[pfn];
    page_info->access_by_bitmap = &heap->access_by_bitmaps[pfn];
    page_info->page_rwlock = &heap->lock_array[pfn];
    page_info->va_align = ka_base_round_down(va, DEVMM_UVM_PAGE_SIZE);

    return 0;
}

ka_rw_semaphore_t *uvm_get_page_lock_array(struct devmm_uvm_heap *heap, uint64_t va)
{
    unsigned long pfn;
    int ret;

    if (heap == NULL) {
        devmm_drv_err("Heap is NULL.\n");
#ifndef EMU_ST
        return NULL;
#endif
    }

    ret = devmm_get_virt_pfn_by_uvm_heap(heap, va, &pfn);
    if (ret != 0) {
        devmm_drv_err("Fail to get virt pfn of va. (va=0x%llx)\n", va);
        return NULL;
    }

    return &heap->lock_array[pfn];
}