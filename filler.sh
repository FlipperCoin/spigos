if [ $# != 1 ]; then
    echo "Usage: $0 [OUTPUT_FILE]"
    exit 1
fi

truncate -s $(calc 512*51-$(calc $(ls -l kernel/out/bin/kernel.bin | awk '{ print $5 }')+$(ls -l boot/out/bin/boot_sect.bin | awk '{ print $5 }'))) $1