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

#ifndef SOC_INTERFACE_ADAPT_H
#define SOC_INTERFACE_ADAPT_H

#include "ascend_kernel_hal.h"

int hal_kernel_get_pg_info_adapt(unsigned int dev_id, HAL_PG_INFO_TYPE info_type, char *data, unsigned int size,
                                 unsigned int *ret_size);
#endif