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
/// \ingroup api lws

#include "json-api.h"

extern const error_t error_none;
extern const error_t error_notbuiltin;
extern const error_t error_notinited;

typedef struct
{
  char* body;
  size_t body_size;
  char* responce;
} api_lws_session_t;

static int
api_lws_callback(struct lws* wsi,
                 enum lws_callback_reasons reason,
                 void* user,
                 void* in,
                 size_t len)
{
  return 0;
}

error_t
api_lws_init_cb(void* user,
                struct lws_http_mount* mount,
                struct lws_protocols* protocol)
{
  if (JSON_API) {
    api_t* api = (api_t*)user;

    if (NULL == api) {
      return error_notinited;
    }

    const struct lws_http_mount api_mount = { .mountpoint = "/api",
                                              .mountpoint_len = 4,
                                              .origin_protocol =
                                                LWSMPRO_CALLBACK,
                                              .protocol = "api" };

    const struct lws_protocols api_protocol = { .name = "api",
                                                .callback = api_lws_callback,
                                                .per_session_data_size =
                                                  sizeof(api_lws_session_t),
                                                .rx_buffer_size = 0,
                                                .user = api };

    memcpy(mount, &api_mount, sizeof(struct lws_http_mount));
    memcpy(protocol, &api_protocol, sizeof(struct lws_protocols));
    return error_none;
  }
  return error_notbuiltin;
}
