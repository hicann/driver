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
    main.c
    cmd.c
    cmd_ext.c
    tool_ops.c
    tool_ops_ext.c
    tool_roce.c
    tool_tls.c
    tool_tls_ext.c
    tool_dcqcn.c
    tool.c
    cfg.c
    log.c
    ${DRIVER_CUST_DIR}/network/common/ascend910B/file_opt.c
    ${DRIVER_CUST_DIR}/network/common/ascend910B/network_comm.c
)

add_executable(hccn_tool ${hccn_tool_list})

target_include_directories(hccn_tool PRIVATE
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_CUST_DIR}/include
    ${DRIVER_CUST_DIR}/network/inc
    ${DRIVER_CUST_DIR}/network/inc/ascend910B
    ${DRIVER_USER_DIR}/dmc/dsmi/dsmi_product_ext
    ${DRIVER_KERNEL_DIR}/dms/command/ioctl/
    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/inc/dms
    ${DRIVER_USER_DIR}/msnpureport/inc/slog
    ${DRIVER_CUST_DIR}/network/dsmi/ascend910B
    ${DRIVER_CUST_DIR}/network/hccn/ascend910B/common
    ${DRIVER_CUST_DIR}/network/hccn/ascend910B/hccn_tool
    ${DRIVER_CUST_DIR}/network/common/ascend910B
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
