#include <screen.h>
#include <keyboard.h>
#include <idt.h>
#include <pic.h>
#include <pit.h>

// === Tasks

#include <types.h>

#define MAX_TASKS 1024
#define STACK_SIZE 1024

enum TaskState {
    Running,
    Ready,
    Paused
};

typedef struct TCB {
    uint_32 *esp;
    TaskState state;
} TCB;

extern "C" void switch_to_task(TCB *nextTask);

TCB *currentTaskTcb;
TCB tasksTcb[MAX_TASKS];
uint_32 tasksIndex;

void initializeMultitasking() {
    // Not initializing ESP because it won't help in any way
    tasksTcb[0].state = TaskState::Running;
    tasksIndex = 1;
    currentTaskTcb = &tasksTcb[0];
    
}

// First stack is a fake and not used because the kernel already has its stack setup from boot
uint_32 stacks[MAX_TASKS][STACK_SIZE];

int createKernelTask(void (*start)()) {
    if (tasksIndex == (MAX_TASKS - 1)) return -1;

    stacks[++tasksIndex][0] = (uint_32)start;

    TCB *newTaskTcb = &tasksTcb[tasksIndex];
    newTaskTcb->esp = stacks[tasksIndex];
    newTaskTcb->state = TaskState::Ready;

    return 0;
}

// ===

void testTask() {
    while (true) {
        println("Kernel test task");
        switch_to_task(&tasksTcb[0]);
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

    createKernelTask(testTask);

    while (true) {
        println("Kernel main task");
        switch_to_task(&tasksTcb[1]);
    }

    // ===

    return 0;
}