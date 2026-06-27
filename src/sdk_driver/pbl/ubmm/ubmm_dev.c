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

#include "ubmm_dev.h"
#include "ubmm_log.h"

#include "ka_task_pub.h"
#include "ka_list_pub.h"
#include "ka_errno_pub.h"
#include "ka_kernel_def_pub.h"
#include "pbl_mem_alloc_interface.h"
#include "pbl_uda.h"

typedef struct ubmem_dev_task_info {
    int tgid;
    enum ubmem_dev_task_status status;
    ka_list_head_t node;
} ubmem_dev_task_info_t;

typedef struct ubmem_dev_info {
    u32 udevid;
    enum ubmem_dev_status status;
    ka_list_head_t task_head;
    ka_list_head_t node;
} ubmem_dev_info_t;

static KA_TASK_DEFINE_MUTEX(g_ubmem_dev_mutex);
static KA_LIST_HEAD(g_ubmem_dev_head);

static bool ubmem_dev_udevid_invalid(u32 udevid)
{
    return (udevid >= uda_get_udev_max_num());
}

static ubmem_dev_info_t *ubmem_dev_find_device(u32 udevid)
{
    ubmem_dev_info_t *dev = NULL;

    ka_list_for_each_entry(dev, &g_ubmem_dev_head, node) {
        if (dev->udevid == udevid) {
            return dev;
        }
    }

    return NULL;
}

static ubmem_dev_task_info_t *ubmem_dev_find_task(ubmem_dev_info_t *dev, int tgid)
{
    ubmem_dev_task_info_t *task_info = NULL;

    ka_list_for_each_entry(task_info, &dev->task_head, node) {
        if (task_info->tgid == tgid) {
            return task_info;
        }
    }

    return NULL;
}

static ubmem_dev_info_t *ubmem_dev_create_device(u32 udevid)
{
    ubmem_dev_info_t *dev = (ubmem_dev_info_t *)dbl_kzalloc(sizeof(ubmem_dev_info_t), KA_GFP_KERNEL | __KA_GFP_ACCOUNT);

    if (dev == NULL) {
        return NULL;
    }

    dev->udevid = udevid;
    dev->status = UBMEM_DEV_STATUS_NORMAL;
    KA_INIT_LIST_HEAD(&dev->task_head);
    ka_list_add_tail(&dev->node, &g_ubmem_dev_head);

    return dev;
}

static int ubmem_dev_add_task_locked(u32 udevid, int tgid)
{
    ubmem_dev_info_t *dev = NULL;
    ubmem_dev_task_info_t *task_info = NULL;

    dev = ubmem_dev_find_device(udevid);
    if (dev == NULL) {
        dev = ubmem_dev_create_device(udevid);
        if (dev == NULL) {
            ubmm_err("Create device node failed. (udevid=%u)\n", udevid);
            return -ENOMEM;
        }
    }

    task_info = ubmem_dev_find_task(dev, tgid);
    if (task_info != NULL) {
        return -EEXIST;
    }

    task_info = (ubmem_dev_task_info_t *)dbl_kzalloc(sizeof(*task_info), KA_GFP_KERNEL | __KA_GFP_ACCOUNT);
    if (task_info == NULL) {
        ubmm_err("Create task node failed. (udevid=%u; tgid=%d)\n", udevid, tgid);
        return -ENOMEM;
    }

    task_info->tgid = tgid;
    task_info->status = UBMEM_DEV_TASK_INUSE;
    ka_list_add_tail(&task_info->node, &dev->task_head);

    return 0;
}

int ubmem_dev_add_task(u32 udevid, int tgid)
{
    int ret;

    if ((tgid < 0) || ubmem_dev_udevid_invalid(udevid)) {
        ubmm_err("Invalid input. (udevid=%u; max=%u; tgid=%d)\n", udevid, uda_get_udev_max_num(), tgid);
        return -EINVAL;
    }

    ka_task_mutex_lock(&g_ubmem_dev_mutex);
    ret = ubmem_dev_add_task_locked(udevid, tgid);
    ka_task_mutex_unlock(&g_ubmem_dev_mutex);

    return ret;
}
KA_EXPORT_SYMBOL_GPL(ubmem_dev_add_task);

static int ubmem_dev_delete_task_locked(u32 udevid, int tgid)
{
    ubmem_dev_info_t *dev = NULL;
    ubmem_dev_task_info_t *task_info = NULL;

    dev = ubmem_dev_find_device(udevid);
    if (dev == NULL) {
        ubmm_err("Device not found. (udevid=%u)\n", udevid);
        return -ENOENT;
    }

    task_info = ubmem_dev_find_task(dev, tgid);
    if (task_info == NULL) {
        ubmm_err("Task not found. (udevid=%u; tgid=%d)\n", udevid, tgid);
        return -ESRCH;
    }

    ka_list_del(&task_info->node);
    dbl_kfree(task_info);

    return 0;
}

static bool ubmem_dev_task_is_idle_locked(u32 udevid)
{
    ubmem_dev_info_t *dev = ubmem_dev_find_device(udevid);
    ubmem_dev_task_info_t *task_info = NULL;

    if (dev == NULL) {
        return true;
    }

    ka_list_for_each_entry(task_info, &dev->task_head, node) {
        if (task_info->status == UBMEM_DEV_TASK_INUSE) {
            return false;
        }
    }

    return true;
}

int ubmem_dev_delete_task(u32 udevid, int tgid, bool *is_idle)
{
    int ret;

    if ((tgid < 0) || ubmem_dev_udevid_invalid(udevid) || (is_idle == NULL)) {
        ubmm_err("Invalid input. (udevid=%u; max=%u; tgid=%d)\n", udevid, uda_get_udev_max_num(), tgid);
        return -EINVAL;
    }

    ka_task_mutex_lock(&g_ubmem_dev_mutex);
    ret = ubmem_dev_delete_task_locked(udevid, tgid);
    if (ret == 0) {
        *is_idle =  ubmem_dev_task_is_idle_locked(udevid);
    }
    ka_task_mutex_unlock(&g_ubmem_dev_mutex);

    return ret;
}
KA_EXPORT_SYMBOL_GPL(ubmem_dev_delete_task);

bool ubmem_dev_task_is_idle(u32 udevid)
{
    bool is_idle = false;

    if (ubmem_dev_udevid_invalid(udevid)) {
        ubmm_err("Invalid udevid. (udevid=%u; max=%u)\n", udevid, uda_get_udev_max_num());
        return false;
    }

    ka_task_mutex_lock(&g_ubmem_dev_mutex);
    is_idle = ubmem_dev_task_is_idle_locked(udevid);
    ka_task_mutex_unlock(&g_ubmem_dev_mutex);

    return is_idle;
}
KA_EXPORT_SYMBOL_GPL(ubmem_dev_task_is_idle);

static bool ubmem_dev_is_fault_locked(u32 udevid)
{
    ubmem_dev_info_t *dev = ubmem_dev_find_device(udevid);

    if (dev == NULL) {
        return false;
    }

    return (dev->status == UBMEM_DEV_STATUS_FAULT);
}

bool ubmem_dev_is_fault(u32 udevid)
{
    bool is_fault = false;

    if (ubmem_dev_udevid_invalid(udevid)) {
        ubmm_err("Invalid udevid. (udevid=%u; max=%u)\n", udevid, uda_get_udev_max_num());
        return false;
    }

    ka_task_mutex_lock(&g_ubmem_dev_mutex);
    is_fault = ubmem_dev_is_fault_locked(udevid);
    ka_task_mutex_unlock(&g_ubmem_dev_mutex);

    return is_fault;
}
KA_EXPORT_SYMBOL_GPL(ubmem_dev_is_fault);

static int ubmem_dev_set_task_status_locked(u32 udevid, int tgid, enum ubmem_dev_task_status status)
{
    ubmem_dev_info_t *dev = NULL;
    ubmem_dev_task_info_t *task_info = NULL;

    dev = ubmem_dev_find_device(udevid);
    if (dev == NULL) {
        ubmm_err("Device not found. (udevid=%u)\n", udevid);
        return -ENOENT;
    }

    if (tgid == UBMEM_DEV_TASK_ALL) {
        ka_list_for_each_entry(task_info, &dev->task_head, node) {
            task_info->status = status;
        }
        return 0;
    }

    task_info = ubmem_dev_find_task(dev, tgid);
    if (task_info == NULL) {
        ubmm_err("Task not found. (udevid=%u; tgid=%d)\n", udevid, tgid);
        return -ENOENT;
    }

    task_info->status = status;

    return 0;
}

int ubmem_dev_set_task_status(u32 udevid, int tgid, enum ubmem_dev_task_status status, bool *is_idle)
{
    int ret;

    if ((status != UBMEM_DEV_TASK_UNUSE) && (status != UBMEM_DEV_TASK_INUSE)) {
        ubmm_err("Invalid status. (udevid=%u; tgid=%d; status=%d)\n", udevid, tgid, status);
        return -EINVAL;
    }

    if (ubmem_dev_udevid_invalid(udevid) || (is_idle == NULL)) {
        ubmm_err("Invalid udevid or is_idle ptr. (udevid=%u; max=%u)\n", udevid, uda_get_udev_max_num());
        return -EINVAL;
    }

    ka_task_mutex_lock(&g_ubmem_dev_mutex);
    ret = ubmem_dev_set_task_status_locked(udevid, tgid, status);
    if (ret == 0) {
        *is_idle =  ubmem_dev_task_is_idle_locked(udevid);
    }
    ka_task_mutex_unlock(&g_ubmem_dev_mutex);

    return ret;
}
KA_EXPORT_SYMBOL_GPL(ubmem_dev_set_task_status);

static int ubmem_dev_set_dev_status_locked(u32 udevid, enum ubmem_dev_status status)
{
    ubmem_dev_info_t *dev = NULL;

    dev = ubmem_dev_find_device(udevid);
    if (dev == NULL) {
        dev = ubmem_dev_create_device(udevid);
        if (dev == NULL) {
            ubmm_err("Create device node failed. (udevid=%u)\n", udevid);
            return -ENOMEM;
        }
    }

    dev->status = status;
    return 0;
}

int ubmem_dev_set_dev_status(u32 udevid, enum ubmem_dev_status status)
{
    int ret;

    if ((status != UBMEM_DEV_STATUS_NORMAL) && (status != UBMEM_DEV_STATUS_FAULT)) {
        ubmm_err("Invalid status. (udevid=%u; status=%d)\n", udevid, status);
        return -EINVAL;
    }

    if (ubmem_dev_udevid_invalid(udevid)) {
        ubmm_err("Invalid udevid. (udevid=%u; max=%u)\n", udevid, uda_get_udev_max_num());
        return -EINVAL;
    }

    ka_task_mutex_lock(&g_ubmem_dev_mutex);
    ret = ubmem_dev_set_dev_status_locked(udevid, status);
    ka_task_mutex_unlock(&g_ubmem_dev_mutex);

    return ret;
}
KA_EXPORT_SYMBOL_GPL(ubmem_dev_set_dev_status);

int ubmem_dev_init(void)
{
    ubmm_info("ubmem dev init success\n");
    return 0;
}

void ubmem_dev_exit(void)
{
    ubmem_dev_info_t *dev = NULL;
    ubmem_dev_info_t *dev_next = NULL;

    ka_task_mutex_lock(&g_ubmem_dev_mutex);

    ka_list_for_each_entry_safe(dev, dev_next, &g_ubmem_dev_head, node) {
        ubmem_dev_task_info_t *task_info = NULL;
        ubmem_dev_task_info_t *task_info_next = NULL;

        ka_list_for_each_entry_safe(task_info, task_info_next, &dev->task_head, node) {
            ka_list_del(&task_info->node);
            dbl_kfree(task_info);
        }

        ka_list_del(&dev->node);
        dbl_kfree(dev);
    }

    ka_task_mutex_unlock(&g_ubmem_dev_mutex);
    ubmm_info("ubmem dev exit success\n");
}
