#include <keyboard.h>
#include <interrupt.h>
#include <pic.h>
#include <port.h>
#include <screen.h>
#include <format.h>
#include <types.h>

#define NUMBER_OF_KEYS 256

enum KeyEventType {
    Pressed = 0,
    Released = 1
};

enum KeyboardStateFlags {
    CapsLock = 1,
    ScrollLock = 2,
    NumLock = 4
};

typedef struct KeyEvent {
    uint_8 key;
    KeyEventType type;
    KeyboardStateFlags state;
    KeyCode keymap[NUMBER_OF_KEYS];
} KeyEvent;

static uint_8 keysBuffer[KEYS_BUFFER_SIZE];
static uint_32 keysIndex;

static char shiftBufferLeft() {
    char c = keysBuffer[0];
    for (size_t i = 0; i < KEYS_BUFFER_SIZE - 1; i++)
    {
        keysBuffer[i] = keysBuffer[i+1];
    }
    keysIndex--;
    return c;
}

static void appendKey(uint_8 key) {
    if (keysIndex < KEYS_BUFFER_SIZE) {
        keysBuffer[keysIndex++];
    } else {
        shiftBufferLeft();
        keysBuffer[keysIndex++];
    }
}

char readKey() {
    return shiftBufferLeft();
}

__attribute__((interrupt))
void 
keyboardISR(interrupt_frame *frame) {
    uint_8 key = portByteIn(PS2_DATA_PORT);
    appendKey(key);
    
    sendEOI(false);
}

void initKeyboardDriver() {
    registerInterrupt(0x21, (void*)keyboardISR, Gate::interrupt);
}