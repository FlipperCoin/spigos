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
#include <gdt.h>
#include <userspace.h>

extern "C" int KernelMain() {
    clearScreen();
    
    println("==== SpigOS ====\n");

    initGdt();

    println("Enabling Virtual Memory...");
    initPhysMemManagement();
    enableVirtualMemory();
    dynmemInit();

    println("Initializing PIC...");
    initPIC();
    
    println("Initializing Multitasking...");
    initializeMultitasking();

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

    println("Initializing User Space...");
    initUserspace();

    createUserTask();

    println();
    println("Done.");
    println();

    // === 
    
    shell();

    // ===

    return 0;
}