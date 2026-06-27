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
    src/main.c
    src/cmd.c
    src/cmd_ext.c
    src/tool_ops.c
    src/tool_ops_ext.c
    src/tool_roce.c
    src/tool_tls.c
    src/tool_tls_ext.c
    src/tool_dcqcn.c
    src/tool.c
    src/cfg.c
    src/log.c
    ${DRIVER_CUST_DIR}/network/common/file_opt.c
    ${DRIVER_CUST_DIR}/network/common/network_comm.c
)

add_executable(hccn_tool ${hccn_tool_list})

target_include_directories(hccn_tool PRIVATE
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_CUST_DIR}/include
    ${DRIVER_CUST_DIR}/network/inc
    ${DRIVER_CUST_DIR}/network/inc/ascend910B
    # ${DRIVER_USER_DIR}/dmc/dsmi/dsmi_product_ext
    # ${DRIVER_USER_DIR}/src/dmc/dsmi/include
    ${DRIVER_KERNEL_DIR}/dms/command/ioctl/
    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/inc/dms
    ${DRIVER_USER_DIR}/msnpureport/inc/slog
    ${DRIVER_CUST_DIR}/network/dsmi
    ${DRIVER_CUST_DIR}/network/hccn/common
    ${DRIVER_CUST_DIR}/network/hccn/hccn_tool/src
    ${DRIVER_NETWORK_DIR}/crypt/inc
    ${DRIVER_NETWORK_DIR}/inc
    ${DRIVER_CUST_DIR}/network/common
)

target_compile_options(hccn_tool PRIVATE
    -fPIC -rdynamic -fno-strict-aliasing -fsigned-char -fno-common)

target_link_libraries(hccn_tool PRIVATE
    $<BUILD_INTERFACE:mmpa_headers>
    c_sec
    drvdsmi_host
    mmpa
    ascend_hal
    -Wl,--no-whole-archive
    tls_adp
    ascend_kms
    ssl
    crypto
    rt
    dl
    m
)

target_compile_definitions(hccn_tool PRIVATE
    DRV_HOST
    NETWORK_HOST
    HCCN_TOOL_SHOW_EXT
    HCCN_TOOL_ADAPT_IPV6
    HCCN_TOOL_ADAPT_DEV_16P
    HCCN_TOOL_SHOW_EXT_STAT
    $<$<STREQUAL:${ASCEND910_93_EX},true>:HCCN_TOOL_SHOW_EXT_V2>
    OPENSSL_SUPPRESS_DEPRECATED
)

install(TARGETS hccn_tool
    RUNTIME DESTINATION ${INSTALL_RUNTIME_DIR} OPTIONAL
)
