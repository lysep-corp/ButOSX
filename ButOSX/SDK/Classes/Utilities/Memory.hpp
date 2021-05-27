//
//  Memory.hpp
//  ButOSX
//
//  Created by Can on 27.05.2021.
//  Copyright © 2021 Lyceion. All rights reserved.
//

#ifndef Memory_hpp
#define Memory_hpp

#include <string>
#include <stdio.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <mach/mach.h>
#include <mach/error.h>
#include <mach-o/dyld.h>
#include <mach/vm_types.h>
#include <mach-o/getsect.h>

#include "xorstr.h"

namespace Memory {
    class Module{
        private:
            void* HeaderPTR = nullptr;
        public:
            std::string Name;
            std::string FilePath;
            uintptr_t Handle = NULL;
            uintptr_t Address = reinterpret_cast<uintptr_t>(HeaderPTR);
            inline uintptr_t* GetAbsoluteAddress(uintptr_t memoryPtr, uintptr_t size) {
                uintptr_t signatureAddress = memoryPtr + 0xF;
                uintptr_t offset = *reinterpret_cast<uint32_t*>(signatureAddress);
                uintptr_t fileOffset = signatureAddress - Address;
                
                return reinterpret_cast<uintptr_t*>(Address + (offset + fileOffset) + size);
            }
            bool IsRunning {Handle ? true : false};
            Module(std::string ModuleName){
                for (int i = 0; i < _dyld_image_count(); i++)
                {
                    mach_header* header = (mach_header*)(_dyld_get_image_header(i)); // extern const struct mach_header* _dyld_get_image_header(uint32_t image_index)
                    
                    std::string imageFilePath(_dyld_get_image_name(i)); //extern const char* _dyld_get_image_name(uint32_t image_index)
                    if (imageFilePath.empty()) continue;
                    
                    //EXTRACT FILE NAME FROM RELATIVE PATH
                    std::string imageName;
                    size_t pos = imageFilePath.rfind(xorstr("/"), imageFilePath.length());
                    if (pos != std::string::npos)
                        imageName = imageFilePath.substr(pos+1, imageFilePath.length() - pos);
                    if (imageName != ModuleName) continue;
                    
                    IsRunning = TRUE;
                    HeaderPTR = header;
                    Name = ModuleName;
                    FilePath = imageFilePath;
                    Handle = reinterpret_cast<uintptr_t>(dlopen(imageFilePath.c_str(), RTLD_GLOBAL | RTLD_LAZY));
                    
                    break;
                }
            }
        ~Module(){free(HeaderPTR);};
    };
}

#endif /* Memory_hpp */
