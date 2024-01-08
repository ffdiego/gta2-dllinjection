#include "pch.h"
#include <Windows.h>
#include <stdio.h>
#include "gta2.h"

static unsigned short currVocal = eVocals::VOCAL_0;
FILE* stream;

void ShowDebugWindow() {
	AllocConsole();
	
	freopen_s(&stream, "conin$", "r", stdin);
	freopen_s(&stream, "conout$", "w", stdout);
	freopen_s(&stream, "conout$", "w", stderr);

	printf("Anexado!\n");
	setvbuf(stdout, NULL, _IONBF, 0);
}

void Dinossauro()
{
	char moneyMsg[50];
	unsigned int money = 0;
	int id;

	Ped* playerPed = fnGetPedByID(1);

	money = *((unsigned int*)((char*)playerPed + 0x188));
	id = *((int*)((char*)playerPed + 0x200));

	sprintf_s(moneyMsg, "id: %d, $%d", id, money);
	MessageBoxA(NULL, moneyMsg, "Parabéns Zé!", MB_OK);
}

void fazerVoz() 
{
	fnPlayVocal(eVocals::VOCAL_LAUGH);
}

DWORD WINAPI MainThread(LPVOID param)
{

	while (true) {
		if (GetAsyncKeyState(VK_F7) & 0x80000) {
			fazerVoz();
			//Dinossauro();
		}
		else if (GetAsyncKeyState(VK_F8) & 0x80000) {
			fazerVoz();
		}
		Sleep(100);
	}
	return 0;
}

bool WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
#if _DEBUG
		ShowDebugWindow();
#endif
		CreateThread(0, 0, MainThread, hModule, 0, 0);
	}
	return true;
}

