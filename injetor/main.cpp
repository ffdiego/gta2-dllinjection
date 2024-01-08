#include <stddef.h>
#include <stdio.h>
#include "ProcMan.h" 
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

void printoffset(size_t offset) {
    printf("%zx bytes\n", offset);
}

int main() {
    void* offset1 = (char*)offsetof(Ped, gameObject);
    void* offset2 = (char*)offsetof(Ped, currentCar);
    void* offset3 = (char*)offsetof(Ped, money);
    void* offset4 = (char*)offsetof(Ped, id);
    

    // Imprimindo o offset
	ProcMan::inject(L"gta2.exe", "..//Debug//dgx.dll");

	return 0;
}