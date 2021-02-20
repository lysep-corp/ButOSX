//
//  Helpers.hpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef Helpers_hpp
#define Helpers_hpp

#include <stdio.h>
#include <stdint.h>

namespace helpers {
    uintptr_t GetAbsoluteAddress(uintptr_t dwAddress, uintptr_t memoryPtr, uintptr_t startOffset, uintptr_t size);
}


#endif /* Helpers_hpp */
