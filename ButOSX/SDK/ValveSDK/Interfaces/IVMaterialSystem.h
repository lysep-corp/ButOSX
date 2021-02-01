class IVMaterialSystem;
class KeyValues;
class RenderContext;

class IVMaterialSystem {
public:
    IMaterial* createMaterial(const char* materialName, KeyValues* keyValues){
        typedef IMaterial* (*Fn)(void*, const char*, KeyValues*);
        return getvfunc<Fn>(this, 83)(this, materialName, keyValues);
    }
    IMaterial* findMaterial(const char* materialName, const char* textureGroupName = nullptr, bool complain = true, const char* complainPrefix = nullptr){
        typedef IMaterial* (*Fn)(void*, const char*, const char*, bool, const char*);
        return getvfunc<Fn>(this, 84)(this, materialName, textureGroupName, complain, complainPrefix);
    }
    short firstMaterial(){
        typedef short (*Fn)(void*);
        return getvfunc<Fn>(this, 86)(this);
    }
    short nextMaterial(short handle){
        typedef short (*Fn)(void*, short);
        return getvfunc<Fn>(this, 87)(this, handle);
    }
    short invalidMaterial(){
        typedef short (*Fn)(void*);
        return getvfunc<Fn>(this, 88)(this);
    }
    IMaterial* getMaterial(short handle){
        typedef IMaterial* (*Fn)(void*, short);
        return getvfunc<Fn>(this, 89)(this, handle);
    }
    RenderContext* getRenderContext(){
        typedef RenderContext* (*Fn)(void*);
        return getvfunc<Fn>(this, 115)(this);
    }
};
