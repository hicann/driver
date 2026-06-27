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
#include "ka_kernel_def_pub.h"
#include "ka_errno_pub.h"
#include "ka_fs_pub.h"

#include "pbl/pbl_runenv_config.h"
#include "runenv_config_module.h"

int dbl_runenv_get_drv_version(char *buf, u32 len)
{
    struct file *file = NULL;
    ssize_t file_size;
    ssize_t read_size;
    loff_t pos = 0;

    if (buf == NULL) {
        recfg_err("Buff is null.\n");
        return -EINVAL;
    }

    file = ka_fs_filp_open("/etc/sys_version.conf", KA_O_RDONLY, 0);
    if (KA_IS_ERR_OR_NULL(file)) {
        recfg_err("Open file:/etc/sys_version.conf failed. (file=%pK; errcode=%ld)\n", file, KA_PTR_ERR(file));
        return -EINVAL;
    }

    file_size = (ssize_t)ka_fs_i_size_read(ka_fs_file_inode(file));
    if ((file_size == 0) || (file_size >= (ssize_t)len)) {
        recfg_err("File size is invalid. (file_size=%lu; buf_len=%u)\n", file_size, len);
        goto file_close;
    }

    read_size = ka_fs_kernel_read(file, buf, (ssize_t)(len - 1), &pos);
    if (read_size != file_size) {
        recfg_err("Read file:/etc/sys_version.conf failed. (ret=%lu)\n", read_size);
        goto file_close;
    }

    ka_fs_filp_close(file, NULL);
    return 0;

file_close:
    ka_fs_filp_close(file, NULL);
    return -EINVAL;
}
KA_EXPORT_SYMBOL(dbl_runenv_get_drv_version);
