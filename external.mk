
include $(sort $(wildcard $(BR2_EXTERNAL_CCTV_PATH)/package/*/*.mk))

include $(BR2_EXTERNAL_CCTV_PATH)/bsp/bsp.mk

#SWUPDATE_POST_INSTALL_TARGET_HOOKS

#define TARGET_FINALIZE_HOOKS_OS_RELEASE
#	echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
#        ( \
#                echo "NAME=Buildroot123"; \
#                echo "VERSION=$(BR2_VERSION_FULL)"; \
#                echo "ID=buildroot"; \
#                echo "VERSION_ID=$(BR2_VERSION)"; \
#                echo "PRETTY_NAME=\"Buildroot $(BR2_VERSION)\"" \
#        ) >  $(TARGET_DIR)/usr/lib/os-release
#endef

#TARGET_FINALIZE_HOOKS += TARGET_FINALIZE_HOOKS_OS_RELEASE
