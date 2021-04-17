//
//  MenuRenderer.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef MenuRenderer_hpp
#define MenuRenderer_hpp
#include <stdio.h>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include "SDL.h"

#include "../../../Thirdparty/imgui/imgui.h"
#include "../../../Thirdparty/imgui/imgui_internal.h"
#include "../../../Thirdparty/imgui/backends/imgui_impl_sdl.h"
#include "../../../Thirdparty/imgui/backends/imgui_impl_opengl2.h"

#include "Design/CustomWidgets.hpp"

#include "xorstr.h"
#include "Visuals.hpp"
#include "ObjCWrapper.h"
#include "CheatSettings.h"
#include "CustomWidgets.hpp"

#include "TouchBar.h"

#define WINDOW_HEIGHT   375
#define WINDOW_PADDING  WINDOW_HEIGHT / 25
#define WINDOW_WIDTH    (WINDOW_HEIGHT * 1.2 * 1.61803398875) //Golden Ratio ?!???!?

namespace MenuRenderer {
    static bool chinaVisible = false;
    static float flAlpha = 0;
    void RenderMenu();
    void InitTheme();
}

namespace Pages {
    extern char *PageList[];
    void VisualsPage();
    void AssistsPage();
    void SettingsPage();
}


#endif /* MenuRenderer_hpp */
