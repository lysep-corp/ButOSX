struct DrawModelState_t {
    void*            m_pStudioHdr;
    void*            m_pStudioHWData;
    void*        m_pRenderable;
    const matrix3x4_t        *m_pModelToWorld;
    void*        m_decals;
    int                        m_drawFlags;
    int                        m_lod;
};

struct ModelRenderInfo_t {
    Vector origin;
    QAngle angles;
    char _padding[0x4];
    void** pRenderable;
    const model_t* pModel;
    const matrix3x4_t* pModelToWorld;
    const matrix3x4_t* pLightingOffset;
    const Vector* pLightingOrigin;
    int flags;
    int entity_index;
    int skin;
    int body;
    int hitboxset;
    void* instance;

    ModelRenderInfo_t()
    {
        pModelToWorld = NULL;
        pLightingOffset = NULL;
        pLightingOrigin = NULL;
    }
};

class IVModelRender {
public:
    void ForcedMaterialOverride(IMaterial* mat) {
        typedef void (*Fn)(void*, IMaterial*, int, int);
        return getvfunc<Fn>(this, 1)(this, mat, 0, 0);
    }
};
