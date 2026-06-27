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
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <time.h>
#include "securec.h"
#include "dcmi_log.h"
#include "npu_common.h"
#include "npu_chip_info.h"
#include "npu_chip_info_ext.h"
#include "npu_info.h"
#include "npu_info_print.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_common.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_i2c_operate.h"
#include "dcmi_environment_judge.h"

STATIC void copy_elabel_info(struct dcmi_elabel_info *elabel_info, struct npu_device_info *device_info)
{
    int ret;

    if (device_info == NULL) {
        gplog(LOG_ERR, "device_info is NULL.");
        return;
    }

    ret = memcpy_s(device_info->serial_number, MAX_LENTH, elabel_info->serial_number, MAX_LENTH);
    if (ret != EOK) {
        gplog(LOG_ERR, "copy serial_number failed. err is %d.", ret);
    }

    ret = memcpy_s(device_info->manufacturer, MAX_LENTH, elabel_info->manufacturer, MAX_LENTH);
    if (ret != EOK) {
        gplog(LOG_ERR, "copy manufacturer failed. err is %d.", ret);
    }

    ret = memcpy_s(device_info->product_name, MAX_LENTH, elabel_info->product_name, MAX_LENTH);
    if (ret != EOK) {
        gplog(LOG_ERR, "copy product_name failed. err is %d.", ret);
    }

    ret = memcpy_s(device_info->model, MAX_LENTH, elabel_info->model, MAX_LENTH);
    if (ret != EOK) {
        gplog(LOG_ERR, "copy model failed. err is %d.", ret);
    }
}

STATIC void set_default_elabel_info(struct npu_device_info *device_info)
{
    int ret;

    if (device_info == NULL) {
        gplog(LOG_ERR, "device_info is NULL.");
        return;
    }

    ret = strcpy_s(device_info->serial_number, MAX_LENTH, "NA");
    if (ret != 0) {
        gplog(LOG_ERR, "copy serial_number failed. err is %d.", ret);
    }

    ret = strcpy_s(device_info->manufacturer, MAX_LENTH, "NA");
    if (ret != 0) {
        gplog(LOG_ERR, "copy manufacturer failed. err is %d.", ret);
    }

    ret = strcpy_s(device_info->product_name, MAX_LENTH, "NA");
    if (ret != 0) {
        gplog(LOG_ERR, "copy product_name failed. err is %d.", ret);
    }

    ret = strcpy_s(device_info->model, MAX_LENTH, "NA");
    if (ret != 0) {
        gplog(LOG_ERR, "copy model failed. err is %d.", ret);
    }
}
#ifndef NPU_SMI_V2
STATIC int npu_get_card_version_info(int card_id, struct npu_device_info *device_info)
{
    int ret;
    int dev_id;
    int device_num = 0;
    enum dcmi_device_compat compatibility = DCMI_COMPAT_UNKNOWN;

    // 获取不到固件版本时，设定默认值为NA
    ret = memcpy_s(device_info->firmware_version, sizeof("NA"), "NA", sizeof("NA"));
    if (ret != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is  %d.", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }
    if (npu_check_is_has_d_chip() == TRUE) {
        ret = dcmi_get_driver_version(device_info->software_version, MAX_LENTH);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to get software version. err is %d", ret);
            return dcmi_to_npu_error_code(ret);
        }

        ret = npu_get_chip_firmware_version(card_id, 0, device_info->firmware_version,
            sizeof(device_info->firmware_version));
        if ((ret != NPU_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT) && (ret != DCMI_ERR_CODE_OPER_NOT_PERMITTED)) {
            gplog(LOG_ERR, "Failed to get firmware version. err is %d", ret);
        }
    }

    if (npu_board_type_is_soc() != TRUE) {
        ret = dcmi_get_device_num_in_card(card_id, &device_num);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to get device num. err is %d", ret);
            device_info->compat_info.err = ret;
            device_info->compat_info.compatibility = DCMI_COMPAT_UNKNOWN;
            return NPU_OK;
        }
        for (dev_id = 0; dev_id < device_num; dev_id++) {
            ret = dcmi_get_device_compatibility(card_id, dev_id, &compatibility);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "Failed to get device compatibility. err is %d", ret);
                break;
            }
            if ((compatibility == DCMI_COMPAT_UNKNOWN) || (compatibility == DCMI_COMPAT_NOK)) {
                break;
            }
        }
        device_info->compat_info.err = ret;
        device_info->compat_info.compatibility = compatibility;
    }
    return NPU_OK;
}
#else
STATIC int npu_get_card_version_info(int card_id, struct npu_device_info *device_info)
{
    int ret;
    enum dcmi_device_compat compatibility = DCMI_COMPAT_UNKNOWN;

    // 获取不到固件版本时，设定默认值为NA
    ret = memcpy_s(device_info->firmware_version, sizeof("NA"), "NA", sizeof("NA"));
    if (ret != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is  %d.", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }
    if (npu_check_is_has_d_chip() == TRUE) {
        ret = dcmiv2_get_driver_version(device_info->software_version, MAX_LENTH);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to get software version. err is %d", ret);
            return dcmi_to_npu_error_code(ret);
        }

        ret = npu_get_chip_firmware_version(card_id, 0, device_info->firmware_version,
            sizeof(device_info->firmware_version));
        if ((ret != NPU_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT) && (ret != DCMI_ERR_CODE_OPER_NOT_PERMITTED)) {
            gplog(LOG_ERR, "Failed to get firmware version. err is %d", ret);
        }
    }

    if (npu_board_type_is_soc() != TRUE) {
        ret = dcmiv2_get_device_compatibility(card_id, &compatibility);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to get device compatibility. err is %d", ret);
        }
        device_info->compat_info.err = ret;
        device_info->compat_info.compatibility = compatibility;
    }
    return NPU_OK;
}
#endif

#ifdef NPU_SMI_V2
STATIC int dcmiv2_get_device_pcie_info_inner(int card_id, struct npu_device_info *device_info)
{
    int ret;
    if (dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
        ret = dcmiv2_get_device_ub_id_info(card_id, &device_info->device_ub_id_info);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmiv2_get_device_ub_id_info failed. (ret=%d)", ret);
            return dcmi_to_npu_error_code(ret);
        }
    } else {
        ret = dcmiv2_get_device_pcie_info(card_id, &device_info->device_pcie_info);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmiv2_get_device_pcie_info failed. (ret=%d)", ret);
            return dcmi_to_npu_error_code(ret);
        }
    }
    ret = dcmiv2_get_device_pcie_slot_id(card_id, &device_info->slot_id);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT) && (ret != DCMI_ERR_CODE_OPER_NOT_PERMITTED)) {
        gplog(LOG_ERR, "dcmiv2_get_device_pcie_slot_id failed. (ret=%d)", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    return NPU_OK;
}
#else
STATIC int dcmi_get_device_pcie_info_inner(int card_id, struct npu_device_info *device_info)
{
    int ret;
    ret = dcmi_get_device_pcie_info_v2(card_id, 0, &device_info->device_pcie_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_pcie_info_v2 failed. (ret=%d)", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmi_get_card_pcie_info(card_id, device_info->pcie_info, sizeof(device_info->pcie_info));
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_card_pcie_info failed. (ret=%d)", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    ret = dcmi_get_card_pcie_slot(card_id, &device_info->slot_id);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT) && (ret != DCMI_ERR_CODE_OPER_NOT_PERMITTED)) {
        gplog(LOG_ERR, "dcmi_get_card_pcie_slot failed. (ret=%d)", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    return NPU_OK;
}
#endif

STATIC int npu_get_card_pcie_info(int card_id, struct npu_device_info *device_info)
{
    int ret;
    if (npu_board_type_is_card() || npu_board_type_is_server()) {
#ifdef NPU_SMI_V2
        ret = dcmiv2_get_device_pcie_info_inner(card_id, device_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "dcmiv2_get_pcie_info_inner failed. (ret=%d)", ret);
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }
#else
        ret = dcmi_get_device_pcie_info_inner(card_id, device_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "dcmi_get_pcie_info_inner failed. (ret=%d)", ret);
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }
#endif
    }
    return NPU_OK;
}

STATIC int npu_get_card_info_basic(int card_id, struct npu_device_info *device_info)
{
    int ret;

    // 1. 获取卡版本信息
    ret = npu_get_card_version_info(card_id, device_info);
    if (ret != NPU_OK) {
        return ret;
    }

    // 2. 获取设备ID信息
    ret = npu_get_card_device_id(card_id, &device_info->chip_count, &device_info->mcu_id, &device_info->cpu_id);
    if (ret != NPU_OK) {
        return ret;
    }

    return NPU_OK;
}

STATIC int npu_get_card_info(int card_id, struct npu_device_info *device_info)
{
    int ret;
    struct dcmi_elabel_info elabel_info = { { 0 } };

    ret = npu_get_card_info_basic(card_id, device_info);
    if (ret != NPU_OK) {
        return ret;
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_fault_device_num_in_card(card_id, &device_info->chip_fault);
#else
    ret = dcmi_get_fault_device_num_in_card(card_id, &device_info->chip_fault);
#endif
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_OPER_NOT_PERMITTED)) {
        gplog(LOG_ERR, "Failed to query chip number of card %d.", card_id);
        return dcmi_to_npu_error_code(ret);
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_board_info(card_id, &device_info->board_info);
#else
    ret = dcmi_get_card_board_info(card_id, &device_info->board_info);
#endif
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "Failed to query board info of card %d.", card_id);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = dcmiv2_get_mainboard_id(card_id, &device_info->main_board_id);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to query main board id of card. err is %d", ret);
            return dcmi_to_npu_error_code(ret);
        }
    }

    device_info->npu_id = card_id;

    ret = npu_get_card_pcie_info(card_id, device_info);
    if (ret != NPU_OK) {
        return ret;
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_elabel_info(card_id, &elabel_info);
#else
    ret = dcmi_get_card_elabel_v2(card_id, &elabel_info);
#endif
    if (ret == DCMI_OK) {
        copy_elabel_info(&elabel_info, device_info);
    } else {
        set_default_elabel_info(device_info);
    }
    return NPU_OK;
}

#if defined(NPU_SMI_V2) && !defined(ORIENT_CH)
STATIC int npu_get_chip_base_info(int card_id, struct npu_chip_info *chip_info)
{
    int ret;
    // 获取不到固件版本时，设定默认值为NA
    ret = memcpy_s(chip_info->xloader_version, sizeof("NA"), "NA", sizeof("NA"));
    if (ret != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is  %d.", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = dcmiv2_get_device_component_static_version(card_id, DCMI_COMPONENT_TYPE_HILINK,
        (unsigned char *)chip_info->xloader_version, (int)sizeof(chip_info->xloader_version));
    // npu-smi info -t board -i，非root查询固件版本为默认值NA
    if (ret != DCMI_OK && ret != DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
        printf("Failed to get device firmware version information.\n");
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmiv2_get_device_pcie_info(card_id, &chip_info->device_pcie_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        printf("Failed to get device pcie information.\n");
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    return NPU_OK;
}

STATIC int npu_get_chip_info(int card_id, struct npu_chip_info *chip_info)
{
    int ret;

    chip_info->npu_id = card_id;

    ret = dcmiv2_get_device_die_id(card_id, DDIE, &chip_info->ddie_id);
    if ((ret != DCMI_OK)) {
        gplog(LOG_ERR, "dcmiv2_get_device_die_id failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = npu_get_chip_base_info(card_id, chip_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_chip_base_info failed. err is %d", ret);
        return ret;
    }

    ret = dcmiv2_get_device_chip_info(chip_info->npu_id, &chip_info->chip_info);
    if ((ret != DCMI_OK)) {
        gplog(LOG_ERR, "dcmiv2_get_device_chip_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmiv2_get_device_board_info(chip_info->npu_id, &chip_info->board_info);
    if ((ret != DCMI_OK)) {
        gplog(LOG_ERR, "dcmiv2_get_device_board_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmiv2_get_device_chip_slot(chip_info->npu_id, &chip_info->chip_pos_id);
    if ((ret != DCMI_OK)) {
        gplog(LOG_ERR, "dcmiv2_get_device_chip_slot failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    return NPU_OK;
}

STATIC int show_npu_board_info(struct npu_smi_operate_info *operate_info)
{
    int ret;

    struct npu_device_info *device_info = (struct npu_device_info *)calloc(1, sizeof(struct npu_device_info));
    if (device_info == NULL) {
        gplog(LOG_ERR, "device_info calloc failed.");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    struct npu_chip_info *chip_info = (struct npu_chip_info *)calloc(1, sizeof(struct npu_chip_info));
    if (chip_info == NULL) {
        gplog(LOG_ERR, "chip_info calloc failed.");
        free(device_info);
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = npu_get_card_info(operate_info->id, device_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to query npu_device_info. err is %d", ret);
    }
    ret = npu_get_chip_info(operate_info->id, chip_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to query npu_chip_info. err is %d", ret);
    }

    if (ret == NPU_OK) {
        print_npu_info(device_info, chip_info);
    } else {
        printf("get npu info failed!\n");
    }

    free(chip_info);
    free(device_info);
    return ret;
}

// ID整改引入，暂时同时查询card和chip的信息用于-t board回显
STATIC int show_ascend_npu_board_info(struct npu_smi_operate_info *operate_info)
{
    return show_npu_board_info(operate_info);
}
#else

STATIC int npu_get_card_board_info(int card_id, struct npu_device_info *device_info)
{
    int ret;
    enum npu_chip_type chip_type = npu_get_chip_type();

#ifndef NPU_SMI_V2
    ret = dcmi_get_card_board_info(card_id, &device_info->board_info);
#else
    ret = dcmiv2_get_device_board_info(card_id, &device_info->board_info);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to query board info of card. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (chip_type == NPU_CHIP_910_93) {
        ret = dcmi_get_mainboard_id(card_id, 0, &device_info->main_board_id);
    } else if (chip_type == NPU_CHIP_950) {
#ifndef ENABLE_EQUIPMENT
        ret = dcmiv2_get_mainboard_id(card_id, &device_info->main_board_id);
#else
        ret = dcmi_get_mainboard_id(card_id, 0, &device_info->main_board_id);
#endif
    }
    if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to query main board id of card. err is %d", ret);
            return dcmi_to_npu_error_code(ret);
    }
    return NPU_OK;
}

int show_ascend_board_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct dcmi_elabel_info elabel_info = { { 0 } };
    enum npu_chip_type chip_type = npu_get_chip_type();

    struct npu_device_info *device_info = calloc(1, sizeof(struct npu_device_info));
    if (device_info == NULL) {
        gplog(LOG_ERR, "calloc device_info failed. ");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = npu_get_card_version_info(operate_info->id, device_info);
    if (ret != NPU_OK) {
        printf("Failed to query board version info.\n");
        free(device_info);
        return ret;
    }

    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93) {
        ret = dcmi_get_card_elabel_v2(operate_info->id, &elabel_info);
    }
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi interface get card elabel failed. err is %d", ret);
        free(device_info);
        return dcmi_to_npu_error_code(ret);
    }
    copy_elabel_info(&elabel_info, device_info);

    ret = dcmi_get_device_id_in_card(operate_info->id, &device_info->chip_count, &device_info->mcu_id,
        &device_info->cpu_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_id_in_card failed. err is %d", ret);
        free(device_info);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    ret = npu_get_card_board_info(operate_info->id, device_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to query card board info. err is %d", ret);
        free(device_info);
        return ret;
    }

    device_info->npu_id = operate_info->id;

    ret = npu_get_card_pcie_info(operate_info->id, device_info);
    if (ret != NPU_OK) {
        printf("Failed to query card pcie info.\n");
    }

    print_ascend_board_info(device_info);

    free(device_info);
    return ret;
}

STATIC int show_npu_card_info(struct npu_smi_operate_info *operate_info)
{
    int ret, tryidx;
    struct npu_device_info *device_info = NULL;
    int succ_tag = FALSE;

    if ((npu_get_chip_type() == NPU_CHIP_310) && (npu_is_in_virtual_machine() == TRUE)) {
        if (operate_info->chip_id == NPU_DEFAULT_VALUE) {
            printf("This command cannot be executed on a VM.\n");
            return NPU_OK;
        }
    }

    device_info = (struct npu_device_info *)malloc(sizeof(struct npu_device_info));
    if (device_info == NULL) {
        printf("Card device info malloc failed.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(device_info, sizeof(struct npu_device_info), 0, sizeof(struct npu_device_info));
    if (ret != 0) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    for (tryidx = 0; (!succ_tag && tryidx < MAX_TRY_COUNT); tryidx++) {
        do {
            ret = npu_get_card_info(operate_info->id, device_info);
            if (ret != NPU_OK) {
                break;
            }
            print_npu_card_info(device_info);
            succ_tag = TRUE;
        } while (0);
        if ((!succ_tag) && tryidx < (MAX_TRY_COUNT - 1)) {
            sleep(RETRY_SLEEP_TIME);
        }
    }
    if ((!succ_tag) && (tryidx >= MAX_TRY_COUNT)) {
        printf("show npu card info fail!\n");
    }

    free(device_info);
    return ret;
}

STATIC int show_ascend_card_board_info(struct npu_smi_operate_info *operate_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();

    bool support_chip_type = (npu_board_type_is_server() == TRUE) &&
        (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93);
    if (support_chip_type) {
        return show_ascend_board_info(operate_info);
    }

    return show_npu_card_info(operate_info);
}
#endif // end of NPU_SMI_V2

STATIC void printf_ascend_card_info_header(struct npu_smi_operate_info *operate_info, int card_id, int device_count)
{
    if (operate_info->type == ECC) {
        printf("\t%-40s : %d\n", "NPU ID", card_id);
#ifndef NPU_SMI_V2
        printf("\t%-40s : %d\n\n", "Chip Count", device_count);
#endif
    } else if (operate_info->type == VNPU_INFO) {
        return;
    } else {
        printf("\t%-30s : %d\n", "NPU ID", card_id);
#ifndef NPU_SMI_V2
        printf("\t%-30s : %d\n\n", "Chip Count", device_count);
#endif
    }
}

STATIC void printf_ascend_card_chip_id(struct npu_smi_operate_info *operate_info, int chip_id)
{
    if (operate_info->type == ECC) {
#ifndef NPU_SMI_V2
        printf("\t%-40s : %d\n", "Chip ID", chip_id);
#endif
    } else if (operate_info->type == VNPU_INFO) {
        return;
    } else {
#ifndef NPU_SMI_V2
        printf("\t%-30s : %d\n", "Chip ID", chip_id);
#endif
    }
}

STATIC int show_ascend_card_mcu_info(int card_id, int mcu_id, query_proc_fun chip_func)
{
    int ret;
    struct npu_smi_operate_info tmp_npu_intf = { 0 };

    tmp_npu_intf.id = card_id;
    tmp_npu_intf.chip_id = mcu_id;
    ret = chip_func(&tmp_npu_intf);
    if (ret != NPU_ERR_CODE_NOT_SUPPORT) {
        printf("\t%-30s : %s\n", "Chip Name", "MCU");
        if (ret != NPU_OK) {
            printf("Failed to query mcu chip: %d info.\n", mcu_id);
        }
        printf("\n");
    } else {
        ret = NPU_OK;
    }
    return ret;
}

STATIC int show_ascend_card_cpu_info(int card_id, int cpu_id, query_proc_fun chip_func)
{
    int ret;
    struct npu_smi_operate_info tmp_npu_intf = { 0 };

    tmp_npu_intf.id = card_id;
    tmp_npu_intf.chip_id = cpu_id;
    ret = chip_func(&tmp_npu_intf);
    if (ret != NPU_ERR_CODE_NOT_SUPPORT) {
        printf("\t%-30s : %s\n", "Chip Name", "3559");
        if (ret != NPU_OK) {
            printf("Failed to query chip: %d info.\n", cpu_id);
        }
        printf("\n");
    } else {
        ret = NPU_OK;
    }
    return ret;
}

STATIC int show_ascend_card_info(struct npu_smi_operate_info *operate_info, query_proc_fun chip_func)
{
    int ret, device_count, i;
    int mcu_id = NPU_DEFAULT_VALUE;
    int cpu_id = NPU_DEFAULT_VALUE;
    struct npu_smi_operate_info tmp_npu_intf = { 0 };

    ret = npu_get_card_device_id(operate_info->id, &device_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    tmp_npu_intf.id = operate_info->id;

    printf_ascend_card_info_header(operate_info, operate_info->id, device_count);

    for (i = 0; i < device_count; i++) {
        tmp_npu_intf.chip_id = i;
        if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
            printf_ascend_card_chip_id(operate_info, i);
        }
        ret = chip_func(&tmp_npu_intf);
        if (ret != NPU_ERR_CODE_NOT_SUPPORT) {
            if ((npu_get_chip_type() != NPU_CHIP_310) && (npu_get_chip_type() != NPU_CHIP_310B)) {
                printf_ascend_card_chip_id(operate_info, i);
            }
            if (ret != NPU_OK) {
                printf("Failed to query npu chip: %d info.\n", i);
            }
            printf("\n");
        } else {
            ret = NPU_OK;
        }
    }

    if (mcu_id != NPU_DEFAULT_VALUE) {
        ret = show_ascend_card_mcu_info(operate_info->id, mcu_id, chip_func);
    }

    if (cpu_id != NPU_DEFAULT_VALUE) {
        ret = show_ascend_card_cpu_info(operate_info->id, cpu_id, chip_func);
    }

    return ret;
}

STATIC int show_ascend_card_voltage(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_info(operate_info, show_ascend_chip_volt_info);
}

STATIC int show_ascend_card_temperature(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_info(operate_info, show_ascend_chip_temp_info);
}

STATIC int show_ascend_card_power_info(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_info(operate_info, show_ascend_chip_power_info);
}

int show_ascend_card_health(struct npu_smi_operate_info *operate_info)
{
#ifndef NPU_SMI_V2
    return show_ascend_card_info(operate_info, show_ascend_chip_health_state);
#else
    return show_ascend_card_info(operate_info, show_ascend_chip_health_info);
#endif
}

STATIC int show_ascend_card_memory(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_info(operate_info, show_ascend_chip_memory_info);
}

int check_vnpu_chip_name(int card_id, int device_id)
{
    int ret;

#ifndef NPU_SMI_V2
    struct dcmi_chip_info chip_info = { { 0 } };
    ret = dcmi_get_device_chip_info(card_id, 0, &chip_info);
#else
    struct dcmi_chip_info_v2 chip_info = { { 0 } };
    ret = dcmiv2_get_device_chip_info(card_id, &chip_info);
#endif
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    if (strstr((char *)chip_info.chip_name, "vir") != NULL) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    return NPU_OK;
}

STATIC int show_ascend_card_flash(struct npu_smi_operate_info *operate_info)
{
    if (((npu_board_type_is_station() == TRUE) || (npu_board_type_is_hilens() == TRUE)) &&
        (npu_get_total_ascend_chip_count() == 0)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    int ret = check_vnpu_chip_name(operate_info->id, 0);
    if (ret != NPU_OK) {
        return ret;
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_flash_info);
}

STATIC int show_ascend_card_ecc_enable(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char *ecc_enable[] = {"False", "True"};
    struct dcmi_ecc_info device_ecc_info = { 0 };
    bool check_result;
    enum npu_chip_type chip_type = npu_get_chip_type();

    check_result = ((npu_check_is_has_d_chip() == FALSE) || (npu_board_type_is_soc() && npu_is_in_docker()));
    // 200SOC 容器中计算组件不支持查询usages，后续计算组件功能OK后，需要放开
    if (check_result) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (chip_type != NPU_CHIP_910B && chip_type != NPU_CHIP_910_93 && chip_type != NPU_CHIP_950) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_ecc_info(operate_info->id, 0, DCMI_DEVICE_TYPE_DDR, &device_ecc_info);
#else
        ret = dcmiv2_get_device_ecc_info(operate_info->id, DCMI_DEVICE_TYPE_DDR, &device_ecc_info);
#endif
        if (ret != DCMI_OK) {
            return dcmi_to_npu_error_code(ret);
        }
        const char *ecc_enable_status_str =
            (chip_type == NPU_CHIP_310 || chip_type == NPU_CHIP_310B) ? "ECC-Enable Status" :
                                                                                            "DDR ECC-Enable Status";
        printf("\t%-30s : %s\n", ecc_enable_status_str, ecc_enable[device_ecc_info.enable_flag]);
    }

    if (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        struct dcmi_ecc_info hbm_ecc_info = {0};
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_ecc_info(operate_info->id, 0, DCMI_DEVICE_TYPE_HBM, &hbm_ecc_info);
#else
        ret = dcmiv2_get_device_ecc_info(operate_info->id, DCMI_DEVICE_TYPE_HBM, &hbm_ecc_info);
#endif
        if (ret != DCMI_OK) {
            return dcmi_to_npu_error_code(ret);
        }

        printf("\t%-30s : %s\n", "HBM ECC-Enable Status", ecc_enable[hbm_ecc_info.enable_flag]);
    }

    return NPU_OK;
}

STATIC int show_ascend_card_p2p_enable_flag(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char *p2p_enable[] = {"False", "True"};
    int flag = 0;

    if (npu_check_is_has_d_chip() == FALSE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_device_p2p_enable(operate_info->id, 0, &flag);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    printf("\t%-30s : %s\n", "P2P-Enable Status", p2p_enable[flag]);
    return NPU_OK;
}

STATIC int show_ascend_card_ssh_enable(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_info(operate_info, show_ascend_chip_ssh_enable_info);
}

STATIC int show_card_product_type(struct npu_smi_operate_info *operate_info)
{
    operate_info->chip_id = 0;
    return show_ascend_card_info(operate_info, show_chip_product_type);
}

STATIC int show_ascend_card_usages(struct npu_smi_operate_info *operate_info)
{
    bool check_result = ((npu_check_is_has_d_chip() == FALSE) || (npu_board_type_is_soc() && npu_is_in_docker()));
    if (check_result) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_usages_info);
}

STATIC int npu_get_card_common_info(struct npu_card_common_info *card_common_info)
{
    int ret, i;

    for (i = 0; i < card_common_info->chip_count; i++) {
        if (npu_check_is_has_d_chip() == FALSE) {
            gplog(LOG_ERR, "npu chip not present.");
            break;
        }

        ret = npu_get_chip_common_info(card_common_info->card_id, i, &card_common_info->chip_common_info[i]);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            return ret;
        }
    }

    if (card_common_info->mcu_id != NPU_DEFAULT_VALUE) {
        ret = npu_get_chip_common_info(card_common_info->card_id, card_common_info->mcu_id,
            &card_common_info->chip_common_info[card_common_info->mcu_id]);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            return ret;
        }
    }

    if (card_common_info->cpu_id != NPU_DEFAULT_VALUE) {
        ret = npu_get_chip_common_info(card_common_info->card_id, card_common_info->cpu_id,
            &card_common_info->chip_common_info[card_common_info->cpu_id]);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            return ret;
        }
    }

    return NPU_OK;
}

STATIC int show_ascend_card_common_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct npu_card_common_info *card_common_info = NULL;

    if ((npu_get_chip_type() == NPU_CHIP_310) && npu_is_in_virtual_machine()) {
        if (operate_info->chip_id == NPU_DEFAULT_VALUE) {
            printf("This command cannot be executed on a VM.\n");
            return NPU_OK;
        }
    }

    card_common_info = (struct npu_card_common_info *)malloc(sizeof(struct npu_card_common_info));
    if (card_common_info == NULL) {
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(card_common_info, sizeof(struct npu_card_common_info), 0, sizeof(struct npu_card_common_info));
    if (ret != 0) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    card_common_info->card_id = operate_info->id;

    ret = npu_get_card_device_id(card_common_info->card_id, &card_common_info->chip_count, &card_common_info->mcu_id,
        &card_common_info->cpu_id);
    if (ret != NPU_OK) {
        free(card_common_info);
        return ret;
    }

    ret = npu_get_card_common_info(card_common_info);

    print_common_info(card_common_info);
    free(card_common_info);
    ret = NPU_OK;
    return ret;
}

STATIC int show_ascend_card_ecc_info(struct npu_smi_operate_info *operate_info)
{
    bool check_result = ((npu_check_is_has_d_chip() == FALSE) || (npu_board_type_is_soc() && npu_is_in_docker()));
    if (check_result) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    int ret = check_vnpu_chip_name(operate_info->id, 0);
    if (ret != NPU_OK) {
        return ret;
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_ecc_info);
}

STATIC int show_ascend_card_i2c_check(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int health_status[IIC_TEST_CASE] = {
        TEST_NOT_STARTED, TEST_NOT_STARTED, TEST_NOT_STARTED, TEST_NOT_STARTED, TEST_NOT_STARTED, TEST_NOT_STARTED
    };
    size_t test_index, case_num;
    char *mcu_check_iic_list[] = {
        "miniD 1 to MCU", "miniD 3 to MCU", "MCU to miniD 0", "MCU to miniD 1", "MCU to miniD 2",  "MCU to miniD 3"
    };
    const char *health_status_map[] = {"OK", "Fault", "Unknown status"};

    ret = user_egid_check();
    if (ret != NPU_OK) { // 只有root用户才有检查I2C权限
        return NPU_OK;
    }

    if (npu_is_run_in_vm_or_docker() == TRUE) {
        printf("\t%-30s : %s\n", "Message", "This command cannot be executed on a VM or container.");
        return NPU_OK;
    }

    if (npu_check_is_has_mcu() != TRUE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    bool check_result = ((npu_get_chip_type() == NPU_CHIP_310) && (npu_board_type_is_card()));
    if (!check_result) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_mcu_check_i2c(operate_info->id, health_status, IIC_TEST_CASE);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    case_num = sizeof(mcu_check_iic_list) / sizeof(mcu_check_iic_list[0]);
    if (case_num > IIC_TEST_CASE) {
        gplog(LOG_ERR, "test case number > result number.");
        return NPU_ERR_CODE_INNER_ERR;
    }
    for (test_index = 0; test_index < case_num; test_index++) {
        const char *health_status_result =
            (health_status[test_index] == TEST_FAIL || (health_status[test_index] == TEST_SUCCESS)) ?
            health_status_map[health_status[test_index]] :
            health_status_map[2];
        printf("\t%s iic channel status: %s\n", mcu_check_iic_list[test_index], health_status_result);
    }
    return ret;
}

STATIC int show_ascend_card_mcu_monitor(struct npu_smi_operate_info *operate_info)
{
    if (npu_check_is_has_mcu() != TRUE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_customized_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char license[MAX_LENTH + 1] = {0};

    ret = check_support_customized_info(operate_info);
    if (ret != NPU_OK) {
        ret = (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED) ? NPU_OK : ret;
        return ret;
    }

    ret = dcmi_get_card_customized_info(operate_info->id, license, sizeof(license) - 1);
    if (ret == DCMI_OK) {
        const char *type_info = (strcmp(operate_info->stype, "customized-info") == 0) ? "Customized info" : "License";
        printf("\t%-30s : %s\n", type_info, license);
    }

    return dcmi_to_npu_error_code(ret);
}

STATIC int show_ascend_card_boot_area(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_ip(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_err_count(struct npu_smi_operate_info *operate_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();

#ifndef _WIN32
    int ret = check_support_get_err_count_info(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    bool check_result =
        (npu_board_type_is_card() && ((chip_type == NPU_CHIP_310) || (chip_type == NPU_CHIP_310P)));
    if (check_result) {
        return show_ascend_card_info(operate_info, show_ascend_chip_err_count_info);
    }

    check_result = (((chip_type == NPU_CHIP_910B || is_a_x_910_93(operate_info->id)) &&
         !dcmi_check_chip_is_in_split_mode(operate_info->id, operate_info->chip_id)) ||
         (dcmi_mainboard_is_a900_a5_pcie(g_mainboard_info.mainboard_id) &&
         !dcmiv2_check_chip_is_in_split_mode(operate_info->id)));
    if (check_result) {
        return show_ascend_card_info(operate_info, show_ascend_chip_pcie_error_info);
    }

    return NPU_ERR_CODE_NOT_SUPPORT;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

STATIC int show_ascend_card_device_share(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_info(operate_info, show_ascend_chip_device_share_info);
}

STATIC int show_ascend_card_nve_level(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

#ifndef NPU_SMI_V2
STATIC int show_ascend_card_sensors(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_system_time(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}
#endif

int show_ascend_card_default_proc(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of type.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_first_power_on_date(struct npu_smi_operate_info *operate_info)
{
    int ret;
    time_t time;
    struct tm tm_time;
    unsigned int first_power_on_date;

    if (npu_is_run_in_vm_or_docker() == TRUE) {
        printf("\t%-30s : %s\n", "Message", "This command cannot be executed on a VM or container.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    ret = dcmi_get_first_power_on_date(operate_info->id, &first_power_on_date);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    if (first_power_on_date == 0) {
        printf("\t%-30s : %s\n", "Message", "First power-on date is not recorded. Please wait 24 hours and try again.");
        return NPU_OK;
    }

    time = (time_t)first_power_on_date;
    (void)localtime_r(&time, &tm_time);

    printf("\t%-30s : %d/%d/%d\n", "First power-on date(local)",
           tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday); // 年份从1900开始到当前年份的值，月份加1为真实月份
    return NPU_OK;
}

STATIC int show_ascend_card_cpu_num_info(struct npu_smi_operate_info *operate_info)
{
    int ret = check_vnpu_chip_name(operate_info->id, 0);
    if (ret != NPU_OK) {
        return ret;
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_cpu_num_info);
}

STATIC int show_ascend_card_vnpu_proc(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_proc_mem_info(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret, device_count, i;
    int ret_err = NPU_OK;
    int mcu_id = NPU_DEFAULT_VALUE;
    int cpu_id = NPU_DEFAULT_VALUE;
    struct npu_smi_operate_info tmp_npu_intf = { 0 };

    ret = npu_get_card_device_id(operate_info->id, &device_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    tmp_npu_intf.id = operate_info->id;

    printf_ascend_card_info_header(operate_info, operate_info->id, device_count);

    for (i = 0; i < device_count; i++) {
        tmp_npu_intf.chip_id = i;
        if ((npu_get_chip_type() == NPU_CHIP_310) || (npu_get_chip_type() == NPU_CHIP_310B)) {
            printf_ascend_card_chip_id(operate_info, i);
        }
        ret = show_ascend_chip_proc_mem_info(&tmp_npu_intf);
        if ((npu_get_chip_type() != NPU_CHIP_310) && (npu_get_chip_type() != NPU_CHIP_310B)) {
            printf_ascend_card_chip_id(operate_info, i);
        }
        if (ret != NPU_OK) {
            ret_err = ret;
            printf("Failed to query npu chip: %d info.\n", i);
        }
        printf("\n");
    }

    if (ret_err != NPU_OK) {
        return ret_err;
    }
    return ret;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}
STATIC int show_ascend_card_p2p_mem_cfg_status(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int flag = 0;

    ret = check_vnpu_chip_name(operate_info->id, 0);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_get_user_config(operate_info->id, 0, "p2p_mem_cfg", P2P_MEM_CFG_SIZE, (unsigned char *)&flag);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_p2p_mem_cfg_status);
}

int show_ascend_card_template_info(struct npu_smi_operate_info *operate_info)
{
    int ret, card_num;
    int mixed_flag = FALSE;
    unsigned int template_num = 0;
    int card_list[MAX_CARD_NUM] = {0};
    struct dcmi_computing_template template_out[10] = { { { 0 } } };

    if (operate_info->id == NPU_DEFAULT_VALUE) {
        ret = check_is_mixed_env(operate_info, &mixed_flag);
        if (ret != NPU_OK) {
            return ret;
        }
        if (mixed_flag == TRUE) {
            printf("There are different types of cards on the server. ");
            printf("Run npu-smi info -t template-info -i id to query.\n");
        }
        ret = dcmi_get_card_list(&card_num, card_list, MAX_CARD_NUM);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_card_list called failed. ret=%d.", ret);
            return dcmi_to_npu_error_code(ret);
        }
        operate_info->id = card_list[0];
        operate_info->chip_id = 0;
    }

    ret = check_valid_info_operation_env(operate_info);
    if (ret != NPU_OK) {
        return NPU_OK;
    }

    ret = check_vnpu_workmode(operate_info);
    if (ret != NPU_OK) {
        if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
            printf("NPU is working in SMP mode, does not support querying %s\n", operate_info->stype);
            ret = DCMI_OK;
        } else {
            printf("Failed to get npu work mode.\n");
        }
        return ret;
    }

    ret = dcmi_get_show_template_info_all(operate_info->id, template_out, sizeof(template_out), &template_num);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_template_info_all failed. err is %d", ret);
        printf("Failed to get template info.\n");
        return dcmi_to_npu_error_code(ret);
    }
    printf_template_info(template_out, template_num);
    return NPU_OK;
}

STATIC int show_ascend_card_work_mode(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned char work_mode;

    if (operate_info == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_get_npu_work_mode(operate_info->id, &work_mode);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "failed to query npu work mode. err is %d.\n", ret);
        return dcmi_to_npu_error_code(ret);
    }

    print_npu_work_mode_info(operate_info->id, work_mode);

    return ret;
}

STATIC int show_ascend_card_mac_addr_info(struct npu_smi_operate_info *operate_info, query_proc_fun chip_func)
{
    int ret, device_count, i;
    int mcu_id = NPU_DEFAULT_VALUE;
    int cpu_id = NPU_DEFAULT_VALUE;
    struct npu_smi_operate_info tmp_npu_intf = { 0 };

    ret = npu_get_card_device_id(operate_info->id, &device_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    tmp_npu_intf.id = operate_info->id;

    printf_ascend_card_info_header(operate_info, operate_info->id, device_count);

    for (i = 0; i < device_count; i++) {
        tmp_npu_intf.chip_id = i;
        ret = chip_func(&tmp_npu_intf);
        if (ret != NPU_ERR_CODE_NOT_SUPPORT) {
            printf_ascend_card_chip_id(operate_info, i);
            if (ret != NPU_OK) {
                printf("Failed to query npu chip: %d info.\n", i);
            }
            printf("\n");
        } else {
            ret = NPU_OK;
        }
    }

    return ret;
}

STATIC int show_ascend_card_mac_addr(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_mac_addr_info(operate_info, show_ascend_chip_mac_addr_info);
}

STATIC int show_ascend_card_boot_sel(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_hccs_lane_info(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_cpu_freq_up(struct npu_smi_operate_info *operate_info)
{
    if (dcmi_check_chip_is_in_split_mode(operate_info->id, operate_info->chip_id)) {
        // 300V算力切分场景下，不支持该命令
        gplog(LOG_OP, "In the vNPU scenario, this device does not support get cpu frequence.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (!dcmi_board_chip_type_is_ascend_310p_300v()) {
        gplog(LOG_ERR, "This device does not support get cpu frequence.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_cpu_freq_up_info);
}

STATIC int show_ascend_card_hccs_avail_credit_info(struct npu_smi_operate_info *operate_info)
{
    if (!dcmi_board_chip_type_is_ascend_910_93()) {
        gplog(LOG_OP, "This device does not support get hccs avail credit info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (dcmi_check_chip_is_in_split_mode(operate_info->id, operate_info->chip_id) == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
        gplog(LOG_ERR, "Operation not permitted, this api cannot be called in split mode");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_hccs_avail_credit_info);
}

STATIC int show_ascend_card_custom_op(struct npu_smi_operate_info *operate_info)
{
    return show_ascend_card_info(operate_info, show_ascend_chip_custom_op_info);
}

STATIC int show_ascend_card_custom_op_secverify_enable(struct npu_smi_operate_info *operate_info)
{
    // 仅支持物理机root + 虚机的root + 特权容器root
    if (!(dcmi_is_in_phy_machine_root() || dcmi_is_in_vm_root() || dcmi_is_in_privileged_docker_root())) {
        gplog(LOG_OP, "This environment does not support get custom op secverify enable info.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (!(dcmi_board_chip_type_is_ascend_910b() || dcmi_board_chip_type_is_ascend_910_93() ||
        dcmi_board_chip_type_is_ascend_950())) {
        gplog(LOG_OP, "This chip does not support get custom op secverify enable info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    return show_ascend_card_info(operate_info, show_ascend_chip_custom_op_secverify_enable_info);
}

STATIC int show_ascend_card_custom_op_secverify_mode(struct npu_smi_operate_info *operate_info)
{
    // 不支持算力切分场景
    if (dcmi_check_vnpu_in_docker_or_virtual(operate_info->id)) {
        gplog(LOG_OP, "This environment does not support get custom op secverify mode info.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (!(dcmi_board_chip_type_is_ascend_910b() || dcmi_board_chip_type_is_ascend_910_93() ||
        dcmi_board_chip_type_is_ascend_950())) {
        gplog(LOG_OP, "This chip does not support get custom op secverify mode info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return show_ascend_card_info(operate_info, show_ascend_chip_custom_op_secverify_mode_info);
}

STATIC int show_ascend_card_custom_op_secverify_cert(struct npu_smi_operate_info *operate_info)
{
    if (!(dcmi_board_chip_type_is_ascend_910b() || dcmi_board_chip_type_is_ascend_910_93())) {
        gplog(LOG_OP, "This chip does not support getting custom op secverify cert info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return show_ascend_card_info(operate_info, show_custom_op_secverify_cert_info);
}

#ifndef NPU_SMI_V2
STATIC int show_ascend_card_spod_info(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int show_ascend_card_sio_info(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of chip id.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}
#endif

struct npu_operate_table_item g_query_card_info_table[] = {
#if defined(NPU_SMI_V2) && !defined(ORIENT_CH) // 在非CH情况下，使用 NPU 版本的 board 信息
    {BOARD, show_ascend_npu_board_info},
#else
    {BOARD, show_ascend_card_board_info},
#endif
    {VOLT, show_ascend_card_voltage},
    {TEMP, show_ascend_card_temperature},
    {POWER, show_ascend_card_power_info},
    {HEALTH, show_ascend_card_health},
    {MEMORY, show_ascend_card_memory},
    {FLASH, show_ascend_card_flash},
    {ECC_ENABLE, show_ascend_card_ecc_enable},
    {P2P_ENABLE_FLAG, show_ascend_card_p2p_enable_flag},
    {SSH_ENABLE, show_ascend_card_ssh_enable},
    {USAGES, show_ascend_card_usages},
    {COMMON, show_ascend_card_common_info},
    {ECC, show_ascend_card_ecc_info},
    {IIC_CHECK, show_ascend_card_i2c_check},
    {MCU_MONITOR, show_ascend_card_mcu_monitor},
    {CUSTOMIZED_INFO, show_ascend_card_customized_info},
    {BOOT_AREA, show_ascend_card_boot_area},
    {IP, show_ascend_card_ip},
    {ERR_COUNT, show_ascend_card_err_count},
    {DEVICE_SHARE, show_ascend_card_device_share},
    {NVE_LEVEL, show_ascend_card_nve_level},
    {PRODUCT_TYPE, show_card_product_type},
    {VNPU_INFO, show_ascend_card_vnpu_proc},
    {VNPU_SVM_INFO, show_ascend_card_vnpu_proc},
    {KEY_MANAGE, show_key_manage_info},
    {FIRST_POWER_ON_DATE, show_ascend_card_first_power_on_date},
    {PROC_MEM, show_ascend_card_proc_mem_info},
    {CPU_NUM_CFG, show_ascend_card_cpu_num_info},
    {NPU_DEFAULT_VALUE, show_ascend_card_default_proc},
    {P2P_MEM_CFG, show_ascend_card_p2p_mem_cfg_status},
    {TEMPLATE_INFO, show_ascend_card_template_info},
    {MAC_ADDR, show_ascend_card_mac_addr},
    {WORK_MODE, show_ascend_card_work_mode},
    {BOOT_SEL, show_ascend_card_boot_sel},
    {HCCS, show_ascend_card_hccs_lane_info},
    {CPU_FREQ_UP, show_ascend_card_cpu_freq_up},
    {HCCS_AVAIL_CREDIT, show_ascend_card_hccs_avail_credit_info},
    {CUSTOM_OP, show_ascend_card_custom_op},
    {CUSTOM_OP_SECVERIFY_ENABLE, show_ascend_card_custom_op_secverify_enable},
    {CUSTOM_OP_SECVERIFY_MODE, show_ascend_card_custom_op_secverify_mode},
    {CUSTOM_OP_SECVERIFY_CERT, show_ascend_card_custom_op_secverify_cert},
#ifndef NPU_SMI_V2
    {SENSORS, show_ascend_card_sensors},
    {SYS_TIME, show_ascend_card_system_time},
    {SPOD_INFO, show_ascend_card_spod_info},
    {SIO_INFO, show_ascend_card_sio_info},
#else
    {CURRENT_FAULT_EVENT, show_ascend_chip_current_fault_event_info},
    {SENSORS, show_ascend_chip_sensor_info},
    {SYS_TIME, show_ascend_chip_sys_time_info},
    {SPOD_INFO, show_ascend_chip_spod_info},
    {SIO_INFO, show_ascend_chip_sio_info},
    {TLS_CSR_GET, show_tls_csr_info},
    {TLS_CERT, show_tls_cert_info},
    {TLS_CERT_PERIOD, show_tls_cert_period_info},
    {PHYID_REMAP, show_ascend_chip_phyid_remap_info},
#endif
};

int query_card_info(struct npu_smi_operate_info *operate_info)
{
    int ret = NPU_ERR_CODE_NOT_SUPPORT;
    size_t table_index, table_size;

    if ((operate_info->type != PHYID_REMAP) && (operate_info->id == NPU_DEFAULT_VALUE)) {
        printf("\nThis command must input card id.\n\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    table_size = sizeof(g_query_card_info_table) / sizeof(g_query_card_info_table[0]);
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == g_query_card_info_table[table_index].fun_index) {
            ret = g_query_card_info_table[table_index].proc_func(operate_info);
            break;
        }
    }

    bool check_result = ((ret != NPU_OK) && (operate_info->type != NPU_DEFAULT_VALUE) &&
        (ret != NPU_ERR_CODE_NOT_SUPPORT) && (ret != NPU_ERR_CODE_INVALID_PARAMETER) && (ret != -EPERM));
    if (check_result) {
        printf("Failed to query \"%s\" info.\n", operate_info->stype);
    } else if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support querying %s.\n", operate_info->stype);
        ret = NPU_OK;
    }
    return ret;
}
