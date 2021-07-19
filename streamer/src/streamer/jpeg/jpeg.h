/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup streamer

#ifndef JPEG_H
#define JPEG_H

#include <libwebsockets.h>

#include "../../error.h"

typedef struct
{
} jpeg_params_t;

typedef struct
{
} jpeg_t;

int
jpeg_init(jpeg_params_t* params, jpeg_t* jpeg);

void
jpeg_deinit(jpeg_t* jpeg);

error_t
jpeg_lws_init_cb(void* jpeg,
                 struct lws_http_mount* mount,
                 struct lws_protocols* protocol);

#endif /*JPEG_H*/
