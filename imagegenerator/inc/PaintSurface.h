#ifndef GCW_PAINTSURFACE_H_
#define GCW_PAINTSURFACE_H_

#include <cstddef>

struct Pixel;

class PaintSurface
{
public:
    virtual Pixel *operator[](size_t idx) = 0;
    virtual const Pixel *operator[](size_t idx) const = 0;
};

#endif // GCW_PAINTSURFACE_H_

