#include <screen.h>
#include <format.h>
 
extern "C" int KernelMain() {
    clearScreen();
    
    println("Hello Kernel!");

    return 0;
}