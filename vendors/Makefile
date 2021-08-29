BUILDROOT_VERSION=2021.02.3
MCP_VERSION=2.1.0

all: buildroot merge_config_plus

buildroot-$(BUILDROOT_VERSION).tar.gz:
	wget https://buildroot.org/downloads/buildroot-$(BUILDROOT_VERSION).tar.gz

buildroot-$(BUILDROOT_VERSION): buildroot-$(BUILDROOT_VERSION).tar.gz
	tar -m -xvf $<

buildroot: buildroot-$(BUILDROOT_VERSION)
	ln -s $< $@

merge_config_plus-$(MCP_VERSION).tar.gz:
	wget https://github.com/OpenHisiIpCam/merge_config_plus/archive/refs/tags/v$(MCP_VERSION).tar.gz -O $@

merge_config_plus-$(MCP_VERSION): merge_config_plus-$(MCP_VERSION).tar.gz
	tar -m -xvf $<

merge_config_plus: merge_config_plus-$(MCP_VERSION)
	ln -s $< $@

.PHONY: clean
clean:
	rm -rf *.tar.gz
	rm -rf buildroot*
	rm -rf merge_config_plus*
