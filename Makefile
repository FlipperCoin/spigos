OUTDIR ?= out

build: $(OUTDIR)/kernel.bin $(OUTDIR)/boot_sect.bin

$(OUTDIR):
	mkdir -p $@

$(OUTDIR)/kernel.bin: kernel/* | $(OUTDIR)

$(OUTDIR)/boot_sect.bin: boot/boot_sect.asm $(shell find boot/rm boot/pm -type f) | $(OUTDIR)
	nasm boot/boot_sect.asm -i boot/rm -i boot/rm/io/ -i boot/pm/ -f bin -o $(OUTDIR)/boot_sect.bin

.PHONY: build clean
clean:
	rm -r $(OUTDIR)