#include "pch.h"
#include <stdio.h>
#include "gta2.h"

void Dinossauro()
{
	char moneyMsg[50];
	unsigned int money = 0;
	int id;

	Ped* playerPed = fnGetPedByID(1);

	if (!playerPed || !playerPed->gameObject /*|| !playerPed->gameObject->sprite */)
		return;

	money = *((unsigned int*)(playerPed + 0x188));
	id = *((int*)(playerPed + 0x200));

	sprintf_s(moneyMsg, "$%d", money);
	MessageBoxA(NULL, moneyMsg, "Parabéns Zé!", MB_OK);
}

DWORD WINAPI MainThread(LPVOID param)
{
	while (true) {
		if (GetAsyncKeyState(VK_F7) & 0x80000) {
			Dinossauro();
		}
		Sleep(100);
	}
	return 0;
}

bool WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		MessageBoxA(NULL, "DLL Injetada!", "Parabéns Zé!", MB_OK);
		CreateThread(0, 0, MainThread, hModule, 0, 0);
	}
	return true;
}

