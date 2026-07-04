/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <unistd.h>
#include <sys/stat.h>
#include <termios.h>
#include <getopt.h>
#include <arpa/inet.h>
#include <regex.h>
#include <errno.h>
#include "tool.h"
#include "cmd.h"
#include "cfg.h"
#include "dsmi_common_interface.h"
#include "log.h"
#include "tool_ops.h"
#include "weak_passwd_dict.h"
#include "rdfx_tls.h"
#include "rdfx_tls_interface.h"
#include "encrypt.h"
#include "file_opt.h"
#include "network_comm.h"
#include "ds_net.h"
#include "hccn_comm.h"
#include "tool_tls.h"

STATIC int tool_parse_tls_clear_op(int argc, char **argv, struct tls_clear_info *clear_info)
{
    int i;
 
    for (i = 0; i < argc; i++) {
        if (tool_check_tls_param(argv[i], "-c") == 0) {
            continue;
        } else if (tool_check_tls_param(argv[i], "crl") == 0) {
            clear_info->clear_flag = TLS_CRL;
        } else if (tool_check_tls_param(argv[i], "host") == 0) {
            clear_info->save_mode = TLS_SAVE_TO_FILE;
        } else {
            roce_err("Invalid option: %s", argv[i]);
            return UDA_PARAM_INVALID_ERR;
        }
    }
 
    // 单CRL清理仅支持device侧
    if ((clear_info->clear_flag == TLS_CRL) && (clear_info->save_mode == TLS_SAVE_TO_FILE)) {
        roce_err("CRL clear do not support host side.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
 
    return UDA_EXE_SUCCESS;
}
 
STATIC int tool_clear_tls_cfg_on_device(int logic_id, const struct tls_clear_info *clear_info)
{
    int ret;
    
    ret = dsmi_clear_tls_cfg(logic_id, clear_info);
    if (ret == -ENODEV) {
        roce_err("VM lacks permission to access flash storage. ret=%d, logic_id=%d", ret, logic_id);
        return UDA_DSMI_NOT_SUPPORT_VM_ERR;
    } else if (ret == -ENOENT) {
        roce_err("No TLS certs found in flash, nothing to clear. ret=%d, logic_id=%d", ret, logic_id);
        return UDA_PARAM_TLS_NO_CERT_ERR;
    }
 
    if (ret != 0) {
        roce_err("DSMI clear failed, ret=%d, logic_id=%d", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return UDA_EXE_SUCCESS;
}

STATIC int tool_delete_enable_conf_if_needed(const struct tls_clear_info *clear_info, struct tool_param *param)
{
    int ret;
    char tls_enable[MAX_TLS_LEN] = "";
 
    if (clear_info->clear_flag != TLS_CLEAR_ALL) {
        return UDA_EXE_SUCCESS;  // 不需要删
    }

    // 清除tls证书的同时清除tls配置
    ret = cfg_read_conf(param->phy_id, "tls_enable", tls_enable, sizeof(tls_enable));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("Tls enable recovery conf do not need delete. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        ret = cfg_del_conf(param->phy_id, "tls_enable");
        if (ret != 0) {
            roce_err("Delete tls cfg error. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }

    return UDA_EXE_SUCCESS;
}

int tool_clear_tls_cfg(int argc, char **argv, struct tool_param *param)
{
    int ret, cfg_ret;
    unsigned int size_out = 0;
    struct tls_clear_info clear_info = {0};
    clear_info.clear_flag = TLS_CLEAR_ALL;                 // Clean up all by default.
    clear_info.save_mode = TLS_SAVE_TO_FlASH;              // Clean up the device side by default.

    if (argc == 0 || argc > TLS_HOST_ARGC_NUM) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = tool_parse_tls_clear_op(argc, argv, &clear_info);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("Parse option filed, ret[%d]", ret);
        return ret;
    }

    LOG_CONFIG("start to clear tls cfg of logic_id[%d]", param->logic_id);
    if (clear_info.save_mode == TLS_SAVE_TO_FILE) {
        ret = rdfx_clear_tls_cfg(param->logic_id, (const char *)&clear_info, sizeof(clear_info), NULL, &size_out);
        if (ret != 0) {
            roce_err("Failed to clear TLS config on host side, ret=%d", ret);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
    } else {
        if (tool_is_virtual_machine()) {
            roce_err("VM lacks permission to access flash storage.");
            return UDA_DSMI_NOT_SUPPORT_VM_ERR;
        }
        ret = tool_clear_tls_cfg_on_device(param->logic_id, &clear_info);
        if (ret == UDA_EXE_SUCCESS || ret == UDA_PARAM_TLS_NO_CERT_ERR) {
            cfg_ret = tool_delete_enable_conf_if_needed(&clear_info, param);
            if (cfg_ret != UDA_EXE_SUCCESS) {
                return cfg_ret;
            }
        }
    }

    if (ret == UDA_EXE_SUCCESS) {
        roce_info("TLS config cleared successfully. (logic_id=%d)", param->logic_id);
    }

    return ret;
}
