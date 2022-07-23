#pragma once

class Vec2F
{
    union
    {
        struct
        {
            float x;
            float y;
        };
        float arr[2];
    };
public:
    Vec2F();
    Vec2F(float x, float y);
};