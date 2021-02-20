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
    //ShowTouchBar(); //Start's Touchbar API BUT REMOVED BECAUSE OF API IN W.I.P
    Hooker::Init();
    return 0;
}
