#pragma once

#include "../../IBasePointers.h"

enum class Device {
    PHONE = 0,
    TABLET = 1,
    UNKNOWN = 2
};

class CBaseScreen : public IBasePointers {
public:
    virtual ~CBaseScreen() {};
};