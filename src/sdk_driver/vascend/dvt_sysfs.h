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

#ifndef _DVT_SYSFS_H_
#define _DVT_SYSFS_H_

const ka_attribute_group_t **get_hw_vdavinci_groups(void);
ssize_t available_instances_ops(ka_device_t *dev, const char *name, char *buf);
ssize_t description_ops(ka_device_t *dev, const char *name, char *buf);
ssize_t device_api_ops(ka_device_t *dev, char *buf);
ssize_t vfg_id_store_ops(ka_device_t *dev, const char *name,
                         const char *buf, size_t count);
#endif
