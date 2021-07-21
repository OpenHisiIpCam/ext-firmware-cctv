################################################################################
#
# streamer
#
################################################################################

#HOST_ESH_VERSION = 0.3.1
#HOST_ESH_SITE = $(call github,jirutka,esh,v$(HOST_ESH_VERSION))
#HOST_ESH_LICENSE = MIT
#HOST_ESH_LICENSE_FILES = LICENSE

CAMERA_VERSION = last
CAMERA_SITE = $(BR2_EXTERNAL_CAMFW_PATH)/../software
CAMERA_SITE_METHOD = local
CAMERA_INSTALL_STAGING = NO
CAMERA_INSTALL_TARGET = YES

#define CAMERA_INSTALL_TARGET_CMDS
#    #mkdir -p $(TARGET_DIR)/usr/local/bin
#    #$(INSTALL) -D -m 0755 $(@D)/quectel-CM $(TARGET_DIR)/usr/local/bin
#    #$(INSTALL) -D -m 0755 $(@D)/quectel-qmi-proxy $(TARGET_DIR)/usr/local/bin
#endef
#
#define CAMERA_BUILD_CMDS
#    #$(TARGET_CONFIGURE_OPTS) $(TARGET_MAKE_ENV) $(MAKE) -C $(@D)
#    #$(TARGET_CONFIGURE_OPTS) $(TARGET_MAKE_ENV) $(MAKE) -C $(@D)/examples -f Makefile.linux PROJECT=demos/ssd1306_demo SDL_EMULATION=y
#    $(TARGET_CONFIGURE_OPTS) $(TARGET_MAKE_ENV) $(MAKE) -C $(@D)/tools/oled_cli
#endef

$(eval $(cmake-package))
