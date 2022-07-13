#pragma once

class IBasePointers {
public:
	struct CTextureLoader* pCTextureLoader;
	struct CInput* pCInput;
	class CApp* pCApp;
	struct CXmlFontImporter* pCXmlFontImporter;
	struct CBaseFileIO* pCBaseFileIO;
	struct CScreenManager* pCScreenManager;
	struct CSoundManager* pCSoundManager;
	struct CMusicManager* pCMusicManager;
	char pad_0024[12]; //0x0024
	struct CStoreInterface* pCStoreInterface;
	struct CSteamInterface* pCSteamInterface;
	char pad_0038[4]; //0x0038
	struct CLicensing* pCLicensing;
	char pad_0040[16]; //0x0040
	struct CFacebookInterface* pCFacebookInterface;
	struct CEveryplayInterface* pCEveryplayInterface;
	struct CCurlHttpRequestManager* pCCurlHttpRequestManager;
	char pad_005C[8]; //0x005C
	struct CLoc* pCLoc;

	IBasePointers();
};