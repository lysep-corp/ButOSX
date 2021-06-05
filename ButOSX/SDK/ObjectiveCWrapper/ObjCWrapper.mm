//
//  ObjCWrapper.m
//  ButOSX
//
//  Created by Can on 10.02.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#include "ObjCWrapper.h"

NSData*             UserData::ImageBuffer;
const char*         UserData::UserName;
NSString*           UserData::UserDefaultPath;
unsigned char*      UserData::ImageData;

void GetUserImage(){
    CBIdentity *identity = [CBIdentity identityWithName:NSUserName() authority:[CBIdentityAuthority defaultIdentityAuthority]];
    NSArray *representations; NSData *bitmapBuffer;
    representations = [[identity image] representations];
    bitmapBuffer = [NSBitmapImageRep representationOfImageRepsInArray:representations usingType:NSBitmapImageFileTypeJPEG properties:[NSDictionary dictionaryWithObject:[NSDecimalNumber numberWithFloat:1.0]
        forKey:NSImageCompressionFactor]];
    //NSString *temp = [@"/Users/" stringByAppendingString:NSUserName()];
    //[bitmapData writeToFile:[temp stringByAppendingString:@"/img.jpeg"] atomically:YES];
    UserData::ImageBuffer = bitmapBuffer;
    UserData::ImageData   = (unsigned char*)[bitmapBuffer bytes];
}

void GenerateUserImage(){
    [UserData::ImageBuffer writeToFile:[UserData::UserDefaultPath stringByAppendingString:[NSString stringWithUTF8String:xorstr("/.but-osx/user.jpeg")]] atomically:YES];
}

void GetUserName(){
    UserData::UserName = [NSUserName() UTF8String];
}

void GetUserDefaultPath(){
    UserData::UserDefaultPath = [NSString stringWithUTF8String:[[[NSString stringWithUTF8String:xorstr("/Users/")] stringByAppendingString:NSUserName()] UTF8String]];
}

void GetUserDatas(){
    GetUserName();
    GetUserDefaultPath();
    GetUserImage();
    GenerateUserImage();
}
