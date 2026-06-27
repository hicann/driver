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

#ifndef _VDAVINCI_H_
#define _VDAVINCI_H_

void hw_vdavinci_unregister_iodev(struct hw_vdavinci *vdavinci);
int hw_vdavinci_register_iodev(struct hw_vdavinci *vdavinci,
                               gpa_t addr, int len, int index);
void vdavinci_module_exit(void);

#endif 