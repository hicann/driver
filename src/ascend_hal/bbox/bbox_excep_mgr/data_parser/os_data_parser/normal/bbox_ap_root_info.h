/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef BBOX_AP_ROOT_INFO_H
#define BBOX_AP_ROOT_INFO_H

#include "bbox_ap_root_info_types.h"

/* normal version: ap_root_info struct for platforms without v2/v4 features */

struct ap_root_info {
    struct ap_top_head top_head;
    struct ap_current_info current_info;
    struct ap_log_info log_info;
    struct ap_area_info area_info;
    struct ap_top_head coretop_head;
    struct ap_current_info corecurrent_info;
    struct ap_log_info corelog_info;
};

#endif /* BBOX_AP_ROOT_INFO_H */
