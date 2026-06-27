/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "securec.h"
#include "dsmi_common_interface.h"
#include "dsmi_network_interface.h"
#include "dcmi_interface_api.h"
#include "dcmi_init_basic.h"
#include "dcmi_fault_manage_intf.h"
#include "dcmi_log.h"
#include "dcmi_product_judge.h"
#include "dcmi_environment_judge.h"
#include "dcmi_prbs_intf.h"

/* PRBS默认lane数量 */
#define PRBS_DEFAULT_LANE_COUNT 1
/* PRBS最大端口号 */
#define PRBS_MAX_PORT_ID 9
/* PRBS最大u-die编号 */
#define PRBS_MAX_UDIE_ID 1

/*
 * @brief 检查调用者权限
 */
STATIC int dcmiv2_check_prbs_permission(void)
{
    if (dcmi_is_in_privileged_docker_root() ||
        dcmi_is_in_phy_machine_root() || dcmi_is_in_vm_root()) {
        return DCMI_OK;
    }
    gplog(LOG_OP, "Operation not permitted, only root user on physical or virtual machine"
        " or privileged docker can call this api.");
    return DCMI_ERR_CODE_OPER_NOT_PERMITTED;
}

/*
 * @brief 检查PRBS端口是否有效
 */
STATIC int dcmiv2_check_prbs_port_valid(
    unsigned int mainboard_id,
    DCMIV2_PRBS_OPERATE_PARAM operate_para)
{
    unsigned int udie_id = 0, port_id = 0;

    if (operate_para.sub_cmd == SERDES_PRBS_SET_CMD) {
        udie_id = operate_para.operate_para.set_param.param_base.udie_id;
        port_id = operate_para.operate_para.set_param.param_base.port_id;
    } else {
        udie_id = operate_para.operate_para.get_param.udie_id;
        port_id = operate_para.operate_para.get_param.port_id;
    }

    if (udie_id > PRBS_MAX_UDIE_ID || port_id > PRBS_MAX_PORT_ID) {
            gplog(LOG_ERR, "Invalid udie_id or port_id. udie_id=%u, port_id=%u", udie_id, port_id);
            return DCMI_ERR_CODE_INVALID_PARAMETER;
        }

    if (!dcmi_board_chip_type_is_ascend_950()) {
        gplog(LOG_OP, "This device does not support prbs operate.");
        return DCMI_ERR_CODE_NOT_SUPPORT;
    }
    return DCMI_OK;
}

/*
 * @brief 检查DCMIV2_PRBS_OPERATE_PARAM参数是否有效
 */

int checkv2_prbs_operate_para(DCMIV2_PRBS_OPERATE_PARAM operate_para, void *buf)
{
    unsigned int serdes_prbs_type = SERDES_PRBS_TYPE_MAX;
    unsigned int serdes_prbs_direction = SERDES_PRBS_DIRECTION_MAX;

    if ((operate_para.sub_cmd >= SERDES_PRBS_SUB_CMD_MAX) || (operate_para.main_cmd >= DSMI_SERDES_CMD_MAX)) {
        gplog(LOG_ERR, "dcmi_prbs_operate prams is invalid, sub_cmd=[%u], main_cmd=[%u]",
            operate_para.sub_cmd, operate_para.main_cmd);
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    if (operate_para.sub_cmd == SERDES_PRBS_SET_CMD) {
        serdes_prbs_type = operate_para.operate_para.set_param.serdes_prbs_type;
        serdes_prbs_direction = operate_para.operate_para.set_param.serdes_prbs_direction;
        if ((serdes_prbs_type != SERDES_PRBS_TYPE_END && serdes_prbs_type != SERDES_PRBS_TYPE_31) ||
            (serdes_prbs_direction >= SERDES_PRBS_DIRECTION_MAX)) {
            gplog(LOG_ERR, "serdes_prbs para is invalid, type=[%u], direction=[%u]",
                serdes_prbs_type, serdes_prbs_direction);
            return DCMI_ERR_CODE_INVALID_PARAMETER;
        }
    }

    if (buf == NULL) {
        gplog(LOG_ERR, "dcmi_prbs operate_result is NULL");
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    return DCMI_OK;
}

/*
 * @brief 将DCMIV2_PRBS_OPERATE_PARAM转换为DCMI_PRBS_OPERATE_PARAM
 * @param[in] v2_operate_param: DCMIV2版本的操作参数(包含udie_id, port_id)
 * @param[out] dcmi_operate_param: DCMI版本的操作参数
 * @return 转换成功返回0，失败返回错误码
 * @note 转换规则: udie_id -> serdes_prbs_start_lane_id, port_id -> serdes_prbs_macro_id
 */
STATIC int convert_dcmiv2_to_dcmi_prbs_param(
    DCMIV2_PRBS_OPERATE_PARAM v2_operate_param,
    DCMI_PRBS_OPERATE_PARAM *dcmi_operate_param)
{
    if (dcmi_operate_param == NULL) {
        return DCMI_ERR_CODE_INVALID_PARAMETER;
    }

    // 复制主命令和子命令
    dcmi_operate_param->main_cmd = v2_operate_param.main_cmd;
    dcmi_operate_param->sub_cmd = v2_operate_param.sub_cmd;

    // 转换 GET 参数：udie_id存到serdes_prbs_start_lane_id（对应driver的serdes_id），port_id存到serdes_prbs_macro_id（对应driver的macro_id）
    dcmi_operate_param->operate_para.get_param.serdes_prbs_start_lane_id =
        v2_operate_param.operate_para.get_param.udie_id;
    dcmi_operate_param->operate_para.get_param.serdes_prbs_macro_id =
        v2_operate_param.operate_para.get_param.port_id;
    dcmi_operate_param->operate_para.get_param.serdes_prbs_lane_count =
        PRBS_DEFAULT_LANE_COUNT;

    // 转换 SET 参数：udie_id存到serdes_prbs_start_lane_id（对应driver的serdes_id），port_id存到serdes_prbs_macro_id（对应driver的macro_id）
    dcmi_operate_param->operate_para.set_param.param_base.serdes_prbs_start_lane_id =
        v2_operate_param.operate_para.set_param.param_base.udie_id;
    dcmi_operate_param->operate_para.set_param.param_base.serdes_prbs_macro_id =
        v2_operate_param.operate_para.set_param.param_base.port_id;
    dcmi_operate_param->operate_para.set_param.param_base.serdes_prbs_lane_count =
        PRBS_DEFAULT_LANE_COUNT;

    // 复制其他字段
    dcmi_operate_param->operate_para.set_param.serdes_prbs_type =
        v2_operate_param.operate_para.set_param.serdes_prbs_type;
    dcmi_operate_param->operate_para.set_param.serdes_prbs_direction =
        v2_operate_param.operate_para.set_param.serdes_prbs_direction;

    return DCMI_OK;
}

/*
 * @brief 执行PRBS操作
 */
STATIC int dcmiv2_exec_prbs_operate(
    int dev_id,
    unsigned int mainboard_id,
    DCMI_PRBS_OPERATE_PARAM dcmi_operate_param,
    void *buf,
    unsigned int buf_size)
{
    int ret;
    if (dcmi_operate_param.sub_cmd == SERDES_PRBS_SET_CMD) {
        ret = dsmi_set_serdes_info(dev_id, dcmi_operate_param.main_cmd, dcmi_operate_param.sub_cmd, buf, buf_size);
        if (ret != 0) {
            gplog(LOG_ERR, "dsmi_set_serdes_info failed, logic_id=[%d], main_cmd=[%u], sub_cmd=[%u] ret=[%d]",
                dev_id, dcmi_operate_param.main_cmd, dcmi_operate_param.sub_cmd, ret);
            return dcmi_convert_error_code(ret);
        }
    } else {
        ret = dsmi_get_serdes_info(dev_id, dcmi_operate_param.main_cmd, dcmi_operate_param.sub_cmd,
                                   buf, &buf_size);
        if (ret != 0) {
            gplog(LOG_ERR, "dsmi_get_serdes_info failed. (logic_id=%d; main_cmd=%u; sub_cmd=%u; ret=%d)",
                  dev_id, dcmi_operate_param.main_cmd, dcmi_operate_param.sub_cmd, ret);
            return dcmi_convert_error_code(ret);
        }
    }
    return DCMI_OK;
}

int dcmiv2_exec_prbs(int dev_id, DCMIV2_PRBS_OPERATE_PARAM operate_para,
    DCMI_PRBS_OPERATE_RESULT *operate_result)
{
    int ret;
    unsigned int mainboard_id = 0;
    unsigned int buf_size = sizeof(DCMI_PRBS_OPERATE_RESULT);
    void *buf = (void *)operate_result;
    DCMI_PRBS_OPERATE_PARAM v1_operate_para = {0};

    // 权限检查
    ret = dcmiv2_check_prbs_permission();
    if (ret != DCMI_OK) {
        return ret;
    }

    ret = checkv2_prbs_operate_para(operate_para, buf);
    if (ret != DCMI_OK) {
        return ret;
    }

    ret = dcmiv2_get_mainboard_id(dev_id, &mainboard_id);
    if (ret != DCMI_OK) {
        gplog(LOG_ERR, "Failed to query main board id of card. err is %d", ret);
        return ret;
    }
    gplog(LOG_INFO, "mainboard_id:%u", mainboard_id);

    // 检查端口有效性
    ret = dcmiv2_check_prbs_port_valid(mainboard_id, operate_para);
    if (ret != DCMI_OK) {
        return ret;
    }

    // 转换参数并复制到buffer
    ret = convert_dcmiv2_to_dcmi_prbs_param(operate_para, &v1_operate_para);
    if (ret != DCMI_OK) {
        return ret;
    }

    // 日志：打印direction参数
    if (operate_para.sub_cmd == SERDES_PRBS_SET_CMD) {
        gplog(LOG_ERR, "dcmiv2_exec_prbs: direction=%u, serdes_prbs_type=%u",
            operate_para.operate_para.set_param.serdes_prbs_direction,
            operate_para.operate_para.set_param.serdes_prbs_type);
        gplog(LOG_ERR, "dcmiv2_exec_prbs: v1 direction=%u, serdes_prbs_type=%u",
            v1_operate_para.operate_para.set_param.serdes_prbs_direction,
            v1_operate_para.operate_para.set_param.serdes_prbs_type);
    }

    // 注意：对于SET操作，buf需要传递DCMI_SERDES_PRBS_SET_PARAM结构
    // 直接拷贝set_param的数据到buf
    ret = memcpy_s(buf, sizeof(DCMI_PRBS_OPERATE_RESULT), &(v1_operate_para.operate_para),
                   sizeof(v1_operate_para.operate_para));
    if (ret != 0) {
        gplog(LOG_ERR, "memcpy failed, ret=[%d]", ret);
        return DCMI_ERR_CODE_MEM_OPERATE_FAIL;
    }
    gplog(LOG_OP, "operate prbs, dev_id:%d", dev_id);
    ret = dcmiv2_exec_prbs_operate(dev_id, mainboard_id, v1_operate_para, buf, buf_size);
    if (ret != DCMI_OK) {
        return ret;
    }

    gplog(LOG_OP, "operate prbs success");
    return DCMI_OK;
}