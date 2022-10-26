#pragma once

#include <algorithm>
#include <vector>

struct SButtonCB {

};

class CBaseButton {

};

class IButtonDelegate {
    std::vector<CBaseButton*> buttons;
    std::vector<CBaseButton*> moreButtons;
    bool avoidDuplicates = false;
    std::vector<CButtonDelegateWatcher*> watchers;
public:
    virtual ~IButtonDelegate() = default;
    virtual void ButtonPressed(SButtonCB& callback) = 0;
    virtual void InputAll(SGameTime& gameTime);
    virtual void AddButton(CBaseButton* button);
    virtual void RemoveButton(CBaseButton* button);
    virtual void AddWatcher(CButtonDelegateWatcher* watcher);
    virtual void RemoveWatcher(CButtonDelegateWatcher* watcher);
};