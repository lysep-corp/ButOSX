//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//


//AND IT IS NOT A F*CKIN MICROWAVE FORK.

#include <iostream>
#include "ButOSX.hpp"


int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    static C_PatternScanner* PatternScanner = C_PatternScanner::get();
    while (!PatternScanner->get_base_address(xorstr("serverbrowser.dylib"))) {
        PatternScanner->load_modules();
    }
    
    //Initialize TouchBar UI.
    RenderTouchBar();
    
    //Initialize Hooker.
    Hooker::Init();
    
    //Inıtalize Objective-C API.
    GetUserDatas();
    return 0;
}
