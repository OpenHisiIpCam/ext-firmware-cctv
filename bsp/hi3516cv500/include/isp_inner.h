/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_INNER_H__
#define __ISP_INNER_H__

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include "mkp_isp.h"
#include "isp_math_utils.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#define MPI_ISP_PARAM_CHECK_RETURN(x, min, max, fmt, ...)                  \
    do {                                                                   \
        if ((x) < (min) || (x) > (max)) {                                  \
            printf("[Func]:%s [Line]:%d [Info]:", __FUNCTION__, __LINE__); \
            printf("%#x " fmt, x, ##__VA_ARGS__);                          \
            return HI_ERR_ISP_ILLEGAL_PARAM;                               \
        }                                                                  \
    } while (0)

#define MPI_ISP_MAX_PARAM_CHECK_RETURN(x, max, fmt, ...)                   \
    do {                                                                   \
        if ((x) > (max)) {                                                 \
            printf("[Func]:%s [Line]:%d [Info]:", __FUNCTION__, __LINE__); \
            printf("%#x " fmt, x, ##__VA_ARGS__);                          \
            return HI_ERR_ISP_ILLEGAL_PARAM;                               \
        }                                                                  \
    } while (0)

#define MPI_ISP_ARRAY_PARAM_CHECK_RETURN(x, type, size, min, max, fmt, ...)     \
    do {                                                                        \
        int loops = size;                                                       \
        type *p = (type *)x;                                                    \
        while (loops--) {                                                       \
            if ((p[loops]) < (min) || (p[loops]) > (max)) {                     \
                printf("[Func]:%s [Line]:%d [Info]:", __FUNCTION__, __LINE__);  \
                printf("array[%d] = %#x " fmt, loops, p[loops], ##__VA_ARGS__); \
                return HI_ERR_ISP_ILLEGAL_PARAM;                                \
            }                                                                   \
        }                                                                       \
    } while (0)

#define MPI_ISP_ARRAY_MAX_PARAM_CHECK_RETURN(x, type, size, max, fmt, ...)      \
    do {                                                                        \
        int loops = size;                                                       \
        type *p = (type *)x;                                                    \
        while (loops--) {                                                       \
            if ((p[loops]) > (max)) {                                           \
                printf("[Func]:%s [Line]:%d [Info]:", __FUNCTION__, __LINE__);  \
                printf("array[%d] = %#x " fmt, loops, p[loops], ##__VA_ARGS__); \
                return HI_ERR_ISP_ILLEGAL_PARAM;                                \
            }                                                                   \
        }                                                                       \
    } while (0)

#ifdef _MSC_VER
#define MUTEX_INIT_LOCK(mutex) InitializeCriticalSection(&mutex)
#define MUTEX_LOCK(mutex) EnterCriticalSection(&mutex)
#define MUTEX_UNLOCK(mutex) LeaveCriticalSection(&mutex)
#define MUTEX_DESTROY(mutex) DeleteCriticalSection(&mutex)
#else
#define MUTEX_INIT_LOCK(mutex)                  \
    do {                                        \
        (void)pthread_mutex_init(&mutex, NULL); \
    } while (0)
#define MUTEX_LOCK(mutex)                 \
    do {                                  \
        (void)pthread_mutex_lock(&mutex); \
    } while (0)
#define MUTEX_UNLOCK(mutex)                 \
    do {                                    \
        (void)pthread_mutex_unlock(&mutex); \
    } while (0)
#define MUTEX_DESTROY(mutex)                 \
    do {                                     \
        (void)pthread_mutex_destroy(&mutex); \
    } while (0)
#endif

hi_s32 isp_set_calibrate_attr(VI_PIPE vi_pipe, hi_isp_fpn_calibrate_attr *calibrate);
hi_s32 isp_set_correction_attr(VI_PIPE vi_pipe, const hi_isp_fpn_attr *correction);
hi_s32 isp_get_correction_attr(VI_PIPE vi_pipe, hi_isp_fpn_attr *correction);
hi_s32 isp_get_fe_focus_statistics(VI_PIPE vi_pipe, hi_isp_fe_focus_statistics *fe_af_stat, isp_stat *isp_act_stat,
                                   hi_u8 wdr_chn);

hi_s32 isp_get_ae_stitch_statistics(VI_PIPE vi_pipe, hi_isp_ae_stitch_statistics *ae_stitch_stat);
hi_s32 isp_get_wb_stitch_statistics(VI_PIPE vi_pipe, hi_isp_wb_stitch_statistics *stitch_wb_stat);
hi_s32 ISP_MeshShadingCalibration(HI_U16 *pu16SrcRaw, ISP_MLSC_CALIBRATION_CFG_S *pstMLSCCaliCfg,
                                  ISP_MESH_SHADING_TABLE_S *pstMLSCTable);
hi_s32 isp_get_lightbox_gain(VI_PIPE vi_pipe, hi_isp_awb_calibration_gain *awb_calibration_gain);
hi_s32 isp_set_radial_shading_attr(VI_PIPE vi_pipe, const hi_isp_radial_shading_attr *radial_shading_attr);
hi_s32 isp_get_radial_shading_attr(VI_PIPE vi_pipe, hi_isp_radial_shading_attr *radial_shading_attr);
hi_s32 isp_set_radial_shading_lut(VI_PIPE vi_pipe, const hi_isp_radial_shading_lut_attr *radial_shading_lut_attr);
hi_s32 isp_get_radial_shading_lut(VI_PIPE vi_pipe, hi_isp_radial_shading_lut_attr *radial_shading_lut_attr);
hi_s32 isp_set_pipe_differ_attr(VI_PIPE vi_pipe, const hi_isp_pipe_diff_attr *pipe_differ);
hi_s32 isp_get_pipe_differ_attr(VI_PIPE vi_pipe, hi_isp_pipe_diff_attr *pipe_differ);
hi_s32 isp_set_rc_attr(VI_PIPE vi_pipe, const hi_isp_rc_attr *rc_attr);
hi_s32 isp_get_rc_attr(VI_PIPE vi_pipe, hi_isp_rc_attr *rc_attr);
hi_s32 isp_set_rgbir_attr(VI_PIPE vi_pipe, const hi_isp_rgbir_attr *rgbir_attr);
hi_s32 isp_get_rgbir_attr(VI_PIPE vi_pipe, hi_isp_rgbir_attr *rgbir_attr);
hi_s32 isp_set_pre_log_lut_attr(VI_PIPE vi_pipe, const hi_isp_preloglut_attr *pre_log_lut_attr);
hi_s32 isp_get_pre_log_lut_attr(VI_PIPE vi_pipe, hi_isp_preloglut_attr *pre_log_lut_attr);
hi_s32 isp_set_log_lut_attr(VI_PIPE vi_pipe, const hi_isp_loglut_attr *log_lut_attr);
hi_s32 isp_get_log_lut_attr(VI_PIPE vi_pipe, hi_isp_loglut_attr *log_lut_attr);
hi_s32 isp_get_ae_grid_info(VI_PIPE vi_pipe, hi_isp_ae_grid_info *fe_grid_info, hi_isp_ae_grid_info *be_grid_info);
hi_s32 isp_get_af_grid_info(VI_PIPE vi_pipe, hi_isp_focus_grid_info *fe_grid_info, hi_isp_focus_grid_info *be_grid_info);
hi_s32 isp_get_wb_grid_info(VI_PIPE vi_pipe, hi_isp_awb_grid_info *grid_info);
hi_s32 isp_get_mg_grid_info(VI_PIPE vi_pipe, hi_isp_mg_grid_info *grid_info);

hi_s32 isp_set_clut_coeff(VI_PIPE vi_pipe, const hi_isp_clut_lut *clut_lut);
hi_s32 isp_get_clut_coeff(VI_PIPE vi_pipe, hi_isp_clut_lut *clut_lut);
hi_s32 isp_set_clut_attr(VI_PIPE vi_pipe, const hi_isp_clut_attr *clut_attr);
hi_s32 isp_get_clut_attr(VI_PIPE vi_pipe, hi_isp_clut_attr *clut_attr);
hi_s32 ISP_CalcFlickerType(ISP_CALCFLICKER_INPUT_S *pstInputParam, ISP_CALCFLICKER_OUTPUT_S *pstOutputParam, VIDEO_FRAME_INFO_S stFrame[], HI_U32 u32ArraySize);

hi_s32 isp_set_raw_pos(VI_PIPE vi_pipe, const hi_isp_raw_pos_attr *raw_pos_attr);
hi_s32 isp_get_raw_pos(VI_PIPE vi_pipe, hi_isp_raw_pos_attr *raw_pos_attr);
hi_s32 isp_calc_flicker_type(VI_PIPE ViPipe, ISP_CALCFLICKER_INPUT_S *pstInputParam,ISP_CALCFLICKER_OUTPUT_S *pstOutputParam, VIDEO_FRAME_INFO_S stFrame[], HI_U32 u32ArraySize);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
