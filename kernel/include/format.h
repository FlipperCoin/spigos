#include <types.h>

#define MAX_BASE 36

int itoa(unsigned int num, char *buf, size_t maxSize);
int itoh(unsigned int num, char *buf, size_t maxSize);
int itos(unsigned int num, unsigned int base, char *buf, size_t maxSize);