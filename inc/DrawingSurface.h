#ifndef GCW_DRAWINGSURFACE_H_
#define GCW_DRAWINGSURFACE_H_

#include <QWidget>

class DrawingSurface : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingSurface(QWidget *parent = nullptr);
    ~DrawingSurface();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    struct Color
    {
        unsigned char r = 0;
        unsigned char g = 0;
        unsigned char b = 0;
        unsigned char a = 1;
    };

    QPixmap outputBuffer;
    QImage inputBuffer;
};

#endif // GCW_DRAWINGSURFACE_H_

