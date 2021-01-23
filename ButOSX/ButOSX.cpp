//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#include <iostream>
#include "ButOSX.hpp"
#include "SDK/NSTouchBar/NSTouchBar.h"

int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    //test impl
    ShowTouchBar();
    Hooker::Init();
    return 0;
}
