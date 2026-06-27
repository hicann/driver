/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include <arpa/inet.h>
#include <limits.h>
#include "dsmi_common_interface.h"
#include "tool.h"
#include "tool_recovery.h"
#include "tool_ext.h"
#include "cmd.h"
#include "cfg.h"
#include "log.h"
#include "hccn_comm.h"
#include "tool_ops.h"
#include "tool_roce.h"

#ifndef STUB_WEAK
#define STUB_WEAK __attribute__((weak))
#endif

struct tool_ip_value {
    ip_addr_t address[MAX_PORT_COUNT];
    ip_addr_t netmask[MAX_PORT_COUNT];
};

STATIC int tool_set_roce_port_custom_mode(int logic_id, int argc, char **argv)
{
    int ret;
    unsigned int roce_port;
 
    if (argc == ARGC_ID_2) {
        if ((strlen(argv[1]) > DSMI_MAX_UDP_PORT_LEN) || (strlen(argv[1]) < DSMI_MIN_UDP_PORT_LEN) ||
            check_str_is_num(argv[1], strlen(argv[1]))) {
            roce_err("Input port num is invalid.");
            return UDA_PARAM_INVALID_ERR;
        }
        roce_port = (unsigned int)strtol(argv[1], NULL, NUMBER_BASE);
    } else if (argc == ARGC_ID_6) { // 基于ip对配置udp端口号属于custom模式的特殊形式，基于ip对配置udp端口号不触发模式切换
        return tool_update_roce_port_ippair(logic_id, argc, argv, IPPAIR_SET);
    } else {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
 
    LOG_CONFIG("start to set roce_port of logic_id[%d]", logic_id);
    ret = dsmi_set_roce_port(logic_id, 0, roce_port);
    if (ret) {
        roce_err("dsmi set roce_port fail ret[%d] logic_id[%d] roce_port[%u]", ret, logic_id, roce_port);
        if (ret == CONF_FILE_NOT_EXIST) {
            return UDA_TOOL_CONF_FILE_NOT_EXIST_ERR;
        }
    }
 
    return dsmi_analysis_dsmi_ret_to_uda(ret);
}
 
STATIC int tool_set_roce_port_auto_mode(int logic_id, int argc, char **argv)
{
    int ret;
    unsigned int roce_port;
 
    if (argc != ARGC_ID_1) {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
 
    roce_port = 0;
    LOG_CONFIG("start to set roce_port of logic_id[%d]", logic_id);
    ret = dsmi_set_roce_port(logic_id, 0, roce_port);
    if (ret) {
        roce_err("dsmi set roce_port fail ret[%d] logic_id[%d] roce_port[%u]", ret, logic_id, roce_port);
        if (ret == CONF_FILE_NOT_EXIST) {
            return UDA_TOOL_CONF_FILE_NOT_EXIST_ERR;
        }
    }
 
    return dsmi_analysis_dsmi_ret_to_uda(ret);
}
 
int tool_set_roce_port(int logic_id, int phy_id, int argc, char **argv, struct tool_param *param)
{
    int ret = 0, i, port_mode = -1;
    struct udp_port_mode_map udp_port_mode_list[] = {
        {"port", UDP_PORT_CUSTOM},
        {"auto", UDP_PORT_AUTO},
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
        {"code", UDP_PORT_CODE},
        {"multi_qp", UDP_PORT_MULTI_QP},
#endif
    };
 
    if (argc < ONE_VALUE || argc > SIX_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    for (i = 0; i < sizeof(udp_port_mode_list) / sizeof(udp_port_mode_list[0]); i++) {
        if (!strncmp(argv[0], udp_port_mode_list[i].mode, strlen(udp_port_mode_list[i].mode) + 1)) {
            port_mode = udp_port_mode_list[i].mode_value;
            break;
        }
    }
    switch (port_mode) {
        case UDP_PORT_CUSTOM:
            ret = tool_set_roce_port_custom_mode(logic_id, argc, argv);
            break;
        case UDP_PORT_AUTO:
            ret = tool_set_roce_port_auto_mode(logic_id, argc, argv);
            break;
        case UDP_PORT_CODE:
            ret = tool_set_roce_ports_info(logic_id, phy_id, argc, argv);
            break;
        case UDP_PORT_MULTI_QP:
            // 天工不支持
            if (param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID ||
                param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID_2) {
                roce_err("This device does not support multi_qp cmd.");
                return UDA_PARAM_OP_NOT_SUPPORT_ERR;
            }
            ret = tool_set_roce_ports_info(logic_id, phy_id, argc, argv);
            break;
        default:
            ret = UDA_PARAM_OP_NOT_SUPPORT_ERR;
            roce_err("Invalid option.");
            break;
    }
 
    return ret;
}

int tool_roce_port_store_conf(int argc, char **argv, struct tool_param *param)
{
    int ret = UDA_SUCCESS;
    char str[PARAM_COUNT_THREE] = { 0 };

#ifdef CFG_SOC_PLATFORM_CLOUD_V2
    // 如果是auto/custom模式清除旧配置
    if (argc == ARGC_ID_2 || argc == ARGC_ID_3) {
        ret = tool_roce_ports_clear_conf(param->phy_id);
        if (ret) {
            roce_err("tool_roce_ports_clear_conf failed. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }
#endif

    // auto port
    if (argc == ARGC_ID_2) {
        ret = memcpy_s(str, PARAM_COUNT_THREE, "-1", strlen("-1") + 1);
        if (ret) {
            roce_err("Memcpy failed");
            return UDA_TOOL_NO_MEM_ERR;
        }
        ret = cfg_write_conf(param->phy_id, "roce_port", str);
    }

    // custom port
    if (argc == ARGC_ID_3) {
        ret = cfg_write_conf(param->phy_id, "roce_port", argv[ARGC_ID_2]);
    }

    if (ret) {
        roce_err("Write cfg error.(ret=%d; phy_id=%d)", ret, param->phy_id);
    }

    return ret;
}

int tool_roce_port_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    int logic_id = param->logic_id;
    int argc_tmp = argc - 1;
    char **argv_tmp = argv + 1;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_roce_port(logic_id, param->phy_id, argc_tmp, argv_tmp, param);
        if (ret) {
            roce_err("set roce_port failed, logic_id[%d]", param->logic_id);
            return ret;
        }
        return tool_roce_port_store_conf(argc, argv, param);
    }

    if (!strncmp(argv[0], "-g", strlen(argv[0]) + 1)) {
        param->get_cmd_flag = true;
        return tool_get_roce_port(logic_id, argc_tmp, argv_tmp);
    }

    if (!strncmp(argv[0], "-d", strlen(argv[0]) + 1)) {
        return tool_update_roce_port_ippair(logic_id, argc_tmp, argv_tmp, IPPAIR_DEL);
    }
 
    if (!strncmp(argv[0], "-c", strlen(argv[0]) + 1)) {
        return tool_clear_roce_port_ippair(logic_id, argc_tmp);
    }

    roce_err("Invalid operation");
    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}

STATIC struct ds_rdma_hw_stats *tool_alloc_hw_stats(const char * const *names, int num_counters)
{
    struct ds_rdma_hw_stats *stats = NULL;

    stats = calloc(sizeof(*stats) + num_counters * sizeof(unsigned long long), sizeof(char));
    if (stats == NULL) {
        roce_err("tool_alloc_hw_stats calloc fail.");
        return NULL;
    }

    stats->names = names;
    stats->num_counters = num_counters;

    return stats;
}

STATIC void tool_display_rdma_hw_stat(int phy_id, const struct ds_rdma_hw_stats * stats)
{
    int i;

    for (i = 0; i < stats->num_counters; i++) {
        TOOL_PRINT_INFO("[devid %d] %s: %llu", phy_id, stats->names[i], stats->value[i]);
    }
}

int tool_hw_stats_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    struct ds_rdma_hw_stats *rdma_hw_stats = NULL;
    int ret;

    static const char * const g_ds_roce_hw_stats_name[] = {
        "pd_alloc",
        "pd_dealloc",
        "mr_alloc",
        "mr_dealloc",
        "cq_alloc",
        "cq_dealloc",
        "qp_alloc",
        "qp_dealloc",
        "pd_active",
        "mr_active",
        "cq_active",
        "qp_active",
        "aeqe",
        "ceqe",
    };

    if (argc != ONE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    rdma_hw_stats = tool_alloc_hw_stats(g_ds_roce_hw_stats_name, ARRAY_SIZE(g_ds_roce_hw_stats_name));
    if (rdma_hw_stats == NULL) {
        roce_err("tool alloc hw stats fail.");
        return UDA_TOOL_NO_MEM_ERR;
    }

    if (strncmp(argv[0], "-g", strlen("-g") + 1) == 0) {
        param->get_cmd_flag = true;
        ret = dsmi_get_rdma_hw_stats(param->logic_id, 0, rdma_hw_stats);
        if (ret) {
            roce_err("dsmi get rdma hw stats fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
            ret = dsmi_analysis_dsmi_ret_to_uda(ret);
            goto out;
        }
        tool_display_rdma_hw_stat(param->phy_id, rdma_hw_stats);
    } else {
        roce_err("invalid option -- '%s'", argv[0]);
        ret = UDA_PARAM_OP_NOT_SUPPORT_ERR;
        goto out;
    }

out:
    free(rdma_hw_stats);
    rdma_hw_stats = NULL;

    return ret;
}

STATIC int parse_timeout_param(struct udhcpc_param *param, int *cur, int argc, char **argv)
{
    unsigned int timeout;
    char *tmp_ptr = NULL;

    if ((*cur + 1) >= argc) {
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    timeout = (unsigned int)strtoul(argv[*cur + 1], &tmp_ptr, STR_NUM_BASE);
    if ((tmp_ptr == argv[*cur + 1]) || (*tmp_ptr != '\0')) {
        roce_err("UDHCPC timeout must be unsigned int, now is %u, tail is %s", timeout, tmp_ptr);
        return UDA_PARAM_INVALID_ERR;
    } else if ((timeout > UDHCPC_MAX_TIMEOUT) || (timeout < UDHCPC_MIN_TIMEOUT)) {
        roce_err("UDHCPC timeout can not more than %u, now is %u", UDHCPC_MAX_TIMEOUT, timeout);
        return UDA_PARAM_INVALID_ERR;
    }

    param->timeout = timeout;
    *cur += 1;
    return UDA_EXE_SUCCESS;
}

STATIC int parse_quit_param(struct udhcpc_param *param, int *cur, int argc, char **argv)
{
    param->retain_process = false;
    *cur += 1;

    return UDA_EXE_SUCCESS;
}

STATIC int tool_print_udhcpc_info(struct udhcpc_param param, struct tool_param *p_param)
{
    int ret;
    unsigned int buf_size = (param.timeout + DEFAULT_UDHCPC_TIMEOUT) * UDHCPC_RUN_INFO_LEN;
    char *udhcpc_info = NULL;
    char *ip_version = (param.is_ipv6 ? "ipv6" : "ipv4");
    char *mask_or_prefix = (param.is_ipv6 ? "prefix-length" : "mask");

    LOG_SET_CONFIG("start to acquire dhcp ip of dev[%d]", p_param->phy_id);

    udhcpc_info = (char *)calloc(buf_size, sizeof(char));
    if (udhcpc_info == NULL) {
        roce_err("Tool calloc udhcpc_info failed.");
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = dsmi_acquire_dhcp_ip(p_param->logic_id, 0, &param, udhcpc_info, buf_size);
    if (ret != 0) {
        roce_err("dsmi acquire dhcp ip failed. (phy_id=%d; is_ipv6=%d; ret=%d)", p_param->phy_id,
            p_param->inet_protocol_type, ret);
        LOG_SET_CONFIG("acquire dhcp run failed. (phy_id=%d)", p_param->phy_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        goto out;
    }

    if (strstr(udhcpc_info, "lease time") != NULL && strstr(udhcpc_info, "setting") != NULL) {
        if (strstr(udhcpc_info, "adding router") != NULL) {
            LOG_SET_CONFIG("Acquired DHCP info, set %s ip/%s and router success.", ip_version, mask_or_prefix);
        } else {
            LOG_SET_CONFIG("Acquired DHCP info, set %s ip/%s success, no router set.", ip_version, mask_or_prefix);
        }
    } else if (strstr(udhcpc_info, "udhcpc running") != NULL) {
        LOG_SET_CONFIG("UDHCPC is running.");
        ret = UDA_DSMI_EXE_ERR;
    } else {
        LOG_SET_CONFIG("Acquire DHCP %s cmd run success, no ip and router set.", ip_version);
        ret = UDA_DSMI_EXE_ERR;
    }

    TOOL_PRINT_INFO("device:%d:%s", p_param->phy_id, udhcpc_info);

out:
    if (udhcpc_info != NULL) {
        free(udhcpc_info);
        udhcpc_info = NULL;
    }
    return ret;
}

STATIC int tool_acquire_dhcp_ip(struct tool_param *p_param, int argc, char **argv)
{
    static struct udhcpc_parse_param udhcpc_param_arr[] = {
        { "timeout", parse_timeout_param },
        { "quit", parse_quit_param },
        { NULL, NULL },
    };
    struct udhcpc_param param = {DEFAULT_UDHCPC_TIMEOUT, 0, true, p_param->inet_protocol_type};
    struct udhcpc_parse_param *param_info = NULL;
    int i, ret;

    if (argc > ARGC_ID_3) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    for (i = 0; i < argc; i++) {
        ret = UDA_PARAM_OP_NOT_SUPPORT_ERR;
        for (param_info = udhcpc_param_arr; param_info->parse_proc != NULL; param_info++) {
            if (strcmp(argv[i], param_info->param) == 0) {
                ret = param_info->parse_proc(&param, &i, argc, argv);
                break;
            }
        }
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("UDHCPC Error used cmd. (ret=%d).", ret);
            return ret;
        }
    }

    ret = tool_print_udhcpc_info(param, p_param);
    if (ret != 0) {
        roce_err("Call tool_print_udhcpc_info failed. (ret=%d).", ret);
        return ret;
    }

    return 0;
}

STATIC int tool_release_dhcp_ip(struct tool_param *p_param, int argc, char **argv)
{
    struct udhcpc_param param = {0};
    char info[UDHCPC_OUTBUFF_LEN] = {0};
    int ret;
    if (argc > 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    LOG_SET_CONFIG("start to release dhcp ip of dev[%d]", p_param->phy_id);
    param.is_ipv6 = p_param->inet_protocol_type;
    ret = dsmi_release_dhcp_ip(p_param->logic_id, 0, &param, info, UDHCPC_OUTBUFF_LEN);
    if (ret) {
        roce_err("dsmi release dhcp ip failed. (phy_id=%d; is_ipv6=%d; ret=%d)", p_param->phy_id,
            p_param->inet_protocol_type, ret);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    LOG_SET_CONFIG("release dhcp ip of dev[%d] success", p_param->phy_id);
    TOOL_PRINT_INFO("device:%d:%s", p_param->phy_id, info);

    return 0;
}

static int add_udhcpc_conf(struct tool_param *param)
{
    int ret;
    char inbuf[UDHCPC_QUIT_INBUFF_LEN] = {0};
 
    ret = sprintf_s(inbuf, UDHCPC_QUIT_INBUFF_LEN, "%s", "on");
    if (ret <= 0) {
        roce_err("udhcpc info cmd sprintf failed!");
        return UDA_TOOL_NO_MEM_ERR;
    }
 
    if (param->inet_protocol_type == IPV6_PROTOCOL) {
        ret = cfg_write_conf(param->phy_id, "udhcpc_ipv6_enable", inbuf);
        if (ret) {
            roce_err("write cfg error[%d], phy_id[%d]", ret, param->phy_id);
            TOOL_PRINT_ERR("Failed to write the udhcpc_ipv6 to the config file, \
                            and user configurations cannot be persisted.");
        }
    } else {
        ret = cfg_write_conf(param->phy_id, "udhcpc_enable", inbuf);
        if (ret) {
            roce_err("write cfg error[%d], phy_id[%d]", ret, param->phy_id);
            TOOL_PRINT_ERR("Failed to write the udhcpc_enable to the config file, \
                            and user configurations cannot be persisted.");
        }
    }
    
    return ret;
}
 
static int del_udhcpc_conf(struct tool_param *param)
{
    int ret = 0;
    if (param->inet_protocol_type == IPV6_PROTOCOL) {
        ret = cfg_del_conf(param->phy_id, "udhcpc_ipv6_enable");
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("del udhcpc ipv6 enable cfg error[%d], phy_id[%d]", ret, param->phy_id);
            return ret;
        }
    } else {
        ret = cfg_del_conf(param->phy_id, "udhcpc_enable");
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("del udhcpc ip cfg error[%d], phy_id[%d]", ret, param->phy_id);
            return ret;
        }
    }
 
    return 0;
}

int tool_udhcpc_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret = UDA_PARAM_OP_NOT_SUPPORT_ERR, argc_tmp = argc - 1;
    char **argv_tmp = argv + 1;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = is_ipv6_cmd(&argc, &argv);
    if (ret) {
        if (argc == 0 || argv == NULL) {
            roce_err("err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        if (is_atlas_9000_a3(param)) {
            roce_err("Ipv6 atlas_9000_a3 command is not supported.");
            return UDA_TOOL_OP_NOT_SUPPORT_IPV6_ERR;
        }
        param->inet_protocol_type = IPV6_PROTOCOL;
        argv_tmp = argv + 1;
        argc_tmp = argc - 1;
    }
    if (strncmp(argv[0], "-a", strlen("-a") + 1) == 0) {
        param->get_cmd_flag = true; // hccn_tool [-i %d] -udhcpc -a [timeout %d] [quit]：使用udhcpc获取ip
        ret = tool_acquire_dhcp_ip(param, argc_tmp, argv_tmp);
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("acquire dhcp ip failed. (ret=%d)", ret);
            return ret;
        }
        ret = add_udhcpc_conf(param);
        if (ret != 0) {
            roce_err("acquire dhcp ip conf write failed. (ret=%d)", ret);
        }
    } else if (strncmp(argv[0], "-r", strlen("-r") + 1) == 0) {
        ret = tool_release_dhcp_ip(param, argc_tmp, argv_tmp);
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("release dhcp ip failed. (ret=%d)", ret);
            return ret;
        }
        ret = del_udhcpc_conf(param);
        if (ret != 0) {
            roce_err("del acquire dhcp ip conf write failed. (ret=%d)", ret);
        }
    } else {
        roce_err("invalid option -- '%s'", argv[0]);
        ret = UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

int tool_cfg_netdetect_ipv6_recovery(struct tool_param *param)
{
    int ret;
    char address[MAX_IPV6_LEN] = "";

    ret = cfg_read_conf(param->phy_id, "IPv6netdetect", address, sizeof(address));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The [IPv6]netdetect conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    } else {
        roce_info("[IPv6]netdetect address need recover cfg");
        ret = tool_netdetect_set_address_ipv6(param->logic_id, address);
        if (ret) {
            roce_err("[IPv6]netdetect set address fail ret[%d] logic_id[%d]", ret, param->logic_id);
            return ret;
        }
    }

    return ret;
}

STATIC int tool_ipv6_to_str(unsigned char *ipv6, char *str, int num)
{
    struct in6_addr addr;
    if (str == NULL) {
        roce_err("Input param is NULL.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    (void)memcpy_s(addr.s6_addr, MAX_IPV6_NUM, ipv6, num);

    const char* result = inet_ntop(AF_INET6, ipv6, str, INET6_ADDRSTRLEN);
    if (result == NULL) {
        roce_err("Error in converting IPv6 address, ipv6 = %s, addr.s6_addr = %s\n", ipv6, addr.s6_addr);
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    return 0;
}

STATIC int tool_get_netdetect_ipv6(int argc, char **argv, const struct tool_param *param)
{
    int ret;
    char address[MAX_IPV6_LEN] = "0:0:0:0:0:0:0:0";
    struct ipv_addr ip = {0};
    ip.ip_flag = 1;

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    ret = dsmi_get_net_detect_ip_address(param->logic_id, 0, &ip);
    if (ret) {
        roce_err("dsmi_get_net_detect_ip_address fail ret[%d] logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    if (ip.ip_flag == 1) {
        ret = tool_ipv6_to_str(ip.ipv6, address, MAX_IPV6_NUM);
        if (ret) {
            roce_err("tool_ipv6_to_str fail ret[%d] logic_id[%d]", ret, param->logic_id);
            return ret;
        }
    }

    TOOL_PRINT_INFO("netdetect addr: %s", address);
    return 0;
}

int tool_inet_pton_ipv6_address(const char *str, unsigned char *ipv6, int length)
{
    struct in6_addr addr = {0};
    int ret;

    if (str == NULL || ipv6 == NULL) {
        roce_err("Input param is NULL.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    ret = inet_pton(AF_INET6, str, &addr);
    if (ret <= 0) {
        roce_err("Invalid IPv6 address. (ret=%d; errno=%d)", ret, errno);
        return UDA_PARAM_IP_INVALID_ERR;
    }
    (void)memcpy_s(ipv6, length, addr.s6_addr, MAX_IPV6_NUM);

    return 0;
}

int tool_netdetect_set_address_ipv6(int logic_id, const char *address)
{
    int ret;
    struct ipv_addr ip = {0};
    ip.ip_flag = 1;
    LOG_CONFIG("Start to set net detect ip of logic_id[%d]", logic_id);

    ret = tool_inet_pton_ipv6_address(address, ip.ipv6, MAX_IPV6_NUM);
    if (ret) {
        roce_err("Tool inet pton ipv6 address fail. (ret=%d)", ret);
        return ret;
    }
    ret = dsmi_set_net_detect_ip_address(logic_id, &ip);
    if (ret) {
        roce_err("dsmi set net detect fail! ret[%d] logic_id[%d]", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return ret;
}

STATIC int tool_set_netdetect_ipv6(int argc, char **argv, const struct tool_param *param)
{
    char address[MAX_IPV6_LEN] = "";
    const int index = 0;
    int ret;

    if (argc != THREE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    if (!strncmp(argv[1], "ipv6_address", strlen("ipv6_address") + 1)) {
        ret = memcpy_s(address, MAX_IPV6_LEN, argv[ARGC_ID_2], strlen(argv[ARGC_ID_2]) + 1);
        if (ret) {
            roce_err("memcpy_s address fail[%d], dlen[%d], slen[%u]", ret, MAX_IPV6_LEN, strlen(argv[ARGC_ID_2]) + 1);
            return UDA_TOOL_NO_MEM_ERR;
        }
    } else {
        roce_err("Err input cmd.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    ret = tool_netdetect_set_address_ipv6(param->logic_id, address);
    if (ret) {
        roce_err("Tool netdetect set address fail. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }
    ret = cfg_write_conf(param->phy_id, "IPv6netdetect", &address[index]);
    if (ret) {
        roce_err("Write cfg error. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    roce_info("Set logic_id[%d] netdetect address success!", param->logic_id);
    return ret;
}

int tool_netdetect_cmd_execute_ipv6(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_netdetect_ipv6(argc, argv, param);
        if (ret) {
            roce_err("tool_get_netdetect fail, ret:%d", ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_netdetect_ipv6(argc, argv, param);
        if (ret) {
            roce_err("tool_set_netdetect fail, ret:%d", ret);
            return ret;
        }
    } else {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}

int tool_netdetect_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret, argc_temp;
    char **argv_temp;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (is_ipv6_cmd(&argc, &argv)) {
        if (is_atlas_9000_a3(param)) {
            roce_err("Ipv6 atlas_9000_a3 command is not supported.");
            return UDA_TOOL_OP_NOT_SUPPORT_IPV6_ERR;
        }
        ret = tool_netdetect_cmd_execute_ipv6(argc, argv, param);
        if (ret != 0) {
            roce_err("tool_netdetect_cmd_execute_ipv6 fail, ret[%d]", ret);
            return ret;
        }
        return 0;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_netdetect(argc, argv, param);
        if (ret) {
            roce_err("tool_get_netdetect fail, ret:%d", ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_netdetect(argc, argv, param);
        if (ret) {
            roce_err("tool_set_netdetect fail, ret:%d", ret);
            return ret;
        }
    } else {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}

int tool_cfg_ip_ipv6_recovery(struct tool_param *param)
{
    int ret;
    char address[MAX_IPV6_LEN] = "";
    char netmask[MAX_IPV6_LEN] = "";

    ret = cfg_read_conf(param->phy_id, "IPv6address", address, sizeof(address));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The [IPv6]ip address conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }

    ret = cfg_read_conf(param->phy_id, "IPv6netmask", netmask, sizeof(netmask));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The [IPv6]netmask conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }

    roce_info("[IPv6]ip address need recover cfg");
    ret = tool_check_mtu_ipv6(param->logic_id);
    if (ret) {
        roce_err("check mtu failed when recover ipv6 configuration. (ret=%d)", ret);
        return ret;
    }

    ret = tool_ip_set_address_ipv6(param, address, netmask);
    if (ret) {
        roce_err("[IPv6]ip set address fail! ret[%d] logic_id[%d]", ret, param->logic_id);
        return ret;
    }

    return ret;
}

int tool_cfg_route_ipv6_recovery(struct tool_param *param)
{
    int ret;
    struct ds_ipv6_route_table_value ip_param = {0};
    char address[MAX_IPV6_LEN] = "";
    char netmask[MAX_IPV6_LEN] = "";
 
    ret = cfg_read_conf(param->phy_id, "udhcpc_ipv6_enable", address, sizeof(address));
    if (ret == 0) {
        roce_info("[IPv6]Udhcpc ipv6 enable, do not need recover route cfg, phy_id:[%d]", param->phy_id);
        return 0;
    }
    ret = cfg_read_conf(param->phy_id, "udhcpc_enable", address, sizeof(address));
    if (ret == 0) {
        roce_info("Udhcpc enable, do not need recover route cfg, phy_id:[%d]", param->phy_id);
        return 0;
    }

    ret = tool_read_hccn_conf_handle_action_ipv6(param, READ_TO_RECOVERY, ip_param);
    if (ret) {
        roce_err("tool_cfg_route_recovery: tool_read_hccn_conf_handle_action failed! ret is [%d]", ret);
        return ret;
    }
    return 0;
}

int tool_gateway_is_get_cmd_execute(struct tool_param *param, int *port, unsigned int *gw_addr, char *gw_str,
                                    unsigned int *default_phy_id)
{
    int ret;
    bool is_gateway_on_eth = is_ATLAS_900_A3_SUPERPOD(param->mainboard_id);

    ret = dsmi_get_default_gateway_address(param->logic_id, port, gw_addr, default_phy_id, is_gateway_on_eth);
    if (ret == -ENOENT) {
        roce_err("dsmi_get_default_gateway_address fail ret=%d, logic_id[%d]", ret, param->logic_id);
        return UDA_DSMI_GATEWAY_NOT_PRESET_ERR;
    } else if (ret) {
        roce_err("dsmi_get_default_gateway_address fail ret=%d, logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    ret = tool_ipv4_int_to_str(*gw_addr, gw_str, MAX_IP_LEN);
    if (ret) {
        roce_err("ipv4_int_to_str failed! ret[%d] gateway[0x%x]", ret, gw_addr);
        return ret;
    }
    DSMI_PRINT_INFO("default gateway:%s, Iface:eth%d", gw_str, *port);
    return 0;
}

int tool_gateway_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret, port;
    unsigned int gw_addr, default_phy_id;
    char gw_str[MAX_IP_LEN] = "";
    bool is_gateway_on_eth;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    
    is_gateway_on_eth = is_ATLAS_900_A3_SUPERPOD(param->mainboard_id);

    if (is_ipv6_cmd(&argc, &argv)) {
        if (is_atlas_9000_a3(param)) {
            roce_err("Ipv6 atlas_9000_a3 command is not supported.");
            return UDA_TOOL_OP_NOT_SUPPORT_IPV6_ERR;
        }
        ret = tool_gateway_cmd_execute_ipv6(argc, argv, param);
        if (ret != 0) {
            roce_err("tool_gateway_cmd_execute_ipv6 fail! ret[%d]", ret);
            return ret;
        }
        return 0;
    }
    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        if (argc != ARGC_ID_3) {
            roce_err("err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        ret = tool_inner_gateway_set_execute(argc, argv, param, is_gateway_on_eth);
        if (ret) {
            roce_err("tool_inner_gateway_set_execute fail! ret[%d] argc[%d]", ret, argc);
            return ret;
        }
    } else if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        if (argc != ARGC_ID_1) {
            roce_err("err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        ret = tool_gateway_is_get_cmd_execute(param, &port, &gw_addr, gw_str, &default_phy_id);
        if (ret) {
            roce_err("tool_inner_gateway_get_execute fail! ret[%d] argc[%d]", ret, argc);
            return ret;
        }
    } else {
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    return 0;
}

static int param_parse_int(int argc, char **argv, struct arg_parse_t *parse_list)
{
    int i, res, index = 0;
    char *end_str = NULL;

    while (index < argc) {
        for (i = 0; parse_list[i].name != NULL; i++) {
            if (strcmp(argv[index], parse_list[i].name)) {
                continue;
            }
            if (index + 1 >= argc) {
                roce_err("param [%s] has no value", argv[index]); // 参数后面没有跟值
                TOOL_PRINT_INFO("param [%s] has no value", argv[index]);
                return UDA_PARAM_CMD_COUNT_ERR;
            }
            if (parse_list[i].mode == ARG_ALRE) {
                roce_err("re-define param [%s]", parse_list[i].name); // 重复定义参数
                TOOL_PRINT_INFO("re-define param [%s]", parse_list[i].name);
                return UDA_PARAM_OP_NOT_SUPPORT_ERR;
            }
            res = strtol(argv[index + 1], &end_str, 0);
            if (res < parse_list[i].min_value || res > parse_list[i].max_value || *end_str != '\0') {
                // 参数值不在范围内
                roce_err("invalid value, [%s] should be [%d~%d], now is [%s]\n",
                    parse_list[i].name, parse_list[i].min_value, parse_list[i].max_value, argv[index + 1]);
                return UDA_PARAM_INVALID_ERR;
            }
            parse_list[i].mode = ARG_ALRE;
            *(parse_list[i].dst) = res;
            break;
        }
        if (parse_list[i].name == NULL) {
            roce_err("param [%s] is invalid", argv[index]); // 参数不存在
            TOOL_PRINT_INFO("param [%s] is invalid", argv[index]);
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
        index += TWO_VALUE;
    }

    for (i = 0; parse_list[i].name != NULL; i++) {
        if (parse_list[i].mode == ARG_MUST) {
            roce_err("param [%s] not found", parse_list[i].name); // 必选的参数没有输入
            TOOL_PRINT_INFO("param [%s] not found", parse_list[i].name);
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
    }

    return 0;
}

int tool_bandwidth_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    char *end_str = NULL;
    char **end_str_p = &end_str;
    struct bandwidth_t bandwidth_info = {0};

    if (argc < ONE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strcmp(argv[0], "-g")) {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    param->get_cmd_flag = true;

    // 设置默认值
    bandwidth_info.time_interval = DEFAULT_TIME_INTERVAL;

    struct arg_parse_t parse_list[] = {
#ifdef HCCN_TOOL_SHOW_EXT
        {"time", ARG_OPT, &bandwidth_info.time_interval, MIN_TIME_INTERVAL, MAX_TIME_INTERVAL},
#endif
        {0},
    };
    ret = param_parse_int(argc - 1, argv + 1, parse_list);
    if (ret) {
        roce_err("bandwidth cmd parse param failed. (ret=[%d])", ret);
        return ret;
    }

    ret = dsmi_get_bandwidth(param->logic_id, 0, &bandwidth_info);
    if (ret) {
        roce_err("get bandwidth failed. (ret=[%d])", ret);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    TOOL_PRINT_INFO("Bandwidth TX: %5u.%02u MB/sec", bandwidth_info.tx_bandwidth / PERCENTAGE_BASE,
        bandwidth_info.tx_bandwidth % PERCENTAGE_BASE);
    TOOL_PRINT_INFO("Bandwidth RX: %5u.%02u MB/sec", bandwidth_info.rx_bandwidth / PERCENTAGE_BASE,
        bandwidth_info.rx_bandwidth % PERCENTAGE_BASE);
    return 0;

invalid_params:
    roce_err("Invalid param.\n");
    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}

// 区分各种产品形态的通用接口，当前不支持识别910A产品形态
int tool_get_board_type(struct tool_param *param, int *board_type)
{
    int ret;
    struct dsmi_board_info_stru board_info;

    if (is_ATLAS_900_A3_SUPERPOD(param->mainboard_id)) {
        *board_type = (int)SUPERPOD_900_BOARD_TYPE;
        return 0;
    }

    ret = dsmi_get_board_info(param->logic_id, &board_info);
    if (ret) {
        roce_err("get board id failed. (ret=%d)", ret);
        return UDA_DSMI_EXE_ERR;
    }

    // board_id [6:4]bits indicate board type
    unsigned int board_id = (board_info.board_id >> 4) & BOARD_ID_MASK;

    if ((board_id == PCIE_BOARD_ID) || (board_id == PCIE_BOARD_ID_EXTEND)) {
        *board_type = (int)PCIe_BOARD_TYPE;
        return 0;
    }

    if (board_id == A_X_BOARD_ID || board_id == A_X_BOARD_ID_EXTEND) {
        *board_type = (int)A_X_BOARD_TYPE;
        return 0;
    }

    if (board_id == A_K_OR_POD_BOARD_ID || board_id == A_K_BOARD_ID_EXTEND) {
        if (param->mainboard_id == A_K_MAIN_BOARD_ID) {
            *board_type = (int)A_K_BOARD_TYPE;
        } else if (param->mainboard_id == POD_BUSINESS_MAIN_BOARD) {
            *board_type = (int)PoD_BUSINESS_BOARD_TYPE;
        } else {
            *board_type = (int)PoD_BOARD_TYPE;
        }
        return 0;
    }

    *board_type = (int)UNKNOWN_BOARD_TYPE;
    roce_info("Unknown board type. (board_id=%d; main_board_id=%d)", board_info.board_id, param->mainboard_id);
    return 0;
}

int tool_loopback_board_type_check(struct tool_param *param)
{
    int ret = 0, board_type;

    ret = tool_get_board_type(param, &board_type);
    if (ret) {
        roce_err("hccn tool get board type failed. (ret=%d)", ret);
        return UDA_DSMI_EXE_ERR;
    }

    // 配置光模块环回，需要提示网络中断
    if ((board_type == A_X_BOARD_TYPE) || (board_type == SUPERPOD_900_BOARD_TYPE)) {
        ret = tool_double_check("[WARNING] This optical module loopback will influence co-groups.\n"
                                "[WARNING] Running this command may cause errors to other programs "
                                "that are using the network port. Please ensure that all other programs "
                                "are stopped before proceeding with this command.\n"
                                "Are you sure you want to continue?");
    } else if (board_type == A_K_BOARD_TYPE || board_type == PCIe_BOARD_TYPE ||
               board_type == PoD_BUSINESS_BOARD_TYPE) {
        ret = tool_double_check("[WARNING] Running this command may cause errors to other programs "
                                "that are using the network port. Please ensure that all other programs "
                                "are stopped before proceeding with this command.\n"
                                "Are you sure you want to continue?");
    } else {
        return UDA_TOOL_CMD_UNSUPPORT_ON_PRODUCT_ERR;
    }
    
    if (ret) {
        roce_err("hccn tool command aborts by user. (optical loopback)");
    }

    return ret;
}

int tool_set_optical_loopback_error_convert(int ret, int logic_id_convert, int mode)
{
    if (ret == OPTICAL_LOOPBACK_UNSUPPORT) {
        roce_err("Command unsupported on this optical module.");
        return UDA_DSMI_CMD_UPSUPPORT_ON_OPTICAL_ERR;
    } else if (ret == OPTICAL_LOOPBACK_OPT_FAIL_DUE_TO_DOWNGRADE) {
        roce_err("Loopback operate failed due to lane downgrade.");
        return UDA_DSMI_LOOPBACK_FAIL_FOR_DOWNGRADE_ERR;
    } else if (ret == OPTICAL_NOT_INIT) {
        roce_err("The system is in optical module initializing, please try again later.");
        return UDA_DSMI_OPTICAL_NOT_INIT_ERR;
    } else if (ret == OPTICAL_ABSENT) {
        roce_err("Optical module is not present.");
        return UDA_DSMI_XSFP_ABSENT;
    } else if (ret == -EACCES) {
        roce_err("Permission is not allowed.");
        return UDA_TOOL_SYS_NOT_ACCESS;
    } else if (ret != UDA_EXE_SUCCESS) {
        roce_err("dsmi set optical loopback failed! (ret=%d; logic_id=%d; mode=%d)", ret, logic_id_convert, mode);
        return UDA_DSMI_EXE_ERR;
    }

    return ret;
}

int tool_set_optical_loopback(int argc, char **argv, struct tool_param *param)
{
    int ret, mode = -1, logic_id_convert;

    struct arg_parse_t parse_list[] = {
        {"-t", ARG_MUST, &mode, OPTICAL_LOOPBACK_MODE_MIN, OPTICAL_LOOPBACK_MODE_MAX},
        {0},
    };
    ret = param_parse_int(argc, argv, parse_list);
    if (ret) {
        roce_err("hccn tool optical loopback cmd parse param failed. (ret=%d)", ret);
        return ret;
    }

    // 只有标卡，PODC, A+K，A+X和天成支持该功能，且A+X和天成有风险提示
    ret = tool_loopback_board_type_check(param);
    if (ret) {
        return ret;
    }
    
    // 如果是天成，需要得到转换后的logic_id，否则使用原有的logic_id
    if (is_ATLAS_900_A3_SUPERPOD(param->mainboard_id) == true) {
        logic_id_convert = ATLAS_900_A3_SUPERPOD_logic_id_convert(param->phy_id);
        if (logic_id_convert == INVALID_LOGIC_ID) {
            return UDA_DSMI_CONTROL_LINK_UNREACHABLE_ERR;
        }
    } else {
        logic_id_convert = param->logic_id;
    }

    for (int i = 0; i < OPTICAL_LOOPBACK_RETRY; i++) {
        ret = dsmi_set_optical_loopback(logic_id_convert, 0, mode, i ? 0 : 1); // 用i区分设置还是查询
        if (ret != OPTICAL_LOOPBACK_RUNNING) {
            break;
        } else {
            TOOL_PRINT_INFO("Running...");
            sleep(1);
        }
    }

    return tool_set_optical_loopback_error_convert(ret, logic_id_convert, mode);
}

int tool_cfg_ip_udhcpc_recovery(struct tool_param *param)
{
    int ret;
    char udhcpc_enable[UDHCPC_QUIT_INBUFF_LEN] = {0};
    char udhcpc_ipv6[UDHCPC_QUIT_INBUFF_LEN] = {0};
    char udhcpc_quit[UDHCPC_QUIT_INBUFF_LEN] = {0};
    char info[UDHCPC_OUTBUFF_LEN] = {0};
    struct udhcpc_param dhcp_param = {DEFAULT_UDHCPC_TIMEOUT, 1, true, 0};
 
    ret = cfg_read_conf(param->phy_id, "udhcpc_enable", udhcpc_enable, sizeof(udhcpc_enable));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The udhcpc conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }
 
    ret = dsmi_acquire_dhcp_ip(param->logic_id, 0, &dhcp_param, info, UDHCPC_OUTBUFF_LEN);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("dsmi_acquire_dhcp_ip error[%d], phy_id[%d], status[%s]",
                 ret, param->phy_id, "on");
    }
 
    roce_info("udhcpc info need recover cfg. (phy_id=%d)", param->phy_id);
    LOG_SET_CONFIG("start to set udhcpc ip of phy_id [%d]", param->phy_id);
 
    return dsmi_analysis_dsmi_ret_to_uda(ret);
}
 
int tool_cfg_ip_ipv6_udhcpc_recovery(struct tool_param *param)
{
    int ret;
    char udhcpc_enable[UDHCPC_QUIT_INBUFF_LEN] = {0};
    char udhcpc_ipv6[UDHCPC_QUIT_INBUFF_LEN] = {0};
    char udhcpc_quit[UDHCPC_QUIT_INBUFF_LEN] = {0};
    char info[UDHCPC_OUTBUFF_LEN] = {0};
    struct udhcpc_param dhcp_param = {DEFAULT_UDHCPC_TIMEOUT, 1, true, 0};
 
    ret = cfg_read_conf(param->phy_id, "udhcpc_ipv6_enable", udhcpc_enable, sizeof(udhcpc_enable));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The [Ipv6]udhcpc conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }
    dhcp_param.is_ipv6 = IPV6_PROTOCOL;
 
    ret = dsmi_acquire_dhcp_ip(param->logic_id, 0, &dhcp_param, info, UDHCPC_OUTBUFF_LEN);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("dsmi_acquire_dhcp_ip error[%d], phy_id[%d], status[%s]",
                 ret, param->phy_id, "on");
    }
 
    roce_info("udhcpc info need recover cfg. (phy_id=%d)", param->phy_id);
    LOG_SET_CONFIG("start to set ipv6 udhcpc ip of phy_id [%d]", param->phy_id);

    return dsmi_analysis_dsmi_ret_to_uda(ret);
}
 
int tool_get_ipaddr_from_device(struct tool_param *param, char *ip_addr, char *netmask_addr, int ipv4_len)
{
    int ret;
    int port_type = DSMI_ROCE_PORT;
    int port_id = 0;
    ip_addr_t ip_address;
    ip_addr_t mask_address;
    const char *pstr = NULL;
 
    ip_address.ip_type = IPADDR_TYPE_V4;
    mask_address.ip_type = IPADDR_TYPE_V4;
    ret = dsmi_get_device_ip_address(param->logic_id, port_type, port_id, &ip_address, &mask_address);
    if (ret) {
        roce_err("Dsmi_get_device_ip_address fail ret=%d, logic_id[%d]", ret, param->logic_id);
        ret = (ret == DRV_ERROR_NO_DEVICE) ? UDA_TOOL_GATEWAY_NO_IP_CONF_ERR : UDA_DSMI_EXE_ERR;
        return ret;
    }
 
    pstr = inet_ntop(AF_INET, (void *)&ip_address, ip_addr, ipv4_len);
    if (pstr == NULL) {
        roce_err("Ip_address transfer error");
        return UDA_TOOL_NO_MEM_ERR;
    }
 
    pstr = inet_ntop(AF_INET, (void *)&mask_address, netmask_addr, ipv4_len);
    if (pstr == NULL) {
        roce_err("Netmask transfer error");
        return UDA_TOOL_NO_MEM_ERR;
    }
 
    return UDA_EXE_SUCCESS;
}

int tool_cfg_ip_recovery_bond(struct tool_param *param)
{
    int ret;
    char address[MAX_IP_LEN] = "";
    char netmask[MAX_IP_LEN] = "";
 
    ret = cfg_read_conf(param->phy_id, "bond_address", address, sizeof(address));
    if (ret != 0) {
        roce_info("ip bond address do not need recover. (cfg=%d, phy_id=%d)", ret, param->phy_id);
        return 0;
    }
 
    ret = cfg_read_conf(param->phy_id, "bond_netmask", netmask, sizeof(netmask));
    if (ret != 0) {
        roce_info("bond_netmask do not need recover. (cfg=%d, phy_id=%d)", ret, param->phy_id);
        return 0;
    } else {
        roce_info("ip bond_address need recover cfg");
        param->option_mode = UDA_OPT_BOND_CMD;
        ret = tool_ip_set_address(param, address, netmask);
        if (ret != 0) {
            roce_err("ip set address fail! (cfg=%d, logic_id=%d)", ret, param->logic_id);
            return ret;
        }
    }
 
    return 0;
}

int tool_get_device_ipaddr(struct tool_param *param)
{
    int ret = 0;
    unsigned int port_index;
    int port_id = 0;
    unsigned int port_count = 1;
    const char *pstr = NULL;
    int port_type = DSMI_ROCE_PORT;
    struct tool_ip_value ip_values[MAX_PORT_COUNT];
    struct tool_ip_character ip_characters[MAX_PORT_COUNT];
 
    if (param->option_mode == UDA_OPT_BOND_CMD) {
        port_type = DSMI_BOND_PORT;
    } else if (param->option_mode == UDA_OPT_EMPTY_CMD) {
        port_type = DSMI_ROCE_PORT;
        ret = dsmi_get_link_cnt(param->logic_id, port_id, &port_count);
        if (ret != 0) {
            roce_err("dsmi_get_link_cnt fail. (ret=%d, logic_id=%d, port_id=%d)", ret, param->logic_id, port_id);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
    }
    for (port_index = 0; port_index < port_count && port_index < MAX_PORT_COUNT; port_index++) {
        ip_values[port_index].address->ip_type = IPADDR_TYPE_V4;
        ip_values[port_index].netmask->ip_type = IPADDR_TYPE_V4;
        ret = dsmi_get_device_ip_address(param->logic_id, port_type, port_id,
                                         ip_values[port_index].address, ip_values[port_index].netmask);
        if (ret != 0) {
            roce_err("dsmi_get_device_ip_address fail. (ret=%d, logic_id=%d)", ret, param->logic_id);
            ret = (ret == DRV_ERROR_NO_DEVICE) ? UDA_DSMI_IPCONF_NOT_PRESET_ERR : UDA_DSMI_EXE_ERR;
            continue;
        }

        pstr = inet_ntop(AF_INET, (void *)ip_values[port_index].address, ip_characters[port_index].address,
                         sizeof(ip_characters[port_index].address));
        if (pstr == NULL) {
            roce_err("ip transfer error. (ip=0x%x)",
                ((struct in_addr *)ip_values[port_index].address)->s_addr);
            return UDA_TOOL_NO_MEM_ERR;
        }
 
        pstr = inet_ntop(AF_INET, (void *)ip_values[port_index].netmask, ip_characters[port_index].netmask,
                         sizeof(ip_characters[port_index].netmask));
        if (pstr == NULL) {
            roce_err("netmask transfer error. (netmask=0x%x)",
                ((struct in_addr *)ip_values[port_index].netmask)->s_addr);
            return UDA_TOOL_NO_MEM_ERR;
        }
 
        DSMI_PRINT_INFO("ipaddr:%s",  ip_characters[port_index].address);
        DSMI_PRINT_INFO("netmask:%s", ip_characters[port_index].netmask);
    }
    return ret;
}

int tool_check_mtu(const char *mtu_str, unsigned int *mtu_size, unsigned int mac_type)
{
    int ret, max_mtu;
    char *tmp_ptr = NULL;

    if (mtu_str == NULL || mtu_size == NULL) {
        roce_err("The mtu_str is NULL[%d] or mtu_size is NULL[%d]. (1 for true)",
                 (mtu_str == NULL), (mtu_size == NULL));
        return UDA_PARAM_INVALID_ERR;
    }

    *mtu_size = (unsigned int)strtoul(mtu_str, &tmp_ptr, NUMBER_BASE);
    if (*tmp_ptr != '\0') {
        roce_err("Dsmi check mtu fail. (mtu=%s)", mtu_str);
        return UDA_PARAM_INVALID_ERR;
    }

    max_mtu = (mac_type == MAC_TYPE_ETH) ? TOOL_ETH_MAX_MTU_SIZE : TOOL_ROH_MAX_MTU_SIZE;
    ret = tool_para_overflow_check(mtu_str, max_mtu, UDA_PARAM_MTU_OUT_OF_RANGE_ERR);
    if (ret) {
        roce_err("[tool_check_mtu] mtu_str is overflow. (mtu_str=%s)", mtu_str);
        return ret;
    }

    if (*mtu_size < TOOL_MIN_MTU_SIZE || *mtu_size > max_mtu) {
        roce_err("Invalid mtu size-- '%s', expect[%d]-[%u]", mtu_str, TOOL_MIN_MTU_SIZE, max_mtu);
        return UDA_PARAM_MTU_OUT_OF_RANGE_ERR;
    }

    if (mac_type == MAC_TYPE_ETH && *mtu_size < TOOL_MIN_MTU_SIZE_IPV6) {
        ret = tool_double_check("[WARNING] The minimum limit of mtu in IPv6 protocol is 1280 bytes. "
            "If the mtu is configured to be less than 1280, "
            "it will result in the loss of IPv6 addresses and the inability to use the IPv6 protocol.\n"
            "Are you sure you want to continue?");
        if (ret) {
            LOG_CONFIG("User aborts to config mtu[%u]", *mtu_size);
            return ret;
        }
    }

    return 0;
}

// 以下为910的桩点函数，在910B及以后版本由ext内的函数做重载
STUB_WEAK int tool_update_roce_port_ippair(int logic_id, int argc, char **argv,
    enum tool_ippair_op_type op)
{
    if (op == IPPAIR_SET) {
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}

STUB_WEAK int tool_clear_roce_port_ippair(int logic_id, int argc)
{
    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}

STUB_WEAK int tool_get_single_ippair(int logic_id, int argc, char **argv)
{
    roce_err("Err arg count.(argc=%d)", argc);
    return UDA_PARAM_CMD_COUNT_ERR;
}

STUB_WEAK int tool_get_all_ippair(int logic_id)
{
    return UDA_SUCCESS;
}

bool check_udhcpc_write_hccn_conf(struct tool_param *param, int is_ipv6)
{
    int ret;
    char udhcpc_flag[UDHCPC_QUIT_INBUFF_LEN] = {0};
 
    if (is_ipv6 == 0) {
        ret = cfg_read_conf(param->phy_id, "udhcpc_enable", udhcpc_flag, sizeof(udhcpc_flag));
        if (ret == 0) {
            roce_info("[Ipv4]hccn.conf have udhcpc_enable flag. ");
            return true;
        }
    } else {
        ret = cfg_read_conf(param->phy_id, "udhcpc_ipv6_enable", udhcpc_flag, sizeof(udhcpc_flag));
        if (ret == 0) {
            roce_info("[Ipv6]hccn.conf have udhcpc_ipv6_enable flag. ");
            return true;
        }
    }
 
    return false;
}

STATIC int tool_get_local_lldp_info(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc != 0) {
        roce_err("Err argc. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_lldp_get_local_info(param->logic_id);
    if (ret) {
        roce_err("dsmi get local lldp info fail! (ret=%d; logic_id=%d)", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    return 0;
}

STATIC int tool_set_lldp_portId(int argc, char **argv, struct tool_param *param)
{
    int logic_id;
    int ret;
    char inbuf[LLDP_TYPE_INBUFF_LEN] = {0};
 
    if (argc != ARGC_ID_2) {
        roce_err("Err argc. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    logic_id = param->logic_id;
 
    ret = sprintf_s(inbuf, LLDP_TYPE_INBUFF_LEN, "%s", argv[1]);
    if (ret <= 0) {
        roce_err("lldp type cmd sprintf failed!");
        return UDA_TOOL_NO_MEM_ERR;
    }
 
    if (strncmp(argv[0], "subtype", strlen("subtype") + 1)) {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
 
    if (!strncmp(argv[1], "mac", strlen("mac") + 1)) {
        ret = dsmi_set_lldp_port_id(logic_id, LLDP_SET_MAC);
        if (ret) {
            roce_err("dsmi set lldp mac address fail! (ret=%d; logic_id=%d)", ret, logic_id);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
        ret = cfg_write_conf(param->phy_id, "lldp_portid_type", inbuf);
        if (ret) {
            roce_err("write cfg error. (error code=%d; phy_id=%d)", ret, param->phy_id);
            return UDA_TOOL_SYS_WRITE_FILE_ERR;
        }
    } else if (!strncmp(argv[1], "ifname", strlen("ifname") + 1)) {
        ret = dsmi_set_lldp_port_id(logic_id, LLDP_SET_INTF);
        if (ret) {
            roce_err("dsmi set interface name fail! (ret=%d; logic_id=%d)", ret, logic_id);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
        ret = cfg_write_conf(param->phy_id, "lldp_portid_type", inbuf);
        if (ret) {
            roce_err("write cfg error. (error code=%d; phy_id=%d)", ret, param->phy_id);
            return UDA_TOOL_SYS_WRITE_FILE_ERR;
        }
    } else {
        roce_err("Invalid operation.)");
        return UDA_PARAM_INVALID_ERR;
    }
 
    return 0;
}
 
int tool_local_lldp_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
 
    if (argc == 0) {
        roce_err("err argc. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_local_lldp_info(argc - 1, argv + 1, param);
        if (ret) {
            roce_err("get local lldp info failed. (logic_id=%d)", param->logic_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_lldp_portId(argc - 1, argv + 1, param);
        if (ret) {
            roce_err("set local lldp tlv cfg port id failed. (logic_id=%d)", param->logic_id);
            return ret;
        }
    } else {
        roce_err("Invalid option.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
 
    return 0;
}
 
int tool_cfg_lldp_portid_recovery(struct tool_param *param)
{
    char port_type[LLDP_TYPE_INBUFF_LEN] = "";
    char *tmp_ptr = NULL;
    int ret;
    char *argv[2];
 
    ret = cfg_read_conf(param->phy_id, "lldp_portid_type", port_type, sizeof(port_type));
    if (ret) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
            roce_info("lldp port_type do not need recover cfg. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return 0;
        } else if (ret == UDA_TOOL_NO_MEM_ERR) { // 当配置文件中找到了这个配置，但是非法参数时，返回失败
            roce_err("Failed to read invalid conf value configuration file. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        } else {
            roce_err("Cfg_read_conf lldp port_type failed! (ret=%d)", ret);
            return UDA_PARAM_INVALID_ERR;
        }
    }
    argv[0] = "subtype";
    argv[1] = port_type;
    ret = tool_set_lldp_portId(ARGC_ID_2, argv, param);
    if (ret) {
        roce_err("set local lldp tlv cfg port id failed. (logic_id=%d)", param->logic_id);
        return ret;
    }
    return 0;
}

static int run_recovery_cmd(int (*recovery_cmd)(struct tool_param *), struct tool_param *param)
{
    int ret;
    int retry_times = 0;
    ret = recovery_cmd(param);
    while (ret != 0 && retry_times < RECOVER_RETRY_TIMES) {
        retry_times++;
        sleep(1);
        ret = recovery_cmd(param);
    }
    return ret;
}

static int recovery_check_param_data(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (param == NULL) {
        roce_err("tool_cfg_cmd_recovery param is null");
        return UDA_TOOL_SYS_FOPEN_ERR;
    }

    ret = resolve_abnormal_param(argc, argv);
    if (ret) {
        roce_err("resolve_abnormal_param fail[%d] phy_id[%d]", ret, param->phy_id);
        return ret;
    }
    (void)tool_cfg_status_set(param, TOOL_NET_CFG_START);
    return 0;
}

STATIC int recovery_cfg_comm_func(struct tool_param *param, recovery_cmd_t *cmd_list, int len,
    char *cmd_list_desc, bool rely_to_first)
{
    int op_index, error_flag = 0, ret;
    for (op_index = 0; op_index < len; op_index++) {
        ret = run_recovery_cmd(cmd_list[op_index].recovery_cmd_execute, param);
        if (ret != 0) {
            roce_err("The recovery of the %s configuration file has failed. (ret=%d; phy_id=%d; op_index=%d)",
                     cmd_list_desc, ret, param->phy_id, op_index);
            LOG_CONFIG("Failed to restore the %s configuration. (phy_id=%d)",
                cmd_list[op_index].recovery_cmd_value, param->phy_id);
            error_flag += 1;

            // 当首个配置恢复失败时，依赖他的其他配置也都失败，不再继续执行
            if (rely_to_first == true && op_index == 0) {
                break;
            }
        }
    }
    return error_flag;
}

STATIC int recovery_ipv4_cfg_cmd(struct tool_param *param)
{
    int ret, op_ipv4_index_len;

    recovery_cmd_t *ipv4_cmd_list = get_recovery_ipv4_cmd_list(&op_ipv4_index_len);
    ret = recovery_cfg_comm_func(param, ipv4_cmd_list, op_ipv4_index_len, "IPV4", true);
    if (ret != 0) {
        roce_err("The recovery of the ipv4 configuration file has failed.");
        return ret;
    }
    return 0;
}

STATIC int recovery_ipv6_cfg_cmd(struct tool_param *param)
{
    int ret, op_ipv6_index_len;

    recovery_cmd_t *ipv6_cmd_list = get_recovery_ipv6_cmd_list(&op_ipv6_index_len);
    ret = recovery_cfg_comm_func(param, ipv6_cmd_list, op_ipv6_index_len, "IPV6", true);
    if (ret != 0) {
        roce_err("The recovery of the ipv6 configuration file has failed.");
        return ret;
    }
    return 0;
}

STATIC int recovery_com_cfg_cmd(struct tool_param *param)
{
    int ret, error_flag = 0, op_index_len, op_index;

    recovery_cmd_t *com_cmd_list = get_recovery_com_cmd_list(&op_index_len);
    error_flag += recovery_cfg_comm_func(param, com_cmd_list, op_index_len, "common", false);

    return error_flag;
}

STATIC int get_cooperative_cmd_param(int *co_need_recovery_flag, struct tool_param *param, struct tool_param *co_param)
{
    int ret = 0;
    if (is_ATLAS_900_A3_SUPERPOD(param->mainboard_id) == false ||
        atlas_900_a3_superpod_phy_id_convert(param->phy_id) != param->phy_id) {
        *co_need_recovery_flag = 0;
        return 0;
    }

    // 在A3 POD中,如果是master,需要恢复一下从die的配置。这里更新从die的phy_id和logic_id
    *co_param = *param;
    co_param->phy_id = atlas_900_a3_superpod_get_cooperative_phy_id(param->phy_id);
    ret = dsmi_get_logicid_from_phyid((unsigned int)co_param->phy_id, (unsigned int *)(void *)&co_param->logic_id);
    if (ret) {
        roce_err("Get logic id fail when get cooperative cmd param. (ret=%d; phy_id=%d)", ret, co_param->phy_id);
        return ret;
    }
    if (co_param->logic_id >= TOOL_HOST_LOGIC_ID_MAX || co_param->logic_id < 0) {
        roce_err("Invalid logic id when get cooperative cmd param. (ret=%d; phy_id=%d; logic_id=%d)",
            ret, co_param->phy_id, co_param->logic_id);
        ret = UDA_MAJOR_CMD_DEV_ID_ERR;
        return ret;
    }
    ret = tool_check_dev_health(co_param->logic_id);
    if (ret) {
        roce_err("Check dev health fail when get cooperative cmd param. (ret=%d; phy_id=%d; logic_id=%d)",
            ret, co_param->phy_id, co_param->logic_id);
        return ret;
    }
    if (ret == 0) {
        *co_need_recovery_flag = 1;
    }
    return ret;
}

STATIC int recovery_cooperative_cfg_cmd(struct tool_param *param)
{
    int ret, error_flag = 0, op_index_len, op_index, co_need_recovery_flag = 0;
    struct tool_param co_param = {0};

    recovery_cmd_t *co_cmd_list = get_recovery_cooperative_cmd_list(&op_index_len);
    error_flag += recovery_cfg_comm_func(param, co_cmd_list, op_index_len, "cooperative", false);

    ret = get_cooperative_cmd_param(&co_need_recovery_flag, param, &co_param);
    if (ret != 0) {
        LOG_CONFIG("Get cooperative cmd param failed, and cooperative configuration not recovered. (ret=%d)", ret);
        return error_flag;
    }

    if (co_need_recovery_flag) {
        error_flag += recovery_cfg_comm_func(&co_param, co_cmd_list, op_index_len, "cooperative", false);
    }
    return error_flag;
}

int recovery_process_cfg_cmd(struct tool_param *param)
{
    int error_flag = 0, ret;
    g_recovering = 1;
    LOG_CONFIG("start to recover config of phy_id[%d]", param->phy_id);

    #ifdef CFG_SOC_PLATFORM_CLOUD_V2
    // 恢复host info时并检验权限
    ret = tool_cfg_host_info_recovery(param);
    if (ret) {
        error_flag++;
        roce_err("tool_cfg_host_info_recovery fail. (ret=%d; phy_id=%d)", ret, param->phy_id);
        if (ret == UDA_TOOL_SYS_NOT_ACCESS) {
            return ret;
        }
    }
    #else
    // 910A检查非root
    ret = hccn_check_usr_identify();
    if (ret) {
        roce_err("Check usr identify failed. (ret=%d; phy_id=%d)", ret, param->phy_id);
        return ret == -EACCES ? UDA_TOOL_SYS_NOT_ACCESS : ret;
    }
    #endif

    error_flag += recovery_com_cfg_cmd(param);
    error_flag += recovery_cooperative_cfg_cmd(param); // 恢复从die需下发到主die上的特殊配置
    error_flag += recovery_ipv4_cfg_cmd(param);
    error_flag += recovery_ipv6_cfg_cmd(param);
    if (error_flag > 0) {
        LOG_CONFIG("start to recover fail");
        (void)tool_cfg_status_set(param, TOOL_NET_CFG_FAIL);
        return CFG_RECOVERY_FAIL;
    } else {
        (void)tool_cfg_status_set(param, TOOL_NET_CFG_SUCCESS);
        return CFG_RECOVERY_SUCCESS;
    }
}

int tool_cfg_cmd_recovery(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc != 1) {
        roce_err("err argc. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = recovery_check_param_data(argc, argv, param);
    if (ret != 0) {
        roce_err("recovery_check_param_data param is null");
        return ret;
    }

    return recovery_process_cfg_cmd(param);
}

int tool_version_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    char firmware_ver[FIRMWARE_VERSION_INFO_LENGTH] = {0};

    if (argc != ONE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = dsmi_get_firmware_version(param->logic_id, 0, firmware_ver, FIRMWARE_VERSION_INFO_LENGTH);
        if (ret) {
            roce_err("dsmi_get_firmware_version failed, logic_id=%d", param->logic_id);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    firmware_ver[FIRMWARE_VERSION_INFO_LENGTH - 1] = '\0';
    TOOL_PRINT_INFO("Network Driver Version:    %s", DRIVER_VERSION_INFO);
    TOOL_PRINT_INFO("Network Firmware Version:  %s", firmware_ver);

    return ret;
}

int is_copper_cable(int logic_id)
{
    int ret = 0;
    struct ds_optical_info info = {0};

    ret = dsmi_get_optical_info(logic_id, 0, &info);
    if (ret) {
        roce_err("dsmi get optical info fail! ret[%d] logic_id[%d]", ret, logic_id);
        return UDA_DSMI_EXE_ERR;
    }

    if (info.additional_info.optical_type == PIF_ATTR_COPPER) {
        return IS_COPPER;
    }
    return ret;
}

int tool_set_sflag(struct tool_param *param, int *sflag, int *logic_id_after_convert)
{
    bool is_ATLAS_900_A3_SUPERPOD_flag = false;
    int board_type, ret;

    ret = tool_get_board_type(param, &board_type);
    if (ret) {
        roce_err("hccn tool get board type failed. (ret=%d)", ret);
        return UDA_DSMI_EXE_ERR;
    }

    if (board_type == A_X_BOARD_TYPE) {
        // display the front 4 lane for 0,2,4,8... npu, or display the rear 4 lane for 1,3,5,7... npu
        if ((param->phy_id % TOOL_INDEX_TWO) == 1) {
            *sflag = LANE_OFFSET;
        }
        return 0;
    }

    if (is_ATLAS_900_A3_SUPERPOD(param->mainboard_id) == true) {
        is_ATLAS_900_A3_SUPERPOD_flag = true;
        *logic_id_after_convert = ATLAS_900_A3_SUPERPOD_logic_id_convert(param->phy_id);
        if (*logic_id_after_convert == INVALID_LOGIC_ID) {
            return UDA_DSMI_CONTROL_LINK_UNREACHABLE_ERR;
        }
    }

    if (is_ATLAS_900_A3_SUPERPOD_flag == true) {
        // display the front 4 lane for 0~7 npu or display the rear 4 lane for 8~15 npu
        if ((param->phy_id / MAX_FRONT_NPU_NUM) == 1) {
            *sflag = LANE_OFFSET;
        }
    }

    return 0;
}

int tool_cfg_cmd_recovery_info_get(struct tool_param *param)
{
    int ret = 0;

    ret = tool_check_dev_health(param->logic_id);
    if (ret != 0) {
        roce_err("tool_check_dev_health fail! (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }
    
    ret = dsmi_get_phyid_from_logicid(param->logic_id, (unsigned int *)(void *)&param->phy_id);
    if (ret != 0) {
        roce_err("dsmi_get_phyid_from_logicid fail! (ret=%d; logic_id=%d)", ret, param->logic_id);
        return ret;
    }

    ret = dsmi_get_mainboard_id(param->phy_id, &(param->mainboard_id));
    if (ret != 0) {
        roce_err("dsmi_get_mainboard_id fail! (ret=%d; phy_id=%d)", ret, param->phy_id);
        return ret;
    }
    
    return 0;
}

int tool_cfg_cmd_recovery_all(int argc, char **argv, struct tool_param *param)
{
    int ret, dev_num = 0, dev_list[DEV_LIST_MAX] = {0}, err_count = 0;

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_get_device_count(&dev_num);
    if ((ret != 0) || (dev_num <= 0) || (dev_num > DEV_LIST_MAX)) {
        roce_err("dsmi_get_device_count fail! (ret=%d; dev_num=%d)", ret, dev_num);
        return UDA_DSMI_EXE_ERR;
    }

    ret = dsmi_list_device(dev_list, dev_num);
    if (ret != 0) {
        roce_err("dsmi_list_device fail! (ret=%d; dev_num=%d)", ret, dev_num);
        return UDA_DSMI_EXE_ERR;
    }

    for (int i = 0; i < dev_num; i++) {
        param->logic_id = dev_list[i];

        ret = tool_cfg_cmd_recovery_info_get(param);
        if (ret != 0) {
            err_count++;
            continue;
        }

        ret = tool_cfg_cmd_recovery(argc, argv, param);
        if (ret == UDA_TOOL_ACCESS_CONF_FILE_ERR || ret == UDA_PARAM_CMD_COUNT_ERR || ret == UDA_TOOL_SYS_NOT_ACCESS) {
            return ret;
        }

        if (ret != 0) {
            err_count++;
            roce_err("tool cfg cmd recovery fail! (i=%d; ret=%d; err_count=%d)", i, ret, err_count);
            TOOL_PRINT_ERR("dev:%d recovery fail", param->phy_id);
            continue;
        }

        TOOL_PRINT_INFO("dev:%d recovery success", param->phy_id);
    }

    if (err_count != 0) {
        roce_err("tool cfg cmd recovery all fail! (err_count=%d)", err_count);
        return UDA_DSMI_EXE_ERR;
    }
    
    return 0;
}
 
STATIC int tool_eth_test_str2char(const char *eth_str, char *mode)
{
    int i;
    // mode online and external_lb are unavailable now
    static const char *eth_mode_str[] = {
        "offline",
    };
 
    for (i = 0; i < ETH_SELF_TEST_MODE_TYPE_MAX; i++) {
        if (strncmp(eth_str, eth_mode_str[i], strlen(eth_mode_str[i]) + 1) == 0) {
            *mode = (char)i;
            return 0;
        }
    }
 
    roce_err("check mode para err.");
    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}
 
STATIC int tool_get_eth_test_info(int argc, char **argv, struct tool_param *param)
{
    int ret;
    char mode;
 
    ret = tool_eth_test_str2char(argv[0], &mode);
    if (ret != 0) {
        roce_err("invalid eth_test mode.");
        return ret;
    }
 
    ret = tool_double_check("[WARNING]Running this command may cause errors to other programs "
                            "that are using the network port. Please ensure that all other programs "
                            "are stopped before proceeding with this command.\n"
                            "Are you sure you want to continue?");
    if (ret) {
        return ret;
    }
 
    ret = dsmi_get_eth_test_info(param->logic_id, mode);
    if (ret != 0) {
        roce_err("dsmi get eth_test failed. ret[%d] logic_id[%d]", ret, param->logic_id);
        if (ret == EBUSY) { // get CDR I2C ctrl failed
            return UDA_DSMI_GET_I2C_CTRL_ERR;
        }
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    return ret;
}
 
int tool_eth_test_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    char **argv_tmp = argv + 1;
    int argc_tmp = argc - 1, ret;
 
    if (argc != TWO_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
 
    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_eth_test_info(argc_tmp, argv_tmp, param);
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("get eth_test self-check fail. ret[%d] logic_id[%d]", ret, param->logic_id);
            return ret;
        }
    } else {
        roce_err("eth_test info cmd invalid operation.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
 
    return ret;
}

void tool_show_additional_dr4_optical_snr_info(struct ds_optical_info *info, const int offset,
    bool host_support, bool media_support)
{
    if (host_support) {
        for (int i = 0; i < XSFP_SHOW_SNR_LEN; i++) {
            TOOL_PRINT_INFO("Host SNR Lane%d       : %.4f dB", i, info->additional_info.host_snr[i + offset]);
        }
    } else {
        for (int i = 0; i < XSFP_SHOW_SNR_LEN; i++) {
            TOOL_PRINT_INFO("Host SNR Lane%d       : not supported", i);
        }
    }

    if (media_support) {
        TOOL_PRINT_INFO("Media SNR Lane0      : %.4f dB",
            ((offset == 0) ? (info->additional_info.media_snr[MEDIA_LANE0])
                : info->additional_info.media_snr[MEDIA_LANE2]));
        TOOL_PRINT_INFO("Media SNR Lane1      : %.4f dB",
            ((offset == 0) ? (info->additional_info.media_snr[MEDIA_LANE1])
                : info->additional_info.media_snr[MEDIA_LANE3]));
        TOOL_PRINT_INFO("Media SNR Lane2      : NA");
        TOOL_PRINT_INFO("Media SNR Lane3      : NA");
    } else {
        for (int i = 0; i < XSFP_SHOW_SNR_LEN; i++) {
            TOOL_PRINT_INFO("Media SNR Lane%d      : not supported", i);
        }
    }
}

STATIC int tool_show_dump_optical_page_info(struct ds_optical_register_info *info)
{
    int ret = 0, byte_no = (info->index == 0) ? 0 : DUMP_PAGE_LEN;
    unsigned int value_index = 0;
    unsigned char value[DUMP_PAGE_LEN];
    TOOL_PRINT_INFO("Dump Optical Register: Page %02xh", info->index);
    for (unsigned int i = 0; i < info->len; i += SHOW_ONE_ROW) {
        if (info->index == 0 && i == 0) {
            TOOL_PRINT_INFO("Page 00h Low Memory : 0 - 127");
        } else if (info->index == 0 && i == DUMP_PAGE_LEN) {
            TOOL_PRINT_INFO("Page 00h High Memory : 128 - 255");
        } else if (info->index != 0 && i == 0) {
            TOOL_PRINT_INFO("Page %02xh : 128 - 255", info->index);
        }
        ret = sprintf_s(value, DUMP_PAGE_LEN, "[%03d]:", byte_no);
        if (ret < 0) {
            roce_err("sprintf_s cmd fail. ret[%d]", ret);
            return ret;
        }
        for (int col = 0; col < SHOW_ONE_ROW; col++) {
            ret = sprintf_s(value + strlen(value), TOOL_DUMP_REG_MARGIN + strlen(value), " %02x", \
                info->page_info[value_index]);
            if (ret < 0) {
                roce_err("sprintf_s cmd fail. ret[%d]", ret);
                return ret;
            }
            value_index += 1;
        }
        TOOL_PRINT_INFO("%s", value);
        byte_no += SHOW_ONE_ROW;
    }
    return 0;
}

int tool_dump_optical_info_ret_convert(int result)
{
    if (result) {
        if (result == DUMP_CMD_IIC_BUSY) { // i2c控制权获取失败
            return UDA_DSMI_GET_I2C_CTRL_ERR;
        } else if (result == DUMP_CMD_NOTSUPP) {
            return UDA_TOOL_CMD_UNSUPPORT_ON_PRODUCT_ERR;
        } else if (result == OPTICAL_NOTSUPP) {
            return UDA_DSMI_CMD_UPSUPPORT_ON_OPTICAL_ERR;
        } else if (result == PAGE_INDEX_NOTSUPP) {
            return UDA_DSMI_PAGE_INDEX_NOTSUPP;
        } else if (result == OPTICAL_NOT_INIT) {
            return UDA_DSMI_OPTICAL_NOT_INIT_ERR;
        } else if (result == OPTICAL_ABSENT) {
            return UDA_DSMI_XSFP_ABSENT;
        } else if (result == EPERM) {
            return UDA_DSMI_DIAG_UNENABLED;
        } else if (result == -EACCES) {
            return UDA_TOOL_SYS_NOT_ACCESS;
        }
        return UDA_DSMI_EXE_ERR;
    } else {
        return UDA_EXE_SUCCESS;
    }
}

static int execute_dump_page_cmd(int argc, char **argv, struct tool_param *param)
{
    int ret, logic_id;
    char *p_end_str = NULL;
    struct ds_optical_register_info info = {0};

    if (argc != 1) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    info.mode = DUMP_PAGE_INFO_CMD;
    info.index = (unsigned int)strtol(argv[0], &p_end_str, NUMBER_HEX);
    if ((*p_end_str != '\0') || (info.index < 0) || (info.index > 0xFF)) {
        return UDA_PARAM_INVALID_ERR;
    }
    info.len = (info.index == 0) ? PAGE_MAX_LEN : DUMP_PAGE_LEN;

    ret = tool_get_convert_logic_id_and_master_flag(param, &logic_id, &info.master_flag);
    if (ret != 0) {
        return ret;
    }

    ret = dsmi_dump_optical_info_cmd(logic_id, 0, &info);
    if (ret) {
        roce_err("Dsmi dump optical info fail. (ret=%d; logic_id=%d; mode=%u; master_flag=%u)",
            ret, logic_id, info.mode, info.master_flag);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    if (info.result) {
        roce_err("Tool dump optical info fail. (result=%u; logic_id=%d; mode=%u; master_flag=%u)",
            info.result, logic_id, info.mode, info.master_flag);
        return tool_dump_optical_info_ret_convert(info.result);
    }

    ret = tool_show_dump_optical_page_info(&info);
    if (ret) {
        roce_err("Show dump optical reg info failed. (ret=%d)", ret);
        return ret;
    }
    return 0;
}

static execute_dump_slog_cmd(int argc, char **argv, struct tool_param *param)
{
    int ret, logic_id;
    struct ds_optical_register_info info = {0};
    info.mode = DUMP_ALL_SLOG_CMD;
    if (argc != 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = tool_get_convert_logic_id_and_master_flag(param, &logic_id, &info.master_flag);
    if (ret != 0) {
        return ret;
    }

    ret = dsmi_dump_optical_info_cmd(logic_id, 0, &info);
    if (ret) {
        roce_err("Dsmi dump optical info fail. (ret=%d; logic_id=%d; mode=%u; master_flag=%u)",
            ret, logic_id, info.mode, info.master_flag);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    if (info.result) {
        roce_err("Tool dump optical info fail. (result=%u; logic_id=%d; mode=%u; master_flag=%u)",
            info.result, logic_id, info.mode, info.master_flag);
        return tool_dump_optical_info_ret_convert(info.result);
    }

    return ret;
}

int tool_dump_optical_info(int argc, char **argv, struct tool_param *param)
{
    int ret, master_flag;

    if (argc == 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    if (strncmp(argv[0], "all", strlen("all") + 1) == 0) {
        ret = execute_dump_slog_cmd(argc - 1, argv + 1, param);
    } else if (strncmp(argv[0], "page", strlen("page") + 1) == 0) {
        param->get_cmd_flag = true;
        ret = execute_dump_page_cmd(argc - 1, argv + 1, param);
    } else {
        roce_err("dump optical info cmd param for %d_para err.", argc);
        return UDA_PARAM_INVALID_ERR;
    }
    return ret;
}

// 在光模块操作前，要求用户二次确认的接口
int double_check_before_optical_operation(struct tool_param *param, int mode)
{
    int ret, board_type;
 
    ret = tool_get_board_type(param, &board_type);
    if (ret) {
        roce_err("hccn tool get board type failed. (ret=%d)", ret);
        return UDA_DSMI_EXE_ERR;
    }
    
    // A+X 天成存在两个device共用一个光模块情况，需要提示对同组的影响
    if (board_type == A_X_BOARD_TYPE || board_type == SUPERPOD_900_BOARD_TYPE) {
        // 软/硬复位、关光、切低功耗，需要提示网络中断
        if (mode == CMD_HARD_RESET || mode == CMD_SOFT_RESET || mode == CMD_DISABLE_TX || mode == CMD_LOW_POWER) {
            ret = tool_double_check("[WARNING]This optical module set mode will influence co-groups.\n"
                                    "[WARNING]Running this command may cause errors to other programs "
                                    "that are using the network port. Please ensure that all other programs "
                                    "are stopped before proceeding with this command.\n"
                                    "Are you sure you want to continue?");
        } else {
            ret = tool_double_check("[WARNING]This optical module set mode will influence co-groups.\n"
                                    "Are you sure you want to continue?");
        }
    } else {
        // 软/硬复位、关光、切低功耗，需要提示网络中断
        if (mode == CMD_HARD_RESET || mode == CMD_SOFT_RESET || mode == CMD_DISABLE_TX || mode == CMD_LOW_POWER) {
            ret = tool_double_check("[WARNING]Running this command may cause errors to other programs "
                                    "that are using the network port. Please ensure that all other programs "
                                    "are stopped before proceeding with this command.\n"
                                    "Are you sure you want to continue?");
        }
    }

    if (ret) {
        roce_err("hccn tool command aborts by user. (set optical mode)");
        return ret;
    }
 
    return 0;
}
 
static int tool_set_optical_mode_parse(int argc, char **argv, struct ds_optical_mode_info *data)
{
    // 命令格式检查
    if (argc == ARGC_NUM_1) {
        if (!strncmp(argv[0], "hard_reset", strlen("hard_reset") + 1)) {
            data->mode = CMD_HARD_RESET;
        } else if (!strncmp(argv[0], "soft_reset", strlen("soft_reset") + 1)) {
            data->mode = CMD_SOFT_RESET;
        } else if (!strncmp(argv[0], "low_power", strlen("low_power") + 1)) {
            data->mode = CMD_LOW_POWER;
        } else if (!strncmp(argv[0], "high_power", strlen("high_power") + 1)) {
            data->mode = CMD_HIGH_POWER;
        } else {
            roce_err("Invalid operation.");
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
    } else if (argc == ARGC_NUM_2) {
        if (!strncmp(argv[0], "tx_disable", strlen("tx_disable") + 1) &&
            !strncmp(argv[1], "all", strlen("all") + 1)) {
            data->mode = CMD_DISABLE_TX;
        } else if (!strncmp(argv[0], "tx_enable", strlen("tx_enable") + 1) &&
                   !strncmp(argv[1], "all", strlen("all") + 1)) {
            data->mode = CMD_ENABLE_TX;
        } else {
            roce_err("Invalid operation.");
            return UDA_PARAM_OP_NOT_SUPPORT_ERR;
        }
    } else {
        roce_err("Err argc. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    return 0;
}
 
static int tool_set_optical_mode_error_convert(int ret, int logic_id, int mode)
{
    if (ret == 0) {
        return 0;
    }

    roce_err("dsmi set optical mode fail. (ret=%d; logic_id=%d; mode=%d)", ret, logic_id, mode);
 
    if (ret == OPTICAL_SET_MODE_UNSUPPORT) { // 不支持的光模块类型（铜缆）
        return UDA_DSMI_CMD_UPSUPPORT_ON_OPTICAL_ERR;
    } else if (ret == OPTICAL_NOT_INIT) { // 光模块初始化未完成
        return UDA_DSMI_OPTICAL_NOT_INIT_ERR;
    } else if (ret == OPTICAL_I2C_BUSY) { // I2C控制权获取失败
        return UDA_DSMI_GET_I2C_CTRL_ERR;
    } else if (ret == OPTICAL_LOOPBACK_OPT_FAIL_DUE_TO_DOWNGRADE) { // 降lane时不允许配置
        return UDA_DSMI_XSFP_FAIL_FOR_DOWNGRADE_ERR;
    } else if (ret == OPTICAL_ABSENT) {
        return UDA_DSMI_XSFP_ABSENT; // 光模块不在位
    } else if (ret == -EACCES) {
        return UDA_TOOL_SYS_NOT_ACCESS;
    } else {
        return UDA_DSMI_EXE_ERR;
    }
}
 
int tool_set_optical_mode(int argc, char **argv, struct tool_param *param)
{
    int ret, logic_id_convert;
    struct ds_optical_mode_info data = {0};

    ret = tool_set_optical_mode_parse(argc, argv, &data);
    if (ret) {
        return ret;
    }

    ret = tool_is_optical_supported_board_type(param);
    if (ret != 0) {
        return ret;
    }

    ret = double_check_before_optical_operation(param, data.mode);
    if (ret) {
        return ret;
    }

    ret = tool_get_convert_logic_id_and_master_flag(param, &logic_id_convert, &data.master_flag);
    if (ret != 0) {
        return ret;
    }

    LOG_CONFIG("Start to set optical mode %u.", data.mode);
    ret = dsmi_set_optical_mode(logic_id_convert, &data);
    return tool_set_optical_mode_error_convert(ret, logic_id_convert, data.mode);
}
