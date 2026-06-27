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
    src/tool_recovery.c
    src/tool_cmd.c
    src/tool_ext.c
    src/tool_optical.c
    src/ds_net_ext.c
    src/ds_net_ops_ext.c
    src/ds_net_tool_ext.c
    src/ds_net_common.c
    src/tool_cdr.c
    src/tool_lib.c
    src/tool_send_arp.c
    src/tool_ops_ext.c
    src/tool_ops_ip.c
    src/tool_scdr.c
    src/tool_pfc_storm.c
    src/tool_ipv6.c
    src/tool_prio_tc.c
    src/tool_diagnostic.c
    src/tool_tc_qos.c
    src/tool_common.c
)
target_include_directories(hccn_tool PRIVATE
    ${DRIVER_USER_DIR}/inc/dmc/
    ${DRIVER_CUST_DIR}/network/hccn/hccn_product_ext/src
)
target_compile_definitions(hccn_tool PRIVATE
    HCCN_TOOL_ADAPT_IPV6
    CFG_SOC_PLATFORM_CLOUD_V2
)
