#ifndef GCW_AFFINE_H_
#define GCW_AFFINE_H_

#include "Matrix.h"
#include <cmath>

inline Matrix4d rotationX(double alpha)
{
    double c = cos(alpha);
    double s = sin(alpha);

    return Matrix4d({
         1,  0,  0,  0,
         0,  c,  s,  0,
         0, -s,  c,  0,
         0,  0,  0,  1
    });
}

inline Matrix4d rotationY(double alpha)
{
    double c = cos(alpha);
    double s = sin(alpha);

    return Matrix4d({
         c,  0, -s,  0,
         0,  1,  0,  0,
         s,  0,  c,  0,
         0,  0,  0,  1
    });
}

inline Matrix4d rotationZ(double alpha)
{
    double c = cos(alpha);
    double s = sin(alpha);

    return Matrix4d({
         c,  s,  0,  0,
        -s,  c,  0,  0,
         0, -0,  1,  0,
         0,  0,  0,  1
    });
}

inline Matrix4d translation(double dx, double dy, double dz)
{
    return Matrix4d({
         1,  0,  0,  0,
         0,  1,  0,  0,
         0,  0,  1,  0,
        dx, dy, dz,  1
    });
}

inline Matrix4d scaling(double rx, double ry, double rz)
{
    return Matrix4d({
        rx,  0,  0,  0,
         0, ry,  0,  0,
         0,  0, rz,  0,
         0,  0,  0,  1
    });
}

#endif // GCW_AFFINE_H_

