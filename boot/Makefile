.PHONY: build clean

build: out/bin/boot_sect.bin

clean:
	if [ -d out ]; then rm -r out; fi

out:
	mkdir -p $@/bin

out/bin/boot_sect.bin: *.asm | out
	nasm boot_sect.asm -f bin -o $@