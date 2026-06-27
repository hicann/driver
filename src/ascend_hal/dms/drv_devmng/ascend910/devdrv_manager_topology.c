/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "securec.h"
#include "devmng_common.h"
#include "dms/dms_devdrv_info_comm.h"
#include "dms/dms_misc_interface.h"
#include "ascend_hal.h"
#include "dms_device_info.h"
#include "ascend_dev_num.h"

#ifdef STATIC_SKIP
#define STATIC
#else
#define STATIC static
#endif

STATIC drvError_t drv_get_sys_info_by_phy_id(uint32_t phy_id, int32_t info_type, int64_t *value)
{
    int ret;
    unsigned int tmp_value;

    switch (info_type) {
        case PHY_INFO_TYPE_CHIPTYPE:
            ret = DmsGetChipType(phy_id, &tmp_value);
            if (ret != 0) {
                DEVDRV_DRV_EX_NOTSUPPORT_ERR(ret, "drvGetDevInfo failed ret = %d.\n", ret);
                return ret;
            }
            *value = (int64_t)tmp_value;
            break;
        case PHY_INFO_TYPE_MASTER_ID:
            ret = DmsGetMasterDevInTheSameOs(phy_id, &tmp_value);
            if (ret != 0) {
                DEVDRV_DRV_EX_NOTSUPPORT_ERR(ret, "Failed to obtain the master device. (phy_id=%u; ret=%d)\n",
                    phy_id, ret);
                return ret;
            }
            *value = (int64_t)tmp_value;
            break;
        case PHY_INFO_TYPE_PHY_CHIP_ID:
        case PHY_INFO_TYPE_PHY_DIE_ID:
            ret = dms_get_phy_dev_info(phy_id, info_type, &tmp_value);
            if (ret != 0) {
                DEVDRV_DRV_EX_NOTSUPPORT_ERR(ret, "Failed to obtain physical device info. (phy_id=%u; ret=%d)\n",
                    phy_id, ret);
                return ret;
            }
            *value = (int64_t)tmp_value;
            break;
        default:
            DEVDRV_DRV_ERR("invalid parameter. (info_type=%d; phy_id=%u)\n", info_type, phy_id);
            return DRV_ERROR_INVALID_VALUE;
    }

    return DRV_ERROR_NONE;
}

drvError_t halGetPhyDeviceInfo(uint32_t phyId, int32_t moduleType, int32_t infoType, int64_t *value)
{
    int ret;
    DEV_MODULE_TYPE mtype = moduleType;
    DEV_INFO_TYPE itype = infoType;

    if (phyId >= ASCEND_DEV_MAX_NUM || value == NULL) {
        DEVDRV_DRV_ERR("invalid parameter, value is NULL or phy_id(%u) is invalid\n", phyId);
        return DRV_ERROR_INVALID_VALUE;
    }

    switch (mtype) {
        case MODULE_TYPE_SYSTEM:
            ret = drv_get_sys_info_by_phy_id(phyId, itype, value);
            break;

        default:
            DEVDRV_DRV_ERR("invalid parameter. (moduleType=%d)\n", mtype);
            return DRV_ERROR_INVALID_VALUE;
    }
    if (ret != 0) {
        DEVDRV_DRV_EX_NOTSUPPORT_ERR(ret, "Get device info failed. (ret=%d; module_type=%d; info_type=%d; phy_id=%u)\n",
                       ret, mtype, itype, phyId);
        return ret;
    }
    return DRV_ERROR_NONE;
}

drvError_t halGetPairDevicesInfo(uint32_t devId, uint32_t otherDevId, int32_t infoType, int64_t *value)
{
#ifdef DRV_HOST
    int ret;
    int topology_type = 0;

    if (value == NULL) {
        DEVDRV_DRV_ERR("Input value is null.\n");
        return DRV_ERROR_INVALID_VALUE;
    }

    if ((drvCheckDevid(devId) != 0) || (drvCheckDevid(otherDevId) != 0)) {
        DEVDRV_DRV_ERR("Device id check failed. (devId=%u; other_dev_id=%u)\n", devId, otherDevId);
        return DRV_ERROR_INVALID_VALUE;
    }

    if (infoType == DEVS_INFO_TYPE_TOPOLOGY) {
        ret = dms_get_device_topology(devId, otherDevId, &topology_type);
        if (ret != 0) {
            DEVDRV_DRV_EX_NOTSUPPORT_ERR(ret, "Get device topology failed. (dev_id=%u; dev_id_other=%u; ret=%d)\n",
                devId, otherDevId, ret);
            return ret;
        }

        *value = topology_type;
        DEVDRV_DRV_DEBUG("Get topology type success. (dev_id=%u; dev_id_other=%u)\n", devId, otherDevId);
    } else {
        DEVDRV_DRV_ERR("Invalid info type. (info_type=%d)\n", infoType);
        return DRV_ERROR_INVALID_VALUE;
    }

    return DRV_ERROR_NONE;
#else
    (void)devId;
    (void)otherDevId;
    (void)infoType;
    (void)value;
    return DRV_ERROR_NOT_SUPPORT;
#endif
}

drvError_t halGetPairPhyDevicesInfo(uint32_t devId, uint32_t otherDevId, int32_t infoType, int64_t *value)
{
#if (defined CFG_FEATURE_PHY_DEVICES_TOPO) && (defined DRV_HOST)
    int ret;
    int topology_type = 0;

    if (value == NULL) {
        DEVDRV_DRV_ERR("Input value is null.\n");
        return DRV_ERROR_INVALID_VALUE;
    }

    if (infoType == DEVS_INFO_TYPE_TOPOLOGY) {
        ret = dms_get_phy_devices_topology(devId, otherDevId, &topology_type);
        if (ret != 0) {
            DEVDRV_DRV_EX_NOTSUPPORT_ERR(ret, "Failed to get devices topology info."
                "(dev_id=%u; dev_id_other=%u; ret=%d)\n", devId, otherDevId, ret);
            return ret;
        }

        *value = topology_type;
    } else {
        return DRV_ERROR_NOT_SUPPORT;
    }

    return DRV_ERROR_NONE;
#else
    (void)devId;
    (void)otherDevId;
    (void)infoType;
    (void)value;
    return DRV_ERROR_NOT_SUPPORT;
#endif
}
