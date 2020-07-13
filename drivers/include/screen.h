#pragma once

#define VIDEO_ADDRESS 0xb8000

#define MAX_ROWS 25
#define MAX_COLS 80
#define MAX_VID_OFFSET MAX_COLS * MAX_ROWS - 1

#define WHITE_ON_BLACK 0x0f

#define REG_SCREEN_ADDR 0x3D4
#define REG_SCREEN_DATA 0x3D5

#define H_CURSOR_OFF 0x0E
#define L_CURSOR_OFF 0x0F

void println(char const*);
void println();
void print(char const*);
void print(char c);

short getCurser();
void setCurser(short);

void clearScreen();