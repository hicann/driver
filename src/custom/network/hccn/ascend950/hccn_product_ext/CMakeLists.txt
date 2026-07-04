# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

set(hccn_product_ext_list
    tool_cfg_ext.c
    tool_lib.c
    tool_optical.c
    tool_optical_dfx.c
    tool_port_dfx.c
    tool_product.c
    tool_record_log.c
    tool_serdes.c
    tool_su_ber.c
    tool_table.c
    tool_udp.c
    cmscbb_log_stub.c
    ${DRIVER_CUST_DIR}/network/hccn/ascend950/common/common_ext/comm_product.c
)

target_sources(hccn_tool PRIVATE ${hccn_product_ext_list})

target_include_directories(hccn_tool PRIVATE
    ${DRIVER_CUST_DIR}/network/hccn/ascend950/common/common_ext
    ${DRIVER_CUST_DIR}/network/hccn/ascend950/hccn_product_ext
    ${DRIVER_USER_DIR}/dmc/dsmi/dsmi_product_ext
)

target_link_libraries(hccn_tool PRIVATE
    dsmi_network
    m
)

target_compile_definitions(hccn_tool PRIVATE
    ENABLE_BUILD_PRODUCT
)

target_link_directories(hccn_tool PRIVATE ${CMAKE_BINARY_DIR}/lib/lib64/driver)