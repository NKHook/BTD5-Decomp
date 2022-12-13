#include "StatusEffect.h"

CStatusEffect::CStatusEffect()
{

}

CStatusEffect::~CStatusEffect()
{
    if (this->tower) {
        this->tower->refCount--;
    }
}

float CStatusEffect::GetBloonSpeed(float base)
{
    return base;
}
void CStatusEffect::IncreasePops(int amount)
{
    if (this->tower != nullptr)
	{
		this->tower->IncPopCount(amount, nullptr);
	}
}