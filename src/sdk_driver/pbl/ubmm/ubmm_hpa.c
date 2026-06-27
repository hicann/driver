/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
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
#include "ascend_hal_define.h"

#include "ka_kernel_def_pub.h"

#include "addr_trans.h"
#include "pbl_ubmm.h"
#include "ubmm_log.h"
#ifdef LATER_OPEN
static inline int ubmm_map_route_to_addr_trans_mode(u32 map_route)
{
    switch (map_route) {
        case MEM_MAP_UB_ONE_PORT_PATH:
            return DEVDRV_ADDR_DESC_MODE_ONEPATH;
        case MEM_MAP_UB_MULTI_PORT_PATH:
            return DEVDRV_ADDR_DESC_MODE_MULTIPATH;
        default:
            return DEVDRV_ADDR_DESC_MODE_DEFAULT;
    }
}
#endif
int ubmm_get_hpa(u32 udevid, u32 peer_udevid, u32 mem_id, u64 offset, u32 map_route, u64 *hpa)
{
    struct devdrv_addr_desc addr_desc = {0};
    int ret = 0;

    if (hpa == NULL) {
        ubmm_err("Invalid param, hpa is NULL. (dev_id=%u).\n", udevid);
        return -EINVAL;
    }
    addr_desc.peer_ub.mem_id = mem_id;
    addr_desc.peer_ub.offset = offset;
#ifdef LATER_OPEN
    addr_desc.peer_ub.mode = ubmm_map_route_to_addr_trans_mode(map_route);
#endif
    addr_desc.size = 0;

    ret = devdrv_addr_trans_p2p_peer_to_local(udevid, peer_udevid, &addr_desc, hpa);
    if (ret != 0) {
        ubmm_err("Trans failed, (udev_id=%u; peer_udevid=%u; mem_id=%u; offset=0x%llx; ret=%d).\n", 
            udevid, peer_udevid, addr_desc.peer_ub.mem_id, addr_desc.peer_ub.offset, ret);
        return ret;
    }
    return 0;
}
KA_EXPORT_SYMBOL_GPL(ubmm_get_hpa);

bool ubmm_map_route_is_exist(u32 dst_udevid, u32 src_sdid, u32 src_mem_id, u32 map_route)
{
    struct devdrv_addr_desc addr_desc = {0};
    u64 hpa;
    int ret;

    addr_desc.peer_ub.mem_id = src_mem_id;
    addr_desc.peer_ub.offset = 0;
#ifdef LATER_OPEN
    addr_desc.peer_ub.mode = ubmm_map_route_to_addr_trans_mode(map_route);
#endif
    addr_desc.size = 1;

    ret = devdrv_addr_trans_p2p_peer_to_local(dst_udevid, src_sdid, &addr_desc, &hpa);
    if (ret != 0) {
        ubmm_debug("Check route fail. (dst_udevid=%u; src_sdid=%u; src_mem_id=%u; route=%u; ret=%d).\n",
            dst_udevid, src_sdid, src_mem_id, map_route, ret);
    }

    return (ret == 0);
}
KA_EXPORT_SYMBOL_GPL(ubmm_map_route_is_exist);
