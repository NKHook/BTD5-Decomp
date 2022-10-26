#include "BaseButton.h"

virtual void InputAll(SGameTime& gameTime)
{
    //No clue what happens here
}
virtual void AddButton(CBaseButton* button)
{
    if(avoidDuplicates) {
        bool added = false;
        for(const auto& b : this->buttons) {
            if(b == button) {
                added = true;
            }
        }
        if(added) {
            return;
        }
        this->buttons.push_back(button);
        return;
    }
    //Something happens here with the vector at this->0x1C
    this->moreButtons.push_back(button);
}
virtual void RemoveButton(CBaseButton* button)
{
    //Dont have time to look at this one right now
}
virtual void AddWatcher(CButtonDelegateWatcher* watcher)
{
    this->watchers.push_back(watcher);
}
virtual void RemoveWatcher(CButtonDelegateWatcher* watcher)
{
    this->watchers.erase(
        std::remove(
            this->watchers.begin(),
            this->watchers.end(),
            watcher
        ), this->watchers.end()
    );
}