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
#include "ka_share_pool.h"
#include "securec.h"
#include "ts_agent_dvpp.h"
#include "dvpp_tlv_decoder.h"
#include "dvpp_cmdlist.h"
#include "dvpp_cmdlist_log.h"
#include "dvpp_cmdlist_context.h"
#include "dvpp_cmdlist_util.h"
#include "dvpp_sqe_update_comm.h"
#include "dvpp_sqe_para_check.h"
#include "dvpp_mem_allocater_args.h"
#include "dvpp_cmdlist_ioctl.h"
#include "cmdbuf_hlist_ctx.h"

static inline int32_t check_addr_read_only(uint64_t addr, uint64_t len)
{
    // 对cmdbuf地址判断是否在只读地址段内
    return (int32_t)((addr >= KA_MMAP_SHARE_POOL_RO_START) && (addr <= KA_MMAP_SHARE_POOL_RO_END) &&
        ((addr + len) <= KA_MMAP_SHARE_POOL_RO_END) &&
        (len <= (KA_MMAP_SHARE_POOL_RO_END - KA_MMAP_SHARE_POOL_RO_START)));
}

static int32_t map_cmdbuf_to_kva(dvpp_comm_para *para, dvpp_sqe_args* sqe_args, dvpp_save_para *save_para,
    dvpp_cmdlist_private_data *data)
{
    dvpp_cmdlist_context *ctx = get_dvpp_cmdlist_ctx();
    cmdbuf_context cmdbuf_ctx;
    int ret;

    BEGIN_TIME_STAMP(ctx, sqe_args->streamid, sqe_args->taskid, time_cost_u2k_map);

    if (save_para->is_cmdbuf_pool) {
        sqe_args->cmdbuf_kva = search_cmdbuf_hlist(para->pid, save_para->chn_id, sqe_args->cmdbuf_uva, data);
        if (sqe_args->cmdbuf_kva != 0) {
            CALC_TIME_COST(ctx, sqe_args->streamid, sqe_args->taskid, time_cost_u2k_map);
            return 0;
        }
    }

    sqe_args->cmdbuf_kva = (uint64_t)(uintptr_t)ka_mg_sp_make_share_u2k(
        sqe_args->cmdbuf_uva, sqe_args->cmdbuf_size, para->pid);
    if (IS_ERR_VALUE(sqe_args->cmdbuf_kva)) {
        DVPP_CMDLIST_LOG_ERROR("cmdbuf addr k2u fail. ret:%ld, len:%u, pid:%d\n", \
            PTR_ERR((const void*)(sqe_args->cmdbuf_kva)), sqe_args->cmdbuf_size, para->pid);
        CALC_TIME_COST(ctx, sqe_args->streamid, sqe_args->taskid, time_cost_u2k_map);
        return -1;
    }
    if (save_para->is_cmdbuf_pool) {
        cmdbuf_ctx.pid = para->pid;
        cmdbuf_ctx.chn = save_para->chn_id;
        cmdbuf_ctx.uva = sqe_args->cmdbuf_uva;
        cmdbuf_ctx.kva = sqe_args->cmdbuf_kva;
        cmdbuf_ctx.size = sqe_args->cmdbuf_size;
        ret = add_cmdbuf_hlist(&cmdbuf_ctx, data);
        save_para->is_cmdbuf_pool = ((ret == 0) ? 1 : 0); // add failed, kva need to ka_mg_sp_unshare
    }

    CALC_TIME_COST(ctx, sqe_args->streamid, sqe_args->taskid, time_cost_u2k_map);

    return 0;
}

void resource_destroy(uint32_t pool_id, dvpp_save_para *save_para, dvpp_sqe_args *sqe_args)
{
    int32_t ret = 0;
    const int32_t spg_id = 0; // unshare kva, spg_id is not used
    free_args_memory(pool_id, sqe_args, save_para->args_kva);
    save_para->args_kva = 0;

    if (save_para->is_cmdbuf_pool == 0) {
        ret = mg_sp_unshare(save_para->cmdbuf_kva, save_para->cmdbuf_size, spg_id);
        if (ret != 0) {
            DVPP_CMDLIST_LOG_ERROR("unshare cmdbuf_size %llu, fail, ret = %d\n", save_para->cmdbuf_size, ret);
        }
        DVPP_CMDLIST_LOG_DEBUG("pid %d unshare cmdbuf_size %llu, ret = %d\n",
            current->tgid, save_para->cmdbuf_size, ret);
    }
    save_para->cmdbuf_kva = 0;
}

static void dvpp_save_cmdbuf_info(dvpp_sqe_args *sqe_args, dvpp_save_para *save_para)
{
    save_para->chn_id = sqe_args->chn_id;
    save_para->is_cmdbuf_pool = sqe_args->is_cmdbuf_pool;
    sqe_args->chn_id = 0; // reset to default value
    sqe_args->is_cmdbuf_pool = 0; // reset to default value
}

static int32_t dvpp_drv_ready(dvpp_sqe_args *sqe_args, dvpp_comm_para *para, dvpp_cmdlist_private_data *data)
{
    int32_t ret = 0;
    uint64_t alloc_size = 0;
    uint64_t tlv_stru_addr = 0;
    dvpp_save_para save_para;
    uint32_t pool_id;
    uint64_t cmdbuf_size_used = 0;
    const int32_t spg_id = 0; // unshare kva, spg_id is not used
    save_para.args_uva = sqe_args->args_addr;
    pool_id = para->devid;
    alloc_size = get_alloc_size(sqe_args, 0); // 0表示device平台不需要申请保存dma信息的内存
    save_para.is_use_mem_pool = sqe_args->is_use_mem_pool;
    save_para.args_kva = alloc_args_mem(pool_id, alloc_size, sqe_args);
    save_para.args_size = sqe_args->args_size;
    dvpp_save_cmdbuf_info(sqe_args, &save_para);
    if (save_para.args_kva == 0) {
        DVPP_CMDLIST_LOG_ERROR("alloc args kva fail.\n");
        goto FAIL0;
    }
    sqe_args->args_addr = save_para.args_kva;

    if (copy_args_from_user(&save_para, sqe_args)) {
        DVPP_CMDLIST_LOG_ERROR("copy args from user fail.\n");
        goto FAIL1;
    }

    if (map_cmdbuf_to_kva(para, sqe_args, &save_para, data) != 0) {
        DVPP_CMDLIST_LOG_ERROR("map cmdbuf uva to kva fail.\n");
        goto FAIL1;
    }

    save_para.cmdbuf_uva = sqe_args->cmdbuf_uva;
    save_para.cmdbuf_kva = sqe_args->cmdbuf_kva;
    save_para.cmdbuf_size = sqe_args->cmdbuf_size;
    tlv_stru_addr = sqe_args->args_addr + sqe_args->args_size;
    cmdbuf_size_used = sqe_args->cmdbuf_size;
    if (dvpp_comm_drv_ready(sqe_args, tlv_stru_addr, &cmdbuf_size_used) != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp drv comm ready fail.\n");
        goto FAIL2;
    }

    sqe_args->is_use_mem_pool = save_para.is_use_mem_pool; // 生成sqe的时候被修改
    resource_destroy(pool_id, &save_para, sqe_args);
    return 0;
FAIL2:
    ret = mg_sp_unshare(save_para.cmdbuf_kva, save_para.cmdbuf_size, spg_id);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("unshare cmdbuf_size %llu, fail, ret = %d\n", save_para.cmdbuf_size, ret);
    }
FAIL1:
    sqe_args->is_use_mem_pool = save_para.is_use_mem_pool; // 生成sqe的时候被修改
    free_args_memory(pool_id, sqe_args, save_para.args_kva);
    save_para.args_kva = 0;
FAIL0:
    return -1;
}

static int32_t dvpp_sqe_update(uint32_t devid, int pid, struct dvpp_sqe *sqe, dvpp_cmdlist_private_data *data)
{
    dvpp_sqe_args *sqe_args = NULL;
    time_cost_node *tmp_node = NULL;
    dvpp_comm_para comm_para;
    dvpp_cmdlist_context *ctx = get_dvpp_cmdlist_ctx();

    if (sqe == NULL) {
        DVPP_CMDLIST_LOG_ERROR("sqe passed from outside is null.\n");
        return -1;
    }
    sqe_args = (dvpp_sqe_args*)sqe;

    if (check_dvpp_sqe_args(sqe_args) != 0) {
        DVPP_CMDLIST_LOG_ERROR("check dvpp sqe args fail.\n");
        return -1;
    }

    if (!(check_addr_read_only(sqe_args->cmdbuf_uva, sqe_args->cmdbuf_size))) {
        DVPP_CMDLIST_LOG_ERROR("cmdbuf is not read only.\n");
        return -1;
    }

    if (ctx->time_cost_stat.enable == 1) {
        tmp_node = alloc_time_cost_node_from_ctx();
        tmp_node->taskid = sqe_args->taskid;
        tmp_node->streamid = sqe_args->streamid;
        add_time_cost_node_to_ctx(tmp_node);
    }

    comm_para.devid = 0;
    comm_para.pid   = current->tgid;
    if (dvpp_drv_ready(sqe_args, &comm_para, data) != 0) {
        DVPP_CMDLIST_LOG_ERROR("dvpp drv ready fail.\n");
        return -1;
    }

    return 0;
}

static int32_t dvpp_sqe_update_ts_check(uint32_t devid, uint32_t tsid, int pid, void* sqe)
{
    dvpp_sqe_args *sqe_args = (dvpp_sqe_args*)sqe;
    if (sqe == NULL) {
        DVPP_CMDLIST_LOG_ERROR("sqe passed from outside is null.\n");
        return -1;
    }

    if (!(check_addr_read_only(sqe_args->cmdbuf_uva_beg, sqe_args->cmdbuf_size))) {
        DVPP_CMDLIST_LOG_ERROR("cmdbuf is not read only.\n");
        return -1;
    }

    return 0;
}

static int32_t dvpp_gen_cmdlist_handler(dvpp_cmdlist_ioctl_args *arg)
{
    int32_t ret = 0;
    int32_t pid;
    uint32_t devid;
    uint32_t phyid;
    dvpp_gen_cmdlist_user_data user_data = {0};
    struct dvpp_sqe sqe = {0};

    ret = dvpp_get_gen_cmdlist_info_from_ioctl(arg, &user_data, &pid, &devid, &phyid, &sqe);
    if (ret != 0) {
        return ret;
    }

    // 处理来自物理机iotcl的sqe，完成uva地址转pa地址，根据args_addr中存的tlvlist结构信息，生成cmdlist并拷入pa内存中
    ret = dvpp_sqe_update(devid, pid, &sqe, arg->info.data);
    if (ret != 0) {
        DVPP_CMDLIST_LOG_ERROR("gen cmdlist devid=%u pid=%d seq update failed ret=%d\n", devid, pid, ret);
        return ret;
    }

    ret = dvpp_set_gen_cmdlist_sqe_to_user_data(&sqe, &user_data);
    return ret;
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