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
#include <string.h>
#include <unistd.h>

#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_inner_cfg_persist.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_network_intf.h"
#include "dcmi_product_judge.h"
#include "dcmi_permission_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_basic_info_intf.h"

#if defined DCMI_VERSION_2
int dcmiv2_get_device_aicore_info(int dev_id, struct dcmi_aicore_info *aicore_info)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (aicore_info == NULL) {
        gplog(LOG_ERR, "aicore_info is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", err);
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_aicore_info(card_id, device_id, aicore_info);
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_power_info(int dev_id, int *power_info)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (power_info == NULL) {
        gplog(LOG_ERR, "power_info is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", err);
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_device_power_info(card_id, device_id, power_info);
    } else if (device_type == MCU_TYPE) {
        if (dcmi_board_chip_type_is_ascend_910()) {
            return DCMI_ERR_CODE_NOT_SUPPORT;
        }

        return dcmi_mcu_get_power_info(card_id, power_info);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_health(int dev_id, unsigned int *health)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (health == NULL) {
        gplog(LOG_ERR, "health is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", err);
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_device_health_950(card_id, device_id, health);
    } else if (device_type == MCU_TYPE) {
        return dcmi_mcu_get_health(card_id, health);
#ifndef _WIN32
    } else if (device_type == CPU_TYPE) {
        return dcmi_cpu_get_health(card_id, health);
#endif
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_driver_health(unsigned int *health)
{
#ifndef _WIN32
    int err;

    if (health == NULL) {
        gplog(LOG_ERR, "health is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dsmi_get_driver_health(health);
    if (err != DSMI_OK) {
        gplog(LOG_ERR, "dsmi_get_driver_health failed. err is %d.", err);
    }
    return dcmi_convert_error_code(err);
#else
    return DCMI_ERR_CODE_NOT_SUPPORT;
#endif
}

int dcmiv2_get_device_proc_mem_info(int dev_id, struct dcmi_proc_mem_info *proc_info, int *proc_num)
{
#ifndef _WIN32
    int err, card_id, device_id;
    bool check_result = FALSE;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (proc_info == NULL || proc_num == NULL) {
        gplog(LOG_ERR, "proc_info or proc_num is null.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. (ret=%d)", err);
        return err;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_card_id_device_id_from_logicid failed. (ret=%d)", err);
        return err;
    }

    check_result = !(dcmi_board_type_is_card() || dcmi_board_type_is_station() || dcmi_board_type_is_hilens() ||
        dcmi_board_type_is_server() || dcmi_board_type_is_model());
    if (check_result) {
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmi_get_npu_proc_mem_info(card_id, device_id, proc_info, proc_num);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_npu_proc_mem_info failed. (ret=%d)", err);
    }

    return err;
#else
    return DCMI_ERR_CODE_NOT_SUPPORT;
#endif
}

int dcmiv2_get_device_aicpu_info(int dev_id, struct dcmi_aicpu_info *aicpu_info)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (aicpu_info == NULL) {
        gplog(LOG_ERR, "aicpu_info is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_aicpu_info(dev_id, (struct dsmi_aicpu_info_stru *)aicpu_info);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_aicpu_info failed. err is %d.", err);
        }
        return dcmi_convert_error_code(err);
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_system_time(int dev_id, unsigned int *system_time)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (system_time == NULL) {
        gplog(LOG_ERR, "system_time is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_system_time(dev_id, system_time);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_system_time failed. err is %d.", err);
        }
        return dcmi_convert_error_code(err);
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}
#endif

int dcmiv2_get_device_boot_status(int dev_id, enum dcmi_boot_status *boot_status)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (boot_status == NULL) {
        gplog(LOG_ERR, "boot_status is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. (ret=%d)", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_device_boot_status(dev_id, (enum dsmi_boot_status *)(void *)boot_status);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_device_boot_status failed. (ret=%d)", err);
        }

        return dcmi_convert_error_code(err);
    }

    gplog(LOG_ERR, "device_type %d is error.", device_type);
    return DCMI_ERR_CODE_NOT_SUPPORT;
}

int dcmiv2_get_device_ecc_info(int dev_id, enum dcmi_device_type input_type, struct dcmi_ecc_info *device_ecc_info)
{
    int err, ret, card_id, dev_phy_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (device_ecc_info == NULL) {
        gplog(LOG_ERR, "device_ecc_info is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (input_type > DCMI_HBM_RECORDED_MULTI_ADDR || input_type < DCMI_DEVICE_TYPE_DDR) {
        gplog(LOG_ERR, "input type is invalid, input_type=%d", input_type);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &dev_phy_id, dev_id);
    if (ret != DCMI_OK) {
        return ret;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_ecc_info(card_id, dev_phy_id, input_type, device_ecc_info);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_frequency(int dev_id, enum dcmi_freq_type input_type, unsigned int *frequency)
{
    int err, card_id, dev_phy_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (frequency == NULL) {
        gplog(LOG_ERR, "frequency is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (input_type > DCMI_FREQ_VECTORCORE_CURRENT) {
        gplog(LOG_ERR, "input_type is invalid. input_type=%d", input_type);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &dev_phy_id, dev_id);
    if (err != DCMI_OK) {
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_device_frequency(card_id, dev_phy_id, input_type, frequency);
#ifndef _WIN32
    } else if (device_type == CPU_TYPE) {
        return dcmi_cpu_get_device_frequency(card_id, dev_phy_id, frequency);
#endif
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_hbm_info(int dev_id, struct dcmi_hbm_info *hbm_info)
{
    int err, card_id, dev_phy_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (hbm_info == NULL) {
        gplog(LOG_ERR, "hbm_info is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &dev_phy_id, dev_id);
    if (err != DCMI_OK) {
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.\n", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_hbm_info(card_id, dev_phy_id, hbm_info);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_utilization_rate(int dev_id, int input_type, unsigned int *utilization_rate)
{
    int err, card_id, dev_phy_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (utilization_rate == NULL) {
        gplog(LOG_ERR, "utilization_rate is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &dev_phy_id, dev_id);
    if (err != DCMI_OK) {
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_device_utilization_rate(card_id, dev_phy_id, input_type, utilization_rate);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_sensor_info(int dev_id, enum dcmi_manager_sensor_id sensor_id,
                                  union dcmi_sensor_info *sensor_info)
{
    int err, card_id, dev_phy_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (sensor_info == NULL) {
        gplog(LOG_ERR, "sensor_info is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (sensor_id >= DCMI_SENSOR_INVALID_ID) {
        gplog(LOG_ERR, "sensor_id is invalid. sensor_id=%d", sensor_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &dev_phy_id, dev_id);
    if (err != DCMI_OK) {
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_soc_sensor_info(card_id, dev_phy_id, sensor_id, sensor_info);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_llc_perf_para(int dev_id, struct dcmi_llc_perf *perf_para)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (perf_para == NULL) {
        gplog(LOG_ERR, "perf_para is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
        return err;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_llc_perf_para(dev_id, (struct dsmi_llc_perf_stru *)perf_para);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_llc_perf_para failed. err is %d.", err);
        }
        return dcmi_convert_error_code(err);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_get_device_cgroup_info(int dev_id, struct dcmi_cgroup_info *cg_info)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (cg_info == NULL) {
        gplog(LOG_ERR, "cg_info is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
        return err;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_device_cgroup_info(dev_id, (struct tag_cgroup_info *)cg_info);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_device_cgroup_info failed. err is %d.", err);
        }
        return dcmi_convert_error_code(err);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_share_enable(int dev_id, unsigned int *enable_flag)
{
    int err;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    unsigned int size = sizeof(unsigned int);

    if (enable_flag == NULL) {
        gplog(LOG_ERR, "enable_flag is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_device_info(dev_id, DSMI_MAIN_CMD_EX_CONTAINER, DSMI_EX_CONTAINER_SUB_CMD_SHARE,
        (void *)enable_flag, &size);
        if (err != DSMI_OK) {
            gplog(LOG_ERR, "call dsmi_get_device_info failed. err is %d.", err);
            return dcmi_convert_error_code(err);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_get_device_share_config_recover_mode(unsigned int *enable_flag)
{
    int err;

    err = dcmi_check_device_share_config_recover_mode_is_permitted("get");
    if (err != DCMI_OK) {
        return err;
    }
    
    if (enable_flag == NULL) {
        gplog(LOG_ERR, "enable_flag is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (access(DCMI_DEVICE_SHARE_CONF, F_OK) != DCMI_OK) { // 配置文件不存在, 则返回默认值
        gplog(LOG_OP, "Query device-share config info: Success.");
        *enable_flag = DCMI_CFG_RECOVER_DISABLE;
        return DCMI_OK;
    }

    err = dcmi_cfg_get_device_share_config_recover_mode(enable_flag);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "get config recover enable_flag failed. err=%d", err);
        return err;
    }
    return DCMI_OK;
}

int dcmiv2_get_device_network_health(int dev_id, enum dcmi_rdfx_detect_result *result)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (result == NULL) {
        gplog(LOG_ERR, "result is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if (dcmi_board_chip_type_is_ascend_950_card()) {
        gplog(LOG_OP, "This device does not support get device network health.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
        return err;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_network_health(dev_id, (DSMI_NET_HEALTH_STATUS *)(void *)result);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_network_health failed. err is %d.", err);
        }
        return dcmi_convert_error_code(err);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_get_device_netdev_health(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    enum dcmi_rdfx_detect_result *result)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (result == NULL || dev_id < 0) {
        gplog(LOG_ERR, "Parameter is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "Parameter is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (err=%d)", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_network_health(dev_id, (DSMI_NET_HEALTH_STATUS *)(void *)result);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "dev_id[%d] call dsmi_get_network_health failed. (err=%d)", dev_id, err);
        }
        return dcmi_convert_error_code(err);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_netdev_ip(int dev_id, const char *netdev_name, unsigned int netdev_name_len, struct dcmi_ip_addr *ip,
                         struct dcmi_ip_addr *mask)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (ip == NULL || mask == NULL) {
        gplog(LOG_ERR, "Parameter is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_validity_check failed. (dev_id=%d; ret=%d)", dev_id, err);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This device does not support get device ip.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (dev_id=%d; ret=%d).", dev_id, err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_device_bond_ip_address(dev_id, netdev_name, netdev_name_len, (struct dsmi_ip_addr *)ip,
                                              (struct dsmi_ip_addr *)mask);
        if (err != DSMI_OK) {
            gplog(LOG_ERR, "call dsmi_get_device_bond_ip_address failed. (dev_id=%d; ret=%d).", dev_id, err);
            return dcmi_convert_error_code(err);
        }
        gplog(LOG_OP, "get device ip success. (dev_id=%d; bond=%s)", dev_id, netdev_name);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_get_netdev_mac(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    char *mac_addr, unsigned int mac_addr_len)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    /* 参数校验 */
    if (dev_id < 0 || mac_addr == NULL || mac_addr_len != MAC_ADDR_LEN) {
        gplog(LOG_ERR, "Parameter is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    ret = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Parameter is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    /* 产品类型校验 */
    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return ret;
    }

    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dsmi_get_netdev_mac_addr(dev_id, netdev_name, netdev_name_len, mac_addr, mac_addr_len);
    if (ret != DSMI_OK) {
        gplog(LOG_ERR, "dsmi_get_netdev_mac_addr failed. err is %d.", ret);
        return dcmi_convert_error_code(ret);
    }

    return dcmi_convert_error_code(ret);
}

int dcmiv2_get_netdev_gateway(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dcmi_ip_addr *gateway)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (gateway == NULL || dev_id < 0) {
        gplog(LOG_ERR, "input param gateway[%d] or dev_id[%d] is invalid.", gateway == NULL, dev_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_validity_check failed. (ret=%d)", err);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_ERR, "This product does not support get device gateway.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_device_type failed. (ret=%d)", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_netdev_gateway(dev_id, netdev_name, netdev_name_len, (struct dsmi_ip_addr *)gateway);
        if ((err != DSMI_OK)) {
            gplog(LOG_ERR, "call dsmi_get_netdev_gateway failed. (ret=%d)", err);
            return dcmi_convert_error_code(err);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_get_ub_port_link_status(int dev_id, struct dcmi_ub_port_link_status *ub_status)
{
    int ret;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (ub_status == NULL) {
        gplog(LOG_ERR, "ub_status is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    // 当前仅支持A5标卡
    if (!dcmi_board_chip_type_is_ascend_950_card()) {
        gplog(LOG_OP, "This device does not support get ub port status info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        unsigned int out_size = sizeof(struct dcmi_ub_port_link_status);
        ret = dsmi_get_device_info(dev_id, DSMI_MAIN_CMD_UB, DSMI_UB_INFO_SUB_CMD_PORT_STATUS,
        (void *)ub_status, &out_size);
        if (ret != DSMI_OK) {
            gplog(LOG_ERR, "call dsmi_get_device_info failed. err is %d.", ret);
        }
        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
    return DCMI_OK;
}

int dcmiv2_get_device_multi_utilization_rate(int dev_id, struct dcmi_multi_utilization_info *util_info)
{
    int err, card_id, dev_phy_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (util_info == NULL) {
        gplog(LOG_ERR, "util_info is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_ERR, "This device does not support getting utilization rate.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &dev_phy_id, dev_id);
    if (err != DCMI_OK) {
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_device_utilization_rate_v2(card_id, dev_phy_id, util_info);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

