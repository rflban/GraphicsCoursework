#ifndef GCW_PIXMAP_H_
#define GCW_PIXMAP_H_

#include "PaintSurface.h"
#include "Pixel.h"

class Pixmap : public PaintSurface
{
public:
    Pixmap(size_t width, size_t height);
    ~Pixmap();

    size_t getWidth() const override { return width; }
    size_t getHeight() const override { return height; }

    Pixel *operator[](size_t idx) override;
    const Pixel *operator[](size_t idx) const override;

private:
    size_t width;
    size_t height;

    Pixel **pixels;
};

#endif // GCW_PIXMAP_H_

