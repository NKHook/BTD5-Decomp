#pragma once

#include "Vec3F.h"
#include "Vec4F.h"

class Matrix16F {
    union
    {
        struct
        {
            float a; float b; float c; float d;
            float e; float f; float g; float h;
            float i; float j; float k; float l;
            float m; float n; float o; float p;
        };
        struct
        {
            Vec4F left;
            Vec4F up;
            Vec4F forward;
            Vec4F translation;
        };
        float arr[16];
    };

public:
    Matrix16F();
    void LoadIdentity();
    void SetTranslationXY(Vec2F& location);
    void SetRot(float angle);
    void Reset(Matrix16F *this, Vec3F *location, float angle);
}