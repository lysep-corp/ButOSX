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
    uintptr_t* vmt;
public:
    
    uintptr_t**  interface      = nullptr;
    uintptr_t*   original_vmt   = nullptr;
    unsigned int methodCount    = 0;
    
public:
    
    VMT(void* interface)
    {
        this->interface = reinterpret_cast<uintptr_t**>(interface);
        
        size_t method_count = 0;
        
        while (reinterpret_cast<uintptr_t*>(*this->interface)[method_count])
            method_count++;
        
        original_vmt = *this->interface;
        
        vmt = new uintptr_t[sizeof(uintptr_t) * method_count];
        
        memcpy(vmt, original_vmt, sizeof(uintptr_t) * method_count);
    }
    ~VMT() { delete (vmt); delete (original_vmt); delete (interface); }
    
    // Hook virtual method
    void HookVM(void* method, size_t methodIndex)
    {
        vmt[methodIndex] = reinterpret_cast<uintptr_t>(method);
    }
    
    template<typename T>
    T GetOriginalMethod(size_t methodIndex)
    {
        return reinterpret_cast<T>(original_vmt[methodIndex]);
    }
    
    void ApplyVMT()
    {
        *this->interface = vmt;
    }
    
    void ReleaseVMT()
    {
        free(vmt);
        free(interface);
        free(original_vmt);
    }
};


#endif /* VMT_h */
