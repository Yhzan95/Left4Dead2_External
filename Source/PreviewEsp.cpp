#include "Include.h"
#include "Globals.h"
#include "PreviewESP.h"
#include "Renderer.h"


void DrawEspPreviewWindow()
{
    if (!showEspPreview) return;

    ImVec2 fixedSize(150, 250);
    ImGui::SetNextWindowSize(fixedSize);
    ImGui::SetNextWindowSizeConstraints(fixedSize, fixedSize);
    ImGui::Begin("ESP Preview", &showEspPreview, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

    ImVec2 canvasPos = ImGui::GetCursorScreenPos();
    ImVec2 canvasSize = ImGui::GetContentRegionAvail();
    ImDrawList* drawList = ImGui::GetWindowDrawList();

    drawList->AddRectFilled(canvasPos, ImVec2(canvasPos.x + canvasSize.x, canvasPos.y + canvasSize.y), IM_COL32(40, 40, 40, 255));

    float boxWidth = 30.f, boxHeight = 60.f, spacing = 50.f;

    // Enemy Preview
    ImVec2 topLeftE = ImVec2(canvasPos.x + canvasSize.x / 2.f - boxWidth / 2.f, canvasPos.y + 10.f);
    ImVec2 bottomRightE = ImVec2(topLeftE.x + boxWidth, topLeftE.y + boxHeight);

    // Allies preview
    ImVec2 topLeftA = ImVec2(topLeftE.x, bottomRightE.y + spacing);
    ImVec2 bottomRightA = ImVec2(topLeftA.x + boxWidth, topLeftA.y + boxHeight);

    // Drawbox
    if (enableBox2D)
    {
        if (boxStyle == 0) {
            drawList->AddRect(topLeftE, bottomRightE, colorInfectedBox2D, 0, 0, 1.5f);
            drawList->AddRect(topLeftA, bottomRightA, colorAllyBox2D, 0, 0, 1.5f);
        }
        else if (boxStyle == 1) {
            DrawCornerBoxImGui(topLeftE, ImVec2(boxWidth, boxHeight), colorInfectedBox2D, 1.5f);
            DrawCornerBoxImGui(topLeftA, ImVec2(boxWidth, boxHeight), colorAllyBox2D, 1.5f);
        }
    }

    // Healthbar
    if (enableHealthBar)
    {
        auto drawHealthBar = [&](ImVec2 pos, float ratio, ImColor color) {
            float width = 4.0f;
            float height = boxHeight;
            float barHeight = height * ratio;
            ImVec2 barTop = ImVec2(pos.x, pos.y + (height - barHeight));
            ImVec2 barBottom = ImVec2(pos.x + width, pos.y + height);
            drawList->AddRectFilled(pos, ImVec2(pos.x + width, pos.y + height), IM_COL32(50, 50, 50, 200));
            drawList->AddRectFilled(barTop, barBottom, color);
            };

        drawHealthBar(ImVec2(topLeftE.x - 6.f, topLeftE.y), 0.7f, colorInfectedHealth);
        drawHealthBar(ImVec2(topLeftA.x - 6.f, topLeftA.y), 0.9f, colorAllyHealth);
    }

    // Health Text
    if (enableHealthESP)
    {
        char hpE[16]; sprintf_s(hpE, "70");
        char hpA[16]; sprintf_s(hpA, "90");

        ImVec2 szE = ImGui::CalcTextSize(hpE);
        ImVec2 szA = ImGui::CalcTextSize(hpA);

        drawList->AddText({ topLeftE.x - szE.x - 10.f, topLeftE.y + boxHeight / 2.f - szE.y / 2.f }, colorInfectedHealth, hpE);
        drawList->AddText({ topLeftA.x - szA.x - 10.f, topLeftA.y + boxHeight / 2.f - szA.y / 2.f }, colorAllyHealth, hpA);
    }

    // Esp Name
    if (enableESPName)
    {
        const char* enemyName = "ENEMY";
        const char* allyName = "ALLY";

        ImVec2 szE = ImGui::CalcTextSize(enemyName);
        ImVec2 szA = ImGui::CalcTextSize(allyName);

        drawList->AddText({ topLeftE.x + boxWidth / 2.f - szE.x / 2.f, topLeftE.y - szE.y - 2.f }, colorInfectedName, enemyName);
        drawList->AddText({ topLeftA.x + boxWidth / 2.f - szA.x / 2.f, topLeftA.y - szA.y - 2.f }, colorAllyName, allyName);
    }

    // Esp Distance
    if (enableDistance)
    {
        const char* enemyDist = "12.5m";
        const char* allyDist = "5.2m";

        ImVec2 szE = ImGui::CalcTextSize(enemyDist);
        ImVec2 szA = ImGui::CalcTextSize(allyDist);

        drawList->AddText({ topLeftE.x + boxWidth / 2.f - szE.x / 2.f, bottomRightE.y + 2.f }, colorInfectedDistance, enemyDist);
        drawList->AddText({ topLeftA.x + boxWidth / 2.f - szA.x / 2.f, bottomRightA.y + 2.f }, colorAllyDistance, allyDist);
    }

    float sepY = bottomRightE.y + spacing * 0.5f;
    drawList->AddLine({ canvasPos.x + 10, sepY }, { canvasPos.x + canvasSize.x - 10, sepY }, IM_COL32(80, 80, 80, 180), 1.0f);

    ImGui::Dummy(canvasSize);
    ImGui::End();
}

