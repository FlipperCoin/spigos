OUT_DIR ?= out

$(OUT_DIR)/boot_sect.bin: boot_sect.asm io.asm
	sh -c "[ ! -d 'out' ] && mkdir out"
	nasm boot_sect.asm -f bin -o $(OUT_DIR)/boot_sect.bin