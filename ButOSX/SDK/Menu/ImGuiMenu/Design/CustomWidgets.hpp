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

struct ImVec2;
struct ImVec4;

namespace CustomWidgets {
    bool SubTab(const char* label, const ImVec2& size_arg, const bool selected);
    bool Switch(const char* label, bool* v);
    bool ControlBox(void (*UnHookFunction)(), bool* HideShowBool, bool* FullScreenBool);
    void Spinner(float radius, float thickness, int num_segments, ImVec4 color);
}

#endif /* CustomWidgets_hpp */
