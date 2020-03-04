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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    double step = M_PI / 120;
    double ratio = 1.05;
    double h = 500;

    if (key == Qt::Key_Right)
    {
        cameraRotationRequested(0, +step, 0);
    }
    if (key == Qt::Key_Left)
    {
        cameraRotationRequested(0, -step, 0);
    }
    if (key == Qt::Key_Up)
    {
        cameraRotationRequested(+step, 0, 0);
    }
    if (key == Qt::Key_Down)
    {
        cameraRotationRequested(-step, 0, 0);
    }
    if (key == Qt::Key_Equal)
    {
        cameraScalingRequested(1/ratio, 1/ratio, 1/ratio);
    }
    if (key == Qt::Key_Minus)
    {
        cameraScalingRequested(ratio, ratio, ratio);
    }
    if (key == Qt::Key_W)
    {
        cameraTranslationRequested(0, 0, -h);
    }
    if (key == Qt::Key_S)
    {
        cameraTranslationRequested(0, 0, h);
    }
    if (key == Qt::Key_D)
    {
        cameraTranslationRequested(h, 0, 0);
    }
    if (key == Qt::Key_A)
    {
        cameraTranslationRequested(-h, 0, 0);
    }
    if (key == Qt::Key_E)
    {
        cameraTranslationRequested(0, -h, 0);
    }
    if (key == Qt::Key_Q)
    {
        cameraTranslationRequested(0, h, 0);
    }
}

