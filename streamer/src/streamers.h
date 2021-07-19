/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#ifndef STREAMERS_H
#define STREAMERS_H

#include "app.h"

#include "error.h"

error_t
streamers_init(streamer_t* app);

void
streamers_deinit(streamer_t* app);

#endif /*STREAMERS_H*/
