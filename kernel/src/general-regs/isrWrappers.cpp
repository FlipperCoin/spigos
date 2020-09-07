#include <interrupt.h>

extern void (*registeredIsrs[IDT_ENTRIES_COUNT])(interrupt_frame*);

// NOTE: leaving end of interrupt signal to actual isrs, 
// which might be problematic because it postpones iret.

__attribute__((interrupt))
void
isr0(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[0];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr1(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[1];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr2(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[2];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr3(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[3];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr4(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[4];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr5(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[5];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr6(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[6];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr7(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[7];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr8(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[8];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr9(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[9];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr10(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[10];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr11(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[11];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr12(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[12];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr13(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[13];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr14(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[14];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr15(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[15];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr16(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[16];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr17(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[17];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr18(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[18];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr19(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[19];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr20(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[20];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr21(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[21];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr22(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[22];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr23(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[23];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr24(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[24];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr25(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[25];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr26(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[26];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr27(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[27];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr28(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[28];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr29(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[29];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr30(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[30];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr31(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[31];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr32(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[32];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr33(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[33];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr34(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[34];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr35(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[35];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr36(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[36];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr37(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[37];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr38(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[38];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr39(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[39];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr40(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[40];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr41(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[41];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr42(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[42];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr43(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[43];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr44(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[44];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr45(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[45];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr46(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[46];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr47(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[47];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr48(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[48];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr49(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[49];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr50(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[50];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr51(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[51];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr52(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[52];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr53(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[53];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr54(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[54];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr55(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[55];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr56(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[56];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr57(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[57];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr58(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[58];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr59(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[59];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr60(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[60];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr61(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[61];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr62(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[62];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr63(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[63];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr64(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[64];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr65(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[65];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr66(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[66];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr67(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[67];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr68(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[68];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr69(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[69];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr70(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[70];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr71(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[71];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr72(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[72];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr73(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[73];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr74(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[74];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr75(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[75];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr76(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[76];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr77(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[77];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr78(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[78];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr79(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[79];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr80(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[80];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr81(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[81];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr82(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[82];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr83(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[83];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr84(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[84];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr85(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[85];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr86(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[86];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr87(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[87];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr88(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[88];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr89(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[89];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr90(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[90];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr91(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[91];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr92(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[92];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr93(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[93];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr94(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[94];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr95(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[95];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr96(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[96];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr97(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[97];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr98(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[98];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr99(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[99];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr100(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[100];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr101(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[101];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr102(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[102];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr103(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[103];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr104(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[104];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr105(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[105];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr106(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[106];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr107(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[107];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr108(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[108];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr109(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[109];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr110(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[110];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr111(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[111];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr112(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[112];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr113(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[113];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr114(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[114];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr115(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[115];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr116(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[116];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr117(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[117];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr118(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[118];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr119(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[119];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr120(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[120];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr121(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[121];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr122(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[122];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr123(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[123];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr124(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[124];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr125(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[125];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr126(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[126];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr127(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[127];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr128(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[128];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr129(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[129];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr130(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[130];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr131(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[131];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr132(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[132];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr133(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[133];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr134(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[134];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr135(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[135];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr136(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[136];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr137(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[137];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr138(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[138];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr139(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[139];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr140(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[140];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr141(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[141];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr142(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[142];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr143(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[143];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr144(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[144];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr145(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[145];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr146(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[146];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr147(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[147];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr148(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[148];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr149(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[149];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr150(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[150];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr151(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[151];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr152(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[152];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr153(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[153];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr154(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[154];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr155(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[155];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr156(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[156];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr157(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[157];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr158(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[158];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr159(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[159];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr160(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[160];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr161(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[161];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr162(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[162];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr163(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[163];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr164(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[164];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr165(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[165];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr166(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[166];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr167(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[167];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr168(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[168];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr169(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[169];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr170(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[170];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr171(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[171];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr172(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[172];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr173(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[173];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr174(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[174];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr175(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[175];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr176(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[176];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr177(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[177];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr178(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[178];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr179(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[179];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr180(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[180];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr181(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[181];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr182(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[182];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr183(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[183];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr184(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[184];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr185(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[185];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr186(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[186];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr187(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[187];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr188(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[188];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr189(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[189];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr190(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[190];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr191(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[191];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr192(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[192];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr193(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[193];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr194(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[194];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr195(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[195];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr196(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[196];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr197(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[197];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr198(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[198];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr199(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[199];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr200(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[200];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr201(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[201];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr202(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[202];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr203(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[203];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr204(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[204];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr205(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[205];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr206(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[206];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr207(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[207];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr208(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[208];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr209(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[209];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr210(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[210];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr211(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[211];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr212(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[212];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr213(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[213];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr214(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[214];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr215(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[215];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr216(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[216];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr217(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[217];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr218(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[218];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr219(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[219];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr220(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[220];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr221(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[221];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr222(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[222];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr223(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[223];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr224(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[224];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr225(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[225];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr226(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[226];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr227(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[227];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr228(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[228];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr229(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[229];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr230(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[230];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr231(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[231];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr232(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[232];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr233(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[233];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr234(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[234];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr235(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[235];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr236(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[236];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr237(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[237];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr238(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[238];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr239(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[239];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr240(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[240];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr241(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[241];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr242(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[242];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr243(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[243];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr244(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[244];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr245(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[245];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr246(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[246];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr247(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[247];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr248(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[248];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr249(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[249];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr250(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[250];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr251(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[251];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr252(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[252];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr253(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[253];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr254(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[254];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr255(interrupt_frame *frame) {
    void (*isr)(interrupt_frame*) = registeredIsrs[255];
    if (isr != nullptr) isr(frame);
}

void (*isrWrappers[IDT_ENTRIES_COUNT])(interrupt_frame*) = {
    isr0,
    isr1,
    isr2,
    isr3,
    isr4,
    isr5,
    isr6,
    isr7,
    isr8,
    isr9,
    isr10,
    isr11,
    isr12,
    isr13,
    isr14,
    isr15,
    isr16,
    isr17,
    isr18,
    isr19,
    isr20,
    isr21,
    isr22,
    isr23,
    isr24,
    isr25,
    isr26,
    isr27,
    isr28,
    isr29,
    isr30,
    isr31,
    isr32,
    isr33,
    isr34,
    isr35,
    isr36,
    isr37,
    isr38,
    isr39,
    isr40,
    isr41,
    isr42,
    isr43,
    isr44,
    isr45,
    isr46,
    isr47,
    isr48,
    isr49,
    isr50,
    isr51,
    isr52,
    isr53,
    isr54,
    isr55,
    isr56,
    isr57,
    isr58,
    isr59,
    isr60,
    isr61,
    isr62,
    isr63,
    isr64,
    isr65,
    isr66,
    isr67,
    isr68,
    isr69,
    isr70,
    isr71,
    isr72,
    isr73,
    isr74,
    isr75,
    isr76,
    isr77,
    isr78,
    isr79,
    isr80,
    isr81,
    isr82,
    isr83,
    isr84,
    isr85,
    isr86,
    isr87,
    isr88,
    isr89,
    isr90,
    isr91,
    isr92,
    isr93,
    isr94,
    isr95,
    isr96,
    isr97,
    isr98,
    isr99,
    isr100,
    isr101,
    isr102,
    isr103,
    isr104,
    isr105,
    isr106,
    isr107,
    isr108,
    isr109,
    isr110,
    isr111,
    isr112,
    isr113,
    isr114,
    isr115,
    isr116,
    isr117,
    isr118,
    isr119,
    isr120,
    isr121,
    isr122,
    isr123,
    isr124,
    isr125,
    isr126,
    isr127,
    isr128,
    isr129,
    isr130,
    isr131,
    isr132,
    isr133,
    isr134,
    isr135,
    isr136,
    isr137,
    isr138,
    isr139,
    isr140,
    isr141,
    isr142,
    isr143,
    isr144,
    isr145,
    isr146,
    isr147,
    isr148,
    isr149,
    isr150,
    isr151,
    isr152,
    isr153,
    isr154,
    isr155,
    isr156,
    isr157,
    isr158,
    isr159,
    isr160,
    isr161,
    isr162,
    isr163,
    isr164,
    isr165,
    isr166,
    isr167,
    isr168,
    isr169,
    isr170,
    isr171,
    isr172,
    isr173,
    isr174,
    isr175,
    isr176,
    isr177,
    isr178,
    isr179,
    isr180,
    isr181,
    isr182,
    isr183,
    isr184,
    isr185,
    isr186,
    isr187,
    isr188,
    isr189,
    isr190,
    isr191,
    isr192,
    isr193,
    isr194,
    isr195,
    isr196,
    isr197,
    isr198,
    isr199,
    isr200,
    isr201,
    isr202,
    isr203,
    isr204,
    isr205,
    isr206,
    isr207,
    isr208,
    isr209,
    isr210,
    isr211,
    isr212,
    isr213,
    isr214,
    isr215,
    isr216,
    isr217,
    isr218,
    isr219,
    isr220,
    isr221,
    isr222,
    isr223,
    isr224,
    isr225,
    isr226,
    isr227,
    isr228,
    isr229,
    isr230,
    isr231,
    isr232,
    isr233,
    isr234,
    isr235,
    isr236,
    isr237,
    isr238,
    isr239,
    isr240,
    isr241,
    isr242,
    isr243,
    isr244,
    isr245,
    isr246,
    isr247,
    isr248,
    isr249,
    isr250,
    isr251,
    isr252,
    isr253,
    isr254,
    isr255
};