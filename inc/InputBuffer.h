#ifndef GCW_INPUTBUFFER_H_
#define GCW_INPUTBUFFER_H_

class InputBuffer
{
public:
    virtual ~InputBuffer() = default;

    virtual inline int width() = 0;
    virtual inline int height() = 0;

    virtual void setPixel(int x, int y,
                          unsigned char r,
                          unsigned char g,
                          unsigned char b,
                          unsigned char a = 255) = 0;

    virtual void reset() = 0;
};

#endif // GCW_INPUTBUFFER_H_

