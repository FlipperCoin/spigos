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

    uint_32 *thankgod = (uint_32*)kmalloc(5 * sizeof(uint_32));
    thankgod[0] = 1;
    thankgod[3] = 4;
    thankgod[4] = 5;
    print("allocated thankgod at: ");
    printHex((uint_32)thankgod);
    println();
    print("thankgod at 0 is: ");
    printNum(thankgod[0]);
    println();
    print("thankgod at 2 is: ");
    printNum(thankgod[2]);
    println();
    print("thankgod at 3 is: ");
    printNum(thankgod[3]);
    println();
    print("thankgod at 4 is: ");
    printNum(thankgod[4]);
    println();

    // === 

    shell();

    // ===

    return 0;
}