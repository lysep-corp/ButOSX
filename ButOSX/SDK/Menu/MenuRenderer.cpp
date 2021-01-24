//
//  MenuRenderer.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#include "MenuRenderer.hpp"
#include "xorstr.h"
#include "CheatSettings.h"
#include "MainHooker.hpp"
#include "CustomWidgets.hpp"

float clip(float n, float lower, float upper)
{
    n = (n > lower) * n + !(n > lower) * lower;
    return (n < upper) * n + !(n < upper) * upper;
}

ImFont* g_Büyük;
ImFont* g_GirisFontBüyük;
ImFont* g_Font;
bool CheatSettings::WaterMark;
void MenuRenderer::RenderMenu(bool _visible){
    static float flAlpha = 0;
    ImDrawList* DrawList = ImGui::GetBackgroundDrawList(); 
    DrawWatermark(DrawList);
    if(_visible){
        const char* CheatName = xorstr("ButOSX - Godly Cheat of MACOSX");
        ImGuiStyle& style = ImGui::GetStyle();
        flAlpha = clip(flAlpha + (1 / 0.55f) * ImGui::GetIO().DeltaTime, 0.f, 1.f);
        style.Alpha = flAlpha;
        style.WindowRounding = 12;
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.13f, 0.13f, 1.00f);
        ImGui::SetNextWindowSize(ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT));
        ImGui::SetNextWindowBgAlpha(flAlpha);
        static int selected_Tab = 0;
        ImGui::Begin(CheatName, NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar); {
            ImGui::SetCursorPosY(1);
            ImGui::PushFont(g_Büyük);
            ImGui::SetCursorPosX(WINDOW_WIDTH - (ImGui::CalcTextSize(CheatName).x + 12));
            ImGui::Text(CheatName);
            ImGui::PopFont();
            ImGuiWindow* window = ImGui::GetCurrentWindow();
            window->DrawList->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + 12, ImGui::GetWindowPos().y + 47), ImVec2(ImGui::GetWindowPos().x + WINDOW_WIDTH - 12, ImGui::GetWindowPos().y + 48), ImColor(255, 255, 255, 255));
            style.FrameRounding = 12;
            style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.36f, 0.33f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.36f, 0.33f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 0.36f, 0.33f, 1.00f);
            style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);
            ImGui::SetCursorPosY(9);
            if (ImGui::Button("s", ImVec2(10, 10))){
                Hooker::Destroy();
            }
            style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.76f, 0.20f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.76f, 0.20f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 0.76f, 0.20f, 1.00f);
            style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);
            ImGui::SetCursorPosY(9);
            ImGui::SetCursorPosX(25);
            if (ImGui::Button("a", ImVec2(10, 10))){
                SDLHook::_visible = false;
            }
            style.Colors[ImGuiCol_Button] = ImVec4(0.14f, 0.49f, 0.20f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.14f, 0.49f, 0.20f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.14f, 0.49f, 0.20f, 1.00f);

            style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 0.00f);
            ImGui::SetCursorPosY(9);
            ImGui::SetCursorPosX(40);
            if (ImGui::Button("d", ImVec2(10, 10)))
            {
                //FULLSCREEN;
            }
            style.FrameRounding = 0;
            style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
            ImGui::SetCursorPosY(55);
            ImGui::SetCursorPosX(12);
            if (CustomWidgets::SubTab("", ImVec2(155, 43), selected_Tab == 0 ? true : false))
                selected_Tab = 0;
            style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
            style.WindowRounding = 11;
            ImGui::SetCursorPosY(60);
            ImGui::SetCursorPosX(60);
            ImGui::PushFont(g_GirisFontBüyük);
            ImGui::Text("Visuals");
            ImGui::SetCursorPosY(55);
            ImGui::SetCursorPosX(170);
            if (CustomWidgets::SubTab("Misc", ImVec2(155, 43), selected_Tab == 1 ? true : false))
                selected_Tab = 1;
            ImGui::SetCursorPosY(60);
            ImGui::SetCursorPosX(230);
            ImGui::Text("Misc");
            ImGui::SetCursorPosY(55);
            ImGui::SetCursorPosX(325);
            if (CustomWidgets::SubTab("Changers", ImVec2(155, 43), selected_Tab == 2 ? true : false))
                selected_Tab = 2;
            ImGui::SetCursorPosY(60);
            ImGui::SetCursorPosX(370);
            ImGui::Text("Changers");
            ImGui::SetCursorPosY(55);
            ImGui::SetCursorPosX(480);
            if (CustomWidgets::SubTab("Miscs", ImVec2(155, 43), selected_Tab == 3 ? true : false))
                selected_Tab = 3;
            ImGui::SetCursorPosY(60);
            ImGui::SetCursorPosX(535);
            ImGui::Text("Miscs");
            ImGui::SetCursorPosY(55);
            ImGui::SetCursorPosX(635);
            if (CustomWidgets::SubTab("Settings", ImVec2(155, 43), selected_Tab == 4 ? true : false))
                selected_Tab = 4;
            ImGui::SetCursorPosY(60);
            ImGui::SetCursorPosX(685);
            ImGui::Text("Settings");
            ImGui::SetCursorPosY(145);
            ImVec2 curPos = ImGui::GetCursorPos();
            ImVec2 curWindowPos = ImGui::GetWindowPos();
            curPos.x += curWindowPos.x;
            curPos.y += curWindowPos.y;
            window->DrawList->AddRectFilled(ImVec2(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y + WINDOW_HEIGHT - 5), ImVec2(ImGui::GetWindowPos().x + WINDOW_WIDTH, ImGui::GetWindowPos().y + WINDOW_HEIGHT), ImColor(253, 112, 0, 255));
            switch (selected_Tab){
                case 0:
                    //RENDER VISUALS PAGE
                    Pages::VisualsPage();
                    break;
                case 1:
                    //RENDER ASSISTS PAGE
                    break;
                case 2:
                    //RENDER CHANGERS PAGE
                    break;
                case 3:
                    //RENDER MISCS PAGE
                    break;
                case 4:
                    //RENDER SETTINGS PAGE
                break;
            }
            ImGui::PopFont();
        }
        ImGui::End();
    }
    else {
        flAlpha = 0;
    }
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}


void MenuRenderer::InitTheme(){ //Loads theme, theme is the vgui's theme. Which stolen from: https://github.com/ocornut/imgui/issues/707#issuecomment-576867100
    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text]                              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_TextDisabled]              = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    colors[ImGuiCol_WindowBg]                          = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
    colors[ImGuiCol_ChildBg]                                = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
    colors[ImGuiCol_PopupBg]                                = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
    colors[ImGuiCol_Border]                          = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
    colors[ImGuiCol_BorderShadow]              = ImVec4(0.14f, 0.16f, 0.11f, 0.52f);
    colors[ImGuiCol_FrameBg]                                = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
    colors[ImGuiCol_FrameBgHovered]          = ImVec4(0.27f, 0.30f, 0.23f, 1.00f);
    colors[ImGuiCol_FrameBgActive]            = ImVec4(0.30f, 0.34f, 0.26f, 1.00f);
    colors[ImGuiCol_TitleBg]                                = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
    colors[ImGuiCol_TitleBgActive]            = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
    colors[ImGuiCol_TitleBgCollapsed]          = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    colors[ImGuiCol_MenuBarBg]                        = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
    colors[ImGuiCol_ScrollbarBg]                    = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab]            = ImVec4(0.28f, 0.32f, 0.24f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.25f, 0.30f, 0.22f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.23f, 0.27f, 0.21f, 1.00f);
    colors[ImGuiCol_CheckMark]                        = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    colors[ImGuiCol_SliderGrab]                      = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]          = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
    colors[ImGuiCol_Button]                          = ImVec4(0.29f, 0.34f, 0.26f, 0.40f);
    colors[ImGuiCol_ButtonHovered]            = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
    colors[ImGuiCol_ButtonActive]              = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
    colors[ImGuiCol_Header]                          = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
    colors[ImGuiCol_HeaderHovered]            = ImVec4(0.35f, 0.42f, 0.31f, 0.6f);
    colors[ImGuiCol_HeaderActive]              = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
    colors[ImGuiCol_Separator]                        = ImVec4(0.14f, 0.16f, 0.11f, 1.00f);
    colors[ImGuiCol_SeparatorHovered]          = ImVec4(0.54f, 0.57f, 0.51f, 1.00f);
    colors[ImGuiCol_SeparatorActive]                = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    colors[ImGuiCol_ResizeGrip]                      = ImVec4(0.19f, 0.23f, 0.18f, 0.00f); // grip invis
    colors[ImGuiCol_ResizeGripHovered]        = ImVec4(0.54f, 0.57f, 0.51f, 1.00f);
    colors[ImGuiCol_ResizeGripActive]          = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    colors[ImGuiCol_Tab]                                    = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
    colors[ImGuiCol_TabHovered]                      = ImVec4(0.54f, 0.57f, 0.51f, 0.78f);
    colors[ImGuiCol_TabActive]                        = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    colors[ImGuiCol_TabUnfocused]              = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
    colors[ImGuiCol_TabUnfocusedActive]      = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
    //colors[ImGuiCol_DockingPreview]          = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    //colors[ImGuiCol_DockingEmptyBg]          = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    colors[ImGuiCol_PlotLines]                        = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    colors[ImGuiCol_PlotLinesHovered]          = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    colors[ImGuiCol_PlotHistogram]            = ImVec4(1.00f, 0.78f, 0.28f, 1.00f);
    colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    colors[ImGuiCol_TextSelectedBg]          = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    colors[ImGuiCol_DragDropTarget]          = ImVec4(0.73f, 0.67f, 0.24f, 1.00f);
    colors[ImGuiCol_NavHighlight]              = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
    colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    colors[ImGuiCol_NavWindowingDimBg]        = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    colors[ImGuiCol_ModalWindowDimBg]          = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

    ImGuiStyle& style = ImGui::GetStyle();
    style.FrameBorderSize = 1.0f;
    style.WindowRounding = 0.0f;
    style.ChildRounding = 0.0f;
    style.FrameRounding = 0.0f;
    style.PopupRounding = 0.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabRounding = 0.0f;
    style.TabRounding = 0.0f;
    style.WindowMinSize = ImVec2(500, 300);
}

void Pages::VisualsPage(){ //Page for visuals.
    ImGui::PushFont(g_Font);
    ImGui::SetCursorPosY(115);
    ImGui::SetCursorPosX(12);
    ImGui::BeginChild("##1", ImVec2{ 250, 260 }, true, ImGuiWindowFlags_NoScrollbar);{
        CustomWidgets::Switch("Watermark", &CheatSettings::WaterMark);
        CustomWidgets::Switch("ESP", &CheatSettings::ESP);
    }
    ImGui::EndChild();
    ImGui::SetCursorPosY(115);
    ImGui::SetCursorPosX(274);
    ImGui::BeginChild("##2", ImVec2{ 250, 260 }, true, ImGuiWindowFlags_NoScrollbar);{
    }
    ImGui::EndChild();
    ImGui::SetCursorPosY(115);
    ImGui::SetCursorPosX(536);
    ImGui::BeginChild("##3", ImVec2{ 250, 260 }, true, ImGuiWindowFlags_NoScrollbar);
    {
    }
    ImGui::EndChild();
    ImGui::PopFont();
}

ImVec2 textsize;
void MenuRenderer::DrawWatermark(ImDrawList* bruh){ //Draws watermark which proudly written by me while i'm learning imgui in 2~3 hrs. LMAO
    if(!CheatSettings::WaterMark)
        return;
    ImVec2 WindowSize = ImGui::GetIO().DisplaySize;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
    std::string str(buffer);
    bruh->AddRectFilled( /* start */ ImVec2(WindowSize.x - (textsize.x + 91), 19), /* finish */ ImVec2(WindowSize.x - 29, 51), IM_COL32(45, 45, 45, 255), (30 / 4));
    bruh->AddRectFilled( /* start */ ImVec2(WindowSize.x - (textsize.x + 90), 20), /* finish */ ImVec2(WindowSize.x - 30, 50), IM_COL32(33, 33, 33, 255), (30 / 4));
    const int vert_start_idx = bruh->VtxBuffer.Size;
    bruh->PathRect(ImVec2(WindowSize.x - (textsize.x + 91), 45), ImVec2(WindowSize.x - 29, 51), 6, 12);
    bruh->PathFillConvex(IM_COL32_WHITE);
    const int vert_end_idx = bruh->VtxBuffer.Size;
    ImVec2 gradient_p0(WindowSize.x - (textsize.x + 91), 45);
    ImVec2 gradient_p1(ImVec2(WindowSize.x - 29, 51));
    ImGui::ShadeVertsLinearColorGradientKeepAlpha(bruh, vert_start_idx, vert_end_idx, gradient_p0, gradient_p1, ImColor(253, 112, 0, 255), ImColor(253, 112, 0, 255));
    const char* watermark_text = (xorstr("ButOSX | hello Lyceion | ") + str).c_str();
    textsize = ImGui::CalcTextSize(watermark_text);
    bruh->AddText(ImVec2(WindowSize.x - (textsize.x + 60), 20 + (30 - textsize.y) / 2), ImColor(255, 255, 255, 255), watermark_text);
}
