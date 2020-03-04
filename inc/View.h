#ifndef GCW_VIEW_H_
#define GCW_VIEW_H_

#include "Container.h"
#include "InputBuffer.h"

class ViewObserver;

class View
{
public:
    void attach(ViewObserver *observer);

    virtual void updateOutputBuffer() = 0;
    virtual InputBuffer *getInputBuffer() = 0;

protected:
    void frameRequested();
    void cameraRotationRequested(double deltaT, double deltaP);

private:
    void notify(void (ViewObserver::*respond)());

    Container<ViewObserver *> observers;
};

#endif // GCW_VIEW_H_

