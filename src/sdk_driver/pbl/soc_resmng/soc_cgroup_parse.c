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
#include "ka_common_pub.h"
#include "ka_errno_pub.h"
#include "ka_fs_pub.h"
#include "ka_kernel_def_pub.h"

#include "soc_resmng_log.h"
#include "soc_cgroup_parse.h"

#define CGOUP_CPUSET_PATH "/sys/fs/cgroup/cpuset/cpuset.cpus"
#define CPU_INFO_SIZE 256
#define CPU_BITMAP_LEN 32
#ifndef EMU_ST
STATIC int dbl_read_cpuset_content(const char *file_path, char *buf)
{
    ka_file_t *file = NULL;
    loff_t pos = 0;
    int len;

    /* read cpuset info from file */
    file = ka_fs_filp_open(file_path, KA_O_RDONLY, 0);
    if (KA_IS_ERR(file)) {
        soc_err("Failed to ka_fs_filp_open. \n");
        return -ENOENT;
    }
    len = ka_fs_kernel_read(file, buf, CPU_INFO_SIZE - 1, &pos);
    ka_fs_filp_close(file, NULL);
    if (len <= 0) {
        soc_err("Failed to get length. (len=%d)\n", len);
        return -ENOENT;
    }
    return 0;
}

STATIC int dbl_parse_cpumask_to_bitmap(const char *buf, u32 *available_bitmap)
{
    ka_cpumask_var_t cpumask;
    u32 i = 0;
    int ret;

    if (!ka_base_zalloc_cpumask_var(&cpumask, KA_GFP_KERNEL)) {
        soc_err("Failed to ka_base_zalloc_cpumask_var. \n");
        return -ENOMEM;
    }
    ret = ka_base_cpulist_parse(buf, cpumask);
    if (ret != 0) {
        soc_err("Failed to parse cpulist. (ret=%d)\n", ret);
        ka_base_free_cpumask_var(cpumask);
        return ret;
    }
    ka_base_for_each_cpu(i, cpumask)
    {
        *available_bitmap |= (1U << i);
    }
    ka_base_free_cpumask_var(cpumask);
    return 0;
}

STATIC int dbl_get_available_cpumask(const char *file_path, u32 *available_bitmap)
{
    char buf[CPU_INFO_SIZE] = {0};
    int ret;

    ret = dbl_read_cpuset_content(file_path, buf);
    if (ret != 0) {
        return ret;
    }
    return dbl_parse_cpumask_to_bitmap(buf, available_bitmap);
}
#endif

void dbl_get_available_cpu(u64 phy_bitmap, u32 *number, u64 *bitmap)
{
    unsigned long bitmap_tmp = 0;
    u32 available_bitmap = 0;
    int ret;

    if (number == NULL) {
        soc_err("Input number NULL.\n");
        return;
    }

    if (bitmap == NULL) {
        soc_err("Input bitmap is NULL.\n");
        return;
    }

#ifndef EMU_ST
    ret = dbl_get_available_cpumask(CGOUP_CPUSET_PATH, &available_bitmap);
    if (ret != 0) {
        soc_err("Failed to get available cpumask. (ret=%d)\n", ret);
        return;
    }
#endif

    (*bitmap) = phy_bitmap & available_bitmap;
    bitmap_tmp = (unsigned long)(*bitmap);
    *number = ka_base_bitmap_weight(&bitmap_tmp, CPU_BITMAP_LEN);
    return;
}
KA_EXPORT_SYMBOL_GPL(dbl_get_available_cpu);
