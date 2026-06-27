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
#include "dcmi_init_basic.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_common.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_cert_manage_intf.h"
 
int dcmiv2_revoke_device_sec_key(int dev_id, enum dcmi_revo_type input_type, const unsigned char *file_data,
    unsigned int file_size)
{
    int err;
    enum dcmi_unit_type device_type = NPU_TYPE;
 
    if (!dcmi_is_in_phy_machine_root()) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical machine can call this api.");
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }
 
    if (file_data == NULL) {
        gplog(LOG_ERR, "file_data is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    bool check_result = ((input_type >= DCMI_REVOCATION_TYPE_MAX) || (file_size != SEC_REVOCATION_FILE_LEN));
    if (check_result) {
        gplog(LOG_ERR, "input para is invalid. input_type=%d file_size=%u", input_type, file_size);
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
        err = dsmi_set_sec_revocation(dev_id, (DSMI_REVOCATION_TYPE)input_type, file_data, file_size);
        if (err != DSMI_OK) {
            if (err != DSMI_ERR_NOT_SUPPORT) {
                gplog(LOG_ERR, "call dsmi_set_sec_revocation failed. err is %d.", err);
            }
            return dcmi_convert_error_code(err);
        }
    } else {
        gplog(LOG_OP, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
 
    gplog(LOG_OP, "set sec revocation success. dev_id=%d, revo_type=%d", dev_id, input_type);
    return DCMI_OK;
}

int dcmiv2_get_attest_akcert(int dev_id, unsigned char *ak_cert, unsigned int *ak_cert_len)
{
    int ret;
    struct ATTEST_OPERATE_RESPONSE rep = {0};
    unsigned int buffer_len = 0;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (ak_cert == NULL || ak_cert_len == NULL) {
        gplog(LOG_ERR, "ak_cert is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    buffer_len = *ak_cert_len;

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return ret;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (device_type == NPU_TYPE) {
        ret = dsmi_attest_get_akcert(dev_id, ak_cert_len, &rep);
        if (ret != 0) {
            gplog(LOG_ERR, "dsmi_attest_get_akcert failed.(device_logic_id=%d,ret=%d)", dev_id, ret);
            return dcmi_convert_error_code(ret);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    *ak_cert_len = rep.data_len;

    ret = memcpy_s(ak_cert, buffer_len, rep.data, *ak_cert_len);
    if (ret != 0) {
        gplog(LOG_ERR, "memcpy_s failed.(buffer_len=%d, ret=%d", buffer_len, ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    return ret;
}

int dcmiv2_get_attest_evidence(int dev_id, struct attest_ctx *ctx,
    unsigned char *evidence, unsigned int *evidence_len)
{
    int ret;
    struct ATTEST_OPERATE_REQUEST req = {0};
    struct ATTEST_OPERATE_RESPONSE rep = {0};
    unsigned int buffer_len = 0;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (evidence == NULL || evidence_len == NULL || ctx == NULL) {
        gplog(LOG_ERR, "evidence is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    buffer_len = *evidence_len;

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return ret;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
 
    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    req.evidence_type = ctx->evidence_type;
    req.challenge_len = ctx->challenge_len;
    req.evidence_len = *evidence_len;

    ret = memcpy_s(req.challenge, MAX_CHALLENGE_LEN, ctx->challenge, ctx->challenge_len);
    if (ret != 0) {
        gplog(LOG_ERR, "memcpy_s failed, ret = %d", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    do {
        ret = dsmi_attest_get_evidence(dev_id, &req, &rep);
        if (ret != 0) {
            gplog(LOG_ERR, "dsmi_attest_get_evidence failed, device_logic_id = %d,ret = %d", dev_id, ret);
            return dcmi_convert_error_code(ret);
        }
        *evidence_len = rep.data_len;
        ret = memcpy_s(evidence + req.start_len, buffer_len - req.start_len, rep.data, rep.copied_len);
        if (ret != 0) {
            gplog(LOG_ERR, "memcpy_s failed, ret = %d", ret);
            return DCMI_ERR_CODE_SECURE_FUN_FAIL;
        }
        req.start_len += rep.copied_len;
        gplog(LOG_INFO, "start len = %u, copied len = %u, remain len = %u",
            req.start_len, rep.copied_len, rep.remain_len);
    } while (rep.remain_len > 0);

    return ret;
}