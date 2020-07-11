#include <keyboard.h>
#include <interrupt.h>
#include <pic.h>
#include <port.h>
#include <screen.h>
#include <format.h>
#include <types.h>
#include <memory.h>

enum KeyEventType {
    Pressed = 0,
    Released = 1
};

enum KeyboardStateFlags {
    CapsLock = 1,
    ScrollLock = 2,
    NumLock = 4
};

KeyboardStateFlags keyboardState;

typedef struct KeyEvent {
    KeyCode key;
    KeyEventType type;
    KeyboardStateFlags state;
    bool pressedKeysKeymap[NUMBER_OF_KEYCODES];
} KeyEvent;

static uint_8 keysBuffer[KEYS_BUFFER_SIZE];
static size_t keysIndex;

static KeyEvent eventsBuffer[EVENTS_BUFFER_SIZE];
static size_t eventsIndex;

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

bool tryResolveSingleCharacterScanCode(uint_8 key, KeyCode *keycode, KeyEventType *type) {
    // pressed
    if (key >= 0x01 && key <= 0x58) { 
        *type = KeyEventType::Pressed;
    }
    // released
    else if (key >= 0x81 && key <= 0xD8) {
        *type = KeyEventType::Released;
        key -= 0x80;
    }
    else {
        return false;
    }

    *keycode = (KeyCode)key;
}

bool tryResolveMultiCharacterScanCode(uint_8 key, KeyCode *keycode, KeyEventType *type) {

}

bool tryResolveScanCode(uint_8 key, KeyCode *keycode, KeyEventType *type) {
    if (keysIndex == 0) {
        if (key == 0x0E) { // Start of multi character scan code
                keysBuffer[keysIndex++] = key;
                return false;
        }

        return tryResolveSingleCharacterScanCode(key, keycode, type);
    }
    else // In middle of multi character scan code
    {
        return tryResolveMultiCharacterScanCode(key, keycode, type);
    } 
}

void addKeyEvent(KeyCode keyCode, KeyEventType eventType) {
    KeyEvent newEvent = {
        keyCode,
        eventType,
        keyboardState,
        eventsBuffer[eventsIndex-1].pressedKeysKeymap
    };
    newEvent.pressedKeysKeymap[keyCode] = eventType == KeyEventType::Pressed;
    eventsBuffer[eventsIndex++] = newEvent;
}

__attribute__((interrupt))
void 
keyboardISR(interrupt_frame *frame) {
    uint_8 key = portByteIn(PS2_DATA_PORT);
    KeyCode keyCode;
    KeyEventType type;
    if (tryResolveScanCode(key, &keyCode, &type)) {
        addKeyEvent(keyCode, type);
    }
    
    sendEOI(false);
}

void initKeyboardDriver() {
    registerInterrupt(0x21, (void*)keyboardISR, Gate::interrupt);
}