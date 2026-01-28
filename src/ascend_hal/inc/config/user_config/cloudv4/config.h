/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef __CONFIG_H
#define __CONFIG_H

#ifndef NULL
#define NULL    (0L)
#endif
/*
 * 用户配置区静态选项
 */
#define CURRENT_USER_CONFIG_VERSION     1                       /* 当前软件能支持的用户配置的版本号 */

#define UC_FLASH_MAIN_ADDR              0x3E00000                /* 配置所在的flash主区偏移地址 */
#define UC_FLASH_BK_ADDR                0x3F00000                /* 配置所在的flash备区偏移地址 */
#define UC_FLASH_DEV_OFFSET             0                        /* 配置共flash场景每个device的地址差值 */

#define UC_FLASH_PARTITION_NUM          32                      /* 用户配置分区数量 */
#define UC_FLASH_PARTITION_MAIN_NUM     16                      /* 用户配置区主区数量 */
#define UC_FLASH_PARTITION_BK_NUM       16                      /* 用户配置区备区数量 */
#define UC_FLASH_PARTITION_SIZE         (64 * 1024)             /* 用户配置分区大小(字节数) */

#define UC_VERION_FLASH_OFFSET          0                       /* 配置版本号偏移 */
#define UC_CONFIG_FLASH_OFFSET          4                       /* 配置内容偏移 */
#define UC_CHECK_FLASH_OFFSET           (64 * 1024 - 4 - 32)    /* 配置校验码偏移 */
#define UC_VALID_FLASH_OFFSET           (64 * 1024 - 4)         /* 配置分区有效标志偏移 */
#define UC_VALID_FLAG_VALUE             0x8a7b6c5d              /* 配置分区有效标志值 */

#define UC_ITEM_VALID_VALUE             1                       /* 配置项有效标志值 */
#define UC_ITEM_MAX_NUM                 5                       /* 配置项数量 */
#define UC_ITEM_DATA_MAX_LEN            0x8000                  /* 配置内容的最大长度,32KB */

/* 配置项数据字节数(最少为2，第1字节为有效性) */
#define UC_CPU_CFG_SIZE                 (16 + 1)                /* CPU数量配置 */
#define UC_MAC_INFO_1_SIZE              (16 + 1)                /* 1个字节是有效性标志 */
#define UC_MAC_INFO_SIZE                16                      /* 16个字节MAC信息存储 */
#define UC_CPU_WORK_MODE_SIZE           (1 + 1)                 /* CPU工作模式配置 */
#define UC_SIGN_AUTH_ENABLE_SIZE        2                       /* 2个字节存储验签标志 */

/* 配置内容中各项偏移，注意：此偏移确定后不能再做修改，删除配置项时，此处不能删除偏移值 */
#define UC_CPU_CFG_OFFSET               0                                               /* CPU数量配置偏移 */
#define UC_MAC_INFO_1_OFFSET            (UC_CPU_CFG_OFFSET + UC_CPU_CFG_SIZE)           /* MAC INFO 1 用户配置偏移 */
#define UC_MAC_INFO_OFFSET              0                                               /* MAC INFO用户配置偏移 */
#define UC_CPU_WORK_MODE_OFFSET         (UC_MAC_INFO_1_OFFSET + UC_MAC_INFO_1_SIZE)         /* CPU工作模式配置偏移 */
#define UC_SIGN_AUTH_ENABLE_OFFSET      (UC_CPU_WORK_MODE_OFFSET + UC_CPU_WORK_MODE_SIZE)   /* 验签标志用户配置偏移 */

/* 配置项权限控制 */
#define UC_AUTHORITY_ROOT_WR	(0) /* root 用户可读可写 普通用户无法访问 */
#define UC_AUTHORITY_USER_WR	(1) /* root 用户可读可写 普通用户可读可写 */
#define UC_AUTHORITY_USER_RO	(2) /* root 用户可读可写 普通用户只读 */
#define UC_USER_PARA_ERR    -1
#define UC_USER_PARA_OK     0

/* 用户配置项信息 */
struct user_config_item {
    const char *name;       /* 配置项名 */
    int  board_id;          /* 此配置属于board_id的单板，如果board_id为-1，那么所有board_id都使用 */
    int  offset;            /* 配置项数据地址偏移 */
    int  len;               /* 数据字节长度,至少为2，第1字节为配置有效性,1为有效 */
    int  authority_flag;    /* 配置项权限， 定义见UC_AUTHORITY_XXX */
    const char *default_data;     /* 配置项默认值,数据为字符串,例如: "0x12,0x34,0x78,0xaa" */
    int (*check_para)(unsigned int buf_size, unsigned char *buf);
};

/*
 * user config配置项
 */
#define CPU_NUM_CONFIG_NAME         "cpu_num_cfg"

#define AUTH_CONFIG_ENABLE_NAME     "sign_auth_enable"
#define AUTH_CONFIG_ENABLE           1
#define AUTH_CONFIG_DISENABLE        0

static int cpu_work_mode_check_para(unsigned int buf_size, unsigned char *buf);
static int cpu_sign_auth_check_para(unsigned int buf_size, unsigned char *buf);

/*
 * default_data字段必须保证，以"0x"开始，每两个字符表示一个字节
 * 例如: 数值0，1表示为 0x0001
 */
static const struct user_config_item user_cfg_version_1[UC_ITEM_MAX_NUM] = {
    {CPU_NUM_CONFIG_NAME, -1, UC_CPU_CFG_OFFSET, UC_CPU_CFG_SIZE, UC_AUTHORITY_USER_WR, "0x01000300", NULL},
    {"mac_info", -1, UC_MAC_INFO_OFFSET, UC_MAC_INFO_SIZE, UC_AUTHORITY_USER_WR, "0x00", NULL},
    {"mac_info_1", -1, UC_MAC_INFO_1_OFFSET, UC_MAC_INFO_1_SIZE, UC_AUTHORITY_USER_WR, "0x00", NULL},
    {"cpu_work_mode", -1, UC_CPU_WORK_MODE_OFFSET, UC_CPU_WORK_MODE_SIZE,
        UC_AUTHORITY_USER_WR, "0x00", cpu_work_mode_check_para},
    {"sign_auth_enable", -1, UC_SIGN_AUTH_ENABLE_OFFSET, UC_SIGN_AUTH_ENABLE_SIZE,
        UC_AUTHORITY_USER_WR, "0x00", cpu_sign_auth_check_para},
};

#define UC_ITEM_INDEX_MAC_INFO          1 /* MAC_INFO在静态表user_cfg_version_1中的INDEX */

/*
 * 用户配置区动态选项
 */
/* 动态配置头地址 */
#define UC_DYNAMIC_CFG_HEAD_OFFSET          0x2000  // 8KB
#define UC_CFG_HEAD_LEN_OFFSET              UC_DYNAMIC_CFG_HEAD_OFFSET
#define UC_CFG_HEAD_BYTES                   4       // 4Bytes
#define UC_CFG_HEAD_ITEM_START              (UC_DYNAMIC_CFG_HEAD_OFFSET + UC_CFG_HEAD_BYTES)
#define UC_CFG_NAME_LEN_MAX                 32
#define UC_SHA256_DIGEST                    32

typedef struct _uc_cfg_head {
    unsigned char item_name[UC_CFG_NAME_LEN_MAX];
    unsigned int blk_offset;
    unsigned int item_offset;
    unsigned int item_bytes;
    unsigned int authority_flg;
    unsigned int valid_flg;
} uc_cfg_head_t;

typedef struct _uc_blk_used_info {
    unsigned char index;
    unsigned char used;
    unsigned short used_len;
} uc_blk_used_info_t;

#define UC_BLK_INFO_OFFSET           (UC_CHECK_FLASH_OFFSET - sizeof(uc_blk_used_info_t)*UC_FLASH_PARTITION_MAIN_NUM)
#define UC_BLK_INFO_BYTES	         (sizeof(uc_blk_used_info_t)*UC_FLASH_PARTITION_MAIN_NUM)
#define UC_ITEM_CONTENT_BLK_START    2
#define UC_BLK_INDEX_MAC_INFO        1
#define UC_ITEM_CONTENT_BLK_OFFSET   0   // first block offset
#define UC_MAC_CNT                   2

#define UC_CPU_WORK_MODE_MAX         2
static int cpu_work_mode_check_para(unsigned int buf_size, unsigned char *buf)
{
    if (buf == NULL) {
        return UC_USER_PARA_ERR;
    }

    if (buf_size + 1 != UC_CPU_WORK_MODE_SIZE) {
        return UC_USER_PARA_ERR;
    }

    if (*buf >= UC_CPU_WORK_MODE_MAX) {
        return UC_USER_PARA_ERR;
    }
    return UC_USER_PARA_OK;
}

static int cpu_sign_auth_check_para(unsigned int buf_size, unsigned char *buf)
{
    if (buf == NULL) {
        return UC_USER_PARA_ERR;
    }

    if (buf_size >= UC_SIGN_AUTH_ENABLE_SIZE) {
        return UC_USER_PARA_ERR;
    }

    if ((buf[0] != AUTH_CONFIG_ENABLE) && (buf[0] != AUTH_CONFIG_DISENABLE)) {
        return UC_USER_PARA_ERR;
    }
    return UC_USER_PARA_OK;
}

#endif
