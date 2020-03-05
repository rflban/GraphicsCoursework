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

void View::cameraScalingRequested(double rx, double ry, double rz)
{
    for (ViewObserver *observer: observers)
    {
        observer->scaleCamera(rx, ry, rz);
    }
}

void View::cameraRotationRequested(double ax, double ay, double az)
{
    for (ViewObserver *observer: observers)
    {
        observer->rotateCamera(ax, ay, az);
    }
}

void View::cameraTranslationRequested(double dx, double dy, double dz)
{
    for (ViewObserver *observer: observers)
    {
        observer->translateCamera(dx, dy, dz);
    }
}

void View::velocityModified(double vel)
{
    for (ViewObserver *observer: observers)
    {
        observer->updateVelocity(vel);
    }
}

void View::particleModified(int qty)
{
    for (ViewObserver *observer: observers)
    {
        observer->updateParticle(qty);
    }
}

