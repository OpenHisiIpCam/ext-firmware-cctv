MERGE_TOOL = $(abspath ../tools/merge_config_plus/merge_config_plus.sh)

BOARDS = 	$(patsubst %.br.config,%_defconfig, \
	  		$(subst /,_, \
				$(patsubst ../board/%,%, \
					$(wildcard ../board/*/*/*.br.config) \
				) \
			) \
		)

.SECONDEXPANSION: %_defconfig

all: $(TOOLCHAINS) $(BOARDS)

%_defconfig: $(MERGE_TOOL) $$(shell $(MERGE_TOOL) -b $(abspath .) --mode dependencies -f ../board/$$(subst _,/,%).br.config)
	@$(MERGE_TOOL) \
		-b $(abspath .) \
		-o $@ \
		--strip-history \
		-f ../board/$(subst /defconfig,.br.config,$(subst _,/,$@))

.PHONY: clean
clean:
	rm -f *_defconfig
