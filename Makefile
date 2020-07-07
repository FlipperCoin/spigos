OUTDIR ?= out

build: $(OUTDIR)/kernel.bin $(OUTDIR)/boot_sect.bin
	cat $(OUTDIR)/boot_sect.bin $(OUTDIR)/kernel.bin > $(OUTDIR)/spigos_img

$(OUTDIR):
	mkdir -p $@

$(OUTDIR)/kernel.bin: kernel/* | $(OUTDIR)
	g++ -o kernel.o -m32 -ffreestanding -c -fno-pie kernel/kernel.cpp
	nasm kernel/kernel_entry.asm -f elf -o kernel_entry.o
	ld -m elf_i386 -o $(OUTDIR)/kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary

$(OUTDIR)/boot_sect.bin: boot/boot_sect.asm $(shell find boot/rm boot/pm -type f) | $(OUTDIR)
	cd boot && nasm boot_sect.asm -f bin -o ../$(OUTDIR)/boot_sect.bin

.PHONY: build clean
clean:
	rm -r $(OUTDIR)