#include <ultra64.h>

extern u64 osClockRate;
extern OSTimer D_8005A498;
extern OSMesgQueue __osEepromTimerQ;
extern OSMesg __osEepromTimerMsg;

extern s32 func_80044890(s32, u8, s32);

s32 func_80039E20(s32 arg0, u8 arg1, s32 arg2, s32 arg3) {
    s32 RetValue = 0;
    
    if(arg1 >= 0x41) {
        return -1;
    }    

    while(arg3 > 0) {
        RetValue = func_80044890(arg0, arg1, arg2);
        if (RetValue != 0) {
            return RetValue;
        }

        arg3 -= 8;
        arg1 += 1;
        arg2 += 8;

        osSetTimer(&D_8005A498, (0x2EE0 * osClockRate) / 0xF4240, 0, &__osEepromTimerQ, &__osEepromTimerMsg);
        osRecvMesg(&__osEepromTimerQ, 0, 1);            
    }

    return RetValue;
}