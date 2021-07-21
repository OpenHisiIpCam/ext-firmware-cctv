/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_DCFINFO_H__
#define __ISP_DCFINFO_H__

#include "hi_comm_isp.h"
#include "hi_comm_video_adapt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

typedef struct {
    hi_isp_dcf_const_info  *isp_dcf_const_info;
    hi_isp_dcf_update_info *isp_update_info;
} isp_update_info_ctrl;

HI_S32 ISP_UpdateInfoInit(VI_PIPE vi_pipe);
HI_S32 ISP_UpdateInfoExit(VI_PIPE vi_pipe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
