//
//  TouchbarMenuRenderer.cpp
//  ButOSX
//
//  Created by Can on 10.02.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "CheatSettings.h"
#include "OpenGLHooker.hpp"
#include "TouchbarMenuRenderer.hpp"
#include "../../../Thirdparty/TouchBar-ObjectiveC/TouchBar.h"

//ButOSX
TBWMenuItem* butButton_Menu;

//Visuals
TBWMenuItem* visButton_ESP;
TBWMenuItem* visButton_Watermark;

//Assists

//Changers

//Others

//Settings
TBWMenuItem* setCol_ESP;

void TouchBarMenu::RenderTouchBar(){
    wrapperMenu = [[TBWrapperMenu alloc] init];
    mMenus = [[NSMutableArray alloc] init];
    
    TBWMenuContext* menu_Main = [wrapperMenu BeginMenu:@"ButOSX"];
    butButton_Menu = [menu_Main AddButton:@"In-Game Menu"];
    SDLHook::_visible = butButton_Menu->state;
    [wrapperMenu EndMenu:menu_Main];
    
    TBWMenuContext* menu_Visuals = [wrapperMenu BeginMenu:@"Visuals"];
    visButton_ESP = [menu_Visuals AddButton:@"ESP"];
    visButton_Watermark = [menu_Visuals AddButton:@"Watermark"];
    [wrapperMenu EndMenu:menu_Visuals];
    
    TBWMenuContext* menu_Assists = [wrapperMenu BeginMenu:@"Assists"];
    [wrapperMenu EndMenu:menu_Assists];
    
    TBWMenuContext* menu_Changers = [wrapperMenu BeginMenu:@"Changers"];
    [wrapperMenu EndMenu:menu_Changers];
    
    TBWMenuContext* menu_Others = [wrapperMenu BeginMenu:@"Others"];
    [wrapperMenu EndMenu:menu_Others];
    
    NSColor* TEST = NSColor.redColor;
    TBWMenuContext* menu_Settings = [wrapperMenu BeginMenu:@"Settings"];
    setCol_ESP = [menu_Settings AddColorPicker:@"ESP Color":TEST];
    [wrapperMenu EndMenu:menu_Settings];

    currentMenuTouchbarDelegate = [[CustomTouchBarDelegate alloc] init];
    [NSApplication sharedApplication].automaticCustomizeTouchBarMenuItemEnabled = YES;
    UpdateTouchBar(-1);
}

void TouchBarMenu::UpdateButtonInputs(){
    //IT RUINS IN GAME MENU CONTROLS BTW. TODO: FIX, IN GAME UI IS NOT USABLE BUG!
    
    SDLHook::_visible = butButton_Menu->state;
    
    CheatSettings::ESP::enabled = visButton_ESP->state;
    CheatSettings::WaterMark = visButton_Watermark->state;
}
