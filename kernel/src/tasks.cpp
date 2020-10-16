#include <tasks.h>
#include <pit.h>
#include <interrupt.h>
#include <screen.h>
#include <dynmem.h>
#include <virtmem.h>
#include <memory.h>
#include <pic.h>

#define TIME_SLICE_LENGTH 5;

static bool multitaskingInitialized = false;

TCB *currentTaskTcb;
TCB tasksTcb[MAX_TASKS];
uint_32 tasksIndex;

Mutex sleepingTasksMutex;

extern "C" void switch_to_task(TCB *nextTask);

void wakeupRoutine();

void idleTask() {
    while (true) { 
        // TODO: add HLT support, preempt idle task
    }
}

void initKernelMain() {
    // Not initializing ESP because it won't help in any way
    tasksTcb[0].state = TaskState::Running;
    tasksTcb[0].cr3 = (uint_32)getKernelPageDirectory();
    tasksTcb[0].lastStartTimeTick = getTicksSinceBoot();
    tasksTcb[0].name = "kernel_main";
    tasksTcb[0].priority = 1;
    tasksIndex = 0;
    currentTaskTcb = &tasksTcb[0];
}

void initializeMultitasking() {
    sleepingTasksMutex = Mutex();
    
    initKernelMain();

    createKernelTask(idleTask, "idle", 255);
    createKernelTask(wakeupRoutine, "wakeup");

    multitaskingInitialized = true;
}

void lockScheduler() {
    disableInterrupts();
}

void unlockScheduler() {
    enableInterrupts();
}

void userTaskStart() {
    unlockScheduler();
    
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
     push $0x4000; \
     iret; \
     ");
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
uint_32 *stacks[MAX_TASKS];

TCB* createKernelTask(void (*start)(), char *name, uint_8 priority) {
    lockScheduler();

    if (tasksIndex == (MAX_TASKS - 1)) return nullptr;

    tasksIndex++;

    stacks[tasksIndex] = (uint_32*)kcalloc(STACK_SIZE * sizeof(uint_32));

    stacks[tasksIndex][STACK_SIZE - 8] = (uint_32)&stacks[tasksIndex][STACK_SIZE - 1]; // EBP
    stacks[tasksIndex][STACK_SIZE - 7] = 1; // EDI
    stacks[tasksIndex][STACK_SIZE - 6] = 2; // ESI
    stacks[tasksIndex][STACK_SIZE - 5] = 3; // EBX
    stacks[tasksIndex][STACK_SIZE - 4] = (uint_32)kernelTaskStart;
    stacks[tasksIndex][STACK_SIZE - 3] = (uint_32)kernelTaskExit;
    stacks[tasksIndex][STACK_SIZE - 2] = (uint_32)start;

    TCB *newTaskTcb = &tasksTcb[tasksIndex];
    newTaskTcb->esp = &stacks[tasksIndex][STACK_SIZE - 8];
    newTaskTcb->cr3 = (uint_32)getKernelPageDirectory();
    newTaskTcb->state = TaskState::Ready;
    newTaskTcb->name = name; // TODO: change with dynamic mem
    newTaskTcb->nextTask = nullptr;
    newTaskTcb->priority = priority;
    newTaskTcb->user = false;

    unlockScheduler();
    return newTaskTcb;
}

TCB* createUserTask(void *start, size_t size) {
    lockScheduler();

    if (tasksIndex == (MAX_TASKS - 1)) return nullptr;

    tasksIndex++;

    PageDirectory *userPd = createUserPageDirectory();

    uint_32 imageSpace = kallocPagePhysical(3); // 12 KiB for user program image
    memcpy((void*)imageSpace, start, size);
    
    uint_32 *userStack = (uint_32*)(imageSpace + 0x2000);
    uint_32 stackSize = 1024; // 4 byte slots. 1024 * 4 = 0x1000;
    uint_32 *esp = (uint_32*)(0x7000 - 6*sizeof(uint_32));

    userStack[stackSize-6] = (uint_32)(uint_32*)(0x7000 - 1*sizeof(uint_32)); // EBP
    userStack[stackSize-5] = 1; // EDI
    userStack[stackSize-4] = 2; // ESI
    userStack[stackSize-3] = 3; // EBX
    userStack[stackSize-2] = (uint_32)userTaskStart;

    map(userPd, 0x4000, imageSpace, 3, true);

    uint_32 cr3 = (uint_32)userPd;

    TCB *userTask = &tasksTcb[tasksIndex];
    userTask->esp = esp;
    userTask->cr3 = cr3;
    userTask->state = TaskState::Ready;
    userTask->name = "User";
    userTask->user = true;
    userTask->nextTask = nullptr;
    userTask->priority = 1;

    unlockScheduler();

    return userTask;
}

// index to the last task, NOT to first open spot
uint_32 runningTaskIndex = 0;

void blockTask(Semaphore *toRelease) {
    lockScheduler();

    setBlockedState(toRelease);
    
    unlockScheduler();
}

void setBlockedState(Semaphore *toRelease) {
    currentTaskTcb->cpuTime += getMs(getTicksSinceBoot() - currentTaskTcb->lastStartTimeTick);
    currentTaskTcb->state = TaskState::Paused;
    if (toRelease != nullptr) toRelease->release();

    schedule();
}

void unblockTask(TCB *task) {
    lockScheduler();
    setUnblockedState(task);
    unlockScheduler();
}

void setUnblockedState(TCB *task) {
    task->state = TaskState::Ready;
}

uint_32 timeSliceRemaining;

uint_32 priorityToTimeSlice(uint_32 priority) {
    return priority == 255 ? 1 : TIME_SLICE_LENGTH;
}

void schedule() {
    uint_32 ticks = getTicksSinceBoot();
    currentTaskTcb->cpuTime += getMs(ticks - currentTaskTcb->lastStartTimeTick);

    if (currentTaskTcb->state == TaskState::Running) {
        currentTaskTcb->state = TaskState::Ready;
    }
    
    TCB *potentialTask;
    do {
        runningTaskIndex = (runningTaskIndex + 1) % (tasksIndex + 1);
        potentialTask = &tasksTcb[runningTaskIndex];
    } while (potentialTask->state != TaskState::Ready); // idle task should always be ready to run
    
    potentialTask->state = TaskState::Running;
    potentialTask->lastStartTimeTick = ticks;
    timeSliceRemaining = priorityToTimeSlice(potentialTask->priority);
    switch_to_task(potentialTask);
}

TCB *sleepingTasks[MAX_SLEEPING_TASKS];
uint_32 sleepingTasksCount = 0;

void wakeupRoutine() {
    while(true) {
        sleepingTasksMutex.wait();
        
        // Resume sleeping tasks, put into ready state

        uint_32 time = getMsSinceBoot();
        uint_32 removedCount = 0;
        for (size_t i = 0; i < sleepingTasksCount; i++)
        {
            TCB *task = sleepingTasks[i];
            if (task->state == TaskState::Paused && task->sleepExpiry < time) {
                unblockTask(task);
                sleepingTasks[i] = nullptr;
                removedCount++;
            }
        }
        
        // Rearrange sleeping tasks array
        if (removedCount != 0) {
            uint_32 newSleepingTasksCount = sleepingTasksCount - removedCount;
            
            int j = 0;
            int i = 0;
            while (i < newSleepingTasksCount && j < sleepingTasksCount) {    
                while (i < newSleepingTasksCount && sleepingTasks[i] != nullptr) {
                    i++;
                }

                if (j == 0) j = i;
                
                while (j < sleepingTasksCount && sleepingTasks[j] == nullptr) {
                    j++;
                }
                
                sleepingTasks[i++] = sleepingTasks[j];
                sleepingTasks[j++] = nullptr;
            }
            
            sleepingTasksCount = newSleepingTasksCount;
        }

        sleepingTasksMutex.release();

        lockScheduler();
        schedule();
        unlockScheduler();
    }
}

void timeUpdate(uint_32 time) {
    if (!multitaskingInitialized) return;
    
    // Check time slice

    timeSliceRemaining--;
    if (timeSliceRemaining == 0) {
        lockScheduler();
        sendEOI(false);
        schedule();
        unlockScheduler();
    }
    else {
        sendEOI(false);
    }
}

TCB *getCurrentTask() {
    return currentTaskTcb;
}

void sleepUntil(uint_32 time) {
    uint_32 timeSinceBoot = getMsSinceBoot();
    if (time < timeSinceBoot) {
        return;
    }

    sleepingTasksMutex.wait();
    if (sleepingTasksCount == MAX_SLEEPING_TASKS) {
        sleepingTasksMutex.release();
        return;
    }
    
    sleepingTasks[sleepingTasksCount] = currentTaskTcb;
    sleepingTasks[sleepingTasksCount]->sleepExpiry = time;
    sleepingTasksCount++;;

    blockTask(&sleepingTasksMutex);
}

void sleep(uint_32 ms) {
    sleepUntil(getMsSinceBoot() + ms);
}

