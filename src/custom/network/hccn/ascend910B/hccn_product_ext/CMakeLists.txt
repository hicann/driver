# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------


target_sources(hccn_tool PRIVATE
    tool_recovery.c
    tool_cmd.c
    tool_ext.c
    tool_optical.c
    ds_net_ext.c
    ds_net_ops_ext.c
    ds_net_tool_ext.c
    ds_net_common.c
    tool_cdr.c
    tool_lib.c
    tool_send_arp.c
    tool_ops_ext.c
    tool_ops_ip.c
    tool_scdr.c
    tool_pfc_storm.c
    tool_ipv6.c
    tool_prio_tc.c
    tool_diagnostic.c
    tool_tc_qos.c
    tool_common.c
)
target_include_directories(hccn_tool PRIVATE
    ${DRIVER_USER_DIR}/inc/dmc/
    ${DRIVER_CUST_DIR}/network/hccn/ascend910B/hccn_product_ext
)
target_compile_definitions(hccn_tool PRIVATE
    HCCN_TOOL_ADAPT_IPV6
    CFG_SOC_PLATFORM_CLOUD_V2
)
