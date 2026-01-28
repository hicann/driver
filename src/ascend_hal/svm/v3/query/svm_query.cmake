get_filename_component(SVM_QUERY_DIR "${CMAKE_CURRENT_LIST_DIR}" ABSOLUTE)
file(GLOB SVM_QUERY_HOST_SRCS
    ${SVM_QUERY_DIR}/*.c
    ${SVM_QUERY_DIR}/get_mem_size/client/*.c
    ${SVM_QUERY_DIR}/get_mem_token_info/*.c
    ${SVM_QUERY_DIR}/pci_adapt/*.c
)

list(APPEND SVM_SRC_FILES ${SVM_QUERY_HOST_SRCS})
list(APPEND SVM_SRC_INC_FILES
    ${SVM_QUERY_DIR}
    ${SVM_QUERY_DIR}/get_mem_size/client/
    ${SVM_QUERY_DIR}/get_mem_token_info/
    ${SVM_QUERY_DIR}/pci_adapt/
)
