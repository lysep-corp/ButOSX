//
//  OpenGLHooker.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//

#include "OpenGLHooker.hpp"
#include "xorstr.h"
#include "../../Menu/Datas.hpp"
#include "../../Menu/MenuRenderer.hpp"
#include "Visuals.hpp"

Uint8 SDLCALL SDL_GameControllerGetButton(SDL_GameController *gamecontroller, SDL_GameControllerButton button){
    typedef Uint8(*currFn) (SDL_GameController*, SDL_GameControllerButton);
    static currFn SDL_GameControllerGetButtonFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GameControllerGetButton")));
    
    return SDL_GameControllerGetButtonFn(gamecontroller, button);
}

Sint16 SDLCALL SDL_GameControllerGetAxis(SDL_GameController *gamecontroller, SDL_GameControllerAxis axis){
    typedef Sint16(*currFn) (SDL_GameController*, SDL_GameControllerAxis);
    static currFn SDL_GameControllerGetAxisFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GameControllerGetAxis")));
    
    return SDL_GameControllerGetAxisFn(gamecontroller, axis);
}

SDL_GameController *SDLCALL SDL_GameControllerOpen(int joystick_index){
    typedef SDL_GameController*(*currFn) (int);
    static currFn SDL_GameControllerOpenFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GameControllerOpen")));
    
    return SDL_GameControllerOpenFn(joystick_index);
}

void SDLCALL SDL_free(void *mem){
    typedef void(*currFn) (void*);
    static currFn SDL_freeFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_free")));
    
    return SDL_freeFn(mem);
}

void SDLCALL SDL_GetWindowPosition(SDL_Window * window, int *x, int *y){
    typedef void(*currFn) (SDL_Window*, int*, int*);
    static currFn SDL_GetWindowPositionFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetWindowPosition")));
    
    return SDL_GetWindowPositionFn(window, x, y);
}

SDL_Window * SDLCALL SDL_GetKeyboardFocus(void){
    typedef SDL_Window*(*currFn) (void);
    static currFn SDL_GetKeyboardFocusFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetKeyboardFocus")));
    
    return SDL_GetKeyboardFocusFn();
}

const char *SDLCALL SDL_GetCurrentVideoDriver(void) {
    typedef char*(*currFn) (void);
    static currFn SDL_GetCurrentVideoDriverFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetCurrentVideoDriver")));
    
    return SDL_GetCurrentVideoDriverFn();
}

void SDLCALL SDL_GetWindowSize(SDL_Window* window, int* w, int* h) {
    typedef void(*currFn) (SDL_Window*, int*, int*);
    static currFn SDL_GetWindowSizeFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetWindowSize")));
    
    return SDL_GetWindowSizeFn(window, w, h);
}

void SDLCALL SDL_WarpMouseInWindow(SDL_Window* window, int x, int y) {
    typedef void(*currFn) (SDL_Window*, int, int);
    static currFn SDL_WarpMouseInWindowFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_WarpMouseInWindow")));
    
    return SDL_WarpMouseInWindowFn(window, x, y);
}

char * SDLCALL SDL_GetClipboardText(void) {
    typedef char*(*currFn) (void);
    static currFn SDL_GetClipboardTextFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetClipboardText")));
    
    return SDL_GetClipboardTextFn();
}

void SDLCALL SDL_GL_GetDrawableSize(SDL_Window* window, int* w, int* h) {
    typedef void(*currFn) (SDL_Window*, int*, int*);
    static currFn SDL_GL_GetDrawableSizeFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GL_GetDrawableSize")));
    
    return SDL_GL_GetDrawableSizeFn(window, w, h);
}

Uint32 SDLCALL SDL_GetTicks(void) {
    typedef Uint32(*currFn) (void);
    static currFn SDL_GetTicksFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetTicks")));
    
    return SDL_GetTicksFn();
}

Uint32 SDLCALL SDL_GetWindowFlags(SDL_Window* window) {
    typedef Uint32(*currFn) (SDL_Window*);
    static currFn SDL_GetWindowFlagsFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetWindowFlags")));
    
    return SDL_GetWindowFlagsFn(window);
}

int SDLCALL SDL_ShowCursor(int toggle) {
    typedef int(*currFn) (int);
    static currFn SDL_ShowCursorFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_ShowCursor")));
    
    return SDL_ShowCursorFn(toggle);
}

int SDLCALL SDL_SetClipboardText(const char* text) {
    typedef int(*currFn) (const char*);
    static currFn SDL_SetClipboardTextFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_SetClipboardText")));
    
    return SDL_SetClipboardTextFn(text);
}

Uint32 SDLCALL SDL_GetMouseState(int* x, int* y) {
    typedef Uint32(*currFn) (int*, int*);
    static currFn SDL_GetMouseStateFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetMouseState")));
    
    return SDL_GetMouseStateFn(x, y);
}

Uint32 SDLCALL SDL_GetGlobalMouseState(int *x, int *y){
    typedef Uint32(*currFn) (int*, int*);
    static currFn SDL_GetGlobalMouseStateFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetGlobalMouseState")));
    
    return SDL_GetGlobalMouseStateFn(x, y);
}

SDL_Keymod SDLCALL SDL_GetModState(void) {
    typedef SDL_Keymod(*currFn) (void);
    static currFn SDL_GetModStateFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetModState")));
    
    return SDL_GetModStateFn();
}

SDL_GLContext SDLCALL SDL_GL_GetCurrentContext(void) {
    typedef SDL_GLContext(*currFn) (void);
    static currFn SDL_GL_GetCurrentContextFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GL_GetCurrentContext")));
    
    return SDL_GL_GetCurrentContextFn();
}

SDL_GLContext SDLCALL SDL_GL_CreateContext(SDL_Window* window) {
    typedef SDL_GLContext(*currFn) (SDL_Window*);
    static currFn SDL_GL_CreateContextFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GL_CreateContext")));
    
    return SDL_GL_CreateContextFn(window);
}

int SDLCALL SDL_GL_MakeCurrent(SDL_Window* window, SDL_GLContext context) {
    typedef int(*currFn) (SDL_Window*, SDL_GLContext);
    static currFn SDL_GL_MakeCurrentFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GL_MakeCurrent")));
    
    return SDL_GL_MakeCurrentFn(window, context);
}

Uint64 SDLCALL SDL_GetPerformanceFrequency(void) {
    typedef Uint64(*currFn) (void);
    static currFn SDL_GetPerformanceFrequencyFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetPerformanceFrequency")));
    
    return SDL_GetPerformanceFrequencyFn();
}

Uint64 SDLCALL SDL_GetPerformanceCounter(void) {
    typedef Uint64(*currFn) (void);
    static currFn SDL_GetPerformanceCounterFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetPerformanceCounter")));
    
    return SDL_GetPerformanceCounterFn();
}

int SDLCALL SDL_CaptureMouse(SDL_bool enabled) {
    typedef int(*currFn) (SDL_bool);
    static currFn SDL_CaptureMouseFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_CaptureMouse")));
    
    return SDL_CaptureMouseFn(enabled);
}

void SDLCALL SDL_SetCursor(SDL_Cursor* cursor) {
    typedef void(*currFn) (SDL_Cursor*);
    static currFn SDL_SetCursorFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_SetCursor")));
    
    SDL_SetCursorFn(cursor);
}

void SDLCALL SDL_FreeCursor(SDL_Cursor* cursor) {
    typedef void(*currFn) (SDL_Cursor*);
    static currFn SDL_FreeCursorFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_FreeCursor")));
    
    return SDL_FreeCursorFn(cursor);
}

SDL_Cursor* SDLCALL SDL_CreateSystemCursor(SDL_SystemCursor id) {
    typedef SDL_Cursor*(*currFn) (SDL_SystemCursor);
    static currFn SDL_CreateSystemCursorFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_CreateSystemCursor")));
    
    return SDL_CreateSystemCursorFn(id);
}

uintptr_t* pollevent_ptr = nullptr;
uintptr_t pollevent_original = NULL;
int PollEventHK(SDL_Event* event) { // Needed for getting inputs mostly show / hide menu and anything else is needed like inputs etc.
    static int (*oSDL_PollEvent) (SDL_Event*) = reinterpret_cast<int(*)(SDL_Event*)>(pollevent_original);
    int returnAddr =  0;
    static SDL_Event _event; 
    if(SDLHook::_visible){
       ImGui_ImplSDL2_ProcessEvent(&_event);
        returnAddr = oSDL_PollEvent(&_event);
    }
    else{
        ImGui_ImplSDL2_ProcessEvent(event);
        returnAddr = oSDL_PollEvent(event);
    }
    return returnAddr;
}

int SDLCALL SDL_GL_SetAttribute(SDL_GLattr attr, int value) {
    typedef int(*currFn) (SDL_GLattr, int);
    static currFn SDL_GL_SetAttributeFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GL_SetAttribute")));
    
    return SDL_GL_SetAttributeFn(attr, value);
}

int SDLCALL SDL_SetRelativeMouseMode(SDL_bool enabled) {
    typedef int(*currFn) (SDL_bool);
    static currFn SDL_SetRelativeMouseModeFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_SetRelativeMouseMode")));
    
    return SDL_SetRelativeMouseModeFn(enabled);
}

const Uint8* SDLCALL SDL_GetKeyboardState(int* numkeys) {
    typedef Uint8*(*currFn) (int*);
    static currFn SDL_GetKeyboardStateFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_GetKeyboardState")));
    
    return SDL_GetKeyboardStateFn(numkeys);
}

SDL_bool SDLCALL SDL_SetHint(const char* name, const char* value) {
    typedef SDL_bool(*currFn) (const char*, const char*);
    static currFn SDL_SetHintFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_SetHint")));
    
    return SDL_SetHintFn(name, value);
}

int SDLCALL SDL_Init(Uint32 flags) {
    typedef int(*currFn) (Uint32);
    static currFn SDL_InitFn = reinterpret_cast<currFn>(dlsym(RTLD_DEFAULT, xorstr("SDL_Init")));
    
    return SDL_InitFn(flags);
}

ImGuiContext* ctx = ImGui::CreateContext();
ImGuiIO& io = ImGui::GetIO();
static SDL_GLContext original_context;
void InitImGui(SDL_Window* window){
    static SDL_GLContext context = NULL;
    original_context = SDL_GL_GetCurrentContext();
    if(!context){
        context = SDL_GL_CreateContext(window);
        ImGui_ImplSDL2_InitForOpenGL(window, context);
        ImGui_ImplOpenGL2_Init();
    }
    ctx = ImGui::GetCurrentContext();
    SDL_GL_MakeCurrent(window, context);
    IMGUI_CHECKVERSION();
    ImGui::StyleColorsDark();
    static bool LoadBytes = false;
    if(!LoadBytes){
        g_GirisFontBüyük = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(mysego_compressed_data, mysego_compressed_size, 20.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
        g_Font = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(mysego_compressed_data, mysego_compressed_size, 15.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
        g_Büyük = ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF(mysego_compressed_data, mysego_compressed_size, 30.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());
        LoadBytes = true;
    }
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();
    io = ImGui::GetIO(); (void)io;
}

uintptr_t* swapwindow_ptr = nullptr;
uintptr_t swapwindow_original = NULL;
bool SDLHook::_visible = false;
void SDLHook::SwapWindow(SDL_Window* window) {
    static void (*oSDL_GL_SwapWindow) (SDL_Window*) = reinterpret_cast<void(*)(SDL_Window*)>(swapwindow_original);
    InitImGui(window);
    if ( io.KeysDownDuration[73] == 0.0f )
        _visible = !_visible;
    
    //Just... Doesn't work...
//    if(_visible){
//        pSurface->UnlockCursor();
//    }
//    else{
//        pSurface->LockCursor();
//    }
    
    static ImDrawList* BackDrawList = ImGui::GetBackgroundDrawList();
    //OPENGL RENDERS
    // Visuals::ESP::EspImGui(BackDrawList); /* BETA */
    Visuals::Others::Watermark(BackDrawList);
    
    MenuRenderer::RenderMenu(_visible);
    oSDL_GL_SwapWindow(window);
    SDL_GL_MakeCurrent(window, original_context);
    glFlush(); //libSDL2's weird thing?
}

void SDLHook::Init() {
    ImGui::CreateContext(); // Ghetto MacOSX Context Crash Fix Like a Boss
    uintptr_t swapwindowFn = reinterpret_cast<uintptr_t>(dlsym(RTLD_DEFAULT, xorstr("SDL_GL_SwapWindow")));
    uintptr_t sdllib = reinterpret_cast<uintptr_t>(embryo::module(xorstr("libSDL2-2.0.0.dylib")).start());
    swapwindow_ptr = reinterpret_cast<uintptr_t*>(helpers::GetAbsoluteAddress(sdllib, swapwindowFn, 0xF, 0x4));
    swapwindow_original = *swapwindow_ptr;
    *swapwindow_ptr = reinterpret_cast<uintptr_t>(&SDLHook::SwapWindow); //Calls our Swap Window instead of the game's orginial.
    
    uintptr_t polleventFn = reinterpret_cast<uintptr_t>(dlsym(RTLD_DEFAULT, xorstr("SDL_PollEvent")));
    pollevent_ptr = reinterpret_cast<uintptr_t*>(helpers::GetAbsoluteAddress(sdllib, polleventFn, 0xF, 0x4));
    pollevent_original = *pollevent_ptr;
    *pollevent_ptr = reinterpret_cast<uintptr_t>(&PollEventHK); //Calls our Poll Event instead of the game's orginial.
    
}

void SDLHook::Unhook() {
    //Unhook doesn't work (?)
    _visible = false;
    ImGui_ImplOpenGL2_Shutdown(); //Shutdowns ImGui
    ImGui_ImplSDL2_Shutdown(); //Shutdowns ImGui
    *swapwindow_ptr = swapwindow_original; //Reverts back to game's original Swap Window.
    *pollevent_ptr = pollevent_original; //Reverts back to game's original Poll Event.
}
