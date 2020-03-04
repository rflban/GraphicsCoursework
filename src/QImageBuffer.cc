#include "QImageBuffer.h"

QImageBuffer::QImageBuffer(QImage *image, int w, int h) :
    image(image), w(w), h(h)
{
}

void QImageBuffer::setPixel(int x, int y,
              unsigned char r,
              unsigned char g,
              unsigned char b,
              unsigned char a)
{
    image->setPixelColor(x, y, QColor(r, g, b, a));
}

