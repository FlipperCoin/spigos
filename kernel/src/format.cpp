#include <format.h>

int itoa(unsigned int num, char *buf, size_t maxSize) {
    return itos(num, 10, buf, maxSize);
}

int itoh(unsigned int num, char *buf, size_t maxSize) {
    buf[0] = '0';
    buf[1] = 'x';
    return itos(num, 16, buf + 2, maxSize - 2);
}

int itos(unsigned int num, unsigned int base, char *buf, size_t maxSize) {
    if (base > MAX_BASE) return -1;
    
    int countOfChars = 1;
    unsigned int tmp = num;
    
    while ((tmp /= base) != 0) countOfChars++;

    // +1 for null terminator
    if (maxSize < countOfChars + 1) return -1;

    buf[countOfChars] = '\0';

    for (int i = countOfChars - 1; i >= 0; i--) {
        unsigned char c = (num % base);
        if (c < 10)
            c = '0' + c;
        else { // English alphabet
            c = 55 + c;
        }
        buf[i] = c;
        num /= base;
    }

    return countOfChars;
}