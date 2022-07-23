#include "BasePositionableObject.h"

#include <memory.h>

CBasePositionableObject::CBasePositionableObject() : field1_0x4(0), field2_0x8(0)
{
	this->field3_0xc = 1;
	this->complete = true;
	this->field23_0x88 = 9;
	this->scale = Vec2F(1.0f, 1.0f);
}

~CBasePositionableObject();
void CBasePositionableObject::Render(bool animate) {}
void CBasePositionableObject::Update(class SGameTime* pSGameTime) {}
void CBasePositionableObject::UpdateRecursive(class SGameTime* param_1) {}
bool CBasePositionableObject::HitTest(class Vec2F* location, float param_2) { return false; }
void CBasePositionableObject::AddChild(class CBasePositionableObject* param_1) {}
void CBasePositionableObject::AddChildAndUpdate(class CBasePositionableObject* param_1, int* param_2) {}
void CBasePositionableObject::FUN_009e6dc0(int* param_1, int** param_2) {}
void CBasePositionableObject::FUN_009e6d60() {}
void CBasePositionableObject::SetXYZ(class Vec3F* location) {}
void CBasePositionableObject::SetXY(class Vec2F* location) {}
void CBasePositionableObject::SetXY_1(class Vec2F* location) {}
void CBasePositionableObject::SetX(float x) {}
void CBasePositionableObject::SetY(float y) {}
void CBasePositionableObject::SetZ(float z) {}
void CBasePositionableObject::MoveXYZ(class Vec3F* location) {}
void CBasePositionableObject::MoveXY(class Vec2F* location) {}
void CBasePositionableObject::MoveX(float x) {}
void CBasePositionableObject::MoveY(float y) {}
void CBasePositionableObject::MoveZ(float z) {}
void CBasePositionableObject::Scale(class Vec2F* scale) {}
void CBasePositionableObject::ScaleXY(class Vec2F* scale) {}
void CBasePositionableObject::ScaleX(float x) {}
void CBasePositionableObject::ScaleY(float y) {}
void CBasePositionableObject::SetRotation(float angle) {}
void CBasePositionableObject::SetSize(class Vec2F* size) {}
void CBasePositionableObject::SetSizeX(float x) {}
void CBasePositionableObject::SetSizeY(float y) {}
void CBasePositionableObject::SetAlignX(float x) {}
void CBasePositionableObject::SetAlignY(float param_1) {}
void CBasePositionableObject::SetAlignXY(class Vec2F* alignment) {}
class CBasePositionableObject::Vec3F* GetLocation(class Vec3F* location) { return nullptr; }
float* CBasePositionableObject:: GetLocationX() { return nullptr; }
float* CBasePositionableObject:: GetLocationX_1() { return nullptr; }
float* CBasePositionableObject:: GetLocationY() { return nullptr; }
float* CBasePositionableObject:: GetLocationZ() { return nullptr; }
class CBasePositionableObject::Vec2F* GetScale(class Vec2F* scale) { return nullptr; }
float CBasePositionableObject::GetScaleX() { return 0.0f; }
float CBasePositionableObject::GetScaleY() { return 0.0f; }
void CBasePositionableObject::ResetMatrix() {
	if (this->complete != false) {
		_DAT_00e2ea78 = _DAT_00e2ea78 + 1;
		this->spriteMatrix.Reset(this->location, this->rotAngle);
		if ((this->scale.x != 1.0) || (this->scale.y != 1.0)) {

			
			//These operations may be its own function?
			//If me or someone else finds a copy of this, lets make it into a function
			//it looks like the result of a compiler optimization


			this->spriteMatrix.a = this->spriteMatrix.a * this->scale.x;
			this->spriteMatrix.b = this->spriteMatrix.b * this->scale.x;
			this->spriteMatrix.c = this->spriteMatrix.c * this->scale.x;
			this->spriteMatrix.d = this->spriteMatrix.d * this->scale.x;

			this->spriteMatrix.e = this->spriteMatrix.e * this->scale.y;
			this->spriteMatrix.f = this->spriteMatrix.f * this->scale.y;
			this->spriteMatrix.g = this->spriteMatrix.g * this->scale.y;
			this->spriteMatrix.h = this->spriteMatrix.h * this->scale.y;
		}
		this->complete = this->incompleteChildren;
	}
}
void CBasePositionableObject::UpdateMatrix(bool param_1) {}
void CBasePositionableObject::UpdateMatrixRecursive() {}
void CBasePositionableObject::ForceUpdate() {}
void CBasePositionableObject::SetTransitionAnim(float time, bool unused) {}
void CBasePositionableObject::FUN_009e69d0() {}
void CBasePositionableObject::ForceUpdate_1() {}
void CBasePositionableObject::DrawChildren() {}