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
#include <signal.h>
#include <unistd.h>

#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_permission_judge.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_ipmi.h"
#include "dcmi_os_adapter.h"
#include "dcmi_product_judge.h"
#include "dcmi_npu_link_intf.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_environment_judge.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_hot_reset_intf.h"

int dcmiv2_get_device_outband_channel_state(int dev_id, int *channel_state)
{
    enum dcmi_unit_type device_type = NPU_TYPE;
    int ret;
    int card_id, device_id;

    if (channel_state == NULL) {
        gplog(LOG_ERR, "channel state is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    // 支持物理机和A5 Pod特权容器场景
    if (!dcmi_is_in_phy_machine_root() && !(dcmi_is_in_privileged_docker_root() &&
         (dcmi_board_chip_type_is_ascend_950_pod() || dcmi_board_chip_type_is_ascend_950_server()))) {
        gplog(LOG_ERR, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_device_type failed.(ret=%d)", ret);
        return ret;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", ret);
        return ret;
    }

    // 310p双芯片卡为smp模式，仅支持对device id 0进行预复位
    if ((device_type == NPU_TYPE) && ((dcmi_board_type_is_310p_duo_chips() != TRUE) || (device_id == 0))) {
        ret = dcmi_get_device_npu_outband_channel_state(card_id, device_id, channel_state);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "call dcmi_get_device_npu_outband_channel_state failed, (dev_id=%d, ret=%d)",
                dev_id, ret);
            return ret;
        }
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_pre_reset_device(int dev_id)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;
 
    // 支持物理机和A5 Pod及Server特权容器场景
    if (!dcmi_is_in_phy_machine_root() && !(dcmi_is_in_privileged_docker_root() &&
        (dcmi_board_chip_type_is_ascend_950_pod() ||
         dcmi_board_chip_type_is_ascend_950_server()))) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }
 
    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        return err;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dcmi_set_npu_device_pre_reset(card_id, device_id);
        if (err != DCMI_OK) {
            gplog(LOG_OP, "set pre reset failed. dev_id=%d, err=%d", dev_id, err);
            return err;
        }
 
        gplog(LOG_OP, "set pre reset success. dev_id=%d", dev_id);
        return DCMI_OK;
    } else {
        gplog(LOG_OP, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}
 
int dcmiv2_reset_device(int dev_id, enum dcmi_reset_channel channel_type)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;
 
    err = dcmi_check_device_reset_permission(channel_type);
    if (err != DCMI_OK) {
        return err;
    }
 
    if (dev_id == ALL_DEVICE_RESET_CARD_ID && channel_type != INBAND_CHANNEL) {
        gplog(LOG_ERR, "This device_id is not supported in this scenario.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        return err;
    }
 
    if ((dev_id != ALL_DEVICE_RESET_CARD_ID) && dcmi_board_chip_type_is_ascend_950()) {
        err = dcmiv2_get_device_type(dev_id, &device_type);
        if (err != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
            return err;
        }
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
 
    if (device_type != NPU_TYPE) {
        gplog(LOG_OP, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
 
    err = execute_npu_reset(card_id, device_id, channel_type);
    if (err != DCMI_OK) {
        gplog(LOG_OP, "reset failed. dev_id=%d, channel_type=%d, err=%d", dev_id, channel_type, err);
        return err;
    }
 
    gplog(LOG_OP, "reset success. dev_id=%d, channel_type=%d", dev_id, channel_type);
    return DCMI_OK;
}
 
int dcmiv2_rescan_device(int dev_id)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;
 
    // 支持物理机和A5 Pod,Server特权容器
    if (!dcmi_is_in_phy_machine_root() && !(dcmi_is_in_privileged_docker_root() &&
        (dcmi_board_chip_type_is_ascend_950_pod() ||
         dcmi_board_chip_type_is_ascend_950_server()))) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }
 
    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        return err;
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
        err = dcmi_set_npu_device_rescan(card_id, device_id);
        if (err != DCMI_OK) {
            gplog(LOG_OP, "set device rescan failed. dev_id=%d, err=%d", dev_id, err);
            return err;
        }
 
        gplog(LOG_OP, "set device rescan success. dev_id=%d", dev_id);
        return DCMI_OK;
    } else {
        gplog(LOG_OP, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}