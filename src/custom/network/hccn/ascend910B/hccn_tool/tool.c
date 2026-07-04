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
#include <time.h>
#include "tool.h"
#include "cmd.h"
#include "cfg.h"
#include "dsmi_common_interface.h"
#include "log.h"
#include "tool_ops.h"
#include "tool_ops_ip.h"
#include "weak_passwd_dict.h"
#include "tool_recovery.h"
#include "tool_ext.h"
#include "ds_net_ext.h"
#include "ds_net.h"

#define CALLOC_BLOCK_NUM            1
#define PER_MSECOND                 1000
#define PER_MB                      (1024*1024)
#define ONE_SECOND                  1

int g_recovering = 0;

static struct xsfp_id_map g_xsfp_id_map[] = {
    { 0x00, "UNKNOWN" },
    { 0x01, "GBIC" },
    { 0x03, "SFP_SFPPLUS" },
    { 0x04, "PIN_XBI" },
    { 0x05, "XENPAK" },
    { 0x06, "XFP" },
    { 0x07, "XFF" },
    { 0x08, "XFP_E" },
    { 0x09, "XPAK" },
    { 0x0A, "X2" },
    { 0x0B, "DWDM_SFP_SFPPLUS" },
    { 0x0C, "QSFP" },
    { 0x0D, "QSFPPLUS" },
    { 0x0E, "CXP" },
    { 0x11, "QSFP28 or later" },
    { 0x12, "CXP2" },
    { 0x18, "QSFP_DD" },
    { 0x1E, "QSFP+ or later" },
    { -127, "RESERVED" },
    { 0xFFFF, "NA" },
};

STATIC int tool_shaping_para_get(const char *rate_str, unsigned int *rate_size, unsigned int bw_max)
{
    char c;
    int ret;
    unsigned int index, str_len;

    if (rate_str == NULL) {
        roce_err("rate str is NULL!");
        return UDA_TOOL_INNER_PARAM_ERR;
    }
    str_len = strlen(rate_str);

    for (index = 0; index < str_len; index++) {
        c = rate_str[index];
        switch (c) {
            case '0' ... '9':
                break;
            default:
                roce_err("tool check tm shaping failed, rate_char[%c], index[%u]", c, index);
                return UDA_PARAM_INVALID_ERR;
        }
    }

    ret = tool_para_overflow_check(rate_str, bw_max, UDA_PARAM_BW_LIMIT_OUT_OF_RANGE_ERR);
    if (ret) {
        roce_err("[tool_shaping_para_get] rate_str is overflow");
        return ret;
    }
    *rate_size = strtol(rate_str, NULL, 10); // Decimal(10)

    return 0;
}

int tool_port_shaping_set(int logic_id, int argc, unsigned int port_id, char **argv)
{
    int ret;
    unsigned int bw_limit, bw_max;

    LOG_CONFIG("start to set bw limit of logic_id[%d]", logic_id);

    if (argc != ARGC_ID_2) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "bw_limit", strlen("bw_limit") + 1)) {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
    bw_max = TOOL_MAX_TM_SHAPING_BW_LIMIT;
#else
    struct dsmi_shaping_info shaping_info = {0};
    ret = dsmi_get_port_shaping(logic_id, port_id, &shaping_info);
    if (ret) {
        roce_err("dsmi get tm shaping info fail ret[%d] logic_id[%d]", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
    bw_max = (unsigned int)shaping_info.bw_max_cap;
#endif

    ret = tool_shaping_para_get(argv[1], &bw_limit, bw_max);
    if (ret) {
        roce_err("tool_shaping_para_get fail, ret[%d]!", ret);
        return ret;
    }

    roce_info("logic_id[%d], bw_limit[%u].", logic_id, bw_limit);

    if (bw_limit < TOOL_MIN_TM_SHAPING_BW_LIMIT || bw_limit > bw_max) {
        roce_err("invalid bw_limit size-- '%s', expect[%d]-[%d] ", argv[1],
            TOOL_MIN_TM_SHAPING_BW_LIMIT, bw_max);
        return UDA_PARAM_BW_LIMIT_OUT_OF_RANGE_ERR;
    }

    ret = dsmi_set_port_shaping(logic_id, port_id, bw_limit);
    if (ret) {
        roce_err("dsmi set shaping port fail ret[%d], logic_id[%d], bw_limit[%u].", ret, logic_id, bw_limit);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return 0;
}

int tool_port_shaping_get(int logic_id, int argc, unsigned int port_id, char **argv)
{
    int ret;
    struct dsmi_shaping_info shaping_info;

    if (argc != 0) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_get_port_shaping(logic_id, port_id, &shaping_info);
    if (ret) {
        roce_err("dsmi get tm shaping info fail ret[%d] logic_id[%d]", ret, logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
    TOOL_PRINT_INFO("bw_limit[%d Mbps], bw_max[%d Mbps], bw_cur[%d Mbps]",
        shaping_info.bw_limit, shaping_info.bw_max_cap,
        shaping_info.bw_limit <= shaping_info.bw_max_cap ? shaping_info.bw_limit : shaping_info.bw_max_cap);
#else
    TOOL_PRINT_INFO("bw_limit[%d Mbps], bw_max[%d Mbps]", shaping_info.bw_limit, shaping_info.bw_max_cap);
#endif
    roce_info("ir_b[%d] ir_u[%d] ir_s[%d] bs_b[%d] bs_s[%d]", shaping_info.IR_B, shaping_info.IR_U,
        shaping_info.IR_S, shaping_info.BS_B, shaping_info.BS_S);

    return 0;
}

int tool_shaping_cmd_execute(int argc, char **argv, struct tool_param *param, unsigned int port_id)
{
    int ret, logic_id = param->logic_id, argc_tmp = argc - 1, tmp_port_id = 0;
    char **argv_tmp = argv + 1;
    if (argc == 0) {
        roce_err("tool_shaping_cmd_execute err argc[%d].", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_port_shaping_set(logic_id, argc_tmp, tmp_port_id, argv_tmp);
        if (ret) {
            roce_err("port shaping set failed, ret[%d] logic_id[%d]", ret, param->logic_id);
            return ret;
        }
        ret = cfg_write_conf(param->phy_id, "bw_limit", argv[ARGV_NUM_2]);
        if (ret) {
            roce_err("write cfg error[%d], phy_id[%d]", ret, param->phy_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_port_shaping_get(logic_id, argc_tmp, tmp_port_id, argv_tmp);
        if (ret) {
            roce_err("port shaping get failed ret[%d]", ret);
            return ret;
        }
    } else {
        roce_err("invalid operation");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}

int tool_add_arp_conf(int phy_id, const char *cmd, const char *dev, const char *ip)
{
#define ARP_ADD_MATCH_CNT 3
    int ret;
    char cmd_buf[CONLINE_LENGTH] = {0}, match_list[ARP_ADD_MATCH_CNT][CONLINE_LENGTH];
    unsigned int tmp;

    ret = memset_s(match_list, sizeof(match_list), 0, sizeof(match_list));
    if (ret) {
        roce_err("Add arp conf memset failed. (ret=%d)", ret);
        return ret;
    }
    ret = sprintf_s(cmd_buf, CONLINE_LENGTH, "arp_%d=%s\n", phy_id, cmd);
    if (ret <= 0) {
        roce_err("Add arp conf sprintf cmd_buf failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = sprintf_s(match_list[0], CONLINE_LENGTH, "arp_%d=", phy_id);
    if (ret <= 0) {
        roce_err("Add arp conf sprintf phy_id failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = sprintf_s(match_list[ARGC_ID_1], CONLINE_LENGTH, "%s ", dev);
    if (ret <= 0) {
        roce_err("Add arp conf sprintf dev failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = sprintf_s(match_list[ARGC_ID_2], CONLINE_LENGTH, "%s ", ip);
    if (ret <= 0) {
        roce_err("Add arp conf sprintf ip failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = handle_conf_to_file(cmd_buf, FILE_OPT_TYPE_MATCH_REPLACES, match_list, ARP_ADD_MATCH_CNT);
    if (ret) {
        roce_err("Tool add arp cfg failed. (ret=%d; cmd=\"%s\")", ret, cmd_buf);
    }
    return ret;
}

int tool_del_arp_conf(int phy_id, const char *dev, const char *ip)
{
#define ARP_DEL_MATCH_CNT 3
    int ret;
    char match_list[ARP_DEL_MATCH_CNT][CONLINE_LENGTH];
    unsigned int tmp;

    ret = memset_s(match_list, sizeof(match_list), 0, sizeof(match_list));
    if (ret) {
        roce_err("Del arp conf memset failed. (ret=%d)", ret);
        return ret;
    }
    ret = sprintf_s(match_list[0], CONLINE_LENGTH, "arp_%d=", phy_id);
    if (ret <= 0) {
        roce_err("Del arp conf sprintf phy_id failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = sprintf_s(match_list[ARGC_ID_1], CONLINE_LENGTH, "%s ", dev);
    if (ret <= 0) {
        roce_err("Del arp conf sprintf dev failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = sprintf_s(match_list[ARGC_ID_2], CONLINE_LENGTH, "%s ", ip);
    if (ret <= 0) {
        roce_err("Del arp conf sprintf ip failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    ret = handle_conf_to_file(NULL, FILE_OPT_TYPE_MATCH_DEL, match_list, ARP_DEL_MATCH_CNT);
    if (ret) {
        roce_err("Tool del arp cfg failed. (ret=%d)", ret);
    }
    return ret;
}

static int tool_prepare_add_arp_param(const char *dev, const char *ip, const char *mac,
                                      struct ds_arp_table_value *cmd_info)
{
    const char *dev_name = NULL;
    unsigned int eth_id;
    struct in_addr addr;
    int ret;

    cmd_info->cmd_type = 's';
    if (strncmp(dev, "eth", strlen("eth")) != 0) {
        return UDA_PARAM_INVALID_ERR;
    }
    dev_name = dev + strlen("eth");
    eth_id = (unsigned int)strtoul(dev_name, NULL, 0);
    if (eth_id > MAX_DEV_ID) {
        roce_err("Invalid eth id in arp cmd.");
        return UDA_PARAM_INVALID_ERR;
    }
    cmd_info->eth_id = eth_id;

    ret = inet_pton(AF_INET, ip, &addr);
    if (ret <= 0) {
        roce_err("Invalid IPv4 address. (ret=%d; errno=%d)", ret, errno);
        return UDA_PARAM_IP_INVALID_ERR;
    }
    cmd_info->ip_address = addr.s_addr;

    ret = tool_mac_str2char(mac, cmd_info->mac_address, TOOL_MAC_ADDR_LEN);
    if (ret != 0) {
        roce_err("Invalid mac_address.");
        return ret;
    }
    return ret;
}

static int tool_send_recovery_arp_cmd(int logic_id, const char *cmdline)
{
    int ret;
    struct send_data_info data_info;
    struct ds_arp_table_value cmd_info = {0};
    unsigned char ip_fst, ip_sed, ip_thd, ip_fth;
    // numbers 0 - 5 are used as index in mac_addr array
    ret = sscanf_s(cmdline, "-i eth%u -s %hhu.%hhu.%hhu.%hhu %hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &cmd_info.eth_id,
        // mac address[0或1] 是 cmd_info.mac_address的第0、1位
        &ip_fst, &ip_sed, &ip_thd, &ip_fth, &cmd_info.mac_address[0], &cmd_info.mac_address[1],
        // mac_address的2、3、4位
        &cmd_info.mac_address[2], &cmd_info.mac_address[3], &cmd_info.mac_address[4],
        // mac_address的5位
        &cmd_info.mac_address[5]);
    if (ret <= 0) {
        roce_err("Tool arp recovery get param failed. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }

    cmd_info.ip_address = ip_fst + (ip_sed << 0x8) + (ip_thd << 0x10) + (ip_fth << 0x18);
    cmd_info.cmd_type = 's';

    TOOL_SET_SEND_DATA(data_info, DS_SET_ARP_TABLE_CFG, (char *)(uintptr_t)&cmd_info, sizeof(cmd_info), NULL, 0);

    ret = dsmi_send_data(logic_id, 0, &data_info);
    if (ret != 0) {
        roce_err("Tool arp recovery dsmi send data fail! ret[%d] logic_id[%d]", ret, logic_id);
        ret = dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return ret;
}

int tool_send_arp_recovery_cmd(const char *cfg, struct tool_param *param)
{
    int ret;
    char *p = NULL;
    char cmdline[INFO_PAYLOAD_LEN] = {0};

    ret = strncpy_s(cmdline, INFO_PAYLOAD_LEN, cfg, strlen(cfg));
    if (ret) {
        roce_err("Tool arp recovery strncpy cfg failed. (ret=%d)", ret);
        return ret;
    }

    p = strtok(cmdline, "=");
    if (p == NULL) {
        roce_err("Strtok get p failed.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    p = strtok(NULL, "=");
    /* del the end \n symbol */
    if (p == NULL) {
        roce_err("Strtok get p failed.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }
    p[strlen(p) - 1] = '\0';

    return tool_send_recovery_arp_cmd(param->logic_id, p);
}

int tool_cfg_arp_recovery(struct tool_param *param)
{
    char arp_prefix[CONLINE_LENGTH] = {0};
    int ret;
    char address[MAX_IP_LEN] = "", netmask[MAX_IP_LEN] = "";

    ret = cfg_read_conf(param->phy_id, "udhcpc_enable", address, sizeof(address));
    if (ret == 0) {
        roce_info("Udhcpc enable, do not need recover arp cfg.");
        return 0;
    }

    ret = cfg_read_conf(param->phy_id, "arp", arp_prefix, sizeof(arp_prefix));
    if (ret != 0) {
        if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) { // 当配置文件中没有找到这个配置时，返回成功，跳过配置
            roce_info("The arp conf name is not found in config file, skipped. (ret=%d)", ret);
            return 0;
        } else { // 其他错误返回失败
            roce_err("Other inner err. (ret=%d; phy_id=%d)", ret, param->phy_id);
            return ret;
        }
    }

    ret = tool_cfg_cmdline_recovery(arp_prefix, CONLINE_LENGTH, param, tool_send_arp_recovery_cmd);

    return ret;
}

int tool_get_arp_table(int argc, char **argv, struct tool_param *param)
{
    int ret;
    struct send_data_info data_info;
    struct ds_arp_table_value cmd_info = {0};

    if (argc != 0) {
        roce_err("Tool get arp param failed. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    cmd_info.cmd_type = 'g';
    TOOL_SET_SEND_DATA(data_info, DS_ARP_TABLE_CFG, (char *)(uintptr_t)&cmd_info, sizeof(cmd_info), NULL, 0);
    data_info.out_buf = (char *)calloc(MAX_TRANS_DATA_LEN, sizeof(char));
    if (data_info.out_buf == NULL) {
        roce_err("Tool get arp calloc out buf failed.");
        return UDA_TOOL_NO_MEM_ERR;
    }
    data_info.size_out = MAX_TRANS_DATA_LEN;

    ret = dsmi_send_data(param->logic_id, 0, &data_info);
    if (ret) {
        free(data_info.out_buf);
        roce_err("Dsmi send data failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
        if (ret == -ENOENT) {
            ret = UDA_TOOL_CONF_NOT_EXIST_ERR;
        } else if (ret == UDA_TOOL_SYS_BUSY_ERR) {
            ret = UDA_TOOL_SYS_BUSY_ERR;
        } else {
            ret = dsmi_analysis_dsmi_ret_to_uda(ret);
        }
        return ret;
    }
    data_info.out_buf[MAX_ROUTE_TABLE_LEN - 1] = '\0';
    DSMI_PRINT_INFO("arp table:");
    DSMI_PRINT_INFO("%s", data_info.out_buf);

    free(data_info.out_buf);
    return 0;
}

static int tool_add_arp_table_conf(int phy_id, const char *dev, const char *ip, const char *mac)
{
    int ret;
    char *cmd_buf = NULL;
    cmd_buf = (char *)calloc(INFO_PAYLOAD_LEN, sizeof(char));
    if (cmd_buf == NULL) {
        roce_err("Tool add arp calloc in buf failed.");
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = sprintf_s(cmd_buf, INFO_PAYLOAD_LEN, "-i %s -s %s %s", dev, ip, mac);
    if (ret <= 0) {
        free(cmd_buf);
        roce_err("Tool construct cmdline failed. (ret=%d)", ret);
        return -UDA_TOOL_INNER_PARAM_ERR;
    }

    ret = tool_add_arp_conf(phy_id, cmd_buf, dev, ip);
    free(cmd_buf);
    return ret;
}

int tool_add_arp_table(int argc, char **argv, struct tool_param *param)
{
    int ret;
    struct send_data_info data_info;
    struct ds_arp_table_value cmd_info = {0};
    char dev[MAX_IP_LEN] = {0}, ip[MAX_IP_LEN] = {0}, mac[MAX_IP_LEN] = {0};

    if (argc != ARGC_ID_6) {
        roce_err("Tool add arp param failed. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = tool_get_param(argc, argv, "dev", dev, MAX_IP_LEN);
    if (ret != 0) {
        return ret;
    }
    ret = tool_get_param(argc, argv, "ip", ip, MAX_IP_LEN);
    if (ret != 0) {
        return ret;
    }
    ret = tool_get_param(argc, argv, "mac", mac, MAX_IP_LEN);
    if (ret != 0) {
        return ret;
    }

    ret = tool_prepare_add_arp_param(dev, ip, mac, &cmd_info);
    if (ret) {
        roce_err("Tool add arp prepare param failed.");
        return ret;
    }

    TOOL_SET_SEND_DATA(data_info, DS_SET_ARP_TABLE_CFG, (char *)(uintptr_t)&cmd_info, sizeof(cmd_info), NULL, 0);

    ret = dsmi_send_data(param->logic_id, 0, &data_info);
    if (ret) {
        roce_err("Dsmi send data failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    if (!check_udhcpc_write_hccn_conf(param, 0)) {
        ret = tool_add_arp_table_conf(param->phy_id, dev, ip, mac);
        if (ret) {
            roce_err("Add arp to config file failed. (ret=%d)", ret);
            return ret;
        }
    }
    return 0;
}

static int tool_prepare_del_arp_param(const char *dev, const char *ip, struct ds_arp_table_value *cmd_info)
{
    const char *dev_name = NULL;
    unsigned int eth_id;
    struct in_addr addr;
    int ret;

    cmd_info->cmd_type = 'd';
    if (strncmp(dev, "eth", strlen("eth")) != 0) {
        return UDA_PARAM_INVALID_ERR;
    }
    dev_name = dev + strlen("eth");
    eth_id = (unsigned int)strtoul(dev_name, NULL, 0);
    if (eth_id > MAX_DEV_ID) {
        roce_err("Invalid eth id in arp cmd.");
        return UDA_PARAM_INVALID_ERR;
    }
    cmd_info->eth_id = eth_id;

    ret = inet_pton(AF_INET, ip, &addr);
    if (ret <= 0) {
        roce_err("Invalid IPv4 address. (ret=%d; errno=%d)", ret, errno);
        return UDA_PARAM_IP_INVALID_ERR;
    }
    cmd_info->ip_address = addr.s_addr;
    return 0;
}

int tool_del_arp_table(int argc, char **argv, struct tool_param *param)
{
    int ret;
    struct send_data_info data_info;
    struct ds_arp_table_value cmd_info = {0};
    char dev[MAX_IP_LEN] = {0}, ip[MAX_IP_LEN] = {0};

    if (argc != ARGC_ID_4) {
        roce_err("Tool del arp param failed. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = tool_get_param(argc, argv, "dev", dev, MAX_IP_LEN);
    if (ret != 0) {
        return ret;
    }
    ret = tool_get_param(argc, argv, "ip", ip, MAX_IP_LEN);
    if (ret != 0) {
        return ret;
    }

    ret = tool_prepare_del_arp_param(dev, ip, &cmd_info);
    if (ret) {
        roce_err("Tool del arp trans param failed.");
        return ret;
    }

    TOOL_SET_SEND_DATA(data_info, DS_SET_ARP_TABLE_CFG, (char *)(uintptr_t)&cmd_info, sizeof(cmd_info), NULL, 0);

    ret = dsmi_send_data(param->logic_id, 0, &data_info);
    if (ret) {
        if (ret == ENOENT) {
            return UDA_TOOL_CONF_NOT_EXIST_ERR;
        }
        roce_err("Dsmi send data failed. (ret=%d; logic_id=%d)", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = tool_del_arp_conf(param->phy_id, dev, ip);
    if (ret) {
        roce_err("Del arp from config file failed. (ret=%d)", ret);
        return ret;
    }
    return 0;
}

int tool_arp_table_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc == 0) {
        roce_err("Tool_arp_table_cmd_execute failed. (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_arp_table(argc - 1, argv + 1, param);
        if (ret) {
            roce_err("Tool_get_arp_table failed. (ret=%d)", ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-a", strlen("-a") + 1)) {
        ret = tool_add_arp_table(argc - 1, argv + 1, param);
        if (ret) {
            roce_err("Tool_add_arp_table failed. (ret=%d)", ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-d", strlen("-d") + 1)) {
        ret = tool_del_arp_table(argc - 1, argv + 1, param);
        if (ret) {
            roce_err("Tool_del_arp_table failed. (ret=%d)", ret);
            return ret;
        }
    } else {
        roce_err("Arp cmd get option failed.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}

int tool_check_single_route_cmd_argv(char **argv, char **ip, const char prefix[], char *route_char,
    unsigned int route_char_length)
{
    int ret;

    if (!strncmp(argv[0], prefix, strlen(prefix) + 1)) {
        ret = memcpy_s(route_char, route_char_length, ip[0], strlen(ip[0]) + 1);
        if (ret) {
            roce_err("memcpy_s address fail[%d], dlen[%d], slen[%u] destStr length is %d", ret, route_char_length,
                strlen(ip[0]) + 1, route_char_length);
            return UDA_TOOL_NO_MEM_ERR;
        }
    } else {
        roce_err("err cmd");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}


STATIC int tool_check_route_cmd_argv(char **argv, struct ds_route_table_character *route_char, bool is_add)
{
    int ret;

    ret = tool_check_single_route_cmd_argv(argv + ARGC_ID_1, argv + ARGC_ID_2, "address", route_char->address,
        sizeof(route_char->address));
    if (ret) {
        roce_err("tool_check_single_route_cmd_argv address fail! ret [%d]", ret);
        return ret;
    }

    ret = tool_check_single_route_cmd_argv(argv + ARGC_ID_3, argv + ARGC_ID_4, "netmask", route_char->netmask,
        sizeof(route_char->netmask));
    if (ret) {
        roce_err("tool_check_single_route_cmd_argv netmask fail! ret [%d]", ret);
        return ret;
    }

    if (is_add) {
        ret = tool_check_single_route_cmd_argv(argv + ARGC_ID_5, argv + ARGC_ID_6, "gateway", route_char->gateway,
            sizeof(route_char->gateway));
        if (ret) {
            roce_err("tool_check_single_route_cmd_argv gateway fail! ret [%d]", ret);
            return ret;
        }
    }

    return 0;
}

STATIC int tool_route_table_inet_pton(struct ds_route_table_character *route_char,
    struct ds_route_table_value *route_param, bool is_add)
{
    int ret;

    ret = tool_inet_pton_ipv4_address(route_char->address, &route_param->address);
    if (ret) {
        roce_err("tool_inet_pton_ipv4_address address fail! ret[%d]", ret);
        return ret;
    }

    ret = tool_inet_pton_ipv4_address(route_char->netmask, &route_param->netmask);
    if (ret) {
        roce_err("tool_inet_pton_ipv4_address netmask fail! ret[%d]", ret);
        return ret;
    }

    if (is_add) {
        ret = tool_inet_pton_ipv4_address(route_char->gateway, &route_param->gateway);
        if (ret) {
            roce_err("tool_inet_pton_ipv4_address gateway fail! ret[%d]", ret);
            return ret;
        }
    }
    return ret;
}

STATIC int tool_route_param_trans(char **argv, struct tool_param *param, struct ds_route_table_value *route_param,
    struct ds_route_table_character *route_char, bool is_add)
{
    int ret, is_address_default, is_mask_default;

    ret = tool_check_route_cmd_argv(argv, route_char, is_add);
    if (ret) {
        roce_err("tool_check_route_cmd_argv error! ret is:%d", ret);
        return ret;
    }

    is_address_default = strncmp(route_char->address, TOOL_DEFAULT_ROUTE_ADDRESS, strlen(TOOL_DEFAULT_ROUTE_ADDRESS));
    is_mask_default = strncmp(route_char->netmask, TOOL_DEFAULT_ROUTE_NETMASK, strlen(TOOL_DEFAULT_ROUTE_NETMASK));
    if (is_address_default == 0 || is_mask_default == 0) {
        roce_err("invalid params! can not add default route.");
        return UDA_TOOL_COFNIG_DEFAULT_ROUTE_ERR;
    }

    ret = tool_route_table_inet_pton(route_char, route_param, is_add);
    if (ret) {
        roce_err("tool_route_table_inet_pton fail logic_id[%d] ret[%d]", param->logic_id, ret);
        return ret;
    }
    route_param->is_route_on_eth = is_ATLAS_900_A3_SUPERPOD(param->mainboard_id);

    return 0;
}

STATIC int tool_route_trans_conf(struct ds_route_table_character route_char, char *route_cfg,
    unsigned int route_cfg_len, char *gateway, unsigned int gateway_len)
{
    int ret;

    ret = snprintf_s(route_cfg, route_cfg_len, route_cfg_len - 1, "route_address_%s_netmask_%s",
        route_char.address, route_char.netmask);
    if (ret <= 0) {
        roce_err("snprintf_s route config fail! ret : %d.", ret);
        return -EINVAL;
    }

    ret = snprintf_s(gateway, gateway_len, gateway_len - 1, "gateway_%s", route_char.gateway);
    if (ret <= 0) {
        roce_err("snprintf_s route gateway fail! ret : %d.", ret);
        return -EINVAL;
    }

    return 0;
}

STATIC int tool_get_gateway_from_conf(const char *conf_gw, char *gw, unsigned int gw_len)
{
    int ret;
    unsigned int gw_fst = 0, gw_sed = 0, gw_thd = 0, gw_fth = 0;

    ret = sscanf_s(conf_gw, "gateway_%x.%x.%x.%x", &gw_fst, &gw_sed, &gw_thd, &gw_fth);
    if (ret != FOUR_VALUE) {
        roce_err("sscanf buf to gateway failed. ret(%d)", ret);
        return -ENOMEM;
    }

    ret = snprintf_s(gw, gw_len, gw_len - 1, "%x.%x.%x.%x", gw_fst, gw_sed, gw_thd, gw_fth);
    if (ret <= 0) {
        roce_err("snprintf_s route conf gateway fail! ret : %d.", ret);
        return -EINVAL;
    }

    return 0;
}

STATIC int tool_check_route(struct tool_param *param, struct ds_route_table_value route_param,
    struct ds_route_table_character route_char, const char *route_cfg, unsigned int route_cfg_len,
    ip_addr_t ip_address, ip_addr_t mask_address)
{
    int ret;
    char gw[MAX_IP_LEN] = {0};
    char conf_gw[CONLINE_LENGTH] = {0};
    unsigned int address, ip_mask_address;
    
    if (!is_network_segment(route_param.address, route_param.netmask)) {
        roce_err("Address is not network segment");
        return UDA_TOOL_IP_MISMATCH_MASK_ERR;
    }
    
    address = *(unsigned int *)(void *)&ip_address.u_addr;
    ip_mask_address = *(unsigned int *)(void *)&mask_address.u_addr;
    
    if (!is_address_gateway_same_segment(address, route_param.gateway, ip_mask_address)) {
        roce_err("Address and gateway are not in the same network segment");
        return UDA_PARAM_DIFF_SEGMT_GTWY_ERR;
    }

    ret = is_ipaddr_conflict(param->logic_id, route_char.address, route_char.netmask);
    if (ret == UDA_PARAM_CONFLICT_IP_ADDR_ERR) {
        DSMI_PRINT_INFO("Route address segment is conflict with vnip ip!");
        roce_err("ipaddr conflict");
        return ret;
    } else if ((ret != 0) && (ret != UDA_DSMI_IPCONF_NOT_PRESET_ERR)) {
        roce_err("Ipaddr conflict failed.");
        return ret;
    }

    ret = cfg_read_conf(param->phy_id, route_cfg, conf_gw, sizeof(conf_gw));
    if (ret == 0) {
        ret = tool_get_gateway_from_conf(conf_gw, gw, MAX_IP_LEN);
        if (ret) {
            roce_err("tool_check_route_exist err! ret is [%d]", ret);
            return ret;
        } else {
            roce_err("Route already exist in routing table!");
            if (strncmp(conf_gw, gw, strlen(gw))) {
                roce_err("tool_add_route_table: invalid gateway!");
                return UDA_TOOL_ROUTE_ALREADY_EXIST_ERR;
            }
        }
    }

    if (ret != UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
        roce_err("tool_add_route_table cfg_read_conf err! ret is [%d] route_cfg_len is [0x%x]", ret, route_cfg_len);
        return ret;
    }

    return 0;
}

STATIC int tool_add_route_table(char **argv, struct tool_param *param, bool is_add)
{
    int ret, temp_ret, port_type = DSMI_ROCE_PORT, port_id = 0;
    char info[MAX_CMD_PAYLOAD_LEN] = {0}, route_cfg[CONLINE_LENGTH] = {0}, gateway[CONLINE_LENGTH] = {0};
    struct ds_route_table_value route_param = {0};
    struct ds_route_table_character route_char = {{0}};
    ip_addr_t ip_address, mask_address;

    LOG_CONFIG("start to add route of logic_id[%d]", param->logic_id);

    ret = tool_route_param_trans(argv, param, &route_param, &route_char, is_add);
    if (ret) {
        roce_err("tool_route_param_trans failed! ret is: %d, is_add is: %d", ret, is_add);
        return ret;
    }

    ret = tool_route_trans_conf(route_char, route_cfg, sizeof(route_cfg),
        gateway, sizeof(gateway));
    if (ret) {
        roce_err("tool_route_trans_conf failed! ret is %d", ret);
        return ret;
    }
    
    ip_address.ip_type = IPADDR_TYPE_V4;
    mask_address.ip_type = IPADDR_TYPE_V4;
    ret = dsmi_get_device_ip_address(param->logic_id, port_type, port_id, &ip_address, &mask_address);
    if (ret) {
        roce_err("Dsmi_get_device_ip_address fail ret=%d, logic_id[%d]", ret, param->logic_id);
        ret = (ret == DRV_ERROR_NO_DEVICE) ? UDA_DSMI_IPCONF_NOT_PRESET_ERR : UDA_DSMI_EXE_ERR;
        return ret;
    }

    ret = dsmi_add_route_table(param->logic_id, 0, &route_param, info, MAX_CMD_PAYLOAD_LEN);
    if (ret == TOOL_MAX_ROUTE_ROWS) {
        roce_err("Route rows reaches max! Can not add anymore!");
        return UDA_DSMI_ROUTE_ROW_REACH_MAX_ERR;
    }

    if (ret) {
        temp_ret = tool_check_route(param, route_param, route_char, route_cfg,
            sizeof(route_cfg), ip_address, mask_address);
        if (temp_ret) {
            return temp_ret;
        }
        roce_err("dsmi add route table fail! ret[%d] logic_id[%d] address[0x%x] netmask[0x%x] gateway[0x%x]",
            ret, param->logic_id, route_param.address, route_param.netmask, route_param.gateway);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    if (!check_udhcpc_write_hccn_conf(param, 0)) {
        ret = cfg_write_conf(param->phy_id, route_cfg, gateway);
        if (ret) {
            roce_err("add route cfg error! ret[%d] logic_id[%d]", ret, param->logic_id);
            return ret;
        }
    }

    return 0;
}

STATIC int tool_del_route(struct ds_route_table_character route_char, struct ds_route_table_value route_param,
    struct tool_param *param, char *info, unsigned int len)
{
    int ret;
    char route_cfg[CONLINE_LENGTH] = {0};
    char gateway[CONLINE_LENGTH] = {0};

    ret = snprintf_s(route_cfg, CONLINE_LENGTH, CONLINE_LENGTH - 1, "route_address_%s_netmask_%s",
        route_char.address, route_char.netmask);
    if (ret <= 0) {
        roce_err("snprintf_s route config fail! ret : %d.", ret);
        return -EINVAL;
    }

    ret = cfg_read_conf(param->phy_id, route_cfg, gateway, sizeof(gateway));
    if (ret == UDA_TOOL_SYS_RD_FILE_NOT_FOUND) {
        roce_info("Route not exist in routing table, can not delete!");
        return UDA_TOOL_ROUTE_NOT_EXIST_ERR;
    }

    if (ret != 0) {
        roce_err("tool_add_route_table cfg_read_conf err! ret is [%d]", ret);
        return ret;
    }

    ret = dsmi_del_route_table(param->logic_id, 0, &route_param, info, len);
    if (ret) {
        roce_err("dsmi del route table fail! ret[%d] logic_id[%d] address[0x%x] netmask[0x%x]",
            ret, param->logic_id, route_param.address, route_param.netmask);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = cfg_del_conf(param->phy_id, route_cfg);
    if (ret) {
        roce_err("delete route cfg error! ret[%d] phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    return 0;
}

STATIC int tool_del_route_table(char **argv, struct tool_param *param, bool is_add)
{
    int ret;
    char info[MAX_CMD_PAYLOAD_LEN] = {0};
    struct ds_route_table_value route_param = {0};
    struct ds_route_table_character route_char = {{0}};
    LOG_CONFIG("start to delete route of logic_id[%d]", param->logic_id);

    ret = tool_route_param_trans(argv, param, &route_param, &route_char, is_add);
    if (ret) {
        roce_err("tool_route_param_trans failed! ret is: %d", ret);
        return ret;
    }
    
    ret = tool_del_route(route_char, route_param, param, info, MAX_CMD_PAYLOAD_LEN);
    if (ret) {
        roce_err("tool_del_route failed! ret is: %d", ret);
        return ret;
    }
    return 0;
}

STATIC int get_route_from_conf(char *line_buf, unsigned int *conf_id, struct tool_route_para *route_param)
{
    int ret;

    ret = sscanf_s(line_buf, "route_address_%u.%u.%u.%u_netmask_%u.%u.%u.%u_%u=gateway_%u.%u.%u.%u",
        route_param->address_ip, route_param->address_ip + ONE_VALUE,
        route_param->address_ip + TWO_VALUE, route_param->address_ip + THREE_VALUE,
        route_param->netmask_ip, route_param->netmask_ip + ONE_VALUE,
        route_param->netmask_ip + TWO_VALUE, route_param->netmask_ip + THREE_VALUE,
        conf_id,  route_param->gateway_ip,  route_param->gateway_ip + ONE_VALUE,
        route_param->gateway_ip + TWO_VALUE, route_param->gateway_ip + THREE_VALUE);
    if (ret != THIRTEEN) {
        roce_err("sscanf_s buf(%s) to route config failed. ret(%d)", line_buf, ret);
        return -ENOMEM;
    }
    return 0;
}

STATIC int tool_recover_single_route(struct ds_route_table_character *route_char, struct tool_param *param)
{
    int ret;
    char info[MAX_CMD_PAYLOAD_LEN] = {0};
    struct ds_route_table_value route_param = {0};

    ret = tool_route_table_inet_pton(route_char, &route_param, true);
    if (ret) {
        roce_err("tool_route_table_inet_pton fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
        return UDA_DSMI_EXE_ERR;
    }

    ret = dsmi_add_route_table(param->logic_id, 0, &route_param, info, MAX_CMD_PAYLOAD_LEN);
    if (ret == TOOL_MAX_ROUTE_ROWS) {
        roce_warn("Route rows reaches max! Can not add anymore!");
        return 0;
    }

    if (ret) {
        roce_err("dsmi add route table fail! ret[%d] logic_id[%d] address[0x%x] netmask[0x%x] gateway[0x%x]",
            ret, param->logic_id, route_param.address, route_param.netmask, route_param.gateway);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    return 0;
}

STATIC int tool_del_route_config(char *route_cfg, unsigned int route_cfg_len,
    struct ds_route_table_character *route_char, struct tool_param *param, FILE *fp)
{
    int ret;

    ret = snprintf_s(route_cfg, CONLINE_LENGTH, CONLINE_LENGTH - 1, "route_address_%s_netmask_%s_%d=",
        route_char->address, route_char->netmask, param->phy_id);
    if (ret <= 0) {
        roce_err("snprintf_s route config fail! ret : %d. route config length is %u", ret, route_cfg_len);
        return -EINVAL;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        return UDA_TOOL_SYS_DELETE_FILE_ERR;
    }

    ret = cfg_inner_del_conf_byfd(fp, route_cfg);
    if (ret) {
        roce_err("cfg_inner_del_conf_byfd: delete cfg error! ret[%d] logic_id[%d]", ret, param->logic_id);
        return ret;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        return UDA_TOOL_SYS_DELETE_FILE_ERR;
    }

    return 0;
}

STATIC int tool_del_route_by_fd(FILE *fp, struct ds_route_table_character *route_char, struct tool_param *param)
{
    int ret;
    char info[MAX_CMD_PAYLOAD_LEN] = {0};
    char route_cfg[CONLINE_LENGTH] = {0};
    struct ds_route_table_value route_param = {0};

    ret = tool_route_table_inet_pton(route_char, &route_param, false);
    if (ret) {
        roce_err("tool_route_table_inet_pton fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
        return UDA_PARAM_IP_INVALID_ERR;
    }

    ret = dsmi_del_route_table(param->logic_id, 0, &route_param, info, MAX_CMD_PAYLOAD_LEN);
    if (ret) {
        roce_err("dsmi del route table fail! ret[%d] logic_id[%d] address[0x%x] netmask[0x%x]",
            ret, param->logic_id, route_param.address, route_param.netmask);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = tool_del_route_config(route_cfg, sizeof(route_cfg), route_char, param, fp);
    if (ret) {
        roce_err("tool_del_route_config failed! route_char is %s, ret is %d", route_cfg, ret);
        return ret;
    }

    return 0;
}

STATIC int tool_del_not_segment_route_by_fd(FILE *fp, struct ds_route_table_character *route_char,
    struct tool_param *param, struct ds_route_table_value ip_param)
{
    int ret;
    char route_cfg[CONLINE_LENGTH] = {0};
    unsigned int gateway = inet_addr(route_char->gateway);
    if ((ip_param.address & ip_param.netmask) != (gateway & ip_param.netmask)) {
        ret = tool_del_route_config(route_cfg, sizeof(route_cfg), route_char, param, fp);
        if (ret) {
            roce_err("tool_del_route_config failed! route_char is %s, ret is %d", route_cfg, ret);
            return ret;
        }
    }
    return 0;
}

STATIC int tool_select_action_for_route(enum read_route_operation route_op, struct tool_param *param, FILE *fp,
    struct ds_route_table_character *route_char, struct ds_route_table_value ip_param)
{
    int ret;

    switch (route_op) {
        case READ_TO_RECOVERY:
            ret = tool_recover_single_route(route_char, param);
            if (ret) {
                roce_err("tool_select_action_for_route: tool_recover_single_route failed! ret is [%d]", ret);
                return ret;
            }
            break;
        case READ_TO_CLEAR:
            ret = tool_del_route_by_fd(fp, route_char, param);
            if (ret) {
                roce_err("tool_select_action_for_route: tool_del_route_by_fd failed! ret is [%d]", ret);
                return ret;
            }
            break;
        case READ_TO_DEL_NOT_SAME_SEGMENT:
            ret = tool_del_not_segment_route_by_fd(fp, route_char, param, ip_param);
            if (ret) {
                roce_err("tool_select_action_for_route: tool_del_not_segment_route_by_fd failed! ret is [%d]", ret);
                return ret;
            }
            break;
        default:
            break;
    }
    return 0;
}

STATIC int tool_trans_conf_to_char(struct ds_route_table_character *route_char, struct tool_route_para route_param)
{
    int ret;

    ret = snprintf_s(route_char->address, MAX_IP_LEN, MAX_IP_LEN - 1, "%u.%u.%u.%u",
        route_param.address_ip[0], route_param.address_ip[ONE_VALUE],
        route_param.address_ip[TWO_VALUE], route_param.address_ip[THREE_VALUE]);
    if (ret <= 0) {
        roce_err("snprintf_s route %s ip fail! ret : %d.", route_char->address, ret);
        return -EINVAL;
    }

    ret = snprintf_s(route_char->netmask, MAX_IP_LEN, MAX_IP_LEN - 1, "%u.%u.%u.%u",
        route_param.netmask_ip[0], route_param.netmask_ip[ONE_VALUE],
        route_param.netmask_ip[TWO_VALUE], route_param.netmask_ip[THREE_VALUE]);
    if (ret <= 0) {
        roce_err("snprintf_s route %s ip fail! ret : %d.", route_char->netmask, ret);
        return -EINVAL;
    }

    ret = snprintf_s(route_char->gateway, MAX_IP_LEN, MAX_IP_LEN - 1, "%u.%u.%u.%u",
        route_param.gateway_ip[0], route_param.gateway_ip[ONE_VALUE],
        route_param.gateway_ip[TWO_VALUE], route_param.gateway_ip[THREE_VALUE]);
    if (ret <= 0) {
        roce_err("snprintf_s route %s ip fail! ret : %d.", route_char->gateway, ret);
        return -EINVAL;
    }

    return 0;
}

STATIC int tool_trans_config_to_route(FILE *fp, struct tool_param *param, enum read_route_operation route_op,
    struct ds_route_table_value ip_param)
{
    int ret, route_count = 0;
    char *c = NULL;
    unsigned int conf_id = 0;
    char line_buf[CONLINE_LENGTH] = {0};
    struct tool_route_para route_param = {{0}};
    struct ds_route_table_character route_char = {{0}};

    while (!feof(fp) && fgets(line_buf, CONLINE_LENGTH, fp) != NULL) {
        if (line_buf[0] == '#' || strlen(line_buf) < strlen("*=*")) {
            continue;
        }

        c = (char *)strchr(line_buf, '=');
        if (c == NULL) {
            continue;
        }

        if (strncmp(line_buf, "route", FIVE_VALUE) != 0) {
            continue;
        }

        ret = get_route_from_conf(line_buf, &conf_id, &route_param);
        if (ret) {
            roce_err("get_route_from_conf failed! ret is [%d].", ret);
            return ret;
        }

        if (conf_id != (unsigned int)param->phy_id) {
            continue;
        }

        ret = tool_trans_conf_to_char(&route_char, route_param);
        if (ret) {
            roce_err("tool_trans_conf_to_char err! ret is [%d]", ret);
            return ret;
        }

        route_count++;
        ret = tool_select_action_for_route(route_op, param, fp, &route_char, ip_param);
        if (ret) {
            roce_err("tool_select_action_for_route failed! ret is [%d]", ret);
            return ret;
        }
    }
    if (route_count == 0) {
        ret = tool_route_clear_zero_conf(param, route_op, CLEAR_ROUTE_TYPE_IPV4);
        if (ret) {
            roce_err("tool_route_clear_zero_conf failed! ret is [%d]", ret);
            return ret;
        }
    }
    return 0;
}

int tool_read_hccn_conf_handle_action(struct tool_param *param, enum read_route_operation route_op,
    struct ds_route_table_value ip_param)
{
    FILE *fp = NULL;
    int ret, ret_val;
    char real_conf_path[PATH_MAX + 1] = {0};//lint !e813

    if ((strlen(CFGFILE_NAME) > PATH_MAX) || (realpath(CFGFILE_NAME, real_conf_path) == NULL)) {
        roce_err("read path_len > PATH_MAX or conf_path is invalid, err[%d]", errno);
        return UDA_TOOL_ACCESS_CONF_FILE_ERR;
    }

    fp = fopen(real_conf_path, "r+");
    if (fp == NULL) {
        roce_err("Open configure file fail errno[%d] real_conf_path[%s]", errno, real_conf_path);
        return UDA_TOOL_SYS_READ_FILE_ERR;
    }

    ret = flock(fileno(fp), LOCK_EX);
    if (ret) {
        roce_err("hccn.conf lock fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        ret = UDA_TOOL_SYS_READ_FILE_ERR;
        goto out;
    }

    ret = fseek(fp, 0, SEEK_SET);
    if (ret) {
        roce_err("hccn.conf fseek fd[%d] failed! ret[%d] errno[%d]", fileno(fp), ret, errno);
        ret = UDA_TOOL_SYS_READ_FILE_ERR;
        goto unlock;
    }

    if (route_op == READ_TO_DEL_IP_ROUTE_NOT_SAME_SEGMENT) {
        ret = tool_trans_config_to_ip_route(fp, param, ip_param);
    } else {
        ret = tool_trans_config_to_route(fp, param, route_op, ip_param);
    }

unlock:
    if (flock(fileno(fp), LOCK_UN)) {
        roce_err("hccn.conf unlock failed! (ret=%d; errno=%d)", ret, errno);
    }
out:
    ret_val = fclose(fp);
    if (ret_val) {
        roce_warn("Fclose fail. (ret_val=%d; errno=%d)", ret_val, errno);
    }
    fp = NULL;
    return ret;
}


STATIC int tool_clear_route_table(struct tool_param *param, char info[], unsigned int len)
{
    int ret;
    struct ds_route_table_value ip_param = {0};

    ret = tool_read_hccn_conf_handle_action(param, READ_TO_CLEAR, ip_param);
    if (ret) {
        roce_err("tool_read_hccn_conf: read config and clear failed! ret is [%d]", ret);
        return ret;
    }
    return 0;
}

STATIC int tool_get_route_table(int argc, char **argv, struct tool_param *param)
{
    int ret;

    char *info = (char *)calloc(MAX_ROUTE_TABLE_LEN, sizeof(char));
    if (info == NULL) {
        roce_err("tool_route_table_cmd_execute calloc fail.");
        return UDA_TOOL_NO_MEM_ERR;
    }
    if (argc != ONE_VALUE) {
        free(info);
        info = NULL;
        roce_err("tool_route_table_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    ret = dsmi_get_route_table(param->logic_id, 0, info, MAX_ROUTE_TABLE_LEN);
    if (ret) {
        free(info);
        info = NULL;
        roce_err("dsmi get route fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
        ret = (ret == UDA_TOOL_SYS_BUSY_ERR) ? UDA_TOOL_SYS_BUSY_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
        return ret;
    }

    info[MAX_ROUTE_TABLE_LEN - 1] = '\0';
    DSMI_PRINT_INFO("Routing table:");
    DSMI_PRINT_INFO("%s", info);

    free(info);
    info = NULL;
    return ret;
}

STATIC int tool_check_argc_clear_route(int argc, char **argv, struct tool_param *param)
{
    int ret;
    char info[MAX_CMD_PAYLOAD_LEN] = {0};

    if (argc != ONE_VALUE) {
        roce_err("tool_route_table_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }
    LOG_CONFIG("start to clear route of logic_id[%d]", param->logic_id);

    ret = tool_clear_route_table(param, info, MAX_CMD_PAYLOAD_LEN);
    if (ret) {
        roce_err("tool_clear_route_table fail logic_id[%d] ret[%d]", param->logic_id, ret);
        return ret;
    }
    return ret;
}

int tool_route_table_cmd_execute_ipv4(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_route_table(argc, argv, param);
        if (ret) {
            roce_err("tool_get_route_table err argc[%d] ret is [%d]", argc, ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-a", strlen("-a") + 1)) {
        if (argc != SEVEN_VALUE) {
            roce_err("tool_route_table_cmd_execute add route err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }

        ret = tool_add_route_table(argv, param, true);
        if (ret) {
            roce_err("tool_add_route_table fail logic_id[%d] result [%d]", param->logic_id, ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-d", strlen("-d") + 1)) {
        if (argc != FIVE_VALUE) {
            roce_err("tool_route_table_cmd_execute delete route err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }

        ret = tool_del_route_table(argv, param, false);
        if (ret) {
            roce_err("tool_del_route_table fail logic_id[%d] result [%d]", param->logic_id, ret);
            return ret;
        }
    } else if (!strncmp(argv[0], "-c", strlen("-c") + 1)) {
        ret = tool_check_argc_clear_route(argc, argv, param);
        if (ret) {
            roce_err("tool_check_argc_clear_route err argc[%d], ret is [%d]", argc, ret);
            return ret;
        }
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

int tool_route_table_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc == 0) {
        roce_err("tool_route_table_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (is_ipv6_cmd(&argc, &argv)) {
        if (is_atlas_9000_a3(param)) {
            roce_err("Ipv6 atlas_9000_a3 command is not supported.");
            return UDA_TOOL_OP_NOT_SUPPORT_IPV6_ERR;
        }
        ret = tool_route_table_cmd_execute_ipv6(argc, argv, param);
    } else {
        ret = tool_route_table_cmd_execute_ipv4(argc, argv, param);
    }
    return ret;
}

int tool_pci_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    char info[MAX_CMD_PAYLOAD_LEN] = {0};

    if (argc != 1) {
        roce_err("tool_pci_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (strncmp(argv[0], "-g", strlen("-g") + 1)) {
        roce_err("tool_pci_cmd_execute invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    param->get_cmd_flag = true;
    ret = dsmi_get_pci_info(param->logic_id, 0, info, MAX_CMD_PAYLOAD_LEN);
    if (ret) {
        roce_err("dsmi get pci fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    info[MAX_CMD_PAYLOAD_LEN - 1] = '\0';
    DSMI_PRINT_INFO("pci:");
    DSMI_PRINT_INFO("%s", info);

    return 0;
}

int tool_get_xsfp_id_map_index(struct ds_optical_info *info, unsigned int *id_map_idx)
{
    unsigned int i;

    for (i = 0; i < sizeof(g_xsfp_id_map) / sizeof(g_xsfp_id_map[0]); i++) {
        if (g_xsfp_id_map[i].id == info->base_info.xsfp_identifier) {
            *id_map_idx = i;
            return 0;
        }
    }

    /* if no entry matched, return the NA entry, which is defined as the last entry in the array */
    *id_map_idx = i - 1;
    return -EINVAL;
}

STATIC void tool_show_additional_optical_invalid_info()
{
    TOOL_PRINT_INFO("Vcc                  : %s", "NA");
    TOOL_PRINT_INFO("Tx Power             : %s", "NA");
    TOOL_PRINT_INFO("Rx Power             : %s", "NA");
    TOOL_PRINT_INFO("Vcc High Thres       : %s", "NA");
    TOOL_PRINT_INFO("Vcc Low Thres        : %s", "NA");
    TOOL_PRINT_INFO("Temp High Thres      : %s", "NA");
    TOOL_PRINT_INFO("Temp Low Thres       : %s", "NA");
    TOOL_PRINT_INFO("TxPower High Thres   : %s", "NA");
    TOOL_PRINT_INFO("TxPower Low Thres    : %s", "NA");
    TOOL_PRINT_INFO("RxPower High Thres   : %s", "NA");
    TOOL_PRINT_INFO("RxPower Low Thres    : %s", "NA");
}

STATIC void tool_show_additional_optical_info_ext(struct ds_optical_info *info, const int sflag)
{
    TOOL_PRINT_INFO("Tx LoL Flag          : 0x%x", info->additional_info.tx_lol);
    TOOL_PRINT_INFO("Rx LoL Flag          : 0x%x", info->additional_info.rx_lol);
    tool_show_additional_optical_snr_info(info, sflag);
    tool_show_additional_optical_physical_code_info(info);
    tool_show_vendor_rev(info);
    tool_show_optical_specification_compliance(info);
}

STATIC void tool_show_txbias_info(struct ds_optical_info *info, const int sflag)
{
    float tx_bias0, tx_bias1 = 0;
 
    // dr4 apsel model lane is 0x42, sflag == 0 indicates the first two lanes.
    if (info->dr4_flag == 0x42) {
        if (sflag == 0) {
            tx_bias0 = (float)((info->additional_info.tx_bias[CHANNEL_0_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_0_L]) / OPTICAL_BIAS_DEVISOR;
            tx_bias1 = (float)((info->additional_info.tx_bias[CHANNEL_1_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_1_L]) / OPTICAL_BIAS_DEVISOR;
        } else {
            tx_bias0 = (float)((info->additional_info.tx_bias[CHANNEL_2_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_2_L]) / OPTICAL_BIAS_DEVISOR;
            tx_bias1 = (float)((info->additional_info.tx_bias[CHANNEL_3_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_3_L]) / OPTICAL_BIAS_DEVISOR;
        }
        TOOL_PRINT_INFO("Tx Bias0             : %.4f mA", tx_bias0);
        TOOL_PRINT_INFO("Tx Bias1             : %.4f mA", tx_bias1);
        TOOL_PRINT_INFO("Tx Bias2             : %s", "NA");
        TOOL_PRINT_INFO("Tx Bias3             : %s", "NA");
    } else {
        TOOL_PRINT_INFO("Tx Bias0             : %.4f mA", (float)((info->additional_info.tx_bias[CHANNEL_0_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_0_L + sflag]) / OPTICAL_BIAS_DEVISOR);
        TOOL_PRINT_INFO("Tx Bias1             : %.4f mA", (float)((info->additional_info.tx_bias[CHANNEL_1_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_1_L + sflag]) / OPTICAL_BIAS_DEVISOR);
        TOOL_PRINT_INFO("Tx Bias2             : %.4f mA", (float)((info->additional_info.tx_bias[CHANNEL_2_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_2_L + sflag]) / OPTICAL_BIAS_DEVISOR);
        TOOL_PRINT_INFO("Tx Bias3             : %.4f mA", (float)((info->additional_info.tx_bias[CHANNEL_3_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_bias[CHANNEL_3_L + sflag]) / OPTICAL_BIAS_DEVISOR);
    }
}
 
STATIC void tool_show_power_info(struct ds_optical_info *info, const int sflag)
{
    float tx_power0, rx_power0 = 0;
    float tx_power1, rx_power1 = 0;

    // dr4 apsel model lane is 0x84 or 0x42
    if (info->dr4_flag == 0x42) {
        if (sflag == 0) {
            tx_power0 = (float)((info->additional_info.tx_power[CHANNEL_0_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_0_L]) / OPTICAL_POWER_DEVISOR;
            rx_power0 = (float)((info->additional_info.rx_power[CHANNEL_0_H] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_0_L]) / OPTICAL_POWER_DEVISOR;
            tx_power1 = (float)((info->additional_info.tx_power[CHANNEL_1_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_1_L]) / OPTICAL_POWER_DEVISOR;
            rx_power1 = (float)((info->additional_info.rx_power[CHANNEL_1_H] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_1_L]) / OPTICAL_POWER_DEVISOR;
        } else {
            tx_power0 = (float)((info->additional_info.tx_power[CHANNEL_2_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_2_L]) / OPTICAL_POWER_DEVISOR;
            rx_power0 = (float)((info->additional_info.rx_power[CHANNEL_2_H] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_2_L]) / OPTICAL_POWER_DEVISOR;
            tx_power1 = (float)((info->additional_info.tx_power[CHANNEL_3_H] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_3_L]) / OPTICAL_POWER_DEVISOR;
            rx_power1 = (float)((info->additional_info.rx_power[CHANNEL_3_H] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_3_L]) / OPTICAL_POWER_DEVISOR;
        }
        TOOL_PRINT_INFO("Tx Power0            : %.4f mW", tx_power0);
        TOOL_PRINT_INFO("Rx Power0            : %.4f mW", rx_power0);
        TOOL_PRINT_INFO("Tx Power1            : %.4f mW", tx_power1);
        TOOL_PRINT_INFO("Rx Power1            : %.4f mW", rx_power1);
        TOOL_PRINT_INFO("Tx Power2            : %s", "NA");
        TOOL_PRINT_INFO("Rx Power2            : %s", "NA");
        TOOL_PRINT_INFO("Tx Power3            : %s", "NA");
        TOOL_PRINT_INFO("Rx Power3            : %s", "NA");
    } else {
        TOOL_PRINT_INFO("Tx Power0            : %.4f mW", (float)((info->additional_info.tx_power[CHANNEL_0_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_0_L + sflag]) / OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("Rx Power0            : %.4f mW", (float)((info->additional_info.rx_power[CHANNEL_0_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_0_L + sflag]) / OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("Tx Power1            : %.4f mW", (float)((info->additional_info.tx_power[CHANNEL_1_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_1_L + sflag]) / OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("Rx Power1            : %.4f mW", (float)((info->additional_info.rx_power[CHANNEL_1_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_1_L + sflag]) / OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("Tx Power2            : %.4f mW", (float)((info->additional_info.tx_power[CHANNEL_2_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_2_L + sflag]) / OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("Rx Power2            : %.4f mW", (float)((info->additional_info.rx_power[CHANNEL_2_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_2_L + sflag]) / OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("Tx Power3            : %.4f mW", (float)((info->additional_info.tx_power[CHANNEL_3_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.tx_power[CHANNEL_3_L + sflag]) / OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("Rx Power3            : %.4f mW", (float)((info->additional_info.rx_power[CHANNEL_3_H + sflag] *
            MULTI_256) + (unsigned char)info->additional_info.rx_power[CHANNEL_3_L + sflag]) / OPTICAL_POWER_DEVISOR);
    }
}
 
STATIC void tool_show_additional_optical_info(struct ds_optical_info *info, const int sflag)
{
    if (info->present != TOOL_XSFP_PRESENT || info->temp == TEMP_INVALID || info->additional_info.voltage == 0) {
        tool_show_additional_optical_invalid_info();
    } else {
        TOOL_PRINT_INFO("Vcc                  : %.2f mV", (float)info->additional_info.voltage / OPTICAL_VCC_DEVISOR);
        tool_show_power_info(info, sflag);
        TOOL_PRINT_INFO("Vcc High Thres       : %.2f mV",
            (float)info->additional_info.vcc_high_threshold / OPTICAL_VCC_DEVISOR);
        TOOL_PRINT_INFO("Vcc Low Thres        : %.2f mV",
            (float)info->additional_info.vcc_low_threshold / OPTICAL_VCC_DEVISOR);
        TOOL_PRINT_INFO("Temp High Thres      : %d C", info->additional_info.temp_high_threshold);
        TOOL_PRINT_INFO("Temp Low Thres       : %d C", (int8_t)(info->additional_info.temp_low_threshold & 0xFF));
        TOOL_PRINT_INFO("TxPower High Thres   : %.4f mW", (float)info->additional_info.tx_power_high_threshold /
            OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("TxPower Low Thres    : %.4f mW", (float)info->additional_info.tx_power_low_threshold /
            OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("RxPower High Thres   : %.4f mW", (float)info->additional_info.rx_power_high_threshold /
            OPTICAL_POWER_DEVISOR);
        TOOL_PRINT_INFO("RxPower Low Thres    : %.4f mW", (float)info->additional_info.rx_power_low_threshold /
            OPTICAL_POWER_DEVISOR);
        tool_show_txbias_info(info, sflag);
        TOOL_PRINT_INFO("Tx Los Flag          : 0x%x", info->additional_info.tx_los);
        TOOL_PRINT_INFO("Rx Los Flag          : 0x%x", info->additional_info.rx_los);
#ifdef HCCN_TOOL_SHOW_EXT
        tool_show_additional_optical_info_ext(info, sflag);
#endif
    }
}

// sflag is offset for choose between first 4 lanes and last 4 lanes
void tool_show_optical_info(struct ds_optical_info *info, unsigned int id_map_idx, const int sflag)
{
    TOOL_PRINT_INFO("optical info:");
    TOOL_PRINT_INFO("present              : %s",
                    (info->present == TOOL_XSFP_PRESENT) ? "present" : "not present");
    if (info->temp == TEMP_INVALID) {
        TOOL_PRINT_INFO("temperature          : not supported");
    } else if (info->present != TOOL_XSFP_PRESENT) {
        TOOL_PRINT_INFO("temperature          : NA");
    } else if (info->temp == TEMP_FAULT) {
        TOOL_PRINT_INFO("temperature          : get failed");
    } else {
        TOOL_PRINT_INFO("temperature          : %d C", info->temp);
    }
    TOOL_PRINT_INFO("high power enable reg: %s",
                    (info->high_power_enable == TOOL_XSFP_HIGH_POWER_ENABLED) ? "enabled" : "not enabled");
    info->base_info.vendor_name[XSFP_NAME_LEN - 1] = '\0';
    TOOL_PRINT_INFO("vendor name          : %s", info->base_info.vendor_name);
    info->base_info.vendor_pn[XSFP_PN_LEN - 1] = '\0';
    TOOL_PRINT_INFO("vendor part number   : %s", info->base_info.vendor_pn);
    info->base_info.vendor_sn[XSFP_SN_LEN - 1] = '\0';
    TOOL_PRINT_INFO("vendor serial number : %s", info->base_info.vendor_sn);
    TOOL_PRINT_INFO("vendor org unique id : 0x%x 0x%x 0x%x",
        (unsigned char)info->base_info.vendor_oui[VENDOR_OUI_FIR],
        (unsigned char)info->base_info.vendor_oui[VENDOR_OUI_MID],
        (unsigned char)info->base_info.vendor_oui[VENDOR_OUI_END]);
    TOOL_PRINT_INFO("xsfp identifier      : %s", g_xsfp_id_map[id_map_idx].id_str);
    TOOL_PRINT_INFO("xsfp wave length     : %d nm", info->base_info.wavelength);
    info->base_info.date_code[XSFP_DATACODE_LEN - 1] = '\0';
    TOOL_PRINT_INFO("manufact date code   : %s", info->base_info.date_code);
    tool_show_additional_optical_info(info, sflag);
}

int atlas_900_a3_superpod_get_cooperative_phy_id(int phy_id)
{
    return (phy_id < MAX_FRONT_NPU_NUM) ? (phy_id + MAX_FRONT_NPU_NUM) : (phy_id - MAX_FRONT_NPU_NUM);
}

int atlas_900_a3_superpod_phy_id_convert(int phy_id)
{
    int parity_flag = 0, group_flag = 0, tmp_phy_id;

    if ((phy_id % EVEN_NUM) != 0) {
        parity_flag = 1;        // 1 indicates odd device
    }
    if ((phy_id / MAX_FRONT_NPU_NUM) != 0) {
        group_flag = 1;         // 1 indicates the rear 8P
    }
    
    if ((parity_flag == 1) && (group_flag == 0)) {
        tmp_phy_id = phy_id + MAX_FRONT_NPU_NUM;
    } else if ((parity_flag == 0) && (group_flag == 1)) {
        tmp_phy_id = phy_id - MAX_FRONT_NPU_NUM;
    } else {
        tmp_phy_id = phy_id;
    }
    return tmp_phy_id;
}

int ATLAS_900_A3_SUPERPOD_logic_id_convert(int phy_id)
{
    int ret, convert_phy_id;
    unsigned int logic_id = 0;

    convert_phy_id = atlas_900_a3_superpod_phy_id_convert(phy_id);
    ret = dsmi_get_logicid_from_phyid(convert_phy_id, &logic_id);
    if (ret) {
        roce_err("DSMI get logicid from phyid fail. (ret=%d; phy_id=%d; convert_phy_id=%d)",
            ret, phy_id, convert_phy_id);
        return INVALID_LOGIC_ID;
    }

    return (int)logic_id;
}

int tool_optical_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret = 0, logic_id = param->logic_id;

    if (argc == 0) {
        roce_err("tool_optical_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    // 天工不支持
    if (param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID || param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID_2) {
        roce_err("This device does not support optical cmd.");
        return UDA_TOOL_CMD_UNSUPPORT_ON_PRODUCT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen(argv[0]) + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_optical_info_handle(argc - 1, argv + 1, param);
        if (ret != 0) {
            roce_err("Func tool_get_optical_info_handle fail. (ret=%d; logic_id=%d)", ret, logic_id);
            return ret;
        }
#ifdef HCCN_TOOL_SHOW_EXT
    } else if (!strncmp(argv[0], "-t", strlen(argv[0]) + 1)) {
        ret = tool_set_optical_loopback(argc, argv, param);
        if (ret) {
            roce_err("tool_set_optical_loopback fail. (ret=%d; logic_id=%d)", ret, logic_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "-dump", strlen(argv[0]) + 1)) {
        ret = tool_dump_optical_info(argc - 1, argv + 1, param);
        if (ret != 0) {
            roce_err("dump_optical_info cmd fail. (ret=%d; logic_id=%d)", ret, logic_id);
            return ret;
        }
    } else if (!strncmp(argv[0], "-s", strlen(argv[0]) + 1)) {
        ret = tool_set_optical_mode(argc - 1, argv + 1, param);
        if (ret != 0) {
            roce_err("tool_set_optical_mode fail. (ret=%d; logic_id=%d)", ret, logic_id);
            return ret;
        }
#endif
    } else {
        roce_err("tool_optical_cmd_execute invalid operation");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return 0;
}

STATIC void tool_display_mac_info(const struct ds_port_stat_info* stat_info)
{
    DSMI_PRINT_INFO("mac_tx_mac_pause_num:%llu", stat_info->mac_tx_mac_pause_num);
    DSMI_PRINT_INFO("mac_rx_mac_pause_num:%llu", stat_info->mac_rx_mac_pause_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pkt_num:%llu", stat_info->mac_tx_pfc_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri0_pkt_num:%llu", stat_info->mac_tx_pfc_pri0_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri1_pkt_num:%llu", stat_info->mac_tx_pfc_pri1_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri2_pkt_num:%llu", stat_info->mac_tx_pfc_pri2_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri3_pkt_num:%llu", stat_info->mac_tx_pfc_pri3_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri4_pkt_num:%llu", stat_info->mac_tx_pfc_pri4_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri5_pkt_num:%llu", stat_info->mac_tx_pfc_pri5_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri6_pkt_num:%llu", stat_info->mac_tx_pfc_pri6_pkt_num);
    DSMI_PRINT_INFO("mac_tx_pfc_pri7_pkt_num:%llu", stat_info->mac_tx_pfc_pri7_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pkt_num:%llu", stat_info->mac_rx_pfc_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri0_pkt_num:%llu", stat_info->mac_rx_pfc_pri0_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri1_pkt_num:%llu", stat_info->mac_rx_pfc_pri1_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri2_pkt_num:%llu", stat_info->mac_rx_pfc_pri2_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri3_pkt_num:%llu", stat_info->mac_rx_pfc_pri3_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri4_pkt_num:%llu", stat_info->mac_rx_pfc_pri4_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri5_pkt_num:%llu", stat_info->mac_rx_pfc_pri5_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri6_pkt_num:%llu", stat_info->mac_rx_pfc_pri6_pkt_num);
    DSMI_PRINT_INFO("mac_rx_pfc_pri7_pkt_num:%llu", stat_info->mac_rx_pfc_pri7_pkt_num);
    DSMI_PRINT_INFO("mac_tx_total_pkt_num:%llu", stat_info->mac_tx_total_pkt_num);
    DSMI_PRINT_INFO("mac_tx_total_oct_num:%llu", stat_info->mac_tx_total_oct_num);
    DSMI_PRINT_INFO("mac_tx_bad_pkt_num:%llu", stat_info->mac_tx_bad_pkt_num);
    DSMI_PRINT_INFO("mac_tx_bad_oct_num:%llu", stat_info->mac_tx_bad_oct_num);
    DSMI_PRINT_INFO("mac_rx_total_pkt_num:%llu", stat_info->mac_rx_total_pkt_num);
    DSMI_PRINT_INFO("mac_rx_total_oct_num:%llu", stat_info->mac_rx_total_oct_num);
    DSMI_PRINT_INFO("mac_rx_bad_pkt_num:%llu", stat_info->mac_rx_bad_pkt_num);
    DSMI_PRINT_INFO("mac_rx_bad_oct_num:%llu", stat_info->mac_rx_bad_oct_num);
#ifdef HCCN_TOOL_SHOW_EXT_STAT
    DSMI_PRINT_INFO("mac_rx_fcs_err_pkt_num:%llu", stat_info->mac_rx_fcs_err_pkt_num);
#endif
}

STATIC void tool_display_roce_info(const struct ds_port_stat_info* stat_info)
{
    DSMI_PRINT_INFO("roce_rx_rc_pkt_num:%llu", stat_info->roce_rx_rc_pkt_num);
    DSMI_PRINT_INFO("roce_rx_all_pkt_num:%llu", stat_info->roce_rx_all_pkt_num);
    DSMI_PRINT_INFO("roce_rx_err_pkt_num:%llu", stat_info->roce_rx_err_pkt_num);
    DSMI_PRINT_INFO("roce_tx_rc_pkt_num:%llu", stat_info->roce_tx_rc_pkt_num);
    DSMI_PRINT_INFO("roce_tx_all_pkt_num:%llu", stat_info->roce_tx_all_pkt_num);
    DSMI_PRINT_INFO("roce_tx_err_pkt_num:%llu", stat_info->roce_tx_err_pkt_num);
    DSMI_PRINT_INFO("roce_cqe_num:%llu", stat_info->roce_cqe_num);
    DSMI_PRINT_INFO("roce_rx_cnp_pkt_num:%llu", stat_info->roce_rx_cnp_pkt_num);
    DSMI_PRINT_INFO("roce_tx_cnp_pkt_num:%llu", stat_info->roce_tx_cnp_pkt_num);
    DSMI_PRINT_INFO("roce_unexpected_ack_num:%llu", stat_info->roce_err_ack_num);
    DSMI_PRINT_INFO("roce_out_of_order_num:%llu", stat_info->roce_err_psn_num);
    DSMI_PRINT_INFO("roce_verification_err_num:%llu", stat_info->roce_verification_err_num);
    DSMI_PRINT_INFO("roce_qp_status_err_num:%llu", stat_info->roce_err_qp_status_num);
    DSMI_PRINT_INFO("roce_new_pkt_rty_num:%llu", stat_info->roce_new_pkt_rty_num);
#ifdef HCCN_TOOL_SHOW_EXT_STAT
    DSMI_PRINT_INFO("roce_ecn_db_num:%llu", stat_info->roce_ecn_db_num);
#endif
}

STATIC void tool_display_stat_info(const struct ds_port_stat_info* stat_info)
{
    DSMI_PRINT_INFO("packet statistics:");
    tool_display_mac_info(stat_info);
    tool_display_roce_info(stat_info);
    DSMI_PRINT_INFO("nic_tx_all_pkg_num:%llu", stat_info->nic_tx_all_pkg_num);
    DSMI_PRINT_INFO("nic_tx_all_oct_num:%llu", stat_info->nic_tx_all_oct_num);
    DSMI_PRINT_INFO("nic_rx_all_pkg_num:%llu", stat_info->nic_rx_all_pkg_num);
    DSMI_PRINT_INFO("nic_rx_all_oct_num:%llu", stat_info->nic_rx_all_oct_num);
}

int tool_stat_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    struct ds_port_stat_info stat_info = {0};

    if (argc != ONE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = dsmi_get_netdev_stat(param->logic_id, 0, &stat_info);
        if (ret) {
            roce_err("dsmi get stat fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
        tool_display_stat_info(&stat_info);
    } else if (!strncmp(argv[0], "-c", strlen("-c") + 1)) {
        LOG_CONFIG("start to clear packet statistics of dev[%d]", param->logic_id);
        ret = dsmi_clear_netdev_stat(param->logic_id, 0);
        if (ret) {
            roce_err("dsmi clear stat fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

int tool_check_dev_health(int logic_id)
{
    int ret;
    unsigned int health = 0;
    unsigned int cnt = 0;
    do {
        cnt += 1;
        ret = dsmi_get_device_health(logic_id, &health);
        if (ret == 0) {
            break;
        } else if (cnt > MAX_HEALTH_CHECK_CNT) {
            roce_warn("DSMI get health timeout. (ret=%d)", ret);
            return UDA_DSMI_DEV_GET_HEALTH_TMOUT_ERR;
        }
        roce_warn("Device not ready. (ret=%d; logic_id=%d; check_cnt=%u)", ret, logic_id, cnt);
        sleep(1);
    }
#ifndef CONFIG_LLT
    while (1);
#else
    while (0);
#endif
    if (health == DEV_NO_EXIST) {
        roce_err("Dev not exist. (logic_id=%d; health=%d)", logic_id, health);
        return UDA_DSMI_DEV_NOT_EXIST_ERR;
    }
    return ret;
}

int tool_get_dev_list_info(struct dev_list_info *info)
{
    int i, ret;

    ret = dsmi_get_device_count(&info->dev_num);
    if (ret != 0) {
        roce_err("dsmi_get_device_count fail! ret=%d", ret);
        return UDA_DSMI_EXE_ERR;
    }

    if ((info->dev_num > DEV_LIST_MAX) || (info->dev_num < 0)) {
        roce_err("dev_num[%d] out the except num [0:%d]", info->dev_num, DEV_LIST_MAX);
        return UDA_DSMI_EXE_ERR;
    }

    ret = dsmi_list_device(info->logic_list, info->dev_num);
    if (ret) {
        roce_err("dsmi_list_device fail! ret=%d, dev_num=%d", ret, info->dev_num);
        return UDA_DSMI_EXE_ERR;
    }
    for (i = 0; i < info->dev_num; i++) {
        ret = tool_check_dev_health(info->logic_list[i]);
        if (ret) {
            roce_err("tool_check_dev_health fail! ret=%d, logic_id=%d", ret, info->logic_list[i]);
            return ret;
        }
        ret = dsmi_get_phyid_from_logicid(info->logic_list[i], (unsigned int *)(void *)&info->phy_list[i]);
        if (ret) {
            roce_err("dsmi_get_phyid_from_logicid fail! ret=%d, logic_id=%d", ret, info->logic_list[i]);
            return UDA_DSMI_EXE_ERR;
        }
    }
    return 0;
}

int tool_process_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret, found = 0;

    if (argc != ONE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = dsmi_get_device_process(param->logic_id, 0, &found, sizeof(int));
        if (ret) {
            roce_err("dsmi_get_device_process failed, logic_id[%d]", param->logic_id);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
    } else {
        roce_err("invalid option");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    if (found == 0) {
        TOOL_PRINT_INFO("device hccp process: not exist");
    } else {
        TOOL_PRINT_INFO("device hccp process: exist");
    }

    return ret;
}

int tool_cfg_status_set(struct tool_param *param, unsigned int status)
{
    return dsmi_set_cfg_status(param->logic_id, status);
}

int tool_cfg_status_get(int argc, char **argv, struct tool_param *param)
{
    unsigned int status;
    int ret;

    if (argc != 1) {
        roce_err("err argc, (argc=%d)", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    ret = dsmi_get_cfg_status(param->logic_id, &status);
    if (ret != 0) {
        roce_err("get network status fail, (ret=%d)", ret);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    switch (status) {
        case TOOL_NET_CFG_NONE:
            TOOL_PRINT_INFO("config status:NONE");      /* not config */
            break;
        case TOOL_NET_CFG_START:
            TOOL_PRINT_INFO("config status:START");     /* start to config and not finish */
            break;
        case TOOL_NET_CFG_FAIL:
            TOOL_PRINT_INFO("config status:FAIL");      /* config fail */
            break;
        case TOOL_NET_CFG_SUCCESS:
            TOOL_PRINT_INFO("config status:SUCCESS");   /* config success */
            break;
        default:
            TOOL_PRINT_INFO("config status:FAULT");     /* unexpected fault. Maybe software coding error */
            break;
    }

    return 0;
}

STATIC int tool_get_netdev_status(int argc, char **argv, struct tool_param *param)
{
    char *info = NULL;
    int ret;

    if (argc != ONE_VALUE) {
        roce_err("tool_netdev_status_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    info = (char *)calloc(MAX_NETDEV_STATUS_LEN, sizeof(char));
    if (info == NULL) {
        roce_err("tool_netdev_status_cmd_execute calloc fail.");
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = dsmi_get_netdev_status(param->logic_id, 0, info, MAX_NETDEV_STATUS_LEN);
    if (ret) {
        free(info);
        info = NULL;
        roce_err("dsmi get netdev status fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
        ret = (ret == UDA_TOOL_SYS_BUSY_ERR) ? UDA_TOOL_SYS_BUSY_ERR : dsmi_analysis_dsmi_ret_to_uda(ret);
        return ret;
    }

    info[MAX_NETDEV_STATUS_LEN - 1] = '\0';
    DSMI_PRINT_INFO("Netdev status:%s", info);

    free(info);
    info = NULL;
    return 0;
}

int tool_netdev_status_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    if (argc == 0) {
        roce_err("tool_netdev_status_cmd_execute err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = tool_get_netdev_status(argc, argv, param);
        if (ret) {
            roce_err("tool_get_netdev_status err argc[%d] ret is [%d]", argc, ret);
            return ret;
        }
    } else {
        roce_err("invalid option -- '%s'", argv[0]);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }
    return ret;
}

STATIC int parse_speed_param(struct generic_info *info, int *cur, int argc, char **argv)
{
    char *tmp_ptr = NULL;
    unsigned int speed;

    if ((*cur + 1) >= argc) {
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    speed = (unsigned int)strtoul(argv[*cur + 1], &tmp_ptr, STR_NUM_BASE);
    if (tmp_ptr == argv[*cur + 1] || *tmp_ptr != '\0') {
        roce_err("generic info option speed must be unsigned int, now is %u, tail is %s", speed, tmp_ptr);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    if (speed != GENERIC_SPEED_100G && speed != GENERIC_SPEED_200G) {
        roce_err("generic info option speed must be 200000 or 100000, now is %d", speed);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    info->speed = speed;
    *cur += 1;
    return UDA_EXE_SUCCESS;
}

STATIC int parse_static_speed_param(struct generic_info *info, int argc, char **argv)
{
    static struct generic_info_parse_param generic_info_param_arr[] = {
        {"static_speed", parse_speed_param},
        {NULL, NULL}
    };
    struct generic_info_parse_param *param_info = NULL;
    int i, ret;

    for (i = 0; i < argc; i++) {
        ret = UDA_PARAM_INVALID_ERR;
        for (param_info = generic_info_param_arr; param_info->parse_proc != NULL; param_info++) {
            if (strcmp(argv[i], param_info->param) == 0) {
                ret = param_info->parse_proc(info, &i, argc, argv);
                break;
            }
        }
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("Parse generic cmd failed, ret is [%d].", ret);
            return ret;
        }
    }

    return ret;
}

STATIC int tool_set_auto_adapt(struct tool_param *param, char *inbuf, int buflen)
{
    int ret = -EINVAL;

    if (buflen != AUTO_ADAPT_INBUFF_LEN) {
        roce_err("arg buflen not correct, buflen is %d!", buflen);
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    ret = sprintf_s(inbuf, buflen, "%s", "on");
    if (ret <= 0) {
        roce_err("generic info cmd sprintf auto_adapt failed!");
        return UDA_TOOL_NO_MEM_ERR;
    }

    ret = tool_double_check("[WARNING]Running this command may cause errors to other programs "
                            "that are using the network port. Please ensure that all other programs "
                            "are stopped before proceeding with this command.\n"
                            "Are you sure you want to continue?");
    if (ret) {
        return ret;
    }

    LOG_CONFIG("start to set auto_adapt speed of logic_id [%d]", param->logic_id);

    ret = dsmi_set_optical_auto_adapt(param->logic_id, inbuf, buflen);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("dsmi_set_optical_auto_adapt error[%d], phy_id[%d]",
            ret, param->phy_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = cfg_write_conf(param->phy_id, "auto_adapt", inbuf);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("write cfg error[%d], phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    ret = cfg_del_conf(param->phy_id, "static_speed");
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("del auto adapt cfg error[%d], phy_id[%d]", ret, param->phy_id);
        return ret;
    }

    return UDA_EXE_SUCCESS;
}

STATIC int tool_set_generic_info(int argc, char **argv, struct tool_param *param)
{
    char inbuf[AUTO_ADAPT_INBUFF_LEN] = {0};
    int ret = UDA_PARAM_OP_NOT_SUPPORT_ERR;
    char **argv_tmp = argv + 1;
    int argc_tmp = argc - 1;

    if (strncmp(argv_tmp[0], "static_speed", strlen("static_speed") + 1) == 0) {
        if (argc_tmp != TWO_VALUE) {
            roce_err("err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }
        // 非铜缆， 不让切速
        if (is_copper_cable(param->logic_id) != IS_COPPER) {
            roce_err("Not support fibre");
            return UDA_TOOL_CMD_UNSUPPORT_ON_MEDIA_ERR;
        }

        ret = tool_set_static_speed(argc_tmp, argv_tmp, param);
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("tool_set_static_speed error[%d], phy_id[%d], speed[%s]", ret, param->phy_id, argv[ARGC_ID_2]);
            return ret;
        }

        return 0;
    }

    if (strncmp(argv_tmp[0], "auto_adapt", strlen("auto_adapt") + 1) == 0) {
        if (argc_tmp != ONE_VALUE) {
            roce_err("err argc[%d]", argc);
            return UDA_PARAM_CMD_COUNT_ERR;
        }

        if (is_copper_cable(param->logic_id) == IS_COPPER) {
            roce_err("Not support cable[%x]", PIF_ATTR_COPPER);
            return UDA_TOOL_CMD_UNSUPPORT_ON_MEDIA_ERR;
        }
        ret = tool_set_auto_adapt(param, inbuf, AUTO_ADAPT_INBUFF_LEN);
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("tool_set_auto_adapt error[%d], phy_id[%d]", ret, param->phy_id);
            return ret;
        }

        return 0;
    }

    return UDA_PARAM_OP_NOT_SUPPORT_ERR;
}

int tool_turn_off_auto_adapt(struct tool_param *param)
{
    char auto_adapt_flag[AUTO_ADAPT_INBUFF_LEN] = {0};
    char auto_adapt[AUTO_ADAPT_INBUFF_LEN] = {0};
    int ret;

    ret = cfg_read_conf(param->phy_id, "auto_adapt", auto_adapt_flag, sizeof(auto_adapt_flag));
    if (ret == 0) {
        ret = sprintf_s(auto_adapt, AUTO_ADAPT_INBUFF_LEN, "%s", "off");
        if (ret <= 0) {
            roce_err("Generic info cmd sprintf auto_adapt failed!");
            return UDA_TOOL_NO_MEM_ERR;
        }

        LOG_CONFIG("start to set auto_adapt speed of logic_id [%d]", param->logic_id);
        ret = dsmi_set_optical_auto_adapt(param->logic_id, auto_adapt, AUTO_ADAPT_INBUFF_LEN);
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("dsmi_set_optical_auto_adapt turn off error[%d], phy_id[%d]",
                ret, param->phy_id);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }

        LOG_PROMPT("Static_speed exclusive with auto_adapt, turn off auto_adapt automatically!");

        ret = cfg_del_conf(param->phy_id, "auto_adapt");
        if (ret != UDA_EXE_SUCCESS) {
            roce_err("del auto adapt cfg error[%d], phy_id[%d]", ret, param->phy_id);
            return ret;
        }
    }
    return ret;
}

int tool_set_static_speed(int argc, char **argv, struct tool_param *param)
{
    struct generic_info info = {GENERIC_INFO_SPEED_UNKNOWN};
    char auto_adapt_flag[AUTO_ADAPT_INBUFF_LEN] = {0};
    char auto_adapt[AUTO_ADAPT_INBUFF_LEN] = {0};
    char inbuf[GENERIC_INFO_INBUFF_LEN] = {0};
    int ret;

    ret = parse_static_speed_param(&info, argc, argv);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("parse_static_speed_param failed, ret [%d]", ret);
        return ret;
    }

    ret = tool_double_check("[WARNING]Running this command may cause errors to other programs "
                            "that are using the network port. Please ensure that all other programs "
                            "are stopped before proceeding with this command.\n"
                            "Are you sure you want to continue?");
    if (ret) {
        return ret;
    }

    ret = tool_turn_off_auto_adapt(param);
    if ((ret != 0) && (ret != UDA_TOOL_SYS_RD_FILE_NOT_FOUND)) {
        roce_err("auto adapt cfg_read_conf failed: logic_id[%d] status[%s]", param->logic_id, "on");
        return ret;
    }

    ret = sprintf_s(inbuf, GENERIC_INFO_INBUFF_LEN, "%u", info.speed);
    if (ret <= 0) {
        roce_err("Generic info cmd sprintf inbuf failed!");
        return UDA_TOOL_NO_MEM_ERR;
    }

    LOG_CONFIG("start to set static_speed of logic_id [%d] speed [%u]", param->logic_id, info.speed);

    ret = dsmi_set_generic_info(param->logic_id, inbuf, GENERIC_INFO_INBUFF_LEN);
    if (ret != 0) {
        roce_err("Set generic info failed, ret[%d] logic_id[%d]", ret, param->logic_id);
        return dsmi_analysis_dsmi_ret_to_uda(ret);
    }

    ret = cfg_write_conf(param->phy_id, "static_speed", argv[1]);
    if (ret != UDA_EXE_SUCCESS) {
        roce_err("write cfg error[%d], phy_id[%d], speed[%s]", ret, param->phy_id, argv[1]);
        return ret;
    }

    return ret;
}

int tool_generic_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;

    // 天工, 天成, 910A3_A+X， 910A3_A+K不支持
    if (param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID || param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID_2 ||
        param->mainboard_id == ATLAS_900_A3_MAINBOARD_ID_1 || param->mainboard_id == ATLAS_900_A3_MAINBOARD_ID_2 ||
        param->mainboard_id == ATLAS_900_A3_MAINBOARD_A_X || param->mainboard_id == ATLAS_900_A3_MAINBOARD_A_K) {
        roce_err("This device does not support this function.");
        return UDA_TOOL_CMD_UNSUPPORT_ON_PRODUCT_ERR;
    }

    if ((argc != TWO_VALUE) && (argc != THREE_VALUE)) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-s", strlen("-s") + 1)) {
        ret = tool_set_generic_info(argc, argv, param);
        if (ret) {
            roce_err("tool_set_generic_info failed, ret [%d]", ret);
        }
    } else {
        roce_err("Generic info cmd invalid operation.");
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

STATIC void tool_display_link_his_stat(int phy_id, const struct ds_link_his_stat *link_his_stat)
{
    struct tm *tblock;
    size_t len;
    char *str;
    int i;

    tblock = localtime((const time_t *)(void *)(&link_his_stat->cur_tv_sec));
    (void)fprintf(stdout, "[devid %d]current time        : %s", phy_id, asctime(tblock));
    (void)fprintf(stdout, "[devid %d]link up count       : %llu\n", phy_id, link_his_stat->link_up_cnt);
    (void)fprintf(stdout, "[devid %d]link down count     : %llu\n", phy_id, link_his_stat->link_down_cnt);
    if (link_his_stat->stat_cnt > 0) {
        (void)fprintf(stdout, "[devid %d]link change records :\n", phy_id);
    } else {
        (void)fprintf(stdout, "[devid %d]link change records : NA\n", phy_id);
    }

    for (i = (int)(link_his_stat->stat_cnt - 1); (i >= 0 && i < LINK_STAT_MAX_IDX); i--) {
        tblock = localtime((const time_t *)(void *)(&link_his_stat->stat[i].link_tv_sec));
        str = asctime(tblock);
        len = strlen(str);
        str[len - 1] = '\0'; // replace '\n'
        (void)fprintf(stdout, "[devid %d]    %s    %s\n", phy_id, str,
            (link_his_stat->stat[i].link_status ? "LINK UP" : "LINK DOWN"));
    }
}

int tool_link_stat_cmd_execute(int argc, char **argv, struct tool_param *param)
{
    int ret;
    struct ds_link_his_stat link_his_stat = {0};

    if (argc != ONE_VALUE) {
        roce_err("err argc[%d]", argc);
        return UDA_PARAM_CMD_COUNT_ERR;
    }

    if (!strncmp(argv[0], "-g", strlen("-g") + 1)) {
        param->get_cmd_flag = true;
        ret = dsmi_get_link_his_stat(param->logic_id, 0, &link_his_stat);
        if (ret) {
            roce_err("dsmi get link history stat fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
        tool_display_link_his_stat(param->phy_id, &link_his_stat);
    } else if (!strncmp(argv[0], "-c", strlen("-c") + 1)) {
        LOG_CONFIG("start to clear link history statistics of dev[%d]", param->logic_id);
        ret = dsmi_clear_link_his_stat(param->logic_id, 0);
        if (ret) {
            roce_err("dsmi clear stat fail logic_id[%d] port[%d] ret[%d]", param->logic_id, 0, ret);
            return dsmi_analysis_dsmi_ret_to_uda(ret);
        }
    } else {
        roce_err("invalid option -- '%s'", argv[0]);
        return UDA_PARAM_OP_NOT_SUPPORT_ERR;
    }

    return ret;
}

int tool_double_check(char *info)
{
    int echo;
 
    if (!g_recovering) {
        TOOL_PRINT_INFO("%s(y/n)", info);
        echo = getchar();
        if ((echo != 'y') && (echo != 'Y')) {
            roce_info("User aborts command");
            return UDA_TOOL_USER_ABORT_CMD_ERR;
        }
        echo = getchar();
        if (echo != '\n') {
            roce_info("User aborts command");
            return UDA_TOOL_USER_ABORT_CMD_ERR;
        }
    }
    return 0;
}

