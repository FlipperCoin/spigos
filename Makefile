OUT ?= out

.PHONY: build clean

build: $(OUT)/spigos_img

clean:
	$(MAKE) -C boot clean
	$(MAKE) -C kernel clean
	if [ -d $(OUT) ]; then rm -r $(OUT); fi

$(OUT):
	mkdir -p $@

$(OUT)/spigos_img: boot/out/boot_sect.bin kernel/out/kernel.bin | $(OUT)
	cat $^ > $@

boot/out/boot_sect.bin:
	$(MAKE) -C boot

kernel/out/kernel.bin: 
	$(MAKE) -C kernel

