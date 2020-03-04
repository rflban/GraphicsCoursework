#include "PerspectiveCube.h"

PerspectiveCube::PerspectiveCube(double fov, double ar,
                                 double near, double far) :
    fov(fov), ar(ar), near(near), far(far)
{
}

Matrix4d PerspectiveCube::operator()()
{
    double halfTanFov = tan(fov) / 2.0;

    return Matrix4d({
        1.0 / (ar * halfTanFov), 0,                0,                                 0,
        0,                       1.0 / halfTanFov, 0,                                 0,
        0,                       0,                -(far + near) / (far - near),     -1,
        0,                       0,                -2 * (far * near) / (far - near),  0
    });
}

