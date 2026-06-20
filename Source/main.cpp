#include "Include.h"
#include <thread>

int main() {
    const char* procName = "left4dead2.exe";
    const char* wndTitle = "Left 4 Dead 2 - Direct3D 9";

    DWORD pid = 0;
    while (!(pid = GetProcId(procName))) {
        std::cout << "[INFO] Waiting target process " << procName << "...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::cout << "[FOUND] Process " << procName << " | PID: " << pid << std::endl;

    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hProcess) {
        std::cout << "[ERROR] Failed to open process." << std::endl;
        return 1;
    }

    clientBase = GetModuleBase(pid, "client.dll");
    engineBase = GetModuleBase(pid, "engine.dll");

    if (!clientBase || !engineBase) {
        std::cout << "[ERROR] Failed to find module base(s)." << std::endl;
        CloseHandle(hProcess);
        return 1;
    }

    std::cout << "[MODULE] client.dll base address : 0x" << std::hex << clientBase << std::endl;
    std::cout << "[MODULE] engine.dll base address : 0x" << std::hex << engineBase << std::endl;
    std::cout << "[INFO] Modules loaded. Pausing 5 seconds before continuing..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    UpdateLocalPlayer();

    // Entityloop
    std::thread([] {
        while (true) {
            LoopEntities();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
        }).detach();

    // OsImgui
    try {
        Gui.AttachAnotherWindow(wndTitle, "", DrawCallBack);
    }
    catch (const OSImGui::OSException& e) {
        std::cout << "[ERROR] OSImGui : " << e.what() << std::endl;
        CloseHandle(hProcess);
        return 1;
    }

    CloseHandle(hProcess);
    return 0;
}
