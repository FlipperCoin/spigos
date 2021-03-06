cpp_sources := $(wildcard src/*.cpp)
cpp_genregs_sources := $(wildcard src/general-regs/*.cpp)
asm_sources := $(wildcard src/*.asm)
user_programs_asm:= $(wildcard src/user-programs/*.asm)
includes = ../drivers/include include
headers := $(foreach dir,$(include),$(wildcard $(dir)/*.h))
objects := $(patsubst src/%.cpp,out/obj/%.o,$(cpp_sources)) $(patsubst src/%.asm,out/obj/%.o,$(asm_sources)) $(patsubst src/general-regs/%.cpp,out/obj/%.o,$(cpp_genregs_sources)) $(patsubst src/user-programs/%.asm,out/obj/%.o,$(user_programs_asm))
foreign = ../drivers

.PHONY: build clean out $(foreign)

build: out/bin/kernel.bin

clean: 
	for submake in $(foreign); do $(MAKE) -C $$submake clean; done;
	rm -rf out

out:
	mkdir -p $@/obj/
	mkdir -p $@/bin/

out/bin/kernel.bin: $(objects)
	ld -N -m elf_i386 -o out/bin/kernel.elf -Ttext 0x100000 out/obj/kernel_entry.o $^ ../drivers/out/obj/*.o
	ld -N -m elf_i386 -o $@ out/bin/kernel.elf --oformat binary

out/obj/%.o: src/%.cpp $(headers) ../drivers | out
	g++ -g -o $@ -m32 -ffreestanding -c -fno-pie -fno-exceptions $(addprefix -I ,$(includes)) $<

out/obj/%.o: src/%.asm | out
	nasm $< -g -f elf -o $@

out/obj/%.o: src/general-regs/%.cpp $(headers) | out
	g++ -g -o $@ -m32 -ffreestanding -c -fno-pie -mgeneral-regs-only -fno-exceptions $(addprefix -I ,$(includes)) $<

out/obj/%.o: src/user-programs/%.asm | out
	nasm $< -g -f elf -o $@
	objcopy --remove-relocations=.TEXT $@ $@

$(foreign):
	$(MAKE) -C $@