/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/


#ifndef __ISP_DEBUG_H__
#define __ISP_DEBUG_H__

#include <stdio.h>
#include "hi_type.h"
#include "hi_errno.h"
#include "hi_comm_isp_adapt.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

typedef struct {
    hi_bool debug_en;
    hi_u64  phy_addr;
    hi_u32  depth;

    hi_u32  size;
    hi_isp_dbg_attr   *dbg_attr;
    hi_isp_dbg_status *dbg_status;
} isp_dbg_ctrl;

HI_S32 isp_dbg_set(VI_PIPE vi_pipe, const hi_isp_debug_info *dbg_info);
HI_S32 isp_dbg_get(VI_PIPE vi_pipe, hi_isp_debug_info *dbg_info);
HI_S32 ISP_DbgRunBgn(isp_dbg_ctrl *dbg, hi_u32 frm_cnt);
HI_S32 ISP_DbgRunEnd(isp_dbg_ctrl *dbg, hi_u32 frm_cnt);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HISI_ISP_DEBUG_H__ */
