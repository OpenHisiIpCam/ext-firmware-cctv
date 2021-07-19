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
/// \ingroup api

#ifndef API_METHOD_H
#define API_METHOD_H

#include <json-c/json.h>

typedef int (*api_method_func_t)(const struct json_object* params,
                                 struct json_object** result,
                                 void* user);

/// \brief TODO
///
/// Detailed description
typedef struct
{
  char* path;
  api_method_func_t func;
  void* user;
} api_method_t;

#endif /*API_METHOD_H*/
