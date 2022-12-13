#pragma once

#include "??/CBloon.h"

class CStatusEffect
{
    CBloon* bloon; //0x0004
    char pad_0008[16]; //0x0008
    CBaseTower* tower; //0x0018
    char pad_001C[12]; //0x001C

public:
    CStatusEffect();

    virtual ~CStatusEffect();
    virtual CStatusEffect* Clone() = 0;
    virtual int TypeID() = 0;
    virtual void Apply() = 0;
    virtual void Reset() = 0;
    virtual void Update(SGameTime& time) = 0;
    virtual void Render() = 0;
    virtual float GetBloonSpeed(float base);
    virtual void IncreasePops(int amount);
}