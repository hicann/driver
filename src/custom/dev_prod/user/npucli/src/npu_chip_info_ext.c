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
#include <ctype.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <process.h>
#endif

#include <time.h>
#include <limits.h>
#include "securec.h"
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "npu_common.h"
#include "npu_info.h"
#include "npu_info_print.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_init_basic.h"

static int csr_name_segment_operate(char *input_str, char **input_para, char **next_token, size_t num)
{
#ifndef _WIN32
    int ret;
    char seps[] = "|";
    char *seg = NULL;
    char *csr_segment_name[] = { "country_name", "province_name",
        "city_name", "organization_name", "department_name" };
    seg = strtok_s(input_str, seps, next_token);
    if (num >= (sizeof(csr_segment_name) / sizeof(csr_segment_name[0]))) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (num != 0 && (seg == NULL || strlen(seg) >= CERT_NAME_MAX_LEN)) {
        printf("Invalid name length of %s. Enter 1 to 15 characters.\n", csr_segment_name[num]);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    if (num == 0 && ((seg == NULL || strlen(seg) != CERT_CN_NAME_LEN) ||
        isupper(seg[0]) == 0 || isupper(seg[1]) == 0)) {
        printf("Invalid name length of %s. Enter two uppercase characters.\n", csr_segment_name[num]);
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = strcpy_s(input_para[num], CERT_NAME_MAX_LEN, seg);
    if (ret != EOK) {
        gplog(LOG_ERR, "Call strcpy_s failed. error code is %d.", ret);
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

static int csr_input(struct dcmi_csr_info *csr_info)
{
#ifndef _WIN32
    int ret;
    char *input_str = NULL;
    char *next_token_init = NULL;
    char **next_token = &next_token_init;
    char *input_para[] = {
        csr_info->country_name,
        csr_info->province_name,
        csr_info->city_name,
        csr_info->organization_name,
        csr_info->department_name
    };
    size_t i;
    size_t input_para_row = sizeof(input_para) / sizeof(input_para[0]);

    input_str = (char *)calloc(input_para_row, CERT_NAME_MAX_LEN);
    if (input_str == NULL) {
        gplog(LOG_ERR, "Call calloc failed.");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    printf("Enter country_name|province_name|city_name|organization_name|department_name.\n"
           "Example: CN|ZHEJIANG|HANGZHOU|Huawei|Marketing\n");
    while (gets_s(input_str, input_para_row * CERT_NAME_MAX_LEN - 1) == NULL) {
        printf("Invalid. Input it again.\n");
    }

    ret = csr_name_segment_operate(input_str, input_para, next_token, 0);
    if (ret != NPU_OK) {
        free(input_str);
        return ret;
    }

    for (i = 1; i < input_para_row; i++) {
        ret = csr_name_segment_operate(NULL, input_para, next_token, i);
        if (ret != NPU_OK) {
            break;
        }
    }

    free(input_str);
    return ret;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

static int csr_write(struct dcmi_csr_info *tls_csr_info, struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
    FILE *csr_file = NULL;
    char filename[PATH_MAX] = {0};

    if (access(CSR_SAVE_PATH, F_OK) != 0) {
        if (mkdir(CSR_SAVE_PATH, S_IRWXU) < 0) {
            gplog(LOG_ERR, "mkdir dir %s fail.", CSR_SAVE_PATH);
            return NPU_ERR_CODE_FILE_OPERATE_FAIL;
        }
    }

    ret = sprintf_s(filename, PATH_MAX - 1, "/run/csr/cert_type_PKI2.0_tls_%d_%d.csr",
                    operate_info->id, operate_info->chip_id);
    if (ret <= 0) {
        gplog(LOG_ERR, "Call sprintf_s failed, operation type is %s, ret is %d.", operate_info->stype, ret);
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    if ((csr_file = fopen(filename, "w")) == NULL) {
        gplog(LOG_ERR, "Creat path '%s' failed.", filename);
        return NPU_ERR_CODE_FILE_OPERATE_FAIL;
    }

    (void)chmod((const char *)filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fseek(csr_file, 0, SEEK_SET) != 0) {
        gplog(LOG_ERR, "Call fseek failed.");
        ret = NPU_ERR_CODE_MEM_OPERATE_FAIL;
        goto CSR_WRITE_OUT;
    }

    if (fwrite(tls_csr_info->csr_data, sizeof(char), tls_csr_info->csr_len, csr_file) <= 0) {
        gplog(LOG_ERR, "Call fwrite failed.");
        ret = NPU_ERR_CODE_FILE_OPERATE_FAIL;
        goto CSR_WRITE_OUT;
    }

    ret = NPU_OK;
CSR_WRITE_OUT:
    (void)fclose(csr_file);
    csr_file = NULL;
    return ret;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

static int show_csr_info(struct npu_smi_operate_info *operate_info, enum dcmi_main_cmd main_cmd, unsigned int sub_cmd)
{
#ifndef _WIN32
    int ret;
    unsigned int csr_len;
    struct dcmi_csr_info csr_info = { 0 };

#ifndef NPU_SMI_V2
    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b() ||
        dcmi_board_chip_type_is_ascend_310p() || dcmi_board_chip_type_is_ascend_950()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#else
    operate_info->chip_id=0;
    if (!(dcmi_board_chip_type_is_ascend_950()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#endif

    if ((dcmi_board_type_is_310p_duo_chips() || dcmi_board_chip_type_is_ascend_910_93()) &&
        (operate_info->chip_id != 0)) {
        gplog(LOG_OP, "The Atlas 300I Duo card and 910_93 is only supported on chip 0.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = csr_input(&csr_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to input csr info. err is %d.", ret);
        return ret;
    }

    csr_len = sizeof(struct dcmi_csr_info);

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id,
        main_cmd, sub_cmd, (char *)&csr_info, &csr_len);
#else
    ret = dcmiv2_get_device_info(operate_info->id, main_cmd, sub_cmd, (char *)&csr_info, &csr_len);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get %s. err is %d.", operate_info->stype, ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = csr_write(&csr_info, operate_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "Failed to write %s file. err is %d.", operate_info->stype, ret);
    }

    return ret;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int show_tls_csr_info(struct npu_smi_operate_info *operate_info)
{
    int ret = show_csr_info(operate_info, DCMI_MAIN_CMD_EX_CERT, DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY);
    if (ret == NPU_OK) {
        printf("\t%-30s : The tls csr file of the chip is obtained successfully.\n", "Message");
    }
    return ret;
}

static int show_cert_info(struct dcmi_cert_info *cert_info, struct npu_smi_operate_info *operate_info,
                          enum dcmi_main_cmd main_cmd, unsigned int sub_cmd)
{
#ifndef _WIN32
    int ret;
    unsigned int cert_len;

#ifndef NPU_SMI_V2
    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b() ||
        dcmi_board_chip_type_is_ascend_310p()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#else
    operate_info->chip_id=0;
    if (!(dcmi_board_chip_type_is_ascend_950()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#endif

    if ((dcmi_board_type_is_310p_duo_chips() || dcmi_board_chip_type_is_ascend_910_93()) &&
        (operate_info->chip_id != 0)) {
        gplog(LOG_OP, "The Atlas 300I Duo card and 910_93 is only supported on chip 0.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    cert_len = sizeof(struct dcmi_cert_info);
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id,
                               main_cmd, sub_cmd, (char *)cert_info, &cert_len);
#else
    ret = dcmiv2_get_device_info(operate_info->id, main_cmd, sub_cmd, (char *)cert_info, &cert_len);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get %s. err is %d.", operate_info->stype, ret);
        return dcmi_to_npu_error_code(ret);
    }

    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

static int print_cert_info(int ret, struct dcmi_cert_info *cert_info)
{
    if (ret == NPU_ERR_CODE_FILE_OPERATE_FAIL) {
        printf("The certificate does not exist.\n");
        ret = NPU_OK;
    } else if (ret == NPU_OK) {
        printf("\t%-30s : %u\n", "Alarm status", cert_info->alarm_stat);
        printf("\t%-30s : %s", "Start time", cert_info->start_time); // 返回的start_time中已包含换行符
        printf("\t%-30s : %s", "End time", cert_info->end_time); // 返回的end_time中已包含换行符
        printf("\t%-30s : %s\n", "Common name", cert_info->common_name);
    }
    return ret;
}

int show_tls_cert_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct dcmi_cert_info cert_info = { 0 };
    ret = show_cert_info(&cert_info, operate_info, DCMI_MAIN_CMD_EX_CERT, DCMI_CERT_SUB_CMD_TLS_CERT_INFO);
    ret = print_cert_info(ret, &cert_info);
    return ret;
}

int show_tls_rootkey_info(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret, status_idx = 0;
    char *rootkey_status_cfg[] = {"Not Support", "Support"};
    unsigned int rootkey_status = 0xFFFFFFFF;

    if (!dcmi_board_chip_type_is_ascend_910b()) {
        gplog(LOG_ERR, "Only support Atlas A2.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    // 当前key_type只支持0
    ret = dcmi_get_rootkey_status(operate_info->id, operate_info->chip_id, 0, &rootkey_status);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Dcmi get rootkey status failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    status_idx = (rootkey_status == ROOTKEY_HUK_ENABLE) ? 1 : 0;
    printf("\t%-30s : %s\n", "Rootkey-Support Status", rootkey_status_cfg[status_idx]);
    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

void print_npu_spod_info(struct dcmi_spod_info *spod_info)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type != NPU_CHIP_950) {
        printf("\t%-30s : %u\n", "SDID", spod_info->sdid);
    }
    printf("\t%-30s : %u\n", "Super Pod Size", spod_info->super_pod_size);
    printf("\t%-30s : %u\n", "Super Pod ID", spod_info->super_pod_id);
    if (chip_type == NPU_CHIP_950) {
        // pod mainboard_id bit[7:5]为000
        if (((g_mainboard_info.mainboard_id >> DCMI_SHIFT_FIVE_BITS) & A5_MAINBOARD_ID_MASK) ==
            MAINBOARD_ID_HIGH_3BIT_POD) {
            printf("\t%-30s : %u\n", "Chassis ID", spod_info->chassis_id);
        } else {
            printf("\t%-30s : %u\n", "Server Index", spod_info->server_index);
        }
        printf("\t%-30s : %u\n", "Super Pod Type", spod_info->super_pod_type);
    } else {
        printf("\t%-30s : %u\n", "Server Index", spod_info->server_index);
    }
}

int show_ascend_chip_spod_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = NPU_TYPE;
    enum npu_chip_type chip_type = npu_get_chip_type();
    struct dcmi_spod_info spod_info = {0};
    unsigned int spod_info_size = sizeof(struct dcmi_spod_info);

    if (chip_type != NPU_CHIP_910_93 && chip_type != NPU_CHIP_950) {
        gplog(LOG_ERR, "This device does not support get spod info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
#else
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_get_device_type failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type == NPU_TYPE) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_CHIP_INF,
            DCMI_CHIP_INF_SUB_CMD_SPOD_INFO, &spod_info, &spod_info_size);
#else
        ret = dcmiv2_get_device_info(operate_info->id, DCMI_MAIN_CMD_CHIP_INF,
            DCMI_CHIP_INF_SUB_CMD_SPOD_INFO, &spod_info, &spod_info_size);
#endif
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Call dcmi_get_device_info failed. ret is %d. main_cmd is %d, sub_cmd is %d.",
                ret, DCMI_MAIN_CMD_CHIP_INF, DCMI_CHIP_INF_SUB_CMD_SPOD_INFO);
            return dcmi_to_npu_error_code(ret);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    print_npu_spod_info(&spod_info);
    return ret;
}

int show_ascend_chip_sio_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = NPU_TYPE;
    struct dcmi_sio_crc_err_statistics_info sio_info = {0};
    unsigned int sio_info_size = sizeof(struct dcmi_sio_crc_err_statistics_info);

    if (npu_get_chip_type() != NPU_CHIP_910_93 && npu_get_chip_type() != NPU_CHIP_950) {
        gplog(LOG_ERR, "This device does not support get SIO info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
#else
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_get_device_type failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type == NPU_TYPE) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_SIO,
            DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS, &sio_info, &sio_info_size);
#else
        ret = dcmiv2_get_device_info(operate_info->id, DCMI_MAIN_CMD_SIO,
            DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS, &sio_info, &sio_info_size);
#endif
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "Call dcmi_get_device_info failed. ret is %d. main_cmd is %d, sub_cmd is %d.",
                ret, DCMI_MAIN_CMD_SIO, DCMI_SIO_SUB_CMD_CRC_ERR_STATISTICS);
            return dcmi_to_npu_error_code(ret);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    print_npu_sio_info(&sio_info);
    return ret;
}

int show_ascend_chip_cpu_freq_up_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int flag = 0;
    char *cpu_freq_up[] = {"1.9GHz", "1.0GHz"};

    ret = dcmi_get_device_cpu_freq_info(operate_info->id, operate_info->chip_id, &flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_cpu_freq_info failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    printf("\t%-30s : %s\n", "CPU-Freq Info", cpu_freq_up[flag]);
    return NPU_OK;
}

int show_work_tops(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    DCMI_LP_CUR_TOPS_STRU cur_tops_stru = { 0 };
    DCMI_LP_TOPS_DETAILS_STRU tops_details_stru = { 0 };
    unsigned int cur_tops_len = sizeof(cur_tops_stru);
    unsigned int tops_details_len = sizeof(tops_details_stru);

    if (operate_info == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
    
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
 
    if (device_type != NPU_TYPE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
 
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_LP,
        DCMI_LP_SUB_CMD_TOPS_DETAILS, &tops_details_stru, &tops_details_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_info failed. err is %d, command is %d", ret, DCMI_LP_SUB_CMD_TOPS_DETAILS);
        return dcmi_to_npu_error_code(ret);
    }
 
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_LP,
        DCMI_LP_SUB_CMD_GET_WORK_TOPS, &cur_tops_stru, &cur_tops_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
 
    ret = show_work_tops_v2(&cur_tops_stru, &tops_details_stru);
    if (ret != NPU_OK) {
        printf("\tfail to get %s\n", "nve level");
        gplog(LOG_ERR, "show_work_tops_v2 failed. err is %d", ret);
    }
    return ret;
}
 
int show_work_tops_v2(DCMI_LP_CUR_TOPS_STRU *cur_tops_stru, DCMI_LP_TOPS_DETAILS_STRU *tops_details_stru)
{
    unsigned int tops_index = (*cur_tops_stru).work_tops;
    unsigned int aic_freq = (*tops_details_stru).each_work_tops[tops_index].aic_freq;
    unsigned int cpu_freq = (*tops_details_stru).each_work_tops[tops_index].cpu_freq;
    unsigned int aic_vol = (*tops_details_stru).each_work_tops[tops_index].aic_vol;
    unsigned int cpu_vol = (*tops_details_stru).each_work_tops[tops_index].cpu_vol;
 
    DCMI_AICFRQ_TOPS_STRU aicfreq_table[] = {
        {1224, "20T"},
        {1000, "16T"},
        {500, "8T"},
        {250, "4T"}
    };
 
    int ret = NPU_ERR_CODE_INVALID_PARAMETER;
    size_t table_index;
    size_t table_size = sizeof(aicfreq_table) / sizeof(aicfreq_table[0]);
    for (table_index = 0; table_index < table_size; table_index++) {
        if (aicfreq_table[table_index].aic_freq == aic_freq) {
            double cpu_freq_ghz = cpu_freq / 1000.0;
            printf("\t%-30s : %s%s%.1f%s\n", "nve level", aicfreq_table[table_index].tops, "_", cpu_freq_ghz, "GHz");
            gplog(LOG_INFO, "aic_freq:%u, cpu_freq:%u, aic_vol:%u, cpu_vol:%u", aic_freq, cpu_freq, aic_vol, cpu_vol);
            return NPU_OK;
        }
    }
    return ret;
}

int show_tls_cert_period_info(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
    unsigned char buf;

    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b() ||
        dcmi_board_chip_type_is_ascend_310p() || dcmi_board_chip_type_is_ascend_950())) {
        gplog(LOG_ERR, "Only support ascend910A2, ascend910_93, ascend310P and ascend950.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if ((dcmi_board_type_is_310p_duo_chips() || dcmi_board_chip_type_is_ascend_910_93()) &&
        (operate_info->chip_id != 0)) {
        gplog(LOG_OP, "The Atlas 300I Duo card and 910_93 is only supported on chip 0.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

#ifndef NPU_SMI_V2
    ret = dcmi_get_user_config(operate_info->id, operate_info->chip_id, CERT_CONFIG_EXPIRED, 1, &buf);
#else
    ret = dcmiv2_get_device_user_config(operate_info->id, CERT_CONFIG_EXPIRED, 1, &buf);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Dcmi get period info failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    printf("\t%-30s : %u days\n", "Certificate validity period", buf);
    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int show_ascend_chip_hccs_avail_credit_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct dcmi_hccs_credit_info hccs_credit_info = {0};
 
    ret = dcmi_get_hccs_avail_credit_info(operate_info->id, operate_info->chip_id, &hccs_credit_info);
    if (ret != DCMI_OK) {
        return dcmi_to_npu_error_code(ret);
    }
 
    if (ret == NPU_ERR_CODE_NOT_SUPPORT_IN_CONTAINER) {
        gplog(LOG_ERR, "HCCS avail credit num has not updated for more than 48s.\n");
    #ifdef ORIENT_CH
        printf("XLink avail credit num has not updated for more than 48s.\n");
    #else
        printf("HCCS avail credit num has not updated for more than 48s.\n");
    #endif
        return ret;
    }
 
    printf_hccs_avail_credit_info(operate_info->id, &hccs_credit_info);
    return NPU_OK;
}

int show_ascend_chip_cpu_num_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned char cpu_num_config[DCMI_CPU_NUM_CFG_LEN] = {0};

    ret = dcmi_get_device_cpu_num_config(operate_info->id, operate_info->chip_id, cpu_num_config, DCMI_CPU_NUM_CFG_LEN);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_cpu_num_config failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    // 添加校验-v参数及解析成cpu_num_config, 海思接口顺序排列与实际习惯不符，对外顺序表现为AI、Ctrl、Data
    printf("\t%-30s : %u\n", "Current AI CPU number", cpu_num_config[2]);       // 海思入参2对应（AI）
    printf("\t%-30s : %u\n", "Current control CPU number", cpu_num_config[0]);  // 海思入参0对应（Ctrl）
    printf("\t%-30s : %u\n", "Current data CPU number", cpu_num_config[1]);     // 海思入参1对应（Data）

    return NPU_OK;
}

int show_ascend_chip_custom_op_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int flag = 0;
    char *custom_op[] = {"False", "True"};

    ret = dcmi_get_custom_op_status(operate_info->id, operate_info->chip_id, &flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_custom_op_status failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "Custom-op Status", custom_op[flag]);
    return NPU_OK;
}

int show_ascend_chip_custom_op_secverify_enable_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned char enable = 0;
    char *custom_op_secverify[] = {"False", "True"};
    enum dcmi_unit_type device_type = INVALID_TYPE;

    if (operate_info == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }
#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
#else
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    // chip为mcu时不涉及查询enable
    if (device_type != NPU_TYPE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_custom_op_secverify_enable(operate_info->id, operate_info->chip_id, &enable);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "failed to query custom op secverify enable. err is %d.\n", ret);
        return dcmi_to_npu_error_code(ret);
    }

    printf("\t%-30s : %s\n", "Custom-op-secverify-enable", custom_op_secverify[enable]);
    return ret;
}

int show_ascend_chip_custom_op_secverify_mode_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int mode;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (operate_info == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
#else
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    // chip为mcu时不涉及查询enable
    if (device_type != NPU_TYPE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
        
    ret = dcmi_get_custom_op_secverify_mode(operate_info->id, operate_info->chip_id, &mode);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "failed to query custom_op_secverify_mode. (card_id=%d, chip_id=%d, ret=%d).",
            operate_info->id, operate_info->chip_id, ret);
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %u\n", "Custom-op-secverify-mode", mode);
    return ret;
}

int npu_get_chip_memory_usages_info(int card_id, int chip_id, struct npu_chip_usages_info *usages_info)
{
    int ret = 0;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 ||
        chip_type == NPU_CHIP_950) {
        enum dcmi_unit_type device_type = INVALID_TYPE;
 
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_type(card_id, chip_id, &device_type);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d", ret);
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }
#else
        ret = dcmiv2_get_device_type(card_id, &device_type);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d", ret);
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }
#endif
        if (device_type == MCU_TYPE) {
            return NPU_ERR_CODE_NOT_SUPPORT;
        } else {
            return NPU_OK;
        }
    }
    ret = dcmi_get_device_memory_info_v3(card_id, chip_id, &usages_info->memory_size_info_M);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_memory_info_v3 failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    ret = npu_get_ddr_usage(card_id, chip_id, &usages_info->memory_usage);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_ddr_usage failed. err is %d", ret);
        return ret;
    }
    ret = npu_get_ddr_bandwidth_usage(card_id, chip_id, &usages_info->memory_bandwidth_usage);
    if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_ddr_bandwidth_usage failed. err is %d", ret);
        return ret;
    }
    return NPU_OK;
}

bool check_result_for_npu_get_hbm_info(enum npu_chip_type chip_type)
{
    return (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950);
}

int npu_get_util_info_simultaneously(int card_id, int chip_index, struct npu_chip_usages_info *usages_info)
{
    int ret;

    struct dcmi_multi_utilization_info util_info = {0};
    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = dcmiv2_get_device_multi_utilization_rate(card_id, &util_info);
    } else {
        ret = dcmi_get_device_multi_utilization_rate(card_id, chip_index, &util_info);
    }
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_npu_device_utilization_rate_v2 failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    usages_info->aicore_usage = util_info.aicore_util;
    usages_info->aicube_usage = util_info.aic_util;
    usages_info->aivector_usage = util_info.aiv_util;
    usages_info->npu_utilization_usage = util_info.npu_util;

    return NPU_OK;
}

int get_memory_info(int card_id, int chip_id, struct npu_chip_usages_info *usages_info, enum npu_chip_type chip_type)
{
    int ret;

    ret = npu_get_chip_memory_usages_info(card_id, chip_id, usages_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_chip_memory_usages_info. err is %d", ret);
        return ret;
    }

    if (check_result_for_npu_get_hbm_info(chip_type)) {
        ret = npu_get_hbm_info(card_id, chip_id, usages_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "npu_get_hbm_info. err is %d", ret);
            return ret;
        }
    }

    return NPU_OK;
}

int npu_get_chip_usages_info(int card_id, int chip_id, struct npu_chip_usages_info *usages_info)
{
    int ret = NPU_OK;
    enum npu_chip_type chip_type = npu_get_chip_type();

    ret = get_memory_info(card_id, chip_id, usages_info, chip_type);
    if (ret != NPU_OK) {
        return ret;
    }

    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 ||
        chip_type == NPU_CHIP_950) {
        ret = npu_get_util_info_simultaneously(card_id, chip_id, usages_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "npu_get_util_info_simultaneously failed. err is %d", ret);
            return ret;
        }
    } else {
        ret = npu_get_ai_core_usage(card_id, chip_id, &usages_info->aicore_usage);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "npu_get_ai_core_usage failed. err is %d", ret);
            return ret;
        }
    }

    ret = npu_get_ai_cpu_usage(card_id, chip_id, &usages_info->aicpu_usage);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_ai_cpu_usage failed. err is %d", ret);
        return ret;
    }

    ret = npu_get_ctrl_cpu_usage(card_id, chip_id, &usages_info->ctrlcpu_usage);
    if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_ctrl_cpu_usage failed. err is %d", ret);
        return ret;
    }

    ret = npu_get_dvpp_info_usage(card_id, chip_id, &usages_info->dvpp_ratio);
    if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_dvpp_info_usage failed. err is %d", ret);
        return ret;
    }

    ret = npu_get_vector_core_usage(card_id, chip_id, &usages_info->vectorcore_usage);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_vector_core_usage failed. err is %d", ret);
        return ret;
    }
    
    return ret;
}


int show_ascend_chip_usages_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct npu_chip_usages_info *device_info = NULL;

    // 200SOC 容器中计算组件不支持查询usages，后续计算组件功能OK后，需要放开
    if ((npu_board_type_is_soc() == TRUE) && (npu_is_in_docker() == TRUE)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    device_info = (struct npu_chip_usages_info *)malloc(sizeof(struct npu_chip_usages_info));
    if (device_info == NULL) {
        printf("Failed to alloc usages info memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(device_info, sizeof(struct npu_chip_usages_info), 0, sizeof(struct npu_chip_usages_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "memset_s failed. err is %d.", ret);
        free(device_info);
        device_info = NULL;
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }

    ret = npu_get_chip_usages_info(operate_info->id, operate_info->chip_id, device_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_chip_usages_info failed. err is %d.", ret);
        free(device_info);
        device_info = NULL;
        return ret;
    }

    print_chip_usages_info(device_info);
    free(device_info);
    device_info = NULL;

    return ret;
}

int show_ascend_op_timeout_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct ts_dcmi_ctrl_msg_body_t ts_msg = {0};
    ts_msg.msg_type = DCMI_TYPE_STARS_TASK_TIMEOUT_GET;
    unsigned int ts_msg_size = sizeof(struct ts_dcmi_ctrl_msg_body_t);

    if (npu_get_chip_type() != NPU_CHIP_910B && npu_get_chip_type() != NPU_CHIP_910_93) {
        gplog(LOG_ERR, "This device does not support set task op timeout info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_TS,
                               DCMI_TS_SUB_CMD_COMMON_MSG, &ts_msg, &ts_msg_size);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    print_op_timeout_info(&ts_msg);
    return ret;
}

void print_current_fault_info(struct dcmi_event *event_buf, int output_event_cnt)
{
    printf("\t%-30s : %d\n", "Fault Event Count", output_event_cnt);
    if (output_event_cnt <= 0) {
        printf("\t%-30s : %s\n", "Fault Event Information", "NA");
        return;
    }
    for (int i = 0; i < output_event_cnt; i++) {
        printf("\t%-30s : event id=0x%X, severity=%u, node type ex=%u, node id=%u, "
            "sub node type ex=%u, sub node id=%u\n", i ? "" : "Fault Event Information",
            event_buf[i].event_t.dms_event.event_id, event_buf[i].event_t.dms_event.severity,
            event_buf[i].event_t.dms_event.node_type_ex, event_buf[i].event_t.dms_event.node_id,
            event_buf[i].event_t.dms_event.sub_node_type_ex, event_buf[i].event_t.dms_event.sub_node_id);
    }
}

int show_ascend_chip_current_fault_event_info(struct npu_smi_operate_info *operate_info)
{
    int output_event_cnt = 0;
    int ret;
    struct dcmi_event *event_buf;

    event_buf = (struct dcmi_event *)calloc(MAX_EVENT_CNT, sizeof(struct dcmi_event));
    if  (event_buf == NULL) {
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        ret = dcmi_get_device_current_fault_event(operate_info->id, operate_info->chip_id,
            event_buf, MAX_EVENT_CNT, &output_event_cnt);
    } else {
        ret = dcmiv2_get_device_current_fault_event(operate_info->id, event_buf, MAX_EVENT_CNT, &output_event_cnt);
    }

    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_current_fault_event failed. err is %d", ret);
        free(event_buf);
        return dcmi_to_npu_error_code(ret);
    }
    print_current_fault_info(event_buf, output_event_cnt);
    free(event_buf);
    return NPU_OK;
}

STATIC int show_custom_op_secverify_cert_chip_info(struct cert_show_info *cert_info,
    struct npu_smi_operate_info *operate_info, unsigned int *show_info_size)
{
    int ret;
    enum dcmi_unit_type device_type = NPU_TYPE;

    if (operate_info == NULL) {
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    // chip为mcu时不涉及查询客户证书
    if (device_type != NPU_TYPE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    if (dcmi_check_run_in_docker() && (!dcmi_check_run_in_privileged_docker())) {
        gplog(LOG_OP, "This environment does not support get custom op secverify cert info.");
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (getgid() != 0 && !dcmi_is_in_root_group()) {
        return NPU_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (!(dcmi_board_chip_type_is_ascend_910_93() || dcmi_board_chip_type_is_ascend_910b()) ||
        (npu_check_npu_chip_id(operate_info->id, operate_info->chip_id) != NPU_OK)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_custom_op_secverify_cert(operate_info->id, operate_info->chip_id, (char *)cert_info, show_info_size);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get %s. err is %d.", operate_info->stype, ret);
        return dcmi_to_npu_error_code(ret);
    }

    return NPU_OK;
}

STATIC int print_custom_op_secverify_cert_info(int ret, struct cert_show_info *cert_info)
{
    if (ret == NPU_ERR_CODE_FILE_OPERATE_FAIL) {
        printf("The certificate does not exist.\n");
        ret = NPU_OK;
    } else if (ret == NPU_OK) {
        printf("\t%-30s : %s\n", "Subject", cert_info->subject);
        printf("\t%-30s : %s\n", "Issuer", cert_info->issuer);
        printf("\t%-30s : %s\n", "Start time", cert_info->start_time); // 返回的start_time中已包含换行符
        printf("\t%-30s : %s\n", "End time", cert_info->end_time); // 返回的end_time中已包含换行符
    }
    return ret;
}
 
int show_custom_op_secverify_cert_info(struct npu_smi_operate_info *operate_info)
{
    int ret;

    struct cert_show_info cert_info[CUSTOM_OP_SECVERIFY_CERT_NUM_MAX] = { 0 };
    unsigned int show_info_size = 0;
    int i = 0;

    ret = show_custom_op_secverify_cert_chip_info(cert_info, operate_info, &show_info_size);
    if (ret == NPU_ERR_CODE_FILE_OPERATE_FAIL) {
        printf("\tThe certificate does not exist.\n");
        ret = NPU_OK;
    }
    if (ret == NPU_ERR_CODE_OPER_NOT_PERMITTED) {
        printf("\tIt is not supported to query certificate information.\n");
        ret = NPU_OK;
    }
    for (i = 0; i * sizeof(struct cert_show_info) < show_info_size; i++) {
        printf("\tcustom_op_secverify_cert %d info\n", i + 1);
        ret = print_custom_op_secverify_cert_info(ret, &cert_info[i]);
    }

    return ret;
}