/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_FRAMEINFO_H__
#define __ISP_FRAMEINFO_H__

#include "hi_comm_isp.h"
#include "hi_comm_video_adapt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

typedef struct {
    hi_isp_frame_info *isp_frame;
} isp_frame_info_ctrl;

typedef struct {
    hi_isp_attach_info *attach_info;
} isp_attach_info_ctrl;

typedef struct {
    hi_isp_colorgammut_info *color_gamut_info;
} isp_gammut_info_ctrl;

typedef struct {
    isp_pro_nr_param *pro_nr_param;
} isp_pro_nr_param_ctrl;

typedef struct {
    isp_pro_shp_param *pro_shp_param;
} isp_pro_shp_param_ctrl;

HI_S32 ISP_TransInfoInit(VI_PIPE vi_pipe, isp_trans_info_buf *trans_info);
HI_S32 ISP_TransInfoExit(VI_PIPE vi_pipe);

HI_S32 ISP_FrameInfoInit(VI_PIPE vi_pipe);
HI_S32 ISP_FrameInfoExit(VI_PIPE vi_pipe);

HI_S32 ISP_AttachInfoInit(VI_PIPE vi_pipe);
HI_S32 ISP_AttachInfoExit(VI_PIPE vi_pipe);

HI_S32 ISP_ColorGamutInfoInit(VI_PIPE vi_pipe);
HI_S32 ISP_ColorGamutInfoExit(VI_PIPE vi_pipe);

HI_S32 ISP_ProInfoInit(VI_PIPE vi_pipe, isp_pro_info_buf *pro_info);
HI_S32 ISP_ProInfoExit(VI_PIPE vi_pipe);

HI_S32 ISP_ProNrParamInit(VI_PIPE vi_pipe);
HI_S32 ISP_ProNrParamExit(VI_PIPE vi_pipe);

HI_S32 ISP_ProShpParamInit(VI_PIPE vi_pipe);
HI_S32 ISP_ProShpParamExit(VI_PIPE vi_pipe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
