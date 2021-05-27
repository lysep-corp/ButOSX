//
//  ButOSX.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef ButOSX_
#define ButOSX_

#include <iostream>
#include "SDK/Hooks/MainHooker.hpp"
#include "SDK/ObjectiveCWrapper/ObjCWrapper.h"
#include "Thirdparty/TouchBar-ObjectiveC/TouchBar.h"

/* The classes below are exported */
#pragma GCC visibility push(internal)

namespace ButOSX
{
    void Initalize();
    void Unload();
};

#pragma GCC visibility pop
#endif
