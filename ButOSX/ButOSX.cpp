//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include <iostream>
#include "ButOSX.hpp"
#include "SDK/Menu/TouchbarMenu/TouchbarMenuRenderer.hpp"
#include "Classes/DiscordRPC.hpp"

int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    Hooker::Init();
    TouchBarMenu::RenderTouchBar();
    //DiscordRPC::StartDiscordRPC();
    return 0;
}
