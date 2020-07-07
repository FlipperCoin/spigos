#include "print.cpp"

extern "C" int KernelMain() {
    print("Hello Kernel!");

    return 0;
}