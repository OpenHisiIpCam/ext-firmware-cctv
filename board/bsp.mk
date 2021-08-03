include $(BR2_EXTERNAL_CCTV_PATH)/board/fullhan/fullhan.mk
include $(BR2_EXTERNAL_CCTV_PATH)/board/goke/goke.mk
include $(BR2_EXTERNAL_CCTV_PATH)/board/grainmedia/grainmedia.mk
include $(BR2_EXTERNAL_CCTV_PATH)/board/hisilicon/hisilicon.mk
include $(BR2_EXTERNAL_CCTV_PATH)/board/novatek/novatek.mk
include $(BR2_EXTERNAL_CCTV_PATH)/board/sigmastar/sigmastar.mk
include $(BR2_EXTERNAL_CCTV_PATH)/board/xiongmai/xiongmai.mk

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

