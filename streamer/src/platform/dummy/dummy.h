/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \defgroup dummy Dymmy platform

/// \file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup platform dummy

#ifndef DUMMY_H
#define DUMMY_H

#include <libconfig.h>

typedef struct
{
  config_t* config;
} dummy_params_t;

typedef struct
{
  config_t* config;
} dummy_t;

int
dummy_init(dummy_params_t* params, dummy_t* dummy);
void
dummy_deinit(dummy_t* dummy);

#endif /*DUMMY_H*/
