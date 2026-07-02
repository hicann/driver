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
#include "ka_base_pub.h"
#include "ka_fs_pub.h"
#include "ka_compiler_pub.h"
#include "ka_kernel_def_pub.h"

#include "ka_memory_mng.h"
#include "ka_module_init.h"
#include "ka_proc_fs.h"
#include "ka_base_pub.h"

#define KA_PROC_FS_NAME_LEN 32
#define KA_PROC_FS_MODE 0444

static ka_proc_dir_entry_t *ka_task_entry = NULL;

STATIC int ka_enable_mem_record_show(ka_seq_file_t *seq, void *offset)
{
    ka_fs_seq_printf(seq, "%d\n", (ka_is_enable_mem_record() == true));
    return 0;
}

STATIC int ka_enable_mem_record_ops_open(ka_inode_t *inode, ka_file_t *file)
{
    return ka_fs_single_open(file, ka_enable_mem_record_show, ka_base_pde_data(inode));
}

#define MEM_RECORD_DISABLE 0
STATIC ssize_t ka_enable_record_ops_write(ka_file_t *filp, const char __ka_user *ubuf, size_t count, loff_t *ppos)
{
    char ch[2] = {0}; /* 2 bytes long */
    long val;

    if ((ppos == NULL) || (*ppos != 0) || (count != sizeof(ch)) || (ubuf == NULL)) {
        return -EINVAL;
    }
    if (ka_base_copy_from_user(ch, ubuf, count)) {
        return -ENOMEM;
    }
    ch[count - 1] = '\0';
    if (ka_base_kstrtol(ch, 10, &val)) {
        return -EFAULT;
    }
    ka_mem_record_status_reset(val != MEM_RECORD_DISABLE);
    ka_debug("Enable_memory.(enable_is_true=%d).\n", (ka_is_enable_mem_record() == true));

    return (ssize_t)count;
}

STATIC int ka_get_alloc_mem_desc_open(ka_inode_t *inode, ka_file_t *file)
{
    return ka_fs_single_open(file, ka_mem_stats_show, ka_base_pde_data(inode));
}

static const ka_procfs_ops_t ka_enable_mem_desc_ops = {
    ka_fs_init_pf_owner(KA_THIS_MODULE) ka_fs_init_pf_open(ka_enable_mem_record_ops_open)
        ka_fs_init_pf_read(ka_fs_seq_read) ka_fs_init_pf_write(ka_enable_record_ops_write)
            ka_fs_init_pf_lseek(ka_fs_seq_lseek) ka_fs_init_pf_release(ka_fs_single_release)};

static const ka_procfs_ops_t ka_mem_ops = {ka_fs_init_pf_owner(KA_THIS_MODULE) ka_fs_init_pf_open(
    ka_get_alloc_mem_desc_open) ka_fs_init_pf_read(ka_fs_seq_read) ka_fs_init_pf_lseek(ka_fs_seq_lseek)
                                               ka_fs_init_pf_release(ka_fs_single_release)};

void ka_proc_fs_init(void)
{
    ka_task_entry = ka_fs_proc_mkdir("ka", NULL);
    if (ka_task_entry != NULL) {
        ka_fs_proc_create_data("ka_enable_mem_record", KA_PROC_FS_MODE, ka_task_entry, &ka_enable_mem_desc_ops,
                               (void *)(uintptr_t)ka_is_enable_mem_record());
        ka_fs_proc_create_data("ka_mem_stats", KA_PROC_FS_MODE, ka_task_entry, &ka_mem_ops,
                               (void *)(uintptr_t)ka_is_enable_mem_record());
    }
}

void ka_proc_fs_uninit(void)
{
    if (ka_task_entry != NULL) {
        ka_fs_remove_proc_subtree("ka", NULL);
    }
}
