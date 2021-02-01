//
//  PatternScanner.cpp
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 VersteckteKrone. All rights reserved.
//
//All Credits goes to: https://github.com/aKalisch/gosx-public-external/blob/f41c9ec45eb0cc657fa81c50b45bd966e302be22/Engine/MemoryManager/pattern.cpp

#include "PatternScanner.hpp"
#include <stdio.h>
#include <string>
#include <deque>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <codecvt>          // codecvt_utf8 // string to wchar
#include <dlfcn.h>
#include <zconf.h>          // Byte
#include <sys/stat.h>
#include <sys/mman.h>       // used in protect_addr
#include <mach-o/dyld_images.h>


C_PatternScanner* C_PatternScanner::_instance = nullptr;

C_PatternScanner::C_PatternScanner()
{
    load_modules();
}

string C_PatternScanner::base_name(string const& pathname)
{
    return string(find_if(pathname.rbegin(), pathname.rend(), [](char ch) { return ch == '\\' || ch == '/'; }).base(), pathname.end());
}

void C_PatternScanner::load_modules()
{
    struct task_dyld_info dyld_info;
    vm_address_t address = 0;
    mach_msg_type_number_t count = TASK_DYLD_INFO_COUNT;
    
    if(task_info(current_task(), TASK_DYLD_INFO, (task_info_t)&dyld_info, &count) == KERN_SUCCESS)
        address = (vm_address_t)dyld_info.all_image_info_addr;
    
    struct dyld_all_image_infos* dyldaii;
    mach_msg_type_number_t size = sizeof(dyld_all_image_infos);
    vm_offset_t readMem;
    kern_return_t kr = vm_read(current_task(), address, size, &readMem, &size);
    
    if(kr != KERN_SUCCESS)
        return;
    
    dyldaii = (dyld_all_image_infos*) readMem;
    
    int imageCount = dyldaii->infoArrayCount;
    mach_msg_type_number_t dataCnt  = imageCount * 24;
    struct dyld_image_info* g_dii   = (struct dyld_image_info*)malloc(dataCnt);
    
    // 32bit bs 64bit
    kern_return_t kr2 = vm_read(current_task(), (vm_address_t)dyldaii->infoArray, dataCnt, &readMem, &dataCnt);
    if (kr2)
    {
        free(g_dii);
        return;
    }
    
    struct dyld_image_info* dii = (struct dyld_image_info*)readMem;
    
    for (int i = 0; i < imageCount; i++)
    {
        dataCnt = 1024;
        vm_read(current_task(), (vm_address_t)dii[i].imageFilePath, dataCnt, &readMem, &dataCnt);
        
        char* imageName = (char*)readMem;
        
        if (imageName)
            g_dii[i].imageFilePath = strdup(imageName);
        else
            g_dii[i].imageFilePath = NULL;
        
        g_dii[i].imageLoadAddress = dii[i].imageLoadAddress;
        
        memory_module_t memoryModule;
        struct stat st;
        stat(imageName, &st);
        
        memoryModule.address    = (vm_address_t)dii[i].imageLoadAddress;
        memoryModule.length     = st.st_size;
        memoryModule.path       = imageName;
        memoryModule.fullpath   = g_dii[i].imageFilePath;
        
        loaded_modules[base_name(imageName)] = memoryModule;
    }
    
    free(g_dii);
    
}

bool C_PatternScanner::compare(const unsigned char* pData, const unsigned char* bMask, const char* szMask)
{
    for (; *szMask; ++szMask, ++pData, ++bMask)
    {
        if (*szMask == 'x' && *pData != *bMask)
            return false;
    }
    
    return (*szMask) == 0;
}

uintptr_t C_PatternScanner::find_pattern(uintptr_t dwAddress, off_t dwLen, unsigned char* bMask, const char* szMask, uintptr_t offset)
{
    for (uintptr_t i = offset; i < dwLen; i++)
    {
        if (compare((unsigned char*)(dwAddress + i), bMask, szMask))
            return (uintptr_t)(dwAddress + i);
    }
    
    return 0;
}

uintptr_t C_PatternScanner::get_pointer(string imageName, unsigned char* bMask, const char* szMask, uint32_t start)
{
    memory_module_t module = loaded_modules[imageName];
    uintptr_t dwAddress = module.address;
    off_t dwLen = module.length;
    
    uintptr_t signatureAddress = find_pattern(dwAddress, dwLen, bMask, szMask) + start;
    uintptr_t fileOffset = signatureAddress - dwAddress;
    uintptr_t offset = *reinterpret_cast<uint32_t*>(signatureAddress);
    
    return dwAddress + (offset + fileOffset);
}

uintptr_t C_PatternScanner::get_procedure(string imageName, unsigned char* bMask, const char* szMask, uintptr_t offset)
{
    memory_module_t module = loaded_modules[imageName];
    uintptr_t dwAddress = module.address;
    off_t dwLen = module.length;
    
    return find_pattern(dwAddress, dwLen, bMask, szMask, offset);
}

string C_PatternScanner::get_module_path(string imageName)
{
    return loaded_modules[imageName].path;
}

uintptr_t C_PatternScanner::get_base_address(string imageName)
{
    memory_module_t module = loaded_modules[imageName];
    return module.address;
}
