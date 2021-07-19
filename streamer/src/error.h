/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

/// @file
/// A brief description of this file.
///
/// A longer description of this file.
/// Be very generous here.

#ifndef ERROR_H
#define ERROR_H

typedef enum
{
  ERR_NONE,

  ERR_GENERAL,

  ERR_ALLOC,

  ERR_NOTBUILTIN,
  ERR_NOTINITED,

  ERR_FAIL_SAFE,
  ERR_FAIL_SOFT,
  ERR_FAIL_HARD,

  ERR_MAX
} error_value_en;

typedef struct
{
  error_value_en err;
} error_t;

#define ERROR_NONE                                                             \
  (error_t) { .err = ERR_NONE }
#define ERROR_GENERAL                                                          \
  (error_t) { .err = ERR_GENERAL }
#define ERROR_ALLOC                                                            \
  (error_t) { .err = ERR_ALLOC }
#define ERROR_NOTBUILTIN                                                       \
  (error_t) { .err = ERR_NOTBUILTIN }
#define ERROR_NOTINITED                                                        \
  (error_t) { .err = ERR_NOTINITED }

#define ERROR_FAIL_SAFE                                                        \
  (error_t) { .err = ERR_FAIL_SAFE }

#endif /*ERROR_H*/
