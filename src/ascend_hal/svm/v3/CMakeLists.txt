get_filename_component(SVM_USER_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)

set(SVM_SRC_FILES)
set(SVM_SRC_INC_FILES)
set(SVM_COMPILE_DEFINITIONS)

if(${ENABLE_UBE})
    list(APPEND SVM_COMPILE_DEFINITIONS
        CFG_FEATURE_SUPPORT_UB
    )
endif()

list(APPEND SVM_SRC_INC_DIRS
    ${SVM_USER_DIR}/inc/
    ${SVM_USER_DIR}/inc/assign
    ${SVM_USER_DIR}/inc/def
    ${SVM_USER_DIR}/inc/op
    ${SVM_USER_DIR}/inc/share
    ${SVM_USER_DIR}/inc/query
    ${SVM_USER_DIR}/inc/umc
    ${SVM_USER_DIR}/command/msg
    ${SVM_USER_DIR}/inc/urma_adapt
    ${DRIVER_KERNEL_DIR}/svm/v3/command/ioctl/
)

include(${SVM_USER_DIR}/api/svm_api.cmake)
include(${SVM_USER_DIR}/assign/svm_assign.cmake)
include(${SVM_USER_DIR}/share/svm_share.cmake)
include(${SVM_USER_DIR}/op/svm_op.cmake)
include(${SVM_USER_DIR}/query/svm_query.cmake)
include(${SVM_USER_DIR}/sys_cmd/svm_sys_cmd.cmake)
include(${SVM_USER_DIR}/umc/svm_umc.cmake)
include(${SVM_USER_DIR}/dbi/svm_dbi.cmake)
include(${SVM_USER_DIR}/mem_show_cfg/svm_mem_show_cfg.cmake)
include(${SVM_USER_DIR}/urma_adapt/svm_urma_adapt.cmake)
include(${SVM_USER_DIR}/apbi/svm_apbi.cmake)

add_library(devmm_obj OBJECT)

target_sources(devmm_obj PRIVATE
    ${SVM_SRC_FILES}
)

target_include_directories(devmm_obj PRIVATE
    ${DRIVER_HAL_INC_DIR}
    ${DRIVER_USER_DIR}/msnpureport/inc/slog/
    ${DRIVER_USER_DIR}/msnpureport/inc/libc_sec/
    ${DRIVER_USER_DIR}/dmc/device_monitor/lib/include
    ${DRIVER_USER_DIR}/pbl/commlib
    ${DRIVER_USER_DIR}/buff/dc/comm/lib

    ${DRIVER_USER_DIR}/inc
    ${DRIVER_USER_DIR}/inc/pbl
    ${DRIVER_USER_DIR}/inc/common

    ${DRIVER_KERNEL_DIR}/inc
    ${DRIVER_KERNEL_DIR}/dpa/apm/command/ioctl

    ${SVM_SRC_INC_DIRS}

    ${DRIVER_USER_DIR}/svm/v3/urma/code/include
    ${DRIVER_USER_DIR}/svm/v3/urma/lib/include
)

target_compile_definitions(devmm_obj PRIVATE
    $<$<STREQUAL:${PRODUCT_SIDE},host>:DRV_HOST>
    ${SVM_COMPILE_DEFINITIONS}
)

target_link_libraries(devmm_obj PRIVATE

)

target_compile_options(devmm_obj PRIVATE

)

set(INSTALL_RUNTIME_DIR bin)