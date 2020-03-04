#include "Camera.h"

#include <cmath>
#include "Affine.h"

Camera::Camera(Vector3d from, Vector3d to, Vector3d up) :
    from(from), to(to), up(up)
{
}

Matrix4d Camera::operator()()
{
    Vector3d foward = (from - to).normalize();
    Vector3d right = up * foward;
    Vector3d up = (foward * right).normalize();

    return Matrix4d({
        right.x,  right.y,  right.z,  0,
        up.x,     up.y,     up.z,     0,
        foward.x, foward.y, foward.z, 0,
        from.x,   from.y,   from.z,   1
    });
}

void Camera::scale(double rx, double ry, double rz)
{
    if (rx != 0 && ry != 0 && rz != 0)
    {
        from = Vector4d(from) * scaling(rx, ry, rz);
    }
}

void Camera::rotate(double ax, double ay, double az)
{
    if (ax != 0)
    {
        from = Vector4d(from) * rotationX(ax);
        up = Vector4d(up) * rotationX(ax);
    }

    if (ay != 0)
    {
        from = Vector4d(from) * rotationY(ay);
        up = Vector4d(up) * rotationY(ay);
    }

    if (az != 0)
    {
        from = Vector4d(from) * rotationZ(az);
        up = Vector4d(up) * rotationZ(az);
    }
}

void Camera::translate(double dx, double dy, double dz)
{
    if (dx != 0 || dy != 0 || dz != 0)
    {
        from = Vector4d(from) * translation(dx, dy, dz);
    }
}

