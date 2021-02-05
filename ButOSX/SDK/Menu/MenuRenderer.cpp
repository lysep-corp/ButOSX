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

char *Pages::PageList[8]{
    (char *)"VISUALS",
    (char *)"ASSISTS",
    (char *)"CHANGERS",
    (char *)"MISCS",
    (char *)"SETTINGS"
};

float clip(float n, float lower, float upper)
{
    n = (n > lower) * n + !(n > lower) * lower;
    return (n < upper) * n + !(n < upper) * upper;
}


ImFont* g_Büyük;
ImFont* g_GirisFontBüyük;
ImFont* g_Font;
static ImVec2 WindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
void MenuRenderer::RenderMenu(bool _visible){
    const char* CheatName = xorstr("ButOSX - Godly Cheat of MACOSX");
    static bool chinaVisible = false;
    static float flAlpha = 0;
    if(_visible){
        chinaVisible = true;
        flAlpha = clip(flAlpha + (1 / 0.85f) * ImGui::GetIO().DeltaTime, 0.f, 1.f);
    }
    else{
        if(flAlpha == 0.f)
            chinaVisible = false;
        flAlpha = clip(flAlpha - (1 / 0.85f) * ImGui::GetIO().DeltaTime, 0.f, 1.f);
    }
    if(chinaVisible){
        static ImVec2 ScreenSize;
        static ImGuiStyle& style = ImGui::GetStyle();
        style.Alpha = flAlpha;
        style.WindowRounding = WINDOW_PADDING;
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.12f, style.Alpha);
        style.Colors[ImGuiCol_Button] = ImVec4(0.11f, 0.11f, 0.11f, style.Alpha);
        style.Colors[ImGuiCol_Border] = ImVec4(0.11f, 0.11f, 0.11f, style.Alpha);
        style.WindowBorderSize = 0;
        style.ChildBorderSize = 0.01f;
        ImGui::SetNextWindowSize(WindowSize);
        ImGui::SetNextWindowBgAlpha(style.Alpha);
        static int selected_Tab = 0;
        static bool isFullscreen = false;
        static ImGuiWindowFlags UI_FLAGS = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
        ImGui::Begin(CheatName, NULL, UI_FLAGS); {
            static ImGuiWindow* window = ImGui::GetCurrentWindow();
            static ImDrawList* UI = window->DrawList;
            static ImVec2 oldWinPos;
            //Fullscreen Mode
            if(!isFullscreen){
                if(ImGui::GetWindowPos().x == 0 && ImGui::GetWindowPos().y == 0)
                    ImGui::SetWindowPos(oldWinPos);
                WindowSize = ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT);
                UI_FLAGS = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
            }
            else{
                if(ImGui::GetWindowPos().x != 0.f && ImGui::GetWindowPos().y != 0.f)
                    oldWinPos = ImGui::GetWindowPos();
                ImGui::SetWindowPos(ImVec2(0,0));
                WindowSize = ImGui::GetIO().DisplaySize;
                UI_FLAGS |= ImGuiWindowFlags_NoMove;
            }
            
            //UI TITLE
            ImGui::PushFont(g_Büyük);
            UI->AddText(ImVec2((ImGui::GetWindowPos().x + WindowSize.x) - (ImGui::CalcTextSize(CheatName).x + WINDOW_PADDING), ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) - ImGui::CalcTextSize(CheatName).y), ImColor(1.0f, 1.0f, 1.0f, style.Alpha), CheatName);
            ImGui::PopFont();
            UI->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 1), ImVec2(ImGui::GetWindowPos().x + WindowSize.x - WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 2), ImColor(1.0f, 1.0f, 1.0f, style.Alpha));
            
            //CONTROLBOX
            CustomWidgets::ControlBox(SDLHook::Unhook, &SDLHook::_visible, &isFullscreen);
            
            //TABs Renderer
            ImGui::PushFont(g_GirisFontBüyük);
            static int PageCount = 5 /*sizeof(Pages::PageList[0]) / sizeof(Pages::PageList)*/;
            ImVec2 TabSize = ImVec2((WindowSize.x - (WINDOW_PADDING * 2)) / PageCount, WINDOW_PADDING * 2);
            //UI->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3.5f)), ImVec2(ImGui::GetWindowPos().x + WindowSize.x - (WINDOW_PADDING + 2.0), ImGui::GetWindowPos().y + (WINDOW_PADDING * 3.5f) + TabSize.y), ImColor(0.20f, 0.20f, 0.20f, style.Alpha));
            for(int i = 0; i <= PageCount - 1; i++){
                style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, flAlpha);
                const char* PageName = Pages::PageList[i];
                ImVec2 PageNameSize = ImGui::CalcTextSize(PageName);
                ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (TabSize.x * i), WINDOW_PADDING * 3.5f));
                if (CustomWidgets::SubTab(PageName, TabSize, selected_Tab == i ? true : false))
                    selected_Tab = i;
                ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (((TabSize.x * (i + 1)) - PageNameSize.x) / 2) + ((TabSize.x * i) / 2), (WINDOW_PADDING * 3.5f) + ((TabSize.y - PageNameSize.y - 4) / 2)));
                ImGui::Text("%s", xorstr(PageName));
            }
            switch (selected_Tab){
                case 0:
                    Pages::VisualsPage();
                    break;
                case 1:
                    Pages::AssistsPage();
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    Pages::SettingsPage();
                    break;
            }
            //UI->AddRectFilled(ImVec2(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y + WindowSize.y - 4), ImVec2(ImGui::GetWindowPos().x + WindowSize.x, ImGui::GetWindowPos().y + WindowSize.y + 2), ImColor(0.99f, 0.43f, 0.f, style.Alpha), 3, ImDrawCornerFlags_Bot);
            ScreenSize = ImGui::GetIO().DisplaySize;
            ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ScreenSize, ImColor(0.f, 0.f, 0.f, (style.Alpha / 1.2f)));
        }
        ImGui::PopFont();
        ImGui::End();
    }
    else {
        flAlpha = 0;
    }
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

void Pages::VisualsPage(){ //Page for visuals.
    ImGui::PushFont(g_Font);
    static int ChildCount = 3;
    ImVec2 ChildSize = ImVec2((WindowSize.x - (WINDOW_PADDING * 2)) / ChildCount, WindowSize.y - ((WINDOW_PADDING * 7.5f ) + 5) );
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 0), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##1"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
        CustomWidgets::Switch(xorstr("Watermark"), &CheatSettings::WaterMark);
        CustomWidgets::Switch(xorstr("ESP"), &CheatSettings::ESP);
    }
    ImGui::EndChild();
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 1), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##2"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
    }
    ImGui::EndChild();
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 2), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##3"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);
    {
    }
    ImGui::EndChild();
    ImGui::PopFont();
}

void Pages::AssistsPage(){ //Page for assists.
    ImGui::PushFont(g_Font);
    static int ChildCount = 1;
    ImVec2 ChildSize = ImVec2((WindowSize.x - (WINDOW_PADDING * 2)) / ChildCount, WindowSize.y - ((WINDOW_PADDING * 7.5f ) + 5) );
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 0), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##2"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
        
    }
    ImGui::EndChild();
    ImGui::PopFont();
}


static bool TEST = false;
void Pages::SettingsPage(){ //Page for settings;
    static ImVec4 COL = ImVec4(0.99f, 0.43f, 0.f, ImGui::GetStyle().Alpha);
    ImGui::GetStyle().Colors[ImGuiCol_Border] = COL;
    ImGui::GetStyle().WindowBorderSize = 1;
    ImGui::Begin(xorstr("UI Tests"), NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar);{
        ImGui::PushFont(g_Font);
        ImGui::SetWindowSize(ImVec2(150, WINDOW_HEIGHT));
        ImGui::SetWindowPos(ImVec2(ImGui::FindWindowByName(xorstr("ButOSX - Godly Cheat of MACOSX"))->Pos.x + WINDOW_WIDTH + 30, ImGui::FindWindowByName(xorstr("ButOSX - Godly Cheat of MACOSX"))->Pos.y));
        ImGui::SetCursorPos(ImVec2(10, 30));
        CustomWidgets::Switch(xorstr("TEST OLUR GIBI"), &CheatSettings::NightMode);
        ImGui::SameLine();
        CustomWidgets::Spinner(16, 5, 100, COL);
        if(TEST){
            ImGui::GetWindowDrawList()->AddRect(ImVec2(ImGui::GetWindowPos().x + 10, ImGui::GetWindowPos().y + 80), ImVec2(ImGui::GetWindowPos().x + 140, ImGui::GetWindowPos().y + WINDOW_HEIGHT - 40), ImColor(0.f, 1.0f, 0.f, ImGui::GetStyle().Alpha));
            ImGui::SetCursorPos(ImVec2((10 + 140 - ImGui::CalcTextSize(xorstr("Lyceion")).x) / 2.f, WINDOW_HEIGHT - 35));
            ImGui::Text("%s", xorstr("Lyceion"));
        }
        ImGui::PopFont();
    }
    ImGui::End();
}
