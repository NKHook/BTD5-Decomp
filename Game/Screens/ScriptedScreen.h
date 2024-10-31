#pragma once

#include "Generic/Menu/PopupScreenBase.hpp"
#include "ScriptedScreenData.h"

class ScriptedScreen : public CPopupScreenBase {
public:
    ScriptedScreen(CGameSystemPointers* pGamePtrs) override;
    virtual ~ScriptedScreen() override;
    virtual void Init(IScreenData& screenData) override;
    virtual void Uninit() override;
    virtual void BackButtonPressed() override;
    virtual std::string ChildScreenClosed(std::string screenName, bool param_2) override;
    virtual void* Process(struct SGameTime* pGameTime) override;
    virtual void Input(struct SGameTime* pGameTime) override;
}