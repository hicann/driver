/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef DMS_URD_FORWARD_UK_MSG_H
#define DMS_URD_FORWARD_UK_MSG_H

struct dms_lpm_info_in {
    unsigned int dev_id;
    unsigned int vfid;
    unsigned int core_id;
    unsigned int sub_cmd;
};

struct dms_lpm_info_in_v2 {
    unsigned int dev_id;
    unsigned int part_id; // die_id
    unsigned int vfid;
    unsigned int core_id;
};

#endif
