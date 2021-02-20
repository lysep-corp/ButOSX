//
//  ObjCWrapper.h
//  ButOSX
//
//  Created by Can on 10.02.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#ifndef ObjCWrapper_h
#define ObjCWrapper_h

namespace UserData {
    extern unsigned char* ImageBuffer;
    extern const char* UserName;
    extern const char* UserDefaultPath;
};

void GetUserDatas(void);

#endif /* ObjCWrapper_h */
