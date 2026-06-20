#pragma once
#include <Windows.h>
#include <cstdint>

extern HANDLE hProcess;

template<typename T>
T ReadMemory(uintptr_t address) {
    T buffer{};
    ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(address), &buffer, sizeof(T), nullptr);
    return buffer;
}
template<typename T>
bool ReadMemoryArray(uintptr_t address, T* buffer, size_t count) {
    SIZE_T bytesRead;
    return ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(address), buffer, sizeof(T) * count, &bytesRead);
}

template<typename T>
void WriteMemory(uintptr_t address, T value) {
    WriteProcessMemory(hProcess, reinterpret_cast<LPVOID>(address), &value, sizeof(T), nullptr);
}

DWORD GetProcId(const char* name);
uintptr_t GetModuleBase(DWORD pid, const char* mod);
