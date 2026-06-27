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
#include "ascend_dev_num.h"
#include "msg_chan_main.h"

#ifndef KA_BITS_PER_LONG_LONG
#define KA_BITS_PER_LONG_LONG 64
#endif

#define SET_BIT_64(x, y) ((x) |= ((u64)0x01 << (y)))
#define CLR_BIT_64(x, y) ((x) &= (~((u64)0x01 << (y))))
#define CHECK_BIT_64(x, y) ((x) & ((u64)0x01 << (y)))

u64 g_prob_device_bitmap[ASCEND_DEV_MAX_NUM / KA_BITS_PER_LONG_LONG + 1];
void devdrv_set_probe_dev_bitmap(u32 devid)
{
    SET_BIT_64(g_prob_device_bitmap[devid / KA_BITS_PER_LONG_LONG], devid % KA_BITS_PER_LONG_LONG);
}
KA_EXPORT_SYMBOL(devdrv_set_probe_dev_bitmap);

void devdrv_clr_probe_dev_bitmap(u32 devid)
{
    CLR_BIT_64(g_prob_device_bitmap[devid / KA_BITS_PER_LONG_LONG], devid % KA_BITS_PER_LONG_LONG);
}
KA_EXPORT_SYMBOL(devdrv_clr_probe_dev_bitmap);

u64 devdrv_check_probe_dev_bitmap(u32 devid)
{
    return CHECK_BIT_64(g_prob_device_bitmap[devid / KA_BITS_PER_LONG_LONG], devid % KA_BITS_PER_LONG_LONG);
}
KA_EXPORT_SYMBOL(devdrv_check_probe_dev_bitmap);
