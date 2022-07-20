#include "Loc.h"

CLoc::CLoc(CBaseFileIO* pCBaseFileIO) {
    this->pCBaseFileIO = pCBaseFileIO;
    StringHelper::format("","\n");
    string locId = "LOC " + this->currentLocale;
    this->AddLanguages("Assets/Loc/");
    this->LoadLang("en");
    this->LoadFallbackLang("en");
    this->pFallbackLang = this->FindLang(true, "en");
    this->SetLangID(this->pCurrentLocale);
    return;
}