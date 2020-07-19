if [ $# != 1 ]; then
    echo "Usage: $0 [OUTPUT_FILE]"
    exit 1
fi
BOOT_SECT_SIZE=$(ls -l boot/out/bin/boot_sect.bin | awk '{ print $5 }')
KERNEL_SIZE=$(ls -l kernel/out/bin/kernel.bin | awk '{ print $5 }')
truncate -s $((512*51-($BOOT_SECT_SIZE+$KERNEL_SIZE))) $1