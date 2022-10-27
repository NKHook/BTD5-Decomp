#pragma once

#include "../../../../Framework/NewFramework/BaseApplication/Screens/BloonsBaseScreen/BloonsBaseScreen.h"
#include "../../../../Framework/NewFramework/Graphics/Objects/BaseButton.h"

class CPopupScreenBase : public CBloonsBaseScreen, public IButtonDelegate {
    char pad_010C[48]; //0x010C
    CBasePositionableObject* pRootObj; //0x013C
    char pad_0140[184]; //0x0140
    SMainButtonStyle buttonStyle; //0x01F8
    char pad_0254[4]; //0x0254
public:
    CPopupScreenBase(CGameSystemPointers* pCGameSystemPointers, std::string screenName);

    virtual ~CPopupScreenBase();
    virtual void DrawForeground();
    virtual CMainButton* CreateDebugButton(std::string param_1, std::string iconSprite, std::string buttonSprite, std::string param_4, Vec2F& param_5);
    virtual CMainButton* CreateButton(std::string param_1, std::string param_2, std::string param_3, std::string param_4, Vec2F& position);
    virtual CMainButton* CreateButton_1(std::string param_1, std::string param_2, std::string param_3, std::string param_4, Vec2F& position);
    virtual CMainButton* CreateButtonBasic(std::string param_1, std::string param_2, std::string param_3, std::string param_4, Vec2F& position);
    virtual CMainButton* CreateButtonBasic_1(std::string param_1, std::string param_2, std::string param_3, std::string param_4, Vec2F& position);
    virtual CToggleButton* CreateButtonToggle(std::string param_1, std::string param_2, std::string param_3, std::string param_4, std::string param_5, bool param_6, Vec2F& param_7, Vec2F& param_8);
    virtual CToggleButton* CreateButtonToggle(std::string param_1, std::string param_2, std::string param_3, std::string param_4, std::string param_5, bool param_6, Vec2F& param_7, Vec2F& param_8);
    virtual void ChangeState(int eScreenSubState);

    void AddObject(CBasePositionableObject* object, int param_1);
};