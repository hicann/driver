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
    hccn_base/tool/main.c
    hccn_base/tool/tool_cmd.c
    hccn_base/tool/tool_cmd_err.c
    hccn_base/tool/tool_cmd_parse.c
    hccn_base/tool/tool_shell_ops.c
    hccn_base/tool/tool_tcpip_ops.c
    hccn_base/tool/tool_ubase_ops.c
    hccn_base/tool/tool_bw_ops.c
    hccn_base/tool/tool_param.c
    hccn_base/tool/tool_log.c
    hccn_base/tool/tool_cfg_ops.c
    hccn_base/tool/tool_comm.c
    hccn_base/tool/tool_dev_info.c
    hccn_base/tool/tool_tls.c
    hccn_base/tool/tool_udis.c
    ${DRIVER_NETWORK_DIR}/common/dl_hal_function.c
    ${DRIVER_NETWORK_DIR}/common/dl_hal_function_internal.c
    ${DRIVER_NETWORK_DIR}/common/ascend_hal_dl.c
    ${DRIVER_NETWORK_DIR}/common/file_opt.c
    ${DRIVER_NETWORK_DIR}/common/network_comm.c
)

add_executable(hccn_tool ${hccn_tool_list})

target_include_directories(hccn_tool PRIVATE
    ${DRIVER_CUST_INC_DIR}
    ${DRIVER_NETWORK_DIR}/common/
    ${DRIVER_NETWORK_DIR}/inc/ascend950
    ${DRIVER_NETWORK_DIR}/orion/hccn/common
    ${DRIVER_NETWORK_DIR}/inc
    ${DRIVER_NETWORK_DIR}/crypt/inc/
    ${DRIVER_NETWORK_DIR}/orion/hccn/host/hccn_base/dsmi
    ${DRIVER_NETWORK_DIR}/orion/hccn/host/hccn_base/tool
    ${DRIVER_NETWORK_DIR}/orion/hccn/host/hccn_base/tool/product
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/inc/dmc
    ${DRIVER_USER_DIR}/msnpureport/inc/slog
    $<IF:$<STREQUAL:${ENABLE_UBE},true>,/usr/include/ub/umdk/urma,${DRIVER_NETWORK_DIR}/inc/stub>
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

add_dependencies(hccn_tool extract_driver_device)
target_link_directories(hccn_tool PRIVATE 
    ${CMAKE_BINARY_DIR}/lib/lib64/common
    ${CMAKE_BINARY_DIR}/lib/lib64/driver
)

install(TARGETS hccn_tool
    RUNTIME DESTINATION ${INSTALL_RUNTIME_DIR} OPTIONAL
)
