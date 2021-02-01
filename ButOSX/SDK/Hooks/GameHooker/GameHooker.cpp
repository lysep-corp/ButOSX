//
//  GameHooker.cpp
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#include "GameHooker.hpp"
#include "ValveSDK.h"
#include "Visuals.hpp"
#include "OpenGLHooker.hpp"

HFONT eFont;
typedef void(*tPaintTraverse)(void*, VPANEL, bool, bool);

extern void hkPaintTraverse(void* thisptr, VPANEL vguiPanel, bool forceRepaint, bool allowForce);
void hkPaintTraverse(void* thisptr, VPANEL vguiPanel, bool forceRepaint, bool allowForce) {
    paintVMT->GetOriginalMethod<tPaintTraverse>(42)(thisptr, vguiPanel, forceRepaint, allowForce);
    static VPANEL currentPanel = 0;
    if(!currentPanel) {
        if(strstr(pPanel->GetName(vguiPanel), "FocusOverlayPanel")) {
            eFont = pSurface->CreateFont(); // ESP Font
            pSurface->SetFontGlyphSet(eFont, "Segoe Ui", 12, 250, 0, 0, FONTFLAG_ANTIALIAS | FONTFLAG_DROPSHADOW);
            currentPanel = vguiPanel;
        }
    }
    
    if(vguiPanel == currentPanel) {
        Visuals::ESP::ESPSurface();
    }
}
typedef void(*tDrawModelExecute)(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld);

extern void hkDrawModelExecute(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld);
void hkDrawModelExecute(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld) {
    if(SDLHook::_visible){
        //DME IS SPOSED TO GIVE ME ISURFACE?
        //pSurface->LockCursor(ISURFACE, edx);
    }
    dmeVMT->GetOriginalMethod<tDrawModelExecute>(21)(thisptr, context, state, model_info, pCustomBoneToWorld); //Get from my old source probably pasted.
    pModelRender->ForcedMaterialOverride(0);
}

typedef void(*tFrameStageNotify)(void* thisptr, FrameStage stage);

extern void hkFrameStageNotify(void* thisptr, FrameStage stage);
void hkFrameStageNotify(void* thisptr, FrameStage stage) {
    if (stage == FrameStage::RENDER_START) {
        Visuals::Others::NightMode();
    }
    fsnVMT->GetOriginalMethod<tFrameStageNotify>(37)(thisptr, stage);
}

void GameHooker::Init(){
    LoadInterfaces();
    HookVMTs();
    Offsets::getOffsets();
}

void GameHooker::Destroy(){
    
}

void GameHooker::HookVMTs(){
    paintVMT = new VMT(pPanel);
    paintVMT->HookVM((void*)hkPaintTraverse, 42);
    paintVMT->ApplyVMT();
    dmeVMT = new VMT(pModelRender);
    dmeVMT->HookVM((void*)hkDrawModelExecute, 21);
    dmeVMT->ApplyVMT();
    fsnVMT = new VMT(pClient);
    fsnVMT->HookVM((void*)hkFrameStageNotify, 37);
    fsnVMT->ApplyVMT();
}

void GameHooker::LoadInterfaces(){
    pSurface        = GetInterface<ISurface>("./bin/osx64/vguimatsurface.dylib", "VGUI_Surface");
    pPanel          = GetInterface<IPanel>("./bin/osx64/vgui2.dylib", "VGUI_Panel");
    pCvar           = GetInterface<ICvar>("./bin/osx64/materialsystem.dylib", "VEngineCvar");
    pClient         = GetInterface<IBaseClientDLL>("./csgo/bin/osx64/client.dylib", "VClient");
    pEngine         = GetInterface<IEngineClient>("./bin/osx64/engine.dylib", "VEngineClient");
    pEntList        = GetInterface<IClientEntityList>("./csgo/bin/osx64/client.dylib", "VClientEntityList");
    pOverlay        = GetInterface<IVDebugOverlay>("./bin/osx64/engine.dylib", "VDebugOverlay");
    pEngineTrace    = GetInterface<IEngineTrace>("./bin/osx64/engine.dylib", "EngineTraceClient");
    pModelInfo      = GetInterface<IVModelInfo>("./bin/osx64/engine.dylib", "VModelInfoClient");
    pModelRender    = GetInterface<IVModelRender>("./bin/osx64/engine.dylib", "VEngineModel");
    pMaterialSystem = GetInterface<IVMaterialSystem>("./bin/osx64/materialsystem.dylib", "VMaterialSystem");
}
