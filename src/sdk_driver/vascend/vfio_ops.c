/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025-2025. All rights reserved.
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

#include <linux/version.h>
#include <linux/device.h>
#include <linux/uuid.h>
#include <linux/mdev.h>
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5,10,0))
#include <linux/dma-map-ops.h>
#include <linux/vfio.h>
#elif ((LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,36)) || (defined(DRV_UT)))
#include <linux/dma-noncoherent.h>
#include <linux/vfio.h>
#elif ((LINUX_VERSION_CODE >= KERNEL_VERSION(4,14,0)) || (defined(DRV_UT)))
#include <linux/vfio.h>
#endif
#include "dvt_sysfs.h"
#include "domain_manage.h"
#include "dma_pool.h"
#include "kvmdt.h"
#include "vfio_ops.h"

STATIC DEFINE_MUTEX(mdev_register_lock);

#ifndef __ASM_DEVICE_H
bool is_dev_dma_coherent(struct device *dev)
{
    return true;
}
#else
#if ((LINUX_VERSION_CODE == KERNEL_VERSION(4,19,36)) || (LINUX_VERSION_CODE == KERNEL_VERSION(4,19,90)))
bool is_dev_dma_coherent(struct device *dev)
{
    return dev->archdata.dma_coherent;
}
#else
bool is_dev_dma_coherent(struct device *dev)
{
        return true;
}
#endif
#endif /* __ASM_DEVICE_H */

void vdavinci_iommu_unmap(struct device *dev, unsigned long iova, size_t size)
{
    size_t unmapped;
    struct iommu_domain *domain = NULL;

    dma_sync_single_for_cpu(dev, iova, size, DMA_BIDIRECTIONAL);
    domain = iommu_get_domain_for_dev(dev);
    unmapped = iommu_unmap(domain, iova, size);
    WARN_ON(unmapped != size);
}

int vdavinci_iommu_map(struct device *dev, unsigned long iova,
                       phys_addr_t paddr, size_t size, int prot)
{
    struct iommu_domain *domain = iommu_get_domain_for_dev(dev);

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,3,0))
    return iommu_map(domain, iova, paddr, size, prot, GFP_KERNEL);
#else
    return iommu_map(domain, iova, paddr, size, prot);
#endif
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,19,36))
    if (!is_dev_dma_coherent(dev)) {
        dma_sync_single_for_device(dev, iova, size, DMA_BIDIRECTIONAL);
    }
#endif
}

void vdavinci_unpin_pages(struct hw_vdavinci *vdavinci, struct vdavinci_pin_info *pin_info)
{
    int ret = pin_info->npage;

    if (pin_info->npage <= 0 || pin_info->npage > (int)VFIO_PIN_PAGES_MAX_ENTRIES) {
        vascend_err(vdavinci_to_dev(vdavinci), "vdavinci error npage: %d\n", pin_info->npage);
        return;
    }
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,0,0))
    if (pin_info->gfn == 0) {
        vascend_err(vdavinci_to_dev(vdavinci), "vdavinci gfn error");
        return;
    }
#else
    if (IS_ERR_OR_NULL(pin_info->gfns)) {
        vascend_err(vdavinci_to_dev(vdavinci), "vdavinci error gfns");
        return;
    }
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,0,0))
    vfio_unpin_pages(vdavinci->vdev.vfio_device, pin_info->gfn, pin_info->npage);
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0))
    ret = vfio_unpin_pages(vdavinci->vdev.vfio_device, pin_info->gfns, pin_info->npage);
#else
    ret = vfio_unpin_pages(mdev_dev(vdavinci->vdev.mdev), pin_info->gfns, pin_info->npage);
#endif
    WARN_ON(ret != pin_info->npage);
}

int vdavinci_pin_pages(struct hw_vdavinci *vdavinci, struct vdavinci_pin_info *pin_info)
{
    int ret = -1;

    if (pin_info->npage <= 0 || pin_info->npage > (int)VFIO_PIN_PAGES_MAX_ENTRIES) {
        vascend_err(vdavinci_to_dev(vdavinci), "vdavinci error npage: %d\n", pin_info->npage);
        return -EINVAL;
    }
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,0,0))
    if (pin_info->gfn == 0 || IS_ERR_OR_NULL(pin_info->pages)) {
        vascend_err(vdavinci_to_dev(vdavinci), "vdavinci pages or gfn error");
        return -EINVAL;
    }
#else
    if (IS_ERR_OR_NULL(pin_info->gfns) || IS_ERR_OR_NULL(pin_info->pfns)) {
        vascend_err(vdavinci_to_dev(vdavinci), "vdavinci pfns or gfns error ");
        return -EINVAL;
    }
#endif

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,0,0))
    ret = vfio_pin_pages(vdavinci->vdev.vfio_device, pin_info->gfn,
                         pin_info->npage, IOMMU_READ | IOMMU_WRITE, pin_info->pages);
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0))
    ret = vfio_pin_pages(vdavinci->vdev.vfio_device, pin_info->gfns,
                         pin_info->npage, IOMMU_READ | IOMMU_WRITE, pin_info->pfns);
#else
    ret = vfio_pin_pages(mdev_dev(vdavinci->vdev.mdev), pin_info->gfns,
                         pin_info->npage, IOMMU_READ | IOMMU_WRITE, pin_info->pfns);
#endif
    return ret;
}

struct device *get_mdev_parent(struct mdev_device *mdev)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0)
    return mdev->type->parent->dev;
#else
    return mdev_parent_dev(mdev);
#endif
}

bool device_is_mdev(struct device *dev)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,13,0)
    if (dev == NULL) {
        return false;
    }
    return !strcmp(dev->bus->name, "mdev");
#else
    return dev->bus == &mdev_bus_type;
#endif
}

struct mdev_device *get_mdev_device(struct device *dev)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0)
    return to_mdev_device(dev);
#else
    return mdev_from_dev(dev);
#endif
}

void *get_mdev_drvdata(struct device *dev)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0)
    return dev_get_drvdata(dev);
#else
    struct mdev_device *mdev = mdev_from_dev(dev);

    return mdev_get_drvdata(mdev);
#endif
}

void set_mdev_drvdata(struct device *dev, void *data)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0)
    dev_set_drvdata(dev, data);
#else
    struct mdev_device *mdev = mdev_from_dev(dev);

    mdev_set_drvdata(mdev, data);
#endif
}

/**
 * first, return the vf device otherwise return mdev parent device
 */
struct device *vdavinci_get_device(struct hw_vdavinci *vdavinci)
{
    struct device *dev = vdavinci_resource_dev(vdavinci);
    if (!dev) {
        dev = get_mdev_parent(vdavinci->vdev.mdev);
    }

    return dev;
}

struct device *vdavinci_to_dev(struct hw_vdavinci *vdavinci)
{
    struct device *dev = NULL;

    if (vdavinci == NULL) {
        return NULL;
    }

    dev = vdavinci_resource_dev(vdavinci);
    if (dev) {
        return dev;
    }

    dev = vdavinci->dvt->vdavinci_priv->dev;
    if (dev) {
        return dev;
    }

    return get_mdev_parent(vdavinci->vdev.mdev);
}

void vdavinci_unregister_driver(struct mdev_driver *drv)
{
#if IS_ENABLED(CONFIG_VFIO_MDEV)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0))
    mdev_unregister_driver(drv);
#endif /* KERNEL_VERSION(6,1,0) */
#endif /* CONFIG_VFIO_MDEV */
}

int vdavinci_register_driver(struct mdev_driver *drv)
{
    int ret = 0;
#if IS_ENABLED(CONFIG_VFIO_MDEV)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0))
    ret = mdev_register_driver(drv);
    if (ret != 0) {
        return ret;
    }
#endif /* KERNEL_VERSION(6,1,0) */
#endif /* CONFIG_VFIO_MDEV */

    return ret;
}

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0))
STATIC inline struct hw_vfio_vdavinci *vfio_dev_to_vfio_vnpu(struct vfio_device *vfio_dev)
{
    return container_of(vfio_dev, struct hw_vfio_vdavinci, vfio_dev);
}

STATIC inline struct hw_vdavinci *vfio_dev_to_vnpu(struct vfio_device *vfio_dev)
{
    struct hw_vfio_vdavinci *vfio_vdavinci = NULL;

    vfio_vdavinci = vfio_dev_to_vfio_vnpu(vfio_dev);
    if (vfio_vdavinci == NULL) {
        return NULL;
    }

    return vfio_vdavinci->vdavinci;
}

STATIC int hw_vdavinci_vfio_init(struct vfio_device *vfio_dev)
{
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);
    struct hw_vfio_vdavinci *vfio_vdavinci = vfio_dev_to_vfio_vnpu(vfio_dev);

    vfio_vdavinci->vdavinci = hw_vdavinci_create(&mdev->type->kobj, mdev);
    if (vfio_vdavinci->vdavinci == NULL) {
        return -EINVAL;
    }

    return 0;
}

STATIC void hw_vdavinci_vfio_release(struct vfio_device *vfio_dev)
{
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);

    (void)hw_vdavinci_remove(mdev);
}

STATIC int hw_vdavinci_vfio_open(struct vfio_device *vfio_dev)
{
    struct vm_dom_info *vm_dom = NULL;
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);
    struct hw_vdavinci *vdavinci = vfio_dev_to_vnpu(vfio_dev);
    struct mutex *g_vm_domains_lock = get_vm_domains_lock();

    if (vdavinci == NULL || vfio_dev->kvm == NULL) {
        return -EINVAL;
    }
    vdavinci->vdev.kvm = vfio_dev->kvm;
    mutex_lock(g_vm_domains_lock);
    vm_dom = vm_dom_info_get(vdavinci->vdev.kvm);
    mutex_unlock(g_vm_domains_lock);
    if (vm_dom == NULL) {
        vascend_err(vdavinci_to_dev(vdavinci), "vnpu init domain failed\n");
        return -EINVAL;
    }
    vdavinci->vdev.domain = vm_dom;

    return hw_vdavinci_open(mdev);
}

STATIC void hw_vdavinci_vfio_close(struct vfio_device *vfio_dev)
{
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);
    struct hw_vdavinci *vdavinci = vfio_dev_to_vnpu(vfio_dev);

    if (vdavinci == NULL) {
        return;
    }
    hw_vdavinci_release(mdev);
    vdavinci->vdev.kvm = NULL;
    vdavinci->vdev.domain = NULL;
}

STATIC ssize_t hw_vdavinci_vfio_read(struct vfio_device *vfio_dev, char __user *buf,
                                     size_t count, loff_t *ppos)
{
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);

    return hw_vdavinci_read(mdev, buf, count, ppos);
}

STATIC ssize_t hw_vdavinci_vfio_write(struct vfio_device *vfio_dev,
                                      const char __user *buf,
                                      size_t count, loff_t *ppos)
{
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);

    return hw_vdavinci_write(mdev, buf, count, ppos);
}

STATIC int hw_vdavinci_vfio_mmap(struct vfio_device *vfio_dev, struct vm_area_struct *vma)
{
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);

    return hw_vdavinci_mmap(mdev, vma);
}

STATIC long hw_vdavinci_vfio_ioctl(struct vfio_device *vfio_dev,
                                   unsigned int cmd, unsigned long arg)
{
    struct mdev_device *mdev = get_mdev_device(vfio_dev->dev);

    return hw_vdavinci_ioctl(mdev, cmd, arg);
}

STATIC void hw_vdavinci_vfio_dma_unmap(struct vfio_device *vfio_dev,
                                       u64 iova, u64 length)
{
    unsigned long start_gfn = iova >> PAGE_SHIFT;
    struct hw_vdavinci *vdavinci = vfio_dev_to_vnpu(vfio_dev);

    if (vdavinci == NULL) {
        return;
    }
    mutex_lock(&vdavinci->vdev.cache_lock);
    hw_vdavinci_unplug_ram(vdavinci, start_gfn, length);
    mutex_unlock(&vdavinci->vdev.cache_lock);
}

STATIC const struct vfio_device_ops hw_vnpu_vfio_dev_ops = {
    .init = hw_vdavinci_vfio_init,
    .release = hw_vdavinci_vfio_release,
    .open_device = hw_vdavinci_vfio_open,
    .close_device = hw_vdavinci_vfio_close,
    .read = hw_vdavinci_vfio_read,
    .write = hw_vdavinci_vfio_write,
    .mmap = hw_vdavinci_vfio_mmap,
    .dma_unmap = hw_vdavinci_vfio_dma_unmap,
    .ioctl = hw_vdavinci_vfio_ioctl,
    .bind_iommufd	= vfio_iommufd_emulated_bind,
    .unbind_iommufd = vfio_iommufd_emulated_unbind,
    .attach_ioas	= vfio_iommufd_emulated_attach_ioas,
    .detach_ioas	= vfio_iommufd_emulated_detach_ioas,
};

STATIC int hw_vdavinci_vfio_probe(struct mdev_device *mdev)
{
    int ret = 0;
    struct device *pdev;
    struct hw_dvt *dvt;
    struct hw_vfio_vdavinci *vfio_vdavinci = NULL;

    pdev = get_mdev_parent(mdev);
    dvt = kdev_to_davinci(pdev)->dvt;
    if (!hw_vdavinci_is_enabled(dvt)) {
        vascend_err(pdev, "driver is not in vm mode or device's sriov is not enabled\n");
        return -EINVAL;
    }

    vfio_vdavinci = vfio_alloc_device(hw_vfio_vdavinci, vfio_dev, &mdev->dev, &hw_vnpu_vfio_dev_ops);
    if (IS_ERR(vfio_vdavinci)) {
        vascend_err(pdev, "vdavinci probe failed\n");
        return -EINVAL;
    }
    vfio_vdavinci->vdavinci->vdev.vfio_device = &vfio_vdavinci->vfio_dev;
    ret = vfio_register_emulated_iommu_dev(&vfio_vdavinci->vfio_dev);
    if (ret != 0) {
        vascend_err(pdev, "register iommu error\n");
        goto out_put_vdev;
    }

    return 0;

out_put_vdev:
    vfio_put_device(&vfio_vdavinci->vfio_dev);
    return ret;
}

STATIC void hw_vdavinci_vfio_remove(struct mdev_device *mdev)
{
    struct hw_vdavinci *vdavinci = get_mdev_drvdata(mdev_dev(mdev));
    struct hw_vfio_vdavinci *vfio_vdavinci = NULL;

    if (vdavinci == NULL) {
        return;
    }
    vfio_vdavinci = container_of(vdavinci->vdev.vfio_device,
                                 struct hw_vfio_vdavinci, vfio_dev);
    if (vfio_vdavinci == NULL) {
        vascend_err(vdavinci_to_dev(vdavinci), "can not get vfio vdavinci\n");
        return;
    }

    vfio_unregister_group_dev(&vfio_vdavinci->vfio_dev);
    vfio_put_device(&vfio_vdavinci->vfio_dev);
}
#else
#if (LINUX_VERSION_CODE <= KERNEL_VERSION(5,12,0))
STATIC int hw_vdavinci_create_ops(struct kobject *kobj, struct mdev_device *mdev)
{
    struct hw_vdavinci *vdavinci = NULL;

    vdavinci = hw_vdavinci_create(kobj, mdev);
    if (vdavinci == NULL) {
        return -EINVAL;
    }

    return 0;
}
#else
STATIC int hw_vdavinci_create_ops(struct mdev_device *mdev)
{
    struct hw_vdavinci *vdavinci = NULL;
    struct kobject *kobj = NULL;

    if (mdev == NULL || mdev->type == NULL) {
        return -EINVAL;
    }
    kobj = (struct kobject *)mdev->type;
    if (kobj == NULL || kobj->name == NULL) {
        return -EINVAL;
    }
    vdavinci = hw_vdavinci_create(kobj, mdev);
    if (vdavinci == NULL) {
        return -EINVAL;
    }

    return 0;
}
#endif /* KERNEL_VERSION(5,12,0) */

STATIC int hw_vdavinci_remove_ops(struct mdev_device *mdev)
{
    return hw_vdavinci_remove(mdev);
}

STATIC int hw_vdavinci_open_ops(struct mdev_device *mdev)
{
    return hw_vdavinci_open(mdev);
}

STATIC void hw_vdavinci_release_ops(struct mdev_device *mdev)
{
    hw_vdavinci_release(mdev);
}

STATIC ssize_t hw_vdavinci_read_ops(struct mdev_device *mdev,
                                    char __user *buf,
                                    size_t count, loff_t *ppos)
{
    return hw_vdavinci_read(mdev, buf, count, ppos);
}

STATIC ssize_t hw_vdavinci_write_ops(struct mdev_device *mdev,
                                     const char __user *buf,
                                     size_t count, loff_t *ppos)
{
    return hw_vdavinci_write(mdev, buf, count, ppos);
}

STATIC int hw_vdavinci_mmap_ops(struct mdev_device *mdev,
                                struct vm_area_struct *vma)
{
    return hw_vdavinci_mmap(mdev, vma);
}

STATIC long hw_vdavinci_ioctl_ops(struct mdev_device *mdev,
                                  unsigned int cmd,
                                  unsigned long arg)
{
    return hw_vdavinci_ioctl(mdev, cmd, arg);
}
#endif /* KERNEL_VERSION(6,1,0) */

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0))
struct mdev_driver hw_vdavinci_mdev_driver = {
    .device_api = VFIO_DEVICE_API_PCI_STRING,
    .driver = {
        .name = "vnpu_mdev",
        .owner = THIS_MODULE,
    },
    .probe = hw_vdavinci_vfio_probe,
    .remove = hw_vdavinci_vfio_remove,
    .get_available = available_instances_show,
    .show_description = description_show
};
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0))
struct mdev_driver hw_vdavinci_mdev_driver = {
    .driver = {
        .name = "vnpu_mdev",
        .owner = THIS_MODULE,
    },
    .probe = hw_vdavinci_vfio_probe,
    .remove = hw_vdavinci_vfio_remove,
};
#else
struct mdev_driver hw_vdavinci_mdev_driver = {
};
#endif /* KERNEL_VERSION(6,1,0) */

#if IS_ENABLED(CONFIG_VFIO_MDEV)
STATIC int vdavinci_set_device_ops(struct hw_dvt *dvt)
{
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0))
    dvt->drv->driver.dev_groups = get_hw_vdavinci_groups();
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0))
    dvt->drv->driver.dev_groups = get_hw_vdavinci_groups();
    dvt->supported_type_groups = dvt->groups;
#else
    struct mdev_parent_ops *vdavinci_mdev_ops = NULL;

    vdavinci_mdev_ops = kzalloc(sizeof(struct mdev_parent_ops), GFP_KERNEL);
    if (vdavinci_mdev_ops == NULL) {
        return -ENOMEM;
    }
    vdavinci_mdev_ops->create = hw_vdavinci_create_ops;
    vdavinci_mdev_ops->remove = hw_vdavinci_remove_ops;
#if (LINUX_VERSION_CODE < KERNEL_VERSION(5,15,0))
    vdavinci_mdev_ops->open = hw_vdavinci_open_ops;
    vdavinci_mdev_ops->release = hw_vdavinci_release_ops;
#else
    vdavinci_mdev_ops->open_device = hw_vdavinci_open_ops;
    vdavinci_mdev_ops->close_device = hw_vdavinci_release_ops;
#endif /* KERNEL_VERSION(5,15,0) */
    vdavinci_mdev_ops->read = hw_vdavinci_read_ops;
    vdavinci_mdev_ops->write = hw_vdavinci_write_ops;
    vdavinci_mdev_ops->mmap = hw_vdavinci_mmap_ops;
    vdavinci_mdev_ops->ioctl = hw_vdavinci_ioctl_ops;
    vdavinci_mdev_ops->supported_type_groups = dvt->groups;
    vdavinci_mdev_ops->mdev_attr_groups = get_hw_vdavinci_groups();
    dvt->vdavinci_mdev_ops = vdavinci_mdev_ops;
#endif /* KERNEL_VERSION(6,1,0) */

    return 0;
}
#endif /* CONFIG_VFIO_MDEV */

int vdavinci_register_device(struct device *dev,
                             struct hw_dvt *dvt,
                             const char *name)
{
    int ret = 0;
#if IS_ENABLED(CONFIG_VFIO_MDEV)
    const char *saved_name;

    ret = vdavinci_set_device_ops(dvt);
    if (ret != 0) {
        return ret;
    }
    mutex_lock(&mdev_register_lock);
    saved_name = dev->driver->name;
    dev->driver->name = name;
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0))
    ret = mdev_register_parent(&dvt->parent, dev, dvt->drv,
                               dvt->mdev_types, dvt->vdavinci_type_num * dvt->dev_num);
#elif (LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0))
    ret = mdev_register_device(dev, dvt->drv);
#else
    ret = mdev_register_device(dev, dvt->vdavinci_mdev_ops);
#endif /* KERNEL_VERSION(6,1,0) */
    dev->driver->name = saved_name;
    mutex_unlock(&mdev_register_lock);
#if (LINUX_VERSION_CODE < KERNEL_VERSION(6,1,0))
    if (ret != 0) {
        kfree(dvt->vdavinci_mdev_ops);
        dvt->vdavinci_mdev_ops = NULL;
    }
#endif /* KERNEL_VERSION(6,1,0) */
#endif /* CONFIG_VFIO_MDEV */

    return ret;
}

void vdavinci_unregister_device(struct device *dev, struct hw_dvt *dvt)
{
#if IS_ENABLED(CONFIG_VFIO_MDEV)
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(6,1,0))
    mdev_unregister_parent(&dvt->parent);
#else
    mdev_unregister_device(dev);
    kfree(dvt->vdavinci_mdev_ops);
    dvt->vdavinci_mdev_ops = NULL;
#endif
#endif /* CONFIG_VFIO_MDEV */
}

void vdavinci_init_iova_domain(struct iova_domain *iovad)
{
    if (iovad == NULL) {
        return;
    }
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4,14,0))
    init_iova_domain(iovad, PAGE_SIZE, 1);
#else
    init_iova_domain(iovad, PAGE_SIZE, 1,
                     DMA_BIT_MASK(DOMAIN_DMA_BIT_MASK_32) >> PAGE_SHIFT);
#endif
}
