#include "Globals.h"

HANDLE hProcess = nullptr;
uintptr_t clientBase = 0;
uintptr_t engineBase = 0;
uintptr_t localPlayer = 0;
uintptr_t ForceJump = 0;
uintptr_t serverBase = 0;
bool menuOpen = false;
extern int boxStyle;
bool showAllies = false;
bool enableBox2D = false;
bool enableHealthBar = false;
bool enableHealthESP = false;
bool enableDistance = false;
bool enableSnapLine = false;
bool enableESPName = false;
bool enableFovCircle = false;
bool enableFovSliderAndCircle = false;
float fov_override = 90.0f;
bool enableBunnyhop = false;
bool hideDebugConsole = false;
bool testHideHUD = false;
bool enablecrosshair = false;
int crosshairStyle = 0;
bool showEspPreview = false;

void ResetEspColors() {
    // Crosshair
    colorCrosshair = ImColor(255, 255, 255);

    // Allies (Survivors)
    colorAllySnapline = ImColor(0, 255, 0);
    colorAllyName = ImColor(0, 255, 0);
    colorAllyDistance = ImColor(0, 255, 0);
    colorAllyHealth = ImColor(0, 255, 0);
    colorAllyBox2D = ImColor(0, 255, 0);

    // Special infected
    colorInfectedSnapline = ImColor(255, 0, 0);
    colorInfectedName = ImColor(255, 0, 0);
    colorInfectedDistance = ImColor(255, 0, 0);
    colorInfectedHealth = ImColor(255, 0, 0);
    colorInfectedBox2D = ImColor(255, 0, 0);

    // Commun infected
    colorCommonSnapline = ImColor(255, 255, 0);
    colorCommonName = ImColor(255, 255, 0);
    colorCommonDistance = ImColor(255, 255, 0);
    colorCommonHealth = ImColor(255, 255, 0);
    colorCommonBox2D = ImColor(255, 255, 0);
}
