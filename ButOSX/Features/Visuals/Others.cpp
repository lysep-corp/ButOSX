//
//  Others.cpp
//  ButOSX
//
//  Created by Can Destan on 27.01.2021.
//  Copyright © 2021 VersteckteKrone. All rights reserved.
//

#include "Visuals.hpp"
#include "imgui.h"
#include "imgui_internal.h"
#include "CheatSettings.h"
#include "xorstr.h"

ImVec2 textsize;
bool CheatSettings::WaterMark = false;
void Visuals::Others::Watermark(ImDrawList* drawArea){ //Draws watermark which proudly written by me while i'm learning imgui in 2~3 hrs. LMAO
    if(!CheatSettings::WaterMark)
        return;
    ImVec2 WindowSize = ImGui::GetIO().DisplaySize;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer),xorstr("%d-%m-%Y %H:%M:%S"),timeinfo);
    std::string str(buffer);
    drawArea->AddRectFilled( /* start */ ImVec2(WindowSize.x - (textsize.x + 91), 19), /* finish */ ImVec2(WindowSize.x - 29, 51), IM_COL32(45, 45, 45, 255), (30 / 4));
    drawArea->AddRectFilled( /* start */ ImVec2(WindowSize.x - (textsize.x + 90), 20), /* finish */ ImVec2(WindowSize.x - 30, 50), IM_COL32(33, 33, 33, 255), (30 / 4));
    drawArea->AddRectFilled(ImVec2(WindowSize.x - (textsize.x + 91), 45), ImVec2(WindowSize.x - 29, 51), ImColor(253, 112, 0, 255), 6, ImDrawCornerFlags_Bot);
    const char* watermark_text = (xorstr("ButOSX | hello Lyceion & xMuraty | ") + str).c_str();
    textsize = ImGui::CalcTextSize(watermark_text);
    drawArea->AddText(ImVec2(WindowSize.x - (textsize.x + 60), 20 + (30 - (textsize.y + 6)) / 2), ImColor(255, 255, 255, 255), watermark_text);
}
