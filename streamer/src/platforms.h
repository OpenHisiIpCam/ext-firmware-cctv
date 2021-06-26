/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// @file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup mainapp

#ifndef PLATFORM_H
#define PLATFORM_H

#include "app.h"

#include "error.h"

const char*
platform_name();

int
platform_init(streamer_t* streamer);

void
platform_deinit(streamer_t* streamer);

#endif /*PLATFORM_H*/
