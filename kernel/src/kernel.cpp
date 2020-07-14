#include <screen.h>
#include <keyboard.h>
#include <idt.h>
#include <pic.h>



extern "C" int KernelMain() {
    clearScreen();
    
    println("Hello Kernel!");

    initPIC();
    initKeyboardDriver();
    loadIDT();

    println("Hello Again!");

    return 0;
}