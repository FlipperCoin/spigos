OUT ?= out

.PHONY: build clean

build: $(OUT)/spigos_img

clean:
	rm -r $(OUT)

$(OUT):
	mkdir -p $@/obj

$(OUT)/spigos_img: $(OUT)/boot_sect.bin $(OUT)/kernel.bin
	cat $^ > $@

$(OUT)/boot_sect.bin: boot/boot_sect.asm boot/*.asm | $(OUT)
	cd boot && nasm boot_sect.asm -f bin -o ../$@

$(OUT)/kernel.bin: $(OUT)/obj/kenrel_entry.o $(OUT)/obj/kernel.o 
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

$(OUT)/obj/kenrel_entry.o: kernel/kernel_entry.asm | $(OUT)
	nasm $< -f elf -o $@

$(OUT)/obj/kernel.o: kernel/kernel.cpp | $(OUT)
	g++ -o $@ -m32 -ffreestanding -c -fno-pie $<
