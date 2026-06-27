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

#include "ka_memory_pub.h"
#include "ka_system_pub.h"
#include "ka_common_pub.h"
#include "ka_sched_pub.h"

#include "pbl_feature_loader.h"
#include "pbl_chip_config.h"

#include "svm_kern_log.h"
#include "svm_gfp.h"
#include "svm_pub.h"
#include "svm_slab.h"
#include "normal_page.h"

#define SVM_2M_CONT_PAGE_NUM (2 * SVM_BYTES_PER_MB / KA_MM_PAGE_SIZE)
#define SVM_64K_CONT_PAGE_NUM (64 * SVM_BYTES_PER_KB / KA_MM_PAGE_SIZE)

static void svm_clear_normal_single_page(ka_page_t *pg) { svm_clear_single_page(pg, KA_MM_PAGE_SIZE); }

static void svm_clear_compound_page(ka_page_t *pg)
{
    unsigned long stamp = (unsigned long)ka_jiffies;
    ka_page_t *head_page = ka_mm_compound_head(pg);
    unsigned int order = ka_mm_compound_order(head_page);
    u64 pg_num = 1 << order;
    u64 i;

    for (i = 0; i < pg_num; i++) {
        ka_try_cond_resched(&stamp);
        svm_clear_single_page(head_page + i, KA_MM_PAGE_SIZE);
    }
}

static inline void svm_put_page(ka_page_t *pg) { ka_mm_put_page(pg); }

static void svm_free_normal_page(ka_page_t *pg, u32 flag)
{
    if (ka_mm_PageCompound(pg) == 0) {
        svm_page_ref_dec(pg, (svm_page_is_need_clear(flag) ? svm_clear_normal_single_page : NULL), svm_put_page);
    } else {
        svm_page_ref_dec(pg, (svm_page_is_need_clear(flag) ? svm_clear_compound_page : NULL), svm_put_page);
    }
}

static void svm_free_normal_pages(ka_page_t **pages, u64 page_num, u32 flag)
{
    unsigned long stamp = ka_jiffies;
    u64 i;

    for (i = 0; i < page_num; i++) {
        svm_free_normal_page(pages[i], flag);
        ka_try_cond_resched(&stamp);
    }
}

static int svm_alloc_pages_node(int nid, ka_page_t **pages, u64 pg_num, u32 flag)
{
    unsigned long stamp = (unsigned long)ka_jiffies;
    bool no_retry = !svm_page_is_continuous(flag) && !svm_page_is_continuous_per_2M(flag);
    ka_gfp_t gfp_mask = svm_get_alloc_page_mask(true, no_retry);
    ka_page_t *comp_pg_head = NULL;
    ka_page_t *pg = NULL;
    u64 i;

    /* Because is comp page, pg_num should be power of 2. */
    if (ka_mm_is_power_of_2(pg_num) == false) {
        return -EINVAL;
    }

    comp_pg_head = _svm_alloc_pages_node(nid, gfp_mask, ka_mm_get_order(pg_num << KA_MM_PAGE_SHIFT));
    if (comp_pg_head == NULL) {
        return -ENOMEM;
    }

    for (i = 0, pg = comp_pg_head; i < pg_num; pg++, i++) {
        ka_try_cond_resched(&stamp);
        pages[i] = pg;
        if (i != 0) {
            ka_mm_get_page(pages[i]);
        }
    }

    return 0;
}

static int svm_alloc_continous_pages(int *latest_nid, int nids[], u32 nid_num, ka_page_t **pages, u64 pg_num, u32 flag)
{
    unsigned long stamp = (unsigned long)ka_jiffies;
    int ret, i;

    ret = svm_alloc_pages_node(*latest_nid, pages, pg_num, flag);
    if (ret == 0) {
        return 0;
    }

    for (i = 0; i < nid_num; i++) {
        ka_try_cond_resched(&stamp);
        if (nids[i] == *latest_nid) {
            continue;
        }
        ret = svm_alloc_pages_node(nids[i], pages, pg_num, flag);
        if (ret == 0) {
            *latest_nid = nids[i];
            return 0;
        }
    }

    return -ENOMEM;
}

/* Alloc continuous cont_num pages, and return got_num. */
static u64 svm_try_alloc_cont_pages(
    int *latest_nid, int nids[], u32 nid_num, ka_page_t **pages, u64 pg_num, u64 cont_num, u32 flag)
{
    unsigned long stamp = ka_jiffies;
    u64 num, i = 0;
    int ret;

    for (i = 0; i < pg_num; i += num) {
        num = ka_base_min(cont_num, (pg_num - i));
        ret = svm_alloc_continous_pages(latest_nid, nids, nid_num, &pages[i], num, flag);
        if (ret != 0) {
            return i;
        }
        ka_try_cond_resched(&stamp);
    }

    return pg_num;
}

static int svm_alloc_normal_pages_one_by_one(
    int *latest_nid, int nids[], u32 nid_num, ka_page_t **pages, u64 pg_num, u32 flag)
{
    unsigned long stamp = ka_jiffies;
    u64 i;
    int ret;

    for (i = 0; i < pg_num; i++) {
        ret = svm_alloc_continous_pages(latest_nid, nids, nid_num, &pages[i], 1, flag);
        if (ret != 0) {
            svm_free_normal_pages(pages, i, 0);
            return -ENOMEM;
        }
        ka_try_cond_resched(&stamp);
    }

    return 0;
}

/* Try alloc continuous pages every 2MB, then try 64KB. */
static u64 _svm_try_alloc_continous_pages(
    int *latest_nid, int nids[], u32 nid_num, ka_page_t **pages, u64 pg_num, u32 flag)
{
    u64 got_num_2m = 0, got_num_64k = 0;

    got_num_2m = svm_try_alloc_cont_pages(latest_nid, nids, nid_num, pages, pg_num, SVM_2M_CONT_PAGE_NUM, flag);
    if (got_num_2m == pg_num) {
        return pg_num;
    }

#if (KA_MM_PAGE_SIZE < (64ULL * SVM_BYTES_PER_KB))
    got_num_64k = svm_try_alloc_cont_pages(
        latest_nid, nids, nid_num, &pages[got_num_2m], pg_num - got_num_2m, SVM_64K_CONT_PAGE_NUM, flag);
#endif

    return got_num_2m + got_num_64k;
}

/* The returned pages is not necessarily continuous, but is as continuous as possible. */
static int svm_try_alloc_continous_pages(int nids[], u32 nid_num, ka_page_t **pages, u64 pg_num, u32 flag)
{
    int latest_nid = nids[0];
    u64 got_num;
    int ret;

    got_num = _svm_try_alloc_continous_pages(&latest_nid, nids, nid_num, pages, pg_num, flag);
    if (got_num == pg_num) {
        return 0;
    }

    ret = svm_alloc_normal_pages_one_by_one(&latest_nid, nids, nid_num, &pages[got_num], pg_num - got_num, flag);
    if (ret != 0) {
        svm_free_normal_pages(pages, got_num, 0);
    }

    return ret;
}

static int svm_alloc_continous_pages_per_2M(
    int *latest_nid, int nids[], u32 nid_num, ka_page_t **pages, u64 pg_num, u32 flag)
{
    u64 got_num = 0;

    got_num = svm_try_alloc_cont_pages(latest_nid, nids, nid_num, pages, pg_num, SVM_2M_CONT_PAGE_NUM, flag);
    if (got_num != pg_num) {
        svm_free_normal_pages(pages, got_num, 0);
        return -ENOMEM;
    }

    return 0;
}

static int svm_alloc_normal_pages(int nids[], u32 nid_num, ka_page_t **pages, u64 page_num, u32 flag)
{
    int latest_nid = nids[0];

    if (svm_page_is_continuous(flag)) {
        return svm_alloc_continous_pages(&latest_nid, nids, nid_num, pages, page_num, flag);
    } else if (svm_page_is_continuous_per_2M(flag)) {
        return svm_alloc_continous_pages_per_2M(&latest_nid, nids, nid_num, pages, page_num, flag);
    }

    return svm_try_alloc_continous_pages(nids, nid_num, pages, page_num, flag);
}

static const struct svm_page_ops normal_page_ops = {
    .alloc = svm_alloc_normal_pages,
    .free = svm_free_normal_pages,
};

int svm_normal_page_init(void)
{
    svm_register_page_ops(SVM_PAGE_GRAN_NORMAL, &normal_page_ops);
    return 0;
}
DECLAER_FEATURE_AUTO_INIT(svm_normal_page_init, FEATURE_LOADER_STAGE_0);