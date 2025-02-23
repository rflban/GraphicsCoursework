#ifndef GCW_PRESENTER_H_
#define GCW_PRESENTER_H_

#include "ViewObserver.h"

#include "Container.h"

class View;
class Scene;

class Presenter : public ViewObserver
{
public:
    Presenter(Scene *scene);

    void setView(View *view);

    void renderFrame() override;

    void scaleCamera(double, double, double) override;
    void rotateCamera(double, double, double) override;
    void translateCamera(double, double, double) override;

    void updateVelocity(double) override;
    void updateParticle(int) override;

private:
    Scene *scene;
    View *view;
};

#endif // GCW_PRESENTER_H_

