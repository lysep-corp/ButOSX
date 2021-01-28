//
//  NSTouchBar.m
//  ButOSX
//
//  Created by Maze on 23.01.2021.
//  Copyright © 2021 VersteckteKrone. All rights reserved.
//

#include "NSTouchBar.h"

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

static NSString *touchBarCustomizationId = @"com.butosx.customization";
static NSString *touchBarItemId = @"com.butosx.defaultitem";

static NSButton *_button;

@interface GLFWTouchBarDelegate : NSObject <NSTouchBarDelegate>
    - (NSTouchBar *)makeTouchBar;
    - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier;
    - (void)glfwButtonAction:(id)sender;
@end

@implementation GLFWTouchBarDelegate
    - (NSTouchBar *)makeTouchBar
    {
        // Create TouchBar object
        NSTouchBar *touchBar = [[NSTouchBar alloc] init];
        touchBar.delegate = self;
        touchBar.customizationIdentifier = touchBarCustomizationId;

        // Set the default ordering of items.
        touchBar.defaultItemIdentifiers = @[touchBarItemId, NSTouchBarItemIdentifierOtherItemsProxy];
        touchBar.customizationAllowedItemIdentifiers = @[touchBarItemId];
        touchBar.principalItemIdentifier = touchBarItemId;

        return touchBar;
    }

    - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier
    {
        if ([identifier isEqualToString:touchBarItemId])
        {
            _button = [NSButton buttonWithTitle:NSLocalizedString(@"ButOSX", @"") target:self action:@selector(glfwButtonAction:)];
            if(!SDLHook::_visible)
                _button.bezelColor = NSColor.systemRedColor;
            else
                _button.bezelColor = NSColor.systemGreenColor;
            NSCustomTouchBarItem* g_TouchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:touchBarItemId];
            g_TouchBarItem.view = _button;
            g_TouchBarItem.customizationLabel = NSLocalizedString(@"Truth Button", @"");

            return g_TouchBarItem;
        }

        return nil;
    }

    - (void)glfwButtonAction:(id)sender
    {
        //tests
        if( !SDLHook::_visible )
            _button.bezelColor = NSColor.systemGreenColor;
        else
            _button.bezelColor = NSColor.systemRedColor;
        SDLHook::_visible=!SDLHook::_visible;
    }
@end

GLFWTouchBarDelegate* g_TouchBarDelegate = NULL;
void ShowTouchBar()
{
    if (!g_TouchBarDelegate) {
        g_TouchBarDelegate = [[GLFWTouchBarDelegate alloc] init];
        [NSApplication sharedApplication].automaticCustomizeTouchBarMenuItemEnabled = YES;
    }

    NSTouchBar* touchBar = [g_TouchBarDelegate makeTouchBar];

    NSArray<NSWindow*>* windows = [NSApplication sharedApplication].windows;
    for (int i = 0; i < windows.count; ++i) {
        NSWindow* wnd = windows[i];
        wnd.touchBar = touchBar;
    }
}
