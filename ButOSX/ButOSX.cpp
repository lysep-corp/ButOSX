//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include <iostream>
#include "ButOSX.hpp"
#include "Thirdparty/TouchBar-ObjectiveC/TouchBar.h"
//#include "Classes/DiscordRPC.hpp"

int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    Hooker::Init();
    RenderTouchBar();
    //DiscordRPC::StartDiscordRPC();
    return 0;
}
