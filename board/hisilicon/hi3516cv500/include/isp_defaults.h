/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/


#ifndef __ISP_DEFAULTS_H_
#define __ISP_DEFAULTS_H_

#include "isp_main.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/* ext register default value */
HI_VOID ISP_ExtRegsDefault(VI_PIPE vi_pipe);

/* initialize ext register */
HI_VOID ISP_ExtRegsInitialize(VI_PIPE vi_pipe);

/* isp register default value */
HI_VOID ISP_RegsDefault(VI_PIPE vi_pipe);

/* initialize isp register */
HI_VOID ISP_RegsInitialize(VI_PIPE vi_pipe);

/* This function initialises an instance of isp_usr_ctx */
HI_VOID ISP_GlobalInitialize(VI_PIPE vi_pipe);

HI_VOID ISP_DngExtRegsInitialize(VI_PIPE vi_pipe, ISP_DNG_COLORPARAM_S *pstDngColorParam);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* __ISP_DEFAULTS_H_ */
