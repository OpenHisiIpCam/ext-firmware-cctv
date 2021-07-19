/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#ifndef XM530_H
#define XM530_H

#include <libconfig.h>

typedef struct
{
  config_t* config;
} xm530_params_t;

typedef struct
{
  config_t* config;
} xm530_t;

int
xm530_init(xm530_params_t* params, xm530_t* xm530);
void
xm530_deinit(xm530_t* xm530);

#endif /*XM530_H*/
