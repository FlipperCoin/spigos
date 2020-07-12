#include <screen.h>
#include <port.h>
#include <format.h>

 
extern "C" int KernelMain() {
    
    portByteOut(REG_SCREEN_ADDR, 0x0B);
    unsigned char skew = portByteIn(REG_SCREEN_DATA);
    skew &= 0b10011111;
    portByteOut(REG_SCREEN_DATA, skew);
    
    portByteOut(REG_SCREEN_ADDR, H_CURSOR_OFF);
    portByteOut(REG_SCREEN_DATA, 0);
    portByteOut(REG_SCREEN_ADDR, L_CURSOR_OFF);
    portByteOut(REG_SCREEN_DATA, 0);
    
    // portByteOut(REG_SCREEN_ADDR, H_CURSOR_OFF);
    // unsigned char hCursorOffset = portByteIn(REG_SCREEN_DATA);
    // portByteOut(REG_SCREEN_ADDR, L_CURSOR_OFF);
    // unsigned char lCursorOffset = portByteIn(REG_SCREEN_DATA);

    // setCurser(80);
    // char buf[10];
    // itoh(hCursorOffset, buf, 10);
    // print(buf);
    // itoh(lCursorOffset, buf, 10);
    // print(buf);

    return 0;
}