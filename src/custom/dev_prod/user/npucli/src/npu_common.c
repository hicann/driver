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
#ifndef _WIN32
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#else
#include <io.h>
#include <process.h>
#endif
#include <sys/types.h>
#include <ctype.h>
#include <limits.h>
#include <regex.h>
#include "securec.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_log.h"
#include "dcmi_inner_cfg_manage.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_product_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_environment_judge.h"
#include "dcmi_basic_info_intf.h"
#include "npu_cmd_parse.h"
#include "npu_parameter_parse.h"
#include "npu_run_env.h"
#include "npu_card_info.h"
#include "npu_common.h"

#define     HCCS_900_ARR_LANEID_MIN          1
#define     HCCS_900_ARR_LANEID_MAX          7
#define     HCCS_9000_ARR_LANEID_MIN         2
#define     HCCS_9000_ARR_LANEID_MAX         7
#define     HCCS_310P_ARR_LANEID             0

enum npu_chip_type g_chip_type = NPU_CHIP_INVALID;
int g_board_type_is_card = FALSE;
int g_board_type_is_server = FALSE;
enum npu_board_type g_board_type = NPU_BOARD_TYPE_INVALID;

#define MINID_CONF_INI  "/home/data/ies/minid.ini"

int npu_ascii_to_num(char ch)
{
    return (ch - '0');
}

int npu_hex_ascii_to_num(char ch)
{
    return (ch - 'A' + NPU_DEC_TO_STR_BASE);
}

#ifdef _WIN32
int root_user_check()
{
    BOOL is_elevated = FALSE;
    HANDLE ptoken = NULL;
    TOKEN_ELEVATION token_buf;
    size_t bus_size = sizeof(TOKEN_ELEVATION);

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &ptoken)) {
        if (GetTokenInformation(ptoken, TokenElevation, &token_buf, sizeof(token_buf), &bus_size)) {
            is_elevated = token_buf.TokenIsElevated;
        } else {
            gplog(LOG_ERR, "call GetTokenInformation failed. err=%d", GetLastError());
        }
    } else {
        gplog(LOG_ERR, "call OpenProcessToken failed. err=%d", GetLastError());
    }

    if (is_elevated == FALSE) {
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    return NPU_OK;
}
#endif

int str2int(int *ptmp_num, const char *str)
{
    int num;
    char *end_ptr = NULL;
    size_t i;
    const char *tmp_str = str;

    for (i = 0; i < strlen(tmp_str); i++) {
        if (!isdigit(tmp_str[i])) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    num = strtol(tmp_str, &end_ptr, NPU_DEC_TO_STR_BASE);
    /* 转换后num为0，但实际传入tmp_str不为'0...0'时，说明传入参数有误 */
    if (num == 0) {
        do {
            if (*tmp_str != '0') {
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
        } while (*++tmp_str != '\0');
    }

    *ptmp_num = num;
    return NPU_OK;
}

int str2ul(unsigned long int *ptmp_num, const char *str)
{
    unsigned long int num;
    char *end_ptr = NULL;
    size_t i;
    const char *tmp_str = str;

    for (i = 0; i < strlen(tmp_str); i++) {
        if (!isdigit(tmp_str[i])) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    num = strtoul(tmp_str, &end_ptr, NPU_DEC_TO_STR_BASE);
    /* 转换后num为0，但实际传入tmp_str不为'0...0'时，说明传入参数有误 */
    if (num == 0) {
        do {
            if (*tmp_str != '0') {
                return NPU_ERR_CODE_INVALID_PARAMETER;
            }
        } while (*++tmp_str != '\0');
    }

    *ptmp_num = num;
    return NPU_OK;
}

STATIC void get_product_bit_index_for_310B(unsigned int *bit)
{
    if (dcmi_get_product_type_inner() == DCMI_A200_A2_MODEL) {
        *bit = CMD_SPT_310B_SOC_DK_INDEX;
    } else {
        *bit = CMD_SPT_310B_SOC_STATION_INDEX;
    }
}

unsigned int determine_hardware_support_linux(enum npu_chip_type chip_type)
{
    unsigned int bit = g_board_type;

    if (npu_board_type_is_card()) {
        if (chip_type == NPU_CHIP_910) {
            bit = CMD_SPT_910_INDEX;
        } else if (chip_type == NPU_CHIP_310P) {
            bit = CMD_SPT_310P_INDEX;
        } else if (chip_type == NPU_CHIP_910B) {
            bit = CMD_SPT_910B_CARD_INDEX;
        } else if (chip_type == NPU_CHIP_910_93) {
            bit = CMD_SPT_910_93_CARD_INDEX;
        } else if (chip_type == NPU_CHIP_950) {
            bit = CMD_SPT_950_CARD_INDEX;
        }
    }

    if (npu_board_type_is_server()) {
        if (chip_type == NPU_CHIP_910B) {
            bit = CMD_SPT_910B_SERVER_INDEX;
        } else if (chip_type == NPU_CHIP_910_93) {
            bit = CMD_SPT_910_93_SERVER_INDEX;
        } else if (chip_type == NPU_CHIP_950) {
            bit = CMD_SPT_950_SERVER_INDEX;
        }
    }

    /* soc形态时匹配支持的硬件形态 */
    if (npu_board_type_is_soc()) {
        if (chip_type == NPU_CHIP_310P) {
            /* 310P soc形态支持时配置值是0x100（bit8为1），判断是否支持此形态需要左移8bit匹配对应bit位是否为1 */
            bit = CMD_SPT_310P_SOC_INDEX;
        } else if (chip_type == NPU_CHIP_310B) {
            get_product_bit_index_for_310B(&bit);
        } else if (chip_type == NPU_CHIP_950) {
            bit = CMD_SPT_950_SOC_INDEX;
        }
    }
    return bit;
}

int determine_hardware_support(struct npu_smi_type_map *type_map)
{
    unsigned int bit;
    enum npu_chip_type chip_type = npu_get_chip_type();

#ifdef _WIN32
    if (type_map->win_support_list == 0) {
        return FALSE;
    }
    // windows仅支持200EP和300-3010场景
    bit = npu_board_type_is_model() ? CMD_SPT_MODEL_INDEX : CMD_SPT_310_INDEX;
 
    return ((type_map->win_support_list & (1 << bit)) != 0);
#else
    if (type_map->linux_support_list == CMD_SPT_ALL) {
        return TRUE;
    }
    bit = determine_hardware_support_linux(chip_type);
    return ((type_map->linux_support_list & (1 << bit)) != 0);
#endif
}

int determine_run_env_support(struct npu_smi_type_map *type_map)
{
    if ((type_map->support_env & CMD_ENV_SPT_NON_ROOT) == 0) {
        if (user_egid_check() != NPU_OK) {
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
    }

    // 尽量跟以前的回显保持一致
    if (((type_map->support_env & CMD_ENV_SPT_DOCKER) == 0) &&
        ((type_map->support_env & CMD_ENV_SPT_VM) == 0)) {
        if (npu_is_run_in_vm_or_docker()) {
            printf("This command cannot be executed on a VM or container.\n");
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
    }

    if ((type_map->support_env & CMD_ENV_SPT_DOCKER) == 0) {
        if (npu_is_in_docker()) {
            printf("This command cannot be executed on a container.\n");
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
    }

    if ((type_map->support_env & CMD_ENV_SPT_VM) == 0) {
        if (npu_is_in_virtual_machine()) {
            printf("This command cannot be executed on a VM.\n");
            return NPU_ERR_CODE_OPER_NOT_PERMITTED;
        }
    }

    return NPU_OK;
}

int set_id(struct npu_smi_operate_info *operate_info, const char *tmp_id)
{
    int ret;

    ret = str2int(&operate_info->id, tmp_id);
    if (operate_info->id < 0) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int set_chip_id(struct npu_smi_operate_info *operate_info, const char *tmp_id)
{
    int ret;

    ret = str2int(&operate_info->chip_id, tmp_id);
    if (operate_info->chip_id < 0) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int set_lane_id(struct npu_smi_operate_info *operate_info, const char *tmp_id)
{
    int ret;
    int card_id = operate_info->id;
    int tmp_lane_id = (int)strtol(tmp_id, NULL, NPU_DEC_TO_STR_BASE);
    unsigned int main_board_id;
    if (npu_get_chip_type() == NPU_CHIP_310P) {
        if (tmp_lane_id != HCCS_310P_ARR_LANEID) {
            gplog(LOG_ERR, "Hccs 310P lane id not within the correct range,err id is:%d", tmp_lane_id);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
        goto OPTION;
    }
    ret = dcmi_get_mainboard_id(card_id, 0, &main_board_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to query main board id of card. err is %d", ret);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    // 天工环境 2-7； 非天工环境 1-7  判断lane输入是否合法
    if ((main_board_id == Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID1) ||
    (main_board_id == Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID2)) {
        if ((tmp_lane_id < HCCS_9000_ARR_LANEID_MIN) || (tmp_lane_id > HCCS_9000_ARR_LANEID_MAX)) {
            gplog(LOG_ERR, "Hccs 9000 lane id not within the correct range,err id is:%d", tmp_lane_id);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    } else {
        if ((tmp_lane_id < HCCS_900_ARR_LANEID_MIN) || (tmp_lane_id > HCCS_900_ARR_LANEID_MAX)) {
            gplog(LOG_ERR, "Hccs 900 lane id not within the correct range,err id is:%d", tmp_lane_id);
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }
OPTION:
    operate_info->lane_id = tmp_lane_id;
    return ret;
}

int set_phy_id(struct npu_smi_operate_info *operate_info, const char *tmp_id)
{
    int ret;
    char dev_name[64] = {0};
#ifdef NPU_SMI_V2
    unsigned int dev_id;
#endif
 
    ret = str2ul(&operate_info->phy_id, tmp_id);
#ifdef NPU_SMI_V2
    if (ret != NPU_OK) {
        return ret;
    }
 
    ret = dcmiv2_get_dev_id_by_chip_phy_id((int)operate_info->phy_id, &dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_dev_id_by_chip_phy_id failed.(ret=%d)", ret);
        return dcmi_to_npu_error_code(ret);
    }
#endif
    if (ret == NPU_OK) {
#ifdef NPU_SMI_V2
        ret = sprintf_s(dev_name, sizeof(dev_name), "/dev/davinci%u", dev_id);
#else
        ret = sprintf_s(dev_name, sizeof(dev_name), "/dev/davinci%lu", operate_info->phy_id);
#endif
        if (ret < 0) {
            ret = NPU_ERR_CODE_INVALID_PARAMETER;
        } else {
            ret = ((access(dev_name, F_OK) != 0) ? NPU_ERR_CODE_INVALID_PARAMETER : NPU_OK);
        }
    }

    return ret;
}

int set_watch_delay(struct npu_smi_operate_info *operate_info, const char *tmp_sec)
{
    int ret;
    ret = str2int(&operate_info->watch_delay, tmp_sec);
    if ((operate_info->watch_delay < NPU_WATCH_DELAY_MIN_VALUE) ||
        (operate_info->watch_delay > NPU_WATCH_DELAY_MAX_VALUE)) {
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return ret;
}

int set_sdata(struct npu_smi_operate_info *operate_info, const char *tmp_str)
{
    int ret;
    size_t len = strlen(tmp_str) + 1;
    ret = memcpy_s(operate_info->sdata, sizeof(operate_info->sdata), tmp_str, len);
    if (ret != EOK) {
        gplog(LOG_ERR, "call memcpy_s failed.%d.\n", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    return NPU_OK;
}

int is_specific_char(const char temp_char)
{
    int ret = FALSE;
    switch (temp_char) {
        case '_':
        case '.':
        case '/':
        case '-':
#ifdef _WIN32
        case '\\':
        case ':':
#endif
            ret = TRUE;
            break;
        default:
            break;
    }
    return ret;
}

int check_file_path(const char *tmp_path)
{
    size_t len = strlen(tmp_path);
    size_t i;

    for (i = 0; i < len; i++) {
        if (!isalnum(tmp_path[i])) {
            if (!is_specific_char(tmp_path[i])) {
                return NPU_ERR_CODE_BASE;
            }
        }
    }
    return NPU_OK;
}

int check_filename(const char *file, char *path, int len)
{
#ifndef _WIN32
    if (len < PATH_MAX) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((file == NULL) || (strlen(file) > PATH_MAX) || (realpath(file, path) == NULL)) {
#else
    if (len < MAX_PATH) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if ((file == NULL) || (strlen(file) > MAX_PATH) || (PathCanonicalizeA(path, file) == FALSE)) {
#endif
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

int covert_file_path(const char *file, char *path, int len)
{
#ifndef _WIN32
    if (len < PATH_MAX) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((file == NULL) || (strlen(file) > PATH_MAX) ||
        ((realpath(file, path) == NULL) && (errno != ENOENT))) {
#else
    if (len < MAX_PATH) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    if ((file == NULL) || (strlen(file) > MAX_PATH) ||
        ((PathCanonicalizeA(path, file) == FALSE) && (errno != ENOENT))) {
#endif
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

int set_path(struct npu_smi_operate_info *operate_info, const char *tmp_path)
{
    size_t len = strlen(tmp_path) + 1;
    int ret;
    if (len > MAX_LENTH) {
        printf("\t%-30s : File path is too long. Length should not be greater than %d.\n", "Message", MAX_LENTH);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = check_file_path(tmp_path);
    if (ret != NPU_OK) {
        printf("\t%-30s : The file path contains special characters.\n", "Message");
#ifdef _WIN32
        printf("\t%-30s : Letters, Digits, Underscores, Dots, Colon, Slash and Hyphens.\n", "Available characters");
#else
        printf("\t%-30s : Letters, Digits, Underscores, Dots, Slash and Hyphens.\n", "Available characters");
#endif
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    operate_info->file_path = (char *)malloc(MAX_LENTH);
    if (operate_info->file_path == NULL) {
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memcpy_s(operate_info->file_path, MAX_LENTH, tmp_path, len);
    if (ret != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is %d.\n", ret);
    }

    return NPU_OK;
}

STATIC int check_nve_level_value(int enable_value)
{
    int chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_310) {
        if (enable_value >= NVE_LOW && enable_value <= NVE_FULL) {
            return NPU_OK;
        }
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (chip_type != NPU_CHIP_310B) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    int tops_type = dcmi_get_310b_tops_type();
    if (tops_type == IS_310B_20TOPS_TYPE) {
        if (enable_value >= (int)WORK_TOPS_20T_1600MHz && enable_value <= (int)WORK_TOPS_8T_1600MHz) {
            return NPU_OK;
        }
    } else if (tops_type == IS_310B_8TOPS_TYPE) {
        if (enable_value >= (int)WORK_TOPS_20T_1600MHz && enable_value <= (int)WORK_TOPS_8T_1000MHz) {
            return NPU_OK;
        }
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int check_power_state_value(int enable_value)
{
    if (enable_value >= MIN_SLEEP_TIME && enable_value <= MAX_SLEEP_TIME) {
        return NPU_OK;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int check_mac_addr_value(int enable_value)
{
    if (enable_value >= 0 && enable_value < MAC_ADDR_MAX_COUNT) {
        return NPU_OK;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int check_boot_sel_value(int enable_value)
{
    if (enable_value >= SSD && enable_value < BOOT_SEL_MODE_MAX) {
        return NPU_OK;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int check_secverify_mode_value(int enable_value)
{
    if (enable_value >= 0 && enable_value < SEC_VERIFY_MODE_MAX) {
        return NPU_OK;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int check_aicpu_conf_value(int enable_value)
{
    if (enable_value == CPU_CNT_2 || enable_value == CPU_CNT_4 || enable_value == CPU_CNT_6) {
        return NPU_OK;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int check_pwm_duty_ratio_value(int enable_value)
{
    if (enable_value >= (int)PWM_MIN_RATIO && enable_value <= (int)PWM_MAX_RATIO) {
        return NPU_OK;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

STATIC int check_op_timeout_value(int enable_value)
{
    if (enable_value >= (int)MIN_TIMEOUT_EXPONENT && enable_value <= (int)MAX_TIMEOUT_EXPONENT) {
        return NPU_OK;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int check_enable_value(int oper_type, int enable_value)
{
    switch (oper_type) {
        case NVE_LEVEL:
            return check_nve_level_value(enable_value);
        case AICPU_CONF:
            return check_aicpu_conf_value(enable_value);
        case PWM_DUTY_RATIO:
            return check_pwm_duty_ratio_value(enable_value);
        case POWER_STATE:
            return check_power_state_value(enable_value);
        case MAC_ADDR:
            return check_mac_addr_value(enable_value);
        case BOOT_SEL:
            return check_boot_sel_value(enable_value);
        case CUSTOM_OP_SECVERIFY_MODE:
            return check_secverify_mode_value(enable_value);
        case OP_TIMEOUT:
            return check_op_timeout_value(enable_value);
        default:
            if (enable_value == 0 || enable_value == 1) {
                return NPU_OK;
            }
            break;
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_enable_value(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;
    int cmp_len = 1;

    if (strncmp(operate_info->stype, "pwm-duty-ratio", sizeof("pwm-duty-ratio")) == 0) {
        cmp_len = 3; // 占空比最大值为100,长度为3
    }

    if (strncmp(operate_info->stype, "power-state", sizeof("power-state")) == 0) {
        cmp_len = 10; // 占空比最大值为1000000000,长度为10
    }

    if (strncmp(operate_info->stype, "op-timeout-cfg", sizeof("op-timeout-cfg")) == 0) {
        cmp_len = 2; // 占空比最大值为63,长度为2
    }

    if (strlen(tmp_value) > (unsigned int)cmp_len) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = str2int(&operate_info->enable_value, tmp_value);
    if (ret == NPU_OK) {
        return check_enable_value(operate_info->type, operate_info->enable_value);
    }
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_chan_src(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;
    if (strlen(tmp_value) != strlen("1")) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    ret = str2int(&operate_info->chan_src, tmp_value);
    if ((ret == NPU_OK) && (operate_info->chan_src == INBAND_CHANNEL)) {
        return NPU_OK;
    }

    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_vdev_svm_param(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;

    ret = str2ul(&operate_info->vnpu_svm, tmp_value);
    if (ret != NPU_OK) {
        return NPU_ERR_CODE_INNER_ERR;
    }

    /* 0xff用于检查-v参数是否传入 */
    operate_info->vnpu_conf[NPU_V_PARAM_FLAG_INDEX] = 0xff;

    return NPU_OK;
}

int set_vdev_id_param(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;

    ret = str2ul(&operate_info->vnpu_id, tmp_value);
    if (ret != NPU_OK) {
        return NPU_ERR_CODE_INNER_ERR;
    }
    return NPU_OK;
}

int check_vdev_template_param(const char *template_name)
{
    int ret;
    int index;
    int supported_template_size;
    const char **supported_template;

    switch (dcmi_get_board_chip_type()) {
        case DCMI_CHIP_TYPE_D310P:
            supported_template = template_name_310p;
            supported_template_size = DCMI_310P_TEMPLATE_NUM;
            break;
        case DCMI_CHIP_TYPE_D910:
            supported_template = template_name_910;
            supported_template_size = DCMI_910_TEMPLATE_NUM;
            break;
        case DCMI_CHIP_TYPE_D910B:
            ret = dcmi_check_910b_template_name(template_name);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "dcmi_check_910b_template_name failed, ret is %d", ret);
            }
            return dcmi_to_npu_error_code(ret);
        default:
            return NPU_ERR_CODE_NOT_SUPPORT;
    }
    for (index = 0; index < supported_template_size; index++) {
        if (strcmp(template_name, supported_template[index]) == 0) {
            break;
        }
    }
    if (index == supported_template_size) {
        gplog(LOG_ERR, "template_name doesn't match any in template.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

int set_create_vdev_param(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;

    ret = check_vdev_template_param(tmp_value);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = strncpy_s(operate_info->vnpu_conf, sizeof(operate_info->vnpu_conf), tmp_value, strlen(tmp_value));
    if (ret != EOK) {
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    return NPU_OK;
}

int check_vdev_exist(struct npu_smi_operate_info *operate_info, int vdev_id)
{
    int ret;
    struct dcmi_soc_total_resource soc_total_resource = { 0 };
    unsigned int resource_len = sizeof(soc_total_resource);
    unsigned int i;

    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_VDEV_MNG,
        DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE, &soc_total_resource, &resource_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get total resource failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    /* 检查vdev是否存在 */
    gplog(LOG_INFO, "vdev_num=%u", soc_total_resource.vdev_num);
    for (i = 0; i < soc_total_resource.vdev_num; i++) {
        gplog(LOG_INFO, "soc_total_resource.vdev_id=%u vdev_id=%d", soc_total_resource.vdev_id[i], vdev_id);
        if (soc_total_resource.vdev_id[i] == (unsigned int)vdev_id) {
            return NPU_OK;
        }
    }

    gplog(LOG_ERR, "vdev_id[%d] is not found!", vdev_id);
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_destroy_vdev_param(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;
    int vdev_id;

    ret = str2int(&vdev_id, tmp_value);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = strncpy_s(operate_info->vnpu_conf, sizeof(operate_info->vnpu_conf), tmp_value, strlen(tmp_value));
    if (ret != EOK) {
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    return NPU_OK;
}

int multi_param_check(const char *param_string, int param_size)
{
#define SPLIT_INIT 0
#define SPLIT_PROC 1
#define SPLIT_SET  2
    int i;
    int flag = SPLIT_INIT;
    bool check_result = false;

    if (param_size <= 0) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    for (i = 0; i < param_size; i++) {
        /* 校验-v参数必须是强匹配 */
        check_result = (!isdigit(param_string[i]) && (param_string[i] != ':'));
        if (check_result) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }

        check_result =
            (((param_string[i] == ':') && (flag == SPLIT_INIT)) || ((param_string[i] == ':') && (flag == SPLIT_SET)));
        if (check_result) {
            return NPU_ERR_CODE_INVALID_PARAMETER;
        } else if (param_string[i] == ':' && flag == SPLIT_PROC) {
            flag = SPLIT_SET;
        } else if (param_string[i] != ':') {
            flag = SPLIT_PROC;
        }
    }

    if (param_string[param_size - 1] == ':') {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return NPU_OK;
}

int set_cpu_num_param(struct npu_smi_operate_info *operate_info, const char *tmp_value)
{
    int ret;
    int cpu_param = 0;
    int index = 0;
    char seps[] = ":";
    char *next_token = NULL;
    char *token = NULL;
    char cmd_str[MAX_LENTH] = {0};

    ret = strcpy_s(cmd_str, MAX_LENTH, tmp_value);
    if (ret != EOK) {
        gplog(LOG_ERR, "strcpy_s failed.ret:%d", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    if (multi_param_check(cmd_str, (int)strlen(cmd_str)) != NPU_OK) {
        gplog(LOG_ERR, "multi_param_check failed.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    token = strtok_s(cmd_str, seps, &next_token);
    while (token != NULL) {
        ret = str2int(&cpu_param, token);
        if (ret != NPU_OK) {
            return NPU_ERR_CODE_INNER_ERR;
        }

        operate_info->vnpu_conf[index++] = (char)cpu_param;
        token = strtok_s(NULL, seps, &next_token);
    }

    /* 0xff用于检查-v参数是否传入 */
    operate_info->vnpu_conf[NPU_V_PARAM_FLAG_INDEX] = 0xff;

    return NPU_OK;
}

int npu_check_card_id(int card_id)
{
    int num_id, ret;
    int card_id_list[MAX_CARD_NUM] = {0};
    int card_num = 0;

#ifndef NPU_SMI_V2
    ret = dcmi_get_card_list(&card_num, card_id_list, MAX_CARD_NUM);
#else
    ret = dcmiv2_get_device_list(card_id_list, &card_num, MAX_CARD_NUM);
#endif
    if (ret != DCMI_OK) {
        printf("Failed to get card number.\n");
        return ret;
    }

    for (num_id = 0; num_id < card_num; num_id++) {
        if (card_id == card_id_list[num_id]) {
            return NPU_OK;
        }
    }

    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int npu_check_chip_id(int card_id, int device_id)
{
    enum dcmi_unit_type chip_type = INVALID_TYPE;

#ifndef NPU_SMI_V2
    int ret = dcmi_get_device_type(card_id, device_id, &chip_type);
#else
    int ret = dcmiv2_get_device_type(card_id, &chip_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (chip_type == INVALID_TYPE) {
        printf("invalid chip type\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return NPU_OK;
}

int npu_check_npu_chip_id(int card_id, int device_id)
{
    enum dcmi_unit_type chip_type = INVALID_TYPE;

#ifndef NPU_SMI_V2
    int ret = dcmi_get_device_type(card_id, device_id, &chip_type);
#else
    int ret = dcmiv2_get_device_type(card_id, &chip_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (chip_type != NPU_TYPE) {
        gplog(LOG_ERR, "Only support the chip id of NPU_TYPE.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return NPU_OK;
}

// root权限检查
int user_egid_check()
{
#ifndef _WIN32
    if (geteuid() != 0) {
        printf("This command can be executed only by the root user.\n");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }
    return NPU_OK;
#else
    int ret = root_user_check();
    if (ret != NPU_OK) {
        printf("This command can be executed only by an administrator.\n");
    }
    return ret;
#endif
}

void npu_init_soc_chip_type(int device_id)
{
    unsigned int board_id;
    if (dcmi_scene_is_950_uboe(device_id)) {
        g_chip_type = NPU_CHIP_950;
        return;
    }

    board_id = (unsigned int)dcmi_get_board_id_inner();
    dcmi_310B_trans_baseboard_id(&board_id);

    switch (board_id) {
        case NPU_310P_1P_SOC_BOARD_ID:
        case NPU_310P_1P_SOC_AG_BOARD_ID:
        case NPU_310P_2P_SOC_BOARD_ID:
        case NPU_310P_CDLS_BOARD_ID:
            g_chip_type = NPU_CHIP_310P;
            break;
        case NPU_A500_A2_BOARD_ID:
        case NPU_A200_A2_MODEL_BOARD_ID:
        case NPU_A200_A2_DK_BOARD_ID:
            g_chip_type = NPU_CHIP_310B;
            break;
        default:
            g_chip_type = NPU_CHIP_310;
            break;
    }
}

int npu_init_ep_chip_type(unsigned int venderid, unsigned int deviceid)
{
    int ret;

    if (venderid == NPU_CHIP_VENDER_ID) {
        ret = NPU_OK;
        switch (deviceid) {
            case NPU_310_DEVICE_ID:
                g_chip_type = NPU_CHIP_310;
                break;
            case NPU_310P_DEVICE_ID:
                g_chip_type = NPU_CHIP_310P;
                break;
            case NPU_910_DEVICE_ID:
                g_chip_type = NPU_CHIP_910;
                break;
            case NPU_910B_DEVICE_ID:
                g_chip_type = NPU_CHIP_910B;
                break;
            case NPU_310B_DEVICE_ID:
                g_chip_type = NPU_CHIP_310B;
                break;
            case NPU_910_93_DEVICE_ID:
                g_chip_type = NPU_CHIP_910_93;
                break;
            case NPU_950_DEVICE_ID:    // pcie场景
                g_chip_type = NPU_CHIP_950;
                break;
            default:
                g_chip_type = NPU_CHIP_INVALID;
                ret = NPU_ERR_CODE_INNER_ERR;
                break;
        }
    } else {
        ret = NPU_ERR_CODE_INNER_ERR;
    }
 
    return ret;
}

int npu_init_chip_type(int card_id, int device_id)
{
    int ret;
    unsigned int mode = 0;
    struct dcmi_pcie_info_all pcie_info = { 0 };
    struct dcmi_board_info board_info = { 0 };

    if (dcmi_mainboard_is_a900_a5_ub(g_mainboard_info.mainboard_id)) {
        g_chip_type = NPU_CHIP_950;
        return NPU_OK;
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_pcie_info(card_id, &pcie_info);
#else
    ret = dcmi_get_device_pcie_info_v2(card_id, device_id, &pcie_info);
#endif
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        if (dcmi_get_rc_ep_mode(&mode) == NPU_OK && mode == DCMI_PCIE_RC_MODE) {
            npu_init_soc_chip_type(device_id);
            g_board_type = NPU_BOARD_TYPE_SOC;
            return NPU_OK;
        }
        gplog(LOG_ERR, "dcmi_get_card_board_info, board_id %d.", board_info.board_id);
        return NPU_ERR_CODE_INNER_ERR;
    } else if (ret != DCMI_OK) {
#ifdef NPU_SMI_V2
        gplog(LOG_ERR, "dcmiv2_get_device_pcie_info failed. err is %d.", ret);
#else
        gplog(LOG_ERR, "dcmi_get_device_pcie_info_v2 failed. err is %d.", ret);
#endif
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = npu_init_ep_chip_type(pcie_info.venderid, pcie_info.deviceid);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_init_ep_chip_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    return ret;
}

int npu_get_chip_type()
{
    return g_chip_type;
}

int npu_get_board_type_by_config(void)
{
    char info_line[NPU_CFG_LINE_MAX_LEN] = {0};
    char *tmp_str = NULL;
    size_t read_count;
    FILE *fp = NULL;

    fp = fopen(BOARD_CONFIG_FILE, "r");
    if (fp == NULL) {
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    if (fseek(fp, 0, SEEK_SET) != 0) {
        gplog(LOG_ERR, "call fseek failed.");
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    read_count = fread(info_line, 1, sizeof(info_line) - 1, fp);
    if (read_count <= 0) {
        gplog(LOG_ERR, "call fread failed.read_count=%zu", read_count);
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    info_line[NPU_CFG_LINE_MAX_LEN - 1] = '\0';
    tmp_str = strstr(info_line, BOARD_TYPE_KEY);
    if (tmp_str == NULL) {
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    // key要全字匹配
    if (info_line != tmp_str && *(tmp_str - 1) != '\n') {
        (void)fclose(fp);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    // 500 A2在rc流程设置单板信息
    if (strncmp(tmp_str + strlen(BOARD_TYPE_KEY), "A500_A2", strlen("A500_A2")) == 0) {
        (void)fclose(fp);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (strncmp(tmp_str + strlen(BOARD_TYPE_KEY), BOARD_TYPE_HILENS, strlen(BOARD_TYPE_HILENS)) == 0) {
        g_board_type = NPU_BOARD_TYPE_HILENS;
    } else {
        g_board_type = NPU_BOARD_TYPE_STATION;
    }
    g_chip_type = NPU_CHIP_310;
    (void)fclose(fp);
    return DCMI_OK;
}

static void npu_init_board_type_for_310(int board_id)
{
    switch (board_id) {
        case NPU_310_CARD_B_BOARD_ID:
        case NPU_310_CARD_C_BOARD_ID:
        case NPU_310_CARD_D_BOARD_ID:
        case NPU_310_CARD_DMPA_BOARD_ID:
        case NPU_310_CARD_DMPB_BOARD_ID:
        case NPU_310_CARD_DMPC_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_CARD;
            break;
        case NPU_310_MODEL_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_MODEL;
            break;
        default:
            break;
    }
    return;
}

static void npu_init_board_type_for_310p(int board_id)
{
    switch (board_id) {
        case NPU_310P_CARD_BOARD_ID:
        case NPU_310P_CARD_BOARD_ID_V2:
        case NPU_310P_CARD_BOARD_ID_V3:
        case NPU_310P_CARD_2P_BOARD_ID:
        case NPU_310P_CARD_2P_HP_BOARD_ID:
        case NPU_310P_CARD_BOARD_ID_XP:
            g_board_type = NPU_BOARD_TYPE_CARD;
            break;
        default:
            break;
    }
    return;
}

static void npu_init_board_type_for_910(int board_id)
{
    switch (board_id) {
        case NPU_910_CARD_256T_A_BOARD_ID:
        case NPU_910_CARD_256T_B_BOARD_ID:
        case NPU_910_CARD_280T_B_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_CARD;
            break;
        case NPU_910_BOARD_256T_A_BOARD_ID:
        case NPU_910_BOARD_256T_B_BOARD_ID:
        case NPU_910_BOARD_280T_A_BOARD_ID:
        case NPU_910_BOARD_280T_B_BOARD_ID:
        case NPU_910_BOARD_320T_A_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_SERVER;
            break;
        default:
            g_board_type = NPU_BOARD_TYPE_INVALID;
            break;
    }
    return;
}

static void npu_init_board_type_for_310b(unsigned int board_id)
{
    dcmi_310B_trans_baseboard_id(&board_id);
    switch (board_id) {
        case NPU_A500_A2_BOARD_ID:
        case NPU_A200_A2_MODEL_BOARD_ID:
        case NPU_A200_A2_DK_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_SOC;
            break;
        default:
            g_board_type = NPU_BOARD_TYPE_INVALID;
            break;
    }
}

STATIC void npu_init_board_type_for_910b(int board_id)
{
    switch (board_id) {
        case NPU_A900T_POD_A1_BIN3_BOARD_ID:
        case NPU_A900T_POD_A1_BIN3_P3_BOARD_ID:
        case NPU_A900T_POD_A1_BIN0_BOARD_ID:
        case NPU_A900T_POD_A1_BIN0_P3_BOARD_ID:
        case NPU_A900T_POD_A1_BIN1_BOARD_ID:
        case NPU_A900T_POD_A1_BIN1_P3_BOARD_ID:
        case NPU_A900T_POD_A1_BIN2_BOARD_ID:
        case NPU_A900T_POD_A1_BIN2_P3_BOARD_ID:
        case NPU_A900T_POD_A1_BIN2X_BOARD_ID:
        case NPU_A900T_POD_A1_BIN2X_P3_BOARD_ID:
        case NPU_A900T_POD_A1_BIN2X_1_BOARD_ID:
        case NPU_A800I_POD_A2_BIN4_1_PCIE_BOARD_ID:
        case NPU_A900T_POD_A1_BIN2X_1_P3_BOARD_ID:
        case NPU_A200T_BOX_A1_BIN3_BOARD_ID:
        case NPU_A200T_BOX_A1_BIN0_BOARD_ID:
        case NPU_A200T_BOX_A1_BIN2_BOARD_ID:
        case NPU_A200T_BOX_A1_BIN1_BOARD_ID:
        case NPU_A200I_BOX_A1_BIN2X_1_BOARD_ID:
        case NPU_A800I_POD_A2_BIN2_BOARD_ID:
        case NPU_A800I_POD_A2_BIN2_1_BOARD_ID:
        case NPU_A800T_POD_A2_BIN1_BOARD_ID:
        case NPU_A800T_POD_A2_BIN0_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_SERVER;
            break;
        case NPU_A300T_A1_BIN1_350W_BOARD_ID:
        case NPU_A300T_A1_BIN2_BOARD_ID:
        case NPU_A300T_A1_BIN1_300W_BOARD_ID:
        case NPU_A300T_A1_BIN0_BOARD_ID:
        case NPU_A300I_A2_BIN2_BOARD_ID:
        case NPU_A300I_A2_BIN2_64G_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_CARD;
            break;
        default:
            g_board_type = NPU_BOARD_TYPE_INVALID;
            break;
    }
}

STATIC void npu_init_board_type_for_910_93(int board_id)
{
    switch (board_id) {
        case NPU_A900_A3_SuperPoD_BIN1_BOARD_ID:
        case NPU_A900_A3_SuperPoD_BIN2_BOARD_ID:
        case NPU_A900_A3_SuperPoD_BIN3_BOARD_ID:
        case NPU_A3_560T_BIN1_BOARD_ID:
        case NPU_A3_ZQ_752T_BOARD_ID:
        case NPU_A3_ZQ_560T_BOARD_ID:
            g_board_type = NPU_BOARD_TYPE_SERVER;
            break;
        default:
            g_board_type = NPU_BOARD_TYPE_INVALID;
            break;
    }
}

// A5采用mainboard_id区分g_board_type
STATIC void npu_init_board_type_by_mainboard_id()
{
    unsigned int mode = 0;
    int ret = 0;
    g_board_type = NPU_BOARD_TYPE_INVALID;

    if (((g_mainboard_info.mainboard_id >> DCMI_SHIFT_FIVE_BITS) & A5_MAINBOARD_ID_MASK) ==
        MAINBOARD_ID_HIGH_3BIT_CARD) {
        if (g_mainboard_info.mainboard_id == DCMI_950_EQUIP_CARD_UBOE_MAIN_BOARD_ID) {
            g_board_type = NPU_BOARD_TYPE_SOC;
        } else {
            g_board_type = NPU_BOARD_TYPE_CARD;
        }
    } else if (((g_mainboard_info.mainboard_id >> DCMI_SHIFT_FIVE_BITS) & A5_MAINBOARD_ID_MASK) ==
        MAINBOARD_ID_HIGH_3BIT_POD ||
        ((g_mainboard_info.mainboard_id >> DCMI_SHIFT_FIVE_BITS) & A5_MAINBOARD_ID_MASK) ==
        MAINBOARD_ID_HIGH_3BIT_A_K ||
        ((g_mainboard_info.mainboard_id >> DCMI_SHIFT_FIVE_BITS) & A5_MAINBOARD_ID_MASK) ==
        MAINBOARD_ID_HIGH_3BIT_A_X) {
        g_board_type = NPU_BOARD_TYPE_SERVER;
    } else if (((g_mainboard_info.mainboard_id >> DCMI_SHIFT_FIVE_BITS) & A5_MAINBOARD_ID_MASK) ==
        MAINBOARD_ID_HIGH_3BIT_EQU) {
        ret = dcmi_get_rc_ep_mode(&mode);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_ep_rc_mode failed. ret is %d", ret);
            return;
        }
        if (mode == DCMI_PCIE_RC_MODE) {
            g_board_type = NPU_BOARD_TYPE_SOC;
        } else {
            g_board_type = NPU_BOARD_TYPE_SERVER;   // a+x装备
        }
    } else {
        g_board_type = NPU_BOARD_TYPE_INVALID;
    }
}

STATIC void npu_init_board_type_by_board_id(unsigned int board_id)
{
    if (npu_get_chip_type() == NPU_CHIP_310) {
        npu_init_board_type_for_310(board_id);
    } else if (npu_get_chip_type() == NPU_CHIP_310P) {
        npu_init_board_type_for_310p(board_id);
    } else if (npu_get_chip_type() == NPU_CHIP_910) {
        npu_init_board_type_for_910(board_id);
    } else if (npu_get_chip_type() == NPU_CHIP_310B) {
        npu_init_board_type_for_310b(board_id);
    } else if (npu_get_chip_type() == NPU_CHIP_910B) {
        npu_init_board_type_for_910b(board_id);
    } else if (npu_get_chip_type() == NPU_CHIP_910_93) {
        npu_init_board_type_for_910_93(board_id);
    } else {
        g_board_type = NPU_BOARD_TYPE_INVALID;
    }
    return;
}

int npu_get_first_ready_device(int *card_id, int *chip_id)
{
    int i;
    int ret;
    unsigned int mode;
    int device_count = 0;
    int device_id_list[MAX_DEVICE_NUM] = {0};

    ret = dcmi_get_npu_device_list((int *)&device_id_list[0], MAX_DEVICE_NUM, &device_count);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_list failed. err is %d.", ret);
        return ret;
    }

    ret = dcmi_get_rc_ep_mode(&mode);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "npu_get_first_ready_device failed. ret is %d", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    for (i = 0; i < device_count; i++) {
        ret = dcmi_get_boot_status(mode, device_id_list[i]);
        if (ret == DCMI_OK) {
#ifndef NPU_SMI_V2
            ret = dcmi_get_card_id_device_id_from_logicid(card_id, chip_id, device_id_list[i]);
#else
            ret = dcmiv2_inner_get_card_id_device_id_from_logicid(card_id, chip_id, device_id_list[i]);
#endif
            if (ret == DCMI_OK) {
                return NPU_OK;
            }
        }
    }

    if (i >= device_count) {
        gplog(LOG_ERR, "can not get ok device.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

int npu_get_board_type_by_board_id()
{
    int ret;
    int card_id;
    int chip_id;
#ifdef NPU_SMI_V2
    int device_logic_id;
#endif
    struct dcmi_board_info board_info = { 0 };

    ret = npu_get_first_ready_device(&card_id, &chip_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "npu_get_first_ready_device failed. err is %d", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_logic_id(&device_logic_id, card_id, chip_id);
    if (ret != DCMI_OK) {
        gplog (LOG_ERR, "dcmiv2_get_device_logic_id failed. "
        "card_id is %d, chip_id is %d, err is %d", card_id, chip_id, ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
    card_id = device_logic_id;
#endif
    ret = npu_init_chip_type(card_id, chip_id);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_init_chip_type failed. err is %d", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_board_info(card_id, &board_info);
#else
    ret = dcmi_get_device_board_info(card_id, chip_id, &board_info);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_board_info failed. err is %d", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    if (npu_get_chip_type() == NPU_CHIP_950) {
        npu_init_board_type_by_mainboard_id();
    } else {
        npu_init_board_type_by_board_id(board_info.board_id);
    }

    return NPU_OK;
}

int npu_board_type_is_card(void)
{
    return (g_board_type == NPU_BOARD_TYPE_CARD);
}

int npu_board_type_is_server(void)
{
    return (g_board_type == NPU_BOARD_TYPE_SERVER);
}

int npu_board_type_is_station(void)
{
    return (g_board_type == NPU_BOARD_TYPE_STATION);
}

int npu_board_type_is_hilens(void)
{
    return (g_board_type == NPU_BOARD_TYPE_HILENS);
}

int npu_board_type_is_soc(void)
{
    return (g_board_type == NPU_BOARD_TYPE_SOC);
}

int npu_board_type_is_model(void)
{
    return (g_board_type == NPU_BOARD_TYPE_MODEL);
}

int npu_check_is_has_d_chip(void)
{
    if (npu_board_type_is_station() == TRUE || npu_board_type_is_hilens() == TRUE) {
        if (access("/run/minid_not_present", F_OK) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

int npu_check_is_has_pcie(void)
{
    return dcmi_is_has_pcieinfo();
}

int npu_check_is_has_mcu(void)
{
    return dcmi_is_has_mcu();
}

int bytes_transform(unsigned long long bytes, enum bytes_transforms_type flag, unsigned long long *result)
{
    /* KB = 1024 B, MB = 1024 *1024 B = 1048576B ,... */
    unsigned long long transform[] = {1024, 1048576, 1073741824, 1099511627776 };
    *result = bytes / transform[flag];
    return NPU_OK;
}

int npu_is_in_virtual_machine(void)
{
#ifdef _WIN32
    return FALSE;
#else
    bool check_result = false;
    if (npu_board_type_is_card() || npu_board_type_is_server() || dcmi_get_product_type_inner() == DCMI_A200_A2_EP) {
        pid_t ret;
        ret = system("/usr/sbin/dmidecode 2>&1 | grep -E \"xen|Xen|VMware|OpenStack|KVM Virtual Machine\" > /dev/null");
        check_result = ((ret != -1) && (WIFEXITED(ret) && (WEXITSTATUS(ret) == 0)));
        if (check_result) {
            return TRUE;
        }

        ret = system("/usr/sbin/dmidecode 2>&1 | grep -E \"Manufacturer: QEMU|Manufacturer: qemu\" > /dev/null");
        check_result = ((ret != -1) && (WIFEXITED(ret) && (WEXITSTATUS(ret) == 0)));
        if (check_result) {
            return TRUE;
        }

        ret = system("/usr/bin/systemd-detect-virt -v > /dev/null  2>&1");
        check_result = ((ret != -1) && (WIFEXITED(ret) && (WEXITSTATUS(ret) == 0)));
        if (check_result) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
#endif
}

int check_vnpu_workmode(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned char work_mode = NPU_INVALID_WORK_MODE;

    /* 标卡形态和910B支持vnpu操作 */
    if (npu_board_type_is_card() || npu_get_chip_type() == NPU_CHIP_910B) {
        return NPU_OK;
    }

    ret = dcmi_get_npu_work_mode(operate_info->id, &work_mode);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get npu work mode.");
        return dcmi_to_npu_error_code(ret);
    }

    /* 只有AMP模式支持vnpu相关操作 */
    if (work_mode == NPU_AMP_WORK_MODE) {
        return NPU_OK;
    }

    gplog(LOG_ERR, "NPU is not working in AMP mode.");
    return NPU_ERR_CODE_NOT_SUPPORT;
}

int check_vnpu_docker_mode(void)
{
    int mode;
    int ret;

    ret = dcmi_get_vdevice_mode(&mode);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_get_vdevice_mode failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (mode == VNPU_DOCKER) {
        return NPU_OK;
    }
    gplog(LOG_ERR, "VNPU is not in docker mode.");
    return NPU_ERR_CODE_NOT_SUPPORT;
}

int npu_is_in_docker()
{
#ifndef _WIN32
    if (npu_is_in_docker_by_file() == TRUE) {
        return TRUE;
    }
    if (npu_is_in_docker_by_cmd() == TRUE) {
        return TRUE;
    }

    return FALSE;
#else
    return FALSE;
#endif
}

int npu_is_run_in_vm_or_docker()
{
    return npu_is_in_docker() || npu_is_in_virtual_machine();
}

int npu_get_card_device_id(int card_id, int *chip_count, int *mcu_id, int *cpu_id)
{
    int ret;
#ifdef NPU_SMI_V2 // A5无cpu_id和mcu_id
    *chip_count = 1;
    *mcu_id = DCMI_INVALID_VALUE;
    *cpu_id = DCMI_INVALID_VALUE;
    ret = DCMI_OK;
#else
    ret = dcmi_get_device_id_in_card(card_id, chip_count, mcu_id, cpu_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_id_in_card card %d failed. err is %d", card_id, ret);
    }
#endif
    return dcmi_to_npu_error_code(ret);
}

int npu_common_get_health_state_str(int status_index, char *health_state, int state_length)
{
    int ret;
    size_t length;
    const char *health_state_list[] = { "OK", "Warning", "Alarm", "Critical", "UNKNOWN" };

    if (status_index < 0 || status_index >= (int)(sizeof(health_state_list) / (sizeof(health_state_list[0])))) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    length = strlen(health_state_list[status_index]) + 1;
    ret = strncpy_s(health_state, state_length, health_state_list[status_index], length);
    if (ret != EOK) {
        gplog(LOG_ERR, "strncpy_s failed. err is %d.", ret);
        ret = NPU_ERR_CODE_SECURE_FUN_FAIL;
    }
    return ret;
}

int check_watch_chip_parm(struct npu_smi_operate_info *operate_info)
{
    if ((operate_info->type != WATCH_INFO) || (operate_info->is_all == TRUE) ||
        (operate_info->is_mapping == TRUE)) {
        printf("The parameter is invalid.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((operate_info->chip_id != NPU_DEFAULT_VALUE) && (operate_info->id == NPU_DEFAULT_VALUE)) {
        printf("You must select a card at first.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    return NPU_OK;
}

int check_watch_proc_parm(struct npu_smi_operate_info *operate_info)
{
    if ((operate_info->type != NPU_DEFAULT_VALUE) || (operate_info->is_all == TRUE) ||
        (operate_info->is_mapping == TRUE)) {
        printf("The parameter is invalid.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if ((operate_info->chip_id == NPU_DEFAULT_VALUE) || (operate_info->id == NPU_DEFAULT_VALUE)) {
        printf("This command must input card id and chip id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (npu_check_card_id(operate_info->id) != NPU_OK) {
        printf("Invalid card id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (npu_check_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK) {
        printf("Invalid chip id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    return NPU_OK;
}

int npu_info_proc_watch_param(struct npu_smi_operate_info *operate_info, const char *argv, int *para_num)
{
    int para_num_tmp = *para_num;
    if (strcmp("watch", argv) == 0) {
        operate_info->is_watch = WATCH_CHIP_INFO;
        operate_info->type = WATCH_INFO;
        para_num_tmp = para_num_tmp + 1;
    }

    if (strcmp("proc", argv) == 0) {
        printf("This device does not support querying proc info.\n");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    *para_num = para_num_tmp;
    return NPU_OK;
}

int npu_get_dvpp_info_usage(int card_id, int device_id, struct dcmi_dvpp_ratio *usage)
{
    int ret;

    if (usage == NULL) {
        gplog(LOG_ERR, "dcmi_get_device_dvpp_ratio_info usage is NULL.");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = dcmi_get_device_dvpp_ratio_info(card_id, device_id, usage);
    if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
        return dcmi_to_npu_error_code(ret);
    }
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "dcmi_get_device_dvpp_ratio_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    return NPU_OK;
}

int npu_set_nic_down_flag(int card_id, int enable_flag)
{
    int ret, i;
    int device_num = 0;

    ret = dcmi_get_device_num_in_card(card_id, &device_num);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_num_in_card failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    for (i = 0; i < device_num; i++) {
        ret = dcmi_set_device_offline_nic_down_flag(card_id, i, enable_flag);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_set_device_offline_nic_down_flag failed. err is %d", ret);
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }
    }
    return NPU_OK;
}

int npu_close_nic_network(int card_id)
{
    int ret, i, j;
    int device_num = 0;
    char command[MAX_STR_LENTH] = {0};

    ret = dcmi_get_device_num_in_card(card_id, &device_num);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_num_in_card failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    if (access("/usr/bin/hccn_tool", F_OK) != 0) {
        gplog(LOG_ERR, "Failed to disable NIC, hccn_tool maybe not exit!");
        return NPU_ERR_CODE_INNER_ERR;
    }
    for (i = 0; i < device_num; i++) {
        ret = sprintf_s(command, MAX_STR_LENTH, "echo y | /usr/bin/hccn_tool -i %d -link -s down > /dev/null 2>&1",
                        device_num * card_id + i);
        if (ret <= 0) {
            gplog(LOG_ERR, "Call sprintf_s failed.");
            return NPU_ERR_CODE_SECURE_FUN_FAIL;
        }

        pid_t status;
        for (j = 0; j < CLOSE_NIC_NETWORK_RETRY_TIME; j++) {
            status = system(command);
            if ((status == -1) || (WIFEXITED(status) == 0) || (WEXITSTATUS(status) != 0)) {
                gplog(LOG_OP, "failed to shutdown device %d. status=%d, retry times=%d.", (device_num * card_id + i),
                    status, j);
                sleep(1);
                continue;
            }
            break;
        }
    }
    return NPU_OK;
}

#define MAX_LINE_LENGTH 256

char *get_param_value(const char *filename, const char *param_name)
{
    char line[MAX_LINE_LENGTH];
    char* param_value = NULL;

    if (filename == NULL || param_name == NULL) {
        gplog(LOG_ERR, "INPUT filename or param_name is NULL.");
        return NULL;
    }
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        gplog(LOG_ERR, "Failed to open file %s.", filename);
        return NULL;
    }

    while (fgets(line, sizeof(line), file)) {
        // 去除行尾的换行符
        line[strlen(line) - 1] = '\0';

        // 查找参数名和值
        char* name = strtok(line, "=");
        char* value = strtok(NULL, "=");

        if (name != NULL && value != NULL && strcmp(name, param_name) == 0) {
            param_value = strdup(value);
            break;
        }
    }

    fclose(file);
    return param_value;
}

int npu_msn_log_cfg_recover(int cardId)
{
    int ret;
    char cmd[MAX_LINE_LENGTH] = {0};
    char card_id[MAX_LINE_LENGTH] = {0};
    char *install_path = get_param_value("/etc/ascend_install.info", "Driver_Install_Path_Param");

    if (install_path != NULL) {
        ret = sprintf_s(cmd, MAX_LINE_LENGTH, "%s/driver/script/msn_config_recover.sh", install_path);
        if (ret < 0) {
            ret = NPU_ERR_CODE_SECURE_FUN_FAIL;
            gplog(LOG_ERR, "call sprintf_s failed. ret=%d", ret);
            goto OUT;
        }
        ret = sprintf_s(card_id, MAX_LINE_LENGTH, "%d", cardId);
        if (ret < 0) {
            ret = NPU_ERR_CODE_SECURE_FUN_FAIL;
            gplog(LOG_ERR, "call sprintf_s failed. ret=%d", ret);
            goto OUT;
        }

        char *cmd_str[] = {cmd, card_id, "1", NULL};

        ret = dcmi_safe_exec_syscmd_without_output(cmd_str);
        if (ret == -1) {
            gplog(LOG_ERR, "Run dcmi_safe_exec_syscmd_without_output failed. ret=%d", ret);
            ret = NPU_ERR_CODE_SECURE_FUN_FAIL;
            goto OUT;
        }
        free(install_path);
    } else {
        gplog(LOG_ERR, "Failed to get the Firmware_Install_Path_Param");
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;

OUT:
    free(install_path);
    return ret;
}

int check_netmask_addr(unsigned int *ip_addr, int ip_max_len)
{
    int i;
    unsigned int j;
    int first_zero_find = FALSE;
    int is_zero;

    for (i = 0; i < ip_max_len; i++) {
        if (ip_addr[i] > MAX_IP_VALUE) {
            return FALSE;
        }

        for (j = 1; j <= IP_AND_MASK_CNT; j++) {
            is_zero = (ip_addr[i] >> (IP_AND_MASK_CNT - j)) & 1;
            if (!is_zero) {
                first_zero_find = (first_zero_find == FALSE) ? TRUE : FALSE;
                continue;
            }

            if (first_zero_find == TRUE) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

int npu_get_elabel_pn_sn_items_info(int card_index, struct npu_all_info *npu_all_info)
{
    int ret;
    struct dcmi_elabel_info elabel_info = { { 0 } };

    if (card_index < 0 || card_index >= MAX_CARD_NUM) {
        gplog(LOG_ERR, "card index invalid .%d", card_index);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
#ifndef NPU_SMI_V2
    ret = dcmi_get_card_elabel_v2(npu_all_info->card_info[card_index].card_id, &elabel_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_card_elabel_v2 card index %d failed. err is %d", card_index, ret);
#else
    ret = dcmiv2_get_device_elabel_info(npu_all_info->card_info[card_index].card_id, &elabel_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_elabel_info card index %d failed. err is %d", card_index, ret);
#endif
        ret = strncpy_s(npu_all_info->card_info[card_index].serial_number, NPU_MAX_LENTH, "NA", strlen("NA"));
        if (ret != EOK) {
            gplog(LOG_ERR, "strncpy_s failed. err is %d", ret);
        }

        ret = strncpy_s(npu_all_info->card_info[card_index].product_name, NPU_MAX_LENTH, "NA", strlen("NA"));
        if (ret != EOK) {
            gplog(LOG_ERR, "strncpy_s failed. err is %d", ret);
        }
    } else {
        ret = strncpy_s(npu_all_info->card_info[card_index].serial_number, NPU_MAX_LENTH, elabel_info.serial_number,
            strlen(elabel_info.serial_number));
        if (ret != EOK) {
            gplog(LOG_ERR, "memcpy_s failed. err is %d", ret);
        }

        ret = strncpy_s(npu_all_info->card_info[card_index].product_name, NPU_MAX_LENTH, elabel_info.product_name,
            strlen(elabel_info.serial_number));
        if (ret != EOK) {
            gplog(LOG_ERR, "strncpy_s failed. err is %d", ret);
        }
    }
    return NPU_OK;
}

int npu_safe_exec_syscmd_without_output(char *cmdstring[])
{
#ifndef _WIN32
    pid_t pid;
    int status;
    int rc = -1;

    if (cmdstring == NULL) {
        return -1;
    }

    if ((pid = fork()) < 0) {
        printf("fork error\n");
    } else if (pid == 0) {
        // child process
        int fd = open("/dev/null", O_WRONLY);
        if (fd < 0) {
            exit(1);
            return rc;
        }
        dup2(fd, 0); /* 0,1,2代表子进程的标准输入输出 */
        dup2(fd, 1); /* 0,1,2代表子进程的标准输入输出 */
        dup2(fd, 2); /* 0,1,2代表子进程的标准输入输出 */
        (void)execvp(cmdstring[0], cmdstring);
        close(fd);
        exit(1);
    } else {
        // parent process
        (void)waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            rc = WEXITSTATUS(status);
        }
    }

    return rc;
#else
    return NPU_OK;
#endif
}

int npu_get_driver_install_path_ep(char *path, int len)
{
    FILE *file;
    char linebuf[BUF_LEN] = {0};
    char *p = NULL;
    int ret = -1;

    file = fopen(ASCEND_INSTALL_INFO, "r");
    if (file == NULL) {
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    while (fgets(linebuf, BUF_LEN - 1, file) != NULL) {
        p = strstr(linebuf, "Driver_Install_Path_Param=");
        if (p != NULL) {
            p = p + strlen("Driver_Install_Path_Param=");
            ret = memcpy_s(path, len, p, strlen(p));
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "npu_get_driver_install_path_ep call memcpy_s failed.%d.", ret);
                ret = DCMI_ERR_CODE_SECURE_FUN_FAIL;
                break;
            }
            if (strlen(path) < 1) {
                ret = NPU_ERR_CODE_FILE_OPERATE_FAIL;
                break;
            }
            if (path[strlen(path) - 1] == 0xa) { // 去除换行 0xa代表换行
                path[strlen(path) - 1] = 0;
            }
            ret = 0;
            break;
        }
    }

    (void)fclose(file);
    return ret;
}

int npu_get_driver_install_path_rc(char *path, int len)
{
    int ret;
    ret = snprintf_s(path, len, len - 1, "%s", "/usr/local/Ascend");
    if (ret < 0) {
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }
    return NPU_OK;
}

int npu_get_driver_install_path(char *path, int len)
{
    int ret;

    if (npu_board_type_is_soc()) {
        ret = npu_get_driver_install_path_rc(path, len);
    } else {
        ret = npu_get_driver_install_path_ep(path, len);
    }
    return ret;
}

int npu_get_key_manage_path(char *real_path, int len)
{
    int ret;
    char driver_path[PATH_MAX + 1] = {0};
    char script_path[PATH_MAX + 1] = {0};

    ret = npu_get_driver_install_path(driver_path, sizeof(driver_path));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_key_manage_path npu_get_driver_install_path failed. err is %d.", ret);
        return ret;
    }
    ret = snprintf_s(script_path, PATH_MAX + 1, PATH_MAX, "%s/%s", driver_path,
        "driver/script/ascend_driver_config.sh");
    if (ret <= 0) {
        gplog(LOG_ERR, "npu_get_key_manage_path call snprintf_s failed.%d\n", ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    if ((check_file_path(script_path) != NPU_OK) ||
        (check_filename(script_path, real_path, len) != NPU_OK) ||
        (access(real_path, F_OK) != NPU_OK)) {
        gplog(LOG_ERR, "npu_get_key_manage_path file check fail.\n");
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }
    return NPU_OK;
}

int check_confirm_info(void)
{
    char string[QUARTER_BUFF_LEN] = {0};

    while (scanf_s("%s", string, (QUARTER_BUFF_LEN - 1)) != EOF) {
        if ((strlen(string) != 1) || ((string[0] != 'y') && (string[0] != 'n') &&
            (string[0] != 'Y') && (string[0] != 'N'))) {
            printf("Error! Please input 'y' or 'n'!\n");
            continue;
        }

        if (string[0] == 'Y' || string[0] == 'y') {
            return NPU_OK;
        }

        if (string[0] == 'N' || string[0] == 'n') {
            return NPU_ERR_CODE_ABORT_OPERATE;
        }
    }

    return NPU_ERR_CODE_INNER_ERR;
}

int check_support_get_err_count_info(struct npu_smi_operate_info *operate_info)
{
    switch (npu_get_chip_type()) {
        case NPU_CHIP_310:
            if (strcmp(operate_info->stype, "pcie-err") == 0) {
                return NPU_ERR_CODE_NOT_SUPPORT;
            }
            break;
        case NPU_CHIP_310P:
            if (strcmp(operate_info->stype, "err-count") == 0) {
                return NPU_ERR_CODE_NOT_SUPPORT;
            }
            break;
        case NPU_CHIP_910:
            return NPU_ERR_CODE_NOT_SUPPORT;
        case NPU_CHIP_910B:
            return NPU_OK;
        case NPU_CHIP_950:
            if (dcmi_mainboard_is_a900_a5_pcie(g_mainboard_info.mainboard_id)) {
                return NPU_OK;
            }
            return NPU_ERR_CODE_NOT_SUPPORT;
        case NPU_CHIP_910_93:
            if (is_a_x_910_93(operate_info->id)) {
                return NPU_OK;
            }
            return NPU_ERR_CODE_NOT_SUPPORT;
        default:
            return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

int check_support_customized_info(struct npu_smi_operate_info *operate_info)
{
    switch (npu_get_chip_type()) {
        case NPU_CHIP_310:
            if (strcmp(operate_info->stype, "license") != 0) {
                return NPU_ERR_CODE_NOT_SUPPORT;
            }

            if (npu_is_run_in_vm_or_docker() == TRUE) {
                printf("\t%-30s : %s\n", "Message", "This command cannot be executed on a VM or container.");
                return NPU_ERR_CODE_OPER_NOT_PERMITTED;
            }

            if (npu_check_is_has_mcu() != TRUE) {
                return NPU_ERR_CODE_NOT_SUPPORT;
            }
            break;
        case NPU_CHIP_310P:
            if (strcmp(operate_info->stype, "customized-info") != 0) {
                return NPU_ERR_CODE_NOT_SUPPORT;
            }

            if (npu_check_is_has_mcu() != TRUE) {
                return NPU_ERR_CODE_NOT_SUPPORT;
            }
            break;
        case NPU_CHIP_910:
        case NPU_CHIP_910B:
            return NPU_ERR_CODE_NOT_SUPPORT;
        default:
            return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

int check_support_err_count_clear(struct npu_smi_operate_info *operate_info)
{
    bool check_support_result = false;
    if (strcmp(operate_info->stype, "errcount-clear") == 0) {
        check_support_result = (npu_get_chip_type() == NPU_CHIP_310 && npu_board_type_is_card() == TRUE);
    } else if (strcmp(operate_info->stype, "clear-pcie-err") == 0) {
        check_support_result = (npu_get_chip_type() == NPU_CHIP_310P && npu_board_type_is_card() == TRUE);
    }

    if (!check_support_result) {
        printf("This device does not support setting %s.\n", operate_info->stype);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return NPU_OK;
}

int update_minid_conf(char *config_name, int config_value)
{
    char buf[64] = {0};
    FILE* resultFile;
    int ret;

    resultFile = fopen(MINID_CONF_INI, "w+");
    if (resultFile == NULL) {
        gplog(LOG_ERR, "failed open %s.\n", MINID_CONF_INI);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    ret = sprintf_s(buf, sizeof(buf), "%s=%d", config_name, config_value);
    if (ret <= 0) {
        gplog(LOG_ERR, "call sprintf_s failed.%d. %s %d\n", ret, config_name, config_value);
        fclose(resultFile);
        return NPU_ERR_CODE_INNER_ERR;
    }

    (void)fwrite(buf, 1, strlen(buf), resultFile);
    (void)fclose(resultFile);
#ifndef _WIN32
    (void)chmod(MINID_CONF_INI, S_IRUSR | S_IWUSR | S_IRGRP);
#endif
    return NPU_OK;
}

int get_chip_boot_status(int card_id, int device_id)
{
    int ret;
    int retry_time = BOOT_STATUS_RETRY_TIME;
    enum dcmi_boot_status boot_status = DCMI_BOOT_STATUS_UNINIT;

    while (retry_time--) {
        if (dcmi_board_chip_type_is_ascend_950() == TRUE) {
            ret = dcmiv2_get_device_boot_status(card_id, &boot_status);
        } else {
            ret = dcmi_get_device_boot_status(card_id, device_id, &boot_status);
        }
        if (ret == DCMI_ERR_CODE_NOT_SUPPORT) {
            return NPU_ERR_CODE_NOT_SUPPORT;
        }

        if (ret == DCMI_OK) {
            if (boot_status == DCMI_SYSTEM_START_FINISH) {
                break;
            }
        }
        sleep(3); // 延时3s
    }

    if (retry_time == -1) {
        gplog(LOG_ERR, "device%d reboot timeout, boot status is %d, ret is %d", device_id, boot_status, ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    return NPU_OK;
}

int npu_invalid_item_proc(struct npu_smi_operate_info *operate_info)
{
    printf("input parameter error,stype=%s\n", operate_info->stype);
    return NPU_ERR_CODE_INVALID_PARAMETER;
}

int set_card_syslog_enable(struct npu_smi_operate_info *operate_info)
{
    int ret;

    if (operate_info->has_id) {
        printf("This command does not support input card id.\n");
        gplog(LOG_ERR, "This command does not support input card id.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_info->enable_value == NPU_INVALID_VALUE) {
        printf("Must input parameter of -d.\n");
        gplog(LOG_ERR, "Must input parameter of -d.");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_set_syslog_persistence_mode(operate_info->enable_value);
    if (ret == DCMI_ERR_CODE_SYSLOG_CONFIG_ILLEGAL) {
        printf("ERROR: The configuration file has been maliciously modified, "
                "please clear configuration and stop syslog collecting process first.\n");
        gplog(LOG_ERR, "The configuration file has been maliciously modified, ret is %d", ret);
        return NPU_ERR_CODE_INNER_ERR;
    } else if (ret != DCMI_OK) {
        printf("Set syslog mode failed.\n");
        gplog(LOG_ERR, "set_syslog_mode failed, ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    gplog(LOG_OP, "Set syslog_persistence_mode %s success.", (operate_info->enable_value == 0) ? "disable" : "enable");
    printf("Set syslog mode success, mode = %d\n", operate_info->enable_value);
    return NPU_OK;
}

int check_is_mixed_env(struct npu_smi_operate_info *operate_info, int *mixed_flag)
{
    int ret, card_num, i;
    int card_list[MAX_CARD_NUM] = {0};
    char product_name[NPU_PRODUCT_NAME_MAX_LEN] = {0};
    char product_name_tmp[NPU_PRODUCT_NAME_MAX_LEN] = {0};
    *mixed_flag = FALSE;

    if (dcmi_board_chip_type_is_ascend_910() || dcmi_board_chip_type_is_ascend_910b()) {
        return NPU_OK;
    }

    ret = dcmi_get_card_list(&card_num, card_list, MAX_CARD_NUM);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_card_list called failed. ret=%d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmi_get_product_type(card_list[0], 0, product_name, NPU_PRODUCT_NAME_MAX_LEN);
    if (ret != DCMI_OK) {
        return ret;
    }

    for (i = 1; i < card_num; i++) {
        ret = dcmi_get_product_type(card_list[i], 0, product_name_tmp, NPU_PRODUCT_NAME_MAX_LEN);
        if (ret != DCMI_OK) {
            return ret;
        }

        if (strcmp(product_name_tmp, product_name) != 0) {
            *mixed_flag = TRUE;
            break;
        }
    }
    return NPU_OK;
}

bool is_a_x_910_93(int card_id)
{
    int ret;
    unsigned int main_board_id;

    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = dcmiv2_get_mainboard_id(card_id, &main_board_id);
    } else {
        ret = dcmi_get_mainboard_id(card_id, 0, &main_board_id);
    }
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to query main board id of card. err is %d", ret);
        return FALSE;
    }
    return (main_board_id == DCMI_A_X_910_93_MAIN_BOARD_ID && npu_get_chip_type() == NPU_CHIP_910_93);
}