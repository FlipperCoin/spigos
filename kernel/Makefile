OUT = out
objects =  $(addprefix $(OUT)/obj/, $(addsuffix .o, kernel_entry kernel))

.PHONY: build clean

build: $(OUT)/kernel.bin

clean:
	if [ -d $(OUT) ]; then rm -r $(OUT); fi

$(OUT):
	mkdir -p $@/obj/

$(OUT)/kernel.bin: $(objects)
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

$(OUT)/obj/kernel_entry.o: kernel_entry.asm | $(OUT)
	nasm $< -f elf -o $@

$(OUT)/obj/kernel.o: kernel.cpp | $(OUT)
	g++ -o $@ -m32 -ffreestanding -c -fno-pie $<