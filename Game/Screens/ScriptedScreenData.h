#pragma once

#include "../../Framework/NewFramework/BaseApplication/Screens/ScreenData.h"
#include <string>

class ScriptedScreenData : public IScreenData {
    std::string scriptPath;
public:
    ScriptedScreenData() = default;
    ScriptedScreenData(std::string& scriptPath);
    virtual ~ScriptedScreenData() = default;
}