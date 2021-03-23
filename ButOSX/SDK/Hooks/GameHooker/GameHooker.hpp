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

namespace GameHooker{
void Init();
void Destroy();
void ScanSigs();
void HookVMTs();
void LoadInterfaces();

extern C_PatternScanner* sigScanner;
extern intptr_t clientModePointer;
}
#endif /* GameHooker_hpp */
