class IPanel {
public:
    const char* GetName(VPANEL vguiPanel) {
        typedef const char*(*oGetName)(void*, VPANEL);
        return getvfunc<oGetName>(this, 37)(this, vguiPanel);
    }
    void SetMouseInputEnabled(VPANEL vguiPanel, bool state) {
        typedef void(* oSetMouseInputEnabled)(void*, VPANEL, bool);
        return getvfunc<oSetMouseInputEnabled>(this, 32)(this, vguiPanel, state);
    }
};
