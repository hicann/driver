/*
 * Copyright (c) 2025 Huawei Technologies Co., Ltd. All rights reserved.
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

#ifndef DMS_BBOX_DUMP_FEATURE_CHECK_H
#define DMS_BBOX_DUMP_FEATURE_CHECK_H

#include "dms_bbox_dump_feature.h"
#include "ascend_hal_error.h"

struct bbox_chip_features {
    const enum bbox_feature_id *features;
    unsigned int feature_count;
};

void bbox_feature_reset(void);
const struct bbox_chip_features *bbox_get_chip_features(unsigned int chip_type);
int bbox_has_feature(unsigned int dev_id, enum bbox_feature_id feature);
drvError_t bbox_feature_init_by_devid(unsigned int dev_id);
unsigned long long bbox_get_feature_bitmap(unsigned int dev_id);

#endif /* DMS_BBOX_DUMP_FEATURE_CHECK_H */
