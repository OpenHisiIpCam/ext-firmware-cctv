#!/usr/bin/env bash
#
# Copyright (c) 2021 OpenHisiIpCam, info@openhisiipcam.org
# SPDX-License-Identifier: MIT
#
# TODO brief description
#

if [ -z "$1" ]; then
	echo "This script should be invoked by Buildroot instance."
	echo "Path to the target filesystem will be passed as the first argument to this script by BR."
	exit 1
fi

#echo "'$0' '$1' '$2' '$3' '$4'"
#echo "----------------------------"
#env
#echo "----------------------------"

source ${BR2_EXTERNAL_CCTV_PATH}/scripts/libscripts.sh

FIRMWARE=$(get_config_value "BR2_CCTV_FIRMWARE" ${BR2_CONFIG})

if [ -z "${FIRMWARE}" ]; then
	echo "Noot needed"
	exit 0
fi

echo "Starting..."

ESH_BIN=${HOST_DIR}/bin/esh
FIRMWARE_DIR=${BR2_EXTERNAL_CCTV_PATH}/firmware

${ESH_BIN} -o ${BINARIES_DIR}/fw.genimage.cfg ${FIRMWARE_DIR}/1p16MB.cfg.esh \
	BR2_CCTV_FIRMWARE_UBOOT="u-boot.bin" \
	BR2_CCTV_FIRMWARE_LINUX="uImage" \
	BR2_CCTV_FIRMWARE_ROOTFS="rootfs.squashfs" \
	BR2_CCTV_FIRMWARE_USER_PARTITION="4"

support/scripts/genimage.sh -c ${BINARIES_DIR}/fw.genimage.cfg

echo "Finished"
