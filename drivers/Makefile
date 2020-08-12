sources := $(wildcard src/*.cpp)
includes = ../kernel/include include
headers := $(foreach dir,$(includes),$(wildcard $(dir)/*.h))
objects := $(patsubst src/%.cpp,out/obj/%.o,$(sources))

.PHONY: build clean out

build: $(objects)

clean: 
	rm -rf out

out:
	mkdir -p $@/obj/

out/obj/%.o: src/%.cpp $(headers) | out
	g++ -o $@ -m32 -ffreestanding -c -fno-pie $(addprefix -I ,$(includes)) $<