set(asdrv_svm_depends asdrv_pbl ascend_kernel_open_adapt asdrv_dpa asdrv_esched drv_pcie_host drv_seclib_host)

add_host_ko(LOCAL_MODULE asdrv_svm
    KO_SRC_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}
    MAKE_ARGS ${MAKE_ARGS}
    TARGETE_DPENDS "${asdrv_svm_depends}")