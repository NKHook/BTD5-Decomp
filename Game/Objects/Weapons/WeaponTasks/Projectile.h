#pragma once

#include "../WeaponTask.h"
#include <NewFramework/Graphics/Objects/BasePositionableObject.h>

//TODO: Find actual place where these would be defined
enum DrawLayer {
    ABOVE_TOWERS,
    BELOW_TOWERS
};
enum CollisionType {
    NONE,
    ONCE,
    CONTINUAL
};

class CProjectile : public WeaponTask, public CBasePositionableObject {
public:
    char pad_00A8[44]; //0x00A8
    DrawLayer N0000147B; //0x00D4
    char pad_00D8[84]; //0x00D8
    float angleIncrement; //0x012C
    char pad_0130[60]; //0x0130
    CollisionType collisionType; //0x016C
    bool ignoreStatusEffect; //0x0170
    char pad_0171[3]; //0x0171
    bool terminateOnZeroPersists; //0x0174
    bool removeOnRoundEnd; //0x0175
    bool growsOnRoundEnd; //0x0176
    bool terminateOnTowerRemoved; //0x0177
    bool onlyFireTerminateTasksOnZeroPersists; //0x0178
    char pad_0179[3]; //0x0179
    int32_t amountToGrow; //0x017C
    int32_t maxGrowth; //0x0180
    float radius; //0x0184
    bool noSpread; //0x0188
    char pad_0189[3]; //0x0189
    float spreadAngle; //0x018C
    float spinRate; //0x0190
    bool hasLimitedDuration; //0x0194
    bool hasRandomOrientation; //0x0195
    char pad_0196[2]; //0x0196
    bool limitedDuration; //0x0198
    char pad_0199[3]; //0x0199
    float N000014AD; //0x019C
    bool hasFixedAngle; //0x01A0
    char pad_01A1[27]; //0x01A1
    bool forcePersists; //0x01BC
    bool collidesOnlyWithTarget; //0x01BD
    bool onlyCollidePastCutOff; //0x01BE
    char pad_01BF[1]; //0x01BF
    bool loopAnimation; //0x01C0
    char pad_01C1[15]; //0x01C1

public:
    virtual ~CProjectile();

    virtual CProjectile* Clone();
    virtual void* FUN_006ffed0(uint32_t param_2);
    virtual void* FUN_006fff50();
    virtual void* FUN_007096b0(uint32_t param_2, uint32_t param_3, uint32_t param_4, uint32_t param_5);
    virtual void FUN_OPTIMIZEDOUT(class SGameTime* pSGameTime);
    virtual void Kill();
};