#ifndef GCW_PAINTSURFACE_H_
#define GCW_PAINTSURFACE_H_

#include <cstddef>

struct Pixel;

class PaintSurface
{
public:
    virtual Pixel *operator[](size_t idx) = 0;
    virtual const Pixel *operator[](size_t idx) const = 0;

    virtual size_t getWidth() const = 0;
    virtual size_t getHeight() const = 0;
};

#endif // GCW_PAINTSURFACE_H_

