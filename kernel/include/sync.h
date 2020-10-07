#pragma once

#include <types.h>
#include <tcb.h>

class Semaphore {
    private:
        size_t _n;
        TCB* _blockedTasksLinkedList;
        TCB* _lastBlockedTask;
    
    public:
        Semaphore(size_t n);
        void wait();
        void release();
};

class Mutex : public Semaphore {  
    public:
        Mutex();
};