#include "BasePositionableObject.h"

#include "../../Math/Matrix16F.h"
#include "../../Math/Vec3F.h"
#include "../../Math/Vec2F.h"
#include <memory.h>

CBasePositionableObject::CBasePositionableObject() : field1_0x4(0), field2_0x8(0)
{
	this->field3_0xc = 1;
	this->complete = true;
	this->field23_0x88 = 9;
	this->scale = Vec2F(1.0f, 1.0f);
}

~CBasePositionableObject();
void CBasePositionableObject::Render(bool recurse)
{
	if(this->visible)
	{
		this->UpdateMatrix(false);
		if(recurse)
		{
			this->RenderChildren();
		}
	}
}
void CBasePositionableObject::Update(SGameTime& gameTime)
{
	return;
}
void CBasePositionableObject::UpdateRecursive(SGameTime& gameTime)
{
	this->Update(gameTime);
	for(CBasePositionableObject* child : this->children)
	{
		child->UpdateRecursive(gameTime);
	}
}
bool CBasePositionableObject::HitTest(Vec2F& location, float param_2)
{
	/* TODO: Write error message code... I'm excluding it for the time being because of the amount of preprocessor code and context I don't have */
}
void CBasePositionableObject::AddChild(CBasePositionableObject* child)
{
	if(child == nullptr)
	{
		return;
	}

	if(this->needsCompletion)
	{
		this->SetCompletionNeeds(true);
	}
	if(child->parent == nullptr)
	{
		child->Complete();
	}
	child->parent = this;
	child->Complete();
	puVar2 = this->children;
	puVar1 = &child->field1_0x4;
	piVar3 = puVar2->pPrevChild;
	child->field2_0x8 = piVar3;
	*puVar1 = puVar2;
	puVar2->pPrevChild = puVar1;
	*piVar3 = (int)puVar1;
}
void CBasePositionableObject::AddChildAndUpdate(CBasePositionableObject& param_1, int* param_2) {}
void CBasePositionableObject::WIN_FUN_009e6dc0(int* param_1, int** param_2) {} //Steam 3.37
void CBasePositionableObject::DeleteChildren() {}
void CBasePositionableObject::SetXYZ(Vec3F& location) {}
void CBasePositionableObject::SetXY(Vec2F& location) {}
void CBasePositionableObject::SetXY_1(Vec2F& location) {}
void CBasePositionableObject::SetX(float x) {}
void CBasePositionableObject::SetY(float y) {}
void CBasePositionableObject::SetZ(float z) {}
void CBasePositionableObject::MoveXYZ(Vec3F& location) {}
void CBasePositionableObject::MoveXY(Vec2F& location) {}
void CBasePositionableObject::MoveX(float x) {}
void CBasePositionableObject::MoveY(float y) {}
void CBasePositionableObject::MoveZ(float z) {}
void CBasePositionableObject::Scale(Vec2F& scale) {}
void CBasePositionableObject::ScaleXY(Vec2F& scale) {}
void CBasePositionableObject::ScaleX(float x) {}
void CBasePositionableObject::ScaleY(float y) {}
void CBasePositionableObject::SetRotation(float angle) {}
void CBasePositionableObject::SetSize(Vec2F& size) {}
void CBasePositionableObject::SetSizeX(float x) {}
void CBasePositionableObject::SetSizeY(float y) {}
void CBasePositionableObject::SetAlignX(float x) {}
void CBasePositionableObject::SetAlignY(float param_1) {}
void CBasePositionableObject::SetAlignXY(Vec2F& alignment) {}
Vec3F& CBasePositionableObject::GetLocation(Vec3F& location) { return nullptr; }
float& CBasePositionableObject::GetLocationX() { return nullptr; }
float& CBasePositionableObject::GetLocationX_1() { return nullptr; }
float& CBasePositionableObject::GetLocationY() { return nullptr; }
float& CBasePositionableObject::GetLocationZ() { return nullptr; }
Vec2F& CBasePositionableObject::GetScale(Vec2F& scale) { return nullptr; }
float CBasePositionableObject::GetScaleX() { return 0.0f; }
float CBasePositionableObject::GetScaleY() { return 0.0f; }
void CBasePositionableObject::ResetMatrix() {
	if (this->complete != false) {
		WIN_DAT_00e2ea78 = WIN_DAT_00e2ea78 + 1; //WIN_DAT_00e2ea78 in Steam ver 3.37
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
void CBasePositionableObject::SetCompletionNeeds(bool needsCompletion)
{
	this->needsCompletion = needsCompletion;
	for(CBasePositionableObject* child : this->children)
	{
		child->SetCompletionNeeds(needsCompletion);
	}
}
void CBasePositionableObject::ForceUpdate_1() {}
void CBasePositionableObject::RenderChildren() {}