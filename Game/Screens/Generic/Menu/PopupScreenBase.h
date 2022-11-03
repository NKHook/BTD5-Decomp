#pragma once

#include "../../../../Framework/NewFramework/BaseApplication/Screens/BloonsBaseScreen/BloonsBaseScreen.h"
#include "../../../../Framework/NewFramework/Graphics/Objects/BaseButton.h"

enum class eNavButtonType {
    CLOSE = 0xF,
};

class CPopupScreenBase : public CBloonsBaseScreen, public IButtonDelegate {
    char pad_010C[20] = 0; //0x010C
    CBasePositionableObject* rootObj = nullptr; //0x0120
    CBasePositionableObject* N00000182 = nullptr; //0x0124
    CBasePositionableObject* N00000183 = nullptr; //0x0128
    CBasePositionableObject* popObj = nullptr; //0x012C
    char pad_0130[12] = 0; //0x0130
    CBasePositionableObject* ui_root = nullptr; //0x013C
    char pad_0140[132] = 0; //0x0140
    CSpriteButton* closeButton = nullptr; //0x01C4
    char pad_01C8[48] = 0; //0x01C8
    SMainButtonStyle buttonStyle; //0x01F8
    char pad_0250[8] = 0; //0x0250
public:
    CPopupScreenBase(CGameSystemPointers* pCGameSystemPointers, std::string screenName);

    virtual ~CPopupScreenBase();
    virtual void DrawForeground(); //Including this in NKHook5 causes the vtable to be off by 1, but I'm like certain its actually there
    virtual CMainButton* CreateDebugButton(std::string param_1, std::string iconSprite, std::string buttonSprite, std::string param_4, Vec2F& param_5) { return nullptr; }
    virtual CMainButton* CreateButton(std::string buttonName, std::string buttonImage, std::string iconImage, std::string buttonText, Vec2F position) { return nullptr; }
    virtual CMainButton* CreateButton(CBasePositionableObject* button, std::string buttonName, std::string buttonImage, std::string iconImage, std::string buttonText, Vec2F position) { return nullptr; }
    virtual CMainButton* CreateButtonBasic(std::string param_1, std::string param_2, std::string param_3, std::string param_4, Vec2F position) { return nullptr; }
    virtual CMainButton* CreateButtonBasic(CBasePositionableObject* button, std::string param_1, std::string param_2, std::string param_3, std::string param_4, Vec2F position) { return nullptr; }
    virtual CToggleButton* CreateButtonToggle(std::string param_1, std::string param_2, std::string param_3, std::string param_4, std::string param_5, bool param_6, Vec2F param_7, Vec2F param_8) { return nullptr; }
    virtual CToggleButton* CreateButtonToggle(CBasePositionableObject* button, std::string param_1, std::string param_2, std::string param_3, std::string param_4, std::string param_5, bool param_6, Vec2F param_7, Vec2F param_8) { return nullptr; }
    virtual void ChangeState(int eScreenSubState) {}

    void AddObject(CBasePositionableObject* object, int param_1);
    void AddNavButton(eNavButtonType type, std::string icon);
    void* AddToPoppingList(CBasePositionableObject* object, CBasePositionableObject* parent, CBasePositionableObject* object_src, bool param_4);
};