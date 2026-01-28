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
#include "ka_fs_pub.h"
#include "ka_memory_pub.h"
#include "ka_ioctl_pub.h"
#include "ka_kernel_def_pub.h"
#include "rmo_auto_init.h"
#include "pbl/pbl_task_ctx.h"

#include "pbl/pbl_davinci_api.h"
#include "rmo_fops.h"

static int rmo_open(ka_inode_t *inode, ka_file_t *file)
{
    struct task_id_entity *task = NULL;

    task = (struct task_id_entity *)ka_mm_kzalloc(sizeof(struct task_id_entity), KA_GFP_KERNEL | __KA_GFP_ACCOUNT);
    if (task == NULL) {
#ifndef EMU_ST
        rmo_err("Failed to ka_mm_kzalloc task_id_entity.\n");
        return -ENOMEM;
#endif
    }

    task->tgid = current->tgid;
    task_get_start_time_by_tgid(current->tgid, &task->start_time);
    file->private_data = (void *)task;

    rmo_info("Open. (tgid=%d)\n", current->tgid);
    return 0;
}

static int rmo_release(ka_inode_t *inode, ka_file_t *file)
{
    struct task_id_entity *task = (struct task_id_entity *)(file->private_data);
    if (task != NULL) {
        module_feature_auto_uninit_task(0, task->tgid, (void*)&(task->start_time));
        rmo_info("Release. (tgid=%d)\n", task->tgid);
        ka_mm_kfree(task);
        file->private_data = NULL;
    }

    return 0;
}

static int (* rmo_ioctl_handler[RMO_MAX_CMD])(u32 cmd, unsigned long arg) = {NULL, };

void rmo_register_ioctl_cmd_func(int nr, int (*fn)(u32 cmd, unsigned long arg))
{
    rmo_ioctl_handler[nr] = fn;
}

static long rmo_ioctl(ka_file_t *file, u32 cmd, unsigned long arg)
{
    if (arg == 0) {
        return -EINVAL;
    }
    if (_KA_IOC_NR(cmd) >= RMO_MAX_CMD) {
        rmo_err("The command is invalid, which is out of range. (cmd=%u)\n", _KA_IOC_NR(cmd));
        return -EINVAL;
    }

    if (rmo_ioctl_handler[_KA_IOC_NR(cmd)] == NULL) {
        rmo_warn("The command is not support. (cmd=%u)\n", _KA_IOC_NR(cmd));
        return -EOPNOTSUPP;
    }

    return rmo_ioctl_handler[_KA_IOC_NR(cmd)](cmd, arg);
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 3, 0)
static int rmo_mremap(ka_vm_area_struct_t * area)
{
    return -ENOTSUPP;
}
#endif

static ka_vm_operations_struct_t rmo_vm_ops = {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 3, 0)
    .mremap = rmo_mremap,
#endif
};

static int rmo_mmap(ka_file_t *file, ka_vm_area_struct_t *vma)
{
    vma->vm_ops = &rmo_vm_ops;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 3, 0)
    vm_flags_set(vma, vma->vm_flags | KA_VM_LOCKED | KA_VM_DONTEXPAND | KA_VM_DONTDUMP | KA_VM_DONTCOPY | KA_VM_IO);
    if (!(vma->vm_flags & KA_VM_WRITE)) {
        vm_flags_clear(vma, VM_MAYWRITE);
    }
#else
    vma->vm_flags |= KA_VM_DONTEXPAND;
    vma->vm_flags |= KA_VM_LOCKED;
    vma->vm_flags |= KA_VM_PFNMAP;
    vma->vm_flags |= KA_VM_DONTDUMP;
    vma->vm_flags |= KA_VM_DONTCOPY;
    vma->vm_flags |= KA_VM_IO;
    if (!(vma->vm_flags & KA_VM_WRITE)) {
        vma->vm_flags &= ~VM_MAYWRITE;
    }
#endif
    vma->vm_private_data = (void *)(uintptr_t)RMO_VMA_MAP_MAGIC_VERIFY;

    return 0;
}

static ka_file_operations_t rmo_fops = {
    .owner = KA_THIS_MODULE,
    .open = rmo_open,
    .release = rmo_release,
    .unlocked_ioctl = rmo_ioctl,
    .mmap = rmo_mmap,
};

int rmo_fops_init(void)
{
    int ret;

    ret = drv_davinci_register_sub_module(RMO_CHAR_DEV_NAME, &rmo_fops);
    if (ret != 0) {
        rmo_err("Module register fail. (ret=%d)\n", ret);
        return ret;
    }

    return 0;
}

void rmo_fops_uninit(void)
{
    (void)drv_ascend_unregister_sub_module(RMO_CHAR_DEV_NAME);
}

