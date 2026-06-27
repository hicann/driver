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

#ifndef XSMEM_FEATURE_CHECK_H
#define XSMEM_FEATURE_CHECK_H

#include "buff_feature_kernel.h"
#include "ascend_hal_error.h"

/*
 * ============================================================================
 * Chip version feature configuration structure
 * Each chip version corresponds to a feature array
 * ============================================================================
 */
struct buff_chip_features {
    const enum buff_feature_id *features;
    unsigned int feature_count;
};

/*
 * ============================================================================
 * Basic function declarations
 * ============================================================================
 */

/*
 * Initialize the feature check system
 * Must be called once before using any other feature functions
 */
void buff_feature_system_init(void);

/*
 * Get feature configuration by chip type
 * @param chip_type: UDA chip type, e.g., HISI_CLOUD_V2, HISI_CLOUD_V5
 * @return: pointer to corresponding feature configuration, NULL if not found
 */
const struct buff_chip_features *buff_get_chip_features(unsigned int chip_type);

/*
 * Get the feature configuration for a specific device
 * @param dev_id: device ID (0 ~ BUFF_FEATURE_DEV_NUM - 1)
 * @return: pointer to device's feature configuration, NULL if device not found
 */
const struct buff_chip_features *buff_get_dev_features(unsigned int dev_id);

int buff_has_feature(unsigned int dev_id, enum buff_feature_id feature);
void buff_feature_uninit(void);
drvError_t buff_feature_init_by_devid(unsigned int dev_id);

/* ============================================================================
 * All chip version feature table declarations
 * ============================================================================
 *
 * Chip type mapping (code and config tables use UDA chip_type enum values):
 * HISI_MINI_V1  (0)  -> buff_get_chip_features(HISI_MINI_V1)
 * HISI_CLOUD_V1 (1)  -> buff_get_chip_features(HISI_CLOUD_V1)
 * HISI_MINI_V2  (2)  -> buff_get_chip_features(HISI_MINI_V2)
 * HISI_CLOUD_V2 (3)  -> buff_get_chip_features(HISI_CLOUD_V2)
 * HISI_MINI_V3  (4)  -> buff_get_chip_features(HISI_MINI_V3)
 * HISI_CLOUD_V4 (6)  -> buff_get_chip_features(HISI_CLOUD_V4)
 * HISI_CLOUD_V5 (7)  -> buff_get_chip_features(HISI_CLOUD_V5)
 * HISI_MINI_V4  (10) -> buff_get_chip_features(HISI_MINI_V4)
 *
 * Note: Use buff_get_chip_features() function to access chip features.
 *       Do not access global variables directly.
 */

#endif /* XSMEM_FEATURE_CHECK_H */
