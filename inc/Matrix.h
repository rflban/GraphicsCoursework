#ifndef GCW_MATRIX_H_
#define GCW_MATRIX_H_

#include <initializer_list>

class Matrix4d
{
public:
    Matrix4d();
    Matrix4d(std::initializer_list<double> l);

    Matrix4d operator*(const Matrix4d &m);

    double data[4][4];
};

#endif // GCW_MATRIX_H_

