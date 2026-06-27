/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#ifndef CMDLIST_DVPP_CMDLIST_SQE_H
#define CMDLIST_DVPP_CMDLIST_SQE_H

#include "ka_type.h"

struct dvpp_sqe {
    uint32_t filed[16];
};

#pragma pack(1)
typedef struct {
    // sqe[0]
    uint32_t sqe_type : 6;
    uint32_t chn_id : 8;
    uint32_t reverse0 : 18;
    // sqe[1]
    uint16_t streamid;
    uint16_t taskid;
    // sqe[2]
    uint32_t cmdbuf_size;
    // sqe[3]
    uint32_t reverse1 : 6;
    uint32_t tlv_node_num : 9; // 最大值256，8位只能到255，所以需要9位
    uint32_t is_use_mem_pool : 1; // 内核态是否使用args内存池
    uint32_t timeout  : 8;
    uint32_t ptr_mode : 1;
    uint32_t is_cmdbuf_pool : 1; // 用户态是否使用cmdbuf内存池
    uint32_t reverse2 : 6;
    // sqe[4-5]
    uint64_t cmdbuf_uva;   // 用户态传入cmdbuf_uva起始地址，内核态偏移后更新
    // sqe[6-7]
    uint64_t args_addr;
    // sqe[8]
    uint32_t args_size;
    // sqe[9-10]
    uint64_t cmdbuf_kva;
    // sqe[11-12]
    uint64_t share_mem_addr;
    // sqe[13]
    uint32_t share_mem_size;
    // sqe[14-15]
    union {
        uint64_t args_node;       // 内核态中临时使用
        uint64_t cmdbuf_uva_beg;  // 存放cmdbuf_uva起始地址，传给runtime用于cmdbuf_uva的释放
    };
} dvpp_sqe_args;
#pragma pack()

#endif // #ifndef CMDLIST_DVPP_CMDLIST_SQE_H
