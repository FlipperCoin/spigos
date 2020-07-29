#include <screen.h>
#include <keyboard.h>
#include <idt.h>
#include <pic.h>
#include <pit.h>
#include <interrupt.h>
#include <tasks.h>

extern "C" int KernelMain() {
    clearScreen();
    
    println("==== SpigOS ====\n");

    println("Initializing PIC & IDT...");

    initPIC();
    
    initializeMultitasking(); 
    
    initKeyboardDriver();
    initTimer();
    loadIDT();

    println("Initializing tasks...");

    println("Done.");
    println();

    // === 

    while (true) {
        uint_8 c = readChar();

        print(c);
    }

    // ===

    return 0;
}