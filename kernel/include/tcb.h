#pragma once

#include <types.h>

enum TaskState {
    Running,
    Ready,
    Paused
};

// TCB - Thread Control Block
// NOTE: The structure is also used in "switch_to_task", 
// when updating the struct make sure it is correct there aswell
typedef struct TCB {
    uint_32 *esp;
    uint_32 cr3;
    uint_32 id;
    char *name;
    TaskState state;
    uint_32 cpuTime; // in milliseconds
    uint_32 lastStartTimeTick; // updated every time the task is ran by the scheduler
    uint_32 sleepExpiry;
    TCB *nextTask; // used by other components to easily track paused tasks
    uint_8 priority;
    bool user; // false = kernel task, true = user task
} TCB;
