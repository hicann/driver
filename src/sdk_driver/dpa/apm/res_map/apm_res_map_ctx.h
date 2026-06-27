/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2026. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
#ifndef APM_RES_MAP_CTX_H
#define APM_RES_MAP_CTX_H

#include "ka_base_pub.h"
#include "ka_common_pub.h"

#include "pbl/pbl_task_ctx.h"
#include "pbl/pbl_rbtree.h"

#include "ascend_hal_define.h"
#include "apm_proc_fs.h"
#include "apm_kern_log.h"
#include "apm_kernel_msg.h"

struct apm_res_map_node {
    ka_rb_node_t rb_node;
    struct apm_res_map_info ctx;
};

struct apm_res_map_ctx {
    ka_proc_dir_entry_t *entry;
    ka_rb_root_t rb_root;
};

int apm_res_map_ctx_create(struct task_ctx_domain *domain, int tgid);
void apm_res_map_ctx_destroy(struct task_ctx_domain *domain, int tgid);
int apm_res_map_add_node(struct task_ctx_domain *domain, int tgid, struct apm_res_map_info *para);
int apm_res_map_del_node(struct task_ctx_domain *domain, int tgid, struct apm_res_map_info *para);
int apm_res_map_query_node(struct task_ctx_domain *domain, int tgid, struct apm_res_map_info *para);
void apm_res_map_ctx_show(struct task_ctx_domain *domain, int tgid, ka_seq_file_t *seq);
void apm_res_map_free_node_pa_array(struct apm_res_map_info *res_map_info);

#endif
