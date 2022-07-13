#include "IBasePointers.h"

IBasePointers::IBasePointers() {
	//TODO: Find missing offsets
	this->pCTextureLoader = 0;
	this->pCInput = 0;
	this->pCApp = 0;
	this->pCXmlFontImporter = 0;
	this->pCBaseFileIO = 0;
	this->pCScreenManager = 0;
	this->pCSoundManager = 0;
	this->pCMusicManager = 0;
	//this->field9_0x24 = 0;
	//this->field10_0x28 = 0;
	//this->field11_0x2c = 0;
	this->pCStoreInterface = 0;
	this->pCSteamInterface = 0;
	//this->field14_0x38 = 0;
	this->pCLicensing = 0;
	//this->field16_0x40 = 0;
	//this->field17_0x44 = 0;
	//this->field18_0x48 = 0;
	//this->field19_0x4c = 0;
	this->pCFacebookInterface = 0;
	this->pCEveryplayInterface = 0;
	this->pCCurlHttpRequestManager = 0;
	//this->field27_0x60 = 0;
	//this->field28_0x64 = 0;
	this->pCLoc = 0;
	//this->field30_0x6c = 0;
}