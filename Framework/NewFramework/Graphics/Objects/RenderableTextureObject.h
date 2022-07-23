#pragma once

#include "BasePositionableObject.h"

class CRenderableTextureObject : public CBasePositionableObject
{
    char pad_00A8[32]; //0x00A8
public:
    CRenderableTextureObject();

    virtual ~CRenderableTextureObject();
    virtual void SetSize(class Vec2F* size);
    virtual void SetSizeX(float x);
    virtual void SetSizeY(float y);
    virtual void SetAlignX(float alignX);
    virtual void SetAlignY(float alignY);
    virtual void SetAlignXY(class Vec2F* alignment);
    virtual void FUN_0069f510();
    virtual void FUN_0069f570();
    virtual void FUN_0069f5d0();
    virtual void FUN_0069f630();
    virtual void FUN_0069f690();
    virtual void FUN_0069f770();
    virtual void SetShader(int shaderId);
    virtual void SetTexture(class CTexture* pCTexture);
};