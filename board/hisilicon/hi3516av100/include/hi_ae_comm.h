/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_ae_comm.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/12/18
  Description   : 
  History       :
  1.Date        : 2012/12/18
    Author      : n00168968
    Modification: Created file

******************************************************************************/
#ifndef __HI_AE_COMM_H__
#define __HI_AE_COMM_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

#define HI_AE_LIB_NAME "hisi_ae_lib"

/************************** ae ctrl cmd **************************************/
typedef enum hiAE_CTRL_CMD_E
{
    AE_DEBUG_ATTR_SET,
    AE_DEBUG_ATTR_GET, 

    AE_CTRL_BUTT,
} AE_CTRL_CMD_E;

typedef struct hiAE_DBG_ATTR_S
{
    HI_U32  u32MaxIntTime;
    HI_U32  u32MinIntTime;
    HI_U32  u32MaxAgain;
    HI_U32  u32MinAgain;
    HI_U32  u32MaxDgain;
    HI_U32  u32MinDgain;
    HI_U32  u32MaxIspDgain;
    HI_U32  u32MinIspDgain;
    HI_U32  u32MaxSysGain;
    HI_U32  u32MinSysGain;
    HI_U32  u32Compensation;
    HI_U32  u32EVBias;
    HI_BOOL bManualExposureEn;
    HI_BOOL bManualTimeEn;
    HI_BOOL bManualAgainEn;
    HI_BOOL bManualDgainEn;
    HI_BOOL bManualIspDgainEn;
    HI_U32  u32ManualExposureLines;
    HI_U32  u32ManualAgain;
    HI_U32  u32ManualDgain;
    HI_U32  u32ManualIspDgain;
    HI_U32  au32AeWeights[255];    
}AE_DBG_ATTR_S;

typedef struct hiAE_DBG_STATUS_S
{
    HI_U32  u32FrmNumBgn;
    HI_U32  u32FullLines;
    HI_U32  u32IntTime;
    HI_U32  u32LongIntTime;
    HI_U32  u32Again;
    HI_U32  u32Dgain;
    HI_U32  u32IspDgain;
    HI_U32  u32IrisFNOLin;
    HI_U64  u64Exposure;
    HI_U32  u32Increment;
    HI_S32  s32HistError;
    HI_S32  s32HistOriAverage;
    HI_S32  s32LumaOffset;
    HI_U32  u32Iso;
}AE_DBG_STATUS_S;

/************************** sensor's interface to ae *********************/

/* eg: 0.35db, enAccuType=AE_ACCURACY_DB, f32Accuracy=0.35 
*  and the multiply of 0.35db is power(10, (0.35/20))
*  eg: 1/16, 2/16, 3/16 multiplies, enAccuType=AE_ACCURACY_LINEAR, f32Accuracy=0.0625
*  eg: 1,2,4,8,16 multiplies, enAccuType=AE_ACCURACY_DB, f32Accuracy=6
*/
typedef enum hiAE_ACCURACY_E
{
    AE_ACCURACY_DB = 0,
    AE_ACCURACY_LINEAR,
    AE_ACCURACY_TABLE,
    
    AE_ACCURACY_BUTT,
} AE_ACCURACY_E;

typedef struct hiAE_ACCURACY_S
{
    AE_ACCURACY_E enAccuType;
    float   f32Accuracy;
    float   f32Offset;
} AE_ACCURACY_S;

typedef struct hiAE_SENSOR_DEFAULT_S
{
    HI_U8   au8HistThresh[4];
    HI_U8   u8AeCompensation;

    HI_U32  u32LinesPer500ms;
    HI_U32  u32FlickerFreq;
    HI_FLOAT f32Fps;
    HI_U32  u32InitExposure;
    HI_U32  u32InitAESpeed;
    HI_U32  u32InitAETolerance;
    
    HI_U32  u32FullLinesStd;  
    HI_U32  u32FullLinesMax;
    HI_U32  u32FullLines;  
    HI_U32  u32MaxIntTime;     /* unit is line */
    HI_U32  u32MinIntTime;
    HI_U32  u32MaxIntTimeTarget;
    HI_U32  u32MinIntTimeTarget;
    AE_ACCURACY_S stIntTimeAccu;
    
    HI_U32  u32MaxAgain;
    HI_U32  u32MinAgain;
    HI_U32  u32MaxAgainTarget;
    HI_U32  u32MinAgainTarget;
    AE_ACCURACY_S stAgainAccu;

    HI_U32  u32MaxDgain;
    HI_U32  u32MinDgain;
    HI_U32  u32MaxDgainTarget;
    HI_U32  u32MinDgainTarget;
    AE_ACCURACY_S stDgainAccu;

    HI_U32  u32MaxISPDgainTarget;
    HI_U32  u32MinISPDgainTarget;
    HI_U32  u32ISPDgainShift;

    ISP_AE_ROUTE_S stAERouteAttr;
    HI_BOOL bAERouteExValid;
    ISP_AE_ROUTE_EX_S stAERouteAttrEx;

    HI_U16 u16ManRatioEnable;
    HI_U32 u32Ratio;
	
	ISP_IRIS_TYPE_E  enIrisType;
    ISP_PIRIS_ATTR_S stPirisAttr;
    ISP_IRIS_F_NO_E  enMaxIrisFNO;  /*RW, Range:[F32.0, F1.0], Max F number of Piris's aperture, it's related to the specific iris */
    ISP_IRIS_F_NO_E  enMinIrisFNO;  /*RW, Range:[F32.0, F1.0], Min F number of Piris's aperture, it's related to the specific iris */

	HI_U8  u8AERunInterval;
} AE_SENSOR_DEFAULT_S;

typedef struct hiAE_FSWDR_ATTR_S
{
    ISP_FSWDR_MODE_E enFSWDRMode;
} AE_FSWDR_ATTR_S;


typedef struct hiAE_SENSOR_EXP_FUNC_S
{
    HI_S32(*pfn_cmos_get_ae_default)(AE_SENSOR_DEFAULT_S *pstAeSnsDft);

    /* the function of sensor set fps */
    HI_VOID(*pfn_cmos_fps_set)(HI_FLOAT f32Fps, AE_SENSOR_DEFAULT_S *pstAeSnsDft);
    HI_VOID(*pfn_cmos_slow_framerate_set)(HI_U32 u32FullLines, AE_SENSOR_DEFAULT_S *pstAeSnsDft);

    /* while isp notify ae to update sensor regs, ae call these funcs. */
    HI_VOID(*pfn_cmos_inttime_update)(HI_U32 u32IntTime);
    HI_VOID(*pfn_cmos_gains_update)(HI_U32 u32Again, HI_U32 u32Dgain);

    HI_VOID (*pfn_cmos_again_calc_table)(HI_U32 *pu32AgainLin, HI_U32 *pu32AgainDb);
    HI_VOID (*pfn_cmos_dgain_calc_table)(HI_U32 *pu32DgainLin, HI_U32 *pu32DgainDb);

    HI_VOID (*pfn_cmos_get_inttime_max)(HI_U32 u32Ratio, HI_U32 *pu32IntTimeMax);

    /* long frame mode set */
    HI_VOID(*pfn_cmos_ae_fswdr_attr_set)(AE_FSWDR_ATTR_S *pstAeFSWDRAttr);
    
} AE_SENSOR_EXP_FUNC_S;

typedef struct hiAE_SENSOR_REGISTER_S
{
    AE_SENSOR_EXP_FUNC_S stSnsExp;
} AE_SENSOR_REGISTER_S;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
