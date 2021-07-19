#!/usr/bin/env bash

#env

IS_OTA_ON=$(cat ${BR2_CONFIG} | grep "BR2_PACKAGE_OTA=" | awk '{print $2}' FS='[=]')

if [ "${IS_OTA_ON}" != "y" ]; then
    echo "BR2_PACKAGE_OTA is not selected, script cannot be used."
    exit 1
fi

echo "Making OTA update file..."

# TODO proper version string
CONTAINER_VER=$(cat ${TARGET_DIR}/etc/sw-versions)
#DTS_NAME=$(cat ${BR2_CONFIG} | grep "BR2_LINUX_KERNEL_INTREE_DTS_NAME" | awk '{print $3}' FS='[="]')
# TODO
DTS_NAME=sipeed_lichee-nano


# TODO sw-description.templete > sw-description
#cp ${BR2_EXTERNAL_PROGRAMMER_PATH}/ota/sw-description ${BINARIES_DIR}/sw-description
#SW_DESCRIPTION=$(cat ${BR2_EXTERNAL_PROGRAMMER_PATH}/ota/sw-description.template)

sed \
	-e "s/_OTA_VERSION_/${CONTAINER_VER}/g" \
	-e "s/_OTA_DTB_FILENAME_/${DTS_NAME}.dtb/" \
	${BR2_EXTERNAL_TMETER_PATH}/ota/sw-description.template > ${BINARIES_DIR}/sw-description

FILES="sw-description zImage ${DTS_NAME}.dtb rootfs.squashfs"

cd ${BINARIES_DIR}
for i in $FILES; do echo $i; done | cpio -ov -H crc > ${BINARIES_DIR}/programmer_${CONTAINER_VER}.swu

echo "Finished OTA file programmer_${CONTAINER_VER}.swu"
