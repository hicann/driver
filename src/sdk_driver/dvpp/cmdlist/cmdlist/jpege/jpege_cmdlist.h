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

#ifndef DVPP_JPEGE_CMDLIST_H
#define DVPP_JPEGE_CMDLIST_H

#include "dvpp_cmdlist.h"

#ifdef __cplusplus
extern "C" {
#endif

void jpege_cmdlist_engine_register(void);
void jpege_cmdlist_engine_unregister(void);

#ifdef __cplusplus
}
#endif
#endif // #ifndef DVPP_JPEGE_CMDLIST_H