include ../Makefile.versions.include
include packages

PREBUILT_OUTPUT_DIR=$(abspath ../output/prebuilt)

build: ../vendors/buildroot
	make \
                -C $(abspath ../vendors/buildroot) \
		BR2_EXTERNAL=$(abspath ..) \
                O=$(PREBUILT_OUTPUT_DIR) \
		prebuilt_defconfig

	make -C $(PREBUILT_OUTPUT_DIR) $(subst ",,$(PACKAGES))
	rm -rf $(BUILDROOT_VERSION)
	./pack.sh $(PREBUILT_OUTPUT_DIR) $(BUILDROOT_VERSION) 
	rm -rf $(PREBUILT_OUTPUT_DIR)

../vendors/buildroot:
	make -C ../vendors buildroot

.PHONY: clean
clean:
	rm -rf $(BUILDROOT_VERSION)
