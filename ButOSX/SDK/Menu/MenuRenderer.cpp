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

float clip(float n, float lower, float upper)
{
    n = (n > lower) * n + !(n > lower) * lower;
    return (n < upper) * n + !(n < upper) * upper;
}

float flAlpha;
static constexpr auto frequency = 1 / 0.55f;

bool CheatSettings::Visuals::blESP = false;
int pageID = 0;
bool ThemeLoaded = false;
void MenuRenderer::RenderMenu(bool _visible){ //It's where the menu begins.
    ImDrawList* _Back = ImGui::GetBackgroundDrawList();
    DrawWatermark(_Back);
    
    if(_visible){
        flAlpha = clip(flAlpha + frequency * ImGui::GetIO().DeltaTime, 0.f, 1.f);
        ImGui::GetStyle().Alpha = flAlpha;
        ImGui::Begin(xorstr("ButOSX - Godly Cheat of MACOSX"), NULL, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse);
        ImGui::SetWindowSize(ImVec2(500, 300));
        ImGui::SameLine();
        if(ImGui::Button(xorstr("Visuals"), ImVec2(100, 20))){
            pageID = 1;
        }
        ImGui::SameLine();
        if(ImGui::Button(xorstr("Assists"), ImVec2(100, 20))){
            pageID = 2;
        }
        ImGui::SameLine();
        if(ImGui::Button(xorstr("Miscs"), ImVec2(100, 20))){
            pageID = 3;
        }
        switch (pageID) {
            case 0:
                Pages::WelcomePage();
                break;
            case 1:
                Pages::VisualsPage();
                break;
            default:
                break;
        }
        ImGui::End();
    }
    else {
        flAlpha = 0.f;
    }
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

ImVec2 textsize;

ImColor rainbow(float speed) {
 
    static float x = 0, y = 0;
    static float r = 0, g = 0, b = 0;
 
    if( y >= 0.0f && y < 255.0f ) {
        r = 255.0f;
        g = 0.0f;
        b = x;
    }
    else if( y >= 255.0f && y < 510.0f ) {
        r = 255.0f - x;
        g = 0.0f;
        b = 255.0f;
    }
    else if( y >= 510.0f && y < 765.0f ) {
        r = 0.0f;
        g = x;
        b = 255.0f;
    }
    else if( y >= 765.0f && y < 1020.0f ) {
        r = 0.0f;
        g = 255.0f;
        b = 255.0f - x;
    }
    else if( y >= 1020.0f && y < 1275.0f ) {
        r = x;
        g = 255.0f;
        b = 0.0f;
    }
    else if( y >= 1275.0f && y < 1530.0f ) {
        r = 255.0f;
        g = 255.0f - x;
        b = 0.0f;
    }
            
    x+=0.25f * speed;
    if( x >= 255.0f )
        x = 0.0f;
 
    y+=0.25f * speed;
    if( y > 1530.0f )
        y = 0.0f;
 
 
    return ImColor((int)r, (int)g, (int)b, 255);
}


void MenuRenderer::DrawWatermark(ImDrawList* bruh){
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
    ImGui::ShadeVertsLinearColorGradientKeepAlpha(bruh, vert_start_idx, vert_end_idx, gradient_p0, gradient_p1, rainbow(1), rainbow(3));
    const char* watermark_text = (xorstr("ButOSX | hello Lyceion | ") + str).c_str();
    textsize = ImGui::CalcTextSize(watermark_text);
    bruh->AddText(ImVec2(WindowSize.x - (textsize.x + 60), 20 + (30 - textsize.y) / 2), ImColor(255, 255, 255, 255), watermark_text);
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

void Pages::WelcomePage(){ //Welcome page for one time show.
    ImGui::TextColored(ImVec4(1.f, 0, 0, 1.f), xorstr("Welcome VersteckteKrone!"));
    if(ImGui::Button(xorstr("UNHOOK!")))
        Hooker::Destroy();
}

void Pages::VisualsPage(){ //Page for visuals.
    ImGui::Checkbox(xorstr("ESP"), &CheatSettings::Visuals::blESP);
}
