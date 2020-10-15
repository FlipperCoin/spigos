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

// temporary test
void enterUserspace() {
   asm volatile("  \
     cli; \
     mov $0x23, %ax; \
     mov %ax, %ds; \
     mov %ax, %es; \
     mov %ax, %fs; \
     mov %ax, %gs; \
                   \
     mov %esp, %eax; \
     pushl $0x23; \
     pushl %eax; \
     pushf; \
     popl %eax; \
     or $0x200, %eax; \
     pushl %eax; \
     pushl $0x1B; \
     push $1f; \
     iret; \
   1: \
     mov $1, %eax; \
     mov $2, %ebx; \
     mov $3, %ecx; \
     mov $4, %edx; \
     int $0x80; \
     ");
     
    print("Hello, User Space!");
    while (true)
    {
      
    }
      
}

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