#ifndef GCW_CAMERA_H_
#define GCW_CAMERA_H_

#include "Vector.h"
#include "Matrix.h"

class Camera
{
public:
    Camera(Vector3d from,
           Vector3d to=Vector3d(0, 0, 0),
           Vector3d up=Vector3d(0, 1, 0));

    Matrix4d operator()();

    void scale(double rx, double ry, double rz);
    void rotate(double ax, double ay, double az);
    void translate(double dx, double dy, double dz);

private:
    Vector3d from;
    Vector3d to;
    Vector3d up;
};

#endif // GCW_CAMERA_H_

