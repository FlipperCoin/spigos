#include <keyboard.h>
#include <interrupt.h>
#include <pic.h>
#include <port.h>
#include <screen.h>
#include <format.h>
#include <types.h>
#include <memory.h>
#include <tasks.h>
#include <sync.h>

namespace ScanCodes {
    uint_8 PrevTrackPressed[] = {0xE0, 0x10};
    uint_8 NextTrackPressed[] = {0xE0, 0x19};
    uint_8 KeypadEnterPressed[] = {0xE0, 0x1C};
    uint_8 RightControlPressed[] = {0xE0, 0x1D};
    uint_8 MutePressed[] = {0xE0, 0x20};
    uint_8 CalculatorPressed[] = {0xE0, 0x21};
    uint_8 PlayPressed[] = {0xE0, 0x22};
    uint_8 StopPressed[] = {0xE0, 0x24};
    uint_8 VolumeDownPressed[] = {0xE0, 0x2E};
    uint_8 VolumeUpPressed[] = {0xE0, 0x30};
    uint_8 WWWHomePressed[] = {0xE0, 0x32};
    uint_8 KeypadSlashPressed[] = {0xE0, 0x35};
    uint_8 RightAltPressed[] = {0xE0, 0x38};
    uint_8 HomePressed[] = {0xE0, 0x47};
    uint_8 CurserUpPressed[] = {0xE0, 0x48};
    uint_8 PageUpPressed[] = {0xE0, 0x49};
    uint_8 CurserLeftPressed[] = {0xE0, 0x4B};
    uint_8 CurserRightPressed[] = {0xE0, 0x4D};
    uint_8 EndPressed[] = {0xE0, 0x4F};
    uint_8 CurserDownPressed[] = {0xE0, 0x50};
    uint_8 PageDownPressed[] = {0xE0, 0x51};
    uint_8 InsertPressed[] = {0xE0, 0x52};
    uint_8 DeletePressed[] = {0xE0, 0x53};
    uint_8 LeftGUIPressed[] = {0xE0, 0x5B};
    uint_8 RightGUIPressed[] = {0xE0, 0x5C};
    uint_8 AppsPressed[] = {0xE0, 0x5D};
    uint_8 PowerPressed[] = {0xE0, 0x5E};
    uint_8 SleepPressed[] = {0xE0, 0x5F};
    uint_8 WakePressed[] = {0xE0, 0x63};
    uint_8 WWWSearchPressed[] = {0xE0, 0x65};
    uint_8 WWWFavoritesPressed[] = {0xE0, 0x66};
    uint_8 WWWRefreshPressed[] = {0xE0, 0x67};
    uint_8 WWWStopPressed[] = {0xE0, 0x68};
    uint_8 WWWForwardPressed[] = {0xE0, 0x69};
    uint_8 WWWBackPressed[] = {0xE0, 0x6A};
    uint_8 MyComputerPressed[] = {0xE0, 0x6B};
    uint_8 EmailPressed[] = {0xE0, 0x6C};
    uint_8 MediaSelectPressed[] = {0xE0, 0x6D};

    uint_8 PrevTrackReleased[] = {0xE0, 0x90};		
    uint_8 NextTrackReleased[] = {0xE0, 0x99};
    uint_8 KeypadEnterReleased[] = {0xE0, 0x9C};
    uint_8 RightControlReleased[] = {0xE0, 0x9D};
    uint_8 MuteReleased[] = {0xE0, 0xA0};
    uint_8 CalculatorReleased[] = {0xE0, 0xA1};
    uint_8 PlayReleased[] = {0xE0, 0xA2};
    uint_8 StopReleased[] = {0xE0, 0xA4};
    uint_8 VolumeDownReleased[] = {0xE0, 0xAE};
    uint_8 VolumeUpReleased[] = {0xE0, 0xB0};
    uint_8 WWWHomeReleased[] = {0xE0, 0xB2};
    uint_8 KeypadSlashReleased[] = {0xE0, 0xB5};
    uint_8 RightAltReleased[] = {0xE0, 0xB8};
    uint_8 HomeReleased[] = {0xE0, 0xC7};
    uint_8 CurserUpReleased[] = {0xE0, 0xC8};
    uint_8 PageUpReleased[] = {0xE0, 0xC9};
    uint_8 CurserLeftReleased[] = {0xE0, 0xCB};
    uint_8 CurserRightReleased[] = {0xE0, 0xCD};
    uint_8 EndReleased[] = {0xE0, 0xCF};
    uint_8 CurserDownReleased[] = {0xE0, 0xD0};
    uint_8 PageDownReleased[] = {0xE0, 0xD1};
    uint_8 InsertReleased[] = {0xE0, 0xD2};
    uint_8 DeleteReleased[] = {0xE0, 0xD3};
    uint_8 LeftGUIReleased[] = {0xE0, 0xDB};
    uint_8 RightGUIReleased[] = {0xE0, 0xDC};
    uint_8 AppsReleased[] = {0xE0, 0xDD};
    uint_8 PowerReleased[] = {0xE0, 0xDE};
    uint_8 SleepReleased[] = {0xE0, 0xDF};
    uint_8 WakeReleased[] = {0xE0, 0xE3};
    uint_8 WWWSearchReleased[] = {0xE0, 0xE5};
    uint_8 WWWFavoritesReleased[] = {0xE0, 0xE6};
    uint_8 WWWRefreshReleased[] = {0xE0, 0xE7};
    uint_8 WWWStopReleased[] = {0xE0, 0xE8};
    uint_8 WWWForwardReleased[] = {0xE0, 0xE9};
    uint_8 WWWBackReleased[] = {0xE0, 0xEA};
    uint_8 MyComputerReleased[] = {0xE0, 0xEB};
    uint_8 EmailReleased[] = {0xE0, 0xEC};
    uint_8 MediaSelectReleased[] = {0xE0, 0xED};

    uint_8 PrintScreenPressed[] = {0xE0, 0x2A, 0xE0, 0x37};
    uint_8 PrintScreenReleased[] = {0xE0, 0xB7, 0xE0, 0xAA};
    uint_8 PauseReleased[] = {0xE1, 0x1D, 0x45, 0xE1, 0x9D, 0xC5};
};

typedef struct ScanCode {
    size_t length;
    uint_8 *scanCode;
} ScanCode;

typedef struct KeyCodeMapping {
    ScanCode scanCode;
    KeyCode keyCode;
} KeyCodeMapping;

KeyCodeMapping mappings[75] = {
    {
        {2, ScanCodes::PrevTrackPressed},
        KeyCode::PrevTrack
    },
    {
        {2, ScanCodes::NextTrackPressed},
        KeyCode::NextTrack
    },
    {
        {2, ScanCodes::KeypadEnterPressed},
        KeyCode::KeypadEnter
    },
    {
        {2, ScanCodes::RightControlPressed},
        KeyCode::RightControl
    },
    {
        {2, ScanCodes::MutePressed},
        KeyCode::Mute
    },
    {
        {2, ScanCodes::CalculatorPressed},
        KeyCode::Calculator
    },
    {
        {2, ScanCodes::PlayPressed},
        KeyCode::Play
    },
    {
        {2, ScanCodes::StopPressed},
        KeyCode::Stop
    },
    {
        {2, ScanCodes::VolumeDownPressed},
        KeyCode::VolumeDown
    },
    {
        {2, ScanCodes::VolumeUpPressed},
        KeyCode::VolumeUp
    },
    {
        {2, ScanCodes::WWWHomePressed},
        KeyCode::WWWHome
    },
    {
        {2, ScanCodes::KeypadSlashPressed},
        KeyCode::KeypadSlash
    },
    {
        {2, ScanCodes::RightAltPressed},
        KeyCode::RightAlt
    },
    {
        {2, ScanCodes::HomePressed},
        KeyCode::Home
    },
    {
        {2, ScanCodes::CurserUpPressed},
        KeyCode::CurserUp
    },
    {
        {2, ScanCodes::PageUpPressed},
        KeyCode::PageUp
    },
    {
        {2, ScanCodes::CurserLeftPressed},
        KeyCode::CurserLeft
    },
    {
        {2, ScanCodes::CurserRightPressed},
        KeyCode::CurserRight
    },
    {
        {2, ScanCodes::EndPressed},
        KeyCode::End
    },
    {
        {2, ScanCodes::CurserDownPressed},
        KeyCode::CurserDown
    },
    {
        {2, ScanCodes::PageDownPressed},
        KeyCode::PageDown
    },
    {
        {2, ScanCodes::InsertPressed},
        KeyCode::Insert
    },
    {
        {2, ScanCodes::DeletePressed},
        KeyCode::Delete
    },
    {
        {2, ScanCodes::LeftGUIPressed},
        KeyCode::LeftGUI
    },
    {
        {2, ScanCodes::RightGUIPressed},
        KeyCode::RightGUI
    },
    {
        {2, ScanCodes::AppsPressed},
        KeyCode::Apps
    },
    {
        {2, ScanCodes::PowerPressed},
        KeyCode::Power
    },
    {
        {2, ScanCodes::SleepPressed},
        KeyCode::Sleep
    },
    {
        {2, ScanCodes::WakePressed},
        KeyCode::Wake
    },
    {
        {2, ScanCodes::WWWSearchPressed},
        KeyCode::WWWSearch
    },
    {
        {2, ScanCodes::WWWFavoritesPressed},
        KeyCode::WWWFavorites
    },
    {
        {2, ScanCodes::WWWRefreshPressed},
        KeyCode::WWWRefresh
    },
    {
        {2, ScanCodes::WWWStopPressed},
        KeyCode::WWWStop
    },
    {
        {2, ScanCodes::WWWForwardPressed},
        KeyCode::WWWForward
    },
    {
        {2, ScanCodes::WWWBackPressed},
        KeyCode::WWWBack
    },
    {
        {2, ScanCodes::MyComputerPressed},
        KeyCode::MyComputer
    },
    {
        {2, ScanCodes::EmailPressed},
        KeyCode::Email
    },
    {
        {2, ScanCodes::MediaSelectPressed},
        KeyCode::MediaSelect
    },

    {
        {2, ScanCodes::PrevTrackReleased},
        KeyCode::PrevTrack
    },
    {
        {2, ScanCodes::NextTrackReleased},
        KeyCode::NextTrack
    },
    {
        {2, ScanCodes::KeypadEnterReleased},
        KeyCode::KeypadEnter
    },
    {
        {2, ScanCodes::RightControlReleased},
        KeyCode::RightControl
    },
    {
        {2, ScanCodes::MuteReleased},
        KeyCode::Mute
    },
    {
        {2, ScanCodes::CalculatorReleased},
        KeyCode::Calculator
    },
    {
        {2, ScanCodes::PlayReleased},
        KeyCode::Play
    },
    {
        {2, ScanCodes::StopReleased},
        KeyCode::Stop
    },
    {
        {2, ScanCodes::VolumeDownReleased},
        KeyCode::VolumeDown
    },
    {
        {2, ScanCodes::VolumeUpReleased},
        KeyCode::VolumeUp
    },
    {
        {2, ScanCodes::WWWHomeReleased},
        KeyCode::WWWHome
    },
    {
        {2, ScanCodes::KeypadSlashReleased},
        KeyCode::KeypadSlash
    },
    {
        {2, ScanCodes::RightAltReleased},
        KeyCode::RightAlt
    },
    {
        {2, ScanCodes::HomeReleased},
        KeyCode::Home
    },
    {
        {2, ScanCodes::CurserUpReleased},
        KeyCode::CurserUp
    },
    {
        {2, ScanCodes::PageUpReleased},
        KeyCode::PageUp
    },
    {
        {2, ScanCodes::CurserLeftReleased},
        KeyCode::CurserLeft
    },
    {
        {2, ScanCodes::CurserRightReleased},
        KeyCode::CurserRight
    },
    {
        {2, ScanCodes::EndReleased},
        KeyCode::End
    },
    {
        {2, ScanCodes::CurserDownReleased},
        KeyCode::CurserDown
    },
    {
        {2, ScanCodes::PageDownReleased},
        KeyCode::PageDown
    },
    {
        {2, ScanCodes::InsertReleased},
        KeyCode::Insert
    },
    {
        {2, ScanCodes::DeleteReleased},
        KeyCode::Delete
    },
    {
        {2, ScanCodes::LeftGUIReleased},
        KeyCode::LeftGUI
    },
    {
        {2, ScanCodes::RightGUIReleased},
        KeyCode::RightGUI
    },
    {
        {2, ScanCodes::AppsReleased},
        KeyCode::Apps
    },
    {
        {2, ScanCodes::PowerReleased},
        KeyCode::Power
    },
    {
        {2, ScanCodes::SleepReleased},
        KeyCode::Sleep
    },
    {
        {2, ScanCodes::WakeReleased},
        KeyCode::Wake
    },
    {
        {2, ScanCodes::WWWSearchReleased},
        KeyCode::WWWSearch
    },
    {
        {2, ScanCodes::WWWFavoritesReleased},
        KeyCode::WWWFavorites
    },
    {
        {2, ScanCodes::WWWRefreshReleased},
        KeyCode::WWWRefresh
    },
    {
        {2, ScanCodes::WWWStopReleased},
        KeyCode::WWWStop
    },
    {
        {2, ScanCodes::WWWForwardReleased},
        KeyCode::WWWForward
    },
    {
        {2, ScanCodes::WWWBackReleased},
        KeyCode::WWWBack
    },
    {
        {2, ScanCodes::MyComputerReleased},
        KeyCode::MyComputer
    },
    {
        {2, ScanCodes::EmailReleased},
        KeyCode::Email
    }
};

uint_8 keyCodeToAscii[NUMBER_OF_KEYCODES];

uint_8 keyboardState;
bool pressedKeysKeymap[NUMBER_OF_KEYCODES];

static uint_8 keysBuffer[KEYS_BUFFER_SIZE];
static size_t keysIndex;

static KeyEvent eventsBuffer[EVENTS_BUFFER_SIZE];
static size_t eventsIndex;

TCB *waitingTask;

Semaphore eventsMutex = {10};

KeyEvent readKey() {
    eventsMutex.wait();

    if (eventsIndex == 0) {
        waitingTask = getCurrentTask();
        blockTask(&eventsMutex);
        
        eventsMutex.wait();
    }

    KeyEvent event = eventsBuffer[--eventsIndex];
    eventsMutex.release();
    
    return event;
}

bool isShiftableKey(KeyCode key) {
    return false; // not supported yet :)
}

uint_8 shiftAlpha(uint_8 ascii) {
    if (ascii <= 90) return (ascii + 32);
    else return (ascii - 32);
}

bool isAlpha(uint_8 ascii) {
    return ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122));
}

uint_8 keyEventToAscii(const KeyEvent *event) {
    uint_8 ascii = keyCodeToAscii[event->key];

    if (ascii == 0) return 0;

    bool capsLockOn = event->state & (int)KeyboardStateFlags::CapsLock;
    bool shiftIsPressed = event->pressedKeysKeymap[KeyCode::LeftShift] || event->pressedKeysKeymap[KeyCode::RightShift];
    
    if (shiftIsPressed) {
        bool isAlphaChar = isAlpha(ascii);
        if (isAlphaChar && !capsLockOn) {
            ascii = shiftAlpha(ascii);
        }
        else if (!isAlpha && isShiftableKey(event->key)) {
            // Shift keycode or ascii code, or use tryShiftKey() instead of isShiftable()->Shift()
        }
    }
    else if (capsLockOn && isAlpha(ascii)) {
        ascii = shiftAlpha(ascii);   
    }

    return ascii;
}

uint_8 readChar() {
    KeyEvent keyEvent;
    uint_8 ascii;
    do {
        keyEvent = readKey();
        ascii = keyEventToAscii(&keyEvent);
    } while (keyEvent.type != KeyEventType::Pressed || ascii == 0);

    return ascii;
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
    return true;
}

bool tryResolveMultiCharacterScanCode(uint_8 key, KeyCode *keycode, KeyEventType *type) {
    if (keysIndex == KEYS_BUFFER_SIZE) {
        keysIndex = 0;
        return false;
    }

    keysBuffer[keysIndex++] = key;

    bool potential = false;
    size_t currentScanCodeLength = keysIndex;
    for (KeyCodeMapping mapping : mappings) {
        if (currentScanCodeLength > mapping.scanCode.length) continue;

        // No Match
        if (currentScanCodeLength < mapping.scanCode.length) {
            // Notify if current buffer still has potential
            if (!potential) {
                int cmp = memcmp(keysBuffer, mapping.scanCode.scanCode, currentScanCodeLength);
                potential = (currentScanCodeLength < mapping.scanCode.length && cmp == 0);
            }

            continue;
        }

        // Same Size
        int cmp = memcmp(keysBuffer, mapping.scanCode.scanCode, currentScanCodeLength);
        if (cmp != 0) continue;
        
        // Match
        keysIndex = 0;    
        // Standard dual-char scan codes differ in type with a constant 
        if (currentScanCodeLength == 2) {
            // Pressed
            if (keysBuffer[1] >= 0x10 && keysBuffer[1] <= 0x6D) {
                *type = KeyEventType::Pressed;
            }
            // Released
            else if (keysBuffer[1] >= 0x90 && keysBuffer[1] <= 0xED) {
                *type = KeyEventType::Released;
            }
            else {
                // Error of flawed design because I'm lazy, should add to mapping the KeyEventType
                return false;
            }
        }
        else if (currentScanCodeLength == 4 && memcmp(keysBuffer, ScanCodes::PrintScreenPressed, 4)) {
            *type = KeyEventType::Pressed;
        }
        else if (currentScanCodeLength == 4 && memcmp(keysBuffer, ScanCodes::PrintScreenReleased, 4)) {
            *type = KeyEventType::Released;
        }
        else if (currentScanCodeLength == 6 && memcmp(keysBuffer, ScanCodes::PauseReleased, 6)) {
            *type = KeyEventType::Released;
        }
        else {
            // Error of flawed design because I'm lazy, should add to mapping the KeyEventType
            return false;
        }

        *keycode = mapping.keyCode;
        return true;
    }

    if (!potential) {
        keysIndex = 0;
    }

    return false;
}

bool tryResolveScanCode(uint_8 key, KeyCode *keycode, KeyEventType *type) {
    if (keysIndex == 0) {
        if (key == 0xE0 || key == 0xE1) { // Start of multi character scan code
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
    if (eventType == KeyEventType::Pressed) {
        if (keyCode == KeyCode::NumLock) {
            keyboardState ^= (int)KeyboardStateFlags::NumLock;
        }
        if (keyCode == KeyCode::ScrollLock) {
            keyboardState ^= (int)KeyboardStateFlags::ScrollLock;
        }
        if (keyCode == KeyCode::CapsLock) {
            keyboardState ^= (int)KeyboardStateFlags::CapsLock;
        }
    }
    
    KeyEvent newEvent = {
        keyCode,
        eventType,
        keyboardState,
        { false }
    };

    pressedKeysKeymap[keyCode] = eventType == KeyEventType::Pressed;
    memcpy(newEvent.pressedKeysKeymap, pressedKeysKeymap, NUMBER_OF_KEYCODES * sizeof(bool));

    if (eventsIndex == EVENTS_BUFFER_SIZE) { 
        for (size_t i = 0; i < EVENTS_BUFFER_SIZE - 1; i++)
        {
            eventsBuffer[i] = eventsBuffer[i+1];
        }
        eventsIndex--;
    }
    eventsBuffer[eventsIndex++] = newEvent;
}

bool keypressFlag;

void keyboardDriverTask() {
    while(true) {
        
        while(true) {
            disableInterrupts();
            if (!keypressFlag) {
                setBlockedState();
                
                enableInterrupts();
            } else {
                keypressFlag = false;
                break;
            }
        }
        enableInterrupts();

        uint_8 key = portByteIn(PS2_DATA_PORT);
        KeyCode keyCode;
        KeyEventType type;
        if (tryResolveScanCode(key, &keyCode, &type)) {
            eventsMutex.wait();
            addKeyEvent(keyCode, type);

            if (waitingTask != nullptr) {
                unblockTask(waitingTask);
                waitingTask = nullptr;
            }
            eventsMutex.release();
        }
    }
}

TCB* keyboardDriverTaskTcb;

void keyboardISR(interrupt_frame *frame) {
    disableInterrupts();
    keypressFlag=true;
    setUnblockedState(keyboardDriverTaskTcb);
    enableInterrupts();
    
    sendEOI(false); 
}

void initKeyCodeToAscii() {
    keyCodeToAscii[KeyCode::A] = 'a';
    keyCodeToAscii[KeyCode::B] = 'b';
    keyCodeToAscii[KeyCode::C] = 'c';
    keyCodeToAscii[KeyCode::D] = 'd';
    keyCodeToAscii[KeyCode::E] = 'e';
    keyCodeToAscii[KeyCode::F] = 'f';
    keyCodeToAscii[KeyCode::G] = 'g';
    keyCodeToAscii[KeyCode::H] = 'h';
    keyCodeToAscii[KeyCode::I] = 'i';
    keyCodeToAscii[KeyCode::J] = 'j';
    keyCodeToAscii[KeyCode::K] = 'k';
    keyCodeToAscii[KeyCode::L] = 'l';
    keyCodeToAscii[KeyCode::M] = 'm';
    keyCodeToAscii[KeyCode::N] = 'n';
    keyCodeToAscii[KeyCode::O] = 'o';
    keyCodeToAscii[KeyCode::P] = 'p';
    keyCodeToAscii[KeyCode::Q] = 'q';
    keyCodeToAscii[KeyCode::R] = 'r';
    keyCodeToAscii[KeyCode::S] = 's';
    keyCodeToAscii[KeyCode::T] = 't';
    keyCodeToAscii[KeyCode::U] = 'u';
    keyCodeToAscii[KeyCode::V] = 'v';
    keyCodeToAscii[KeyCode::W] = 'w';
    keyCodeToAscii[KeyCode::X] = 'x';
    keyCodeToAscii[KeyCode::Y] = 'y';
    keyCodeToAscii[KeyCode::Z] = 'z';

    keyCodeToAscii[KeyCode::Zero] = '0';
    keyCodeToAscii[KeyCode::One] = '1';
    keyCodeToAscii[KeyCode::Two] = '2';
    keyCodeToAscii[KeyCode::Three] = '3';
    keyCodeToAscii[KeyCode::Four] = '4';
    keyCodeToAscii[KeyCode::Five] = '5';
    keyCodeToAscii[KeyCode::Six] = '6';
    keyCodeToAscii[KeyCode::Seven] = '7';
    keyCodeToAscii[KeyCode::Eight] = '8';
    keyCodeToAscii[KeyCode::Nine] = '9';
    
    keyCodeToAscii[KeyCode::Keypad0] = '0';
    keyCodeToAscii[KeyCode::Keypad1] = '1';
    keyCodeToAscii[KeyCode::Keypad2] = '2';
    keyCodeToAscii[KeyCode::Keypad3] = '3';
    keyCodeToAscii[KeyCode::Keypad4] = '4';
    keyCodeToAscii[KeyCode::Keypad5] = '5';
    keyCodeToAscii[KeyCode::Keypad6] = '6';
    keyCodeToAscii[KeyCode::Keypad7] = '7';
    keyCodeToAscii[KeyCode::Keypad8] = '8';
    keyCodeToAscii[KeyCode::Keypad9] = '9';

    keyCodeToAscii[KeyCode::Space] = ' ';
    keyCodeToAscii[KeyCode::Tab] = '\t';
    keyCodeToAscii[KeyCode::Enter] = '\n';
    keyCodeToAscii[KeyCode::Period] = '.';
    keyCodeToAscii[KeyCode::Comma] = ',';
    keyCodeToAscii[KeyCode::Slash] = '/';
    keyCodeToAscii[KeyCode::SemiColon] = ';';
    keyCodeToAscii[KeyCode::OpenSquareBracket] = '[';
    keyCodeToAscii[KeyCode::CloseSquareBracket] = ']';
    keyCodeToAscii[KeyCode::BackSlash] = '\\';
    keyCodeToAscii[KeyCode::BackTick] = '`';
    keyCodeToAscii[KeyCode::KeypadMinus] = '-';
    keyCodeToAscii[KeyCode::KeypadPlus] = '+';
    keyCodeToAscii[KeyCode::KeypadPeriod] = '.';
    keyCodeToAscii[KeyCode::KeypadAsterisk] = '*';
    keyCodeToAscii[KeyCode::Minus] = '-';
    keyCodeToAscii[KeyCode::Equals] = '=';
    keyCodeToAscii[KeyCode::Backspace] = '\b';
}

void initKeyboardDriver() {
    eventsMutex = Mutex();
    keypressFlag = false;
    initKeyCodeToAscii();

    keyboardDriverTaskTcb = createKernelTask(keyboardDriverTask, "keyboard_driver");

    registerInterrupt(0x21, keyboardISR, Gate::interrupt);
}