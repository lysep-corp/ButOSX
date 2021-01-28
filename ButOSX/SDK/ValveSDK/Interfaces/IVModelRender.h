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
    
    virtual void ForcedMaterialOverride(IMaterial* mat);
    
    virtual void DrawModelExecute(void* ctx, void *state, const ModelRenderInfo_t &pInfo, matrix3x4_t* pCustomBoneToWorld = NULL);
    
};
