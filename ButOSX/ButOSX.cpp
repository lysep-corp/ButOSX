//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 16.05.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "ButOSX.hpp"

void ButOSX::Initalize(){
    // Implemention of new module system
    static Memory::Module* ServerBrowser = new Memory::Module(SRVBRWMODULE);
    while (!ServerBrowser->IsRunning) {
        sleep(1);
        free(ServerBrowser);
        ServerBrowser = new Memory::Module(SRVBRWMODULE);
    }
    
    //Initialize TouchBar UI.
    RenderTouchBar();
    
    //Inıtalize Objective-C API.
    GetUserDatas();
    
    //Initialize Hooker.
    Hooker::Init();
    
    return 0;
}
