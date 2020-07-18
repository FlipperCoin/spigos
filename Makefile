OUT ?= out
boot_img = boot/out/bin/boot_sect.bin kernel/out/bin/kernel.bin out/bin/filler.bin
foreign_targets := boot/out/bin/boot_sect.bin kernel/out/bin/kernel.bin
foreign_targets_dirs := $(basename $(foreign_targets))
get_root_dir = $(firstword $(subst /, ,$(dir)))
submakes := $(foreach dir,$(foreign_targets_dirs),$(get_root_dir))

.PHONY: build clean $(submakes)

build: $(OUT)/spigos_img

clean:
	for submake in $(submakes); do $(MAKE) -C $$submake clean; done;
	if [ -d $(OUT) ]; then rm -r $(OUT); fi

$(OUT):
	mkdir -p $@/bin

$(OUT)/spigos_img: $(boot_img) | $(OUT)
	cat $^ > $@

$(OUT)/bin/filler.bin: boot/out/bin/boot_sect.bin kernel/out/bin/kernel.bin | $(OUT)
	./filler.sh $@

$(foreign_targets): $(submakes)
	
$(submakes):
	$(MAKE) -C $@
