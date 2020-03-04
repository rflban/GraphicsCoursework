#ifndef GCW_VIEW_H_
#define GCW_VIEW_H_

#include "Container.h"

class ViewObserver;

class View
{
public:
    void attach(ViewObserver *observer);

protected:

private:
    void notify(void (ViewObserver::*respond)());

    Container<ViewObserver *> observers;
};

#endif // GCW_VIEW_H_

