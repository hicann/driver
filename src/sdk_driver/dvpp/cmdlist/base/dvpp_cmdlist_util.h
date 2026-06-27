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
#ifndef DVPP_CMDLIST_UTIL_H
#define DVPP_CMDLIST_UTIL_H

#ifdef __KERNEL__
#include "ka_type.h"
#else
#include <stdint.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

int64_t dvpp_cmdlist_get_usec(void);

#ifdef __cplusplus
}
#endif

#endif // #ifndef DVPP_CMDLIST_UTIL_H