#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include "ultra64.h"

// 3490.c
s32 func_80002890(struct UnkStruct80001CF0* arg0, s32* arg1, s32* arg2, s32 arg3);

// 17930.c
s32 func_80016DD4();
s32 func_80016E84();
void PlayTrack_WithVolLoop(s16 trackID, s8 vol, s8 loop);
void func_80017FD8(char* str);
void InitControllers();
void func_8001994C(void);
void func_8001E80C(void);
void func_8001D244(char arg0, char arg1, char arg2, char arg3);
void func_8001D4D0();
void func_8001D638(s32, s32, s32, s32);
void func_8001E954(s32*);
void func_8001E98C(s32, void*, void*);
void func_8001ECB8(void);
void func_80019C84(void);
void func_80019D2C(void);
void func_8001A258(void);
void func_8001D284(void);
void func_8001D2C0(void);
s32 func_8001D1D4(void);
s32 func_8001ECA0();
s32 func_8001D1F4();
s32 func_8001D440();
s32 func_8001EE64();
void func_8001D9E4(void* arg0);
s32 func_8001EBE8();
s32 func_8001EC1C();
s32 func_8001EC50();
s32 func_8001EC84();

// 1FAB0.c
void func_8001F38C(struct UnkStruct_8001EFD0*, s32);
void func_8001F9DC();
void func_8001FAD4();
void func_800200D8(void);
void func_8002021C(void);
void func_80020360(void);
void func_80020420(void);
s32 func_80021158();

// 25810.c
s32 func_80025E28();

// 2BF00.c
s32 func_8002F738();

#define FIRST_CODE_FUNCTION Demo_RenderTextBG

// 4DFF0.c
void Demo_RenderTextBG(void);
void Demo_SetupTextPal(void);
void Demo_Start(s32);

// 71AA0.c
s32 func_80083180(s32);

// EFF30.c
u32 func_800FE898();

// isprint.c (enhancement)
void osSyncPrintf(const char* fmt, ...);

#endif // _FUNCTIONS_H_
