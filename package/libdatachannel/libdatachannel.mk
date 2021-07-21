################################################################################
#
# libdatachannel
#
################################################################################

LIBDATACHANNEL_VERSION = 0.14.0
LIBDATACHANNEL_SITE = $(call github,paullouisageneau,libdatachannel,v$(LIBDATACHANNEL_VERSION))
LIBDATACHANNEL_INSTALL_STAGING = YES
LIBDATACHANNEL_INSTALL_TARGET = YES
#LIBDATACHANNEL_DEPENDENCIES += libsrtp-custom

LIBDATACHANNEL_CONF_OPTS = -DUSE_GNUTLS=0 \
			   -DUSE_NICE=0 \
			   -DUSE_SYSTEM_SRTP=0 \
			   -DNO_WEBSOCKET=1 \
			   -DNO_MEDIA=0 \
			   -DNO_EXAMPLES=1 \
			   -DNO_TESTS=1

define LIBDATACHANNEL_POST_EXTRACT_HOOKS_GIT_SUBMODULES
	cd $(@D); \
		git clone --depth 1 https://github.com/SergiusTheBest/plog.git deps/plog; \
		git clone --depth 1 https://github.com/sctplab/usrsctp.git deps/usrsctp; \
		git clone --depth 1 https://github.com/paullouisageneau/libjuice deps/libjuice; \
		git clone --depth 1 https://github.com/nlohmann/json.git deps/json; \
		git clone https://github.com/cisco/libsrtp.git deps/libsrtp;
endef

# git clone https://github.com/cisco/libsrtp.git deps/libsrtp;

LIBDATACHANNEL_POST_EXTRACT_HOOKS += LIBDATACHANNEL_POST_EXTRACT_HOOKS_GIT_SUBMODULES

$(eval $(cmake-package))
