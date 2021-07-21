/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_STATISTICS_H__
#define __ISP_STATISTICS_H__

#include "hi_comm_isp.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/* init the statistics buf */
HI_S32 ISP_StatisticsInit(VI_PIPE vi_pipe);
/* exit the statistics buf */
HI_S32 ISP_StatisticsExit(VI_PIPE vi_pipe);
/* get a statistics buf from kernel */
HI_S32 ISP_StatisticsGetBuf(VI_PIPE vi_pipe, hi_void **ppStat);
/* release a statistics buf to kernel */
HI_S32 ISP_StatisticsPutBuf(VI_PIPE vi_pipe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
