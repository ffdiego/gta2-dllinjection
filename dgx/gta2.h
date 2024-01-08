#pragma once

typedef unsigned char    byte;
typedef void GameObject;
typedef void Car;
typedef void WEAPON_STRUCT;

struct Ped {
    byte pad1[0x168]; //0x00 -- 0x164
    struct GameObject* gameObject; //0x168
    struct Car* currentCar; //0x16c
    struct WEAPON_STRUCT* selectedWeapon; //0x170
    void* ptrToWeapon; //0x174
    byte pad2[0x10]; //0x178 -- 0x184
    unsigned int money; //0x188
    byte pad3[0x74]; //0x18c
    int id; //0x200
};

enum eVocals {
    VOCAL_0,
    VOCAL_INSANESTUNTBONUS,
    VOCAL_1,
    VOCAL_2,
    VOCAL_EXPIDITIOUS,
    VOCAL_GENOCIDE,
    VOCAL_COPKILLA,
    VOCAL_CARJACKER,
    VOCAL_ELVIS,
    VOCAL_ACCURACYBONUS,
    VOCAL_BACK2FRONT,
    VOCAL_MEDICALEMERCENCY,
    VOCAL_KILLFRENZY,
    VOCAL_BUSTED = 17,
    VOCAL_FRENZYFAILED,
    VOCAL_FRENZYPASSED,
    VOCAL_FRYINGTONITE,
    VOCAL_21,
    VOCAL_JOBCOMPLETE,
    VOCAL_JOBFAILED,
    VOCAL_RESPECTIS,
    VOCAL_SHOCKING,
    VOCAL_SOMETHINGSCOOKING,
    VOCAl_TIMESUP,
    VOCAL_TOASTED,
    VOCAL_WASTED,
    VOCAL_BOMBARMED,
    VOCAL_LAUGH,
    VOCAL_YOOHOO,
    VOCAL_RACEOVER,
    VOCAl_2NDLAP,
    VOCAL_FINALLAP,
    VOCAL_RACEON,
    VOCAL_30PEOPLEDOWN,
    VOCAL_60PEOPLEDOWN,
    VOCAL_90PEOPLEDOWN,
    VOCAL_120PEOPLEDOWN,
    VOCAL_150PEOPLEDOWN,
    VOCAL_TIMEOUT,
    VOCAL_TIMEEXTENDED,
    VOCAL_TIMESUP_2,
    VOCAL_DIDTHATHURT,
    VOCAL_NICEWORK,
    VOCAL_CHOCTASTIC,
    VOCAL_RASPBERRYRIPPLE,
    VOCAL_YOUSHOTYOURLOAD,
    VOCAL_OOHDIDTHATHURT,
    VOCAL_DEATHTOICVANS,
    VOCAL_CRISPYCRITTER,
    VOCAL_YOURETOASTBUDDY,
    VOCAL_EATLEADDEATH,
    VOCAL_THATSGOTTAHURT,
    VOCAL_SORRYABOUTTHAT,
    VOCAL_XINLOIMYMAN,
    VOCAL_DAMNSUNDAYDRIVERS,
    VOCAL_SUCKITANDSEE,
    VOCAL_TASTEMYWRATH,
    VOCAL_HALLELUJAH,
    VOCAL_DAMNATION,
};

typedef Ped* (__stdcall GetPedById)(int);
static GetPedById* fnGetPedByID = (GetPedById*)0x0043ae10;

typedef void* (__stdcall PlayVocal)(unsigned short);
static PlayVocal* fnPlayVocal = (PlayVocal*)0x4105B0;

typedef void* (__stdcall PrintString)(const wchar_t* str, int x, int y, int style, int scale, int const& mode, int palette, bool enableAlpha, int alpha);
static PrintString* fnPrintString = (PrintString*)0x4CC100;

