#include <screen.h>
#include <keyboard.h>
#include <idt.h>
#include <pic.h>
#include <pit.h>
#include <interrupt.h>

// === Tasks

#include <types.h>

#define MAX_TASKS 2048
#define STACK_SIZE 2048

enum TaskState {
    Running,
    Ready,
    Paused
};

// NOTE: The structure is also used in "switch_to_task", 
// when updating the struct make sure it is correct there aswell
typedef struct TCB {
    uint_32 *esp;
    TaskState state;
    uint_32 cpuTime; // in milliseconds
    uint_32 lastStartTimeTick; // updated every time the task is ran by the scheduler
    char *name;
} TCB;

extern "C" void switch_to_task(TCB *nextTask);

TCB *currentTaskTcb;
TCB tasksTcb[MAX_TASKS];
uint_32 tasksIndex;

void initializeMultitasking() {
    // Not initializing ESP because it won't help in any way
    tasksTcb[0].state = TaskState::Running;
    tasksTcb[0].lastStartTimeTick = getTicks();
    tasksTcb[0].name = "kernel_main";
    tasksIndex = 0;
    currentTaskTcb = &tasksTcb[0];
    
}

void lockScheduler() {
    disableInterrupts();
}

void unlockScheduler() {
    enableInterrupts();
}

void kernelTaskStart(void (*start)()) {
    unlockScheduler();
    
    start();
}

void kernelTaskExit() {
    println("Kernel task exited...");

    // Need to properly implement task exit, loop for now
    while (true) {
        
    }
}

// First stack is a fake and not used because the kernel already has its stack setup from boot
uint_32 stacks[MAX_TASKS][STACK_SIZE];

int createKernelTask(void (*start)(), char *name = "") {
    if (tasksIndex == (MAX_TASKS - 1)) return -1;

    tasksIndex++;

    stacks[tasksIndex][STACK_SIZE - 6] = (uint_32)&stacks[tasksIndex][STACK_SIZE - 2]; // EBP
    stacks[tasksIndex][STACK_SIZE - 5] = 1; // EDI
    stacks[tasksIndex][STACK_SIZE - 4] = 2; // ESI
    stacks[tasksIndex][STACK_SIZE - 3] = 3; // EBX
    stacks[tasksIndex][STACK_SIZE - 2] = (uint_32)kernelTaskStart;
    stacks[tasksIndex][STACK_SIZE - 1] = (uint_32)kernelTaskExit;
    stacks[tasksIndex][STACK_SIZE] = (uint_32)start;

    TCB *newTaskTcb = &tasksTcb[tasksIndex];
    newTaskTcb->esp = &stacks[tasksIndex][STACK_SIZE - 6];
    newTaskTcb->state = TaskState::Ready;
    newTaskTcb->name = name; // TODO: change with dynamic mem
    return 0;
}

uint_32 runningTaskIndex = 0;

void schedule() {
    uint_32 ticks = getTicks();

    TCB *runningTask = &tasksTcb[runningTaskIndex];
    runningTask->cpuTime += getMs(ticks - runningTask->lastStartTimeTick);
    runningTask->state = TaskState::Ready;
    
    do {
        runningTaskIndex = (runningTaskIndex + 1) % (tasksIndex + 1);
        runningTask = &tasksTcb[runningTaskIndex];
    } while (runningTask->state != TaskState::Ready); // Full loop will lead to the task that we just put in the ready state
    
    runningTask->state = TaskState::Running;
    runningTask->lastStartTimeTick = ticks;
    switch_to_task(runningTask);
}

// ===

void testTask1() {
    uint_32 n = 0;
    while (true) {
        println("Kernel test task 1");
        for (size_t i = 0; i < 100000000; i++)
        {
            n += i;
        }
        lockScheduler();
        schedule();
        unlockScheduler();
    }
}

void testTask2() {
    uint_32 n = 0;
    while (true) {
        println("Kernel test task 2");
        for (size_t i = 0; i < 10000000; i++)
        {
            n += i;
        }
        lockScheduler();
        schedule();
        unlockScheduler();
    }
}

void testTask3() {
    uint_32 n = 0;
    while (true) {
        println("Kernel test task 3");
        for (size_t i = 0; i < 100000; i++)
        {
            n += i;
        }
        lockScheduler();
        schedule();
        unlockScheduler();
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

    createKernelTask(testTask1, "task_1");
    createKernelTask(testTask2, "task_2");
    createKernelTask(testTask3, "task_3");

    while (true) {
        println("Kernel main task");
        lockScheduler();
        schedule();
        unlockScheduler();
    }

    // ===

    return 0;
}