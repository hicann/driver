# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

get_filename_component(SVM_ASSIGN_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

if(${PRODUCT_SIDE} STREQUAL host)
    file(GLOB SVM_ASSIGN_HOST_SRCS
        ${SVM_ASSIGN_DIR}/*.c
        ${SVM_ASSIGN_DIR}/gen_allocator/*.c
        ${SVM_ASSIGN_DIR}/va_allocator/*.c
        ${SVM_ASSIGN_DIR}/normal_malloc/*.c
        ${SVM_ASSIGN_DIR}/cache_malloc/*.c
        ${SVM_ASSIGN_DIR}/malloc_mng/*.c
        ${SVM_ASSIGN_DIR}/mpl/*.c
        ${SVM_ASSIGN_DIR}/mpl_client/*.c
        ${SVM_ASSIGN_DIR}/mms/*.c
        ${SVM_ASSIGN_DIR}/gap/*.c
        ${SVM_ASSIGN_DIR}/pci_adapt/*.c
        ${SVM_ASSIGN_DIR}/madvise/*.c
        ${SVM_ASSIGN_DIR}/madvise_client/*.c
    )

    list(APPEND SVM_SRC_FILES ${SVM_ASSIGN_HOST_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_ASSIGN_DIR}/
        ${SVM_ASSIGN_DIR}/gen_allocator/
        ${SVM_ASSIGN_DIR}/va_allocator/
        ${SVM_ASSIGN_DIR}/normal_malloc/
        ${SVM_ASSIGN_DIR}/cache_malloc/
        ${SVM_ASSIGN_DIR}/malloc_mng/
        ${SVM_ASSIGN_DIR}/mpl/
        ${SVM_ASSIGN_DIR}/mpl_client/
        ${SVM_ASSIGN_DIR}/mms/
        ${SVM_ASSIGN_DIR}/gap/
        ${SVM_ASSIGN_DIR}/pci_adapt/
        ${SVM_ASSIGN_DIR}/madvise/
        ${SVM_ASSIGN_DIR}/madvise_client/
    )
else ()
    file(GLOB SVM_ASSIGN_DEVICE_SRCS
        ${SVM_ASSIGN_DIR}/*.c
        ${SVM_ASSIGN_DIR}/mpl/*.c
        ${SVM_ASSIGN_DIR}/mpl_agent/*.c
        ${SVM_ASSIGN_DIR}/va_allocator_agent/*.c
        ${SVM_ASSIGN_DIR}/gap_agent/*.c
        ${SVM_ASSIGN_DIR}/madvise/*.c
        ${SVM_ASSIGN_DIR}/madvise_agent/*.c
    )

    list(APPEND SVM_SRC_FILES ${SVM_ASSIGN_DEVICE_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_ASSIGN_DIR}/
        ${SVM_ASSIGN_DIR}/mpl/
        ${SVM_ASSIGN_DIR}/mpl_agent/
        ${SVM_ASSIGN_DIR}/va_allocator_agent/
        ${SVM_ASSIGN_DIR}/gap_agent/
        ${SVM_ASSIGN_DIR}/madvise/
        ${SVM_ASSIGN_DIR}/madvise_agent/
    )
endif ()
