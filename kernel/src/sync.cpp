#include <sync.h>
#include <interrupt.h>
#include <tasks.h>

Semaphore::Semaphore(size_t n) {
    _blockedTasksLinkedList = nullptr;
    _n = n;
}

void Semaphore::wait() {
    disableInterrupts();
    if (_n > 0) {
        _n--;
        enableInterrupts();
        return;
    }

    if (_blockedTasksLinkedList == nullptr) {
        _blockedTasksLinkedList = getCurrentTask();
        _blockedTasksLinkedList->nextTask = nullptr;
        _lastBlockedTask = _blockedTasksLinkedList;
    }
    else {
        _lastBlockedTask->nextTask = getCurrentTask();
        _lastBlockedTask = _lastBlockedTask->nextTask;
    }

    setBlockedState();
    enableInterrupts();
}

void Semaphore::release() {
    disableInterrupts();

    if (_blockedTasksLinkedList == nullptr) {
        _n++;
        enableInterrupts();
        return;
    }

    TCB *next = _blockedTasksLinkedList->nextTask;
    _blockedTasksLinkedList->nextTask = nullptr;
    setUnblockedState(_blockedTasksLinkedList);
    // if next is nullptr, one might think that _lastBlockedTask should be cleared (which is not the case here),
    // but it doesn't cause any bugs so all good
    _blockedTasksLinkedList = next;
    
    enableInterrupts();
}

Mutex::Mutex() : Semaphore::Semaphore(1) {}