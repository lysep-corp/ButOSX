//
//  MainHooker.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "MainHooker.hpp"

void Hooker::Init() { //Load hooks.
    //Inserting GUI
    SDLHook::Init();
    //Load Game SDK
    GameHooker::Init();
}

void Hooker::Destroy(){ //Destroy hooks.
    //Destroying GUI
    SDLHook::Unhook();
}
