//
//  MenuRenderer.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "MenuRenderer.hpp"
#include "xorstr.h"
#include "CheatSettings.h"
#include "MainHooker.hpp"
#include "CustomWidgets.hpp"
#include "../../ObjectiveCWrapper/ObjCWrapper.h"
#include "Visuals.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../../Thirdparty/stb/stb_image.h"


//PROUDLY PASTED
// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromMemory(stbi_uc const *buffer, int len, int *x, int *y, GLuint* out_texture)
{
    // Load from file
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data_buffer = stbi_load_from_memory(buffer, len, x, y, NULL, 4);
    if (image_data_buffer == NULL)
        return false;

    // Create a OpenGL texture identifier
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data_buffer);
    stbi_image_free(image_data_buffer);

    *out_texture = image_texture;
    *x = image_width;
    *y = image_height;

    return true;
}

char *Pages::PageList[]{
    (char *)"VISUALS ",
    (char *)"ASSISTS ",
    (char *)"CHANGERS",
    (char *)"MISCS   ",
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
static ImVec2 MainWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
static ImVec2 MainWindowPos;
int my_image_width = 0;
int my_image_height = 0;
GLuint my_image_texture = 0;
void MenuRenderer::RenderMenu(bool _visible){
    const char* CheatName = xorstr("ButOSX - Godly Cheat of MACOSX");
    static bool chinaVisible = false;
    static float flAlpha = 0;
    static bool GetUserData = false;
    if(!GetUserData){
        GetUserDatas(); /*Yeah B1g Data Grabber*/
//        bool ret = LoadTextureFromMemory(UserData::ImageBuffer, sizeof(UserData::ImageBuffer), &my_image_width, &my_image_height, &my_image_texture);
//        if(ret){
//            printf("OK!");
//            printf("%d", my_image_texture);
//            printf("%d", my_image_height);
//            printf("%d", my_image_width);
//            GetUserData = true;
//        }
        GetUserData = true;
    }
    if(_visible){
        chinaVisible = true;
        flAlpha = clip(flAlpha + (1 / 0.15f) * ImGui::GetIO().DeltaTime, 0.f, 1.f);
    }
    else{
        if(flAlpha == 0.f)
            chinaVisible = false;
        flAlpha = clip(flAlpha - (1 / 0.15f) * ImGui::GetIO().DeltaTime, 0.f, 1.f);
    }
    if(chinaVisible){
        static ImVec2 ScreenSize;
        static ImGuiStyle& style = ImGui::GetStyle();
        style.Alpha = flAlpha;
        style.WindowRounding = WINDOW_PADDING / 2;
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.12f, style.Alpha);
        style.Colors[ImGuiCol_Button] = ImVec4(0.11f, 0.11f, 0.11f, style.Alpha);
        style.Colors[ImGuiCol_Border] = ImVec4(0.11f, 0.11f, 0.11f, style.Alpha);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize | ImGuiStyleVar_ChildBorderSize, 0);
        ImGui::SetNextWindowSize(MainWindowSize);
        ImGui::SetNextWindowBgAlpha(style.Alpha);
        static int selected_Tab = 0;
        static bool isFullscreen = false;
        static ImGuiWindowFlags UI_FLAGS = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
        ImGui::Begin(CheatName, NULL, UI_FLAGS); {
            ImGui::PopStyleVar();
            MainWindowPos = ImGui::GetWindowPos();
            static ImGuiWindow* window = ImGui::GetCurrentWindow();
            static ImDrawList* UI = window->DrawList;
            static ImVec2 oldWinPos;
            //Fullscreen Mode
            if(!isFullscreen){
                if(ImGui::GetWindowPos().x == 0 && ImGui::GetWindowPos().y == 0)
                    ImGui::SetWindowPos(oldWinPos);
                MainWindowSize = ImVec2(WINDOW_WIDTH, WINDOW_HEIGHT);
                UI_FLAGS = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar;
            }
            else{
                if(ImGui::GetWindowPos().x != 0.f && ImGui::GetWindowPos().y != 0.f)
                    oldWinPos = ImGui::GetWindowPos();
                ImGui::SetWindowPos(ImVec2(0,0));
                MainWindowSize = ImGui::GetIO().DisplaySize;
                UI_FLAGS |= ImGuiWindowFlags_NoMove;
            }
            
            //UI TITLE
            ImGui::PushFont(g_Büyük);
            UI->AddText(ImVec2((ImGui::GetWindowPos().x + MainWindowSize.x) - (ImGui::CalcTextSize(CheatName).x + WINDOW_PADDING), ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) - ImGui::CalcTextSize(CheatName).y), ImColor(1.0f, 1.0f, 1.0f, style.Alpha), CheatName);
            ImGui::PopFont();
            UI->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 1), ImVec2(ImGui::GetWindowPos().x + MainWindowSize.x - WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 2), ImColor(1.0f, 1.0f, 1.0f, style.Alpha));
            
            //CONTROLBOX
            CustomWidgets::ControlBox(SDLHook::Unhook, &SDLHook::_visible, &isFullscreen);
            
            //TABs Renderer
            ImGui::PushFont(g_GirisFontBüyük);
            static int PageCount = 5 /*sizeof(Pages::PageList[0]) / sizeof(Pages::PageList)*/;
            ImVec2 TabSize = ImVec2((MainWindowSize.x - (WINDOW_PADDING * 2)) / PageCount, WINDOW_PADDING * 2);
            //UI->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3.5f)), ImVec2(ImGui::GetWindowPos().x + WindowSize.x - (WINDOW_PADDING + 2.0), ImGui::GetWindowPos().y + (WINDOW_PADDING * 3.5f) + TabSize.y), ImColor(0.20f, 0.20f, 0.20f, style.Alpha));
            for(int i = 0; i <= PageCount - 1; i++){
                style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, flAlpha);
                const char* PageName = Pages::PageList[i];
                ImVec2 PageNameSize = ImGui::CalcTextSize(PageName);
                ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (TabSize.x * i), WINDOW_PADDING * 3.5f));
                if (CustomWidgets::SubTab(PageName, TabSize, selected_Tab == i ? true : false))
                    selected_Tab = i;
                ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (((TabSize.x * (i + 1)) - PageNameSize.x) / 2) + ((TabSize.x * i) / 2), (WINDOW_PADDING * 3.5f) + ((TabSize.y - PageNameSize.y - 4) / 2)));
                ImGui::Text("%s", PageName);
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
            ScreenSize = ImGui::GetIO().DisplaySize;
            char array[5];
            sprintf(array, "%f", ImGui::GetIO().Framerate);
            ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ScreenSize, ImColor(0.f, 0.f, 0.f, (style.Alpha / 1.2f)));
            ImGui::GetBackgroundDrawList()->AddText(ImVec2(ScreenSize.x - (ImGui::CalcTextSize(array).x + 5), ImGui::CalcTextSize(array).y), ImColor(255,255,255), array);
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
    ImVec2 ChildSize = ImVec2((MainWindowSize.x - (WINDOW_PADDING * 2)) / ChildCount, MainWindowSize.y - ((WINDOW_PADDING * 7.5f ) + 5) );
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 0), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##1"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
        CustomWidgets::Switch(xorstr("ESP"), &CheatSettings::ESP::enabled);
        if(CheatSettings::ESP::enabled){
            ImGui::BeginChild(xorstr("##ESP"), ImVec2(ChildSize.x / 1.5f, 100), true, ImGuiWindowFlags_NoScrollbar);{
                ImGui::Checkbox(xorstr("Box"), &CheatSettings::ESP::box);
                ImGui::Checkbox(xorstr("Name"), &CheatSettings::ESP::name);
                ImGui::Checkbox(xorstr("Healthbar"), &CheatSettings::ESP::health);
                //ImGui::Checkbox(xorstr("Skeleton"), CheatSettings::ESP::skeleton);
            }
            ImGui::EndChild();
        }
        CustomWidgets::Switch(xorstr("Watermark"), &CheatSettings::WaterMark);
    }
    ImGui::EndChild();
    ImGui::PopFont();
    if(CheatSettings::ESP::enabled){
        static ImVec4 COL = ImVec4(0.99f, 0.43f, 0.f, ImGui::GetStyle().Alpha);
        ImGui::GetStyle().Colors[ImGuiCol_Border] = COL;
        ImGui::GetStyle().WindowBorderSize = 1;
        ImGui::Begin(xorstr("ESP Preview"), NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar);{
            ImGui::PushFont(g_Font);
            ImVec2 WindowSize(300, WINDOW_HEIGHT);
            ImGui::SetWindowSize(WindowSize);
            ImGui::SetWindowPos(ImVec2(MainWindowPos.x + WINDOW_WIDTH + 30, MainWindowPos.y));
            static ImVec2 ESPBoxSize(150, WINDOW_HEIGHT - 100);
            static ImVec2 ESPBoxLocation(ImGui::GetWindowPos().x + ((WindowSize.x - ESPBoxSize.x) / 2), ImGui::GetWindowPos().y + ((WindowSize.y - ESPBoxSize.y) / 2));
            if(CheatSettings::ESP::box){
                ImGui::GetWindowDrawList()->AddRect(ESPBoxLocation, ImVec2(ESPBoxLocation.x + ESPBoxSize.x, ESPBoxLocation.y + ESPBoxSize.y), ImColor(0.f, 1.0f, 0.f, ImGui::GetStyle().Alpha));
            }
            //static ImVec2 HealthBarSize(3, ESPSize.y);
            //static ImVec2 HealthBarPos(BoxPos.x - 5, BoxPos.y);
            if(CheatSettings::ESP::health){
                //ImGui::GetWindowDrawList()->AddRect(HealthBarPos, ImVec2(ImGui::GetWindowSize().x + HealthBarPos.x + HealthBarSize.x, ImGui::GetWindowSize().y + HealthBarPos.y + HealthBarSize.y), ImColor(1.f, 0.f, 0.f, ImGui::GetStyle().Alpha));
               // BoxPos.x = (ImGui::GetWindowPos().x + (ImGui::GetWindowSize().x - ESPSize.x) / 2) + 5;
            }
            else{
                ESPBoxLocation.x = ImGui::GetWindowPos().x + ((WindowSize.x - ESPBoxSize.x) / 2);
            }
            if(CheatSettings::ESP::name){
                ImGui::SetCursorPos(ImVec2((WindowSize.x - ImGui::CalcTextSize(xorstr("Lyceion")).x) / 2.f, ESPBoxLocation.y - ImGui::GetWindowPos().y - ImGui::CalcTextSize(xorstr("Lyceion")).y));
                ImGui::Text("%s", xorstr("Lyceion"));
                ESPBoxLocation.y = ImGui::GetWindowPos().y + ImGui::CalcTextSize(xorstr("Lyceion")).y + ((WindowSize.y - ESPBoxSize.y) / 2);
            }
            else{
                ESPBoxLocation.y = ImGui::GetWindowPos().y + ((WindowSize.y - ESPBoxSize.y) / 2);
            }
            ImGui::PopFont();
        }
        ImGui::End();
    }
}

void Pages::AssistsPage(){ //Page for assists.
    ImGui::PushFont(g_Font);
    static int ChildCount = 1;
    ImVec2 ChildSize = ImVec2((MainWindowSize.x - (WINDOW_PADDING * 2)) / ChildCount, MainWindowSize.y - ((WINDOW_PADDING * 7.5f ) + 5) );
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
        ImGui::SetWindowPos(ImVec2(MainWindowPos.x + WINDOW_WIDTH + 30, MainWindowPos.y));
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
