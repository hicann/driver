/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef PAIR_DEV_INFO_COMM_H
#define PAIR_DEV_INFO_COMM_H

#define DEVDRV_PAIR_DEV_EID_LENGTH 16
struct devdrv_pair_info_eid {
    unsigned char raw[DEVDRV_PAIR_DEV_EID_LENGTH];
};

#endif