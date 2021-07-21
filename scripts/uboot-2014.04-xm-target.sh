#!/bin/bash
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


# This script is applicable for  
#	hi3616cv100 family
#	...
#	
# It adds register init table to built uboot.bin

#source ${BR2_CONFIG}

echo "---------------------------"
env
echo "---------------------------"

REGBIN_FILE=$(grep "BR2_CCTV_UBOOT_REGBIN" ${BR2_CONFIG} | cut -d'=' -f2)
echo ${REGBIN_FILE}

UBOOT_FILE="TODO"
UBOOT_REGBIN_FILE="TODO"

#dd if=./u-boot.bin of=./fb1 bs=1 count=64
#dd if=$1 of=./fb2 bs=4096 conv=sync
#dd if=./u-boot.bin of=./fb3 bs=1 skip=4160
#cat fb1 fb2 fb3 > $2
#rm -f fb1 fb2 fb3

