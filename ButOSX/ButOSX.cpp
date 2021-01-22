//
//  ButOSX.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#include <iostream>
#include "ButOSX.hpp"

int __attribute__((constructor))
attach() //Main attach function which executes when library loads.
{
    Hooker::Init();
    return 0;
}

void __attribute__((constructor))
detach() //De-attach function which executes when library unloads.
{
    // Hooker::Destroy();
}
