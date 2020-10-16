OUT ?= out
boot_img = bootloader/out/bin/bootable.img
programs_bin = programs/out/bin/programs.bin
kernel_bin = kernel/out/bin/kernel.bin 
foreign_targets := $(kernel_bin) $(programs_bin)
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

$(OUT)/spigos_img: $(boot_img) out/bin/filler.bin $(programs_bin) | $(OUT)
	cat $^ > $@

$(OUT)/bin/filler.bin: $(boot_img)
	./filler.sh $@ 512000 $(boot_img)

bootloader/out/bin/bootable.img: $(kernel_bin)
	$(MAKE) -C $(firstword $(subst /, ,$@)) KERNEL_BIN=../$(kernel_bin)

$(foreign_targets): $(submakes)
	
$(submakes):
	$(MAKE) -C $@
