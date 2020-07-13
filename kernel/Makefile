sources := $(wildcard src/*.cpp)
includes = ../drivers/include include
headers := $(foreach dir,$(include),$(wildcard $(dir)/*.h))
objects := $(patsubst src/%.cpp,out/obj/%.o,$(sources)) 
foreign = ../drivers

.PHONY: build clean out $(foreign)

build: out/bin/kernel.bin

clean: 
	for submake in $(foreign); do $(MAKE) -C $$submake clean; done;
	rm -rf out

out:
	mkdir -p $@/obj/
	mkdir -p $@/bin/

out/bin/kernel.bin: out/obj/kernel_entry.o $(objects)
	ld -m elf_i386 -o $@ -Ttext 0x1000 $^ ../drivers/out/obj/*.o --oformat binary

out/obj/%.o: src/%.cpp $(headers) ../drivers | out
	g++ -o $@ -m32 -ffreestanding -c -fno-pie $(addprefix -I ,$(includes)) $<

out/obj/%.o: src/%.asm | out
	nasm $< -f elf -o $@

$(foreign):
	$(MAKE) -C $@