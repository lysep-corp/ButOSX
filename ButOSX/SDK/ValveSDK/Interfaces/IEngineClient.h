class IEngineClient {
public:
    typedef struct Matrix4x4 {
        union {
            struct {
                float _11, _12, _13, _14;
                float _21, _22, _23, _24;
                float _31, _32, _33, _34;
                float _41, _42, _43, _44;

            };
            float m[4][4];
        };
    }Matrix4x4;
    typedef struct player_info_s
    {
        int64_t __pad0;
        union {
            int64_t xuid;
            struct {
                int xuidlow;
                int xuidhigh;
            };
        };
        char name[128];
        int userid;
        char guid[33];
        unsigned int friendsid;
        char friendsname[128];
        bool fakeplayer;
        bool ishltv;
        unsigned int customfiles[4];
        unsigned char filesdownloaded;
    }player_info_t;

    bool GetPlayerInfo(int iIndex, player_info_t *pInfo) {
        typedef bool (* oGetPlayerInfo)(void*, int, player_info_t*);
        return getvfunc<oGetPlayerInfo>(this, 8)(this, iIndex, pInfo);
    }

    int GetMaxClients() {
        typedef int(*oGetMaxClients)(void*);
        return getvfunc<oGetMaxClients>(this, 20)(this);
    }
    
    bool IsInGame() {
        typedef bool (* oIsInGame)(void*);
        return getvfunc<oIsInGame>(this, 26)(this);
    }
    
    bool IsConnected() {
        typedef bool (* oIsConnected)(void*);
        return getvfunc<oIsConnected>(this, 27)(this);
    }
    
    int GetLocalPlayer() {
        typedef int (* oGetLocalPlayer)(void*);
        return getvfunc<oGetLocalPlayer>(this, 12)(this);
    }
    
    void GetViewAngles(Vector& vAngle) {
        typedef void(* oGetViewAngles)(void*, Vector&);
        return getvfunc<oGetViewAngles>(this, 18)(this, vAngle);
    }

    void SetViewAngles(Vector& vAngle) {
        typedef void(* oSetViewAngles)(void*, Vector&);
        return getvfunc<oSetViewAngles>(this, 19)(this, vAngle);
    }

    bool IsHLTV() {
        typedef bool(*oIsHLTV)(void*);
        return getvfunc<oIsHLTV>(this, 93)(this);
    }

    bool IsTakingScreenShot() {
        typedef bool(*oIsTakingScreenShot)(void*);
        return getvfunc<oIsTakingScreenShot>(this, 92)(this);
    }

    void ClientCmd_Unrestricted(const char* szCommand) {
        typedef void(*oClientCmd)(void*);
        return getvfunc<oClientCmd>(this, 114)(this); //OLD WAS 7
    }
    
    void GetScreenSize(int& width, int& height){
        typedef void(*oGetScreenSize)(void*);
        return getvfunc<oGetScreenSize>(this, 5)(this);
    }
    Matrix4x4 WorldToScreenMatrix(){
        typedef Matrix4x4(*oWorldToScreenMatrix)(void*);
        return getvfunc<oWorldToScreenMatrix>(this, 37)(this);
    }

};
