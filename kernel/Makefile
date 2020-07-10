objects =  $(addprefix out/obj/, $(addsuffix .o, kernel_entry kernel))

.PHONY: build clean

build: out/kernel.bin

clean:
	if [ -d out ]; then rm -r out; fi

out:
	mkdir -p $@/obj/

out/kernel.bin: $(objects)
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ --oformat binary

out/obj/kernel_entry.o: kernel_entry.asm | out
	nasm $< -f elf -o $@

out/obj/kernel.o: kernel.cpp | out
	g++ -o $@ -m32 -ffreestanding -c -fno-pie $<