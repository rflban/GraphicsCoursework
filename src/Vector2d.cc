#include "Vector.h"

#include <cmath>

Vector2d::Vector2d(double x, double y) :
    x(x), y(y)
{
}

Vector2d::Vector2d(const Vector2d &other) :
    x(other.x), y(other.y)
{
}

Vector2d &Vector2d::operator=(const Vector2d &other)
{
    x = other.x;
    y = other.y;

    return *this;
}

Vector2d Vector2d::operator+(double num)
{
    x += num;
    y += num;

    return *this;
}

Vector2d Vector2d::operator+(const Vector2d &other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2d Vector2d::operator-()
{
    x *= -1;
    y *= -1;

    return *this;
}

Vector2d Vector2d::operator-(double num)
{
    x -= num;
    y -= num;

    return *this;
}

Vector2d Vector2d::operator-(const Vector2d &other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vector2d Vector2d::operator*(double num)
{
    x *= num;
    y *= num;

    return *this;
}

Vector2d Vector2d::operator/(double num)
{
    x /= num;
    y /= num;

    return *this;
}

Vector2d &Vector2d::normalize()
{
    double len = this->len();

    if (len != 0)
    {
        x /= len;
        y /= len;
    }

    return *this;
}

double Vector2d::len()
{
    return sqrt(x*x + y*y);
}

