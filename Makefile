OUT_DIR ?= out

$(OUT_DIR)/boot_sect.bin:
	nasm boot_sect.asm -f bin -o $(OUT_DIR)/boot_sect.bin