#ifndef GCW_GEOMETRY_H_
#define GCW_GEOMETRY_H_

struct Vector2D
{
    Vector2D(double x=0, double y=0) : x(x), y(y) {}

    double x;
    double y;
};

struct Vector3D
{
    Vector3D(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}

    double x;
    double y;
    double z;
};

#endif // GCW_GEOMETRY_H_

