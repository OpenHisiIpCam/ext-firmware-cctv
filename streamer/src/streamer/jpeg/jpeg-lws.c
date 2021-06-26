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
/// \ingroup streamer lws

#include "jpeg.h"

extern const error_t error_none;
extern const error_t error_notbuiltin;
extern const error_t error_notinited;

/*! @brief JPEG serving client data
 */
typedef struct
{
  /*
uint8_t *data;///< @brief Pointer to allocated buffer for client copy serving
data (used in copy serving mode). uint8_t encoder;///< @brief Number of encoder.
uint8_t frame;///< @brief Number of frame in encoder`s storage.
uint32_t sent;///< @brief Amount of served (pushed to socket) bytes.
uint32_t size;///< @brief Size of data to be sent, even for economy mode should
be used, as original data can be lost in case of slow client. uint64_t pts;///<
@brief Local copy of serving frame pts value, use it to check that original
storage still has same frame.
*/
} jpeg_lws_session_t;

static int
jpeg_lws_callback(struct lws* wsi,
                  enum lws_callback_reasons reason,
                  void* user,
                  void* in,
                  size_t len)
{
  return 0;
}

error_t
jpeg_lws_init_cb(void* user,
                 struct lws_http_mount* mount,
                 struct lws_protocols* protocol)
{
  if (STREAMER_JPEG) {
    jpeg_t* jpeg = (jpeg_t*)user;

    if (NULL == jpeg) {
      return error_notinited;
    }

    const struct lws_http_mount jpeg_mount = { .mountpoint = "/jpeg",
                                               .mountpoint_len = 5,
                                               .origin_protocol =
                                                 LWSMPRO_CALLBACK,
                                               .protocol = "jpeg" };

    const struct lws_protocols jpeg_protocol = { .name = "jpeg",
                                                 .callback = jpeg_lws_callback,
                                                 .per_session_data_size =
                                                   sizeof(jpeg_lws_session_t),
                                                 .rx_buffer_size = 0,
                                                 .user = jpeg };

    memcpy(mount, &jpeg_mount, sizeof(struct lws_http_mount));
    memcpy(protocol, &jpeg_protocol, sizeof(struct lws_protocols));
    return error_none;
  }
  return error_notbuiltin;
}
