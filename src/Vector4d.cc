#include "Vector.h"

#include <cmath>

#include "Matrix.h"

Vector4d::Vector4d(double x, double y, double z, double w) :
    x(x), y(y), z(z), w(w)
{
}

Vector4d::Vector4d(const Vector3d &other, double w) :
    x(other.x), y(other.y), z(other.z), w(w)
{
}

Vector4d::Vector4d(const Vector4d &other) :
    x(other.x), y(other.y), z(other.z), w(other.w)
{
}

Vector4d &Vector4d::operator=(const Vector4d &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;

    return *this;
}

Vector4d Vector4d::operator+(double num)
{
    x += num;
    y += num;
    z += num;
    w += num;

    return *this;
}

Vector4d Vector4d::operator+(const Vector4d &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;

    return *this;
}

Vector4d Vector4d::operator-()
{
    x *= -1;
    y *= -1;
    z *= -1;
    w *= -1;

    return *this;
}

Vector4d Vector4d::operator-(double num)
{
    x -= num;
    y -= num;
    z -= num;
    w -= num;

    return *this;
}

Vector4d Vector4d::operator-(const Vector4d &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;

    return *this;
}

Vector4d Vector4d::operator*(double num)
{
    x *= num;
    y *= num;
    z *= num;
    w *= num;

    return *this;
}

Vector4d Vector4d::operator/(double num)
{
    x /= num;
    y /= num;
    z /= num;
    w /= num;

    return *this;
}

Vector4d Vector4d::operator*(const Matrix4d &matrix)
{
    Vector4d v;

    v.x = x * matrix.data[0][0] + y * matrix.data[1][0] +
          z * matrix.data[2][0] + w * matrix.data[3][0];

    v.y = x * matrix.data[0][1] + y * matrix.data[1][1] +
          z * matrix.data[2][1] + w * matrix.data[3][1];

    v.z = x * matrix.data[0][2] + y * matrix.data[1][2] +
          z * matrix.data[2][2] + w * matrix.data[3][2];

    v.w = x * matrix.data[0][3] + y * matrix.data[1][3] +
          z * matrix.data[2][3] + w * matrix.data[3][3];

    return v;
}

Vector4d &Vector4d::normalize()
{
    double len = this->len();

    if (len != 0)
    {
        x /= len;
        y /= len;
        z /= len;
        w /= len;
    }

    return *this;
}

double Vector4d::len()
{
    return sqrt(x*x + y*y + z*z + w*w);
}

