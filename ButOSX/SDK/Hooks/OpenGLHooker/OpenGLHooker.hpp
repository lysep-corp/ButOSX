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
#include <OpenGL/gl3.h>
#include "SDL.h"

#include "Functions/Helpers.hpp"
#include "Functions/Module.hpp"

struct ImFont;
extern ImFont* g_GirisFontBüyük;
extern ImFont* g_Font;
extern ImFont* g_Büyük;

//extern SDL_Texture* images;


#include <dlfcn.h>

namespace SDLHook {
    void Init();
    void SwapWindow(SDL_Window* window);
    extern bool _visible;
    void Unhook();
}
#endif /* OpenGLHooker_hpp */
