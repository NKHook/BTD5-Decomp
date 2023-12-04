#pragma once

#include <Framework/NewFramework/Events/Observer.h>
#include <Framework/NewFramework/Graphics/Objects/BasePositionableObject.h>

class CBaseTower : public CBasePositionableObject, public CObserver<CBloonEscapedEvent>, public CObserver<CTowerRemovedEvent>
{

};