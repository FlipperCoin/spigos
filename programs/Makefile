includes = include
headers := $(foreach dir,$(include),$(wildcard $(dir)/*.h))
cpp_sources := $(wildcard src/*.cpp)
cpp_sources := $(filter-out src/stdlib.cpp, $(cpp_sources))
bins := $(patsubst src/%.cpp,out/bin/%.bin,$(cpp_sources))

.PHONY: build clean out

build: out/bin/programs.bin

clean: 
	rm -rf out

out:
	mkdir -p $@/obj/
	mkdir -p $@/bin/

out/bin/programs.bin: $(bins)
	cat $^ > out/bin/programs.bin

out/bin/%.bin: out/bin/%.elf
	ld -N -m elf_i386 -o $@.tmp --oformat binary $<
	python -c "import struct; import sys; sys.stdout.write(struct.pack('<I',$$(stat -c "%s" $@.tmp)).decode()); sys.stdout.flush()" > $@
	cat $@.tmp >> $@
	rm $@.tmp

out/bin/%.elf: out/obj/%.o out/obj/entry.o out/obj/stdlib.o
	ld -N -m elf_i386 -o $@ -Ttext 0x4000 out/obj/entry.o $< out/obj/stdlib.o

out/obj/%.o: src/%.cpp $(headers) | out
	g++ -g -o $@ -m32 -ffreestanding -c -fno-pie -fno-exceptions $(addprefix -I ,$(includes)) $<

out/obj/%.o: src/%.asm | out
	nasm $< -g -f elf -o $@