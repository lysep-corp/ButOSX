#pragma once

class IVDebugOverlay {
public:
     bool ScreenPosition(const Vector& vIn, Vector& vOut) {
        typedef bool (* oScreenPosition)(void*, const Vector&, Vector&);
        return getvfunc<oScreenPosition>(this, 11)(this, vIn, vOut);
    }
    
    void AddLineOverlay( const Vector& origin, const Vector& dest, int r, int g, int b, bool noDepthTest, float duration ) {
        typedef void(*oAddLineOverlay)(void*, const Vector&, const Vector&, int, int, int, bool, float);
        return getvfunc<oAddLineOverlay>(this, 4)(this, origin, dest, r, g, b, noDepthTest, duration);
    }
};
