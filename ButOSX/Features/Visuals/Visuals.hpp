//
//  Visuals.hpp
//  ButOSX
//
//  Created by Can Destan on 27.01.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#ifndef Visuals_hpp
#define Visuals_hpp

#include <stdio.h>

#include "ValveSDK.h"
struct ImDrawList;
extern HFONT eFont;

namespace Visuals{
    namespace ESP{
        extern void ESPSurface();
    }
    namespace Others{
        extern void Watermark(ImDrawList* bruh);
        extern void NightMode();
    
    }
}

#endif /* Visuals_hpp */
