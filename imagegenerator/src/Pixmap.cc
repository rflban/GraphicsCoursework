#include "Pixmap.h"

#include "Pixel.h"

Pixmap::Pixmap(size_t width, size_t height) :
    width(width),
    height(height)
{
    size_t ptrs_size = width * sizeof(Pixel *);
    size_t line_size = height * sizeof(Pixel);

    pixels = (Pixel **)new char[ptrs_size + width * line_size];

    for (size_t idx = 0; idx < width; idx++)
    {
        pixels[idx] = (Pixel *)((char *)pixels + ptrs_size + idx * line_size);
    }

    for (size_t i = 0; i < width; i++)
    {
        for (size_t j = 0; j < height; j++)
        {
            pixels[i][j] = {0, 0, 0};
        }
    }
}

Pixmap::~Pixmap()
{
    delete[] pixels;
}

Pixel *Pixmap::operator[](size_t idx)
{
    return pixels[idx];
}

const Pixel *Pixmap::operator[](size_t idx) const
{
    return pixels[idx];
}

