#include "AppClass.h"

CApp::CApp() : IBasePointers::IBasePointers() {
	time64_t _Var1;
	//this->field0_0x0 = vftable;
	this->field126_0x84 = 0;
	this->field127_0x88 = 0;
	this->field128_0x8c = 0;
	this->field129_0x90 = 0;
	this->field131_0x93 = 0x101;
	this->field132_0x97 = 0;
	this->field_0x9b = 0;
	this->field138_0xa0 = 0x7fefffffffffffff;
	this->field139_0xa8 = 0;
	this->field_0xaa = 0;
	FUN_005a0580(&this->field146_0xb0);
	FUN_005a0580(&this->field170_0xc8);
	FUN_005a0580(&this->field194_0xe0);
	this->field218_0xf8 = 0;
	this->field219_0xfc = 0x101;
	DAT_00e921c8 = 0;
	DAT_00e921d0 = 0;
	DAT_00e921d8 = 0;
	_Var1 = _time64(nullptr);
	DAT_00e921e0 = (int)_Var1;
	_DAT_00e921e4 = (int)((ulonglong)_Var1 >> 0x20);
	_DAT_00e921e8 = 0;
	_DAT_00e921f0 = 0;
	return &this->field0_0x0;
}
CApp::~CApp() {
	uint uVar1;
	int iVar2;
	int **in_FS_OFFSET;
	int *local_10;
	undefined *puStack12;
	undefined4 uStack8;
	
	uStack8 = 0xffffffff;
	puStack12 = &LAB_00b634c4;
	local_10 = *in_FS_OFFSET;
	uVar1 = DAT_00db1034 ^ (uint)&stack0xfffffffc;
	*in_FS_OFFSET = (int *)&local_10;
	iVar2 = DAT_00e2ea1c;
	this->field0_0x0 = vftable;
	if (iVar2 == 0) {
		operator_new(0xc);
		iVar2 = FUN_009a9a10();
		DAT_00e2ea1c = iVar2;
	}
	FUN_009a9b50(iVar2,"..\\..\\..\\BaseApplication\\AppClass\\AppClass.cpp",
				"__thiscall CApp::~CApp(void)",0xbc,"Game Shutdown",uVar1);
	if (this->field69_0x48 != 0) {
		FUN_00a11d40();
	}
	FUN_005a0410();
	FUN_005a0410();
	FUN_005a0410();
	FUN_005fc4d0();
	*in_FS_OFFSET = local_10;
	return;
}