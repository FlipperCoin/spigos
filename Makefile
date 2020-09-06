OUT ?= out
boot_img = bootloader/out/bin/bootable.img
foreign_targets := kernel/out/bin/kernel.bin
foreign_targets_dirs := $(basename $(foreign_targets))
get_root_dir = $(firstword $(subst /, ,$(dir)))
submakes := $(foreach dir,$(foreign_targets_dirs),$(get_root_dir))

.PHONY: build clean $(submakes)

build: $(OUT)/spigos_img

clean:
	for submake in $(submakes); do $(MAKE) -C $$submake clean; done;
	$(MAKE) -C bootloader clean
	if [ -d $(OUT) ]; then rm -r $(OUT); fi

$(OUT):
	mkdir -p $@/bin

$(OUT)/spigos_img: $(boot_img) | $(OUT)
	cat $^ > $@

bootloader/out/bin/bootable.img: kernel/out/bin/kernel.bin
	$(MAKE) -C $(firstword $(subst /, ,$@)) KERNEL_BIN=../kernel/out/bin/kernel.bin

$(foreign_targets): $(submakes)
	
$(submakes):
	$(MAKE) -C $@
