/*
* Copyright (C) Hisilicon Technologies Co., Ltd. 2012-2019. All rights reserved.
* Description:
* Author: Hisilicon multimedia software group
* Create: 2011/06/28
*/

#ifndef __ISP_PROC_H__
#define __ISP_PROC_H__

#include "hi_common.h"
#include "isp_main.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

HI_S32 ISP_ProcInit(VI_PIPE vi_pipe);
HI_S32 ISP_ProcWrite(const isp_alg_node *algs, VI_PIPE vi_pipe);
HI_S32 ISP_ProcExit(VI_PIPE vi_pipe);

#define ISP_PROC_PRINTF(proc, len, fmt...)                                              \
    do {                                                                                \
        hi_snprintf((proc)->proc_buff, (proc)->buff_len, (proc)->buff_len, ##fmt); \
        (proc)->write_len = strlen((proc)->proc_buff);                               \
        (proc)->proc_buff = &((proc)->proc_buff[(proc)->write_len]);                \
        (proc)->buff_len -= (proc)->write_len;                                      \
        len += (proc)->write_len;                                                     \
    } while (0)

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
