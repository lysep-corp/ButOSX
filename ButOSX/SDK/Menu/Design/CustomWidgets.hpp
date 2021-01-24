//
//  CustomWidgets.hpp
//  ButOSX
//
//  Created by Can on 31.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#ifndef CustomWidgets_hpp
#define CustomWidgets_hpp
#include <stdio.h>

struct ImVec2;

namespace CustomWidgets {
    bool SubTab(const char* label, const ImVec2& size_arg, const bool selected);
    bool Switch(const char* label, bool* v); 
}

#endif /* CustomWidgets_hpp */
