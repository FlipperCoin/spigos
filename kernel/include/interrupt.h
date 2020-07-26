#include <types.h>
#include <idt.h>

typedef struct interrupt_frame {
    uint_32 eip;
    uint_32 cs;
    uint_32 eflags;    
} interrupt_frame;

void registerInterrupt(uint_8 interrupt, void (*isr)(interrupt_frame*), Gate type, uint_8 dpl = 0);
void enableInterrupts();
void disableInterrupts();