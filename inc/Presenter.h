#ifndef GCW_PRESENTER_H_
#define GCW_PRESENTER_H_

#include "ViewObserver.h"

#include "Container.h"

class View;

class Presenter : public ViewObserver
{
public:
    void addView(View *view);

private:
    Container<View *> views;
};

#endif // GCW_PRESENTER_H_

