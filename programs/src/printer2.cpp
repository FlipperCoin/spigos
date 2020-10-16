#include <stdlib.h>

int main() {
    while (true) {
        write((void*)"Hello Again!\n\0",13);
        sleep(1000);
    }
}