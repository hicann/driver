/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <linux/pci.h>
 
#ifndef _WIN32
#include "ascend_hal.h"
#endif
#include "securec.h"
#include "dsmi_network_interface.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_os_adapter.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_npu_link_intf.h"
#include "dcmi_basic_info_intf.h"
 
int dcmiv2_get_topo_info_by_device_id(int dev_id1, int dev_id2, int *topo_type)
{
    int ret;
    enum dcmi_unit_type device_type1 = INVALID_TYPE;
    enum dcmi_unit_type device_type2 = INVALID_TYPE;

    if (topo_type == NULL) {
        gplog(LOG_ERR, "topo_type is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This device does not support get Topo.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id1, &device_type1);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type for device1 failed. (ret=%d)", ret);
        return ret;
    }

    ret = dcmiv2_get_device_type(dev_id2, &device_type2);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type for device2 failed. (ret=%d)", ret);
        return ret;
    }

    if (device_type1 == NPU_TYPE && device_type2 == NPU_TYPE) {
        return dcmiv2_query_topo_type(dev_id1, dev_id2, topo_type);
    } else {
        gplog(LOG_ERR, "device_type %d and %d is not support.", device_type1, device_type2);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}
 
int dcmiv2_get_affinity_cpu_info_by_dev_id(int dev_id, char *affinity_cpu, int *len)
{
    int ret, card_id, device_id;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    if (affinity_cpu == NULL || len  == NULL) {
        gplog(LOG_ERR, "Affinity_cpu or length is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_check_product_of_get_affinity(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This device does not support get Cpu affinity.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type for device failed. (ret=%d)", ret);
        return ret;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", ret);
        return ret;
    }
 
    if (device_type == NPU_TYPE) {
        if (dcmi_mainboard_is_a900_a5_pcie(g_mainboard_info.mainboard_id)) {
            return dcmi_get_cpu_affinity_by_device_id(card_id, device_id, affinity_cpu, len);
        } else {
            return dcmi_get_ub_cpu_affinity_by_device_id(dev_id, affinity_cpu, len);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_serdes_quality_info(int dev_id, unsigned int macro_id,
    struct dcmi_serdes_quality_info *serdes_quality_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    unsigned int out_size = sizeof(struct dcmi_serdes_quality_info);

    if (serdes_quality_info == NULL) {
        gplog(LOG_ERR, "serdes_quality_info is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = checkv2_serdes_environment_is_invalid(dev_id, macro_id);
    if (ret != DCMI_OK) {
        return ret;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. (ret=%d)", ret);
        return ret;
    }
 
    if (device_type == NPU_TYPE) {
        serdes_quality_info->macro_id = macro_id;
        ret = dsmi_get_device_info(dev_id, DSMI_MAIN_CMD_SERDES, DSMI_SERDES_SUB_CMD_QUALITY_INFO,
            (void *)serdes_quality_info, &out_size);
        if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_device_info failed. (ret=%d)", ret);
        }
 
        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_pcie_link_bandwidth_info(int dev_id, struct dcmi_pcie_link_bandwidth_info *pcie_link_bandwidth_info)
{
    int ret;
    unsigned int env_flag = ENV_PHYSICAL;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    unsigned int out_size = sizeof(struct dcmi_pcie_link_bandwidth_info);
 
    if (dcmiv2_check_chip_is_in_split_mode(dev_id) == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
        gplog(LOG_ERR, "Operation not permitted, this api cannot be called in split mode.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (pcie_link_bandwidth_info == NULL) {
        gplog(LOG_ERR, "pcie_link_bandwidth_info is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_check_run_in_docker()) {
        ret = dcmi_get_environment_flag(&env_flag);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "call dcmi_get_environment_flag failed. (ret=%d)", ret);
            return DCMI_ERR_CODE_INNER_ERR;
        }
        if (env_flag != ENV_PHYSICAL_PRIVILEGED_CONTAINER && env_flag != ENV_VIRTUAL_PRIVILEGED_CONTAINER) {
            gplog(LOG_ERR, "Operation not permitted, only privileged containers are supported. (Current env_flag=%u)",
                env_flag);
            return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
        }
    }

    if (!dcmi_board_chip_type_is_ascend_950_card()) {
        gplog(LOG_OP, "This device does not support get pcie link bandwidth info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. (ret=%d)", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        ret = dsmi_get_device_info(dev_id, DSMI_MAIN_CMD_PCIE_BANDWIDTH, DSMI_PCIE_CMD_GET_BANDWIDTH,
            (void *)pcie_link_bandwidth_info, &out_size);
        if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_device_info failed. (ret=%d)", ret);
        }
        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_ub_realtime_bandwidth_info(int dev_id, unsigned int profiling_time,
    struct dcmi_ub_port_info *ub_port_info, struct dcmi_ub_bandwidth_info *ub_bandwidth_info)
{
    int ret;
    int card_id, device_id;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    struct ub_bandwidth_t bandwidth = {0};
    if (ub_bandwidth_info == NULL || ub_port_info == NULL) {
        gplog(LOG_ERR, "ub_bandwidth_info[%d] or ub_port_info[%d] is NULL.",
            ub_bandwidth_info == NULL, ub_port_info == NULL);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    // 仅支持A5
    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This device does not support get ub link bandwidth info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. err is %d.", ret);
        return ret;
    }

    // 判断入参是否满足
    ret = dcmi_ub_bandwidth_info_check(card_id, device_id, profiling_time, ub_port_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_ub_bandwidth_info_check failed. ret is %d.", ret);
        return ret;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Dcmi_get_device_type failed. ret is %d.", ret);
        return ret;
    }
 
    if (device_type == NPU_TYPE) {
        ret = dsmi_get_ub_bandwidth(dev_id, ub_port_info->udie_id, ub_port_info->port_id,
            profiling_time, &bandwidth);
        if (ret != DSMI_OK) {
            gplog(LOG_ERR, "Call dsmi_get_ub_bandwidth failed. err is %d.", ret);
            return dcmi_convert_error_code(ret);
        }
        ub_bandwidth_info->tx_bandwidth = bandwidth.tx_bandwidth;
        ub_bandwidth_info->rx_bandwidth = bandwidth.rx_bandwidth;
    } else {
        gplog(LOG_ERR, "Device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
    return DCMI_OK;
}