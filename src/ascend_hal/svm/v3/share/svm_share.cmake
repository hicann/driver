# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

get_filename_component(SVM_SHARE_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

if(${PRODUCT_SIDE} STREQUAL host)
    file(GLOB SVM_SHARE_HOST_SRCS
        ${SVM_SHARE_DIR}/*.c
        ${SVM_SHARE_DIR}/smm/*.c
        ${SVM_SHARE_DIR}/smm_client/*.c
        ${SVM_SHARE_DIR}/svmm/*.c
        ${SVM_SHARE_DIR}/casm/*.c
        ${SVM_SHARE_DIR}/casm_map/*.c
        ${SVM_SHARE_DIR}/casm_adapt/cross_server/master/*.c
        ${SVM_SHARE_DIR}/register_to_master/*.c
        ${SVM_SHARE_DIR}/dma_map/*.c
    )

    file(GLOB SVM_SHARE_PCI_ADAPT_SRCS
        ${SVM_SHARE_DIR}/pcie_adapt/*.c
    )
    file(GLOB SVM_SHARE_UB_ADAPT_SRCS
        ${SVM_SHARE_DIR}/ub_adapt/*.c
    )

    list(APPEND SVM_SRC_FILES
        ${SVM_SHARE_PCI_ADAPT_SRCS}
        ${SVM_SHARE_UB_ADAPT_SRCS}
    )
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_SHARE_DIR}/pcie_adapt/
        ${SVM_SHARE_DIR}/ub_adapt/
    )

    list(APPEND SVM_SRC_FILES ${SVM_SHARE_HOST_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_SHARE_DIR}/
        ${SVM_SHARE_DIR}/smm/
        ${SVM_SHARE_DIR}/smm_client/
        ${SVM_SHARE_DIR}/svmm/
        ${SVM_SHARE_DIR}/casm/
        ${SVM_SHARE_DIR}/casm_map/
        ${SVM_SHARE_DIR}/dma_map/
        ${SVM_SHARE_DIR}/register_to_master/
    )
else ()
    file(GLOB SVM_SHARE_DEVICE_SRCS
        ${SVM_SHARE_DIR}/*.c
        ${SVM_SHARE_DIR}/smm/*.c
        ${SVM_SHARE_DIR}/smm_agent/*.c
    )

    list(APPEND SVM_SRC_FILES ${SVM_SHARE_DEVICE_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_SHARE_DIR}/
        ${SVM_SHARE_DIR}/smm/
        ${SVM_SHARE_DIR}/smm_agent/
    )
endif ()
