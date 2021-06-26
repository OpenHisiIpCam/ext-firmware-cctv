/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#include "streamers.h"

extern error_t error_none;

error_t
streamers_init(streamer_t* app)
{
  // return ERROR_FAIL_SAFE;

  if (STREAMER_JPEG /*&& params.streamer_rtp*/) {
    /// @todo
  }

  if (STREAMER_PIPE /*&& params.streamer_rtp*/) {
    /// @todo
  }

  if (STREAMER_RTP /*&& params.streamer_rtp*/) {
    /// @todo
  }

  if (STREAMER_WEBRTC /*&& params.streamer_rtp*/) {
    /// @todo
  }

  return error_none;
}

void
streamers_deinit(streamer_t* app)
{
  if (STREAMER_WEBRTC /*&& params.streamer_rtp*/ /*&& NULL != app->webrtc*/) {
    /// @todo
  }

  if (STREAMER_RTP /*&& params.streamer_rtp*/) {
    /// @todo
  }

  if (STREAMER_PIPE /*&& params.streamer_rtp*/) {
    /// @todo
  }

  if (STREAMER_JPEG /*&& params.streamer_rtp*/) {
    /// @todo
  }
}
