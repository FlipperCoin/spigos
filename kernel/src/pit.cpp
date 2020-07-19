#include <interrupt.h>
#include <screen.h>
#include <pit.h>
#include <pic.h>

__attribute__((interrupt))
void
timerISR(interrupt_frame *frame) {
    print("Timer");

    sendEOI(false);
}

void initTimer() {
    registerInterrupt(0x20, (void*)timerISR, Gate::interrupt);
}