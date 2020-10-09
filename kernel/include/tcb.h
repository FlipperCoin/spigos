#pragma once

#include <types.h>

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
    uint_32 sleepExpiry;
    TCB *nextTask; // used by other components to easily track paused tasks
    uint_8 priority;
} TCB;
