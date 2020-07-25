#include <screen.h>
#include <keyboard.h>
#include <idt.h>
#include <pic.h>
#include <pit.h>

// === Tasks

#include <types.h>

#define MAX_TASKS 2048
#define STACK_SIZE 2048

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
    tasksIndex = 0;
    currentTaskTcb = &tasksTcb[0];
    
}

// First stack is a fake and not used because the kernel already has its stack setup from boot
uint_32 stacks[MAX_TASKS][STACK_SIZE];

int createKernelTask(void (*start)()) {
    if (tasksIndex == (MAX_TASKS - 1)) return -1;

    tasksIndex++;

    stacks[tasksIndex][STACK_SIZE - 4] = (uint_32)&stacks[tasksIndex][0]; // EBP
    stacks[tasksIndex][STACK_SIZE - 3] = 1; // EDI
    stacks[tasksIndex][STACK_SIZE - 2] = 2; // ESI
    stacks[tasksIndex][STACK_SIZE - 1] = 3; // EBX
    stacks[tasksIndex][STACK_SIZE] = (uint_32)start;

    TCB *newTaskTcb = &tasksTcb[tasksIndex];
    newTaskTcb->esp = &stacks[tasksIndex][STACK_SIZE - 4];
    newTaskTcb->state = TaskState::Ready;

    return 0;
}

uint_32 runningTaskIndex = 0;

void schedule() {
    TCB *runningTask = &tasksTcb[runningTaskIndex];
    runningTask->state = TaskState::Ready;
    
    runningTaskIndex = (runningTaskIndex + 1) % (tasksIndex + 1);
    runningTask = &tasksTcb[runningTaskIndex];
    runningTask->state = TaskState::Running;
    switch_to_task(runningTask);
}

// ===

void testTask1() {
    while (true) {
        println("Kernel test task 1");
        schedule();
    }
}

void testTask2() {
    while (true) {
        println("Kernel test task 2");
        schedule();
    }
}

void testTask3() {
    while (true) {
        println("Kernel test task 3");
        schedule();
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

    createKernelTask(testTask1);
    createKernelTask(testTask2);
    createKernelTask(testTask3);

    while (true) {
        println("Kernel main task");
        schedule();
    }

    // ===

    return 0;
}