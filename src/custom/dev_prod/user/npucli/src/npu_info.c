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
#include <regex.h>
#include <dirent.h>
#include <time.h>
#include <errno.h>
#ifndef _WIN32
#include <unistd.h>
#include "ascend_hal.h"
#else
#include <io.h>
#include <process.h>
#include "dcmi_os_adapter.h"
#endif
#include "securec.h"
#include "dcmi_interface_api.h"
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_inner_cfg_manage.h"
#include "npu_common.h"
#include "npu_init.h"
#include "npu_info_watch.h"
#include "npu_info_print.h"
#include "npu_cmd_parse.h"
#include "npu_card_info.h"
#include "npu_chip_info.h"
#include "npu_error_code.h"
#include "dcmi_npu_link_intf.h"
#include "dcmi_inner_cfg_persist.h"
#include "dcmi_environment_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_product_judge.h"
#include "dcmi_basic_info_intf.h"
#include "npu_cmd_parse.h"
#include "npu_info.h"

#define REGEX_MATCH_NUM 2  /* regexec匹配的最大子表达式数量 */

STATIC struct topo_pcie_info g_pcie_dev_info_list = {0};

STATIC void npu_info_help(const char *name)
{
    printf("Usage: %s %s <watch|proc|-h|-m|-l|-t type> [Options...]\n", TOOL_NAME, name);
    printf("\nCommands:\n");
    printf("       watch          Show all device's status in scrolling format\n");
    printf("       proc           Show device's matrix process status in scrolling format\n");
    printf("       -h, --help     Show this help text and exit\n");
    printf("       -m             Show all device's mapping information\n");
    printf("       -l             Show all device's topology information\n");
#ifdef NPU_SMI_V2 // ID整改后npu-smi -h
    printf("       -t type        Show information for type\n");
    printf("                      type: board, common, flash, memory, usages, temp, power, volt, health,\n");
    printf("                            current-fault-event, ecc, ecc-enable, sensors, sys-time, key-manage,\n");
    printf("                            proc-mem, phyid-remap, topo, spod-info, sio-info, sys-log-info,\n");
    printf("                            tls-csr-get, tls-cert, tls-cert-period, pcie-err.\n");
#else // A5代际前npu-smi -h
    printf("       -t type        Show information for type\n");
    printf("                      type: board, flash, memory, usages, sensors, temp, power, volt, mac-addr,\n");
    printf("                            common, health, product, ecc, ip, sys-time, i2c_check, work-mode,\n");
    printf("                            ecc-enable, p2p-enable, ssh-enable, license, customized-info, device-share,\n");
    printf("                            device-share-cfg-recover, nve-level, aicpu-config, pcie-err, mcu-monitor,\n");
    printf("                            err-count, boot-area, vnpu-mode, info-vnpu, vnpu-svm, cpu-num-cfg,\n");
    printf("                            first-power-on-date, proc-mem, phyid-remap, vnpu-cfg-recover, key-manage,\n");
    printf("                            template-info, pkcs-enable, p2p-mem-cfg, pwm-mode, pwm-duty-ratio,\n");
#ifdef ORIENT_CH
    printf("                            boot-select, topo, xlink, sio-info, spod-info, tls-csr-get, tls-cert,\n");
    printf("                            tls-cert-period, rootkey, xlink-bw, cpu-freq-up, sys-log-info, "
           "xlink-credit,\n");
#else
    printf("                            boot-select, topo, hccs, sio-info, spod-info, tls-csr-get, tls-cert,\n");
    printf("                            tls-cert-period, rootkey, hccs-bw, cpu-freq-up, sys-log-info, hccs-credit,\n");
#endif
    printf("                            custom-op, custom-op-cfg-recover, custom-op-secverify-enable,\n");
    printf("                            custom-op-secverify-mode, op-timeout, current-fault-event,\n");
    printf("                            custom-op-secverify-cert, multi-die-policy, multi-die-policy-cfg-recover.\n");
#endif
    printf("\nOptions:\n");
#ifdef NPU_SMI_V2 // ID整改后npu-smi -h
    printf("       -i %%d          NPU ID\n");
    printf("       -p %%d          Chip Physical ID\n");
#else
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -p %%d          Chip Physical ID\n");
#endif
}
#ifndef NPU_SMI_V2
STATIC void npu_info_hccs_bw_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -time %%d       Profiling Time\n");
}

STATIC void npu_info_hccs_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
    printf("       -lane %%d       Lane ID\n");
}

STATIC void npu_info_tls_cert_period_help(struct npu_smi_operate_info *operate_info)
{
    printf("Usage: %s %s -t %s [Options...]\n", TOOL_NAME, operate_info->name, operate_info->stype);
    printf("\nOptions:\n");
    printf("       -i %%d          Card ID\n");
    printf("       -c %%d          Chip ID\n");
}
#endif
void npu_info_show_help(struct npu_smi_operate_info *operate_info)
{
#ifndef NPU_SMI_V2 // A5代际前
    struct info_help_cmd info_help_list[] = {
        { npu_info_hccs_bw_help, HCCS_BANDWIDTH_INFO},
        { npu_info_hccs_help, HCCS},
        { npu_info_tls_cert_period_help, TLS_CSR_GET},
        { npu_info_tls_cert_period_help, TLS_CERT},
        { npu_info_tls_cert_period_help, TLS_CERT_PERIOD},
        { NULL },
    };

    struct info_help_cmd *cmd = NULL;
    /* 优先走定制的帮助信息 */
    for (cmd = info_help_list; cmd->func != NULL; cmd++) {
        if (cmd->type == operate_info->type) {
            cmd->func(operate_info);
            return;
        }
    }
#endif
    /* 未定制的帮助信息，打印npu-help的默认帮助 */
    npu_info_help(operate_info->name);
}

STATIC int npu_get_resource_info(struct npu_card_total_info *card_info, int device_id)
{
    int proc_index, ret;
#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_proc_mem_info(card_info->card_id,
        card_info->chip_proc_info[device_id], &card_info->proc_nums[device_id]);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_proc_mem_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
#else
    ret = dcmi_get_device_resource_info(card_info->card_id, device_id,
        card_info->chip_proc_info[device_id], &card_info->proc_nums[device_id]);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_resource_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
#endif
    for (proc_index = 0; proc_index < card_info->proc_nums[device_id]; proc_index++) {
        ret = get_pid_name(card_info->chip_proc_info[device_id][proc_index].proc_id,
            card_info->chip_proc_name[device_id][proc_index], MAX_PROCESS_NAME_LEN);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "get_pid_name failed. err is %d", ret);
        }
    }

    return ret;
}

STATIC bool check_result_for_dcmi_get_hbm_info(void)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    return (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950);
}

#ifdef NPU_SMI_V2
int get_chip_info_v2_as_old(int dev_id, struct dcmi_chip_info *old_info)
{
    if (old_info == NULL) {
        gplog(LOG_ERR, "Input old_info is NULL.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    struct dcmi_chip_info_v2 new_info = {0};
    int ret = dcmiv2_get_device_chip_info(dev_id, &new_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_chip_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = memcpy_s(old_info->chip_type, sizeof(old_info->chip_type),
                   new_info.chip_type, sizeof(new_info.chip_type));
    if (ret) {
        gplog(LOG_ERR, "Copy chip_type from dcmi_chip_info_v2 failed. err is %d", ret);
    }
    ret = memcpy_s(old_info->chip_name, sizeof(old_info->chip_name),
                   new_info.chip_name, sizeof(new_info.chip_name));
    if (ret) {
        gplog(LOG_ERR, "Copy chip_name from dcmi_chip_info_v2 failed. err is %d", ret);
    }
    ret = memcpy_s(old_info->chip_ver, sizeof(old_info->chip_ver),
                   new_info.chip_ver, sizeof(new_info.chip_ver));
    if (ret) {
        gplog(LOG_ERR, "Copy chip_ver from dcmi_chip_info_v2 failed. err is %d", ret);
    }
    old_info->aicore_cnt = new_info.aicore_cnt;

    return NPU_OK;
}
STATIC int query_card_chip_total_info(struct npu_card_total_info *card_info)
{
    int chip_index, ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        ret = dcmiv2_get_device_type(card_info->card_id, &device_type);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            printf("Failed to get device type.\n");
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }
        ret = dcmiv2_get_device_health(card_info->card_id, &card_info->chip_health[chip_index]);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmiv2_get_device_health failed. err is %d", ret);
        }

        ret = get_chip_info_v2_as_old(card_info->card_id, &card_info->chip_info[chip_index]);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "get_chip_info_v2_as_old failed. err is %d", ret);
        }

        ret = dcmiv2_check_device_heartbeat_state(card_info->card_id);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Device heartbeat abnormal, skip query info, (card_id=%d, ret=%d)", card_info->card_id, ret);
            continue;
        }

        if (!dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
            ret = dcmiv2_get_device_pcie_info(card_info->card_id, &card_info->device_pcie_info[chip_index]);
            if (ret != DCMI_OK && ret != DCMI_ERR_CODE_NOT_SUPPORT) {
                gplog(LOG_ERR, "dcmiv2_get_device_pcie_info failed. err is %d", ret);
            }
            card_info->is_has_pcie = (ret == DCMI_OK);
        }
        ret = npu_get_chip_common_info(card_info->card_id, chip_index, &card_info->chip_common_info[chip_index]);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "get card %d device %d common info failed. err is %d", card_info->card_id, chip_index, ret);
        }
        if (check_result_for_dcmi_get_hbm_info()) {
            ret = dcmiv2_get_device_hbm_info(card_info->card_id, &card_info->chip_hbm_info[chip_index]);
            if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
                gplog(LOG_ERR, "dcmiv2_get_device_hbm_info failed. err is %d", ret);
            }
        }

        ret = npu_get_resource_info(card_info, chip_index);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "npu_get_resource_info failed. err is %d", ret);
        }
    }
    return NPU_OK;
}
#else
STATIC int get_chip_health(int card_id, int chip_index, unsigned int *chip_health)
{
    int ret = 0, chip_logid = 0;
    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = dcmi_get_device_logic_id(&chip_logid, card_id, chip_index);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Failed to get chip logic_id. err is %d.", ret);
            return ret;
        }
        ret = dcmiv2_get_device_health(chip_logid, chip_health);
    } else {
        ret = dcmi_get_device_health(card_id, chip_index, chip_health);
    }

    return ret;
}

STATIC int query_card_chip_total_info(struct npu_card_total_info *card_info)
{
    int chip_index, ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        ret = dcmi_get_device_type(card_info->card_id, chip_index, &device_type);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            printf("Failed to get device type.\n");
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }

        ret = get_chip_health(card_info->card_id, chip_index, &card_info->chip_health[chip_index]);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_health failed. err is %d", ret);
        }

        ret = dcmi_get_device_chip_info(card_info->card_id, chip_index, &card_info->chip_info[chip_index]);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_chip_info failed. err is %d", ret);
        }

        if (!dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
            ret = dcmi_get_device_pcie_info_v2(card_info->card_id, chip_index,
                &card_info->device_pcie_info[chip_index]);
            if (ret != DCMI_OK && ret != DCMI_ERR_CODE_NOT_SUPPORT) {
                gplog(LOG_ERR, "dcmi_get_device_pcie_info_v2 failed. err is %d", ret);
            }
            card_info->is_has_pcie = (ret == DCMI_OK);
        }

        ret = npu_get_chip_common_info(card_info->card_id, chip_index, &card_info->chip_common_info[chip_index]);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "get card %d device %d common info failed. err is %d", card_info->card_id, chip_index, ret);
        }

        if (!dcmi_board_chip_type_is_ascend_910b() && !dcmi_board_chip_type_is_ascend_910_93() &&
            !dcmi_board_chip_type_is_ascend_950()) { // 910B、910_93、950不支持该接口
            ret = dcmi_get_device_memory_info_v3(card_info->card_id, chip_index,
                &card_info->chip_memory_info[chip_index]);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "dcmi_get_device_memory_info_v3 failed. err is %d", ret);
            }
        }

        if (check_result_for_dcmi_get_hbm_info()) {
            ret = dcmi_get_device_hbm_info(card_info->card_id, chip_index, &card_info->chip_hbm_info[chip_index]);
            if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
                gplog(LOG_ERR, "dcmi_get_device_hbm_info failed. err is %d", ret);
            }
        }

        ret = npu_get_resource_info(card_info, chip_index);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "npu_get_resource_info failed. err is %d", ret);
        }
    }
    return NPU_OK;
}
#endif

STATIC int query_card_total_info(struct npu_total_info *npu_total_info, int *card_id_list, int card_count)
{
    int card_index, ret;
    struct npu_card_total_info *card_info = NULL;

    for (card_index = 0; card_index < card_count; card_index++) {
        npu_total_info->card_info[card_index].card_id = card_id_list[card_index];
        ret = npu_get_card_device_id(npu_total_info->card_info[card_index].card_id,
            &npu_total_info->card_info[card_index].chip_count,
            &npu_total_info->card_info[card_index].mcu_id,
            &npu_total_info->card_info[card_index].cpu_id);
        if (ret != NPU_OK) {
            printf("npu_get_card_device_id failed. err is %d\n", ret);
            return ret;
        }

        card_info = &npu_total_info->card_info[card_index];
        ret = query_card_chip_total_info(card_info);
        if (ret != NPU_OK) {
            printf("Failed to query card chip total info.\n");
            return ret;
        }
    }
    return NPU_OK;
}
// 获取卡列表（封装 NPU_SMI_V2 差异）
STATIC int get_card_list_internal(int card_id_list[], int *card_count, size_t max_count)
{
#ifdef NPU_SMI_V2
    int ret = dcmiv2_get_device_list(card_id_list, card_count, max_count);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_list failed. err is %d", ret);
        printf("Failed to get card number.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }
#else
    int ret = dcmi_get_card_list(card_count, card_id_list, max_count);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_card_list failed. err is %d", ret);
        printf("Failed to get card number.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }
#endif
    return NPU_OK;
}

// 获取驱动版本（封装 NPU_SMI_V2 差异）
STATIC int get_driver_version_internal(char version[], size_t version_size)
{
#ifdef NPU_SMI_V2
    int ret = dcmiv2_get_driver_version(version, version_size);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_driver_version failed. err is %d", ret);
        return ret;
    }
#else
    int ret = dcmi_get_driver_version(version, version_size);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_driver_version failed. err is %d", ret);
        return ret;
    }
#endif
    return NPU_OK;
}

STATIC int query_total_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int card_id_list[MAX_CARD_NUM] = {0};
    struct npu_total_info *npu_total_info = NULL;
    enum npu_chip_type chip_type = npu_get_chip_type();

    npu_total_info = (struct npu_total_info *)malloc(sizeof(struct npu_total_info));
    if (npu_total_info == NULL) {
        printf("Failed to alloc memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(npu_total_info, sizeof(struct npu_total_info), 0, sizeof(struct npu_total_info));
    if (ret != 0) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    ret = get_card_list_internal(card_id_list, &npu_total_info->card_count, MAX_CARD_NUM);
    if (ret != NPU_OK) {
        free(npu_total_info);
        return ret;
    }

    ret = query_card_total_info(npu_total_info, card_id_list, npu_total_info->card_count);
    if (ret != NPU_OK) {
        printf("Failed to query card total info.\n");
        free(npu_total_info);
        return ret;
    }

    ret = get_driver_version_internal(npu_total_info->software_version,
                                      sizeof(npu_total_info->software_version));
    if (ret != NPU_OK) {
        free(npu_total_info);
        return ret;
    }

    if (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        print_total_info_with_HBM(npu_total_info);
    } else {
        print_total_info(npu_total_info);
    }
    free(npu_total_info);
    return NPU_OK;
}

static int fill_npu_all_info(struct npu_all_info *npu_all_info)
{
    int index, ret;
    int card_id_list[MAX_CARD_NUM] = {0};

    if (npu_get_total_ascend_chip_count() == 0) {
        if (npu_board_type_is_station() || npu_board_type_is_hilens()) {
            ret = npu_get_elabel_pn_sn_items_info(0, npu_all_info);
            if (ret != NPU_OK) {
                printf("Failed to get card PN and SN number.\n");
                return ret;
            }
        }
        return NPU_OK;
    }

#ifndef NPU_SMI_V2
    ret = dcmi_get_card_num_list(&npu_all_info->card_count, card_id_list, MAX_CARD_NUM);
#else
    ret = dcmiv2_get_device_list(card_id_list, &npu_all_info->card_count, MAX_CARD_NUM);
#endif
    if (ret != DCMI_OK) {
        printf("Failed to get card number.\n");
        return NPU_ERR_CODE_INNER_ERR;
    }

    for (index = 0; index < npu_all_info->card_count; index++) {
        npu_all_info->card_info[index].card_id = card_id_list[index];
        ret = npu_get_card_device_id(npu_all_info->card_info[index].card_id,
            &npu_all_info->card_info[index].chip_count,
            &npu_all_info->card_info[index].mcu_id,
            &npu_all_info->card_info[index].cpu_id);
        if (ret != NPU_OK) {
            printf("Failed to get device num.\n");
                continue;
        }

        ret = npu_get_elabel_pn_sn_items_info(index, npu_all_info);
        if (ret != NPU_OK) {
            printf("Failed to get card(%d) PN and SN number.\n", index);
                continue;
        }
    }

    return NPU_OK;
}

int query_all_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct npu_all_info *npu_all_info;

    npu_all_info = (struct npu_all_info *)malloc(sizeof(struct npu_all_info));
    if (npu_all_info == NULL) {
        printf("Failed to malloc memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(npu_all_info, sizeof(struct npu_all_info), 0, sizeof(struct npu_all_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    ret = fill_npu_all_info(npu_all_info);
    if (ret == NPU_OK) {
        print_all_info(npu_all_info);
    }

    free(npu_all_info);
    return ret;
}

#ifdef NPU_SMI_V2
STATIC void query_card_mapping_info(struct npu_card_info *card_info)
{
    int ret, chip_index;
    unsigned int phy_id;
    enum npu_chip_type chip_type = npu_get_chip_type();

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        if (chip_type == NPU_CHIP_950) {
            ret = dcmiv2_get_chip_phy_id_by_dev_id(card_info->card_id, &phy_id);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "dcmiv2_get_chip_phy_id_by_dev_id failed. ret is %d", ret);
                continue;
            }
            card_info->chip_phy_id[chip_index] = (int)phy_id;
        }
        ret = get_chip_info_v2_as_old(card_info->card_id, &card_info->chip_info[chip_index]);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "get_chip_info_v2_as_old card %d, chip %d failed. err is %d",
                card_info->card_id, chip_index, ret);
            continue;
        }
    }
}
#else
STATIC void query_card_mapping_info(struct npu_card_info *card_info)
{
    int ret, chip_index;
    unsigned int phy_id;
    enum npu_chip_type chip_type = npu_get_chip_type();

    for (chip_index = 0; chip_index < card_info->chip_count; chip_index++) {
        ret = dcmi_get_device_logic_id(&card_info->chip_logic_id[chip_index], card_info->card_id, chip_index);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_logic_id card %d chip %d failed. err is %d",
                card_info->card_id, chip_index, ret);
            continue;
        }
        if (chip_type == NPU_CHIP_910_93) {
            ret = dcmi_get_device_phyid_from_logicid((unsigned int)card_info->chip_logic_id[chip_index], &phy_id);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "dcmi_get_device_phyid_from_logicid failed. ret is %d", ret);
                continue;
            }
            card_info->chip_phy_id[chip_index] = (int)phy_id;
        }
#ifdef ENABLE_EQUIPMENT
        if (chip_type == NPU_CHIP_950) {
            ret = dcmi_get_device_phyid_from_logicid((unsigned int)card_info->chip_logic_id[chip_index], &phy_id);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "dcmi_get_device_phyid_from_logicid failed. ret is %d", ret);
                continue;
            }
            card_info->chip_phy_id[chip_index] = (int)phy_id;
        }
#endif
        ret = dcmi_get_device_chip_info(card_info->card_id, chip_index, &card_info->chip_info[chip_index]);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "dcmi_get_device_chip_info card %d, chip %d failed. err is %d",
                card_info->card_id, chip_index, ret);
            continue;
        }
    }
}
#endif

int query_mapping_info(struct npu_smi_operate_info *operate_info)
{
    int card_index, ret;
    int card_id_list[MAX_CARD_NUM] = {0};
    struct npu_mapping_info *npu_mapping_info;
    enum npu_chip_type chip_type = npu_get_chip_type();

    npu_mapping_info = (struct npu_mapping_info *)malloc(sizeof(struct npu_mapping_info));
    if (npu_mapping_info == NULL) {
        printf("Failed to alloc memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(npu_mapping_info, sizeof(struct npu_mapping_info), 0, sizeof(struct npu_mapping_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

#ifndef NPU_SMI_V2
    ret = dcmi_get_card_num_list(&npu_mapping_info->card_count, card_id_list, MAX_CARD_NUM);
#else
    ret = dcmiv2_get_device_list(card_id_list, &npu_mapping_info->card_count, MAX_CARD_NUM);
#endif
    if (ret != DCMI_OK) {
        free(npu_mapping_info);
        printf("Failed to get card number.\n");
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    for (card_index = 0; card_index < npu_mapping_info->card_count; card_index++) {
        npu_mapping_info->card_info[card_index].card_id = card_id_list[card_index];
        ret = npu_get_card_device_id(
            npu_mapping_info->card_info[card_index].card_id, &npu_mapping_info->card_info[card_index].chip_count,
            &npu_mapping_info->card_info[card_index].mcu_id, &npu_mapping_info->card_info[card_index].cpu_id);
        if (ret != NPU_OK) {
            printf("Failed to get chip number of card%d.\n", card_index);
            continue;
        }
        query_card_mapping_info(&npu_mapping_info->card_info[card_index]);
    }

    if (chip_type == NPU_CHIP_910_93) {
        print_mapping_info_910_93(npu_mapping_info);
    } else if (chip_type == NPU_CHIP_950) {
#ifndef ENABLE_EQUIPMENT
        print_mapping_info_950(npu_mapping_info);
#else
        print_mapping_info_910_93(npu_mapping_info);
#endif
    } else {
        print_mapping_info(npu_mapping_info);
    }
    free(npu_mapping_info);
    return ret;
}

STATIC int show_ascend_vnpu_mode(struct npu_smi_operate_info *operate_info)
{
    int mode, ret;
    const char *mode_info[] = { "docker", "VM" };

    ret = dcmi_get_vdevice_mode(&mode);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_vdevice_mode failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if ((mode < 0) || (mode > 1)) {
        gplog(LOG_ERR, "mode %d is invalid.", mode);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    printf("\t%-30s : %s\n", "vnpu-mode", mode_info[mode]);
    return NPU_OK;
}

STATIC int show_pkcs_enable_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned char buf;
    unsigned int buf_size = sizeof(unsigned char);
    const char *pkcs_info[] = { "Enable", "Disable", "Disable" };

    //  pkcs使能整机生效，与device_id, card_id无关，参数不会使用，此处强制写0
    ret = dcmi_get_device_info(0, 0, DCMI_MAIN_CMD_SEC, DCMI_SEC_SUB_CMD_PSS, &buf, &buf_size);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (buf > 2) { // 2为pkcs_info最大属组下标
        gplog(LOG_ERR, "buf %u is invalid.", buf);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    printf("\t%-30s : %s\n", "Pkcs-enable Status", pkcs_info[buf]);
    return NPU_OK;
}

STATIC int show_vnpu_cfg_recover_state(struct npu_smi_operate_info *operate_info)
{
    unsigned int state = 0;

    if (npu_get_chip_type() != NPU_CHIP_310P && npu_is_in_virtual_machine()) {
        printf("This command cannot be executed on a VM or container.\n");
        return NPU_OK;
    }

    int ret = dcmi_get_vnpu_config_recover_mode(&state);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_vnpu_config_recover_mode failed. err is %d", ret);
        /* 该接口返回DCMI_ERR_CODE_NOT_SUPPORT，一种可能是芯片类型不匹配，另外是工作在SMP模式下，
           芯片类型在命令解析已经判断，此处返回不支持只有工作模式为SMP
        */
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("NPU is working in SMP mode, does not support querying %s\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("This device does not support querying %s.\n", operate_info->stype);
            ret = DCMI_OK;
        }
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "VNPU config recover mode", (state == 0) ? "Disable" : "Enable");
    return NPU_OK;
}

int query_pwm_mode(unsigned int *mode)
{
    int ret;
    int fd = -1;

    fd = open(DEV_PWM_NAME, O_RDONLY);
    if (fd == -1) {
        gplog(LOG_ERR, "open pwm dev failed.");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = ioctl(fd, PWM_CMD_GET_DUTY_RATIO_ADJUST_MODE, mode);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "ioctl query pwm mode failed. err is %d", ret);
        close(fd);
        return NPU_ERR_CODE_IOCTL_FAIL;
    }

    close(fd);
    return NPU_OK;
}

STATIC int show_pwm_mode(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int mode;
    const char *mode_string[] = {"manual", "auto"};

    ret = query_pwm_mode(&mode);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Get pwm mode failed. err is %d", ret);
        return ret;
    }

    if (mode < PWM_MANUAL || mode >= PWM_MODE_MAX) {
        gplog(LOG_ERR, "pwm mode is invalid.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    printf("\t%-30s : %s\n", "pwm-mode", mode_string[mode]);
    return NPU_OK;
}

STATIC int show_pwm_duty_ratio(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int fd = -1;
    struct pwm_info pwm_operate_info = { 0 };

    fd = open(DEV_PWM_NAME, O_RDONLY);
    if (fd == -1) {
        gplog(LOG_ERR, "open pwm dev failed.");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    pwm_operate_info.channel_num = PWM_CHANNEL;
    ret = ioctl(fd, PWM_CMD_GET_DUTY_RATIO, &pwm_operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "ioctl query pwm duty ratio failed. err is %d", ret);
        close(fd);
        return NPU_ERR_CODE_IOCTL_FAIL;
    }

    close(fd);
    printf("\t%-30s : %u\n", "pwm-duty-ratio(%)", pwm_operate_info.ratio);
    return NPU_OK;
}

STATIC int topo_read_line_info_from_file(const char *cfg_file_path, char *content)
{
    FILE *fp = NULL;
    int ret = 0;
    char file_string[NPU_MAX_LENTH] = {0};
    char real_conf_path[PATH_MAX + 1] = {0};

    if (realpath(cfg_file_path, real_conf_path) == NULL) {
        gplog(LOG_ERR, "node name invalid.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    fp = fopen(real_conf_path, "r");
    if (fp == NULL) {
        gplog(LOG_ERR, "file open failed. errno is %d\n", errno);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fgets(file_string, sizeof(file_string), fp) == NULL) {
        (void)fclose(fp);
        fp = NULL;
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    int len = strlen(file_string);
    if ((len > 0) && (file_string[len - 1] == '\n')) {
        file_string[len - 1] = 0;
    }

    ret = snprintf_s(content, TOPO_INFO_MAX_LENTH, TOPO_INFO_MAX_LENTH - 1, "%s", file_string);
    if (ret <= 0) {
        gplog(LOG_ERR, "failed to snprintf_s. ret is %d\n", ret);
        (void)fclose(fp);
        fp = NULL;
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    (void)fclose(fp);
    fp = NULL;
    return NPU_OK;
}

STATIC int topo_read_pcie_config_data(struct topo_pcie_id *pcie_id, unsigned char *data, int data_len)
{
    int ret;
    FILE *fp = NULL;
    char cfg_file_path[NPU_MAX_LENTH] = {0};
    char real_conf_path[PATH_MAX + 1] = {0};

    ret = snprintf_s(cfg_file_path, NPU_MAX_LENTH, NPU_MAX_LENTH - 1,
        "%s/%04x:%02x:%02x.%1u/config", SYS_BUS_PCI_DEVICE_PATH, pcie_id->domain,
        pcie_id->bdf_busid, pcie_id->bdf_deviceid, pcie_id->bdf_funcid);
    if (ret <= 0) {
        gplog(LOG_ERR, "failed to snprintf_s. ret is %d\n", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    if (realpath(cfg_file_path, real_conf_path) == NULL) {
        gplog(LOG_ERR, "node name invalid.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    fp = fopen(real_conf_path, "r");
    if (fp == NULL) {
        gplog(LOG_ERR, "failed to open file. file_name is %s", real_conf_path);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fgets((char*)data, data_len, fp) == NULL) {
        (void)fclose(fp);
        fp = NULL;
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (strlen((char*)data) < ((unsigned int)data_len - 1)) {
        gplog(LOG_INFO, "non-root users have low read permission. len is %zu", strlen((char*)data));
    }

    (void)fclose(fp);
    fp = NULL;
    return NPU_OK;
}

STATIC int topo_get_config_bytes(unsigned char *config, int offset, int len, unsigned int *output)
{
    int i;
    *output = 0;

    if (offset + len >= TOPO_PCIE_CONFIG_SPACE_LEN || (unsigned int)len > sizeof(int)) {
        gplog(LOG_ERR, "offset is out of range. offset is %d, len is %d", offset, len);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = 0; i < len; i++) {
        *output <<= BIT_OPERATION_ONE_BYTE;
        *output += config[offset + len - i - 1];
    }

    return NPU_OK;
}

STATIC int topo_get_pcie_cfg_info_by_pcie_id(struct topo_pcie_id *pcie_id, struct topo_pcie_cfg_info *config_info)
{
    int ret;
    unsigned char config[TOPO_PCIE_CONFIG_SPACE_LEN] = {0};
    unsigned char pci_cap_offset;
    unsigned int lnk_cap = 0;
    unsigned int lnk_sta = 0;

    ret = topo_read_pcie_config_data(pcie_id, config, TOPO_PCIE_CONFIG_SPACE_LEN);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to topo_read_pcie_config_data. ret is %d", ret);
        return ret;
    }

    ret = topo_get_config_bytes(config, TOPO_PCI_CLASS_CODE, DEV_CLASS_LEN, &config_info->dev_class);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to topo_get_config_bytes. dev_class is %u, ret is %d", config_info->dev_class, ret);
        return ret;
    }

    config_info->primary_bus = (unsigned int)config[TOPO_PCI_PRIMARY_BUS];
    config_info->secondary_bus = (unsigned int)config[TOPO_PCI_SECONDARY_BUS];
    pci_cap_offset = config[TOPO_PCI_CAPABILITY_LIST];

    ret = topo_get_config_bytes(config, pci_cap_offset + TOPO_PCIE_LNKCAP, LNK_CAP_LEN, &lnk_cap);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to topo_get_config_bytes. lnk_cap is %u, ret is %d", lnk_cap, ret);
        return ret;
    }

    config_info->cap_speed = lnk_cap & TOPO_PCIE_MASK_LNKCAP_SPEED;
    config_info->cap_width = (lnk_cap & TOPO_PCIE_MASK_LNKCAP_WIDTH) >> BIT_OPERATION_CAP_WIDTH;

    ret = topo_get_config_bytes(config, pci_cap_offset + TOPO_PCIE_LNKSTA, LNK_STA_LEN, &lnk_sta);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to topo_get_config_bytes. lnk_sta is %u, ret is %d", lnk_sta, ret);
        return ret;
    }

    config_info->sta_speed = lnk_sta & TOPO_PCIE_MASK_LNKSTA_SPEED;
    config_info->sta_width = (lnk_sta & TOPO_PCIE_MASK_LNKSTA_WIDTH) >> BIT_OPERATION_STA_WIDTH;

    return NPU_OK;
}

STATIC int topo_get_numa_node_by_pcie_id(struct topo_pcie_id *pcie_id, struct topo_pcie_info *pcie_dev_info_chain)
{
    int ret;
    char cfg_file_path[NPU_MAX_LENTH] = {0};
    char content[TOPO_INFO_MAX_LENTH] = {0};

    ret = snprintf_s(cfg_file_path, NPU_MAX_LENTH, NPU_MAX_LENTH - 1,
        "%s/%04x:%02x:%02x.%1u/local_cpulist", SYS_BUS_PCI_DEVICE_PATH, pcie_id->domain,
        pcie_id->bdf_busid, pcie_id->bdf_deviceid, pcie_id->bdf_funcid);
    if (ret <= 0) {
        gplog(LOG_ERR, "failed to snprintf_s. ret is %d", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = topo_read_line_info_from_file(cfg_file_path, pcie_dev_info_chain->local_cpu_list);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to topo_read_line_info_from_file. ret is %d", ret);
        return ret;
    }

    ret = snprintf_s(cfg_file_path, NPU_MAX_LENTH, NPU_MAX_LENTH - 1,
        "%s/%04x:%02x:%02x.%1u/numa_node", SYS_BUS_PCI_DEVICE_PATH, pcie_id->domain,
        pcie_id->bdf_busid, pcie_id->bdf_deviceid, pcie_id->bdf_funcid);
    if (ret <= 0) {
        gplog(LOG_ERR, "failed to snprintf_s. ret is %d", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = topo_read_line_info_from_file(cfg_file_path, content);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to topo_read_line_info_from_file. ret is %d", ret);
        return ret;
    }

    ret = sscanf_s(content, "%d", &pcie_dev_info_chain->numa_node);
    if (ret <= 0) {
        gplog(LOG_ERR, "failed to sscanf_s. ret is %d", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }
    if (pcie_dev_info_chain->numa_node == -1) {
        pcie_dev_info_chain->numa_node = 0;
    }

    return NPU_OK;
}

STATIC int topo_get_pcie_affinity_cpu_info_by_device_id(int numa_node, char *affinity_cpu)
{
    int ret;
    char cfg_file_path[NPU_MAX_LENTH] = {0};

    ret = snprintf_s(cfg_file_path, NPU_MAX_LENTH, NPU_MAX_LENTH - 1,
        "/sys/devices/system/node/node%d/cpulist", numa_node);
    if (ret <= 0) {
        gplog(LOG_ERR, "failed to snprintf_s. ret is %d", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = topo_read_line_info_from_file(cfg_file_path, affinity_cpu);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to topo_read_line_info_from_file. ret is %d", ret);
    }

    return ret;
}

STATIC int topo_check_dbf_name(char *dbf_name, bool *is_match)
{
    int ret;
    regex_t regex;

    ret = regcomp(&regex, "([0-9a-f]{4}):([0-9a-f]{2}):([0-9a-f]{2})\\.([0-f]{1})", REG_EXTENDED | REG_NOSUB);
    if (ret != 0) {
        gplog(LOG_ERR, "regcomp failed. ret is %d", ret);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = regexec(&regex, dbf_name, 0, NULL, 0);
    *is_match = (ret != REG_NOERROR) ? false : true;
    regfree(&regex);

    return NPU_OK;
}

STATIC int topo_get_list_dir(char *dir_name, char pcie_dir_list[PCIE_NUM_MAX][PCIE_NAME_LENTH])
{
    int ret = 0;
    int i = 0;
    bool is_match = false;
    struct dirent *ptr = NULL;

    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        gplog(LOG_ERR, "opendir failed. dir_name is %s", dir_name);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    while ((ptr = readdir(dir)) != NULL && (i < PCIE_NUM_MAX)) {
        ret = topo_check_dbf_name(ptr->d_name, &is_match);
        if (ret != NPU_OK || !is_match) {
            continue;
        }

        ret = strcpy_s(pcie_dir_list[i], PCIE_NAME_LENTH, ptr->d_name);
        if (ret < 0) {
            gplog(LOG_ERR, "strcpy_s failed. d_name is %s", ptr->d_name);
            closedir(dir);
            dir = NULL;
            return NPU_ERR_CODE_SECURE_FUN_FAIL;
        }
        i++;
    }
    closedir(dir);
    dir = NULL;

    return NPU_OK;
}

STATIC int topo_get_pcie_dev_info_from_dbf(char *dbf_name, struct topo_pcie_info *pcie_dev_info)
{
    bool is_match = false;

    int ret = topo_check_dbf_name(dbf_name, &is_match);
    if (ret != NPU_OK || !is_match) {
        gplog(LOG_ERR, "topo_check_dbf_name failed. dbf_name is %s, ret is %d", dbf_name, ret);
    }

    ret = sscanf_s(dbf_name, "%04x:%02x:%02x.%1u",
        &pcie_dev_info->pcie_id.domain, &pcie_dev_info->pcie_id.bdf_busid,
        &pcie_dev_info->pcie_id.bdf_deviceid, &pcie_dev_info->pcie_id.bdf_funcid);
    if (ret <= 0) {
        gplog(LOG_ERR, "failed to sscanf_s. dbf_name is %s, ret is %d", dbf_name, ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = topo_get_pcie_cfg_info_by_pcie_id(&pcie_dev_info->pcie_id, &pcie_dev_info->config);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to get pcie cfg info by pcie id. ret is %d", ret);
        return ret;
    }
    // 设置 CPU 信息
    ret = topo_get_numa_node_by_pcie_id(&pcie_dev_info->pcie_id, pcie_dev_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to get numa node by pcie id. ret is %d", ret);
        return ret;
    }

    ret = topo_get_pcie_affinity_cpu_info_by_device_id(pcie_dev_info->numa_node, pcie_dev_info->local_cpu_list);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to get pcie affinity cpu info by device id. ret is %d", ret);
        return ret;
    }

    return NPU_OK;
}

/* 读取系统中的所有pcie设备信息，然后保存起来 */
STATIC int topo_pcie_init(void)
{
    int ret;
    int i;
    char pcie_dir_list[PCIE_NUM_MAX][PCIE_NAME_LENTH] = {0};
    g_pcie_dev_info_list.prev_pcie_info = &g_pcie_dev_info_list;
    g_pcie_dev_info_list.next_pcie_info = &g_pcie_dev_info_list;

    ret = topo_get_list_dir(SYS_BUS_PCI_DEVICE_PATH, pcie_dir_list);
    if (ret != NPU_OK) {
        return ret;
    }

    for (i = 0; (i < PCIE_NUM_MAX) && (pcie_dir_list[i][0] != 0); i++) {
        struct topo_pcie_info pcie_dev_info = {0};

        ret = topo_get_pcie_dev_info_from_dbf(pcie_dir_list[i], &pcie_dev_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "topo_get_pcie_dev_info_from_dbf failed. ret is %d", ret);
            continue;
        }

        if ((pcie_dev_info.config.dev_class & TOPO_PCI_CLASS_CODE_MASK) != TOPO_PCI_BASE_CLASS_BRIDGE) {
            continue;
        }

        struct topo_pcie_info *p_pcie_dev_info = (struct topo_pcie_info *)malloc(sizeof(struct topo_pcie_info));
        if (p_pcie_dev_info == NULL) {
            gplog(LOG_ERR, "alloc memory failed.");
            return NPU_ERR_CODE_MEM_OPERATE_FAIL;
        }

        ret = memset_s(p_pcie_dev_info, sizeof(struct topo_pcie_info), 0, sizeof(struct topo_pcie_info));
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "memset_s failed. ret is %d", ret);
        }

        ret = memcpy_s(p_pcie_dev_info, sizeof(struct topo_pcie_info), &pcie_dev_info, sizeof(struct topo_pcie_info));
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "memcpy_s failed. ret is %d", ret);
        }
        // 构造bus->pcie的映射关系
        p_pcie_dev_info->prev_pcie_info = g_pcie_dev_info_list.prev_pcie_info;
        p_pcie_dev_info->next_pcie_info = &g_pcie_dev_info_list;
        g_pcie_dev_info_list.prev_pcie_info->next_pcie_info = p_pcie_dev_info;
        g_pcie_dev_info_list.prev_pcie_info = p_pcie_dev_info;
    }

    return NPU_OK;
}

/* 释放topo_pcie_init中申请的内存 */
STATIC void topo_pcie_free(void)
{
    struct topo_pcie_info *tmp_pcie_dev_info = NULL;
    struct topo_pcie_info *p_pcie_dev_info = g_pcie_dev_info_list.next_pcie_info;

    while (p_pcie_dev_info != &g_pcie_dev_info_list) {
        tmp_pcie_dev_info = p_pcie_dev_info;
        p_pcie_dev_info = tmp_pcie_dev_info->next_pcie_info;

        if (tmp_pcie_dev_info != NULL) {
            tmp_pcie_dev_info->prev_pcie_info->next_pcie_info = tmp_pcie_dev_info->next_pcie_info;
            tmp_pcie_dev_info->next_pcie_info->prev_pcie_info = tmp_pcie_dev_info->prev_pcie_info;
            free(tmp_pcie_dev_info);
            tmp_pcie_dev_info = NULL;
        }
    }
}

STATIC struct topo_pcie_info *topo_find_pice_info_from_primary_bus(int primary_bus)
{
    struct topo_pcie_info *p_pcie_dev_info = g_pcie_dev_info_list.next_pcie_info;

    for (; p_pcie_dev_info != &g_pcie_dev_info_list; p_pcie_dev_info = p_pcie_dev_info->next_pcie_info) {
        if (p_pcie_dev_info->config.secondary_bus == (unsigned int)primary_bus) {
            return p_pcie_dev_info;
        }
    }

    return NULL;
}

STATIC void topo_pcie_id_assignment(struct dcmi_pcie_info_all *topo_dcmi_pcie_info,
    struct topo_pcie_info *pcie_dev_info_chain)
{
    pcie_dev_info_chain->pcie_id.domain = (unsigned int)(topo_dcmi_pcie_info->domain);
    pcie_dev_info_chain->pcie_id.bdf_busid = topo_dcmi_pcie_info->bdf_busid;
    pcie_dev_info_chain->pcie_id.bdf_deviceid = topo_dcmi_pcie_info->bdf_deviceid;
    pcie_dev_info_chain->pcie_id.bdf_funcid = topo_dcmi_pcie_info->bdf_funcid;
}

STATIC int topo_get_full_pcie_chain(struct topo_pcie_info *pcie_dev_info_chain)
{
    unsigned int loop;
    unsigned int max_loop = 0xffff;
    unsigned int primary_bus = 0;
    struct topo_pcie_info *tmp_pcie_dev_info = NULL;

    for (loop = 0; loop < max_loop; loop++) {
        primary_bus = pcie_dev_info_chain->prev_pcie_info->config.primary_bus;
        tmp_pcie_dev_info = topo_find_pice_info_from_primary_bus(primary_bus);
        if (tmp_pcie_dev_info != NULL) {
            tmp_pcie_dev_info->prev_pcie_info = pcie_dev_info_chain->prev_pcie_info;
            pcie_dev_info_chain->prev_pcie_info = tmp_pcie_dev_info;
            pcie_dev_info_chain->pcie_size++;
        } else {
            break;
        }
    }

    if (loop == max_loop - 1) {
        gplog(LOG_ERR, "the loop exited due to reaching the maximum number of cycles. loop is %u", loop);
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

STATIC int topo_get_pcie_chain_by_card_id(int dev_id, struct topo_pcie_info *pcie_dev_info_chain)
{
    // dev_id说明：910_93传入phy_id再转换为card_id和device_id,其余芯片传入card_id
    int card_id, device_id, ret;
    struct dcmi_pcie_info_all topo_dcmi_pcie_info = {0};

    pcie_dev_info_chain->pcie_size = 0;
    if (dcmi_board_chip_type_is_ascend_910_93()) {
        ret = dcmi_get_card_id_device_id_from_phyid(&card_id, &device_id, (unsigned int)dev_id);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Get card id and device id failed. (ret=[%d]; phyid=[%d])", ret, dev_id);
            return ret;
        }
        ret = dcmi_get_device_pcie_info_v2(card_id, device_id, &topo_dcmi_pcie_info);
    } else {
        // 非910_93中npu的device_id默认为0
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_pcie_info_v2(dev_id, 0, &topo_dcmi_pcie_info);
#else
        ret = dcmiv2_get_device_pcie_info(dev_id, &topo_dcmi_pcie_info);
#endif
    }
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_pcie_info_v2 failed. ret is %d", ret);
        return ret;
    }

    topo_pcie_id_assignment(&topo_dcmi_pcie_info, pcie_dev_info_chain);

    ret = topo_get_pcie_cfg_info_by_pcie_id(&pcie_dev_info_chain->pcie_id, &pcie_dev_info_chain->config);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to get pcie cfg info by pcie id. ret is %d", ret);
        return ret;
    }

    ret = topo_get_numa_node_by_pcie_id(&pcie_dev_info_chain->pcie_id, pcie_dev_info_chain);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to get numa node by pcie id. ret is %d", ret);
        return ret;
    }

    ret = topo_get_pcie_affinity_cpu_info_by_device_id(pcie_dev_info_chain->numa_node,
        pcie_dev_info_chain->affinity_cpu);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to get pcie affinity cpu info by device id. ret is %d", ret);
        return ret;
    }

    pcie_dev_info_chain->pcie_size++;
    pcie_dev_info_chain->prev_pcie_info = pcie_dev_info_chain;
    pcie_dev_info_chain->next_pcie_info = pcie_dev_info_chain;

    // 获取完整链路
    ret = topo_get_full_pcie_chain(pcie_dev_info_chain);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "failed to get full pcie chain. ret is %d", ret);
        return ret;
    }

    return NPU_OK;
}

STATIC bool topo_is_same_pci_device(struct topo_pcie_info *device_a, struct topo_pcie_info *device_b)
{
    return (device_a->pcie_id.domain == device_b->pcie_id.domain) &&
        (device_a->pcie_id.bdf_busid == device_b->pcie_id.bdf_busid) &&
        (device_a->pcie_id.bdf_deviceid == device_b->pcie_id.bdf_deviceid) &&
        (device_a->pcie_id.bdf_funcid == device_b->pcie_id.bdf_funcid);
}

STATIC int hal_to_npu_topo_type(int hal_topo_type)
{
    switch (hal_topo_type) {
        case HAL_TOPOLOGY_HCCS:
            return TOPO_TYPE_HCCS;
            break;
        case HAL_TOPOLOGY_PIX:
            return TOPO_TYPE_PIX;
            break;
        case HAL_TOPOLOGY_PIB:
            return TOPO_TYPE_PXB;
            break;
        case HAL_TOPOLOGY_PHB:
            return TOPO_TYPE_PHB;
            break;
        case HAL_TOPOLOGY_SYS:
            return TOPO_TYPE_SYS;
            break;
        case HAL_TOPOLOGY_SIO:
            return TOPO_TYPE_SIO;
            break;
        case HAL_TOPOLOGY_HCCS_SW:
            return TOPO_TYPE_HCCS_SW;
            break;
        case HAL_TOPOLOGY_UB:
            return TOPO_TYPE_UB;
            break;
        default:
            return TOPO_TYPE_BUTT;
    }
}

STATIC void query_topo_type_1980b(int row, int col, struct topo_info *topo_operate_info)
{
    int ret;
#ifdef NPU_SMI_V2
    unsigned int phyid1, phyid2;
#endif
    int64_t value;

    if (row == col) {
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_SELF;
        return;
    }

#ifndef NPU_SMI_V2
    ret = halGetPairPhyDevicesInfo(topo_operate_info->device_id_list[row],
                                   topo_operate_info->device_id_list[col],
                                   0, &value);
#else
    ret = dcmiv2_get_chip_phy_id_by_dev_id(topo_operate_info->device_id_list[row], &phyid1);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get phyid1 failed. (ret=%d)", ret);
        return;
    }

    ret = dcmiv2_get_chip_phy_id_by_dev_id(topo_operate_info->device_id_list[col], &phyid2);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get phyid2 failed. (ret=%d)", ret);
        return;
    }
    ret = halGetPairPhyDevicesInfo((int)phyid1, (int)phyid2, 0, &value);
#endif
    if (ret) {
        gplog(LOG_ERR, "get pcie chain hccs status failed. (ret=%d)", ret);
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_BUTT;
        return;
    }
    topo_operate_info->topo_type_matrix[row][col] = hal_to_npu_topo_type(value);
    return;
}

STATIC void query_topo_type_1980_server(int row, int col, struct topo_info *topo_operate_info)
{
    if (((topo_operate_info->device_id_list[row] < TYPE_910_SERVER) &&
        (topo_operate_info->device_id_list[col] < TYPE_910_SERVER)) ||
        ((topo_operate_info->device_id_list[row] >= TYPE_910_SERVER) &&
        (topo_operate_info->device_id_list[col] >= TYPE_910_SERVER))) {
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_HCCS;
    } else {
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_SYS;
    }
}

STATIC void query_topo_type(int row, int col, struct topo_pcie_info *pcie_info, struct topo_info *topo_operate_info)
{
    int work_mode = 0;
    struct topo_pcie_info *root_dev_info_a = NULL;
    struct topo_pcie_info *root_dev_info_b = NULL;

    if (topo_is_same_pci_device(&pcie_info[row], &pcie_info[col])) {
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_SELF;
        return;
    }

    if (pcie_info[row].numa_node != pcie_info[col].numa_node) {
        if (npu_board_type_is_server()) {
            (void)dcmi_get_npu_work_mode(0, (unsigned char*)&work_mode);
            if (work_mode == NPU_SMP_WORK_MODE) {
                query_topo_type_1980_server(row, col, topo_operate_info);
                return;
            }
        }
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_SYS;
        return;
    }

    root_dev_info_a = pcie_info[row].prev_pcie_info;
    root_dev_info_b = pcie_info[col].prev_pcie_info;

    if (strcmp(root_dev_info_a->local_cpu_list, root_dev_info_b->local_cpu_list) == 0) {
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_PHB;
    } else {
        topo_operate_info->topo_type_matrix[row][col] = TOPO_TYPE_BUTT;
    }
}

STATIC void npu_caculate_device_topo_matrix(struct topo_pcie_info *pcie_dev_info_chain, int size,
    struct topo_info *topo_operate_info)
{
    int row, col;

    for (row = 0; (row < topo_operate_info->device_count) && (row < size); row++) {
        for (col = 0; (col < topo_operate_info->device_count) && (col < size); col++) {
            if (row > col) {
                topo_operate_info->topo_type_matrix[row][col] = topo_operate_info->topo_type_matrix[col][row];
            }

            if (dcmi_board_chip_type_is_ascend_910b() || dcmi_board_chip_type_is_ascend_910_93() ||
                dcmi_board_chip_type_is_ascend_950()) {
                query_topo_type_1980b(row, col, topo_operate_info);
            } else {
                query_topo_type(row, col, pcie_dev_info_chain, topo_operate_info);
            }
        }
    }
}


STATIC int match_ens_pattern(const char *str)
{
    // 空指针检查
    if (str == NULL) {
        return -1;
    }

    regex_t regex;
    regmatch_t matches[2];  // 0是整个匹配，1是第一个捕获组
    int ret;
    char pattern[] = "^ens([0-9]).*";  // 使用捕获组获取数字
    
    // 编译正则表达式
    ret = regcomp(&regex, pattern, REG_EXTENDED);
    if (ret) {
        fprintf(stderr, "无法编译正则表达式\n");
        return -1;
    }
    
    // 执行匹配
    ret = regexec(&regex, str, REGEX_MATCH_NUM, matches, 0);
    if (ret == 0) {
        // 成功匹配，提取捕获组中的数字
        if (matches[1].rm_so != -1) {  // 确保捕获组匹配成功
            char num_str[2] = {0};
            ret = strncpy_s(num_str, sizeof(num_str), str + matches[1].rm_so,
                matches[1].rm_eo - matches[1].rm_so);
            if (ret != 0) {
                regfree(&regex);
                return -1;
            }
            int num = atoi(num_str);
            regfree(&regex);
            return num;
        }
    }
    
    regfree(&regex);
    return -1;  // 匹配失败
}

STATIC void find_interfaces(char interfaces[][NIC_NAME_LEN])
{
    FILE *fp;
    char buffer[1024]; // 设置较大的1024以接收网卡信息
    char tempInterfaces[NIC_NAME_LEN];
    int ret;

    ret = memset_s(interfaces, NIC_PORT_NUM * NIC_NAME_LEN, 0, NIC_PORT_NUM * NIC_NAME_LEN);
    if (ret != 0) {
        return;
    }

    // 执行命令并读取输出
    fp = popen("ifconfig | grep 'flags'", "r");
    if (fp == NULL) {
        gplog(LOG_ERR, "Failed to run command");
        return;
    }
    // 读取输出并处理
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char *colon_pos = strchr(buffer, ':');

        if (colon_pos == NULL) {
            continue;
        }

        // 计算网卡名称长度
        size_t name_len = colon_pos - buffer;
        if (name_len >= NIC_NAME_LEN) {
            name_len = NIC_NAME_LEN - 1;
        }

        ret = strncpy_s(tempInterfaces, sizeof(tempInterfaces), buffer, name_len);
        if (ret != 0) {
            continue;
        }
        tempInterfaces[name_len] = '\0';  // 确保字符串终止

        int num = match_ens_pattern(tempInterfaces);
        if (num != -1 && num < NIC_PORT_NUM) {
            // 复制网卡名称到数组
            ret = strncpy_s(interfaces[num], NIC_NAME_LEN, tempInterfaces, name_len);
            if (ret != 0) {
                continue;
            }
            interfaces[num][name_len] = '\0';  // 确保字符串终止
        }
    }

    // 关闭管道
    pclose(fp);
}

STATIC void set_nic_npu_topo(struct topo_info *topo_operate_info, int nic_idx)
{
    int col;
    for (col = 0; col < NIC_NPU_RATIO; col++) {
        int npu_idx = nic_idx * NIC_NPU_RATIO + col;
        if (npu_idx < topo_operate_info->device_count) {
            topo_operate_info->nic_topo_matrix[nic_idx][npu_idx] = TOPO_TYPE_UB;
        }
    }
}

STATIC void npu_nic_topo_matrix(struct topo_info *topo_operate_info)
{
    // 空指针检查
    if (topo_operate_info == NULL) {
        gplog(LOG_ERR, "topo_operate_info is NULL");
        return;
    }

    int col, ret, nic_idx;
    char interfaces[NIC_PORT_NUM][NIC_NAME_LEN] = {0};

    // 初始化 NIC 拓扑矩阵为 NA (TOPO_TYPE_BUTT)
    for (nic_idx = 0; nic_idx < NIC_PORT_NUM; nic_idx++) {
        for (col = 0; col < topo_operate_info->device_count; col++) {
            topo_operate_info->nic_topo_matrix[nic_idx][col] = TOPO_TYPE_BUTT;
        }
        // 初始化 NIC 名称为空
        ret = memset_s(topo_operate_info->nic_name_list[nic_idx], NIC_NAME_LEN, 0, NIC_NAME_LEN);
        if (ret != 0) {
            return;
        }
    }

    // 查找网卡信息
    find_interfaces(interfaces);

    // 填充 NIC 拓扑矩阵：NIC与NPU按顺序1对NIC_NPU_RATIO对应
    // NIC0 -> NPU0-3, NIC1 -> NPU4-7, NIC2 -> NPU8-11, NIC3 -> NPU12-15
    for (nic_idx = 0; nic_idx < NIC_PORT_NUM; nic_idx++) {
        if (interfaces[nic_idx][0] == '\0') {
            continue;
        }
        // 网卡存在，复制名称并设置为 UB
        ret = strncpy_s(topo_operate_info->nic_name_list[nic_idx], NIC_NAME_LEN,
            interfaces[nic_idx], NIC_NAME_LEN - 1);
        if (ret != 0) {
            continue;
        }
        topo_operate_info->nic_name_list[nic_idx][NIC_NAME_LEN - 1] = '\0';

        // 设置对应的NIC_NPU_RATIO个NPU为UB
        set_nic_npu_topo(topo_operate_info, nic_idx);
    }

    return;
}

STATIC int query_ascend_topo_info(struct topo_info *topo_operate_info,
    struct topo_pcie_info *pcie_dev_info_chain, int size)
{
    int i;
    int ret = 0;

    if (!(dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id))) {
        // 获取所有device的pcie链路
        for (i = 0; i < topo_operate_info->device_count; i++) {
            ret = topo_get_pcie_chain_by_card_id(topo_operate_info->device_id_list[i], &pcie_dev_info_chain[i]);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "get pcie chain by device id failed. ret is %d", ret);
                return ret;
            }
        }
    }
 
    // 计算topo关系
    npu_caculate_device_topo_matrix(pcie_dev_info_chain, size, topo_operate_info);

    // 计算NIC拓扑关系
    npu_nic_topo_matrix(topo_operate_info);

    if (!(dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id))) {
        // cpu 亲和性
        for (i = 0; i < topo_operate_info->device_count; i++) {
            ret = snprintf_s(topo_operate_info->affinity_cpu_info[i],
                TOPO_INFO_MAX_LENTH, TOPO_INFO_MAX_LENTH - 1, "%s", pcie_dev_info_chain[i].affinity_cpu);
            if (ret <= 0) {
                gplog(LOG_ERR, "snprintf_s failed. ret is %d\n", ret);
                return NPU_ERR_CODE_SECURE_FUN_FAIL;
            }
        }
    }

    return NPU_OK;
}

int devdrv_get_host_phy_mach_flag(unsigned int dev_id, unsigned int *host_flag);

// x86仅910A2、910A3、910A5场景支持虚拟机
STATIC int rule_x86_vm_unsupported(unsigned int env_flag)
{
    if (!(dcmi_board_chip_type_is_ascend_910b() || dcmi_board_chip_type_is_ascend_910_93() ||
        dcmi_board_chip_type_is_ascend_950()) && dcmi_is_x86() && env_flag == ENV_VIRTUAL) {
        printf("This command cannot be executed on a VM.\n");
        gplog(LOG_OP, "This command cannot be executed on a VM.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    return DCMI_OK;
}
 
// arm仅910A3、910A5场景支持虚拟机
STATIC int rule_arm_vm_unsupported(unsigned int env_flag)
{
    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_950()) &&
        dcmi_is_arm() && env_flag == ENV_VIRTUAL) {
        printf("This command cannot be executed on a VM.\n");
        gplog(LOG_OP, "This command cannot be executed on a VM.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    return DCMI_OK;
}
 
// VM 容器不支持
STATIC int rule_vm_container(unsigned int env_flag)
{
    if (env_flag == ENV_VIRTUAL_PLAIN_CONTAINER || env_flag == ENV_VIRTUAL_PRIVILEGED_CONTAINER) {
        printf("This command cannot be executed on a VM-based container.\n");
        gplog(LOG_OP, "This command cannot be executed on a VM-based container.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    return DCMI_OK;
}

STATIC int query_topo_permission_check()
{
    int ret = 0;
    unsigned int env_flag = ENV_PHYSICAL;

    // 定义一个函数指针数组，元素是需要检查的规则函数
    int (*const rule_functions[3])(unsigned int) = {
        rule_x86_vm_unsupported,
        rule_arm_vm_unsupported,
        rule_vm_container
    };
    const size_t num_rules = sizeof(rule_functions) / sizeof(rule_functions[0]);

    // 虚拟机容器场景不支持
    ret = dcmi_get_environment_flag(&env_flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_environment_flag failed. err is %d.", ret);
        return ret;
    }

    // 遍历所有规则函数
    for (size_t i = 0; i < num_rules; ++i) {
        ret = rule_functions[i](env_flag);
        if (ret != DCMI_OK) {
            return ret;
        }
    }
    
    // 仅910A2、910A3、910A5支持x86
    if (!(dcmi_board_chip_type_is_ascend_910b() || dcmi_board_chip_type_is_ascend_910_93() ||
        dcmi_board_chip_type_is_ascend_950())) {
        if (!dcmi_is_arm()) {
            gplog(LOG_ERR, "this api is not support x86");
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
    }
 
    return DCMI_OK;
}

STATIC int topo_get_910_93_device_list(int *device_num, int *device_list, int list_len)
{
    int card_id, device_id, num;
    struct dcmi_card_info *card_info = NULL;
    int *device_id_curr = NULL;

    if (device_num == NULL || device_list == NULL) {
        gplog(LOG_ERR, "input para device_num or device_list is NULL.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if (list_len <= 0) {
        gplog(LOG_ERR, "input para list_len is invalid, list_len=%d.", list_len);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_get_run_env_init_flag() != TRUE) {
        gplog(LOG_ERR, "dcmi is not init.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (g_board_details.device_count > list_len) {
        gplog(LOG_ERR, "device_count is bigger than list_len. (device_count=[%d]; list_len=[%d]",
            g_board_details.device_count, list_len);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    num = 0;
    device_id_curr = device_list;
    for (card_id = 0; card_id < g_board_details.card_count; card_id++) {
        card_info = &g_board_details.card_info[card_id];
        for (device_id = 0; device_id < card_info->device_count; device_id++) {
            if ((num >= g_board_details.device_count) || (num >= list_len)) {
                break;
            }
            device_id_curr[num++] = (int)(card_info->device_info[device_id].phy_id);
        }
    }
    *device_num = num;

    return NPU_OK;
}

STATIC int topo_get_device_list(struct topo_info *topo_info)
{
    int ret;
 
    if (dcmi_board_chip_type_is_ascend_910_93()) {
        ret = topo_get_910_93_device_list(&topo_info->device_count, topo_info->device_id_list, MAX_CARD_NUM);
    } else {
#ifndef NPU_SMI_V2
        ret = dcmi_get_card_num_list(&topo_info->device_count, topo_info->device_id_list, MAX_CARD_NUM);
#else
        ret = dcmiv2_get_device_list(topo_info->device_id_list, &topo_info->device_count, MAX_CARD_NUM);
#endif
        ret = dcmi_to_npu_error_code(ret);
    }
 
    return ret;
}

STATIC int show_ascend_topo(struct npu_smi_operate_info *operate_info)
{
    int ret = 0;
    struct topo_info *topo_operate_info = NULL;
    struct topo_pcie_info pcie_dev_info_chain[MAX_CARD_NUM] = {0};

    ret = query_topo_permission_check();
    if (ret != DCMI_OK) {
        return ret;
    }

    topo_operate_info = (struct topo_info *)malloc(sizeof(struct topo_info));
    if (topo_operate_info == NULL) {
        printf("Failed to alloc memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(topo_operate_info, sizeof(struct topo_info), 0, sizeof(struct topo_info));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    ret = topo_get_device_list(topo_operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get card number failed. (ret=%d)", ret);
        goto out;
    }

    ret = topo_pcie_init();
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "topo_pcie_init failed. ret is %d", ret);
        goto out;
    }

    ret = query_ascend_topo_info(topo_operate_info, pcie_dev_info_chain, sizeof(pcie_dev_info_chain));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "query_ascend_topo_info failed. ret is %d", ret);
        goto out;
    }

    print_npu_topo_info((struct topo_info *)topo_operate_info);
    ret = NPU_OK;

out:
    topo_pcie_free();
    if (topo_operate_info != NULL) {
        free(topo_operate_info);
        topo_operate_info = NULL;
    }
    return ret;
}

STATIC int show_ascend_hccs_bandwidth_info(struct npu_smi_operate_info *operate_info)
{
    int ret, env_offset;
    struct dcmi_hccs_bandwidth_info hccs_bandwidth_info = {0};
    if ((operate_info->id == NPU_INVALID_VALUE) || (operate_info->chip_id == NPU_INVALID_VALUE)) {
        printf("\nThis command must input card id and chip id.\n\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if (operate_info->profiling_time == NPU_INVALID_VALUE) {
        printf("\nThis command must input profiling_time(1-1000, ms).\n\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    hccs_bandwidth_info.profiling_time = operate_info->profiling_time;
    ret = dcmi_get_hccs_link_bandwidth_info(operate_info->id, operate_info->chip_id, &hccs_bandwidth_info);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }
    env_offset = get_env_offset_info(operate_info);
    printf_hccs_bandwidth_info(&hccs_bandwidth_info, env_offset);
    return NPU_OK;
}

STATIC int show_ascend_sys_log_info(struct npu_smi_operate_info *operate_info)
{
    int ret, gear, card_num, persistence_enable = 0;
    int card_id_list[MAX_CARD_NUM] = {0};
    int logic_id_list[MAX_CARD_NUM] = {0};
    int card_msn_existed[MAX_CARD_NUM] = {0}; // 有日志落盘持久化进程的card id列表
    char cfg[SYS_LOG_MAX_CMD_LINE] = {0};
    char path[PATH_MAX + 1] = {0}; // 用户输入日志落盘的路径
 
    ret = memset_s(card_msn_existed, sizeof(card_msn_existed), -1, sizeof(card_msn_existed));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Call memset_s failed. err is %d", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (operate_info->has_id) {
        printf("This command does not support input card id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = get_card_and_logic_id_list(card_id_list, logic_id_list, &card_num);
    if (ret != NPU_OK) {
        printf("Get card id list or logic id list failed. ret = %d.\n", ret);
        return ret;
    }

    ret = get_card_msn_existed_list(card_num, logic_id_list, card_id_list, card_msn_existed);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get_card_msn_existed_list failed, ret = %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmi_get_syslog_persistence_info(&persistence_enable, cfg, sizeof(cfg) / sizeof(char));
    if (ret == DCMI_ERR_CODE_CONFIG_INFO_NOT_EXIST) {
        goto SYSLOG_DUMP_INFO;
    } else if (ret == DCMI_ERR_CODE_SYSLOG_CONFIG_ILLEGAL) {
        printf("ERROR: The configuration file has been maliciously modified, "
                "please clear configuration and stop syslog collecting process first.\n");
        return NPU_ERR_CODE_INNER_ERR;
    } else if (ret != DCMI_OK) {
        printf("Failed to show syslog dump mode.\n");
        return dcmi_to_npu_error_code(ret);
    }

    if (cfg[0] != '\0') {
        ret = sscanf_s(cfg, "/usr/local/bin/npu-smi set -t sys-log-dump -s %d -f %s", &gear, path, sizeof(path));
        if (ret < 1) {  /* 解析失败 */
            gplog(LOG_ERR, "sscanf_s failed. ret is %d", ret);
            return NPU_ERR_CODE_INNER_ERR;
        }
    }
SYSLOG_DUMP_INFO:
    gplog(LOG_OP, "Query syslog info success.");
    printf_syslog_dump_info(ret, persistence_enable, gear, path, card_msn_existed,
                            sizeof(path) / sizeof(char), sizeof(card_msn_existed) / sizeof(int));
    return NPU_OK;
}

STATIC int show_ascend_customop_recover_state(struct npu_smi_operate_info *operate_info)
{
    unsigned int state = 0;

    int ret = dcmi_get_custom_op_config_recover_mode(&state);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_custom_op_config_recover_mode failed. err is %d", ret);

        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support querying %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine can call this api.\n");
            ret = DCMI_OK;
        }
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "Custom-op config recover mode", (state == 0) ? "Disable" : "Enable");
    return NPU_OK;
}

static struct npu_operate_table_item g_query_common_info_table[] = {
    {KEY_MANAGE, show_key_manage_info},
    {VNPU_MODE, show_ascend_vnpu_mode},
    {VNPU_CFG_RECOVER, show_vnpu_cfg_recover_state},
    {PKCS_ENABLE, show_pkcs_enable_info},
    {PWM_MODE, show_pwm_mode},
    {PWM_DUTY_RATIO, show_pwm_duty_ratio},
    {NPU_DEFAULT_VALUE, show_ascend_card_default_proc},
    {TEMPLATE_INFO, show_ascend_card_template_info},
    {TOPO, show_ascend_topo},
    {HCCS_BANDWIDTH_INFO, show_ascend_hccs_bandwidth_info},
    {SYS_LOG_INFO, show_ascend_sys_log_info},
    {CUSTOM_OP_CFG_RECOVER, show_ascend_customop_recover_state},
    {DEVICE_SHARE_CFG_RECOVER, show_ascend_device_share_config_recover_info},
    {MULTI_DIE_POLICY, show_card_multi_die_policy_info},
    {MULTI_DIE_POLICY_CFG_RECOVER, show_ascend_multi_die_policy_config_recover_info}
};

STATIC int query_common_info(struct npu_smi_operate_info *operate_info)
{
    int ret = NPU_ERR_CODE_NOT_SUPPORT;
    size_t table_index, table_size;

    table_size = sizeof(g_query_common_info_table) / sizeof(g_query_common_info_table[0]);
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == g_query_common_info_table[table_index].fun_index) {
            ret = g_query_common_info_table[table_index].proc_func(operate_info);
            break;
        }
    }

    bool check_result = ((ret != NPU_OK) && (operate_info->type != NPU_DEFAULT_VALUE) &&
        (ret != NPU_ERR_CODE_OPER_NOT_PERMITTED) && (ret != NPU_ERR_CODE_NOT_SUPPORT) &&
        (ret != NPU_ERR_CODE_INVALID_PARAMETER) && (ret != -EPERM));
    if (check_result) {
        printf("Failed to query \"%s\" info.\n", operate_info->stype);
    } else if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support querying %s.\n", operate_info->stype);
        ret = NPU_OK;
    }
    return ret;
}

STATIC int get_total_info(struct npu_smi_operate_info *operate_info)
{
    if (npu_check_is_has_d_chip() == FALSE) {
        npu_info_show_help(operate_info);
        return NPU_OK;
    }

    return query_total_info(operate_info);
}

STATIC int get_watch_info(struct npu_smi_operate_info *operate_info)
{
    return npu_info_proc_watch_cmd(operate_info);
}

STATIC int get_all_info(struct npu_smi_operate_info *operate_info)
{
    return query_all_info(operate_info);
}

STATIC int get_mapping_info(struct npu_smi_operate_info *operate_info)
{
    return query_mapping_info(operate_info);
}

STATIC int get_default_info(struct npu_smi_operate_info *operate_info)
{
    if (operate_info->is_common) {
        return query_common_info(operate_info);
    } else if (operate_info->is_chip) {
        return query_chip_info(operate_info);
    } else {
        return query_card_info(operate_info);
    }
}

STATIC int npu_info_run(struct npu_smi_operate_info *operate_info)
{
    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    int query_defalut_flag = 1;

    struct npu_operate_table_item query_info_table[] = {
        {operate_info->is_total, get_total_info},       // npu-smi info
        {operate_info->is_watch, get_watch_info},       // npu-smi info watch
        {operate_info->is_all, get_all_info},           // npu-smi info -l
        {operate_info->is_mapping, get_mapping_info},   // npu-smi info -m
        {query_defalut_flag, get_default_info}          // npu-smi info -t
    };

    size_t table_index;
    size_t table_size = sizeof(query_info_table) / sizeof(query_info_table[0]);
    for (table_index = 0; table_index < table_size; table_index++) {
        if (query_info_table[table_index].fun_index) {
            ret = query_info_table[table_index].proc_func(operate_info);
            break;
        }
    }

    if (ret == NPU_ERR_CODE_INVALID_PARAMETER) {
        npu_info_show_help(operate_info);
    }
    return ret;
}

int check_env_info(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    if (type_need_check_root(argc, argv)) {
        gplog(LOG_OP, "This environment is not permitted to query this info.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (type_unsupport_info_in_common_docker(argc, argv)) {
        printf("This command cannot be executed on a common container.\n");
        gplog(LOG_OP, "This environment is not permitted to query this info.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    /* 非910B产品不支持在容器中查询info-vnpu */
    if ((type_is_info_vnpu(argc, argv)) && (!dcmi_board_chip_type_is_ascend_910b()) && (npu_is_in_docker())) {
        gplog(LOG_OP, "This device does not support querying info-vnpu.");
        printf("This command cannot be executed on a container.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    return NPU_OK;
}

int npu_info_main(struct npu_smi_operate_info *operate_info, int argc, char **argv)
{
    int ret;

#ifdef _WIN32
    ret = user_egid_check();
    if (ret != NPU_OK) {  // windows下，海思接口要求管理员权限，此处对权限进行检测。
        return ret;
    }
#endif

    if (argc < NPU_INFO_PARAMETER_MIN_NUM) {
        operate_info->is_total = TRUE;
        return npu_info_run(operate_info);
    }

    ret = check_env_info(operate_info, argc, argv);
    if (ret != NPU_OK) {
        // 已在check_env_info函数中增加日志和打印，此处直接返回
        return ret;
    }

    ret = parse_npu_info_param(operate_info, argc, argv);

#ifdef NPU_SMI_V2
    if (operate_info->is_chip) {
        printf("This device does not support input parameter of -c.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
#endif
    if (ret == NPU_OK) {
        return npu_info_run(operate_info);
    }

    if ((ret == NPU_ERR_CODE_INVALID_PARAMETER) || (ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP)) {
        if (operate_info->is_watch) {
            npu_info_watch_help(operate_info);
        } else {
            npu_info_show_help(operate_info);
        }
    }

    if ((ret == NPU_ERR_CODE_PARAMETER_SHOW_HELP) || (ret == NPU_ERR_CODE_NOT_SUPPORT) ||
        (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED)) {
        ret = NPU_OK;
    }
    return ret;
}

int show_ascend_device_share_config_recover_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int state = 0;

    if (operate_info->has_id) {
        printf("This command does not support entering card id.\n");
        gplog(LOG_ERR, "This command does not support entering card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_get_device_share_config_recover_mode(&state);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_share_config_recover_mode failed. err is %d", ret);

        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support querying %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine or on physical privilege container "
                   "can call this api.\n");
            ret = DCMI_OK;
        }
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "Device-share config recover mode", (state == 0) ? "Disable" : "Enable");
    return NPU_OK;
}

int show_ascend_multi_die_policy_config_recover_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int state = 0;

    if (operate_info->has_id) {
        printf("This command does not support entering card id.\n");
        gplog(LOG_ERR, "This command does not support entering card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_get_multi_die_policy_config_recover_mode(&state);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_multi_die_policy_config_recover_mode failed. err is %d", ret);

        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support querying %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine or on physical privilege container "
                   "can call this api.\n");
            ret = DCMI_OK;
        }
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "Multi-die-policy config recover mode", (state == 0) ? "Disable" : "Enable");
    return NPU_OK;
}

int show_card_multi_die_policy_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_multi_die_policy policy = 0;
 
    if (operate_info->has_id) {
        printf("This command does not support entering card id.\n");
        gplog(LOG_ERR, "This command does not support entering card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
 
    ret = dcmi_get_multi_die_policy(&policy);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_multi_die_policy failed. err is %d", ret);
 
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            printf("This device does not support querying %s.\n", operate_info->stype);
            ret = DCMI_OK;
        } else if (ret == DCMI_ERR_CODE_OPER_NOT_PERMITTED) {
            printf("Operation not permitted, only root user on physical machine or on physical privilege container "
                   "can call this api.\n");
            ret = DCMI_OK;
        }
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "Multi_die policy",
        (policy == DCMI_MULTI_DIE_UNION_POLICY) ? "UNION_POLICY" : "INDEP_POLICY");
    return NPU_OK;
}