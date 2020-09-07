.PHONY: build clean out 

build: out/bin/bootable.img | out

clean:
	rm -rf out

out:
	mkdir -p $@/obj
	mkdir -p $@/bin

out/bin/bootable.img: out/bin/boot_sect.bin out/bin/bootloader.bin out/bin/bootloader_filler.bin $(KERNEL_BIN) out/bin/kernel_filler.bin | out
	cat $^ > $@

out/bin/boot_sect.bin: src/*.asm | out
	nasm src/boot_sect.asm -i src -f bin -o $@

out/bin/bootloader_filler.bin: filler.sh out/bin/bootloader.bin | out
	./filler.sh $@ $(shell echo $$((512*54))) out/bin/bootloader.bin

out/bin/kernel_filler.bin: filler.sh $(KERNEL_BIN) | out kernelbin
	./filler.sh $@ $(PADDED_KERNEL_SIZE) $(KERNEL_BIN)

out/bin/bootloader.bin: out/obj/bootloader_entry.o out/obj/bootloader.o out/obj/ataRead.o out/obj/print.o | out
	ld -m elf_i386 -o out/bin/bootloader.elf -Ttext 0x1000 out/obj/bootloader_entry.o $^
	ld -m elf_i386 -o $@ out/bin/bootloader.elf -Ttext 0x1000 --oformat binary

out/obj/bootloader.o: src/bootloader.cpp | out kernelbin
	g++ -o $@ -m32 -ffreestanding -c -fno-pie -fno-exceptions -DKERNEL_SIZE=$(PADDED_KERNEL_SIZE) $^

out/obj/%.o: src/%.cpp | out
	g++ -o $@ -m32 -ffreestanding -c -fno-pie -fno-exceptions $<

out/obj/%.o: src/%.asm | out
	nasm $< -f elf -o $@

# the reason I don't want a kernel that is larger than 0xEF0000 is that I don't wanna 	\
		fuck with addresses like mem mapped IO or something because I'm too lazy to check 	\
		what's in larger than 0x00F00000 addr range (0x10000 kernel start addr + 0xEF0000).	\
		should be able to do the check with memory detection BIOS routine
kernelbin: 
	if [ -z "$(KERNEL_BIN)" ]; then echo "KERNEL_BIN is not set"; exit 1; fi

	if [ ! -f $(KERNEL_BIN) ]; then echo "file '$(KERNEL_BIN)' does not exist"; exit 1; fi
	
	$(eval KERNEL_SIZE := $(shell stat -c %s $(KERNEL_BIN)))
	$(eval PADDED_KERNEL_SIZE := $(shell echo $$(($(KERNEL_SIZE)+(512-$(KERNEL_SIZE)%512)%512))))
	$(eval MAX_KERNEL_SIZE := $(shell echo $$((0xEF0000))))

	if [ "$(PADDED_KERNEL_SIZE)" -gt "$(MAX_KERNEL_SIZE)" ]; then echo "padded kernel size ($(PADDED_KERNEL_SIZE)) exceeded max size ($(MAX_KERNEL_SIZE))"; exit 1; fi
