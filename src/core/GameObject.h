#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "events/IObserver.h"
#include "events/ISubject.h"

class GameObject : public IObserver, public ISubject
{
public:
    GameObject()
    {

    }

// Events: Observer
private:
    /**
     * @brief Do something when notified
     * 
     * @param subject 
     */
    virtual void onNotify(ISubject *subject) override;
};


#endif