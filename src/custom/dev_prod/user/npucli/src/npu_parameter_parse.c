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
#include <stdbool.h>

#include "npu_smi.h"
#include "securec.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_log.h"

#include "dcmi_virtual_intf.h"
#include "npu_cmd_parse.h"
#include "npu_run_env.h"
#include "npu_common.h"
#include "npu_card_set.h"
#include "npu_parameter_parse.h"

static unsigned char g_para_i_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_c_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_d_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_m_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_f_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_s_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_v_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_p_operate_support[ITEMS_MAX] = {0};
static unsigned char g_para_g_operate_support[ITEMS_MAX] = {0};

int parse_upgrade_help_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    if (cur >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_ERR_CODE_PARAMETER_SHOW_HELP;
}

static void init_para_i_operate_support(void)
{
    g_para_i_operate_support[BOARD] = 1;
    g_para_i_operate_support[COMMON] = 1;
    g_para_i_operate_support[FLASH] = 1;
    g_para_i_operate_support[MEMORY] = 1;
    g_para_i_operate_support[USAGES] = 1;
    g_para_i_operate_support[TEMP] = 1;
    g_para_i_operate_support[POWER] = 1;
    g_para_i_operate_support[VOLT] = 1;
    g_para_i_operate_support[HEALTH] = 1;
    g_para_i_operate_support[ECC] = 1;
    g_para_i_operate_support[P2P_ENABLE_FLAG] = 1;
    g_para_i_operate_support[SENSORS] = 1;
    g_para_i_operate_support[SYS_TIME] = 1;
    g_para_i_operate_support[IIC_CHECK] = 1;
    g_para_i_operate_support[PRODUCT_TYPE] = 1;
    g_para_i_operate_support[ERR_COUNT] = 1;
    g_para_i_operate_support[VNPU_INFO] = 1;
    g_para_i_operate_support[RESET_VNPU] = 1;
    g_para_i_operate_support[FIRST_POWER_ON_DATE] = 1;
    g_para_i_operate_support[PROC_MEM] = 1;
    g_para_i_operate_support[VNPU_SVM_INFO] = 1;
    g_para_i_operate_support[ECC_ENABLE] = 1;
    g_para_i_operate_support[COLLECT_LOG] = 1;
    g_para_i_operate_support[RESET] = 1;
    g_para_i_operate_support[DEVICE_SHARE] = 1;
    g_para_i_operate_support[NVE_LEVEL] = 1;
    g_para_i_operate_support[ECC_INFO_CLEAR] = 1;
    g_para_i_operate_support[ECC_INFO] = 1;
    g_para_i_operate_support[CUSTOMIZED_INFO] = 1;
    g_para_i_operate_support[SSH_ENABLE] = 1;
    g_para_i_operate_support[REVOCATION] = 1;
    g_para_i_operate_support[ERR_COUNT_CLEAR] = 1;
    g_para_i_operate_support[MCU_MONITOR] = 1;
    g_para_i_operate_support[BOOT_AREA] = 1;
    g_para_i_operate_support[AICPU_CONF] = 1;
    g_para_i_operate_support[DISK_POWER] = 1;
    g_para_i_operate_support[IP] = 1;
    g_para_i_operate_support[VNPU_CREATE] = 1;
    g_para_i_operate_support[VNPU_DESTORY] = 1;
    g_para_i_operate_support[SET_VNPU_SVM] = 1;
    g_para_i_operate_support[CPU_NUM_CFG] = 1;
    g_para_i_operate_support[MCU_ITEM] = 1;
    g_para_i_operate_support[BOOTLOADER] = 1;
    g_para_i_operate_support[VRD_ITEM] = 1;
    g_para_i_operate_support[WATCH_INFO] = 1;
    g_para_i_operate_support[MAC_ADDR] = 1;
    g_para_i_operate_support[POWER_STATE] = 1;
}

int check_para_i_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_i_operate_support[index];
}

static void init_para_c_operate_support(void)
{
    g_para_c_operate_support[BOARD] = 1;
    g_para_c_operate_support[FLASH] = 1;
    g_para_c_operate_support[MEMORY] = 1;
    g_para_c_operate_support[USAGES] = 1;
    g_para_c_operate_support[TEMP] = 1;
    g_para_c_operate_support[POWER] = 1;
    g_para_c_operate_support[VOLT] = 1;
    g_para_c_operate_support[HEALTH] = 1;
    g_para_c_operate_support[MCU_MONITOR] = 1;
    g_para_c_operate_support[ECC] = 1;
    g_para_c_operate_support[RESET] = 1;
    g_para_c_operate_support[SENSORS] = 1;
    g_para_c_operate_support[SYS_TIME] = 1;
    g_para_c_operate_support[PRODUCT_TYPE] = 1;
    g_para_c_operate_support[ERR_COUNT] = 1;
    g_para_c_operate_support[VNPU_INFO] = 1;
    g_para_c_operate_support[PROC_MEM] = 1;
    g_para_c_operate_support[VNPU_SVM_INFO] = 1;
    g_para_c_operate_support[DEVICE_SHARE] = 1;
    g_para_c_operate_support[NVE_LEVEL] = 1;
    g_para_c_operate_support[ECC_INFO_CLEAR] = 1;
    g_para_c_operate_support[ECC_INFO] = 1;
    g_para_c_operate_support[SSH_ENABLE] = 1;
    g_para_c_operate_support[ERR_COUNT_CLEAR] = 1;
    g_para_c_operate_support[REVOCATION] = 1;
    g_para_c_operate_support[MCU_MONITOR] = 1;
    g_para_c_operate_support[BOOT_AREA] = 1;
    g_para_c_operate_support[AICPU_CONF] = 1;
    g_para_c_operate_support[DISK_POWER] = 1;
    g_para_c_operate_support[IP] = 1;
    g_para_c_operate_support[VNPU_CREATE] = 1;
    g_para_c_operate_support[VNPU_DESTORY] = 1;
    g_para_c_operate_support[SET_VNPU_SVM] = 1;
    g_para_c_operate_support[CPU_NUM_CFG] = 1;
    g_para_c_operate_support[WATCH_INFO] = 1;
    g_para_c_operate_support[MAC_ADDR] = 1;
    g_para_c_operate_support[POWER_STATE] = 1;
}

int  check_para_c_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_c_operate_support[index];
}

static void init_para_d_operate_support(void)
{
    g_para_d_operate_support[ECC_ENABLE] = 1;
    g_para_d_operate_support[DEVICE_SHARE] = 1;
    g_para_d_operate_support[SSH_ENABLE] = 1;
    g_para_d_operate_support[MCU_MONITOR] = 1;
    g_para_d_operate_support[AICPU_CONF] = 1;
    g_para_d_operate_support[DISK_POWER] = 1;
    g_para_d_operate_support[VNPU_MODE] = 1;
    g_para_d_operate_support[VNPU_CFG_RECOVER] = 1;
    g_para_d_operate_support[WATCH_INFO] = 1;
    g_para_d_operate_support[PWM_MODE] = 1;
    g_para_d_operate_support[PWM_DUTY_RATIO] = 1;
    g_para_d_operate_support[MAC_ADDR] = 1;
    g_para_d_operate_support[POWER_STATE] = 1;
}

int check_para_d_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_d_operate_support[index];
}

static void init_para_f_operate_support(void)
{
    g_para_f_operate_support[CUSTOMIZED_INFO] = 1;
    g_para_f_operate_support[REVOCATION] = 1;
    g_para_f_operate_support[VNPU_CREATE] = 1;
    g_para_f_operate_support[MCU_ITEM] = 1;
    g_para_f_operate_support[BOOTLOADER] = 1;
    g_para_f_operate_support[VRD_ITEM] = 1;
}

int check_para_f_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_f_operate_support[index];
}

static void init_para_m_operate_support(void)
{
    g_para_m_operate_support[RESET] = 1;
}

int check_para_m_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_m_operate_support[index];
}

static void init_para_s_operate_support(void)
{
    g_para_s_operate_support[IP] = 1;
    g_para_s_operate_support[KEY_MANAGE] = 1;
    g_para_s_operate_support[WATCH_INFO] = 1;
    g_para_s_operate_support[MAC_ADDR] = 1;
}

int check_para_s_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_s_operate_support[index];
}


static void init_para_v_operate_support(void)
{
    g_para_v_operate_support[VNPU_CREATE] = 1;
    g_para_v_operate_support[VNPU_DESTORY] = 1;
    g_para_v_operate_support[SET_VNPU_SVM] = 1;
    g_para_v_operate_support[CPU_NUM_CFG] = 1;
}

int check_para_v_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_v_operate_support[index];
}

static void init_para_p_operate_support(void)
{
    g_para_p_operate_support[PHYID_REMAP] = 1;
}

static void init_para_g_operate_support(void)
{
    g_para_g_operate_support[VNPU_CREATE] = 1;
}

int check_para_g_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_g_operate_support[index];
}

int check_para_p_is_support(unsigned int index)
{
    if (index >= ITEMS_MAX) {
        return 0;
    }
    return g_para_p_operate_support[index];
}

void init_para_support_map(void)
{
    init_para_i_operate_support();
    init_para_c_operate_support();
    init_para_d_operate_support();
    init_para_f_operate_support();
    init_para_m_operate_support();
    init_para_s_operate_support();
    init_para_v_operate_support();
    init_para_p_operate_support();
    init_para_g_operate_support();
}


int parse_type_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return set_type(operate_info, argv[cur + 1]);
}

int parse_card_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;

    if (cur + 1 >= argc) {
        printf("Invalid card id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = set_id(operate_info, argv[cur + 1]);
#ifdef NPU_SMI_V2 // A5 chip_id默认值为0
    operate_info->chip_id = 0;
#endif
    operate_info->has_id = TRUE;
    
    if (strcmp(operate_info->stype, "reset-vnpu") == 0) {
        ret = reset_vnpu_para_check(operate_info);
    } else if (npu_check_card_id(operate_info->id) != NPU_OK) {
        printf("Invalid card id.\n");
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return ret;
}

int parse_chip_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;

    if (cur + 1 >= argc) {
        printf("Invalid chip id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = set_chip_id(operate_info, argv[cur + 1]);
    operate_info->is_chip = TRUE;
    if (npu_check_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK) {
        printf("Invalid chip id.\n");
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int parse_watch_type_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->is_watch == WATCH_CHIP_INFO) {
        ret = set_watch_type(operate_info, argv[cur + 1]);
    } else {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int parse_watch_delay_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->is_watch) {
        ret = set_watch_delay(operate_info, argv[cur + 1]);
    } else {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int parse_chip_all_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    if (cur >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    operate_info->is_all = TRUE;
    return NPU_OK;
}

int parse_chip_lane_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    int len_stype;
    if (cur >= argc) {
        gplog(LOG_ERR, "argc is invalid, cur is %d", cur);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if (strlen(operate_info->stype) >= strlen(STYPE_CMD_HCCS)) {
        len_stype = strlen(operate_info->stype);
    } else {
        len_stype = strlen(STYPE_CMD_HCCS);
    }
    if (strncmp(operate_info->stype, STYPE_CMD_HCCS, len_stype) == 0) {
        if (cur + 1 >= argc) {
            gplog(LOG_ERR, "%s is nothing behind -lane.", operate_info->stype);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
        ret = set_lane_id(operate_info, argv[cur + 1]);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "set lane id failed ");
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    } else {
        gplog(LOG_ERR, "cmp lane stype failed ");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

/* 函数功能：修改 is_hccs_topo 状态 */
int parse_chip_hccs_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    if (cur >= argc) {
        gplog(LOG_ERR, "invalid cur:%d and argc:%d ", cur, argc);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    operate_info->is_hccs_topo = TRUE;
    return NPU_OK;
}

int parse_chip_mapping_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    if (cur >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    operate_info->is_mapping = TRUE;
    return NPU_OK;
}

int parse_help_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    if (cur >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_ERR_CODE_PARAMETER_SHOW_HELP;
}

int parse_phyid_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;

    if (cur + 1 >= argc) {
        printf("Invalid phy id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = set_phy_id(operate_info, argv[cur + 1]);
#ifndef NPU_SMI_V2
    operate_info->is_chip = TRUE;
#endif
    return ret;
}

int parse_str_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (strncmp(operate_info->stype, "qos-master-config", strlen("qos-master-config")) == 0) {
        ret = set_qos_cfg_para_parse(operate_info, cur + 1, argc, argv);
    } else {
        if (cur + 1 >= argc) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
        ret = set_sdata(operate_info, argv[cur + 1]);
        if (ret != NPU_OK) {
            ret = NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }
    return ret;
}

int parse_enable_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;

    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = set_enable_value(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int parse_chan_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;

    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = set_chan_src(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int parse_multi_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret = NPU_ERR_CODE_INVALID_PARAMETER;

    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (strcmp((const char*)operate_info->stype, "vnpu-svm") == 0) {
        ret = set_vdev_svm_param(operate_info, argv[cur + 1]);
    } else if (strcmp((const char*)operate_info->stype, "create-vnpu") == 0) {
        ret = set_vdev_id_param(operate_info, argv[cur + 1]);
    } else if (strcmp((const char*)operate_info->stype, "destroy-vnpu") == 0) {
        ret = set_destroy_vdev_param(operate_info, argv[cur + 1]);
    } else if (strcmp((const char*)operate_info->stype, "cpu-num-cfg") == 0) {
        ret = set_cpu_num_param(operate_info, argv[cur + 1]);
    } else {
        gplog(LOG_ERR, "not support %s", operate_info->stype);
    }

    if (ret != NPU_OK) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

static int check_vdev_virgroupid_param(const char *input, unsigned int *virgroup_id)
{
    long tmp_id;
    char *end_ptr;
    int decimal = 10;

    if (input == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    errno = 0;
    tmp_id = strtol(input, &end_ptr, decimal);
    if (end_ptr == input || *end_ptr != '\0') {
        gplog(LOG_ERR, "invalid virgroupid  %s, error = %s", input, strerror(errno));
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (tmp_id >= VIRGROUP_MAX || tmp_id < VIRGROUP_0) {
        gplog(LOG_ERR, "invalid virgroupid  %s", input);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    *virgroup_id = (unsigned int)tmp_id;

    return NPU_OK;
}

static int set_create_vdev_virgroupid_param(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;
    unsigned int virgroup_id;

    ret = check_vdev_virgroupid_param(tmp_value, &virgroup_id);
    if (ret != NPU_OK) {
        return ret;
    }

    operate_info->vfg_id = virgroup_id;

    return NPU_OK;
}

int parse_virgroup_id_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;

    if (check_para_g_is_support(operate_info->type) != 1 || npu_get_chip_type() != NPU_CHIP_310P) {
        gplog(LOG_ERR, "not support %s with virgroup id.", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (cur + 1 >= argc) {
        gplog(LOG_ERR, "%s is nothing behind -g.", operate_info->stype);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = set_create_vdev_virgroupid_param(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return ret;
}

int parse_sdata_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = set_sdata(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    operate_info->is_sdata = TRUE;
    return ret;
}

int parse_upgrade_type_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = set_type(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
    }
    operate_info->is_upgrade = TRUE;
    return ret;
}

int parse_mcu_file_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = set_path(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
    }

    return ret;
}

int parse_upgrade_query_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = set_type(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
    }
    operate_info->is_query = TRUE;
    return ret;
}

int parse_upgrade_version_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = set_type(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
    }
    operate_info->is_version = TRUE;
    return ret;
}

int parse_upgrade_active_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = set_type(operate_info, argv[cur + 1]);
    if (ret != NPU_OK) {
    }
    operate_info->is_active = TRUE;
    return ret;
}

int parse_profiling_time_param(struct npu_smi_operate_info *operate_info, int cur, int argc, const char **argv)
{
    int ret;
    if (cur + 1 >= argc) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = str2int(&operate_info->profiling_time, argv[cur + 1]);
    if (operate_info->profiling_time <= 0 || operate_info->profiling_time > MAX_HCCS_PROFILING_TIME) {
        printf("Invalid time.\n");
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}