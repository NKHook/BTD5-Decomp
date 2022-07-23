#include "RenderableTextureObject.h"

CRenderableTextureObject::CRenderableTextureObject() : CBasePositionableObject() {
    this->incomplete = 0;
    this->field_0xac = 0;
    this->field_0xb0 = 0;
    this->field_0xb4 = 0;
    this->field_0xb8 = 0;
    this->field_0xbc = DAT_00e2ea4e;
    this->shaderId = g_DefaultShader;
    this->texture = (CTexture *)0x0;
    this->field23_0x88 = 0;
}
~CRenderableTextureObject::CRenderableTextureObject() {}

void CRenderableTextureObject::SetSize(Vec2F& size) {
    this->size.x = size.x;
    this->size.y = size.y;
    this->sizeHalf.x = this->size.x * 0.5;
    this->sizeHalf.y = size.y * 0.5;
    this->incomplete = true;
}
void CRenderableTextureObject::SetSizeX(float x) {
    this->size.x = x;
    this->sizeHalf.x = x * 0.5;
    this->sizeHalf.y = this->size.y * 0.5;
    this->incomplete = true;
}
void CRenderableTextureObject::SetSizeY(float y) {
    this->size.y = y;
    this->sizeHalf.x = this->size.x * 0.5;
    this->sizeHalf.y = y * 0.5;
    this->incomplete = true;
}
void CRenderableTextureObject::SetAlignX(float alignX) {
    this->alignment.x = alignX;
    this->incomplete = true;
}
void CRenderableTextureObject::SetAlignY(float alignY) {
    this->alignment.y = alignY;
    this->incomplete = true;
}
void CRenderableTextureObject::SetAlignXY(Vec2F& alignment) {
    this->alignment = alignment;
    this->incomplete = true;
}
void CRenderableTextureObject::FUN_0069f510() {}
void CRenderableTextureObject::FUN_0069f570() {}
void CRenderableTextureObject::FUN_0069f5d0() {}
void CRenderableTextureObject::FUN_0069f630() {}
void CRenderableTextureObject::FUN_0069f690() {}
void CRenderableTextureObject::FUN_0069f770() {}
void CRenderableTextureObject::SetShader(int shaderId) {
    this->shaderId = shaderId;
}
void CRenderableTextureObject::SetTexture(CTexture* pCTexture) {
    this->texture = pCTexture;
}