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
#include <fcntl.h>
 
#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_common.h"
#include "dcmi_init_basic.h"
#include "dcmi_log.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_os_adapter.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_fault_manage_intf.h"

#if defined DCMI_VERSION_2
static int dcmi_get_device_errorcode_para_handle(int dev_id, int *card_id, int *device_id,
    enum dcmi_unit_type *device_type)
{
    int err, tmp_card_id, tmp_device_id;

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&tmp_card_id, &tmp_device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", err);
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }
    *card_id = tmp_card_id;
    *device_id = tmp_device_id;
    return DCMI_OK;
}

int dcmiv2_get_device_error_info(int dev_id, unsigned int error_code, unsigned char *error_info,
    int buf_size)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (error_info == NULL || buf_size < DCMI_MIN_ERR_INFO_LEN) {
        gplog(LOG_ERR, "error_info or buff_size %d is invalid.", buf_size);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d.)", err);
        return err;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_device_errorcode_string(card_id, device_id, error_code, error_info, buf_size);
    } else if (device_type == MCU_TYPE) {
        return dcmi_mcu_get_device_errorcode_string(card_id, error_code, error_info, buf_size);
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_driver_error_code_list(int *error_count, unsigned int *error_code_list, unsigned int list_len)
{
#ifndef _WIN32
    int err, index;
    unsigned int err_code_list[DCMI_ERROR_CODE_MAX_COUNT] = {0}, err_count = 0;
    unsigned int filtered_count = 0;
    unsigned int filtered_list[DCMI_ERROR_CODE_MAX_COUNT] = {0};

    bool check_result = (error_count == NULL || error_code_list == NULL || list_len == 0);
    if (check_result) {
        gplog(LOG_ERR, "error_count or error_code_list or list_len is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dsmi_get_driver_errorcode((int *)(void *)&err_count, err_code_list);
    if (err != DSMI_OK) {
        gplog(LOG_ERR, "dsmi_get_driver_errorcode failed. err is %d.", err);
        return dcmi_convert_error_code(err);
    }

    /* A5代际没有/dev/devmm_svm */
    for (index = 0; index < err_count; index++) {
        if (err_code_list[index] != HOST_SVM_NOT_EXIST) {
            filtered_list[filtered_count++] = err_code_list[index];
        }
    }
    err_count = filtered_count;
    err = memcpy_s(err_code_list, DCMI_ERROR_CODE_MAX_COUNT * sizeof(unsigned int),
                   filtered_list, err_count * sizeof(unsigned int));
    if (err != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is %d.", err);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    if (err_count > list_len) {
        gplog(LOG_ERR, "list_len %u is smaller than error_count %u.", list_len, err_count);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = memcpy_s(error_code_list, list_len * sizeof(unsigned int), err_code_list, err_count * sizeof(unsigned int));
    if (err != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is %d.", err);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }
    *error_count = err_count;
    return DCMI_OK;
#else
    return DCMI_ERR_CODE_NOT_SUPPORT;
#endif
}

int dcmiv2_get_device_error_code_list(int dev_id, int *error_count, unsigned int *error_code_list,
    unsigned int list_len)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;
    /* 错误码的最大个数为128，修改此大小，需要评估D芯片和MCU的错误码个数是否满足要求 */
    unsigned int err_code_list[DCMI_ERROR_CODE_MAX_COUNT] = {0}, err_code_count = 0;

    bool check_result = ((error_count == NULL) || (error_code_list == NULL) || list_len == 0);
    if (check_result) {
        gplog(LOG_ERR, "error_count or error_code_list is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = dcmi_get_device_errorcode_para_handle(dev_id, &card_id, &device_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_errorcode_para_handle fail. err = %d", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dcmi_get_device_errorcode_950(card_id, device_id, (int *)(void *)&err_code_count, err_code_list,
            DCMI_ERROR_CODE_MAX_COUNT);
    } else if (device_type == MCU_TYPE) {
        err = dcmi_mcu_get_device_errorcode(card_id, (int *)(void *)&err_code_count,
                                            err_code_list, DCMI_ERROR_CODE_MAX_COUNT);
#ifndef _WIN32
    } else if (device_type == CPU_TYPE) {
        err = dcmi_cpu_get_device_errorcode(card_id, (int *)(void *)&err_code_count,
                                            err_code_list, DCMI_ERROR_CODE_MAX_COUNT);
#endif
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (err != DCMI_OK) {
        gplog(LOG_ERR, "get device error code failed. err is %d.", err);
        return DCMI_ERR_CODE_INNER_ERR;
    }

    if (err_code_count > list_len) {
        gplog(LOG_ERR, "list_len %u is smaller than err_code_count %u.", list_len, err_code_count);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    err = memcpy_s(error_code_list, list_len * sizeof(unsigned int), err_code_list,
        err_code_count * sizeof(unsigned int));
    if (err != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is %d.", err);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }
    *error_count = err_code_count;
    return DCMI_OK;
}

int dcmiv2_get_device_current_fault_event(int dev_id, struct dcmi_event *event_buf,
    int input_event_buf_length, int *output_event_cnt)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (event_buf == NULL) {
        gplog(LOG_ERR, "event_buf is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (output_event_cnt == NULL) {
        gplog(LOG_ERR, "output_event_cnt is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (input_event_buf_length < 1 || input_event_buf_length > MAX_EVENT_CNT) {
        gplog(LOG_ERR, "input para input_event_buf_length is invalid. (input_event_buf_length=%d)",
            input_event_buf_length);
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
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d.)", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_current_fault_event(card_id, device_id,
            event_buf, input_event_buf_length, output_event_cnt);
    }
    gplog(LOG_ERR, "device_type %d is not supported.", device_type);
    return DCMI_ERR_CODE_NOT_SUPPORT;
}

int dcmiv2_get_fault_event(int dev_id, int timeout, struct dcmi_event_filter filter,
    struct dcmi_event *event)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (event == NULL) {
        gplog(LOG_ERR, "input para event is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    if ((timeout < 0 && timeout != -1) || (timeout > DCMI_GET_EVENT_WAIT_TIME_MAX)) {
        gplog(LOG_ERR, "input para timeout is invalid. (timeout=%d)", timeout);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_check_run_in_docker() && dcmi_check_run_not_root()) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical or virtual machine"
            " or privileged docker can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (ret=%d)", err);
        return err;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        return dcmi_get_npu_fault_event(card_id, device_id, timeout, filter, event);
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_pcie_error_cnt(int dev_id, struct dcmi_chip_pcie_err_rate *pcie_err_code_info)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;
 
    if (pcie_err_code_info == NULL) {
        gplog(LOG_ERR, "pcie_err_code_info is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
        return err;
    }
 
    if (!dcmi_board_chip_type_is_ascend_950() || dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
        gplog(LOG_ERR, "This device does not support.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_get_pcie_error_rate(dev_id, (struct dsmi_chip_pcie_err_rate_stru *) pcie_err_code_info);
        if ((err != DSMI_OK) && (err != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_pcie_error_rate failed. err is %d.", err);
        }
        return dcmi_convert_error_code(err);
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_subscribe_fault_event(int dev_id, struct dcmi_event_filter filter,
    dcmi_fault_event_callback handler)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This device does not this api");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (dcmi_check_run_in_docker() && dcmi_check_run_not_root()) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical or virtual machine"
            " or privileged docker can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (handler == NULL) {
        gplog(LOG_ERR, "handler is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (dev_id == -1) {
        device_type = NPU_TYPE;
    } else {
        err = dcmiv2_get_device_type(dev_id, &device_type);
        if (err != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
            return err;
        }
    }

    if (device_type == NPU_TYPE) {
        return dcmiv2_subscribe_npu_fault_event(dev_id, filter, handler);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_subscribe_npu_fault_event(int device_id, struct dcmi_event_filter filter,
    dcmi_fault_event_callback handler)
{
    int ret;
    struct dsmi_soc_die_stru die_struct = {0};
    int device_cnt = 0;
    int device_list[MAX_CARD_NUM] = {0};
    int index;

    ret = dcmiv2_get_device_list(device_list, &device_cnt, sizeof(device_list) / sizeof(device_list[0]));
    if (device_cnt <= 0 || ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_card_list failed. err is %d.", ret);
        return ret;
    }
    // 调用接口初始化dmp进程流程，无实际使用意义
    for (index = 0; index < device_cnt; index++) {
        if (device_list[index] != -1) {
            break;
        }
    }

    ret = dsmi_get_device_die(device_list[index], &die_struct);
    if (ret != DSMI_OK) {
        gplog(LOG_ERR, "call dsmi_get_device_die failed. err is %d.", ret);
        return dcmi_convert_error_code(ret);
    }

    ret = dsmi_subscribe_fault_event(device_id, *(struct dsmi_event_filter *)&filter,
        (fault_event_callback)handler);
    if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
        gplog(LOG_ERR, "call dcmi_subscribe_npu_fault_event failed. err is %d.", ret);
    }

    return dcmi_convert_error_code(ret);
}
#endif