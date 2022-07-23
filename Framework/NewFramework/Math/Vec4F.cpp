#include "Vec4F.h"

Vec4F::Vec4F() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
}

Vec4F::Vec4F(float x, float y, float z, float w) : Vec4F() {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}