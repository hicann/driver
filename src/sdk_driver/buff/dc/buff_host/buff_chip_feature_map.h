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

#ifndef BUFF_CHIP_FEATURE_MAP_H
#define BUFF_CHIP_FEATURE_MAP_H

#include "buff_feature_kernel.h"

#define BUFF_CHIP_FEATURE_COUNT 8

#ifdef __cplusplus
extern "C" {
#endif

/* chip key: hisi_mini_v1 - HISI_MINI_V1 (0) */
static const enum buff_feature_id hisi_mini_v1_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,
    BUFF_FEATURE_SUPPORT_VMA,
    BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
};

/* chip key: hisi_cloud_v1 - HISI_CLOUD_V1 (1) */
static const enum buff_feature_id hisi_cloud_v1_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,      BUFF_FEATURE_SUPPORT_VMA, BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_KA_ALLOC_INTERFACE, BUFF_FEATURE_HOST_LOG,    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
};

/* chip key: hisi_mini_v2 - HISI_MINI_V2 (2) */
static const enum buff_feature_id hisi_mini_v2_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,      BUFF_FEATURE_SUPPORT_VMA, BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_KA_ALLOC_INTERFACE, BUFF_FEATURE_HOST_LOG,    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
};

/* chip key: hisi_cloud_v2 - HISI_CLOUD_V2 (3) */
static const enum buff_feature_id hisi_cloud_v2_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,      BUFF_FEATURE_SUPPORT_VMA, BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_KA_ALLOC_INTERFACE, BUFF_FEATURE_HOST_LOG,    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
    BUFF_FEATURE_NO_SUPPORT_DVPP_MZ,
};

/* chip key: hisi_mini_v3 - HISI_MINI_V3 (4) */
static const enum buff_feature_id hisi_mini_v3_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,      BUFF_FEATURE_SUPPORT_VMA, BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_KA_ALLOC_INTERFACE, BUFF_FEATURE_HOST_LOG,    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
};

/* chip key: hisi_cloud_v4 - HISI_CLOUD_V4 (6) */
static const enum buff_feature_id hisi_cloud_v4_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,      BUFF_FEATURE_SUPPORT_VMA, BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_KA_ALLOC_INTERFACE, BUFF_FEATURE_HOST_LOG,    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
};

/* chip key: hisi_cloud_v5 - HISI_CLOUD_V5 (7), CHIP_CLOUD_V5 */
static const enum buff_feature_id hisi_cloud_v5_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,      BUFF_FEATURE_SUPPORT_VMA, BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_KA_ALLOC_INTERFACE, BUFF_FEATURE_HOST_LOG,    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
};

/* chip key: hisi_mini_v4 - HISI_MINI_V4 (10) */
static const enum buff_feature_id hisi_mini_v4_features[] = {
    BUFF_FEATURE_EXTERNAL_CDEV,      BUFF_FEATURE_SUPPORT_VMA, BUFF_FEATURE_SHARE_LOG,
    BUFF_FEATURE_KA_ALLOC_INTERFACE, BUFF_FEATURE_HOST_LOG,    BUFF_FEATURE_SUPPORT_HUGE_PAGE,
};

#ifdef __cplusplus
}
#endif

#endif /* BUFF_CHIP_FEATURE_MAP_H */
