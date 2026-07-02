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

#include "uvm_master_memset.h"
#include "svm_log.h"
#include "uvm_heap_mng.h"
#include "devmm_proc_info.h"
#include "svm_msg_client.h"
#include "uvm_master_common.h"
#include "svm_kernel_msg.h"
#include "devmm_common.h"

struct uvm_memory_attributes {
    bool is_uvm_host;
    bool is_uvm_device;
    bool is_uvm_non_page;
    bool is_readmostly;
    uint64_t va;
    uint64_t pa;
    uint32_t devid;
    int device_count;
    int device_ids[DEVMM_UVM_MAX_DEVICE_NUM];
};

static int uvm_memset_send_device_msg(struct devmm_svm_process *svm_proc, struct devmm_mem_memset_para *memset_para,
                                      uint32_t devid)
{
    int ret;
    struct devmm_chan_memset devmm_chan_memset_dev = {0};

    devmm_chan_memset_dev.head.dev_id = devmm_get_phyid_devid_from_svm_process(svm_proc, devid);
    devmm_chan_memset_dev.head.msg_id = DEVMM_CHAN_UVM_CHAN_MEMSET_H2D_ID;
    devmm_chan_memset_dev.head.process_id.hostpid = svm_proc->process_id.hostpid;
    devmm_chan_memset_dev.value = memset_para->value;
    devmm_chan_memset_dev.dst = memset_para->dst;
    devmm_chan_memset_dev.count = memset_para->count;

    ret = devmm_chan_msg_send(&devmm_chan_memset_dev, sizeof(devmm_chan_memset_dev), sizeof(devmm_chan_memset_dev));
#ifndef EMU_ST
    if (ret != 0) {
        devmm_drv_err("Device memset error. (ret=%d; dst=0x%llx; count=%lu)\n", ret, memset_para->dst,
                      memset_para->count);
        return ret;
    }
#endif
    return ret;
}

static int uvm_memset_device_process(struct devmm_svm_process *svm_proc, struct devmm_mem_memset_para *memset_para,
                                     struct uvm_memory_attributes *attr)
{
    uint64_t va_start;
    unsigned long size;
    unsigned long va_end;
    int ret, i;

    va_start = memset_para->dst;
    size = memset_para->count;
    va_end = va_start + size;

    if (attr->is_readmostly) {
        for (i = 0; i < attr->device_count; i++) {
            attr->devid = attr->device_ids[i];
            ret = uvm_memset_send_device_msg(svm_proc, memset_para, attr->devid);
#ifndef EMU_ST
            if (ret != 0) {
                devmm_drv_err("memset dma h2d failed. (dev_id=%u; va=0x%llx)\n", attr->devid, memset_para->dst);
                return ret;
            }
#endif
        }
    } else {
        ret = uvm_memset_send_device_msg(svm_proc, memset_para, attr->devid);
#ifndef EMU_ST
        if (ret != 0) {
            devmm_drv_err("Send memset device message failed. (dst=0x%llx; count=%lu)\n", memset_para->dst,
                          memset_para->count);
            return ret;
        }
#endif
    }

    return 0;
}

static int uvm_memset_host_process(struct devmm_svm_process *svm_proc, struct devmm_mem_memset_para *memset_para,
                                   struct uvm_memory_attributes *attr, struct uvm_page_info *page_info)
{
    int ret;
    void *kvaddr;
    uint64_t memset_size, paddr;
    uint64_t va_start, va_end, page_offset;
    uint8_t value;
    ka_vm_area_struct_t *vma;

    va_start = memset_para->dst;
    va_end = va_start + memset_para->count;
    value = (uint8_t)memset_para->value;

    page_offset = va_start & (DEVMM_UVM_PAGE_SIZE - 1);

    vma = devmm_find_vma(svm_proc, va_start);
    if (vma == NULL) {
        devmm_drv_err("Failed to find vma. (va=0x%llx)\n", va_start);
        return -EINVAL;
    }

    if (attr->is_uvm_non_page) {
        ret = uvm_host_alloc_and_map_page(svm_proc, page_info, page_info->va_align, -1, false);
        if (ret != 0) {
            devmm_drv_err("Failed to alloc host page for va=0x%llx, ret=%d\n", va_start, ret);
            return ret;
        }

        uvm_set_bitmap_mapped(page_info->page_bitmap, UVM_HOST_ID);
        attr->pa = page_info->page_map->pa_addr;
        devmm_drv_debug("Memset alloc host page succeeded. (dst=0x%llx; byte_count=%llu)\n", va_start,
                        memset_para->count);
    }

    paddr = attr->pa;
    memset_size = memset_para->count;

#ifndef EMU_ST
    kvaddr = ka_mm_phys_to_virt(paddr + page_offset);
#else
    paddr = (paddr + page_offset) >> KA_MM_PAGE_SHIFT;
    kvaddr = ka_mm_phys_to_virt(paddr);
#endif
#ifndef EMU_ST
    if (kvaddr == NULL) {
        devmm_drv_err("Phys_to_virt failed. (size=0x%llx)\n", memset_size);
        return -EINVAL;
    }

    ret = memset_s(kvaddr, DEVMM_UVM_PAGE_SIZE - page_offset, value, memset_size);
    if (ret != 0) {
        devmm_drv_err("Memset_s failed. (ret=%d; size=0x%llx)\n", ret, (uint64_t)(DEVMM_UVM_PAGE_SIZE - page_offset));
        return ret;
    }
#endif

    return 0;
}

static int uvm_get_memory_attributes(struct devmm_uvm_heap *uvm_heap, uint64_t addr, struct uvm_memory_attributes *attr,
                                     struct uvm_page_info *page_info)
{
    page_bitmap_t *page_bitmap;
    struct uvm_page_mapping *page_map;
    device_bitmap *device_bitmap;
    int ret;

    if (page_info == NULL || page_info->page_map == NULL) {
        ret = uvm_get_page_info_by_va(uvm_heap, addr, page_info);
#ifndef EMU_ST
        if (ret != 0) {
            devmm_drv_err("Fail to get page info.\n");
            return -EFAULT;
        }
#endif
    }

    page_map = page_info->page_map;
    page_bitmap = page_info->page_bitmap;
    device_bitmap = page_info->dev_bitmap;

    *attr = (struct uvm_memory_attributes){0};
    attr->va = addr;
    attr->is_uvm_host = page_bitmap_get_host_mapped(page_bitmap);
    attr->is_uvm_device = page_bitmap_get_device_mapped(page_bitmap);
    attr->is_readmostly = page_bitmap_get_read_mostly(page_bitmap);
    attr->devid = page_map->devid;
    attr->pa = page_map->pa_addr;
    attr->device_count = get_present_devices(device_bitmap, attr->device_ids);
    attr->is_uvm_non_page = (!attr->is_uvm_host && !attr->is_uvm_device);

    return 0;
}

static int devmm_memset_page_processing(struct devmm_svm_process *svm_proc, struct devmm_uvm_heap *uvm_heap,
                                        uint64_t vaddr, uint64_t memset_size, uint64_t value,
                                        struct uvm_page_info *page_info)
{
    int ret;
    struct uvm_memory_attributes attr = {};
    struct devmm_mem_memset_para current_para = {};

    ret = uvm_get_memory_attributes(uvm_heap, vaddr, &attr, page_info);
#ifndef EMU_ST
    if (ret != 0) {
        devmm_drv_err("Get memory attributes failed. (va=0x%llx)\n", vaddr);
        return ret;
    }
#endif

    current_para.dst = vaddr;
    current_para.count = memset_size;
    current_para.value = value;

    if (attr.is_uvm_non_page || attr.is_uvm_host) {
        ret = uvm_memset_host_process(svm_proc, &current_para, &attr, page_info);
#ifndef EMU_ST
        if (ret != 0) {
            devmm_drv_err("uvm_memset_host_process failed. (ret=%d; dst=0x%llx)\n", ret, current_para.dst);
            return ret;
        }
#endif
    }

    if (attr.is_uvm_device) {
        ret = uvm_memset_device_process(svm_proc, &current_para, &attr);
#ifndef EMU_ST
        if (ret != 0) {
            devmm_drv_err("uvm_memset_device_process failed. (ret=%d; dst=0x%llx)\n", ret, current_para.dst);
            return ret;
        }
#endif
    }

    return 0;
}

static int devmm_memset_partial(struct devmm_svm_process *svm_proc, struct devmm_uvm_heap *uvm_heap,
                                struct devmm_mem_memset_para *memset_para)
{
    int ret;
    uint64_t vaddr, left_size, offset_size, page_size, memset_size;
    struct uvm_page_info page_info = {};

    devmm_drv_debug("Memset parameter. (dst=0x%llx; value=0x%llx; count=%llu)\n", memset_para->dst, memset_para->value,
                    memset_para->count);

    left_size = memset_para->count;
    page_size = DEVMM_UVM_PAGE_SIZE;
    vaddr = memset_para->dst;

    do {
        offset_size = vaddr & (page_size - 1);
        memset_size = page_size - offset_size;
        memset_size = ka_base_min(memset_size, left_size);
        if (memset_size == 0) {
            break;
        }

        ret = uvm_get_page_info_by_va(uvm_heap, vaddr, &page_info);
#ifndef EMU_ST
        if (ret) {
            devmm_drv_err("Failed to get page_info for va=0x%llx\n", vaddr);
            return ret;
        }
#endif
        ka_task_down_write(page_info.page_rwlock);

        if (!page_bitmap_get_alloced(page_info.page_bitmap)) {
            devmm_drv_err("Va is not alloced, va = 0x%llx.\n", vaddr);
            ka_task_up_write(page_info.page_rwlock);
            return -EINVAL;
        }

        ret = devmm_memset_page_processing(svm_proc, uvm_heap, vaddr, memset_size, memset_para->value, &page_info);

        ka_task_up_write(page_info.page_rwlock);

        if (ret != 0) {
            return ret;
        }

        vaddr += memset_size;
        left_size -= memset_size;
    } while (left_size > 0);

    return 0;
}

int devmm_uvm_ioctl_memset_process(struct devmm_svm_process *svm_proc, struct devmm_ioctl_arg *arg)
{
    int ret;
    uint64_t head_size, middle_size, tail_size;
    uint64_t vaddr = arg->data.memset_para.dst;
    struct devmm_mem_memset_para memset_para;
    struct devmm_uvm_heap *uvm_heap = NULL;

    uvm_heap = devmm_uvm_get_heap(svm_proc, (unsigned long)vaddr);
#ifndef EMU_ST
    if (uvm_heap == NULL) {
        devmm_drv_err("UVM Heap is NULL or error for va=0x%llx.\n", vaddr);
        return -EADDRNOTAVAIL;
    }
#endif
    memset_para.dst = arg->data.memset_para.dst;
    memset_para.value = arg->data.memset_para.value;
    memset_para.count = arg->data.memset_para.count;

    head_size = (DEVMM_UVM_PAGE_SIZE - (arg->data.memset_para.dst & ~UVM_PAGE_MASK)) % DEVMM_UVM_PAGE_SIZE;
    if (arg->data.memset_para.count < head_size) {
        head_size = arg->data.memset_para.count;
    }
    tail_size = (arg->data.memset_para.count - head_size) & ~UVM_PAGE_MASK;
    middle_size = arg->data.memset_para.count - head_size - tail_size;

    if (head_size != 0) {
        memset_para.dst = vaddr;
        memset_para.count = head_size;
        ret = devmm_memset_partial(svm_proc, uvm_heap, &memset_para);
        if (ret) {
            return ret;
        }
    }
    vaddr += head_size;

    if (middle_size != 0) {
        memset_para.dst = vaddr;
        memset_para.count = middle_size;
        ret = devmm_memset_partial(svm_proc, uvm_heap, &memset_para);
        if (ret) {
            return ret;
        }
    }
    vaddr += middle_size;

    if (tail_size != 0) {
        memset_para.dst = vaddr;
        memset_para.count = tail_size;
        ret = devmm_memset_partial(svm_proc, uvm_heap, &memset_para);
        if (ret) {
            return ret;
        }
    }

    return 0;
}
