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
#include "npu_common.h"
#include "npu_info.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_i2c_operate.h"
#include "npu_info_print.h"
#include "npu_chip_info_ext.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_environment_judge.h"
#include "dcmi_mcu_intf.h"
#include "dcmi_product_judge.h"
#include "dcmi_basic_info_intf.h"

#define MEMORY_SIZE_32G        32
#define MEMORY_SIZE_64G        64
#define ENV_ATLAS_9000_OFFSET  2
#define ENV_DEFAULT_OFFSET     1
#define ERROR_ENV            (-1)
STATIC void generate_vnpu_id_info(char *vnpu_id_info, unsigned int vnpu_id_info_size, unsigned int vdev_id)
{
    int ret;

    if (vdev_id == 0xFFFFFFFF) {
        ret = sprintf_s(vnpu_id_info, vnpu_id_info_size, "%s", "NA");
    } else {
        ret = sprintf_s(vnpu_id_info, vnpu_id_info_size, "%-4u", vdev_id);
    }
    if (ret < EOK) {
        printf("generate_vnpu_id_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_vfg_info(char *vfg_info, unsigned int vfg_info_size, unsigned int vfg_id)
{
    int ret;

    if (vfg_id == 0xFFFFFFFF) {
        ret = sprintf_s(vfg_info, vfg_info_size, "%s", "NA");
    } else {
        ret = sprintf_s(vfg_info, vfg_info_size, "%-12u", vfg_id);
    }
    if (ret < EOK) {
        printf("generate_vfg_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_container_info(char *container_info, unsigned int container_info_size,
    unsigned long long container_id)
{
    int ret;

    if (container_id == 0xFFFFFFFFFFFFFFFF) {
        ret = sprintf_s(container_info, container_info_size, "%s", "NA");
    } else {
        ret = sprintf_s(container_info, container_info_size, "%012llx", container_id);
    }
    if (ret < EOK) {
        printf("generate_container_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_container_use_info(char *container_use_info, unsigned int container_use_info_size,
    unsigned int is_container_used)
{
    int ret;

    if (is_container_used == 0xFFFFFFFF) {
        ret = sprintf_s(container_use_info, container_use_info_size, "%s", "NA");
    } else {
        ret = sprintf_s(container_use_info, container_use_info_size, "%-2u", is_container_used);
    }
    if (ret < EOK) {
        printf("generate_container_use_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_template_info(char *template_info, unsigned int template_info_size, const char *name)
{
    int ret;

    if (name[0] == 0xFF) {
        ret = sprintf_s(template_info, template_info_size, "%s", "NA");
    } else {
        ret = sprintf_s(template_info, template_info_size, "%-15s", name);
    }
    if (ret < EOK) {
        printf("generate_template_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void printf_each_vnpu_info(struct npu_smi_operate_info *operate_info, unsigned int vdev_id[], int vdev_num)
{
    int ret, i;
    struct dcmi_vdev_query_stru vdev_query_stru = { 0 };
    unsigned int resource_len = sizeof(vdev_query_stru);
    char vnpu_id_info[5] = {0};
    char vfg_info[13] = {0};
    char container_info[13] = {0};
    char container_use_info[3] = {0};
    char template_info[16] = {0};

    printf("|  Vnpu ID  |  Vgroup ID     |  Container ID  |  Status  |  Template Name       |\n");
    for (i = 0; i < vdev_num; i++) {
        vdev_query_stru.vdev_id = vdev_id[i];

        ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_VDEV_MNG,
            DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE, &vdev_query_stru, &resource_len);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "get vdev resource failed. ret is %d, vdev_id=%u", ret, vdev_query_stru.vdev_id);
        }
        generate_vnpu_id_info(vnpu_id_info, sizeof(vnpu_id_info), vdev_query_stru.vdev_id);
        generate_vfg_info(vfg_info, sizeof(vfg_info), vdev_query_stru.query_info.base.vfg_id);
        generate_container_info(container_info, sizeof(container_info), vdev_query_stru.query_info.container_id);
        generate_container_use_info(container_use_info, sizeof(container_use_info),
            vdev_query_stru.query_info.is_container_used);
        generate_template_info(template_info, sizeof(template_info), (const char *)vdev_query_stru.query_info.name);

        printf("+-------------------------------------------------------------------------------+\n");
        printf("|  %-4u     |  %-12s  |  %-12s  |  %-2s      |  %-15s     |\n",
            vdev_query_stru.vdev_id, vfg_info, container_info, container_use_info, template_info);
    }
    printf("+-------------------------------------------------------------------------------+\n");
}

STATIC void generate_aicore_info(char *aic_info, unsigned int aic_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->computing.aic == -1.0) {
        ret = sprintf_s(aic_info, aic_info_size, "NA/NA");
    } else {
        ret = sprintf_s(aic_info, aic_info_size, "%u/%u", (unsigned int)soc_free_resource->computing.aic,
            (unsigned int)soc_total_resource->computing.aic);
    }
    if (ret < EOK) {
        printf("generate_aicore_info call sprintf_s failed. ret is %d\n", ret);
    }
}

void generate_mem_transform(unsigned long long* memory_info_total)
{
    if (*memory_info_total < MEMORY_SIZE_32G) {
        *memory_info_total = MEMORY_SIZE_32G;
    }
    if (*memory_info_total > MEMORY_SIZE_32G && *memory_info_total < MEMORY_SIZE_64G) {
        *memory_info_total = MEMORY_SIZE_64G;
    }
    return;
}

STATIC void generate_mem_info(char *memory_info, unsigned int memory_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;
    const unsigned int mb_to_gb_shift_num = 10;
    unsigned long long memory_info_free = 0;
    unsigned long long memory_info_total = 0;

    if (soc_free_resource->computing.memory_size == 0xFFFFFFFFFFFFFFFF) {
        ret = sprintf_s(memory_info, memory_info_size, "NA/NA");
    } else {
        memory_info_free = (soc_free_resource->computing.memory_size >> mb_to_gb_shift_num);
        memory_info_total = (soc_total_resource->computing.memory_size >> mb_to_gb_shift_num);

        if (npu_get_chip_type() == NPU_CHIP_910B) {
            generate_mem_transform(&memory_info_total);
        }

        ret = sprintf_s(memory_info, memory_info_size, "%llu/%llu",
            memory_info_free, memory_info_total);
    }
    if (ret < EOK) {
        printf("generate_mem_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_aicpu_info(char *aicpu_info, unsigned int aicpu_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->computing.device_aicpu == 0xFFFF) {
        ret = sprintf_s(aicpu_info, aicpu_info_size, "NA/NA");
    } else {
        ret = sprintf_s(aicpu_info, aicpu_info_size, "%hu/%hu",  soc_free_resource->computing.device_aicpu,
            soc_total_resource->computing.device_aicpu);
    }
    if (ret < EOK) {
        printf("generate_aicpu_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_vpc_info(char *vpc_info, unsigned int vpc_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->media.vpc == -1.0) {
        ret = sprintf_s(vpc_info, vpc_info_size, "NA/NA");
    } else {
        ret = sprintf_s(vpc_info, vpc_info_size, "%d/%d",   (int)soc_free_resource->media.vpc,
            (int)soc_total_resource->media.vpc);
    }

    if (ret < EOK) {
        printf("generate_vpc_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_venc_info(char *venc_info, unsigned int venc_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->media.venc == -1.0) {
        ret = sprintf_s(venc_info, venc_info_size, "NA/NA");
    } else {
        ret = sprintf_s(venc_info, venc_info_size, "%d/%d",   (int)soc_free_resource->media.venc,
            (int)soc_total_resource->media.venc);
    }
    if (ret < EOK) {
        printf("generate_venc_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_vdec_info(char *vdec_info, unsigned int vdec_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->media.vdec == -1.0) {
        ret = sprintf_s(vdec_info, vdec_info_size, "NA/NA");
    } else {
        ret = sprintf_s(vdec_info, vdec_info_size, "%d/%d",   (int)soc_free_resource->media.vdec,
            (int)soc_total_resource->media.vdec);
    }
    if (ret < EOK) {
        printf("generate_vdec_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_jpegd_info(char *jpegd_info, unsigned int jpegd_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->media.jpegd == -1.0) {
        ret = sprintf_s(jpegd_info, jpegd_info_size, "NA/NA");
    } else {
        ret = sprintf_s(jpegd_info, jpegd_info_size, "%d/%d",   (int)soc_free_resource->media.jpegd,
            (int)soc_total_resource->media.jpegd);
    }
    if (ret < EOK) {
        printf("generate_jpegd_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_jpege_info(char *jpege_info, unsigned int jpege_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->media.jpege == -1.0) {
        ret = sprintf_s(jpege_info, jpege_info_size, "NA/NA");
    } else {
        ret = sprintf_s(jpege_info, jpege_info_size, "%d/%d",   (int)soc_free_resource->media.jpege,
            (int)soc_total_resource->media.jpege);
    }
    if (ret < EOK) {
        printf("generate_jpegd_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void generate_pngd_info(char *pngd_info, unsigned int pngd_info_size,
    struct dcmi_soc_free_resource *soc_free_resource, struct dcmi_soc_total_resource *soc_total_resource)
{
    int ret;

    if (soc_free_resource->media.pngd == -1.0) {
        ret = sprintf_s(pngd_info, pngd_info_size, "NA/NA");
    } else {
        ret = sprintf_s(pngd_info, pngd_info_size, "%d/%d",   (int)soc_free_resource->media.pngd,
            (int)soc_total_resource->media.pngd);
    }
    if (ret < EOK) {
        printf("generate_pngd_info call sprintf_s failed. ret is %d\n", ret);
    }
}

STATIC void printf_vnpu_free_resoure_info(unsigned int vdev_num, struct dcmi_soc_free_resource *soc_free_resource,
    struct dcmi_soc_total_resource *soc_total_resource)
{
    char aic_info[32] = {0};
    char memory_info[32] = {0};
    char aicpu_info[32] = {0};
    char vpc_info[32] = {0};
    char venc_info[32] = {0};
    char vdec_info[32] = {0};
    char jpegd_info[32] = {0};
    char jpege_info[32] = {0};
    char pngd_info[32] = {0};

    generate_aicore_info(aic_info, sizeof(aic_info), soc_free_resource, soc_total_resource);
    generate_mem_info(memory_info, sizeof(memory_info), soc_free_resource, soc_total_resource);
    generate_aicpu_info(aicpu_info, sizeof(aicpu_info), soc_free_resource, soc_total_resource);
    generate_vpc_info(vpc_info, sizeof(vpc_info), soc_free_resource, soc_total_resource);
    generate_venc_info(venc_info, sizeof(venc_info), soc_free_resource, soc_total_resource);
    generate_vdec_info(vdec_info, sizeof(vdec_info), soc_free_resource, soc_total_resource);
    generate_jpegd_info(jpegd_info, sizeof(jpegd_info), soc_free_resource, soc_total_resource);
    generate_jpege_info(jpege_info, sizeof(jpege_info), soc_free_resource, soc_total_resource);
    generate_pngd_info(pngd_info, sizeof(pngd_info), soc_free_resource, soc_total_resource);

    printf("+-------------------------------------------------------------------------------+\n");
    printf("| NPU resource static info as follow:                                           |\n");
    printf("| Format:Free/Total                   NA: Currently, query is not supported.    |\n");
    printf("| AICORE    Memory    AICPU    VPC    VENC    VDEC    JPEGD    JPEGE    PNGD    |\n");
    printf("|            GB                                                                 |\n");
    printf("|===============================================================================|\n");
    printf("| %-9s %-9s %-8s %-6s %-7s %-7s %-8s %-8s %-8s|\n", aic_info, memory_info, aicpu_info, vpc_info, venc_info,
        vdec_info, jpegd_info, jpege_info, pngd_info);
    printf("+-------------------------------------------------------------------------------+\n");
    printf("| Total number of vnpu: %-2u                                                      |\n", vdev_num);
    printf("+-------------------------------------------------------------------------------+\n");
}

STATIC int show_ascend_vnpu_info_for_910B(struct npu_smi_operate_info *operate_info)
{
    struct dcmi_soc_total_resource soc_total_resource = { 0 };
    struct dcmi_soc_free_resource soc_free_resource = { 0 };
    int ret;

    unsigned int resource_len = sizeof(soc_total_resource);
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_VDEV_MNG,
        DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE, &soc_total_resource, &resource_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get total resource failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    resource_len = sizeof(soc_free_resource);
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_VDEV_MNG,
        DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE, &soc_free_resource, &resource_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get free resource failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    printf_vnpu_free_resoure_info(soc_total_resource.vdev_num, &soc_free_resource, &soc_total_resource);
    printf_each_vnpu_info(operate_info, soc_total_resource.vdev_id, soc_total_resource.vdev_num);

    return NPU_OK;
}

STATIC int show_ascend_vnpu_info_for_310P_910(struct npu_smi_operate_info *operate_info)
{
    struct dcmi_soc_total_resource soc_total_resource = { 0 };
    struct dcmi_soc_free_resource soc_free_resource = { 0 };
    int ret;

    unsigned int resource_len = sizeof(soc_total_resource);
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_VDEV_MNG,
        DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE, &soc_total_resource, &resource_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get total resource failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    resource_len = sizeof(soc_free_resource);
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_VDEV_MNG,
        DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE, &soc_free_resource, &resource_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "get free resource failed. ret is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    printf_vnpu_free_resoure_info(soc_total_resource.vdev_num, &soc_free_resource, &soc_total_resource);
    printf_each_vnpu_info(operate_info, soc_total_resource.vdev_id, soc_total_resource.vdev_num);

    return NPU_OK;
}

STATIC int check_vnpu_mode_and_workmode(struct npu_smi_operate_info *operate_info)
{
    int ret = NPU_OK;

    // 910B支持特权容器查询info-vnpu,但不支持查询切分模式,此处不对910B的容器判断切分模式
    if (!(npu_get_chip_type() == NPU_CHIP_910B && npu_is_in_docker())) {
        ret = check_vnpu_docker_mode();
        if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
            printf("The vnpu is not in docker mode, does not support querying %s.\n", operate_info->stype);
            return NPU_ERR_CODE_NOT_SUPPORT;
        } else if (ret != NPU_OK) {
            printf("Failed to get vnpu mode.\n");
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
    }

    ret = check_vnpu_workmode(operate_info);
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("NPU is working in SMP mode, does not support vnpu query.\n");
    } else if (ret != NPU_OK) {
        printf("Failed to get npu work mode.\n");
    }
    return ret;
}

STATIC int show_ascend_vnpu_info(struct npu_smi_operate_info *operate_info)
{
    enum dcmi_unit_type device_type = INVALID_TYPE;

    int ret = check_valid_info_operation_env(operate_info);
    if (ret != NPU_OK) {
        return NPU_OK;
    }

    ret = check_vnpu_mode_and_workmode(operate_info);
    // 910B支持特权容器查询info-vnpu,但不支持查询切分模式,此处不对910B的容器判断切分模式
    if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        return NPU_OK;
    } else if (ret != NPU_OK) {
        // check_vnpu_mode_and_workmode()函数中有异常情况的打印，此处直接返回
        return ret;
    }

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
    if (device_type != NPU_TYPE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    switch (npu_get_chip_type()) {
        case NPU_CHIP_310P:
        case NPU_CHIP_910:
            ret = show_ascend_vnpu_info_for_310P_910(operate_info);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "show_ascend_vnpu_info_for_310P_910 failed: err is %d ", ret);
            }
            break;
        case NPU_CHIP_910B:
            ret = show_ascend_vnpu_info_for_910B(operate_info);
            if (ret != NPU_OK) {
                gplog(LOG_ERR, "show_ascend_vnpu_info_for_910B failed: err is %d ", ret);
            }
            break;
        default:
            return NPU_ERR_CODE_NOT_SUPPORT;
    }
    return ret;
}

STATIC int show_ascend_vnpu_svm_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int svm_len = 8; // ulong类型8字符
    unsigned long int svm_data;
    enum dcmi_unit_type device_type = NPU_TYPE;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type != NPU_TYPE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_SVM,
        DCMI_READ_VNPU_SVM_SUB_CMD, (unsigned long int *)(&svm_data), &svm_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_info failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    printf("Asynchronous Copy Length: %luBytes\n", svm_data);
    return NPU_OK;
}

int show_key_manage_info(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret, cfg_status, run_status;
    char *boot_state[] = {"Enable", "Disable"};
    char *service_state[] = {"Running", "Stop"};
    char real_path[PATH_MAX + 1] = {0x00};

    ret = npu_get_key_manage_path(real_path, sizeof(real_path));
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "npu_get_key_manage_path failed. err is %d.", ret);
        return ret;
    }

    char *cfg_cmd_str[] = {real_path, "kmsagent", "cfgstatus", NULL};
    cfg_status = npu_safe_exec_syscmd_without_output(cfg_cmd_str);
    char *run_cmd_str[] = {real_path, "kmsagent", "runstatus", NULL};
    run_status = npu_safe_exec_syscmd_without_output(run_cmd_str);
    if (((cfg_status == 0) || (cfg_status == 1)) && ((run_status == 0) || (run_status == 1))) {
        printf("\t%-30s : %s\n", "service auto startup", boot_state[cfg_status]);
        printf("\t%-30s : %s\n", "service running status", service_state[run_status]);
    } else {
        gplog(LOG_ERR, "show_key_manage_info status is invaild. cfg %d run %d\n", cfg_status, run_status);
        printf("Failed to query \"%s\" result.\n", operate_info->stype);
    }

    return NPU_OK;
#else
    gplog(LOG_OP, "unsupport query %s.", operate_info->stype);
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int get_pid_name(int pid, char *name, int name_len)
{
    int ret;
    FILE *fp = NULL;
    char filename[DCMI_BUFFER_SIZE] = {0};
    char line[DCMI_BUFFER_SIZE] = {0};
    char cmpstr[] = "Name";
    size_t i;
    int cnt = 0;
    int flag = 0;
    ret = sprintf_s(filename, DCMI_BUFFER_SIZE, "/proc/%d/status", pid);
    if (ret <= 0) {
        gplog(LOG_ERR, "sprintf_s failed.");
        return NPU_ERR_CODE_SECURE_FUN_FAIL;
    }
    fp  = fopen(filename, "r");
    if (fp == NULL) {
        gplog(LOG_ERR, "open file %s failed errno(%d).", filename, errno);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
    while (!feof(fp)) {
        if (fgets(line, DCMI_BUFFER_SIZE, fp) == NULL) {
            break;
        }
        if (strstr(line, cmpstr) != NULL) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        for (i = strlen(cmpstr); i < strlen(line); i++) {
            if ((line[i] == '\t') || (line[i] == ':') || (line[i] == '\n')) {
                continue;
            }
            if (cnt >= name_len - 1) {
                break;
            }
            name[cnt++] = line[i];
        }
        name[(cnt) + 1] = '\0';
    }
    (void)fclose(fp);
    fp = NULL;
    return NPU_OK;
}

int show_ascend_chip_proc_mem_info(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
    struct dcmi_proc_mem_info proc_info[MAX_PROC_NUM_IN_DEVICE] = { { 0 } };
    int proc_nums = 0;
    char proc_name[MAX_PROCESS_NAME_LEN] = {0};
    int i;
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_resource_info(operate_info->id, operate_info->chip_id, proc_info, &proc_nums);
#else
    ret = dcmiv2_get_device_proc_mem_info(operate_info->id, proc_info, &proc_nums);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_resource_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    if (proc_nums == 0) {
        printf("\tNo process in device.\n");
    } else {
        for (i = 0; i < proc_nums; i++) {
            ret = get_pid_name(proc_info[i].proc_id, proc_name, MAX_PROCESS_NAME_LEN);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "get_pid_name failed. err is %d", ret);
                printf("\tGet pid name failed.\n");
            }
            printf("\tProcess id:%-7d Process name:%-17s Process memory(MB):%lu\n",
                proc_info[i].proc_id, proc_name, (unsigned long)(proc_info[i].proc_mem_usage /
                    BYTE_TO_KB_TRANS_VALUE / KB_TO_MB_TRANS_VALUE));
            ret = memset_s(proc_name, MAX_PROCESS_NAME_LEN, 0, MAX_PROCESS_NAME_LEN);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "memset_s failed. ret is %d.", ret);
                return NPU_ERR_CODE_MEM_OPERATE_FAIL;
            }
        }
    }
    return NPU_OK;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

STATIC int npu_get_ascend_chip_die_id(int card_id, int chip_id, struct npu_chip_info *chip_info)
{
    int ret;
    
    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = dcmi_get_device_die_v2(card_id, chip_id, DDIE, &chip_info->ddie_id);
    } else {
        ret = dcmi_get_device_die_v2(card_id, chip_id, VDIE, &chip_info->vdie_id);
    }
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_die_v2 failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    if (npu_get_chip_type() == NPU_CHIP_910) {
        ret = dcmi_get_device_die_v2(card_id, chip_id, NDIE, &chip_info->ndie_id);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "dcmi_get_device_die_v2 failed. err is %d", ret);
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }
    }
    return NPU_OK;
}

STATIC int npu_get_npu_firmware_version(int card_id, int chip_id, unsigned char *version_str, int len)
{
    int ret = NPU_ERR_CODE_NOT_SUPPORT;

    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_310) {
        ret = dcmi_get_device_component_static_version(card_id, chip_id, DCMI_COMPONENT_TYPE_XLOADER, version_str, len);
    } else if (chip_type == NPU_CHIP_310P || chip_type == NPU_CHIP_310B ||
        chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93) {
        ret = dcmi_get_device_component_static_version(card_id, chip_id, DCMI_COMPONENT_TYPE_HILINK, version_str, len);
    } else if (chip_type == NPU_CHIP_910) {
        ret = dcmi_get_device_component_static_version(card_id, chip_id, DCMI_COMPONENT_TYPE_IMU, version_str, len);
    } else if (chip_type == NPU_CHIP_950) {
#ifdef ENABLE_EQUIPMENT
        ret = dcmi_get_device_component_static_version(card_id, chip_id, DCMI_COMPONENT_TYPE_HILINK, version_str, len);
#else
        ret = dcmiv2_get_device_component_static_version(card_id, DCMI_COMPONENT_TYPE_HILINK, version_str, len);
#endif
    }

    return ret;
}

int npu_get_chip_firmware_version(int card_id, int chip_id, unsigned char *version_str, int len)
{
    int ret = 0;
    enum dcmi_unit_type device_type = INVALID_TYPE;

#if defined(NPU_SMI_V2) && !defined(ENABLE_EQUIPMENT)
    ret = dcmiv2_get_device_type(card_id, &device_type);
#else
    ret = dcmi_get_device_type(card_id, chip_id, &device_type);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    if (device_type == NPU_TYPE) {
        ret = npu_get_npu_firmware_version(card_id, chip_id, version_str, len);
    } else if (device_type == MCU_TYPE) {
        ret = dcmi_get_mcu_version(card_id, (char *)version_str, len);
    } else {
        ret = DCMI_ERR_CODE_NOT_SUPPORT;
    }

    bool check_result =
        ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT) && (ret != DCMI_ERR_CODE_OPER_NOT_PERMITTED));
    if (check_result) {
        gplog(LOG_ERR, "npu_get_chip_firmware_version failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    return NPU_OK;
}

STATIC int npu_get_chip_base_info_for_card_or_server(int card_id, int chip_id, enum dcmi_unit_type device_type,
    struct npu_chip_info *chip_info)
{
    int ret;
    // 获取不到固件版本时，设定默认值为NA
    ret = memcpy_s(chip_info->xloader_version, sizeof("NA"), "NA", sizeof("NA"));
    if (ret != EOK) {
        gplog(LOG_ERR, "memcpy_s failed. err is  %d.", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }
    bool check_result = (npu_board_type_is_card() == TRUE || npu_board_type_is_server() == TRUE ||
                        npu_board_type_is_station() == TRUE || dcmi_board_type_is_A500_A2() == TRUE ||
                        ((npu_board_type_is_soc() == TRUE) && (npu_get_chip_type() == NPU_CHIP_310P)));
    if (check_result) {
        ret = npu_get_chip_firmware_version(card_id, chip_id,
            (unsigned char *)chip_info->xloader_version, (int)sizeof(chip_info->xloader_version));
        if (ret != NPU_OK) {
            printf("Failed to get device firmware version information.\n");
            return ret;
        }

        ret = dcmi_get_device_pcie_info_v2(card_id, chip_id, &chip_info->device_pcie_info);
        if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
            printf("Failed to get device pcie information.\n");
            return NPU_ERR_CODE_DCMI_FUN_FAIL;
        }

        if (device_type == NPU_TYPE) {
            ret = dcmi_get_device_logic_id(&chip_info->chip_logic_id, card_id, chip_id);
            if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
                printf("Failed to get chip logic_id.\n");
                return NPU_ERR_CODE_DCMI_FUN_FAIL;
            }
        }
    }
    return NPU_OK;
}

int get_ascend_chip_board_info(struct npu_smi_operate_info *operate_info, struct npu_chip_info *chip_info,
    enum dcmi_unit_type *dev_type)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    chip_info->npu_id = operate_info->id;
    chip_info->chip_id = operate_info->chip_id;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return ret;
    }

    ret = npu_get_ascend_chip_die_id(operate_info->id, operate_info->chip_id, chip_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = npu_get_chip_base_info_for_card_or_server(operate_info->id, operate_info->chip_id, device_type, chip_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = dcmi_get_device_chip_info_v2(operate_info->id, operate_info->chip_id, &chip_info->chip_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        return ret;
    }

    ret = dcmi_get_device_board_info(operate_info->id, operate_info->chip_id, &chip_info->board_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        return ret;
    }

    ret = dcmi_get_device_chip_slot(operate_info->id, operate_info->chip_id, &chip_info->chip_pos_id);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        return ret;
    }

    *dev_type = device_type;
    ret = NPU_OK;
    return ret;
}

int dcmi_get_board_info_for_310b(unsigned int *module_id)
{
    int ret;
    char buff[2] = {0};
    unsigned char addr = DCMI_1911_BOARD_ID_I2C_ADDR;

    ret = dcmi_i2c_get_data(I2C9_DEV_NAME, addr, I2C_REG_ADDR, (unsigned char *)buff, sizeof(buff));
    if (ret != DCMI_OK) {
        *module_id = 0;
        gplog(LOG_ERR, "call dcmi_i2c_read_board_id failed. err is %d.", ret);
        return ret;
    }
    *module_id = (unsigned int)buff[1];
    return DCMI_OK;
}

int show_ascend_chip_board_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    unsigned int module_id = 0;

    struct npu_chip_info *chip_info = (struct npu_chip_info *)malloc(sizeof(struct npu_chip_info));
    if (chip_info == NULL) {
        gplog(LOG_ERR, "chip_info malloc failed.");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(chip_info, sizeof(struct npu_chip_info), 0, sizeof(struct npu_chip_info));
    if (ret != 0) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    if (dcmi_board_chip_type_is_ascend_310b()) {
        if (dcmi_get_board_info_for_310b(&module_id) != DCMI_OK) {
            gplog(LOG_ERR, "call dcmi_get_board_info_for_310b failed. err is %d.", ret);
        }
    }

    ret = get_ascend_chip_board_info(operate_info, chip_info, &device_type);
    if (ret == DCMI_OK) {
        print_chip_info_by_type(device_type, chip_info, module_id);
    }

    free(chip_info);
    return ret;
}

int show_ddr_ecc_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int ecc_count = 0;
    unsigned int double_bit_next_isolated_pages_cnt = 0;
    struct dcmi_ecc_info ddr_ecc_info = {0};
    struct dcmi_ecc_common_data ddr_ecc_common_info[MAX_RECORD_ECC_ADDR_COUNT] = {0};
    struct dcmi_ecc_record_type type;
    type.read_type = MULTI_ECC_INFO_READ;
    type.module_type = DCMI_DEVICE_TYPE_DDR;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        return NPU_OK;
    }
    ret = dcmi_get_device_ecc_info(operate_info->id, operate_info->chip_id, DCMI_DEVICE_TYPE_DDR, &ddr_ecc_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_ecc_info %s. (card_id=%d, ret=%d)",
            (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? "not support" : "failed", operate_info->id, ret);
        return dcmi_to_npu_error_code(ret);
    }

    if ((chip_type == NPU_CHIP_310P) && (!dcmi_board_type_is_soc())) {
        ret = dcmi_get_multi_ecc_record_info_v2(operate_info->id, operate_info->chip_id,
                                                type, &ecc_count, ddr_ecc_common_info);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_multi_ecc_record_info failed. (card_id=%d, ret=%d)", operate_info->id, ret);
            return dcmi_to_npu_error_code(ret);
        }
        double_bit_next_isolated_pages_cnt = ecc_count - ddr_ecc_info.double_bit_isolated_pages_cnt;
    }
    printf_ddr_ecc_info(&ddr_ecc_info, double_bit_next_isolated_pages_cnt);
    return NPU_OK;
}

STATIC int show_hbm_ecc_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    unsigned int ecc_count = 0;
    unsigned int single_bit_next_isolated_pages_cnt = 0;
    unsigned int double_bit_next_isolated_pages_cnt = 0;
    struct dcmi_ecc_info hbm_ecc_info = {0};
    struct dcmi_ecc_common_data hbm_ecc_common_info[MAX_RECORD_ECC_ADDR_COUNT] = {0};
    struct dcmi_ecc_record_type type;
    type.read_type = MULTI_ECC_INFO_READ;
    type.module_type = DCMI_DEVICE_TYPE_HBM;
    enum npu_chip_type chip_type = npu_get_chip_type();

    bool support_chip_type = (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
                              chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950);
    if (support_chip_type) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_ecc_info(operate_info->id, operate_info->chip_id, DCMI_DEVICE_TYPE_HBM, &hbm_ecc_info);
#else
        ret = dcmiv2_get_device_ecc_info(operate_info->id, DCMI_DEVICE_TYPE_HBM, &hbm_ecc_info);
#endif
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_ecc_info %s. ret is %d",
                (ret == DCMI_ERR_CODE_NOT_SUPPORT) ? "not support" : "failed", ret);
            return dcmi_to_npu_error_code(ret);
        }
#ifndef NPU_SMI_V2
        ret = dcmi_get_multi_ecc_record_info_v2(operate_info->id, operate_info->chip_id,
                                                type, &ecc_count, hbm_ecc_common_info);
#else
        ret = dcmiv2_get_multi_ecc_record_info(operate_info->id, type, &ecc_count, hbm_ecc_common_info);
#endif
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_multi_ecc_record_info failed. err is %d", ret);
            return dcmi_to_npu_error_code(ret);
        }
        printf_hbm_ecc_info(&hbm_ecc_info);
        if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
            double_bit_next_isolated_pages_cnt = ecc_count - hbm_ecc_info.double_bit_isolated_pages_cnt;
            printf("\t%-40s : %u\n", "HBM Single Bit Next-Isolated Pages Count",
                   single_bit_next_isolated_pages_cnt);
            printf("\t%-40s : %u\n", "HBM Double Bit Next-Isolated Pages Count",
                   double_bit_next_isolated_pages_cnt);
        }
    }
    return NPU_OK;
}

int show_ascend_chip_phyid_remap_info(struct npu_smi_operate_info *operate_info)
{
    int card_id, device_id, ret;
    unsigned int logic_id;
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_logicid_from_phyid(operate_info->phy_id, &logic_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_logicid_from_phyid failed. (ret=%d)", ret);
        return dcmi_to_npu_error_code(ret);
    }

    ret = dcmi_get_card_id_device_id_from_phyid(&card_id, &device_id, (unsigned int)operate_info->phy_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_card_id_device_id_from_phyid failed. (ret=%d)", ret);
        return dcmi_to_npu_error_code(ret);
    }

    printf("\t%-30s:%lu\n", "Chip Physical ID", operate_info->phy_id);
    printf("\t%-30s:%u\n",  "Chip Logic ID", logic_id);
    printf("\t%-30s:%d\n",  "NPU ID", card_id);
    printf("\t%-30s:%d\n",  "Chip ID", device_id);
#else
    ret = dcmiv2_get_dev_id_by_chip_phy_id(operate_info->phy_id, &logic_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_dev_id_by_chip_phy_id failed. (ret=%d)", ret);
        return dcmi_to_npu_error_code(ret);
    }
 
    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, logic_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_inner_get_card_id_device_id_from_logicid failed. (ret=%d)", ret);
        return dcmi_to_npu_error_code(ret);
    }
 
    printf("\t%-30s:%lu\n", "Chip Phy-ID", operate_info->phy_id);
    printf("\t%-30s:%d\n",  "NPU ID", logic_id);
    printf("\t%-30s:%d\n",  "Slot ID", g_board_details.card_info[logic_id].slot_id);
    printf("\t%-30s:%d\n",  "Chip ID", device_id);
#endif
    return NPU_OK;
}

int show_ascend_chip_volt_info(struct npu_smi_operate_info *operate_info)
{
    unsigned int volt;
 
#ifndef NPU_SMI_V2
    int ret = dcmi_get_device_voltage(operate_info->id, operate_info->chip_id, &volt);
#else
    int ret = dcmiv2_get_device_voltage(operate_info->id, &volt);
#endif
    if (ret == DCMI_OK) {
        // 0x7ffd~0x7fff代表未获取电压
        if (volt >= 0x7ffd && volt <= 0x7fff) {
            printf("\t%-30s : NA\n", "Voltage(V)");
        } else {
            // 读取的值为整数，电压值*0.01，才是真实电压值
            printf("\t%-30s : %.2f\n", "Voltage(V)", (float)volt * (float)(0.01));
        }
        return NPU_OK;
    }

    return dcmi_to_npu_error_code(ret);
}

int show_ascend_chip_temp_info(struct npu_smi_operate_info *operate_info)
{
    int ret, temp = 0;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    enum npu_chip_type chip_type = npu_get_chip_type();

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
#else
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
#endif

    bool check_supported_scene = ((npu_board_type_is_station() == TRUE) || (npu_get_chip_type() == NPU_CHIP_310B) ||
        ((npu_board_type_is_card() == TRUE) && (chip_type == NPU_CHIP_310P ||
        chip_type == NPU_CHIP_910)) || (chip_type == NPU_CHIP_910B) ||
        (chip_type == NPU_CHIP_910_93) || (chip_type == NPU_CHIP_950));
    if (check_supported_scene && device_type == MCU_TYPE) {
        char data_info[NPU_MAX_LENTH] = {0}; // 返回的数据
        int len = 0;                           // 返回当前数据的长度
        ret = dcmi_mcu_get_chip_temperature(operate_info->id, data_info, NPU_MAX_LENTH, &len);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "call dcmi_mcu_get_chip_temperature failed!  err is %d", ret);
            return dcmi_to_npu_error_code(ret);
        }
        print_chip_temperature_for_outband(operate_info->id, (const char *)data_info, len);
    } else {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_temperature(operate_info->id, operate_info->chip_id, &temp);
#else
        ret = dcmiv2_get_device_temperature(operate_info->id, &temp);
#endif
        print_chip_temp_info(ret, device_type, temp);
    }
    return dcmi_to_npu_error_code(ret);
}

int show_ascend_chip_power_info(struct npu_smi_operate_info *operate_info)
{
    int power = 0;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    int ret = 0;
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
#else
    ret = dcmiv2_get_device_type(operate_info->id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmiv2_get_device_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }
#endif
    if ((npu_get_chip_type() == NPU_CHIP_310P) && (device_type == NPU_TYPE)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_power_info(operate_info->id, operate_info->chip_id, &power);
#else
    ret = dcmiv2_get_device_power_info(operate_info->id, &power);
#endif
    if (ret == DCMI_OK) {
        if (device_type == NPU_TYPE) {
            if (npu_get_chip_type() == NPU_CHIP_310) {
                printf("\t%-30s : %.1f\n", "Rated Power Dissipation(W)", (float)power * (float)(NPU_DECIMAL_TRANS));
            } else {
                printf("\t%-30s : %.1f\n", "NPU Real-time Power(W)", (float)power * (float)(NPU_DECIMAL_TRANS));
            }
        } else {
            printf("\t%-30s : %.1f\n", "Power Dissipation(W)", (float)power * (float)(NPU_DECIMAL_TRANS));
        }
        return NPU_OK;
    }
    return dcmi_to_npu_error_code(ret);
}

int npu_get_chip_heath_state(struct npu_smi_operate_info *operate_info, char *health_state, int state_length)
{
    int ret;
    unsigned int health_index = 0;

    if (dcmi_board_chip_type_is_ascend_950()) {
#ifndef ENABLE_EQUIPMENT
        ret = dcmiv2_get_device_health(operate_info->id, &health_index);
#else
        ret = dcmi_get_device_health(operate_info->id, operate_info->chip_id, &health_index);
#endif
    } else {
        ret = dcmi_get_device_health(operate_info->id, operate_info->chip_id, &health_index);
    }

    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_health failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    return npu_common_get_health_state_str(health_index, health_state, state_length);
}

int show_ascend_chip_health_state(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char health_info[NPU_HEALTH_STATE_MAX_LEN] = {0};
    enum dcmi_unit_type device_type = INVALID_TYPE;
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return NPU_ERR_CODE_INNER_ERR;
    }

    ret = npu_get_chip_heath_state(operate_info, &health_info[0], sizeof(health_info));
    if (ret == NPU_OK) {
        if (dcmi_check_vnpu_in_docker_or_virtual(operate_info->id) && device_type == MCU_TYPE) {
            printf("\t%-30s : %s\n", "Health", "NA");
            return ret;
        }
        printf("\t%-30s : %s\n", "Health", &health_info[0]);
    }
    return ret;
}

STATIC bool is_unhealthy_state(const char *health_state)
{
    const char * const unhealthy_states[] = {"Warning", "Alarm", "Critical"};
    const int num_states = sizeof(unhealthy_states) / sizeof(unhealthy_states[0]);

    for (int i = 0; i < num_states; i++) {
        if (strncmp(health_state, unhealthy_states[i], strlen(unhealthy_states[i]) + 1) == 0) {
            return true;
        }
    }
    return false;
}

static int get_error_codes(struct npu_smi_operate_info *operate_info,
    struct npu_device_health_info *health_info)
{
    int ret;

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_errorcode_v2(operate_info->id, operate_info->chip_id,
        &health_info->error_code_count,
        &health_info->error_code[0], NPU_ERROR_CODE_MAX_NUM);
#else
    ret = dcmiv2_get_device_error_code_list(operate_info->id, &health_info->error_code_count,
        &health_info->error_code[0], NPU_ERROR_CODE_MAX_NUM);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_errorcode_v2 failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
    return NPU_OK;
}

static int handle_health_state(struct npu_device_health_info *health_info)
{
    if (health_info->error_code_count <= 0 && is_unhealthy_state(health_info->health_state)) {
        char initial_health_state[NPU_HEALTH_STATE_MAX_LEN] = {0};
        int ret = strncpy_s(initial_health_state, NPU_HEALTH_STATE_MAX_LEN, health_info->health_state,
            strlen(health_info->health_state));
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "Failed to record health_state %d", ret);
            return ret;
        }

        ret = strncpy_s(health_info->health_state, NPU_HEALTH_STATE_MAX_LEN, "OK", strlen("OK"));
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "Failed to set health_state to OK %d", ret);
            return ret;
        }
        // 在日志中记录初始的健康状态
        gplog(LOG_OP, "initial health status was %s but no error code captured, now set to OK\n", initial_health_state);
    }
    return NPU_OK;
}

static int get_health_state(struct npu_smi_operate_info *operate_info, struct npu_device_health_info *health_info)
{
    health_info->error_code_width = (int)sizeof(unsigned int);
    return npu_get_chip_heath_state(operate_info, health_info->health_state, NPU_HEALTH_STATE_MAX_LEN - 1);
}

int show_ascend_chip_health_info(struct npu_smi_operate_info *operate_info)
{
    struct npu_device_health_info *health_info;
    int ao_err_code_count = 0;
    int tmp_card_id, dev_id;
    unsigned int ao_err_code_list[DCMI_ERROR_CODE_MAX_COUNT] = {0};

    health_info = (struct npu_device_health_info *)malloc(sizeof(struct npu_device_health_info));
    if (health_info == NULL) {
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }
    int ret = memset_s(health_info, sizeof(struct npu_device_health_info), 0, sizeof(struct npu_device_health_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    ret = get_health_state(operate_info, health_info);
    if (ret != NPU_OK) {
        gplog(LOG_ERR, "get_chip_health_state failed.err is %d", ret);
        free(health_info);
        return ret;
    }

    ret = get_error_codes(operate_info, health_info);
    if (ret != NPU_OK) {
        free(health_info);
        return ret;
    }

    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&tmp_card_id, &dev_id, operate_info->id);
        if (ret != DCMI_OK) {
            return ret;
        }
        ret = dcmi_mcu_get_device_errorcode(tmp_card_id, &ao_err_code_count,
            ao_err_code_list, DCMI_ERROR_CODE_MAX_COUNT);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_mcu_get_device_errorcode failed. err is %d.", ret);
            free(health_info);
            return dcmi_to_npu_error_code(ret);
        }
    }

    ret = handle_health_state(health_info);
    if (ret != NPU_OK) {
        free(health_info);
        return ret;
    }

    if (npu_get_chip_type() == NPU_CHIP_950 && ao_err_code_count > 0) {
        print_diagnosis_info_ao(operate_info, health_info, ao_err_code_list, ao_err_code_count);
    } else {
        print_diagnosis_info(operate_info, health_info);
    }

    free(health_info);
    return ret;
}

STATIC int get_ascend_910_hbm_info(int card_id, int device_id, struct npu_memory_info *dev_mem_info)
{
    int ret;
    enum npu_chip_type chip_type = npu_get_chip_type();
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_hbm_info(card_id, device_id, &dev_mem_info->hbm_size_info_M);
#else
    ret = dcmiv2_get_device_hbm_info(card_id, &dev_mem_info->hbm_size_info_M);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_hbm_info failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

#ifndef NPU_SMI_V2
    ret = dcmi_get_device_frequency(card_id, device_id, DCMI_FREQ_HBM, &dev_mem_info->hbm_frequency_mhz);
#else
    ret = dcmiv2_get_device_frequency(card_id, DCMI_FREQ_HBM, &dev_mem_info->hbm_frequency_mhz);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_frequency failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (chip_type == NPU_CHIP_910B || chip_type == NPU_CHIP_910_93  || chip_type == NPU_CHIP_950) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_hbm_product_info(card_id, device_id, &dev_mem_info->hbm_product_info);
#else
        ret = dcmiv2_get_device_hbm_product_info(card_id, &dev_mem_info->hbm_product_info);
#endif
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_hbm_product_info failed. ret is %d.", ret);
            dev_mem_info->hbm_product_info.manufacturer_id = 0xFF;
        }
    }
    return NPU_OK;
}

int show_ascend_chip_memory_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct npu_memory_info *dev_mem_info;
    enum npu_chip_type chip_type = npu_get_chip_type();

    dev_mem_info = (struct npu_memory_info *)malloc(sizeof(struct npu_memory_info));
    if (dev_mem_info == NULL) {
        printf("Failed to malloc memory info memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(dev_mem_info, sizeof(struct npu_memory_info), 0, sizeof(struct npu_memory_info));
    if (ret != 0) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }

    if (!((chip_type == NPU_CHIP_910B) || (chip_type == NPU_CHIP_910_93) || (chip_type == NPU_CHIP_950))) {
        ret = dcmi_get_device_memory_info_v3(operate_info->id, operate_info->chip_id,
            &dev_mem_info->memory_size_info_M);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_memory_info_v3 failed. ret is %d.", ret);
            goto out;
        }

        ret = dcmi_get_device_frequency(operate_info->id, operate_info->chip_id, DCMI_FREQ_DDR,
            &dev_mem_info->memory_frequency_mhz);
        if (ret != DCMI_OK && ret != DCMI_ERR_CODE_NOT_SUPPORT) {
            gplog(LOG_ERR, "dcmi_get_device_frequency failed. ret is %d.", ret);
            goto out;
        }
    }

    if ((chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
         chip_type == NPU_CHIP_910_93 ||  chip_type == NPU_CHIP_950)) {
        ret = get_ascend_910_hbm_info(operate_info->id, operate_info->chip_id, dev_mem_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "get_ascend_910_hbm_info failed. ret is %d.", ret);
        }
    }

    if (ret == NPU_OK) {
        print_memory_info(operate_info->id, operate_info->chip_id, dev_mem_info);
    }

    free(dev_mem_info);
    dev_mem_info = NULL;
    return ret;
out:
    free(dev_mem_info);
    dev_mem_info = NULL;
    return dcmi_to_npu_error_code(ret);
}

int show_ascend_chip_flash_info(struct npu_smi_operate_info *operate_info)
{
    unsigned int i;
    int ret;
    struct npu_flash_info *flash_info;

    flash_info = (struct npu_flash_info *)malloc(sizeof(struct npu_flash_info));
    if (flash_info == NULL) {
        printf("Failed to alloc flash memory.\n");
        return NPU_ERR_CODE_MEM_OPERATE_FAIL;
    }

    ret = memset_s(flash_info, sizeof(struct npu_flash_info), 0, sizeof(struct npu_flash_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "memset_s failed. err is %d", ret);
    }
#ifndef NPU_SMI_V2
    ret = dcmi_get_device_flash_count(operate_info->id, operate_info->chip_id, &flash_info->flash_count);
#else
    ret = dcmiv2_get_device_flash_cnt(operate_info->id, &flash_info->flash_count);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_flash_count failed. err is %d", ret);
        free(flash_info);
        return dcmi_to_npu_error_code(ret);
    }

    for (i = 0; i < flash_info->flash_count; i++) {
#ifndef NPU_SMI_V2
        ret = dcmi_get_device_flash_info_v2(operate_info->id, operate_info->chip_id, i, &flash_info->flash_info[i]);
#else
        ret = dcmiv2_get_device_flash_info(operate_info->id, i, &flash_info->flash_info[i]);
#endif
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_flash_info_v2 failed. err is %d", ret);
            free(flash_info);
            return dcmi_to_npu_error_code(ret);
        }
    }

    print_flash_info(flash_info);
    free(flash_info);
    return ret;
}

int show_ascend_chip_ssh_enable_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int flag = 0;
    char *ssh_enable[] = {"False", "True"};

    // 310p双芯片卡为SMP模式，不支持查询单个芯片的ssh使能状态
    bool check_result = (dcmi_board_type_is_310p_duo_chips() && operate_info->is_chip);
    if (check_result) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_device_ssh_enable(operate_info->id, operate_info->chip_id, &flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_ssh_enable failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    printf("\t%-30s : %s\n", "SSH-Enable Status", ssh_enable[flag]);
    return NPU_OK;
}

STATIC int npu_get_chip_common_info_for_910(int card_id, int chip_id, struct npu_chip_common_info *chip_common_info)
{
#ifdef NPU_SMI_V2
    int ret = dcmiv2_get_device_utilization_rate(
        card_id, DCMI_UTILIZATION_RATE_HBM, &chip_common_info->hbm_usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    struct dcmi_chip_info_v2 chip_info = { { 0 } };
    ret = dcmiv2_get_device_chip_info(card_id, &chip_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_chip_info failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#else
    int ret = dcmi_get_device_utilization_rate(
        card_id, chip_id, DCMI_UTILIZATION_RATE_HBM, &chip_common_info->hbm_usage);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_utilization_rate failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    struct dcmi_chip_info chip_info = { { 0 } };
    ret = dcmi_get_device_chip_info(card_id, chip_id, &chip_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_chip_info failed. err is %d", ret);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }
#endif
    chip_common_info->aicore_count = chip_info.aicore_cnt;
    return NPU_OK;
}

bool check_result_for_dcmi_get_device_aicore_info(void)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_310P || chip_type == NPU_CHIP_310B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        return true;
    } else {
        return false;
    }
}

bool check_result_for_npu_get_chip_common_info_for_910(void)
{
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_910 || chip_type == NPU_CHIP_910B ||
        chip_type == NPU_CHIP_910_93 || chip_type == NPU_CHIP_950) {
        return true;
    } else {
        return false;
    }
}

static void try_get_aicore_info(int card_id, int chip_id, struct dcmi_aicore_info *aicore_info)
{
    int ret;
    if (!check_result_for_dcmi_get_device_aicore_info()) {
        return;
    }

#ifdef NPU_SMI_V2
    ret = dcmiv2_get_device_aicore_info(card_id, aicore_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmiv2_get_device_aicore_info failed. err is %d", ret);
    }
#else
    ret = dcmi_get_device_aicore_info(card_id, chip_id, aicore_info);
    if ((ret != DCMI_OK) && (ret != DCMI_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dcmi_get_device_aicore_info failed. err is %d", ret);
    }
#endif
}

static int npu_get_chip_common_info_npu_usage(int card_id, int chip_id, struct npu_chip_common_info *chip_common_info)
{
    int ret;

    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = npu_get_npu_utilization_usage_v2(card_id, &chip_common_info->npu_usage);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "npu_get_npu_utilization_usage_v2 failed. err is %d", ret);
        }
    } else {
        ret = npu_get_ai_core_usage(card_id, chip_id, &chip_common_info->npu_usage);
        if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
            gplog(LOG_ERR, "npu_get_ai_core_usage failed. err is %d", ret);
        }
    }

    return ret;
}

int npu_get_chip_common_info(int card_id, int chip_id, struct npu_chip_common_info *chip_common_info)
{
    int ret;

    ret = npu_get_ddr_usage(card_id, chip_id, &chip_common_info->memory_usage);
    if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_ddr_usage failed. err is %d", ret);
    }

    if (check_result_for_npu_get_chip_common_info_for_910()) {
        ret = npu_get_chip_common_info_for_910(card_id, chip_id, chip_common_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "npu_get_chip_common_info_for_910 failed. err is %d", ret);
        }
    }

    try_get_aicore_info(card_id, chip_id, &chip_common_info->aicore_info);

    ret = npu_get_chip_common_info_npu_usage(card_id, chip_id, chip_common_info);
    if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_chip_common_info_npu_usage failed. err is %d", ret);
    }

    ret = npu_get_device_temperature(card_id, chip_id, &chip_common_info->temp);
    if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_device_temperature failed. err is %d", ret);
    }

    ret = npu_get_device_power_info(card_id, chip_id, &chip_common_info->power);
    if ((ret != NPU_OK) && (ret != NPU_ERR_CODE_NOT_SUPPORT)) {
        gplog(LOG_ERR, "npu_get_device_power_info failed. err is %d", ret);
    }

    return ret;
}

int show_ascend_chip_ecc_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    // 200SOC 容器中计算组件不支持查询usages，后续计算组件功能OK后，需要放开
    if ((npu_board_type_is_soc() == TRUE) && (npu_is_in_docker() == TRUE)) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = show_ddr_ecc_info(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    ret = show_hbm_ecc_info(operate_info);

    return ret;
}

STATIC int show_ascend_chip_mcu_monitor_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int enable_flag = 0;
    char *mcu_monitor_enable[] = {"False", "True"};

    if (npu_board_type_is_station() != TRUE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_mcu_get_monitor_enable(operate_info->id, operate_info->chip_id, &enable_flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_mcu_get_monitor_enable failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "MCU Monitor Status", mcu_monitor_enable[enable_flag]);
    return NPU_OK;
}

STATIC int show_ascend_chip_boot_area_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int status = -1;

    if (npu_board_type_is_station() != TRUE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_device_boot_area(operate_info->id, operate_info->chip_id, &status);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_boot_area failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if ((status != 0) && (status != 1)) {
        return NPU_ERR_CODE_INNER_ERR;
    }

    printf("\t%-30s : %d\n", "curr uboot area is", status);
    return ret;
}

STATIC int show_ascend_chip_ip_info(struct npu_smi_operate_info *operate_info)
{
    struct dcmi_ip_addr ip_addr = { { { 0 } } };
    struct dcmi_ip_addr ip_mask = { { { 0 } } };

    int ret = dcmi_get_device_ip(operate_info->id, operate_info->chip_id, DCMI_VNIC_PORT, 0, &ip_addr, &ip_mask);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_ip_info failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    printf("\t%-30s : %u.%u.%u.%u\n", "ip", ip_addr.u_addr.ip4[0], ip_addr.u_addr.ip4[1], // 分别打印ip地址的0、1位
        ip_addr.u_addr.ip4[2], ip_addr.u_addr.ip4[3]); // 分别打印ip地址的2、3位
    printf("\t%-30s : %u.%u.%u.%u\n", "netmask", ip_mask.u_addr.ip4[0], ip_mask.u_addr.ip4[1], // 分别打印掩码的0、1位
        ip_mask.u_addr.ip4[2], ip_mask.u_addr.ip4[3]); // 分别打印netmask子网掩码的2、3位

    return NPU_OK;
}

int show_ascend_chip_pcie_error_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    struct dcmi_pcie_link_error_info pcie_err_count = {0};
    unsigned int resource_len = sizeof(struct dcmi_pcie_link_error_info);

    if (npu_get_chip_type() == NPU_CHIP_950) {
        ret = dcmiv2_get_device_info(operate_info->id, DCMI_MAIN_CMD_PCIE,
            DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO, &pcie_err_count, &resource_len);
    } else {
        ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_PCIE,
            DCMI_PCIE_SUB_CMD_PCIE_ERROR_INFO, &pcie_err_count, &resource_len);
    }
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_pcie_error_cnt failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    print_pcie_err_count(&pcie_err_count);
    return NPU_OK;
}

int show_ascend_chip_err_count_info(struct npu_smi_operate_info *operate_info)
{
#ifndef _WIN32
    int ret;
    struct dcmi_chip_pcie_err_rate pcie_err_code_info = {0};
    enum npu_chip_type chip_type = npu_get_chip_type();

    ret = check_support_get_err_count_info(operate_info);
    if (ret != NPU_OK) {
        return ret;
    }

    bool check_result =
        (npu_board_type_is_card() && ((chip_type == NPU_CHIP_310) || (chip_type == NPU_CHIP_310P)));
    if (check_result) {
        ret = dcmi_get_device_pcie_error_cnt(operate_info->id, operate_info->chip_id, &pcie_err_code_info);
        if (ret != DCMI_OK) {
            gplog(LOG_ERR, "dcmi_get_device_pcie_error_cnt failed. err is %d.", ret);
            return dcmi_to_npu_error_code(ret);
        }

        print_pcie_err_code(&pcie_err_code_info);
        return NPU_OK;
    }

    check_result = (((chip_type == NPU_CHIP_910B || is_a_x_910_93(operate_info->id)) &&
         !dcmi_check_chip_is_in_split_mode(operate_info->id, operate_info->chip_id)) ||
         (dcmi_mainboard_is_a900_a5_pcie(g_mainboard_info.mainboard_id) &&
         !dcmiv2_check_chip_is_in_split_mode(operate_info->id)));
    if (check_result) {
        return show_ascend_chip_pcie_error_info(operate_info);
    }

    return NPU_ERR_CODE_NOT_SUPPORT;
#else
    return NPU_ERR_CODE_NOT_SUPPORT;
#endif
}

int show_ascend_chip_device_share_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int flag = 0;
    char *share_enable[] = {"False", "True"};

    ret = dcmi_get_device_share_enable(operate_info->id, operate_info->chip_id, &flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_share_enable failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    printf("\t%-30s : %s\n", "Device-share Status", share_enable[flag]);
    return NPU_OK;
}

STATIC int show_ascend_chip_nve_level_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int flag = 0;
    enum npu_chip_type chip_type = npu_get_chip_type();
    if (chip_type == NPU_CHIP_310B) {
        ret = show_work_tops(operate_info);
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "show_work_tops failed. err is %d", ret);
        }
        return ret;
    }

    char *level[] = {"Low", "Middle", "High", "Full"};
    ret = dcmi_get_nve_level(operate_info->id, operate_info->chip_id, &flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_nve_level failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    flag = (flag == NVE_DEFAULT) ? NVE_FULL : flag;
    if ((flag >= NVE_LOW) && (flag <= NVE_FULL)) {
        printf("\t%-30s : %s\n", "nve level", level[flag]);
    } else {
        printf("\tfail to get %s\n", "nve level");
        gplog(LOG_ERR, "show_ascend_chip_nve_level_info failed to get nve-level.flag %d.\n", flag);
    }
    return NPU_OK;
}

STATIC int get_aicpu_current_number(int *aicpu_cnt)
{
    FILE *resultFile;
    int ret, begin_id, end_id;

    resultFile = fopen(AI_CPU_SET_PATH, "r");
    if (resultFile == NULL) {
        gplog(LOG_ERR, "open file %s failed errno(%d).", AI_CPU_SET_PATH, errno);
        return NPU_ERR_CODE_DCMI_FUN_FAIL;
    }

    ret = fscanf_s(resultFile, "%d-%d", &begin_id, &end_id);
    if (ret <= 0) {
        gplog(LOG_ERR, "call fscanf_s failed.%d", ret);
        fclose(resultFile);
        return NPU_ERR_CODE_INNER_ERR;
    }

    (void)fclose(resultFile);
    *aicpu_cnt = end_id - begin_id + 1;
    return NPU_OK;
}

STATIC int show_ascend_chip_ai_cpu_count_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int current_aicpu_count = 0;
    unsigned char config = 0;
    unsigned int aicpu_count;

    ret = dcmi_get_device_aicpu_count_info(operate_info->id, operate_info->chip_id, &config);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_aicpu_count_info failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    if (get_aicpu_current_number(&current_aicpu_count) == NPU_OK) {
        printf("\t%-30s : %d\n", "Current AI CPU number", current_aicpu_count);
        printf("\t%-30s : %d\n", "Current control CPU number", CPU_NUMBER_IN_CHIP - current_aicpu_count);
    }
    for (aicpu_count = 0; config > 0; config >>= 1) {
        aicpu_count += config & 1;
    }
    printf("\t%-30s : %u\n", "Number of AI CPUs set", aicpu_count);
    printf("\t%-30s : %u\n", "Number of control CPUs set", CPU_NUMBER_IN_CHIP - aicpu_count);
    return NPU_OK;
}

void print_sensor_info(int sensorID, const char* sensorType, union dcmi_sensor_info* sensor_info)
{
    // 910 hbm 温度返回的uchar类型的, 不是int
    if ((sensorID == DCMI_HBM_TEMP_ID) && dcmi_board_chip_type_is_ascend_910()) {
        printf("\t%-30s : %d\n", sensorType, (int)sensor_info->uchar);
        return;
    }
 
    if (sensor_info->iint != NPU_SENSORS_TEMP_INVALID && sensor_info->iint != NPU_SENSORS_TEMP_FAULT) {
        printf("\t%-30s : %d\n", sensorType, sensor_info->iint);
    } else {
        printf("\t%-30s : %s\n", sensorType, "NA");
    }
}

int show_ascend_chip_sensor_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    size_t i;
    union dcmi_sensor_info sensor_info;
    int sensorID[] = {DCMI_SOC_TEMP_ID, DCMI_FP_TEMP_ID, DCMI_N_DIE_TEMP_ID, DCMI_HBM_TEMP_ID};
    char* sensorType[] = {
        "Soc Max Temperature (C)", "SFP Temperature (C)", "NDIE Temperature (C)", "HBM Temperature (C)"
    };
    const size_t chip_310p_sensor_num = 1;
    size_t nums = sizeof(sensorID) / sizeof(sensorID[0]);

    if (npu_get_chip_type() == NPU_CHIP_310) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    nums = (npu_get_chip_type() == NPU_CHIP_310P) ? chip_310p_sensor_num : nums;

    for (i = 0; i < nums; i++) {
        ret = memset_s(&sensor_info, sizeof(union dcmi_sensor_info), 0, sizeof(union dcmi_sensor_info));
        if (ret != NPU_OK) {
            gplog(LOG_ERR, "memset_s failed. err is %d", ret);
        }

#ifndef NPU_SMI_V2
        ret = dcmi_get_device_sensor_info(operate_info->id, operate_info->chip_id, sensorID[i], &sensor_info);
#else
        ret = dcmiv2_get_device_sensor_info(operate_info->id, sensorID[i], &sensor_info);
#endif
        if (ret == DCMI_OK) {
            print_sensor_info(sensorID[i], sensorType[i], &sensor_info);
        }

        if ((ret == DCMI_ERR_CODE_DEVICE_NOT_EXIST) && (sensorID[i] == DCMI_FP_TEMP_ID)) {
            if (dcmi_board_chip_type_is_ascend_950()) {
                printf("\t%-30s : %s\n", sensorType[i], "NA");  // A5 Pod上没有光模块但要保持回显一致
            }
        }
    }

    return dcmi_to_npu_error_code(ret);
}

int show_ascend_chip_sys_time_info(struct npu_smi_operate_info *operate_info)
{
    unsigned int time_tmp = 0;
    time_t time;

    if (npu_get_chip_type() == NPU_CHIP_310) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
#ifndef NPU_SMI_V2
    int ret = dcmi_get_device_system_time(operate_info->id, operate_info->chip_id, &time_tmp);
#else
    int ret = dcmiv2_get_device_system_time(operate_info->id, &time_tmp);
#endif
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_system_time failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    time = (time_t)time_tmp;
    const struct tm *ptr = localtime(&time);
    if (ptr == NULL) {
        gplog(LOG_ERR, "ptr is NULL.");
        return NPU_ERR_CODE_INNER_ERR;
    }

    printf("\t%-30s : %s", "System Time(local)", asctime(ptr));
    return NPU_OK;
}

int show_chip_product_type(struct npu_smi_operate_info *operate_info)
{
    int ret;
    char product_type_str[NPU_PRODUCT_TYPE_STR_MAX] = {0};

    if (operate_info->id == NPU_DEFAULT_VALUE) {
        printf("Must input parameter of card id.\n");
        return NPU_ERR_CODE_INVALID_PARAMETER;
    }

    ret  = dcmi_get_product_type(operate_info->id, operate_info->chip_id, product_type_str, sizeof(product_type_str));
    if (ret == DCMI_OK) {
        printf("\t%-30s : %s\n", "Product Type", product_type_str);
        return NPU_OK;
    }

    return dcmi_to_npu_error_code(ret);
}

int show_ascend_chip_default_proc(struct npu_smi_operate_info *operate_info)
{
    printf("Must input parameter of type.\n");
    return NPU_ERR_CODE_INVALID_PARAMETER;
}
int show_ascend_chip_p2p_mem_cfg_status(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int flag = 0;
    char *p2p_mem_cfg[] = {"Disable", "Enable"};
    enum dcmi_unit_type device_type = NPU_TYPE;

    // 2P卡为SMP模式，不支持-c参数查询单个芯片的bar空间拷贝开关
    bool check_result = (dcmi_board_type_is_310p_duo_chips() && operate_info->is_chip);
    if (check_result) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    // 2P卡不支持从片查询，npu-smi侧适配从片和主片保持一致
    check_result = (dcmi_board_type_is_310p_duo_chips() && device_type == NPU_TYPE);
    if (check_result) {
        operate_info->chip_id = 0;
    }

    ret = dcmi_get_user_config(operate_info->id, operate_info->chip_id, "p2p_mem_cfg",
        P2P_MEM_CFG_SIZE, (unsigned char *)&flag);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_user_config failed. err is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
    if (flag == BAR_CFG_SIZE) {
        printf("\t%-30s : %s\n", "p2p-mem-cfg Status", p2p_mem_cfg[BAR_CFG_ON]);
    } else {
        printf("\t%-30s : %s\n", "p2p-mem-cfg Status", p2p_mem_cfg[BAR_CFG_OFF]);
    }
    return NPU_OK;
}

int show_ascend_chip_mac_addr_info(struct npu_smi_operate_info *operate_info)
{
    int ret, mac_id;
    char mac_addr[MAC_ADDR_LEN] = {0};
    int mac_count = 0;
    enum dcmi_unit_type device_type = NPU_TYPE;

    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (device_type == NPU_TYPE) {
        if (dcmi_board_chip_type_is_ascend_310b()) {
            ret = dcmi_get_device_mac_count(operate_info->id, operate_info->chip_id, &mac_count);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "dcmi_get_device_mac_count failed. ret is %d.", ret);
                return dcmi_to_npu_error_code(ret);
            }
        } else {
            gplog(LOG_ERR, "This device does not support set mac-addr.");
            return NPU_ERR_CODE_NOT_SUPPORT;
        }
        for (mac_id = 0; mac_id < mac_count; mac_id++) {
            ret = dcmi_get_device_mac(operate_info->id, operate_info->chip_id, mac_id, (char *)&mac_addr, MAC_ADDR_LEN);
            if (ret != DCMI_OK) {
                gplog(LOG_ERR, "dcmi_get_device_type failed. mac_id is %d;ret is %d.", mac_id, ret);
                return dcmi_to_npu_error_code(ret);
            }
            printf("\tmac-addr %-21d : %02x:%02x:%02x:%02x:%02x:%02x\n", mac_id,
                mac_addr[MAC_ADDR_OFFSET0], mac_addr[MAC_ADDR_OFFSET1], mac_addr[MAC_ADDR_OFFSET2],
                mac_addr[MAC_ADDR_OFFSET3], mac_addr[MAC_ADDR_OFFSET4], mac_addr[MAC_ADDR_OFFSET5]);
        }
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    return NPU_OK;
}

STATIC int show_ascend_chip_mcu_bootsel_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int boot_sel = 0;
    char *mcu_boot_sel[] = {"M.2 SSD", "eMMC"};

    if (dcmi_board_chip_type_is_ascend_310b() != TRUE) {
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_mcu_get_boot_sel(operate_info->id, operate_info->chip_id, &boot_sel);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_mcu_get_boot_sel failed. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }

    if (boot_sel < SSD || boot_sel >= BOOT_SEL_MODE_MAX) {
        gplog(LOG_ERR, "boot_select %d is invalid", boot_sel);
        return NPU_ERR_CODE_INNER_ERR;
    }
    printf("\t%-30s : %s\n", "Boot Select", mcu_boot_sel[boot_sel - SSD]);
    return NPU_OK;
}

int get_env_offset_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    int id = operate_info->id;
    unsigned int main_board_id;
    ret = dcmi_get_mainboard_id(id, 0, &main_board_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to query main board id of card. err is %d", ret);
        return dcmi_to_npu_error_code(ret);
    }
    switch (main_board_id) {
        // 天工
        case Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID1:
        case Atlas_9000_A3_SuperPoD_MAIN_BOARD_ID2:
            ret = ENV_ATLAS_9000_OFFSET;
            break;
        default:
            ret = ENV_DEFAULT_OFFSET;
    }
    return ret;
}

STATIC int dcmi_get_device_info_failed(int main_cmd, int sub_cmd, int ret)
{
    gplog(LOG_ERR, "Call dcmi_get_device_info failed. ret is %d. main_cmd is %d, sub_cmd is %d.",
        ret, main_cmd, sub_cmd);
    return dcmi_to_npu_error_code(ret);
}

int query_chip_hccs_lane_info(struct npu_smi_operate_info *operate_info, struct dcmi_hccs_statues *hccs_status,
    struct dcmi_hccs_lane_info *lane_info, struct dcmi_hccs_statistic_info_u64 *statistic_info)
{
    int ret;
    unsigned int hccs_status_size = sizeof(struct dcmi_hccs_statues);
    unsigned int hccs_lane_size = sizeof(struct dcmi_hccs_lane_info);
    unsigned int hccs_statistic_size = sizeof(struct dcmi_hccs_statistic_info_u64);

    // dcmi get hccs statistic info.
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_HCCS,
        DCMI_HCCS_CMD_GET_STATISTIC_INFO_U64, statistic_info, &hccs_statistic_size);
    if (ret != DCMI_OK) {
        return dcmi_get_device_info_failed(DCMI_MAIN_CMD_HCCS, DCMI_HCCS_CMD_GET_STATISTIC_INFO_U64, ret);
    }

    if (npu_get_chip_type() == NPU_CHIP_310P) {
        return DCMI_OK;
    }
    // dcmi get hccs status info.
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_HCCS,
        DCMI_HCCS_CMD_GET_STATUS, hccs_status, &hccs_status_size);
    if (ret != DCMI_OK) {
        return dcmi_get_device_info_failed(DCMI_MAIN_CMD_HCCS, DCMI_HCCS_CMD_GET_STATUS, ret);
    }
    // dcmi get hccs lane info.
    ret = dcmi_get_device_info(operate_info->id, operate_info->chip_id, DCMI_MAIN_CMD_HCCS,
        DCMI_HCCS_CMD_GET_LANE_INFO, lane_info, &hccs_lane_size);
    if (ret != DCMI_OK) {
        return dcmi_get_device_info_failed(DCMI_MAIN_CMD_HCCS, DCMI_HCCS_CMD_GET_LANE_INFO, ret);
    }
    return DCMI_OK;
}

STATIC int show_ascend_chip_hccs_lane_info(struct npu_smi_operate_info *operate_info)
{
    int ret;
    enum dcmi_unit_type device_type = NPU_TYPE;
    struct dcmi_hccs_statues hccs_status = {0};
    struct dcmi_hccs_lane_info lane_info = {0};
    struct dcmi_hccs_statistic_info_u64 statistic_info = {0};

    if (npu_get_chip_type() != NPU_CHIP_910B && npu_get_chip_type() != NPU_CHIP_910_93 &&
        (!dcmi_board_type_is_a300i_duo())) {
        gplog(LOG_ERR, "This device does not support get hccs lane info.");
        return NPU_ERR_CODE_NOT_SUPPORT;
    }
    ret = dcmi_get_device_type(operate_info->id, operate_info->chip_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Call dcmi_get_device_type failed. ret is %d.", ret);
        return dcmi_to_npu_error_code(ret);
    }
    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return NPU_ERR_CODE_NOT_SUPPORT;
    }

    ret = query_chip_hccs_lane_info(operate_info, &hccs_status, &lane_info, &statistic_info);
    if (ret != DCMI_OK) {
        return ret;
    }

    ret = print_ascend_chip_hccs_lane_info(operate_info, &hccs_status, &lane_info, &statistic_info);
    if (ret != DCMI_OK) {
        return ret;
    }
    return NPU_OK;
}

static struct npu_operate_table_item g_query_chip_info_table[] = {
    {BOARD, show_ascend_chip_board_info},
    {VOLT, show_ascend_chip_volt_info},
    {TEMP, show_ascend_chip_temp_info},
    {POWER, show_ascend_chip_power_info},
    {HEALTH, show_ascend_chip_health_info},
    {MEMORY, show_ascend_chip_memory_info},
    {FLASH, show_ascend_chip_flash_info},
    {SSH_ENABLE, show_ascend_chip_ssh_enable_info},
    {USAGES, show_ascend_chip_usages_info},
    {ECC, show_ascend_chip_ecc_info},
    {MCU_MONITOR, show_ascend_chip_mcu_monitor_info},
    {BOOT_AREA, show_ascend_chip_boot_area_info},
    {IP, show_ascend_chip_ip_info},
    {ERR_COUNT, show_ascend_chip_err_count_info},
    {DEVICE_SHARE, show_ascend_chip_device_share_info},
    {NVE_LEVEL, show_ascend_chip_nve_level_info},
    {AICPU_CONF, show_ascend_chip_ai_cpu_count_info},
    {SENSORS, show_ascend_chip_sensor_info},
    {SYS_TIME, show_ascend_chip_sys_time_info},
    {PRODUCT_TYPE, show_chip_product_type},
    {VNPU_INFO, show_ascend_vnpu_info},
    {VNPU_SVM_INFO, show_ascend_vnpu_svm_info},
    {KEY_MANAGE, show_key_manage_info},
    {TLS_CSR_GET, show_tls_csr_info},
    {TLS_CERT, show_tls_cert_info},
    {TLS_CERT_PERIOD, show_tls_cert_period_info},
    {ROOTKEY, show_tls_rootkey_info},
    {PROC_MEM, show_ascend_chip_proc_mem_info},
    {CPU_NUM_CFG, show_ascend_chip_cpu_num_info},
    {PHYID_REMAP, show_ascend_chip_phyid_remap_info},
    {NPU_DEFAULT_VALUE, show_ascend_chip_default_proc},
    {P2P_MEM_CFG, show_ascend_chip_p2p_mem_cfg_status},
    {MAC_ADDR, show_ascend_chip_mac_addr_info},
    {BOOT_SEL, show_ascend_chip_mcu_bootsel_info},
    {HCCS, show_ascend_chip_hccs_lane_info},
    {SPOD_INFO, show_ascend_chip_spod_info},
    {SIO_INFO, show_ascend_chip_sio_info},
    {HCCS_AVAIL_CREDIT, show_ascend_chip_hccs_avail_credit_info},
    {CUSTOM_OP, show_ascend_chip_custom_op_info},
    {OP_TIMEOUT, show_ascend_op_timeout_info},
    {CURRENT_FAULT_EVENT, show_ascend_chip_current_fault_event_info},
};

int query_chip_info(struct npu_smi_operate_info *operate_info)
{
    int ret = NPU_ERR_CODE_NOT_SUPPORT;
    size_t table_index;
    bool check_result = false;

    if (operate_info->type != PHYID_REMAP) {
        if ((operate_info->id == NPU_INVALID_VALUE) || (operate_info->chip_id == NPU_INVALID_VALUE)) {
            printf("This command must input card id and chip id.\n");
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    } else {
        if (operate_info->phy_id == NPU_INVALID_VALUE) {
            printf("This command must input phy id. Input parameter of -p\n");
            return NPU_ERR_CODE_INVALID_PARAMETER;
        }
    }

    size_t table_size = sizeof(g_query_chip_info_table) / sizeof(g_query_chip_info_table[0]);
    for (table_index = 0; table_index < table_size; table_index++) {
        if (operate_info->type == g_query_chip_info_table[table_index].fun_index) {
            ret = g_query_chip_info_table[table_index].proc_func(operate_info);
            break;
        }
    }

    if (table_index == table_size) {
        printf("Error parameter in querying chip info, type: \"%s\".\n", operate_info->stype);
        ret = NPU_ERR_CODE_INVALID_PARAMETER;
    }

    check_result = ((ret != NPU_OK) && (operate_info->type != NPU_DEFAULT_VALUE) && (ret != NPU_ERR_CODE_NOT_SUPPORT) &&
                    (ret != NPU_ERR_CODE_INVALID_PARAMETER) && (ret != -EPERM));
    if (check_result) {
        printf("Failed to query \"%s\" result.\n", operate_info->stype);
    } else if (ret == NPU_ERR_CODE_NOT_SUPPORT) {
        printf("This device does not support querying %s.\n", operate_info->stype);
        ret = NPU_OK;
    }

    return ret;
}
