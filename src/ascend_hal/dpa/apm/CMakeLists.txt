# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
get_filename_component(BASE_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)
add_library(apm_obj OBJECT)

target_sources(apm_obj PRIVATE
        apm_ioctl.c
        apm_user_master.c
        apm_user_slave.c
        apm_user_res_map.c
        apm_user_slave_status.c
        apm_user_slave_ssid.c
)

target_include_directories(apm_obj PRIVATE
        ${DRIVER_HAL_INC_DIR}
        ${C_SEC_INCLUDE}
        ${DRIVER_USER_DIR}/inc
        ${DRIVER_USER_DIR}/inc/dpa
        ${DRIVER_KERNEL_DIR}/dpa/apm/command/ioctl
        ${DRIVER_USER_DIR}/msnpureport/inc/slog
)

target_link_libraries(apm_obj PRIVATE
        $<BUILD_INTERFACE:intf_pub>
        -ldl
        -Wl,--Bsymbolic
)

target_compile_definitions(apm_obj PRIVATE
        $<$<STREQUAL:${PRODUCT_SIDE},host>:DRV_HOST>
)
