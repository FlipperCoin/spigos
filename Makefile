OUT_DIR ?= out

$(OUT_DIR)/boot_sect.bin: boot_sect.asm
	nasm boot_sect.asm -f bin -o $(OUT_DIR)/boot_sect.bin