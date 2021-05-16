//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 16.05.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include <stdio.h>
#include "ButOSX.hpp"

void ButOSX::Initalize(){
    static unique_ptr<C_PatternScanner>PatternScanner(C_PatternScanner::get());
    while (!PatternScanner->get_base_address(SRVBRWMODULE)) {
        sleep(1);
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
