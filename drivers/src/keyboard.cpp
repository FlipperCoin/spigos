#include <keyboard.h>
#include <interrupt.h>
#include <pic.h>
#include <port.h>
#include <screen.h>
#include <format.h>
#include <types.h>

__attribute__((interrupt))
void 
keyboardISR(interrupt_frame *frame) {
    uint_8 key = portByteIn(PS2_DATA_PORT);
    
    print("Key Event: ");
    char buf[10];
    itoh(key, buf, 10);
    println(buf);
    
    sendEOI(false);
}

void initKeyboardDriver() {
    registerInterrupt(0x21, (void*)keyboardISR, Gate::interrupt);
}