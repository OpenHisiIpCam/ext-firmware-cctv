/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// \defgroup platform Platform backend

/// @file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.
///
/// \ingroup mainapp platform

#include "platforms.h"

#include <assert.h>
#include <string.h>

const char*
platform_name()
{
  if (PLATFORM_DUMMY) {
    return "dummy";
  }
  if (PLATFORM_HI3516AV100) {
    return "hi3516av100";
  }
  if (PLATFORM_HI3516AV200) {
    return "hi3516av200";
  }
  if (PLATFORM_HI3516CV100) {
    return "hi3516cv100";
  }
  if (PLATFORM_HI3516CV200) {
    return "hi3516cv200";
  }
  if (PLATFORM_HI3516CV300) {
    return "hi3516cv300";
  }
  if (PLATFORM_HI3516CV500) {
    return "hi3516cv500";
  }
  if (PLATFORM_HI3516EV200) {
    return "hi3516ev200";
  }
  if (PLATFORM_XM530) {
    return "xm530";
  }

  assert(0);
}

static int
platform_dummy_init(streamer_t* streamer)
{
  // streamer->dummy = malloc(sizeof(dummy_t));
  // if (streamer->dummy == NULL) {
  //  /// @todo
  //  return 1;
  //}

  dummy_params_t params = { 0 };

  // params.log = streamer->log;
  // params.config = streamer->config;

  int result = dummy_init(&params, streamer->dummy);
  if (result != 0) {
    /// @todo
    return 1;
  }

  return 0;
}

static int
platform_hisilicon_init(streamer_t* streamer)
{
  assert(NULL != streamer);

  hisilicon_params_t params = { 0 };
  // memset(&params, 0, sizeof(hisilicon_params_t));

  // params.log = &streamer->log;
  params.config = streamer->config;

  if (PLATFORM_HI3516AV100) {
    params.family = HISILICON_HI3516AV100;
    /// @todo
  } else if (PLATFORM_HI3516AV200) {
    params.family = HISILICON_HI3516AV200;
    /// @todo
  } else if (PLATFORM_HI3516CV100) {
    params.family = HISILICON_HI3516CV100;
    /// @todo
  } else if (PLATFORM_HI3516CV200) {
    params.family = HISILICON_HI3516CV200;
    /// @todo
  } else if (PLATFORM_HI3516CV300) {
    params.family = HISILICON_HI3516CV300;
    /// @todo
  } else if (PLATFORM_HI3516CV500) {
    params.family = HISILICON_HI3516CV500;
    /// @todo
  } else if (PLATFORM_HI3516EV200) {
    params.family = HISILICON_HI3516EV200;
    /// @todo
  }

  streamer->hisilicon = malloc(sizeof(hisilicon_t));
  if (streamer->hisilicon == NULL) {
    /// @todo
    return 1;
  }

  memset(streamer->hisilicon, 0, sizeof(hisilicon_t));
  int result = hisilicon_init(&params, streamer->hisilicon);
  if (result != 0) {
    /// @todo
    return 1;
  }

  return 0;
}

static int
platform_xm530_init(streamer_t* streamer)
{
  xm530_params_t params;
  memset(&params, 0, sizeof(xm530_params_t));

  // params.log = streamer->log;
  // params.config = streamer->config;

  streamer->xm530 = malloc(sizeof(xm530_t));
  if (streamer->xm530 == NULL) {
    /// @todo
    return 1;
  }

  memset(streamer->xm530, 0, sizeof(xm530_t));
  int result = xm530_init(&params, streamer->xm530);
  if (result != 0) {
    /// @todo
    return 1;
  }

  return 0;
}

static int
platform_infinity6b0_init(streamer_t* streamer)
{
  return 0;
}

static int
platform_infinity6e_init(streamer_t* streamer)
{
  return 0;
}

static int
platform_nt9852x_init(streamer_t* streamer)
{
  return 0;
}

static int
platform_nt9856x_init(streamer_t* streamer)
{
  return 0;
}

static void
platform_dummy_deinit(streamer_t* streamer)
{
  if (streamer->dummy != NULL) {
    dummy_deinit(streamer->dummy);
    free(streamer->dummy);
  }
}

static void
platform_hisilicon_deinit(streamer_t* streamer)
{
  if (streamer->hisilicon != NULL) {
    hisilicon_deinit(streamer->hisilicon);
    free(streamer->hisilicon);
  }
}

static void
platform_xm530_deinit(streamer_t* streamer)
{
  if (streamer->xm530 != NULL) {
    xm530_deinit(streamer->xm530);
    free(streamer->xm530);
  }
}

static void
platform_infinity6b0_deinit(streamer_t* streamer)
{}
static void
platform_infinity6e_deinit(streamer_t* streamer)
{}
static void
platform_nt9852x_deinit(streamer_t* streamer)
{}
static void
platform_nt9856x_deinit(streamer_t* streamer)
{}

/// \brief Platform init
///
/// Depending on build configuration function call target platform init
int
platform_init(streamer_t* streamer)
{
  //	int result;

  if (PLATFORM_DUMMY) {
    if (1) {
      platform_dummy_init(streamer);
    } else {
      // int result = dummy_init(&params, streamer->dummy);
      // if (0 != result) {
      /// @todo
      //	return 1;
    }
  }

  if (PLATFORM_HI3516AV100 || PLATFORM_HI3516AV200 || PLATFORM_HI3516CV100 ||
      PLATFORM_HI3516CV200 || PLATFORM_HI3516CV300 || PLATFORM_HI3516CV500 ||
      PLATFORM_HI3516EV200) {
    platform_hisilicon_init(streamer);
  }

  if (PLATFORM_XM530) {
    platform_xm530_init(streamer);
  }

  if (PLATFORM_INFINITY6B0) {
    /// @todo add ssc335
  }

  if (PLATFORM_INFINITY6E) {
    /// @todo add ssc338
  }

  if (PLATFORM_NT9852X) {
  }

  if (PLATFORM_NT9856X) {
  }

  return 0;
}

void
platform_deinit(streamer_t* streamer)
{
  if (PLATFORM_DUMMY) {
    platform_dummy_deinit(streamer);
  }

  if (PLATFORM_HI3516AV100 || PLATFORM_HI3516AV200 || PLATFORM_HI3516CV100 ||
      PLATFORM_HI3516CV200 || PLATFORM_HI3516CV300 || PLATFORM_HI3516CV500 ||
      PLATFORM_HI3516EV200) {
    platform_hisilicon_deinit(streamer);
  }

  if (PLATFORM_XM530) {
    platform_xm530_deinit(streamer);
  }

  if (PLATFORM_INFINITY6B0) {
  }

  if (PLATFORM_INFINITY6E) {
  }

  if (PLATFORM_NT9852X) {
  }

  if (PLATFORM_NT9856X) {
  }
}
