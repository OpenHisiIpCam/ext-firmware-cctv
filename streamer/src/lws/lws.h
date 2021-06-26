/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \defgroup lws HTTP server

/// \file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup lws

#ifndef LWS_H
#define LWS_H

#include <libwebsockets.h>
#include <uv.h>

#include "../error.h"

#include "../json-api/json-api.h"
#include "../log/log-lws.h"
#include "../streamer/jpeg/jpeg.h"

/// @brief libwebsockets`s params
///
/// http server is inited on startup, runtime configuration is not implemented.
/// Maybe such reconf is not possible.
typedef struct
{
  uv_loop_t* loop_uv;

  int network;
  int network_files;
  int network_api;
  unsigned int network_port;
  char* network_file_dir;

  int uds;
  int uds_api;
  char* usd_path;

  jpeg_t* jpeg;
  api_t* api;
  log_ram_t* log_ram;
} lws_params_t;

typedef struct
{
  uv_loop_t* loop_uv;

  struct lws_context* lws_context; /// @todo rename to context
  struct lws_vhost* vhost_net;
  struct lws_vhost* vhost_uds;

  struct lws_http_mount* mounts;
  struct lws_protocols* protocols;
} lws_t;

lws_t*
lws_init(lws_params_t* params, int* error);

void
lws_deinit(lws_t* lws);

#endif /*LWS_H*/
