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

extern "C" int KernelMain() {
    clearScreen();
    
    println("==== SpigOS ====\n");

    initPhysMemManagement();

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

    println("Enabling Virtual Memory...");
    enableVirtualMemory();

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