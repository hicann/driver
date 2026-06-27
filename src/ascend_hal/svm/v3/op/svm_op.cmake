# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

get_filename_component(SVM_OP_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

if(${PRODUCT_SIDE} STREQUAL host)
    file(GLOB SVM_OP_HOST_SRCS
        ${SVM_OP_DIR}/*.c
        ${SVM_OP_DIR}/access/*.c
        ${SVM_OP_DIR}/memcpy_local/*.c
        ${SVM_OP_DIR}/memcpy_local_client/*.c
        ${SVM_OP_DIR}/memcpy/*.c
        ${SVM_OP_DIR}/memset/*.c
        ${SVM_OP_DIR}/memset_client/*.c
    )

    if(${ENABLE_UBE})
        file(GLOB SVM_OP_PCI_ADAPT_SRCS
            ${SVM_OP_DIR}/pci_adapt/*.c
        )
        file(GLOB SVM_OP_UB_ADAPT_SRCS
            ${SVM_OP_DIR}/ub_adapt/*.c
        )

        list(APPEND SVM_SRC_FILES
            ${SVM_OP_PCI_ADAPT_SRCS}
            ${SVM_OP_UB_ADAPT_SRCS}
        )
        list(APPEND SVM_SRC_INC_DIRS
            ${SVM_OP_DIR}/pci_adapt/
            ${SVM_OP_DIR}/ub_adapt/
        )
    else ()
        file(GLOB SVM_OP_PCI_ADAPT_SRCS
            ${SVM_OP_DIR}/pci_adapt/*.c
        )

        list(APPEND SVM_SRC_FILES
            ${SVM_OP_PCI_ADAPT_SRCS}
        )
        list(APPEND SVM_SRC_INC_DIRS
            ${SVM_OP_DIR}/pci_adapt/
        )
    endif ()

    list(APPEND SVM_SRC_FILES ${SVM_OP_HOST_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_OP_DIR}/
        ${SVM_OP_DIR}/access/
        ${SVM_OP_DIR}/memcpy_local/
        ${SVM_OP_DIR}/memcpy_local_client/
        ${SVM_OP_DIR}/memcpy/
        ${SVM_OP_DIR}/memset/
        ${SVM_OP_DIR}/memset_client/
    )
else ()
    file(GLOB SVM_OP_DEVICE_SRCS
        ${SVM_OP_DIR}/*.c
        ${SVM_OP_DIR}/memcpy_local/*.c
        ${SVM_OP_DIR}/memcpy_local_agent/*.c
        ${SVM_OP_DIR}/memset/*.c
        ${SVM_OP_DIR}/memset_agent/*.c
    )

    list(APPEND SVM_SRC_FILES ${SVM_OP_DEVICE_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_OP_DIR}/
        ${SVM_OP_DIR}/memcpy_local/
        ${SVM_OP_DIR}/memcpy_local_agent/
        ${SVM_OP_DIR}/memset/
        ${SVM_OP_DIR}/memset_agent/
    )
endif ()
