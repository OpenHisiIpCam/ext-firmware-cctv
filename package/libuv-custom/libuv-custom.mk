################################################################################
#
# libuv-custom
# replacement for libuv
#
################################################################################

# When bumping libuv, check if a new version of uvw is available
# and bump it too.
LIBUV_CUSTOM_VERSION = 1.42.0
LIBUV_CUSTOM_SOURCE = libuv-$(LIBUV_CUSTOM_VERSION).tar.gz
LIBUV_CUSTOM_SITE = $(call github,libuv,libuv,v$(LIBUV_CUSTOM_VERSION))
LIBUV_CUSTOM_DEPENDENCIES = host-pkgconf
LIBUV_CUSTOM_INSTALL_STAGING = YES
LIBUV_CUSTOM_AUTORECONF = YES
LIBUV_CUSTOM_LICENSE = BSD-2-Clause, BSD-3-Clause, ISC, MIT
LIBUV_CUSTOM_LICENSE_FILES = LICENSE
LIBUV_CUSTOM_CPE_ID_VENDOR = libuv

# Upstream needs tests to be run sequentially. This is the default in
# automake 1.11 and before, but not starting in 1.12. To maintain
# sequentiality in 1.12 and later, the automake option 'serial-tests'
# must be used, Unfortunately, it is not recognised by 1.11 and
# before. So upstream only adds it conditionally. We use automake
# 1.14, so we need it.
define LIBUV_CUSTOM_FIXUP_AUTOGEN
	echo "m4_define([UV_EXTRA_AUTOMAKE_FLAGS], [serial-tests])" \
		>$(@D)/m4/libuv-extra-automake-flags.m4
endef
LIBUV_CUSTOM_POST_PATCH_HOOKS += LIBUV_CUSTOM_FIXUP_AUTOGEN

$(eval $(autotools-package))
