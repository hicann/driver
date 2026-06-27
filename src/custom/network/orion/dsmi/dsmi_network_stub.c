/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
 
#include "dsmi_network_interface.h"
 
int dsmi_get_bandwidth(int logic_id, int port, struct bandwidth_t *bandwidth_info)
{
    return 0;
}
 
int dsmi_get_netdev_stat(int logic_id, int port, struct ds_port_stat_info *stat)
{
    return 0;
}

int dsmi_hccs_ping(int logic_id, int port_id, hccs_ping_operate_info *ping_info,
                   hccs_ping_reply_info *reply_info)
{
    return 0;
}

int dsmi_get_traceroute_status(int logic_id, int *troute_status)
{
    return 0;
}
 
int dsmi_start_traceroute(int logic_id, struct dsmi_traceroute_info *traceroute_info_send,
    int *troute_start_result)
{
    return 0;
}
 
int dsmi_get_traceroute_info(int logic_id, char *troute_info_show, unsigned int info_size, int cmd_type)
{
    return 0;
}
 
int dsmi_reset_traceroute(int logic_id, int *troute_reset)
{
    return 0;
}

int dsmi_set_prbs_flag(int logic_id, int prbs_flag)
{
    return 0;
}

int dsmi_prbs_adapt_in_order(unsigned int mode, unsigned int logic_id, unsigned char master_flag)
{
    return 0;
}

int dsmi_set_cdr_mode_cmd(int logic_id, int port, struct ds_cdr_mode_info *info)
{
    return 0;
}

int dsmi_get_pfc_duration_info(int logic_id, struct pfc_duration_info *info)
{
    return 0;
}

int dsmi_get_tc_stat(int logic_id, struct ds_tc_stat_data *stat)
{
    return 0;
}

int dsmi_clear_tc_stat(int logic_id)
{
    return 0;
}

int dsmi_clear_pfc_duration(int logic_id, int mode)
{
    return 0;
}

int dsmi_get_qpn_list(int logic_id, int port_id, struct ds_qpn_list *list)
{
    return 0;
}
 
int dsmi_get_qp_info(int logic_id, int port_id, unsigned int qpn, struct ds_qp_info *qp_info)
{
    return 0;
}

int dsmi_start_hccs_ping_mesh(int logic_id, struct hccs_ping_mesh_operate *operate_info)
{
    return 0;
}
int dsmi_get_hccs_ping_mesh_info(int logic_id, int task_id, struct ping_mesh_stat *info)
{
    return 0;
}
int dsmi_get_hccs_ping_mesh_state(int logic_id, int task_id, unsigned int *state)
{
    return 0;
}
int dsmi_stop_hccs_ping_mesh(int logic_id, int task_id)
{
    return 0;
}
int dsmi_get_extra_statistics_info(int logic_id, int port_id, struct ds_extra_statistics_info *info)
{
    return 0;
}

EXPORT_FUNCTION int dsmi_set_device_offline_nic_down_flag(int logic_id, int enable_flag)
{
    return 0;
}