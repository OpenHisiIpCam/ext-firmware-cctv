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
/// \ingroup mainapp lws streamer

#include "app.h"

#include <assert.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "params.h"
#include "platforms.h"
#include "streamers.h"

#include "error.h"
#include "log/log.h"

#define INIT_OR_FAIL(init_fn, fail_msg, fail_goto, success_msg)                \
  do {                                                                         \
    error_t e = init_fn(&streamer);                                            \
    if (ERR_NONE != e.err) {                                                   \
      log_fatal(fail_msg);                                                     \
      goto fail_goto;                                                          \
    }                                                                          \
    log_info(success_msg);                                                     \
  } while (0)

#define INIT_OR_FAIL2(init_fn, fail_msg, fail_goto, success_msg)               \
  do {                                                                         \
    int e = init_fn(&streamer);                                                \
    if (0 != e) {                                                              \
      log_fatal(fail_msg);                                                     \
      goto fail_goto;                                                          \
    }                                                                          \
    log_info(success_msg);                                                     \
  } while (0)

#define INIT_OR_FAIL3(init_fn, fail_goto)                                      \
  do {                                                                         \
    error_t e = init_fn(&streamer);                                            \
    if (ERR_FAIL_HARD == e.err) {                                              \
      log_fatal(#init_fn " failed!\n");                                        \
      goto fail_goto;                                                          \
    } else if (ERR_FAIL_SOFT == e.err) {                                       \
      log_error(#init_fn " not inited.\n");                                    \
    } else if (ERR_NONE == e.err) {                                            \
      log_info(#init_fn " inited.\n");                                         \
    } else if (ERR_NOTBUILTIN == e.err) {                                      \
      ;                                                                        \
    } else {                                                                   \
      assert(0);                                                               \
    }                                                                          \
  } while (0)

extern const char _binary_LICENSE_start[];
extern const char _binary_LICENSE_end[];

/// @brief Startup params parsed from cmd
///
/// This struct first filled with default values, than cmd params replace
/// default values.
typedef struct
{
  char* config;     ///< libconfig file path
  int http_server;  ///< enable/disable http server flag
  int streamer_rtp; ///< enable/disable rtp streamer module flag

  /// @todo
} streamer_params_t;

static void
params_notset(streamer_params_t* params)
{
  params->config = NULL;
  params->http_server = INT_MIN;
  params->streamer_rtp = INT_MIN;
}

static void
params_defaults(streamer_params_t* params)
{
  params->config = DEFAULT_CONFIG_PATH;
  params->http_server = 1;
  params->streamer_rtp = 1;
}

static void
version()
{
  const char msg[] = "Streamer (%s)\n"
                     "Version: %s\n";
  //"Options: %s\n";

  printf(msg, STREAMER_VERSION_URL, STREAMER_VERSION /*, platform_name()*/);

  /// \todo print all build options
}

static void
license()
{
  fwrite(_binary_LICENSE_start,
         1,
         _binary_LICENSE_end - _binary_LICENSE_start,
         stdout);

  if ((PLATFORM_HI3516AV100 || PLATFORM_HI3516AV200 || PLATFORM_HI3516CV100 ||
       PLATFORM_HI3516CV200 || PLATFORM_HI3516CV300 || PLATFORM_HI3516CV500 ||
       PLATFORM_HI3516EV200)) {
    printf("\nThis binary is linked with HiSilicon (Shanghai) Technologies "
           "Co., Ltd proprietary libraries.\n");
  }

  if (PLATFORM_XM530) {
    printf("\nThis binary is linked with Hangzhou Xiongmai Technology Co., Ltd "
           "proprietary libraries.\n");
  }

  if (PLATFORM_INFINITY6B0 || PLATFORM_INFINITY6E) {
    printf("\nThis binary is linked with SigmaStar Technology Corp proprietary "
           "libraries.\n");
  }

  if (PLATFORM_NT9852X || PLATFORM_NT9856X) {
    printf("\nThis binary is linked with Novatek Microelectronics Corp "
           "proprietary libraries.\n");
  }
}

static void
help()
{
  version();
  const char msg[] = "\n"
                     "-h, --help    Show this message\n"
                     "-v, --version Show version and build information\n"
                     "-l, --license Show this binary license information\n"
                     "\n"
                     "-c, --config  Path to configuration file (default: %s)\n";

  printf(msg, DEFAULT_CONFIG_PATH);
}

static int
params_parse_cmd(int argc, char* argv[], streamer_params_t* params)
{
  int long_index;
  int short_index;

  struct option options[] = { { "help", no_argument, NULL, 'h' },
                              { "version", no_argument, NULL, 'v' },
                              { "license", no_argument, NULL, 'l' },
                              { "config", required_argument, NULL, 'c' },
                              { 0, 0, 0, 0 } };

  while (1) {
    short_index = getopt_long(argc, argv, "h", options, &long_index);

    if (short_index == -1) {
      break;
    } else if (short_index == 0) {
      switch (long_index) {
        case 1: // version
          version();
          exit(0); // return 1;
          break;
        case 2: // license
          license();
          exit(0); // return 1;
          break;
        default:
          printf("TODO option %s", options[long_index].name);
          if (optarg) {
            printf(" with arg %s", optarg);
          }
          printf("\n");
          assert(0);
          break;
      }
    } else if (short_index == 'h') {
      help();
      exit(0); // return 1;
    } else if (short_index == 'c') {
      printf("CONFIG OPTION TODO\n");
    } else if (short_index == '?') {
      printf("Try -h or --help.\n");
      exit(1); // return 1;
    } else {
      assert(0);
    }
  }

  return 0;
}

static int
config_parse(const char* file, config_t* config)
{
  config_init(config);

  int r = config_read_file(config, file);

  if (0 == r) {
    printf("\n%s:%d - %s",
           config_error_file(config),
           config_error_line(config),
           config_error_text(config));

    config_destroy(config);
    free(config);
    /// @todo
    return 1;
  }

  return 0;
};

/*
void signal_cb_uv(uv_signal_t *watcher, int signum) {
        int result = uv_loop_close(handle->loop);
    if (result == UV_EBUSY)
    {
        uv_walk(handle->loop, on_uv_walk, NULL);
    }
}

void on_uv_walk(uv_handle_t* handle, void* arg)
{
    uv_close(handle, on_uv_close);
}

void on_uv_close(uv_handle_t* handle)
{
    if (handle != NULL)
    {
        delete handle;
    }
}
*/

// static streamer_t* streamer_tmp;

static void
signal_cb_uv(uv_signal_t* watcher, int signum)
{
  streamer_t* streamer = watcher->data;

  lwsl_notice("Signal %d caught...\n", signum);

  switch (signum) {
    case SIGTERM:
    case SIGINT:
      break;
    default:
      break;
  }

  uv_stop(&streamer->loop_uv);
  /*
  if (streamer->lws != NULL) {
    lws_deinit(streamer->lws);
    free(streamer->lws);
    streamer->lws = NULL;
    log_trace("lws deinited\n");
  } else {
    log_info("exit(100)\n");
     exit(100);
    //abort();
  }
  */
}

int
main(int argc, char* argv[])
{
  streamer_params_t default_params = { 0 };
  streamer_params_t params = { 0 };
  streamer_t streamer = { 0 };

  int r;

  // api(NULL, NULL);
  // return 1;

  params_defaults(&default_params);
  params_notset(&params);

  r = params_parse_cmd(argc, argv, &params);
  if (0 != r) {
    goto shutdown;
  }

  if (params.config != NULL /*&& *params.config != NUL*/) {
    streamer.config = calloc(1, sizeof(config_t));
    if (NULL == streamer.config) {
      log_fatal("calloc() failed!\n");
      goto shutdown;
    }

    r = config_parse(params.config, streamer.config);
    if (0 != r) {
      log_fatal("config_parse() failed!\n");
      goto shutdown;
    }
  }

  if (LOG_RAM) {
    streamer.log_ram = calloc(1, sizeof(log_ram_t));
    if (NULL == streamer.log_ram) {
    }

    log_ram_params_t params = { 0 };

    r = log_ram_init(&params, streamer.log_ram);
    if (0 != r) {
    }
    log_trace("Log to RAM inited.\n");
  }

  r = uv_loop_init(&streamer.loop_uv); /// @todo check return
  if (0 != r) {
    log_fatal("UV loop init failed!\n");
    /// @todo check return error values
    goto shutdown;
  }
  log_trace("UV loop inited.\n");

  uv_signal_init(&streamer.loop_uv, &streamer.sighandler_uv);

  streamer.sighandler_uv.data = &streamer;

  uv_signal_start(&streamer.sighandler_uv, signal_cb_uv, SIGINT);
  /// @ todo add other signals

#if 0
  r = platform_init(&streamer);
  if (0 != r) {
    log_fatal("Platform init failed!\n");
    goto uv_shutdown;
  }
  log_trace("Platform inited.\n");
#else
  INIT_OR_FAIL2(platform_init,
                "Platform init failed!\n",
                uv_shutdown,
                "Platform inited.\n");

  // INIT_OR_FAIL3(platform_init,
  //              uv_shutdown);

#endif

#if 0
  error_t tmp = streamers_init(&streamer);
  if (ERR_NONE != tmp.err) {
    log_fatal("Streamers init failed!\n");
    goto platform_shutdown;
  }
  log_trace("Streamers inited.\n");
#else
  // INIT_OR_FAIL(streamers_init,
  //             "Streamers init failed!\n",
  //             platform_shutdown,
  //             "Streamers inited.\n");
  INIT_OR_FAIL3(streamers_init, platform_shutdown);

#endif

  if (HTTP_SERVER /*&& params.http_server*/) {
    lws_params_t params = { 0 };

    params.loop_uv = &streamer.loop_uv;

    streamer.lws = lws_init(&params, &r);
    if (0 != r) {
      log_fatal("LWS init failed!\n");
      goto uv_shutdown; // streamers_shutdown;
    }
    log_trace("LWS inited.\n");
  }

  log_info("App started!\n");
  uv_run(&streamer.loop_uv, UV_RUN_DEFAULT);
  log_info("Shutting down...\n");

http_server_shutdown:
  if (HTTP_SERVER /*&& enabled flag*/ /*&& NULL != streamer.lws*/) {
    lws_deinit(streamer.lws);
    free(streamer.lws);
    streamer.lws = NULL;
  }

streamers_shutdown:
  streamers_deinit(&streamer);

platform_shutdown:
  platform_deinit(&streamer);

uv_shutdown:
  /*
  uv_close((uv_handle_t*) &handle1, NULL);
  uv_close((uv_handle_t*) &handle2, NULL);

  uv_run(loop, UV_RUN_DEFAULT);
  */

  uv_signal_stop(&streamer.sighandler_uv);
  uv_close((uv_handle_t*)&streamer.sighandler_uv, NULL);

  log_trace("run\n");
  uv_run(&streamer.loop_uv, UV_RUN_DEFAULT);
  log_trace("ok\n");

  uv_loop_close(&streamer.loop_uv);

log_ram_shutdown:
  if (LOG_RAM) {
    log_ram_deinit(streamer.log_ram);
  }

  log_info("Bye!\n");

shutdown:
  return 0;
}
