#!/bin/bash
# ------------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# ------------------------------------------------------------------------------------------------------------

TIMESTAMP=$(date +"%Y-%m-%d-%H-%M-%S")
hal_dir="./hal_${TIMESTAMP}"
mkdir -p ${hal_dir}
echo "Start exporting logs and files to path: ${hal_dir}"


#=============start /proc/queue/===============
mkdir -p ${hal_dir}/queue/
find /proc/queue/ -type f -exec echo -e "\n" {} \; -exec cat >  ${hal_dir}/queue/hal_proc_queue.log {} \;
chmod 640 ${hal_dir}/queue/hal_proc_queue.log
echo "export queue logs finished, path: queue/"
#=============end /proc/queue/===============

#=============start /proc/xsmem/===============
mkdir -p ${hal_dir}/xsmem/
find /proc/xsmem/ -type f -exec echo -e "\n" {} \; -exec cat >  ${hal_dir}/xsmem/hal_proc_xsmem.log {} \;
chmod 640 ${hal_dir}/xsmem/hal_proc_xsmem.log
echo "export xsmem logs finished, path: xsmem/"
#=============end /proc/xsmem/===============

#=============start /proc/event_sched/===============
mkdir -p ${hal_dir}/event_sched/
cp /sys/devices/virtual/devdrv_manager/davinci_manager/node/* ${hal_dir}/event_sched/ 2>/dev/null
chmod 640 ${hal_dir}/event_sched/*
echo "export event_sched logs finished, path: event_sched/"
#=============end /proc/event_sched/===============

#===============start pcie=================
mkdir -p ${hal_dir}/pcie/
lspci -vt > ${hal_dir}/pcie/pcie_dev_info.log
lspci -vv >> ${hal_dir}/pcie/pcie_dev_info.log
dmesg > ${hal_dir}/pcie/host_dmesg.log
chmod 640 ${hal_dir}/pcie/pcie_dev_info.log
chmod 640 ${hal_dir}/pcie/host_dmesg.log
echo "export pcie logs finished, path: pcie/"
#===============end   pcie=================

#===============start vnic=================
mkdir -p ${hal_dir}/vnic/
vnic_dir=$(find /sys/ -name vnic | head -n 1)
cat $vnic_dir/stat > ${hal_dir}/vnic/vnic_state.log
chmod 640 ${hal_dir}/vnic/vnic_state.log
echo "export vnic logs finished, path: vnic/"
#===============end   vnic=================

#===============start hdc=================
mkdir -p ${hal_dir}/hdc/
hdc_dir=$(find /sys/ -name hdc | head -n 1)
dev_num=$(find /sys/ -name devdrv_sysfs_bdf_to_devid | wc -l)
for ((dev_id = 0; dev_id < dev_num; dev_id++)); do
    echo $dev_id > $hdc_dir/dev
    cat $hdc_dir/dev_stat >> ${hal_dir}/hdc/dev_stat.log
    for chan_id in {0..21}
    do
        echo $chan_id > $hdc_dir/chan
        echo $chan_id > $hdc_dir/server
        cat $hdc_dir/chan_stat >> ${hal_dir}/hdc/chan_stat.log
        cat $hdc_dir/server_stat >> ${hal_dir}/hdc/server_stat.log
    done
done
chmod 640 ${hal_dir}/hdc/dev_stat.log
chmod 640 ${hal_dir}/hdc/chan_stat.log
chmod 640 ${hal_dir}/hdc/server_stat.log
echo "export hdc logs finished, path: hdc/"
#===============end   hdc=================

#=============start svm===============
mkdir -p ${hal_dir}/svm/
find /proc/svm/ -type f -exec echo -e "\n" {} \; -exec cat >  ${hal_dir}/svm/hal_proc_svm.log {} \;
chmod 640 ${hal_dir}/svm/hal_proc_svm.log
echo "export svm logs finished, path: svm/"
#=============end svm===============

#=============start trsdrv===============
mkdir -p ${hal_dir}/trsdrv/
if [ -e /proc/trs_chan/ ];then
find /proc/trs_chan/ -type f -exec echo -e "\n" {} \; -exec cat >  ${hal_dir}/trsdrv/hal_proc_trsdrv.log {} \;
find /proc/trs_chan_mem_node/ -type f -exec echo -e "\n" {} \; -exec cat >>  ${hal_dir}/trsdrv/hal_proc_trsdrv.log {} \;
find /proc/trs_core/ -type f -exec echo -e "\n" {} \; -exec cat >>  ${hal_dir}/trsdrv/hal_proc_trsdrv.log {} \;
fi
if [ -e /sys/kernel/debug/tsdrv/ ];then
find /sys/kernel/debug/tsdrv/ -type f -exec echo -e "\n" {} \; -exec cat >>  ${hal_dir}/trsdrv/hal_proc_trsdrv.log {} \;
fi
chmod 640 ${hal_dir}/trsdrv/hal_proc_trsdrv.log
echo "export trsdrv logs finished, path: trsdrv/"
#=============end trsdrv===============

#=============start apm===============
if [ -e /proc/apm/ ];then
mkdir -p ${hal_dir}/apm/
find /proc/apm/ -type f -exec echo -e "\n" {} \; -exec cat >  ${hal_dir}/apm/hal_proc_apm.log {} \;
chmod 640 ${hal_dir}/apm/hal_proc_apm.log
echo "export apm logs finished, path: apm/"
fi
#=============end apm===============

#=============start uda===============
if [ -e /proc/uda/ ];then
    mkdir -p ${hal_dir}/uda/
    chmod 700 ${hal_dir}/uda/
    find /proc/uda/ -type f -exec echo -e "\n" {} \; -exec cat >  ${hal_dir}/uda/hal_proc_uda.log {} \;
    chmod 400 ${hal_dir}/uda/hal_proc_uda.log
    echo "export uda logs finished, path: uda/"
fi
#=============end uda===============

#=============start dms===============
mkdir -p ${hal_dir}/dms/
chmod 700 ${hal_dir}/dms/
echo "feature_list:" > ${hal_dir}/dms/hal_proc_dms.log
cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/feature_list >> ${hal_dir}/dms/hal_proc_dms.log
echo "node_list:" >> ${hal_dir}/dms/hal_proc_dms.log
cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/node_list >> ${hal_dir}/dms/hal_proc_dms.log
echo "sensor_list:" >> ${hal_dir}/dms/hal_proc_dms.log
cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/sensor_list >> ${hal_dir}/dms/hal_proc_dms.log
echo "subscribe_handle:" >> ${hal_dir}/dms/hal_proc_dms.log
cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/subscribe_handle >> ${hal_dir}/dms/hal_proc_dms.log
echo "subscribe_process:" >> ${hal_dir}/dms/hal_proc_dms.log
cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/subscribe_process >> ${hal_dir}/dms/hal_proc_dms.log

udev_list=($(cat /proc/uda/udevice | grep -Eo "udevid [0-9]+ type" | awk -F' ' '{print $2}'))
for udev_id in ${udev_list[@]}; do
    if (( $udev_id >= 64 )); then
        continue
    fi
    echo "udev_id: ${udev_id}" >> ${hal_dir}/dms/hal_proc_dms.log
    echo ${udev_id} > /sys/devices/virtual/devdrv_manager/davinci_manager/dms/channel_flux
    echo ${udev_id} > /sys/devices/virtual/devdrv_manager/davinci_manager/dms/convergent_diagrams
    echo ${udev_id} > /sys/devices/virtual/devdrv_manager/davinci_manager/dms/event_list
    echo ${udev_id} > /sys/devices/virtual/devdrv_manager/davinci_manager/dms/mask_list
    echo "channel_flux:" >> ${hal_dir}/dms/hal_proc_dms.log
    cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/channel_flux >> ${hal_dir}/dms/hal_proc_dms.log
    echo "convergent_diagrams:" >> ${hal_dir}/dms/hal_proc_dms.log
    cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/convergent_diagrams >> ${hal_dir}/dms/hal_proc_dms.log
    echo "event_list:" >> ${hal_dir}/dms/hal_proc_dms.log
    cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/event_list >> ${hal_dir}/dms/hal_proc_dms.log
    echo "mask_list:" >> ${hal_dir}/dms/hal_proc_dms.log
    cat /sys/devices/virtual/devdrv_manager/davinci_manager/dms/mask_list >> ${hal_dir}/dms/hal_proc_dms.log
done
chmod 400 ${hal_dir}/dms/hal_proc_dms.log
echo "export dms logs finished, path: dms/"
#=============end dms===============

#=============start dsmi=============
mkdir -p ${hal_dir}/dsmi/
chmod 700 ${hal_dir}/dsmi/
cat /proc/dsmi_log | grep -v DFX > ${hal_dir}/dsmi/dsmi.log
cat /proc/dsmi_log | grep DFX > ${hal_dir}/dsmi/dsmi_log_dfx.log
chmod 400 ${hal_dir}/dsmi/dsmi.log
chmod 400 ${hal_dir}/dsmi/dsmi_log_dfx.log
echo "export dsmi logs finished, path: dsmi/"
#=============end dsmi===============

echo "All modules export finished."