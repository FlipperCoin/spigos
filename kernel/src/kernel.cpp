#include <screen.h>
#include <idt.h>

// void keyboardInterrupt() {
//     return;
// }

extern "C" int KernelMain() {
    clearScreen();
    
    println("Hello Kernel!");

    // registerInterrupt(9, (void*)keyboardInterrupt, 0x0E, 0);
    loadIDT();

    println("Hello Again!");

    return 0;
}