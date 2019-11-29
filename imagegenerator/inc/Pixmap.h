#ifndef GCW_PIXMAP_H_
#define GCW_PIXMAP_H_

#include "PaintSurface.h"

class Pixmap : public PaintSurface
{
public:
    Pixmap(size_t width, size_t height);
    ~Pixmap();

    inline size_t getWidth() const { return width; }
    inline size_t getHeight() const { return height; }

    Pixel *operator[](size_t idx) override;
    const Pixel *operator[](size_t idx) const override;

private:
    size_t width;
    size_t height;

    Pixel **pixels;
};

#endif // GCW_PIXMAP_H_

