#include <interrupt.h>

extern void (*registeredIsrs[IDT_ENTRIES_COUNT])(InterruptFrame*);

// NOTE: leaving end of interrupt signal to actual isrs, 
// which might be problematic because it postpones iret.

__attribute__((interrupt))
void
isr0(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[0];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr1(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[1];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr2(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[2];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr3(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[3];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr4(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[4];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr5(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[5];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr6(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[6];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr7(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[7];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr8(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[8];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr9(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[9];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr10(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[10];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr11(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[11];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr12(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[12];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr13(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[13];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr14(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[14];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr15(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[15];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr16(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[16];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr17(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[17];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr18(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[18];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr19(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[19];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr20(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[20];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr21(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[21];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr22(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[22];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr23(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[23];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr24(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[24];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr25(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[25];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr26(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[26];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr27(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[27];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr28(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[28];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr29(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[29];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr30(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[30];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr31(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[31];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr32(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[32];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr33(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[33];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr34(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[34];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr35(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[35];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr36(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[36];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr37(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[37];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr38(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[38];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr39(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[39];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr40(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[40];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr41(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[41];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr42(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[42];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr43(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[43];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr44(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[44];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr45(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[45];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr46(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[46];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr47(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[47];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr48(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[48];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr49(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[49];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr50(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[50];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr51(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[51];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr52(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[52];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr53(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[53];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr54(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[54];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr55(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[55];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr56(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[56];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr57(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[57];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr58(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[58];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr59(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[59];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr60(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[60];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr61(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[61];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr62(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[62];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr63(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[63];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr64(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[64];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr65(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[65];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr66(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[66];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr67(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[67];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr68(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[68];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr69(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[69];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr70(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[70];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr71(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[71];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr72(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[72];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr73(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[73];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr74(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[74];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr75(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[75];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr76(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[76];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr77(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[77];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr78(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[78];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr79(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[79];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr80(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[80];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr81(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[81];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr82(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[82];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr83(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[83];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr84(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[84];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr85(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[85];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr86(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[86];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr87(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[87];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr88(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[88];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr89(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[89];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr90(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[90];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr91(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[91];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr92(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[92];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr93(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[93];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr94(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[94];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr95(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[95];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr96(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[96];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr97(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[97];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr98(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[98];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr99(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[99];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr100(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[100];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr101(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[101];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr102(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[102];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr103(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[103];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr104(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[104];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr105(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[105];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr106(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[106];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr107(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[107];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr108(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[108];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr109(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[109];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr110(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[110];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr111(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[111];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr112(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[112];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr113(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[113];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr114(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[114];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr115(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[115];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr116(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[116];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr117(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[117];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr118(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[118];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr119(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[119];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr120(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[120];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr121(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[121];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr122(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[122];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr123(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[123];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr124(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[124];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr125(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[125];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr126(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[126];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr127(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[127];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr128(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[128];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr129(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[129];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr130(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[130];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr131(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[131];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr132(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[132];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr133(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[133];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr134(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[134];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr135(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[135];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr136(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[136];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr137(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[137];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr138(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[138];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr139(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[139];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr140(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[140];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr141(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[141];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr142(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[142];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr143(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[143];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr144(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[144];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr145(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[145];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr146(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[146];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr147(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[147];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr148(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[148];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr149(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[149];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr150(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[150];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr151(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[151];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr152(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[152];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr153(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[153];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr154(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[154];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr155(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[155];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr156(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[156];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr157(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[157];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr158(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[158];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr159(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[159];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr160(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[160];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr161(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[161];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr162(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[162];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr163(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[163];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr164(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[164];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr165(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[165];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr166(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[166];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr167(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[167];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr168(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[168];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr169(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[169];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr170(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[170];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr171(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[171];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr172(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[172];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr173(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[173];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr174(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[174];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr175(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[175];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr176(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[176];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr177(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[177];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr178(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[178];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr179(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[179];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr180(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[180];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr181(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[181];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr182(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[182];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr183(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[183];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr184(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[184];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr185(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[185];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr186(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[186];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr187(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[187];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr188(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[188];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr189(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[189];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr190(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[190];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr191(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[191];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr192(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[192];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr193(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[193];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr194(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[194];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr195(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[195];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr196(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[196];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr197(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[197];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr198(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[198];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr199(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[199];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr200(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[200];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr201(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[201];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr202(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[202];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr203(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[203];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr204(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[204];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr205(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[205];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr206(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[206];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr207(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[207];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr208(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[208];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr209(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[209];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr210(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[210];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr211(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[211];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr212(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[212];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr213(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[213];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr214(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[214];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr215(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[215];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr216(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[216];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr217(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[217];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr218(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[218];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr219(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[219];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr220(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[220];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr221(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[221];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr222(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[222];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr223(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[223];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr224(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[224];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr225(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[225];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr226(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[226];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr227(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[227];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr228(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[228];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr229(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[229];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr230(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[230];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr231(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[231];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr232(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[232];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr233(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[233];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr234(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[234];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr235(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[235];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr236(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[236];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr237(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[237];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr238(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[238];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr239(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[239];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr240(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[240];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr241(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[241];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr242(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[242];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr243(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[243];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr244(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[244];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr245(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[245];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr246(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[246];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr247(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[247];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr248(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[248];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr249(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[249];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr250(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[250];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr251(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[251];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr252(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[252];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr253(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[253];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr254(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[254];
    if (isr != nullptr) isr(frame);
}

__attribute__((interrupt))
void
isr255(InterruptFrame *frame) {
    void (*isr)(InterruptFrame*) = registeredIsrs[255];
    if (isr != nullptr) isr(frame);
}

void (*isrWrappers[IDT_ENTRIES_COUNT])(InterruptFrame*) = {
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