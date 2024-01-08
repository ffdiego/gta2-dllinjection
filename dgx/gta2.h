#pragma once

typedef unsigned char    byte;
typedef void GameObject;
typedef void Car;
typedef void WEAPON_STRUCT;

struct Ped {
    byte pad1[89]; //0x00 -- 0x164
    struct GameObject* gameObject; //0x168
    struct Car* currentCar; //0x16c
    struct WEAPON_STRUCT* selectedWeapon; //0x170
    void* ptrToWeapon; //0x174
    byte pad2[4]; //0x178 -- 0x184
    unsigned int money; //0x188
    byte pad3[30]; //0x18c
    int id; //0x200
};

typedef Ped* (__stdcall GetPedById)(int);
static GetPedById* fnGetPedByID = (GetPedById*)0x0043ae10;

