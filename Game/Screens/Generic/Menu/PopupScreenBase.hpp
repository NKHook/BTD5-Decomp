#pragma once

#include <Graphics/Objects/BasePositionableObject.h>
#include <Graphics/Objects/BaseButton.h>
#include <BaseApplication/Screens/BloonsBaseScreen/BloonsBaseScreen.h>>

enum class eNavButtonType {
    CLOSE = 0xF,
};

struct SMainButtonStyle{};
class CPopupScreenBase : public CBloonsBaseScreen, public IButtonDelegate {
    char pad_010C[20]{}; //0x010C
    CBasePositionableObject* rootObj = nullptr; //0x0120
    CBasePositionableObject* N00000182 = nullptr; //0x0124
    CBasePositionableObject* N00000183 = nullptr; //0x0128
    CBasePositionableObject* popObj = nullptr; //0x012C
    char pad_0130[12]{}; //0x0130
    CBasePositionableObject* ui_root = nullptr; //0x013C
    char pad_0140[132]{}; //0x0140
    class CSpriteButton* closeButton = nullptr; //0x01C4
    char pad_01C8[48]{}; //0x01C8
    SMainButtonStyle buttonStyle; //0x01F8
    char pad_0250[8]{}; //0x0250
public:
    CPopupScreenBase(class CGameSystemPointers* pCGameSystemPointers, std::string screenName);

    virtual ~CPopupScreenBase();
    virtual void DrawForeground(); //Including this in NKHook5 causes the vtable to be off by 1, but I'm like certain its actually there
    virtual class CMainButton* CreateDebugButton(std::string param_1, std::string iconSprite, std::string buttonSprite, std::string param_4, CVec2& param_5) { return nullptr; }
    virtual class CMainButton* CreateButton(std::string buttonName, std::string buttonImage, std::string iconImage, std::string buttonText, CVec2 position) { return nullptr; }
    virtual class CMainButton* CreateButton(CBasePositionableObject* button, std::string buttonName, std::string buttonImage, std::string iconImage, std::string buttonText, CVec2 position) { return nullptr; }
    virtual class CMainButton* CreateButtonBasic(std::string param_1, std::string param_2, std::string param_3, std::string param_4, CVec2 position) { return nullptr; }
    virtual class CMainButton* CreateButtonBasic(CBasePositionableObject* button, std::string param_1, std::string param_2, std::string param_3, std::string param_4, CVec2 position) { return nullptr; }
    virtual class CToggleButton* CreateButtonToggle(std::string param_1, std::string param_2, std::string param_3, std::string param_4, std::string param_5, bool param_6, CVec2 param_7, CVec2 param_8) { return nullptr; }
    virtual class CToggleButton* CreateButtonToggle(CBasePositionableObject* button, std::string param_1, std::string param_2, std::string param_3, std::string param_4, std::string param_5, bool param_6, CVec2 param_7, CVec2 param_8) { return nullptr; }
    virtual void ChangeState(int eScreenSubState) {}

    void AddObject(CBasePositionableObject* object, int param_1);
    void AddNavButton(eNavButtonType type, std::string icon);
    void* AddToPoppingList(CBasePositionableObject* object, CBasePositionableObject* parent, CBasePositionableObject* object_src, bool param_4);
};