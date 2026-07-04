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
#include <getopt.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdbool.h>
#include "securec.h"
#include "cmd.h"
#include "tool.h"
#include "cfg.h"
#include "dsmi_common_interface.h"
#include "log.h"

#define CFG_OPTION "-cfg"
#define RECOVERY_OPTION "recovery"
#define STATUS_OPTION "status"
#define CFG_OPTION_LEN 4
#define RECOVERY_OPTION_LEN 8
#define STATUS_OPTION_LEN 6
#define MAX_ARG_LEN 128

struct cmd_info g_cmd_list[MAX_CMD_LIST] = {
    {
        "-i", "devid", "-ip", tool_ip_cmd_execute, "ip cfg cmd",
#ifdef HCCN_TOOL_ADAPT_IPV6
        "   [-inet6]             : use IPv6, when not specified default is IPv4\n"
#endif
        "   [-s]                 : set ip cfg \n"
        "       address %s       : set IPv4 ip address, such as x.x.x.x\n"
        "       netmask %s       : set IPv4 ip netmask, such as x.x.x.x\n"
#ifdef HCCN_TOOL_ADAPT_IPV6
        "       ipv6_address  %s : set IPv6 ip address, such as x:x:x:x:x:x:x:x\n"
        "       prefix_length %d : set prefix length of IPv6 address, [0 ~ 128]\n"
#endif
        "   [-g]                 : get ip address and netmask/prefix_length \n"
    },
    {
        "-i", "devid", "-gateway", tool_gateway_cmd_execute, "gateway cfg cmd",
#ifdef HCCN_TOOL_ADAPT_IPV6
        "   [-inet6]            : use IPv6, when not specified default is IPv4\n"
#endif
        "   [-s]                : set gateway cfg \n"
        "       gateway %s      : set IPv4 gateway, such as x.x.x.x\n"
#ifdef HCCN_TOOL_ADAPT_IPV6
        "       ipv6_gateway %s : set IPv6 gateway, such as x:x:x:x:x:x:x:x\n"
#endif
        "   [-g]                : get gateway address \n"
    },
    {
        "-i", "devid", "-netdetect", tool_netdetect_cmd_execute, "net detect cfg cmd",
#ifdef HCCN_TOOL_ADAPT_IPV6
        "   [-inet6]            : use IPv6, when not specified default is IPv4\n"
#endif
        "   [-s]                : set net detect cfg \n"
        "       address %s      : set net detect IPv4 ip address, such as x.x.x.x\n"
#ifdef HCCN_TOOL_ADAPT_IPV6
        "       ipv6_address %s : set net detect IPv6 ip address, such as x:x:x:x:x:x:x:x\n"
#endif
        "   [-g]                : get net detect cfg \n"
    },
    {
        "-i", "devid", "-lldp", tool_lldp_cmd_execute, "lldp cfg cmd",
        "   [-g]        : get lldp cfg \n"
    },
#ifdef HCCN_TOOL_SHOW_EXT
    {
        "-i", "devid", "-local_lldp", tool_local_lldp_cmd_execute, "local lldp cfg cmd",
        "   [-g]        : get local lldp cfg \n"
        "   [-s]            : set local lldp port id tlv info\n"
        "       subtype %s  : subtype for specifying cmd type\n"
        "                     set mac for display mac address, set ifname for ifname number\n"
    },
#endif
    {
        "-i", "devid", "-mac", tool_mac_cmd_execute, "mac cfg cmd",
        "   [-s]        : set mac cfg\n"
        "       mac %s  : set mac address, such as xx:xx:xx:xx:xx:xx\n"
        "   [-g]        : get mac cfg\n"
    },
    {
        "-i", "devid", "-cfg", tool_cfg_cmd_execute, "cfg cmd",
        "   recovery    : recovery cfg \n"
        "   status      : config status \n"
    },
    {
        "-i", "devid", "-link", tool_link_cmd_execute, "link related cmd",
        "   [-s]                   : set the eth ports link status\n"
        "       down               : shut down eth port \n"
        "       up                 : start up eth port \n"
#ifdef HCCN_TOOL_SHOW_EXT
        "       down_fault_time %d : set linkdown warning filter time (0~3s)\n"
#endif
        "   [-g]                   : get the eth ports link status, UP or DOWN \n"
#ifdef HCCN_TOOL_SHOW_EXT
        "       [down_fault_time]    : get linkdown warning filter time \n"
#endif
    },
    {
        "-i", "devid", "-dscp_to_tc", tool_dscp_cmd_execute, "dscp to tc cmd",
        "   [-s]        : set dscp to tc map \n"
        "       dscp %u : set dscp value, [0 ~ 63] \n"
        "       tc   %u : set tc value, [0 ~ 3] \n"
        "   [-g]        : get the all dscp to tc map info \n"
        "       [dscp %u] : get the specify dscp of tc map info, [0 ~ 63] \n"
    },
    {
        "-i", "devid", "-shaping", tool_shaping_cmd_execute, "cfg shaper port bw limit cmd",
        "   [-s]        : set shaper port bw limit \n"
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
        "       bw_limit %d : set port bw limit rate, from 10000Mbps to 200000Mbps \n"
#else
        "       bw_limit %d : set port bw limit rate, from 10000Mbps to bw_max(use -g cmd to get bw_max) \n"
#endif
        "   [-g]        : get shaper port bw limit & max bw capability \n"
    },
    {
        "-i", "devid", "-mtu", tool_mtu_cmd_execute, "mtu cfg cmd",
        "   [-s]        : set mtu cfg \n"
        #ifdef HCCN_TOOL_SHOW_EXT_V2
        "       size %d : set mtu size, ETH from 68 to 9702, RoH from 68 to 4192\n"
        #else
        "       size %d : set mtu size, ETH from 68 to 9702\n"
        #endif
        "   [-g]        : get mtu cfg\n"
    },
    {
        "-i", "devid", "-net_health", tool_net_health_cmd_execute, "net health cmd",
        "   [-g]        : get net health status\n"
    },
    {
        "-i", "devid", "-arp", tool_arp_table_cmd_execute, "arp table cmd",
        "   [-g]        : get arp table\n"
        "   [-a]        : add arp table\n"
        "        dev %s : eth device, such as eth0\n"
        "         ip %s : ip address, such as x.x.x.x\n"
        "        mac %s : mac address, such as xx:xx:xx:xx:xx:xx\n"
        "   [-d]        : del arp table\n"
        "        dev %s : eth device, such as eth0\n"
        "         ip %s : ip address, such as x.x.x.x\n"
    },
    {
        "-i", "devid", "-route", tool_route_table_cmd_execute, "route table cmd",
#ifdef HCCN_TOOL_ADAPT_IPV6
        "   [-inet6]             : use IPv6, when not specified default is IPv4\n"
#endif
        "   [-g]                 : get route table\n"
        "   [-a]                 : add route\n"
        "       address %s       : destination IPv4 address, such as x.x.x.x\n"
        "       netmask %s       : destination IPv4 netmask, such as x.x.x.x\n"
        "       gateway %s       : IPv4 gateway address, such as x.x.x.x\n"
#ifdef HCCN_TOOL_ADAPT_IPV6
        "       ipv6_address  %s : destination IPv6 address, such as x:x:x:x:x:x:x:x\n"
        "       prefix_length %d : prefix length of ipv6_address, [0 ~ 128]\n"
        "       next_address  %s : IPv6 next address, such as x:x:x:x:x:x:x:x\n"
#endif
        "   [-d]                 : del route\n"
        "       address %s       : destination IPv4 address, such as x.x.x.x\n"
        "       netmask %s       : destination IPv4 netmask, such as x.x.x.x\n"
#ifdef HCCN_TOOL_ADAPT_IPV6
        "       ipv6_address  %s : destination IPv6 address, such as x:x:x:x:x:x:x:x\n"
        "       prefix_length %d : prefix length of IPv6 address, [0 ~ 128]\n"
#endif
        "   [-c]                 : clear route\n"
    },
    {
        "-i", "devid", "-pci", tool_pci_cmd_execute, "pci table cmd",
        "   [-g]        : get device pci table\n"
    },
    {
        "-i", "devid", "-context", tool_roce_context_cmd_execute, "roce context cmd",
        "   [-g]        : get the roce context info\n"
        "       qpc %d  : get the specify qpc context info, [0 ~ 1048576]\n"
        "       aeqc %d : get the specify aeqc context info, [0 ~ 1048576]\n"
        "       ceqc %d : get the specify ceqc context info, [0 ~ 1048576]\n"
        "       cqc %d  : get the specify cqc context info, [0 ~ 1048576]\n"
        "       mpt %d  : get the specify mpt context info, [0 ~ 1048576]\n"
    },
    {
        "-i", "devid", "-reg", tool_reg_cmd_execute, "get reg cmd",
        "   [-g]        : get reg info \n"
        "   [-a]        : input the reg offset that you want to read\n"
        "       reg %x  : reg offset, range [0 ~ 0x0007ffff] and [0x10000000 ~ 0x11ffffff], "
        "the reg addr must be 4-byte aligned\n"
    },
    {
        "-i", "devid", "-optical", tool_optical_cmd_execute, "get optical info cmd",
        "   [-g]               : get optical info \n"
#ifdef HCCN_TOOL_SHOW_EXT
        "        [v2]            : get optical new version info \n"
        "        [dfx_cfg]       : get optical dfx info \n"
        "   [-t]               : set optical loopback \n"
        "        0             : cancel optical module loopback \n"
        "        1             : set host side input loopback \n"
        "        2             : set media side output loopback \n"
        "        3             : set host side output loopback \n"
        "        4             : set media side input loopback \n"
        "   [-dump]            : dump optical EEPROM reg info \n"
        "        all           : get all EEPROM information of the optical modules and print the information to logs \n"
        "        page %x       : get the specified page [0 ~ FF] information of the optical modules \n"
        "   [-s]               : set optical info \n"
        "        hard_reset    : hard reset optical \n"
        "        soft_reset    : soft reset optical \n"
        "        low_power     : switch optical to low power \n"
        "        high_power    : switch optical to high power \n"
        "        tx_disable    : disable the tx \n"
        "                  all : disable all the lane tx \n"
        "        tx_enable     : enable the tx \n"
        "                  all : enable all the lane tx \n"
#endif
    },
    {
        "-i", "devid", "-stat", tool_stat_cmd_execute, "packet statistics cmd",
        "   [-g]        : get packet statistics\n"
        "   [-c]        : clear packet statistics\n"
    },
    {
        "-a", "", "-cfg", tool_cfg_cmd_execute, "cfg cmd",
        "    recovery   : recovery cfg \n"
    },
    {
        "-i", "devid", "-tls", tool_tls_cmd_execute, "tls cfg cmd",
        "   [-s]        : set tls cfg\n"
        "       enable %d : set tls enable, 0: disable, 1: enable\n"
        "       host      : if you want to set tls enable on host, you need to add host flag on the tail\n"
        "       or\n"
        "       alarm %d  : set tls alarm(days), [0, 7 ~ 180], 0: disable tls alarm, only support on npu\n"
        "       host      : if you want to set tls alarm on host, you need to add host flag on the tail\n"
        "       or\n"
        "       path %s   : set tls cfg file path, such as xxx\n"
        "       pri %s    : set tls private key, only support pem file format\n"
        "       pub %s    : set tls public cert, only support pem file format\n"
        "       ca1 %s    : set tls first level CA, only support pem file format\n"
        "       ca2 %s    : set tls second level CA, only support pem format\n"
        "       ......            \n"
        "       ca14 %s   : set tls fourteen level CA(the deepest CA level), only support pem format\n"
        "       crl %s    : set tls certificate revocation list, only support crl format\n"
        "       host      : if you want to set tls certificate suite on host, you need to add host flag on the tail\n"
        "       or\n"
        "       path %s   : set tls cfg file path, such as xxx\n"
        "       crl %s    : set tls certificate revocation list separately, only support device-side\n"
        "   [-g]        : get tls cfg\n"
        "       host      : if you want to get tls certificate suite on host, you need to add host flag on the tail\n"
        "   [-c]        : clear tls cfg\n"
        "       host      : if you want to clear tls certificate suite on host, you need to add host flag on the tail\n"
        "       or\n"
        "       crl       :  clear certificate revocation list separately, only support device-side\n"
    },
#ifdef HCCN_TOOL_ADAPT_IPV6
    {
        "-i", "devid", "-tlsca", tool_tls_ca_cmd_execute, "tls ca cert cfg cmd",
        "   [-importcert] : import CA cert to device\n"
        "       alias %s  : tls CA cert alias, such as xxx, must match this format: [a-zA-Z0-9-_]{1,63}\n"
        "       path %s   : tls CA cert pem file path, such as /home/tmp.pem\n"
        "   [-deletecert] : delete CA cert of device\n"
        "       alias %s  : tls CA cert alias, such as xxx, must match this format: [a-zA-Z0-9-_]{1,63}\n"
        "       or\n"
        "       all       : all CA cert\n"
        "   [-showcert]   : list CA cert of device\n"
        "       alias %s  : tls CA cert alias, such as xxx, must match this format: [a-zA-Z0-9-_]{1,63}\n"
        "       or\n"
        "       all       : all CA cert\n"
    },
#endif
    {
        "-i", "devid", "-version", tool_version_cmd_execute, "version cmd",
        "   [-g]        : get version info\n"
    },
    {
        "-i", "devid", "-vnic", tool_vnic_cmd_execute, "vnic cmd",
        "   [-g]        : get vnic link status, ip address and netmask \n"
    },
    {
        "-i", "devid", "-process", tool_process_cmd_execute, "process cmd",
        "   [-g]        : get device process info\n"
    },
    {
        "-i", "devid", "-udp", tool_roce_port_cmd_execute, "roce port set cmd",
        "   [-s]                    : set roce port\n"
        "       port %d             : roce UDP port, range [4097 ~ 65535]\n"
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
        "           [sip %s]        : if you want to add udp port based on ip pair, you need to add source ip address\n"
        "           [dip %s]        : if you want to add udp port based on ip pair, "
                                     "you need to add destination ip address\n"
#endif
        "       auto                : use random roce UDP port\n"
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
        "       multi_qp            : use multi qp mode set UDP source port\n"
        "           count %d        : set the count of port, range [2 ~ 32]\n"
        "           port %s         : set the range of ports number, format port-port, or port,...,port,"
                                                                                " range [4097 ~ 65535]\n"
        "       code                : use code mode set UDP source port\n"
        "   [-t]                    : select algorithm mode\n"
        "       nslb-dp             : select nslb mode set UDP source port\n"
        "           [listen_port %d]: set hccp socket listen port, range[10000 ~ 57999], default 16668\n"
#endif
#ifndef CFG_SOC_PLATFORM_CLOUD_V2
        "   [-g]                    : get roce udp port\n"
#else
        "   [-g]                    : get roce udp port and ip pair list\n"
        "       [sip %s]            : if you want to query one ip pair, you need to add source ip address\n"
        "       [dip %s]            : if you want to query one ip pair, you need to add destination ip address\n"
        "   [-d]                    : delete one configured roce UDP port based on ip pair\n"
        "       port %d             : roce UDP port, range [4097 ~ 65535]\n"
        "       sip %s              : source ip address\n"
        "       dip %s              : destination ip address\n"
        "   [-c]                    : clear device's all roce port based on ip pair\n"
#endif
    },
    {
        "-i", "devid", "-bandwidth", tool_bandwidth_cmd_execute, "bandwidth cmd",
        "   [-g]        : get tx/rx bandwidth \n"
#ifdef HCCN_TOOL_SHOW_EXT
        "       [time %d] : specify time period to measure bandwidth, range [100 ~ 10000] ms\n"
#endif
    },
    {
        "-i", "devid", "-status", tool_netdev_status_cmd_execute, "netdev status cmd",
        "   [-g]        : get netdev status\n"
#ifdef HCCN_TOOL_SHOW_EXT
    },
    {
        "-i", "devid", "-generic", tool_generic_cmd_execute, "generic info cmd",
        "   [-s]        : set generic info\n"
        "       static_speed %d : set port speed, the function supports 200000/100000 switching rate.\n"
        "                  note : shaper cfg will become invalid if bw_limit is bigger than speed\n"
        "       auto_adapt : auto adapt speed base on port speed and optical speed capabilities.\n"
        "             note : mutually exclusive with the static_speed\n"
#endif
    },
    {
        "-i", "devid", "-link_stat", tool_link_stat_cmd_execute, "link history statistics cmd",
        "   [-g]        : get link history statistics\n"
        "   [-c]        : clear link history statistics\n"
    },
    {
        "-i", "devid", "-eth_test", tool_eth_test_cmd_execute, "eth self-check info cmd",
        "   [-g]        : get the self-check result of eth ports\n"
        "       offline : mode, now only offline is supported.\n"
    },
    {
        "-i", "devid", "-hw_stats", tool_hw_stats_cmd_execute, "rdma hw resource statistics cmd",
        "   [-g]        : get hw resource statistics\n"
    },
    {
        "-i", "devid", "-udhcpc", tool_udhcpc_cmd_execute, "udhcpc cmd",
#ifdef HCCN_TOOL_ADAPT_IPV6
        "   [-inet6]             : use IPv6, when not specified default is IPv4\n"
#endif
        "   [-a]                 : acquire dhcp ip\n"
        "       [timeout %d]       : timeout, optional, default is 3 seconds, range [1 ~ 300] seconds\n"
        "       [quit]             : exit after obtaining lease, optional, default not exit\n"
        "   [-r]                 : release dhcp ip\n"
    },
#ifdef HCCN_TOOL_SHOW_EXT
    {
        "-i", "devid", "-dcqcn", tool_dcqcn_cmd_execute, "dcqcn cmd",
        "   [-s]        : set the setting of dcqcn\n"
        "       enable %d        : set the ability of dcqcn, 0: disable, 1: enable.\n"
        "       alg_mode %d      : set the value of alg_mode(0 or 1)\n"
        "       or\n"
        "       cnp_dscp %d      : set the value of cnp_dscp [0 ~ 63]\n"
        "       or\n"
        "       alg_mode %d      : set the value of alg_mode(0 or 1)\n"
        "       f %d             : set the value of iterations [0 ~ 255]\n"
        "       g_shift %d       : set the value of g_shift [0 ~ 15]\n"
        "       al %d            : set the value of alpha_min [0 ~ 255]\n"
        "       tkp %d           : set the value of tkp_shift [0 ~ 15]\n"
        "       max_speed %d     : set the value of max_speed ( 100000 or 200000)\n"
        "       ai %d            : set the value of ai [0 ~ 65535]\n"
        "       tmp %d           : set the value of tmp_shift [0 ~ 15]\n"
        "       alp %d           : set the value of alp [0 ~ 65535]\n"
        "       cnp_time %d      : set the value of cnp_time [0 ~ 255]\n"
        "       alp_shift %d     : set the value of alpha_shift[0 ~ 15]\n"
        "       max_des_shift %d : set the value of max_des_shift [0 ~ 9]\n"
        "   [-g]        : get the setting of dcqcn\n"
        "       status         : get the value of enable, alg_mode\n"
        "       or\n"
        "       cnp_dscp       : get the value of cnp_dscp\n"
        "       or\n"
        "       param          : get the value of param\n"
        "       alg_mode %d    : the value of alg_mode(0 or 1)\n"
    },
#endif
};

struct option_mode_info g_option_mode_list[MAX_CMD_LIST] = {
    {"-bond", UDA_OPT_BOND_CMD, ONE_VALUE},
    {"-port", UDA_OPT_PORT_CMD, TWO_VALUE}, // 预埋
    {NULL}
};

#ifdef CONFIG_FUZZ
bool insert_ext_cmd_done = false;
#endif


int insert_cmd_list(struct cmd_info *cmd, int cmd_num)
{
#ifdef CONFIG_FUZZ
    if (insert_ext_cmd_done) {
        return 0;
    }
    insert_ext_cmd_done = true;
#endif
    int ret;
    int i = 0;
    int current_cmd_num = MAX_CMD_LIST;
    struct cmd_info *cmd_end = NULL;

    for (i = 0; i < MAX_CMD_LIST; i++) {
        if (g_cmd_list[i].cmd_execute == NULL) {
            current_cmd_num = i;
            cmd_end = &g_cmd_list[i];
            break;
        }
    }
    if (current_cmd_num + cmd_num >= MAX_CMD_LIST || cmd_end == NULL) {
        roce_err("Cmd num out of max cmd num or cmd end ptr is null. (current_cmd_num=%d; cmd_num=%d)",
            current_cmd_num, cmd_num);
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    ret = memcpy_s(cmd_end, cmd_num * sizeof(struct cmd_info), cmd, cmd_num * sizeof(struct cmd_info));
    if (ret) {
        roce_err("Memcpy_s cmd fail. (ret=%d)", ret);
        return UDA_TOOL_NO_MEM_ERR;
    }
    return 0;
}

STATIC int dsmi_err_to_hccn_err(int dsmi_err)
{
    int uda_ret;

    uda_ret = UDA_DSMI_EXE_ERR;
    return uda_ret;
}

void uda_help_cmd_print(void)
{
    int index = 0;
    int major_cmd_cnt  = sizeof(g_cmd_list) / sizeof(g_cmd_list[0]);
    while (index < major_cmd_cnt) {
        if (g_cmd_list[index].option_help == NULL) {
            break;
        }
        if (g_cmd_list[index].option_mode != NULL) {
            TOOL_PRINT_INFO("hccn_tool %s %s %s %s", g_cmd_list[index].attr,
                g_cmd_list[index].attr_value, g_cmd_list[index].option_mode, g_cmd_list[index].option);
        } else {
            TOOL_PRINT_INFO("hccn_tool %s %s %s", g_cmd_list[index].attr,
                g_cmd_list[index].attr_value, g_cmd_list[index].option);
        }
        TOOL_PRINT_INFO("%s", g_cmd_list[index].option_help);
        index++;
    }
}

STATIC void uda_cmd_pram_list_print(int cmd_index)
{
    struct cmd_info *main_cmd_info = &g_cmd_list[cmd_index];

    if (main_cmd_info->option_mode != NULL) {
        TOOL_PRINT_INFO("[ hccn_tool %s devid %s %s ] needs the following parameters:", main_cmd_info->attr,
            main_cmd_info->option_mode, main_cmd_info->option);
    } else {
        TOOL_PRINT_INFO("[ hccn_tool %s devid %s ] needs the following parameters:", main_cmd_info->attr,
            main_cmd_info->option);
    }

    TOOL_PRINT_INFO("%s", main_cmd_info->option_help);
}

STATIC void uda_param_cmd_count_err_print(int cmd_index)
{
    TOOL_PRINT_ERR("The total count of input parameters is wrong!");
    uda_cmd_pram_list_print(cmd_index);
}

STATIC void uda_major_cmd_type_err_print(void)
{
    TOOL_PRINT_ERR("Get invalid major cmd type. The valid major cmd type should be \"-a\" or \"-i\".");
    TOOL_PRINT_ERR("Enter [ hccn_tool -h ] for more details.");
}

STATIC void uda_major_cmd_err_print(void)
{
    TOOL_PRINT_ERR("Get invalid major cmd.");
    TOOL_PRINT_ERR("Enter [ hccn_tool -h ] for more details.");
}

STATIC void uda_major_cmd_dev_id_err_print(void)
{
    TOOL_PRINT_ERR("Get invalid device id.");
}


STATIC void uda_major_cmd_num_err_print(void)
{
    TOOL_PRINT_ERR("Get invalid major cmd number. Please check your input.");
    TOOL_PRINT_ERR("Enter [ hccn_tool -h ] for more details.");
}

STATIC void uda_major_cmd_len_err_print(void)
{
    TOOL_PRINT_ERR("Get invalid input param len.");
}

void uda_handle_major_err(int exe_ret)
{
    switch (exe_ret) {
        case UDA_MAJOR_CMD_TYPE_ERR:
            uda_major_cmd_type_err_print();
            break;
        case UDA_MAJOR_CMD_INVALID_ERR:
            uda_major_cmd_err_print();
            break;
        case UDA_MAJOR_CMD_NUM_ERR:
            uda_major_cmd_num_err_print();
            break;
        case UDA_MAJOR_CMD_DEV_ID_ERR:
            uda_major_cmd_dev_id_err_print();
            break;
        case UDA_MAJOR_CMD_LEN_ERR:
            uda_major_cmd_len_err_print();
            break;
        default:
            TOOL_PRINT_ERR("Cmd execute failed!");
    }
}

STATIC void uda_handle_tls_ca_param_err(int exe_ret, struct tool_param *param)
{
    switch (exe_ret) {
        case UDA_PARAM_TLS_CA_MEM_FULL:
            TOOL_PRINT_ERR("ca cert memory is full.");
            break;
        case UDA_PARAM_TLS_CA_MEM_EMPTY:
            TOOL_PRINT_ERR("ca cert memory is empty.");
            break;
        case UDA_PARAM_TLS_CA_SAME_ALIAS:
            TOOL_PRINT_ERR("ca cert alias is exist.");
            break;
        case UDA_PARAM_TLS_HOST_INSERT_CA_ERR:
            TOOL_PRINT_ERR("In host, insert ca cert failed.");
            break;
        case UDA_PARAM_TLS_CA_ALIAS_NOT_EXIST:
            TOOL_PRINT_ERR("ca cert alias is not exist.");
            break;
        case UDA_PARAM_DIFF_SEGMT_VIA_ERR:
            TOOL_PRINT_ERR("The segment of configured via doesn't match that of the configured ip adress!");
            break;
        default:
            TOOL_PRINT_ERR("Cmd execute failed!");
            break;
    }
}

STATIC void uda_handle_tls_param_err(int exe_ret, struct tool_param *param)
{
    switch (exe_ret) {
        case UDA_PARAM_TLS_NO_CERT_ERR:
            TOOL_PRINT_ERR("No certificate found, please set certs firstly!"); break;
        case UDA_PARAM_TLS_INVALID_ALARM_ERR:
            TOOL_PRINT_ERR("Get invalid alarm time!");
            uda_cmd_pram_list_print(param->cmd_index); break;
        case UDA_PARAM_TLS_INVALID_ENABLE_ERR:
            TOOL_PRINT_ERR("Get invalid enable value!");
            uda_cmd_pram_list_print(param->cmd_index); break;
        case UDA_PARAM_PATH_INVALID_ERR:
            TOOL_PRINT_ERR("The file path input is invalid!"); break;
        case UDA_PARAM_TLS_CA_WTHOT_PRI_ERR:
            TOOL_PRINT_ERR("No pri key, cannot assign ca without pri key!");
            uda_cmd_pram_list_print(param->cmd_index); break;
        case UDA_PARAM_TLS_PRI_WITHOUT_PUB_ERR:
            TOOL_PRINT_ERR("Pri key doesn't match to pub cert!");
            uda_cmd_pram_list_print(param->cmd_index); break;
        case UDA_PARAM_TLS_CERT_DISCONSEQ_ERR:
            TOOL_PRINT_ERR("The certificate chain is not continuous!");
            uda_cmd_pram_list_print(param->cmd_index); break;
        case UDA_PARAM_TLS_CRL_NOT_LAST_ITEM_ERR:
            TOOL_PRINT_ERR("The crl certificate should be the last config item!");
            uda_cmd_pram_list_print(param->cmd_index); break;
        case UDA_PARAM_TLS_HOST_NOT_LAST_ITEM_ERR:
            TOOL_PRINT_ERR("The host flag should be the last config item!");
            uda_cmd_pram_list_print(param->cmd_index); break;
        case UDA_PARAM_TLS_PWD_LEN_INVALID_ERR:
            TOOL_PRINT_ERR("Your input password length is illegal, length must between [%d] and [%d]",
                PWD_MIN_LEN, PWD_MAX_LEN); break;
        case UDA_PARAM_TLS_PWD_COMPLEXITY_ERR:
            TOOL_PRINT_ERR("The complexity of password you input is too low, please choose another one!");
            break;
        case UDA_PARAM_TLS_CERT_LEN_INVALID_ERR:
            TOOL_PRINT_ERR("The certificate length is invalid!"); break;
        case UDA_PARAM_TLS_WEAK_PWD_DICT_CHECK_FAIL:
            /* This type of error has been displayed in weak_pwd_check_ret_print */
            break;
        default:
            uda_handle_tls_ca_param_err(exe_ret, param);
            break;
    }
}

static void uda_param_cmd_err_tips_print(char *item, int cmd_index)
{
    TOOL_PRINT_ERR("The value of %s you input is out of the valid range!", item);
    uda_cmd_pram_list_print(cmd_index);
    return;
}

void uda_handle_param_err(int exe_ret, struct tool_param *param)
{
    switch (exe_ret) {
        case UDA_PARAM_INVALID_ERR:
            TOOL_PRINT_ERR("Get invalid parameters!");
            uda_cmd_pram_list_print(param->cmd_index);
            break;
        case UDA_PARAM_OP_NOT_SUPPORT_ERR:
            TOOL_PRINT_ERR("Get unknown option!");
            uda_cmd_pram_list_print(param->cmd_index);
            break;
        case UDA_PARAM_IP_INVALID_ERR:
            TOOL_PRINT_ERR("The ip address you configured is invalid!");
            break;
        case UDA_PARAM_CMD_COUNT_ERR:
            uda_param_cmd_count_err_print(param->cmd_index);
            break;
        case UDA_PARAM_MAC_ADDR_INVALID_ERR:
            TOOL_PRINT_ERR("The mac address you configured is invalid or saved by system");
            break;
        case UDA_PARAM_CONFLICT_IP_ADDR_ERR:
            TOOL_PRINT_ERR("The ip address configured is conflicted!");
            break;
        case UDA_PARAM_DIFF_SEGMT_GTWY_ERR:
            TOOL_PRINT_ERR("The segment of configured gateway doesn't match that of the configured ip adress!");
            break;
        case UDA_PARAM_DSCP_OUT_OF_RANGE_ERR:
            uda_param_cmd_err_tips_print("dscp", param->cmd_index);
            break;
        case UDA_PARAM_TC_OUT_OF_RANGE_ERR:
            uda_param_cmd_err_tips_print("tc", param->cmd_index);
            break;
        case UDA_PARAM_BW_LIMIT_OUT_OF_RANGE_ERR:
            uda_param_cmd_err_tips_print("bw limit", param->cmd_index);
            break;
        case UDA_PARAM_MTU_OUT_OF_RANGE_ERR:
            uda_param_cmd_err_tips_print("mtu", param->cmd_index);
            break;
        case UDA_PARAM_ROCE_CTXT_OUT_OF_RANGE_ERR:
            uda_param_cmd_err_tips_print("roce context param", param->cmd_index);
            break;
        default:
            uda_handle_tls_param_err(exe_ret, param);
    }
}

struct hccn_tool_err_info g_uda_dsmi_err_list[] = {
    { UDA_DSMI_EXE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Command execute failed!"
    },
    { UDA_DSMI_GATEWAY_NOT_PRESET_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Get gateway failed, because no gateway was preset there!"
    },
    { UDA_DSMI_IPCONF_NOT_PRESET_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Get ipconf failed, because no ip was preset there!"
    },
    { UDA_DSMI_DEV_GET_HEALTH_TMOUT_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Get device health status failed!"
    },
    { UDA_DSMI_DEV_NOT_EXIST_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The device is not exist!"
    },
    { UDA_DSMI_TLS_CER_ILLEGAL_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The certificates are illegal!"
    },
    { UDA_DSMI_TLS_CER_VERIFY_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Failed to verify the certificate chain, make sure the certificate chain is correct!"
    },
    { UDA_DSMI_ROUTE_ROW_REACH_MAX_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Route rows reaches max! Can not add anymore!"
    },
    { UDA_DSMI_CMD_UPSUPPORT_ON_OPTICAL_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "Command unsupported on this optical module."
    },
    { UDA_DSMI_CONFIG_NUM_EXCEED_LIMIT_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "The number of configuration exceed the limit!"
    },
    { UDA_DSMI_UPDATE_QP_UDP_SPORT_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "Update qp udp source port didn't take effect immediately, you can try again."
    },
    { UDA_DSMI_SET_UDP_PORT_IPPAI_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "Set roce udp source port based on ip failed."
    },
    { UDA_DSMI_GET_I2C_CTRL_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "I2c is busy. Please try again."
    },
    { UDA_DSMI_LOOPBACK_FAIL_FOR_DOWNGRADE_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "Loopback can not be operated, because the xsfp has already been auto-downgraded. "
        "Please retry after disable the auto-downgrade switch."
    },
    { UDA_DSMI_CONTROL_LINK_UNREACHABLE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Control link unreachable."
    },
    { UDA_DSMI_CDR_NOT_SUPPORT_ERROR, UDA_PRINT_LEVEL_ERR, NULL,
        "Current cdr do not support this command!"
    },
    { UDA_DSMI_PAGE_INDEX_NOTSUPP, UDA_PRINT_LEVEL_ERR, NULL,
        "This optical module does not support dumping on this page!"
    },
    { UDA_DSMI_OPTICAL_NOT_INIT_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "The system is in optical module initializing, please try again later."
    },
    { UDA_DSMI_XSFP_FAIL_FOR_DOWNGRADE_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "Can not operate, because the xsfp has already been auto-downgraded. "
        "Please retry after disable the auto-downgrade switch."
    },
    { UDA_DSMI_XSFP_ABSENT, UDA_PRINT_LEVEL_INFO, NULL,
        "Optical module is not present."
    },
    { UDA_DSMI_NOT_SUPPORT_VM_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The VM does not support this command."
    },
    { UDA_DSMI_LINK_IS_DOWN_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Execute failed: Link status is down."
    },
    { UDA_DSMI_TLS_CERT_EXPIRED_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The Certificate has expired!"
    },
    { UDA_DSMI_DIAG_UNENABLED, UDA_PRINT_LEVEL_ERR, NULL,
        "Diagnostic mode is not enabled, please enable it first."
    },
    { UDA_DSMI_GET_LOCK_FAILED, UDA_PRINT_LEVEL_ERR, NULL,
        "Get lock failed. Please try again."
    },
    { UDA_TOOL_CHECK_TC_QOS_CONFIG, UDA_PRINT_LEVEL_ERR, NULL,
        "Get invalid parameters, please check tc_qos config."
    },
    { UDA_TOOL_CHECK_PRIO_TC_CONFIG, UDA_PRINT_LEVEL_ERR, NULL,
        "Get invalid parameters, please check prio_tc config."
    },
};

void uda_handle_exe_err(int exe_ret)
{
    switch (exe_ret) {
        case UDA_EXE_TIME_OUT_ERR:
            TOOL_PRINT_ERR("The cmd line execute timeout!");
            break;
        default:
            TOOL_PRINT_ERR("Cmd execute failed!");
    }
}

struct hccn_tool_err_info g_uda_tool_err_list[] = {
    { UDA_TOOL_SYS_WRITE_FILE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Write configurations to config file failed. User configurations cannot be persisted!"
        " pls check cmd run permission."
    },
    { UDA_TOOL_SYS_READ_FILE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Read file failed, cmd execute failed! pls check cmd run permission."
    },
    { UDA_TOOL_SYS_RD_FILE_NOT_FOUND, UDA_PRINT_LEVEL_ERR, NULL,
        "Read file failed, cmd execute failed! pls check cmd run permission."
    },
    { UDA_TOOL_SYS_DELETE_FILE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Delete configurations from config file failed. User configurations cannot be persisted!"
        " pls check cmd run permission."
    },
    { UDA_TOOL_SYS_FOPEN_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Open file failed, cmd execute failed! pls check the conf path or cmd run permission."
    },
    { UDA_TOOL_ACCESS_CONF_FILE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The hccn.conf can't access, cmd execute failed! pls check the conf file or cmd run permission."
    },
    { UDA_TOOL_CONF_FILE_NOT_EXIST_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The conf file can't access, cmd execute failed!"
    },
    { UDA_TOOL_INSUFFICIENT_FILE_SIZE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The hccn.conf has no enough space to save user configurations."
    },
    { UDA_TOOL_PARSE_CONF_FILE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Parsing configurations from config file failed, pls check the config file."
    },
    { UDA_TOOL_SYS_BUSY_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "hccn_tool is busy, please try again."
    },
    { UDA_TOOL_SYS_NOT_ACCESS, UDA_PRINT_LEVEL_ERR, NULL,
        "permission denied: pls check this cmd run permission."
    },
    { UDA_TOOL_CMD_UNSUPPORT_ON_PRODUCT_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "The command is not supported on this product."
    },
    { UDA_TOOL_CMD_UNSUPPORT_ON_MEDIA_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "The command is not supported on this optical media."
    },
    { UDA_TOOL_CDR_IS_UPDATING_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "CDR reg data is updating, please wait a moment(30s) to get."
    },
    { UDA_TOOL_CDR_UPDATE_FAIL_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "CDR reg data update data fail, please retrig or exception cdr."
    },
    { UDA_TOOL_CDR_NOT_TRIGGERED_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "CDR reg data is not trigged, must trig at least once."
    },
    { UDA_TOOL_ROUTE_ALREADY_EXIST_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Route already exist in routing table!"
    },
    { UDA_TOOL_ROUTE_NOT_EXIST_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "Route not exist in routing table, can not delete!"
    },
    { UDA_TOOL_USER_ABORT_CMD_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "User aborts command."
    },
    { UDA_TOOL_OP_NOT_SUPPORT_IPV6_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "This device does not support IPV6!"
    },
    { UDA_TOOL_OP_NOT_SUPPORT_BOND_ERR, UDA_PRINT_LEVEL_INFO, NULL,
        "This device does not support bonding!"
    },
    { UDA_TOOL_OP_PFC_NUMS_OUT_OF_VALUE, UDA_PRINT_LEVEL_INFO, NULL,
#ifdef CFG_SOC_PLATFORM_CLOUD_V2
        "The number of pfc priority queues exceeds the maximum value(4)."
#else
        "The number of pfc priority queues exceeds the maximum value(8)."
#endif
    },
    { UDA_TOOL_GATEWAY_NO_IP_CONF_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Unable to configure gateway, because ip is not configured!"
    },
    { UDA_TOOL_MTU_TOO_SMALL_FOR_IPV6_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Unable to configure IPV6 address, because mtu is less than 1280!"
    },
    { UDA_TOOL_IP_ROUTE_TABLE_ALREADY_EXIST_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "IP route table already exists."
    },
    { UDA_TOOL_HCCS_PING_RESOURCE_BUSY, UDA_PRINT_LEVEL_ERR, NULL,
        "The device is occupied. Please try again later."
    },
    { UDA_TOOL_CONF_NOT_EXIST_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The confuguraion does not exist! Please preset firstly!"
    },
    { UDA_TOOL_CONF_ALREADY_EXIST_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "The configuraion already exist!"
    },
    { UDA_TOOL_IP_MISMATCH_MASK_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Inconsistent address and mask!"
    },
    { UDA_TOOL_COFNIG_DEFAULT_ROUTE_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Can not add or delete default route! Please use hccn_tool gateway cfg cmd!"
    },
    { UDA_TOOL_ROUTE_TABLE_NOT_EXIST_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "FIB table does not exist!"
    },
    { UDA_TOOL_COFNIG_BROAD_ADDRESS_ERR, UDA_PRINT_LEVEL_ERR, NULL,
        "Can not config broadcast address!"
    },
};

void uda_handle_err_comm(int exe_ret, struct tool_param *param, struct hccn_tool_err_info *err_list, unsigned int size)
{
    unsigned int i;
    struct hccn_tool_err_info *err_info = NULL;

    for (i = 0; i < size; i++) {
        if (err_list[i].err_code != exe_ret) {
            continue;
        }
        err_info = &err_list[i];
        break;
    }

    if (err_info == NULL) {
        TOOL_PRINT_ERR("Cmd execute failed!");
        return;
    }

    if (err_info->err_str != NULL) {
        if (err_info->err_level == UDA_PRINT_LEVEL_INFO) {
            TOOL_PRINT_INFO("%s", err_info->err_str);
        } else {
            TOOL_PRINT_ERR("%s", err_info->err_str);
        }
    }

    if (err_info->print_private_err_str != NULL) {
        err_info->print_private_err_str(param);
    }
}

void uda_handle_dsmi_err(int exe_ret)
{
    unsigned int size = sizeof(g_uda_dsmi_err_list) / sizeof(g_uda_dsmi_err_list[0]);
    uda_handle_err_comm(exe_ret, NULL, g_uda_dsmi_err_list, size);
}

void uda_handle_tool_sys_err(int exe_ret, struct tool_param *param)
{
    unsigned int size = sizeof(g_uda_tool_err_list) / sizeof(g_uda_tool_err_list[0]);
    uda_handle_err_comm(exe_ret, param, g_uda_tool_err_list, size);
}

STATIC int cmd_check_phy_id(char **argv)
{
    int i;
    int length;
    const char *phy_id = NULL;
    char **argv_tmp = argv;

    argv_tmp += CMD_PHY_ID_POS;
    phy_id = *argv_tmp;
    if (phy_id == NULL) {
        roce_err("Phy_id param is NULL.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }

    length = strlen(phy_id);
    if (length > MAX_PHY_ID_LEN) {
        roce_err("device id length[%d] check fail! valid length is[1 or 2]", length);
        return UDA_MAJOR_CMD_DEV_ID_ERR;
    }
    for (i = 0; i < length; i++) {
        if ((phy_id[i] < '0') || (phy_id[i] > '9')) {
            roce_err("HCCN get invalid phy_id.");
            return UDA_MAJOR_CMD_DEV_ID_ERR;
        }
    }

    return 0;
}

STATIC int tool_parse_dev(char **argv, struct tool_param *param)
{
    const char *phy_id = NULL;
    int ret, tmp_phy_id;
    char **argv_tmp = argv;

    ret = cmd_check_phy_id(argv_tmp);
    if (ret) {
        roce_err("Device phy id check failed. (ret=0x%x)", ret);
        return ret;
    }

    argv_tmp += CMD_PHY_ID_POS;
    phy_id = *argv_tmp;

    tmp_phy_id = (int)strtol(phy_id, NULL, NUMBER_BASE);
    param->phy_id = tmp_phy_id;

    ret = dsmi_get_logicid_from_phyid(tmp_phy_id, (unsigned int *)(void *)(&param->logic_id));
    if (ret) {
        roce_err("DSMI get logicid from phyid fail. (ret=%d; phy_id=%d)", ret, tmp_phy_id);
        return UDA_MAJOR_CMD_DEV_ID_ERR;
    }

    if (param->logic_id >= TOOL_HOST_LOGIC_ID_MAX || param->logic_id < 0) {
        roce_err("HCCN get invalid logic id. (logic_id=%d)", param->logic_id);
        return UDA_MAJOR_CMD_DEV_ID_ERR;
    }

    ret = tool_check_dev_health(param->logic_id);
    if (ret) {
        roce_err("HCCN check dev health fail. (logic_id=%d; ret=0x%x)", param->logic_id, ret);
        return ret;
    }

    return 0;
}

STATIC int tool_parse_dev_para_for_host(char **argv, struct tool_param *param)
{
    const char *phy_id = NULL;
    int ret, tmp_phy_id;
    char **argv_tmp = argv;

    ret = cmd_check_phy_id(argv_tmp);
    if (ret) {
        roce_err("Device phy id check failed. (ret=0x%x)", ret);
        return ret;
    }

    argv_tmp += CMD_PHY_ID_POS;
    phy_id = *argv_tmp;
    tmp_phy_id = strtol(phy_id, NULL, NUMBER_BASE);
    if (tmp_phy_id >= TOOL_HOST_LOGIC_ID_MAX || tmp_phy_id < 0) {
        roce_err("HCCN get invalid phy_id. (tmp_phy_id=%d)", tmp_phy_id);
        return UDA_MAJOR_CMD_DEV_ID_ERR;
    }
    param->phy_id = 0;      // not use phy_id in host, set default value 0
    param->logic_id = 0;    // not use logic_id in host, set default value 0
    return 0;
}

STATIC int cmd_attr_check(hccn_cmd_attr attr, struct cmd_info *cmd_info)
{
    switch (attr) {
        case UDA_DEV_CMD:  // device cmd -i
            if (strncmp(cmd_info->attr, "-i", strlen("-i") + 1)) {
                return  UDA_MAJOR_CMD_TYPE_ERR;
            }
            break;
        case UDA_GLOBAL_CMD:  // global cmd -a
            if (strncmp(cmd_info->attr, "-a", strlen("-a") + 1)) {
                return  UDA_MAJOR_CMD_TYPE_ERR;
            }
            break;
        default:
            roce_err("CMD attr check fail. (attr=%d)", attr);
            return UDA_MAJOR_CMD_TYPE_ERR;
    }
    return 0;
}

STATIC int cmd_dev_parse(char **argv, struct tool_param *param)
{
    if (param->host_flag == false) {
        return tool_parse_dev(argv, param);
    } else {
        return tool_parse_dev_para_for_host(argv, param);
    }
}

STATIC int option_mode_cmd_parse(int argc, char **argv, struct tool_param *param, int *attr_index)
{
    struct option_mode_info *option_cmd_info = NULL;
    char *option_mode_input = NULL;
    int ret;
    int i;
    int option_cmd_cnt = sizeof(g_option_mode_list) / sizeof(g_option_mode_list[0]);

    if (argc <= *attr_index) {
        return UDA_MAJOR_CMD_INVALID_ERR;
    }

    param->option_mode = UDA_OPT_EMPTY_CMD;
    for (i = 0; i < option_cmd_cnt; i++) {
        option_cmd_info = &g_option_mode_list[i];
        if (option_cmd_info->attr == NULL) {
            break;
        }
        if (strcmp(option_cmd_info->attr, argv[*attr_index]) == 0) {
            *attr_index += option_cmd_info->cmd_major_offset;
            param->option_mode = option_cmd_info->mode;
            break;
        }
    }

    return UDA_EXE_SUCCESS;
}

STATIC int major_cmd_parse(int argc, char **argv, struct tool_param *param, hccn_cmd_attr attr, int attr_index)
{
    char *option = NULL;
    char *option_input = NULL;
    struct cmd_info *main_cmd_info = NULL;
    int major_cmd_cnt = sizeof(g_cmd_list) / sizeof(g_cmd_list[0]);
    int i = 0;
    int j;
    unsigned int len, opt_input_len;

    while (i < major_cmd_cnt) {
        main_cmd_info = &g_cmd_list[i];
        if (main_cmd_info->cmd_execute == NULL) {
            break;
        }
        option = main_cmd_info->option;
        len = strlen(option);
        for (j = 1; j < argc; j++) {
            option_input = argv[j];
            opt_input_len = strlen(option_input);
            if (len > opt_input_len) {
                continue;
            }

            if ((strncmp(option, option_input, len) == 0) && ((option_input)[len] == 0) &&
                (j == attr_index) && (cmd_attr_check(attr, main_cmd_info))) {
                continue;
            }

            if ((strncmp(option, option_input, len) == 0) && ((option_input)[len] == 0) &&
                (j == attr_index) && (!cmd_attr_check(attr, main_cmd_info))) {
                param->cmd_index = i;
                param->cmd_major_offset = j + 1;
                param->argc = argc;
                param->argv = argv;
                return 0;
            }
        }
        i++;
    }

    roce_err("Major cmd parse fail, can not find cmd in list. (cur_idx=%d; major_cmd_cnt=%d)", i, major_cmd_cnt);
    return UDA_MAJOR_CMD_INVALID_ERR;
}

STATIC int len_valid(int argc, char *argv[])
{
    int i;

    if ((argc <= NO_PARAM) || (argc >= MAX_PARAM)) {
        roce_err("Param num error. (argc=%d)", argc);
        /*
        * cmd length check failed while parse major cmd, didn't get cmd index so far,
        * so return invalid major cmd error here insted of cmd count err.
        */
        return UDA_MAJOR_CMD_NUM_ERR;
    }
    for (i = 0; i < argc; ++i) {
        if (strlen(argv[i]) > MAX_ARGV_LEN) {
            roce_err("Param len error. (len=%u)", strlen(argv[i]));
            return UDA_MAJOR_CMD_LEN_ERR;
        }
    }
    return 0;
}

STATIC int is_help(int argc, char **argv)
{
    if (argc != TWO_VALUE) {
        return UDA_NOT_HELP_CMD;
    }

    if (!strncmp(argv[1], "-h", strlen("-h") + 1)) {
        return UDA_HELP_CMD;
    } else if (!strncmp(argv[1], "--help", strlen("--help") + 1)) {
        return UDA_HELP_CMD;
    } else {
        return UDA_NOT_HELP_CMD;
    }
}

STATIC int get_cmd_type(int argc, char **argv, hccn_cmd_attr *cmd_attr, int *attr_index)
{
    if (!strncmp(argv[1], "-i", strlen("-i") + 1)) {
        *cmd_attr = UDA_DEV_CMD;
        *attr_index = THREE_VALUE;
    } else if (!strncmp(argv[1], "-a", strlen("-a") + 1)) {
        *cmd_attr = UDA_GLOBAL_CMD;
        *attr_index = TWO_VALUE;
    } else {
        roce_err("Invalid param cmd type.");
        return UDA_MAJOR_CMD_TYPE_ERR;
    }
    return 0;
}

STATIC int option_mode_check(struct tool_param *param, hccn_cmd_attr cmd_attr)
{
    int ret;
    bool is_atlas_9000_a3 = false;

    if (param->host_flag == true || cmd_attr != UDA_DEV_CMD) {
        // not need query mainboard_id in host
        // no phy_id when not using -i
        param->mainboard_id = 0;
        if (param->option_mode != UDA_OPT_EMPTY_CMD) {
            return UDA_PARAM_INVALID_ERR;
        } else {
            return UDA_EXE_SUCCESS;
        }
    }

    ret = dsmi_get_mainboard_id(param->phy_id, &(param->mainboard_id));
    if (ret != 0) {
        roce_err("Call dsmi get mainboard id failed. (ret=%d, phy_id=%d)", ret, param->phy_id);
        return UDA_DSMI_EXE_ERR;
    }
    if (param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID || param->mainboard_id == ATLAS_9000_A3_MAINBOARD_ID_2) {
        is_atlas_9000_a3 = true;
    }

    // 仅天工支持-bond
    if ((param->option_mode != UDA_OPT_EMPTY_CMD) && (!is_atlas_9000_a3)) {
        return UDA_TOOL_OP_NOT_SUPPORT_BOND_ERR;
    }
    return UDA_EXE_SUCCESS;
}

/* !!!const secondary pointer and nonconst secondary pointer cannot be singed to each other!!! */
STATIC int parse_major_dev_cmd(int argc, char **argv, hccn_cmd_attr *cmd_attr, struct tool_param *param)
{
    int ret;
    int attr_index;

    param->option_mode = UDA_OPT_EMPTY_CMD;
    ret = get_cmd_type(argc, argv, cmd_attr, &attr_index);
    if (ret) {
        roce_err("Get cmd type fail. (ret=0x%x)", ret);
        return ret;
    }
    ret = major_cmd_parse(argc, argv, param, *cmd_attr, attr_index);
    if (ret) {
        roce_err("Major cmd parse fail. (ret=0x%x)", ret);
        return ret;
    }
    if (*cmd_attr == UDA_DEV_CMD) {
        ret = cmd_dev_parse(argv, param);
        if (ret) {
            roce_err("Dev cmd parse fail. (ret=0x%x)", ret);
            return ret;
        }
    }

    ret = option_mode_check(param, *cmd_attr);
    if (ret) {
        roce_err("Option mode check fail. (ret=0x%x)", ret);
        return ret;
    }

    return ret;
}

#define CMD_OPS_IDX 3
#define DEFAULT_FILL_CONTENT "********"
struct check_element {
    char *cmd;
    char *config_para;
    int idx;
};

static struct check_element check_list[] = {
    { "-ip", "address", 5, },
    { "-ip", "netmask", 7, },
    { "-ip", "ipv6_address", 6},
    { "-ip", "prefix_length", 8},
    { "-gateway", "gateway", 5, },
    { "-gateway", "ipv6_gateway", 6},
    { "-netdetect", "address", 5, },
    { "-netdetect", "ipv6_address", 6},
    { "-mac", "mac", 5, },
    { "-tls", "path", 5, },
    { "-tls", "pri", 7, },
    { "-tls", "pub", 9, },
    { "-tls", "ca1", 11, },
    { "-tls", "ca2", 13, },
    { "-tls", "ca3", 15, },
    { "-tls", "ca4", 17, },
    { "-tls", "ca5", 19, },
    { "-tls", "ca6", 21, },
    { "-tls", "ca7", 23, },
    { "-tls", "ca8", 25, },
    { "-tls", "ca9", 27, },
    { "-tls", "ca10", 29, },
    { "-tls", "ca11", 31, },
    { "-tls", "ca12", 33, },
    { "-tls", "ca13", 35, },
    { "-tls", "ca14", 37, },
    { "-tls", "crl", -1, },
    { "-envelope", "path", 5, },
    { "-envelope", "pri", 7, },
    { "-envelope", "pub", 9, },
    { "-arp", "dev", -1, },
    { "-arp", "ip", -1, },
    { "-arp", "mac", -1, },
    { "-route", "address", 5, },
    { "-route", "netmask", 7, },
    { "-route", "gateway", 9, },
    { "-ip_rule", "dir", -1, },
    { "-ip_rule", "ip", -1, },
    { "-ip_rule", "table", -1, },
    { "-ip_route", "ip", -1, },
    { "-ip_route", "ip_mask", -1, },
    { "-ip_route", "via", -1, },
    { "-ip_route", "dev", -1, },
    { "-ip_route", "table", -1, },
    { "-route", "ipv6_address", 6, },
    { "-route", "prefix_length", 8, },
    { "-route", "next_address", 10, },
    { "-neigh", "dev", 6},
    { "-neigh", "ipv6_address", 8},
    { "-neigh", "mac", 10},
    { "-ping", "ipv6_address", 6},
    { "-ping", "address", 5},
    { "-traceroute", "-d", -1},
    { "-roce_test", "address", -1},
};

// 辅助函数：检查下一个参数是否是 "recovery" 或 "status"
STATIC bool check_next_argument(const char *arg)
{
    size_t arg_len = strnlen(arg, MAX_ARG_LEN); // 获取参数长度，限制为 MAX_ARG_LEN
    if (arg_len == RECOVERY_OPTION_LEN && strncmp(arg, RECOVERY_OPTION, RECOVERY_OPTION_LEN) == 0) {
        return true; // 匹配到 "recovery" 时返回 true
    }
    if (arg_len == STATUS_OPTION_LEN && strncmp(arg, STATUS_OPTION, STATUS_OPTION_LEN) == 0) {
        return true; // 匹配到 "status" 时返回 true
    }
    return false; // 如果不是 "status" 或 "recovery"，返回 false
}

STATIC bool hccn_is_cmd_recovery_type(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        // 检查当前参数是否等于 "-cfg"
        if (strncmp(argv[i], CFG_OPTION, CFG_OPTION_LEN) == 0 &&
            strnlen(argv[i], CFG_OPTION_LEN) == CFG_OPTION_LEN) {
            // 确保下一个参数存在，并检查其值
            if ((i + 1) < argc) {
                return check_next_argument(argv[i + 1]);
            }
            // 如果 "-cfg" 后没有有效参数，则返回 false
            return false;
        }
    }
    // 如果没有找到 "-cfg" 参数，则返回 false
    return false;
}

const cmd_type_config get_cmd_config_list[] = {
    // 不包含-g的特殊查询类命令, 第一个数字字段表示需要校验的的参数个数, 需要小于CMD_TYPE_MAX_CHECK_PARAMS
    {3, {"-scdr", "-t", "5"}},
    {3, {"-scdr", "-t", "4"}},
    {2, {"-cfg", "status"}},
    {2, {"-reg", "-a"}},
    {2, {"-hilink_info", "-t"}},
    // 由于roce_test中的reset是配置类命令， 所以需要对roce_test每一个参数单独匹配
    {2, {"-roce_test", "ib_read_bw"}},
    {2, {"-roce_test", "ib_write_bw"}},
    {2, {"-roce_test", "ib_send_bw"}},
    {2, {"-roce_test", "ib_read_lat"}},
    {2, {"-roce_test", "ib_write_lat"}},
    {2, {"-roce_test", "ib_send_lat"}},
    {3, {"-roce_test", "-inet6", "ib_read_bw"}},
    {3, {"-roce_test", "-inet6", "ib_write_bw"}},
    {3, {"-roce_test", "-inet6", "ib_send_bw"}},
    {3, {"-roce_test", "-inet6", "ib_read_lat"}},
    {3, {"-roce_test", "-inet6", "ib_write_lat"}},
    {3, {"-roce_test", "-inet6", "ib_send_lat"}},

    {2, {"-optical", "-dump"}},
    {2, {"-tlsca", "-showcert"}},
    {3, {"-scdr", "-reg_read", "address"}},
};

const cmd_type_config set_cmd_config_list[] = {
    // 含-g的特殊设置类命令, 第一个数字字段表示需要校验的的参数个数, 需要小于CMD_TYPE_MAX_CHECK_PARAMS
    {3, {"-eth_test", "-g", "offline"}},
};

/**
 * 检查配置列表是否与参数匹配
 *
 * @param argc 参数个数
 * @param argv 参数数组，和argc同为传入main函数的原始用户输入，通过校验argc可保证argv指针的合法性
 * @param cmd_list 命令配置列表, 可以为set_cmd_config_list或get_cmd_config_list
 * @param config_size 配置列表大小
 * @return 如果存在匹配项返回true，否则返回false
 */
static bool check_config_list(int argc, char **argv, const cmd_type_config *cmd_list, const size_t config_size)
{
    const cmd_type_config *entry = NULL;
    bool match = true;
    size_t j;
    int k;

    for (j = 0; j < config_size; j++) {
        entry = &cmd_list[j];
        // 检查参数数量是否足够
        if (argc < (HCCN_TOOL_MAIN_CMD_POS + entry->length)) {
            continue; // 参数不足，跳过当前配置项
        }
        // 逐个比较参数
        match = true;
        for (k = 0; k < entry->length; k++) {
            if (strcmp(argv[HCCN_TOOL_MAIN_CMD_POS + k], entry->params[k]) != 0) {
                match = false;
                break;
            }
        }
        if (match) {
            return true; // 存在匹配项
        }
    }
    return false; // 无匹配项
}

/**
 * 检查get_cmd_config_list表， 匹配特殊的查询类命令类型
 *
 * @param argc 参数个数
 * @param argv 参数数组，和argc同为传入main函数的原始用户输入，通过校验argc可保证argv指针的合法性
 * @return 配置类返回true，查询类返回false
 */
static bool check_special_cmd_type(int argc, char **argv)
{
    size_t config_size = sizeof(get_cmd_config_list) / sizeof(get_cmd_config_list[0]);
    // 检查 get_cmd_config_list 是否有匹配项
    if (check_config_list(argc, argv, get_cmd_config_list, config_size)) {
        return false;
    }
    return true; // 所有 get 配置项均不匹配
}

bool check_cmd_is_set_type(int argc, char **argv)
{
    size_t config_size = sizeof(set_cmd_config_list) / sizeof(set_cmd_config_list[0]);
    int i;
    for (i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            return false;
        }
    }
    // 检查是否存在 "-g" 参数
    for (i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-g") == 0) {
            if (check_config_list(argc, argv, set_cmd_config_list, config_size)) {
                return true;  // 包含-g的特殊设置类命令
            }
            return false;
        }
    }
    // 检查是否为特殊的查询类命令
    return check_special_cmd_type(argc, argv);
}

STATIC int check_cmd_is_in_black_list(int idx, char **argv)
{
    int i;
    struct check_element *ele = NULL;

    if (idx <= CMD_OPS_IDX) {
        return 0;
    }

    for (i = 0; i < sizeof(check_list) / sizeof(struct check_element); ++i) {
        ele = &check_list[i];
        if (strncmp(argv[CMD_OPS_IDX], ele->cmd, strlen(ele->cmd) + 1)) {
            continue;
        }
        if (idx == ele->idx + 1 && !strncmp(argv[ele->idx], ele->config_para, strlen(ele->config_para) + 1)) {
            return 1;
        }
        if (ele->idx == -1 && !strncmp(argv[idx - 1], ele->config_para, strlen(ele->config_para) + 1)) {
            return 1;
        }
    }
    return 0;
}

STATIC void record_normal_cmd_to_log(int idx, char *argv_copy, bool is_set_cmd_type)
{
    int j;

    for (j = 0; j < strlen(argv_copy); ++j) {
        switch (argv_copy[j]) {
            case 'a' ... 'z':
            case 'A' ... 'Z':
            case '0' ... '9':
            case '_':
            case '.':
            case '-':
            case '/':
                continue;
            default:
                argv_copy[j] = ':';
                break;
        }
    }
    if (is_set_cmd_type) {
        LOG_SET_CONFIG("parse [%d]th argv[%s]", idx, argv_copy);
    } else {
        LOG_PROMPT("parse [%d]th argv[%s]", idx, argv_copy);
    }
}

STATIC void record_black_list_cmd_to_log(int idx, char *argv_copy, bool is_set_cmd_type)
{
    int ret;

    ret = strncpy_s(argv_copy, MAX_ARGV_LEN + 1, DEFAULT_FILL_CONTENT, strlen(DEFAULT_FILL_CONTENT));
    if (ret) {
        if (is_set_cmd_type) {
            LOG_SET_CONFIG("Record argv[%d] failed, ret=%d", idx, ret);
        } else {
            LOG_PROMPT("Record argv[%d] failed, ret=%d", idx, ret);
        }
        return;
    }
    if (is_set_cmd_type) {
        LOG_SET_CONFIG("parse [%d]th argv[%s]", idx, argv_copy);
    } else {
        LOG_PROMPT("parse [%d]th argv[%s]", idx, argv_copy);
    }
}

STATIC void record_cmd_to_log(int argc, char **argv)
{
    int i, ret;
    bool is_set_cmd_type = false;
    char argv_copy[MAX_ARGV_LEN + 1] = {0};

    is_set_cmd_type = check_cmd_is_set_type(argc, argv);
    for (i = 0; i < argc; i++) {
        ret = memcpy_s(argv_copy, MAX_ARGV_LEN + 1, argv[i], strlen(argv[i]) + 1);
        if (ret) {
            if (is_set_cmd_type) {
                LOG_SET_CONFIG("Record argv[%d] failed, ret=%d", i, ret);
            } else {
                LOG_PROMPT("Record argv[%d] failed, ret=%d", i, ret);
            }
            continue;
        }
        if (check_cmd_is_in_black_list(i, argv)) {
            record_black_list_cmd_to_log(i, argv_copy, is_set_cmd_type);
        } else {
            record_normal_cmd_to_log(i, argv_copy, is_set_cmd_type);
        }
    }
}

int parse_cmd(int argc, char **argv, struct tool_param *param)
{
    int argc_temp;
    char **argv_temp;
    int ret;
    int (*cmd_execute)(int argc, char **argv, struct tool_param *para) = NULL;
    hccn_cmd_attr cmd_attr;

    if (param == NULL) {
        roce_err("Input param is NULL.");
        return UDA_TOOL_INNER_PARAM_ERR;
    }
    ret = len_valid(argc, argv);
    if (ret) {
        roce_err("HCCN check input param num fail. (ret=0x%x)", ret);
        return ret;
    }

    if (strncmp(argv[argc - 1], "host", strlen("host") + 1) != 0 && is_help(argc, argv) != UDA_HELP_CMD) {
        param->host_flag = false;
    } else {
        param->host_flag = true;
    }
    if (check_cmd_is_set_type(argc, argv) == 1) {
        LOG_SET_CONFIG("input parameters: argc[%d]", argc);
    } else {
        LOG_PROMPT("input parameters: argc[%d]", argc);
    }
    ret = insert_ext_cmd();
    if (ret) {
        roce_err("HCCN insert ext cmd failed. (ret=0x%x)", ret);
        return ret;
    }

    record_cmd_to_log(argc, argv);

    ret = is_help(argc, argv);
    if (ret == UDA_HELP_CMD) {
        param->get_cmd_flag = true; // hccn_tool -h 打印帮助信息，不需要回显success
        uda_help_cmd_print();
        return UDA_EXE_SUCCESS;
    }

    ret = parse_major_dev_cmd(argc, argv, &cmd_attr, param);
    if (ret) {
        roce_err("Parse major or dev cmd fail. (ret=0x%x)", ret);
        return ret;
    }

    cmd_execute = g_cmd_list[param->cmd_index].cmd_execute;
    argc_temp = param->argc - param->cmd_major_offset;
    argv_temp = param->argv + param->cmd_major_offset;
    param->cmd_attr = cmd_attr;
    roce_info("Parse cmd success. (cmd_index=%d)", param->cmd_index);
    ret = cmd_execute(argc_temp, argv_temp, param);
    return ret;
}


void record_result_fail_to_log(int argc, char *argv[], int ret)
{
    int res;
    unsigned int err_family = (unsigned int)ret & 0xF000;

    // 参数合法校验
    res = len_valid(argc, argv);
    if (res) {
        roce_err("HCCN check input param num fail. (ret=0x%x)", res);
        return;
    }
    if ((err_family != UDA_PARAM_ERR) && (err_family != UDA_MAJOR_CMD_ERR) && hccn_is_cmd_recovery_type(argc, argv)) {
        if (ret != UDA_TOOL_SYS_NOT_ACCESS) { // -cfg recovery 没有权限时不需要提示用户查看日志
            // 判断为recovery命令（recovery命令执行失败时提示用户查看hccn_config.log）,新增回显
            TOOL_PRINT_INFO("Recovery failed. Check '/var/log/hccn_tool/hccn_config.log' for details.");
        }
    }
    // 日志分流
    if (check_cmd_is_set_type(argc, argv)) {
        LOG_SET_CONFIG("hccn tool execution failed! ret=0x%x", ret);
    } else {
        LOG_PROMPT("hccn tool execution failed! ret=0x%x", ret);
    }
}

void record_result_success_to_log(bool get_cmd_flag, int argc, char *argv[])
{
    // 仅非查询类命令行在成功时需要打印回显（成功回显逻辑与原来保持一致）
    if (get_cmd_flag == false) {
        TOOL_PRINT_INFO("Cmd executed successfully!");
    }
    // 日志分流
    if (check_cmd_is_set_type(argc, argv)) {
        LOG_SET_CONFIG("hccn tool execution succeed!");
    } else {
        LOG_PROMPT("hccn tool execution succeed!");
    }
}

