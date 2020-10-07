#pragma once

#include <types.h>
#include <tcb.h>
#include <sync.h>

#define MAX_TASKS 128
#define STACK_SIZE 2048
#define MAX_SLEEPING_TASKS MAX_TASKS

void initializeMultitasking();
int createKernelTask(void (*start)(), char *name = "");

void lockScheduler();
void unlockScheduler();
void schedule();

void blockTask(Semaphore *toRelease = nullptr);
void unblockTask(TCB *task);
void setBlockedState(Semaphore *toRelease = nullptr);
void setUnblockedState(TCB *task);

TCB *getCurrentTask();

void timeUpdate(uint_32 time);