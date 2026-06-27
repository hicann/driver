# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------
target_sources(drvdsmi_host PRIVATE
    $<$<NOT:$<STREQUAL:${PRODUCT},ascend950>>:${CMAKE_CURRENT_SOURCE_DIR}/hash_table.c>
)

add_library(drv_hash_obj OBJECT)

target_sources(drv_hash_obj PRIVATE
    hash_table.c
)

target_include_directories(drv_hash_obj PRIVATE
    ${BASE_DIR}
    ${BASE_DIR}/inc
    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/msnpureport/inc/slog/
    ${C_SEC_INCLUDE}/
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_USER_DIR}/inc/dmc
    ${DRIVER_USER_DIR}/dmc/device_monitor/include
    ${DRIVER_USER_DIR}/dmc/device_monitor/lib/include
)

target_link_libraries(drv_hash_obj PRIVATE
    $<BUILD_INTERFACE:intf_pub>
)

target_compile_definitions(drv_hash_obj PRIVATE
    $<$<STREQUAL:${PRODUCT_SIDE},host>:DRV_HOST>
)
