#include <tasks.h>
#include <pit.h>
#include <interrupt.h>
#include <screen.h>

TCB *currentTaskTcb;
TCB tasksTcb[MAX_TASKS];
uint_32 tasksIndex;

extern "C" void switch_to_task(TCB *nextTask);

void idleTask() {
    while (true) { 
        // TODO: remove once scheduler works on timer, add HLT support, preempt idle task ===
        lockScheduler();
        schedule();
        unlockScheduler();
        // ===
    }
}

void initKernelMain() {
    // Not initializing ESP because it won't help in any way
    tasksTcb[0].state = TaskState::Running;
    tasksTcb[0].lastStartTimeTick = getTicksSinceBoot();
    tasksTcb[0].name = "kernel_main";
    tasksIndex = 0;
    currentTaskTcb = &tasksTcb[0];
}

void initializeMultitasking() {
    initKernelMain();

    createKernelTask(idleTask, "idle");
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

int createKernelTask(void (*start)(), char *name) {
    lockScheduler();

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

    unlockScheduler();
    return 0;
}

// index to the last task, NOT to first open spot
uint_32 runningTaskIndex = 0;

void blockTask() {
    lockScheduler();
    currentTaskTcb->cpuTime += getMs(getTicksSinceBoot() - currentTaskTcb->lastStartTimeTick);
    currentTaskTcb->state = TaskState::Paused;
    schedule();
    unlockScheduler();
}

void unblockTask(uint_32 taskIndex) {
    lockScheduler();
    tasksTcb[taskIndex].state = TaskState::Ready;
    unlockScheduler();
}

void schedule() {
    uint_32 ticks = getTicksSinceBoot();

    if (currentTaskTcb->state == TaskState::Running) {
        currentTaskTcb->cpuTime += getMs(ticks - currentTaskTcb->lastStartTimeTick);
        currentTaskTcb->state = TaskState::Ready;
    }
    
    TCB *potentialTask;
    do {
        runningTaskIndex = (runningTaskIndex + 1) % (tasksIndex + 1);
        potentialTask = &tasksTcb[runningTaskIndex];
    } while (potentialTask->state != TaskState::Ready); // idle task should always be ready to run
    
    potentialTask->state = TaskState::Running;
    potentialTask->lastStartTimeTick = ticks;
    switch_to_task(potentialTask);
}

TCB *sleepingTasks[MAX_SLEEPING_TASKS];
uint_32 sleepingTasksIndex = 0;

void timeUpdate(uint_32 time) {
    lockScheduler();
    
    uint_32 removedCount = 0;
    for (size_t i = 0; i < sleepingTasksIndex; i++)
    {
        TCB *task = sleepingTasks[i];
        if (task->state == TaskState::Paused && task->sleepExpiry < time) {
            task->state = TaskState::Ready;
            sleepingTasks[i] = nullptr;
            removedCount++;
        }
    }

    if (removedCount == 0) {
        unlockScheduler();
        return;
    }

    uint_32 newSleepingTasksIndex = sleepingTasksIndex - removedCount;
    
    int j = 0;
    int i = 0;
    while (i < newSleepingTasksIndex && j < sleepingTasksIndex) {    
        while (i < newSleepingTasksIndex && sleepingTasks[i] != nullptr) {
            i++;
        }

        if (j == 0) j = i;

        while (j < sleepingTasksIndex && sleepingTasks[j] == nullptr) {
            j++;
        }

        sleepingTasks[i++] = sleepingTasks[j];
        sleepingTasks[j++] = nullptr;
    }

    unlockScheduler();
}

void sleepUntil(uint_32 time) {
    lockScheduler();

    uint_32 timeSinceBoot = getMsSinceBoot();
    if (time < timeSinceBoot) {
        unlockScheduler();
        return;
    }

    if (sleepingTasksIndex == MAX_SLEEPING_TASKS) {
        unlockScheduler();
        return;
    }

    sleepingTasks[sleepingTasksIndex] = currentTaskTcb;
    sleepingTasks[sleepingTasksIndex]->sleepExpiry = time;
    sleepingTasksIndex++;

    unlockScheduler();
    blockTask();
}

void sleep(uint_32 ms) {
    sleepUntil(getMsSinceBoot() + ms);
}

