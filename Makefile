# TODO description

BR_EXTERNAL = $(abspath .)

usage:
	@echo "Usage:"
	@echo "TODO"

prepare: vendors/buildroot configs

vendors/buildroot:
	make -C vendors buildroot

.PHONY: configs
configs:
	make -C configs

.PHONY: list-defconfigs
list-defconfigs: vendors/buildroot configs
	make \
		-C $(abspath vendors/buildroot) \
	        BR2_EXTERNAL=$(BR_EXTERNAL) \
	        list-defconfigs

.PHONY: %_defconfig
%_defconfig: vendors/buildroot configs
	@test -f ./configs/$@ || (echo "Config $@ does not exist"; exit 1)
	make \
		-C $(abspath vendors/buildroot) \
        	BR2_EXTERNAL=$(abspath $(BR_EXTERNAL)) \
        	O=$(abspath output/$(subst _defconfig,,$@)) \
        	$@

TOOLCHAINS = $(patsubst configs/%,%,$(wildcard configs/*toolchain-*_defconfig))
toolchains: $(TOOLCHAINS)

.PHONY: toolchain_%_defconfig
$(TOOLCHAINS): %: vendors/buildroot configs
	@test -f ./configs/$@ || (echo "Config $@ does not exist"; exit 1)
	make \
		-C $(abspath vendors/buildroot) \
		BR2_EXTERNAL=$(abspath $(BR_EXTERNAL)) \
        	O=$(abspath output/$(subst _defconfig,,$@)) \
        	$@
	make \
		-C $(abspath output/$(subst _defconfig,,$@)) \
		sdk
	cp -f $(abspath output/$(subst _defconfig,,$@))/images/*.tar.gz toolchain
	rm -rf $(abspath output/$(subst _defconfig,,$@))

# Run BR utils/check-package on all custom packages
.IGNORE: check-packages
check-packages: vendors/buildroot
	vendors/buildroot/utils/check-package -b $(BR_EXTERNAL)/package/*/*
	vendors/buildroot/utils/check-package -b $(BR_EXTERNAL)/package/*/*/*

deb:
	echo "TODO add deb apt-get dependencies"

.PHONY: mrproper
mrproper:
	make -C vendors clean
	make -C configs clean
	rm -rf output
