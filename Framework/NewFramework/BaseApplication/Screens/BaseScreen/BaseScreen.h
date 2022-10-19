#pragma once

#include "../../IBasePointers.h"
#include "../../../Utilities/Misc/AssetBag.h"

#include <string>

enum class Device {
    PHONE = 0,
    TABLET = 1,
    UNKNOWN = 2
};

class CBaseScreen : public IBasePointers {
public:
    CBaseScreen();
    virtual ~CBaseScreen() {};

    void StartUsingAsset(CAssetBag::eAssetType& assetType, std::string& assetName);
};