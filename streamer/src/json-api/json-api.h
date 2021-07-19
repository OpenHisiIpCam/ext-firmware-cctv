/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \defgroup api API

/// \file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup api

#ifndef API_H
#define API_H

#include <libwebsockets.h>

#include "json-api-method.h"

#include "../platform/dummy/dummy.h"
#include "../platform/hisilicon_deprecated/hisilicon.h"
#include "../platform/infinity6b0/infinity6b0.h"
#include "../platform/infinity6e/infinity6e.h"
#include "../platform/nt9852x/nt9852x.h"
#include "../platform/nt9856x/nt9856x.h"
#include "../platform/xm530/xm530.h"

#include "../streamer/jpeg/jpeg.h"
#include "../streamer/pipe/pipe.h"
#include "../streamer/rtp/rtp.h"
#include "../streamer/webrtc/webrtc.h"

#include "../error.h"

typedef struct
{
  union
  {
    dummy_t* dummy;
    hisilicon_t* hisilicon;
    xm530_t* xm530;
  } platform;

  jpeg_t* jpeg;
  pipe_t* pipe;
  rtp_t* rtp;
  webrtc_t* webrtc;
} api_params_t;

typedef struct
{
  api_method_t* methods;

  /*
  union
  {
    dummy_t* dummy;
    hisilicon_t* hisilicon;
    xm530_t* xm530;
  } platform;
  */
} api_t;

int
api_init(api_params_t* params, api_t* api);

void
api_deinit(api_t* api);

error_t
api_lws_init_cb(void* user,
                struct lws_http_mount* mount,
                struct lws_protocols* protocol);

void
api(const char* request, char* answer);

char*
api2(api_t* api, const char* request);

#endif /*API_H*/
