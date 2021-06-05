//
//  ObjCWrapper.h
//  ButOSX
//
//  Created by Can on 10.02.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#ifndef ObjCWrapper_h
#define ObjCWrapper_h

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <Collaboration/Collaboration.h>

#include "xorstr.h"

namespace UserData {
    extern NSData* ImageBuffer;
    extern const char* UserName;
    extern NSString* UserDefaultPath;
    extern unsigned char* ImageData;
};

extern void GetUserDatas();

#endif /* ObjCWrapper_h */
