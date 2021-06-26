/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#include "log-lws.h"

typedef struct
{
} log_ram_lws_session_t;

static int
log_ram_lws_callback(struct lws* wsi,
                     enum lws_callback_reasons reason,
                     void* user,
                     void* in,
                     size_t len)
{
  return 0;
}

struct lws_http_mount
log_ram_lws_mount()
{
  return (struct lws_http_mount){ .mountpoint = "/log",
                                  .mountpoint_len = 4,
                                  .origin_protocol = LWSMPRO_CALLBACK,
                                  .protocol = "log" };
}
struct lws_protocols
log_ram_lws_protocol(log_ram_t* log_ram)
{
  return (struct lws_protocols){ .name = "log",
                                 .callback = log_ram_lws_callback,
                                 .per_session_data_size =
                                   sizeof(log_ram_lws_session_t),
                                 .rx_buffer_size = 0,
                                 .user = log_ram };
}
