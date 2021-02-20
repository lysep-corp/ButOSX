//
//  ObjCWrapper.m
//  ButOSX
//
//  Created by Can on 10.02.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "ObjCWrapper.h"

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <Collaboration/Collaboration.h>


unsigned char*      UserData::ImageBuffer;
const char*         UserData::UserName;
const char*         UserData::UserDefaultPath;

void GetUserImage(){
    CBIdentity *identity = [CBIdentity identityWithName:NSUserName() authority:[CBIdentityAuthority defaultIdentityAuthority]];
    NSArray *representations; NSData *bitmapData;
    representations = [[identity image] representations];
    bitmapData = [NSBitmapImageRep representationOfImageRepsInArray:representations usingType:NSBitmapImageFileTypeJPEG properties:[NSDictionary dictionaryWithObject:[NSDecimalNumber numberWithFloat:1.0]
        forKey:NSImageCompressionFactor]];
    //NSString *temp = [@"/Users/" stringByAppendingString:NSUserName()];
    //[bitmapData writeToFile:[temp stringByAppendingString:@"/img.jpeg"] atomically:YES];
    UserData::ImageBuffer = (unsigned char*)[bitmapData bytes];
}

void GetUserName(){
    UserData::UserName = [NSUserName() UTF8String];
}

void GetUserDefaultPath(){
    UserData::UserDefaultPath = [[@"/Users/" stringByAppendingString:NSUserName()] UTF8String];
}

void GetUserDatas(){
    GetUserName();
    GetUserImage();
    GetUserDefaultPath();
}
