if [ $# != 3 ]; then
    echo "Usage: $0 [OUTPUT_FILE] [DESIRED_SIZE] [FILE]"
    exit 1
fi

SIZE=$2

if [ ! -f $3 ]; then
    echo "file $3 does not exist"
    exit 1
fi

FILE_SIZE=$(stat -c %s $3)
FILLED_SIZE=$(($SIZE-$FILE_SIZE))

if [ $FILLED_SIZE -lt 0 ]; then
    echo "$3 larger than $SIZE, size: $FILE_SIZE"
    exit 1
fi

truncate -s $FILLED_SIZE $1