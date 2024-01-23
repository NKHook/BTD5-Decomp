#pragma once

class IBasePointers {
public:
	class CTextureManager* mTextureManager = nullptr; //0x0000
	class CTextureLoader* mTextureLoader = nullptr; //0x0004
	class CInput* mInput = nullptr; //0x0008
	class CApp* mApp = nullptr; //0x000C
	class IFontImporter* mFontImporter = nullptr; //0x0010
	class CBaseFileIO* mBaseFileIO = nullptr; //0x0014
	class CScreenManager* mScreenManager = nullptr; //0x0018
	class CSoundManager* mSoundManager = nullptr; //0x001C
	class CMusicManager* mMusicManager = nullptr; //0x0020
	char pad_0024[4]; //0x0024
	class IStoreInterface* mStoreInterface = nullptr; //0x0028
	class IDRMInterface* mAchievementInterface = nullptr; //0x002C
	char pad_0030[4]; //0x0030
	class CLicensing* mLicensing = nullptr; //0x0034
	char pad_0038[12]; //0x0038
	class CFacebookInterface* mFacebookInterface = nullptr; //0x0044
	class CEveryplayInterface* mEveryplayInterface = nullptr; //0x0048
	class CCurlHttpRequestManager* mCurlHttpRequestManager = nullptr; //0x004C
	char pad_0050[8]; //0x0050
	class CLoc* mLoc = nullptr; //0x0058
	char pad_005C[16]; //0x005C

	IBasePointers();

	void CopyFrom(IBasePointers* other);
};