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

#include <linux/fs.h>
#include "securec.h"
#include "ka_fs_pub.h"
#include "ka_memory_pub.h"

ssize_t ka_fs_kernel_read(ka_file_t *file, void *buf, size_t count, loff_t *pos)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
    return kernel_read(file, buf, count, pos);
#else
    return kernel_read(file, *pos, (char *)buf, count);
#endif
}
EXPORT_SYMBOL_GPL(ka_fs_kernel_read);

ssize_t ka_fs_kernel_write(ka_file_t *file, const void *buf, size_t count, loff_t *pos)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
    return kernel_write(file, buf, count, pos);
#else
    return kernel_write(file, (char *)buf, count, *pos);
#endif
}
EXPORT_SYMBOL_GPL(ka_fs_kernel_write);

#ifndef EMU_ST
ssize_t ka_fs_kernel_write_ret(struct file *file, const void *buf, size_t count, loff_t *pos)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 18, 0)
    return __kernel_write(file, buf, count, pos);
#else
    return kernel_write(file, buf, count, *pos);
#endif
}
EXPORT_SYMBOL_GPL(ka_fs_kernel_write_ret);
#endif

int ka_fs_vfs_getattr(ka_path_t *path, ka_kstat_t *stat, u32 request_mask, unsigned int query_flags)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 11, 0)
    return vfs_getattr(path, stat, request_mask, query_flags);
#else
    return vfs_getattr(path, stat);
#endif
}
EXPORT_SYMBOL_GPL(ka_fs_vfs_getattr);

ssize_t ka_fs_read_file(ka_file_t *file, loff_t *pos, char *addr, size_t count)
{
    ssize_t len;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
    len = kernel_read(file, addr, count, pos);
#else
    char __user *buf = (char __user *)addr;
    mm_segment_t old_fs;

    old_fs = get_fs();
    set_fs(get_ds()); /* lint !e501 */ /* kernel source */
    len = vfs_read(file, buf, count, pos);
    set_fs(old_fs);
#endif

    return len;
}
EXPORT_SYMBOL_GPL(ka_fs_read_file);

int ka_fs_get_file_kstat(ka_kstat_t *src_stat, const char *path)
{
    int ret = 0;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 20, 0)
    ka_path_t kernel_path;

    ret = ka_fs_kern_path(path, KA_LOOKUP_FOLLOW, &kernel_path);
    if (ret != 0) {
        return ret;
    }
    ret = ka_fs_vfs_getattr(&kernel_path, src_stat, KA_STATX_BASIC_STATS, KA_AT_NO_AUTOMOUNT);
    ka_fs_path_put(&kernel_path);
#else
    ka_mm_segment_t old_fs;

    old_fs = ka_fs_get_fs();
    ka_fs_set_fs(KERNEL_DS);
    ret = vfs_stat(path, src_stat);
    ka_fs_set_fs(old_fs);
#endif
    return ret;
}
EXPORT_SYMBOL_GPL(ka_fs_get_file_kstat);