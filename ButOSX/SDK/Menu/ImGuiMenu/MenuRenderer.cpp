//
//  MenuRenderer.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "MenuRenderer.hpp"

ImFont* g_Buyuk;
ImFont* g_GirisFontBüyük; //Not my code. A friends...
ImFont* g_Font;

char *Pages::PageList[]{
    (char *)"VISUALS ",
    (char *)"MISCS   ",
    (char *)"SETTINGS"
};

float clip(float n, float lower, float upper)
{
    n = (n > lower) * n + !(n > lower) * lower;
    return (n < upper) * n + !(n < upper) * upper;
}

static ImVec2 MainWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
void OpenDiscord(){
    std::string op = std::string(xorstr("open https://github.com/Lyceion"));
    system(op.c_str());
}

void HandleInputs(){
    pInputSystem->EnableInput(!butButton_Menu->state);
    
    ImGuiIO& gIO = ImGui::GetIO();
    //DEFAULT MENU KEY IS RIGHT ARROW or INSERT!!!
    //Open&Close Menu Key Handler
    
    if ( gIO.KeysDownDuration[SDL_SCANCODE_RIGHT] == 0.0f || gIO.KeysDownDuration[SDL_SCANCODE_INSERT] == 0.0f )
        butButton_Menu->state = !butButton_Menu->state;
    
    if(butButton_Menu->state){
        MenuRenderer::chinaVisible = true;
        MenuRenderer::flAlpha = clip(MenuRenderer::flAlpha + (1 / 0.15f) * ImGui::GetIO().DeltaTime, 0.f, 1.f);
    }
    else{
        if(MenuRenderer::flAlpha == 0.f)
            MenuRenderer::chinaVisible = false;
        
        MenuRenderer::flAlpha = clip(MenuRenderer::flAlpha - (1 / 0.15f) * ImGui::GetIO().DeltaTime, 0.f, 1.f);
    }
    
    gIO.MouseDrawCursor = butButton_Menu->state;
    gIO.WantCaptureMouse = butButton_Menu->state;
    gIO.WantCaptureKeyboard = butButton_Menu->state;
    
    UpdateButton(butButton_Menu);
}

void MenuRenderer::RenderMenu(){
    HandleInputs();
    if(chinaVisible){
        ImGui::StyleColorsDark();
        static ImGuiStyle& style = ImGui::GetStyle();
        style.Alpha = flAlpha;
        style.WindowRounding = WINDOW_PADDING / 2;
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.12f, style.Alpha);
        ImGui::SetNextWindowSize(MainWindowSize);
        ImGui::SetNextWindowBgAlpha(style.Alpha);
        static int selected_Tab = 0;
        ImGui::Begin(xorstr("ButOSX"), NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);{
            CustomWidgets::ControlBox(&butButton_Menu->state);
            
            //UI TITLE
            ImGui::PushFont(g_Buyuk);
            ImVec2 CheatTitleSize = ImGui::CalcTextSize(xorstr("ButOSX"));
            ImGui::GetWindowDrawList()->AddText(ImVec2((ImGui::GetWindowPos().x + MainWindowSize.x) - (CheatTitleSize.x + WINDOW_PADDING), ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) - CheatTitleSize.y), ImColor(1.0f, 1.0f, 1.0f, style.Alpha), xorstr("ButOSX"));
            ImGui::PopFont();
            ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 1), ImVec2(ImGui::GetWindowPos().x + MainWindowSize.x - WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 2), ImColor(1.0f, 1.0f, 1.0f, style.Alpha));
            
            
            ImGui::PushFont(g_GirisFontBüyük);
            static int PageCount = 3 /*sizeof(Pages::PageList[0]) / sizeof(Pages::PageList)*/;
            ImVec2 TabSize = ImVec2((MainWindowSize.x - (WINDOW_PADDING * 2)) / PageCount, WINDOW_PADDING * 2);
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
                    Pages::MiscsPage();
                    break;
                case 2:
                    Pages::SettingsPage();
                    break;
            }
            ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0, 0), ImGui::GetIO().DisplaySize, ImColor(0.f, 0.f, 0.f, (style.Alpha / 1.2f)));
        }
        ImGui::PopFont();
        ImGui::End();
    }
    else
        flAlpha = 0;
    
    MenuRenderer::MessageBox::Show(xorstr("WELCOME - ButOSX"), xorstr("Hello, welcome to ButOSX.\nCheat is sucsessfully injected. \nI'm Lyceion. It's a free, opensource software. If you paid for it, you are scammed. \nIf you liked the software, just visit my GitHub and star it. \nDiscord: @HiddenCrown#4558 if you have any questions."), xorstr("Yes, Please!"), OpenDiscord);
    
    //ImGui Functions
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

void Pages::VisualsPage(){ //Page for visuals.
    ImGui::PushFont(g_Font);
    static int ChildCount = 3;
    ImVec2 ChildSize = ImVec2((MainWindowSize.x - (WINDOW_PADDING * 2)) / ChildCount, MainWindowSize.y - ((WINDOW_PADDING * 7.5f ) + 5) );
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 0), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##0"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
        CustomWidgets::SwitchTouchbar(xorstr("ESP"), visButton_ESP);
        if(visButton_ESP->state){
            ImGui::BeginChild(xorstr("##ESP"), ImVec2(ChildSize.x / 1.5f, 100), true, ImGuiWindowFlags_NoScrollbar);{
                ImGui::Checkbox(xorstr("Box"), &CheatSettings::ESP::box);
                ImGui::Checkbox(xorstr("Name"), &CheatSettings::ESP::name);
                ImGui::Checkbox(xorstr("Healthbar"), &CheatSettings::ESP::health);
            }
            ImGui::EndChild();
        }
        CustomWidgets::SwitchTouchbar(xorstr("Watermark"), visButton_Watermark);
        CustomWidgets::SwitchTouchbar(xorstr("Night Mode"), visButton_NightMode);
        CustomWidgets::SwitchTouchbar(xorstr("Sniper Crosshair"), visButton_SniperCrosshair);
        CustomWidgets::SwitchTouchbar(xorstr("Recoil Crosshair"), visButton_RecoilCrosshair);
    }
    ImGui::EndChild();
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 1), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##1"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
        CustomWidgets::SwitchTouchbar(xorstr("No Visual Recoil"), visButton_NoVisRecoil);
        CustomWidgets::SwitchTouchbar(xorstr("No Flash"), visButton_NoFlash);
        CustomWidgets::SwitchTouchbar(xorstr("Grenade Prediction"), visButton_GrenadePrediction);
    }
    ImGui::EndChild();
    ImGui::PopFont();
}

void Pages::MiscsPage(){ //Page for miscs.
    ImGui::PushFont(g_Font);
    static int ChildCount = 1;
    ImVec2 ChildSize = ImVec2((MainWindowSize.x - (WINDOW_PADDING * 2)) / ChildCount, MainWindowSize.y - ((WINDOW_PADDING * 7.5f ) + 5) );
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 0), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##2"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
        CustomWidgets::SwitchTouchbar(xorstr("Bunny Hop"), miscButton_BunnyHop);
    }
    ImGui::EndChild();
    ImGui::PopFont();
}


void Pages::SettingsPage(){ //Page for settings;
    ImGui::PushFont(g_Font);
    static int ChildCount = 1;
    ImVec2 ChildSize = ImVec2((MainWindowSize.x - (WINDOW_PADDING * 2)) / ChildCount, MainWindowSize.y - ((WINDOW_PADDING * 7.5f ) + 5) );
    ImGui::SetCursorPos(ImVec2(WINDOW_PADDING + (ChildSize.x * 0), WINDOW_PADDING * 6.5f));
    ImGui::BeginChild(xorstr("##3"), ChildSize, true, ImGuiWindowFlags_NoScrollbar);{
        CustomWidgets::ColorPicker4(xorstr("Color Picker TEST"), setCol_ESP, 0);
    }
    ImGui::EndChild();
    ImGui::PopFont();
}

void MenuRenderer::MessageBox::Show(const char* Title, const char* Text, const char* ButtonText, void (*ButtonFunction)()){
    static bool show = true;
    if(show){
        ImGui::GetBackgroundDrawList()->AddRectFilled(ImVec2(0,0), ImGui::GetIO().DisplaySize, ImColor(0,0,0,212));
        static ImGuiStyle& style = ImGui::GetStyle();
        style.Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.12f, 1.0f);
        style.Colors[ImGuiCol_Button] = ImVec4(0.11f, 0.11f, 0.11f, 1.0f);
        style.Colors[ImGuiCol_Border] = ImVec4(0.99f, 0.43f, 0.f, 1.0f);
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.99f, 0.43f, 0.f, 1.0f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.79f, 0.23f, 0.f, 1.0f);
        style.WindowBorderSize = 1;
        static ImVec2 TitleSize = ImGui::CalcTextSize(Title);
        static ImVec2 TextSize  = ImGui::CalcTextSize(Text);
        static ImVec2 WindowSize= ImVec2(TextSize.x + (WINDOW_PADDING * 2), TextSize.y + WINDOW_PADDING * 7);
        ImGui::SetNextWindowSize(WindowSize);
        ImGui::SetNextWindowPos(ImVec2((ImGui::GetIO().DisplaySize.x - WindowSize.x) / 2, (ImGui::GetIO().DisplaySize.y - WindowSize.y) / 2));
        ImGui::Begin(Title, &show, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove); {
            
            //TITLE
            ImGui::PushFont(g_Buyuk);
            static ImGuiWindow* window = ImGui::GetCurrentWindow();
            static ImDrawList* UI = window->DrawList;
            UI->AddText(ImVec2(ImGui::GetWindowPos().x + WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 2) - TitleSize.y), ImColor(1.0f, 1.0f, 1.0f, 1.0f), Title);
            ImGui::PopFont();
            UI->AddRectFilled(ImVec2(ImGui::GetWindowPos().x + WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 1), ImVec2(ImGui::GetWindowPos().x + WindowSize.x - WINDOW_PADDING, ImGui::GetWindowPos().y + (WINDOW_PADDING * 3) + 2), ImColor(1.0f, 1.0f, 1.0f, 1.0f));
            ImGui::SetCursorPos(ImVec2(WINDOW_PADDING, WINDOW_PADDING * 4));
            ImGui::PushFont(g_GirisFontBüyük);
            ImGui::Text("%s", Text);
            ImGui::SetCursorPos(ImVec2(WINDOW_PADDING, WindowSize.y - (WINDOW_PADDING * 2.5)));
            if(ImGui::Button(ButtonText)){
                ButtonFunction();
            }
            ImGui::SameLine();
            if(ImGui::Button(xorstr("CLOSE")))
                show = false;
            ImGui::PopFont();
        }
        ImGui::End();
    }
}
