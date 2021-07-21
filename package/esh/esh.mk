################################################################################
#
# esh
#
################################################################################

HOST_ESH_VERSION = 0.3.1
HOST_ESH_SITE = $(call github,jirutka,esh,v$(HOST_ESH_VERSION))
HOST_ESH_LICENSE = MIT
HOST_ESH_LICENSE_FILES = LICENSE

define HOST_ESH_INSTALL_CMDS
	cp $(@D)/esh $(HOST_DIR)/bin
endef

$(eval $(host-generic-package))
