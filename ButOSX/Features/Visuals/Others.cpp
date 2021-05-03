//
//  Others.cpp
//  ButOSX
//
//  Created by Can Destan on 27.01.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "Visuals.hpp"
#include "imgui.h"
#include "imgui_internal.h"
#include "CheatSettings.h"
#include "xorstr.h"
#include "PatternScanner.hpp"
#include "OpenGLHooker.hpp"
#include "TouchBar.h"

ImVec2 textsize;
void Visuals::Others::Watermark(ImDrawList* drawArea){ //Draws watermark which proudly written by me while i'm learning imgui in 2~3 hrs. LMAO
    if(!visButton_Watermark->state)
        return;
    ImGui::PushFont(g_GirisFontBüyük);
    ImVec2 WindowSize = ImGui::GetIO().DisplaySize;
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,sizeof(buffer), xorstr("%d-%m-%Y %H:%M:%S"), timeinfo);
    std::string str(buffer);
    drawArea->AddRectFilled( /* start */ ImVec2(WindowSize.x - (textsize.x + 91), 19), /* finish */ ImVec2(WindowSize.x - 29, 51), IM_COL32(45, 45, 45, 255), (30 / 4));
    drawArea->AddRectFilled( /* start */ ImVec2(WindowSize.x - (textsize.x + 90), 20), /* finish */ ImVec2(WindowSize.x - 30, 50), IM_COL32(33, 33, 33, 255), (30 / 4));
    drawArea->AddRectFilled(ImVec2(WindowSize.x - (textsize.x + 91), 45), ImVec2(WindowSize.x - 29, 51), ImColor(253, 112, 0, 255), 6, ImDrawCornerFlags_Bot);
    string waterMarkBuff = xorstr("ButOSX | Welcome to, Lyceion/ButOSX | ") + str;
    const char* watermark_text = waterMarkBuff.c_str();
    textsize = ImGui::CalcTextSize(watermark_text);
    drawArea->AddText(ImVec2(WindowSize.x - (textsize.x + 60), 20 + (30 - (textsize.y + 6)) / 2), ImColor(255, 255, 255, 255), watermark_text);
    ImGui::PopFont();
}

void Visuals::Others::NightMode(){
    if(!visButton_NightMode->state)
        return;
    static bool bPerformed = false;
    if(!pEngine->IsInGame())
        return;
    C_BasePlayer* pLocal = (C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    if (pLocal->IsAlive()){
        if ( bPerformed != visButton_NightMode->state ){
            static ConVar* sv_skyname = pCvar->FindVar("sv_skyname");
            for (short h = pMaterialSystem->firstMaterial(); h != pMaterialSystem->invalidMaterial(); h = pMaterialSystem->nextMaterial(h)){
                auto material = pMaterialSystem->getMaterial(h);
                if ( !material )
                    continue;
                if (strstr( material->GetTextureGroupName(), ("World")) || strstr( material->GetTextureGroupName(), ("SkyBox")) || strstr( material->GetTextureGroupName(), ("StaticProp"))){
                    sv_skyname->SetValue("sky_csgo_night02");
                    material->ColorModulate( 0.1f, 0.1f, 0.1f );
                    pSurface->DrawSetColor(0,0,0, 125);
                    pSurface->DrawFilledRect(0, 0, ImGui::GetIO().DisplaySize.x, ImGui::GetIO().DisplaySize.y); //B1g feature yeah
                }
            }
            bPerformed = visButton_NightMode->state;
        }
    }
}

void Visuals::Others::NoVisRecoil(){
    if(!visButton_NoVisRecoil->state)
        return;
    if(!pEngine->IsInGame())
        return;
    
    C_BasePlayer* pLocal = (C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    QAngle* apg = pLocal->GetViewPunchAngle();
    QAngle* vpa = pLocal->GetViewPunchAngle();
    if (apg)
        *apg = QAngle(0, 0, 0);
    if (vpa)
        *vpa = QAngle(0, 0, 0);
}

void Visuals::Others::NoFlash(){
    if(!pEngine->IsInGame())
        return;
    
    C_BasePlayer* pLocal = (C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    if(visButton_NoFlash->state)
        *pLocal->GetFlashMaxAlpha() = 0.f;
    else
        *pLocal->GetFlashMaxAlpha() = 255.0f;
}

void Visuals::Others::SniperCrosshair(){
    if(!pEngine->IsInGame())
        return;
    
    ConVar* weapon_debug = pCvar->FindVar("weapon_debug_spread_show");
    if(!visButton_SniperCrosshair->state)
        weapon_debug->SetValue(0);
    
    C_BasePlayer* pLocal = (C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    if(pLocal->IsAlive() && !pLocal->IsScoped())
        weapon_debug->SetValue(2);
    else if(pLocal->IsAlive() && pLocal->IsScoped())
        weapon_debug->SetValue(0);
}

void Visuals::Others::RecoilCrosshair(){
    if(!pEngine->IsInGame())
        return;
    
    ConVar* recoil_cross = pCvar->FindVar("cl_crosshair_recoil");
    if(!visButton_RecoilCrosshair->state)
        recoil_cross->SetValue(0);
    
    C_BasePlayer* pLocal = (C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    if(pLocal->IsAlive() && !pLocal->IsScoped())
        recoil_cross->SetValue(1);
    else if(pLocal->IsAlive() && pLocal->IsScoped())
        recoil_cross->SetValue(0);
}
