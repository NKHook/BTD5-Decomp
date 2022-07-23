#pragma once

class Vec4F
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
        float arr[4];
    };
    
public:
    Vec4F();
    Vec4F(float x, float y, float z, float w);
};