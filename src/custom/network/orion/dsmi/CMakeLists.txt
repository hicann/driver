# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

get_filename_component(BASE_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)
set(source_list
    dsmi_cfg_ops.c
    dsmi_common.c
    dsmi_network_stub.c
    dsmi_network.c
    dsmi_optical.c
    dsmi_ubping.c
    ${DRIVER_NETWORK_DIR}/common/file_opt.c
    ${DRIVER_NETWORK_DIR}/orion/hccn/host/hccn_base/dsmi/ds_net_interface.c
)

add_library(dsmi_network SHARED ${source_list})

target_include_directories(dsmi_network PRIVATE
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_CUST_INC_DIR}
    ${DRIVER_CUST_DIR}/network/orion/hccn/host/hccn_base/tool
    ${DRIVER_CUST_DIR}/network/orion/hccn/host/hccn_base/dsmi
    ${DRIVER_CUST_DIR}/network/orion/hccn/common
    ${DRIVER_CUST_DIR}/network/common
    ${DRIVER_CUST_DIR}/network/inc
    ${DRIVER_CUST_DIR}/network/inc/ascend950
    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/inc/dmc
    ${DRIVER_USER_DIR}/inc/mmpa/
    ${DRIVER_USER_DIR}/dmc/dsmi/include
    ${DRIVER_USER_DIR}/dmc/device_monitor/include/
    ${DRIVER_USER_DIR}/dmc/device_monitor/lib/include/
    ${DRIVER_USER_DIR}/msnpureport/inc/slog
    ${DRIVER_KERNEL_DIR}/dms/command/ioctl/
    ${DRIVER_NETWORK_DIR}/inc
    ${DRIVER_NETWORK_DIR}/inc/ascend950
    ${DRIVER_NETWORK_DIR}/orion/hccn/common
    ${DRIVER_NETWORK_DIR}/orion/hccn/common/comm_ext/
    ${DRIVER_NETWORK_DIR}/orion/hccn/host/hccn_base/tool
    ${DRIVER_NETWORK_DIR}/orion/hccn/host/hccn_base/dsmi
    $<IF:$<STREQUAL:${ENABLE_UBE},true>,/usr/include/ub/umdk/urma,${DRIVER_NETWORK_DIR}/inc/stub>
)

target_compile_definitions(dsmi_network PRIVATE
    DRV_HOST
)

target_compile_options(dsmi_network PRIVATE
    -fvisibility=hidden -fPIC -fstack-protector-strong
)

target_link_options(dsmi_network PRIVATE
    -s -Wl,-z-relro,-z,now,-z,noexecstack -pie
)

target_link_libraries(dsmi_network PRIVATE
    c_sec
    drvdsmi_host
    ascend_hal
    cmscbb
    mbedcrypto
    mbedx509
    mbedtls
    -Wl,--no-whole-archive
    -lrt
    -ldl
)

add_dependencies(dsmi_network extract_driver_device_custom)
target_link_directories(dsmi_network PRIVATE ${CMAKE_BINARY_DIR}/lib/lib64/driver)

install(TARGETS dsmi_network
    LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR} OPTIONAL
)