#include "Include.h"

// Viewmatrix-W2s
bool GetViewMatrix(CView& view) {
    uintptr_t ptrToMatrix = ReadMemory<uintptr_t>(engineBase + Offsets::dwViewMatrix);

    if (!ptrToMatrix) return false;

    float mat[16]{};
    if (!ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(ptrToMatrix + Offsets::viewMatrixInnerOffset), &mat, sizeof(mat), nullptr)) {
        std::cout << "[ERROR] ViewMatrix RPM failed\n";
        return false;
    }

    for (int i = 0, k = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j, ++k)
            view.Matrix[i][j] = mat[k];

    return true;
}

