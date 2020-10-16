#include <types.h>

typedef struct File {
    size_t Size;
    void *Data;
} File;

File *getFile(size_t idx);
void loadFiles();