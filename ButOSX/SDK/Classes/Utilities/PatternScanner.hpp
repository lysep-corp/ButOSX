#pragma once
#include <map>
using namespace std;

struct memory_module_t
{
    off_t           length;
    uint64_t        address;
    char*           path;
    const char*     fullpath;
    unsigned char*  buffer = nullptr;
};

class C_PatternScanner
{
private:
    
    map<string, memory_module_t> loaded_modules;
    
    static C_PatternScanner* _instance;
    
private:
    
    void load_modules();
    
public:
    
    static C_PatternScanner* get()
    {
        if(!_instance)
        {
            _instance = new C_PatternScanner();
        }
        return _instance;
    }
    
    C_PatternScanner();
    
    string    base_name(string const& pathname);
    string    get_module_path(string imageName);
    
    bool      compare(const unsigned char* pData, const unsigned char* bMask, const char* szMask);
    
    uintptr_t find_pattern(uintptr_t dwAddress, off_t dwLen, unsigned char* bMask, const char* szMask, uintptr_t offset = 0x0);
    uintptr_t get_pointer(string imageName, unsigned char* bMask, const char* szMask, uint32_t start);
    uintptr_t get_procedure(string imageName, unsigned char* bMask, const char* szMask, uintptr_t offset = 0x0);
    uintptr_t get_base_address(string imageName);
    
};
