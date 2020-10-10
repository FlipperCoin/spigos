#include <tss.h>

extern "C" void tss_flush(uint_32 tssDescIndex);

void flushTSS(uint_32 tssDescIndex) {
    tss_flush(tssDescIndex);
}