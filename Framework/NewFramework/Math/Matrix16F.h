#pragma once

#include "Vec3F.h"

class Matrix16F {
    union
    {
        struct
        {
            float a;
            float b;
            float c;
            float d;
            float e;
            float f;
            float g;
            float h;
            float i;
            float j;
            float k;
            float l;
            float m;
            float n;
            float o;
            float p;
        };
        struct
        {
            float arrX[4];
            float arrY[4];
            float arrZ[4];
            float arrW[4];
        };
        float arr[16];
    };

public:
    Matrix16F();
    void Reset(Matrix16F *this, Vec3F *location, float angle);
}