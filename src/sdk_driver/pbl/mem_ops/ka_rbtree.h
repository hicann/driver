/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2025. All rights reserved.
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

#ifndef KA_RBTREE_H
#define KA_RBTREE_H

#include "ka_base_pub.h"

typedef unsigned long (*rb_handle_func)(ka_rb_node_t *node);

int ka_rb_erase(ka_rb_root_t *root, ka_rb_node_t *node);
int ka_rb_insert(ka_rb_root_t *root, ka_rb_node_t *node, rb_handle_func get_handle);
ka_rb_node_t *ka_rb_search(ka_rb_root_t *root, unsigned long handle, rb_handle_func get_handle);
ka_rb_node_t *ka_rb_erase_one_node(ka_rb_root_t *root);

#endif /* KA_RBTREE_H */
