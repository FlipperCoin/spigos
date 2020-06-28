OUT_DIR ?= out

$(OUT_DIR)/boot_sect.bin: boot_sect.asm io.asm
	sh -c "if [ ! -d 'out' ]; then mkdir out; fi"
	nasm boot_sect.asm -f bin -o $(OUT_DIR)/boot_sect.bin