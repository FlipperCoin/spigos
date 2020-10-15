#pragma once

#include <types.h>
#include <tcb.h>
#include <sync.h>

#define MAX_TASKS 64
#define STACK_SIZE 512
#define MAX_SLEEPING_TASKS MAX_TASKS

void initializeMultitasking();
TCB* createKernelTask(void (*start)(), char *name = "", uint_8 priority = 1);
TCB* createUserTask();

void lockScheduler();
void unlockScheduler();
void schedule();

void blockTask(Semaphore *toRelease = nullptr);
void unblockTask(TCB *task);
void setBlockedState(Semaphore *toRelease = nullptr);
void setUnblockedState(TCB *task);

TCB *getCurrentTask();

void timeUpdate(uint_32 time);