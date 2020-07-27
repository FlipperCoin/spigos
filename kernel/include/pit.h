#include <types.h>

uint_32 getTicksSinceBoot();
double getFrequency();
void initTimer();
int initTimer(double frequency);
uint_32 getMsSinceBoot();
uint_32 getMs(uint_32 ticks);
void sleep(uint_32 ms);
void sleepUntil(uint_32 time);