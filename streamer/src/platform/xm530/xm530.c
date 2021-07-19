/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#include "xm530.h"

/*********************/

#define SOC_XMSDK

#include "mpi_sys.h"
#include "xm/Camera.h"

static int xm530_sys_init(/*unsigned int RsltType*/)
{
  XM_MPI_SYS_Init(); // returns XM_S32

  CAMERACFG_TO_ISP stCfg = { 0 };

  stCfg.u32StdType = 0;
  stCfg.u32RsltType = 0; // RsltType;
  stCfg.u32Infrared = (1 << 31) | 0;

  camera_isp_task(&stCfg);

  return 0;
}

int static xm530_test(xm530_t* xm530)
{
  xm530_sys_init();

  return 0;
}

/*********************/

int
xm530_init(xm530_params_t* params, xm530_t* xm530)
{
  (void)xm530_test(xm530);

  return 0;
}

void
xm530_deinit(xm530_t* xm530)
{}
