//
//  GameHooker.hpp
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef GameHooker_hpp
#define GameHooker_hpp

#include <stdio.h>
#include "PatternScanner.hpp"

// FUNC INDEXES
#define DME_INDEX 21
#define CMV_INDEX 25
#define FSN_INDEX 37
#define PTV_INDEX 42

//DLL NAMES
#define CLIENTMODULE xorstr("client.dylib")
#define ENGINEMODULE xorstr("engine.dylib")
#define SRVBRWMODULE xorstr("serverbrowser.dylib")

namespace GameHooker{
void Init();
void Destroy();
void ScanSigs();
void HookVMTs();
void LoadInterfaces();

extern C_PatternScanner* sigScanner;
extern uintptr_t clientModePointer;
}
#endif /* GameHooker_hpp */
