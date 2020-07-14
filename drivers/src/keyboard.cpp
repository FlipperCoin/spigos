#include <keyboard.h>
#include <interrupt.h>
#include <pic.h>

__attribute__((interrupt))
void 
keyboardISR(interrupt_frame *frame) {
    sendEOI(false);
    return;
}

void initKeyboardDriver() {
    registerInterrupt(0x21, (void*)keyboardISR, Gate::interrupt);
}