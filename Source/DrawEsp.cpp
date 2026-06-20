#include "Include.h"

#define DEG2RAD(x) ((x) * (3.14159265f / 180.0f))

bool IsTank(const EntityInfo& info) {
    return info.zombieClass == 7; // 
}
bool IsValidSpecialInfected(const EntityInfo& info, const EntityState& state) {
    return info.team == 3 && info.zombieClass >= 1 && info.zombieClass <= 6 && state.lifeState == 0;
}
bool IsValidSurvivor(const EntityInfo& info, const EntityState& state) {
    return info.team == 2 && state.lifeState == 0 && info.health > 0;
}
ImColor GetColorFromType(
    ImColor ally,
    ImColor tank,
    ImColor infected,
    ImColor common,
    const EntityInfo& info,
    const EntityState& state,
    EntityType type
) {
    if (type == EntityType::Witch) return ImColor(200, 0, 255);
    if (type == EntityType::Common) return common;
    if (info.team == 2) return ally;
    if (IsTank(info)) return tank;
    if (IsValidSpecialInfected(info, state)) return infected;
    return common;
}
void DrawSnapline() {
    if (!enableSnapLine || !localPlayer) return;
    CView view;
    if (!GetViewMatrix(view)) return;

    for (const auto& [info, state] : g_entities) {
        Vec2 screen;
        if (!view.WorldToScreen(info.position, screen)) continue;
        if (!showAllies && info.team == 2) continue;
        ImColor color = GetColorFromType(
            colorAllySnapline, colorTankSnapline, colorInfectedSnapline, colorCommonSnapline,
            info, state, info.type
        );
        DrawSnaplineTo(screen, color, 1.5f);
    }
}
void DrawDistance() {
    if (!enableDistance || !localPlayer) return;
    Vec3 localPos = ReadMemory<Vec3>(localPlayer + Offsets::m_vecOrigin);
    CView view;
    if (!GetViewMatrix(view)) return;
    for (const auto& [info, state] : g_entities) {
        Vec3 top = info.position; top.z += 72.f;
        Vec2 screenTop, screenBottom;
        if (!view.WorldToScreen(top, screenTop) || !view.WorldToScreen(info.position, screenBottom)) continue;
        if (!showAllies && info.team == 2) continue;
        float dist = (info.position - localPos).Length();
        char buf[32];
        sprintf_s(buf, "%.1f m", dist);
        ImVec2 textSize = ImGui::CalcTextSize(buf);
        Vec2 textPos(screenTop.x - textSize.x / 2.f, screenBottom.y + 2.0f);
        ImColor color = GetColorFromType(
            colorAllyDistance, colorTankDistance, colorInfectedDistance, colorCommonDistance,
            info, state, info.type
        );
        Gui.Text(buf, textPos, color, 16.0f);
    }
}
void DrawEspName() {
    if (!enableESPName || !localPlayer) return;
    CView view;
    if (!GetViewMatrix(view)) return;
    for (const auto& [info, state] : g_entities) {
        Vec3 top = info.position; top.z += 72.f;
        Vec2 screenTop;
        if (!view.WorldToScreen(top, screenTop)) continue;
        if (!showAllies && info.team == 2) continue;
        const char* name = "Unknown";
        if (info.team == 2) name = "Survivor";
        else if (info.type == EntityType::Witch) name = "Witch";
        else if (info.type == EntityType::Common) name = "Common";
        else if (IsTank(info)) name = "Tank";
        else {
            switch (info.zombieClass) {
            case 1: name = "Smoker"; break;
            case 2: name = "Boomer"; break;
            case 3: name = "Hunter"; break;
            case 4: name = "Spitter"; break;
            case 5: name = "Jockey"; break;
            case 6: name = "Charger"; break;
            default: name = "Infected"; break;
            }
        }
        ImColor color = GetColorFromType(
            colorAllyName, colorTankName, colorInfectedName, colorCommonName,
            info, state, info.type
        );
        Gui.Text(name, screenTop, color, 16.0f);
    }
}
void Draw2DBox() {
    if (!enableBox2D || !localPlayer || boxStyle != 0) return;
    CView view;
    if (!GetViewMatrix(view)) return;
    for (const auto& [info, state] : g_entities) {
        Vec3 top = info.position; top.z += 72.f;
        Vec2 screenTop, screenBottom;
        if (!view.WorldToScreen(top, screenTop) || !view.WorldToScreen(info.position, screenBottom)) continue;
        if (!showAllies && info.team == 2) continue;
        float height = screenBottom.y - screenTop.y;
        float width = height / 2.f;
        Vec2 boxPos(screenTop.x - width / 2.f, screenTop.y);
        Vec2 boxSize(width, height);
        ImColor color = GetColorFromType(
            colorAllyBox2D, colorTankBox2D, colorInfectedBox2D, colorCommonBox2D,
            info, state, info.type
        );
        Gui.Rectangle(boxPos, boxSize, color, 1.5f);
    }
}
void DrawEspCutline() {
    if (!enableBox2D || !localPlayer || boxStyle != 1) return;
    CView view;
    if (!GetViewMatrix(view)) return;
    for (const auto& [info, state] : g_entities) {
        Vec3 top = info.position; top.z += 72.f;
        Vec2 screenTop, screenBottom;
        if (!view.WorldToScreen(top, screenTop) || !view.WorldToScreen(info.position, screenBottom)) continue;
        if (!showAllies && info.team == 2) continue;
        float height = screenBottom.y - screenTop.y;
        float width = height / 2.f;
        Vec2 boxPos(screenTop.x - width / 2.f, screenTop.y);
        Vec2 boxSize(width, height);
        ImColor color = GetColorFromType(
            colorAllyBox2D, colorTankBox2D, colorInfectedBox2D, colorCommonBox2D,
            info, state, info.type
        );
        Draw2DCornerBox(boxPos, boxSize, color, 1.5f);
    }
}
void DrawHealthBar() {
    if (!enableHealthBar || !localPlayer) return;
    CView view;
    if (!GetViewMatrix(view)) return;
    for (const auto& [info, state] : g_entities) {
        Vec3 top = info.position; top.z += 72.f;
        Vec2 screenTop, screenBottom;
        if (!view.WorldToScreen(top, screenTop) || !view.WorldToScreen(info.position, screenBottom)) continue;
        if (!showAllies && info.team == 2) continue;
        float height = screenBottom.y - screenTop.y;
        float width = height / 2.f;
        float x = screenTop.x - width / 2.f - 6.f;
        float y = screenTop.y;
        float ratio = std::clamp(info.health / 100.f, 0.f, 1.f);
        DrawVerticalHealthBar({ x, y }, height, ratio);
    }
}
void HealthEsp() {
    if (!enableHealthESP || !localPlayer) return;
    CView view;
    if (!GetViewMatrix(view)) return;
    for (const auto& [info, state] : g_entities) {
        Vec3 top = info.position; top.z += 72.f;
        Vec2 screenTop, screenBottom;
        if (!view.WorldToScreen(top, screenTop) || !view.WorldToScreen(info.position, screenBottom)) continue;
        if (!showAllies && info.team == 2) continue;
        char hpText[16];
        sprintf_s(hpText, "%d", info.health);
        ImVec2 textSize = ImGui::CalcTextSize(hpText);
        float height = screenBottom.y - screenTop.y;
        float boxLeft = screenTop.x - (height / 2.0f) / 2.0f;
        float posX = boxLeft - 4.0f - 6.0f - textSize.x - 10.0f;
        float posY = screenTop.y + (height / 2.0f) - (textSize.y / 2.0f);
        ImColor color = GetColorFromType(
            colorAllyHealth, colorTankHealth, colorInfectedHealth, colorCommonHealth,
            info, state, info.type
        );
        Gui.Text(hpText, Vec2(posX, posY), color, 16.0f);
    }
}
void DrawFov() {
    if (!enableFovCircle) return;
    Vec2 screenCenter = Gui.Window.Size / 2.0f;
    float angle = fov_override;
    float length = 300.0f;
    float radiansLeft = DEG2RAD(-angle / 2.0f);
    float radiansRight = DEG2RAD(angle / 2.0f);
    Vec2 left = {
        screenCenter.x + cosf(radiansLeft) * length,
        screenCenter.y + sinf(radiansLeft) * length
    };
    Vec2 right = {
        screenCenter.x + cosf(radiansRight) * length,
        screenCenter.y + sinf(radiansRight) * length
    };

    ImColor col = colorFov;
    Gui.Line(screenCenter, left, col, 1.0f);
    Gui.Line(screenCenter, right, col, 1.0f);
    Gui.Circle(screenCenter, length, col, 64, false);
}
void DrawCustomCrosshair() {
    if (!enablecrosshair) return;
    Vec2 center = Gui.Window.Size / 2.0f;
    ImColor col = colorCrosshair;
    switch (crosshairStyle) {
    case 0:
        Gui.Line({ center.x - 8, center.y }, { center.x + 8, center.y }, col, 1.5f);
        Gui.Line({ center.x, center.y - 8 }, { center.x, center.y + 8 }, col, 1.5f);
        break;
    case 1:
        Gui.Circle(center, 2.5f, col, 0, true);
        break;
    case 2:
        Gui.Circle(center, 6.0f, col, 32, false);
        break;
    case 3:
        Gui.Line({ center.x - 6, center.y }, { center.x + 6, center.y }, col, 1.5f);
        Gui.Line({ center.x, center.y }, { center.x, center.y + 8 }, col, 1.5f);
        break;
    }
}
void DebugConsole() {
    HWND consoleWnd = GetConsoleWindow();
    if (consoleWnd) ShowWindow(consoleWnd, SW_SHOW);
}