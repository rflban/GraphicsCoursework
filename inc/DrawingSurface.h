#ifndef GCW_DRAWINGSURFACE_H_
#define GCW_DRAWINGSURFACE_H_

#include <QWidget>

class DrawingSurface : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingSurface(QWidget *parent = nullptr);
    ~DrawingSurface();

    QImage &getInputBuffer();
    void updateOutputBuffer();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QPixmap outputBuffer;
    QImage inputBuffer;
};

#endif // GCW_DRAWINGSURFACE_H_

