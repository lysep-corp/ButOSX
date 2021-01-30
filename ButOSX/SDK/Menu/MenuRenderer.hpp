//
//  MenuRenderer.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#ifndef MenuRenderer_hpp
#define MenuRenderer_hpp

#include <stdio.h>

#include "../../Thirdparty/imgui/imgui.h"
#include "../../Thirdparty/imgui/backends/imgui_impl_sdl.h"
#include "../../Thirdparty/imgui/backends/imgui_impl_opengl2.h"
#include "../../Thirdparty/imgui/imgui_internal.h"

#include "Design/CustomWidgets.hpp"

#define WINDOW_HEIGHT   375
#define WINDOW_PADDING  WINDOW_HEIGHT / 25
#define WINDOW_WIDTH    (WINDOW_HEIGHT * 1.2 * 1.61803398875) //Golden Ratio ?!???!?

#include "SDL.h"

namespace MenuRenderer {
    void RenderMenu(bool _visible);
    void InitTheme();
}

namespace Pages {
    extern char *PageList[];
    void VisualsPage();
    void AssistsPage();
    void SettingsPage();
}


#endif /* MenuRenderer_hpp */
