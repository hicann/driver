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

#include "ka_list_pub.h"
#include "dvt.h"
#include "vfio_ops.h"
#include "dma_pool.h"
#include "dma_pool_map.h"

STATIC void dev_map_scheduled(struct hw_vdavinci *vdavinci,
                              unsigned long *count)
{
    (*count)++;
    if (hw_vdavinci_scheduled(vdavinci,
                              (*count) * KA_VFIO_PIN_PAGES_MAX_ENTRIES,
                              VDAVINCI_MAP_PAGES_OF_SCHEDULE,
                              VDAVINCI_MAP_TIME_OF_SCHEDULE,
                              NULL)) {
        (*count) = 0;
    }
}

STATIC int dev_get_prot(struct hw_vdavinci *vdavinci)
{
    ka_device_t *dev = vdavinci_get_device(vdavinci);
    bool coherent = ka_is_dev_dma_coherent(dev);
    int prot = coherent ? KA_IOMMU_CACHE : 0;

    return prot | KA_IOMMU_READ | KA_IOMMU_WRITE;
}

STATIC void dev_unmap_2m(ka_device_t *dev, ka_sg_table_t *dma_sgt)
{
    ka_dma_unmap_sg(dev, dma_sgt->sgl, dma_sgt->orig_nents, KA_DMA_BIDIRECTIONAL);
    ka_base_sg_free_table(dma_sgt);
    ka_mm_kfree(dma_sgt);
}

STATIC int dev_map_2m(ka_device_t *dev, unsigned long gfn,
                      ka_sg_table_t **dma_sgt,
                      struct page_info_list *dma_page_list, unsigned long size)
{
    int ret;
    struct page_info_entry *dma_page_info;
    ka_scatterlist_t *sgl = NULL;

    if (dma_page_list == NULL) {
        return -EINVAL;
    }

    *dma_sgt = ka_mm_kzalloc(sizeof(ka_sg_table_t), KA_GFP_KERNEL);
    if (*dma_sgt == NULL) {
        return -ENOMEM;
    }

    ret = ka_base_sg_alloc_table(*dma_sgt, dma_page_list->elem_num, KA_GFP_KERNEL);
    if (ret) {
        vascend_err(dev, "ka_base_sg_alloc_table return error result, ret: %d, sg_len: %u",
                    ret, dma_page_list->elem_num);
        ret = -ENOMEM;
        goto err_free_sgt;
    }

    sgl = (*dma_sgt)->sgl;
    ka_list_for_each_entry(dma_page_info, &dma_page_list->head, list) {
        ka_base_sg_set_page(sgl, dma_page_info->page, dma_page_info->length, 0);
        sgl = ka_base_sg_next(sgl);
    }

    (*dma_sgt)->nents = ka_dma_map_sg(dev, (*dma_sgt)->sgl, (*dma_sgt)->orig_nents, KA_DMA_BIDIRECTIONAL);
    if ((*dma_sgt)->nents == 0) {
        ret = -ENOMEM;
        vascend_err(dev, "dma map sg failed, gfn: 0x%lx, size: %lu\n", gfn, size);
        goto err_free_sg;
    }

    return 0;
err_free_sg:
    ka_base_sg_free_table(*dma_sgt);
err_free_sgt:
    ka_mm_kfree(*dma_sgt);

    return ret;
}

void dev_dma_unmap_ram_range(struct hw_vdavinci *vdavinci,
                             struct ram_range_info *ram_info)
{
    int i;
    bool found = false;
    unsigned long count = 0;
    struct dev_dma_sgt *dev_dma_sgt = NULL;
    ka_device_t *dev = vdavinci_get_device(vdavinci);
    struct dev_dma_info *dma_info = NULL;
    ka_list_head_t *pos = NULL, *next = NULL;

    if (ka_list_empty(&(vdavinci->vdev.dev_dma_info_list_head))) {
        return;
    }
    ka_list_for_each_safe(pos, next, &(vdavinci->vdev.dev_dma_info_list_head)) {
        dma_info = ka_list_entry(pos, struct dev_dma_info, list);
        if (ram_info != dma_info->ram_info) {
            continue;
        }
        ka_list_del(&dma_info->list);
        for (i = 0; i < ram_info->dma_array_len; i++) {
            dev_map_scheduled(vdavinci, &count);
            dev_dma_sgt = dma_info->sgt_array[i];
            dev_unmap_2m(dev, dev_dma_sgt->dma_sgt);
            ka_mm_kfree(dev_dma_sgt);
        }
        ka_mm_kfree(dma_info);
        found = true;
    }
    if (!found) {
        return;
    }
    ka_base_atomic_dec(&ram_info->map_count);
}

STATIC struct dev_dma_sgt *dev_map_sgt_2m(struct hw_vdavinci *vdavinci,
                                          struct dma_info_2m *dma_array_node)
{
    int ret = 0;
    ka_sg_table_t *dma_sgt = NULL;
    struct dev_dma_sgt *dev_dma_sgt = NULL;
    ka_device_t *dev = vdavinci_get_device(vdavinci);

    ret = dev_map_2m(dev, dma_array_node->gfn, &dma_sgt,
                     &dma_array_node->dma_page_list,
                     dma_array_node->size);
    if (ret != 0) {
        goto out;
    }

    dev_dma_sgt = (struct dev_dma_sgt *)ka_mm_kzalloc(sizeof(struct dev_dma_sgt), KA_GFP_KERNEL);
    if (dev_dma_sgt == NULL) {
        ret = -ENOMEM;
        goto free;
    }

    dev_dma_sgt->gfn = dma_array_node->gfn;
    dev_dma_sgt->dev = dev;
    dev_dma_sgt->dma_sgt = dma_sgt;
    dev_dma_sgt->dma_addr = ka_mm_sg_dma_address(dma_sgt->sgl);

    return dev_dma_sgt;

free:
    dev_unmap_2m(dev, dma_sgt);
out:
    vascend_err(dev, "dma map page failed, ret: %d, size: 0x%lx\n",
                ret, dma_array_node->size);
    return NULL;
}

int dev_dma_map_ram_range(struct hw_vdavinci *vdavinci,
                          struct ram_range_info *ram_info)
{
    int ret = 0, i = 0, j = 0;
    unsigned long count = 0;
    struct dma_info_2m *dma_array_node = NULL;
    struct dev_dma_sgt **sgt_array = NULL;
    struct dev_dma_sgt *dev_dma_sgt = NULL;
    ka_device_t *dev = vdavinci_get_device(vdavinci);
    struct dev_dma_info *dma_info = NULL;

    sgt_array = (struct dev_dma_sgt **)
        ka_mm_kzalloc(sizeof(struct dev_dma_sgt *) * ram_info->dma_array_len, KA_GFP_KERNEL);
    if (sgt_array == NULL) {
        return -ENOMEM;
    }

    dma_info = ka_mm_kzalloc(sizeof(struct dev_dma_info), KA_GFP_KERNEL);
    if (dma_info == NULL) {
        ret = -ENOMEM;
        goto free_sgt;
    }
    for (i = 0; i < ram_info->dma_array_len; i++) {
        dev_map_scheduled(vdavinci, &count);
        dma_array_node = ram_info->dma_array[i];
        dev_dma_sgt = dev_map_sgt_2m(vdavinci, dma_array_node);
        if (dev_dma_sgt == NULL) {
            ret = -EINVAL;
            goto out;
        }
        sgt_array[i] = dev_dma_sgt;
    }
    dma_info->ram_info = ram_info;
    dma_info->sgt_array = sgt_array;
    ka_list_add_tail(&(dma_info->list), &(vdavinci->vdev.dev_dma_info_list_head));
    ka_base_atomic_inc(&ram_info->map_count);

    return 0;
out:
    for (j = 0; j < i; j++) {
        dma_array_node = ram_info->dma_array[j];
        dev_dma_sgt = sgt_array[j];
        dev_unmap_2m(dev, dev_dma_sgt->dma_sgt);
        ka_mm_kfree(dev_dma_sgt);
    }
    ka_mm_kfree(dma_info);
free_sgt:
    ka_mm_kfree(sgt_array);
    return ret;
}

STATIC void vf_unmap_2m(ka_device_t *dev, ka_dma_addr_t base_2m_iova,
                        struct page_info_list *dma_page_list)
{
    struct page_info_entry *dma_page_info = NULL;
    ka_list_head_t *pos = NULL, *next = NULL;
    ka_dma_addr_t iova = base_2m_iova;

    ka_list_for_each_safe(pos, next, &(dma_page_list->head)) {
        dma_page_info = ka_list_entry(pos, struct page_info_entry, list);
        vdavinci_iommu_unmap(dev, iova, dma_page_info->length);
        iova += dma_page_info->length;
    }
}

/**
 * After calling hw_pin_guest_contiguous_page, we get a linked list of consecutive pfn
 * addresses. Then you can use this function to convert the pfn address to the iova
 * address of the corresponding pcie device.
 */
STATIC int vf_map_2m(ka_device_t *dev,
                     ka_dma_addr_t base_2m_iova, struct page_info_list *dma_page_list,
                     int prot)
{
    struct page_info_entry *dma_page_info = NULL;
    struct page_info_entry *dma_page_info_err = NULL;
    ka_list_head_t *pos = NULL, *next = NULL;
    ka_dma_addr_t iova = base_2m_iova;
    phys_addr_t phys;

    if (dma_page_list == NULL) {
        return -EINVAL;
    }

    ka_list_for_each_safe(pos, next, &(dma_page_list->head)) {
        dma_page_info = ka_list_entry(pos, struct page_info_entry, list);

        phys = ka_mm_page_to_phys(dma_page_info->page);
        /* phys is page algned, so there is no iova_offset alignment */
        if (vdavinci_iommu_map(dev, iova, phys, dma_page_info->length, prot) != 0) {
            dma_page_info_err = dma_page_info;
            goto unmap;
        }

        iova += dma_page_info->length;
    }

    return 0;

unmap:
    iova = base_2m_iova;
    ka_list_for_each_safe(pos, next, &(dma_page_list->head)) {
        dma_page_info = ka_list_entry(pos, struct page_info_entry, list);

        if (dma_page_info != dma_page_info_err) {
            vdavinci_iommu_unmap(dev, iova, dma_page_info->length);
            iova += dma_page_info->length;
        } else {
            break;
        }
    }

    return -EFAULT;
}

void vf_unmap_ram_range(struct hw_vdavinci *vdavinci,
                        struct ram_range_info *ram_info)
{
    int j;
    bool found = false;
    unsigned long count = 0;
    struct dma_info_2m *dma_array_node = NULL;
    struct dev_dma_info *dma_info = NULL;
    ka_list_head_t *pos = NULL, *next = NULL;
    ka_device_t *dev = vdavinci_get_device(vdavinci);

    if (ka_list_empty(&(vdavinci->vdev.dev_dma_info_list_head))) {
        return;
    }
    ka_list_for_each_safe(pos, next, &(vdavinci->vdev.dev_dma_info_list_head)) {
        dma_info = ka_list_entry(pos, struct dev_dma_info, list);
        if (ram_info != dma_info->ram_info) {
            continue;
        }
        ka_list_del(&dma_info->list);
        for (j = 0; j < ram_info->dma_array_len; j++) {
            dev_map_scheduled(vdavinci, &count);
            dma_array_node = ram_info->dma_array[j];
            vf_unmap_2m(dev, dma_info->base_iova +
                j * KA_VFIO_PIN_PAGES_MAX_ENTRIES * KA_MM_PAGE_SIZE,
                &(dma_array_node->dma_page_list));
        }
        ka_mm_kfree(dma_info);
        found = true;
    }
    if (!found) {
        return;
    }
    ka_base_atomic_dec(&ram_info->map_count);
}

int vf_map_ram_range(struct hw_vdavinci *vdavinci,
                     struct ram_range_info *ram_info)
{
    unsigned long count = 0;
    int i = 0, j = 0, ret = 0;
    struct dma_info_2m *dma_array_node = NULL;
    ka_device_t *dev = vdavinci_get_device(vdavinci);
    int prot = dev_get_prot(vdavinci);
    ka_dma_addr_t base_iova;
    struct dev_dma_info *dma_info = NULL;

    base_iova = ram_info->base_gfn << KA_MM_PAGE_SHIFT;

    dma_info = ka_mm_kzalloc(sizeof(struct dev_dma_info), KA_GFP_KERNEL);
    if (!dma_info) {
        return -ENOMEM;
    }
    for (i = 0; i < ram_info->dma_array_len; i++) {
        dev_map_scheduled(vdavinci, &count);
        dma_array_node = ram_info->dma_array[i];
        ret = vf_map_2m(dev, base_iova + i * KA_VFIO_PIN_PAGES_MAX_ENTRIES * KA_MM_PAGE_SIZE,
                        &(dma_array_node->dma_page_list),
                        prot);
        if (ret != 0) {
            goto out;
        }
    }

    dma_info->ram_info = ram_info;
    dma_info->base_iova = base_iova;
    ka_list_add_tail(&(dma_info->list), &(vdavinci->vdev.dev_dma_info_list_head));
    ka_base_atomic_inc(&ram_info->map_count);

    return 0;
out:
    for (j = 0; j < i; j++) {
        dma_array_node = ram_info->dma_array[j];

        vf_unmap_2m(dev, base_iova + j * KA_VFIO_PIN_PAGES_MAX_ENTRIES * KA_MM_PAGE_SIZE,
                    &(dma_array_node->dma_page_list));
    }
    ka_mm_kfree(dma_info);
    return ret;
}
