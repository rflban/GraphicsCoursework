#ifndef GCW_QIMAGE_H_
#define GCW_QIMAGE_H_

#include "InputBuffer.h"
#include <QImage>

class QImageBuffer : public InputBuffer
{
public:
    QImageBuffer(QImage *image, int w, int h);

    inline int width() override
    { return w; }
    inline int height() override
    { return h; }

    void setPixel(int x, int y,
                  unsigned char r,
                  unsigned char g,
                  unsigned char b,
                  unsigned char a = 255);

private:
    QImage *image;

    int w;
    int h;
};

#endif // GCW_QIMAGE_H_

