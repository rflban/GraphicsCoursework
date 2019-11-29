#include "Painter.h"

#include <cmath>

#include "Pixel.h"
#include "PaintSurface.h"

Painter::Painter(PaintSurface *surface) :
    surface(surface),
    color(nullptr)
{
    setColor({0, 0, 0});
}

Painter::~Painter()
{
    delete color;
}

void Painter::setColor(const Pixel &color)
{
    if (this->color == nullptr)
        this->color = new Pixel;

    *(this->color) = color;
}

void Painter::fillRect(size_t startX, size_t startY,
                       size_t width, size_t height, const Pixel &pixel)
{
    for (size_t i = startX; i < width; i++)
    {
        for (size_t j = startY; j < height; j++)
        {
            (*surface)[i][j] = pixel;
        }
    }
}

void Painter::fillPixel(size_t x, size_t y)
{
    this->fillPixel(x, y, *color);
}

void Painter::fillPixel(size_t x, size_t y, const Pixel &color)
{
    (*surface)[x][y] = color;
}

void Painter::drawEllipse(size_t x0, size_t y0,
                          size_t a, size_t b,
                          double angle)
{
    this->drawEllipse(x0, y0, a, b, angle, *color);
}

void Painter::drawEllipse(size_t x0, size_t y0,
                          size_t a, size_t b,
                          double angle, const Pixel &color)
{
    double x;
    double y = b;
    double t = 0;
    double h = 1.0 / a;

    int y_min = int(round(b * b / sqrt(a * a + b * b)));

    while (y >= y_min)
    {
        x = a * sin(t);
        y = b * cos(t);

        int _x = int(round(x));
        int _y = int(round(y));

        (*surface)[x0 + _x][y0 + _y] = color;
        (*surface)[x0 + _x][y0 - _y] = color;
        (*surface)[x0 - _x][y0 + _y] = color;
        (*surface)[x0 - _x][y0 - _y] = color;

        t += h;
    }

    h = 1.0 / b;

    while (y >= 0)
    {
        x = a * sin(t);
        y = b * cos(t);

        int _x = int(round(x));
        int _y = int(round(y));

        (*surface)[x0 + _x][y0 + _y] = color;
        (*surface)[x0 + _x][y0 - _y] = color;
        (*surface)[x0 - _x][y0 + _y] = color;
        (*surface)[x0 - _x][y0 - _y] = color;

        t += h;
    }
}

