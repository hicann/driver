# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

set(hccn_tool_list
    hccn_base/tool/tool_cfg_ext.c
    hccn_base/tool/tool_lib.c
    hccn_base/tool/tool_optical.c
    hccn_base/tool/tool_optical_dfx.c
    hccn_base/tool/tool_port_dfx.c
    hccn_base/tool/tool_product.c
    hccn_base/tool/tool_record_log.c
    hccn_base/tool/tool_serdes.c
    hccn_base/tool/tool_su_ber.c
    hccn_base/tool/tool_table.c
    hccn_base/tool/tool_udp.c
    hccn_base/tool/cmscbb_log_stub.c
    ${DRIVER_NETWORK_DIR}/orion/hccn/common/comm_ext/comm_product.c
)

target_sources(hccn_tool PRIVATE ${hccn_tool_list})

target_include_directories(hccn_tool BEFORE PRIVATE
    ${DRIVER_CUST_DIR}/network/inc
    ${DRIVER_USER_DIR}/dmc/dsmi/dsmi_product_ext
    ${DRIVER_USER_DIR}/src/dmc/dsmi/include
    ${DRIVER_NETWORK_DIR}/orion/hccn/common/comm_ext
    ${DRIVER_USER_DIR}/msnpureport/inc/slog
    ${DRIVER_CUST_DIR}/network/orion/dsmi
    ${DRIVER_CUST_DIR}/network/orion/hccn/common
    ${DRIVER_CUST_DIR}/network/orion/hccn/host/hccn_base/tool
)

target_link_libraries(hccn_tool PRIVATE
    dsmi_network
    m
)

target_compile_definitions(hccn_tool PRIVATE
    ENABLE_BUILD_PRODUCT
)

add_dependencies(hccn_tool extract_driver_device)
target_link_directories(hccn_tool PRIVATE ${CMAKE_BINARY_DIR}/lib/lib64/driver)