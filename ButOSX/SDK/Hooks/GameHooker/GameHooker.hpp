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

namespace GameHooker{
void Init();
void Destroy();
void HookVMTs();
void LoadInterfaces();
}
#endif /* GameHooker_hpp */
