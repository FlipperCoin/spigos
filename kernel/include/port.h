#pragma once

#include <types.h>

uint_8 portByteIn(uint_16 port);
void portByteOut(uint_16 port, uint_8 data);

uint_16 portWordIn(uint_16 port);
void portWordOut(uint_16 port, uint_16 data);