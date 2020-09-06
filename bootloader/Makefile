ifndef KERNEL_BIN
$(error KERNEL_BIN is not set)
endif

ifeq (,$(wildcard $(KERNEL_BIN)))
$(error file "$(KERNEL_BIN)" does not exist)
endif

KERNEL_SIZE := $(shell stat -c %s $(KERNEL_BIN))
PADDED_KERNEL_SIZE := $(shell echo $$(($(KERNEL_SIZE)+(512-$(KERNEL_SIZE)%512)%512)))

.PHONY: build clean out 

build: out/bin/bootable.img

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

out/bin/kernel_filler.bin: filler.sh $(KERNEL_BIN) | out
	./filler.sh $@ $(PADDED_KERNEL_SIZE) $(KERNEL_BIN)

out/bin/bootloader.bin: out/obj/bootloader_entry.o out/obj/bootloader.o out/obj/ataRead.o | out
	ld -m elf_i386 -o out/bin/bootloader.elf -Ttext 0x1000 out/obj/bootloader_entry.o $^
	ld -m elf_i386 -o $@ out/bin/bootloader.elf -Ttext 0x1000 --oformat binary

out/obj/bootloader.o: src/bootloader.cpp | out
	g++ -o $@ -m32 -ffreestanding -c -fno-pie -fno-exceptions -DKERNEL_SIZE=$(PADDED_KERNEL_SIZE) $<

out/obj/%.o: src/%.cpp | out
	g++ -o $@ -m32 -ffreestanding -c -fno-pie -fno-exceptions $<

out/obj/%.o: src/%.asm | out
	nasm $< -f elf -o $@