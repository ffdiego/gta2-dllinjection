#pragma once
#include <Windows.h>

class MemOp
{
public:
	static void read_bytes(void* readAddress, void* readBuffer, int len) {
		protected_read(readBuffer, readAddress, len);
	}

	static void write_bytes(void* destinationAddress, void* patch, int len) {
		protected_read(destinationAddress, patch, len);
	}

private:
	static void protected_read(void* dest, void* src, int n) {
		DWORD oldProtect = 0;
		VirtualProtect(dest, n, PAGE_EXECUTE_READWRITE, &oldProtect);
		memcpy(dest, src, n);
		VirtualProtect(dest, n, oldProtect, &oldProtect);
	}
};

