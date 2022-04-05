////////////////////////////////////////////////////////////////////////////////
//
// The University of Illinois/NCSA
// Open Source License (NCSA)
//
// Copyright (c) 2022, Advanced Micro Devices, Inc. All rights reserved.
//
// Developed by:
//
//                 AMD Research and AMD HSA Software Development
//
//                 Advanced Micro Devices, Inc.
//
//                 www.amd.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal with the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
//  - Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimers.
//  - Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimers in
//    the documentation and/or other materials provided with the distribution.
//  - Neither the names of Advanced Micro Devices, Inc,
//    nor the names of its contributors may be used to endorse or promote
//    products derived from this Software without specific prior written
//    permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS WITH THE SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef OPENSRC_HSA_RUNTIME_CORE_INC_AMD_BLIT_SHADERS_H_ 
#define OPENSRC_HSA_RUNTIME_CORE_INC_AMD_BLIT_SHADERS_H_

namespace rocr {
namespace AMD {

static const unsigned int kCodeCopyAligned7[] = {
    0xC0820100, 0xC0840104, 0xC0860108, 0xC088010C, 0xC08A0110, 0xC00C0114,
    0xBF8C007F, 0x8F028602, 0x4A000002, 0x7E060205, 0xD24A6A02, 0x00000900,
    0xD2506A03, 0x01A90103, 0x7E0A0207, 0xD24A6A04, 0x00000D00, 0xD2506A05,
    0x01A90105, 0xD1C2006A, 0x00001102, 0xBF86000F, 0x87FE6A7E, 0xDC200000,
    0x01000002, 0xBF8C0F70, 0xD24A6A02, 0x00003102, 0xD2506A03, 0x01A90103,
    0xDC600000, 0x00000104, 0xD24A6A04, 0x00003104, 0xD2506A05, 0x01A90105,
    0xBF82FFEE, 0xBEFE04C1, 0x8F198418, 0x34020084, 0x7E060209, 0xD24A6A02,
    0x00001101, 0xD2506A03, 0x01A90103, 0x7E0A020B, 0xD24A6A04, 0x00001501,
    0xD2506A05, 0x01A90105, 0xD1C2006A, 0x00001902, 0xBF86000E, 0xDC380000,
    0x08000002, 0xD24A6A02, 0x00003302, 0xD2506A03, 0x01A90103, 0xBF8C0F70,
    0xDC780000, 0x00000804, 0xD24A6A04, 0x00003304, 0xD2506A05, 0x01A90105,
    0xBF82FFEF, 0x8F198218, 0x34020082, 0x7E06020D, 0xD24A6A02, 0x00001901,
    0xD2506A03, 0x01A90103, 0x7E0A020F, 0xD24A6A04, 0x00001D01, 0xD2506A05,
    0x01A90105, 0xD1C2006A, 0x00002102, 0xBF86000F, 0x87FE6A7E, 0xDC300000,
    0x01000002, 0xD24A6A02, 0x00003302, 0xD2506A03, 0x01A90103, 0xBF8C0F70,
    0xDC700000, 0x00000104, 0xD24A6A04, 0x00003304, 0xD2506A05, 0x01A90105,
    0xBF82FFEE, 0xBEFE04C1, 0x7E060211, 0xD24A6A02, 0x00002100, 0xD2506A03,
    0x01A90103, 0x7E0A0213, 0xD24A6A04, 0x00002500, 0xD2506A05, 0x01A90105,
    0xD1C2006A, 0x00002902, 0xBF860006, 0x87FE6A7E, 0xDC200000, 0x01000002,
    0xBF8C0F70, 0xDC600000, 0x00000104, 0xBF810000,
};

static const unsigned int kCodeCopyMisaligned7[] = {
    0xC0820100, 0xC0840104, 0xC0860108, 0xC008010C, 0xBF8C007F, 0x8F028602,
    0x4A000002, 0x7E060205, 0xD24A6A02, 0x00000900, 0xD2506A03, 0x01A90103,
    0x7E0A0207, 0xD24A6A04, 0x00000D00, 0xD2506A05, 0x01A90105, 0xD1C2006A,
    0x00001102, 0xBF860032, 0xDC200000, 0x06000002, 0xD24A6A02, 0x00002102,
    0xD2506A03, 0x01A90103, 0xDC200000, 0x07000002, 0xD24A6A02, 0x00002102,
    0xD2506A03, 0x01A90103, 0xDC200000, 0x08000002, 0xD24A6A02, 0x00002102,
    0xD2506A03, 0x01A90103, 0xDC200000, 0x09000002, 0xD24A6A02, 0x00002102,
    0xD2506A03, 0x01A90103, 0xBF8C0F70, 0xDC600000, 0x00000604, 0xD24A6A04,
    0x00002104, 0xD2506A05, 0x01A90105, 0xDC600000, 0x00000704, 0xD24A6A04,
    0x00002104, 0xD2506A05, 0x01A90105, 0xDC600000, 0x00000804, 0xD24A6A04,
    0x00002104, 0xD2506A05, 0x01A90105, 0xDC600000, 0x00000904, 0xD24A6A04,
    0x00002104, 0xD2506A05, 0x01A90105, 0xBF82FFCB, 0x7E060209, 0xD24A6A02,
    0x00001100, 0xD2506A03, 0x01A90103, 0x7E0A020B, 0xD24A6A04, 0x00001500,
    0xD2506A05, 0x01A90105, 0xD1C2006A, 0x00001902, 0xBF86000F, 0x87FE6A7E,
    0xDC200000, 0x01000002, 0xD24A6A02, 0x00002102, 0xD2506A03, 0x01A90103,
    0xBF8C0F70, 0xDC600000, 0x00000104, 0xD24A6A04, 0x00002104, 0xD2506A05,
    0x01A90105, 0xBF82FFEE, 0xBF810000,
};

static const unsigned int kCodeFill7[] = {
    0xC0820100, 0xC0840104, 0xBF8C007F, 0x8F028602, 0x4A000002, 0x7E08020A,
    0x7E0A020A, 0x7E0C020A, 0x7E0E020A, 0x8F0C840B, 0x34020084, 0x7E060205,
    0xD24A6A02, 0x00000901, 0xD2506A03, 0x01A90103, 0xD1C2006A, 0x00000D02,
    0xBF860007, 0xDC780000, 0x00000402, 0xD24A6A02, 0x00001902, 0xD2506A03,
    0x01A90103, 0xBF82FFF6, 0x8F0C820B, 0x34020082, 0x7E060207, 0xD24A6A02,
    0x00000D01, 0xD2506A03, 0x01A90103, 0xD1C2006A, 0x00001102, 0xBF860008,
    0x87FE6A7E, 0xDC700000, 0x00000402, 0xD24A6A02, 0x00001902, 0xD2506A03,
    0x01A90103, 0xBF82FFF5, 0xBF810000,
};

static const unsigned int kCodeCopyAligned8[] = {
    0xC00A0100, 0x00000000, 0xC00A0200, 0x00000010, 0xC00A0300, 0x00000020,
    0xC00A0400, 0x00000030, 0xC00A0500, 0x00000040, 0xC0020600, 0x00000050,
    0xBF8C007F, 0x8E028602, 0x32000002, 0x7E060205, 0xD1196A02, 0x00000900,
    0xD11C6A03, 0x01A90103, 0x7E0A0207, 0xD1196A04, 0x00000D00, 0xD11C6A05,
    0x01A90105, 0xD0E9006A, 0x00001102, 0xBF86000F, 0x86FE6A7E, 0xDC400000,
    0x01000002, 0xBF8C0F70, 0xD1196A02, 0x00003102, 0xD11C6A03, 0x01A90103,
    0xDC600000, 0x00000104, 0xD1196A04, 0x00003104, 0xD11C6A05, 0x01A90105,
    0xBF82FFEE, 0xBEFE01C1, 0x8E198418, 0x24020084, 0x7E060209, 0xD1196A02,
    0x00001101, 0xD11C6A03, 0x01A90103, 0x7E0A020B, 0xD1196A04, 0x00001501,
    0xD11C6A05, 0x01A90105, 0xD0E9006A, 0x00001902, 0xBF86000E, 0xDC5C0000,
    0x08000002, 0xD1196A02, 0x00003302, 0xD11C6A03, 0x01A90103, 0xBF8C0F70,
    0xDC7C0000, 0x00000804, 0xD1196A04, 0x00003304, 0xD11C6A05, 0x01A90105,
    0xBF82FFEF, 0x8E198218, 0x24020082, 0x7E06020D, 0xD1196A02, 0x00001901,
    0xD11C6A03, 0x01A90103, 0x7E0A020F, 0xD1196A04, 0x00001D01, 0xD11C6A05,
    0x01A90105, 0xD0E9006A, 0x00002102, 0xBF86000F, 0x86FE6A7E, 0xDC500000,
    0x01000002, 0xD1196A02, 0x00003302, 0xD11C6A03, 0x01A90103, 0xBF8C0F70,
    0xDC700000, 0x00000104, 0xD1196A04, 0x00003304, 0xD11C6A05, 0x01A90105,
    0xBF82FFEE, 0xBEFE01C1, 0x7E060211, 0xD1196A02, 0x00002100, 0xD11C6A03,
    0x01A90103, 0x7E0A0213, 0xD1196A04, 0x00002500, 0xD11C6A05, 0x01A90105,
    0xD0E9006A, 0x00002902, 0xBF860006, 0x86FE6A7E, 0xDC400000, 0x01000002,
    0xBF8C0F70, 0xDC600000, 0x00000104, 0xBF810000,
};

static const unsigned int kCodeCopyMisaligned8[] = {
    0xC00A0100, 0x00000000, 0xC00A0200, 0x00000010, 0xC00A0300, 0x00000020,
    0xC0020400, 0x00000030, 0xBF8C007F, 0x8E028602, 0x32000002, 0x7E060205,
    0xD1196A02, 0x00000900, 0xD11C6A03, 0x01A90103, 0x7E0A0207, 0xD1196A04,
    0x00000D00, 0xD11C6A05, 0x01A90105, 0xD0E9006A, 0x00001102, 0xBF860032,
    0xDC400000, 0x06000002, 0xD1196A02, 0x00002102, 0xD11C6A03, 0x01A90103,
    0xDC400000, 0x07000002, 0xD1196A02, 0x00002102, 0xD11C6A03, 0x01A90103,
    0xDC400000, 0x08000002, 0xD1196A02, 0x00002102, 0xD11C6A03, 0x01A90103,
    0xDC400000, 0x09000002, 0xD1196A02, 0x00002102, 0xD11C6A03, 0x01A90103,
    0xBF8C0F70, 0xDC600000, 0x00000604, 0xD1196A04, 0x00002104, 0xD11C6A05,
    0x01A90105, 0xDC600000, 0x00000704, 0xD1196A04, 0x00002104, 0xD11C6A05,
    0x01A90105, 0xDC600000, 0x00000804, 0xD1196A04, 0x00002104, 0xD11C6A05,
    0x01A90105, 0xDC600000, 0x00000904, 0xD1196A04, 0x00002104, 0xD11C6A05,
    0x01A90105, 0xBF82FFCB, 0x7E060209, 0xD1196A02, 0x00001100, 0xD11C6A03,
    0x01A90103, 0x7E0A020B, 0xD1196A04, 0x00001500, 0xD11C6A05, 0x01A90105,
    0xD0E9006A, 0x00001902, 0xBF86000F, 0x86FE6A7E, 0xDC400000, 0x01000002,
    0xD1196A02, 0x00002102, 0xD11C6A03, 0x01A90103, 0xBF8C0F70, 0xDC600000,
    0x00000104, 0xD1196A04, 0x00002104, 0xD11C6A05, 0x01A90105, 0xBF82FFEE,
    0xBF810000,
};

static const unsigned int kCodeFill8[] = {
    0xC00A0100, 0x00000000, 0xC00A0200, 0x00000010, 0xBF8C007F, 0x8E028602,
    0x32000002, 0x7E08020A, 0x7E0A020A, 0x7E0C020A, 0x7E0E020A, 0x8E0C840B,
    0x24020084, 0x7E060205, 0xD1196A02, 0x00000901, 0xD11C6A03, 0x01A90103,
    0xD0E9006A, 0x00000D02, 0xBF860007, 0xDC7C0000, 0x00000402, 0xD1196A02,
    0x00001902, 0xD11C6A03, 0x01A90103, 0xBF82FFF6, 0x8E0C820B, 0x24020082,
    0x7E060207, 0xD1196A02, 0x00000D01, 0xD11C6A03, 0x01A90103, 0xD0E9006A,
    0x00001102, 0xBF860008, 0x86FE6A7E, 0xDC700000, 0x00000402, 0xD1196A02,
    0x00001902, 0xD11C6A03, 0x01A90103, 0xBF82FFF5, 0xBF810000,
};

static const unsigned int kCodeCopyAligned10[] = {
    0xF4080100, 0xFA000000, 0xF4080200, 0xFA000010, 0xF4080300, 0xFA000020,
    0xF4080400, 0xFA000030, 0xF4080500, 0xFA000040, 0xF4000600, 0xFA000050,
    0xBF8CC07F, 0x8F028602, 0xD70F6A00, 0x00020002, 0x7E060205, 0xD70F6A02,
    0x00020004, 0xD5286A03, 0x01A90103, 0x7E0A0207, 0xD70F6A04, 0x00020006,
    0xD5286A05, 0x01A90105, 0xD4E1006A, 0x00001102, 0xBF86000F, 0x87FE6A7E,
    0xDC200000, 0x017D0002, 0xBF8C3F70, 0xD70F6A02, 0x00020418, 0xD5286A03,
    0x01A90103, 0xDC600000, 0x007D0104, 0xD70F6A04, 0x00020818, 0xD5286A05,
    0x01A90105, 0xBF82FFEE, 0xBEFE04C1, 0x8F198418, 0x34020084, 0x7E060209,
    0xD70F6A02, 0x00020208, 0xD5286A03, 0x01A90103, 0x7E0A020B, 0xD70F6A04,
    0x0002020A, 0xD5286A05, 0x01A90105, 0xD4E1006A, 0x00001902, 0xBF86000E,
    0xDC380000, 0x087D0002, 0xD70F6A02, 0x00020419, 0xD5286A03, 0x01A90103,
    0xBF8C3F70, 0xDC780000, 0x007D0804, 0xD70F6A04, 0x00020819, 0xD5286A05,
    0x01A90105, 0xBF82FFEF, 0x8F198218, 0x34020082, 0x7E06020D, 0xD70F6A02,
    0x0002020C, 0xD5286A03, 0x01A90103, 0x7E0A020F, 0xD70F6A04, 0x0002020E,
    0xD5286A05, 0x01A90105, 0xD4E1006A, 0x00002102, 0xBF86000F, 0x87FE6A7E,
    0xDC300000, 0x017D0002, 0xD70F6A02, 0x00020419, 0xD5286A03, 0x01A90103,
    0xBF8C3F70, 0xDC700000, 0x007D0104, 0xD70F6A04, 0x00020819, 0xD5286A05,
    0x01A90105, 0xBF82FFEE, 0xBEFE04C1, 0x7E060211, 0xD70F6A02, 0x00020010,
    0xD5286A03, 0x01A90103, 0x7E0A0213, 0xD70F6A04, 0x00020012, 0xD5286A05,
    0x01A90105, 0xD4E1006A, 0x00002902, 0xBF860006, 0x87FE6A7E, 0xDC200000,
    0x017D0002, 0xBF8C3F70, 0xDC600000, 0x007D0104, 0xBF810000,
};

static const unsigned int kCodeCopyMisaligned10[] = {
    0xF4080100, 0xFA000000, 0xF4080200, 0xFA000010, 0xF4080300, 0xFA000020,
    0xF4000400, 0xFA000030, 0xBF8CC07F, 0x8F028602, 0xD70F6A00, 0x00020002,
    0x7E060205, 0xD70F6A02, 0x00020004, 0xD5286A03, 0x01A90103, 0x7E0A0207,
    0xD70F6A04, 0x00020006, 0xD5286A05, 0x01A90105, 0xD4E1006A, 0x00001102,
    0xBF860032, 0xDC200000, 0x067D0002, 0xD70F6A02, 0x00020410, 0xD5286A03,
    0x01A90103, 0xDC200000, 0x077D0002, 0xD70F6A02, 0x00020410, 0xD5286A03,
    0x01A90103, 0xDC200000, 0x087D0002, 0xD70F6A02, 0x00020410, 0xD5286A03,
    0x01A90103, 0xDC200000, 0x097D0002, 0xD70F6A02, 0x00020410, 0xD5286A03,
    0x01A90103, 0xBF8C3F70, 0xDC600000, 0x007D0604, 0xD70F6A04, 0x00020810,
    0xD5286A05, 0x01A90105, 0xDC600000, 0x007D0704, 0xD70F6A04, 0x00020810,
    0xD5286A05, 0x01A90105, 0xDC600000, 0x007D0804, 0xD70F6A04, 0x00020810,
    0xD5286A05, 0x01A90105, 0xDC600000, 0x007D0904, 0xD70F6A04, 0x00020810,
    0xD5286A05, 0x01A90105, 0xBF82FFCB, 0x7E060209, 0xD70F6A02, 0x00020008,
    0xD5286A03, 0x01A90103, 0x7E0A020B, 0xD70F6A04, 0x0002000A, 0xD5286A05,
    0x01A90105, 0xD4E1006A, 0x00001902, 0xBF86000F, 0x87FE6A7E, 0xDC200000,
    0x017D0002, 0xD70F6A02, 0x00020410, 0xD5286A03, 0x01A90103, 0xBF8C3F70,
    0xDC600000, 0x007D0104, 0xD70F6A04, 0x00020810, 0xD5286A05, 0x01A90105,
    0xBF82FFEE, 0xBF810000,
};

static const unsigned int kCodeFill10[] = {
    0xF4080100, 0xFA000000, 0xF4080200, 0xFA000010, 0xBF8CC07F, 0x8F028602,
    0xD70F6A00, 0x00020002, 0x7E08020A, 0x7E0A020A, 0x7E0C020A, 0x7E0E020A,
    0x8F0C840B, 0x34020084, 0x7E060205, 0xD70F6A02, 0x00020204, 0xD5286A03,
    0x01A90103, 0xD4E1006A, 0x00000D02, 0xBF860007, 0xDC780000, 0x007D0402,
    0xD70F6A02, 0x0002040C, 0xD5286A03, 0x01A90103, 0xBF82FFF6, 0x8F0C820B,
    0x34020082, 0x7E060207, 0xD70F6A02, 0x00020206, 0xD5286A03, 0x01A90103,
    0xD4E1006A, 0x00001102, 0xBF860008, 0x87FE6A7E, 0xDC700000, 0x007D0402,
    0xD70F6A02, 0x0002040C, 0xD5286A03, 0x01A90103, 0xBF82FFF5, 0xBF810000,
};

}  // namespace AMD
}  // namespace rocr

#endif // OPENSRC_HSA_RUNTIME_CORE_INC_AMD_BLIT_SHADERS_H_
