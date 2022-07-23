#include "Matrix16F.h"

Matrix16F::Matrix16F() {
    //Load identity matrix
    this->LoadIdentity();
}

void Matrix16F::LoadIdentity() {
    memset(this,0,0x40);
    this->p = 1.0;
    this->k = 1.0;
    this->f = 1.0;
    this->a = 1.0;
}

void Matrix16F::SetTranslationXY(Vec2F& location) {
    this->translation.x = location.x;
    this->translation.y = location.y;
}

void Matrix16F::SetRot(float angle) {
    this->a = 0.0f;
    this->b = 0.0f;
    this->e = 0.0f;
    this->f = 0.0f;

    if (angle != 0.0) {
        float angleRadian = (angle * 3.141593) / 180.0;
        float angleCos = Math::cos(angleRadian);
        float angleSin = Math::Sin(angleRadian);
        this->a = angleCos;
        this->b = angleSin;
        this->e = -angleSin;
        this->f = angleCos;
    }
}

void Matrix16F::Reset(Vec3F& location, float angle)
{
    this->LoadIdentity();
    this->SetTranslationXY(location);
    this->SetRot(angle);
    return;
}