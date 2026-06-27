# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
add_library(ubmem_dev_obj OBJECT)

target_sources(ubmem_dev_obj PRIVATE
    ${MODULE_SRC_DIR}/ubmm_dev.c
)

target_include_directories(ubmem_dev_obj PRIVATE
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_USER_DIR}/msnpureport/inc/slog
    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/inc/pbl
    ${DRIVER_USER_DIR}/inc/mmpa_sdk
    ${DRIVER_KERNEL_DIR}/pbl/dev_urd/command/ioctl
    ${DRIVER_KERNEL_DIR}/dms/command/ioctl
    ${DRIVER_KERNEL_DIR}/pbl/uda/command/ioctl
)

target_link_libraries(ubmem_dev_obj PRIVATE
    $<BUILD_INTERFACE:c_sec_headers>
    $<BUILD_INTERFACE:intf_pub>
    -ldl
    -Wl,--Bsymbolic
)

target_compile_definitions(ubmem_dev_obj PRIVATE
    DRV_HOST
)

target_compile_options(ubmem_dev_obj PRIVATE
    -fno-common
    -funsigned-char
    -Werror
    -Wformat=2
    $<$<VERSION_GREATER:${CMAKE_C_COMPILER_VERSION},4.8.5>: -Wdate-time>
    -Wfloat-equal
    -Wswitch-default
    -Wshadow
    -Wframe-larger-than=2048
    -Wvla
    -Wunused
    -Wundef
    -Wextra
    -fno-common
    -Wstrict-prototypes
    -Wcast-align
    -Wcast-qual
    -Wno-strict-prototypes
    -Wno-cast-align
    -Wno-cast-qual
    -Wno-sign-compare
    -Wno-unused-parameter
    -Wno-missing-field-initializers
    -Wno-missing-braces
)