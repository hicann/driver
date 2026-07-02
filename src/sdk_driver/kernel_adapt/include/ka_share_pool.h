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

#ifndef KA_SHARE_POOL_H
#define KA_SHARE_POOL_H

#include <linux/share_pool.h>

#define KA_MMAP_SHARE_POOL_RO_START MMAP_SHARE_POOL_RO_START
#define KA_MMAP_SHARE_POOL_RO_END MMAP_SHARE_POOL_RO_END

#define ka_mg_sp_make_share_u2k(uva, size, pid) mg_sp_make_share_u2k(uva, size, pid)
#define ka_mg_sp_unshare(va, size, id) mg_sp_unshare(va, size, id)
#endif