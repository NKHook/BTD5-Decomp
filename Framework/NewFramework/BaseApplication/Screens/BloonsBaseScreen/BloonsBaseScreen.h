#pragma once

#include "CBaseScreen.h"

class CBloonsBaseScreen : public CBaseScreen
{
    CGameSystemPointers* pCGameSystemPointers; //0x00BC
    char pad_00C0[12]; //0x00C0
    boost::shared_ptr<CFont> pMenuFont; //0x00CC
public:
    virtual ~CBloonsBaseScreen() {};
};