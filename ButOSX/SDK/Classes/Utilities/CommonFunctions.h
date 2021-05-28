#pragma once
#include <cstring>

inline void**& getvtable(void* inst, size_t offset = 0)
{
    return *reinterpret_cast<void***>((size_t)inst + offset);
}

inline const void** getvtable(const void* inst, size_t offset = 0)
{
    return *reinterpret_cast<const void***>((size_t)inst + offset);
}

template<typename Fn>
inline Fn getvfunc(void* inst, size_t index, size_t offset = 0)
{
    return reinterpret_cast<Fn>(getvtable(inst, offset)[index]);
}

template <typename T>
T GetSymbolAddress(const char* filename, const char* symbol)
{
    void* handle = dlopen(filename, RTLD_NOW);
    T result = reinterpret_cast<T>(dlsym(handle, symbol));
    dlclose(handle);
    
    return result;
};
