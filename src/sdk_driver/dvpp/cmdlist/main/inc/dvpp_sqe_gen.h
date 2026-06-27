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

#ifndef DVPP_SQE_GEN_H
#define DVPP_SQE_GEN_H

#include "ka_type.h"
#include "dvpp_cmdlist_define.h"
#include "dvpp_vpc_pipe.h"

int32_t dvpp_gen_vpc_sqe(dvpp_cmdlist_param_t *param, void *sqe);

#endif // #ifndef DVPP_SQE_GEN_H
