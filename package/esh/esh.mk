################################################################################
#
# esh
#
################################################################################

ESH_VERSION = 0.3.1
ESH_SITE = $(call github,jirutka,esh,v$(HOST_ESH_VERSION))
ESH_LICENSE = MIT
ESH_LICENSE_FILES = LICENSE

define HOST_ESH_INSTALL_CMDS
	cp $(@D)/esh $(HOST_DIR)/bin
endef

$(eval $(host-generic-package))
