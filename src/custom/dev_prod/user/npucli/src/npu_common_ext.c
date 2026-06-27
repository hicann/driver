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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#ifndef _WIN32
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <sys/types.h>
#include <ctype.h>
#include <limits.h>
#include <regex.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_log.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_product_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_environment_judge.h"
#include "npu_cmd_parse.h"
#include "npu_parameter_parse.h"
#include "npu_run_env.h"
#include "npu_card_info.h"
#include "npu_common.h"

int npu_get_hbm_info(int card_id, int chip_id, struct npu_chip_usages_info *usages_info)
{
    int ret = 0;
    // HBM容量, 带宽占用率获取
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_hbm_info(card_id, chip_id, &usages_info->hbm_size_info_M);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_hbm_info failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    ret = dcmiv2_get_device_hbm_info(card_id, &usages_info->hbm_size_info_M);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_hbm_info failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_id, DCMI_UTILIZATION_RATE_HBM, &usages_info->hbm_usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_HBM, &usages_info->hbm_usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
    return NPU_OK;
}

int npu_get_device_power_info(int card_id, int chip_index, int *power)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_type(card_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
#else
    ret = dcmi_get_device_type(card_id, chip_index, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
#endif
    if (npu_get_chip_type() == NPU_CHIP_310P && device_type == NPU_TYPE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_power_info(card_id, power);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_power_info failed. ret is %d, NPU %d", ret, card_id);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    ret = dcmi_get_device_power_info(card_id, chip_index, power);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_power_info failed. ret is %d, card %d chip %d", ret, card_id, chip_index);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
    return NPU_OK;
}

int npu_get_device_temperature(int card_id, int chip_index, int *temp)
{
    int ret;
#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_temperature(card_id, temp);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_temperature failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    ret = dcmi_get_device_temperature(card_id, chip_index, temp);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_temperature failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
    return NPU_OK;
}

int npu_get_ai_core_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;
#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_AICORE, usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_AICORE, usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
    return NPU_OK;
}

int npu_get_ai_cube_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_AICUBE, usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_AICUBE, usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
    return NPU_OK;
}

int npu_get_ai_cpu_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_AICPU, usage);
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_AICPU, usage);
#endif
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_ai_cpu_usage failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    return NPU_OK;
}

int npu_get_ctrl_cpu_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_CTRLCPU, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_CTRLCPU, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#endif
    return NPU_OK;
}

int npu_get_vector_core_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret = NPU_OK;

    if (npu_get_chip_type() != NPU_CHIP_310P) {
        return ret;
    }
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_VECTORCORE, usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_VECTORCORE, usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
    return NPU_OK;
}

int npu_get_ddr_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        // 910B、910_93、950没有DDR,不支持查询DDR信息
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_DDR, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_DDR, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#endif
    return NPU_OK;
}

int npu_get_hbm_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_HBM, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_HBM, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#endif
    return NPU_OK;
}

int npu_get_ddr_bandwidth_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;

    *usage = NPU_DEFAULT_VALUE;
 
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_DDR_BANDWIDTH,
        (unsigned int *)usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_DDR_BANDWIDTH,
        (unsigned int *)usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#endif
    return NPU_OK;
}

int npu_get_hbm_bandwidth_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;

    *usage = NPU_DEFAULT_VALUE;
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_HBM_BANDWIDTH,
        (unsigned int *)usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_HBM_BANDWIDTH,
        (unsigned int *)usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#endif
    return NPU_OK;
}

int npu_get_npu_utilization_usage(int card_id, int chip_index, unsigned int *usage)
{
    int ret;

    *usage = NPU_DEFAULT_VALUE;
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_utilization_rate(card_id, chip_index, DCMI_UTILIZATION_RATE_NPU, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#else
    ret = dcmiv2_get_device_utilization_rate(card_id, DCMI_UTILIZATION_RATE_NPU, usage);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        ret = (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? NPU_ERR_CODE_NOT_SUPPORT : NPU_ERR_CODE_DCMI_FUN_FAIL;
        return ret;
    }
#endif
    return NPU_OK;
}

int npu_get_npu_utilization_usage_v2(int card_id, unsigned int *usage)
{
    int ret;
    struct dcmi_multi_utilization_info util_info = {0};

    if (npu_get_chip_type() != NPU_CHIP_950) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (usage == NULL) {
        gplog(LOG_ERR, "usage is NULL");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmiv2_get_device_multi_utilization_rate(card_id, &util_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_npu_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    *usage = util_info.npu_util;
    return NPU_OK;
}