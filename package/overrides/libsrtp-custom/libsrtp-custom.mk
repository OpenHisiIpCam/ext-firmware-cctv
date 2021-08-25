################################################################################
#
# libsrtp-custom
# replecement for libsrtp
#
################################################################################

LIBSRTP_CUSTOM_VERSION = 2.2.0
LIBSRTP_CUSTOM_SOURCE = libsrtp-$(LIBSRTP_CUSTOM_VERSION).tar.gz
LIBSRTP_CUSTOM_SITE = $(call github,cisco,libsrtp,v$(LIBSRTP_CUSTOM_VERSION))
LIBSRTP_CUSTOM_INSTALL_STAGING = YES
LIBSRTP_CUSTOM_LICENSE = BSD-3-Clause
LIBSRTP_CUSTOM_LICENSE_FILES = LICENSE
LIBSRTP_CUSTOM_CPE_ID_VENDOR = cisco

ifeq ($(BR2_STATIC_LIBS),y)
LIBSRTP_CUSTOM_MAKE_OPTS = libsrtp2.a
else ifeq ($(BR2_SHARED_LIBS),y)
LIBSRTP_CUSTOM_MAKE_OPTS = shared_library
else
LIBSRTP_CUSTOM_MAKE_OPTS = libsrtp2.a shared_library
endif

# While libsrtp is not using pkg-config itself, it checks if
# pkg-config is available to determine whether it should install
# libsrtp.pc. Since installing it seems useful, let's depend on
# host-pkgconf to make sure pkg-config is installed.
LIBSRTP_CUSTOM_DEPENDENCIES = host-pkgconf

# openssl handling needs libdl support
ifeq ($(BR2_PACKAGE_OPENSSL)x$(BR2_STATIC_LIBS),yx)
LIBSRTP_CUSTOM_DEPENDENCIES += openssl
LIBSRTP_CUSTOM_CONF_OPTS += --enable-openssl
else
LIBSRTP_CUSTOM_CONF_OPTS += --disable-openssl
endif

$(eval $(autotools-package))
