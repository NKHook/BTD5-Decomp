#include "BaseScreen.h"

CBaseScreen::CBaseScreen(std::string& screenName) : IBasePointers()
{
    this->unknown_constructed = KONG_FUN_005c4cc0(0,0); //3.37
    this->screenName = screenName;
    this->parent = nullptr;
    this->assetBag = nullptr;
}
CBaseScreen::~CBaseScreen()
{

}
void CBaseScreen::_PreloadAssets() 
{
    return;
}
void CBaseScreen::Init(class IScreenData* screenData) 
{
    if(this->assetBag == nullptr) {
        this->assetBag = boost::make_shared<CAssetBag>(this);
    }
    this->_PreloadAssets();
    this->screenState = eScreenState::INITIALIZED;
}
void CBaseScreen::Uninit() 
{
    if(this->assetBag != nullptr) {
        this->assetBag->Reset();
    }
    this->screenState = eScreenState::DESTROYED;
}
void CBaseScreen::Show() 
{
    this->screenState = eScreenState::SHOWN;
}
void CBaseScreen::Hide() 
{
    this->screenState = eScreenState::HIDDEN;
}
void CBaseScreen::ApplicationWillResignActive() 
{
    for(CBaseScreen* pChild : this->children) {
        //TODO: Figure out what happens here
    }
}
void CBaseScreen::ApplicationWillTerminate() 
{
    for(CBaseScreen* pChild : this->children) {
        //TODO: Figure out what happens here
    }
}
void CBaseScreen::ApplicationDidBecomeActive() 
{
    for(CBaseScreen* pChild : this->children) {
        //TODO: Figure out what happens here
    }
}
void CBaseScreen::SelectButtonPressed() 
{
    for(CBaseScreen* pChild : this->children) {
        //TODO: Figure out what happens here
    }
}
void CBaseScreen::BackButtonPressed() 
{
    for(CBaseScreen* pChild : this->children) {
        //TODO: Figure out what happens here
    }
}
void CBaseScreen::ScreenResized() 
{
    //Weird stack stuff here, might just be big params?
}
std::string CBaseScreen::ChildScreenClosed(std::string screenName, bool param_2) 
{
    return screenName;
}
void CBaseScreen::BatteryLevelDidChange() 
{

}
void CBaseScreen::ProcessInit() 
{
    bool loaded = this->AllAssetsLoaded();
    if(loaded != false) {
        //TODO: Figure out the rest of this
    }
}
void CBaseScreen::ProcessUninit() 
{
    bool loaded = this->AllAssetsLoaded();
    if(loaded == false) {
        this->screenState = eScreenState::DESTROYING;
    }
}
void* CBaseScreen::Process(SGameTime* pGameTime) 
{

}
void CBaseScreen::Input(SGameTime* pGameTime) 
{

}
void CBaseScreen::Draw() 
{

}
void CBaseScreen::DrawOverlay() 
{

}
bool CBaseScreen::AllAssetsLoaded() 
{
    if(this->assetBag != nullptr) {
        bool ready = this->assetBag->Ready();
        if(ready != false) {
            return true;
        }
    }
    return false;
}
void CBaseScreen::SetupPointers(CBaseScreen* child) 
{
    child->parent = this;
    child->CopyFrom(this);
}
void CBaseScreen::RemoveScreen(CBaseScreen* child) 
{
    this->children->remove(child);
}
void CBaseScreen::PrintTree(int param_1, std::stringstream outstream) 
{
    //TODO: Figure out this code (its mostly useless afaik so like meh)
}

void CBaseScreen::StartUsingAsset(CAssetBag::eAssetType& assetType, std::string& assetName)
{
    if(this->assetBag == nullptr) {
        NKAssert();
    }
    this->assetBag->StartUsing(assetType, assetName);
}