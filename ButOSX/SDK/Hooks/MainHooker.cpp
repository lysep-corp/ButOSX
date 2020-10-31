//
//  MainHooker.cpp
//  ButOSX
//
//  Created by Can Destan on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#include "MainHooker.hpp"

void Hooker::Init() {
    //Inserting GUI
    SDLHook::Init();
    
}

void Hooker::Destroy(){
    //SDLHook::UnHook();
}
