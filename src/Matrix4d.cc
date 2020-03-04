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

