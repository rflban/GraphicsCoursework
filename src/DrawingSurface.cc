#include "DrawingSurface.h"

#include <QPainter>

#include <QApplication>
#include <QDesktopWidget>

#include "Utility.h"

DrawingSurface::DrawingSurface(QWidget *parent) :
    QWidget(parent)
{
    QRect rec = QApplication::desktop()->screenGeometry();
    outputBuffer = QPixmap(rec.width(), rec.height());
}

DrawingSurface::~DrawingSurface()
{
}

void DrawingSurface::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.drawPixmap(0, 0, outputBuffer.width(), outputBuffer.height(), outputBuffer);
}

void DrawingSurface::resizeEvent(QResizeEvent *)
{
}

QImage &DrawingSurface::getInputBuffer()
{
    inputBuffer = outputBuffer.toImage();

    return inputBuffer;
}

void DrawingSurface::updateOutputBuffer()
{
    outputBuffer = QPixmap::fromImage(inputBuffer);
    update();
}

