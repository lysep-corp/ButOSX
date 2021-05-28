//
//  GameHooker.cpp
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "GameHooker.hpp"

void hkDrawModelExecute(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld) {
    //DME THINGS...
    dmeVMT->GetMethod<tDrawModelExecute>(DME_INDEX)(thisptr, context, state, model_info, pCustomBoneToWorld); //Get from my old source probably pasted.
    pModelRender->ForcedMaterialOverride(0);
}

bool hkCreateMove(void* thisptr, float inputSampleTime, CUserCmd* cmd)
{
    crtmVMT->GetMethod<tCreateMove>(CMV_INDEX)(thisptr, inputSampleTime, cmd);
    //CREATEMOVE THINGS
 
    return false;
}

void hkFrameStageNotify(void* thisptr, FrameStage stage) {
    if (stage == FrameStage::RENDER_START) {
        //Visuals::Others::NightMode();
        Visuals::Others::NoVisRecoil();
        Visuals::Others::NoFlash();
        Visuals::Others::SniperCrosshair();
        Visuals::Others::RecoilCrosshair();
        Visuals::Others::GrenadePrediction();
    }
    fsnVMT->GetMethod<tFrameStageNotify>(FSN_INDEX)(thisptr, stage);
}

HFONT eFont;
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
    LoadModules();
    ScanSigs();
    LoadInterfaces();
    HookVMTs();
    Offsets::getOffsets();
}

Memory::Module* CLIENTMODULE;
Memory::Module* ENGINEMODULE;
Memory::Module* INPUTSYSTEMM;
Memory::Module* VGUI2MODULEM;
Memory::Module* MATRLSMODULE;
Memory::Module* VGUIMATSURFM;

void GameHooker::LoadModules(){
    CLIENTMODULE = new Memory::Module(xorstr("client.dylib"));
    ENGINEMODULE = new Memory::Module(xorstr("engine.dylib"));
    INPUTSYSTEMM = new Memory::Module(xorstr("inputsystem.dylib"));
    VGUI2MODULEM = new Memory::Module(xorstr("vgui2.dylib"));
    MATRLSMODULE = new Memory::Module(xorstr("materialsystem.dylib"));
    VGUIMATSURFM = new Memory::Module(xorstr("vguimatsurface.dylib"));
}

void GameHooker::Destroy(){}

uintptr_t GameHooker::clientModePointer;
void GameHooker::ScanSigs(){
    C_PatternScanner* sigScanner = C_PatternScanner::get();
    clientModePointer = sigScanner->get_pointer(CLIENTMODULE->Name, (Byte*)xorstr("\x48\x8B\xB7\x00\x00\x00\x00\x48\x8D\x3D\x00\x00\x00\x00\x5D\xE9"), xorstr("xxx????xxx????xx"), 0xA) + 0x4;
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
    pPanel              = VGUI2MODULEM->GetInterface<IPanel>(xorstr("VGUI_Panel"));
    pCvar               = MATRLSMODULE->GetInterface<ICvar>(xorstr("VEngineCvar"));
    pModelRender        = ENGINEMODULE->GetInterface<IVModelRender>(xorstr("VEngineModel"));
    pClient             = CLIENTMODULE->GetInterface<IBaseClientDLL>(xorstr("VClient"));
    pClient             = CLIENTMODULE->GetInterface<IBaseClientDLL>(xorstr("VClient"));
    pEngine             = ENGINEMODULE->GetInterface<IEngineClient>(xorstr("VEngineClient"));
    pOverlay            = ENGINEMODULE->GetInterface<IVDebugOverlay>(xorstr("VDebugOverlay"));
    pModelInfo          = ENGINEMODULE->GetInterface<IVModelInfo>(xorstr("VModelInfoClient"));
    pSurface            = VGUIMATSURFM->GetInterface<ISurface>(xorstr("VGUI_Surface"));
    pEngineTrace        = ENGINEMODULE->GetInterface<IEngineTrace>(xorstr("EngineTraceClient"));
    pInputSystem        = INPUTSYSTEMM->GetInterface<IInputSystem>(xorstr("InputSystemVersion"));
    pMaterialSystem     = MATRLSMODULE->GetInterface<IVMaterialSystem>(xorstr("VMaterialSystem"));
    pEntList            = CLIENTMODULE->GetInterface<IClientEntityList>(xorstr("VClientEntityList"));
}
