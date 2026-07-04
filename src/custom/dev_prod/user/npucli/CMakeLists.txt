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
get_filename_component(DCMI_DIR "${CMAKE_CURRENT_LIST_DIR}/../dcmi" ABSOLUTE)

set(SRC_LIST
    ${BASE_DIR}/src/npu_card_info.c
    ${BASE_DIR}/src/npu_card_set.c
    ${BASE_DIR}/src/npu_chip_info_ext.c
    ${BASE_DIR}/src/npu_chip_info.c
    ${BASE_DIR}/src/npu_chip_set_ext.c
    ${BASE_DIR}/src/npu_chip_set.c
    ${BASE_DIR}/src/npu_clear.c
    ${BASE_DIR}/src/npu_cmd_parse.c
    ${BASE_DIR}/src/npu_cms_api.c
    ${BASE_DIR}/src/npu_common_ext.c
    ${BASE_DIR}/src/npu_common.c
    ${BASE_DIR}/src/npu_error_code.c
    ${BASE_DIR}/src/npu_file_operate.c
    ${BASE_DIR}/src/npu_hpm_parse.c
    ${BASE_DIR}/src/npu_info_print_ch.c
    ${BASE_DIR}/src/npu_info_print_ext.c
    ${BASE_DIR}/src/npu_info_print.c
    ${BASE_DIR}/src/npu_info_watch.c
    ${BASE_DIR}/src/npu_info.c
    ${BASE_DIR}/src/npu_init.c
    ${BASE_DIR}/src/npu_parameter_parse.c
    ${BASE_DIR}/src/npu_run_env.c
    ${BASE_DIR}/src/npu_set_print.c
    ${BASE_DIR}/src/npu_set.c
    ${BASE_DIR}/src/npu_smi.c
    ${BASE_DIR}/src/npu_upgrade.c
)

set(NPUSMI_INC_DIRS
    ${C_SEC_INCLUDE}
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_CUST_INC_DIR}
    ${BASE_DIR}/inc
    ${DCMI_DIR}/dcmi_interface/inc
    ${DCMI_DIR}/dcmi_init/inc
    ${DCMI_DIR}/dcmi_inner/inc
)

add_executable(npu-smi ${SRC_LIST})

target_compile_definitions(npu-smi PRIVATE
    NPUSMI
    TOOL_VERSION="${PROJECT_VERSION}"
    $<$<STREQUAL:${PRODUCT},ascend950>:NPU_SMI_V2>
)

target_include_directories(npu-smi PRIVATE ${NPUSMI_INC_DIRS})

target_link_libraries(npu-smi PRIVATE
    dcmi
    dsmi_network
    cmscbb
    mbedcrypto
    mbedx509
    mbedtls
    c_sec
    drvdsmi_host
    mmpa
    ascend_hal
    pthread
    ${CMAKE_DL_LIBS}
    m
)

target_link_directories(npu-smi PRIVATE ${CMAKE_BINARY_DIR}/lib/lib64/driver)

set(INSTALL_RUNTIME_DIR bin)
install(TARGETS npu-smi
    RUNTIME DESTINATION ${INSTALL_RUNTIME_DIR} OPTIONAL)
