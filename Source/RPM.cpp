#include "RPM.h"
#include <TlHelp32.h>
#include <cstring>



DWORD GetProcId(const char* name) {
    DWORD pid = 0;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap != INVALID_HANDLE_VALUE) {
        PROCESSENTRY32 pe{ sizeof(pe) };
        for (BOOL ok = Process32First(snap, &pe); ok; ok = Process32Next(snap, &pe)) {
            if (_stricmp(pe.szExeFile, name) == 0) {
                pid = pe.th32ProcessID;
                break;
            }
        }
    }
    CloseHandle(snap);
    return pid;
}

uintptr_t GetModuleBase(DWORD pid, const char* mod) {
    uintptr_t base = 0;
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (snap != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 me{ sizeof(me) };
        for (BOOL ok = Module32First(snap, &me); ok; ok = Module32Next(snap, &me)) {
            if (_stricmp(me.szModule, mod) == 0) {
                base = reinterpret_cast<uintptr_t>(me.modBaseAddr);
                break;
            }
        }
    }
    CloseHandle(snap);
    return base;
}
