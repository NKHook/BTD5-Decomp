#include "Vec3F.h"

Vec3F::Vec3F() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vec3F::Vec3F(float x, float y, float z) : Vec3F() {
    this->x = x;
    this->y = y;
    this->z = z;
}