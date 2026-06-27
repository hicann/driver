# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

get_filename_component(SVM_URMA_ADAPT_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

if(${PRODUCT_SIDE} STREQUAL host)
    if(${ENABLE_UBE})
        file(GLOB SVM_URMA_ADAPT_HOST_SRCS
            ${SVM_URMA_ADAPT_DIR}/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_jetty/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_chan/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_seg_register_client/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_seg_mng/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_adapt_init/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_seg_local/*.c
        )

        list(APPEND SVM_SRC_FILES ${SVM_URMA_ADAPT_HOST_SRCS})
        list(APPEND SVM_SRC_INC_DIRS
            ${SVM_URMA_ADAPT_DIR}/
            ${SVM_URMA_ADAPT_DIR}/inc
            ${SVM_URMA_ADAPT_DIR}/urma_jetty/
            ${SVM_URMA_ADAPT_DIR}/urma_chan/
            ${SVM_URMA_ADAPT_DIR}/urma_seg_register_client/
            ${SVM_URMA_ADAPT_DIR}/urma_seg_mng/
            ${SVM_URMA_ADAPT_DIR}/urma_adapt_init/
            ${SVM_URMA_ADAPT_DIR}/urma_seg_local/
        )
    else ()
	    file(GLOB SVM_URMA_ADAPT_HOST_SRCS
            ${SVM_URMA_ADAPT_DIR}/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_seg_register_client/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_seg_mng/*.c
            ${SVM_URMA_ADAPT_DIR}/urma_adapt_init/*.c
        )

        list(APPEND SVM_SRC_FILES ${SVM_URMA_ADAPT_HOST_SRCS})
        list(APPEND SVM_SRC_INC_DIRS
            ${SVM_URMA_ADAPT_DIR}/
            ${SVM_URMA_ADAPT_DIR}/inc
            ${SVM_URMA_ADAPT_DIR}/urma_seg_register_client/
            ${SVM_URMA_ADAPT_DIR}/urma_seg_mng/
            ${SVM_URMA_ADAPT_DIR}/urma_adapt_init/
        )
    endif ()
else ()
    file(GLOB SVM_URMA_ADAPT_DEVICE_SRCS
        ${SVM_URMA_ADAPT_DIR}/*.c
        ${SVM_URMA_ADAPT_DIR}/urma_jetty/*.c
        ${SVM_URMA_ADAPT_DIR}/urma_chan_agent/*.c
        ${SVM_URMA_ADAPT_DIR}/urma_seg_register_agent/*.c
        ${SVM_URMA_ADAPT_DIR}/urma_seg_local/*.c
    )

    list(APPEND SVM_SRC_FILES ${SVM_URMA_ADAPT_DEVICE_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SVM_URMA_ADAPT_DIR}/
        ${SVM_URMA_ADAPT_DIR}/inc
        ${SVM_URMA_ADAPT_DIR}/urma_jetty/
        ${SVM_URMA_ADAPT_DIR}/urma_chan_agent/
        ${SVM_URMA_ADAPT_DIR}/urma_seg_register_agent/
        ${SVM_URMA_ADAPT_DIR}/urma_seg_local/
    )
endif ()
