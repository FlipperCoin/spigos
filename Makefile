OUT_DIR ?= out

$(OUT_DIR)/boot_sect.bin: boot_sect.asm pm/*
	sh -c "if [ ! -d 'out' ]; then mkdir out; fi"
	nasm boot_sect.asm -i pm/ -i pm/io/ -f bin -o $(OUT_DIR)/boot_sect.bin