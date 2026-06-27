/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
 
#ifndef HCCN_TOOL_ROCE_H
#define HCCN_TOOL_ROCE_H
 
enum UDP_PORT_MODE {
    UDP_PORT_CUSTOM   = 0X00000,
    UDP_PORT_AUTO     = 0X10000,
    UDP_PORT_CODE     = 0X20000,
    UDP_PORT_MULTI_QP = 0X40000,
};
 
struct udp_port_mode_map {
    const char *mode;
    enum UDP_PORT_MODE mode_value;
};
 
#define UDP_PORT_CODE_NSLB_DP_MODE      "nslb-dp"
#define CONF_FILE_NOT_EXIST             (-200)
 
int tool_get_roce_port(int logic_id, int argc, char **argv);
int tool_cfg_recovery_err_proc(int ret, int phy_id, const char *conf_param);
#endif
