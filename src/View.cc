#include "View.h"

#include "ViewObserver.h"

void View::attach(ViewObserver *observer)
{
    observers.append(observer);
}

void View::notify(void (ViewObserver::*respond)())
{
    for (ViewObserver *observer: observers)
    {
        (observer->*respond)();
    }
}

void View::frameRequested()
{
    notify(&ViewObserver::renderFrame);
}

