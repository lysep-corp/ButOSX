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

int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    TouchBarMenu::RenderTouchBar();
    Hooker::Init();
    return 0;
}
