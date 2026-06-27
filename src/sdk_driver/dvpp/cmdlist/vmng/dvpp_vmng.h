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
#ifndef DVPP_VMNG_VMNG_H
#define DVPP_VMNG_VMNG_H

#include "ka_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DVPP_VMNG_DEVICE_NUM_MAX 1124  // dev_id 0~63是物理设备, 100~1123为切分设备

int32_t dvpp_vmng_init(void);
int32_t dvpp_vmng_uninit(void);

#ifdef __cplusplus
}
#endif
#endif