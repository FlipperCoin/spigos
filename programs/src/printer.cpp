#include <stdlib.h>

int main() {
    while (true) {
        write((void*)"Hello World!\n\0",13);
        sleep(500);
    }
}