//
//  MenuRenderer.hpp
//  ButOSX
//
//  Created by Can Destan on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#ifndef MenuRenderer_hpp
#define MenuRenderer_hpp

#include <stdio.h>

#include "../../Thirdparty/imgui/imgui.h"
#include "../../Thirdparty/imgui/backends/imgui_impl_sdl.h"
#include "../../Thirdparty/imgui/backends/imgui_impl_opengl2.h"

#include "Design/CustomWidgets.hpp"

#include "SDL.h"

namespace MenuRenderer {
void RenderMenu(bool _visible);
void InitTheme();
}

namespace Pages {
void WelcomePage();
void VisualsPage();
}


#endif /* MenuRenderer_hpp */
