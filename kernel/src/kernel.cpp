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
        sleep(2000);
        
        lockScheduler();
        schedule();
        unlockScheduler();
    }
}

void testTask2() {
    uint_32 n = 0;
    while (true) {
        println("Kernel test task 2");
        sleep(1000);
        
        lockScheduler();
        schedule();
        unlockScheduler();
    }
}

void testTask3() {
    uint_32 n = 0;
    while (true) {
        println("Kernel test task 3");
        sleep(500);
        
        lockScheduler();
        schedule();
        unlockScheduler();
    }
}

void idleTask() {
    while (true) { 
        // TODO: remove once scheduler works on timer ===
        lockScheduler();
        schedule();
        unlockScheduler();
        // ===
    }
}

extern "C" int KernelMain() {
    clearScreen();
    
    println("==== SpigOS ====\n");

    println("Initializing PIC & IDT...");

    initPIC();
    initKeyboardDriver();
    initTimer();
    loadIDT();

    println("Initializing tasks...");
    initializeMultitasking(); 

    println("Done.");
    println();

    // === 

    createKernelTask(idleTask, "idle");
    // createKernelTask(testTask1, "task_1");
    createKernelTask(testTask2, "task_2");
    // createKernelTask(testTask3, "task_3");

    while (true) {
        println("Kernel main task");

        sleep(250);

        lockScheduler();
        schedule();
        unlockScheduler();
    }

    // ===

    return 0;
}