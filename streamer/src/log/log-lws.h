/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#ifndef LOG_LWS_H
#define LOG_LWS_H

#include <libwebsockets.h>

#include "log.h"

struct lws_http_mount
log_ram_lws_mount();

struct lws_protocols
log_ram_lws_protocol(log_ram_t* log_ram);

#endif /*LOG_LWS_H*/
