#pragma once

#include "../../../../../BlankTypes.h"

#include "../../../Utilities/Misc/AssetBag.h"
#include "../../BasePointers.h"
#include "../ScreenData.h"

#include <string>
#include <sstream>
#include <list>
#include <vector>

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
    char pad_0070[4]; //0x0070
	void* unknown_constructed = nullptr; //0x0074
	char pad_0078[4]; //0x0078
    std::vector<CBaseScreen*> children; //0x007C
    char pad_0088[4] = 0; //0x0088
    std::string screenName; //0x008C
    CBaseScreen* parentScreen = nullptr; //0x00A4
    eScreenState screenState = eScreenState::UNINITIALIZED; //0x00A8
    char pad_00AC[4] = 0; //0x00AC
    boost::shared_ptr<CAssetBag> pAssetBag = nullptr; //0x00B0
    char pad_00B8[4] = 0; //0x00B8
public:
    CBaseScreen(std::string& screenName);
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