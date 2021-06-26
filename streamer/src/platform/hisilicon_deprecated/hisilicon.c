/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#include "hisilicon.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

//#include "mpp1/mpp1.h"
//#include "mpp2/mpp2.h"
//#include "mpp3/mpp3.h"
//#include "mpp4/mpp4.h"

int
hisilicon_init(hisilicon_params_t* params, hisilicon_t* hisilicon)
{
  assert(NULL != params);
  assert(NULL != hisilicon);
  assert(hisilicon->family <= HISILICON_FAMILY_NONE ||
         hisilicon->family >= HISILICON_FAMILY_MAX);

  return 0;
}

void
hisilicon_deinit(hisilicon_t* hisilicon)
{}
