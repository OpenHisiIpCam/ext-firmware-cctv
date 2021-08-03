/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_SENSOR_H__
#define __ISP_SENSOR_H__

#include "mkp_isp.h"
#include "hi_comm_sns_adapt.h"
#include "hi_comm_isp.h"
#include "isp_math_utils.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

HI_S32 ISP_SensorRegCallBack(VI_PIPE vi_pipe, ISP_SNS_ATTR_INFO_S *sns_attr_info,
                             ISP_SENSOR_REGISTER_S *sns_register);
HI_S32 ISP_SensorUnRegCallBack(VI_PIPE vi_pipe);

HI_S32 ISP_SensorUpdateAll(VI_PIPE vi_pipe);

HI_S32 ISP_SensorGetId(VI_PIPE vi_pipe, SENSOR_ID *sensor_id);
HI_S32 isp_sensor_get_blc(VI_PIPE vi_pipe, hi_isp_cmos_black_level **sns_black_level);
HI_S32 isp_sensor_get_default(VI_PIPE vi_pipe, hi_isp_cmos_default **sns_dft);
HI_S32 ISP_SensorGetSnsReg(VI_PIPE vi_pipe, ISP_SNS_REGS_INFO_S **sns_reg_info);
HI_S32 ISP_SensorGetMaxResolution(VI_PIPE vi_pipe, ISP_CMOS_SENSOR_MAX_RESOLUTION_S **sns_max_resolution);

HI_S32 ISP_SensorCtxInit(VI_PIPE vi_pipe);
HI_S32 ISP_SensorUpdateAll_YUV(VI_PIPE vi_pipe);
HI_S32 ISP_GetYUVDefault(ISP_CMOS_DEFAULT_S *sns_dft);
HI_S32 ISP_SensorInit(VI_PIPE vi_pipe);
HI_S32 ISP_SensorSwitch(VI_PIPE vi_pipe);
HI_S32 ISP_SensorExit(VI_PIPE vi_pipe);
HI_S32 isp_sensor_update_blc(VI_PIPE vi_pipe);
HI_S32 ISP_SensorUpdateDefault(VI_PIPE vi_pipe);
HI_S32 ISP_SensorSetWDRMode(VI_PIPE vi_pipe, hi_u8 mode);
HI_S32 ISP_SensorSetResolutionMode(VI_PIPE vi_pipe, hi_u32 mode);
HI_S32 ISP_SensorSetPixelDetect(VI_PIPE vi_pipe, hi_bool enable);
HI_S32 isp_sensor_get_awb_gain(VI_PIPE vi_pipe, hi_u32 *sensor_awb_gain);
HI_S32 ISP_SensorUpdateSnsReg(VI_PIPE vi_pipe);
HI_S32 ISP_SensorSetImageMode(VI_PIPE vi_pipe, ISP_CMOS_SENSOR_IMAGE_MODE_S *sns_image_mode);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
