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

// make facets usable by giving them a public destructor
template <class Facet>
class usable_facet
    : public Facet
{
public:
    template <class ...Args>
        usable_facet(Args&& ...args)
            : Facet(std::forward<Args>(args)...) {}
    ~usable_facet() {}
};

namespace Visuals{
    namespace ESP{
        extern void ESPSurface();
    }
    namespace Others{
        extern void Watermark(ImDrawList* drawArea);
        extern void NightMode();
        extern void NoVisRecoil();
        extern void NoFlash();
        extern void SniperCrosshair();
        extern void RecoilCrosshair();
        extern void GrenadePrediction();
    }
}

#endif /* Visuals_hpp */
