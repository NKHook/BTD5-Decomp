#pragma once

#include "Generic/Menu/PopupScreenBase.h"
#include "ScriptedScreenData.h"

class ScriptedScreen : public CPopupScreenBase {
public:
    ScriptedScreen(CGameSystemPointers* pGamePtrs) override;
    virtual ~ScriptedScreen() override;
    virtual void Init(IScreenData& screenData) override;
    virtual void Uninit() override;
    virtual void BackButtonPressed() override;
    virtual std::string ChildScreenClosed(std::string screenName, bool param_2) override;
    virtual void* Process(SGameTime* pGameTime) override;
    virtual void Input(SGameTime* pGameTime) override;
}