#include "Matrix.h"

Matrix4d::Matrix4d()
{
    for (int i = 0; i < 16; i++)
    {
        data[i / 4][i % 4] = 0;
    }
}

Matrix4d::Matrix4d(std::initializer_list<double> l)
{
    int i = 0;

    for (auto it = l.begin(); i < 16; i++, it++)
    {
        data[i / 4][i % 4] = *it;
    }
}

Matrix4d Matrix4d::operator*(const Matrix4d &m)
{
    Matrix4d res;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int r = 0; r < 4; r++)
            {
                res.data[i][j] += data[i][r] * m.data[r][j];
            }
        }
    }

    return res;
}

