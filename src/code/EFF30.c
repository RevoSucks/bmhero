#include "common.h"

//STRUCTS

struct Light
{
    u8 LightData[8];
};

struct LightingStruct
{
    struct Light AmbientLight;
    struct Light DiffuseLight;
    s8 Direction[8];
};

struct PlayerStruct
{
    f32 PosX; //00
    f32 PosY; //04
    f32 PosZ; //08
    char Padding[0xC];
    f32 RotX;
    f32 RotY;
    f32 RotZ;
};

//FUNCTIONS
extern void func_8005F96C(u8, u8, u8);                           /* extern */
extern void func_8005F9EC(s8*, s8*); 
extern void func_8001E954(s32*);                                 /* extern */
extern void func_8001E98C(s32, s32*, s32*);                         /* extern */
extern void func_800175F0(s32, s32, s32, s32, s32);                 /* extern */
extern void func_8001994C();                                  /* extern */
extern s32 func_8001D1D4();                                /* extern */
extern void func_8001D2C0();                                  /* extern */
void func_800FDA10();                                  /* extern */
s32 func_800FDF98();                                /* extern */
void func_8005FA90();                                  /* extern */
void func_800FE9BC();                                  /* extern */
void func_800FEB6C();                                  /* extern */
void func_800FEE34();                                  /* extern */
void func_800FEFA0();                                  /* extern */
void func_800FF43C();                                  /* extern */
void func_800FF88C();                                  /* extern */
void func_800FFD30();                                  /* extern */
void func_800FFF40();                                  /* extern */

//RAM ADDRESSES
extern s8 D_80134334;
extern s8 D_80134340;
extern s8 D_8013435C;
extern s8 D_80134378;
extern s8 D_8013438C;
extern s8 D_801343A4;
extern s8 D_801343BC;
extern s8 D_801343CC;
extern s8 D_801343DC;
extern s8 D_801343F0;
extern s8 D_8016523F;
extern s8 D_80165240;
extern s8 D_8016E1B8;
extern u8 D_80177974;
extern s16 D_8016E3F4;
extern s16 D_80134730;
extern s16 D_80134734;
extern s16 D_80134738[];
extern f64 D_801346A0;
extern f64 D_801346A8;
extern u16 D_8016E290[];
extern f32 D_8016E158;
extern f32 D_8016E15C;
extern f32 D_8016E170;
extern s32 D_80134210;
extern s32 D_8013421C;
extern s32 D_80134220;

extern s32 D_8016E244;
extern u16 D_8016E384;
extern s32 D_801765F4;
extern u8 D_8017793A;
extern u8 D_8017793E;
extern u8 D_80177940;
extern s16 D_80177944;
extern s16 D_80177948;
extern f32 D_801779C8;
extern s32 D_80134218;
extern u16 D_8016E2D0[];
extern u16 D_8016E2F0[];
extern s32 D_80134FD0;
extern u16 D_8016E2B0[];
extern struct LightingStruct D_8004A5B8[];

extern s16 D_80134C14;
extern struct PlayerStruct D_80154150[];
extern f32 D_8016E140;
extern f32 D_8016E144;
extern f32 D_8016E148;
extern f32 D_8016E14C;
extern f32 D_8016E150;
extern f32 D_8016E154;
extern f32 D_8016E160;

extern u16 D_8016E3A0;
extern u8 D_80177932;
extern u8 D_80177934;
extern u8 D_80177938;

//ROM ADDRESSES
extern u8 DebugCircle[];
extern u8 DebugSquare[];

void func_800FDA10(void) {
    f32 sp4;

    if (D_8016E290[0] & 2) {
        sp4 = (f32) ((f64) D_8016E15C + 2.0);
        D_8016E15C = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 1) {
        sp4 = (f32) ((f64) D_8016E15C + D_801346A0);
        D_8016E15C = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 8) {
        sp4 = (f32) ((f64) D_8016E158 + 2.0);
        D_8016E158 = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 4) {
        sp4 = (f32) ((f64) D_8016E158 + D_801346A8);
        D_8016E158 = sp4 - (f32) (((s32) sp4 / 360) * 0x168);
    }
    if (D_8016E290[0] & 0x400) {
        D_8016E170 += 10.0f;
    }
    if (D_8016E290[0] & 0x800) {
        D_8016E170 -= 10.0f;
        if (D_8016E170 < 200.0f) {
            D_8016E170 = 200.0f;
        }
    }
}

void func_800FDD48(void) {
    func_8005F96C(0xFFU, 0xFFU, 0xFFU);
    sprintf(&D_8016E1B8, "%8d", D_8016E244);
    func_8005F9EC((s8* )0xD0, (s8* )0xD8);
    sprintf(&D_8016E1B8, "[BOMBERMAN ACTION MENU]");
    func_8005F9EC((s8* )0x20, (s8* )0x10);
    sprintf(&D_8016E1B8, "   GAME START = %d", D_80134228);
    func_8005F9EC((s8* )0x20, (s8* )0x20);
    sprintf(&D_8016E1B8, "   MAP NUMBER  = 0x%X", D_8016E428);
    func_8005F9EC((s8* )0x20, (s8* )0x30);
    sprintf(&D_8016E1B8, "   MAP TEST    = 0x%X", D_8016E428);
    func_8005F9EC((s8* )0x20, (s8* )0x40);
    sprintf(&D_8016E1B8, "   CAMERA TYPE = %d", D_801765EC);
    func_8005F9EC((s8* )0x20, (s8* )0x50);
    sprintf(&D_8016E1B8, "   TITLE TEST");
    func_8005F9EC((s8* )0x20, (s8* )0x60);
    sprintf(&D_8016E1B8, "   ENTRY EDIT = 0x%X", D_8016E428);
    func_8005F9EC((s8* )0x20, (s8* )0x70);
    sprintf(&D_8016E1B8, "   MUSIC NUMBER = %d", D_8013421C);
    func_8005F9EC((s8* )0x20, (s8* )0x80);
    sprintf(&D_8016E1B8, "   SOUND NUMBER = %d", D_80134220);
    func_8005F9EC((s8* )0x20, (s8* )0x90);
    sprintf(&D_8016E1B8, "   DEMO = %d", D_80134224);
    func_8005F9EC((s8* )0x20, (s8* )0xA0);
    sprintf(&D_8016E1B8, "   SHOCK TEST");
    func_8005F9EC((s8* )0x20, (s8* )0xB0);
    sprintf(&D_8016E1B8, "=");
    func_8005F9EC((s8* )0x28, (D_80134210 * 0x10) + 0x20);
    sprintf(&D_8016E1B8, "MASTER ----- DEBUG");
    func_8005F9EC((s8* )0x98, (s8* )0xC0);
    func_8005FA90();
}

s32 func_800FDF98(void) {
    s32 sp4;
    s32 var_t9;

    if (D_80134218 != 0) {
        D_80134218 -= 1;
    }
    sp4 = 0;
    if (D_80134218 == 0) {
        if (D_8016E2F0[0] & 0x100) {
            D_80134218 = 0xF;
            sp4 = 1;
        } else {
            if (D_8016E2F0[0] & 0x200) {
                D_80134218 = 0xF;
                sp4 = -1;
            }
            else if (D_8016E2F0[0] & 0x800) {
                D_80134218 = 0xF;
                sp4 = 2;
            } 
            else if (D_8016E2F0[0] & 0x400) {
                D_80134218 = 0xF;
                sp4 = -2;
            }
        }
    } else if (D_8016E2D0[0] & 0x100) {
        if (D_80134218 == 1) {
            sp4 = 1;
            D_80134218 = 2;
        }
    } else if (D_8016E2D0[0] & 0x200) {
        if (D_80134218 == 1) {
            sp4 = -1;
            D_80134218 = 2;
        }
    } else if (D_8016E2D0[0] & 0x800) {
        if (D_80134218 == 1) {
            sp4 = 2;
            D_80134218 = 2;
        }
    } else if (D_8016E2D0[0] & 0x400) {
        if (D_80134218 == 1) {
            sp4 = -2;
            D_80134218 = 2;
        }
    } else {
        D_80134218 = 0;
    }
    return sp4;
}

void func_800FE204(void) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;

    if (D_8016E2B0[0] & 0x8000) {
        switch(D_80134210)
        {
            case 6:
            {
                if (D_8013421C != 0) {
                    func_80016F38(D_8013421C, -1, 0);
                } else {
                    func_80016F38(-1, -1, 0);
                }            
                break;
            }
            case 7:
            {
                func_800175F0(-1, 0, D_80134220, -1, 0);
                break;
            }
            default:
            {
                func_8001D2C0();
                D_80134FD0 = D_80134210;
                break;
            }
        }
        if (func_8001D1D4() == 1) 
        {
            return;
        }
        if (func_8001D1D4() == 2) 
        {
            D_80165264 = 1;
        }
        sp30 = func_800FDF98();
        if (sp30 == 2) {
            if (--D_80134210 < 0) {
                D_80134210 = 9;
            }
        }   
        if (sp30 == -2) {
            if (++D_80134210 >= 0xA) {
                D_80134210 = 0;
            }
        }
        switch(D_80134210)
        {
            case 0:
            {
                if (sp30 == 1) {
                    if (++D_80134228 >= 8) {
                        D_80134228 = 0;
                    }
                } else if (sp30 == -1) {
                    if (--D_80134228 < 0) {
                        D_80134228 = 7;
                    }
                }
                break;
            }
            case 1:
            case 2:
            case 5:
            {
                if (sp30 == 1) {
                    if (++D_8016E428 >= 0xC0) 
                    {
                        D_8016E428 = 0;
                    }
                } 
                else if (sp30 == -1) {
                    if (--D_8016E428 < 0) 
                    {
                        D_8016E428 = 0xBF;
                    }
                }
                break;
            }
            case 3:
            {
                if (sp30 == 1) 
                {
                    if (++D_801765EC >= 0xB) 
                    {
                        D_801765EC = 0;
                    }
                } else if (sp30 == -1) 
                {
                    if (--D_801765EC < 0) {
                        D_801765EC = 0xA;
                    }
                }
                break;
            }
            case 6:
            {
                if (sp30 == 1) {
                    if (++D_8013421C >= 0x101) {
                        D_8013421C = 0;
                    }
                } else if (sp30 == -1) {
                    if (--D_8013421C < 0) {
                        D_8013421C = 0x100;
                    }
                }
                break;                    
            }
        case 7:
        {
            if (sp30 == 1) {
                if (++D_80134220 >= 0x101) {
                    D_80134220 = 0;
                }
            } else if (sp30 == -1) {
                if (--D_80134220 < 0) {
                    D_80134220 = 0x100;
                }
            }
            break;            
        }
        case 8:
            {                
                if (sp30 == 1) {
                    if (++D_80134224 >= 0xA) {
                        D_80134224 = 0;
                    }
                } else if (sp30 == -1) {
                    if (--D_80134224 < 0) {
                        D_80134224 = 9;
                    }
                }
            break;
            }
        }
    }
    func_800FDA10();
    func_8001994C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FE6D8.s")

void func_800FE854(void) {
    func_8001E954(0x8024C000);
    func_8001E98C(0, DebugCircle, DebugSquare);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FE898.s")

void func_800FE9BC(void) {
    sprintf(&D_8016E1B8, "[MAIN MENU]");
    func_8005F9EC(0x20, 0x10);
    sprintf(&D_8016E1B8, "   TIMER BAR ON/OFF = %d", D_8016E3E4);
    func_8005F9EC(0x20, 0x20);
    sprintf(&D_8016E1B8, "   DEBUG DISPLAY MODE = %d", D_8016E3F7);
    func_8005F9EC(0x20, 0x30);
    sprintf(&D_8016E1B8, "   NO DAMAGE = %d", D_8016E3FC);
    func_8005F9EC(0x20, 0x40);
    sprintf(&D_8016E1B8, "   NO ATTRIBUTE = %d", D_8016E404);
    func_8005F9EC(0x20, 0x50);
    sprintf(&D_8016E1B8, "   G BUTTON DEBUG = %d", D_8016E40C);
    func_8005F9EC(0x20, 0x60);
    sprintf(&D_8016E1B8, "   BOM  = %d", D_8016523F);
    func_8005F9EC(0x20, 0x70);
    sprintf(&D_8016E1B8, "   FIRE = %d", D_80165240);
    func_8005F9EC(0x20, 0x80);
    sprintf(&D_8016E1B8, "   DISPTYPE = %d", D_80177974);
    func_8005F9EC(0x20, 0x90);
    sprintf(&D_8016E1B8, "=");
    func_8005F9EC(0x28, (D_8016E3F4 * 0x10) + 0x20);
}

void func_800FEB6C(void) {
    f32 sp24;
    f32 sp20;
    f32 sp1C;
    f32 sp18;

    sprintf(&D_8016E1B8, "[LIGHT EDIT]");
    func_8005F9EC((s8* )0x20, (s8* )0x10);
    sprintf(&D_8016E1B8, "   AMBIENT R = %d", (u8)D_8004A5B8[0].AmbientLight.LightData[0]);
    func_8005F9EC((s8* )0x20, (s8* )0x20);
    sprintf(&D_8016E1B8, "   AMBIENT G = %d", D_8004A5B8[0].AmbientLight.LightData[1]);
    func_8005F9EC((s8* )0x20, (s8* )0x30);
    sprintf(&D_8016E1B8, "   AMBIENT B = %d", D_8004A5B8[0].AmbientLight.LightData[2]);
    func_8005F9EC((s8* )0x20, (s8* )0x40);
    sprintf(&D_8016E1B8, "   DIFFUSE R = %d", D_8004A5B8[0].DiffuseLight.LightData[0]);
    func_8005F9EC((s8* )0x20, (s8* )0x50);
    sprintf(&D_8016E1B8, "   DIFFUSE G = %d", D_8004A5B8[0].DiffuseLight.LightData[1]);
    func_8005F9EC((s8* )0x20, (s8* )0x60);
    sprintf(&D_8016E1B8, "   DIFFUSE B = %d", D_8004A5B8[0].DiffuseLight.LightData[2]);
    func_8005F9EC((s8* )0x20, (s8* )0x70);
    sprintf(&D_8016E1B8, "   DIR     X = %d", D_8004A5B8[0].Direction[0]);
    func_8005F9EC((s8* )0x20, (s8* )0x80);
    sprintf(&D_8016E1B8, "   DIR     Y = %d", D_8004A5B8[0].Direction[1]);
    func_8005F9EC((s8* )0x20, (s8* )0x90);
    sprintf(&D_8016E1B8, "   DIR     Z = %d", D_8004A5B8[0].Direction[2]);
    func_8005F9EC((s8* )0x20, (s8* )0xA0);
    sp24 = (f32) D_8004A5B8[0].Direction[0];
    sp20 = (f32) D_8004A5B8[0].Direction[1];
    sp1C = (f32) D_8004A5B8[0].Direction[2];
    sp18 = sqrtf((sp24 * sp24) + (sp20 * sp20) + (sp1C * sp1C));
    sprintf(&D_8016E1B8, "   DIR TOTAL = %d", (s32) sp18);
    func_8005F9EC((s8* )0x20, (s8* )0xB0);
    sprintf(&D_8016E1B8, "=");
    func_8005F9EC((s8* )0x28, (D_8016E3F4 * 0x10) + 0x20);
}


void func_800FEE34(void) {
    sprintf(&D_8016E1B8, "[FOG EDIT]");
    func_8005F9EC((s8* )0x20, (s8* )0x10);
    sprintf(&D_8016E1B8, "   FOG R    = %d", D_8017793A);
    func_8005F9EC((s8* )0x20, (s8* )0x20);
    sprintf(&D_8016E1B8, "   FOG G    = %d", D_8017793E);
    func_8005F9EC((s8* )0x20, (s8* )0x30);
    sprintf(&D_8016E1B8, "   FOG B    = %d", D_80177940);
    func_8005F9EC((s8* )0x20, (s8* )0x40);
    sprintf(&D_8016E1B8, "   DIR MINI = %d", D_80177944);
    func_8005F9EC((s8* )0x20, (s8* )0x50);
    sprintf(&D_8016E1B8, "   DIR MAX  = %d", D_80177948);
    func_8005F9EC((s8* )0x20, (s8* )0x60);
    sprintf(&D_8016E1B8, "   ZFAR     = %f", (f64) D_801779C8);
    func_8005F9EC((s8* )0x20, (s8* )0x70);
    sprintf(&D_8016E1B8, "=");
    func_8005F9EC((s8* )0x28, (D_8016E3F4 * 0x10) + 0x20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_800FEFA0.s")

void func_800FF43C(void) {
    sprintf(&D_8016E1B8, "PLAY.POS X=%5d Y=%5d Z=%5d", (s32) D_80154150[0].PosX, (s32) D_80154150[0].PosY, (s32) D_80154150[0].PosZ);
    func_8005F9EC((s8* )0x20, (s8* )0x10);
    sprintf(&D_8016E1B8, "PLAY.ROT X=%5d Y=%5d Z=%5d", (s32) D_80154150[0].RotX, (s32) D_80154150[0].RotY, (s32) D_80154150[0].RotZ);
    func_8005F9EC((s8* )0x20, (s8* )0x20);
    sprintf(&D_8016E1B8, "VIEW.AT  X=%5d Y=%5d Z=%5d", (s32) D_8016E140, (s32) D_8016E144, (s32) D_8016E148);
    func_8005F9EC((s8* )0x20, (s8* )0x30);
    sprintf(&D_8016E1B8, "VIEW.EYE X=%5d Y=%5d Z=%5d", (s32) D_8016E14C, (s32) D_8016E150, (s32) D_8016E154);
    func_8005F9EC((s8* )0x20, (s8* )0x40);
    sprintf(&D_8016E1B8, "VIEW.ROT X=%5d Y=%5d Z=%5d", (s32) D_8016E158, (s32) D_8016E15C, (s32) D_8016E160);
    func_8005F9EC((s8* )0x20, (s8* )0x50);
    sprintf(&D_8016E1B8, "VIEW.DIST =%5d", (s32) D_8016E170);
    func_8005F9EC((s8* )0x20, (s8* )0x60);
    sprintf(&D_8016E1B8, "FRWAIT =%5d", D_80134C14);
    func_8005F9EC((s8* )0x20, (s8* )0x70);
}

void func_800FF7B4(void) {
    func_8005F96C(0xFF, 0xFF, 0xFF);
    switch (D_8016E3EC) {
        case 0x1:
            func_800FEFA0();
            break;
        case 0x2:
            func_800FF43C();
            break;
        case 0x64:
            func_800FE9BC();
            break;
        case 0x65:
            func_800FEB6C();
            break;
        case 0x66:
            func_800FEE34();
            break;
    }
    func_8005FA90();
}

void func_800FF88C(void) {

    if (*D_8016E2F0 & 0x800) {
        if (--D_8016E3F4 < 0) {
            D_8016E3F4 = 7;
        }
    }
    if (*D_8016E2F0 & 0x400) {
        if (++D_8016E3F4 >= 8) {
            D_8016E3F4 = 0;
        }
    }
    switch (D_8016E3F4) {
        case 0:
            {
                if (*D_8016E2F0 & 0x200) {
                    if (--D_8016E3E4 < 0) {
                        D_8016E3E4 = 1;
                    }
                }
                if (*D_8016E2F0 & 0x100) {
                    if (++D_8016E3E4 >= 2) {
                        D_8016E3E4 = 0;
                    }
                }
                break;                
            }
        case 1:
            {
                if (*D_8016E2F0 & 0x200) {
                    if (--D_8016E3F7 < 0) {
                        D_8016E3F7 = 2;
                    }
                }
                if (*D_8016E2F0 & 0x100) {
                    if (++D_8016E3F7 >= 3) {
                        D_8016E3F7 = 0;
                    }
                }
                break;                
            }
        case 2:
            {
                if ((D_8016E3A0 & 0x200) || (D_8016E3A0 & 0x100)) {
                    D_8016E3FC ^= 1;
                }
                break;                
            }
        case 3:
            {
                if ((D_8016E3A0 & 0x200) || (D_8016E3A0 & 0x100)) {
                    D_8016E404 ^= 1;
                }                
                break;
            }
        case 4:
            {
                if ((D_8016E3A0 & 0x200) || (D_8016E3A0 & 0x100)) {
                    D_8016E40C ^= 1;
                }
                break;                
            }
        case 5:
            {
                if (*D_8016E2F0 & 0x200) {
                    if (--D_8016523F < 0) {
                        D_8016523F = 3;
                    }
                }
                if (*D_8016E2F0 & 0x100) {
                    if (++D_8016523F >= 4) {
                        D_8016523F = 0;
                    }
                }
                break;                
            }
        case 6:
            {
                if (*D_8016E2F0 & 0x200) {
                    if (--D_80165240 < 0) {
                        D_80165240 = 3;
                    }
                }
                if (*D_8016E2F0 & 0x100) {
                    if (++D_80165240 >= 4) {
                        D_80165240 = 0;
                    }
                }
                break;                
            }
        case 7:
            {
                if (*D_8016E2F0 & 0x200) {
                    if ((--D_80177974) == 0xFF) {
                        D_80177974 = 0x1E;
                    }
                }
                if (*D_8016E2F0 & 0x100) {
                    if ((++D_80177974) >= 0x1F) {
                        D_80177974 = 0;
                    }
                }                
            }
        break;
    }
}

void func_800FFD30(void) {
    s32 sp1C;
    s32 sp18;

    sp1C = func_800FDF98();
    if (sp1C == 2) {
        if (--D_8016E3F4 < 0) {
            D_8016E3F4 = 8;
        }
    } else if (sp1C == -2) {
        if (++D_8016E3F4 >= 9) {
            D_8016E3F4 = 0;
        }
    }
    if ((sp1C == 1) || (sp1C == -1)) {
        switch (D_8016E3F4) {
        case 0:
        case 1:
        case 2:
            sp18 = (s32) D_8016E3F4;
            D_8004A5B8[0].AmbientLight.LightData[sp18] += sp1C;
            D_8004A5B8[0].AmbientLight.LightData[sp18 + 4] = D_8004A5B8[0].AmbientLight.LightData[sp18];
            break;
        case 3:
        case 4:
        case 5:
            sp18 = D_8016E3F4 - 3; // - 3 so we index back to 0-2
            D_8004A5B8[0].DiffuseLight.LightData[sp18] += sp1C;
            D_8004A5B8[0].DiffuseLight.LightData[sp18 + 4] = D_8004A5B8[0].DiffuseLight.LightData[sp18];
            break;
        case 6:
        case 7:
        case 8:
            sp18 = D_8016E3F4 - 6; // - 6 so we index back to 0-2
            D_8004A5B8[0].Direction[sp18] += sp1C;
            D_8004A5B8[0].Direction[sp18 + 0x10] = D_8004A5B8[0].Direction[sp18];
            break;
        }
    }
}

void func_800FFF40(void) {
    s32 sp1C;

    sp1C = func_800FDF98();
    if (sp1C == 2) {
        if (--D_8016E3F4 < 0) {
            D_8016E3F4 = 5;
        }
    } else if (sp1C == -2) {
        if (++D_8016E3F4 >= 6) {
            D_8016E3F4 = 0;
        }
    }
    if ((sp1C == 1) || (sp1C == -1)) {
        switch (D_8016E3F4) {
        case 0:
            D_8017793A += sp1C;
            D_80177932 = D_8017793A;
            break;
        case 1:
            D_8017793E += sp1C;
            D_80177934 = D_8017793E;
            break;
        case 2:
            D_80177940 += sp1C;
            D_80177938 = D_80177940;
            break;
        case 3:
            D_80177944 += sp1C;
            break;
        case 4:
            D_80177948 += sp1C;
            break;
        case 5:
            D_801779C8 = D_801779C8 + (sp1C * 0x64);
            break;
        }
    }
}

void func_80100148(void) {
    if (D_8016E384 & 0x1000) {
        D_8016E3EE = 0;
        D_8016E3EC = D_8016E3F7;
        D_801765F4 = 0;
        return;
    }
    if (D_8016E384 & 0x20) {
        D_8016E3EC += 1;
        D_8016E3F4 = 0;
        if (D_8016E3EC == 0x67) {
            D_8016E3EC = 0x64;
        }
    }
    if (D_8016E3EC == 0x64) {
        func_800FF88C();
    } else if (D_8016E3EC == 0x65) {
        func_800FFD30();
    } else if (D_8016E3EC == 0x66) {
        func_800FFF40();
    }
}

void func_80100260(void) {
    s16 i;

    D_80134734 = 0;
    D_80134730 = 0;
    for(i = 0; i < 2; i++)
    {
        D_80134738[i] = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/code/EFF30/func_801002BC.s")
