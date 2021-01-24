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

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 400

#include "SDL.h"
struct ImDrawList;

namespace MenuRenderer {
void RenderMenu(bool _visible);
void DrawWatermark(ImDrawList* bruh);
void InitTheme();
}

namespace Pages {
void VisualsPage();
}


#endif /* MenuRenderer_hpp */
