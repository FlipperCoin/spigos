#include <types.h>

#define MAX_TASKS 2048
#define STACK_SIZE 2048
#define MAX_SLEEPING_TASKS MAX_TASKS

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
} TCB;

void initializeMultitasking();
int createKernelTask(void (*start)(), char *name = "");

void lockScheduler();
void unlockScheduler();
void schedule();

void timeUpdate(uint_32 time);