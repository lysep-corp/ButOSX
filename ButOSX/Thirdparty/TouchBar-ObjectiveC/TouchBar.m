//
//  TouchBar.m
//  TouchBar.h
//  ButOSX
//
//  Created by Can on 19.02.2021.
//  Created by Can on 4.04.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//
// YEAH STOLEN FROM https://github.com/xMuratY/TouchBar-ObjectiveC w/His permission (He is in the contributors what can i else do?!?)

#import "TouchBar.h"
#import "OpenGLHooker.hpp"

@implementation TBWMenuItem
    
@end

NSInteger objIdGlobal = 1000;
@implementation TBWMenuContext
    -(TBWMenuItem*)AddButton:(NSString*)title
    {
        return [self AddButton:title:NULL:NULL];
    }
    -(TBWMenuItem*)AddButtonWithImage:(NSString*)title :(NSString*)image
    {
        return [self AddButton:title:image:NULL];
    }
    -(TBWMenuItem*)AddColorPicker:(NSString*)title :(NSColor*)defaultColor;
    {
        return [self AddButton:title:NULL:defaultColor];
    }
    -(TBWMenuItem*)AddButton:(NSString*)title :(NSString*)image :(NSColor*)defaultColor
    {
        TBWMenuItem* menuItem = [TBWMenuItem alloc];
        menuItem->state = false;
        menuItem->title = title;
        menuItem->objid = objIdGlobal;
        menuItem->btnimage = image;
        menuItem->color = defaultColor;
        menuItem->btnimage = NULL;
        menuItem->colReferance = NULL;
        
        [mItems addObject:menuItem];
        objIdGlobal++;
        return menuItem;
    }
@end


NSMutableArray<TBWMenuContext *> *mMenus;
NSInteger     ctxIdGlobal = 0;

@implementation TBWrapperMenu


- (TBWMenuContext*)BeginMenu:(NSString*)title
{
    return [self BeginMenu:title : 0];
}

- (TBWMenuContext*)BeginMenu:(NSString*)title  : (NSString*) image
{
    TBWMenuContext* context = [TBWMenuContext alloc];
    context->title = title;
    context->ctxid = ctxIdGlobal;
    context->mItems = [[NSMutableArray alloc] init];
    context->btnimage = image;
    ctxIdGlobal++;
    return context;
}

- (void)EndMenu:(TBWMenuContext*)context
{
    [mMenus addObject:context];
}

- (NSArray<NSString*>*)GetCtx: (NSInteger)ctxID
{
    NSMutableArray<NSString*> *array = [[NSMutableArray alloc] init];
    [mMenus enumerateObjectsUsingBlock:^(TBWMenuContext* object, NSUInteger idx, BOOL *stop) {
        
        if(ctxID != -1)
        {
            if ( ctxID != object->ctxid )
                return;
            [object->mItems enumerateObjectsUsingBlock:^(TBWMenuItem* altobject, NSUInteger idx, BOOL *stop)
            {
                if(altobject->color == NULL)
                    [array addObject:[NSString stringWithFormat:@"%ld:%ld:%@:%@:%d", object->ctxid, altobject->objid, altobject->title, altobject->btnimage, altobject->state]];
                else
                {
                    [array addObject:[NSString stringWithFormat:@"%ld:%ld:coloritemtitle:%@", object->ctxid, altobject->objid, altobject->title]];
                    [array addObject:[NSString stringWithFormat:@"%ld:%ld:coloritem", object->ctxid, altobject->objid]];
                }
            }];
        }else
        {
            [array addObject:[NSString stringWithFormat:@"%ld:%@:%@", object->ctxid,object->title, object->btnimage]];
        }
    }];
    return [NSArray arrayWithArray:array];
}
@end

TBWrapperMenu* wrapperMenu;

@interface CustomTouchBarDelegate : NSObject <NSTouchBarDelegate>
    - (NSTouchBar *)makeTouchBar: (NSInteger)touchbarIdentifier;
    - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier;
    - (void)glfwButtonAction:(id)sender;
- (void)colorAction:(id)sender;
@end

@implementation CustomTouchBarDelegate
    - (NSTouchBar *)makeTouchBar: (NSInteger)touchbarIdentifier
    {
        NSTouchBar *touchBar = [[NSTouchBar alloc] init];
        touchBar.delegate = self;
        
        NSArray<NSString*>* mIdentifiers = [[ NSArray alloc] init];
        if( touchbarIdentifier != -1 )
        {
            mIdentifiers = [ mIdentifiers arrayByAddingObject:@".backbuttonidentifier" ];
        }
        mIdentifiers = [mIdentifiers arrayByAddingObjectsFromArray: [wrapperMenu GetCtx:touchbarIdentifier] ];
        touchBar.defaultItemIdentifiers = [NSArray arrayWithArray:mIdentifiers];
        return touchBar;
    }

    - (NSTouchBarItem *)touchBar:(NSTouchBar *)touchBar makeItemForIdentifier:(NSTouchBarItemIdentifier)identifier
    {
        if( [identifier isEqualToString:@".backbuttonidentifier"] )
        {
            NSButton* mButton = [NSButton buttonWithTitle:@"" target:self action:@selector(glfwButtonAction:)];
            [mButton setTag:-999];
            [mButton setImage:[NSImage imageNamed:NSImageNameTouchBarGoBackTemplate]];
            NSCustomTouchBarItem* mTouchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:identifier];
            [mTouchBarItem setView:mButton];
            return mTouchBarItem;
        }
        
        NSArray<NSString*>* identifierSplitResult = [identifier componentsSeparatedByString:@":"];
        
        NSInteger identifierSplitCount = identifierSplitResult.count;
                
        if( identifierSplitCount < 3 )
            return nil;
        
        
        if( [identifierSplitResult[2] isEqualToString:@"coloritemtitle"] )
        {
            NSCustomTouchBarItem* colorpickerlbl = [[NSCustomTouchBarItem alloc] initWithIdentifier:identifier];
            [colorpickerlbl setView:[NSTextField labelWithString:identifierSplitResult[3]]];
            return colorpickerlbl;
        }
        
        if( [identifierSplitResult[2] isEqualToString:@"coloritem"] )
        {
            NSColorPickerTouchBarItem *colorPickerItem = [NSColorPickerTouchBarItem colorPickerWithIdentifier:identifier];
            [colorPickerItem setTarget:self];
            [colorPickerItem setAction:@selector(colorAction:)];
            
            [colorPickerItem setCustomizationLabel:identifierSplitResult[1]];

            [mMenus enumerateObjectsUsingBlock:^(TBWMenuContext* object, NSUInteger idx1, BOOL *stop1) {
                if(object->ctxid != [identifierSplitResult[0] intValue])
                    return;
                [object->mItems enumerateObjectsUsingBlock:^(TBWMenuItem* altobject, NSUInteger idx2, BOOL *stop2)
                {
                    if(altobject->objid == [identifierSplitResult[1] intValue])
                    {
                        [colorPickerItem setColor:altobject->color];
                        altobject->colReferance = colorPickerItem;
                        *stop1 = *stop2 = YES;
                        return;
                    }
                }];
            }];
            return colorPickerItem;
        }
        
        NSInteger baseCounter = identifierSplitCount == 5 ? 1 : 0;
        
        NSButton* mButton = [NSButton buttonWithTitle:identifierSplitResult[baseCounter+1] target:self action:@selector(glfwButtonAction:)];
        
        if( ![identifierSplitResult[baseCounter+2] isEqualToString:@"(null)"] )
        {
            NSImage* image = [NSImage imageNamed:identifierSplitResult[baseCounter+2]];
            [mButton setImage:image];
            [mButton setImagePosition:NSImageLeft];
        }
        
        [mButton setTag:[identifierSplitResult[baseCounter] intValue]];
        
        if([mButton tag] >= 1000)
        {
            NSColor* btnColor = [identifierSplitResult[baseCounter+3] intValue] == 0 ? NSColor.systemRedColor : NSColor.systemGreenColor;
            [mButton setBezelColor:btnColor];
        }
        
        NSCustomTouchBarItem* mTouchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:identifier];
        [mTouchBarItem setView:mButton];
        
        [mMenus enumerateObjectsUsingBlock:^(TBWMenuContext* object, NSUInteger idx1, BOOL *stop1) {
            [object->mItems enumerateObjectsUsingBlock:^(TBWMenuItem* altobject, NSUInteger idx2, BOOL *stop2)
            {
                if(altobject->objid == [mButton tag])
                {
                    altobject->btnReferance = mTouchBarItem;
                    *stop1 = *stop2 = YES;
                    return;
                }
            }];
        }];
        return mTouchBarItem;
    }

    - (void)glfwButtonAction:(id)sender
    {
        if ( [sender tag] >= 1000 )
        {
            NSButton* senderbtn = (NSButton*)sender;
            NSColor* colorResult = ((NSButton*)sender).bezelColor == NSColor.systemRedColor ? NSColor.systemGreenColor : NSColor.systemRedColor;
            [senderbtn setBezelColor:colorResult];
            
            [mMenus enumerateObjectsUsingBlock:^(TBWMenuContext* object, NSUInteger idx1, BOOL *stop1) {
                [object->mItems enumerateObjectsUsingBlock:^(TBWMenuItem* altobject, NSUInteger idx2, BOOL *stop2)
                {
                    if(altobject->objid == [sender tag])
                    {
                        altobject->state = !altobject->state;
                        *stop1 = *stop2 = YES;
                        return;
                    }
                }];
            }];
            
            return;
        }
        
        NSString* identifierstr = [sender title];

        printf("Clicked %s - %ld\n", identifierstr.UTF8String, [sender tag]);
       
        UpdateTouchBar([sender tag]);
    }

    - (void)colorAction:(id)sender
    {
        [mMenus enumerateObjectsUsingBlock:^(TBWMenuContext* object, NSUInteger idx1, BOOL *stop1) {
            [object->mItems enumerateObjectsUsingBlock:^(TBWMenuItem* altobject, NSUInteger idx2, BOOL *stop2)
            {
                if(altobject->objid == [[sender customizationLabel] intValue])
                {
                    altobject->color = [sender color];
                    *stop1 = *stop2 = YES;
                    return;
                }
            }];
        }];
    }

@end

CustomTouchBarDelegate* currentMenuTouchbarDelegate = NULL;

void UpdateTouchBar(NSInteger iIndex)
{
    NSInteger indexResult = iIndex;
    if( indexResult < 0 )
        indexResult = -1;
    NSTouchBar* mTouchBar = [currentMenuTouchbarDelegate makeTouchBar:indexResult];
    
    NSArray<NSWindow*>* windows = [NSApplication sharedApplication].windows;
    for (int i = 0; i < windows.count; ++i) {
        NSWindow* wnd = windows[i];
        wnd.touchBar = mTouchBar;
    }
}

void UpdateButton(TBWMenuItem* _btn){
    NSButton* btn = (NSButton*)_btn->btnReferance.view;
    NSColor* colorResult = _btn->state ? NSColor.systemGreenColor : NSColor.systemRedColor;
    [btn setBezelColor:colorResult];
}


TBWMenuItem* butButton_Menu;

TBWMenuItem* visButton_ESP;
TBWMenuItem* visButton_Watermark;

TBWMenuItem* setCol_ESP;

void RenderTouchBar(){
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
