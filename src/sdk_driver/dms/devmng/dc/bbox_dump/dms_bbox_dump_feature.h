/*
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef DMS_BBOX_DUMP_FEATURE_H
#define DMS_BBOX_DUMP_FEATURE_H

#include "bbox_dump_feature_def.h"

static inline int bbox_feature_array_has(const enum bbox_feature_id *features, unsigned int feature_count,
                                         enum bbox_feature_id feature)
{
    unsigned int i;

    for (i = 0; i < feature_count; i++) {
        if (features[i] == feature) {
            return 1;
        }
    }
    return 0;
}

#endif
