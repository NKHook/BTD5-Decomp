#pragma once

#include <list>

#include <Math/Matrix.hpp>
#include <Math/MathematicTypes/VectorDataStructures.hpp>

class CBasePositionableObject /*:
	public boost::intrusive::list_base_hook<boost::intrusive::tag<_BasePositionableObjectDetail::SBasePositionableObjectListTag>, boost::intrusive::link_mode<2>, void>,
	public boost::intrusive::hook_tags_definer<boost::intrusive::generic_hook<boost::intrusive::circular_list_algorithms<boost::intrusive::list_node_traits<void*>>, _BasePositionableObjectDetail::SBasePositionableObjectListTag, 2, 1>, 0>*/
{
public:
	char pad_0000[12]; //0x0000
	bool visible; //0x000C
	char pad_000D[3]; //0x000D
	std::list<CBasePositionableObject*> children; //0x0014
	CVec2 size; //0x0020
	CVec2 sizeHalf; //0x0028
	char pad_0030[8]; //0x0030
	CMatrix spriteMatrix; //0x0038
	bool complete; //0x0078
	bool needsCompletion; //0x0079
	char pad_007A[2]; //0x007A
	CVec2 alignment; //0x007C
	char pad_0084[12]; //0x0084
	CVec3 location; //0x0090
	float rotAngle; //0x009C
	CVec2 scale; //0x00A0

	CBasePositionableObject();

	virtual ~CBasePositionableObject();
	virtual void Render(bool recurse);
	virtual void Update(struct SGameTime& pSGameTime);
	virtual void UpdateRecursive(SGameTime& param_1);
	virtual bool HitTest(CVec2& location, float param_2) { return false;  }
	virtual void AddChild(CBasePositionableObject& child);
	virtual void AddChildAndUpdate(CBasePositionableObject& child, int* param_2);
	virtual void FUN_009e6dc0(int* param_1, int** param_2);
	virtual void FUN_009e6d60();
	virtual void SetXYZ(CVec3& location);
	virtual void SetXY(CVec2& location);
	virtual void SetXY_1(CVec2& location);
	virtual void SetX(float x);
	virtual void SetY(float y);
	virtual void SetZ(float z);
	virtual void MoveXYZ(CVec3& location);
	virtual void MoveXY(CVec2& location);
	virtual void MoveX(float x);
	virtual void MoveY(float y);
	virtual void MoveZ(float z);
	virtual void Scale(CVec2& scale);
	virtual void ScaleXY(CVec2& scale);
	virtual void ScaleX(float x);
	virtual void ScaleY(float y);
	virtual void SetRotation(float angle);
	virtual void SetSize(CVec2& size);
	virtual void SetSizeX(float x);
	virtual void SetSizeY(float y);
	virtual void SetAlignX(float x);
	virtual void SetAlignY(float param_1);
	virtual void SetAlignXY(CVec2& alignment);
	virtual CVec3& GetLocation() { return location; }
	virtual float& GetLocationX() { return location.mX; }
	virtual float& GetLocationX_1() { return location.mX; }
	virtual float& GetLocationY() { return location.mY; }
	virtual float& GetLocationZ() { return location.mZ; }
	virtual CVec2& GetScale(CVec2& scale) { return scale; }
	virtual float GetScaleX() { return 0.0f; }
	virtual float GetScaleY() { return 0.0f; }
	virtual void ResetMatrix();
	virtual void UpdateMatrix(bool param_1);
	virtual void UpdateMatrixRecursive();
	virtual void ForceUpdate();
	virtual void SetTransitionAnim(float time, bool unused);
	virtual void SetCompletionNeeds(bool completed);
	virtual void ForceUpdate_1();
	virtual void RenderChildren();
};