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
#include <errno.h>
#include <arpa/inet.h>
#include "securec.h"
#include "dsmi_common_interface.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_interface_api.h"
#include "dcmi_product_judge.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_environment_judge.h"
#include "dcmi_log.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_ubping_intf.h"


int dcmiv2_exec_ub_ping(int dev_id, struct dcmi_ub_ping_operate *ping_args,
    struct ub_ping_result *ping_result)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.\n", ret);
        return ret;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (device_type == NPU_TYPE) {
        ret = dsmi_get_device_ub_ping_info(dev_id, ping_args, ping_result);
        if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_device_ub_ping_info failed. err is %d.", ret);
        }
        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

STATIC int dcmiv2_ubping_mesh_param_check(const struct dcmi_ubping_mesh_params *ubping_mesh)
{
    int i = 0, ret = 0;
    struct in6_addr addr;

    if (ubping_mesh == NULL) {
        gplog(LOG_ERR, "ubping_mesh is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (ubping_mesh->pair_num <= 0 || ubping_mesh->pair_num > DCMI_UBPING_MESH_MAX_NUM) {
        gplog(LOG_ERR, "invalid pair_num:%d, valid range [1, %d].", ubping_mesh->pair_num, DCMI_UBPING_MESH_MAX_NUM);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (ubping_mesh->pkt_size < 0 || ubping_mesh->pkt_size > UBPING_MESH_MAX_PKT_SIZE) {
        gplog(LOG_ERR, "invalid pkt_size:%d, valid range [0, %d].",
            ubping_mesh->pkt_size, UBPING_MESH_MAX_PKT_SIZE);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (ubping_mesh->pkt_send_num < UBPING_MESH_MIN_PKT_NUM || ubping_mesh->pkt_send_num > UBPING_MESH_MAX_PKT_NUM) {
        gplog(LOG_ERR, "invalid pkt_send_num:%d, valid range [%d, %d].",
            ubping_mesh->pkt_send_num, UBPING_MESH_MIN_PKT_NUM, UBPING_MESH_MAX_PKT_NUM);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (ubping_mesh->pkt_interval < 0 || ubping_mesh->pkt_interval > UBPING_MESH_MAX_INTERVAL) {
        gplog(LOG_ERR, "invalid pkt_interval:%d, valid range [0, %d].",
            ubping_mesh->pkt_interval, UBPING_MESH_MAX_INTERVAL);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (ubping_mesh->task_interval < UBPING_MESH_MIN_TASK_INTERVAL ||
        ubping_mesh->task_interval > UBPING_MESH_MAX_TASK_INTERVAL) {
        gplog(LOG_ERR, "invalid task_interval:%d, valid range [%d, %d].",
            ubping_mesh->task_interval, UBPING_MESH_MIN_TASK_INTERVAL, UBPING_MESH_MAX_TASK_INTERVAL);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    /* 检查EID地址有效性 */
    for (i = 0; i < ubping_mesh->pair_num; i++) {
        if (ubping_mesh->ub_pair_info[i].src_eid[0] == '\0' || ubping_mesh->ub_pair_info[i].dst_eid[0] == '\0') {
            gplog(LOG_ERR, "pair[%d] has empty address.", i);
            return DCMI_ERR_CODE_INVALID_PARAMETER;
        }
        ret = inet_pton(AF_INET6, ubping_mesh->ub_pair_info[i].src_eid, &addr);
        if (ret <= 0) {
            gplog(LOG_ERR, "IPv6 convert failed. (ip=%s; ret=%d)", ubping_mesh->ub_pair_info[i].src_eid, ret);
            return DCMI_ERR_CODE_INVALID_PARAMETER;
        }
        ret = inet_pton(AF_INET6, ubping_mesh->ub_pair_info[i].dst_eid, &addr);
        if (ret <= 0) {
            gplog(LOG_ERR, "IPv6 convert failed. (ip=%s; ret=%d)", ubping_mesh->ub_pair_info[i].dst_eid, ret);
            return DCMI_ERR_CODE_INVALID_PARAMETER;
        }
    }

    return DCMI_OK;
}

STATIC int dcmiv2_ubping_mesh_environment_check(int dev_id)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api. (dev_id=%d)", dev_id);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
    if (!dcmi_board_chip_type_is_ascend_950_pod() &&
        !dcmi_board_chip_type_is_ascend_950_server() &&
        !dcmi_board_chip_type_is_ascend_950_a_x() &&
        !dcmi_board_chip_type_is_ascend_950_card()) {
        gplog(LOG_OP, "This product does not support this api. (dev_id=%d)", dev_id);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (!(dcmi_is_in_phy_machine_root() || dcmi_is_in_vm_root() || dcmi_is_in_privileged_docker_root())) {
        gplog(LOG_OP, "Operation not permitted, only root user on physical or virtual machine"
            " or privileged docker can call this api. (dev_id=%d)", dev_id);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed.(dev_id=%d, ret=%d)", dev_id, ret);
        return ret;
    }
    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type %d is not support. (dev_id=%d)", device_type, dev_id);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_start_ubping_mesh(int dev_id, struct dcmi_ubping_mesh_params *ubping_mesh)
{
    int ret;
    struct ubping_mesh_operate dsmi_operate = {0};

    ret = dcmiv2_ubping_mesh_environment_check(dev_id);
    if (ret != DCMI_OK) {
        return ret;
    }
    ret = dcmiv2_ubping_mesh_param_check(ubping_mesh);
    if (ret != DCMI_OK) {
        return ret;
    }
    dsmi_operate.pair_num = ubping_mesh->pair_num;
    dsmi_operate.pkt_size = ubping_mesh->pkt_size;
    dsmi_operate.pkt_send_num = ubping_mesh->pkt_send_num;
    dsmi_operate.pkt_interval = ubping_mesh->pkt_interval;
    dsmi_operate.task_interval = ubping_mesh->task_interval;
    ret = memcpy_s(dsmi_operate.ub_pair_info, sizeof(dsmi_operate.ub_pair_info), ubping_mesh->ub_pair_info,
                   sizeof(ubping_mesh->ub_pair_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "memcpy_s ub_pair_info failed. (dev_id=%d, ret=%d)", dev_id, ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    /* 调用dsmi接口 */
    ret = dsmi_start_ubping_mesh_proc(dev_id, &dsmi_operate);
    if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
        gplog(LOG_ERR, "call dsmi_start_ubping_mesh failed. (dev_id=%d, ret=%d)", dev_id, ret);
    }

    return dcmi_convert_error_code(ret);
}

int dcmiv2_get_ubping_mesh_info(int dev_id, struct dcmi_ubping_mesh_info *ubping_mesh_reply)
{
    int ret = 0, retval = 0;
    struct ubping_mesh_info dsmi_info = {0};

    if (ubping_mesh_reply == NULL) {
        gplog(LOG_ERR, "ubping_mesh_reply is NULL. (dev_id=%d)", dev_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    ret = dcmiv2_ubping_mesh_environment_check(dev_id);
    if (ret != DCMI_OK) {
        return ret;
    }
    ret = dsmi_get_ubping_mesh_info_proc(dev_id, &dsmi_info);
    if (ret != DSMI_OK && ret != DSMI_ERR_NOT_SUPPORT) {
        gplog(LOG_ERR, "call dsmi_get_ubping_mesh_info_proc failed.(dev_id=%d, ret=%d)", dev_id, ret);
        return dcmi_convert_error_code(ret);
    }
    ubping_mesh_reply->result_num = dsmi_info.result_num;
    retval = memcpy_s(ubping_mesh_reply->ub_ping_result, sizeof(ubping_mesh_reply->ub_ping_result),
        dsmi_info.ub_ping_result, sizeof(dsmi_info.ub_ping_result));
    if (retval != EOK) {
        gplog(LOG_ERR, "memcpy_s ub_ping_result failed. (dev_id=%d, ret=%d)", dev_id, retval);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    return dcmi_convert_error_code(ret);
}

int dcmiv2_get_ubping_mesh_state(int dev_id, unsigned int *state)
{
    int ret;
    unsigned int dsmi_state = 0;

    if (state == NULL) {
        gplog(LOG_ERR, "state is NULL. (dev_id=%d)", dev_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
    ret = dcmiv2_ubping_mesh_environment_check(dev_id);
    if (ret != DCMI_OK) {
        return ret;
    }
    ret = dsmi_get_ubping_mesh_state_proc(dev_id, &dsmi_state);
    if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
        gplog(LOG_ERR, "call dsmi_get_ubping_mesh_state failed. (dev_id=%d, ret=%d)", dev_id, ret);
        return dcmi_convert_error_code(ret);
    }

    *state = dsmi_state;
    return dcmi_convert_error_code(ret);
}

int dcmiv2_stop_ubping_mesh(int dev_id)
{
    int ret;

    ret = dcmiv2_ubping_mesh_environment_check(dev_id);
    if (ret != DCMI_OK) {
        return ret;
    }
    ret = dsmi_stop_ubping_mesh_proc(dev_id);
    if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
        gplog(LOG_ERR, "call dsmi_stop_ubping_mesh failed. (dev_id=%d, ret=%d)", dev_id, ret);
    }

    return dcmi_convert_error_code(ret);
}