/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_ALG_H__
#define __ISP_ALG_H__

#include <stdlib.h>
#include <string.h>
#include "hi_common.h"
#include "hi_comm_isp.h"
#include "isp_main.h"
#include "hi_math.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

hi_s32 isp_alg_register_ae(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_awb(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_af(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_dpc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_ge(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_frame_wdr(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_bayer_nr(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_flicker(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_hrs(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_dg(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_fe_lsc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_lsc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_rlsc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_rc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_drc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_dehaze(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_lcac(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_gcac(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_split(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_expander(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_demosaic(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_fcr(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_gamma(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_csc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_sharpen(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_edge_mark(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_mcds(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_dci(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_ldci(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_ca(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_fpn(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_pre_gamma(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_blc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_fe_log_lut(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_log_lut(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_clut(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_hlc(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_detail(VI_PIPE vi_pipe);
hi_s32 isp_alg_register_rgbir(VI_PIPE vi_pipe);

/* find the specified library */
static inline HI_S32 ISP_FindLib(const isp_lib_node *astLibs,
                                 const ALG_LIB_S *pstLib)
{
    HI_S32 i;

    for (i = 0; i < MAX_REGISTER_ALG_LIB_NUM; i++) {
        /* can't use memcmp, if user not fill the string. */
        if ((strncmp(astLibs[i].alg_lib.acLibName, pstLib->acLibName, ALG_LIB_NAME_SIZE_MAX) == 0) &&
            (astLibs[i].alg_lib.s32Id == pstLib->s32Id)) {
            return i;
        }
    }

    return -1;
}

/* search the empty pos of libs */
static inline isp_lib_node *ISP_SearchLib(isp_lib_node *astLibs)
{
    HI_S32 i;

    for (i = 0; i < MAX_REGISTER_ALG_LIB_NUM; i++) {
        if (!astLibs[i].used) {
            return &astLibs[i];
        }
    }

    return HI_NULL;
}

/* search the empty pos of algs */
static inline isp_alg_node *ISP_SearchAlg(isp_alg_node *astAlgs)
{
    HI_S32 i;

    for (i = 0; i < ISP_MAX_ALGS_NUM; i++) {
        if (!astAlgs[i].used) {
            return &astAlgs[i];
        }
    }

    return HI_NULL;
}

static inline HI_VOID ISP_AlgsInit(const isp_alg_node *astAlgs, VI_PIPE ViPipe, HI_VOID *pRegCfg)
{
    HI_S32 i;

    for (i = 0; i < ISP_MAX_ALGS_NUM; i++) {
        if (astAlgs[i].used) {
            if (astAlgs[i].alg_func.pfn_alg_init != HI_NULL) {
                astAlgs[i].alg_func.pfn_alg_init(ViPipe, pRegCfg);
            }
        }
    }

    return;
}

static inline HI_VOID ISP_AlgsRun(const isp_alg_node *astAlgs, VI_PIPE ViPipe,
                                  const HI_VOID *pStatInfo, HI_VOID *pRegCfg, HI_S32 s32Rsv)
{
    HI_S32 i;

    for (i = 0; i < ISP_MAX_ALGS_NUM; i++) {
        if (astAlgs[i].used) {
            if (astAlgs[i].alg_func.pfn_alg_run != HI_NULL) {
                astAlgs[i].alg_func.pfn_alg_run(ViPipe, pStatInfo, pRegCfg, s32Rsv);
            }
        }
    }

    return;
}

static inline HI_VOID ISP_AlgsCtrl(const isp_alg_node *astAlgs,
                                   VI_PIPE ViPipe, HI_U32 u32Cmd, HI_VOID *pValue)
{
    HI_S32 i;

    for (i = 0; i < ISP_MAX_ALGS_NUM; i++) {
        if (astAlgs[i].used) {
            if (astAlgs[i].alg_func.pfn_alg_ctrl != HI_NULL) {
                astAlgs[i].alg_func.pfn_alg_ctrl(ViPipe, u32Cmd, pValue);
            }
        }
    }

    return;
}

static inline HI_VOID ISP_AlgsExit(VI_PIPE ViPipe, const isp_alg_node *astAlgs)
{
    HI_S32 i;

    for (i = 0; i < ISP_MAX_ALGS_NUM; i++) {
        if (astAlgs[i].used) {
            if (astAlgs[i].alg_func.pfn_alg_exit != HI_NULL) {
                astAlgs[i].alg_func.pfn_alg_exit(ViPipe);
            }
        }
    }

    return;
}

static inline HI_VOID ISP_AlgsRegister(VI_PIPE vi_pipe)
{
    isp_alg_register_ae(vi_pipe);
    isp_alg_register_awb(vi_pipe);
#ifdef CONFIG_HI_ISP_AF_SUPPORT
    isp_alg_register_af(vi_pipe);
#endif
    isp_alg_register_dpc(vi_pipe);

#ifdef CONFIG_HI_ISP_CR_SUPPORT
    isp_alg_register_ge(vi_pipe);
#endif
    isp_alg_register_frame_wdr(vi_pipe);
    isp_alg_register_expander(vi_pipe);
    isp_alg_register_blc(vi_pipe);
    isp_alg_register_bayer_nr(vi_pipe);
    isp_alg_register_split(vi_pipe);
    isp_alg_register_flicker(vi_pipe);
    isp_alg_register_dg(vi_pipe);
    isp_alg_register_hrs(vi_pipe);
    isp_alg_register_fe_lsc(vi_pipe);
    isp_alg_register_lsc(vi_pipe);
    isp_alg_register_rlsc(vi_pipe);
    isp_alg_register_rc(vi_pipe);
    isp_alg_register_drc(vi_pipe);
    isp_alg_register_dehaze(vi_pipe);
    isp_alg_register_lcac(vi_pipe);

#ifdef CONFIG_HI_ISP_GCAC_SUPPORT
    isp_alg_register_gcac(vi_pipe);
#endif

    isp_alg_register_demosaic(vi_pipe);
    isp_alg_register_fcr(vi_pipe);
    isp_alg_register_gamma(vi_pipe);
    isp_alg_register_csc(vi_pipe);

#ifdef CONFIG_HI_ISP_CA_SUPPORT
    isp_alg_register_ca(vi_pipe);
#endif

#ifdef CONFIG_HI_VI_FPN_SUPPORT
    isp_alg_register_fpn(vi_pipe);
#endif
    isp_alg_register_sharpen(vi_pipe);

#ifdef CONFIG_HI_ISP_EDGEMARK_SUPPORT
    isp_alg_register_edge_mark(vi_pipe);
#endif
    isp_alg_register_mcds(vi_pipe);
    isp_alg_register_ldci(vi_pipe);

#ifdef CONFIG_HI_ISP_PREGAMMA_SUPPORT
    isp_alg_register_pre_gamma(vi_pipe);
#endif
    isp_alg_register_fe_log_lut(vi_pipe);
    isp_alg_register_log_lut(vi_pipe);
    isp_alg_register_clut(vi_pipe);

#ifdef CONFIG_HI_ISP_HLC_SUPPORT
    isp_alg_register_hlc(vi_pipe);
#endif
    isp_alg_register_detail(vi_pipe);
    isp_alg_register_rgbir(vi_pipe);
    return;
}

static inline HI_VOID ISP_YUVAlgsRegister(VI_PIPE vi_pipe)
{
#ifdef CONFIG_HI_ISP_AF_SUPPORT
    isp_alg_register_af(vi_pipe);
#endif

#ifdef CONFIG_HI_ISP_CA_SUPPORT
    isp_alg_register_ca(vi_pipe);
#endif

    isp_alg_register_sharpen(vi_pipe);
#ifdef CONFIG_HI_ISP_EDGEMARK_SUPPORT
    isp_alg_register_edge_mark(vi_pipe);
#endif
    isp_alg_register_mcds(vi_pipe);
    isp_alg_register_ldci(vi_pipe);

    return;
}

/* resolve problem:
isp error: Null Pointer in ISP_AlgRegisterxxx when return isp_init without app exit */
static inline HI_VOID ISP_AlgsUnRegister(VI_PIPE vi_pipe)
{
    isp_usr_ctx *pstIspCtx = HI_NULL;
    HI_S32 i;

    ISP_GET_CTX(vi_pipe, pstIspCtx);

    for (i = 0; i < ISP_MAX_ALGS_NUM; i++) {
        if (pstIspCtx->algs[i].used) {
            pstIspCtx->algs[i].used = HI_FALSE;
        }
    }
}

/* resolve problem:
isp error: HI_MPI_XX_Register failed when return 3a lib register without app exit */
static inline HI_VOID ISP_LibsUnRegister(VI_PIPE ViPipe)
{
    isp_usr_ctx *pstIspCtx = HI_NULL;
    HI_S32 i;

    ISP_GET_CTX(ViPipe, pstIspCtx);

    for (i = 0; i < MAX_REGISTER_ALG_LIB_NUM; i++) {
        pstIspCtx->ae_lib_info.libs[i].used  = HI_FALSE;
        pstIspCtx->awb_lib_info.libs[i].used = HI_FALSE;
        pstIspCtx->af_lib_info.libs[i].used  = HI_FALSE;
    }
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
