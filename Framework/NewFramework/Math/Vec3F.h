#pragma once

class Vec3F
{
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        float arr[3];
    };
    
public:
    Vec3F();
    Vec3F(float x, float y, float z);
};