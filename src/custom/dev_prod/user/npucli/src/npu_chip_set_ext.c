/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdbool.h>
#include <stdio.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "npu_error_code.h"
#include "npu_common.h"
#include "dcmi_log.h"
#include "dcmi_inner_cfg_manage.h"
#include "npu_set_print.h"
#include "npu_file_operate.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_product_judge.h"
#include "dcmi_hot_reset_intf.h"
#include "dcmi_inner_cfg_persist.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_environment_judge.h"
#include "dcmi_permission_judge.h"
#include "npu_chip_set.h"

static void print_cert_set_status(struct npu_smi_operate_info *operate_info, int ret)
{
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return;
    } else if (ret == NPU_ERR_CODE_PARTITION_NOT_RIGHT) {
        printf("The certificate does not match the CSR file of %s.\n", operate_info->stype);
        return;
    } else if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to set %s.\n", "Message", operate_info->stype);
        return;
    }

    gplog(LOG_OP, "Set %s for card %d chip %d successfully.", operate_info->stype,
          operate_info->id, operate_info->chip_id);
    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : The %s of the chip is set successfully.\n", "Message", operate_info->stype);
    return;
}

static int set_tls_cert_period_inner_work(struct npu_smi_operate_info *operate_info)
{
    int ret, period = -1;
    unsigned char cert_period;
    const char *buf = operate_info->sdata;

    ret = str2int(&period, buf);
    if ((ret != NPU_OK) || (period < CERT_PERIOD_MIN) || (period > CERT_PERIOD_MAX)) {
        gplog(LOG_ERR, "Input para of -s is invalid, period is %d, ret of str_to_int is %d, err is %d.",
            period, ret, NPU_ERR_CODE_INVALID_PARAMETER);
        gplog(LOG_OP, "Failed to set tls cert period.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    cert_period = (unsigned char)period;
#ifndef NPU_SMI_V2
    ret = dcmi_set_user_config(operate_info->id, operate_info->chip_id, CERT_CONFIG_EXPIRED, 1, &cert_period);
#else
    ret = dcmiv2_set_device_user_config(operate_info->id, CERT_CONFIG_EXPIRED, 1, (char*)&cert_period);
#endif
    if (ret != DCMI_OK) {
        print_cert_set_status(operate_info, ret);
        gplog(LOG_OP, "Failed to set tls cert period, err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    print_cert_set_status(operate_info, ret);
    return NPU_OK;
}

int set_tls_cert_period(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
#ifndef NPU_SMI_V2
    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b() ||
        dcmi_board_chip_type_is_ascend_310p()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        print_cert_set_status(operate_info, NPU_ERR_CODE_NOT_SUPPORT);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#else
    operate_info->chip_id=0;
    if (!(dcmi_board_chip_type_is_ascend_950())||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        print_cert_set_status(operate_info, NPU_ERR_CODE_NOT_SUPPORT);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#endif

    if ((dcmi_board_type_is_310p_duo_chips() || dcmi_board_chip_type_is_ascend_910_93()) &&
        (operate_info->chip_id != 0)) {
        gplog(LOG_OP, "The Atlas 300I Duo card and 910_93 is only supported on chip 0.");
        print_cert_set_status(operate_info, NPU_ERR_CODE_NOT_SUPPORT);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = set_tls_cert_period_inner_work(operate_info);
    return ret;

#else
    gplog(LOG_OP, "unsupport set %s.", operate_info->stype);
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int reset_operation_with_v2(struct npu_smi_operate_info *operate_info)
{
    int ret;
    if (operate_info == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    
    // 预复位
#ifndef NPU_SMI_V2
    ret = dcmi_pre_reset_soc(operate_info->id, operate_info->chip_id);
#else
    ret = dcmiv2_pre_reset_device(operate_info->id);
#endif
    if (ret != DCMI_OK) {
        printf("Failed to start prereset chip %d.\n", operate_info->chip_id);
        printf("Please reboot OS to reset card.\n");
        return ret;
    }

    // 复位
#ifndef NPU_SMI_V2
    ret = dcmi_reset_device(operate_info->id, operate_info->chip_id);
#else
    ret = dcmiv2_reset_device(operate_info->id, OUTBAND_CHANNEL);
#endif
    if (ret != DCMI_OK) {
        printf("Failed to reset chip %d in card %d.\n", operate_info->chip_id, operate_info->id);
        printf("Please reboot OS to reset card.\n");
        return ret;
    }

    sleep(3); // 延时3s

    // 重新扫描
#ifndef NPU_SMI_V2
    ret = dcmi_rescan_soc(operate_info->id, operate_info->chip_id);
#else
    ret = dcmiv2_rescan_device(operate_info->id);
#endif
    if (ret != DCMI_OK) {
        printf("Failed to rescan chip %d.\n", operate_info->chip_id);
        printf("Please reboot OS to reset card.\n");
        return ret;
    }

    return ret;
}