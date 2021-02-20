//
//  TouchBar.m
//  ButOSX
//
//  Created by Can on 19.02.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//
// YEAH STOLEN FROM https://github.com/xMuratY/TouchBar-ObjectiveC w/His permission

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

void UpdateTouchBar(NSInteger iIndex);

@interface TBWMenuItem : NSObject {
    @public
        NSString* title;
        bool state;
        NSInteger objid;
}
@end
@implementation TBWMenuItem
@end

@interface TBWMenuContext : NSObject {
@public
    NSString* title;
    NSInteger ctxid;
    NSMutableArray<TBWMenuItem *> *mItems;
}

-(TBWMenuItem*)AddButton:(NSString*)title;
@end

NSInteger objIdGlobal = 1000;
@implementation TBWMenuContext
    -(TBWMenuItem*)AddButton:(NSString*)title
    {
        TBWMenuItem* menuItem = [TBWMenuItem alloc];
        menuItem->state = false;
        menuItem->title = title;
        menuItem->objid = objIdGlobal;
        [mItems addObject:menuItem];
        objIdGlobal++;
        return menuItem;
    }
@end

NSMutableArray<TBWMenuContext *> *mMenus;
NSInteger     ctxIdGlobal = 0;

@interface TBWrapperMenu : NSObject
    - (TBWMenuContext*)BeginMenu:(NSString*)title;
    - (void)EndMenu:(TBWMenuContext*)context;
    - (NSArray<NSString*>*)GetCtx: (NSInteger)ctxID;
@end

@implementation TBWrapperMenu

- (TBWMenuContext*)BeginMenu:(NSString*)title
{
    TBWMenuContext* context = [TBWMenuContext alloc];
    context->title = title;
    context->ctxid = ctxIdGlobal;
    context->mItems = [[NSMutableArray alloc] init];
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
                [array addObject:[NSString stringWithFormat:@"%ld:%ld:%@:%d", object->ctxid, altobject->objid, altobject->title, altobject->state]];
            }];
        }else
        {
            [array addObject:[NSString stringWithFormat:@"%ld:%@", object->ctxid,object->title]];
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
                
        if( identifierSplitCount < 2 )
            return nil;
                
        NSInteger baseCounter = identifierSplitCount == 4 ? 1 : 0;
        
        NSButton* mButton = [NSButton buttonWithTitle:identifierSplitResult[baseCounter+1] target:self action:@selector(glfwButtonAction:)];
        [mButton setTag:[identifierSplitResult[baseCounter] intValue]];
        if([mButton tag] >= 1000)
        {
            NSColor* btnColor = [identifierSplitResult[baseCounter+2] intValue] == 0 ? NSColor.systemRedColor : NSColor.systemGreenColor;
            [mButton setBezelColor:btnColor];
        }

        NSCustomTouchBarItem* mTouchBarItem = [[NSCustomTouchBarItem alloc] initWithIdentifier:identifier];
        [mTouchBarItem setView:mButton];

        return mTouchBarItem;
    }

    - (void)glfwButtonAction:(id)sender
    {
        if ( [sender tag] >= 1000 )
        {
            NSButton* senderbtn = (NSButton*)sender;
            NSColor* colorResult = ((NSButton*)sender).bezelColor == NSColor.systemRedColor ? NSColor.systemGreenColor : NSColor.systemRedColor;
            [senderbtn setBezelColor:colorResult];
            
            [mMenus enumerateObjectsUsingBlock:^(TBWMenuContext* object, NSUInteger idx, BOOL *stop) {
                [object->mItems enumerateObjectsUsingBlock:^(TBWMenuItem* altobject, NSUInteger idx, BOOL *stop)
                {
                    if(altobject->objid == [sender tag])
                        altobject->state = !altobject->state;
                }];
            }];
            
            return;
        }
        
        NSString* identifierstr = [sender title];
        UpdateTouchBar([sender tag]);
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

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
    wrapperMenu = [[TBWrapperMenu alloc] init];
    mMenus = [[NSMutableArray alloc] init];
    TBWMenuContext* menu_Test = [wrapperMenu BeginMenu:@"Test"];
    
    TBWMenuItem* menuitem_Opt1 = [menu_Test AddButton:@"Opt1"];
    TBWMenuItem* menuitem_Opt2 = [menu_Test AddButton:@"Opt2"];
    TBWMenuItem* menuitem_Opt3 = [menu_Test AddButton:@"Opt3"];
    
    [wrapperMenu EndMenu:menu_Test];
    
    TBWMenuContext* menu_TestEmpty = [wrapperMenu BeginMenu:@"Test Empty"];
    [wrapperMenu EndMenu:menu_TestEmpty];
    
    currentMenuTouchbarDelegate = [[CustomTouchBarDelegate alloc] init];
    [NSApplication sharedApplication].automaticCustomizeTouchBarMenuItemEnabled = YES;
    UpdateTouchBar(-1);
}

@end
