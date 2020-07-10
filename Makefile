OUT ?= out
boot_img = boot/out/boot_sect.bin kernel/out/kernel.bin
foreign_targets := $(boot_img)
foreign_targets_dirs := $(basename $(foreign_targets))
get_root_dir = $(firstword $(subst /, ,$(dir)))
submakes := $(foreach dir,$(foreign_targets_dirs),$(get_root_dir))

.PHONY: build clean $(submakes)

build: $(OUT)/spigos_img

clean:
	for submake in $(submakes); do $(MAKE) -C $$submake clean; done;
	if [ -d $(OUT) ]; then rm -r $(OUT); fi

$(OUT):
	mkdir -p $@

$(OUT)/spigos_img: $(boot_img) | $(OUT)
	cat $^ > $@

$(foreign_targets): $(submakes)
	
$(submakes):
	$(MAKE) -C $@
