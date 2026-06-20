#pragma once
#include "Include.h"

// SnapLine
inline void DrawSnaplineTo(Vec2 to, ImColor color, float thickness) {
    Vec2 from = { Gui.Window.Size.x / 2.0f, Gui.Window.Size.y - 50.0f };
    Gui.Line(from, to, color, thickness);
}
// FOV Cone
inline void DrawFov(float fovDegrees, float size, ImColor color, float thickness) {
    float radian = (fovDegrees / 2.0f) * static_cast<float>(M_PI) / 180.0f;
    Vec2 center = Gui.Window.Size / 2;
    float length = size * tanf(radian);

    Vec2 left = { center.x - length, center.y - size };
    Vec2 right = { center.x + length, center.y - size };

    Gui.Line(center, left, color, thickness);
    Gui.Line(center, right, color, thickness);
}
// FOV Circle
inline void DrawFovCircle(float fovDegrees, ImColor color, float thickness) {
    Vec2 center = Gui.Window.Size / 2;
    float baseFov = 90.0f;
    float radius = 150.0f * (fovDegrees / baseFov);
    if (radius > 0 && color.Value.w > 0.01f)
        Gui.Circle(center, radius, color, thickness, 100);
}
// 2D Box
inline void Draw2DBox(Vec2 topLeft, Vec2 size, ImColor color, float thickness = 1.5f) {
    Gui.Rectangle(topLeft, size, color, thickness, 0.0f);
}
// HealthBar
inline void DrawVerticalHealthBar(Vec2 pos, float height, float ratio, float width = 4.0f) {
    Vec2 size(width, height);
    Gui.RectangleFilled(pos, size, ImColor(0, 0, 0, 200));

    int steps = 40;
    float filledHeight = height * ratio;

    for (int j = 0; j < steps; ++j) {
        float t = static_cast<float>(j) / steps;
        float segmentY = height * (1.0f - t);
        float y = pos.y + segmentY;

        if (y < pos.y + height - filledHeight)
            continue;

        float segmentHeight = height / steps;
        Vec2 segmentPos(pos.x, y - segmentHeight);
        Vec2 segmentSize(width, segmentHeight);

        ImColor color = (t < 0.5f)
            ? ImColor(255, static_cast<int>(255 * t * 2), 0)       
            : ImColor(static_cast<int>(255 * (1 - t) * 2), 255, 0);

        Gui.RectangleFilled(segmentPos, segmentSize, color);
    }
}
//2dbox cutline
inline void Draw2DCornerBox(Vec2 topLeft, Vec2 size, ImColor color, float thickness = 1.5f, float ratio = 0.2f) {
    float lw = size.x * ratio, lh = size.y * ratio;
    float x = topLeft.x, y = topLeft.y;
    float x2 = x + size.x, y2 = y + size.y;

    Gui.Line({ x, y }, { x + lw, y }, color, thickness);
    Gui.Line({ x, y }, { x, y + lh }, color, thickness);
    Gui.Line({ x2, y }, { x2 - lw, y }, color, thickness);
    Gui.Line({ x2, y }, { x2, y + lh }, color, thickness);
    Gui.Line({ x, y2 }, { x + lw, y2 }, color, thickness);
    Gui.Line({ x, y2 }, { x, y2 - lh }, color, thickness);
    Gui.Line({ x2, y2 }, { x2 - lw, y2 }, color, thickness);
    Gui.Line({ x2, y2 }, { x2, y2 - lh }, color, thickness);
}
// Center Text
inline void DrawTextCentered(const char* text, Vec2 centerPos, ImColor color, float size = 16.0f) {
    ImVec2 textSize = ImGui::CalcTextSize(text);
    Vec2 pos(centerPos.x - textSize.x / 2.0f, centerPos.y - textSize.y / 2.0f);
    Gui.Text(text, pos, color, size);
}
// Up Text
inline void DrawTextAbove(const char* text, Vec2 basePos, ImColor color, float offset = 18.0f, float size = 16.0f) {
    ImVec2 textSize = ImGui::CalcTextSize(text);
    Vec2 pos(basePos.x - textSize.x / 2.0f, basePos.y - offset);
    Gui.Text(text, pos, color, size);
}
//imgui
// Preview
inline void DrawCornerBoxImGui(ImVec2 topLeft, ImVec2 size, ImColor color, float thickness = 1.5f, float ratio = 0.2f)
{
    ImDrawList* drawList = ImGui::GetWindowDrawList();

    float lw = size.x * ratio;
    float lh = size.y * ratio;

    float x = topLeft.x, y = topLeft.y;
    float x2 = x + size.x, y2 = y + size.y;

    drawList->AddLine({ x, y }, { x + lw, y }, color, thickness);
    drawList->AddLine({ x, y }, { x, y + lh }, color, thickness);

    drawList->AddLine({ x2, y }, { x2 - lw, y }, color, thickness);
    drawList->AddLine({ x2, y }, { x2, y + lh }, color, thickness);

    drawList->AddLine({ x, y2 }, { x + lw, y2 }, color, thickness);
    drawList->AddLine({ x, y2 }, { x, y2 - lh }, color, thickness);

    drawList->AddLine({ x2, y2 }, { x2 - lw, y2 }, color, thickness);
    drawList->AddLine({ x2, y2 }, { x2, y2 - lh }, color, thickness);
}
