//
//  OpenGLHooker.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#ifndef OpenGLHooker_hpp
#define OpenGLHooker_hpp

#include <stdio.h>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include "SDL.h"

#include "Functions/Helpers.hpp"
#include "Functions/Module.hpp"

#include "../../Menu/MenuRenderer.hpp"

#include <dlfcn.h>

namespace SDLHook {
    void Init();
    void SwapWindow(SDL_Window* window);
    extern bool _visible;
    void Unhook();
}
#endif /* OpenGLHooker_hpp */
