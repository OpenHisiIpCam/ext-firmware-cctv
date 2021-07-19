# TODO description

BUILDROOT_VERSION=2021.02.3
#BUILDROOT_VERSION=2021.05

#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/be-ext-bsp-infinity6b0)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-hi3516av100)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-hi3516av200)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-hi3516cv100)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-hi3516cv200)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-hi3516cv300)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-hi3516cv500)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-hi3516ev200)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-nt9852x)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-nt9856x)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath bsp/br-ext-bsp-xm530)
#BR_EXTERNAL := $(BR_EXTERNAL):$(abspath br-ext-camfw)

BR_EXTERNAL = $(abspath .)

include Makefile.docs.include

usage:
	@echo "Usage:"
	@echo "TODO"

x86: output
	echo "TODO"

firmware-%: buildroot-$(BUILDROOT_VERSION) output
	echo "TODO"
	#support/kconfig/merge_config.sh

output:
	mkdir -p output

buildroot-$(BUILDROOT_VERSION).tar.gz:
	wget https://buildroot.org/downloads/buildroot-$(BUILDROOT_VERSION).tar.gz

buildroot-$(BUILDROOT_VERSION): buildroot-$(BUILDROOT_VERSION).tar.gz
	tar -xvf buildroot-$(BUILDROOT_VERSION).tar.gz

list-defconfigs: buildroot-$(BUILDROOT_VERSION)
	make -C $(abspath buildroot-$(BUILDROOT_VERSION)) \
        BR2_EXTERNAL=$(BR_EXTERNAL) \
        list-defconfigs

configure: buildroot-$(BUILDROOT_VERSION)
	make -C $(abspath buildroot-$(BUILDROOT_VERSION)) \
        BR2_EXTERNAL=$(BR_EXTERNAL) \
        O=$(abspath output/$(CONFIG)) menuconfig #\
        #$(CONFIG)_defconfig

# Run BR utils/check-package on all custom packages
check-packages:
	./buildroot-2021.05/utils/check-package -b ./br-ext-camfw/package/camera/*
	#TODO

mrproper:
	make -C software clean
	rm -f buildroot-$(BUILDROOT_VERSION).tar.gz
	rm -rf buildroot-$(BUILDROOT_VERSION)
	rm -rf output

.PHONY: docs/doxygen
.PHONY: list-defconfigs
.PHONY: mrproper
