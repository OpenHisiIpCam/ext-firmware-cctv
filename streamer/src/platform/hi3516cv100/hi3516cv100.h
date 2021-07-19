/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#ifndef HI3516CV100_H
#define HI3516CV100_H

typedef struct
{

} hi3516cv100_params_t;

typedef struct
{

} hi3516cv100_t;

int
hi3516cv100_init(hi3516cv100_t* hi3516cv100, hi3516cv100_params_t* params);

void
hi3516cv100_deinit(hi3516cv100_t* hi3516cv100);

#endif /*HI3516CV100_H*/
