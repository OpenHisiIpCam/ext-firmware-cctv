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
/// \ingroup lws

#include "lws.h"

#include <assert.h>

#include "../error.h"
#include "../log/log.h"

// Reference:
// https://libwebsockets.org/lws-api-doc-v4.2-stable/html/structlws__http__mount.html
// Reference:
// https://libwebsockets.org/lws-api-doc-main/html/structlws__protocols.html

extern const error_t error_none;
extern const error_t error_alloc;

typedef struct
{
  char* name;
  error_t (*init_cb)(void* user,
                     struct lws_http_mount* mount,
                     struct lws_protocols* protocol);
  void* user;
} lws_plugin_t;

static void
lws_log_wrapper(int lws_level, const char* line)
{
  int level;

  /// \todo rearrange level, to have good usefull output
  switch (lws_level) {
    case LLL_USER:
    case LLL_LATENCY:
    case LLL_CLIENT:
    case LLL_EXT:
    case LLL_HEADER:
    case LLL_PARSER:
      level = LOG_TRACE;
      break;
    case LLL_DEBUG:
      level = LOG_DEBUG;
      break;
    case LLL_INFO:
    case LLL_NOTICE:
      level = LOG_INFO;
      break;
    case LLL_WARN:
      level = LOG_WARN;
      break;
    case LLL_ERR:
      level = LOG_ERROR;
      break;
    default:
      assert(0);
      break;
  }

  if (0) {
    log_log(level, __FILE__, __LINE__, line);
  } else {
    log_log(level, "libwebsockets fwd", 0, line);
  }
}

/// \brief Add lws mount item to the list
///
///
static error_t
lws_mount_add(struct lws_http_mount** mounts, const struct lws_http_mount* item)
{
  assert(mounts != NULL);

  int counter = 0;
  struct lws_http_mount* target = *mounts;

  if (target == NULL) {
    target = (struct lws_http_mount*)malloc(sizeof(struct lws_http_mount));
    if (target == NULL) {
      log_fatal("malloc() failed!\n");
      return error_alloc;
    }
  } else {
    do {
      counter++;
    } while ((target + counter - 1)->mount_next != NULL);

    struct lws_http_mount* new = (struct lws_http_mount*)realloc(
      target, sizeof(struct lws_http_mount) * (counter + 1));

    if (new == NULL) {
      log_fatal("realloc() failed!\n");
      return error_alloc;
    } else {
      target = new;
      (target + counter - 1)->mount_next = (target + counter);
    }
  }

  memcpy((target + counter), item, sizeof(struct lws_http_mount));
  *mounts = target;

  return error_none;
}

/// \brief Add lws protocol item to array
///
///
static error_t
lws_protocol_add(struct lws_protocols** protocols,
                 const struct lws_protocols* item)
{
  assert(protocols != NULL);

  int counter = 0;
  struct lws_protocols* target = *protocols;

  if (target == NULL) {
    target = (struct lws_protocols*)malloc(sizeof(struct lws_protocols) * 2);
    if (target == NULL) {
      log_fatal("malloc() failed!\n");
      return error_alloc;
    }
    memset(target + 1, 0, sizeof(struct lws_protocols));
  } else {
    while ((target + counter)->name != NULL) {
      counter++;
    }

    struct lws_protocols* new = (struct lws_protocols*)realloc(
      target, sizeof(struct lws_protocols) * (counter + 2));

    if (new == NULL) {
      log_fatal("realloc() failed!\n");
      return error_alloc;
    } else {
      target = new;
    }
    memset(target + counter + 1, 0, sizeof(struct lws_protocols));
  }

  memcpy((target + counter), item, sizeof(struct lws_protocols));
  *protocols = target;

  return error_none;
}

static int
lws_functions_init(lws_params_t* params, lws_t* lws)
{
  assert(params != NULL);
  assert(lws != NULL);
  assert(lws->mounts == NULL);
  assert(lws->protocols == NULL);

  error_t e;

  if (1 /*files enabled*/) {
    const struct lws_http_mount files = {
      .mountpoint = "/",
      .mountpoint_len = 1,
      .origin_protocol = LWSMPRO_FILE,
      .origin = params->network_file_dir,
      .def = "index.html",
    };

    e = lws_mount_add(&lws->mounts, &files);
    if (ERR_NONE != e.err) {
      log_fatal("lws_mount_add(files) failed!\n");
      goto fail;
    }
  }

  const lws_plugin_t plugins[] = {
    { .name = "api", .init_cb = api_lws_init_cb, .user = params->api },
    { .name = "jpeg", .init_cb = jpeg_lws_init_cb, .user = params->jpeg },
    //{ .name = "log", .init_cb = log_ram_lws_init_cb, .user = NULL },
    { 0 }
  };

  const lws_plugin_t* plugin = plugins;

  while (NULL != plugin->name) {
    assert(NULL != plugin->init_cb);

    struct lws_http_mount mount;
    struct lws_protocols protocol;

    e = plugin->init_cb(plugin->user, &mount, &protocol);
    switch (e.err) {
      case ERR_NONE:
        e = lws_mount_add(&lws->mounts, &mount);
        if (ERR_NONE != e.err) {
          log_fatal("lws_mount_add(%s) failed!\n", plugin->name);
          goto fail;
        }

        e = lws_protocol_add(&lws->protocols, &protocol);
        if (ERR_NONE != e.err) {
          log_fatal("lws_protocol_add(%s) failed!\n", plugin->name);
          goto fail;
        }
        break;
      case ERR_NOTBUILTIN:
        log_trace("lws plugin '%s' not built-in.\n", plugin->name);
        break;
      case ERR_NOTINITED:
        log_trace("lws plugin '%s' can`t be intited.\n", plugin->name);
        break;
      default:
        assert(0);
        break;
    }

    plugin++;
  }

  return 0;

fail:
  free(lws->mounts);
  free(lws->protocols);

  return 1;
}

lws_t*
lws_init(lws_params_t* params, int* error)
{
  struct lws_context_creation_info info = { 0 };

  assert(NULL != params);
  assert(NULL != params->loop_uv);

  lws_t* lws = (lws_t*)calloc(1, sizeof(lws_t));
  if (NULL == lws) {
    log_fatal("calloc() failed!\n");
    goto fail; // return 1;
  }

  lws->loop_uv = params->loop_uv;

  lws_set_log_level(LLL_USER | LLL_ERR | LLL_WARN | LLL_NOTICE /*| LLL_DEBUG*/,
                    lws_log_wrapper);

  /// \todo check libwebsockets documentation and tune info.options
  info.options = LWS_SERVER_OPTION_LIBUV | LWS_SERVER_OPTION_EXPLICIT_VHOSTS;
  info.foreign_loops = (void*)&lws->loop_uv;

  lws->lws_context = lws_create_context(&info);
  if (NULL == lws->lws_context) {
    log_fatal("lws_create_context() failed!\n");
    goto fail; // return 1;
  }

  int r = lws_functions_init(params, lws);
  if (0 != r) {
    log_fatal("lws_functions_init() failed!\n");
    goto fail; // return 1;
  }

  if (HTTP_SERVER_NETWORK /*&& params.network*/) {
    /// \todo add httpS

    info.port = 8001; /// @todo use params->port
    info.protocols = lws->protocols;
    info.mounts = lws->mounts;
    info.error_document_404 = "/";     // Single Page Application behavior
    info.pcontext = &lws->lws_context; /// @todo what is it?
    info.vhost_name = "network";

    lws->vhost_net = lws_create_vhost(lws->lws_context, &info);
    if (NULL == lws->vhost_net) {
      log_fatal("lws_create_vhost(network) failed!\n");
      goto fail; // return 1;
    }
  }

  if (HTTP_SERVER_UDS /*&& params.uds*/) {
    /// \todo remove files serve from uds

    info.port = 0;
    info.protocols = lws->protocols;
    info.mounts = lws->mounts; // + 1; /// @todo make nicer, skip files
    info.error_document_404 = "/";
    info.pcontext = &lws->lws_context;
    info.vhost_name = "uds";
    info.iface = "/tmp/streamer"; /// @todo use params->path
    info.options |= LWS_SERVER_OPTION_UNIX_SOCK;

    lws->vhost_uds = lws_create_vhost(lws->lws_context, &info);
    if (NULL == lws->vhost_uds) {
      log_fatal("lws_create_vhost(uds) failed!\n");
      goto fail; // return 1;
    }
  }

  *error = 0;
  return lws;

fail:
  /// \todo how to close it?
  // lws_context_destroy(lws->lws_context);
  free(lws);

  *error = 1;
  return NULL;
}

void
lws_deinit(lws_t* lws)
{
  assert(NULL != lws);

  // lws_context_destroy(lws->lws_context); /// @todo check return ?

  free(lws->mounts);
  free(lws->protocols);
}
