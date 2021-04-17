//
//  ButOSX.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef ButOSX_
#define ButOSX_

#include "SDK/Hooks/MainHooker.hpp"
#include "Thirdparty/TouchBar-ObjectiveC/TouchBar.h"
#include "SDK/ObjectiveCWrapper/ObjCWrapper.h"
/* The classes below are exported */
#pragma GCC visibility push(default)

class ButOSX
{
    public:
    void attach();
    void detach();
};

#pragma GCC visibility pop
#endif
