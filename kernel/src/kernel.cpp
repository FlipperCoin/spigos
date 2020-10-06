#include <screen.h>
#include <keyboard.h>
#include <ata.h>
#include <idt.h>
#include <pic.h>
#include <pit.h>
#include <interrupt.h>
#include <tasks.h>
#include <memory.h>
#include <physmem.h>
#include <virtmem.h>
#include <shell.h>
#include <exceptions.h>
#include <dynmem.h>

extern "C" int KernelMain() {
    clearScreen();
    
    println("==== SpigOS ====\n");

    println("Enabling Virtual Memory...");
    initPhysMemManagement();
    enableVirtualMemory();

    println("Initializing PIC...");
    initPIC();
    
    println("Initializing Drivers...");
    initKeyboardDriver();
    initAta();
    initTimer();

    println("Registering Exception Handlers...");
    registerExceptions();
    
    println("Loading IDT...");
    loadIDT();

    println("Enabling Hardware IRQs...");
    enableHardwareInterrupts();

    println("Initializing Multitasking...");
    initializeMultitasking();

    println();
    println("Done.");
    println();

    // === 

    shell();

    // ===

    return 0;
}