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

    painter.drawPixmap(0, 0, width(), height(), outputBuffer);
}

void DrawingSurface::resizeEvent(QResizeEvent *)
{
}

