//
//  Vector3D.h
//  ButOSX
//
//  Created by Can on 1.11.2020.
//  Copyright © 2020 Lyceion. All rights reserved.
//

#ifndef Vector3D_h
#define Vector3D_h
#pragma once
#pragma GCC diagnostic ignored "-Wunused-value"
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <math.h>
#include <stdlib.h>

typedef float vec_t;

#define CHECK_VALID( _v ) 0
#define Assert( _exp ) ((void)0)

#define FastSqrt(x)            (sqrt)(x)

#define M_RADPI     57.295779513082
#define M_PI_F        ((float)(M_PI))         // Shouldn't collide with anything.
#define M_PHI        1.61803398874989484820  // golden ratio

// NJS: Inlined to prevent floats from being autopromoted to doubles, as with the old system.
#ifndef RAD2DEG
#define RAD2DEG( x  )  ( (float)(x) * (float)(180.f / M_PI_F) )
#endif

#ifndef DEG2RAD
#define DEG2RAD( x  )  ( (float)(x) * (float)(M_PI_F / 180.f) )
#endif

#ifndef rad
#define rad(a) a * 0.01745329251
#endif

// MOVEMENT INFO
enum
{
    PITCH = 0,  // up / down
    YAW,        // left / right
    ROLL        // fall over
};

// decls for aligning data

#define DECL_ALIGN(x) __attribute__((aligned(x)))

#define ALIGN16 DECL_ALIGN(16)
#define VALVE_RAND_MAX 0x7fff

inline float isqrt(float _Xx)
{
    return (sqrtf(_Xx));
}

struct matrix3x4_t
{
    matrix3x4_t() {}
    matrix3x4_t(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23)
    {
        m_flMatVal[0][0] = m00;    m_flMatVal[0][1] = m01; m_flMatVal[0][2] = m02; m_flMatVal[0][3] = m03;
        m_flMatVal[1][0] = m10;    m_flMatVal[1][1] = m11; m_flMatVal[1][2] = m12; m_flMatVal[1][3] = m13;
        m_flMatVal[2][0] = m20;    m_flMatVal[2][1] = m21; m_flMatVal[2][2] = m22; m_flMatVal[2][3] = m23;
    }
    
    float *operator[](int i)                { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
    const float *operator[](int i) const    { Assert((i >= 0) && (i < 3)); return m_flMatVal[i]; }
    float *Base()                            { return &m_flMatVal[0][0]; }
    const float *Base() const                { return &m_flMatVal[0][0]; }
    
    float m_flMatVal[3][4];
};


class Vector
{
public:
    // Members
    vec_t x, y, z;  // Pitch, Yaw, Roll
    
    // Construction/destruction:
    Vector(void);
    Vector(vec_t X, vec_t Y, vec_t Z);
    explicit Vector(vec_t XYZ); ///< broadcast initialize
    
    // Initialization
    void Init(vec_t ix = 0.0f, vec_t iy = 0.0f, vec_t iz = 0.0f);
    // TODO (Ilya): Should there be an init that takes a single float for consistency?
    
    // Got any nasty NAN's?
    bool IsValid() const;
    void Invalidate();
    
    // array access...
    vec_t operator[](int i) const;
    vec_t& operator[](int i);
    
    // Base address...
    vec_t* Base();
    vec_t const* Base() const;
    
    // Cast to Vector2D...
    void Random(vec_t minVal, vec_t maxVal);
    inline void Zero(); ///< zero out a vector
    
    // equality
    bool operator==(const Vector& v) const;
    bool operator!=(const Vector& v) const;
    
    // arithmetic operations
    inline Vector&    operator+=(const Vector &v);
    inline Vector&    operator-=(const Vector &v);
    inline Vector&    operator*=(const Vector &v);
    inline Vector&    operator*=(float s);
    inline Vector&    operator/=(const Vector &v);
    inline Vector&    operator/=(float s);
    inline Vector&    operator+=(float fl); ///< broadcast add
    inline Vector&    operator-=(float fl); ///< broadcast sub
    
    // negate the vector components
    void    Negate();
    
    // Normalise
    inline Vector GetNormalized(void);
    inline Vector Normalize(void);
    
    // Get the vector's magnitude.
    
    // return true if this vector is (0,0,0) within tolerance
    bool IsZero(float tolerance = 0.01f) const
    {
        return (x > -tolerance && x < tolerance &&
                y > -tolerance && y < tolerance &&
                z > -tolerance && z < tolerance);
    }
    
    inline vec_t LengthSqr(void) const
    {
        CHECK_VALID(*this);
        return (x*x + y*y + z*z);
    }
    
    vec_t    NormalizeInPlace();
    Vector    Normalized();
    bool    IsLengthGreaterThan(float val) const;
    bool    IsLengthLessThan(float val) const;
    
    // check if a vector is within the box defined by two other vectors
    inline bool WithinAABox(Vector const &boxmin, Vector const &boxmax);
    
    // Get the distance from this vector to the other one.
    vec_t    DistTo(const Vector &vOther) const
    {
        Vector delta;
        
        delta.x = x - vOther.x;
        delta.y = y - vOther.y;
        delta.z = z - vOther.z;
        
        return delta.Length();
    }
    
    
    // Get the distance from this vector to the other one squared.
    // NJS: note, VC wasn't inlining it correctly in several deeply nested inlines due to being an 'out of line' inline.
    // may be able to tidy this up after switching to VC7
    
    // Copy
    void    CopyToArray(float* rgfl) const;
    
    // Multiply, add, and assign to this (ie: *this = a + b * scalar). This
    // is about 12% faster than the actual vector equation (because it's done per-component
    // rather than per-vector).
    void    MulAdd(const Vector& a, const Vector& b, float scalar);
    
    // Dot product.
    vec_t    Dot(const Vector& vOther) const;
    vec_t   Dots(const float* fOther) const;
    
    auto dot(float* other) const -> float
    {
        return x * other[0] + y * other[1] + z * other[2];
    }
    
    // assignment
    Vector& operator=(const Vector &vOther);
    
    // 2d
    vec_t    Length2D(void) const;
    vec_t    Length(void) const;
    vec_t    Length2DSqr(void) const;
    
    
#ifndef VECTOR_NO_SLOW_OPERATIONS
    // copy constructors
    //    Vector(const Vector &vOther);
    
    // arithmetic operations
    Vector    operator-(void) const;
    
    Vector    operator+(const Vector& v) const;
    Vector    operator-(const Vector& v) const;
    Vector    operator*(const Vector& v) const;
    Vector    operator/(const Vector& v) const;
    Vector    operator*(float fl) const;
    Vector    operator/(float fl) const;
    
    // Cross product between two vectors.
    Vector    Cross(const Vector &vOther) const;
    
    // Returns a vector with the min or max in X, Y, and Z.
    Vector    Min(const Vector &vOther) const;
    Vector    Max(const Vector &vOther) const;
    
    void ClampAngles();
    
#else
    
private:
    // No copy constructors allowed if we're in optimal mode
    Vector(const Vector& vOther);
#endif
};

inline Vector::Vector(void)
{
#ifdef _DEBUG
#ifdef VECTOR_PARANOIA
    // Initialize to NAN to catch errors
    x = y = z = VEC_T_NAN;
#endif
#endif
}

inline float VectorLength(const Vector& v)
{
    return (float)isqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector::Vector(vec_t X, vec_t Y, vec_t Z)
{
    x = X; y = Y; z = Z;
    CHECK_VALID(*this);
}

inline Vector::Vector(vec_t XYZ)
{
    x = y = z = XYZ;
    CHECK_VALID(*this);
}

inline Vector Vector::GetNormalized(void)
{
    float length = this->Length();
    
    if (length != 0)
        return Vector(*this / this->Length());
    
    return Vector(0, 0, 1);
}

inline Vector Vector::Normalize(void)
{
    *this = GetNormalized();
    return *this;
}


//inline Vector::Vector(const float *pFloat)
//{
//    Assert( pFloat );
//    x = pFloat[0]; y = pFloat[1]; z = pFloat[2];
//    CHECK_VALID(*this);
//}

#if 0
//-----------------------------------------------------------------------------
// copy constructor
//-----------------------------------------------------------------------------
inline Vector::Vector(const Vector &vOther)
{
    CHECK_VALID(vOther);
    x = vOther.x; y = vOther.y; z = vOther.z;
}
#endif

//-----------------------------------------------------------------------------
// initialization
//-----------------------------------------------------------------------------

inline void Vector::Init(vec_t ix, vec_t iy, vec_t iz)
{
    x = ix; y = iy; z = iz;
    CHECK_VALID(*this);
}


// This should really be a single opcode on the PowerPC (move r0 onto the vec reg)
inline void Vector::Zero()
{
    x = y = z = 0.0f;
}

inline void VectorClear(Vector& a)
{
    a.x = a.y = a.z = 0.0f;
}

//-----------------------------------------------------------------------------
// assignment
//-----------------------------------------------------------------------------

inline Vector& Vector::operator=(const Vector &vOther)
{
    CHECK_VALID(vOther);
    x = vOther.x; y = vOther.y; z = vOther.z;
    return *this;
}


//-----------------------------------------------------------------------------
// Array access
//-----------------------------------------------------------------------------
inline vec_t& Vector::operator[](int i)
{
    Assert((i >= 0) && (i < 3));
    return ((vec_t*)this)[i];
}

inline vec_t Vector::operator[](int i) const
{
    Assert((i >= 0) && (i < 3));
    return ((vec_t*)this)[i];
}


//-----------------------------------------------------------------------------
// Base address...
//-----------------------------------------------------------------------------
inline vec_t* Vector::Base()
{
    return (vec_t*)this;
}

inline vec_t const* Vector::Base() const
{
    return (vec_t const*)this;
}

//-----------------------------------------------------------------------------
// Cast to Vector2D...
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// IsValid?
//-----------------------------------------------------------------------------

inline bool Vector::IsValid() const
{
    return finite(x) && finite(y) && finite(z);
}

//-----------------------------------------------------------------------------
// Invalidate
//-----------------------------------------------------------------------------

void inline Vector::Invalidate()
{
    x = y = z = std::numeric_limits<float>::infinity();
}

//-----------------------------------------------------------------------------
// comparison
//-----------------------------------------------------------------------------

inline bool Vector::operator==(const Vector& src) const
{
    CHECK_VALID(src);
    CHECK_VALID(*this);
    return (src.x == x) && (src.y == y) && (src.z == z);
}

inline bool Vector::operator!=(const Vector& src) const
{
    CHECK_VALID(src);
    CHECK_VALID(*this);
    return (src.x != x) || (src.y != y) || (src.z != z);
}


//-----------------------------------------------------------------------------
// Copy
//-----------------------------------------------------------------------------

inline void VectorCopy(const Vector& src, Vector& dst)
{
    CHECK_VALID(src);
    dst.x = src.x;
    dst.y = src.y;
    dst.z = src.z;
}

inline void    Vector::CopyToArray(float* rgfl) const
{
    Assert(rgfl);
    CHECK_VALID(*this);
    rgfl[0] = x;
    rgfl[1] = y;
    rgfl[2] = z;
}

//-----------------------------------------------------------------------------
// standard math operations
//-----------------------------------------------------------------------------
// #pragma message("TODO: these should be SSE")

inline void Vector::Negate()
{
    CHECK_VALID(*this);
    x = -x; y = -y; z = -z;
}

inline  Vector& Vector::operator+=(const Vector& v)
{
    CHECK_VALID(*this);
    CHECK_VALID(v);
    x += v.x; y += v.y; z += v.z;
    return *this;
}

inline  Vector& Vector::operator-=(const Vector& v)
{
    CHECK_VALID(*this);
    CHECK_VALID(v);
    x -= v.x; y -= v.y; z -= v.z;
    return *this;
}

inline  Vector& Vector::operator*=(float fl)
{
    x *= fl;
    y *= fl;
    z *= fl;
    CHECK_VALID(*this);
    return *this;
}

inline  Vector& Vector::operator*=(const Vector& v)
{
    CHECK_VALID(v);
    x *= v.x;
    y *= v.y;
    z *= v.z;
    CHECK_VALID(*this);
    return *this;
}

// this ought to be an opcode.
inline Vector&    Vector::operator+=(float fl)
{
    x += fl;
    y += fl;
    z += fl;
    CHECK_VALID(*this);
    return *this;
}

inline Vector&    Vector::operator-=(float fl)
{
    x -= fl;
    y -= fl;
    z -= fl;
    CHECK_VALID(*this);
    return *this;
}

inline void Vector::ClampAngles() {
    if(this->x > 89) {
        this->x = 89;
    }
    if(this->x < -89)
        this->x = -89;
    
    while(this->y > 180) {
        this->y -= 360;
    }
    while(this->y < -180) {
        this->y += 360;
    }
    
    this->z = 0;
}

inline  Vector& Vector::operator/=(float fl)
{
    Assert(fl != 0.0f);
    float oofl = 1.0f / fl;
    x *= oofl;
    y *= oofl;
    z *= oofl;
    CHECK_VALID(*this);
    return *this;
}

inline  Vector& Vector::operator/=(const Vector& v)
{
    CHECK_VALID(v);
    Assert(v.x != 0.0f && v.y != 0.0f && v.z != 0.0f);
    x /= v.x;
    y /= v.y;
    z /= v.z;
    CHECK_VALID(*this);
    return *this;
}

inline void VectorSubtract(const Vector& a, const Vector& b, Vector& c)
{
    CHECK_VALID(a);
    CHECK_VALID(b);
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
}

inline void VectorAdd(const Vector& a, const Vector& b, Vector& result)
{
    CHECK_VALID(a);
    CHECK_VALID(b);
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
}

inline void VectorMultiply(const Vector& a, vec_t b, Vector& c)
{
    CHECK_VALID(a);
    Assert(IsFinite(b));
    c.x = a.x * b;
    c.y = a.y * b;
    c.z = a.z * b;
}

inline void VectorMultiply(const Vector& a, const Vector& b, Vector& c)
{
    CHECK_VALID(a);
    CHECK_VALID(b);
    c.x = a.x * b.x;
    c.y = a.y * b.y;
    c.z = a.z * b.z;
}


inline Vector Vector::operator-(void) const
{
    return Vector(-x, -y, -z);
}

inline Vector Vector::operator+(const Vector& v) const
{
    Vector res;
    VectorAdd(*this, v, res);
    return res;
}

inline Vector Vector::operator-(const Vector& v) const
{
    Vector res;
    VectorSubtract(*this, v, res);
    return res;
}

inline Vector Vector::operator*(float fl) const
{
    Vector res;
    VectorMultiply(*this, fl, res);
    return res;
}

inline Vector Vector::operator*(const Vector& v) const
{
    Vector res;
    VectorMultiply(*this, v, res);
    return res;
}

inline void VectorDivide(const Vector& a, vec_t b, Vector& c)
{
    CHECK_VALID(a);
    Assert(b != 0.0f);
    vec_t oob = 1.0f / b;
    c.x = a.x * oob;
    c.y = a.y * oob;
    c.z = a.z * oob;
}

inline void VectorDivide(const Vector& a, const Vector& b, Vector& c)
{
    CHECK_VALID(a);
    CHECK_VALID(b);
    Assert((b.x != 0.0f) && (b.y != 0.0f) && (b.z != 0.0f));
    c.x = a.x / b.x;
    c.y = a.y / b.y;
    c.z = a.z / b.z;
}

inline Vector Vector::operator/(float fl) const
{
    Vector res;
    VectorDivide(*this, fl, res);
    return res;
}

inline Vector Vector::operator/(const Vector& v) const
{
    Vector res;
    VectorDivide(*this, v, res);
    return res;
}

inline Vector operator*(float fl, const Vector& v)
{
    return v * fl;
}

inline vec_t Vector::Length2D(void) const {
    CHECK_VALID(*this);
    
    float root = 0.0f;
    
    float sqst = x * x + y * y;
    
    __asm
    {
        sqrtss xmm0, sqst
        movss root, xmm0
    }
    
    return root;
}

inline vec_t Vector::Length(void) const {
    CHECK_VALID(*this);
    
    float root = 0.0f;
    
    float sqsr = x*x + y*y + z*z;
    
    __asm {
        sqrtss xmm0, sqsr
        movss root, xmm0
    }
    
    return root;
}

inline vec_t DotProduct(const Vector& a, const Vector& b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline vec_t Vector::Dot(const Vector& vOther) const
{
    return DotProduct(*this, vOther);
}
// Edit
inline vec_t Vector::Dots(const float* fOther) const
{
    const Vector& a = *this;
    
    return(a.x * fOther[0] + a.y * fOther[1] + a.z * fOther[2]);
}

inline void CrossProduct(const Vector& a, const Vector& b, Vector& result)
{
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
}

inline Vector Vector::Normalized() {
    if (this->x != this->x)
        this->x = 0;
    if (this->y != this->y)
        this->y = 0;
    if (this->z != this->z)
        this->z = 0;
    
    if (this->x > 89.f)
        this->x = 89.f;
    if (this->x < -89.f)
        this->x = -89.f;
    
    while (this->y > 180)
        this->y -= 360;
    while (this->y <= -180)
        this->y += 360;
    
    if (this->y > 180.f)
        this->y = 180.f;
    if (this->y < -180.f)
        this->y = -180.f;
    
    this->z = 0;
    
    return *this;
}

inline vec_t Vector::NormalizeInPlace()
{
    Vector& v = *this;
    
    float iradius = 1.f / (this->Length() + 1.192092896e-07F); //FLT_EPSILON
    
    v.x *= iradius;
    v.y *= iradius;
    v.z *= iradius;
}

inline vec_t VectorNormalize(Vector& v) {
    vec_t l = v.Length();
    
    if (l != 0.0f) {
        v /= l;
    }
    else
    {
        v.x = v.y = 0.0f; v.z = 1.0f;
    }
    
    return l;
}

inline float BitsToFloat(unsigned int i)
{
    union Convertor_t
    {
        float f;
        unsigned long ul;
    }tmp;
    tmp.ul = i;
    return tmp.f;
}

inline unsigned long& FloatBits(float& f)
{
    return *reinterpret_cast<unsigned long*>(&f);
}

inline unsigned long const& FloatBits(float const& f)
{
    return *reinterpret_cast<unsigned long const*>(&f);
}

inline float BitsToFloat(unsigned long i)
{
    return *reinterpret_cast<float*>(&i);
}
inline float FloatNegate(float f)
{
    return BitsToFloat(FloatBits(f) ^ 0x80000000);
}

class ALIGN16 VectorAligned : public Vector
{
public:
    inline VectorAligned(void) {};
    inline VectorAligned(float X, float Y, float Z)
    {
        Init(X, Y, Z);
    }
    
#ifdef VECTOR_NO_SLOW_OPERATIONS
    
private:
    // No copy constructors allowed if we're in optimal mode
    VectorAligned(const VectorAligned& vOther);
    VectorAligned(const Vector &vOther);
    
#else
public:
    explicit VectorAligned(const Vector &vOther)
    {
        Init(vOther.x, vOther.y, vOther.z);
    }
    
    VectorAligned& operator=(const Vector &vOther)
    {
        Init(vOther.x, vOther.y, vOther.z);
        return *this;
    }
    
#endif
    float w;    // this space is used anyway
};

inline bool IsFinite(float f)
{
    return ((FloatBits(f) & 0x7F800000) != 0x7F800000);
}



#endif /* Vector3D_h */
