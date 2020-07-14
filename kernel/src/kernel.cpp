#include <screen.h>
#include <keyboard.h>
#include <idt.h>
#include <pic.h>

extern "C" int KernelMain() {
    clearScreen();
    
    println("==== SpigOS ====\n");

    println("Initializing PIC & IDT...");

    initPIC();
    initKeyboardDriver();
    loadIDT();

    println("Done.");

    return 0;
}