get_filename_component(SOMA_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)
 
if(${PRODUCT_SIDE} STREQUAL host)
    file(GLOB SOMA_MASTER_SRCS
        ${SOMA_DIR}/master/*.c
    )
 
    list(APPEND SVM_SRC_FILES ${SOMA_MASTER_SRCS})
else ()
    file(GLOB SOMA_DEVICE_SRCS
        ${SOMA_DIR}/*.c
        ${SOMA_DIR}/agent/*.c
        ${SOMA_DIR}/agent/soma_pool/*.c
        ${SOMA_DIR}/agent/soma_mem/*.c
        ${SOMA_DIR}/agent/soma_msg/*.c
        ${SOMA_DIR}/../../../abl/buff/dc/comm/lib/*.c
    )

    list(APPEND SVM_SRC_FILES ${SOMA_DEVICE_SRCS})
    list(APPEND SVM_SRC_INC_DIRS
        ${SOMA_DIR}/
        ${SOMA_DIR}/agent/
        ${SOMA_DIR}/agent/soma_pool/
        ${SOMA_DIR}/agent/soma_mem/
        ${SOMA_DIR}/agent/soma_pool/include
        ${SOMA_DIR}/../../../buff/dc/comm/common
        ${SOMA_DIR}/../../../buff/dc/comm/lib
    )
endif ()