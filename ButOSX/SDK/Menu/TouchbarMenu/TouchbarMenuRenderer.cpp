//
//  TouchbarMenuRenderer.cpp
//  ButOSX
//
//  Created by Can on 10.02.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "TouchbarMenuRenderer.hpp"
#include "../../../Thirdparty/TouchBar-ObjectiveC/TouchBar.h"
#include "CheatSettings.h"


void TouchBarMenu::RenderTouchBar(){
    //RENDER TOUCHBAR CODES
    wrapperMenu = [[TBWrapperMenu alloc] init];
    mMenus = [[NSMutableArray alloc] init];
    TBWMenuContext* menu_Test = [wrapperMenu BeginMenu:@"ButOSX"];

    TBWMenuItem* menuitem_Opt1 = [menu_Test AddButton:@"ESP"];
    CheatSettings::ESP::enabled = menuitem_Opt1->state;

    [wrapperMenu EndMenu:menu_Test];

    currentMenuTouchbarDelegate = [[CustomTouchBarDelegate alloc] init];
    [NSApplication sharedApplication].automaticCustomizeTouchBarMenuItemEnabled = YES;
    UpdateTouchBar(-1);
}
