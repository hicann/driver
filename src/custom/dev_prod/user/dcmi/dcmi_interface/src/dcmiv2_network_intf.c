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
#include <stdint.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <math.h>
#include <unistd.h>

#include "securec.h"
#include "dsmi_network_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_common.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_permission_judge.h"
#include "dcmi_virtual_intf.h"
#include "dcmi_npu_link_intf.h"
#include "dcmi_network_intf.h"
#include "dcmi_basic_info_intf.h"
#include "dcmi_inner_info_get.h"
#include "dcmi_permission_judge.h"

int dcmiv2_get_netdev_pkt_stats_info(int dev_id, int port_id,
    struct dcmi_network_pkt_stats_info *network_pkt_stats_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    if (network_pkt_stats_info == NULL) {
        gplog(LOG_ERR, "network_pkt_stats_info is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_check_port_id_valid(port_id) == DCMI_ERR_CODE_INVALID_PARAMETER) {
        gplog(LOG_ERR, "port_id is invalid. Input port_id is %d.", port_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!dcmi_board_chip_type_is_ascend_910b() && !dcmi_board_chip_type_is_ascend_910_93()) {
        gplog(LOG_OP, "This device does not support get dcmiv2_get_netdev_pkt_stats_info info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (dcmi_board_chip_type_is_ascend_910b_300i_a2()) {
        gplog(LOG_OP, "This device does not support get dcmiv2_get_netdev_pkt_stats_info info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (ret=%d)", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        ret = dsmi_get_netdev_stat(dev_id, port_id, (struct ds_port_stat_info*)network_pkt_stats_info);
        if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_bandwidth failed. (ret=%d)", ret);
        }

        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_get_rdma_bandwidth_info(int dev_id, int port_id, unsigned int prof_time,
    struct dcmi_network_rdma_bandwidth_info *network_rdma_bandwidth_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    struct bandwidth_t rdma_bandwidth_info = {0};

    if (network_rdma_bandwidth_info == NULL) {
        gplog(LOG_ERR, "network_rdma_bandwidth_info is NULL.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_check_port_id_valid(port_id) == DCMI_ERR_CODE_INVALID_PARAMETER) {
        gplog(LOG_ERR, "port_id is invalid. Input portid is %d.", port_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (prof_time > MAX_TIME_INTERVAL || prof_time < MIN_TIME_INTERVAL) {
        gplog(LOG_ERR, "Input prof time is invalid, prof time need to be 100-10000ms.");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (!(dcmi_board_chip_type_is_ascend_910b() || dcmi_board_chip_type_is_ascend_910_93())) {
        gplog(LOG_OP, "This device does not support get rdma bandwidth info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    if (dcmi_board_chip_type_is_ascend_910b_300i_a2()) {
        gplog(LOG_OP, "This device does not support get rdma bandwidth info.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (ret=%d)", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        rdma_bandwidth_info.time_interval = prof_time;
        ret = dsmi_get_bandwidth(dev_id, port_id, &rdma_bandwidth_info);
        if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_bandwidth failed. (ret=%d)", ret);
        }
        network_rdma_bandwidth_info->tx_bandwidth = rdma_bandwidth_info.tx_bandwidth / NETWORK_RDMA_BYTE_TO_MBYTE;
        network_rdma_bandwidth_info->rx_bandwidth = rdma_bandwidth_info.rx_bandwidth / NETWORK_RDMA_BYTE_TO_MBYTE;

        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
}

int dcmiv2_exec_ping(int dev_id, int port_id, struct dcmi_ping_operate_info *dcmi_ping,
    struct dcmi_ping_reply_info *dcmi_reply)
{
    int ret;
    int card_id, device_id;
    struct dcmi_ping_reply_info_v2 *info = calloc(1, sizeof(struct dcmi_ping_reply_info_v2));
    if (info == NULL) {
        return DCMI_ERR_CODE_MEM_OPERATE_FAIL;
    }

    if (dcmi_reply == NULL || dcmi_ping == NULL) {
        gplog(LOG_ERR, "dcmi_reply is NULL.");
        free(info);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (dcmi_check_port_id_valid(port_id) == DCMI_ERR_CODE_INVALID_PARAMETER) {
        gplog(LOG_ERR, "port_id is invalid. Input portid is %d.", port_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmiv2_inner_get_card_id_device_id_from_logicid(&card_id, &device_id, dev_id);
    if (ret != DCMI_OK) {
        free(info);
        return ret;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        free(info);
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmi_get_ping_info_v2(card_id, device_id, port_id, dcmi_ping, info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_ping_info_v2 failed. (ret=%d)", ret);
        free(info);
        return ret;
    }

    memcpy_s(dcmi_reply, sizeof(struct dcmi_ping_reply_info), &info->info, sizeof(struct dcmi_ping_reply_info));
    free(info);
    return DCMI_OK;
}

int dcmiv2_exec_netdev_traceroute(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
                                  struct dcmi_traceroute_params traceroute_info, struct dcmi_traceroute_result *result)
{
    int err, index;
    enum dcmi_unit_type device_type = NPU_TYPE;

    err = dcmi_netdev_permission_judge(dev_id);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_permission_judge failed. (dev_id=%d; ret=%d)", dev_id, err);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    err = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (err != 0) {
        gplog(LOG_ERR, "Parameter is invalid. (dev_id=%d; ret=%d)", dev_id, err);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (result == NULL || result->result_nums < 0 || result->result_nums > TRACEROUTE_TTL_MAX) {
        gplog(LOG_ERR, "Parameter is invalid. (max_size=%u; traceout_result_nums=%u)",
              TRACEROUTE_TTL_MAX, result->result_nums);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
     
    err = dcmiv2_get_device_type(dev_id, &device_type);
    if (err != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (dev_id=%d; ret=%d).", dev_id, err);
        return err;
    }

    if (device_type == NPU_TYPE) {
        err = dsmi_exec_bond_traceroute(dev_id, netdev_name, netdev_name_len,
                                        (struct dsmi_traceroute_param *)&traceroute_info,
                                        (struct dsmi_traceroute_result *)result);
        if (err != DCMI_OK) {
            gplog(LOG_ERR, "call dsmi_exec_bond_traceroute failed. (dev_id=%d; ret=%d).", dev_id, err);
            return dcmi_convert_error_code(err);
        }
        gplog(LOG_OP, "Set traceroute success. (dev_id=%d)", dev_id);
    } else {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    // 由于device侧开方函数无法使用，在host侧对stdev值开方
    for (index = 0; index < result->result_nums ; index++) {
        result[index].result_data->stdev = sqrt(result[index].result_data->stdev);
    }

    return DCMI_OK;
}

int dcmiv2_get_pfc_duration_info(int dev_id, const char *netdev_name, unsigned int netdev_name_len,
    struct dcmi_netdev_pfc_duration_info *pfc_duration_info)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    if (dev_id < 0 || pfc_duration_info == NULL) {
        gplog(LOG_ERR, "param pfc_duration_info[%d] or dev_id[%d] is invalid.", pfc_duration_info == NULL, dev_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_validity_check failed. (ret=%d)", ret);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (ret=%d)", ret);
        return ret;
    }

    if (device_type == NPU_TYPE) {
        ret = dsmi_get_netdev_pfc_duration_info(dev_id, netdev_name, netdev_name_len,
            &pfc_duration_info->duration_info);
        if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_get_netdev_pfc_duration_info failed. (ret=%d)", ret);
        }
        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_clear_pfc_duration(int dev_id, const char *netdev_name, unsigned int netdev_name_len)
{
    int ret;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    ret = dcmi_netdev_permission_judge(dev_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_permission_judge failed. (ret=%d)", ret);
        return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
    }

    if (dev_id < 0) {
        gplog(LOG_ERR, "input param dev_id[%d] is invalid.", dev_id);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmi_netdev_validity_check(dev_id, netdev_name, netdev_name_len);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "call dcmi_netdev_validity_check failed. (ret=%d)", ret);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }
 
    if (!dcmi_mainboard_is_a900_a5_uboe(g_mainboard_info.mainboard_id)) {
        gplog(LOG_OP, "This device does not support set device gateway.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (ret=%d)", ret);
        return ret;
    }
    if (device_type == NPU_TYPE) {
        ret = dsmi_clear_netdev_pfc_duration_info(dev_id, netdev_name, netdev_name_len);
        if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
            gplog(LOG_ERR, "call dsmi_clear_netdev_pfc_duration_info failed. (ret=%d)", ret);
        }
        return dcmi_convert_error_code(ret);
    } else {
        gplog(LOG_ERR, "device_type %d is not supported.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    return DCMI_OK;
}

int dcmiv2_get_port_pkt_stats_info(int dev_id, struct dcmi_ub_port_info *ub_port_info,
                                   struct dcmi_port_pkt_stats_info *port_pkt_stats_info)
{
    int ret = 0;
    int err;
    enum dcmi_unit_type device_type = INVALID_TYPE;

    if (ub_port_info == NULL || port_pkt_stats_info == NULL) {
        gplog(LOG_ERR, "The parameter is invalid. ub_port_info[%d] or port_pkt_stats_info[%d] is NULL",
            ub_port_info == NULL, port_pkt_stats_info == NULL);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return ret;
    }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    int udie_id = ub_port_info->udie_id;
    int port_id = ub_port_info->port_id;
    struct ds_port_pkt_stats_info ds_port_pkt_stats_info = {0};

    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dsmi_get_port_pkt_stats_info(dev_id, udie_id, port_id, &ds_port_pkt_stats_info);
    if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dsmi_get_port_pkt_stats_info failed. err is %d.\n", ret);
        return dcmi_convert_error_code(ret);
    }

    memset_s(port_pkt_stats_info->reserved, sizeof(port_pkt_stats_info->reserved), 0,
                     sizeof(port_pkt_stats_info->reserved));
    err = memcpy_s(port_pkt_stats_info, sizeof(*port_pkt_stats_info),
                                &ds_port_pkt_stats_info, sizeof(ds_port_pkt_stats_info));
    if (err != EOK) {
        gplog(LOG_ERR, "Failed to copy port statistics info. Error code: %d.", err);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    return dcmi_convert_error_code(ret);
}

int dcmiv2_get_port_avail_credit_info(int dev_id, struct dcmi_ub_port_info *ub_port_info,
                                      struct dcmi_credit_info *port_avail_credit_info)
{
    int ret = 0;
    int i = 0;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    struct dsmi_credit_info dsmi_port_avail_credit_info = {0};
    int udie_id = 0;
    int port_id = 0;

    if (ub_port_info == NULL || port_avail_credit_info == NULL) {
        gplog(LOG_ERR, "The parameter is invalid. ub_port_info[%d] or port_avail_credit_info[%d] is NULL",
            ub_port_info ==  NULL, port_avail_credit_info == NULL);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    udie_id = ub_port_info->udie_id;
    port_id = ub_port_info->port_id;

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. err is %d.", ret);
        return ret;
    }

    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type %d is not support.", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dsmi_get_port_avail_credit_info(dev_id, udie_id, port_id, &dsmi_port_avail_credit_info);
    if ((ret != DSMI_OK) && (ret != DSMI_ERR_NOT_SUPPORT)) {
        gplog(LOG_ERR, "dsmi_get_port_avail_credit_info failed. err is %d.\n", ret);
        return dcmi_convert_error_code(ret);
    }

    port_avail_credit_info->link_alloc_port_share_credit =
        dsmi_port_avail_credit_info.link_alloc_port_share_credit;
    port_avail_credit_info->link_cur_used_port_share_credit =
        dsmi_port_avail_credit_info.link_cur_used_port_share_credit;

    for (i = 0; i < VL_NUM_PER_PORT; i++) {
        port_avail_credit_info->link_alloc_vl_pri_credit[i] =
            dsmi_port_avail_credit_info.link_alloc_vl_pri_credit[i];
        port_avail_credit_info->link_cur_used_pri_credit[i] =
            dsmi_port_avail_credit_info.link_cur_used_pri_credit[i];
    }

    return dcmi_convert_error_code(ret);
}

int dcmiv2_get_device_port_list_info(int dev_id, struct dcmi_port_list_info *port_list_info)
{
    int ret;
    unsigned int main_board_id;

    if (port_list_info == NULL) {
        gplog(LOG_ERR, "The parameter is invalid. port_list_info is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmiv2_get_mainboard_id(dev_id, &main_board_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to query 950 main board id of card. err is %d", ret);
        return ret;
    }

    ret = dcmi_get_device_port_list_info_inner(&main_board_id, port_list_info);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_port_list_info failed. err is %d", ret);
        return ret;
    }

    return DCMI_OK;
}

int dcmiv2_get_device_netdev_list_info(int dev_id, struct dcmi_netdev_list_info *netdev_list)
{
    int ret;
    unsigned int main_board_id;
    enum dcmi_unit_type device_type = INVALID_TYPE;
    struct dsmi_netdev_list_info dsmi_netdev_list = {0};

    if (dev_id < 0 || netdev_list == NULL) {
        gplog(LOG_ERR, "The parameter is invalid.(dev_id: %d or netdev_list%d is NULL)",
              dev_id, netdev_list == NULL);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    ret = dcmiv2_get_mainboard_id(dev_id, &main_board_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to get 950 main board id. (dev_id=%d, ret=%d)", dev_id, ret);
        return ret;
    }

    if (!dcmi_mainboard_is_a900_a5_uboe(main_board_id)) {
        gplog(LOG_OP, "This product does not support this api.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dcmiv2_get_device_type(dev_id, &device_type);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "dcmi_get_device_type failed. (err is %d).", ret);
        return ret;
    }

    if (device_type != NPU_TYPE) {
        gplog(LOG_ERR, "device_type is not support.(device_type: %d)", device_type);
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }

    ret = dsmi_get_device_netdev_list_info(dev_id, &dsmi_netdev_list);
    if (ret != DSMI_OK) {
        gplog(LOG_ERR, "dsmi_get_device_netdev_list_info failed. (err is %d).", ret);
        return dcmi_convert_error_code(ret);
    }

    ret = memcpy_s(netdev_list, sizeof(struct dcmi_netdev_list_info),
                   &dsmi_netdev_list, sizeof(struct dsmi_netdev_list_info));
    if (ret != EOK) {
        gplog(LOG_ERR, "Failed to copy netdev_list_info. (err is %d).", ret);
        return DCMI_ERR_CODE_SECURE_FUN_FAIL;
    }

    return DCMI_OK;
}