BUILDROOT_VERSION=2021.02.3
#BUILDROOT_VERSION=2021.05
DOXYGEN_VERSION=1.9.1
DOXYGEN_AWESOME_CSS_VERSION=1.4.0
ESH_VERSION=0.3.1

all: buildroot doxygen doxygen-awesome-css esh

buildroot-$(BUILDROOT_VERSION).tar.gz:
	wget https://buildroot.org/downloads/buildroot-$(BUILDROOT_VERSION).tar.gz

buildroot-$(BUILDROOT_VERSION): buildroot-$(BUILDROOT_VERSION).tar.gz
	tar -m -xvf $<

buildroot: buildroot-$(BUILDROOT_VERSION)
	ln -s $< $@

doxygen-$(DOXYGEN_VERSION).src.tar.gz:
	wget https://doxygen.nl/files/doxygen-$(DOXYGEN_VERSION).src.tar.gz

doxygen-$(DOXYGEN_VERSION): doxygen-$(DOXYGEN_VERSION).src.tar.gz
	tar -m -xvf $<

doxygen: doxygen-$(DOXYGEN_VERSION)
	cd $<; \
		rm -rf build; \
		mkdir build; \
		cd build; \
			cmake ..; \
			make;
	ln -s $< $@

doxygen-awesome-css-$(DOXYGEN_AWESOME_CSS_VERSION).tar.gz:
	wget https://github.com/jothepro/doxygen-awesome-css/archive/refs/tags/v$(DOXYGEN_AWESOME_CSS_VERSION).tar.gz -O $@
	
doxygen-awesome-css-$(DOXYGEN_AWESOME_CSS_VERSION): doxygen-awesome-css-$(DOXYGEN_AWESOME_CSS_VERSION).tar.gz
	tar -m -xvf $<

doxygen-awesome-css: doxygen-awesome-css-$(DOXYGEN_AWESOME_CSS_VERSION)
	ln -s $< $@

.PHONY: clean
clean:
	rm -rf *.tar.gz
	rm -rf buildroot*
	rm -rf esh*
	rm -rf doxygen*
