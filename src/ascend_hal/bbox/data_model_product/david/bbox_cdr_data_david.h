/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef BBOX_CDR_DATA_DAVID_H
#define BBOX_CDR_DATA_DAVID_H

#include "bbox_ddr_data.h"

/**
 *  the whole space is 512k, used for history data record
 *  the struct distribution is as follows:
 *  +-------------------+     +-------------------+
 *  | head info(1k)     |---->| magic             |
 *  +-------------------+     +-------------------+
 *  | MIN region(48k)   |     | version           |
 *  +-------------------+     +-------------------+
 *  | reserved(1k)      |     | reserved[24]      |
 *  +-------------------+     +-------------------+
 *  | FULL region(4M)   |     | area head[6]      |
 *  +-------------------+     +-------------------+
 */
#define DATA_MODEL_CDR_MIN MODEL_VECTOR(CDR_MIN) = { \
    {"Aic Key", ELEM_OUTPUT_R4_BLOCK, {0xC}, {0xb40}}, \
    {"Aiv Key", ELEM_OUTPUT_R4_BLOCK, {0xb4C}, {0x1440}}, \
    {"L2b Key", ELEM_OUTPUT_R4_BLOCK, {0x1f8C}, {0x400}}, \
    {"L3d Key", ELEM_OUTPUT_R4_BLOCK, {0x238C}, {0x80}}, \
    {"L3t Key", ELEM_OUTPUT_R4_BLOCK, {0x240C}, {0x80}}, \
    {"Aa Key", ELEM_OUTPUT_R4_BLOCK, {0x248C}, {0x460}}, \
    {"Disp Key", ELEM_OUTPUT_R4_BLOCK, {0x28EC}, {0x508}}, \
    {"Sdma Key", ELEM_OUTPUT_R4_BLOCK, {0x2DF4}, {0x20}}, \
    {"Cpu Key", ELEM_OUTPUT_R4_BLOCK, {0x2E14}, {0x220}}, \
    {"Mn Key", ELEM_OUTPUT_R4_BLOCK, {0x3034}, {0x70}}, \
    {"Sche Key", ELEM_OUTPUT_R4_BLOCK, {0x30A4}, {0x78}}, \
    {"Asmb Key", ELEM_OUTPUT_R4_BLOCK, {0x311C}, {0x820}}, \
    {"Bailu Key", ELEM_OUTPUT_R4_BLOCK, {0x393C}, {0x540}}, \
    {"Smmu Key", ELEM_OUTPUT_R4_BLOCK, {0x3E7C}, {0x1260}}, \
    {"Ha Key", ELEM_OUTPUT_R4_BLOCK, {0x50DC}, {0x300}}, \
    {"Pcie Key", ELEM_OUTPUT_R4_BLOCK, {0x53DC}, {0x368}}, \
    {"Sllc Key", ELEM_OUTPUT_R4_BLOCK, {0x5744}, {0x1080}}, \
    {"Hscb Key", ELEM_OUTPUT_R4_BLOCK, {0x67C4}, {0x130}}, \
    {"BA Key", ELEM_OUTPUT_R4_BLOCK, {0x68F4}, {0x20a0}}, \
    {"MISC Key", ELEM_OUTPUT_R4_BLOCK, {0x8994}, {0xf28}}, \
    {"NL Key", ELEM_OUTPUT_R4_BLOCK, {0x98BC}, {0x1068}}, \
    {"TA Key", ELEM_OUTPUT_R4_BLOCK, {0xA924}, {0x530}}, \
    {"TP Key", ELEM_OUTPUT_R4_BLOCK, {0xAE54}, {0x1358}}, \
    {"UB_CCU Key", ELEM_OUTPUT_R4_BLOCK, {0xC1AC}, {0x9d8}}, \
    {"UMMU Key", ELEM_OUTPUT_R4_BLOCK, {0xCB84}, {0x1b0}}, \
    {"UCMI Key", ELEM_OUTPUT_R4_BLOCK, {0xCD34}, {0x180}}, \
}

#define DATA_MODEL_CDR_FULL MODEL_VECTOR(CDR_FULL) = { \
    {"AA FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xc}, {0xa87e0}}, \
    {"AIC FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xa87ec}, {0xd890}}, \
    {"AIV FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xb607c}, {0x18d20}}, \
    {"ASMB FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xced9c}, {0x820}}, \
    {"BAILU FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xcf5bc}, {0x16d20}}, \
    {"CPU FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xe62dc}, {0x7020}}, \
    {"CPU FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xed2fc}, {0x7020}}, \
    {"CS FullInfo", ELEM_OUTPUT_R4_BLOCK, {0xf431c}, {0x276e0}}, \
    {"DISP FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x11b9fc}, {0x52a8}}, \
    {"DLPHY FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x120ca4}, {0xe1c8}}, \
    {" EFUSE FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x12ee6c}, {0x4580}}, \
    {"HILINK FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1333ec}, {0x13c20}}, \
    {"HSCB FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x14700c}, {0xc98}}, \
    {"L2B FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x147ca4}, {0x60680}}, \
    {"L3D FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1a8324}, {0xc880}}, \
    {"L3T FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1b4ba4}, {0x10680}}, \
    {"MN FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1c5224}, {0x14880}}, \
    {"PCIE FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1d9aa4}, {0x1070}}, \
    {"PLL FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1dab14}, {0x624}}, \
    {"PMC FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1db138}, {0x1288}}, \
    {"PPU FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1dc3c0}, {0x4af8}}, \
    {"SCHE FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1e0eb8}, {0x1e410}}, \
    {"SDMA FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x1ff2c8}, {0x71e0}}, \
    {"SIOE FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x2064a8}, {0x5d6e0}}, \
    {"SLLC FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x263b88}, {0x90780}}, \
    {"SMMU FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x2f4308}, {0x1892b0}}, \
    {"STARS FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x47d5b8}, {0x9e28}}, \
    {"SUBSTRL FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x4873e0}, {0xa08}}, \
    {"UB_BA FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x487de8}, {0xff88}}, \
    {"UB_CCU FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x497d70}, {0x6318}}, \
    {"UB_MISC FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x49e088}, {0x2360}}, \
    {"UB_NL FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x4a03e8}, {0x32408}}, \
    {"UB_TA FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x4d27f0}, {0xb40}}, \
    {"UB_TP FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x4d3330}, {0x29b8}}, \
    {"UB_UMMU FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x4d5ce8}, {0x1940}}, \
    {"VPC FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x4d7628}, {0x357e0}}, \
    {"HA FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x50ce08}, {0x1a2400}}, \
    {"UCMI FullInfo", ELEM_OUTPUT_R4_BLOCK, {0x6af208}, {0x1b8}}, \
}

#define DATA_MODEL_CDR_SRAM MODEL_VECTOR(CDR_SRAM) = { \
    {"chip dfx min info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"if", ELEM_CTRL_COMPARE, {0x4}, {0x4}}, \
    {"magic", ELEM_CTRL_CMP_JUMP_NE, {0x63686970}, {0xFF}}, \
    {"version", ELEM_OUTPUT_INT, {0x8}, {0x4}}, \
    {"if", ELEM_CTRL_COMPARE, {0x0}, {0x1}}, \
    {"is used", ELEM_CTRL_CMP_JUMP_NE, {0x1}, {0xFF}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"CDR_MIN", ELEM_CTRL_TABLE_GOTO, {0x0}, {0x18000}}, \
    {"table_index", ELEM_CTRL_TABLE_RANGE, {PLAINTEXT_TABLE_CDR_SRAM_MIN}, {0x1}}, \
}

#define DATA_MODEL_CDR MODEL_VECTOR(CDR) = { \
    {"chip dfx info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"if", ELEM_CTRL_COMPARE, {0x0}, {0x4}}, \
    {"magic", ELEM_CTRL_CMP_JUMP_NE, {0x63686970}, {0xFF}}, \
    {"version", ELEM_OUTPUT_INT, {0x4}, {0x4}}, \
    {"trigType", ELEM_OUTPUT_INT, {0x32}, {0x1}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"min info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"if", ELEM_CTRL_COMPARE, {0x40}, {0x1}}, \
    {"is used", ELEM_CTRL_CMP_JUMP_NE, {0x1}, {0x7}}, \
    {"flag", ELEM_OUTPUT_INT, {0x20}, {0x1}}, \
    {"type", ELEM_OUTPUT_INT, {0x21}, {0x1}}, \
    {"offset", ELEM_OUTPUT_INT, {0x28}, {0x4}}, \
    {"length", ELEM_OUTPUT_INT, {0x2C}, {0x4}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"CDR_MIN", ELEM_CTRL_TABLE_GOTO, {0x400}, {0x18300}}, \
    {"table_index", ELEM_CTRL_TABLE_RANGE, {PLAINTEXT_TABLE_CDR_MIN}, {0x1}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"full info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"if", ELEM_CTRL_COMPARE, {0x30}, {0x1}}, \
    {"is used", ELEM_CTRL_CMP_JUMP_NE, {0x1}, {0x7}}, \
    {"flag", ELEM_OUTPUT_INT, {0x30}, {0x1}}, \
    {"type", ELEM_OUTPUT_INT, {0x31}, {0x1}}, \
    {"offset", ELEM_OUTPUT_INT, {0x38}, {0x4}}, \
    {"length", ELEM_OUTPUT_INT, {0x3C}, {0x4}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"CDR_FULL", ELEM_CTRL_TABLE_GOTO, {0x18800}, {0x13FFC00}}, \
    {"table_index", ELEM_CTRL_TABLE_RANGE, {PLAINTEXT_TABLE_CDR_FULL}, {0x1}}, \
}

#define DATA_MODEL_CDR_SRAM_LOOSE MODEL_VECTOR(CDR_SRAM_LOOSE) = { \
    {"chip dfx min info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"if", ELEM_CTRL_COMPARE, {0x4}, {0x4}}, \
    {"magic", ELEM_CTRL_CMP_JUMP_NE, {0x63686970}, {0xFF}}, \
    {"version", ELEM_OUTPUT_INT, {0x8}, {0x4}}, \
    {"flag", ELEM_OUTPUT_INT, {0x0}, {0x1}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"CDR_MIN", ELEM_CTRL_TABLE_GOTO, {0x0}, {0x18000}}, \
    {"table_index", ELEM_CTRL_TABLE_RANGE, {PLAINTEXT_TABLE_CDR_SRAM_MIN}, {0x1}}, \
}

#define DATA_MODEL_CDR_LOOSE MODEL_VECTOR(CDR_LOOSE) = { \
    {"chip dfx info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"if", ELEM_CTRL_COMPARE, {0x0}, {0x4}}, \
    {"magic", ELEM_CTRL_CMP_JUMP_NE, {0x63686970}, {0xFF}}, \
    {"version", ELEM_OUTPUT_INT, {0x4}, {0x4}}, \
    {"trigType", ELEM_OUTPUT_INT, {0x32}, {0x1}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"min info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"flag", ELEM_OUTPUT_INT, {0x20}, {0x1}}, \
    {"type", ELEM_OUTPUT_INT, {0x21}, {0x1}}, \
    {"offset", ELEM_OUTPUT_INT, {0x28}, {0x4}}, \
    {"length", ELEM_OUTPUT_INT, {0x2C}, {0x4}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"CDR_MIN", ELEM_CTRL_TABLE_GOTO, {0x400}, {0x18000}}, \
    {"table_index", ELEM_CTRL_TABLE_RANGE, {PLAINTEXT_TABLE_CDR_MIN}, {0x1}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"full info", ELEM_OUTPUT_DIVIDE, {0x0}, {0x3D}}, \
    {"flag", ELEM_OUTPUT_INT, {0x30}, {0x1}}, \
    {"type", ELEM_OUTPUT_INT, {0x31}, {0x1}}, \
    {"offset", ELEM_OUTPUT_INT, {0x38}, {0x4}}, \
    {"length", ELEM_OUTPUT_INT, {0x3C}, {0x4}}, \
    {"NL", ELEM_OUTPUT_NL, {0x0}, {0x0}}, \
    {"CDR_FULL", ELEM_CTRL_TABLE_GOTO, {0xC800}, {0x800000}}, \
    {"table_index", ELEM_CTRL_TABLE_RANGE, {PLAINTEXT_TABLE_CDR_FULL}, {0x1}}, \
}
#endif
