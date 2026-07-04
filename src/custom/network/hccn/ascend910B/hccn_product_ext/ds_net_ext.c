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
#include <pwd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include "securec.h"
#include "user_log.h"
#include "ascend_hal.h"
#include "ds_net.h"
#include "hccn_dfx_struct.h"
#include "tool_cdr.h"
#include "ds_net_ext.h"
#include "tool.h"
#include "hccn_comm.h"
#include "dsmi_common_interface.h"
#include "ds_net_tool_ext.h"

int dsmi_start_roce_perftest(int device_id, struct perftest_cmd_info cmd_info[], unsigned int in_len, unsigned int *out)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    char out_s[PERFTEST_FLAG_LEN] = {0};
    unsigned int size_in;
    unsigned int size_out;

    if (device_id > DS_MAX_LOGIC_ID || device_id < 0) {
        roce_err("device id:%d is invalid! expect [0]-[%d]", device_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (cmd_info == NULL) {
        roce_err("ptr is NULL!");
        return -EINVAL;
    }
    if (out == NULL) {
        roce_err("Invalid input param. (dev_id=%d)", device_id);
        return -EINVAL;
    }

    size_in = sizeof(struct perftest_cmd_info) * in_len;
    size_out = PERFTEST_FLAG_LEN;
    DSMI_SET_TRANS_DATA(trans_data, DS_START_PERFTEST, (char*)cmd_info, size_in, (char*)out_s, &size_out);

    ret = dsmi_network_transmission_channel(device_id, &trans_data);
    if (ret) {
        roce_err("Dsmi start roce perftest fail. (ret=%d; dev_id=%d)", ret, device_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi start roce perftest error. (result=%d; dev_id=%d)", trans_data.result, device_id);
        return trans_data.result;
    }
    *out = strtol(out_s, NULL, NUMBER_BASE);
    DSMI_PRINT_INFO("Dsmi start roce perftest end. (out=%u)", *out);
    return trans_data.result;
}

int dsmi_get_roce_perftest_status(int device_id, unsigned int is_client, struct perftest_curr_stat *perftest_curr)
{
    int ret;
    char is_client_s[PERFTEST_FLAG_LEN] = {0};
    struct ds_trans_data trans_data = {0};
    char status_s[PERFTEST_FLAG_LEN] = {0};
    unsigned int size_in;
    unsigned int size_out;

    if (device_id > DS_MAX_LOGIC_ID || device_id < 0) {
        roce_err("device id:%d is invalid! expect [0]-[%d]", device_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (perftest_curr  == NULL) {
        roce_err("Invalid input param. (dev_id=%d)", device_id);
        return -EINVAL;
    }
    ret = sprintf_s(is_client_s, PERFTEST_FLAG_LEN, "%u", is_client);
    if (ret <= 0) {
        roce_err("Sprintf is_client err. (ret=%d)", ret);
        return -ENOMEM;
    }
    size_in = sizeof(unsigned int);
    size_out = sizeof(struct perftest_curr_stat);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_PERFTEST_STATUS, (char*)is_client_s, size_in, (char*)perftest_curr,
                        &size_out);
    ret = dsmi_network_transmission_channel(device_id, &trans_data);
    if (ret) {
        roce_err("Dsmi network transmission get roce perftest status fail. (ret=%d; dev_id=%d)", ret, device_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get roce perftest status error. (result=%d; dev_id=%d)", trans_data.result, device_id);
        return trans_data.result;
    }
    return trans_data.result;
}

int dsmi_get_roce_perftest_report(int device_id, unsigned int is_client, char *report, unsigned int len)
{
    int ret;
    char is_client_s[PERFTEST_FLAG_LEN] = {0};
    struct ds_trans_data trans_data = {0};
    unsigned int size_in;

    if (device_id > DS_MAX_LOGIC_ID || device_id < 0) {
        roce_err("device id:%d is invalid! expect [0]-[%d]", device_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (report == NULL) {
        roce_err("report is NULL!");
        return -EINVAL;
    }
    if (len == 0) {
        roce_err("Len is invalid. (len=%u)", len);
        return -EINVAL;
    }
    ret = sprintf_s(is_client_s, PERFTEST_FLAG_LEN, "%u", is_client);
    if (ret <= 0) {
        roce_err("Sprintf is_client err. (ret=%d)", ret);
        return -ENOMEM;
    }

    size_in = sizeof(unsigned int);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_PERFTEST_REPORT, (char*)is_client_s, size_in, report, &len);

    ret = dsmi_network_transmission_channel(device_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get roce perftest report fail. (ret=%d; dev_id=%d)", ret, device_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get roce perftest report error. (result=%d; dev_id=%d)", trans_data.result, device_id);
        return trans_data.result;
    }

    return trans_data.result;
}

int dsmi_stop_roce_perftest(int device_id, unsigned int is_client)
{
    int ret;
    char is_client_s[PERFTEST_FLAG_LEN] = {0};
    struct ds_trans_data trans_data = {0};
    unsigned int size_in;
    unsigned int size_out;

    if (device_id > DS_MAX_LOGIC_ID || device_id < 0) {
        roce_err("device id:%d is invalid! expect [0]-[%d]", device_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    ret = sprintf_s(is_client_s, PERFTEST_FLAG_LEN, "%u", is_client);
    if (ret <= 0) {
        roce_err("sprintf is_client err ret %d", ret);
        return -ENOMEM;
    }

    size_in = sizeof(unsigned int);
    size_out = 0;
    DSMI_SET_TRANS_DATA(trans_data, DS_STOP_PERFTEST, (char*)is_client_s, size_in, NULL, &size_out);

    ret = dsmi_network_transmission_channel(device_id, &trans_data);
    if (ret) {
        roce_err("dsmi dsmi_stop_roce_perftest fail ret[%d] dev_id[%d]", ret, device_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi dsmi_stop_roce_perftests error result[%d] dev_id[%d]", trans_data.result, device_id);
        return trans_data.result;
    }

    return trans_data.result;
}

int dsmi_reset_roce_perftest(int device_id, char *report)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (device_id > DS_MAX_LOGIC_ID || device_id < 0) {
        roce_err("Device id is invalid. (device_id=%d)", device_id);
        return -EINVAL;
    }
    if (report == NULL) {
        roce_err("Report is NULL!");
        return -EINVAL;
    }

    size_out = MAX_REPORT_LEN;
    DSMI_SET_TRANS_DATA(trans_data, DS_RESET_PERFTEST, NULL, 0, report, &size_out);

    ret = dsmi_network_transmission_channel(device_id, &trans_data);
    if (ret) {
        roce_err("Dsmi reset roce perftest failed. (ret=%d; dev_id=%d)", ret, device_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi reset roce perftest error. (result=%d; dev_id=%d)", trans_data.result, device_id);
        return trans_data.result;
    }

    return trans_data.result;
}

int dsmi_get_eth_speed(int logic_id, int *speed)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (speed == NULL) {
        roce_err("speed is null, logic_id[%d]", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(int);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_ETH_SPEED, NULL, 0, (char*)speed, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi_get_eth_speed fail ret[%d] logic_id[%d]", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi_get_eth_speed error result[%d]", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_eth_duplex(int logic_id, int *duplex)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (duplex == NULL) {
        roce_err("duplex is null, logic_id[%d]", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(int);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_ETH_DUPLEX, NULL, 0, (char*)duplex, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi_get_eth_duplex fail ret[%d] logic_id[%d]", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi_get_eth_duplex error result[%d]", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_ssu_reg(int logic_id, unsigned int *reg, unsigned int reg_size)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (reg == NULL) {
        roce_err("reg is null, logic_id[%d]", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(unsigned int) * reg_size;
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_ETH_SSU_REG, NULL, 0, (char*)reg, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi_get_ssu_reg fail ret[%d] logic_id[%d]", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi_get_ssu_reg error result[%d]", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_serdes_ctle_info(int logic_id, struct hilink_ctle_data *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (!info) {
        roce_err("input is null. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(struct hilink_ctle_data) * MAX_SERDES_NUM;
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_SERDES_CTLE_INFO, NULL, 0, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_serdes_dfe_info(int logic_id, struct hilink_dfe_data *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (!info) {
        roce_err("input is null. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(struct hilink_dfe_data) * MAX_SERDES_NUM;
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_SERDES_DFE_INFO, NULL, 0, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_serdes_ffe_info(int logic_id, struct hilink_ffe_data *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (!info) {
        roce_err("input is null. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(struct hilink_ffe_data) * MAX_SERDES_NUM;
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_SERDES_FFE_INFO, NULL, 0, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_fec_info(int logic_id, int *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return -EINVAL;
    }
    if (!info) {
        roce_err("input is null. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(int);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_FEC_INFO, NULL, 0, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_set_fec_info(int logic_id, char mode)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size = 0;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_SET_FEC_INFO, &mode, sizeof(mode), NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi set fec enabled failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi set fec mode failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_pcs_info(int logic_id, struct hilink_port_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return (-EINVAL);
    }
    if (!info) {
        roce_err("input is null. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(struct hilink_port_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_PCS_INFO, NULL, 0, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_adapt_status_info(int logic_id, int port_id, struct hilink_adapt_status_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }

    size_out = sizeof(struct hilink_adapt_status_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_ADAPT_STATUS_INFO, (char *)(&port_id), sizeof(port_id),
        (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("Dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_trig_query_cdr_info(int logic_id, struct trig_get_cdr_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    size_out = sizeof(struct trig_get_cdr_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_TRIG_GET_CDR_INFO, (char *)info, size_out, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
    if (trans_data.result) {
        roce_err("Dsmi trans res error. (result=%d)", trans_data.result);
        return trans_data.result;
    }
    return trans_data.result;
}

int dsmi_query_mac_lane_cdr_info(int logic_id, struct query_mac_lane_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    size_out = sizeof(struct query_mac_lane_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_MAC_LANE_INFO, NULL, 0, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_cdr_reg_info(int logic_id, struct query_cdr_reg_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    size_out = sizeof(struct query_cdr_reg_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_CDR_REG_INFO, (char *)info, sizeof(struct query_cdr_reg_info),
        (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_send_data(int logic_id, int port_id, struct send_data_info *data_info)
{
    int ret;
    struct ds_trans_data trans_data;

    if ((port_id < 0) || (port_id > MAX_PORT_ID)) {
        roce_err("Port id check failed. (port_id = %d)", port_id);
        return -EINVAL;
    }

    DSMI_SET_TRANS_DATA(trans_data, data_info->cmd, data_info->in_buf, data_info->size_in, data_info->out_buf,
        &data_info->size_out);

    if (data_info->size_out != 0) {
        trans_data.pid = getpid();
    }

    roce_info("Dsmi send cmd (opcode=%d; cmdline=\"%s\")", trans_data.cmd, data_info->in_buf);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi send failed. (ret=%d; logic_id=%d; port=%d)", ret, logic_id, port_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi send result failed. (result=%d; logic_id=%d; port=%d)", trans_data.result, logic_id, port_id);
    }

    return trans_data.result;
}

int dsmi_get_pfc_enabled(int logic_id, int port_id, char *pfc_enabled)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    size = PRIORITY_NUM;
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_PFC_CFG, NULL, 0, pfc_enabled, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans info failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get PFC info failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}
 
int dsmi_set_pfc_enabled(int logic_id, int port_id, char *pfc_enabled, unsigned int priority_num)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size = 0;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id:%d; port_id:%d)", logic_id, port_id);
        return -EINVAL;
    }

    ret = hccn_check_usr_identify();
    if (ret) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_SET_PFC_CFG, pfc_enabled, priority_num, NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi set pfc enabled failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi set pfc enabled failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_tc_cfg(int logic_id, int port_id, struct tc_cfg_get *tc_cfg)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id:%d; port_id:%d)", logic_id, port_id);
        return -EINVAL;
    }

    size = sizeof(struct tc_cfg_get);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_TC_CFG, NULL, 0, (char *)tc_cfg, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans info failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get tc cfg failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_set_tc_cfg(int logic_id, int port_id, struct tc_cfg_set *tc_cfg)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id:%d; port_id:%d)", logic_id, port_id);
        return -EINVAL;
    }

    ret = hccn_check_usr_identify();
    if (ret) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    size = 0;
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_TC_CFG, (char *)tc_cfg, sizeof(struct tc_cfg_set), NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi set tc cfg failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi set tc cfg failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_current_tc_used(int logic_id, int port_id, int tc_id, unsigned int *tc_used)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id:%d; port_id:%d)", logic_id, port_id);
        return -EINVAL;
    }

    size_out = sizeof(unsigned int);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_CURR_TC_USED, (char *)(&tc_id), sizeof(int), (char*)tc_used, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("Dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_get_prio_tc_info(int logic_id, int port_id, char *prio_tc)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size = PRIORITY_NUM;
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d; port_id=%d)", logic_id, port_id);
        return -EINVAL;
    }
 
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_PRIO_TC_INFO, NULL, 0, prio_tc, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans info failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi get prio_tc info failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }
 
    return trans_data.result;
}
 
int dsmi_set_prio_tc_info(int logic_id, int port_id, char *prio_tc, unsigned int priority_num)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size = 0;
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d; port_id=%d)", logic_id, port_id);
        return -EINVAL;
    }
 
    ret = hccn_check_usr_identify();
    if (ret) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_PRIO_TC_INFO, prio_tc, priority_num, NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi trans info failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi set prio_tc info failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }
 
    return trans_data.result;
}

#define PING_OUTBUFF_LEN  2000
int dsmi_ping_fun(int logic_id, int phy_id, char *inbuf, struct ping_operate_info *operate_info,
                  unsigned int inbuf_size)
{
    int ret;
    unsigned int size = PING_OUTBUFF_LEN;
    struct ds_trans_data trans_data = {0};
    char outbuf[PING_OUTBUFF_LEN] = {0};

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }
 
    DSMI_SET_TRANS_DATA(trans_data, DS_PING, (char *)operate_info, inbuf_size, (char *)outbuf, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Ping dsmi trans info failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi_ping_fun failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
        return trans_data.result;
    }
    if (operate_info->ipv6_index == 1) {
        TOOL_PRINT_INFO("device %d PING6 %s\n%s", phy_id, operate_info->str_ip6, outbuf);
    } else {
        TOOL_PRINT_INFO("device %d PING %s\n%s", phy_id, operate_info->str_ip, outbuf);
    }

    if (strstr(outbuf, "Message too long") != NULL || strstr(outbuf, "recv time out seq") != NULL
               || strstr(outbuf, "Destination Host Unreachable") != NULL) {
        roce_err("Ping inner error.");
        trans_data.result = PING_INNER_ERROR;
    }
 
    return trans_data.result;
}

int dsmi_get_hccs_ping_result(int logic_id, hccs_ping_operate_info *operate_info,
                              hccs_ping_reply_info_ext *reply_info_ext)
{
    int time_val, ret, reply_len;
    struct ds_trans_data trans_data;

    operate_info->get_info = 1;
    for (time_val = 0; time_val < TASK_WAIT_MAX_TIME; time_val++) {
        sleep(1);

        ret = memset_s(&trans_data, sizeof(struct ds_trans_data), 0, sizeof(struct ds_trans_data));
        if (ret != 0) {
            roce_err("get hccs ping memset failed. (ret=[%d]; logic_id=[%d])", ret, logic_id);
            return ret;
        }

        reply_len = sizeof(hccs_ping_reply_info_ext);
        DSMI_SET_TRANS_DATA(trans_data, DS_HCCS_PING, (char *)operate_info, sizeof(hccs_ping_operate_info),
                            (char *)reply_info_ext, &reply_len);
        trans_data.pid = getpid();

        ret = dsmi_network_transmission_channel(logic_id, &trans_data);
        if (ret != 0) {
            roce_err("get hccs ping res trans info failed. (ret=[%d]; logic_id=[%d])", ret, logic_id);
            return ret;
        }

        ret = trans_data.result;
        if (ret != 0) {
            roce_err("get hccs ping res failed. (result=[%d]; logic_id=[%d])", ret, logic_id);
            return ret;
        }

        if (reply_info_ext->completed) {
            break;
        }
    }

    if (time_val >= TASK_WAIT_MAX_TIME) {
        roce_err("get hccs ping res timeout. (time_val=[%d]; result=[%d]; logic_id=[%d])", time_val, ret, logic_id);
    }

    return ret;
}

int dsmi_hccs_ping(int logic_id, int port_id, hccs_ping_operate_info *operate_info,
                   hccs_ping_reply_info *reply_info)
{
    int ret, reply_len;
    struct ds_trans_data trans_data = {0};
    hccs_ping_reply_info_ext *reply_info_ext;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Ping_ext logic id is invalid. (logic_id=[%d])", logic_id);
        return -EINVAL;
    }

    reply_info_ext = calloc(1, sizeof(hccs_ping_reply_info_ext));
    if (reply_info_ext == NULL) {
        roce_err("calloc hccs ping reply failed.");
        return -ENOMEM;
    }

    operate_info->get_info = 0;
    ret = memcpy_s(&reply_info_ext->info, sizeof(hccs_ping_reply_info), reply_info, sizeof(hccs_ping_reply_info));
    if (ret != 0) {
        roce_err("hccs ping memcpy reply info ext failed. (ret=[%d])", ret);
        ret = -EINVAL;
        goto out;
    }

    reply_len = sizeof(hccs_ping_reply_info_ext);
    DSMI_SET_TRANS_DATA(trans_data, DS_HCCS_PING, (char *)operate_info, sizeof(hccs_ping_operate_info),
                        (char *)reply_info_ext, &reply_len);
    trans_data.pid = getpid();
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Ping_ext dsmi trans info failed. (ret=[%d]; logic_id=[%d])", ret, logic_id);
        goto out;
    }

    ret = trans_data.result;
    if (ret != 0) {
        roce_err("Ping_ext failed. (result=[%d]; logic_id=[%d])", ret, logic_id);
        goto out;
    }

    // 接收底层hccsping结果
    ret = dsmi_get_hccs_ping_result(logic_id, operate_info, reply_info_ext);
    if (ret) {
        roce_err("dsmi_get_hccs_ping_result failed. (result=[%d]; logic_id=[%d])", ret, logic_id);
        goto out;
    }

    ret = memcpy_s(reply_info, sizeof(hccs_ping_reply_info), &reply_info_ext->info, sizeof(hccs_ping_reply_info));
out:
    free(reply_info_ext);
    return ret;
}

int dsmi_get_gratuitous_arp_info(int logic_id, struct gratuitous_arp_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }

    size_out = sizeof(struct gratuitous_arp_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_GRATUIT_ARP_INFO, (char *)(&logic_id), sizeof(logic_id),
        (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi get gratuitous arp info fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get gratuitous arp info result fail. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_set_gratuitous_arp_info(int logic_id, struct gratuitous_arp_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_in, size_out = 0;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }

    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    size_in = sizeof(struct gratuitous_arp_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_GRATUIT_ARP_INFO, (char *)info, size_in, NULL, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi set gratuitous arp info fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi set gratuitous arp info result fail. (result=%d)", trans_data.result);
    }
    
    return trans_data.result;
}

int dsmi_set_optical_auto_adapt(int logic_id, char *inbuf, unsigned int inbuf_len)
{
    struct ds_trans_data trans_data = {0};
    unsigned int size = 0;
    int ret;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(inbuf, -EINVAL);

    DSMI_SET_TRANS_DATA(trans_data, DS_SET_OPTICAL_AUTO_ADAPT, inbuf, inbuf_len, NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi trans info failed, ret[%d] logic_id[%d]", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi set optical auto adapt failed, result[%d] logic_id[%d]", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_route_table_ipv6(int logic_id, int port_id, char *route, unsigned int len)
{
    int ret;
    struct ds_trans_data trans_data = {0};

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id:%d; port_id:%d)", logic_id, port_id);
        return -EINVAL;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(route, -EINVAL);
    if (len == 0) {
        roce_err("len is invalid len[%u]", len);
        return -EINVAL;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_GET_ROUTE_TABLE_INET6, NULL, 0, route, &len);
    trans_data.pid = getpid();
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi get route fail ret[%d] logic_id[%d] port[%d]", ret, logic_id, port_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi get route fail result[%d] logic_id[%d] port[%d]", trans_data.result, logic_id, port_id);
    }
    return trans_data.result;
}

int dsmi_add_route_table_ipv6(int logic_id, int port_id, struct ds_ipv6_route_table_value *route_param, char *outbuf,
    unsigned int len)
{
    int ret;
    struct ds_trans_data trans_data = {0};

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("device id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return -EINVAL;
    }

    if (port_id < 0 ||  port_id > MAX_PORT_ID) {
        roce_err("port id:%d is invalid! expect [0]-[%d]", port_id, MAX_PORT_ID);
        return -EINVAL;
    }

    if (len == 0) {
        roce_err("len is invalid len[%u]", len);
        return -EINVAL;
    }

    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(outbuf, -EINVAL);
    DSMI_CHECK_PTR_VALID_RETURN_VAL(route_param, -EINVAL);
    DSMI_SET_TRANS_DATA(trans_data, DS_ADD_ROUTE_TABLE_INET6, (char*)route_param,
        sizeof(struct ds_ipv6_route_table_value), outbuf, &len);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi add route fail ret[%d] logic_id[%d] port[%d]", ret, logic_id, port_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi add route fail result[%d] logic_id[%d] port[%d]", trans_data.result, logic_id, port_id);
    }

    return trans_data.result;
}

int dsmi_del_route_table_ipv6(int logic_id, int port_id, struct ds_ipv6_route_table_value *route_param,
    char *outbuf, unsigned int len)
{
    int ret;
    struct ds_trans_data trans_data = {0};

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("device id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return -EINVAL;
    }

    if (port_id < 0 ||  port_id > MAX_PORT_ID) {
        roce_err("port id:%d is invalid! expect [0]-[%d]", port_id, MAX_PORT_ID);
        return (-EINVAL);
    }

    if (len == 0) {
        roce_err("len is invalid len[%u]", len);
        return -EINVAL;
    }
    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(outbuf, -EINVAL);
    DSMI_CHECK_PTR_VALID_RETURN_VAL(route_param, -EINVAL);
    DSMI_SET_TRANS_DATA(trans_data, DS_DELETE_ROUTE_TABLE_INET6, (char*)route_param,
        sizeof(struct ds_ipv6_route_table_value), outbuf, &len);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi del route fail ret[%d] logic_id[%d] port[%d]", ret, logic_id, port_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi del route fail result[%d] logic_id[%d] port[%d]", trans_data.result, logic_id, port_id);
    }
    return trans_data.result;
}

int dsmi_get_cdr_snr_cmd(int logic_id, int port, struct cdr_snr_info *cdr_snr_info)
{
    int ret;
    unsigned int size_out;
    struct ds_trans_data trans_data = {0};

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port > MAX_PORT_ID) || (port < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d; port_id=%d)", logic_id, port);
        return -EINVAL;
    }

    DSMI_CHECK_PTR_VALID_RETURN_VAL(cdr_snr_info, -EINVAL);

    size_out = sizeof(struct cdr_snr_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_CDR_SNR_CMD, NULL, 0, (char *)cdr_snr_info, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get snr failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
    if (trans_data.result != 0) {
        roce_err("Dsmi get snr result failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
        return trans_data.result;
    }

    return 0;
}

int dsmi_set_cdr_mode_cmd(int logic_id, int port, struct ds_cdr_mode_info *info)
{
    struct ds_trans_data trans_data = {0};
    unsigned int size_out = 0;
    int ret;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port > MAX_PORT_ID) || (port < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d; port_id=%d)", logic_id, port);
        return -EINVAL;
    }
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_CDR_MODE_CMD, (char*)info, sizeof(struct ds_cdr_mode_info), NULL, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi set cdr mode fail fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi set cdr mode result failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_set_prbs_flag(int logic_id, int prbs_flag)
{
    struct ds_trans_data trans_data = {0};
    int ret;
    unsigned int size = 0;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d", logic_id);
        return -EINVAL;
    }

    roce_info("in dsmi_set_prbs_flag, (logic_id=%d, prbs_flag=%d)", logic_id, prbs_flag);
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_NPU_PRBS_FLAG, (char*)&prbs_flag, sizeof(prbs_flag), NULL, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi set prbs flag data fail failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi set prbs flag data result failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_prbs_adapt_in_order(unsigned int mode, unsigned int logic_id, unsigned char master_flag)
{
    int ret = 0;
    unsigned int size = 0;
    struct ds_trans_data trans_data = {0};
    struct prbs_adapt_mode_info mode_info = {0};

    mode_info.mode = mode;
    mode_info.master_flag = master_flag;

    roce_info("prbs adapt in order start. (mode=%u, logic_id=%u, master_flag=%d)",
        mode, logic_id, master_flag);
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_PRBS_ADAPT_IN_ORDER,
                        (char*)&mode_info, sizeof(struct prbs_adapt_mode_info), NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi set prbs adapt in order failed. (mode=%u, ret=%d; logic_id=%d)", mode, ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("dsmi set prbs adapt in order failed. (mode=%u, result=%d; logic_id=%d)",
            mode, trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_cdr_version(int logic_id, int port_id, struct ds_cdr_version_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id:%d; port_id:%d)", logic_id, port_id);
        return -EINVAL;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(info, -EINVAL);

    size = sizeof(struct ds_cdr_version_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_CDR_VERSION_INFO_CMD, NULL, 0, (char*)info, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get cdr version info fail. (ret=%d; logic_id=%d; port_id=%d)", ret, logic_id, port_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get cdr version info fail. (result=%d; logic_id=%d; port=%d)",
                 trans_data.result, logic_id, port_id);
    }

    return trans_data.result;
}

int dsmi_get_eth_down_data(int logic_id, struct ds_link_down_data *down_data)
{
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;
    int ret;
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (down_data == NULL)) {
        roce_err("Logic id or down_data is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }
 
    size_out = sizeof(struct ds_link_down_data);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_LINK_DOWN_INFO_CMD, (char *)(&logic_id), sizeof(logic_id),
        (char*)down_data, &size_out);
 
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get eth down data fail fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi get eth down data result failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }
 
    return trans_data.result;
}

int dsmi_get_traceroute_status(int logic_id, int *troute_status)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size = ARGC_NUM_10;
    char status[ARGC_NUM_10];
    char *p_tmp = NULL;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id in dsmi get traceroute status is invalid! expect [0]-[%d]. (logic_id=%d)",
                 DS_MAX_LOGIC_ID, logic_id);
        return -EINVAL;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_GET_TRACEROUTE_STATUS, NULL, 0, status, &size);
    
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi channel got traceroute status failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
    *troute_status = strtol(status, &p_tmp, STR_TO_INT_TEN);
    if (*p_tmp != '\0') {
        roce_err("Strtol current status got invalid param. (status=%s)", status);
        return -EINVAL;
    }
    if (trans_data.result != 0) {
        roce_err("Dsmi get traceroute status result wrong. (result=%d; logic_id=%d)", trans_data.result, logic_id);
        return trans_data.result;
    }

    return 0;
}

int dsmi_start_traceroute(int logic_id, struct dsmi_traceroute_info *traceroute_info_send,
    int *troute_start_result)
{
    int ret;
    unsigned int size = ARGC_NUM_10;
    struct ds_trans_data trans_data = {0};
    char result[ARGC_NUM_10];
    char *p_tmp = NULL;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id in dsmi start traceroute is invalid! expect [0]-[%d]. (logic_id=%d)",
                 DS_MAX_LOGIC_ID, logic_id);
        return -EINVAL;
    }

    DSMI_CHECK_PTR_VALID_RETURN_VAL(traceroute_info_send, -EINVAL);
    DSMI_SET_TRANS_DATA(trans_data, DS_START_TRACEROUTE, (char *)(void *)traceroute_info_send,
        sizeof(struct dsmi_traceroute_info), result, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi channel start traceroute cmd failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
    *troute_start_result = strtol(result, &p_tmp, STR_TO_INT_TEN);
    if (*p_tmp != '\0') {
        roce_err("Strtol tracerrroute result got invalid param. (result=%s)", result);
        return -EINVAL;
    }
    if (trans_data.result != 0) {
        roce_err("Dsmi start traceroute result wrong. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_extra_statistics_info(int logic_id, int port_id, struct ds_extra_statistics_info *info)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id:%d; port_id:%d)", logic_id, port_id);
        return -EINVAL;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(info, -EINVAL);

    size = sizeof(struct ds_extra_statistics_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_EXTRA_STAT_INFO, NULL, 0, (char*)info, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get extra statistics info fail. (ret=%d; logic_id=%d; port_id=%d)", ret, logic_id, port_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get extra statistics fail. (result=%d; logic_id=%d; port=%d)",
                 trans_data.result, logic_id, port_id);
    }

    return trans_data.result;
}

int dsmi_get_fec_error_info(int logic_id, struct ds_fec_error_info *info, int mac_id)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_in;
    unsigned int size_out;
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(info, -EINVAL);
    size_in = sizeof(int);
    size_out = sizeof(struct ds_fec_error_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_FEC_ERROR_INFO, (char*)(&mac_id), size_in, (char*)info, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi get FEC error info fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get FEC error info fail. (result=%d; logic_id=%d)",
                 trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_clear_extra_statistics_info(int logic_id, int port)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port > MAX_PORT_ID) || (port < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d; port_id=%d)", logic_id, port);
        return -EINVAL;
    }

    size = 0;
    DSMI_SET_TRANS_DATA(trans_data, DS_CLEAR_EXTRA_STAT_INFO, NULL, 0, NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi clear stat extra fail. (ret=%d; logic_id=%d; port=%d)", ret, logic_id, port);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi clear stat extra fail. (ret=%d; logic_id=%d; port=%d)", trans_data.result, logic_id, port);
    }

    return trans_data.result;
}

int dsmi_get_traceroute_info(int logic_id, char *troute_info_show, unsigned int info_size, int cmd_type)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id in dsmi get traceroute info is invalid! expect [0]-[%d]. (logic_id=%d)",
            DS_MAX_LOGIC_ID, logic_id);
        return -EINVAL;
    }

    size = info_size;
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_TRACEROUTE_INFO, (char *)(void *)&cmd_type,
                        sizeof(cmd_type), troute_info_show, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi channel got traceroute info failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get traceroute info result wrong. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_reset_traceroute(int logic_id, int *troute_reset)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size = ARGC_NUM_10;
    char reset[ARGC_NUM_10] = {0};
    char *p_tmp = NULL;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id in dsmi reset traceroute is invalid! expect [0]-[%d]. (logic_id=%d)",
                 DS_MAX_LOGIC_ID, logic_id);
        return -EINVAL;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_RESET_TRACEROUTE, NULL, 0, reset, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi channel got traceroute reset failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
    *troute_reset = strtol(reset, &p_tmp, STR_TO_INT_TEN);
    if (*p_tmp != '\0') {
        roce_err("Strtol traceroute reset got invalid param. (reset=%s)", reset);
        return -EINVAL;
    }
    if (trans_data.result != 0) {
        roce_err("Dsmi reset traceroute result was wrong. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_xsfp_reset_info(int logic_id, struct xsfp_reset_info *reset_info)
{
    unsigned int size_out = sizeof(struct xsfp_reset_info);
    struct ds_trans_data trans_data = {0};
    int ret;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_GET_XSFP_RESET_INFO, (char *)(&logic_id), sizeof(logic_id),
        (char*)reset_info, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi get xsfp reset info fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get xsfp reset info result fail. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}
 
int dsmi_set_xsfp_reset_info(int logic_id, struct xsfp_reset_info *reset_info)
{
    struct ds_trans_data trans_data = {0};
    unsigned int size_in, size_out = 0;
    int ret;
 
    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }
 
    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    size_in = sizeof(struct xsfp_reset_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_XSFP_RESET_INFO, (char *)reset_info, size_in, NULL, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi set xsfp reset info fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi set xsfp reset info result fail. (result=%d)", trans_data.result);
    }
    
    return trans_data.result;
}

int dsmi_set_host_info(int logic_id, struct ds_host_info *host_info)
{
    int ret;
    unsigned int size_out = 0;
    struct ds_trans_data trans_data = {0};
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (host_info == NULL)) {
        roce_err("Logic id invalid or host_info NULL (logic_id=%d; host_info=%d;)", logic_id, (host_info == NULL));
        return -EINVAL;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_SET_HOST_INFO,
        (char*)host_info, HOST_INFO_SIZE_MAX + HOST_NAME_SIZE_MAX, NULL, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Call dsmi transmission failed. (ret=%d; logic_id:%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Set host info fail. (trans_data.result=%d; logic_id:%d)", trans_data.result, logic_id);
    }
 
    return trans_data.result;
}

static int check_roce_port_ippair(struct ds_roce_port_ippair *ippair)
{
    int roce_port;
    struct in6_addr zero_addr = { 0 };

    if (memcmp(&zero_addr, &ippair->sip.ipv6, sizeof(struct in6_addr)) == 0 ||
        memcmp(&zero_addr, &ippair->dip.ipv6, sizeof(struct in6_addr)) == 0) {
        roce_err("Invalid zero ip address.");
        return -EINVAL;
    }

    roce_port = ippair->roce_port;
    if (roce_port < DSMI_MIN_UDP_PORT || roce_port > DSMI_MAX_UDP_PORT) {
        roce_err("Invalid roce_port, expect 4097-65535.(port=%d)", roce_port);
        return -EINVAL;
    }

    if (ippair->sip_family != AF_INET && ippair->sip_family != AF_INET6) {
        roce_err("Invalid address family, expect %d/%d.(family=%d)", AF_INET, AF_INET6, ippair->sip_family);
        return -EINVAL;
    }

    if (ippair->sip_family != ippair->dip_family) {
        roce_err("Address familys isn't same.(src=%d; dst=%d)",
            ippair->sip_family, ippair->dip_family);
        return -EINVAL;
    }

    return 0;
}

static int dsmi_update_roce_port_ippair(int logic_id, int port_id,
    struct ds_roce_port_ippair *ippair, enum ds_ippair_op_type op)
{
    int ret;
    unsigned int size;
    char *op_name[] = {"set", "del"};
    char sip[INET6_ADDRSTRLEN] = { 0 };
    char dip[INET6_ADDRSTRLEN] = { 0 };
    struct ds_trans_data trans_data = { 0 };
    struct ds_update_ippair update_ippair = { 0 };

    DSMI_CHECK_PTR_VALID_RETURN_VAL(ippair, -EINVAL);

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid.(logic_id=%d; port_id=%d)", logic_id, port_id);
        return -EINVAL;
    }

    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    ret = check_roce_port_ippair(ippair);
    if (ret != 0) {
        return ret;
    }

    update_ippair.ippair = *ippair;
    update_ippair.op = op;

    (void)inet_ntop(ippair->sip_family, &ippair->sip.ipv6, sip, INET6_ADDRSTRLEN);
    (void)inet_ntop(ippair->dip_family, &ippair->dip.ipv6, dip, INET6_ADDRSTRLEN);

    size = 0;
    DSMI_SET_TRANS_DATA(trans_data, DS_UPDATE_ROCE_PORT_IPPAIR, (char*)(void*)&update_ippair,
        sizeof(struct ds_update_ippair), NULL, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi %s roce port fail.(ret=%d; logic_id=%d; port=%d; roce_port=%d; sip=%s; dip=%s)",
            op_name[op], ret, logic_id, port_id, ippair->roce_port, sip, dip);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi %s roce port fail.(result=%d; logic_id=%d; port=%d; roce_port=%d; sip=%s; dip=%s)",
            op_name[op], trans_data.result, logic_id, port_id, ippair->roce_port, sip, dip);
    }

    return trans_data.result;
}

int dsmi_set_roce_port_ippair(int logic_id, int port_id, struct ds_roce_port_ippair *ippair)
{
    return dsmi_update_roce_port_ippair(logic_id, port_id, ippair, DS_IPPAIR_SET);
}

int dsmi_del_roce_port_ippair(int logic_id, int port_id, struct ds_roce_port_ippair *ippair)
{
    return dsmi_update_roce_port_ippair(logic_id, port_id, ippair, DS_IPPAIR_DEL);
}

int dsmi_clear_roce_port_ippair(int logic_id, int port_id)
{
    int ret;
    unsigned int size;
    struct ds_trans_data trans_data = { 0 };

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid.(logic_id=%d; port_id=%d).", logic_id, port_id);
        return -EINVAL;
    }

    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    size = 0;
    DSMI_SET_TRANS_DATA(trans_data, DS_CLEAR_ROCE_PORT_IPPAIR, NULL, 0, NULL, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi clear roce port fail.(ret=%d; logic_id=%d; port=%d)", ret, logic_id, port_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Clear roce port fail.(result=%d; logic_id=%d; port=%d)", trans_data.result, logic_id, port_id);
    }

    return trans_data.result;
}

int dsmi_get_roce_port_ippair(int logic_id, int port_id, struct ds_ippair_list *list)
{
    int ret;
    unsigned int size;
    struct ds_trans_data trans_data = { 0 };
    int list_count;

    DSMI_CHECK_PTR_VALID_RETURN_VAL(list, -EINVAL);
    list_count = list->count;

    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid.(logic_id=%d; port_id=%d)", logic_id, port_id);
        return -EINVAL;
    }

    size = sizeof(struct ds_ippair_list) + sizeof(struct ds_roce_port_ippair) * list->count;
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_ROCE_PORT_IPPAIR, (char*)(&list_count),
        sizeof(list_count), (char*)(void*)list, &size);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get roce port fail.(ret=%d; logic_id=%d; port=%d; count=%d)",
            ret, logic_id, port_id, list->count);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Get roce port fail.(result=%d; logic_id=%d; port=%d; count=%d)",
            trans_data.result, logic_id, port_id, list->count);
    }

    return trans_data.result;
}

int dsmi_get_downgrade_lane_info(int logic_id, struct downgrade_lane_info *info)
{
    unsigned int size_out = sizeof(struct downgrade_lane_info);
    struct ds_trans_data trans_data = {0};
    int ret;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_GET_DOWNGRADE_LANE_INFO, (char *)(info), size_out,
        (char*)info, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi get downgrade info fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get downgrade info result fail. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}
 
/* 设置降lane的全局开关 */
int dsmi_set_downgrade_lane_info(int logic_id, struct downgrade_lane_info *info)
{
    struct ds_trans_data trans_data = {0};
    unsigned int size_in, size_out = 0;
    int ret;
 
    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid. (logic_id=%d)", logic_id);
        return (-EINVAL);
    }
 
    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    size_in = sizeof(struct downgrade_lane_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_DOWNGRADE_LANE_INFO, (char *)info, size_in, NULL, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi set downgrade info fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi set downgrade info result fail. (result=%d)", trans_data.result);
    }
    
    return trans_data.result;
}

int dsmi_get_pfc_duration_info(int logic_id, struct pfc_duration_info *info)
{
    int ret;
	struct ds_trans_data trans_data = {0};
    unsigned int size_out;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("logic id:%d is invalid! expect [0]-[%d]", logic_id, DS_MAX_LOGIC_ID);
        return -EINVAL;
    }
    if (!info) {
        roce_err("input is null. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    size_out = sizeof(struct pfc_duration_info);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_PFC_D_INFO, NULL, 0, (char*)info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("dsmi trans fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result) {
        roce_err("dsmi trans res error. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_clear_pfc_duration(int logic_id, int mode)
{
	struct ds_trans_data trans_data = {0};
    int ret;
    int out_buf = 0;
    int size_out = 0;
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Log ic id is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }
    if (mode < 0 || mode > DS_CLEAR_PFC_MODE_MAX) {
        roce_err("duration mode is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_CLEAR_PFC_DURATION, (char*) &mode, sizeof(int), NULL, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi clear pfc pause duration fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi set cdr mode result failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
        return trans_data.result;
    }

    return trans_data.result;
}
int dsmi_get_tc_stat(int logic_id, struct ds_tc_stat_data *stat)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;
    
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < DS_MIN_LOGIC_ID)) {
        roce_err("Logic id is invalid. (logic_id:%d)", logic_id);
        return -EINVAL;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(stat, -EINVAL);
    
    size = sizeof(struct ds_tc_stat_data);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_TC_STAT, (char *)(&logic_id), sizeof(logic_id), (char*)stat, &size);
 
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get stat fail. (ret=%d logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi get stat fail. (result=%d logic_id=%d)", trans_data.result, logic_id);
    }
 
    return trans_data.result;
}

int dsmi_clear_tc_stat(int logic_id)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size;
    
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0)) {
        roce_err("Logic id is invalid. (logic_id:%d;)", logic_id);
        return -EINVAL;
    }
    
    size = 0;
    DSMI_SET_TRANS_DATA(trans_data, DS_CLEAR_TC_PACKET_STATISTICS, (char *)(&logic_id), sizeof(logic_id), NULL, &size);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi clear tc stat fail. (ret=%d logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi clear tc stat fail. (result=%d logic_id=%d)", trans_data.result, logic_id);
    }
 
    return trans_data.result;
}

int dsmi_get_serdes_info_steady(int logic_id, struct ds_serdes_info *serdes_info)
{
    int ret = 0;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out = sizeof(struct ds_serdes_info);
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (serdes_info == NULL)) {
        roce_err("Logic id or serdes_info is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }
 
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_SERDES_INFO_STEADY, (char *)(&logic_id), sizeof(logic_id),
        (char*)serdes_info, &size_out);
 
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get hilink info steady fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi get hilink info steady result failed. (result=%d; logic_id=%d)",
            trans_data.result, logic_id);
    }
 
    return trans_data.result;
}

int dsmi_get_serdes_info_flash(int logic_id, struct ds_serdes_info *serdes_info)
{
    int ret = 0;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out = sizeof(struct ds_serdes_info);
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (serdes_info == NULL)) {
        roce_err("Logic id or serdes_info is invalid. (logic_id=%d)", logic_id);
        return -EINVAL;
    }

    DSMI_SET_TRANS_DATA(trans_data, DS_GET_SERDES_INFO_FLASH, (char *)(&logic_id), sizeof(logic_id),
        (char*)serdes_info, &size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret) {
        roce_err("Dsmi get hilink info flash fail. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get hilink info flash result failed. (result=%d; logic_id=%d)", trans_data.result, logic_id);
    }

    return trans_data.result;
}

int dsmi_get_qpn_list(int logic_id, int port_id, struct ds_qpn_list *list)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out;
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d; port_id=%d)", logic_id, port_id);
        return -EINVAL;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(list, -EINVAL);
    
    size_out = sizeof(struct ds_qpn_list);
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_QPN_LIST, NULL, 0, (char*)list, &size_out);
 
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi channel get qpn list failed. (ret=%d; logic_id=%d; port_id=%d)", ret, logic_id, port_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi channel get qpn list failed. (result=%d)", trans_data.result);
    }
 
    return trans_data.result;
}
 
int dsmi_get_qp_context(int logic_id, int port_id, unsigned int qpn, char *context)
{
    int ret;
    struct ds_trans_data trans_data = {0};
    unsigned int size_out = INFO_PAYLOAD_LEN;
 
    if ((logic_id > DS_MAX_LOGIC_ID) || (logic_id < 0) || (port_id > MAX_PORT_ID) || (port_id < 0)) {
        roce_err("Logic id or port id is invalid. (logic_id=%d; port_id=%d)", logic_id, port_id);
        return -EINVAL;
    }
    DSMI_CHECK_PTR_VALID_RETURN_VAL(context, -EINVAL);
    
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_QP_CONTEXT, (char *)&qpn, sizeof(unsigned int), context, &size_out);
 
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi channel get qp context failed. (ret=%d; logic_id=%d; port_id=%d)", ret, logic_id, port_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi channel get qp context failed. (result=%d)", trans_data.result);
    }
 
    return trans_data.result;
}
 
static int is_ipv6_v4_mapped(const struct in6_addr *address)
{
    return IN6_IS_ADDR_V4MAPPED(address);
}
 
static unsigned short reverse_8_bits(unsigned short value)
{
    int offset_8 = 8;
    unsigned char high = (value >> 8) & 0xFF;
    unsigned char low = value & 0xFF;
 
    return (low << offset_8) | high;
}
 
static int dgid_to_ip(char *ip, int ip_address_len, unsigned int *qpc, int is_ipv4_flag)
{
    int ret;
    int dgid_offset = 7;      // dgid偏移地址
    
    int offset_1 = 1;
    int offset_2 = 2;
    int offset_3 = 3;
    int offset_8 = 8;
    int offset_16 = 16;
    int offset_24 = 24;
 
    if (is_ipv4_flag) {
        ret = sprintf_s(ip, ip_address_len, "%u.%u.%u.%u",
                        *(qpc + dgid_offset + offset_3) & 0xFF,
                        (*(qpc + dgid_offset + offset_3) >> offset_8) & 0xFF,
                        (*(qpc + dgid_offset + offset_3) >> offset_16) & 0xFF,
                        (*(qpc + dgid_offset + offset_3) >> offset_24) & 0xFF);
        if (ret <= 0) {
            roce_err("Dsmi sprintf ip_v4 failed. (ret=%d)\n", ret);
            return -ENOMEM;
        }
    } else {
        ret = sprintf_s(ip, ip_address_len, "%x:%x:%x:%x:%x:%x:%x:%x",
                        reverse_8_bits(*(qpc + dgid_offset) & 0xFFFF),
                        reverse_8_bits((*(qpc + dgid_offset) >> offset_16) & 0xFFFF),
                        reverse_8_bits(*(qpc + dgid_offset + offset_1) & 0xFFFF),
                        reverse_8_bits((*(qpc + dgid_offset + offset_1) >> offset_16) & 0xFFFF),
                        reverse_8_bits(*(qpc + dgid_offset + offset_2) & 0xFFFF),
                        reverse_8_bits((*(qpc + dgid_offset + offset_2) >> offset_16) & 0xFFFF),
                        reverse_8_bits(*(qpc + dgid_offset + offset_3) & 0xFFFF),
                        reverse_8_bits((*(qpc + dgid_offset + offset_3) >> offset_16) & 0xFFFF));
        if (ret <= 0) {
            roce_err("Dsmi sprintf ip_v6 failed. (ret=%d)\n", ret);
            return -ENOMEM;
        }
    }
 
    return 0;
}
 
static int dsmi_parse_qp_info(unsigned int qpn, char *context, struct ds_qp_info *qp_info)
{
    int ret;
    unsigned int *qpc;
    int dgid_offset = 7;                                       // dgid偏移地址
    char ip[IP_ADDRESS_LEN] = {0};
    qpc = (unsigned int *)context;
   
    unsigned char status = (*(qpc + 14) >> 29) & 0x07;         // byte_60_qpst bit 29-31
    unsigned char type = (*(qpc + 19) >> 24) & 0x01;           // byte_80_xrc_qp_type bit 24
    unsigned short src_port = (*(qpc + 12) >> 16) & 0xFFFF;    // byte_52_udpspn bit 16-31
    unsigned int dst_qpn = *(qpc + 13) & 0xFFFFFF;             // byte_56_dqpn bit 0-23
    unsigned int send_psn = (*(qpc + 42) >> 8) & 0xFFFFFF;     // byte_172_sq_cur_psn bit 8-31
    unsigned int recv_psn = (*(qpc + 26) >> 8) & 0xFFFFFF;     // byte_108_rap_psn bit 8-31
 
    if (is_ipv6_v4_mapped((struct in6_addr *)(qpc + dgid_offset))) {
        ret = dgid_to_ip(&ip, sizeof(ip), qpc, 1);
        if (ret != 0) {
            roce_err("Dsmi parse ip_v4 addrress of qp info failed. (ret=%d)\n", ret);
            return -ENOMEM;
        }
    } else {
        ret = dgid_to_ip(&ip, sizeof(ip), qpc, 0);
        if (ret != 0) {
            roce_err("Dsmi parse ip_v6 addrress of qp info failed. (ret=%d)\n", ret);
            return -ENOMEM;
        }
    }
    
    qp_info->src_qpn = qpn;
    qp_info->status = status;
    qp_info->type = type;
    qp_info->src_port = src_port;
    qp_info->dst_qpn = dst_qpn;
    qp_info->send_psn = send_psn;
    qp_info->recv_psn = recv_psn;
 
    ret = memcpy_s(qp_info->ip, IP_ADDRESS_LEN, ip, strlen(ip));
    if (ret != 0) {
        roce_err("Dsmi memcpy_s ip addrress of qp info failed. (ret=%d)\n", ret);
        return -ENOMEM;
    }
 
    return 0;
}
 
int dsmi_get_qp_info(int logic_id, int port_id, unsigned int qpn, struct ds_qp_info *qp_info)
{
    int ret;
    char context[INFO_PAYLOAD_LEN] = {0};
 
    ret = dsmi_get_qp_context(logic_id, port_id, qpn, &context);
    if (ret != 0) {
        roce_err("Dsmi get qp context failed. (ret=%d; logic_id=%d; port_id=%d)", ret, logic_id, port_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
 
    context[INFO_PAYLOAD_LEN - 1] = '\0';
 
    ret = dsmi_parse_qp_info(qpn, context, qp_info);
    if (ret != 0) {
        roce_err("Dsmi parse qp info failed. (ret=%d; logic_id=%d; port_id=%d)", ret, logic_id, port_id);
        return ret;
    }
 
    return 0;
}

int dsmi_set_roce_cw_bad_cnt_thd(int logic_id, unsigned int cw_bad_cnt_thd)
{
    struct ds_trans_data trans_data = {0};
    unsigned int size_in, size_out = 0;
    int ret;
    struct ds_cw_bad_cnt_thd info = {0};

    info.cw_bad_cnt_thd = cw_bad_cnt_thd;
    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return (-EINVAL);
    }

    ret = hccn_check_usr_identify();
    if (ret != 0) {
        roce_err("Check usr identify failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    size_in = sizeof(struct ds_cw_bad_cnt_thd);
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_ROCE_CW_BAD_CNT_THD, (char *)(&info), size_in, NULL, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi set roce cw_bad_cnt_thd failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }
 
    if (trans_data.result != 0) {
        roce_err("Dsmi set roce cw_bad_cnt_thd failed. (result=%d)", trans_data.result);
    }
    
    return trans_data.result;
}

int dsmi_get_roce_cw_bad_cnt_thd(int logic_id, struct ds_cw_bad_cnt_thd *info)
{
    unsigned int size_out = sizeof(struct ds_cw_bad_cnt_thd);
    struct ds_trans_data trans_data = {0};
    int ret;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return -EINVAL;
    }
    DSMI_SET_TRANS_DATA(trans_data, DS_GET_ROCE_CW_BAD_CNT_THD, (char *)(&logic_id),
                        sizeof(logic_id), (char*)info, &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi get roce cw_bad_cnt_thd failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi get roce cw_bad_cnt_thd failed. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}

int dsmi_set_device_offline_nic_down_flag(int logic_id, int enable_flag)
{
    unsigned int size_out = 0;
    struct ds_trans_data trans_data = {0};
    int ret;

    if (logic_id > DS_MAX_LOGIC_ID || logic_id < 0) {
        roce_err("Logic id is invalid, expect [0]-[%d]. (logic_id=%d)", DS_MAX_LOGIC_ID, logic_id);
        return -EINVAL;
    }
    DSMI_SET_TRANS_DATA(trans_data, DS_SET_DEVICE_OFFLINE_NET_DOWN, (char *)(&enable_flag), sizeof(int), NULL,
        &size_out);
    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        roce_err("Dsmi set device offline net down flag failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return ret;
    }

    if (trans_data.result != 0) {
        roce_err("Dsmi set device offline net down flag failed. (result=%d)", trans_data.result);
    }
    return trans_data.result;
}