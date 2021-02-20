//
//  Helpers.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "Helpers.hpp"
namespace helpers { //PASTED

    uintptr_t GetAbsoluteAddress(uintptr_t dwAddress, uintptr_t memoryPtr, uintptr_t startOffset, uintptr_t size) {
        uintptr_t signatureAddress = memoryPtr + startOffset;
        uintptr_t fileOffset = signatureAddress - dwAddress;
        uintptr_t offset = *reinterpret_cast<uint32_t*>(signatureAddress);
        
        return dwAddress + (offset + fileOffset) + size;
    }
}
