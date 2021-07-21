################################################################################
#
# genimage-custom
# replecement for genimage
#
################################################################################

HOST_GENIMAGE_CUSTOM_VERSION = 14
HOST_GENIMAGE_CUSTOM_SOURCE = genimage-$(HOST_GENIMAGE_CUSTOM_VERSION).tar.xz
HOST_GENIMAGE_CUSTOM_SITE = https://github.com/pengutronix/genimage/releases/download/v$(HOST_GENIMAGE_CUSTOM_VERSION)
HOST_GENIMAGE_CUSTOM_DEPENDENCIES = host-pkgconf host-libconfuse
HOST_GENIMAGE_CUSTOM_LICENSE = GPL-2.0
HOST_GENIMAGE_CUSTOM_LICENSE_FILES = COPYING

$(eval $(host-autotools-package))
