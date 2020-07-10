OUT ?= out
boot_img = boot/out/boot_sect.bin kernel/out/kernel.bin
submakes = $(boot_img)

.PHONY: build clean $(submakes)

build: $(OUT)/spigos_img

clean:
	$(MAKE) -C boot clean
	$(MAKE) -C kernel clean
	if [ -d $(OUT) ]; then rm -r $(OUT); fi

$(OUT):
	mkdir -p $@

$(OUT)/spigos_img: $(boot_img) | $(OUT)
	cat $^ > $@

$(submakes):
	$(MAKE) -C $(firstword $(subst /, ,$@))
