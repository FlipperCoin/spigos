#include <interrupt.h>

void divByZero(InterruptFrame *frame);
void singleStep(InterruptFrame *frame);
void NMI(InterruptFrame *frame);
void breakpoint(InterruptFrame *frame);
void overflow(InterruptFrame *frame);
void bounds(InterruptFrame *frame);
void invalidOpcode(InterruptFrame *frame);
void coprocessorNotAvailable(InterruptFrame *frame);
void doubleFault(InterruptFrame *frame);
void coprocessorSegmentOverrun(InterruptFrame *frame);
void invalidTaskStateSegment(InterruptFrame *frame);
void segmentNotPresent(InterruptFrame *frame);
void stackFault(InterruptFrame *frame);
void generalProtectionFault(InterruptFrame *frame);
void pageFault(InterruptFrame *frame);
void reserved(InterruptFrame *frame);
void mathFault(InterruptFrame *frame);
void alignmentCheck(InterruptFrame *frame);
void machineCheck(InterruptFrame *frame);
void SIMDFloatingPointException(InterruptFrame *frame);
void virtualizationException(InterruptFrame *frame);
void controlProtectionException(InterruptFrame *frame);

void registerExceptions();