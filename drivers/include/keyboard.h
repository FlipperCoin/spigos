#include <types.h>

#define PS2_DATA_PORT 0x60

#define KEYS_BUFFER_SIZE 6
#define EVENTS_BUFFER_SIZE 64

#define NUMBER_OF_KEYCODES 256

enum KeyCode {
	NULL_KEY = 0,
	Q = 0x10,
	W = 0x11,
	E = 0x12,
	R = 0x13,
	T = 0x14,
	Y = 0x15,
	U = 0x16,
	I = 0x17,
	O = 0x18,
	P = 0x19,
	A = 0x1E,
	S = 0x1F,
	D = 0x20,
	F = 0x21,
	G = 0x22,
	H = 0x23,
	J = 0x24,
	K = 0x25,
	L = 0x26,
	Z = 0x2C,
	X = 0x2D,
	C = 0x2E,
	V = 0x2F,
	B = 0x30,
	N = 0x31,
	M = 0x32,

	Zero = 0x29,
	One = 0x2,
	Two = 0x3,
	Three = 0x4,
	Four = 0x5,
	Five = 0x6,
	Six = 0x7,
	Seven = 0x8,
	Eight = 0x9,
	Nine = 0xA,

	OpenSquareBracket = 0x1A,
	CloseSquareBracket = 0x1B,

	LeftControl = 0x1D,
	LeftAlt = 0x38,
	LeftShift = 0x2A,
	RightShift = 0x36,

	SemiColon = 0x27,
	SingleQuote = 0x28,
	BackTick = 0x29,
	Comma = 0x33,
	Period = 0x34,
	Slash = 0x35,
	BackSlash = 0x2B,

	F1 = 0x3B,
	F2 = 0x3C,
	F3 = 0x3D,
	F4 = 0x3E,
	F5 = 0x3F,
	F6 = 0x40,
	F7 = 0x41,
	F8 = 0x42,
	F9 = 0x43,
	F10 = 0x44,
	F11 = 0x57,
	F12 = 0x58,

	CapsLock = 0x3A,
	NumLock = 0x45,
	ScrollLock = 0x46,

	Keypad7 = 0x47,
	Keypad8 = 0x48,
	Keypad9 = 0x49,
	KeypadMinus = 0x4A,
	Keypad4 = 0x4B,
	Keypad5 = 0x4C,
	Keypad6 = 0x4D,
	KeypadPlus = 0x4E,
	Keypad1 = 0x4F,
	Keypad2 = 0x50,
	Keypad3 = 0x51,
	Keypad0 = 0x52,
	KeypadPeriod = 0x53,
	KeypadAsterisk = 0x37,

	Minus = 0x0C,
	Equals = 0x0D,

	Escape = 0x01,
	Backspace = 0xE,
	Tab = 0x0F,
	Space = 0x39,
	Enter = 0x1C,
	
	PrevTrack = 0x60,
	NextTrack,
	KeypadEnter,
	RightControl,
	Mute,
	Calculator,
	Play,
	Stop,
	VolumeDown,
	VolumeUp,
	WWWHome,
	KeypadSlash,
	RightAlt,
	Home,
	CurserUp,
	PageUp,
	CurserLeft,
	CurserRight,
	End,
	CurserDown,
	PageDown,
	Insert,
	Delete,
	LeftGUI,
	RightGUI,
	Apps,
	Power,
	Sleep,
	Wake,
	WWWSearch,
	WWWFavorites,
	WWWRefresh,
	WWWStop,
	WWWForward,
	WWWBack,
	MyComputer,
	Email,
	MediaSelect,
	PrintScreen,
	Pause
};

enum class KeyEventType {
    Pressed = 0,
    Released = 1
};

enum class KeyboardStateFlags {
    CapsLock = 1,
    ScrollLock = 2,
    NumLock = 4
};

typedef struct KeyEvent {
    KeyCode key;
    KeyEventType type;
    uint_8 state;
    bool pressedKeysKeymap[NUMBER_OF_KEYCODES];
} KeyEvent;

void initKeyboardDriver();

KeyEvent readKey();
uint_8 readChar();

uint_8 keyEventToAscii(const KeyEvent *event);