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

#include "ka_rbtree.h"

int ka_rb_erase(ka_rb_root_t *root, ka_rb_node_t *node)
{
    int ret = -ENODEV;

    if (KA_BASE_RB_EMPTY_NODE(node) == false) {
        ka_base_rb_erase(node, root);
        KA_BASE_RB_CLEAR_NODE(node);
        ret = 0;
    }

    return ret;
}

int ka_rb_insert(ka_rb_root_t *root, ka_rb_node_t *node, rb_handle_func get_handle)
{
    ka_rb_node_t **cur_node = ka_base_get_rb_root_node_addr(root);
    ka_rb_node_t *parent = NULL;
    unsigned long handle = get_handle(node);

    /* Figure out where to put new node */
    while (*cur_node) {
        unsigned long tmp_handle = get_handle(*cur_node);

        parent = *cur_node;
        if (handle < tmp_handle) {
            cur_node = ka_base_get_rb_node_left_addr(*cur_node);
        } else if (handle > tmp_handle) {
            cur_node = ka_base_get_rb_node_right_addr(*cur_node);
        } else {
            return -EINVAL;
        }
    }

    /* Add new node and rebalance tree. */
    ka_base_rb_link_node(node, parent, cur_node);
    ka_base_rb_insert_color(node, root);
    return 0;
}

ka_rb_node_t *ka_rb_search(ka_rb_root_t *root, unsigned long handle, rb_handle_func get_handle)
{
    ka_rb_node_t *node = NULL;

    node = ka_base_get_rb_root_node(root);
    while (node != NULL) {
        unsigned long tmp_handle = get_handle(node);
        if (handle < tmp_handle) {
            node = ka_base_get_rb_node_left(node);
        } else if (handle > tmp_handle) {
            node = ka_base_get_rb_node_right(node);
        } else {
            return node;
        }
    }

    return NULL;
}

ka_rb_node_t *ka_rb_erase_one_node(ka_rb_root_t *root)
{
    ka_rb_node_t *node = NULL;

    if (KA_BASE_RB_EMPTY_ROOT(root) == true) {
        return NULL;
    }
    node = ka_base_rb_first(root);
    if (node != NULL) {
        ka_base_rb_erase(node, root);
        KA_BASE_RB_CLEAR_NODE(node);
    }
    return node;
}
