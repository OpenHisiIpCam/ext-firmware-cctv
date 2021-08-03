# TODO description

BR_EXTERNAL = $(abspath .)

include Makefile.docs.include
include Makefile.docker.include

usage:
	@echo "Usage:"
	@echo "TODO"

tools/buildroot:
	make -C tools buildroot

.PHONY: configs
configs:
	make -C configs

.PHONY: list-defconfigs
list-defconfigs: tools/buildroot configs
	make \
		-C $(abspath tools/buildroot) \
	        BR2_EXTERNAL=$(BR_EXTERNAL) \
	        list-defconfigs

.PHONY: %_defconfig
%_defconfig: tools/buildroot configs
	@test -f ./configs/$@ || (echo "Config $@ does not exist"; exit 1)
	make \
		-C $(abspath tools/buildroot) \
        	BR2_EXTERNAL=$(abspath $(BR_EXTERNAL)) \
        	O=$(abspath output/$(subst _defconfig,,$@)) \
        	$@

TOOLCHAINS = $(patsubst configs/%,%,$(wildcard configs/*toolchain-*_defconfig))
toolchains: $(TOOLCHAINS)

GENERICS = $(patsubst configs/%,%,$(wildcard configs/generic_*_defconfig))
generics: $(GENERICS)

.PHONY: toolchain_%_defconfig
$(TOOLCHAINS): %: tools/buildroot configs
	@test -f ./configs/$@ || (echo "Config $@ does not exist"; exit 1)
	make \
		-C $(abspath tools/buildroot) \
		BR2_EXTERNAL=$(abspath $(BR_EXTERNAL)) \
        	O=$(abspath output/$(subst _defconfig,,$@)) \
        	$@
	make \
		-C $(abspath output/$(subst _defconfig,,$@)) \
		sdk
	cp -f $(abspath output/$(subst _defconfig,,$@))/images/*.tar.gz toolchain
	rm -rf $(abspath output/$(subst _defconfig,,$@))

# Run BR utils/check-package on all custom packages
check-packages: tools/buildroot
	tools/buildroot/utils/check-package -b $(BR_EXTERNAL)/package/camera/*
	#TODO

deb:
	echo "TODO add deb apt-get dependencies"

.PHONY: mrproper
mrproper:
	make -C tools clean
	rm -rf output
