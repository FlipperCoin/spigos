SIZE=$((512*55))

if [ $# != 1 ]; then
    echo "Usage: $0 [OUTPUT_FILE]"
    exit 1
fi

BOOT_SECT_SIZE=$(ls -l boot/out/bin/boot_sect.bin | awk '{ print $5 }')
KERNEL_SIZE=$(ls -l kernel/out/bin/kernel.bin | awk '{ print $5 }')
IMAGE_SIZE=$(($BOOT_SECT_SIZE+$KERNEL_SIZE))
FILLED_SIZE=$(($SIZE-$IMAGE_SIZE))

if [ $FILLED_SIZE -lt 0 ]; then
    echo "Boot sector and kernel are larger than $SIZE, size: $IMAGE_SIZE"
    exit 1
fi

truncate -s $FILLED_SIZE $1