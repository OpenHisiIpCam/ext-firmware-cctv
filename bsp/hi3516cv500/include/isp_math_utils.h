/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/


#ifndef __ISP_MATH_UTILS_H__
#define __ISP_MATH_UTILS_H__

#include "hi_type.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#define ISP_BITMASK(bit)      ((1 << (bit)) - 1)
#define ISP_BITFIX(bit)       ((1 << (bit)))
#define ISP_SQR(x)            ((x) * (x))

HI_U8  sqrt16(hi_u32 arg);
HI_U8  log16(hi_u32 arg);
HI_U16 Sqrt32(hi_u32 arg);
HI_S32 LinearInter(hi_s32 v, hi_s32 x0, hi_s32 y0, hi_s32 x1, hi_s32 y1);
HI_S32 CalcMulCoef(hi_s32 x0, hi_s32 y0, hi_s32 x1, hi_s32 y1, hi_u8 sft);
HI_U32 math_log2(const hi_u32 val, const hi_u8 out_precision, const hi_u8 shift_out);
HI_U32 log2_int_to_fixed(const hi_u32 val, const hi_u8 out_precision, const hi_u8 shift_out);
HI_U32 math_exp2(hi_u32 val, const unsigned char shift_in, const unsigned char shift_out);
HI_S32 solving_lin_equation_a(hi_s32 y1, hi_s32 y2, hi_s32 x1, hi_s32 x2, hi_s16 a_fraction_size);
HI_S32 solving_lin_equation_b(hi_s32 y1, hi_s32 a, hi_s32 x1, hi_s16 a_fraction_size);
HI_U32 div_fixed(hi_u32 a, hi_u32 b, const hi_u16 fraction_size);
HI_S32 solving_nth_root_045(hi_s32 x, const hi_u16 fraction_size);
HI_U32 transition(hi_u32 *lut_in, hi_u32 *lut_out, hi_u32 lut_size, hi_u32 value, hi_u32 value_fraction_size);
HI_S64 SignedRightShift(hi_s64 value, hi_u8 bit_shift);
HI_S64 SignedLeftShift(hi_s64 value, hi_u8 bit_shift);
void MemsetU16(hi_u16 *vir, hi_u16 temp, hi_u32 size);
void MemsetU32(hi_u32 *vir, hi_u32 temp, hi_u32 size);

HI_U8 GetIsoIndex(hi_u32 iso);

void *ISP_MALLOC(unsigned long size);
#define ISP_FREE(ptr)         \
    do {                      \
        if (ptr != HI_NULL) { \
            free(ptr);        \
            ptr = HI_NULL;    \
        }                     \
    } while (0)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif  // __ISP_MATH_UTILS_H__
