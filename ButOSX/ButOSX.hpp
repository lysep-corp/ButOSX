//
//  ButOSX.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef ButOSX_
#define ButOSX_

/* The classes below are exported */
#pragma GCC visibility push(default)
#include "SDK/Hooks/MainHooker.hpp"

class ButOSX
{
    public:
    void attach();
    void detach();
};

#pragma GCC visibility pop
#endif
