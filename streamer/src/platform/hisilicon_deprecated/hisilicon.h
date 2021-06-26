/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \defgroup hisilicon HiSilicon platform

/// \file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup platform hisilicon

#ifndef HISILICON_H
#define HISILICON_H

#include <libconfig.h>

//#include "../../log.h"
//#include "mpp1/mpp1.h"
//#include "mpp2/mpp2.h"
//#include "mpp3/mpp3.h"
//#include "mpp4/mpp4.h"

typedef enum
{
  HISILICON_FAMILY_NONE,

  HISILICON_HI3516AV100,
  HISILICON_HI3516AV200,
  HISILICON_HI3516CV100,
  HISILICON_HI3516CV200,
  HISILICON_HI3516CV300,
  HISILICON_HI3516CV500,
  HISILICON_HI3516EV200,
  HISILICON_HI3519AV100,
  HISILICON_HI3536DV100,

  HISILICON_FAMILY_MAX
} hisilicon_family_en;

typedef struct
{
  // log_t* log;
  config_t* config;
  hisilicon_family_en family;
} hisilicon_params_t;

typedef struct
{
  // log_t* log;
  config_t* config;

  hisilicon_family_en family;

  union
  {
    // hisilicon_mpp1_t* mpp1;
    // hisilicon_mpp2_t* mpp2;
    // hisilicon_mpp3_t* mpp3;
    // hisilicon_mpp4_t* mpp4;
  };
} hisilicon_t;

int
hisilicon_init(hisilicon_params_t* params, hisilicon_t* hisilicon);
void
hisilicon_deinit(hisilicon_t* hisilicon);

#endif /*HISILICON_H*/
