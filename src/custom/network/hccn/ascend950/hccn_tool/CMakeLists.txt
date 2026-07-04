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
    tool_cmd.c
    tool_cmd_err.c
    tool_cmd_parse.c
    tool_shell_ops.c
    tool_tcpip_ops.c
    tool_ubase_ops.c
    tool_bw_ops.c
    tool_param.c
    tool_log.c
    tool_cfg_ops.c
    tool_comm.c
    tool_dev_info.c
    tool_tls.c
    tool_udis.c
    ${DRIVER_CUST_DIR}/network/common/ascend950/dl_hal_function.c
    ${DRIVER_CUST_DIR}/network/common/ascend950/dl_hal_function_internal.c
    ${DRIVER_CUST_DIR}/network/common/ascend950/ascend_hal_dl.c
    ${DRIVER_CUST_DIR}/network/common/ascend950/file_opt.c
    ${DRIVER_CUST_DIR}/network/common/ascend950/network_comm.c
)

add_executable(hccn_tool ${hccn_tool_list})

target_include_directories(hccn_tool PRIVATE
    ${DRIVER_CUST_INC_DIR}
    ${DRIVER_CUST_DIR}/network/inc
    ${DRIVER_CUST_DIR}/network/inc/ascend950
    ${DRIVER_CUST_DIR}/network/common/ascend950
    ${DRIVER_CUST_DIR}/network/dsmi/ascend950
    ${DRIVER_CUST_DIR}/network/hccn/ascend950/common
    ${DRIVER_CUST_DIR}/network/hccn/ascend950/hccn_product_ext
    ${DRIVER_CUST_DIR}/network/hccn/ascend950/hccn_tool
    $<IF:$<STREQUAL:${ENABLE_UBE},true>,/usr/include/ub/umdk/urma,${DRIVER_CUST_DIR}/network/inc/ascend950/urma>

    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/inc/dmc
    ${DRIVER_USER_DIR}/msnpureport/inc/slog
)

target_compile_options(hccn_tool PRIVATE
    -fPIC -rdynamic -fno-strict-aliasing -fsigned-char -fno-common)

target_link_libraries(hccn_tool PRIVATE
    $<BUILD_INTERFACE:mmpa_headers>
    c_sec
    drvdsmi_host
    mmpa
    ascend_hal
    ascend_kms
    hccntls
    crypto
    cmscbb
    mbedcrypto
    mbedx509
    mbedtls
    -Wl,--no-whole-archive
    -lrt
    -ldl
)

target_link_directories(hccn_tool PRIVATE
    # avoid libascend_hal linking urma symbol not found issue
    ${CMAKE_INSTALL_PREFIX}/lib
)

target_compile_definitions(hccn_tool PRIVATE
    DRV_HOST
    OPENSSL_SUPPRESS_DEPRECATED
)

target_link_directories(hccn_tool PRIVATE 
    ${CMAKE_BINARY_DIR}/lib/lib64/common
    ${CMAKE_BINARY_DIR}/lib/lib64/driver
)

set(INSTALL_RUNTIME_DIR bin)
install(TARGETS hccn_tool
    RUNTIME DESTINATION ${INSTALL_RUNTIME_DIR} OPTIONAL
)