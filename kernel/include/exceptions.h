#include <interrupt.h>

void divByZero(interrupt_frame *frame);
void singleStep(interrupt_frame *frame);
void NMI(interrupt_frame *frame);
void breakpoint(interrupt_frame *frame);
void overflow(interrupt_frame *frame);
void bounds(interrupt_frame *frame);
void invalidOpcode(interrupt_frame *frame);
void coprocessorNotAvailable(interrupt_frame *frame);
void doubleFault(interrupt_frame *frame);
void coprocessorSegmentOverrun(interrupt_frame *frame);
void invalidTaskStateSegment(interrupt_frame *frame);
void segmentNotPresent(interrupt_frame *frame);
void stackFault(interrupt_frame *frame);
void generalProtectionFault(interrupt_frame *frame);
void pageFault(interrupt_frame *frame);
void reserved(interrupt_frame *frame);
void mathFault(interrupt_frame *frame);
void alignmentCheck(interrupt_frame *frame);
void machineCheck(interrupt_frame *frame);
void SIMDFloatingPointException(interrupt_frame *frame);
void virtualizationException(interrupt_frame *frame);
void controlProtectionException(interrupt_frame *frame);

void registerExceptions();