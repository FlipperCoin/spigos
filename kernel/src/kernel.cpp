#include <screen.h>
#include <keyboard.h>
#include <idt.h>
#include <pic.h>
#include <pit.h>
#include <interrupt.h>
#include <tasks.h>

void testTask1() {
    uint_32 n = 0;
    while (true) {
        println("Kernel test task 1");
        sleep(1000);
    }
}

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

    createKernelTask(testTask1, "task_1");

    while (true) {
        println("Kernel main task");

        sleep(250);
    }

    // ===

    return 0;
}