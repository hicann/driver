/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#include <malloc.h>
#include "securec.h"

#include "urma_api.h"
#include "udma_u_ctl.h"

#include "dms_user_interface.h"
#include "comm_user_interface.h"

#include "trs_user_pub_def.h"
#include "trs_sqcq.h"
#include "trs_dev_drv.h"
#include "trs_ioctl.h"
#include "trs_urma.h"

static int trs_create_jfc(urma_context_t *urma_ctx, urma_jfce_t *jfce, struct trs_urma_jfc *trs_jfc, void *priv)
{
    urma_jfc_cfg_t jfc_cfg = {0};
    urma_status_t urma_ret;

    jfc_cfg.jfce = jfce;
    jfc_cfg.depth = trs_get_jfc_depth();
    jfc_cfg.user_ctx = (uintptr_t)priv;
    trs_jfc->jfc = urma_create_jfc(urma_ctx, &jfc_cfg);
    if (trs_jfc->jfc == NULL) {
        trs_err("Failed to create jfc.\n");
        return DRV_ERROR_INNER_ERR;
    }

    urma_ret = urma_rearm_jfc(trs_jfc->jfc, false);
    if (urma_ret != URMA_SUCCESS) {
        trs_err("Urma rearm jfc failed. (ret=%d)\n", urma_ret);
        (void)urma_delete_jfc(trs_jfc->jfc);
        return DRV_ERROR_INNER_ERR;
    }

    return 0;
}

static void trs_destroy_jfc(struct trs_urma_jfc *trs_jfc)
{
    if (trs_jfc->jfc != NULL) {
        (void)urma_delete_jfc(trs_jfc->jfc);
        trs_jfc->jfc = NULL;
    }
}

static int trs_create_stars_jfc(urma_context_t *urma_ctx, urma_jfce_t *jfce, struct trs_urma_jfc *trs_jfc)
{
    struct udma_u_jfc_cfg_ex jfc_cfg_ex = {0};
    urma_user_ctl_in_t in = {0};
    urma_user_ctl_out_t out = {0};
    urma_status_t urma_ret;

    jfc_cfg_ex.base_cfg.jfce = jfce;
    jfc_cfg_ex.base_cfg.depth = TRS_STARS_JFC_MAX_DEPTH;
    jfc_cfg_ex.jfc_mode = UDMA_U_STARS_JFC_TYPE;

    in.addr = (uint64_t)(uintptr_t)(&jfc_cfg_ex);
    in.len = sizeof(struct udma_u_jfc_cfg_ex);
    in.opcode = UDMA_U_USER_CTL_CREATE_JFC_EX;

    out.addr = (uint64_t)(uintptr_t)(&trs_jfc->jfc);
    out.len = sizeof(urma_jfc_t *);
    urma_ret = urma_user_ctl(urma_ctx, &in, &out);
    if (urma_ret != 0) {
#ifndef EMU_ST
        trs_err("Urma user ctl failed. (ret=%d)\n", urma_ret);
        return DRV_ERROR_INNER_ERR;
#endif
    }

    return 0;
}

static void trs_destroy_stars_jfc(urma_context_t *urma_ctx, struct trs_urma_jfc *trs_jfc)
{
    urma_user_ctl_in_t in = {0};
    urma_user_ctl_out_t out = {0};
    urma_status_t urma_ret;

    in.addr = (uint64_t)(uintptr_t)(&trs_jfc->jfc);
    in.len = sizeof(urma_jfc_t *);
    in.opcode = UDMA_U_USER_CTL_DELETE_JFC_EX;
    urma_ret = urma_user_ctl(urma_ctx, &in, &out);
    if (urma_ret != 0) {
        trs_err("Urma user ctl failed. (ret=%d)\n", urma_ret);
        return;
    }
}

#define TRS_JFS_MAX_SGE_NUM 12U
int _trs_create_jfs(urma_context_t *urma_ctx, struct trs_urma_jfs *trs_jfs)
{
    uint8_t jfs_db_status = 1;
    urma_jfs_cfg_t jfs_cfg = {0};
    urma_status_t urma_ret;

    jfs_cfg.depth = trs_get_jfs_depth();
    jfs_cfg.trans_mode = URMA_TM_RM;
    jfs_cfg.priority = ASCEND_URMA_PRIORITY_HIGH;
    jfs_cfg.rnr_retry = URMA_TYPICAL_RNR_RETRY;
    jfs_cfg.err_timeout = URMA_TYPICAL_ERR_TIMEOUT;
    jfs_cfg.max_sge = TRS_JFS_MAX_SGE_NUM;
    jfs_cfg.flag.bs.error_suspend = 1; /* 1: error suspend */
    jfs_cfg.jfc = trs_jfs->trs_jfc.jfc;
    urma_ret = urma_alloc_jfs(urma_ctx, &jfs_cfg, &trs_jfs->jfs);
    if (urma_ret != URMA_SUCCESS) {
        trs_err("Failed to alloc jfs.\n");
        return DRV_ERROR_INNER_ERR;
    }

    /* disable db */
    urma_ret = urma_set_jfs_opt(trs_jfs->jfs, URMA_JFS_DB_STATUS, (void *)(&jfs_db_status), sizeof(uint8_t));
    if (urma_ret != URMA_SUCCESS) {
        trs_err("Failed to set jfs db disable. (ret=%d)\n", urma_ret);
        urma_free_jfs(trs_jfs->jfs);
        trs_jfs->jfs = NULL;
        return DRV_ERROR_INNER_ERR;
    }

    urma_ret = urma_active_jfs(trs_jfs->jfs);
    if (urma_ret != URMA_SUCCESS) {
        trs_err("Failed to actice jfs. (ret=%d)\n", urma_ret);
        urma_free_jfs(trs_jfs->jfs);
        trs_jfs->jfs = NULL;
        return DRV_ERROR_INNER_ERR;
    }

    return 0;
}

void _trs_destroy_jfs(struct trs_urma_jfs *trs_jfs)
{
    (void)urma_deactive_jfs(trs_jfs->jfs);
    (void)urma_free_jfs(trs_jfs->jfs);
    trs_jfs->jfs = NULL;
}

int trs_create_jfs(urma_context_t *urma_ctx, urma_jfce_t *jfce, struct trs_urma_jfs *trs_jfs, void *priv)
{
    urma_status_t urma_ret;
    int ret;

    ret = trs_create_jfc(urma_ctx, jfce, &trs_jfs->trs_jfc, priv);
    if (ret != 0) {
        trs_err("Failed to create jfc for jfs.\n");
        return ret;
    }

    ret = _trs_create_jfs(urma_ctx, trs_jfs);
    if (ret != 0) {
        goto exit_destroy_jfc;
    }

    urma_ret = urma_get_jfs_opt(trs_jfs->jfs, URMA_JFS_DB_ADDR, (void *)(&trs_jfs->jfs_db_addr), sizeof(uint64_t));
    if (urma_ret != URMA_SUCCESS) {
        trs_err("Failed to get jfs db addr. (ret=%d)\n", urma_ret);
        ret = DRV_ERROR_INNER_ERR;
        goto exit_destroy_jfs;
    }

    trs_jfs->wr_sge_array = calloc(TRS_URMA_ARGS_CPY_WR_MAX_NUM, sizeof(struct trs_wr_sge_pack));
    if (trs_jfs->wr_sge_array == NULL) {
        trs_jfs->jfs_db_addr = NULL;
        trs_err("Alloc wr sge array failed. (num=%u)\n", TRS_URMA_ARGS_CPY_WR_MAX_NUM);
        ret = DRV_ERROR_OUT_OF_MEMORY;
        goto exit_destroy_jfs;
    }

    trs_debug("Create jfs success. (jfs_id=%u; jfc_id=%u)\n", trs_jfs->jfs->jfs_id.id, trs_jfs->trs_jfc.jfc->jfc_id.id);
    return 0;

exit_destroy_jfs:
    _trs_destroy_jfs(trs_jfs);
exit_destroy_jfc:
    trs_destroy_jfc(&trs_jfs->trs_jfc);
    return ret;
}

void trs_destroy_jfs(struct trs_urma_jfs *trs_jfs)
{
    free(trs_jfs->wr_sge_array);
    trs_jfs->wr_sge_array = NULL;
    trs_jfs->jfs_db_addr = NULL;
    _trs_destroy_jfs(trs_jfs);
    trs_destroy_jfc(&trs_jfs->trs_jfc);
}

int trs_create_jfr(urma_context_t *urma_ctx, urma_jfce_t *jfce, urma_token_t token, struct trs_urma_jfr *trs_jfr)
{
    urma_jfr_cfg_t jfr_cfg = {0};
    int ret;

    ret = trs_create_jfc(urma_ctx, jfce, &trs_jfr->trs_jfc, NULL);
    if (ret != 0) {
        trs_err("Failed to create jfc for jfr.\n");
        return ret;
    }

    jfr_cfg.depth = trs_get_jfr_depth();
    jfr_cfg.trans_mode = URMA_TM_RM;
    jfr_cfg.min_rnr_timer = URMA_TYPICAL_MIN_RNR_TIMER;
    jfr_cfg.max_sge = 1;
    jfr_cfg.jfc = trs_jfr->trs_jfc.jfc;
    jfr_cfg.flag.bs.token_policy = URMA_TOKEN_PLAIN_TEXT;
    jfr_cfg.token_value = token;
    trs_jfr->jfr = urma_create_jfr(urma_ctx, &jfr_cfg);
    if (trs_jfr->jfr == NULL) {
#ifndef EMU_ST
        trs_err("Failed to create jfr.\n");
        trs_destroy_jfc(&trs_jfr->trs_jfc);
        return DRV_ERROR_INNER_ERR;
#endif
    }
    trs_debug("Create jfr success. (jfr_id=%u; jfc_id=%u)\n", trs_jfr->jfr->jfr_id.id, trs_jfr->trs_jfc.jfc->jfc_id.id);

    return 0;
}

void trs_destroy_jfr(struct trs_urma_jfr *trs_jfr)
{
    urma_status_t ret;
    if (trs_jfr->jfr != NULL) {
        ret = urma_delete_jfr(trs_jfr->jfr);
        if (ret != URMA_SUCCESS) {
            trs_warn("Delete jfr failed. (ret=%d)\n", ret);
        }
    }
    trs_destroy_jfc(&trs_jfr->trs_jfc);
}

static int trs_init_stars_jetty_wr_info_array(struct trs_urma_stars_jetty *trs_jetty)
{
    trs_jetty->wr_sge_array = calloc(TRS_URMA_ASYNC_CPY_WR_MAX_NUM, sizeof(struct trs_wr_sge_pack));
    if (trs_jetty->wr_sge_array == NULL) {
        trs_err("Alloc wr buff failed. (size=%lu)\n", TRS_URMA_ASYNC_CPY_WR_MAX_NUM * sizeof(struct trs_wr_sge_pack));
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    trs_jetty->tseg_array = calloc(TRS_STARS_NORMAL_JETTY_DEPTH, sizeof(urma_target_seg_t *));
    if (trs_jetty->tseg_array == NULL) {
        free(trs_jetty->wr_sge_array);
        trs_jetty->wr_sge_array = NULL;
        trs_err("Alloc tseg array failed. (num=%d)\n", TRS_STARS_NORMAL_JETTY_DEPTH);
        return DRV_ERROR_OUT_OF_MEMORY;
    }

    return 0;
}

static void trs_uninit_stars_jetty_wr_info_array(struct trs_urma_stars_jetty *trs_jetty)
{
    if (trs_jetty->tseg_array != NULL) {
        unsigned int i;

        for (i = 0; i < TRS_STARS_NORMAL_JETTY_DEPTH; i++) {
            if (trs_jetty->tseg_array[i] != NULL) {
                urma_unimport_seg(trs_jetty->tseg_array[i]);
                trs_jetty->tseg_array[i] = NULL;
            }
        }

        free(trs_jetty->tseg_array);
        trs_jetty->tseg_array = NULL;
    }

    if (trs_jetty->wr_sge_array != NULL) {
        free(trs_jetty->wr_sge_array);
        trs_jetty->wr_sge_array = NULL;
    }
}

static int _trs_destroy_stars_jetty(urma_context_t *urma_ctx, struct trs_urma_stars_jetty *trs_jetty)
{
    urma_user_ctl_in_t in = {0};
    urma_user_ctl_out_t out = {0};
    urma_status_t urma_ret;

    in.addr = (uint64_t)(uintptr_t)(&trs_jetty->jetty);
    in.len = sizeof(urma_jetty_t *);
    in.opcode = UDMA_U_USER_CTL_DELETE_JETTY_EX;
    urma_ret = urma_user_ctl(urma_ctx, &in, &out);
    if (urma_ret != 0) {
        trs_err("Urma user ctl destroy jetty failed. (ret=%d)\n", urma_ret);
        return DRV_ERROR_INNER_ERR;
    }

    return 0;
}

static int _trs_create_stars_jetty(urma_context_t *urma_ctx, struct trs_urma_jfr *trs_jfr, uint32_t depth,
                                   struct trs_urma_stars_jetty *trs_jetty)
{
    struct udma_u_jetty_cfg_ex jetty_ex_cfg = {0};
    urma_jetty_cfg_t jetty_cfg = {0};
    urma_jfs_cfg_t jfs_cfg = {0};
    struct udma_u_jetty_info jetty_info = {0};
    urma_status_t urma_ret;
    urma_user_ctl_in_t in = {0};
    urma_user_ctl_out_t out = {0};

    jfs_cfg.depth = 1;
    jfs_cfg.trans_mode = URMA_TM_RM;
    jfs_cfg.priority = ASCEND_URMA_PRIORITY_MIDDLE;
    jfs_cfg.rnr_retry = URMA_TYPICAL_RNR_RETRY;
    jfs_cfg.err_timeout = URMA_TYPICAL_ERR_TIMEOUT;
    jfs_cfg.max_sge = 1;
    jfs_cfg.jfc = trs_jetty->trs_jfc.jfc;

    jetty_cfg.jfs_cfg = jfs_cfg;
    jetty_cfg.flag.bs.share_jfr = 1;
    jetty_cfg.shared.jfc = trs_jfr->trs_jfc.jfc;
    jetty_cfg.shared.jfr = trs_jfr->jfr;

    jetty_ex_cfg.base_cfg = jetty_cfg;
    jetty_ex_cfg.jfs_cstm.flag.bs.sq_cstm = 0;
    jetty_ex_cfg.jetty_type = trs_jetty->jetty_type;
    jetty_ex_cfg.sqebb_num = depth;
    jetty_ex_cfg.pi_type = trs_jetty->wqe_sink_flag; /* pi_type: 0 absolute pi, 1 relative pi */

    in.addr = (uint64_t)(uintptr_t)(&jetty_ex_cfg);
    in.len = sizeof(struct udma_u_jetty_cfg_ex);
    in.opcode = UDMA_U_USER_CTL_CREATE_JETTY_EX;

    out.addr = (uint64_t)(uintptr_t)(&jetty_info);
    out.len = sizeof(struct udma_u_jetty_info);
    urma_ret = urma_user_ctl(urma_ctx, &in, &out);
    if (urma_ret != 0) {
        trs_destroy_stars_jfc(urma_ctx, &trs_jetty->trs_jfc);
        trs_err("Urma user ctl create jetty failed. (ret=%d)\n", urma_ret);
        return DRV_ERROR_INNER_ERR;
    }

    trs_jetty->jetty = jetty_info.jetty;
    return 0;
}

int trs_create_stars_jetty(urma_context_t *urma_ctx, urma_jfce_t *jfce, struct trs_urma_jfr *trs_jfr, uint32_t depth,
                           struct trs_urma_stars_jetty *trs_jetty)
{
    int ret = 0;

    ret = trs_create_stars_jfc(urma_ctx, jfce, &trs_jetty->trs_jfc);
    if (ret != 0) {
        trs_err("Failed to create jfc for jetty.\n");
        return ret;
    }

    ret = _trs_create_stars_jetty(urma_ctx, trs_jfr, depth, trs_jetty);
    if (ret != 0) {
        return ret;
    }

    if (trs_jetty->jetty_type == UDMA_U_NORMAL_JETTY_TYPE) {
        ret = trs_init_stars_jetty_wr_info_array(trs_jetty);
        if (ret != 0) {
            (void)_trs_destroy_stars_jetty(urma_ctx, trs_jetty);
            trs_destroy_stars_jfc(urma_ctx, &trs_jetty->trs_jfc);
            return ret;
        }
    }

    trs_jetty->init_flag = true;
    trs_debug("Create stars jetty success. (jetty_id=%u; jfr_id=%u; jfc_id=%u)\n", trs_jetty->jetty->jetty_id.id,
              trs_jfr->jfr->jfr_id.id, trs_jetty->trs_jfc.jfc->jfc_id.id);

    return 0;
}

void trs_destroy_stars_jetty(urma_context_t *urma_ctx, struct trs_urma_stars_jetty *trs_jetty)
{
    uint32_t jetty_id;
    int ret;

    if (trs_jetty->init_flag == false) {
        return;
    }

    trs_jetty->init_flag = false;
    if (trs_jetty->jetty_type == UDMA_U_NORMAL_JETTY_TYPE) {
        trs_uninit_stars_jetty_wr_info_array(trs_jetty);
    }

    jetty_id = trs_jetty->jetty->jetty_id.id;
    ret = _trs_destroy_stars_jetty(urma_ctx, trs_jetty);
    if (ret != 0) {
        trs_err("Urma user ctl destroy jetty failed. (ret=%d)\n", ret);
        return;
    }

    trs_destroy_stars_jfc(urma_ctx, &trs_jetty->trs_jfc);
    trs_debug("Destroy stars jetty success. (jetty_id=%u)\n", jetty_id);
}

#ifndef EMU_ST
struct trs_urma_ctx *trs_urma_ctx_create(void)
{
    struct trs_urma_ctx *urma_ctx = NULL;

    urma_ctx = (struct trs_urma_ctx *)calloc(1, sizeof(struct trs_urma_ctx));
    return urma_ctx;
}

void trs_urma_ctx_destroy(struct trs_urma_ctx *urma_ctx)
{
    if (urma_ctx != NULL) {
        free(urma_ctx);
    }
}
#endif

static struct trs_urma_proc_ctx g_urma_proc_ctx[TRS_DEV_NUM];

struct trs_urma_proc_ctx *trs_get_urma_proc_ctx(uint32_t dev_id)
{
    if (dev_id >= TRS_DEV_NUM) {
        return NULL;
    }
    return &g_urma_proc_ctx[dev_id];
}

void trs_urma_proc_ctx_uninit(struct trs_urma_proc_ctx *proc_ctx)
{
    urma_status_t ret;
    if (proc_ctx->tjetty != NULL) {
        ret = urma_unimport_jfr(proc_ctx->tjetty);
        if (ret != URMA_SUCCESS) {
            trs_warn("Unimport jfr failed. (ret=%d)\n", ret);
        }
        proc_ctx->tjetty = NULL;
    }
    trs_destroy_jfr(&proc_ctx->trs_jfr);
    if (proc_ctx->jfce != NULL) {
        (void)urma_delete_jfce(proc_ctx->jfce);
        proc_ctx->jfce = NULL;
    }
    if (proc_ctx->urma_ctx != NULL) {
        (void)urma_delete_context(proc_ctx->urma_ctx);
        proc_ctx->urma_ctx = NULL;
    }
    proc_ctx->urma_dev = NULL;
}

#include "trs_master_async.h"
#ifndef DRV_HOST
#include "trs_slave_async.h"
#endif

void _trs_urma_proc_ctx_uninit_by_devid(uint32_t dev_id)
{
    int i;

    for (i = 0; i < TRS_URMA_SEG_TOKEN_ALLOC_DIVIDE; i++) {
        if (g_urma_proc_ctx[dev_id].token_id[i] != NULL) {
            (void)urma_free_token_id(g_urma_proc_ctx[dev_id].token_id[i]);
            g_urma_proc_ctx[dev_id].token_id[i] = NULL;
        }
    }

#ifdef DRV_HOST
    trs_destroy_remote_d2d_jetty(dev_id);
#else
    trs_d2d_ctx_uninit(dev_id);
#endif
    trs_urma_proc_ctx_uninit(&g_urma_proc_ctx[dev_id]);
    g_urma_proc_ctx[dev_id].tpn_valid = false;
}

void trs_urma_proc_ctx_uninit_by_devid(uint32_t dev_id)
{
    int connection_type = trs_get_connection_type(dev_id);

    if ((connection_type != TRS_CONNECT_PROTOCOL_UB) && (connection_type != TRS_CONNECT_PROTOCOL_RC)) {
        return;
    }

    if (g_urma_proc_ctx[dev_id].urma_ctx != NULL) {
        trs_urma_cqe_poll_uninit_dev(dev_id);
        trs_async_urma_uninit(dev_id);
    }

    _trs_urma_proc_ctx_uninit_by_devid(dev_id);
}

drvError_t trs_urma_proc_ctx_init(struct trs_urma_proc_ctx *proc_ctx)
{
    struct dms_ub_dev_info eid_info;
    int ret, num;

    ret = dms_get_ub_dev_info(proc_ctx->dev_id, &eid_info, &num);
    if ((ret != 0) || (num == 0)) {
#ifndef EMU_ST
        trs_warn("No dev_info. (ret=%d; num=%d)\n", ret, num);
        return DRV_ERROR_NONE; /* dms should return not support later */
#endif
    }
    proc_ctx->eid_index = eid_info.eid_index[0];
    if (proc_ctx->urma_dev == NULL) {
        proc_ctx->urma_dev = (urma_device_t *)(eid_info.urma_dev[0]);
    }

    ret = ascend_urma_get_token_val(proc_ctx->dev_id, &proc_ctx->token.token);
    if (ret != DRV_ERROR_NONE) {
        trs_err("Get token val failed. (ret=%d; devid=%u)\n", ret, proc_ctx->dev_id);
        return ret;
    }

    proc_ctx->urma_ctx = urma_create_context(proc_ctx->urma_dev, proc_ctx->eid_index);
    if (proc_ctx->urma_ctx == NULL) {
        trs_err("Create urma proc ctx failed. (eid=%u)\n", proc_ctx->eid_index);
        return DRV_ERROR_INNER_ERR;
    }
    proc_ctx->eid = proc_ctx->urma_ctx->eid;
    trs_debug("Get eid list. (dev_name=%s; eid_index=%d; " EID_FMT ").\n", proc_ctx->urma_dev->name,
              proc_ctx->eid_index, EID_ARGS(proc_ctx->eid));

    proc_ctx->jfce = urma_create_jfce(proc_ctx->urma_ctx);
    if (proc_ctx->jfce == NULL) {
        (void)urma_delete_context(proc_ctx->urma_ctx);
        trs_err("Failed to create jfce.\n");
        return DRV_ERROR_INNER_ERR;
    }

    ret = trs_create_jfr(proc_ctx->urma_ctx, proc_ctx->jfce, proc_ctx->token, &proc_ctx->trs_jfr);
    if (ret != DRV_ERROR_NONE) {
        (void)urma_delete_jfce(proc_ctx->jfce);
        (void)urma_delete_context(proc_ctx->urma_ctx);
        trs_err("Failed to create jfr. (ret=%d)\n", ret);
        return ret;
    }

    return DRV_ERROR_NONE;
}

int trs_query_fe_info(struct trs_urma_proc_ctx *proc_ctx)
{
    urma_user_ctl_in_t in = {0};
    urma_user_ctl_out_t out = {0};
    struct udma_u_ue_info fe_info = {0};
    urma_status_t urma_ret;

    in.opcode = UDMA_U_USER_CTL_QUERY_UE_INFO;
    out.addr = (uint64_t)(uintptr_t)(&fe_info);
    out.len = sizeof(struct udma_u_ue_info);
    urma_ret = urma_user_ctl(proc_ctx->urma_ctx, &in, &out);
    if (urma_ret != URMA_SUCCESS) {
        trs_err("Urma user ctl failed. (urma_ret=%d)\n", urma_ret);
        return DRV_ERROR_INNER_ERR;
    }

    proc_ctx->func_id = fe_info.ue_id;
    proc_ctx->die_id = fe_info.die_id;
    return 0;
}

drvError_t _trs_urma_proc_ctx_init_by_devid(uint32_t dev_id)
{
    struct trs_ub_info_query_para ub_info = {0};
    drvError_t ret;
    int i;

    g_urma_proc_ctx[dev_id].tpn_valid = false;
    g_urma_proc_ctx[dev_id].dev_id = dev_id;
    ret = trs_urma_proc_ctx_init(&g_urma_proc_ctx[dev_id]);
    if (ret != DRV_ERROR_NONE) {
        trs_err("Failed to init urma proc ctx. (dev_id=%u; ret=%d)\n", dev_id, ret);
        return ret;
    }

    if (g_urma_proc_ctx[dev_id].urma_ctx == NULL) { /* PCIE scene no need */
        return 0;
    }

    for (i = 0; i < TRS_URMA_SEG_TOKEN_ALLOC_DIVIDE; i++) {
        g_urma_proc_ctx[dev_id].token_id[i] = urma_alloc_token_id(g_urma_proc_ctx[dev_id].urma_ctx);
        if (g_urma_proc_ctx[dev_id].token_id[i] == NULL) {
            _trs_urma_proc_ctx_uninit_by_devid(dev_id);
            trs_err("Urma alloc token id failed. (index=%d)\n", i);
            return DRV_ERROR_INNER_ERR;
        }
    }

    if (trs_get_connection_type(dev_id) == TRS_CONNECT_PROTOCOL_RC) {
        ret = trs_query_fe_info(&g_urma_proc_ctx[dev_id]);
    } else {
        ret = trs_dev_io_ctrl(dev_id, TRS_UB_INFO_QUERY, &ub_info);
        if (ret == 0) {
            g_urma_proc_ctx[dev_id].die_id = ub_info.die_id;
            g_urma_proc_ctx[dev_id].func_id = ub_info.func_id;
        }
    }

    if (ret != 0) {
        _trs_urma_proc_ctx_uninit_by_devid(dev_id);
        trs_err("Failed to query ub fe info. (ret=%d)\n", ret);
        return ret;
    }

    return DRV_ERROR_NONE;
}

drvError_t trs_urma_proc_ctx_init_by_devid(uint32_t dev_id)
{
    int connection_type = trs_get_connection_type(dev_id);
    drvError_t ret;

    if ((connection_type != TRS_CONNECT_PROTOCOL_UB) && (connection_type != TRS_CONNECT_PROTOCOL_RC)) {
        return DRV_ERROR_NONE;
    }

    ret = _trs_urma_proc_ctx_init_by_devid(dev_id);
    if (ret != 0) {
        return ret;
    }

    if (g_urma_proc_ctx[dev_id].urma_ctx != NULL) {
        ret = trs_async_urma_init(dev_id);
        if (ret != 0) {
            _trs_urma_proc_ctx_uninit_by_devid(dev_id);
            trs_err("Failed to init urma async. (ret=%d)\n", ret);
            return ret;
        }

        ret = trs_urma_cqe_poll_init_dev(dev_id); /* would to be destroy in destructor */
        if (ret != 0) {
            trs_async_urma_uninit(dev_id);
            _trs_urma_proc_ctx_uninit_by_devid(dev_id);
            trs_err("Try to init cqe poll fail. (ret=%d)\n", ret);
            return ret;
        }
    }

    return DRV_ERROR_NONE;
}
