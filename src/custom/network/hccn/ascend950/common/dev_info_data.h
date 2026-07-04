/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef DEV_INFO_DATA_H
#define DEV_INFO_DATA_H

#include <string.h>
#include <net/if.h>
#include <linux/if_bonding.h>
#include <urma_types.h>
#include "tcpip_cmd_data.h"

#define RDFX_VNIC_NAME_LEN   8
#define DEV_INFO_DEFAULT_BOND_SLAVE_NUM 2U
#define DEV_INFO_MAX_DEV_NUM 32U
#define DEV_INFO_MAX_PORT_NUM DEV_INFO_MAX_DEV_NUM
#define DEV_INFO_MAX_DIE_NUM 2U
#define DEV_INFO_MAX_DIE_PORT_NUM (DEV_INFO_MAX_PORT_NUM / DEV_INFO_MAX_DIE_NUM)
#define DEV_INFO_MAX_EID_NUM 64U
#define DEV_INFO_MAX_IP_NUM DEV_INFO_MAX_EID_NUM

enum {
    PORT_TYPE_UB = 0,
    PORT_TYPE_ETH = 1,
};

enum {
    LINK_STATUS_DOWN = 0,
    LINK_STATUS_UP = 1,
};

enum {
    INTERFACE_STATUS_DOWN = 0,
    INTERFACE_STATUS_UP = 1,
    INTERFACE_STATUS_CHANGING = 2,
};

enum {
    MEDIA_TYPE_ELECTRICAL = 0,
    MEDIA_TYPE_OPTICAL = 1,
};

#define LINE_BAR_7    "---------"
#define LINE_BAR_9    "-----------"
#define LINE_BAR_10    "------------"
#define LINE_BAR_11    "-------------"
#define LINE_BAR_15    "-----------------"
#define LINE_BAR_19    "---------------------"
#define LINE_BAR_39    "-----------------------------------------"
#define LINE_BAR_42    "--------------------------------------------"
#define GET_PORT_TYPE_STR(type) ((type) == PORT_TYPE_UB ? "UB" : "ETH")
#define GET_LINK_STATUS_STR(status) ((status) == LINK_STATUS_DOWN ? "DOWN" : "UP")
#define GET_MEDIA_TYPE_STR(type) ((type) == MEDIA_TYPE_ELECTRICAL ? "Electrical" : "Optical")
#define NA_STR "NA"
#define GET_IS_BOND_STR(is_bond, bond_mode) ((is_bond) ? \
    ((bond_mode) == BOND_MODE_8023AD ? "8023.ad" : "Unknown") : NA_STR)
#define GET_BOND_SLAVE0_STR(is_bond, slave0_name) ((is_bond) ? (slave0_name) : NA_STR)

#define BOND_IFACE_PREFIX "bond"
#define BOND_IFACE_PREFIX_LEN (sizeof(BOND_IFACE_PREFIX) - 1)

static inline bool hccn_check_is_uboe_dev(char *dev_name)
{
    if (strncmp(dev_name, "eth", strlen("eth")) != 0 &&
        strncmp(dev_name, BOND_IFACE_PREFIX, BOND_IFACE_PREFIX_LEN) != 0) {
        return false;
    }
    return true;
}

static inline bool hccn_check_is_bond_dev(char *dev_name)
{
    if (strncmp(dev_name, BOND_IFACE_PREFIX, BOND_IFACE_PREFIX_LEN) != 0) {
        return false;
    }
    return true;
}

struct port_info {
    uint32_t chip_id;
    uint32_t udie_id;
    uint32_t port_id;
    uint32_t speed_ability; // Gbps
    uint8_t port_type;
    uint8_t link_status;
    uint8_t media_type;
    uint8_t is_in_use; // 1:Y/0:N
};

struct port_info_data {
    struct port_info data[DEV_INFO_MAX_PORT_NUM];
    unsigned int num;
};

struct netdev_info {
    char ifname[IFNAMSIZ];
    union sockaddr_t addr_list[DEV_INFO_MAX_IP_NUM];
    union sockaddr_t mask_list[DEV_INFO_MAX_IP_NUM];
    uint8_t list_size;
    bool is_bond;
    struct {
        uint8_t bond_mode; // BOND_MODE_8023AD, refer to linux/if_bonding.h
        char slaves_ifname[DEV_INFO_DEFAULT_BOND_SLAVE_NUM][IFNAMSIZ];
    } bond_info;
};

struct netdev_info_data {
    struct netdev_info data[DEV_INFO_MAX_DEV_NUM];
    unsigned int num;
};

struct udev_info {
    char name[URMA_MAX_NAME];
    urma_eid_info_t eid_list[DEV_INFO_MAX_EID_NUM];
    uint8_t eid_num;
};

struct udev_info_data {
    struct udev_info data[DEV_INFO_MAX_DEV_NUM];
    unsigned int num;
};
#endif // DEV_INFO_DATA_H
