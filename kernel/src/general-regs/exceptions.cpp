#include <interrupt.h>
#include <screen.h>
#include <cr.h>

__attribute__((interrupt))
void
divByZero(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
singleStep(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
NMI(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
breakpoint(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
overflow(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
bounds(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
invalidOpcode(InterruptFrame *frame) {
    print("Invalid Opcode. Instruction: ");
    printHex(frame->eip);
    println();
    while(true){}
}

__attribute__((interrupt))
void
coprocessorNotAvailable(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
doubleFault(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
coprocessorSegmentOverrun(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
invalidTaskStateSegment(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
segmentNotPresent(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
stackFault(InterruptFrame *frame){println("exception");while(true){}}

// TODO: remove err from stack (poped)

__attribute__((interrupt))
void
generalProtectionFault(InterruptFrame *frame, uint_32 error) { 
    print("General Protection Fault. Error (segment selector if none 0): ");
    printHex(error);
    print(", instruction: ");
    printHex(frame->eip);
    println();
    while(true){}
}

__attribute__((interrupt))
void
pageFault(InterruptFrame *frame, uint_32 error) {
    
    print("Page Fault. Error: ");
    printHex(error);
    print(", Virtual Address: ");
    printHex(getCR2());
    print(", Instruction: ");
    printHex(frame->eip);
    println();
    
    while(true){}
}

__attribute__((interrupt))
void
reserved(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
mathFault(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
alignmentCheck(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
machineCheck(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
SIMDFloatingPointException(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
virtualizationException(InterruptFrame *frame){println("exception");while(true){}}

__attribute__((interrupt))
void
controlProtectionException(InterruptFrame *frame){println("exception");while(true){}}

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
    registerRawInterrupt(0x0D, (void(*)(InterruptFrame*))generalProtectionFault, Gate::trap);
    registerRawInterrupt(0x0E, (void(*)(InterruptFrame*))pageFault, Gate::trap);
    registerRawInterrupt(0x0F, reserved, Gate::trap);
    registerRawInterrupt(0x10, mathFault, Gate::trap);
    registerRawInterrupt(0x11, alignmentCheck, Gate::trap);
    registerRawInterrupt(0x12, machineCheck, Gate::trap);
    registerRawInterrupt(0x13, SIMDFloatingPointException, Gate::trap);
    registerRawInterrupt(0x14, virtualizationException, Gate::trap);
    registerRawInterrupt(0x15, controlProtectionException, Gate::trap);
}