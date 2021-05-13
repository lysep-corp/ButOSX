//
//  TouchBar.h
//  ButOSX
//
//  Created by Can on 4.04.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#ifndef TouchBar_h
#define TouchBar_h
#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@interface TBWMenuItem : NSObject {
    @public
        NSString* title;
        bool state;
        NSInteger objid;
        NSString *btnimage;
        NSColor* color;
        NSCustomTouchBarItem* btnReferance;
        NSColorPickerTouchBarItem* colReferance;
}
@end

@interface TBWMenuContext : NSObject {
@public
    NSString* title;
    NSInteger ctxid;
    NSString *btnimage;
    NSMutableArray<TBWMenuItem *> *mItems;
}

-(TBWMenuItem*)AddButton:(NSString*)title;
-(TBWMenuItem*)AddButtonWithImage:(NSString*)title :(NSString*)image;
-(TBWMenuItem*)AddColorPicker:(NSString*)title :(NSColor*)defaultColor;
-(TBWMenuItem*)AddButton:(NSString*)title :(NSString*)image :(NSColor*)defaultColor;
@end

@interface TBWrapperMenu : NSObject
    - (TBWMenuContext*)BeginMenu:(NSString*)title;
    - (TBWMenuContext*)BeginMenu:(NSString*)title : (NSString*) image;
    - (void)EndMenu:(TBWMenuContext*)context;
    - (NSArray<NSString*>*)GetCtx: (NSInteger)ctxID;
@end

extern TBWMenuItem* butButton_Menu;

extern TBWMenuItem* visButton_ESP;
extern TBWMenuItem* visButton_Watermark;
extern TBWMenuItem* visButton_NightMode;
extern TBWMenuItem* visButton_NoVisRecoil;
extern TBWMenuItem* visButton_NoFlash;
extern TBWMenuItem* visButton_SniperCrosshair;
extern TBWMenuItem* visButton_RecoilCrosshair;
extern TBWMenuItem* visButton_GrenadePrediction;

extern TBWMenuItem* setCol_ESP;

extern TBWrapperMenu* wrapperMenu;

void UpdateTouchBar(NSInteger iIndex);
extern void UpdateButton(TBWMenuItem* _btn);
extern void RenderTouchBar();

#endif /* TouchBar_h */
