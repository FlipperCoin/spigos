#include <interrupt.h>
#include <screen.h>
#include <cr.h>

__attribute__((interrupt))
void
divByZero(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
singleStep(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
NMI(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
breakpoint(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
overflow(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
bounds(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
invalidOpcode(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
coprocessorNotAvailable(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
doubleFault(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
coprocessorSegmentOverrun(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
invalidTaskStateSegment(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
segmentNotPresent(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
stackFault(interrupt_frame *frame){println("exception");while(true){}}

// TODO: remove err from stack (poped)

__attribute__((interrupt))
void
generalProtectionFault(interrupt_frame *frame, uint_32 error){println("exception");while(true){}}

__attribute__((interrupt))
void
pageFault(interrupt_frame *frame, uint_32 error) {
    
    print("Page Fault. Error: ");
    printHex(error);
    print(", Virtual Address: ");
    printHex(getCR2());
    println();
    
    while(true){}
}

__attribute__((interrupt))
void
reserved(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
mathFault(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
alignmentCheck(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
machineCheck(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
SIMDFloatingPointException(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
virtualizationException(interrupt_frame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
controlProtectionException(interrupt_frame *frame){println("exception");while(true){}}

void registerExceptions() {
    registerRawInterrupt(0x00, divByZero, Gate::trap);
    registerRawInterrupt(0x01, singleStep, Gate::trap);
    registerRawInterrupt(0x02, NMI, Gate::trap);
    registerRawInterrupt(0x03, breakpoint, Gate::trap);
    registerRawInterrupt(0x04, overflow, Gate::trap);
    registerRawInterrupt(0x05, bounds, Gate::trap);
    registerRawInterrupt(0x06, invalidOpcode, Gate::trap);
    registerRawInterrupt(0x07, coprocessorNotAvailable, Gate::trap);
    registerRawInterrupt(0x08, doubleFault, Gate::trap);
    registerRawInterrupt(0x09, coprocessorSegmentOverrun, Gate::trap);
    registerRawInterrupt(0x0A, invalidTaskStateSegment, Gate::trap);
    registerRawInterrupt(0x0B, segmentNotPresent, Gate::trap);
    registerRawInterrupt(0x0C, stackFault, Gate::trap);
    registerRawInterrupt(0x0D, (void(*)(interrupt_frame*))generalProtectionFault, Gate::trap);
    registerRawInterrupt(0x0E, (void(*)(interrupt_frame*))pageFault, Gate::trap);
    registerRawInterrupt(0x0F, reserved, Gate::trap);
    registerRawInterrupt(0x10, mathFault, Gate::trap);
    registerRawInterrupt(0x11, alignmentCheck, Gate::trap);
    registerRawInterrupt(0x12, machineCheck, Gate::trap);
    registerRawInterrupt(0x13, SIMDFloatingPointException, Gate::trap);
    registerRawInterrupt(0x14, virtualizationException, Gate::trap);
    registerRawInterrupt(0x15, controlProtectionException, Gate::trap);
}