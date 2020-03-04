#ifndef GCW_VECTOR_H_
#define GCW_VECTOR_H_

class Vector2d;
class Vector3d;
class Vector4d;

class Matrix4d;

class Vector2d
{
public:
    Vector2d(double x=0, double y=0);
    Vector2d(const Vector2d &other);

    Vector2d &operator=(const Vector2d &other);

    Vector2d operator+(double num);
    Vector2d operator+(const Vector2d &other);

    Vector2d operator-();
    Vector2d operator-(double num);
    Vector2d operator-(const Vector2d &other);

    Vector2d operator*(double num);
    Vector2d operator/(double num);

    Vector2d &normalize();

    double len();

    double x;
    double y;
};

class Vector3d
{
public:
    Vector3d(double x=0, double y=0, double z=0);
    Vector3d(const Vector3d &other);
    Vector3d(const Vector4d &other);

    Vector3d &operator=(const Vector3d &other);

    Vector3d operator+(double num);
    Vector3d operator+(const Vector3d &other);

    Vector3d operator-();
    Vector3d operator-(double num);
    Vector3d operator-(const Vector3d &other);

    Vector3d operator*(double num);
    Vector3d operator/(double num);

    Vector3d operator*(const Vector3d &other); // cross
    double operator&(const Vector3d &other); // dot

    Vector3d &normalize();

    double len();

    double x;
    double y;
    double z;
};

class Vector4d
{
public:
    Vector4d(double x=0, double y=0, double z=0, double w=1);
    Vector4d(const Vector3d &other, double w=1);
    Vector4d(const Vector4d &other);

    Vector4d &operator=(const Vector4d &other);

    Vector4d operator+(double num);
    Vector4d operator+(const Vector4d &other);

    Vector4d operator-();
    Vector4d operator-(double num);
    Vector4d operator-(const Vector4d &other);

    Vector4d operator*(double num);
    Vector4d operator/(double num);

    Vector4d operator*(const Matrix4d &matrix);

    Vector4d &normalize();

    double len();

    double x;
    double y;
    double z;
    double w;
};

#endif // GCW_VECTOR_H_

