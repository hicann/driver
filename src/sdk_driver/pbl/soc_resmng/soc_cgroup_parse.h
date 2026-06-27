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

#ifndef SOC_CGOUP_PARSE_H
#define SOC_CGOUP_PARSE_H
#ifdef STATIC_SKIP
#define STATIC
#else
#define STATIC static
#endif

#include "ka_memory_pub.h"

/**
 * To get the num and bitmap of all kind of cpuset, the following interfaces are provided in dbl,
 * AICPU: soc_resmng_dev_get_mia_res_ex(devid, MIA_CPU_DEV_ACPU, &info);
 * DataCPU: soc_resmng_dev_get_mia_res_ex(devid, MIA_CPU_DEV_DCPU, &info);
 * CrtlCPU: soc_resmng_dev_get_mia_res_ex(devid, MIA_CPU_DEV_CCPU, &info);
 * Cgroup/cpuset: dbl_get_available_cpu(u32 phy_bitmap, u32 *number, u32 *bitmap);
 */

/**
* @driver base layer interface
* @description: Obtain the available cgroup/cpuset/cpuset.cpus in current env
* @attention  : For device
* @param [in] : phy_bitmap(u64), cpu bitmap of phy_device
* @param [out]: number(u32 *), the available cpu num of current env
                bitmap(u64 *), the available cpu bitmap of current env
* @return     : void
*/
void dbl_get_available_cpu(u64 phy_bitmap, u32 *number, u64 *bitmap);

#endif
