#pragma once
#include <Windows.h>
#include <TlHelp32.h>

class ProcMan
{
public:
	static int get_proc_id(const wchar_t* target) {
		DWORD pId = 0;
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		do {
			if (wcscmp(pe32.szExeFile, target) == 0) {
				CloseHandle(hSnapshot);
				pId = pe32.th32ProcessID;
				break;
			}
		} while (Process32Next(hSnapshot, &pe32));
		
		return pId;
	}

	static int inject(const wchar_t* processName, const char* dllName) {
		int pId = get_proc_id(processName);

		char dllPath[MAX_PATH] = { 0 };

		GetFullPathNameA(dllName, MAX_PATH, dllPath, NULL);
		HANDLE hProcess = OpenProcess(
			PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, pId);
		LPVOID pszLibFileRemote = VirtualAllocEx(hProcess, NULL, strlen(dllPath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		WriteProcessMemory(hProcess, pszLibFileRemote, dllPath, strlen(dllPath) + 1, NULL);
		HANDLE hThread = CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryA, pszLibFileRemote, NULL, NULL);

		WaitForSingleObject(hThread, INFINITE);
		CloseHandle(hThread);
		VirtualFreeEx(hProcess, dllPath, 0, MEM_RELEASE);
		CloseHandle(hProcess);

		return 0;
	}
};

