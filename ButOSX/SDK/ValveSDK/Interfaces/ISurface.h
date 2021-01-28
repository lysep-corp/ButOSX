class ISurface {
public:
    
    void DrawSetColor(int r, int g, int b) {
        typedef void (* oDrawSetColor)(void*, int, int, int, int);
        return getvfunc<oDrawSetColor>(this, 14)(this, r, g, b, 255); 
    }
    
    void DrawSetColor(int r, int g, int b, int a) {
        typedef void (* oDrawSetColor)(void*, int, int, int, int);
        return getvfunc<oDrawSetColor>(this, 14)(this, r, g, b, a);
    }
    
    void DrawSetColor(Color color) {
        typedef void(* oDrawSetColor)(void*, int, int, int, int);
        return getvfunc<oDrawSetColor>(this, 14)(this, color.r(), color.g(), color.b(), color.a());
    }
    
    void DrawFilledRect(int x0, int y0, int x1, int y1) {
        typedef void (* oDrawFilledRect)(void*, int, int, int, int);
        return getvfunc<oDrawFilledRect>(this, 16)(this, x0, y0, x1, y1);
    }
    
    void DrawOutlinedRect(int x0, int y0, int x1, int y1) {
        typedef void (* oDrawOutlinedRect)(void*, int, int, int, int);
        return getvfunc<oDrawOutlinedRect>(this, 18)(this, x0, y0, x1, y1);
    }
    
    void DrawLine(int x0, int y0, int x1, int y1) {
        typedef void (* oDrawLine)(void*, int, int, int, int);
        return getvfunc<oDrawLine>(this, 19)(this, x0, y0, x1, y1);
    }
    
    void DrawSetTextFont(HFONT font) {
        typedef void (* oDrawSetTextFont)(void*, HFONT);
        return getvfunc<oDrawSetTextFont>(this, 23)(this, font);
    }
    
    void DrawSetTextColor(int r, int g, int b, int a) {
        typedef void (* oDrawSetTextColor)(void*, int, int, int, int);
        return getvfunc<oDrawSetTextColor>(this, 24)(this, r, g, b, a);
    }
    
    void DrawSetTextColor(Color color) {
        typedef void (* oDrawSetTextColor)(void*, int, int, int, int);
        return getvfunc<oDrawSetTextColor>(this, 24)(this, color.r(), color.g(), color.b(), color.a());
    }
    
    void DrawSetTextPos(int x, int y) {
        typedef void (* oDrawSetTextPos)(void*, int, int);
        return getvfunc<oDrawSetTextPos>(this, 26)(this, x, y);
    }
    
    void DrawPrintText(const wchar_t *text, int textLen) {
        typedef void (* oDrawPrintText)(void*, const wchar_t *, int, int);
        return getvfunc<oDrawPrintText>(this, 28)(this, text, textLen, 0);
    }
    
    void UnlockCursor() {
        typedef void(* oUnlockCursor)(void*);
        return getvfunc<oUnlockCursor>(this, 66)(this);
    }
    
    //KEEP TRYING...
//    void LockCursor(ISurface* thisptr, void* edx) {
//        typedef void(* oLockCursor)(void*, ISurface*, void*);
//        return getvfunc<oLockCursor>(this, 67)(this, thisptr, edx);
//    }
    void LockCursor() {
        typedef void(* oLockCursor)(void*);
        return getvfunc<oLockCursor>(this, 67)(this);
    }
    
    HFONT CreateFont() {
        typedef HFONT (* oCreateFont)(void*);
        return getvfunc<oCreateFont>(this, 71)(this);
    }
    
    void SetFontGlyphSet(HFONT &font, const char *FontName, int tall, int weight, int blur, int scanlines, int flags) {
        typedef void (* oSetFontGlyphSet)(void*, HFONT, const char*, int, int, int, int, int, int, int);
        return getvfunc<oSetFontGlyphSet>(this, 72)(this, font, FontName, tall, weight, blur, scanlines, flags, 0, 0);
    }
    
    void GetTextSize(HFONT font, const wchar_t *text, int &wide, int &tall) {
        typedef void (* oGetTextSize)(void*, HFONT font, const wchar_t *text, int &wide, int &tall);
        return getvfunc<oGetTextSize>(this, 79)(this, font, text, wide, tall);
    }
};
