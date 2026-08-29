/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#include "dvpp_sqe_update.h"

#include "ascend_kernel_hal.h"
#include "ts_agent_dvpp.h"
#include "comm_kernel_interface.h"
#include "dvpp_sqe_update_phy.h"
#include "dvpp_sqe_update_vir.h"
#include "dvpp_cmdlist.h"
#include "dvpp_cmdlist_log.h"
#include "dvpp_sqe_update_comm.h"
#include "dvpp_sqe_para_check.h"
#include "dvpp_vcm_host.h"
#include "dvpp_cmdlist_ioctl.h"

typedef enum {
    DVPP_PHY_MACHINE = 0,
    DVPP_VIR_MACHINE,
    DVPP_BUTT_MACHINE,
} DVPP_MACHINE_SCENE;

static int32_t check_addr_read_only(uint64_t addr, uint64_t len)
{
    return hal_kernel_svm_addr_is_read_only(addr, len);
}

static int32_t dvpp_sqe_update(uint32_t devid, uint32_t tsid, int pid, void *sqe, DVPP_MACHINE_SCENE scene)
{
    int32_t ret = 0;
    dvpp_sqe_args *sqe_args = NULL;

    if (sqe == NULL) {
        DVPP_CMDLIST_LOG_ERROR("sqe passed from outside is null.\n");
        return -1;
    }
    sqe_args = (dvpp_sqe_args *)sqe;

    if (check_dvpp_sqe_args(sqe_args) != 0) {
        DVPP_CMDLIST_LOG_ERROR("check dvpp sqe args fail.\n");
        return -1;
    }

    if ((check_addr_read_only(sqe_args->cmdbuf_uva, sqe_args->cmdbuf_size)) == 0) {
        DVPP_CMDLIST_LOG_ERROR("cmdbuf is not read only.\n");
        return -1;
    }

    switch (scene) {
        case DVPP_PHY_MACHINE: {
            ret = dvpp_sqe_update_phy_mach(devid, pid, sqe);
            if (ret != 0) {
                DVPP_CMDLIST_LOG_ERROR("dvpp update sqe fail in phy scene.\n");
                return -1;
            }
            break;
        }
        case DVPP_VIR_MACHINE: {
#ifdef SUPPORT_VIR_MACH
            ret = dvpp_sqe_update_vir_mach(devid, pid, sqe);
            if (ret != 0) {
                DVPP_CMDLIST_LOG_ERROR("dvpp update sqe fail in vir scene.\n");
                return -1;
            }
#endif
            break;
        }
        case DVPP_BUTT_MACHINE: {
            DVPP_CMDLIST_LOG_ERROR("unknown machine scene.\n");
            return -1;
        }
        default:
            break;
    }

    return 0;
}

static int32_t dvpp_sqe_update_ts_check(uint32_t devid, uint32_t tsid, int pid, void *sqe)
{
    dvpp_sqe_args *sqe_args = (dvpp_sqe_args *)sqe;
    if (sqe_args == NULL) {
        DVPP_CMDLIST_LOG_ERROR("sqe passed from outside is null.\n");
        return -1;
    }

    if ((check_addr_read_only(sqe_args->cmdbuf_uva_beg, sqe_args->cmdbuf_size)) == 0) {
        DVPP_CMDLIST_LOG_ERROR("cmdbuf is not read only.\n");
        return -1;
    }

    return 0;
}

static int32_t dvpp_sqe_gen_cmdlist_handle_vir(uint32_t dev_id, uint32_t fid, void *msg_data, uint32_t msg_data_len)
{
    int32_t ret;
    if (msg_data_len != sizeof(struct dvpp_sqe)) {
        DVPP_CMDLIST_LOG_ERROR("dvpp sqe gen cmdlist msg_data_len=%u invalid.\n", msg_data_len);
        return -1;
    }
    // 处理来自虚拟机侧的sqe，根据args_addr中存的tlvlist结构信息，生成cmdlist并拷入pa内存中
    ret = dvpp_sqe_update(dev_id, 0, 0, msg_data, DVPP_VIR_MACHINE);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp update vir sqe fail ret=%d devid=%u fid=%u\n", ret, dev_id, fid);
        return -1;
    }
    return 0;
}

static int32_t dvpp_gen_cmdlist_handler(dvpp_cmdlist_ioctl_args *arg)
{
    int32_t ret;
    int32_t pid;
    uint32_t devid;
    uint32_t phyid; // 容器场景需要使用打平后的device id来申请dma内存
    dvpp_gen_cmdlist_user_data user_data = {0};
    struct dvpp_sqe sqe = {0};

    ret = dvpp_get_gen_cmdlist_info_from_ioctl(arg, &user_data, &pid, &devid, &phyid, &sqe);
    if (ret != 0) {
        return ret;
    }

    // 处理来自物理机iotcl的sqe，完成uva地址转pa地址，根据args_addr中存的tlvlist结构信息，生成cmdlist并拷入pa内存中
    ret = dvpp_sqe_update(phyid, 0, pid, &sqe, DVPP_PHY_MACHINE);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("gen cmdlist phyid=%u pid=%d seq update failed ret=%d\n", phyid, pid, ret);
        return ret;
    }

    ret = dvpp_set_gen_cmdlist_sqe_to_user_data(&sqe, &user_data);
    if (ret != 0) {
        return ret;
    }
    return 0;
}

void dvpp_sqe_update_init(void)
{
    cmdlist_case cmd_case;
    int32_t ret = 0;
    // 挂接响应tsagent的sqe update请求钩子函数
    ts_agent_dvpp_ops_t dvpp_ops = {
        .dvpp_sqe_update = dvpp_sqe_update_ts_check,
    };
    tsagent_dvpp_register(&dvpp_ops);

#ifdef SUPPORT_VIR_MACH
    // 挂接响应虚拟机的sqe update请求钩子函数，虚拟机场景
    ret = dvpp_vcm_register_msg_recv_cb(DVPP_VCM_GEN_CMDLIST, dvpp_sqe_gen_cmdlist_handle_vir);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp_vcm_register_msg_recv_cb failed cmd=%d\n", (int32_t)DVPP_VCM_GEN_CMDLIST);
        return;
    }
#endif

    // 挂接响应iotcl的sqe update请求钩子函数，纯物理机场景
    cmd_case.cmd = GEN_CMDLIST;
    cmd_case.handler = dvpp_gen_cmdlist_handler;
    ret = dvpp_set_gen_cmdlist_func(&cmd_case);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp_set_gen_cmdlist_func failed cmd=%d\n", (int32_t)GEN_CMDLIST);
        return;
    }
}

void dvpp_sqe_update_uninit(void)
{
    tsagent_dvpp_unregister();
}