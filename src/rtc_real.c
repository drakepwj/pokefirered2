#include "global.h"

// mGBA BIOS extensions
// SWI 0x0B: GetTime
// SWI 0x0C: GetDate

// Registers for SWI calls
//#define REG_R0 (*(volatile u32 *)0x03007FF0)
//#define REG_R1 (*(volatile u32 *)0x03007FF4)
//#define REG_R2 (*(volatile u32 *)0x03007FF8)
//#define REG_R3 (*(volatile u32 *)0x03007FFC)

//static void MgbaGetTime(int *hour, int *minute, int *second)
//{
//    __asm__ volatile("swi 0x0B"); // mGBA GetTime
//
//    *hour   = REG_R0;
//    *minute = REG_R1;
//    *second = REG_R2;
//}

//static void MgbaGetDate(int *year, int *month, int *day, int *weekday)
//{
//    __asm__ volatile("swi 0x0C"); // mGBA GetDate
//
//    *year    = REG_R0; // 0–99
//    *month   = REG_R1; // 1–12
//    *day     = REG_R2; // 1–31
//    *weekday = REG_R3; // 0–6
//}
//
// Your public API
//int GetCurrentHour(void)
//{
//    int hour, minute, second;
//    MgbaGetTime(&hour, &minute, &second);
//    return hour;
//}

int GetCurrentHour(void)
{
    return 3;
}
