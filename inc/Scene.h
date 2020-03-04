#ifndef GCW_SCENE_H_
#define GCW_SCENE_H_

#include "Camera.h"
#include "PerspectiveCube.h"

class InputBuffer;
class SpiralGalaxy;

class Scene
{
public:
    Scene();
    ~Scene();

    void render(InputBuffer &buffer);

    void scaleCamera(double, double, double);
    void rotateCamera(double, double, double);
    void translateCamera(double, double, double);

private:
    SpiralGalaxy *galaxy;

    Camera viewer;
    PerspectiveCube perspective;
};

#endif // GCW_SCENE_H_

