#pragma once

#include "../../../../../BlankTypes.h"

#include "../../../Utilities/Misc/AssetBag.h"
#include "../../BasePointers.h"
#include "../ScreenData.h"

#include <string>
#include <sstream>
#include <list>

enum class Device {
    PHONE = 0,
    TABLET = 1,
    UNKNOWN = 2
};

enum class eScreenState {
    UNINITIALIZED,
    INITIALIZED,
    SHOWN,
    UNKNOWN_3,
    HIDDEN,
    DESTROYING,
    DESTROYED
}

class CBaseScreen : public IBasePointers {
    std::list<CBaseScreen*> children;
    undefined4 field4_0x7c;
    undefined4 field5_0x80;
    undefined4 field6_0x84;
    undefined4 field7_0x88;
    undefined field8_0x8c;
    undefined field9_0x8d;
    undefined field10_0x8e;
    undefined field11_0x8f;
    undefined field12_0x90;
    undefined field13_0x91;
    undefined field14_0x92;
    undefined field15_0x93;
    undefined field16_0x94;
    undefined field17_0x95;
    undefined field18_0x96;
    undefined field19_0x97;
    undefined field20_0x98;
    undefined field21_0x99;
    undefined field22_0x9a;
    undefined field23_0x9b;
    undefined4 field24_0x9c;
    undefined4 field25_0xa0;
    CBaseScreen* parent;
    eScreenState screenState;
    undefined field28_0xa9;
    undefined field29_0xaa;
    undefined field30_0xab;
    undefined4 field31_0xac;
    boost::shared_ptr<CAssetBag> assetBag;
    undefined4 field37_0xb8;
public:
    CBaseScreen();
    virtual ~CBaseScreen();
    virtual void _PreloadAssets();
    virtual void Init(IScreenData& screenData);
    virtual void Uninit();
    virtual void Show();
    virtual void Hide();
    virtual void ApplicationWillResignActive();
    virtual void ApplicationWillTerminate();
    virtual void ApplicationDidBecomeActive();
    virtual void SelectButtonPressed();
    virtual void BackButtonPressed();
    virtual void ScreenResized();
    virtual std::string ChildScreenClosed(std::string screenName, bool param_2);
    virtual void BatteryLevelDidChange();
    virtual void ProcessInit();
    virtual void ProcessUninit();
    virtual void* Process(SGameTime* pGameTime);
    virtual void Input(SGameTime* pGameTime);
    virtual void Draw();
    virtual void DrawOverlay();
    virtual bool AllAssetsLoaded();
    virtual void SetupPointers(CBaseScreen* child);
    virtual void RemoveScreen(CBaseScreen* child);
    virtual void PrintTree(int param_1, std::stringstream outstream);

    void StartUsingAsset(CAssetBag::eAssetType& assetType, std::string& assetName);
};