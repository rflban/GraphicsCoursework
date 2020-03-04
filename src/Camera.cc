#include "Camera.h"

#include <cmath>

Camera::Camera(Vector3d from, Vector3d to, Vector3d up) :
    from(from), to(to), up(up)
{
}

Matrix4d Camera::operator()()
{
    Vector3d foward = (from - to).normalize();
    Vector3d right = up * foward;

    up = (foward * right).normalize();

    return Matrix4d({
        right.x,  right.y,  right.z,  0,
        up.x,     up.y,     up.z,     0,
        foward.x, foward.y, foward.z, 0,
        from.x,   from.y,   from.z,   1
    });
}

void Camera::rotateArroundCenter(double deltaTheta, double deltaPhi)
{
    double theta;
    double phi;
    double r = (from - to).len();

    int signx = 1;
    if (from.x < 0)
    {
        signx = -1;
    }

    int signz = 1;
    if (from.z < 0)
    {
        signz = -1;
    }

    if (from.z == 0)
    {
        theta = 0;
    }
    else
    {
        theta = atan(sqrt(from.x * from.x + from.y * from.y) / from.z) * signx;
    }

    if (from.x == 0)
    {
        phi = 0;
    }
    else
    {
        phi = atan(from.y / from.x) * signz;
    }

    theta += deltaTheta;
    phi += deltaPhi;

    from.x = r * sin(theta) * cos(phi);
    from.y = r * sin(theta) * sin(phi);
    from.z = r * cos(theta);

    double x1 = to.x;
    double y1 = to.y * cos(theta) - to.z * sin(theta);
    double z1 = to.y * sin(theta) + to.z * cos(theta);

    to.x = +x1 * cos(theta) + z1 * sin(theta);
    to.y = +y1;
    to.z = -x1 * sin(theta) + z1 * cos(theta);
}

