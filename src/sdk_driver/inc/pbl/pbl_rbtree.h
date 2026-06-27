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

#ifndef PBL_RBTREE_H
#define PBL_RBTREE_H

#include "ka_base_pub.h"

/* return 0: equal; <0: a < b; >0: a > b */
typedef int (*pbl_rb_compare_of_insert_t)(ka_rb_node_t *tar, ka_rb_node_t *cur);
typedef int (*pbl_rb_compare_of_search_t)(void *handle, ka_rb_node_t *cur);

/* interface */
static inline int pbl_rb_insert(ka_rb_root_t *root, ka_rb_node_t *node, pbl_rb_compare_of_insert_t cmp)
{
    ka_rb_node_t **cur_node = &root->rb_node, *parent = NULL;
    int cmp_result;

    while (*cur_node) {
        parent = *cur_node;

        cmp_result = cmp(node, parent);
        if (cmp_result < 0) {
            cur_node = ka_base_get_rb_node_left_addr(parent);
        } else if (cmp_result > 0) {
            cur_node = ka_base_get_rb_node_right_addr(parent);
        } else {
            return -EINVAL;
        }
    }

    ka_base_rb_link_node(node, parent, cur_node);
    ka_base_rb_insert_color(node, root);
    return 0;
}

/* interface */
static inline int pbl_rb_erase(ka_rb_root_t *root, ka_rb_node_t *node)
{
    int ret = -ENODEV;

    if (!KA_BASE_RB_EMPTY_NODE(node)) {
        ka_base_rb_erase(node, root);
        KA_BASE_RB_CLEAR_NODE(node);
        ret = 0;
    }
    return ret;
}

/* interface */
static inline ka_rb_node_t *pbl_rb_search(ka_rb_root_t *root, void *handle, pbl_rb_compare_of_search_t cmp)
{
    ka_rb_node_t *cur_node = root->rb_node;

    while (cur_node) {
        int cmp_result = cmp(handle, cur_node);
        if (cmp_result < 0) {
            cur_node = ka_base_get_rb_node_left(cur_node);
        } else if (cmp_result > 0) {
            cur_node = ka_base_get_rb_node_right(cur_node);
        } else {
            return cur_node;
        }
    }
    return NULL;
}

#endif