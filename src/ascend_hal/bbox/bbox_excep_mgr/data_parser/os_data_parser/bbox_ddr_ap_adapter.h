/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef BBOX_DDR_AP_ADAPTER_H
#define BBOX_DDR_AP_ADAPTER_H

#include <stddef.h>
#include "bbox_ddr_int.h"
#include "bbox_ap_root_info_types.h"
#include "bbox_ap_root_info.h"

#define AP_DUMP_MAGIC           0x19283746
#define AP_DUMP_END_MAGIC       0x1F2E3D4C
#define FILE_AP_EH_ROOT "os_info.txt"
#define REG_NAME_PMU    "pmu"

#define DEFAULT_DEVICE_ID               0

static inline void *bbox_rdr_ap_vaddr_convert(const struct ap_root_info *ap, u64 vaddr, u32 *len)
{
    u64 map_addr = ap->area_info.ap_map_addr;
    u64 area_len = ap->area_info.ap_area_len;
    u64 offset = 0;

    if (vaddr > map_addr) {
        offset = vaddr - map_addr;
        if (offset <= area_len) {
            *len = (u32)area_len - (u32)offset;
            return (u8 *)(uintptr_t)ap + offset;
        }
    }
    return NULL;
}

void bbox_ddr_dump_ap(const struct ap_root_info *ap, u32 len, const char *log_path);

#endif
