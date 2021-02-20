//
//  Interfaces.cpp
//  ButOSX
//
//  Created by Can on 23.01.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "ValveSDK.h"
#include "VMT.h"

ISurface* pSurface = nullptr;
IPanel* pPanel = nullptr;
ICvar* pCvar = nullptr;
IBaseClientDLL* pClient = nullptr;
IClientEntityList* pEntList = nullptr;
IVDebugOverlay* pOverlay = nullptr;
IEngineClient* pEngine = nullptr;
IVModelInfo* pModelInfo = nullptr;
IEngineTrace* pEngineTrace = nullptr;
IClientMode* pClientMode = nullptr;
IVModelRender* pModelRender = nullptr;
IVMaterialSystem* pMaterialSystem = nullptr;
IAppSystem* pAppSystem = nullptr;

VMT* paintVMT = nullptr;
VMT* dmeVMT = nullptr;
VMT* fsnVMT = nullptr;
