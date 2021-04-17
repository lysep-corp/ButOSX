//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include <iostream>
#include "ButOSX.hpp"

int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    //Initialize TouchBar UI.
    RenderTouchBar();
    
    //Initialize Hooker.
    Hooker::Init();
    
    //Inıtalize Objective-C API.
    GetUserDatas();
    return 0;
}
