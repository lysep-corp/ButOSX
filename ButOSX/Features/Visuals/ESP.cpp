//
//  ESP.cpp
//  ButOSX
//
//  Created by Can on 23.01.2021.
//  Copyright © 2021 VersteckteKrone. All rights reserved.
//

#include "ESP.hpp"
#include "CheatSettings.h"

bool CheatSettings::ESP;

std::wstring StringToWstring(std::string str) { 
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    
    try
    {
        return converter.from_bytes(str);
    }
    catch (std::range_error)
    {
        std::wostringstream s;
        s << str.c_str();
        return s.str();
    }
}

void FillRGBA(int x, int y, int w, int h, Color color) {
    pSurface->DrawSetColor(color);
    pSurface->DrawFilledRect(x, y, x +  w, y + h);
}

void DrawBox(int x, int y, int w, int h, Color color) {
    pSurface->DrawSetColor(color);
    pSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void DrawBoxOutline(int x, int y, int w, int h, Color color) {
    DrawBox(x + 1, y + 1, w - 2, h - 2, Color(0, 0, 0, 120));
    DrawBox(x - 1, y - 1, w + 2, h + 2, Color(0, 0, 0, 120));
    DrawBox(x, y, w, h, color);
}

void DrawLine(int x, int y, int xx, int yy, Color color) {
    pSurface->DrawSetColor(color);
    pSurface->DrawLine(x, y, xx, yy);
}

void DrawString(int x, int y, Color color, HFONT font, bool bCenter, const char* szString) {
    std::wstring wString = StringToWstring(szString);
    if(bCenter) {
        int wide, tall;
        pSurface->GetTextSize(font, wString.c_str(), wide, tall);
        x -= wide / 2;
        y -= tall / 2;
    }
    pSurface->DrawSetTextPos(x, y);
    pSurface->DrawSetTextFont(font);
    pSurface->DrawSetTextColor(color);
    pSurface->DrawPrintText(wString.c_str(), wcslen(wString.c_str()));
}

void DrawHealthbar(int x, int y, int w, int h, int health, Color color) {
    
    if(health > 100)
        health = 100; // Just a fix, tried without this on Zombie servers.. you don't wanna know what happend.
    
    int hw = h - ((h) * health) / 100;
    FillRGBA(x, y - 1, w, h + 2, Color(0, 0, 0, 120));
    FillRGBA(x, y + hw - 1, w, h - hw + 2, color);
    DrawBox(x, y - 1, w, h + 2, Color(0, 0, 0, 200));
}

enum Teams {
    Terrorist = 2,
    CounterTerrorist = 3
};
bool WorldToScreen(Vector& vFrom, Vector& vTo) {
    return (pOverlay->ScreenPosition(vFrom, vTo) != 1);
}

struct bBoxStyle {
    int x, y, w, h;
};

bool DrawPlayerBox(C_BaseEntity* pEntity, bBoxStyle& boxes) {
    if (!pEntity)
        return false;
    
    Vector vOrigin = pEntity->GetVecOrigin();
    Vector min = pEntity->GetCollideable()->OBBMins() + vOrigin;
    Vector max = pEntity->GetCollideable()->OBBMaxs() + vOrigin;
    
    Vector points[] = { Vector(min.x, min.y, min.z),
        Vector(min.x, max.y, min.z),
        Vector(max.x, max.y, min.z),
        Vector(max.x, min.y, min.z),
        Vector(max.x, max.y, max.z),
        Vector(min.x, max.y, max.z),
        Vector(min.x, min.y, max.z),
        Vector(max.x, min.y, max.z) };

    Vector flb;
    Vector brt;
    Vector blb;
    Vector frt;
    Vector frb;
    Vector brb;
    Vector blt;
    Vector flt;
    
    
    if (!WorldToScreen(points[3], flb) || !WorldToScreen(points[5], brt)
        || !WorldToScreen(points[0], blb) || !WorldToScreen(points[4], frt)
        || !WorldToScreen(points[2], frb) || !WorldToScreen(points[1], brb)
        || !WorldToScreen(points[6], blt) || !WorldToScreen(points[7], flt))
        return false;
    
    Vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };
    
    float left = flb.x;        // left
    float top = flb.y;        // top
    float right = flb.x;    // right
    float bottom = flb.y;    // bottom
    
    for (int i = 1; i < 8; i++)
    {
        if (left > arr[i].x)
            left = arr[i].x;
        if (bottom < arr[i].y)
            bottom = arr[i].y;
        if (right < arr[i].x)
            right = arr[i].x;
        if (top > arr[i].y)
            top = arr[i].y;
    }
    
    boxes.x = left;
    boxes.y = top;
    boxes.w = right - left;
    boxes.h = bottom - top;
    return true;
}

auto TestTrace(C_BaseEntity* pEntity, C_BaseEntity* pLocal) -> bool { /* Just a simple visible check :^) */
    Ray_t ray;
    trace_t trace;
    CTraceFilter filter;
    filter.pSkip = pLocal;
    
    ray.Init(pLocal->GetEyePosition(), pEntity->GetEyePosition());
    pEngineTrace->TraceRay(ray, 0x4600400B, &filter, &trace);
    
    return (trace.m_pEnt == pEntity || trace.fraction > 0.99f);
}

void DrawSkeleton(C_BaseEntity* pEntity, Color color) {
    studiohdr_t* pStudioModel = pModelInfo->GetStudioModel( pEntity->GetModel() );
    if ( pStudioModel ) {
        static matrix3x4_t pBoneToWorldOut[128];
        if ( pEntity->SetupBones( pBoneToWorldOut, 128, 256, 0) )
        {
            for ( int i = 0; i < pStudioModel->numbones; i++ )
            {
                mstudiobone_t* pBone = pStudioModel->pBone( i );
                if ( !pBone || !( pBone->flags & 256 ) || pBone->parent == -1 )
                    continue;
                
                
                Vector vBone1 = pEntity->GetBonePosition(i);
                Vector vBoneOut1;
                
                Vector vBone2 = pEntity->GetBonePosition(pBone->parent);
                Vector vBoneOut2;
                
                if(WorldToScreen(vBone1, vBoneOut1) && WorldToScreen(vBone2, vBoneOut2)) {
                    DrawLine(vBoneOut1.x, vBoneOut1.y, vBoneOut2.x, vBoneOut2.y, color);
                }
            }
        }
    }
}
/*
*/
extern void ESP() {
    C_BaseEntity* pLocal = (C_BaseEntity*)pEntList->GetClientEntity(pEngine->GetLocalPlayer());
    for(int i = 0; i < pEntList->GetHighestEntityIndex(); i++) {
        C_BaseEntity* pEntity = (C_BaseEntity*)pEntList->GetClientEntity(i);
        
        if(!pEntity)
            continue;
        if(pEntity->GetHealth() < 1)
            continue;
        if(pEntity->GetTeam() == pLocal->GetTeam())
            continue;
        if(pEntity->IsDormant())
            continue;
        if(pEntity->IsGhost())
            continue;
        if(pEntity == pLocal)
            continue;
        
        bBoxStyle players;
        auto isVisible = TestTrace(pEntity, pLocal);
        
        IEngineClient::player_info_t pInfo;
        pEngine->GetPlayerInfo(i, &pInfo);
        if(CheatSettings::ESP)
            if(DrawPlayerBox(pEntity, players)) {
                if(pEntity->GetTeam() == Terrorist) { // Draw box ESP on T
                    DrawBoxOutline(players.x, players.y, players.w, players.h, isVisible ? Color::Red() : Color::Yellow());
                }
                if(pEntity->GetTeam() == CounterTerrorist) { // Draw box ESP on CT
                    DrawBoxOutline(players.x, players.y, players.w, players.h, isVisible ? Color::Green() : Color::Blue());
                }
                /* Draw Skeleton */
                DrawSkeleton(pEntity, Color::White());
                /* Draws health bar */
                DrawHealthbar(players.x - 5, players.y, 3, players.h, pEntity->GetHealth(), Color::Green());
                /* Draws player name */
                DrawString(players.x + players.w / 2, players.y - 12, Color::White(), eFont, true, pInfo.name);
            }
    }
}
