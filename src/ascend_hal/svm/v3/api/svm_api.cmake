# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

get_filename_component(SVM_API_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

if(${PRODUCT_SIDE} STREQUAL host)
    file(GLOB SVM_API_HOST_SRCS
        ${SVM_API_DIR}/*.c
        ${SVM_API_DIR}/master/*.c
        ${SVM_API_DIR}/master/task_group/*.c
    )

    list(APPEND SVM_SRC_FILES ${SVM_API_HOST_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_API_DIR}/master/
        ${SVM_API_DIR}/master/task_group/
    )
else ()
    file(GLOB SVM_API_DEVICE_SRCS
        ${SVM_API_DIR}/*.c
        ${SVM_API_DIR}/agent/*.c
        ${SVM_API_DIR}/agent/task_group/*.c
        ${SVM_API_DIR}/agent/task_group_sp/*.c
    )

    list(APPEND SVM_SRC_FILES ${SVM_API_DEVICE_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_API_DIR}/
        ${SVM_API_DIR}/agent/
        ${SVM_API_DIR}/agent/task_group/
        ${SVM_API_DIR}/agent/task_group_sp/
    )
endif ()
