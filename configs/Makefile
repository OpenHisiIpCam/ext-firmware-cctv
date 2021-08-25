MERGE_TOOL = $(abspath ../vendors/merge_config_plus/merge_config_plus.sh)

# Collect all ../board/*/*/*.br.config (excluding ../board/common/...) config entry points
BOARDS = 	$(patsubst %.br.config,%_defconfig, \
	  		$(subst /,_, \
				$(patsubst ../board/%,%, \
					$(patsubst ../board/common/%,, \
						$(wildcard ../board/*/*/*.br.config) \
					)\
				) \
			) \
		)

.SECONDEXPANSION: %_defconfig

all: $(MERGE_TOOL) $(BOARDS)

$(MERGE_TOOL): ../vendors/merge_config_plus

../vendors/merge_config_plus:
	make -C ../vendors merge_config_plus

%_defconfig: $$(shell $(MERGE_TOOL) -b $(abspath .) --mode dependencies -f ../board/$$(subst _,/,%).br.config)
	@$(MERGE_TOOL) \
		-b $(abspath .) \
		-o $@ \
		--strip-history \
		-f ../board/$(subst /defconfig,.br.config,$(subst _,/,$@))

.PHONY: clean
clean:
	rm -f *_defconfig
