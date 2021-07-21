/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_REGCFG_H__
#define __ISP_REGCFG_H__

#include "hi_comm_isp.h"
#include "mpi_isp.h"
#include "isp_sensor.h"
#include "mkp_isp.h"
#include "vi_ext.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

#define IS_HRS_ON(ViPipe) (g_astIspCtx[ViPipe].isp0_p2_en == HI_TRUE)
#define ISP_ALIGNUP(x, g) ((((x) + (g)-1) / (g)) * (g))

typedef struct {
    hi_u64 be_phy_addr; /* head addr */
    hi_void *be_virt_addr;

    isp_be_wo_cfg_buf be_wo_cfg_buf;
} isp_be_buf;

typedef struct {
    isp_mmz_buf_ex lut_stt_buf[ISP_MAX_BE_NUM];
} isp_be_lut_buf;

HI_S32 ISP_ModParamGet(hi_isp_mod_param *pstModParam);
HI_S32 ISP_ResetFeSttEn(VI_PIPE ViPipe);
HI_S32 ISP_AlgEnExit(VI_PIPE ViPipe);
HI_S32 ISP_LdciBufInit(VI_PIPE ViPipe);
HI_S32 ISP_LdciBufExit(VI_PIPE ViPipe);
HI_S32 ISP_ClutBufInit(VI_PIPE ViPipe);
HI_S32 ISP_ClutBufExit(VI_PIPE ViPipe);
HI_S32 ISP_SpecAwbBufInit(VI_PIPE ViPipe);
HI_S32 ISP_SpecAwbBufExit(VI_PIPE ViPipe);
HI_S32 ISP_SttBufInit(VI_PIPE ViPipe);
HI_S32 ISP_SttBufExit(VI_PIPE ViPipe);
HI_S32 ISP_SttAddrInit(VI_PIPE ViPipe);
HI_S32 ISP_CfgBeBufInit(VI_PIPE ViPipe);
HI_S32 ISP_CfgBeBufExit(VI_PIPE ViPipe);
HI_S32 ISP_RegCfgInit(VI_PIPE ViPipe);
HI_S32 ISP_GetRegCfgCtx(VI_PIPE ViPipe, HI_VOID **ppCfg);
HI_S32 ISP_RegCfgCtrl(VI_PIPE ViPipe);
HI_S32 ISP_RegCfgExit(VI_PIPE ViPipe);
HI_S32 ISP_SwitchRegSet(VI_PIPE ViPipe);
HI_S32 ISP_GetBeLastBuf(VI_PIPE ViPipe);
HI_S32 ISP_BeVregAddrInit(VI_PIPE ViPipe);
HI_S32 ISP_GetBeVregCfgAddr(VI_PIPE ViPipe, HI_VOID *pVirtAddr[]);
HI_S32 ISP_GetBeBufFirst(VI_PIPE ViPipe);
HI_S32 ISP_GetBeFreeBuf(VI_PIPE ViPipe);
HI_S32 ISP_AllCfgsBeBufInit(VI_PIPE ViPipe);
HI_S32 ISP_SetCfgBeBufState(VI_PIPE ViPipe);
HI_S32 ISP_RegCfgInfoSet(VI_PIPE ViPipe);
HI_S32 ISP_RegCfgInfoInit(VI_PIPE ViPipe);
HI_S32 ISP_Lut2SttApbReg(VI_PIPE ViPipe);
HI_S32 ISP_SyncCfgSet(VI_PIPE ViPipe);
HI_S32 ISP_SnapRegCfgSet(VI_PIPE ViPipe, hi_isp_config_info *pstSnapInfo);
HI_S32 ISP_SnapRegCfgGet(VI_PIPE ViPipe, isp_snap_info *pstSnapInfo);
HI_BOOL ISP_ProTriggerGet(VI_PIPE ViPipe);
HI_VOID *ISP_GetBeVirAddr(VI_PIPE ViPipe, BLK_DEV BlkDev);
HI_VOID *ISP_GetBeLut2SttVirAddr(VI_PIPE ViPipe, BLK_DEV BlkDev, HI_U8 U8BufId);
HI_VOID *ISP_GetViProcVirAddr(VI_PIPE ViPipe, BLK_DEV BlkDev);
HI_VOID *ISP_GetFeVirAddr(VI_PIPE ViPipe);
HI_S32 ISP_SwitchStateSet(VI_PIPE ViPipe);
HI_S32  ISP_SetBeRaw(VI_PIPE ViPipe);

#define ISP_CHECK_FE_PIPE(pipe)                              \
    do {                                                     \
        if (((pipe) < 0) || ((pipe) >= ISP_MAX_PIPE_NUM)) {  \
            ISP_ERR_TRACE("Invalid ISP-FE Pipe!\n"); \
            return HI_NULL;                                  \
        }                                                    \
    } while (0)

#define ISP_CHECK_BE_DEV(dev)                                 \
    do {                                                      \
        if (((dev) < 0) || ((dev) >= ISP_STRIPING_MAX_NUM)) { \
            ISP_ERR_TRACE("Err ISP-BE dev!\n");       \
            return HI_NULL;                                   \
        }                                                     \
    } while (0)

#define ISP_CHECK_NULLPTR(ptr)                                                \
    do {                                                                      \
        if (ptr == HI_NULL) {                                                 \
            ISP_ERR_TRACE("Null point when writing isp register!\n"); \
            return HI_NULL;                                                   \
        }                                                                     \
    } while (0)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
