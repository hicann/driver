/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef PBL_PROF_INTERFACE_CMD_H
#define PBL_PROF_INTERFACE_CMD_H
#define PROF_OK (0)
#define PROF_ERROR (-1)
#define PROF_STOPPED_ALREADY (-4)
#define PROF_NOT_SUPPORT (-7)
#define PROF_NOT_ENOUGH_SUB_CHANNEL_RESOURCE (-10)
#define PROF_VF_SUB_RESOURCE_FULL (-11)
#define PROF_CHANNEL_NUM 160

struct channels_info {
    unsigned short remote_pid;
    unsigned short channel_id;
};

struct prof_channel_list {
    unsigned int channel_num;
    struct channels_info channel[PROF_CHANNEL_NUM];
};

#define PROF_USER_DATA_LEN 128U
#define PROF_USER_ADDR_DATA_LEN 64U
struct prof_host_sample_start_event_msg {
    unsigned int chan_id;
    unsigned int sample_period;
    unsigned int data_len;
    char data[PROF_USER_DATA_LEN];
    char addrdata[PROF_USER_ADDR_DATA_LEN];
    unsigned int addr_data_len;
};

#define PROF_START_OUTDATA_SIZE_MAX 64
struct prof_start_event_out_msg {
    unsigned int sub_chan_id;
    unsigned int outdata_len;
    char outdata[PROF_START_OUTDATA_SIZE_MAX];
};

typedef enum {
    PROF_STOP_STAGE_DEFAULT = 0,
    PROF_STOP_STAGE_PAUSE,
    PROF_STOP_STAGE_RELEASE,
    PROF_STOP_STAGE_PAUSE_AND_RELEASE,
} prof_stop_stage;

struct prof_host_sample_stop_event_msg {
    unsigned int chan_id;
    unsigned int release_flag;
};
#endif
