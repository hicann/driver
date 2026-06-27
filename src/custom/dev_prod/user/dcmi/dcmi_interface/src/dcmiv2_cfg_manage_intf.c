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
#ifndef _WIN32
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#endif
#include <errno.h>
#include "securec.h"
#include "dcmi_log.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_common.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_network_intf.h"
#include "dcmi_inner_cfg_persist.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_permission_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_basic_info_intf.h"

int dcmiv2_clear_device_user_config(int dev_id, const char *config_name)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (!dcmi_is_in_phy_machine_root()) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (config_name == NULL) {
        gplog(LOG_ERR, "config_name is invalid.");
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
        err = dsmi_clear_user_config(dev_id, config_name);
        if (err != DSMI_OK) {
            if (err != DSMI_ERR_NOT_SUPPORT) {
                gplog(LOG_ERR, "call dsmi_clear_user_config failed. err is %d.", err);
            }
            return dcmi_convert_error_code(err);
        }
    } else {
        gplog(LOG_OP, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    gplog(LOG_OP, "clear user config success. dev_id=%d", dev_id);
    return DCMI_OK;
}

int dcmiv2_get_device_user_config(int dev_id, const char *config_name, unsigned int buf_size, unsigned char *buf)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    err = dcmi_check_user_config_parameter(config_name, buf_size, buf);
    if (err != DCMI_OK) {
        return err;
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
        return dcmi_get_npu_device_user_config(card_id, device_id, config_name, buf_size, buf);
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_set_device_user_config(int dev_id, const char *config_name, unsigned int buf_size, char *buf)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (!dcmi_is_in_phy_machine_root()) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    err = dcmi_check_user_config_parameter(config_name, buf_size, (unsigned char *)buf);
    if (err != DCMI_OK) {
        return err;
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
        err = dcmi_set_npu_device_user_config(card_id, device_id, config_name, buf_size, (unsigned char *)buf);
        if (err != DCMI_OK) {
            gplog(LOG_OP, "set user config failed. dev_id=%d,err=%d", dev_id, err);
            return err;
        }

        gplog(LOG_OP, "set user config success. dev_id=%d", dev_id);
        return DCMI_OK;
    }
    gplog(LOG_OP, "device_type %d is not support.", device_type);
    return DCMI_ERR_CODE_NOT_SUPPORT;
}

int dcmiv2_set_device_share_enable(int dev_id, unsigned int enable_flag)
{
    int err;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    unsigned int size = sizeof(unsigned int);
    int chip_id = 0;

    if (!(dcmi_is_in_phy_privileged_docker_root() || dcmi_is_in_phy_machine_root())) {
        gplog(LOG_OP,
            "Operation not permitted, only root user on physical machine or on physical privileged container"
            " can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (enable_flag != 0 && enable_flag != 1) {
        gplog(LOG_ERR, "enable_flag %u is invalid.", enable_flag);
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
        err = dsmi_set_device_info(dev_id, DSMI_MAIN_CMD_EX_CONTAINER, DSMI_EX_CONTAINER_SUB_CMD_SHARE,
        (void *)&enable_flag, size);
        if (err != DSMI_OK) {
            gplog(LOG_ERR, "call dsmi_set_device_info failed. err is %d.", err);
            return dcmi_convert_error_code(err);
        }
    } else {
        gplog(LOG_OP, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return handle_device_share_cfg(dev_id, chip_id, &enable_flag);
}

int dcmiv2_set_device_share_config_recover_mode(unsigned int enable_flag)
{
    int ret;

    ret = dcmi_check_device_share_config_recover_mode_is_permitted("set");
    if (ret != DCMI_OK) {
        return ret;
    }

    if ((enable_flag != DCMI_CFG_RECOVER_ENABLE) && (enable_flag != DCMI_CFG_RECOVER_DISABLE)) {
        gplog(LOG_ERR,
            "dcmi_set_device_share_config_recover_mode: parameter enable_flag [%u] is invalid.", enable_flag);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_cfg_set_device_share_config_recover_mode(enable_flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "set device-share config recover enable_flag [%u] failed. ret=%d", enable_flag, ret);
        return ret;
    }

    gplog(LOG_OP, "dcmi set device-share config recover enable_flag %s success",
        (enable_flag == DCMI_CFG_RECOVER_ENABLE) ? "enable" : "disable");
    return DCMI_OK;
}

int dcmiv2_set_netdev_mac(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    const char *mac_addr, unsigned int mac_addr_len)
{
    int err;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    /* 权限检查 */
    err = dcmi_netdev_permission_judge(dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_permission_judge failed. (ret=%d)", err);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    /* 参数校验 */
    if (dev_id < 0 || mac_addr == NULL || mac_addr_len != MAC_ADDR_LEN) {
        gplog(LOG_ERR, "Parameter is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    err = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "Parameter is invalid.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    /* 产品类型校验 */
    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_set_netdev_mac_addr(dev_id, netdev_name, netdev_name_len, mac_addr, mac_addr_len);
        if ((err != DSMI_OK)) {
            gplog(LOG_ERR, "call dsmi_set_netdev_mac_addr failed. err is %d.", err);
            return dcmi_convert_error_code(err);
        }
        gplog(LOG_OP, "set device mac success. (dev_id=%d, netdev_name=%s)", dev_id, netdev_name);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_set_netdev_gateway(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dcmi_ip_addr *gateway)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    err = dcmi_netdev_permission_judge(dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_permission_judge failed. (ret=%d)", err);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

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
        gplog(LOG_OP, "This device does not support set device gateway.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_device_type failed. (ret=%d)", err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_set_netdev_gateway(dev_id, netdev_name, netdev_name_len, (struct dsmi_ip_addr *)gateway);
        if (err != DSMI_OK) {
            gplog(LOG_ERR, "call dsmi_set_netdev_gateway failed. (ret=%d)", err);
            return dcmi_convert_error_code(err);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_set_netdev_ip(int dev_id, const char *netdev_name, unsigned int netdev_name_len, struct dcmi_ip_addr *ip,
                         struct dcmi_ip_addr *mask)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;

    err = dcmi_netdev_permission_judge(dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_permission_judge failed. (dev_id=%d; ret=%d)", dev_id, err);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

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
        gplog(LOG_OP, "This device does not support set device ip.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (dev_id=%d; ret=%d).", dev_id, err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_set_device_bond_ip_address(dev_id, netdev_name, netdev_name_len, (struct dsmi_ip_addr *)ip,
                                              (struct dsmi_ip_addr *)mask);
        if (err != DCMI_OK) {
            gplog(LOG_ERR, "call dsmi_set_device_bond_ip_address failed. (dev_id=%d; ret=%d).", dev_id, err);
            return dcmi_convert_error_code(err);
        }
        gplog(LOG_OP, "set device ip success. (dev_id=%d; bond=%s)", dev_id, netdev_name);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_clear_device_ecc_stats_info(int dev_id)
{
    int err;
    int card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (!dcmi_is_in_phy_machine_root()) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", err);
        return err;
    }

    err = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. err is %d.", err);
        return err;
    }

    if (dcmi_check_card_is_split_phy(card_id) == TRUE) {
        // 910B算力切分场景下，不支持该命令
        gplog(LOG_OP,
            "In the vNPU scenario, this device does not support dcmiv2_clear_device_ecc_stats_info.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (device_type == NPU_TYPE) {
        gplog(LOG_OP, "Clean Ecc Isolated Statistics Info:dev_id=%d.", dev_id);
        err = dsmi_clear_ecc_isolated_statistics_info(dev_id);
        if (err != DSMI_OK) {
            gplog(LOG_ERR, "call dsmi_clear_ecc_isolated_statistics_info failed. err is %d.", err);
            return dcmi_convert_error_code(err);
        }
        gplog(LOG_OP, "clear ecc statistics info success. dev_id=%d", dev_id);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
    return DCMI_OK;
}