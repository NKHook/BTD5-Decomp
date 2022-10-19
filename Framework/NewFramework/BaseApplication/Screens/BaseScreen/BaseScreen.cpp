#include "BaseScreen.h"

CBaseScreen::CBaseScreen() {}
CBaseScreen::~CBaseScreen() {}

void CBaseScreen::StartUsingAsset(CAssetBag::eAssetType& assetType, std::string& assetName)
{
    if(this->assetBag == nullptr) {
        NKAssert();
    }
    this->assetBag->StartUsing(assetType, assetName);
}