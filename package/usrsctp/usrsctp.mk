################################################################################
#
# libusrctp
#
################################################################################

USRSCTP_VERSION = 0.9.5.0
USRSCTP_SITE = $(call github,sctplab,usrsctp,$(USRSCTP_VERSION))
USRSCTP_INSTALL_STAGING = YES
USRSCTP_INSTALL_TARGET = YES

#USRSCTP_CONF_OPTS = -DUSE_GNUTLS=0

$(eval $(cmake-package))

