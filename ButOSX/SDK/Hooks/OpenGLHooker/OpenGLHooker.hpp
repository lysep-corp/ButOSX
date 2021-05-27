//
//  OpenGLHooker.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef OpenGLHooker_hpp
#define OpenGLHooker_hpp

#include <stdio.h>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include "SDL.h"
#include "SDL_video.h"

#include "Memory.hpp"

#include "Visuals.hpp"

struct ImFont;
extern ImFont* g_GirisFontBüyük;
extern ImFont* g_Font;
extern ImFont* g_Buyuk;

extern bool FreeTheCursor;

namespace SDLHook {
    void Init();
    void SwapWindow(SDL_Window* window);
    void Unhook();
}
#endif /* OpenGLHooker_hpp */
