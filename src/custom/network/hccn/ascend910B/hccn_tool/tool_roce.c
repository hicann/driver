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
#include <termios.h>
#include <getopt.h>
#include <arpa/inet.h>
#include "tool.h"
#include "cmd.h"
#include "cfg.h"
#include "dsmi_common_interface.h"
#include "tool_ops.h"
#include "weak_passwd_dict.h"
#include "ds_net.h"
#include "ds_net_tool_ext.h"
#include "tool_ext.h"
#include "tool_roce.h"

STATIC int tool_roce_check_arg(int argc, char **argv)
{
    if (argc != TOOL_ARGC_MIN_LEN) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "-g", strlen("-g") + 1)) {
        roce_err("invalid option -- '%s'", argv[0]);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}

STATIC int tool_roce_check_input_para(char **argv)
{
    unsigned int id;
    unsigned int argv_len;

    if (argv[ARGC_ID_2] == NULL) {
        roce_err("input para error");
        return UDA_PARAM_INVALID_ERR;
    }

    argv_len = strlen(argv[ARGC_ID_2]);
    for (id = 0; id < argv_len; id++) {
        if (((argv[ARGC_ID_2])[id] < '0') || ((argv[ARGC_ID_2])[id] > '9')) {
            roce_err("Check fail. (value=\"%c\"; return=%d)", (argv[ARGC_ID_2])[id], UDA_PARAM_INVALID_ERR);
            return UDA_PARAM_INVALID_ERR;
        }
    }

    return 0;
}

static void tool_roce_print_context_info(unsigned int index, const char *info)
{
    DSMI_PRINT_INFO("context(0x%x):", index);
    DSMI_PRINT_INFO("%s", info);
}

int tool_roce_context_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret, len;
    char info[INFO_PAYLOAD_LEN] = {0};
    enum ds_net_context_type type = DS_TYPE_MAX;
    unsigned int id, index;
    struct dsmi_roce_context_factors roce_context_factors;

    struct context_cmd_info context_cmd_list[] = {
        {DS_TYPE_QPC, "qpc"}, {DS_TYPE_AEQC, "aeqc"}, {DS_TYPE_CEQC, "ceqc"},
        {DS_TYPE_CQC, "cqc"}, {DS_TYPE_MPT, "mpt"}
    };

    ret = tool_roce_check_arg(argc, argv);
    if (ret) {
        roce_err("check arg err, ret[%d]", ret);
        return ret;
    }
    param->get_cmd_flag = true;

    len = strlen(argv[1]);

    for (id = 0; id < sizeof(context_cmd_list) / sizeof(context_cmd_list[0]); id++) {
        if ((strncmp(argv[1], context_cmd_list[id].cmd, len) == 0) && ((argv[1])[len] == 0)) {
            type = context_cmd_list[id].type;
            break;
        }
    }

    if (id == sizeof(context_cmd_list) / sizeof(context_cmd_list[0])) {
        roce_err("not found context cmd[%s]", argv[1]);
        return UDA_PARAM_INVALID_ERR;
    }

    ret = tool_roce_check_input_para(argv);
    if (ret) {
        roce_err("check input para err, ret[%d]", ret);
        return ret;
    }

    ret = tool_para_overflow_check(argv[ARGC_ID_2], TOOL_MAX_QPCINDEX, UDA_PARAM_ROCE_CTXT_OUT_OF_RANGE_ERR);
    if (ret) {
        roce_err("[tool_roce_context_cmd_execute] argc_ID_2 overflow, %s", argv[ARGC_ID_2]);
        return ret;
    }

    index = (unsigned int)strtol(argv[ARGC_ID_2], NULL, NUMBER_BASE);
    roce_context_factors.type = type;
    roce_context_factors.len = INFO_PAYLOAD_LEN;
    roce_context_factors.index = index;
    ret = dsmi_get_roce_context(param->logic_id, 0, roce_context_factors, info);
    if (ret) {
        roce_err("dsmi get context fail logic_id[%d] port[%d] ret[%d] type[%d]", param->logic_id, 0, ret, type);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    info[INFO_PAYLOAD_LEN - 1] = '\0';
    tool_roce_print_context_info(index, info);

    return 0;
}

static unsigned int tool_align(unsigned int val, unsigned int align)
{
    return ((val + align - 1) & ~(align - 1));
}

static int tool_get_reg_info_ext(struct tool_param *param)
{
    int ret;
    char *info = NULL;

    info = (char *)calloc(MAX_TRANS_DATA_LEN, sizeof(char));
    if (info == NULL) {
        roce_err("dsmi get eth reg malloc fail! logic_id[%d]",
                 param->logic_id);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = dsmi_get_eth_reg_info(param->logic_id, 0, info, MAX_TRANS_DATA_LEN);
    if (ret) {
        roce_err("dsmi get eth reg fail! ret[%d] logic_id[%d]", ret, param->logic_id);
        free(info);
        info = NULL;
        ret = (ret == UDA_TOOL_SYS_BUSY_ERR) ? UDA_TOOL_SYS_BUSY_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
        return ret;
    }
    info[MAX_TRANS_DATA_LEN - 1] = '\0';
    TOOL_PRINT_INFO("eth reg info:");
    TOOL_PRINT_INFO("%s", info);

    free(info);
    info = NULL;

    return 0;
}

#define ROCE_DFX_PRINT_NUM_PER_LINE (8)
#define ROCE_DFX_LEN_ALIGN (ROCE_DFX_PRINT_NUM_PER_LINE * 4) // algin 8 * sizeof(u32)

STATIC int tool_get_reg_info(int argc, char **argv, struct tool_param *param)
{
    int ret, i;
    unsigned int *ptr = NULL;
    unsigned int *data = NULL;
    struct ds_roce_dfx roce_dfx_len = { 0 };

    if (argc != 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    ret = tool_get_reg_info_ext(param);
    if (ret != 0) {
        return ret;
    }

    ret = dsmi_get_roce_dfx_len(param->logic_id, 0, &roce_dfx_len);
    if (ret) {
        roce_err("dsmi get roce dfx len fail! ret[%d] logic_id[%d]", ret, param->logic_id);
        ret = (ret == UDA_TOOL_SYS_BUSY_ERR) ? UDA_TOOL_SYS_BUSY_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
        return ret;
    }

    if (roce_dfx_len.buf_len > MAX_TRANS_DATA_LEN) {
        roce_err("dsmi get roce dfx len oversize(%u)! logic_id[%d]", roce_dfx_len.buf_len, param->logic_id);
        ret = (ret == UDA_TOOL_SYS_BUSY_ERR) ? UDA_TOOL_SYS_BUSY_ERR : UDA_DSMI_EXE_ERR;
        return ret;
    }

    data = (unsigned int *)calloc(1, tool_align(roce_dfx_len.buf_len, ROCE_DFX_LEN_ALIGN));
    if (data == NULL) {
        roce_err("dsmi get roce dfx malloc fail! buf_len[%d] logic_id[%d]",
                 roce_dfx_len.buf_len, param->logic_id);
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = dsmi_get_roce_dfx_data(param->logic_id, 0, (char *)data, roce_dfx_len.buf_len);
    if (ret) {
        roce_err("dsmi get roce dfx data fail! ret[%d] logic_id[%d]", ret, param->logic_id);
        free(data);
        data = NULL;
        ret = (ret == UDA_TOOL_SYS_BUSY_ERR) ? UDA_TOOL_SYS_BUSY_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
        return ret;
    }

    ptr = data;
    TOOL_PRINT_INFO("ROCEE reg info:");
    for (i = 0; i < (roce_dfx_len.buf_len >> 2U); i += ROCE_DFX_PRINT_NUM_PER_LINE) {
        TOOL_PRINT_INFO("0x%04x: %08x %08x %08x %08x %08x %08x %08x %08x",
            i, *ptr, *(ptr + 0x1), *(ptr + 0x2), *(ptr + 0x3), *(ptr + 0x4), *(ptr + 0x5),
            *(ptr + 0x6), *(ptr + 0x7));
        ptr += ROCE_DFX_PRINT_NUM_PER_LINE;
    }

    free(data);
    data = NULL;
    return 0;
}

/**
 * string_toul - string to u64
 * @nptr: the string
 * @value: the output value
 **/
int string_toul(const char *nptr, unsigned long long *value)
{
    char *endptr = NULL;
    unsigned long long tmp_value;

    tmp_value = strtoul(nptr, &endptr, 0);
    if (*endptr != 0) {
        return -EINVAL;
    }

    *value = tmp_value;
    return 0;
}

STATIC int tool_get_network_reg_addr(char *argv, unsigned long long *addr)
{
#define TOOL_NIC_ADDR_MASK 0x11FFFFFFULL
#define TOOL_NIC_TQPS_MASK 0x7FFFFUL
#define BIT(x)  (1UL << (x))
    unsigned long long tmp_addr = 0;
    int ret;

    ret = string_toul(argv, &tmp_addr);
    if (ret) {
        roce_err("-a param is error.");
        return ret;
    }

    if (tmp_addr & ~TOOL_NIC_ADDR_MASK) {
        roce_err("-a param is out of range.");
        return -EINVAL;
    }

    /* The reg addr must be 4-byte aligned. */
    if (tmp_addr & 0x3) {
        roce_err("bus error, reg addr is invalid.");
        return -EINVAL;
    }

    /* 屏蔽NIC PF/VF tqps reg */
    if (!(tmp_addr & BIT(28)) && (tmp_addr & ~TOOL_NIC_TQPS_MASK)) {
        roce_err("addr error, reg addr not support read.\n");
        return -EINVAL;
    }

    *addr = tmp_addr;

    return 0;
}

STATIC int tool_get_network_reg(int argc, char **argv, struct tool_param *param)
{
    unsigned long long reg_addr;
    unsigned long reg_value = 0;
    int ret;

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = tool_get_network_reg_addr(argv[0], &reg_addr);
    if (ret) {
        roce_err("tool get network reg addr fail! ret[%d] logic_id[%d]\n", ret, param->logic_id);
        return UDA_PARAM_INVALID_ERR;
    }

    ret = dsmi_get_network_register(param->logic_id, 0, reg_addr, &reg_value);
    if (ret) {
        roce_err("dsmi get network register fail! ret[%d] logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    TOOL_PRINT_INFO("addr: 0x%llx; value:0x%lx", reg_addr, reg_value);

    return 0;
}

int tool_reg_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret = 0;
    char **argv_tmp = argv + 1;
    int argc_tmp = argc - 1;
    int logic_id = param->logic_id;

    if (argc == 0) {
        roce_err("tool_reg_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_reg_info(argc_tmp, argv_tmp, param);
        if (ret) {
            roce_err("tool get reg info fail! ret=%d, logic_id=%d", ret, logic_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "-a", strlen("-a") + 1)) {
        param->get_cmd_flag = true; // hccn_tool [-i %d] -reg -a [%d]：获取network寄存器值
        ret = tool_get_network_reg(argc_tmp, argv_tmp, param);
        if (ret) {
            roce_err("tool get network reg fail! ret=%d, logic_id=%d", ret, logic_id);
            return ret;
        }
    } else {
        roce_err("tool_reg_cmd_execute invalid operation[%s]", argv[0]);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}

char is_empty_ascii(unsigned char c)
{
    return !(c > VALID_ASCII_LOW && c < VALID_ASCII_HIGH);
}
 
// 要求当vendor rev为两个空格或\0或非法字符，即用户无法直接看到的时候，打印NA
void tool_show_vendor_rev(struct ds_optical_info *info)
{
    unsigned char char1 = info->additional_info.vendor_rev[0];
    unsigned char char2 = info->additional_info.vendor_rev[1];
 
    if (is_empty_ascii(char1) && is_empty_ascii(char2)) {
        TOOL_PRINT_INFO("vendor rev           : NA");
    } else {
        TOOL_PRINT_INFO("vendor rev           : %c%c", char1, char2);
    }
}
 
void tool_show_optical_specification_compliance(struct ds_optical_info *info)
{
    // 该数组的具体含义见 SFF-8636_R2.10a.pdf Page 50
    unsigned char *data = info->additional_info.specification_compliance;
    int i;
 
    if ((info->present != TOOL_XSFP_PRESENT) || (data[0] == 0xFF)) {
        TOOL_PRINT_INFO("Specification compliance: NA");
        return;
    }
 
    TOOL_PRINT_INFO("Specification compliance: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",
        data[0], data[NUMBER_1], data[NUMBER_2], data[NUMBER_3],
        data[NUMBER_4], data[NUMBER_5], data[NUMBER_6], data[NUMBER_7]);
}

void tool_show_additional_optical_snr_info(struct ds_optical_info *info, const int sflag)
{
    /* 光模块已在device转换为float格式，此处只进行一半的偏移 */
    int offset = sflag / 2;
    info->additional_info.snr_support <<=
        (sflag == 0 ? TOOL_SNR_SUPPORT_BIT_FRONT_OFFSET : TOOL_SNR_SUPPORT_BIT_REAR_OFFSET);
    bool host_support = (info->additional_info.snr_support >> TOOL_SNR_SUPPORT_BIT_HOST) & 0x1;
    bool media_support = (info->additional_info.snr_support >> TOOL_SNR_SUPPORT_BIT_MEDIA) & 0x1;
    
    if (info->dr4_flag == 0x42) {
        tool_show_additional_dr4_optical_snr_info(info, offset, host_support, media_support);
    } else {
        for (int i = 0; i < XSFP_SHOW_SNR_LEN; i++) {
            if (host_support) {
                TOOL_PRINT_INFO("Host SNR Lane%d       : %.4f dB", i, info->additional_info.host_snr[i + offset]);
            } else {
                TOOL_PRINT_INFO("Host SNR Lane%d       : not supported", i);
            }
        }
 
        for (int i = 0; i < XSFP_SHOW_SNR_LEN; i++) {
            if (media_support) {
                TOOL_PRINT_INFO("Media SNR Lane%d      : %.4f dB", i, info->additional_info.media_snr[i + offset]);
            } else {
                TOOL_PRINT_INFO("Media SNR Lane%d      : not supported", i);
            }
        }
    }
}

static struct xsfp_physical_code_map g_xsfp_physical_code_map[] = {
    {"34061089", XSFP_FIBER_FACE_TYPE_UPC},
    {"34061299", XSFP_FIBER_FACE_TYPE_UPC},
    {"34160118", XSFP_FIBER_FACE_TYPE_UPC},
    {"34160189", XSFP_FIBER_FACE_TYPE_APC},
    {"02313FHB", XSFP_FIBER_FACE_TYPE_UPC},
    {"34160023", XSFP_FIBER_FACE_TYPE_APC},
    {"34160104", XSFP_FIBER_FACE_TYPE_APC},
    {"34160105", XSFP_FIBER_FACE_TYPE_APC},
    {"34160168", XSFP_FIBER_FACE_TYPE_APC},
    {"34160198", XSFP_FIBER_FACE_TYPE_APC},
    {"34160207", XSFP_FIBER_FACE_TYPE_APC},
    {"34160209", XSFP_FIBER_FACE_TYPE_APC},
    {"02315AKC", XSFP_FIBER_FACE_TYPE_UPC},
};

struct xsfp_physical_code_map *tool_get_xsfp_physical_code_map(struct ds_optical_info *info)
{
    int i;
    int cnt = sizeof(g_xsfp_physical_code_map) / sizeof(g_xsfp_physical_code_map[0]);

    for (i = 0; i < cnt; i++) {
        if (strncmp(info->additional_info.physical_code, g_xsfp_physical_code_map[i].physical_code,
            TOOL_XSFP_PHYSICAL_CODE_LEN) == 0) {
            return &g_xsfp_physical_code_map[i];
        }
    }
    return NULL;
}

void tool_show_additional_optical_physical_code_info(struct ds_optical_info *info)
{
    struct xsfp_physical_code_map *pc_map = NULL;

    pc_map = tool_get_xsfp_physical_code_map(info);
    if (pc_map != NULL) {
        TOOL_PRINT_INFO("Physical Code        : %s", pc_map->face_type);
    } else {
        TOOL_PRINT_INFO("Physical Code        : %s", "NA");
    }
}

int tool_cfg_recovery_err_proc(int ret, int phy_id, const char *conf_param)
{
    if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
        roce_info("The %s conf name is not found in config file, skipped. (ret=%d)", conf_param, ret);
        return 0;
    } else { // 其他错误返回失败
        roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, phy_id);
        return ret;
    }
}

int tool_cfg_roce_port_recovery(struct tool_param *param)
{
    int ret;
    char roce_port[SIX_VALUE] = "";
    int argc;
    char *argv[ARGC_ID_2];
 
    ret = cfg_read_conf(param->phy_id, "roce_port", roce_port, sizeof(roce_port));
    if (ret != 0) {
        return tool_cfg_recovery_err_proc(ret, param->phy_id, "roce_port");
    } else {
        roce_info("roce_port need recover cfg");
        ret = strncmp(roce_port, "-1", strlen("-1"));
        if (ret) {
            argc = ARGC_ID_2;
            argv[0] = "port";
            argv[1] = roce_port;
        } else {
            argc = ARGC_ID_1;
            argv[0] = "auto";
        }
        ret = tool_set_roce_port(param->logic_id, param->phy_id, argc, argv, param);
        if (ret) {
            roce_err("Roce port set fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        }
    }
 
    return ret;
}
 
STATIC int handle_multi_qp(int phy_id, int *argc, char **argv)
{
    const char *multi_qp_param[] = {"multi_qp", "count", NULL, "port", NULL};
    int ret, i;
 
    *argc = ARGC_ID_5;
    for (i = 0; i < ARGC_ID_5; i++) {
        if (multi_qp_param[i] != NULL) {
            ret = memcpy_s(argv[i], MAX_UDP_PORT_LIST_LEN, multi_qp_param[i], strlen(multi_qp_param[i]) + 1);
            if (ret != 0) {
                roce_err("%s get param name failed. (ret=%d)", __func__, ret);
                return ret;
            }
        }
    }

    // 从配置文件中读取端口数量和端口列表
    ret = cfg_read_conf(phy_id, "multi_qp_count", argv[ARGC_ID_2], MAX_UDP_PORT_LIST_LEN);
    if (ret != 0) {
        return tool_cfg_recovery_err_proc(ret, phy_id, "multi_qp_count");
    }
    ret = cfg_read_conf(phy_id, "multi_qp_udp_ports", argv[ARGC_ID_4], MAX_UDP_PORT_LIST_LEN);
    if (ret != 0) {
        return tool_cfg_recovery_err_proc(ret, phy_id, "multi_qp_udp_ports");
    }
 
    return 0;
}
 
STATIC int handle_code_mode(int phy_id, int *argc, char **argv)
{
    const char *nslb_dp_param[] = {"code", "-t", "nslb-dp", "listen_port", NULL};
    int ret, i;
 
    *argc = ARGC_ID_5;
    for (i = 0; i < ARGC_ID_5; i++) {
        if (nslb_dp_param[i] != NULL) {
            ret = memcpy_s(argv[i], MAX_UDP_PORT_LIST_LEN, nslb_dp_param[i], strlen(nslb_dp_param[i]) + 1);
            if (ret != 0) {
                roce_err("%s get param name failed. (ret=%d)", __func__, ret);
                return ret;
            }
        }
    }

    // 从配置文件中读取监听端口号
    ret = cfg_read_conf(phy_id, "nslb_dp_listen_port", argv[ARGC_ID_4], MAX_UDP_PORT_LIST_LEN);
    if (ret != 0) {
        return tool_cfg_recovery_err_proc(ret, phy_id, "nslb_dp_listen_port");
    }
    
    return 0;
}
 
STATIC int get_and_set_roce_ports_param(int phy_id, int *argc, char **argv, char *param_name)
{
    int ret;
    
    if (!strncmp(param_name, "multi_qp", strlen("multi_qp") + 1)) {
        ret = handle_multi_qp(phy_id, argc, argv);
    } else if (!strncmp(param_name, "code:nslb_dp", strlen("code:nslb_dp") + 1)) {
        ret = handle_code_mode(phy_id, argc, argv);
    } else {
        roce_err("Invalid param name. (param_name=%s)", param_name);
        return UDA_PARAM_INVALID_ERR;
    }
 
    return ret;
}
 
int tool_cfg_udp_port_mode_recovery(struct tool_param *param)
{
    int ret = -1, i;
    char roce_port_mode[MAX_UDP_MODE_LEN] = "";
    int argc = 0;
    char *argv[ARGC_ID_5] = {NULL};
 
    for (i = 0; i < ARGC_ID_5; ++i) {
        argv[i] = (char *)malloc(MAX_UDP_PORT_LIST_LEN * sizeof(char));
        if (argv[i] == NULL) {
            roce_err("%s malloc failed.", __func__);
            goto malloc_free;
        }
    }
 
    ret = cfg_read_conf(param->phy_id, "udp_port_mode", roce_port_mode, sizeof(roce_port_mode));
    if (ret != 0) {
        ret = tool_cfg_recovery_err_proc(ret, param->phy_id, "udp_port_mode");
        goto malloc_free;
    }
 
    ret = get_and_set_roce_ports_param(param->phy_id, &argc, argv, roce_port_mode);
    if (ret != 0) {
        roce_err("get and set roce ports param fail. (ret=%d; phy_id=%d)", ret, param->phy_id);
        goto malloc_free;
    }
 
    ret = tool_set_roce_ports_info(param->logic_id, param->phy_id, argc, argv);
    if (ret != 0) {
        roce_err("tool_set_roce_port execution failed!");
        goto malloc_free;
    }
 
malloc_free:
    for (i = 0; i < ARGC_ID_5; i++) {
        if (argv[i] != NULL) {
            free(argv[i]);
            argv[i] = NULL;
        }
    }
    return ret;
}
 
STATIC int udp_multi_qp_param_count(struct ds_roce_port_info *info, char *val, int len)
{
    unsigned long count;
    char *tmp_ptr = NULL;
    
    if (strlen(val) > TWO_VALUE || strlen(val) != len) {
        return UDA_PARAM_INVALID_ERR;
    }
 
    count = strtoul(val, &tmp_ptr, STR_NUM_BASE);
    if (tmp_ptr == val || *tmp_ptr != '\0') {
        roce_err("alg para val must be unsigned int. (count=%u, tail=%s)", count, tmp_ptr);
        return UDA_PARAM_INVALID_ERR;
    }
    if (count < QP_NUM_MIN || count > QP_NUM_MAX) {
        roce_err("multi qp mode param count is invalid. (count=%u)", count);
        return UDA_PARAM_INVALID_ERR;
    }
    info->port_cnt = (unsigned int)count;
 
    return 0;
}
 
// 检查输入格式是否为 port-port 格式或者 port,port,..,port 格式
STATIC int isValidPortFormat(const char *val, int count)
{
    int i, hcnt = 0, ccnt = 0; // hcnt为"-"数量，ccnt为","数量
    int ret = UDA_PARAM_INVALID_ERR;
 
    for (i = 0; i < strlen(val); i++) {
        if (val[i] == '-') {
            hcnt++;
        } else if (val[i] == ',') {
            ccnt++;
        } else {
            continue;
        }
    }
 
    if ((ccnt == 0) && (hcnt == 1)) {
        ret = HYPHEN_FORMAT;
    } else if ((hcnt == 0) && (ccnt == (count - 1))) {
        ret = COMMA_FORMAT;
    }
 
    return ret;
}

// 检查端口号是否在范围内
STATIC int isValidPort(unsigned long port_number)
{
    if (port_number < UDP_PORT_MIN || port_number > UDP_PORT_MAX) {
        TOOL_PRINT_INFO("Udp port is out of range, expect %u~%u", UDP_PORT_MIN, UDP_PORT_MAX);
        return UDA_PARAM_INVALID_ERR;
    }
    return 0;
}
 
STATIC int parse_comma_format(struct ds_roce_port_info *info, char *val, int count)
{
    unsigned long tmp_val;
    int i, port_num = 0;
    char *next_ptr = NULL;
    char *end_str_p = NULL;
    char *size_str = NULL;
 
    size_str = strtok_s(val, ",", &next_ptr);
    while (size_str != NULL) {
        if (port_num >= count) {
            roce_err("Get Invalid port format.\n");
            return UDA_PARAM_INVALID_ERR;
        }
 
        tmp_val = strtoul(size_str, &end_str_p, NUMBER_BASE);
        if ((end_str_p == size_str) || (*end_str_p != '\0') || (errno == ERANGE) || isValidPort(tmp_val)) {
            roce_err("Transfer port number value failed.\n");
            return UDA_PARAM_INVALID_ERR;
        }
        i = 0;
        // 检查是否有重复的端口号
        while (port_num >= 1 && i < port_num) {
            if (tmp_val == info->ports_list[i]) {
                TOOL_PRINT_INFO("Get duplicate udp port.");
                return UDA_PARAM_INVALID_ERR;
            }
            i++;
        }
        info->ports_list[port_num] = (unsigned int)tmp_val;
        port_num++;
        size_str = strtok_s(NULL, ",", &next_ptr);
    }
    if (port_num != count) {
        roce_err("Get Invalid port format.\n");
        return UDA_PARAM_INVALID_ERR;
    }
    return 0;
}
 
STATIC int parse_hyphen_format(struct ds_roce_port_info *info, char *val, unsigned int count)
{
    unsigned long port_begin, port_end;
    char *end_str_p = NULL;
    char *next_ptr = NULL;
    char *size_str = NULL;
    unsigned int i;
    int ret;
    
    // 解析开始端口和结束端口
    ret = sscanf_s(val, "%lu-%lu", &port_begin, &port_end);
    if (ret <= 0) {
        roce_err("multi_qp mode parse hyphen format udp ports failed. (ret=%d)\n", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
 
    if (isValidPort(port_begin) || isValidPort(port_end)) {
        return UDA_PARAM_INVALID_ERR;
    }
 
    // 结束端口需要大于开始端口，且范围内端口数量为 count
    if (port_end <= port_begin || ((port_end - port_begin + 1) != count)) {
        roce_err("multiqp port list range is invalid. (port_begin=%lu, port_end=%lu)\n", port_begin, port_end);
        return UDA_PARAM_INVALID_ERR;
    }
 
    for (i = 0; i < count; i++) {
        info->ports_list[i] = port_begin + i;
    }
 
    return 0;
}
 
STATIC int udp_multi_qp_ports_list(struct ds_roce_port_info *info, char *val, int len)
{
    int ret = 0, retval = 0;
 
    if (val == NULL || strlen(val) < NINE_VALUE || strlen(val) != len) {
        roce_err("multi qp mode gets invalid port list.");
        return UDA_PARAM_INVALID_ERR;
    }
 
    ret = isValidPortFormat(val, info->port_cnt);
    switch (ret) {
        case COMMA_FORMAT:
            retval = parse_comma_format(info, val, info->port_cnt);
            break;
        case HYPHEN_FORMAT:
            retval = parse_hyphen_format(info, val, info->port_cnt);
            break;
        default:
            retval = ret;
            break;
    }
 
    return retval;
}

STATIC int tool_parse_ports_info_multi_qp_mode(struct ds_roce_port_info *ports_info, int argc, char **argv)
{
    char val[MAX_UDP_PORT_LIST_LEN] = {0};
    int ret, i, cnt = 0;

    struct udp_multi_qp_info multi_qp_param_list[] = {
        {"count", udp_multi_qp_param_count},
        {"port", udp_multi_qp_ports_list},
    };
 
    for (i = 0; i < (sizeof(multi_qp_param_list) / sizeof(multi_qp_param_list[0])); i++) {
        ret = memset_s(val, MAX_UDP_PORT_LIST_LEN, 0, MAX_UDP_PORT_LIST_LEN);
        if (ret != 0) {
            roce_err("multi_qp_param_list tmp val memset failed. (ret=%d)\n", ret);
            return UDA_TOOL_INNER_PARAM_ERR;
        }

        // 校验count、port命令字
        if ((strncmp(argv[cnt], multi_qp_param_list[i].param, strlen(multi_qp_param_list[i].param) + 1) != 0) ||
            (strlen(argv[cnt]) != strlen(multi_qp_param_list[i].param))) {
            roce_err("Get unsupport param. (param=%s)", argv[cnt]);
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
        ret = memcpy_s(val, MAX_UDP_PORT_LIST_LEN, argv[cnt + 1], strlen(argv[cnt + 1]) + 1);
        if (ret != 0) {
            roce_err("Get param copy failed. (ret=%d; max_len=%d; real_len=%d)",
                     ret, MAX_UDP_PORT_LIST_LEN, strlen(argv[cnt + 1]));
            return UDA_TOOL_NO_MEM_ERR;
        }
 
        // 校验 count/port 后的具体数值格式
        ret = multi_qp_param_list[i].param_parse_func(ports_info, val, strlen(val));
        if (ret != 0) {
            roce_err("multi_qp_param_list parse_func execution failed! (ret=%d)\n", ret);
            return ret;
        }
        
        cnt += TWO_VALUE;
    }
 
    return 0;
}
 
STATIC int tool_parse_ports_info_code_mode(struct ds_roce_port_info *ports_info, int argc, char **argv)
{
    unsigned long port;
    char *tmp_ptr = NULL;
    char *val;
 
    if (argv == NULL || argc < TWO_VALUE) {
        return UDA_PARAM_INVALID_ERR;
    }
 
    if (argc == TWO_VALUE) {
        if (strncmp(argv[0], "-t", strlen("-t") + 1) ||
            strncmp(argv[1], UDP_PORT_CODE_NSLB_DP_MODE, strlen(UDP_PORT_CODE_NSLB_DP_MODE) + 1)) {
            goto err;
        }
        ports_info->listen_port = DEFAULT_LISTEN_PORT;
    } else if (argc == FOUR_VALUE) {
        if (strncmp(argv[0], "-t", strlen("-t") + 1) ||
            strncmp(argv[1], UDP_PORT_CODE_NSLB_DP_MODE, strlen(UDP_PORT_CODE_NSLB_DP_MODE) + 1) ||
            strncmp(argv[ARGC_ID_2], "listen_port", strlen("listen_port") + 1)) {
            goto err;
        }
        val = argv[ARGC_ID_3];
        port = strtoul(val, &tmp_ptr, STR_NUM_BASE);
        if (tmp_ptr == val || *tmp_ptr != '\0') {
            goto err;
        }
        if (port < LISTEN_PORT_MIN || port > LISTEN_PORT_MAX) {
            TOOL_PRINT_INFO("Listen port is out of range, expect %d~%d", LISTEN_PORT_MIN, LISTEN_PORT_MAX);
            return UDA_PARAM_INVALID_ERR;
        }
        ports_info->listen_port = (unsigned int)port;
    } else {
        goto err;
    }
    
    return 0;
err:
    roce_err("Code mode get invalid param. (param=%s)", argv[0]);
    return UDA_PARAM_INVALID_ERR;
}
 
int tool_roce_ports_clear_conf(int phy_id)
{
    int i, ret, retval;
    char val[MAX_UDP_PORT_LIST_LEN] = "";
    const char *udp_port_conf[] = {"roce_port", "udp_port_mode", "multi_qp_count", "multi_qp_udp_ports",
                                   "nslb_dp_listen_port"};
    for (i = 0; i < sizeof(udp_port_conf) / sizeof(udp_port_conf[0]); i++) {
        ret = cfg_read_conf(phy_id, udp_port_conf[i], val, sizeof(val));
        if (!ret) {
            retval = cfg_del_conf(phy_id, udp_port_conf[i]);
            if (retval) {
                roce_err("cfg_del_conf failed. (retval=%d; phy_id=%d)", retval, phy_id);
                return retval;
            }
        } else if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
            continue;
        } else {
            roce_err("cfg read conf failed.");
            return ret;
        }
    }
 
    return 0;
}

STATIC int format_ports_list(struct ds_roce_port_info *ports_info, char *port_list, int maxlen)
{
    int len = 0, total_len = 0, remain_len = 0;
    unsigned int i;
 
    if (ports_info->port_cnt == 0) {
        port_list[0] = '\0'; // 如果没有端口，则设置为空字符串
        return 0;
    }
    
    // 端口号拼接，通过逗号分割
    for (i = 0; i < ports_info->port_cnt; ++i) {
        remain_len = maxlen - total_len;
        len = snprintf_s(port_list + total_len, remain_len, remain_len - 1, "%u,", ports_info->ports_list[i]);
        if (len <= 0 || len >= remain_len - 1) {
            roce_err("tool format_ports_list snprintf_s fail. (len=%d)", len);
            return len;
        }
        total_len += len;
    }
 
    // 去掉最后一个逗号
    if (total_len > 0) {
        port_list[total_len - 1] = '\0';
    }
 
    return 0;
}
 
STATIC int tool_roce_ports_write_conf(int phy_id, struct ds_roce_port_info ports_info, char **argv)
{
    int i;
    char port_list[MAX_UDP_PORT_LIST_LEN] = {0};
    char listen_port[MAX_PORT_LEN] = {0};
    int ret = 0;
    unsigned int uret = 0;
 
    ret = tool_roce_ports_clear_conf(phy_id);
    if (ret) {
        roce_err("tool_roce_ports_clear_conf failed. (ret=%d; phy_id=%d)", ret, phy_id);
        return ret;
    }
 
    if (ports_info.port_mode == UDP_MODE_MULTI_QP) {
        ret = format_ports_list(&ports_info, port_list, MAX_UDP_PORT_LIST_LEN);
        if (ret) {
            return ret;
        }
        uret = (unsigned int)cfg_write_conf(phy_id, "udp_port_mode", "multi_qp");
        uret |= (unsigned int)cfg_write_conf(phy_id, "multi_qp_count", argv[TWO_VALUE]);
        uret |= (unsigned int)cfg_write_conf(phy_id, "multi_qp_udp_ports", port_list);
        if (uret) {
            roce_err("tool_roce_ports_write_conf multi_qp mode failed. (ret=%d)", (int)uret);
            return (int)uret;
        }
    } else if (ports_info.port_mode == UDP_MODE_CODE) {
        ret = snprintf_s(listen_port, MAX_PORT_LEN, MAX_PORT_LEN - 1, "%u", ports_info.listen_port);
        if (ret <= 0) {
            roce_warn("snprintf_s failed. (ret=%d; port=%u)\n", ret, ports_info.listen_port);
            return ret;
        }
        uret = (unsigned int)cfg_write_conf(phy_id, "udp_port_mode", "code:nslb_dp");
        uret |= (unsigned int)cfg_write_conf(phy_id, "nslb_dp_listen_port", listen_port);
        if (uret) {
            roce_err("tool_roce_ports_write_conf code mode failed. (ret=%d)", (int)uret);
            return (int)uret;
        }
    }
 
    return 0;
}

static int tool_check_roce_ports_info_params(struct ds_roce_port_info *ports_info, int argc, char **argv)
{
    int ret = 0;
    char **argv_tmp = argv + 1;

    if (argc < ONE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "multi_qp", strlen("multi_qp") + 1)) {
        // multi_qp count %d port %s;
        if ((argc != FIVE_VALUE)) {
            roce_err("argc err. (argc=%d)", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        ports_info->port_mode = UDP_MODE_MULTI_QP;
        ports_info->listen_port = 0;
        ret = tool_parse_ports_info_multi_qp_mode(ports_info, argc - 1, argv_tmp);
        if (ret) {
            roce_err("tool_parse_multi_qp_mode failed. (ret=%d, argc=%d, argv=%s)\n", ret, argc - 1, argv_tmp);
            return ret;
        }
    } else if (!strncmp(argv[0], "code", strlen("code") + 1)) {
         // code -t nslb-dp listen_port %d; code -t nslb-dp
        if ((argc != THREE_VALUE) && (argc != FIVE_VALUE)) {
            roce_err("argc err. (argc=%d)", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        ports_info->port_mode = UDP_MODE_CODE;
        ports_info->port_cnt = 1;
        ports_info->ports_list[0] = 0;
        ret = tool_parse_ports_info_code_mode(ports_info, argc - 1, argv_tmp);
        if (ret) {
            roce_err("tool_parse_ports_info_code_mode failed. (ret=%d, argc=%d, argv=%s)\n",
                     ret, argc - 1, argv_tmp);
            return ret;
        }
    } else {
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return  ret;
}

int tool_set_roce_ports_info(int logic_id, int phy_id, int argc, char **argv)
{
    int ret;
    struct ds_roce_port_info ports_info = {0};

    ret = tool_check_roce_ports_info_params(&ports_info, argc, argv);
    if (ret) {
        roce_err("tool_check_roce_ports_info_params failed. (ret=%d)", ret);
        return ret;
    }

    ret = dsmi_handle_multi_roce_ports(logic_id, &ports_info, SET_MODE);
    if (ret != 0) {
        roce_err("dsmi_set_multi_roce_ports failed. (ret=%d)", ret);
        if (ret == CONF_FILE_NOT_EXIST) {
            return UDA_TOOL_CONF_FILE_NOT_EXIST_ERR;
        }
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
 
    // recovery流程不更新配置文件
    if (!g_recovering) {
        ret = tool_roce_ports_write_conf(phy_id, ports_info, argv);
        if (ret) {
            roce_err("tool_roce_ports_write_conf failed\n");
            return ret;
        }
    }
 
    return 0;
}
 
STATIC int tool_show_multi_roce_ports(struct ds_roce_port_info ports_info)
{
    unsigned int mode = ports_info.port_mode;
    char port_list[MAX_UDP_PORT_LIST_LEN] = {0};
    int ret = 0;
    
    if (mode == UDP_PORT_MULTI_QP) {
        ret = format_ports_list(&ports_info, port_list, MAX_UDP_PORT_LIST_LEN);
        if (ret != 0) {
            return ret;
        }
        TOOL_PRINT_INFO("udp_port:%s", port_list);
        TOOL_PRINT_INFO("status:multi_qp");
        TOOL_PRINT_INFO("qp_count:%u", ports_info.port_cnt);
    } else if (mode == UDP_PORT_CODE) {
        TOOL_PRINT_INFO("udp_port:calculated by the NSLB-DP algorithm");
        TOOL_PRINT_INFO("status:code(nslb_dp)");
        TOOL_PRINT_INFO("listen_port:%u", ports_info.listen_port);
    } else {
        TOOL_PRINT_INFO("udp_port:unknown");
    }
 
    return ret;
}
 
STATIC int tool_get_multi_roce_ports(int logic_id, int argc, char **argv)
{
    struct ds_roce_port_info ports_info = {0};
    int ret;
 
    ret = dsmi_handle_multi_roce_ports(logic_id, &ports_info, GET_MODE);
    if (ret) {
        roce_err("dsmi get multi roce ports failed. (ret=%d, logic_id=%d)", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
 
    ret = tool_show_multi_roce_ports(ports_info);
    if (ret) {
        roce_err("tool show multi roce ports failed. (ret=%d, logic_id=%d)", ret, logic_id);
        return UDA_TOOL_INNER_PARAM_ERR;
    }
 
    return 0;
}
 
STATIC void tool_show_roce_port(int *roce_port)
{
    if (roce_port == NULL) {
        roce_err("roce_port is null.");
        return;
    }
    if (*roce_port == 0) {
        DSMI_PRINT_INFO("Unknown udp port");
    } else {
        // in 1980, bit 0x10000 means udp_port is auto
        if ((unsigned int)(*roce_port) & UDP_PORT_AUTO) {
            *roce_port = (int)((unsigned int)(*roce_port) & DSMI_UDP_RANGE);
            if (*roce_port == 0) {
                DSMI_PRINT_INFO("udp_port:Unknown");
            } else {
                DSMI_PRINT_INFO("udp_port:%d", *roce_port);
            }
            DSMI_PRINT_INFO("status:auto");
        } else {
            DSMI_PRINT_INFO("udp_port:%d", *roce_port);
            DSMI_PRINT_INFO("status:custom");
        }
    }
    return;
}
 
int tool_get_roce_port(int logic_id, int argc, char **argv)
{
    int roce_port = 0;
    unsigned int port_mode = 0;
    int ret;
 
    // [sip %s] [dip %s] 获取指定ip对及其端口号
    if (argc == ARGC_ID_4) {
        return tool_get_single_ippair(logic_id, argc, argv);
    }
    if (argc != 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
 
    ret = dsmi_get_roce_port(logic_id, 0, &roce_port);
    if (ret) {
        roce_err("dsmi get roce port failed. (ret=%d; logic_id=%d)", ret, logic_id);
        return UDA_DSMI_EXE_ERR;
    }
 
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
    port_mode = (unsigned int)roce_port & 0xF0000;
    // multi_qp、code 模式，从 multi_roce_ports 获取
    if ((port_mode == UDP_PORT_MULTI_QP) || (port_mode == UDP_PORT_CODE)) {
        return tool_get_multi_roce_ports(logic_id, argc, argv);
    }
#endif
    // auto、custom 模式
    tool_show_roce_port(&roce_port);
    ret = tool_get_all_ippair(logic_id);
    if (ret) {
        roce_err("tool get all ippair failed. (ret=%d; logic_id=%d)", ret, logic_id);
    }
 
    return ret;
}
