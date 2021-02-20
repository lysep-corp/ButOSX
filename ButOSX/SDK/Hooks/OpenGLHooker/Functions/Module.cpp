//
//  Module.cpp
//  ButOSX
//
//  Created by Can on 29.10.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#include "Module.hpp"

std::string getFileNameFromPath(const std::string& path) //PASTED
{
    int pos = (int)path.length();
    while (pos && path[pos] != '/') --pos;
    return path.substr(pos + 1);
}
namespace embryo { //PASTED
    module::module(const std::string& name) : m_start(0), m_size(0) //PASTED
    {
        bool found = false;
        unsigned int imageCount = _dyld_image_count();
        for (int i = 0; i < imageCount; i++)
        {
            mach_header *header = (mach_header *)_dyld_get_image_header(i);
            
            const char *imageName = _dyld_get_image_name(i);
            if (!imageName) continue;
            
            std::string shortName = getFileNameFromPath(std::string(imageName));
            if (shortName != name) continue;
            
            struct stat sb;
            if (stat(imageName, &sb))
            {
                break;
            }
            found = true;
            m_start = (void *)header;
            m_size = (unsigned int)sb.st_size;
            m_header = header;
            m_name = shortName;
            m_path = std::string(imageName);
            m_handle = dlopen(imageName, RTLD_GLOBAL | RTLD_LAZY);
            break;
        }
    }
}
