//
//  Visuals.hpp
//  ButOSX
//
//  Created by Can Destan on 27.01.2021.
//  Copyright © 2021 VersteckteKrone. All rights reserved.
//

#ifndef Visuals_hpp
#define Visuals_hpp

#include <stdio.h>

#include "ValveSDK.h"
struct ImDrawList;
extern HFONT eFont;

namespace Visuals{
    namespace ESP{
        void ESPSurface();
        void EspImGui(ImDrawList* drawArea);
    }
    namespace Others{
        void Watermark(ImDrawList* bruh);
        void NightMode();
    }
}

#endif /* Visuals_hpp */
