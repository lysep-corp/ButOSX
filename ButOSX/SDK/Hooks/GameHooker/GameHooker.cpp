//
//  GameHooker.cpp
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "GameHooker.hpp"
#include "ValveSDK.h"
#include "Visuals.hpp"
#include "OpenGLHooker.hpp"
#include "PatternScanner.hpp"
#include "TouchBar.h"
//#include "DiscordRPC.hpp"


typedef void(*tDrawModelExecute)(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld);
extern void hkDrawModelExecute(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld);
void hkDrawModelExecute(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld) {
    //DME THINGS...
    dmeVMT->GetMethod<tDrawModelExecute>(DME_INDEX)(thisptr, context, state, model_info, pCustomBoneToWorld); //Get from my old source probably pasted.
    pModelRender->ForcedMaterialOverride(0);
}

typedef bool(*tCreateMove)(void* thisptr, float inputSampleTime, CUserCmd* cmd);
extern bool hkCreateMove(void* thisptr, float inputSampleTime, CUserCmd* cmd);
bool hkCreateMove(void* thisptr, float inputSampleTime, CUserCmd* cmd)
{
    crtmVMT->GetMethod<tCreateMove>(CMV_INDEX)(thisptr, inputSampleTime, cmd);
    //CREATEMOVE THINGS
 
    return false;
}

typedef void(*tFrameStageNotify)(void* thisptr, FrameStage stage);
extern void hkFrameStageNotify(void* thisptr, FrameStage stage);
void hkFrameStageNotify(void* thisptr, FrameStage stage) {
    if (stage == FrameStage::RENDER_START) {
        //Visuals::Others::NightMode();
        Visuals::Others::NoVisRecoil();
        Visuals::Others::NoFlash();
        Visuals::Others::SniperCrosshair();
        Visuals::Others::RecoilCrosshair();
    }
    fsnVMT->GetMethod<tFrameStageNotify>(FSN_INDEX)(thisptr, stage);
}

HFONT eFont;
typedef void(*tPaintTraverse)(void*, VPANEL, bool, bool);
extern void hkPaintTraverse(void* thisptr, VPANEL vguiPanel, bool forceRepaint, bool allowForce);
void hkPaintTraverse(void* thisptr, VPANEL vguiPanel, bool forceRepaint, bool allowForce) {
    paintVMT->GetMethod<tPaintTraverse>(PTV_INDEX)(thisptr, vguiPanel, forceRepaint, allowForce);
    static VPANEL currentPanel = 0;
    if(!currentPanel)
        if(strstr(pPanel->GetName(vguiPanel), xorstr("FocusOverlayPanel"))) {
            eFont = pSurface->CreateFont(); // ESP Font
            pSurface->SetFontGlyphSet(eFont, xorstr("Segoe Ui"), 12, 100, 0, 0, FONTFLAG_ANTIALIAS | FONTFLAG_DROPSHADOW);
            currentPanel = vguiPanel;
        }
    
    if(vguiPanel == currentPanel)
        Visuals::ESP::ESPSurface();
}

typedef void(*tLockCursor)(void* thisptr);
extern void hkLockCursor(void* thisptr);
void hkLockCursor(void* thisptr)
{
    //Weirdly it lock's mouse when i open the menu?
    if(butButton_Menu->state){
        pSurface->UnlockCursor();
        return;
    }
    lkcVMT->GetMethod<tLockCursor>(LKC_INDEX)(thisptr);
}

void GameHooker::Init(){
    ScanSigs();
    LoadInterfaces();
    HookVMTs();
    Offsets::getOffsets();
}

void GameHooker::Destroy(){}

uintptr_t GameHooker::clientModePointer;
void GameHooker::ScanSigs(){
    C_PatternScanner* sigScanner = C_PatternScanner::get();
    clientModePointer = sigScanner->get_pointer(CLIENTMODULE, (Byte*)xorstr("\x48\x8B\xB7\x00\x00\x00\x00\x48\x8D\x3D\x00\x00\x00\x00\x5D\xE9"), xorstr("xxx????xxx????xx"), 0xA) + 0x4;
}

void GameHooker::HookVMTs(){
    dmeVMT              = new VMT(pModelRender, (void*)hkDrawModelExecute, DME_INDEX);
    crtmVMT             = new VMT(pClientMod,   (void*)hkCreateMove, CMV_INDEX);
    fsnVMT              = new VMT(pClient,      (void*)hkFrameStageNotify, FSN_INDEX);
    paintVMT            = new VMT(pPanel,       (void*)hkPaintTraverse, PTV_INDEX);
    //lkcVMT              = new VMT(pSurface,     (void*)hkLockCursor, LKC_INDEX);
}

void GameHooker::LoadInterfaces(){
    pClientMod          = reinterpret_cast<IClientMode*>(clientModePointer);
    pPanel              = GetInterface<IPanel>(xorstr("./bin/osx64/vgui2.dylib"), xorstr("VGUI_Panel"));
    pCvar               = GetInterface<ICvar>(xorstr("./bin/osx64/materialsystem.dylib"), xorstr("VEngineCvar"));
    pModelRender        = GetInterface<IVModelRender>(xorstr("./bin/osx64/engine.dylib"), xorstr("VEngineModel"));
    pClient             = GetInterface<IBaseClientDLL>(xorstr("./csgo/bin/osx64/client.dylib"), xorstr("VClient"));
    pEngine             = GetInterface<IEngineClient>(xorstr("./bin/osx64/engine.dylib"), xorstr("VEngineClient"));
    pOverlay            = GetInterface<IVDebugOverlay>(xorstr("./bin/osx64/engine.dylib"), xorstr("VDebugOverlay"));
    pModelInfo          = GetInterface<IVModelInfo>(xorstr("./bin/osx64/engine.dylib"), xorstr("VModelInfoClient"));
    pSurface            = GetInterface<ISurface>(xorstr("./bin/osx64/vguimatsurface.dylib"), xorstr("VGUI_Surface"));
    pEngineTrace        = GetInterface<IEngineTrace>(xorstr("./bin/osx64/engine.dylib"), xorstr("EngineTraceClient"));
    pInputSystem        = GetInterface<IInputSystem>(xorstr("./bin/osx64/inputsystem.dylib"), xorstr("InputSystemVersion"));
    pMaterialSystem     = GetInterface<IVMaterialSystem>(xorstr("./bin/osx64/materialsystem.dylib"), xorstr("VMaterialSystem"));
    pEntList            = GetInterface<IClientEntityList>(xorstr("./csgo/bin/osx64/client.dylib"), xorstr("VClientEntityList"));
}
