#ifndef GCW_PERSPECTIVECUBE_H_
#define GCW_PERSPECTIVECUBE_H_

#include <cmath>
#include "Matrix.h"

class PerspectiveCube
{
public:
    PerspectiveCube(double fov, double ar, double near, double far);

    Matrix4d operator()();

private:
    double fov;  // field of view
    double ar;   // aspect ratio
    double near; // nearest cube face
    double far;  // furthest cube face
};

#endif // GCW_PERSPECTIVECUBE_H_

