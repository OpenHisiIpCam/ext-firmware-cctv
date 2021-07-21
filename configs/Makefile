MERGE_TOOL = $(abspath ../tools/merge_config_plus/merge_config_plus.py)

BOARDS = 	$(patsubst %.br.config,%_defconfig, \
	  		$(subst /,_, \
				$(patsubst ../board/%,%, \
					$(wildcard ../board/*/*/*.br.config) \
				) \
			) \
		)

TOOLCHAINS =	$(patsubst %.br.config,%_defconfig, \
                        $(subst /,_, \
                                        $(wildcard toolchain/*.br.config) \
                        ) \
                )

GENERICS =	$(patsubst %.br.config,%_defconfig, \
                        $(subst br/,generic_, \
                                        $(wildcard br/*.br.config) \
                        ) \
                )

.NOTPARALLEL: all
all: clean $(TOOLCHAINS) $(GENERICS) $(BOARDS)

%_defconfig:
	$(MERGE_TOOL) \
		-r $(abspath ..) \
		--strip-strings \
		-o $@ \
		../board/$(subst /defconfig,.br.config,$(subst _,/,$@))

toolchain_%_defconfig:
	$(MERGE_TOOL) \
                -r $(abspath ..) \
                --strip-strings \
                -o $@ \
                ./$(subst /defconfig,.br.config,$(subst _,/,$@))

generic_%_defconfig:
	$(MERGE_TOOL) \
                -r $(abspath ..) \
                --strip-strings \
                -o $@ \
                ./$(subst _defconfig,.br.config,$(subst generic_,br/,$@))

.PHONY: clean
clean:
	rm -f *_defconfig
