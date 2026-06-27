/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "securec.h"
#include "hccn_log.h"
#include "ascend_hal.h"
#include "ascend_inpackage_hal.h"
#include "ds_data.h"
#include "ds_net_interface.h"

static int dsmi_network_transmission_channel_para_check(struct ds_trans_data *trans_data)
{
    if (trans_data->inbuf == NULL && trans_data->size_in != 0) {
        hccn_err("invalid param, inbuf is NULL, size_in %u", trans_data->size_in);
        return -EINVAL;
    }

    if (trans_data->inbuf != NULL && trans_data->size_in == 0) {
        hccn_err("invalid param, inbuf != NULL and size_in is 0");
        return -EINVAL;
    }

    if (trans_data->outbuf == NULL && trans_data->size_out == NULL) {
        hccn_err("invalid param, outbuf is NULL, sizeout is NULL");
        return -EINVAL;
    }

    if (trans_data->outbuf == NULL && trans_data->size_out != NULL && *(trans_data->size_out) != 0) {
        hccn_err("invalid param, outbuf is NULL, sizeout %u", *trans_data->size_out);
        return -EINVAL;
    }

    if (trans_data->outbuf != NULL && trans_data->size_out == NULL) {
        hccn_err("invalid param, outbuf != NULL and sizeout is NULL");
        return -EINVAL;
    }

    if (trans_data->outbuf != NULL && trans_data->size_out != NULL && *(trans_data->size_out) == 0) {
        hccn_err("invalid param, outbuf is not NULL, sizeout is zero");
        return -EINVAL;
    }

    return 0;
}

static void dsmi_network_transmission_channel_cmd_init(int logic_id, struct ds_common_req_param *ds_common_cmd,
    struct ds_trans_data *trans_data)
{
    ds_common_cmd->req_head.logic_id = logic_id;
    ds_common_cmd->req_head.cmd = trans_data->cmd;
    ds_common_cmd->req_head.send_data_len = trans_data->size_in;
    ds_common_cmd->req_head.recv_data_len = *(trans_data->size_out);
    ds_common_cmd->req_head.host_tid = drvDeviceGetBareTgid();
    ds_common_cmd->req_head.pid = trans_data->pid;
}

static void dsmi_cmd_cleanup_info(struct ds_common_req_param *ds_common_cmd,
    struct ds_common_rsp_param *ds_common_rsp)
{
    int ret1, ret2;

    ret1 = memset_s(ds_common_cmd->info, MAX_CMD_PAYLOAD_LEN, 0, MAX_CMD_PAYLOAD_LEN);
    if (ret1) {
        hccn_warn("memset_s ds_req.info unsuccessful ret:%d", ret1);
    }

    ret2 = memset_s(ds_common_rsp->info, MAX_CMD_PAYLOAD_LEN, 0, MAX_CMD_PAYLOAD_LEN);
    if (ret2) {
        hccn_warn("memset_s ds_rsp.info unsuccessful ret:%d", ret2);
    }
}

static int dsmi_cmd_get_outbuf_from_every_pkt(struct ds_trans_data *trans_data,
    struct ds_common_rsp_param *ds_common_rsp, unsigned int *offset, unsigned int *recv_len, unsigned int orig_len)
{
    int ret;

    /* rdfx response pkt from middle or one pkt */
    if ((orig_len <= MAX_CMD_PAYLOAD_LEN && ds_common_rsp->rsp_head.data_frag != DS_ONE_PKT) ||
        (orig_len > MAX_CMD_PAYLOAD_LEN && ds_common_rsp->rsp_head.data_frag == DS_FIRST_PKT)) {
        hccn_err("error rsp from rdfx, orig_len %u, data frag %d", orig_len, ds_common_rsp->rsp_head.data_frag);
        return -EINVAL;
    }

    if (ds_common_rsp->rsp_head.one_piece_len > 0 && trans_data->outbuf != NULL &&
        ds_common_rsp->rsp_head.one_piece_len <= MAX_CMD_PAYLOAD_LEN && ds_common_rsp->rsp_head.one_piece_len != 0) {
        /* get recv data from every pkt */
        ret = memcpy_s(trans_data->outbuf + *offset, *recv_len, ds_common_rsp->info,
            ds_common_rsp->rsp_head.one_piece_len);
        if (ret != 0) {
            hccn_err("dsmi memcpy outbuf failed ret[%d], dst_len[%u], src_len[%u]",
                ret, *recv_len, ds_common_rsp->rsp_head.one_piece_len);
            return ret;
        }

        if (ds_common_rsp->rsp_head.one_piece_len > *recv_len) {
            hccn_err("one piece len %u is bigger than recv len %u", ds_common_rsp->rsp_head.one_piece_len, *recv_len);
            return -EINVAL;
        }

        hccn_info("dsmi get one piece len %u, offset %u", ds_common_rsp->rsp_head.one_piece_len, *offset);
        *offset += ds_common_rsp->rsp_head.one_piece_len;
        *recv_len -= ds_common_rsp->rsp_head.one_piece_len;
    }

    return 0;
}

static int dsmi_set_send_cfg(struct ds_common_req_param *ds_cmd, unsigned int len, unsigned int *copy_size,
    const char *buf_tmp, unsigned int off_set)
{
    int ret;

    if (ds_cmd->req_head.send_data_len <= MAX_CMD_PAYLOAD_LEN) {
        ds_cmd->req_head.data_frag = DS_ONE_PKT;
        *copy_size = ds_cmd->req_head.send_data_len;
        ds_cmd->req_head.one_piece_len = *copy_size;
    } else {
        *copy_size = MIN(MAX_CMD_PAYLOAD_LEN, len);
        ds_cmd->req_head.one_piece_len = *copy_size;
        hccn_info("copy_size:%d", *copy_size);
        if (off_set == 0) {
            ds_cmd->req_head.data_frag = DS_FIRST_PKT;
        } else if (*copy_size == len) {
            ds_cmd->req_head.data_frag = DS_LAST_PKT;
        } else {
            ds_cmd->req_head.data_frag = DS_MIDDLE_PKT;
        }
    }

    /* in buf size could be zero */
    if (*copy_size != 0 && buf_tmp != NULL) {
        ret = memcpy_s(ds_cmd->info, MAX_CMD_PAYLOAD_LEN, buf_tmp + off_set, *copy_size);
        if (ret != 0) {
            hccn_err("dsmi memcpy data to info failed ret[%d] dst_len[%d], off_set[%u], src_len[%u]",
                ret, MAX_CMD_PAYLOAD_LEN, off_set, *copy_size);
            return ret;
        }
    }

    return 0;
}

static int dsmi_send(int logic_id, struct ds_trans_data *trans_data, struct ds_common_req_param *ds_common_cmd,
    struct ds_common_rsp_param *ds_common_rsp)
{
    unsigned int size = sizeof(struct ds_common_rsp_param);
    const char *buf_tmp = trans_data->inbuf;
    unsigned int len = trans_data->size_in;
    unsigned int copy_size = 0;
    unsigned int off_set = 0;
    int result = 0;
    int ret;

    ds_common_cmd->req_head.send_recv_op = DS_SEND_OP; /* set send flag to device */
    while (true) {
        ret = dsmi_set_send_cfg(ds_common_cmd, len, &copy_size, buf_tmp, off_set);
        if (ret != 0) {
            hccn_err("dev %d set send cfg failed ret %d", logic_id, ret);
            goto out;
        }

        ret = dsmi_cmd_get_network_device_info(logic_id, (char *)ds_common_cmd, sizeof(struct ds_common_req_param),
            (char *)ds_common_rsp, &size);
        if (ret != 0 || size != sizeof(struct ds_common_rsp_param)) {
            hccn_err("logic_id %d dsmi get network info failed ret %d, ret_size %u != rsp_size %zu",
                logic_id, ret, size, sizeof(struct ds_common_rsp_param));
            ret = -EINVAL;
            goto out;
        }

        /* get result from the every rsp head result */
        result = ds_common_rsp->rsp_head.result;
        if (result) {
            hccn_warn("logic_id %d, dsmi get result %d != 0", logic_id, result);
            break;
        }

        len -= copy_size;
        off_set += copy_size;

        if (ds_common_cmd->req_head.data_frag == DS_LAST_PKT || ds_common_cmd->req_head.data_frag == DS_ONE_PKT ||
            len == 0) {
            break;
        }
    }

    ret = 0;
out:
    trans_data->result = result;
    return ret;
}

static int dsmi_recv(int logic_id, struct ds_trans_data *trans_data, struct ds_common_req_param *ds_common_cmd,
    struct ds_common_rsp_param *ds_common_rsp)
{
    unsigned int size = sizeof(struct ds_common_rsp_param);
    unsigned int recv_len = *trans_data->size_out;
    unsigned int orig_len = *trans_data->size_out;
    unsigned int offset = 0;
    int result = 0;
    int ret;

    ds_common_cmd->req_head.send_recv_op = DS_RECV_OP; /* set recv flag to device */
    *(trans_data->size_out) = 0;
    while (true) {
        ret = dsmi_cmd_get_outbuf_from_every_pkt(trans_data, ds_common_rsp, &offset, &recv_len, orig_len);
        if (ret != 0) {
            hccn_err("logic_id %d dsmi get outbuf failed ret %d", logic_id, ret);
            goto out;
        }

        /* sizeout is sum of rsp head piece len */
        *(trans_data->size_out) += ds_common_rsp->rsp_head.one_piece_len;

        /* get rsp flag from device */
        if (ds_common_rsp->rsp_head.data_frag == DS_ONE_PKT || ds_common_rsp->rsp_head.data_frag == DS_LAST_PKT) {
            break;
        }

        if (recv_len == 0 && ds_common_rsp->rsp_head.data_frag == DS_MIDDLE_PKT) {
            hccn_err("recv len is zero but pkt is not last or one pkt");
            return -EINVAL;
        }

        ds_common_cmd->req_head.data_frag = ds_common_rsp->rsp_head.data_frag; /* reuse rsp flag */
        ret = dsmi_cmd_get_network_device_info(logic_id, (char *)ds_common_cmd, sizeof(struct ds_common_req_param),
            (char *)ds_common_rsp, &size);
        if (ret != 0 || size != sizeof(struct ds_common_rsp_param) || ds_common_rsp->rsp_head.one_piece_len == 0 ||
            ds_common_rsp->rsp_head.one_piece_len > MAX_CMD_PAYLOAD_LEN) {
            hccn_err("logic_id %d dsmi get network info failed ret %d, ret_size is %u, rsp_head_len %u",
                logic_id, ret, size, ds_common_rsp->rsp_head.one_piece_len);
            ret = -EINVAL;
            goto out;
        }

        /* get result from the every rsp head result */
        result = ds_common_rsp->rsp_head.result;
        if (result) {
            hccn_err("logic_id %d dsmi get result %d != 0", logic_id, result);
            break;
        }
    }

    ret = 0;
out:
    trans_data->result = result;
    return ret;
}

int dsmi_network_transmission_channel(int logic_id, struct ds_trans_data *trans_data)
{
    struct ds_common_req_param ds_common_cmd = { {0}, {0} };
    struct ds_common_rsp_param ds_common_rsp = { {0}, {0} };
    int ret;

    ret = dsmi_network_transmission_channel_para_check(trans_data);
    if (ret != 0) {
        hccn_err("invalid para input %d, logic_id %d", ret, logic_id);
        return ret;
    }

    dsmi_network_transmission_channel_cmd_init(logic_id, &ds_common_cmd, trans_data);

    ret = dsmi_send(logic_id, trans_data, &ds_common_cmd, &ds_common_rsp);
    if (ret != 0) {
        hccn_err("dsmi send failed %d, logic_id %d", ret, logic_id);
        goto out;
    }

    if (trans_data->result != 0) {
        goto out;
    }

    ret = dsmi_recv(logic_id, trans_data, &ds_common_cmd, &ds_common_rsp);
    if (ret != 0) {
        hccn_err("dsmi recv failed %d, logic_id %d", ret, logic_id);
    }

out:
    dsmi_cmd_cleanup_info(&ds_common_cmd, &ds_common_rsp);
    return ret;
}

int dsmi_exe_get_info(int logic_id, enum ds_cmd_opcode cmd, struct dsmi_info *info)
{
    unsigned int total_size_in = info->size_in + info->size_extra_in;
    struct ds_trans_data trans_data = {0};
    char *total_inbuf = info->inbuf;
    int ret;

    CHK_PRT_RETURN(logic_id < 0, hccn_err("input invalid logic_id %d < 0", logic_id), -EINVAL);

    if (info->inbuf != NULL && info->extra_inbuf != NULL && info->size_in != 0 && info->size_extra_in != 0) {
        total_inbuf = (char *)calloc(1, total_size_in);
        CHK_PRT_RETURN(total_inbuf == NULL, hccn_err("malloc total_inbuf failed"), -ENOMEM);

        ret = memcpy_s(total_inbuf, total_size_in, info->inbuf, info->size_in);
        if (ret != 0) {
            hccn_err("memcpy_s failed, ret[%d]", ret);
            goto out;
        }

        (void)memcpy_s(total_inbuf + info->size_in, info->size_extra_in, info->extra_inbuf, info->size_extra_in);
    }

    DSMI_SET_TRANS_DATA(trans_data, cmd, total_inbuf, total_size_in, info->outbuf, info->size_out);

    ret = dsmi_network_transmission_channel(logic_id, &trans_data);
    if (ret != 0) {
        hccn_err("dsmi transmission failed, ret[%d] logic_id[%d] cmd[0x%x]", ret, logic_id, cmd);
        goto out;
    }

    ret = trans_data.result;

out:
    if (info->inbuf != NULL && info->extra_inbuf != NULL && info->size_in != 0 && info->size_extra_in != 0) {
        free(total_inbuf);
        total_inbuf = NULL;
    }
    return ret;
}
