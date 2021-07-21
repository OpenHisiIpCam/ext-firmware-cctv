/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/


#ifndef __ISP_MAIN_H__
#define __ISP_MAIN_H__

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>

#include <pthread.h>

#include "hi_comm_3a_adapt.h"
#include "isp_debug.h"
#include "mkp_isp.h"
#include "isp_dcfinfo.h"
#include "isp_frameinfo.h"
#include "isp_dnginfo.h"
#include "isp_block.h"
#include "vi_ext.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#define ISP_MAX_ALGS_NUM     64

typedef struct {
    hi_bool used;
    ALG_LIB_S alg_lib;
    union {
        ISP_AE_REGISTER_S ae_regsiter;
        ISP_AWB_REGISTER_S awb_regsiter;
    };
} isp_lib_node;

typedef struct {
    hi_u32         active_lib; /* the lib used present. */
    isp_lib_node libs[MAX_REGISTER_ALG_LIB_NUM];
} isp_lib_info;

typedef struct {
    hi_s32 (*pfn_alg_init)(VI_PIPE vi_pipe, hi_void *reg_cfg);
    hi_s32 (*pfn_alg_run)(VI_PIPE vi_pipe,
                          const hi_void *stat_info,
                          hi_void *reg_cfg,
                          hi_s32 rsv);
    hi_s32 (*pfn_alg_ctrl)(VI_PIPE vi_pipe, hi_u32 cmd, hi_void *value);
    hi_s32 (*pfn_alg_exit)(VI_PIPE vi_pipe);
} isp_alg_func;

typedef struct {
    hi_bool         used;
    hi_isp_alg_mod  alg_type;
    isp_alg_func    alg_func;
} isp_alg_node;

#define ISP_SYNC_ISO_BUF_MAX 6

typedef struct {
    hi_u16 high_ccm[9];
    hi_u16 low_ccm[9];
    hi_u16 high_color_temp;
    hi_u16 low_color_temp;
} isp_dng_ccm;

typedef struct {
    hi_bool defect_pixel;  // each alg need to check this status

    hi_u32  isp_dgain;
    hi_u32  again;
    hi_u32  dgain;
    hi_u32  isp_dgain_shift;
    hi_u32  iso;
    hi_u32  iso_max;
    hi_u32  sensor_iso;
    hi_u32  exp_ratio;
    hi_u32  exp_ratio_lut[3];
    hi_u32  wdr_gain[4];
    hi_u32  int_time;
    hi_u32  piris_gain;
    hi_u8   ae_run_interval;
    hi_isp_fswdr_mode fswdr_mode;
    hi_isp_fswdr_mode pre_fswdr_mode;
    hi_u32  color_temp;
    hi_u32  white_balance_gain[4];
    hi_u16  ccm[9];
    hi_u8   saturation;
    hi_bool snap_state;
    hi_bool pro_trigger;
    hi_bool load_ccm;
    hi_snap_type snap_type;
    isp_snap_pipe_mode snap_pipe_mode;
    hi_s32  preview_pipe_id;
    hi_s32  picture_pipe_id;
    isp_running_mode preview_running_mode;
    isp_running_mode picture_running_mode;
    hi_u32  update_pos;
    hi_u32  sync_iso_buf[ISP_SYNC_ISO_BUF_MAX];
    hi_u32  sync_all_exp_ratio_buf[ISP_SYNC_ISO_BUF_MAX];
    hi_u32  sync_exp_ratio_buf[3][ISP_SYNC_ISO_BUF_MAX];
    hi_u32  pro_index_buf[ISP_SYNC_ISO_BUF_MAX];
    hi_u8   pro_index;
    hi_u32  iso_done_frm_cnt;
    hi_u8   cfg2valid_delay_max;
    hi_bool flicker;
    hi_u8   freq_result;
    hi_bool stat_ready;
    hi_bool run_once;
} isp_linkage;

typedef struct {
    hi_bool wdr_cfg;
    hi_bool pub_cfg;
    hi_bool init;
    hi_bool run;
    hi_bool stitch_sync;

    hi_bool run_en;
} isp_para_rec;

typedef struct {
    hi_bool be_on_stt_update[ISP_MAX_BE_NUM];
    hi_bool fe_stt_update;
} isp_special_opt;

typedef struct {
    hi_u16   width;
    hi_u16   height;
    hi_float fps;
    hi_u8    sns_mode;
} isp_sensor_image_mode;

typedef struct {
    hi_u16 out_width;
    hi_u16 out_height;
} isp_bas_out_image_mode;

typedef struct {
    hi_bool                  enable_be_raw;
    hi_bool                  pre_enabe_be_raw;
    hi_u32                     be_ctrl0;
    hi_u32                     be_ctrl1;
    hi_isp_raw_pos         isp_raw_pos;
}isp_be_raw_info;

typedef union {
    hi_u64 key;
    struct {
        hi_u64  bit1_ae          : 1 ;   /* [0] */
        hi_u64  bit1_awb         : 1 ;   /* [1] */
        hi_u64  bit1_af          : 1 ;   /* [2] */
        hi_u64  bit1_dp          : 1 ;   /* [3] */
        hi_u64  bit1_ge          : 1 ;   /* [4] */
        hi_u64  bit1_wdr         : 1 ;   /* [5] */
        hi_u64  bit1_expander    : 1 ;   /* [6] */
        hi_u64  bit1_blc         : 1 ;   /* [7] */
        hi_u64  bit1_bayernr     : 1 ;   /* [8] */
        hi_u64  bit1_split       : 1 ;   /* [9] */
        hi_u64  bit1_flicker     : 1 ;   /* [10] */
        hi_u64  bit1_dg          : 1 ;   /* [11] */
        hi_u64  bit1_hrs         : 1 ;   /* [12] */
        hi_u64  bit1_fe_lsc      : 1 ;   /* [13] */
        hi_u64  bit1_lsc         : 1 ;   /* [14] */
        hi_u64  bit1_r_lsc       : 1 ;   /* [15] */
        hi_u64  bit1_rc          : 1 ;   /* [16] */
        hi_u64  bit1_drc         : 1 ;   /* [17] */
        hi_u64  bit1_dehaze      : 1 ;   /* [18] */
        hi_u64  bit1_lcac        : 1 ;   /* [19] */
        hi_u64  bit1_gcac        : 1 ;   /* [20] */
        hi_u64  bit1_demosaic    : 1 ;   /* [21] */
        hi_u64  bit1_fcr         : 1 ;   /* [22] */
        hi_u64  bit1_gamma       : 1 ;   /* [23] */
        hi_u64  bit1_csc         : 1 ;   /* [24] */
        hi_u64  bit1_ca          : 1 ;   /* [25] */
        hi_u64  bit1_fpn         : 1;    /* [26] */
        hi_u64  bit1_sharpen     : 1;    /* [27] */
        hi_u64  bit1_edge_mark   : 1 ;   /* [28] */
        hi_u64  bit1_mcds        : 1 ;   /* [29] */
        hi_u64  bit1_ldci        : 1 ;   /* [30] */
        hi_u64  bit1_pre_gamma   : 1 ;   /* [31] */
        hi_u64  bit1_fe_log_lut  : 1 ;   /* [32] */
        hi_u64  bit1_log_lut     : 1 ;   /* [33] */
        hi_u64  bit1_clut        : 1 ;   /* [34] */
        hi_u64  bit1_hlc         : 1 ;   /* [35] */
        hi_u64  bit1_detail      : 1 ;   /* [36] */
        hi_u64  bit1_rgbir       : 1 ;   /* [37] */
        hi_u64  bit26_rsv        : 26;   /* [38:63] */
    };
} isp_alg_key;

typedef struct {
    /* 1. ctrl param */
    hi_bool                  mem_init;
    hi_bool                  sns_reg;
    hi_bool                  isp_yuv_mode;
    isp_para_rec             para_rec;
    hi_rect                  sys_rect;
    isp_block_attr           block_attr;
    pthread_mutex_t          lock;
    isp_special_opt          special_opt;
    isp_be_raw_info        be_raw_info;
    /* 2. algorithm ctrl param */
    hi_bool                  freeze_fw;
    hi_bool                  change_wdr_mode;
    hi_bool                  change_image_mode;
    hi_bool                  change_isp_res;
    hi_bool                  isp0_p2_en;
    hi_bool                  ldci_tpr_flt_en;
    hi_u8                    count;
    hi_u8                    pre_sns_wdr_mode;
    hi_u8                    sns_wdr_mode;
    hi_u32                   frame_cnt;    /* frame count for 3a libs which can decide the interval of calculate. */
    hi_isp_bayer_format      bayer;
    isp_alg_key              alg_key;

    hi_u8                    isp_image_mode_flag;
    isp_sensor_image_mode    pre_sns_image_mode;
    isp_sensor_image_mode    sns_image_mode;

    ISP_AE_RESULT_S          ae_result;
    ISP_AWB_RESULT_S         awb_result;

    isp_bas_out_image_mode   pre_bas_image_mode;
    isp_bas_out_image_mode   cur_bas_image_mode;
    hi_size                  pipe_size;
    vi_pipe_hdr_attr         hdr_attr;
    vi_pipe_wdr_attr         wdr_attr;
    vi_stitch_attr           stitch_attr;
    hi_color_gamut           color_gamut;
    hi_isp_smart_info        smart_info;

    /* 3. 3a register info */
    hi_isp_bind_attr         bind_attr;
    isp_lib_info             ae_lib_info;
    isp_lib_info             awb_lib_info;
    isp_lib_info             af_lib_info;

    /* 4. algorithm ctrl */
    isp_alg_node             algs[ISP_MAX_ALGS_NUM];
    isp_linkage              linkage;

    /* 5. debug info */
    isp_dbg_ctrl             isp_dbg;

    /* 6. DCF info */
    isp_trans_info_buf       isp_trans_info;
    isp_pro_info_buf         isp_pro_info;

    isp_update_info_ctrl     update_info_ctrl;
    isp_frame_info_ctrl      frame_info_ctrl;
    isp_attach_info_ctrl     attach_info_ctrl;
    isp_gammut_info_ctrl     gamut_info_ctrl;
    isp_pro_nr_param_ctrl    pro_nr_param_ctrl;
    isp_pro_shp_param_ctrl   pro_shp_param_ctrl;
    hi_isp_dcf_update_info   dcf_update_info;
    hi_isp_frame_info        frame_info;

    /* DNG info */
    isp_dng_info_ctrl        dng_info_ctrl;
    hi_isp_dng_color_param   pre_dng_color_param;
    isp_dng_ccm              pre_dng_ccm;

    isp_pro_param            pro_param;
    hi_u8                    pro_frm_cnt;
    isp_snap_info            snap_isp_info;

    /* 7. ViProc/BE Addr */
    hi_void                 *isp_be_virt_addr[ISP_STRIPING_MAX_NUM];
    hi_void                 *viproc_virt_addr[ISP_STRIPING_MAX_NUM];
} isp_usr_ctx;

extern HI_S32    g_as32IspFd[ISP_MAX_PIPE_NUM];
extern isp_usr_ctx g_astIspCtx[ISP_MAX_PIPE_NUM];
extern isp_reg_cfg_attr *g_pastRegCfgCtx[ISP_MAX_PIPE_NUM];
extern const HI_U32 g_au32IsoLut[ISP_AUTO_ISO_STRENGTH_NUM];

#define ISP_REGCFG_GET_CTX(dev, pstCtx) (pstCtx = g_pastRegCfgCtx[dev])
#define ISP_REGCFG_SET_CTX(dev, pstCtx) (g_pastRegCfgCtx[dev] = pstCtx)
#define ISP_REGCFG_RESET_CTX(dev)       (g_pastRegCfgCtx[dev] = HI_NULL)

#define ISP_CHECK_OPEN(dev)                    \
    do {                                       \
        HI_S32 s32Ret = ISP_CheckDevOpen(dev); \
        if (s32Ret != HI_SUCCESS) {            \
            return s32Ret;                     \
        }                                      \
    } while (0)

#define ISP_CHECK_MEM_INIT(dev)                \
    do {                                       \
        HI_S32 s32Ret = ISP_CheckMemInit(dev); \
        if (s32Ret != HI_SUCCESS) {            \
            return s32Ret;                     \
        }                                      \
    } while (0)

#define ISP_CHECK_ISP_WDR_CFG(dev)                                            \
    do {                                                                      \
        if (g_astIspCtx[dev].para_rec.wdr_cfg != HI_TRUE) {               \
            ISP_ERR_TRACE("Isp[%d] WDR mode doesn't config!\n", dev); \
            return HI_ERR_ISP_ATTR_NOT_CFG;                                   \
        }                                                                     \
    } while (0)

#define ISP_CHECK_ISP_PUB_ATTR_CFG(dev)                                       \
    do {                                                                      \
        if (g_astIspCtx[dev].para_rec.pub_cfg != HI_TRUE) {               \
            ISP_ERR_TRACE("Isp[%d] Pub Attr doesn't config!\n", dev); \
            return HI_ERR_ISP_ATTR_NOT_CFG;                                   \
        }                                                                     \
    } while (0)

#define ISP_CHECK_ISP_INIT(dev)                                           \
    do {                                                                  \
        if (g_astIspCtx[dev].para_rec.init != HI_TRUE) {             \
            ISP_ERR_TRACE("Isp[%d] doesn't initialized!\n", dev); \
            return HI_ERR_ISP_NOT_INIT;                                   \
        }                                                                 \
    } while (0)

#define ISP_CHECK_OFFLINE_MODE(dev)                                                \
    do {                                                                           \
        if ((IS_ONLINE_MODE(g_astIspCtx[dev].block_attr.running_mode)) ||  \
            (IS_SIDEBYSIDE_MODE(g_astIspCtx[dev].block_attr.running_mode))) { \
            return HI_SUCCESS;                                                     \
        }                                                                          \
    } while (0)

#define ISP_GET_CTX(dev, pstIspCtx)    \
    do {                               \
        pstIspCtx = &g_astIspCtx[dev]; \
    } while (0)

/*
 * HIGH LEVEL functions used to set-up and run ISP.
 */
/*
 * This function executes the auto-exposure algorithm
 * and its results are used to drive sensor parameters,
 * drc engine and noise reduction algorithms,
 * Results are based on the collected image histogram data.
 */
HI_S32 ISP_Run(VI_PIPE ViPipe);
HI_S32 ISP_Exit(VI_PIPE ViPipe);
HI_S32 ISP_StitchSyncExit(VI_PIPE ViPipe);

HI_S32 ISP_SwitchWDR(VI_PIPE ViPipe);
HI_S32 ISP_SwitchWDRMode(VI_PIPE ViPipe);
HI_S32 ISP_SwitchImageMode(VI_PIPE ViPipe);
HI_S32 ISP_SwitchMode(VI_PIPE ViPipe);

HI_S32 ISP_WDRCfgSet(VI_PIPE ViPipe);
HI_U32 ISP_FrameCntGet(VI_PIPE ViPipe);

HI_S32 ISP_CheckDevOpen(ISP_DEV dev);
HI_S32 ISP_CheckMemInit(ISP_DEV dev);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* __ISP_MAIN_H__ */
