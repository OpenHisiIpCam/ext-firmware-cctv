################################################################################
#
# hi-sdk
#
################################################################################

HI_SDK_VERSION = $(BR2_PACKAGE_HI_SDK_FAMILY)-$(BR2_PACKAGE_HI_SDK_VERSION)
HI_SDK_SITE = $(BR2_EXTERNAL_CCTV_PATH)/boards/hisilicon/$(BR2_PACKAGE_HI_SDK_FAMILY)/sdk-$(HI_SDK_VERSION)
HI_SDK_SITE_METHOD = local
HI_SDK_INSTALL_STAGING = YES

define HI_SDK_INSTALL_STAGING_CMDS
        $(INSTALL) -D -m 0755 $(@D)/libfoo.a $(STAGING_DIR)/usr/lib/libfoo.a
        $(INSTALL) -D -m 0644 $(@D)/foo.h $(STAGING_DIR)/usr/include/foo.h
        $(INSTALL) -D -m 0755 $(@D)/libfoo.so* $(STAGING_DIR)/usr/lib
endef

ifeq ($(BR2_PACKAGE_HI_SDK_TARGET_KOMODS),y)
HI_SDK_INSTALL_TARGET = YES
HI_SDK_PRE_INSTALL_TARGET_HOOKS += HI_SDK_INSTALL_TARGET_CMDS_KOMODS
endif

ifeq ($(BR2_PACKAGE_HI_SDK_TARGET_LIBS),y)
HI_SDK_INSTALL_TARGET = YES
HI_SDK_PRE_INSTALL_TARGET_HOOKS += HI_SDK_INSTALL_TARGET_CMDS_LIBS
endif

define HI_SDK_INSTALL_TARGET_CMDS_KOMODS
        $(INSTALL) -D -m 0755 $(@D)/libfoo.so* $(TARGET_DIR)/usr/lib
endef

define HI_SDK_INSTALL_TARGET_CMDS_LIBS
        $(INSTALL) -D -m 0755 $(@D)/libfoo.so* $(TARGET_DIR)/usr/lib
endef

#define HI_SDK_INSTALL_TARGET_CMDS
#endef

$(eval $(generic-package))
