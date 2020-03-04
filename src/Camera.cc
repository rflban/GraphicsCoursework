#include "Camera.h"

Camera::Camera(Vector3d from, Vector3d to) :
    from(from), to(to)
{
}

Matrix4d Camera::operator()()
{
    Vector3d foward = (from - to).normalize();
    Vector3d right = Vector3d(0, 1, 0).normalize() * foward;
    Vector3d up = (foward * right).normalize();

    return Matrix4d({
        right.x,  right.y,  right.z,  0,
        up.x,     up.y,     up.z,     0,
        foward.x, foward.y, foward.z, 0,
        from.x,   from.y,   from.z,   1
    });
}

