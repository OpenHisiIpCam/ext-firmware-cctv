DOXYGEN_VERSION=1.9.1
DOXYGEN_AWESOME_CSS_VERSION=1.4.0

all: doxygen doxygen-awesome-css 

doxygen-$(DOXYGEN_VERSION).src.tar.gz:
	wget https://doxygen.nl/files/doxygen-$(DOXYGEN_VERSION).src.tar.gz

doxygen-$(DOXYGEN_VERSION): doxygen-$(DOXYGEN_VERSION).src.tar.gz
	tar -xvf $<

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
	tar -xvf $<

# TODO target triggers regardless of doxygen-awesome-css-$(DOXYGEN_AWESOME_CSS_VERSION) existence
doxygen-awesome-css: doxygen-awesome-css-$(DOXYGEN_AWESOME_CSS_VERSION)
	ln -s $< $@
