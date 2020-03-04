#include "Vector.h"

#include <cmath>

Vector3d::Vector3d(double x, double y, double z) :
    x(x), y(y), z(z)
{
}

Vector3d::Vector3d(const Vector3d &other) :
    x(other.x), y(other.y), z(other.z)
{
}

Vector3d &Vector3d::operator=(const Vector3d &other)
{
    x = other.x;
    y = other.y;
    z = other.z;

    return *this;
}

Vector3d Vector3d::operator+(double num)
{
    x += num;
    y += num;
    z += num;

    return *this;
}

Vector3d Vector3d::operator+(const Vector3d &other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3d Vector3d::operator-()
{
    x *= -1;
    y *= -1;
    z *= -1;

    return *this;
}

Vector3d Vector3d::operator-(double num)
{
    x -= num;
    y -= num;
    z -= num;

    return *this;
}

Vector3d Vector3d::operator-(const Vector3d &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vector3d Vector3d::operator*(double num)
{
    x *= num;
    y *= num;
    z *= num;

    return *this;
}

Vector3d Vector3d::operator/(double num)
{
    x /= num;
    y /= num;
    z /= num;

    return *this;
}

Vector3d Vector3d::operator*(const Vector3d &other)
{
    Vector3d v;

    v.x = y * other.z - z * other.y;
    v.y = z * other.x - x * other.z;
    v.z = x * other.y - y * other.x;

    return v;
}

Vector3d &Vector3d::normalize()
{
    double len = this->len();

    if (len != 0)
    {
        x /= len;
        y /= len;
        z /= len;
    }

    return *this;
}

double Vector3d::len()
{
    return sqrt(x*x + y*y + z*z);
}

