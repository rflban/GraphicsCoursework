#ifndef GCW_PIXEL_H_
#define GCW_PIXEL_H_

using ubyte = unsigned char;

struct Pixel
{
    ubyte red;
    ubyte green;
    ubyte blue;

    Pixel() : Pixel(0, 0, 0) {}
    Pixel(ubyte r, ubyte g, ubyte b) : red(r), green(g), blue(b) {}
};

#endif // GCW_PIXEL_H_

