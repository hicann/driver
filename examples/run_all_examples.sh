#!/bin/bash
# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

set +e

SCRIPT_DIR=$(cd "$(dirname "$0")"; pwd)
REPO_DIR=$(cd "${SCRIPT_DIR}/.."; pwd)
DCMI_HEADER_PATH="${REPO_DIR}/src/custom/include/dcmi_interface_api.h"
DCMI_INSTALL_HEADER_PATH="/usr/local/dcmi/dcmi_interface_api.h"

if [ ! -f "${DCMI_INSTALL_HEADER_PATH}" ]; then
    cp "${DCMI_HEADER_PATH}" "${DCMI_INSTALL_HEADER_PATH}"
    cp_ret=$?
    if [ ${cp_ret} -ne 0 ]; then
        echo "COPY_HEADER_FAILED: ${DCMI_HEADER_PATH} -> ${DCMI_INSTALL_HEADER_PATH} ret=${cp_ret}"
        exit 1
    fi
fi


RUN_TARGETS=(
    #"dcmi/dcmi/run.sh|all"
    "devmng/0_device_p2p/run.sh|"
    #"resmng/queue_buff_esched/run.sh|"
    #"resmng/svm/0_svm_memcpy/run.sh|"
    #"resmng/trs/0_trs_shrid/run.sh|"
    #"resmng/uvm/developer_demo/run.sh|"
)

FAILED_COUNT=0
SUCCESS_COUNT=0
RESULTS=()

run_one_script() {
    local relative_path="$1"
    local arg_string="$2"
    local script_path="${SCRIPT_DIR}/${relative_path}"
    local script_dir
    local script_name
    local ret

    script_dir=$(dirname "${script_path}")
    script_name=$(basename "${script_path}")

    if [ ! -f "${script_path}" ]; then
        echo "MISSING: ${relative_path}"
        RESULTS+=("FAIL ${relative_path} 127")
        FAILED_COUNT=$((FAILED_COUNT + 1))
        return 127
    fi

    echo "======================================"
    echo "RUNNING: ${relative_path} ${arg_string}"
    echo "======================================"

    if [ -n "${arg_string}" ]; then
        (
            cd "${script_dir}" && bash "./${script_name}" ${arg_string}
        )
    else
        (
            cd "${script_dir}" && bash "./${script_name}"
        )
    fi
    ret=$?

    if [ ${ret} -eq 0 ]; then
        echo "RUN_SH_SUCCESS: ${relative_path}"
        RESULTS+=("PASS ${relative_path} 0")
        SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
    else
        echo "RUN_SH_FAILED: ${relative_path} ret=${ret}"
        RESULTS+=("FAIL ${relative_path} ${ret}")
        FAILED_COUNT=$((FAILED_COUNT + 1))
    fi

    echo
    return ${ret}
}

for target in "${RUN_TARGETS[@]}"; do
    relative_path="${target%%|*}"
    arg_string="${target#*|}"
    run_one_script "${relative_path}" "${arg_string}"
done

echo "============== SUMMARY =============="
for result in "${RESULTS[@]}"; do
    echo "${result}"
done
echo "SUCCESS_COUNT=${SUCCESS_COUNT}"
echo "FAILED_COUNT=${FAILED_COUNT}"

if [ ${FAILED_COUNT} -ne 0 ]; then
    exit 1
fi

exit 0
