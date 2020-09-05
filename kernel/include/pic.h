#define PIC1		0x20		/* IO base address for master PIC */
#define PIC2		0xA0		/* IO base address for slave PIC */
#define PIC1_COMMAND	PIC1
#define PIC1_DATA	(PIC1+1)
#define PIC2_COMMAND	PIC2
#define PIC2_DATA	(PIC2+1)

#define ICW1 0x10
#define ICW4 0x01

#define OCW2 0x00
#define OCW3 0x08

enum ICW1Flags {
    ICW4Present = 0x01,
    Single = 0x02, // Disabled = Cascade Mode
    LevelTriggered = 0x08 // Disabled = Edge Triggered
};

enum ICW4Flags {
    AutomaticEOI = 0x02,
    FullyNested = 0x10
};

enum OCW2Flags {
    EOI = 0x20,
    SpecificCommand = 0x40,
    RotatePriorities = 0x80
};

int initPIC();
void sendEOI(bool isSlave = false);
int setIRQMask(uint_8 line);
int clearIRQMask(uint_8 line);
uint_16 getIRR();
uint_16 getISR();