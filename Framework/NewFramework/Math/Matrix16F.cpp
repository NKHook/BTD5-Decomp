#include "Matrix16F.h"

Matrix16F::Matrix16F() {
    memset(this,0,0x40);
    this->p = 1.0;
    this->k = 1.0;
    this->f = 1.0;
    this->a = 1.0;
}

void Matrix16F::Reset(Vec3F& location, float angle)
{
    memset(this,0,0x40);
    this->p = 1.0;
    this->k = 1.0;
    this->f = 1.0;
    this->a = 1.0;
    this->m = location->x;
    this->n = location->y;
    if (angle != 0.0) {
        float angleRadian = (angle * 3.141593) / 180.0;
        Math::cos(angleRadian);
        Math::Sin(angleRadian);
        this->b = angleRadian;
        this->a = angleRadian;
        this->e = -angleRadian;
        this->f = angleRadian;
    }
    return;
}