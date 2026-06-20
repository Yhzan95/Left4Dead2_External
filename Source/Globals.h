#pragma once

#include "include.h"

class CView;
extern bool menuOpen;

extern HANDLE hProcess;
extern uintptr_t clientBase;
extern uintptr_t engineBase;
extern uintptr_t localPlayer;
extern uintptr_t ForceJump;
extern uintptr_t serverBase;

extern bool showAllies;
extern bool enableBox2D;
extern bool enableHealthBar;
extern bool enableHealthESP;
extern bool enableDistance;
extern bool enableSnapLine;
extern bool enableESPName;
extern bool enableWitchESP;
inline int boxStyle = 0;

extern bool enableFovCircle;
extern bool enableFovSliderAndCircle;
extern float fov_override;
extern bool enableBunnyhop;
extern bool hideDebugConsole;
extern bool testHideHUD;
extern bool enablecrosshair;
extern int crosshairStyle;
extern bool showEspPreview;
bool GetViewMatrix(CView& view);
void ResetEspColors();

// Esp colors
inline ImColor colorAllySnapline = ImColor(0, 255, 0);
inline ImColor colorAllyName = ImColor(0, 255, 0);
inline ImColor colorAllyDistance = ImColor(0, 255, 0);
inline ImColor colorAllyHealth = ImColor(0, 255, 0);
inline ImColor colorAllyBox2D = ImColor(0, 255, 0);
inline ImColor colorInfectedSnapline = ImColor(255, 0, 0);
inline ImColor colorInfectedName = ImColor(255, 0, 0);
inline ImColor colorInfectedDistance = ImColor(255, 0, 0);
inline ImColor colorInfectedHealth = ImColor(255, 0, 0);
inline ImColor colorInfectedBox2D = ImColor(255, 0, 0);
inline ImColor colorTankSnapline = ImColor(150, 0, 255);
inline ImColor colorTankName = ImColor(150, 0, 255);
inline ImColor colorTankDistance = ImColor(150, 0, 255);
inline ImColor colorTankHealth = ImColor(150, 0, 255);
inline ImColor colorTankBox2D = ImColor(150, 0, 255);
inline ImColor colorCommonSnapline = ImColor(255, 255, 0);
inline ImColor colorCommonName = ImColor(255, 255, 0);
inline ImColor colorCommonDistance = ImColor(255, 255, 0);
inline ImColor colorCommonHealth = ImColor(255, 255, 0);
inline ImColor colorCommonBox2D = ImColor(255, 255, 0);
inline ImColor colorCrosshair = ImColor(255, 255, 255);

// Esp Preview
inline ImColor previewBoxAllyColor = ImColor(0, 180, 255);
inline ImColor previewBoxEnemyColor = ImColor(255, 60, 60);
inline ImColor previewHealthBarColor = ImColor(0, 255, 100);
inline ImColor previewHealthTextColor = ImColor(255, 255, 255);
inline ImColor previewNameColor = ImColor(255, 255, 255);
inline ImColor previewDistanceColor = ImColor(200, 200, 0);

inline ImColor colorFov = ImColor(255, 255, 255, 255); 
