#include <interrupt.h>
#include <screen.h>
#include <pit.h>
#include <pic.h>
#include <port.h>
#include <tasks.h>

#define OSCILLATOR_FREQUENCY 1193181.0

#define MIN_FREQUENCY (OSCILLATOR_FREQUENCY / 0x10000)
#define MAX_FREQUENCY (OSCILLATOR_FREQUENCY / 1)

#define DEFAULT_PIT_DIVIDER 0x10000
#define DEFAULT_PIT_FREQUENCY (OSCILLATOR_FREQUENCY / DEFAULT_PIT_DIVIDER)

#define CHANNEL_0_DATA 0x40
#define MODE_COMMAND_REG 0x43

double frequency;
uint_32 totalTicks = 0;

double getFrequency() {
    return frequency;
} 

uint_32 getTicksSinceBoot() {
    return totalTicks;
}

uint_32 getMsSinceBoot() {
    return getMs(getTicksSinceBoot());
}

uint_32 getMs(uint_32 ticks) {
    return (ticks / frequency) * 1000;
}

void timerISR(interrupt_frame *frame) {
    totalTicks++;
    
    timeUpdate(getMsSinceBoot());

    sendEOI(false);
}

void setDivier(uint_16 divider) {
    // Channel 0, lobyte/hibyte, rate generator
    portByteOut(MODE_COMMAND_REG, 0b00110100);

    portByteOut(CHANNEL_0_DATA, divider && 0xFF);
    portByteOut(CHANNEL_0_DATA, divider >> 8);
}

int initTimer(double desiredFrequency) {
    if (desiredFrequency > MAX_FREQUENCY) return -1;
    if (desiredFrequency < MIN_FREQUENCY) return -1;

    uint_32 divider = OSCILLATOR_FREQUENCY / desiredFrequency;
    
    setDivier((uint_16)divider);

    registerInterrupt(0x20, timerISR, Gate::interrupt);
    
    double actualFrequency = OSCILLATOR_FREQUENCY / (double)divider;
    frequency = actualFrequency;

    return actualFrequency;
}

void initTimer() {
    initTimer(100); 
}