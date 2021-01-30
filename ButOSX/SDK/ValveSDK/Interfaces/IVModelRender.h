typedef unsigned short ModelInstanceHandle_t;


struct ModelRenderInfo_t
{
    Vector              origin;
    QAngle              angles;
    char                pad[0x4];
    void*               pRenderable;
    const model_t*      pModel;
    const matrix3x4_t*  pModelToWorld;
    const matrix3x4_t*  pLightingOffset;
    const Vector*       pLightingOrigin;
    int                 flags;
    int                 entity_index;
    int                 skin;
    int                 body;
    int                 hitboxset;
    ModelInstanceHandle_t instance;
    
    ModelRenderInfo_t()
    {
        pModelToWorld = NULL;
        pLightingOffset = NULL;
        pLightingOrigin = NULL;
    }
};
class IVModelRender
{
public:
    
    virtual void ForcedMaterialOverride(IMaterial* material){
        typedef void (* oForcedMaterialOverride)(void*, IMaterial*, int, int);
        return getvfunc<oForcedMaterialOverride>(this, 1)(this, material, 0, 0);
    }
    virtual void DrawModelExecute(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld = NULL) {
        typedef void (*oDrawModelExecute)(void* thisptr, void* context, void* state, ModelRenderInfo_t& model_info, matrix3x4_t* pCustomBoneToWorld);
        return getvfunc<oDrawModelExecute>(this, 21)(thisptr, context, state, model_info, pCustomBoneToWorld);
    }
};
