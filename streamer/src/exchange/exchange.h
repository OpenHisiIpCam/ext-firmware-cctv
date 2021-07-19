/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <pthread.h>

#include "storage.h"

typedef struct
{

  // int (*on_data_cb)(...);

} exchange_consumer_t;

typedef enum
{
  EXCHANGE_TYPE_NONE,

  EXCHANGE_TYPE_JPEG,
  EXCHANGE_TYPE_MJPEG,

  EXCHANGE_TYPE_H264,
  EXCHANGE_TYPE_H265,

  EXCHANGE_TYPE_MAX
} exchange_type_en;

typedef struct
{
  // char *name;
  exchange_type_en type;

  // int (*consumer_add)(...);
  // int (*consumer_remove)(...);

} exchange_item_t;

typedef struct
{
  pthread_mutex_t lock;

  exchange_item_t items[]; /// \todo maybe list required
} exchange_t;

typedef struct
{

} exchange_params_t;

int
exchange_init(exchange_t* exchange, exchange_params_t* params);
int
exchange_deinit(exchange_t* exchange);

int
exchange_item_add();
int
exchange_item_remove();

#endif /*EXCHANGE_H*/
