#ifndef GCW_CAMERA_H_
#define GCW_CAMERA_H_

#include "Vector.h"
#include "Matrix.h"

class Camera
{
public:
    Camera(Vector3d from, Vector3d to=Vector3d(0, 0, 0));

    Matrix4d operator()();

private:
    Vector3d from;
    Vector3d to;
};

#endif // GCW_CAMERA_H_

