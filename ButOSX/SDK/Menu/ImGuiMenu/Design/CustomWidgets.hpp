//
//  CustomWidgets.hpp
//  ButOSX
//
//  Created by Can on 31.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef CustomWidgets_hpp
#define CustomWidgets_hpp
#include <stdio.h>
#include "TouchBar.h"

struct ImVec2;
struct ImVec4;

namespace CustomWidgets {
    bool SubTab(const char* label, const ImVec2& size_arg, const bool selected);
    bool Switch(const char* label, bool* v);
    bool SwitchTouchbar(const char* label, TBWMenuItem* _btn);
    bool ControlBox(bool* HideShowBool);
    void Spinner(float radius, float thickness, int num_segments, ImVec4 color);
    bool ColorPicker4(const char* label, TBWMenuItem* color, int flags);
}

#endif /* CustomWidgets_hpp */
