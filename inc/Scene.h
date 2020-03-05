#ifndef GCW_SCENE_H_
#define GCW_SCENE_H_

#include "Camera.h"
#include "PerspectiveCube.h"
#include "Matrix.h"

#include "other/specrend.h"

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

    void rotateGalaxy(double, double, double);

    void resetGalaxy(int qty);

    inline void setVel(double vel)
    { this->vel = vel; }

private:

    struct Color { double r; double g; double b; };

    Color ColorFromTemperature(double temp) const;

    SpiralGalaxy *galaxy;
    Matrix4d rotation;

    Camera viewer;
    PerspectiveCube perspective;

    double vel;

    int m_colNum;
    double m_t0;
    double m_t1;
    double m_dt;
    Color *m_col;
};

#endif // GCW_SCENE_H_

