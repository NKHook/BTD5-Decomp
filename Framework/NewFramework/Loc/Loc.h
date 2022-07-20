#pragma once

#include <string>

class CLoc {
    //Ignore first 4 bytes bc vtable
	//char pad_0000[4]; //0x0000
	CBaseFileIO* pCBaseFileIO = nullptr; //0x0004
	std::vector<SLangDef*> langDefs; //0x0008
	SLangDef* pCurrentLang = nullptr; //0x0014
	SLangDef* pFallbackLang = nullptr; //0x0018
	std::string unknown_1; //0x001C
	uint32_t unknown_2 = 0;
	uint32_t unknown_3 = 0;
	std::string currentLang; //0x003C
	std::string unknown_4; //0x0054
	uint32_t unknown_5 = 0;
	uint32_t unknown_6 = 0;
	uint32_t unknown_7 = 0;
	std::string dayHourFmt; //0x0078
	std::string hourMinuteFmt; //0x0090
	std::string minuteSecondFmt; //0x00A8
	std::string secondFmt; //0x00C0
	std::string dateFmt; //0x00D8

public:
    /*
    * CLoc::CLoc
    *
    * Creates a new CLoc instance and loads all Langs using the provided CBaseFileIO*.
    */
    CLoc(CBaseFileIO*);
    /*
    * CLoc::~CLoc
    *
    * Destroys the CLoc instance and cleans up.
    */
    virtual ~CLoc();
    /*
    * CLoc::AddLanguages
    *
    * langDir - The path to the directory containing translations
    * by default the game will use "Assets/Loc/".
    */
    bool AddLanguages(std::string& langDir);
    /*
    * CLoc::LoadLang
    *
    * lang - A string reference of the Lang id. Ex. "en" for English, or "it" for Italian.
    */
    void LoadLang(string& lang);
    /*
    * CLoc::LoadFallbackLang
    *
    * works the same as CLoc::LoadLang, but sets the fallback Lang instead.
    */
    void LoadFallbackLang(string& lang);
    /*
    * CLoc::FindLang
    *
    * fullLang - If we want to search via the full lang (Ex. "en-US" for English, or "it-IT" for Italian)
    * lang - The lang we are looking for. Without fullLang, this may be "en" for English, or "it" for Italian, for example.
    */
    SLang* FindLang(bool fullLang,string& lang)
};