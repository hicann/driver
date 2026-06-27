/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stddef.h>
#include "dcmi_interface_api.h"
#include "npu_cmd_parse.h"
#include "npu_common.h"
#include "securec.h"
#include "dcmi_log.h"
#include "dcmi_virtual_intf.h"
#include "npu_chip_set.h"
#include "npu_chip_set_ext.h"
#include "dcmi_product_judge.h"
#include "npu_clear.h"

void print_clear_result(int ret, struct npu_smi_operate_info *operate_info)
{
    if (ret != NPU_OK) {
        printf("\t%-30s : %s\n", "Status", "Fail");
        printf("\t%-30s : Failed to clear %s.\n", "Message", operate_info->stype);
        return;
    }

    printf("\t%-30s : %s\n", "Status", "OK");
    printf("\t%-30s : Clear %s successfully.\n", "Message", operate_info->stype);
}

int clear_chip_ecc_isolated_statistics_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = NPU_TYPE;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type != NPU_CHIP_910 && chip_type != NPU_CHIP_910B &&
        chip_type != NPU_CHIP_310P && chip_type != NPU_CHIP_910_93 &&
        chip_type != NPU_CHIP_950) {
        printf("This device does not support clearing %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "dcmi_get_device_type failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type != NPU_TYPE) {
        printf("This device does not support clearing %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    
    ret = dcmi_set_device_clear_ecc_statistics_info(operate_info->id, operate_info->chip_id);
    if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
        printf("In the vNPU scenario, this device does not support clearing %s.\n", operate_info->stype);
        gplog(LOG_OP, "In the vNPU scenario, this device does not support clearing %s.", operate_info->stype);
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    print_clear_result(ret, operate_info);
    if (ret != DCMI_OK) {
        gplog(LOG_OP, "clear ecc_info for chip%d of card%d failed.", operate_info->chip_id, operate_info->id);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "clear ecc_info for chip%d of card%d success.", operate_info->chip_id, operate_info->id);
    return NPU_OK;
}

int clear_card_ecc_isolated_statistics_info(struct npu_smi_operate_info *operate_info)
{
    int ret, chip_id;
    int npu_count = 0;
    int mcu_id = 0;
    int cpu_id = 0;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type != NPU_CHIP_910 && chip_type != NPU_CHIP_910B &&
        chip_type != NPU_CHIP_310P && chip_type != NPU_CHIP_910_93 &&
        chip_type != NPU_CHIP_950) {
        printf("This device does not support clearing %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = npu_get_card_device_id(operate_info->id, &npu_count, &mcu_id, &cpu_id);
    if (ret != NPU_OK) {
        printf("Failed to query chip count.\n");
        return ret;
    }

    for (chip_id = 0; chip_id < npu_count; chip_id++) {
#ifndef NPU_SMI_V2
        ret = dcmi_set_device_clear_ecc_statistics_info(operate_info->id, chip_id);
#else
        ret = dcmiv2_clear_device_ecc_stats_info(operate_info->id);
#endif
        if ((ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) && (dcmi_check_card_is_split_phy(operate_info->id) == TRUE)) {
            printf("In the vNPU scenario, this device does not support clearing %s.\n", operate_info->stype);
            gplog(LOG_OP, "In the vNPU scenario, this device does not support clearing %s.", operate_info->stype);
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
        if (ret != DCMI_OK) {
            print_clear_result(ret, operate_info);
            if (ret != DCMI_ERR_CODE_NOT_SUPPORT) {
                gplog(LOG_OP, "clear ecc info for card%d failed.", operate_info->id);
            }
            return dcmi_to_npu_error_code(ret);
        }
    }

    print_clear_result(ret, operate_info);
    gplog(LOG_OP, "clear ecc info for card%d success.", operate_info->id);
    return NPU_OK;
}

STATIC int clear_tls_cert_period(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
 
#ifndef NPU_SMI_V2
    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b() ||
        dcmi_board_chip_type_is_ascend_310p()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        printf("This device does not support clearing %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#else
    operate_info->chip_id=0;
    if (!(dcmi_board_chip_type_is_ascend_950()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        printf("This device does not support clearing %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#endif
 
    if ((dcmi_board_type_is_310p_duo_chips() || dcmi_board_chip_type_is_ascend_910_93()) &&
        (operate_info->chip_id != 0)) {
        gplog(LOG_OP, "The Atlas 300I Duo card and 910_93 is only supported on chip 0.");
        printf("This device does not support clearing %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#ifndef NPU_SMI_V2
    ret = dcmi_clear_device_user_config(operate_info->id, operate_info->chip_id, CERT_CONFIG_EXPIRED);
#else
    ret = dcmiv2_clear_device_user_config(operate_info->id, CERT_CONFIG_EXPIRED);
#endif
 
    print_clear_result(ret, operate_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to clear tls cert period for card%d chip%d, err is %d.",
              operate_info->id, operate_info->chip_id, ret);
        return dcmi_to_npu_error_code(ret);
    }
    // clear后新增默认用户
    ret = set_user_config(operate_info->id, operate_info->chip_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to set user config, err is %d.", ret);
        return ret;
    }
 
    gplog(LOG_OP, "clear tls cert period for card%d chip%d successfully.", operate_info->id, operate_info->chip_id);
    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}


int chip_clear(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->id == NPU_INVALID_VALUE || operate_info->chip_id == NPU_INVALID_VALUE) {
        printf("This command must input card id and chip id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    struct npu_operate_table_item clear_chip_info_table[] = {
        {ECC_INFO, clear_chip_ecc_isolated_statistics_info},
        {TLS_CERT_PERIOD, clear_tls_cert_period},
        {NPU_INVALID_VALUE, npu_invalid_item_proc}
    };

    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    size_t table_index;
    size_t table_size = sizeof(clear_chip_info_table) / sizeof(clear_chip_info_table[0]);
    // 查表并执行对应的清除操作
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == clear_chip_info_table[table_index].fun_index) {
            ret = clear_chip_info_table[table_index].proc_func(operate_info);
            return ret;
        }
    }

    printf("Error parameter in clear chip info, type: \"%s\".\n", operate_info->stype);
    return ret;
}


int card_clear(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->id == NPU_INVALID_VALUE) {
        printf("This command must input card id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
 
    struct npu_operate_table_item clear_card_info_table[] = {
        {ECC_INFO, clear_card_ecc_isolated_statistics_info},
        {NPU_INVALID_VALUE, npu_invalid_item_proc},
#ifdef NPU_SMI_V2
        {TLS_CERT_PERIOD, clear_tls_cert_period},
#endif
    };
 
    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    size_t table_index;
    size_t table_size = sizeof(clear_card_info_table) / sizeof(clear_card_info_table[0]);
    // 查表并执行对应的清除操作
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == clear_card_info_table[table_index].fun_index) {
            ret = clear_card_info_table[table_index].proc_func(operate_info);
            return ret;
        }
    }
 
    printf("Error parameter in clear card info, type: \"%s\".\n", operate_info->stype);
    return ret;
}


void npu_clear_help(const char *name)
{
    printf("Usage: %s %s <-h|-t type> [Options...]\n", TOOL_NAME, name);
    printf("\nCommands:\n");
    printf("       -h, --help     Show this help text and exit\n");
    printf("       -t type        The clear type for device\n");
    printf("                      type: ecc-info, tls-cert-period.\n");
    printf("\nOptions:\n");
#ifndef NPU_SMI_V2
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
#else
    printf("       -i %%d          NPU ID\n");
#endif
}


int npu_clear_run(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->is_chip) {
        ret = chip_clear(operate_info);
    } else {
        ret = card_clear(operate_info);
    }
    if (ret == NPU_ERR_CODE_INVALID_PARAMETER) {
        npu_clear_help(operate_info->name);
    }
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        gplog(LOG_OP, "This device does not support clearing %s, card_id=%d, device_id=%d", \
              operate_info->stype, operate_info->id, operate_info->chip_id);
    }

    return ret;
}

int npu_clear_main(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int ret;

    ret = user_egid_check();
    if (ret != NPU_OK) { // 只有root用户才有clear权限
        return ret;
    }

    if (npu_is_run_in_vm_or_docker()) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (argc < LEAST_PARAMETER_NUM) {
        printf("\nThere has no options.\n\n");
        npu_clear_help(operate_info->name);
        return NPU_ERR_CODE_PARAMETER_SHOW_HELP;
    }

    ret = parse_npu_clear_param(operate_info, argc, argv);

#ifdef NPU_SMI_V2
    if (operate_info->is_chip) {
        printf("This device does not support input parameter of -c.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
#endif
    if (ret == NPU_OK) {
        return npu_clear_run(operate_info);
    }

    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        gplog(LOG_OP, "This device does not support clearing %s.", operate_info->stype);
        ret = NPU_OK;
    }
    if ((ret == NPU_ERR_CODE_INVALID_PARAMETER) || (ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
        npu_clear_help(operate_info->name);
    }
    if (ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP) {
        ret = NPU_OK;
    }
    return ret;
}
