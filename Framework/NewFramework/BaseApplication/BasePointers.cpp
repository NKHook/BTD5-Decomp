#include "BasePointers.h"

IBasePointers::IBasePointers() {
	//TODO: Find missing offsets
	this->pCTextureLoader = nullptr;
	this->pCInput = nullptr;
	this->pCApp = nullptr;
	this->pCXmlFontImporter = nullptr;
	this->pCBaseFileIO = nullptr;
	this->pCScreenManager = nullptr;
	this->pCSoundManager = nullptr;
	this->pCMusicManager = nullptr;
	//this->field9_0x24 = nullptr;
	//this->field10_0x28 = nullptr;
	//this->field11_0x2c = nullptr;
	this->pCStoreInterface = nullptr;
	this->pCSteamInterface = nullptr;
	//this->field14_0x38 = nullptr;
	this->pCLicensing = nullptr;
	//this->field16_0x40 = nullptr;
	//this->field17_0x44 = nullptr;
	//this->field18_0x48 = nullptr;
	//this->field19_0x4c = nullptr;
	this->pCFacebookInterface = nullptr;
	this->pCEveryplayInterface = nullptr;
	this->pCCurlHttpRequestManager = nullptr;
	//this->field27_0x60 = nullptr;
	//this->field28_0x64 = nullptr;
	this->pCLoc = nullptr;
	//this->field30_0x6c = nullptr;
}

void IBasePointers::CopyFrom(IBasePointers* other) {
	this->pCTextureLoader = other->pCTextureLoader;
	this->pCInput = other->pCInput;
	this->pCApp = other->pCApp;
	this->pCXmlFontImporter = other->pCXmlFontImporter;
	this->pCBaseFileIO = other->pCBaseFileIO;
	this->pCScreenManager = other->pCScreenManager;
	this->pCSoundManager = other->pCSoundManager;
	this->pCMusicManager = other->pCMusicManager;
	//this->field9_0x24 = other->field9_0x24;
	//this->field10_0x28 = other->field10_0x28;
	//this->field11_0x2c = other->field11_0x2c;
	this->pCStoreInterface = other->pCStoreInterface;
	this->pCSteamInterface = other->pCSteamInterface;
	//this->field14_0x38 = other->field14_0x38;
	this->pCLicensing = other->pCLicensing;
	//this->field16_0x40 = other->field16_0x40;
	//this->field17_0x44 = other->field17_0x44;
	//this->field18_0x48 = other->field18_0x48;
	//this->field19_0x4c = other->field19_0x4c;
	this->pCFacebookInterface = other->pCFacebookInterface;
	this->pCEveryplayInterface = other->pCEveryplayInterface;
	this->pCCurlHttpRequestManager = other->pCCurlHttpRequestManager;
	//this->field27_0x60 = other->field27_0x60;
	//this->field28_0x64 = other->field28_0x64;
	this->pCLoc = other->pCLoc;
	//this->field30_0x6c = other->field30_0x6c;
}
