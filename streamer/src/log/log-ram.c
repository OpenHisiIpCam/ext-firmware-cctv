/*
 * Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
 * SPDX-License-Identifier: MIT
 */

#include "log.h"

#include <stdlib.h>

int
log_ram_init(log_ram_params_t* params, log_ram_t* log_ram)
{

  log_ram = calloc(1, sizeof(log_ram_t));
  if (NULL == log_ram) {
    /// \todo
    goto fail;
  }

  log_ram->lines = params->lines;
  log_ram->line_size = params->line_size;

  log_ram->buf = malloc(log_ram->lines * log_ram->line_size);
  if (NULL == log_ram->buf) {
    /// \todo
    goto fail;
  }

  int r = log_ram_add_callback(log_ram, params->level);
  if (0 != r) {
    goto fail;
  }

  return 0;

fail:
  free(log_ram->buf);
  free(log_ram);
  return 1;
}

void
log_ram_deinit(log_ram_t* log_ram)
{}
