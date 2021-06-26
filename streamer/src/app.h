/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \defgroup mainapp Main Application

/// \file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup mainapp

#ifndef APP_H
#define APP_H

#include <libconfig.h>
#include <uv.h>

#include "exchange/exchange.h"

#include "platform/dummy/dummy.h"
#include "platform/hisilicon_deprecated/hisilicon.h"
#include "platform/infinity6b0/infinity6b0.h"
#include "platform/infinity6e/infinity6e.h"
#include "platform/nt9852x/nt9852x.h"
#include "platform/nt9856x/nt9856x.h"
#include "platform/xm530/xm530.h"

#include "streamer/jpeg/jpeg.h"
#include "streamer/pipe/pipe.h"
#include "streamer/rtp/rtp.h"
#include "streamer/webrtc/webrtc.h"

#include "json-api/json-api.h"

#include "log/log.h"
#include "lws/lws.h"
//#include "script/script.h"

/// @brief Startup params parsed from cmd
///
/// This struct first filled with default values, than cmd params replace
/// default values.
typedef struct
{
  char* config; ///< libconfig file path
  // int http_server;  ///< enable/disable http server flag
  // int streamer_rtp; ///< enable/disable rtp streamer module flag

  int http_server;
  int streamer_jpeg;
  int streamer_pipe;
  int streamer_rtp;
  int streamer_webrtc;

  /// @todo
} app_params_t;

/// @brief Main app`s struct
///
/// All permanent application`s data is handled here. Even if some module is not
/// compiled into final binary pointer (if possible) will be here.
typedef struct
{
  app_params_t params;
  config_t* config; ///< libconfig instance

  exchange_t exchange;

  uv_loop_t loop_uv;         ///< libuv instance
  uv_signal_t sighandler_uv; ///< signal handler (via libuv)

  log_ram_t* log_ram;

  lws_t* lws; ///< libwebsockets ws/http server instance

  dummy_t* dummy; ///< Dummy platform
  /// @todo union should be named!
  union
  {
    hisilicon_t* hisilicon; ///< HiSilicon platform
    xm530_t* xm530;         ///< XM530 platform
    // infinity6b0_t *infinity6b0; ///<
    // infinity6e_t *infinity6e; ///<
    // nt9852x_t *nt9852x; ///<
    // nt9856x_t *nt9856x; ///<
  }; ///< Anonymous union for hw dependent platform
     ///< As it is only one hw platform build possible they are grouped as
     ///< union

  union
  {
    dummy_t* dummy;
    hisilicon_t* hisilicon;
    xm530_t* xm530;
  } platform;

  jpeg_t* jpeg;
  pipe_t* pipe;
  rtp_t* rtp; ///< RTP streamer module
  webrtc_t* webrtc;

  // script_t* script; ///< Test script instance
} streamer_t;

#endif /*APP_H*/
