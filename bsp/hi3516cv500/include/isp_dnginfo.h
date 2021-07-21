/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_DNGINFO_H__
#define __ISP_DNGINFO_H__

#include "hi_comm_isp_adapt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

typedef struct {
    hi_isp_dng_image_static_info *isp_dng;
} isp_dng_info_ctrl;

typedef struct {
    hi_double a_color_matrix[9];
    hi_double d50_color_matrix[9];
    hi_double a_forward_matrix[9];
    hi_double d50_forward_matrix[9];
} dng_matrix;

HI_S32 ISP_UpdateDngImageDynamicInfo(VI_PIPE vi_pipe);

HI_S32 ISP_DngInfoInit(VI_PIPE vi_pipe);
HI_S32 ISP_DngInfoExit(VI_PIPE vi_pipe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
