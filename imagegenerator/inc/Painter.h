#ifndef GCW_PAINTER_H_
#define GCW_PAINTER_H_

#include <cstddef>

class PaintSurface;
struct Pixel;

class Painter
{
public:
    Painter(PaintSurface *surface);
    ~Painter();

    void setColor(const Pixel &color);

    void fillRect(size_t startX, size_t startY,
                  size_t width, size_t height, const Pixel &pixel);

    void fillPixel(size_t x, size_t y);
    void fillPixel(size_t x, size_t y, const Pixel &color);

    void drawEllipse(size_t x, size_t y,
                     size_t a, size_t b,
                     double angle = 0);
    void drawEllipse(size_t x, size_t y,
                     size_t a, size_t b,
                     double angle, const Pixel &color);

private:
    PaintSurface *surface;
    Pixel *color;

    void __set_pixel(size_t x, size_t y, const Pixel &pixel);
};

#endif // GCW_PAINTER_H_

