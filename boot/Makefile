OUT = out

.PHONY: build clean

build: $(OUT)/boot_sect.bin

clean:
	if [ -d $(OUT) ]; then rm -r $(OUT); fi

$(OUT):
	mkdir -p $@

$(OUT)/boot_sect.bin: *.asm | $(OUT)
	nasm boot_sect.asm -f bin -o $@