#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputEvent>
#include <cmath>

#include "QImageBuffer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow),
    frameTimer(new QTimer)
{
    ui->setupUi(this);

    connect(frameTimer, SIGNAL(timeout()), this, SLOT(requestFrame()));
    frameTimer->start(1000 / 24);
}

MainWindow::~MainWindow()
{
    delete frameTimer;
    delete ui;
}

void MainWindow::requestFrame()
{
    frameRequested();
}

void MainWindow::updateOutputBuffer()
{
    ui->display->updateOutputBuffer();
}

InputBuffer *MainWindow::getInputBuffer()
{
    return new QImageBuffer(&ui->display->getInputBuffer(),
                            ui->display->width(),
                            ui->display->height());
}
#include <QDebug>
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    double step = M_PI / 120;

    if (key == Qt::Key_Right)
    {
        cameraRotationRequested(+step, 0);
    }
    if (key == Qt::Key_Left)
    {
        cameraRotationRequested(-step, 0);
    }
    if (key == Qt::Key_Up)
    {
        cameraRotationRequested(0, +step*10);
    }
    if (key == Qt::Key_Down)
    {
        cameraRotationRequested(0, -step*10);
    }
    frameRequested();
}

