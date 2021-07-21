#!/usr/bin/env bash
#
# Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
# SPDX-License-Identifier: MIT
#
# TODO brief description
#
# References:
# * https://www.freedesktop.org/software/systemd/man/os-release.html

if [ -z "$1" ]; then
        echo "This script should be invoked by Buildroot instance."
        echo "Path to the target filesystem will be passed as the first argument to this script by BR."
        exit 1
fi

# TODO extract vars from config

echo "

" > ${TARGET_DIR}/etc/issue

echo "NAME=Buildroot123
VERSION=${BR2_VERSION_FULL}
ID=openhisiipcam
ID_LIKE=buildroot
VERSION_ID=${BR2_VERSION}
PRETTY_NAME=\"Buildroot ${BR2_VERSION}\"
VARIANT=\"Server Edition\"
VARIANT_ID=xm_53h20-s_bsp
HOME_URL=\"http://www.openhisiipcam.org/\"
BUG_REPORT_URL=\"https://github.com/OpenHisiIpCam/cctv/issues\"
" > ${TARGET_DIR}/usr/lib/os-release
