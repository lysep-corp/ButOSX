//
//  Others.cpp
//  ButOSX
//
//  Created by Can Destan on 27.01.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "Visuals.hpp"
#include "imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"
#include "xorstr.h"
#include "OpenGLHooker.hpp"
#include "TouchBar.h"
#include "GameHooker.hpp"

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
typedef void (*LoadSkyNameFn) (const char*);
void Visuals::Others::NightMode(){
    if(!visButton_NightMode->state)
        return;
    static bool bPerformed = false;
    if(!pEngine->IsInGame())
        return;
    //auto const LoadSkyName = reinterpret_cast<LoadSkyNameFn>(GameHooker::sigScanner->get_procedure(xorstr("engine.dylib"), (unsigned char*)xorstr("x55\x48\x89\xE5\x41\x57\x41\x56\x41\x55\x41\x54\x53\x48\x81"), xorstr("xxxxxxxxxxxxxxx"))); //void R_LoadNamedSky(const char* SkyName) -> engine.dylib + 55 48 89 E5 41 57 41 56 41 55 41 54 53 48 81
    //LoadSkyName(xorstr("sky_csgo_night02"));
    static unique_ptr<ConVar>sv_skyname(pCvar->FindVar(xorstr("sv_skyname")));
    static const char* buffer = sv_skyname->GetString();
    static unique_ptr<C_BasePlayer>pLocal((C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer()));
    if (pLocal->IsAlive()){
        if (visButton_NightMode->state){
            for (short h = pMaterialSystem->firstMaterial(); h != pMaterialSystem->invalidMaterial(); h = pMaterialSystem->nextMaterial(h)){
                auto material = pMaterialSystem->getMaterial(h);
                if ( !material )
                    continue;
                if (strstr( material->GetTextureGroupName(), (xorstr("World"))) || strstr( material->GetTextureGroupName(), (xorstr("SkyBox"))) || strstr( material->GetTextureGroupName(), (xorstr("StaticProp")))){
                    sv_skyname->SetValue(xorstr("sky_csgo_night02"));
                    material->ColorModulate( 0.1f, 0.1f, 0.1f );
                }
            }
        }
        else {
            for (short h = pMaterialSystem->firstMaterial(); h != pMaterialSystem->invalidMaterial(); h = pMaterialSystem->nextMaterial(h)){
                auto material = pMaterialSystem->getMaterial(h);
                if ( !material )
                    continue;
                if (strstr( material->GetTextureGroupName(), (xorstr("World"))) || strstr( material->GetTextureGroupName(), (xorstr("SkyBox"))) || strstr( material->GetTextureGroupName(), (xorstr("StaticProp")))){
                    sv_skyname->SetValue(buffer); //ex. sky_cs15_daylight01_hdr
                    material->ColorModulate( 1.0f, 1.0f, 1.0f );
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
    
    static unique_ptr<C_BasePlayer>pLocal((C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer()));
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
    
    static unique_ptr<C_BasePlayer>pLocal((C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer()));
    if(visButton_NoFlash->state)
        *pLocal->GetFlashMaxAlpha() = 0.f;
    else
        *pLocal->GetFlashMaxAlpha() = 255.0f;
}

void Visuals::Others::SniperCrosshair(){
    if(!pEngine->IsInGame())
        return;
    
    
    static unique_ptr<ConVar>weapon_debug(pCvar->FindVar(xorstr("weapon_debug_spread_show")));
    if(!visButton_SniperCrosshair->state){
        weapon_debug->SetValue(0);
        return;
    }
    
    C_BasePlayer* pLocal = (C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    if(pLocal->IsAlive() && !pLocal->IsScoped())
        weapon_debug->SetValue(2);
    else if(pLocal->IsAlive() && pLocal->IsScoped())
        weapon_debug->SetValue(0);
}

void Visuals::Others::RecoilCrosshair(){
    if(!pEngine->IsInGame())
        return;
    
    static unique_ptr<ConVar>recoil_cross(pCvar->FindVar(xorstr("cl_crosshair_recoil")));
    if(!visButton_RecoilCrosshair->state){
        recoil_cross->SetValue(0);
        return;
    }
    
    static unique_ptr<C_BasePlayer>pLocal((C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer()));
    if(pLocal->IsAlive() && !pLocal->IsScoped())
        recoil_cross->SetValue(1);
    else if(pLocal->IsAlive() && pLocal->IsScoped())
        recoil_cross->SetValue(0);
}

void Visuals::Others::GrenadePrediction(){
    if(!pEngine->IsInGame())
        return;
    static unique_ptr<ConVar>grenade_preview(pCvar->FindVar(xorstr("cl_grenadepreview")));
    if(!visButton_GrenadePrediction->state){
        grenade_preview->SetValue(0);
        return;
    }
    
    static unique_ptr<C_BasePlayer>pLocal((C_BasePlayer*)pEntList->GetClientEntity(pEngine->GetLocalPlayer()));
    if(!pLocal->IsAlive())
        grenade_preview->SetValue(0);
    else
        grenade_preview->SetValue(1);
}
