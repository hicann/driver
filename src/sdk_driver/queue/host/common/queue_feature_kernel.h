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

#ifndef QUEUE_FEATURE_KERNEL_H
#define QUEUE_FEATURE_KERNEL_H

/*
 * queue feature ID definitions
 * Used by both kernel queue and user-space tools
 */

enum queue_feature_id {
    QUEUE_FEATURE_PLATFORM_MINI_DMA = 0,
    QUEUE_FEATURE_SURPORT_PCIE_DMA_SVA,
    QUEUE_FEATURE_SHARE_LOG,
    QUEUE_FEATURE_KA_ALLOC_INTERFACE,
    QUEUE_FEATURE_HOST_LOG,

    QUEUE_FEATURE_MAX
};

/*
 * Check if a feature exists in the feature array
 * @param features: feature array
 * @param feature_count: number of elements in feature array
 * @param feature: feature ID to check
 * @return: 1 if feature exists, 0 if not
 */
static inline int queue_feature_array_has(const enum queue_feature_id *features, unsigned int feature_count,
                                          enum queue_feature_id feature)
{
    unsigned int i;

    for (i = 0; i < feature_count; i++) {
        if (features[i] == feature) {
            return 1;
        }
    }
    return 0;
}

#endif /* QUEUE_FEATURE_KERNEL_H */
