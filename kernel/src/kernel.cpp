#include <screen.h>
#include <keyboard.h>
#include <ata.h>
#include <idt.h>
#include <pic.h>
#include <pit.h>
#include <interrupt.h>
#include <tasks.h>
#include <memory.h>
#include <shell.h>

extern "C" int KernelMain() {
    clearScreen();
    
    println("==== SpigOS ====\n");

    println("Initializing PIC & IDT...");

    initPIC();
    
    initializeMultitasking(); 
    
    initKeyboardDriver();
    initAta();
    initTimer();
    loadIDT();

    println("Initializing tasks...");

    println("Done.");
    println();

    uint_8 sector[512];
    read(0, 1, sector);
    printNum(sector[510]);
    println();
    printNum(sector[511]);
    println();
    println();

    // === 

    shell();

    // ===

    return 0;
}