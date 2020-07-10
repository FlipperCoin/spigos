DEFAULT_OUT_DIR="out"
DEFAULT_WIN_OUT_DIR="/mnt/d/${PWD##*/}/out"

if [ -z $OUT_DIR ]
then
    echo "Using default out dir '$DEFAULT_OUT_DIR'"
    OUT_DIR=$DEFAULT_OUT_DIR
fi

if [ -z $WIN_OUT_DIR ]
then
    echo "Using default win out dir '$DEFAULT_WIN_OUT_DIR'"
    WIN_OUT_DIR=$DEFAULT_WIN_OUT_DIR
fi

cp -r $OUT_DIR/* $WIN_OUT_DIR

cpErrorCode=$?

if [ $cpErrorCode -eq 0 ]; then
    echo "Finished sync succesfully"
else
    echo "Sync failed with error code $cpErrorCode"
    exit 1
fi

exit 0