#include "Include.h"
#include "Menu.h"

// ToggleMenu (Insert)
void HandleMenuToggle() {
    static bool wasPressed = false;
    bool isPressed = GetAsyncKeyState(VK_INSERT) & 0x8000;
    if (isPressed && !wasPressed)
        menuOpen = !menuOpen;
    wasPressed = isPressed;
}

void DrawMenu() {
    ImGui::Begin("1SpiRaTioN", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

    if (ImGui::BeginTabBar("MainTabs")) {
        if (ImGui::BeginTabItem("ESP Visuals")) { DrawTabESP();       ImGui::EndTabItem(); }
        if (ImGui::BeginTabItem("Mouvements")) { DrawTabMouvement(); ImGui::EndTabItem(); }
        if (ImGui::BeginTabItem("Visuals")) { DrawTabVisuals();   ImGui::EndTabItem(); }
        if (ImGui::BeginTabItem("Custom")) { DrawTabCustom();    ImGui::EndTabItem(); }
        ImGui::EndTabBar();
    }

    ImGui::End();
}

void DrawTabESP() {
    ImGui::Checkbox("2D Box", &enableBox2D);
    if (enableBox2D) {
        const char* boxOptions[] = { "Box Classique", "Box Coin (Cutline)" };
        ImGui::Indent();
        ImGui::Checkbox("Show Allies", &showAllies);
        ImGui::SameLine();
        if (ImGui::Button("ESP Preview"))
            showEspPreview = !showEspPreview;
        ImGui::Combo("Style Box 2D", &boxStyle, boxOptions, IM_ARRAYSIZE(boxOptions));
        ImGui::Checkbox("HealthBar", &enableHealthBar);
        ImGui::Checkbox("Health ESP (valeur)", &enableHealthESP);
        ImGui::Checkbox("Distance", &enableDistance);
        ImGui::Separator();
        ImGui::Unindent();
    }
    ImGui::Separator();
    ImGui::Checkbox("Snapline", &enableSnapLine);
    ImGui::Checkbox("Show Esp Name", &enableESPName);
    ImGui::Separator();
    if (ImGui::Checkbox("Hide Debug Console", &hideDebugConsole)) {
        DebugConsole();
    }
    ImGui::Checkbox("Afficher cercle FOV (avec slider)", &enableFovSliderAndCircle);
    if (enableFovSliderAndCircle)
        ImGui::SliderFloat("FOV (personnalisé)", &fov_override, 30.0f, 150.0f);
}

void DrawTabMouvement() {
    ImGui::Checkbox("Bunnyhop", &enableBunnyhop);
}

void DrawTabVisuals() {
    ImGui::Checkbox("Custom Crosshairs", &enablecrosshair);
    if (enablecrosshair) {
        const char* crosshairOptions[] = { "Cross", "Dot", "Circle", "T-Cross" };
        ImGui::Combo("Crosshair Style", &crosshairStyle, crosshairOptions, IM_ARRAYSIZE(crosshairOptions));
    }
}

void DrawTabCustom() {
    ImGui::Text("Allies (Survivants)");
    ImGui::ColorEdit3("##AllySnaplineColor", (float*)&colorAllySnapline.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("Snaplines");
    ImGui::ColorEdit3("##AllyNameColor", (float*)&colorAllyName.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Name");
    ImGui::ColorEdit3("##AllyDistanceColor", (float*)&colorAllyDistance.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Distance");
    ImGui::ColorEdit3("##AllyHealthColor", (float*)&colorAllyHealth.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Health");
    ImGui::ColorEdit3("##AllyBox2DColor", (float*)&colorAllyBox2D.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("2D Box / Cutline");
    ImGui::Spacing();

    ImGui::Text("Infectés spéciaux (Boomer, Smoker...)");
    ImGui::ColorEdit3("##InfSnaplineColor", (float*)&colorInfectedSnapline.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("Snaplines");
    ImGui::ColorEdit3("##InfNameColor", (float*)&colorInfectedName.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Name");
    ImGui::ColorEdit3("##InfDistanceColor", (float*)&colorInfectedDistance.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Distance");
    ImGui::ColorEdit3("##InfHealthColor", (float*)&colorInfectedHealth.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Health");
    ImGui::ColorEdit3("##InfBox2DColor", (float*)&colorInfectedBox2D.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("2D Box / Cutline");
    ImGui::Spacing();

    ImGui::Text("Tank");
    ImGui::ColorEdit3("##TankSnaplineColor", (float*)&colorTankSnapline.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("Snaplines");
    ImGui::ColorEdit3("##TankNameColor", (float*)&colorTankName.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Name");
    ImGui::ColorEdit3("##TankDistanceColor", (float*)&colorTankDistance.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Distance");
    ImGui::ColorEdit3("##TankHealthColor", (float*)&colorTankHealth.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Health");
    ImGui::ColorEdit3("##TankBox2DColor", (float*)&colorTankBox2D.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("2D Box / Cutline");
    ImGui::Spacing();

    ImGui::Text("Infectés communs");
    ImGui::ColorEdit3("##CommSnaplineColor", (float*)&colorCommonSnapline.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("Snaplines");
    ImGui::ColorEdit3("##CommNameColor", (float*)&colorCommonName.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Name");
    ImGui::ColorEdit3("##CommDistanceColor", (float*)&colorCommonDistance.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Distance");
    ImGui::ColorEdit3("##CommHealthColor", (float*)&colorCommonHealth.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("ESP Health");
    ImGui::ColorEdit3("##CommBox2DColor", (float*)&colorCommonBox2D.Value, ImGuiColorEditFlags_NoInputs);
    ImGui::SameLine(); ImGui::Text("2D Box / Cutline");
    ImGui::Spacing();

    ImGui::Separator();
    ImGui::Text("Crosshair Color");
    ImGui::ColorEdit4("##CrosshairColor", (float*)&colorCrosshair, ImGuiColorEditFlags_NoInputs);
    ImGui::Spacing();

    if (ImGui::Button("Reset couleurs par défaut")) {
        ResetEspColors();
    }
}

void DrawCallBack() {
    HandleMenuToggle();

    if (!localPlayer) {
        UpdateLocalPlayer();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    Bunnyhop();

    if (menuOpen)
        DrawMenu();

    if (enableFovCircle && !enableFovSliderAndCircle)
        DrawFov();

    if (enableFovSliderAndCircle)
        DrawFovCircle(fov_override, ImColor(255, 255, 255), 1.5f);

    if (enableSnapLine)   DrawSnapline();
    if (enablecrosshair)  DrawCustomCrosshair();
    if (hideDebugConsole) DebugConsole();

    if (enableBox2D) {
        if (boxStyle == 0) Draw2DBox();
        else               DrawEspCutline();

        DrawEspPreviewWindow();

        if (enableHealthBar) DrawHealthBar();
        if (enableDistance)  DrawDistance();
        if (enableESPName)   DrawEspName();
        if (enableHealthESP) HealthEsp();
    }
}