#ifeq ($(BR2_CCTV_PLATFORM_HI3516AV100),y)
#endif
#ifeq ($(BR2_CCTV_PLATFORM_HI3516AV200),y)
#endif
#ifeq ($(BR2_CCTV_PLATFORM_HI3516CV100),y)
#endif
#ifeq ($(BR2_CCTV_PLATFORM_HI3516CV200),y)
#endif
#ifeq ($(BR2_CCTV_PLATFORM_HI3516CV300),y)
#endif
#ifeq ($(BR2_CCTV_PLATFORM_HI3516CV500),y)
#endif
#ifeq ($(BR2_CCTV_PLATFORM_HI3516EV200),y)
#endif

#define LINUX_PRE_PATCH_HOOKS_SDK_PATCHES
#       $(APPLY_PATCHES) ...
#       echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
#       echo $(PATH)
#endef

#LINUX_PRE_PATCH_HOOKS += LINUX_PRE_PATCH_HOOKS_SDK_PATCHES
#LINUX_POST_PATCH_HOOKS
#LINUX_PRE_BUILD_HOOKS

# Uboot

## HiSilicon Legacy Uboot 2010.06
# Prepare build configuration
# Patch u-boot.bin with registers table

#define UBOOT_POST_PATCH_HOOKS_HISI_UBOOT2010_06
#       TODO esh target to include/configs/target.h
#endef

#define UBOOT_POST_INSTALL_IMAGES_HOOKS_HISI_UBOOT2010_06
#       $(BR2_EXTERNAL_CCTV_PATH)/scripts/hisi-uboot-add-regbin.sh
#endef

#ifeq ($(BR2_CCTV_PLATFORM_HISI_UBOOT2010_06),y)
#UBOOT_POST_PATCH_HOOKS += UBOOT_POST_PATCH_HOOKS_HISI_UBOOT2010_06
#UBOOT_POST_INSTALL_IMAGES_HOOKS += UBOOT_POST_INSTALL_IMAGES_HOOKS_HISI_UBOOT2010_06
#endif


