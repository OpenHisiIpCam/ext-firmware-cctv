# Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
# SPDX-License-Identifier: MIT

# Tools pathes
DOXYGEN=../tools/doxygen/build/bin/doxygen

# Final binary name
OUTPUT ?= streamer

# Source files list
# Main application files
SRC += $(wildcard src/*.c)
# Log
SRC += $(wildcard src/log/*.c)
# Exchange
SRC += $(wildcard src/exchange/*c)
# System net
SRC += $(wildcard src/system/net/*.c)
# System OTA
SRC += $(wildcard src/system/ota/*.c)
# Platform dummy
SRC += $(wildcard src/platform/dummy/*.c)
# Platform HiSilicon
SRC += $(wildcard src/platform/hisilicon/*.c) 
SRC += $(wildcard src/platform/hisilicon/*/*.c)
# Platform XM530
SRC += $(wildcard src/platform/xm530/*.c)
# Platform infinity6b0
SRC += $(wildcard src/platform/infinity6b0/*.c)
# Platform infinity6e
SRC += $(wildcard src/platform/infinity6e/*.c)
# Platform nt9852x
SRC += $(wildcard src/platform/nt9852x/*.c)
# Platform nt9856x
SRC += $(wildcard src/platform/nt9856x/*.c)
# LWS
SRC += $(wildcard src/lws/*.c)
# API
SRC += $(wildcard src/json-api/*.c)
# Streamer rtp
SRC += $(wildcard src/streamer/rtp/*.c)
# Streamer jpeg
SRC += $(wildcard src/streamer/jpeg/*.c)
# Streamer webrtc
SRC += $(wildcard src/streamer/webrtc/*.c)
# Streamer pipe
SRC += $(wildcard src/streamer/pipe/*.c)
# Script
SRC += $(wildcard src/script/*.c)

# Embeddable files list
# Platform HiSilicon
SRC_EMBED += $(wildcard vendor/hisilicon/*/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3516av200/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3516cv100/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3516cv200/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3516cv300/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3516cv500/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3510av100/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3516ev200/ko/*.ko)
#SRC_EMBED += $(wildcard vendor/hi3536dv100/ko/*.ko)
SRC_EMBED += $(wildcard vendor/xm530/ko/*.ko)

OBJECTS += $(patsubst %.c,%.o,$(SRC)) 
OBJECTS += $(patsubst %.ko,%.o,$(SRC_EMBED)) 
OBJECTS += src/LICENSE.o

# include build configuration parameters if needed
# TODO find nice way implement this, maybe unneded
#-include Makefile.$(CONFIGURATION).include

# Default build configuration (x86)
DEFAULT_CONFIG		?="/etc/streamer.config"

PLATFORM_DUMMY 		?=1
PLATFORM_HI3516AV100 	?=0
PLATFORM_HI3516AV200	?=0
PLATFORM_HI3516CV100	?=0
PLATFORM_HI3516CV200	?=0
PLATFORM_HI3516CV300	?=0
PLATFORM_HI3516CV500	?=0
PLATFORM_HI3516EV200	?=0
PLATFORM_XM530		?=0
PLATFORM_INFINITY6B0	?=0
PLATFORM_INFINITY6E	?=0
PLATFORM_NT9852X	?=0
PLATFORM_NT9856X	?=0
EMBED_KO 		?=0
HTTP_SERVER 		?=1
HTTP_SERVER_NETWORK	?=1
HTTP_SERVER_UDS		?=1
STREAMER_RTP 		?=1
STREAMER_JPEG		?=1
STREAMER_PIPE           ?=1
STREAMER_WEBRTC         ?=1
LOG_RAM			?=1
JSON_API		?=1
PROCESSING_QUIRC	?=0

STREAMER_URL 		= "$(shell git config --get remote.origin.url)"

# TODO rework versioning
# Version is current tag or branch commit hash[-dirty]
STREAMER_VERSION = "$(shell git name-rev --name-only --tags HEAD)"
ifeq ($(STREAMER_VERSION),"undefined")
STREAMER_VERSION = "$(shell git rev-parse --abbrev-ref HEAD) $(shell git rev-parse --short HEAD)$(shell git diff --quiet . || echo '-dirty')"
endif

# Actual gcc configuration parameters assigment
CFLAGS += -DSTREAMER_VERSION_URL='$(STREAMER_URL)'
CFLAGS += -DSTREAMER_VERSION='$(STREAMER_VERSION)'
CFLAGS += -DDEFAULT_CONFIG_PATH='$(DEFAULT_CONFIG)'
CFLAGS += -DPLATFORM_DUMMY=$(PLATFORM_DUMMY)
CFLAGS += -DPLATFORM_HI3516AV100=$(PLATFORM_HI3516AV100)
CFLAGS += -DPLATFORM_HI3516AV200=$(PLATFORM_HI3516AV200)
CFLAGS += -DPLATFORM_HI3516CV100=$(PLATFORM_HI3516CV100)
CFLAGS += -DPLATFORM_HI3516CV200=$(PLATFORM_HI3516CV200)
CFLAGS += -DPLATFORM_HI3516CV300=$(PLATFORM_HI3516CV300)
CFLAGS += -DPLATFORM_HI3516CV500=$(PLATFORM_HI3516CV500)
CFLAGS += -DPLATFORM_HI3516EV200=$(PLATFORM_HI3516EV200)
CFLAGS += -DPLATFORM_XM530=$(PLATFORM_XM530)
CFLAGS += -DPLATFORM_INFINITY6B0=$(PLATFORM_INFINITY6B0)
CFLAGS += -DPLATFORM_INFINITY6E=$(PLATFORM_INFINITY6E)
CFLAGS += -DPLATFORM_NT9852X=$(PLATFORM_NT9852X)
CFLAGS += -DPLATFORM_NT9856X=$(PLATFORM_NT9856X)
CFLAGS += -DEMBED_KO=$(EMBED_KO)
CFLAGS += -DHTTP_SERVER=$(HTTP_SERVER)
CFLAGS += -DHTTP_SERVER_NETWORK=$(HTTP_SERVER_NETWORK)
CFLAGS += -DHTTP_SERVER_UDS=$(HTTP_SERVER_UDS)
CFLAGS += -DSTREAMER_RTP=$(STREAMER_RTP)
CFLAGS += -DSTREAMER_JPEG=$(STREAMER_JPEG)
CFLAGS += -DSTREAMER_PIPE=$(STREAMER_PIPE)
CFLAGS += -DSTREAMER_WEBRTC=$(STREAMER_WEBRTC)
CFLAGS += -DLOG_RAM=$(LOG_RAM)
CFLAGS += -DJSON_API=$(JSON_API)
CFLAGS += -DPROCESSING_QUIRC=$(PROCESSING_QUIRC)

# Common compiler and linker options
# TODO gnu99 -> c99
CFLAGS += -std=gnu99 -Wall 
#CFLAGS += -DNDEBUG=1
#CFLAGS += -Wshadow -Werror 
#CFLAGS += -pedantic
LDFLAGS += -pthread -lconfig -luv -lwebsockets -ljson-c

# Allow gcc remove unused symbols (critical due to app conditional build architecture)
# Reference: https://gcc.gnu.org/legacy-ml/gcc-help/2003-08/msg00128.html
CFLAGS += -fdata-sections -ffunction-sections
LDFLAGS += -Wl,--gc-sections

# Temporary
# LDFLAGS += -Wl,--strip-all

# Debug
#CFLAGS += -O0 -pg -fsanitize=address -fno-omit-frame-pointer
CFLAGS += -O0 -pg -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize=null -fno-sanitize=alignment

# PERMANENT platform specific include pathes and ...
# TODO choose file organization
#CFLAGS_HISILICON   += Ivendor/hisilicon
#CFLAGS_HISILICON   += Ivendor/hisilicon/include
#CFLAGS_HI3516AV100 += -Ivendor/hisilicon/hi3516av100/include
#CFLAGS_HI3516AV200 += -Ivendor/hisilicon/hi3516av200/include
#CFLAGS_HI3516CV100 += -Ivendor/hisilicon/hi3516cv100/include
#CFLAGS_HI3516CV200 += -Ivendor/hisilicon/hi3516cv200/include
#CFLAGS_HI3516CV300 += -Ivendor/hisilicon/hi3516cv300/include
#CFLAGS_HI3516CV500 += -Ivendor/hisilicon/hi3516cv500/include
#CFLAGS_HI3516EV200 += -Ivendor/hisilicon/hi3516ev200/include

CFLAGS_XM530       += -Ivendor/xm530/include 

# Platforms specific include pathes and libraries
ifeq ($(PLATFORM_HI3516AV100),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_HI3516AV200),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_HI3516CV100),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_HI3516CV200),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_HI3516CV300),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_HI3516CV500),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_HI3516EV200),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_XM530),1)
LDFLAGS += vendor/xm530/lib/libmpi.a
endif
ifeq ($(PLATFORM_INFINITY6B0),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_INFINITY6E),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_NT9852X),1)
LDFLAGS +=
endif
ifeq ($(PLATFORM_NT9856X),1)
LDFLAGS +=
endif


all: $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

#src/platform/hisilicon/%.o: src/platform/hisilicon/%.c
#        $(CC) $(CFLAGS) $(CFLAGS_???) -o $@ -c $<

src/platform/xm530/%.o: src/platform/xm530/%.c
	$(CC) $(CFLAGS) $(CFLAGS_XM530) -o $@ -c $<

vendor/%.o: vendor/%.ko
	# TODO strip path in result symbols
	ld -r -b binary -o $@ $<

src/LICENSE.o : LICENSE
	ld -r -b binary -o $@ $<

../docs/doxygen:
	rm -rf ../docs/doxygen
	$(DOXYGEN) Doxyfile

HEADERS += $(wildcard src/*.h)
HEADERS += $(wildcard src/*/*.h)
HEADERS += $(wildcard src/*/*/*.h)
HEADERS += $(wildcard src/*/*/*/*.h)

#HEADERS +=  $(wildcard vendor/xm530/include/*.h)
#HEADERS +=  $(wildcard vendor/xm530/include/*/*.h)

GCHS 	+= $(patsubst %.h,%.h.gch,$(HEADERS))

headers: $(GCHS)

src/%.h.gch: src/%.h
	$(CC) $<

vendor/%.h.gch: vendor/%.h
	$(CC) $<


# Include style targets
include Makefile.style.include

clean:
	rm -f $(OUTPUT)
	rm -f $(OBJECTS)
	rm -f $(GCHS)

.PHONY: ../docs/doxygen

