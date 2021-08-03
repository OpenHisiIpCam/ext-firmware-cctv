## HiSilicon Legacy Uboot 2010.06
# Prepare build configuration
# Patch u-boot.bin with registers table

define UBOOT_PRE_CONFIGURE_HOOKS_HISI_UBOOT2010_06
	@$(call MESSAGE,"Executing cripts/hisilicon-uboot-2010.06-board.sh")

	# TODO add vars
	$(HOST_DIR)/bin/esh \
		-o $(BUILD_DIR)/uboot-2010.06/include/configs/hi3516c.h \
		$(BR2_EXTERNAL_CCTV_PATH)/board/hisilicon/hi3516cv100/uboot-config.h.esh
endef

#define UBOOT_POST_INSTALL_IMAGES_HOOKS_HISI_UBOOT2010_06
#       $(BR2_EXTERNAL_CCTV_PATH)/scripts/hisi-uboot-add-regbin.sh
#endef

ifeq ($(BR2_CCTV_PLATFORM_HISI_UBOOT2010_06_CUSTOM),y)
UBOOT_PRE_CONFIGURE_HOOKS+= UBOOT_PRE_CONFIGURE_HOOKS_HISI_UBOOT2010_06
#UBOOT_POST_INSTALL_IMAGES_HOOKS += UBOOT_POST_INSTALL_IMAGES_HOOKS_HISI_UBOOT2010_06
endif

