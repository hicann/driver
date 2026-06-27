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

#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_common.h"
#include "dcmi_init_basic.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_flash_intf.h"
#include "dcmi_permission_judge.h"
#include "dcmi_basic_info_intf.h"

#if defined DCMI_VERSION_2
int dcmiv2_get_device_flash_cnt(int dev_id, unsigned int *flash_cnt)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (flash_cnt == NULL) {
        gplog(LOG_ERR, "flash_count is invalid.");
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
        return dcmi_get_npu_device_flash_count(card_id, device_id, flash_cnt);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_device_flash_info(int dev_id, unsigned int flash_index,
    struct dcmi_flash_info *flash_info)
{
    int err, card_id, device_id;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (flash_info == NULL) {
        gplog(LOG_ERR, "flash_info is invalid.");
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
        return dcmi_get_npu_device_flash_info(card_id, device_id, flash_index, flash_info);
    } else {
        gplog(LOG_ERR, "device_type %d is error.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}
#endif

int dcmiv2_get_device_hbm_product_info(int dev_id, struct dcmi_hbm_product_info *hbm_product_info)
{
    int ret;
    enum dcmi_unit_type device_type = NPU_TYPE;
    unsigned int manufacturer_id = 0xffffffff;

    if (hbm_product_info == NULL) {
        gplog(LOG_ERR, "hbm_product_info is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_ERR, "This device does not support get hbm product info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (ret=%d)", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        ret = dsmi_get_hbm_manufacturer_id(dev_id, &manufacturer_id);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "call dsmi_get_hbm_manufacturer_id failed. (manufacturer_id is 0x%X, ret=%d)",
                manufacturer_id, ret);
            return dcmi_convert_error_code(ret);
        }

        ret = dcmi_check_hbm_manufacturer_id(manufacturer_id);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Check hbm manufacturer_id failed. (dev_id=%d, ret=%d)",
                dev_id, ret);
            return ret;
        }

        hbm_product_info->manufacturer_id = (unsigned short)(manufacturer_id & 0xFF);
        return ret;
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_multi_ecc_time_info(int dev_id, struct dcmi_multi_ecc_time_data *multi_ecc_time_data)
{
    int ret, card_id, device_id;
 
    if (multi_ecc_time_data == NULL) {
        gplog(LOG_ERR, "multi_ecc_time_data is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d.)", ret);
        return ret;
    }
 
    if (dcmi_check_vnpu_in_docker(card_id, device_id) == DCMI_ERR_CODE_NOT_SUPPORT_IN_CONTAINER) {
        gplog(LOG_OP, "dev_id %d is in vnpu mode can not get multi ecc time info.", dev_id);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dsmi_get_multi_ecc_time_info(dev_id, (struct dsmi_multi_ecc_time_data *)multi_ecc_time_data);
    if (ret != DSMI_OK) {
        gplog(LOG_ERR, "call dsmi_get_multi_ecc_time_info failed. (ret=%d)", ret);
        return dcmi_convert_error_code(ret);
    }
    return ret;
}
 
int dcmiv2_get_multi_ecc_record_info(int dev_id, struct dcmi_ecc_record_type type,
    unsigned int *ecc_count, struct dcmi_ecc_common_data *ecc_common_data_s)
{
    int ret, card_id, device_id;
 
    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d.)", ret);
        return ret;
    }
 
    if (ecc_common_data_s == NULL || ecc_count == NULL) {
        gplog(LOG_ERR, "ecc_common_data_s or ecc_count is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    if ((type.read_type != SINGLE_ECC_INFO_READ) && (type.read_type != MULTI_ECC_INFO_READ)) {
        // 仅支持获取单比特和多比特ecc信息
        gplog(LOG_OP, "This read_type does not support get multi ecc record info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
    if (dcmi_check_vnpu_in_docker(card_id, device_id) == DCMI_ERR_CODE_NOT_SUPPORT_IN_CONTAINER) {
        gplog(LOG_OP, "dev_id %d is in vnpu mode can not get multi ecc record info.", dev_id);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if ((dcmi_board_chip_type_is_ascend_310p()) && (type.module_type == (enum dcmi_device_type)DSMI_DEVICE_TYPE_HBM)) {
        gplog(LOG_ERR, "module_type is not support. (module_type=%d)",  type.module_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
 
    ret = dsmi_get_multi_ecc_record_info(dev_id, ecc_count,
        type.read_type, type.module_type, (struct dsmi_ecc_common_data *)ecc_common_data_s);
    if (ret != DSMI_OK) {
        gplog(LOG_ERR, "call dsmi_get_multi_ecc_record_info failed. (ret=%d)", ret);
        return dcmi_convert_error_code(ret);
    }
    return ret;
}