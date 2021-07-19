/*
 * Copyright (c) 2020 rxi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 */

#include "log.h"

#define LOG_USE_COLOR (1)
#define MAX_CALLBACKS (1)

typedef struct
{
  log_LogFn fn;
  void* udata;
  int level;
} Callback;

static struct
{
  void* udata;
  log_LockFn lock;
  int level;
  bool quiet;
#ifdef MAX_CALLBACKS
  Callback callbacks[MAX_CALLBACKS];
#endif
} L;

static const char* level_strings[] = { "TRACE", "DEBUG", "INFO",
                                       "WARN",  "ERROR", "FATAL" };

#ifdef LOG_USE_COLOR
static const char* level_colors[] = { "\x1b[94m", "\x1b[36m", "\x1b[32m",
                                      "\x1b[33m", "\x1b[31m", "\x1b[35m" };
#endif

static void
stdout_callback(log_Event* ev)
{
  char buf[16];
  buf[strftime(buf, sizeof(buf), "%H:%M:%S", ev->time)] = '\0';
#ifdef LOG_USE_COLOR
  fprintf(ev->udata,
          "%s %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ",
          buf,
          level_colors[ev->level],
          level_strings[ev->level],
          ev->file,
          ev->line);
#else
  fprintf(ev->udata,
          "%s %-5s %s:%d: ",
          buf,
          level_strings[ev->level],
          ev->file,
          ev->line);
#endif
  vfprintf(ev->udata, ev->fmt, ev->ap);
  if (0) { // removed becasue of libwebsocket log forward, each message already
           // has \n
    fprintf(ev->udata, "\n");
  }
  fflush(ev->udata);
}

#ifdef MAX_CALLBACKS
static void
file_callback(log_Event* ev)
{
  char buf[64];
  buf[strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ev->time)] = '\0';
  fprintf(ev->udata,
          "%s %-5s %s:%d: ",
          buf,
          level_strings[ev->level],
          ev->file,
          ev->line);
  vfprintf(ev->udata, ev->fmt, ev->ap);
  fprintf(ev->udata, "\n");
  fflush(ev->udata);
}
#endif

static void
lock(void)
{
  if (L.lock) {
    L.lock(true, L.udata);
  }
}

static void
unlock(void)
{
  if (L.lock) {
    L.lock(false, L.udata);
  }
}

const char*
log_level_string(int level)
{
  return level_strings[level];
}

void
log_set_lock(log_LockFn fn, void* udata)
{
  L.lock = fn;
  L.udata = udata;
}

void
log_set_level(int level)
{
  L.level = level;
}

void
log_set_quiet(bool enable)
{
  L.quiet = enable;
}

#ifdef MAX_CALLBACKS
int
log_add_callback(log_LogFn fn, void* udata, int level)
{
  for (int i = 0; i < MAX_CALLBACKS; i++) {
    if (!L.callbacks[i].fn) {
      L.callbacks[i] = (Callback){ fn, udata, level };
      return 0;
    }
  }
  return -1;
}
#endif

#ifdef MAX_CALLBACKS
int
log_add_fp(FILE* fp, int level)
{
  return log_add_callback(file_callback, fp, level);
}
#endif

static void
init_event(log_Event* ev, void* udata)
{
  if (!ev->time) {
    time_t t = time(NULL);
    ev->time = localtime(&t);
  }
  ev->udata = udata;
}

void
log_log(int level, const char* file, int line, const char* fmt, ...)
{
  log_Event ev = {
    .fmt = fmt,
    .file = file,
    .line = line,
    .level = level,
  };

  lock();

  if (!L.quiet && level >= L.level) {
    init_event(&ev, stderr);
    va_start(ev.ap, fmt);
    stdout_callback(&ev);
    va_end(ev.ap);
  }

#ifdef MAX_CALLBACKS
  for (int i = 0; i < MAX_CALLBACKS && L.callbacks[i].fn; i++) {
    Callback* cb = &L.callbacks[i];
    if (level >= cb->level) {
      init_event(&ev, cb->udata);
      va_start(ev.ap, fmt);
      cb->fn(&ev);
      va_end(ev.ap);
    }
  }
#endif

  unlock();
}

/*
 * Below added ...
 */

/// \brief TODO
///
/// \todo remove if
static void
ram_callback(log_Event* ev)
{
  log_ram_t* log_ram = (log_ram_t*)ev->udata;

  char buf[64];
  buf[strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ev->time)] = '\0';
  int size = snprintf(log_ram->buf + (log_ram->line_size * log_ram->current),
                      log_ram->line_size,
                      "%s %-5s %s:%d: ",
                      buf,
                      level_strings[ev->level],
                      ev->file,
                      ev->line);

  size = log_ram->line_size - size;

  if (size > 0) {
    snprintf(log_ram->buf + (log_ram->line_size * log_ram->current + size),
             size,
             ev->fmt,
             ev->ap);
  }

  log_ram->current++;

  if (log_ram->current == log_ram->lines) {
    log_ram->current = 0;
    log_ram->overflow = 1;
  }
}

int
log_ram_add_callback(log_ram_t* log_ram, int level)
{
  return log_add_callback(ram_callback, log_ram, level);
}
