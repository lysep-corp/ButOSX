//
//  VMT.h
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef VMT_h
#define VMT_h
#pragma once

class VMT
{
private:
    unsigned int methodCount = 0;
    uintptr_t* vmtAddr;
    uintptr_t* original_vmt = nullptr;
    uintptr_t** interface = nullptr;
public:
    
    VMT(void* interface, void* method, size_t index)
    {
        this->interface = reinterpret_cast<uintptr_t**>(interface);
        size_t method_count = 0;
        while (reinterpret_cast<uintptr_t*>(*this->interface)[method_count])
            method_count++;
        original_vmt = *this->interface;
        vmtAddr = new uintptr_t[sizeof(uintptr_t) * method_count];
        memcpy(vmtAddr, original_vmt, sizeof(uintptr_t) * method_count);
        vmtAddr[index] = reinterpret_cast<uintptr_t>(method);
        *this->interface = vmtAddr;
    }
    ~VMT() { delete (vmtAddr); delete (original_vmt); delete (interface); }
    template<typename T>
    T GetMethod(size_t index)
    {
        return reinterpret_cast<T>(original_vmt[index]);
    }
    void Release()
    {
        free(vmtAddr);
        free(interface);
        free(original_vmt);
    }
};

#endif /* VMT_h */
